#include "Socket.h"

//クライアントが接続してきたときに使用されるメッセージ


#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
//#include <WinSock2.h>


int SocketClass::AutoMsg(UINT Msg,LPARAM lParam,int *Event)
{

	if(Msg>=(UINT)MsgNum && Msg<=(UINT)MsgNum+ClientMax)//ネットワークメッセージかのチェック
	{
		//イベント番号取得(ACCEPT,CONNECT,READ,CLOSEなど)
		*Event=WSAGETSELECTEVENT(lParam);
	}
	else
	{
		return -1;
	}


	int i;

	if(ServerEnable)
	{
		if(Msg==(UINT)MsgNum)
		{
			//サーバー時、新規接続クライアントからのメッセージ

			if(*Event==FD_ACCEPT)
			{

				//あいてる番号を探す
				for(i=0;i<ClientMax;i++)
				{
					if(client[i].enable==false)
					{

						//やっぱここで確立？

						SOCKADDR from;
						memset(&from, 0, sizeof(SOCKADDR));
						int fromlen = sizeof(from);
						client[i].s = accept(s, (SOCKADDR *)&from, &fromlen);
						if (client[i].s == INVALID_SOCKET)
						{
							closesocket(client[i].s);
							return -1;
						}
						int nAsync = WSAAsyncSelect(client[i].s, hWnd, MsgNum+1+i, FD_CLOSE | FD_READ);
						if (nAsync != 0) {
							closesocket(client[i].s);
							return -1;
						}

						client[i].enable=true;
						client[i].LastTime=(long)clock();

						return i;
					}
				}

			}
			else
			{
				return -1;
			}


		}
		else if(Msg>(UINT)MsgNum && Msg<=(UINT)MsgNum+ClientMax)
		{
			//サーバー時、接続済みクライアントからのメッセージ
			int ClientNum=(int)Msg-MsgNum-1;
			
			//時間更新
			client[ClientNum].LastTime=(long)clock();

			if(*Event==FD_READ)
			{
				//クライアント番号を返す
				return ClientNum;
			}
			else if(*Event==FD_CLOSE)
			{
				//勝手にソケット閉じて一応閉じた番号を返す
				closesocket(client[ClientNum].s);
				client[ClientNum].enable=false;
				return ClientNum;
			}
			else
			{
				return -1;
			}

		}


	}
	else if(ClientEnable)
	{
		if(Msg==(UINT)MsgNum)
		{
			//クライアント時、サーバーからのメッセージ
			//時間更新
			LastTime=(long)clock();

			if(*Event==FD_CLOSE)
			{
				//クライアント終了
				Exit();
			}

			return 0;//クライアントのときは一応0を返す
		}
	}
	else
	{
		return -1;
	}





	return true;
}






bool SocketClass::InitServer(int port,HWND wnd,int Msg,int Max,float Time)
{
	if(ServerEnable || ClientEnable)
		return false;

	hWnd=wnd;
	MsgNum=Msg;

	if(Max>CLIENT_MAX)Max=CLIENT_MAX;
	ClientMax=Max;
	OutTime=Time;

	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(1, 1), &wsaData))
	{
		WSACleanup();
		return false;
	}



	SOCKADDR_IN saddr;
	int nAsync;


	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s < 0)
	{
		if (WSAGetLastError() != WSAEWOULDBLOCK)
		{
			return false;
		}
	}

	nAsync = WSAAsyncSelect(s, hWnd, MsgNum, FD_ACCEPT);
	if (nAsync != 0)
	{
		closesocket(s);
		return false;
	} 

	memset(&saddr, 0, sizeof(SOCKADDR_IN));
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(port);
	saddr.sin_addr.s_addr = INADDR_ANY;

	if (bind(s, (SOCKADDR *)&saddr, sizeof(saddr)) == SOCKET_ERROR)
	{
		closesocket(s);
		return false;
	}


	if (listen(s, 0) == SOCKET_ERROR) {
			closesocket(s);
			return false;
	}

	client=new ClientStruct[ClientMax];

	ServerEnable=true;
	return true;
}

