#include "stdafx.h"
#include <windows.h>
#include <winsock2.h>
#include "resource.h"



//すでにプログラムが起動していないかを調べる
bool mutexcheck()
{
	HANDLE hMutex;
	hMutex = OpenMutex(MUTEX_ALL_ACCESS, false, "BallerMutex");
	if( hMutex != 0 )
	{
		CloseHandle(hMutex);
		return false;
	}
	hMutex = CreateMutex( NULL, true, "BallerMutex");
	return true;
}



#define port 14143
#define url "parity.cjb.net"



int tangou(int time,char *filename)
{
//	MessageBox(NULL,filename,"",MB_OK);

	int ans=0,count=0;
	char *p=filename;

	//ファイル名で同じ事をする
	while(*p!='\0')
	{
		count+=time;
		ans+=((*p)*count)%256;
		p++;
	}

	return ans;
}



int GetFileSize(char *FileName)
{
	fpos_t fsize = 0;

	FILE *fp = fopen(FileName,"rb");
 
	/* ファイルサイズを調査 */ 
	fseek(fp,0,SEEK_END);
	fgetpos(fp,&fsize); 
 
	fclose(fp);
 
	return (int)fsize;
}




bool sendreplay(bool stage,int index,int time,int angou,char *name)
{

	//char str[100];
	//sprintf(str,"%d",time);
	//MessageBox(NULL,str,"",MB_OK);

	//クライアントを初期化してスタート！！

	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(2, 0), &wsaData))
	{
		WSACleanup();
		MessageBox(NULL,"クライアントの初期化に失敗しました","エラー",MB_OK);
		return false;
	}

	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
	if (s < 0) {
		MessageBox(NULL,"クライアントの初期化に失敗しました","エラー",MB_OK);
		return false;
	}

	HOSTENT *lpHost = gethostbyname(url);

	if (lpHost == NULL) {
		unsigned int addr = inet_addr(url);
		lpHost = gethostbyaddr((char *)&addr, 4, AF_INET);
	}

	if (lpHost == NULL) {
		closesocket(s);
		MessageBox(NULL,"サーバーが見つかりませんでした","エラー",MB_OK);
		return false;
	}


	SOCKADDR_IN saddr;
	memset(&saddr, 0, sizeof(SOCKADDR_IN));
	saddr.sin_family = lpHost->h_addrtype;
	saddr.sin_port = htons(port);
	saddr.sin_addr.s_addr = *((u_long *)lpHost->h_addr);

	if (connect(s,(SOCKADDR *)&saddr, sizeof(saddr)) == SOCKET_ERROR) 
	{
		if (WSAGetLastError() != WSAEWOULDBLOCK)
		{
			closesocket(s);
			MessageBox(NULL,"サーバーとの通信に失敗しました\nサーバーが実行されていないか,ほかのユーザーが接続中です","更新エラー",MB_OK);
			return false;
		}
	}


	//サーバーからのメッセージを待つ

	char buf[1024];

	timeval waittime;
	fd_set rdps;
	int ret;

	waittime.tv_sec = 10;	/* タイムアウト秒数を設定する */
	waittime.tv_usec = 0;
	FD_ZERO(&rdps);			/* 初期化する */
	FD_SET(s,&rdps);		/* selectするソケットを追加する */

	ret = select(FD_SETSIZE,&rdps,(fd_set *)0,(fd_set *)0,&waittime);
	if(ret == SOCKET_ERROR)
	{
		//予期せぬエラー
		MessageBox(NULL,"予期せぬエラーが発生しました","エラー",MB_OK);
		return false;
	}
	if(ret == 0)
	{
		//タイムアウト
		MessageBox(NULL,"サーバーからの応答が無いためタイムアウトしました","エラー",MB_OK);
		return false;
	}
	if (FD_ISSET(s, &rdps)) {
		//2文字読み込む
		recv(s,buf,1024,0);
		if(strcmp(buf,"OK")!=0)
		{
			MessageBox(NULL,"サーバーとの通信に失敗しました","エラー",MB_OK);
			return false;
		}
	}



	//送信する

	/*データの受信順(全てunsigned)
	←"OK"
	→4バイト=種類
	→4バイト=ステージ番号(21以降でバーサスと言う意味)
	→4バイト=記録時間(フレーム)
	→4バイト=暗号データ
	→4バイト=ファイルサイズ
	→30バイト=名前
	実際のデータを送信*/

