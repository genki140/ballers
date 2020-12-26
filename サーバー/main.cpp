#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define port 14143
#define BALL_MAX 50

SOCKET ls,s;


//圧縮解凍用ライブラリ
typedef WORD(WINAPI *UNLHAGETVERSION)(void);
typedef int(WINAPI *UNLHA)(const HWND, LPCSTR, LPSTR , const DWORD);
UNLHA Unlha;
HINSTANCE lhalib;




struct
{
	char name[42][30];
	int chara[42];
	int time[42];
	int check;
}rankdata;

struct vec
{
	float x,y,z;
	vec()
	{
		x=y=z=0;
	}
	vec(float nx,float ny,float nz)
	{
		x=nx,y=ny,z=nz;
	}
};

vec GetGoalPos(int statgenum);

int getcharanum(char *filename)
{

	int n;

	FILE *file=fopen("Data/Save/Replay/RTemp","r");
	fscanf(file,"%d",&n);
	fclose(file);

	return n;
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




//\nがくるまでファイルから読み出す関数を作る(EOFで終わった場合はtrueを返す)
bool fgetline(FILE *file,char *buffer)
{
	bool start=true;

	while(fscanf(file,"%c",buffer)!=EOF)
	{
		if(*buffer=='\n')
		{
			if(start)
			{
				continue;
			}
			*buffer='\0';
			return false;
		}
		start=false;
		buffer++;
	}
	*buffer='\0';
	return true;
}




bool loaddata()
{
	FILE *file=fopen("data/data.txt","r");
	if(file==NULL)return false;

	int i;

	for(i=0;i<42;i++)
	{
		fgetline(file,rankdata.name[i]);
		fscanf(file,"%d",&(rankdata.chara[i]));
		fscanf(file,"%d",&(rankdata.time[i]));
	}

	fclose(file);

	//char str[100];
	//for(i=0;i<42;i++)
	//{
	//	sprintf(str,"%s\n%d,%d",rankdata.name[i],rankdata.chara[i],rankdata.time[i]);
	//	MessageBox(NULL,str,"",MB_OK);
	//}


	return true;
}
void savedata()
{
	FILE *file=fopen("data/data.txt","w");

	int i;

	for(i=0;i<42;i++)
	{
		fprintf(file,"%s\n",rankdata.name[i]);
		fprintf(file,"%d\n",rankdata.chara[i]);
		fprintf(file,"%d\n",rankdata.time[i]);
	}

	fclose(file);
}

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

//ファイルを読み、チェック用数値を作成する
int createcheck(char *filename)
{
	FILE* file;
	int ans=0,count=0;
	char c,*p=filename;

	//クリアファイルをバイナリで開いて数値を作る
	if((file=fopen(filename,"rb"))==NULL) return false;

	while(fscanf(file,"%c",&c)!=EOF)
	{
		count+=2;
		ans+=(c*count)%256;
	}

	//ファイル名で同じ事をする
	while(*p!='\0')
	{
		count++;
		ans+=((*p)*count)%256;
		p++;
	}

	fclose(file);

	return ans;
}

//ファイルが不正でないかチェックする
bool checkfile(char *filename)
{
	//createcheckの結果とfilename+"c"の中身を比較して結果を返す
	char checkfilename[256];
	strcpy(checkfilename,filename);
	strcat(checkfilename,"c");
	FILE *file=fopen(checkfilename,"r");

	if(file==NULL)
		return false;
	
	int c;
	fscanf(file,"%d",&c);
	fclose(file);

	if(c!=createcheck(filename))
		return false;

	return true;
}

//チェックファイルを作成する
bool createcheckfile(char *filename)
{
	char checkfilename[256];
	strcpy(checkfilename,filename);
	strcat(checkfilename,"c");
	FILE *file=fopen(checkfilename,"w");

	if(file==NULL)
		return false;
	
	fprintf(file,"%d",createcheck(filename));
	fclose(file);

	return true;
}


//チェックファイルの数値を読む
int readcheck(char *filename)
{
	//createcheckの結果とfilename+"c"の中身を比較して結果を返す
	char checkfilename[256];
	strcpy(checkfilename,filename);
	strcat(checkfilename,"c");
	FILE *file=fopen(checkfilename,"r");

	if(file==NULL)
		return false;

	int c;
	fscanf(file,"%d",&c);
	fclose(file);

	return c;
}


//num=0～
bool checkComplete(int time,bool stage,int num)
{
	////簡易チェック
	//if(num==24 && stage==true && time>25*60)
	//	return false;

	//コースなら無条件
	if(stage==false) return true;

	char work[10000];
	FILE *fp=fopen("Data/Save/Replay/RTemp","r");
	if(fp==NULL) return false;
	vec v1,v2,v3;

	//ballkind
	fgetline(fp,work);
	
	//フレーム数カウント
	int c=0;
	while(!fgetline(fp,work))
	{
//		MessageBox(NULL,work,"",MB_OK);
		if(atoi(work)!=0)
			fgetline(fp,work);

		if(stage && (c % 50) == 0)
		{
			//0番ボール情報取得
			sscanf(work,"%f,%f,%f,%f,%f,%f,%f,%f,%f",
				&v1.x,&v1.y,&v1.z,
				&v2.x,&v2.y,&v2.z,
				&v3.x,&v3.y,&v3.z);			
		}

		c++;
	}

//	sprintf(work,"%d,%d,%d",time,c,c/BALL_MAX);
//	MessageBox(NULL,work,"",MB_OK);

	if(abs((time+250)-c/BALL_MAX)>10)
	{
		fclose(fp);
		return false;
	}


	//最終位置情報チェック
	{
		vec v=GetGoalPos(num);
		v.x-=v1.x;
		v.y-=v1.y;
		v.z-=v1.z;
		if(v.x*v.x+v.y*v.y+v.z*v.z > 11*11)//ゴール判定の半径は10
		{
			return false;
		}
	}


	fclose(fp);
	return true;
}






//




bool startserver()
{



	SOCKADDR_IN saddr;
//	int nAsync;

	ls = socket(AF_INET, SOCK_STREAM, 0);
	if (ls < 0)
	{
		if (WSAGetLastError() != WSAEWOULDBLOCK)
		{
			return false;
		}
	}


	memset(&saddr, 0, sizeof(SOCKADDR_IN));
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(port);
	saddr.sin_addr.s_addr = INADDR_ANY;


	if (bind(ls, (SOCKADDR *)&saddr, sizeof(saddr)) == SOCKET_ERROR)
	{
		closesocket(ls);
		return false;
	}

	//リスンソケットを立てる
	if (listen(ls, 0) == SOCKET_ERROR) {
			closesocket(ls);
			return false;
	}


	return true;
}




#define bufsize 1024


void recvdata()
{
//	MessageBox(NULL,"データ来ました","",MB_OK);
	//セレクトを使ってデータを受信

	/*データの受信順(全てunsigned)
	←"OK"
	→4バイト=ステージ番号(21以降でバーサスと言う意味)
	→4バイト=記録時間(フレーム)
	→4バイト=暗号データ
	→4バイト=ファイルサイズ
	実際のデータを送信*/

	//タイムアウトは10秒とする(タイムアウトした場合は失敗とみなす)
	//最後に暗号データのチェックを行う
	//暗号チェックの結果を相手に返す

	//←"DATAOK" or タイムアウト(無視)



	send(s,"OK\0",3,0);

	timeval waittime;
	fd_set rdps;
	int ret;

	waittime.tv_sec = 10;	/* タイムアウト秒数を設定する */
	waittime.tv_usec = 0;
	FD_ZERO(&rdps);			/* 初期化する */
	FD_SET(s,&rdps);		/* selectするソケットを追加する */

	int kind;
	int readlevel=0;
	//0=(up=0,down=1,update=2)
	//2=ステージ番号
	//2=タイム
	//3=タイム暗号
	//4=暗号
	//5=サイズ
	//6=名前
	//6=データ


	char name[30];
	bool stage;
	int tstagenum,stagenum,time,angou,timeangou,size;
	char buf[bufsize];
	char filename[MAX_PATH];
	FILE *file=NULL;//書き込み用ファイル

	while(1)
	{

		ret = select(FD_SETSIZE,&rdps,(fd_set *)0,(fd_set *)0,&waittime);

		if(ret == SOCKET_ERROR)
		{
			//予期せぬエラー
			break;
		}
		if(ret == 0)
		{
			//タイムアウト
//			MessageBox(NULL,"タイムアウト","",MB_OK);
			break;
		}


		/* sに読み込み可能データがある場合 */
		if (FD_ISSET(s, &rdps))
		{
			if(readlevel==0)
			{
//				MessageBox(NULL,"データが来ました","",MB_OK);
				ret=recv(s,(char*)(&kind),4,0);
				if(ret==SOCKET_ERROR) break;

//				if(kind==1)
//					MessageBox(NULL,"KIND1","",MB_OK);

				if(kind==2)
				{
					//更新
					//そのまま送信
					send(s,(char*)(&rankdata),sizeof(rankdata),0);
					break;
				}
			}
			else
			{

				if(kind==0)//upload
				{
					if(readlevel==1)
					{
						ret=recv(s,(char*)(&tstagenum),4,0);
						if(ret==SOCKET_ERROR) break;
						if(tstagenum<=30)
						{
							stage=true;
							stagenum=tstagenum;
						}
						else
						{
							stage=false;
							stagenum=tstagenum-30;
						}
					}
					else if(readlevel==2)
					{
						ret=recv(s,(char*)(&time),4,0);
						if(ret==SOCKET_ERROR) break;
					}
					else if(readlevel==3)
					{
						ret=recv(s,(char*)(&timeangou),4,0);
						if(ret==SOCKET_ERROR) break;
					}
					else if(readlevel==4)
					{
						ret=recv(s,(char*)(&angou),4,0);
						if(ret==SOCKET_ERROR) break;
					}
					else if(readlevel==5)
					{


						ret=recv(s,(char*)(&size),4,0);
						if(ret==SOCKET_ERROR) break;

						if(stage)
							sprintf(filename,"Data/Save/Replay/Stage/%d.lzh",stagenum-1);
						else
							sprintf(filename,"Data/Save/Replay/Corce/%d.lzh",stagenum-1);

						file=fopen(filename,"wb");

//						char str[1000];
//						sprintf(str,"filename=%s,time=%d,timeangou=%d,createangou=%d",filename,time,timeangou,tangou(time,filename));
//						MessageBox(NULL,str,"",MB_OK);

						//次はタイムの確認
						if(tangou(time,filename)!=timeangou)
						{
//							MessageBox(NULL,"タイムが間違っています","",MB_OK);
							break;
						}


						//char str[100];
						//sprintf(str,"%d,%d",time,rankdata.time[tstagenum-1]);
						//MessageBox(NULL,str,"",MB_OK);

						if(time>=rankdata.time[tstagenum-1] && rankdata.time[tstagenum-1]!=0)
						{
//							MessageBox(NULL,"TimeError","",MB_OK);
							break;
						}

					}
					else if(readlevel==6)
					{
						ret=recv(s,name,30,0);
						if(ret==SOCKET_ERROR) break;


					}
					else
					{
						//最終データ受信(size分)


						ret=recv(s,buf,bufsize,0);
						if(ret==SOCKET_ERROR)
						{
//							MessageBox(NULL,"エラーが発生しました","サーバー",MB_OK);
							break;
						}
//						buf[ret]=0;
//						MessageBox(NULL,buf,"サーバー",MB_OK);
						size-=ret;
						if(size<0)
						{
//							MessageBox(NULL,"指定以上のデータが送られてきました","サーバー",MB_OK);
							break;
						}
						for(int i=0;i<ret;i++)
							fprintf(file,"%c",buf[i]);
						if(size==0)
						{
							fclose(file);


							//データが不正でないかチェックを行う
							{
								if(createcheck(filename)!=angou)
								{
//									MessageBox(NULL,"暗号データが間違っています","",MB_OK);
									break;
								}
							}

							//解凍
							{
								//すでにあるRTempを削除
								remove("Data/Save/Replay/RTemp");
								//解凍して移動
								char command[500];
								sprintf(command,"e %s Data/Save/Replay/ RTemp -n1 -gm1",filename);
								Unlha(NULL, command, "" ,0);
							}

							//データが不正でないか、正確にチェックを行う
							{
								if(!checkComplete(time,stage,stagenum-1))
									break;
							}


//							MessageBox(NULL,"無事アップロードされました","サーバー",MB_OK);


							//rankdataを更新する
							strcpy(rankdata.name[tstagenum-1],name);
							rankdata.chara[tstagenum-1]=getcharanum(filename);
							rankdata.time[tstagenum-1]=time;

							savedata();


							send(s,"DATAOK",7,0);
							break;
						}
					}
				}








				else if(kind==1)//ダウンロード
				{
					//ステージ番号を受信し、データサイズ、データ本体を送信する
					ret=recv(s,(char*)(&tstagenum),4,0);
					if(ret==SOCKET_ERROR) break;
					if(tstagenum<30)
					{
						stage=true;
						stagenum=tstagenum;
					}
					else
					{
						stage=false;
						stagenum=tstagenum-30;
					}

					if(stage)
						sprintf(filename,"Data/Save/Replay/Stage/%d.lzh",stagenum-1);
					else
						sprintf(filename,"Data/Save/Replay/Corce/%d.lzh",stagenum-1);

//					MessageBox(NULL,filename,"",MB_OK);
					
					//サイズを取得し、送信
					int filesize=GetFileSize(filename);
					send(s,(char*)&filesize,4,0);

					send(s,(char*)&(rankdata.time[tstagenum-1]),4,0);

					//データ本体の送信
					//実際のデータ(1024文字づつ送る)
					FILE *file=fopen(filename,"rb");
					int count=0;
					while(1)
					{
						if(fscanf(file,"%c",&buf[count])!=EOF)
						{

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
					break;

				}



			}

			readlevel++;

		}

	}



	if(file)
		fclose(file);




}




int APIENTRY WinMain(HINSTANCE hInstance,
                        HINSTANCE hPrevInstance,
                        LPSTR lpCmdLine,
                        int nCmdShow )
{
	int i;

	//カレントパスの設定
	char mename[MAX_PATH];
	GetModuleFileName(NULL,mename,MAX_PATH-1);
	char path[MAX_PATH];
	strcpy(path,mename);
	//パスの最後から/を探す
	int len=(int)strlen(path);
	for(i=0;i<len;i++)
		if(path[i]=='\\')
			path[i]='/';
	for(i=len-1;i>=0;i--)
	{
		if(path[i]=='/')
		{
			path[i]='\0';
			break;
		}
	}
	//正しいパスをセット
	SetCurrentDirectory(path);




	rankdata.check=12345;//このデータがちゃんと送られたかをクライアントでは調べる



	lhalib = LoadLibrary("data/dll/unlha32.dll");
	if (lhalib == NULL){
        MessageBox(NULL, "必要なライブラリファイルが見つかりません", "エラー", MB_OK);
        return false;
	}

	//関数作成
	Unlha = (UNLHA)GetProcAddress(lhalib,"Unlha");



	if(loaddata()==false)
	{
		MessageBox(NULL,"データファイルが見つかりません","",MB_OK);
		return false;
	}


	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(2, 0), &wsaData))
	{
		WSACleanup();
		return false;
	}




	//受付
	SOCKADDR_IN from;
	int fromlen;
	while(1)
	{

		closesocket(s);
		closesocket(ls);

		//サーバースタート
		if(!startserver())
			break;

//		MessageBox(NULL,"待機しています","",MB_OK);

		s=accept(ls,(SOCKADDR *)&from,&fromlen);
		closesocket(ls);

		if(s!=INVALID_SOCKET)
		{
			//データ受信開始！
			recvdata();
			//すぐにソケットを閉じないように、少し待つ
			Sleep(500);
		}
	}

	closesocket(s);
	WSACleanup();

//	savedata();

	// 戻り値を返します。
	return 0;
}



vec GetGoalPos(int stagenum)
{
	if(stagenum==0)
		return vec(-39.87f,1.73f,-76.92f);
	else if(stagenum==1)
		return vec(19.97f,-1.61f,174.09f);
	else if(stagenum==2)
		return vec(146.0f,-3.2f,65.58f);
	else if(stagenum==3)
		return vec(22.64f,0.03f,89.89f);
	else if(stagenum==4)
		return vec(36.15f,88.65f,126.18f);
	else if(stagenum==5)
		return vec(32.34f,-50.60f,350.36f);
	else if(stagenum==6)
		return vec(-122.18f,-12.6f,77.81f);
	else if(stagenum==7)
		return vec(-26.04f,-15.28f,183.82f);
	else if(stagenum==8)
		return vec(30.51f,25.55f,103.19f);
	else if(stagenum==9)
		return vec(11.13f,-73.98f,205.21f);
	else if(stagenum==10)
		return vec(88.87f,40.19f,188.36f);
	else if(stagenum==11)
		return vec(26.33f,-18.66f,62.36f);
	else if(stagenum==12)
		return vec(-121.42f,-251.32f,127.88f);
	else if(stagenum==13)
		return vec(55.91f,0,-15.83f);
	else if(stagenum==14)
		return vec(-8.29f,-0.21f,72.85f);
	else if(stagenum==15)
		return vec(-29.11f,29.36f,16.49f);
	else if(stagenum==16)
		return vec(-31.40f,13.40f,171.79f);
	else if(stagenum==17)
		return vec(-71.69f,51.52f,-104.13f);
	else if(stagenum==18)
		return vec(-49.89f,195.71f,22.56f);
	else if(stagenum==19)
		return vec(183.85f,-39.16f,285.35f);
	else if(stagenum==20)
		return vec(0.0f,74.49f,256.44f);
	else if(stagenum==21)
		return vec(-58.67f,-46.26f,-3.38f);
	else if(stagenum==22)
		return vec(-134.66f,36.56f,152.98f);
	else if(stagenum==23)
		return vec(-31.51f,76.47f,52.37f);
	else if(stagenum==24)
		return vec(196.93f,43.47f,56.4f);
	else if(stagenum==25)
		return vec(-88.1f,-11.83f,72.68f);
	else if(stagenum==26)
		return vec(49.78f,-274.0f,-10.34f);
	else if(stagenum==27)
		return vec(-0.01f,-1.04f,19.86f);
	else if(stagenum==28)
		return vec(0.0f,-14.57f,0.0f);
	else if(stagenum==29)
		return vec(-160.23f,100.0f,-78.19f);
	else
		return vec(0,1000000,0);
}