bool SocketClass::InitClient(char *ip,int port,HWND wnd,int Msg,float Time)
{
	if(ServerEnable || ClientEnable)
		return false;

	hWnd=wnd;
	MsgNum=Msg;
	OutTime=Time;

	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(1, 1), &wsaData))
	{
		WSACleanup();
		return false;
	}


	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s < 0) {
		return false;
	}


	if(strlen(ip)<=0)
		lpHost = gethostbyname("localhost");
	else
		lpHost = gethostbyname(ip);


	if (lpHost == NULL) {
		addr = inet_addr(ip);
		lpHost = gethostbyaddr((char *)&addr, 4, AF_INET);
	}

	if (lpHost == NULL) {
		closesocket(s);
		return false;
	}


	WSAAsyncSelect(s, hWnd, MsgNum,
		FD_CONNECT | FD_READ | FD_CLOSE);

	memset(&saddr, 0, sizeof(SOCKADDR_IN));
	saddr.sin_family = lpHost->h_addrtype;
	saddr.sin_port = htons(port);
	saddr.sin_addr.s_addr = *((u_long *)lpHost->h_addr);

	if (connect(s,(SOCKADDR *)&saddr, sizeof(saddr)) == SOCKET_ERROR) 
	{
		if (WSAGetLastError() != WSAEWOULDBLOCK)
		{
			closesocket(s);
			return false;
		}
	}



	//接続成功！！
	ClientEnable=true;
	LastTime=clock();
	return true;

}


void SocketClass::Exit()
{
	if(ServerEnable)
	{
		ServerEnable=false;

		//全ソケットとリスンソケット終了
		int i;
		for(i=0;i<ClientMax;i++)
		{
			shutdown(client[i].s, SD_BOTH);
			closesocket(client[i].s);
		}

		closesocket(s);
	}
	else if(ClientEnable)
	{
		ClientEnable=false;

		shutdown(s, SD_BOTH);
		closesocket(s);
		WSACleanup();
	}
}

void SocketClass::DeleteClient(int index)
{
	//ソケットを閉じる
	closesocket(client[index].s);
	client[index].enable=false;
}























int SocketClass::CheckTimeOut()
{
	int i;

	if(ServerEnable)
	{
		//クライアントが落ちていないかを調べる
		for(i=0;i<ClientMax;i++)
		{
			if(client[i].enable)
			{
				if((float)((long)clock()-client[i].LastTime)/1000.0f>OutTime)
				{
					//勝手にソケット閉じて一応閉じた番号を返す
					closesocket(client[i].s);
					client[i].enable=false;
					return i;
				}
			}
		}
	}
	else if(ClientEnable)
	{
		if((float)((long)clock()-LastTime)/1000.0f>OutTime)
		{
			//クライアント終了
			Exit();
			return 0;
		}
	}

	return -1;
}




//sizeが0以下のときはヘッダのみ送信
bool SocketClass::Send(short int kind,char* data,long int size,int index)
{
	//ヘッダを自動的につけて送信する
	if(!ServerEnable && !ClientEnable)
		return false;

	//ヘッダ調整
	HeadStruct head;
	head.kind=kind;
	head.size=size;
	head.rnd=(char)(rand()%256);

	//送信するデータ&ヘッダをそれぞれ暗号化
	//(とりあえずなにもしなくていい)

	if(ServerEnable)
	{
		//ヘッダ送信
		if(send(client[index].s,(char*)&head,sizeof(head),0)==SOCKET_ERROR)
			return false;

		//データ送信
		if(size>0)
		{
			if(send(client[index].s,data,size,0)==SOCKET_ERROR)
				return false;
		}
	}
	else
	{
		//ヘッダ送信
		if(send(s,(char*)&head,sizeof(head),0)==SOCKET_ERROR)
			return false;

		if(size>0)
		{
			//データ送信
			if(send(s,data,size,0)==SOCKET_ERROR)
				return false;
		}
	}
	return true;
}