//	unsigned int stagenum,time,angou,size;

	char filename[MAX_PATH];
	if(stage)
		sprintf(filename,"Data/Save/Replay/Stage/%d.lzh",index-1);
	else
		sprintf(filename,"Data/Save/Replay/Corce/%d.lzh",index-1);

	if(!stage)
		index+=30;

	int size=GetFileSize(filename);
	int kind=0;
	int timeangou=tangou(time,filename);

//	char str[100];
//	sprintf(str,"%d",size);
//	MessageBox(NULL,str,"",MB_OK);

	send(s,(char*)(&kind),4,0);//種類
	send(s,(char*)(&index),4,0);
	send(s,(char*)(&time),4,0);
	send(s,(char*)(&timeangou),4,0);
	send(s,(char*)(&angou),4,0);
	send(s,(char*)(&size),4,0);
	send(s,name,30,0);


	//実際のデータ(1024文字づつ送る)
	FILE *file=fopen(filename,"rb");
	int count=0;
	while(1)
	{
		if(fscanf(file,"%c",&buf[count])!=EOF)
		{
			//char teststr[10];
			//sprintf(teststr,"%c",buf[count]);
			//MessageBox(NULL,teststr,"c",MB_OK);
			count++;
			if(count==1024)
			{
				//送信
				send(s,buf,count,0);
				count=0;
			}
		}
		else
		{
			//EOF
			if(count!=0)
			{
				//送信
				send(s,buf,count,0);

				break;
			}
		}
	}	
	fclose(file);


	//サーバーからのメッセージを待つ

	ret = select(FD_SETSIZE,&rdps,(fd_set *)0,(fd_set *)0,&waittime);
	if(ret == SOCKET_ERROR)
	{
		//予期せぬエラー
		MessageBox(NULL,"予期せぬエラーが発生しました","エラー",MB_OK);
		return false;
	}
	if(ret == 0)
	{
		//タイムアウト
		MessageBox(NULL,"サーバーからの応答が無いためタイムアウトしました","エラー",MB_OK);
		return false;
	}
	if (FD_ISSET(s, &rdps)) {
		//7文字読み込む
		recv(s,buf,7,0);
		if(strcmp(buf,"DATAOK")!=0)
		{
			MessageBox(NULL,"データの送信ミスか,データが不正です","エラー",MB_OK);
//			MessageBox(NULL,buf,"",MB_OK);
			return false;
		}
	}


	Sleep(1000);
	MessageBox(NULL,"アップロードは無事に完了しました","ランキング",MB_OK);

	return true;
}



bool recvreplay(bool stage,int index,int *onlinetime)
{





	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(2, 0), &wsaData))
	{
		WSACleanup();
		MessageBox(NULL,"クライアントの初期化に失敗しました","エラー",MB_OK);
		return false;
	}

	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
	if (s < 0) {
		MessageBox(NULL,"クライアントの初期化に失敗しました","エラー",MB_OK);
		return false;
	}

	HOSTENT *lpHost = gethostbyname(url);

	if (lpHost == NULL) {
		unsigned int addr = inet_addr(url);
		lpHost = gethostbyaddr((char *)&addr, 4, AF_INET);
	}

	if (lpHost == NULL) {
		closesocket(s);
		MessageBox(NULL,"サーバーが見つかりませんでした","エラー",MB_OK);
		return false;
	}


	SOCKADDR_IN saddr;
	memset(&saddr, 0, sizeof(SOCKADDR_IN));
	saddr.sin_family = lpHost->h_addrtype;
	saddr.sin_port = htons(port);
	saddr.sin_addr.s_addr = *((u_long *)lpHost->h_addr);

	if (connect(s,(SOCKADDR *)&saddr, sizeof(saddr)) == SOCKET_ERROR) 
	{
		if (WSAGetLastError() != WSAEWOULDBLOCK)
		{
			closesocket(s);
			MessageBox(NULL,"サーバーとの通信に失敗しました\nサーバーが実行されていないか,ほかのユーザーが接続中です","更新エラー",MB_OK);
			return false;
		}
	}


	//サーバーからのメッセージを待つ

	char buf[1024];

	timeval waittime;
	fd_set rdps;
	int ret;

	waittime.tv_sec = 10;	/* タイムアウト秒数を設定する */
	waittime.tv_usec = 0;
	FD_ZERO(&rdps);			/* 初期化する */
	FD_SET(s,&rdps);		/* selectするソケットを追加する */

	ret = select(FD_SETSIZE,&rdps,(fd_set *)0,(fd_set *)0,&waittime);
	if(ret == SOCKET_ERROR)
	{
		//予期せぬエラー
		MessageBox(NULL,"予期せぬエラーが発生しました","エラー",MB_OK);
		return false;
	}
	if(ret == 0)
	{
		//タイムアウト
		MessageBox(NULL,"サーバーからの応答が無いためタイムアウトしました","エラー",MB_OK);
		return false;
	}
	if (FD_ISSET(s, &rdps)) {
		//2文字読み込む
		recv(s,buf,3,0);
		if(strcmp(buf,"OK")!=0)
		{
			MessageBox(NULL,"サーバーとの通信に失敗しました","エラー",MB_OK);
			return false;
		}
	}



	//送信する


	char filename[MAX_PATH];
	if(stage)
		sprintf(filename,"Data/Save/Replay/Stage/%d.lzh",index-1);
	else
		sprintf(filename,"Data/Save/Replay/Corce/%d.lzh",index-1);

	if(!stage)
		index+=30;

	int size;
	int kind=1;

	send(s,(char*)(&kind),4,0);//種類
	send(s,(char*)(&index),4,0);//ステージ番号

	int readlevel=0;

	FILE *file;
	file=fopen("data/save/replay/DTemp","wb");


	while(1)
	{

		ret = select(FD_SETSIZE,&rdps,(fd_set *)0,(fd_set *)0,&waittime);

		if(ret == SOCKET_ERROR)
		{
			//予期せぬエラー
			MessageBox(NULL,"予期せぬエラーが発生しました","エラー",MB_OK);
			fclose(file);
			return false;
		}
		if(ret == 0)
		{
			//タイムアウト
			MessageBox(NULL,"サーバーからの応答が無いためタイムアウトしました","",MB_OK);
			fclose(file);
			return false;
		}



		/* sに読み込み可能データがある場合 */
		if (FD_ISSET(s, &rdps))
		{
			if(readlevel==0)
			{
//				MessageBox(NULL,"データが来ました","",MB_OK);
				ret=recv(s,(char*)(&size),4,0);
				if(ret==SOCKET_ERROR)
				{
					fclose(file);
					return false;
				}
			}
			else if(readlevel==1)
			{
//				MessageBox(NULL,"データが来ました","",MB_OK);
				ret=recv(s,(char*)onlinetime,4,0);
				if(ret==SOCKET_ERROR)
				{
					fclose(file);
					return false;
				}
			}
			else
			{
				//データ本体が送られてくる

				ret=recv(s,buf,1024,0);
				if(ret==SOCKET_ERROR)
				{
					MessageBox(NULL,"予期せぬエラーが発生しました","エラー",MB_OK);
					fclose(file);
					return false;
				}
				size-=ret;
				if(size<0)
				{
					MessageBox(NULL,"受信したデータにエラーが見られました","エラー",MB_OK);
					fclose(file);
					return false;
				}
				for(int i=0;i<ret;i++)
					fprintf(file,"%c",buf[i]);
				if(size==0)
				{
					fclose(file);
					break;
				}

			}


			readlevel++;

		}

	}