bool SocketClass::SendAll(short int kind,char* data,long int size)
{
	//サーバーオンリー
	if(!ServerEnable) return false;

	bool ok=true;

	int i;
	for(i=0;i<ClientMax;i++)
	{
		if(client[i].enable)
		{
			if(!Send(kind,data,size,i))
			{
				ok=false;
			}
		}
	}
	return ok;
}


int SocketClass::Recv(char *data,int index)
{
	if(!ServerEnable && !ClientEnable)
		return SOCKET_ERROR;



	int getsize;
	HeadStruct headstruct;//ヘッダ情報格納用
	SOCKET *sockp;//ソケットポインタ
	bool *headenp;//ヘッダ有無ポインタ

	//ヘッダ有無とソケットをポインタ化
	if(ServerEnable)
	{
		headenp=&(client[index].headenable);
		sockp=&(client[index].s);
	}
	else
	{
		headenp=&headenable;
		sockp=&s;
	}


	//ヘッダ情報が無効だったら取得しない
	if(!(*headenp))
		return SOCKET_ERROR;

	//とりあえずヘッダ情報を取得
	if(recv(*sockp,(char*)&headstruct,sizeof(headstruct),0)==SOCKET_ERROR)
		return SOCKET_ERROR;	


	//ヘッダ複合化！！
	//(とりあえずこのままでいい)


	//いよいよ情報を受信
	if((getsize=recv(*sockp,data,headstruct.size,0))==SOCKET_ERROR)
		return SOCKET_ERROR;


	//情報複合化！！
	//(とりあえずこのままでいい)


	//正しく受信できたので、ヘッダを無効にする
	*headenp=false;

	return getsize;
}





//たまっているデータの種類を返す
bool SocketClass::GetMsgKind(int *kind,int *size,int index)
{
	if(!ServerEnable && !ClientEnable)
		return false;

	//まだ取得していない場合、sizeof(HeadStruct)分のデータがたまっているか調べ、たまっていたら情報を取得し、種類を返す(たまっていなかったらfalseを返す)

	int getsize;//サイズ格納用
	HeadStruct headstruct;//ヘッダ情報格納用
	SOCKET *sockp;//ソケットポインタ
	bool *headenp;//ヘッダ有無ポインタ


	//ヘッダ有無とソケットをポインタ化
	if(ServerEnable)
	{
		headenp=&(client[index].headenable);
		sockp=&(client[index].s);
	}
	else
	{
		headenp=&headenable;
		sockp=&s;
	}


	//データは残したまま、ヘッダ情報を取得
	if((getsize=recv(*sockp,(char*)&headstruct,sizeof(headstruct),MSG_PEEK)) < sizeof(headstruct) )
		return false;


	//ヘッダ複合化！！
	//(とりあえず何もしない)


	//ヘッダ情報が有効になっていたらまだデータがrecvで消えていないので、そのままの情報を返す
	if(*headenp)
	{
		*kind=headstruct.kind;
		if(size) *size=headstruct.size;
		return true;
	}

	//情報部のサイズが0だったら受信しちゃって種類を返す(この場合、headenableはfalseのままにしておく)
	if(headstruct.size==0)//種類だけのデータ
	{
		if(recv(*sockp,(char*)&Buffer,sizeof(headstruct),0) == SOCKET_ERROR )//受信しちゃう！！(ヘッダはすでに複合化されているのでBufferに書き込む)
			return false;
		*kind=headstruct.kind;
		if(size) *size=headstruct.size;
		return true;
	}


	//ソケットとたまっているデータのサイズが取得できるサイズかどうかを調べる
	if(recv(*sockp,(char*)Buffer,sizeof(Buffer),MSG_PEEK) < (signed)(sizeof(headstruct)+headstruct.size) )
		return false;

	//どうやらデータはちゃんと届いているらしいので、ヘッダを有効にし、種類などを返して終了
	*kind=headstruct.kind;
	if(size) *size=headstruct.size;
	*headenp=true;

	return true;
}



//暗号化
void SocketClass::Encryption(char *data,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		data[i]+=i+140;
	}
}

//複合化
void SocketClass::Composite(char *data,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		data[i]-=i+140;
	}
}