//	MessageBox(NULL,filename,"",MB_OK);


	remove(filename);
	rename("data/save/replay/DTemp",filename);



	Sleep(1000);
	MessageBox(NULL,"ダウンロードは無事に完了しました","ランキング",MB_OK);

	return true;
}
bool updateinfo(rankdatastruct *rankdata)
{




	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(2, 0), &wsaData))
	{
		WSACleanup();
		MessageBox(NULL,"クライアントの初期化に失敗しました","更新エラー",MB_OK);
		return false;
	}

	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
	if (s < 0) {
		MessageBox(NULL,"クライアントの初期化に失敗しました","更新エラー",MB_OK);
		return false;
	}

	HOSTENT *lpHost = gethostbyname(url);

	if (lpHost == NULL) {
		unsigned int addr = inet_addr(url);
		lpHost = gethostbyaddr((char *)&addr, 4, AF_INET);
	}

	if (lpHost == NULL) {
		closesocket(s);
		MessageBox(NULL,"サーバーが見つかりませんでした","更新エラー",MB_OK);
		return false;
	}


	SOCKADDR_IN saddr;
	memset(&saddr, 0, sizeof(SOCKADDR_IN));
	saddr.sin_family = lpHost->h_addrtype;
	saddr.sin_port = htons(port);
	saddr.sin_addr.s_addr = *((u_long *)lpHost->h_addr);

	if (connect(s,(SOCKADDR *)&saddr, sizeof(saddr)) == SOCKET_ERROR) 
	{
		if (WSAGetLastError() != WSAEWOULDBLOCK)
		{
			closesocket(s);
			MessageBox(NULL,"サーバーへの接続に失敗しました","更新エラー",MB_OK);
			return false;
		}
	}


	//サーバーからのメッセージを待つ

	char buf[1024];

	timeval waittime;
	fd_set rdps;
	int ret;

	waittime.tv_sec = 10;	/* タイムアウト秒数を設定する */
	waittime.tv_usec = 0;
	FD_ZERO(&rdps);			/* 初期化する */
	FD_SET(s,&rdps);		/* selectするソケットを追加する */

	ret = select(FD_SETSIZE,&rdps,(fd_set *)0,(fd_set *)0,&waittime);
	if(ret == SOCKET_ERROR)
	{
		//予期せぬエラー
		MessageBox(NULL,"予期せぬエラーが発生しました","更新エラー",MB_OK);
		return false;
	}
	if(ret == 0)
	{
		//タイムアウト
		MessageBox(NULL,"サーバーからの応答が無いためタイムアウトしました","更新エラー",MB_OK);
		return false;
	}
	if (FD_ISSET(s, &rdps)) {
		//2文字読み込む
		recv(s,buf,3,0);
		if(strcmp(buf,"OK")!=0)
		{
			MessageBox(NULL,"サーバーとの通信に失敗しました\nサーバーが実行されていないか,ほかのユーザーが接続中です","更新エラー",MB_OK);
			return false;
		}
	}


	int kind=2;
	send(s,(char*)(&kind),4,0);//種類


	//受信待機
	ret = select(FD_SETSIZE,&rdps,(fd_set *)0,(fd_set *)0,&waittime);
	if(ret == SOCKET_ERROR)
	{
		//予期せぬエラー
		MessageBox(NULL,"予期せぬエラーが発生しました","更新エラー",MB_OK);
		return false;
	}
	if(ret == 0)
	{
		//タイムアウト
		MessageBox(NULL,"サーバーからの応答が無いためタイムアウトしました","更新エラー",MB_OK);
		return false;
	}
	if (FD_ISSET(s, &rdps)) {
		//データが全部届くくらいの時間待つ
		Sleep(500);
		recv(s,(char*)rankdata,sizeof(rankdatastruct),0);
	}

	if(rankdata->check!=12345)
	{
		MessageBox(NULL,"サーバーとの通信に失敗しました","更新エラー",MB_OK);
		return false;
	}

	Sleep(1000);
	return true;
}


//bool Exec()
//{
////	char filename[256];
////	sprintf(filename,"\"data/bin/sock.exe\" %d",);
////
//////					char lpFileName[] = "H:/Book1.xls";
//////					WinExec(lpFileName, SW_SHOWNORMAL);
////
////
////	if(WinExec(,SW_SHOWNORMAL)>31)
////		return true;
//	return false;
//}

//
//
//BOOL CALLBACK DlgWndProc(HWND,UINT,WPARAM,LPARAM)
//{
//	return true;
//}
//
//
//bool GetOnline()
//{
//	CreateDialog(NULL,MAKEINTRESOURCE(IDD_KOUSINDIALOG),NULL,(DLGPROC)DlgWndProc);
//	return false;
//}