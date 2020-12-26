#ifndef NET_HED
#define NET_HED


#include <winsock.h>
#include <conio.h>


enum NETMSG_ENUM{	NETMSG_INOK,NETMSG_PLAYERMAX,NETMSG_SEAVERDOWN,NETMSG_ENDGAME,NETMSG_GAMESTART,NETMSG_COUNTSTART,NETMSG_READY,
					NETMSG_PLAYERINFO,NETMSG_INPUT,
					NETMSG_PLAYERIN,NETMSG_PLAYEROUT,NETMSG_SETPLAYER,NETMSG_KETTEI,NETMSG_HENKOU,
					NETMSG_BALL,NETMSG_CAMERA,NETMSG_ITEM,
					NETMSG_INFO,//NETMSG_INFOは、プレイヤー全員のラップとランク、所持アイテムと効果中アイテム情報

					//その他のちょっとしたデータ(サーバーからクライアントへ一方的に送るデータ)
					NETMSG_BAKUHUU,NETMSG_IWASTART,NETMSG_IWAEND,NETMSG_YUUDOUSTART,NETMSG_YUUDOUEND,

					NETMSG_SHOT,NETMSG_FIRE,NETMSG_FIRESTART,NETMSG_MIZUSTART,NETMSG_TAIHOU,
					NETMSG_BOMB,NETMSG_YUUDOU,NETMSG_GURABISTART,NETMSG_GURABI,

					NETMSG_STAGESTATE

					};


//ネットワーク用
char Buffer[65536];



//ネットワーク関係の変数
#define MY_MSG (WM_USER+1)

WSADATA wsaData;
SOCKADDR_IN addr,from[3],tempsock;
HOSTENT *lpHost;



//bool AddOK;//ぷれいやー参加ＯＫかどうかが、サーバーから帰ってきたときに格納しておく


void GetMsg(char *s,int *id,int *command);
void SetMsg(char *s,int id,int command);





bool SetNetwork()
{
	//ネットワークの設定をする(めんどいのでUDP)

	if (WSAStartup(MAKEWORD(1, 1), &wsaData))
		return false;

	//ソケットオープン
	s = socket(AF_INET, SOCK_DGRAM, 0);
	if (s < 0)
	{
		WSACleanup();
		return false;
	}




	if(Setting.Seaver)
	{

		memset(&addr, 0, sizeof(addr));
		addr.sin_family = AF_INET;
		addr.sin_port = htons(atoi(Setting.port));
		addr.sin_addr.s_addr = htonl(INADDR_ANY);


		if (bind(s, (LPSOCKADDR)&addr, (int)sizeof(addr)) == SOCKET_ERROR)
		{
			closesocket(s);
			WSACleanup();
			return false;
		} 
		if (WSAAsyncSelect(s, hWnd, MY_MSG, FD_READ) == SOCKET_ERROR)
		{
			if (WSAGetLastError() != WSAEWOULDBLOCK)
			{
				closesocket(s);
				WSACleanup();
				return false;
			} 
		}

		fromID[0]=-1;
		fromID[1]=-1;
		fromID[2]=-1;

		multiplayready[0]=false;
		multiplayready[1]=false;
		multiplayready[2]=false;
//		GetNowPlayerCount=1;//1は自分

	}
	else
	{
		lpHost=gethostbyname(Setting.ip);
		if (lpHost == NULL)
		{
			unsigned int address = inet_addr(Setting.ip);
			lpHost=gethostbyaddr((char *)&address, 4, AF_INET);
			if (lpHost == NULL)
			{
				closesocket(s);
				WSACleanup();
				return false;
			}
		}

		memset(&addr, 0, sizeof(addr));
		addr.sin_port = htons(atoi(Setting.port));
		addr.sin_family = AF_INET;
		addr.sin_addr.s_addr = *((unsigned long *)lpHost->h_addr);

		s = socket(AF_INET, SOCK_DGRAM, 0);
		if (s == INVALID_SOCKET) 
		{
			closesocket(s);
			WSACleanup();
			return false;
		}

		
		if (WSAAsyncSelect(s, hWnd, MY_MSG, FD_READ | FD_WRITE) == SOCKET_ERROR)
		{
			if (WSAGetLastError() != WSAEWOULDBLOCK) {
				closesocket(s);
				WSACleanup();
				return false;
			}
		}


		strcpy(Buffer,"");
		SetMsg(Buffer,myID,NETMSG_PLAYERIN);

		//転送できるかな？(一応テスト)
		if (sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&addr, (int)sizeof(addr)) == SOCKET_ERROR)
		{
			closesocket(s);
			WSACleanup();
			return false;
		}

		//後はメッセージが来るまで待つのみ！！(一定時間来ないか満員だったらエラーメッセージ表示)


	}


	return true;
}



void GetNetMsg()
{
	int i,j,k,size,len,si;
	D3DXMATRIX mat;

	int ID=0,command=0;

	size=(int)sizeof(tempsock);
	len=recvfrom(s, Buffer, (int)sizeof(Buffer) - 1, 0, (SOCKADDR *)&tempsock, &size);

	if(len != SOCKET_ERROR)
		Buffer[len] = '\0';
	else
		return;

	GetMsg(Buffer,&ID,&command);//データ編集

	if(ID!=myID)//自分からのメッセージでなければ
	{

		if(Setting.Seaver)
		{
			if(command==NETMSG_PLAYERIN)
			{
				bool sinki=true;

				for(i=0;i<playercount-1;i++)
				{
					if(fromID[i]==ID)
					{
						sinki=false;
						break;
					}
				}

				if(sinki)
				{

					if(GetNowPlayerCount()<playercount)
					{

						//あいてるところを探す
						for(i=0;i<playercount-1;i++)
						{
							if(fromID[i]==-1)
							{

								sprintf(Buffer,"%d",i+1);
								SetMsg(Buffer,myID,NETMSG_INOK);
								sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&tempsock, (int)sizeof(tempsock));

								from[i]=tempsock;
								fromID[i]=ID;

								SendAllPlayerInfo(playercount);

								break;
							}

						}
					}
					else
					{//もう人数いっぱい！！
						Buffer[0]='\0';
						SetMsg(Buffer,myID,NETMSG_PLAYERMAX);
						sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&tempsock, (int)sizeof(tempsock));
					}


				}
				else
				{
					sprintf(Buffer,"%d",i+1);
					SetMsg(Buffer,myID,NETMSG_INOK);
					sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&tempsock, (int)sizeof(tempsock));
				}

				wait(0.5f);

			}
			else if(command==NETMSG_PLAYEROUT)
			{
				for(i=0;i<playercount-1;i++)
				{
					if(fromID[i]==ID)
					{
						fromID[i]=-1;
						player[i+1].charnum=-1;
						break;
					}
				}
				SendAllPlayerInfo(playercount);

			}
			else if(command==NETMSG_SETPLAYER)
			{
				for(i=0;i<playercount-1;i++)
				{
					if(fromID[i]==ID)
					{
						player[i+1].charnum=atoi(Buffer);
						break;
					}
				}

				SendAllPlayerInfo(playercount);
			}
			else if(command==NETMSG_KETTEI)
			{
				for(i=0;i<playercount-1;i++)
				{
					if(fromID[i]==ID)
					{
						multiplayready[i]=true;
						break;
					}
				}
			}
			else if(command==NETMSG_HENKOU)
			{
				for(i=0;i<playercount-1;i++)
				{
					if(fromID[i]==ID)
					{
						multiplayready[i]=false;
						break;
					}
				}
			}
			else if(command==NETMSG_INPUT)
			{
				bool jump,item;

				for(i=0;i<playercount-1;i++)
				{
					if(fromID[i]==ID)
					{
						//プレイヤーi+1を動かす

						i++;
//						MessageBox(hWnd,Buffer,"",MB_OK);

						sscanf(Buffer,"%d,%d,%f,%f",&item,&jump,&buttonstate[i].x,&buttonstate[i].y);

						if(jump)
							buttonstate[i].jump=true;
						if(item)
						{
							buttonstate[i].item=true;
							if(0)//意味なしｗ(これを消すとバグが・・・orz)
							MessageBox(NULL,"","",MB_OK);
						}



						break;
					}
				}

			}
			else if(command==NETMSG_CAMERA)
			{

				for(i=0;i<playercount-1;i++)
				{
					if(fromID[i]==ID)
					{
						i++;

						sscanf(Buffer,"%f,%f,%f,%f,%f,%f",
//							&player[i].cpo.x,&player[i].cpo.y,&player[i].cpo.z,
							&player[i].cponext.x,&player[i].cponext.y,&player[i].cponext.z,
//							&player[i].cup.x,&player[i].cup.y,&player[i].cup.z,
							&player[i].cupnext.x,&player[i].cupnext.y,&player[i].cupnext.z);

						break;
					}
				}

			}


			else if(command==NETMSG_READY)//クライアントがゲーム開始準備ができた
			{

				for(i=0;i<playercount-1;i++)
				{
					if(fromID[i]==ID)
					{
						multiplaystartcount[i]=true;
						break;
					}
				}

			}

		}
		else
		{//クライアント


			int index,usecountw;



			if(command==NETMSG_INOK)
			{
				Error=CAPTION_NONE;
				sscanf(Buffer,"%d",&multiplayernum);
			}
			else if(command==NETMSG_PLAYERMAX)
			{
				Error=CAPTION_NINZUUERROR;
			}
			else if(command==NETMSG_PLAYERINFO)
			{
				sscanf(Buffer,"%d,%d,%d,%d,%d,%d",&playercount,&stagenum,&player[0].charnum,&player[1].charnum,&player[2].charnum,&player[3].charnum);

				if(playercount<=multiplayernum)
				{
					Error=CAPTION_NINZUUERROR;
				}
			}
			else if(command==NETMSG_SEAVERDOWN)
			{
				//ゲーム中だったら
				if(gamemode==GAMEMODE_GAME)
				{
					//セレクト画面に戻る
					feed[4].Start(FEEDMODE_BLACKOUT,60);
					player[multiplayernum].goal=true;
				}
				Error=CAPTION_SETUZOKUERROR;
			}
			else if(command==NETMSG_ENDGAME)
			{
				//ゲーム中だったら
				if(gamemode==GAMEMODE_GAME)
				{
					//セレクト画面に戻る
					feed[4].Start(FEEDMODE_BLACKOUT,60);
					player[multiplayernum].goal=true;
				}
			}
			else if(command==NETMSG_GAMESTART)
			{
				gamestartlimit=0;
				MultiPlayStart=true;
			}
			else if(command==NETMSG_COUNTSTART)
			{
				MultiPlayCountStart=true;

				//音楽再生
				ShowSetting(stagenum%3+6);

			}
			else if(command==NETMSG_BALL)//gameframeもここに含む
			{


				char str[100];
				int gamef;

				j=0;//jを検索文字位置として使う

				k=0;
				while((str[k]=Buffer[j])!=',')
				{k++;j++;}
				str[k]='\0';
				gamef=atoi(str);

				if(gamef>gameframe)
				{
					gameframe=gamef;

					j++;


					for(i=0;i<BALL_MAX;i++)
					{
						j+=2;
						if(Buffer[j-2]=='1')
						{
							//ボールの情報を次々と格納

							k=0;
							while((str[k]=Buffer[j])!=',')
							{k++;j++;}
							str[k]='\0';
							ball[i].info[0]=atoi(str);

							j++;k=0;
							while((str[k]=Buffer[j])!=',')
							{k++;j++;}
							str[k]='\0';
							ball[i].info[1]=atoi(str);

							j++;k=0;
							while((str[k]=Buffer[j])!=',')
							{k++;j++;}
							str[k]='\0';
							ball[i].nojudindex=atoi(str);

							j++;k=0;
							while((str[k]=Buffer[j])!=',')
							{k++;j++;}
							str[k]='\0';
							ball[i].deletecount=atoi(str);

							j++;k=0;
							while((str[k]=Buffer[j])!=',')
							{k++;j++;}
							str[k]='\0';
							ball[i].meshindex=atoi(str);

							//もし誘導でまだ存在しなかったらマトリックスのリセット
							if(ball[i].meshindex==BALLMESH_YUUDOU && !ball[i].enable)
								ball[i].ball.reset();

							j++;k=0;
							while((str[k]=Buffer[j])!=',')
							{k++;j++;}
							str[k]='\0';
							ball[i].matindex=atoi(str);

							j++;k=0;
							while((str[k]=Buffer[j])!=',')
							{k++;j++;}
							str[k]='\0';
							ball[i].gv.x=(float)atof(str);

							j++;k=0;
							while((str[k]=Buffer[j])!=',')
							{k++;j++;}
							str[k]='\0';
							ball[i].gv.y=(float)atof(str);

							j++;k=0;
							while((str[k]=Buffer[j])!=',')
							{k++;j++;}
							str[k]='\0';
							ball[i].gv.z=(float)atof(str);

							j++;k=0;
							while((str[k]=Buffer[j])!=',')
							{k++;j++;}
							str[k]='\0';
							ball[i].ball.w=(float)atof(str);

							j++;k=0;
							while((str[k]=Buffer[j])!=',')
							{k++;j++;}
							str[k]='\0';
							ball[i].ball.r=(float)atof(str);

							j++;k=0;
							while((str[k]=Buffer[j])!=',')
							{k++;j++;}
							str[k]='\0';
							ball[i].ball.po.x=(float)atof(str);

							j++;k=0;
							while((str[k]=Buffer[j])!=',')
							{k++;j++;}
							str[k]='\0';
							ball[i].ball.po.y=(float)atof(str);

							j++;k=0;
							while((str[k]=Buffer[j])!=',')
							{k++;j++;}
							str[k]='\0';
							ball[i].ball.po.z=(float)atof(str);

							j++;k=0;
							while((str[k]=Buffer[j])!=',')
							{k++;j++;}
							str[k]='\0';
							ball[i].ball.mv.x=(float)atof(str);

							j++;k=0;
							while((str[k]=Buffer[j])!=',')
							{k++;j++;}
							str[k]='\0';
							ball[i].ball.mv.y=(float)atof(str);

							j++;k=0;
							while((str[k]=Buffer[j])!=',')
							{k++;j++;}
							str[k]='\0';
							ball[i].ball.mv.z=(float)atof(str);

							j++;k=0;
							while((str[k]=Buffer[j])!=',')
							{k++;j++;}
							str[k]='\0';
							ball[i].ball.axis.x=(float)atof(str);

							j++;k=0;
							while((str[k]=Buffer[j])!=',')
							{k++;j++;}
							str[k]='\0';
							ball[i].ball.axis.y=(float)atof(str);

							j++;k=0;
							while((str[k]=Buffer[j])!=',')
							{k++;j++;}
							str[k]='\0';
							ball[i].ball.axis.z=(float)atof(str);

							ball[i].enable=true;

							j++;

						}
						else
							ball[i].enable=false;
					}


				}



			}
			else if(command==NETMSG_ITEM)
			{

				char str[100];
				int gamef;

				j=0;//jを検索文字位置として使う

				k=0;
				while((str[k]=Buffer[j])!=',')
				{k++;j++;}
				str[k]='\0';
				gamef=atoi(str);



				for(i=0;i<itemcount;i++)
				{
					//アイテムの情報を次々と格納

					j++;k=0;
					while((str[k]=Buffer[j])!=',')
					{k++;j++;}
					str[k]='\0';
					item[i].kind=atoi(str);
					j++;k=0;
					while((str[k]=Buffer[j])!=',')
					{k++;j++;}
					str[k]='\0';
					item[i].getter=atoi(str);
					if(item[i].getter==-1)
						item[i].nowpo=item[i].po;


				}

				for(i=0;i<playercount;i++)
				{
					j++;k=0;
					while((str[k]=Buffer[j])!=',')
					{k++;j++;}
					str[k]='\0';
					player[i].usekind=atoi(str);
					
					j++;k=0;
					while((str[k]=Buffer[j])!=',')
					{k++;j++;}
					str[k]='\0';
					player[i].usecount=atoi(str);
				}


			}
			else if(command==NETMSG_INFO)
			{
				int feedcount,feedcountend,feedmode;

				sscanf(Buffer,"%d,%d,%d,%d,%d,%d",&player[multiplayernum].lap,&player[multiplayernum].rank,
					&feedcount,&feedcountend,&feedmode,
					&player[multiplayernum].itemkind);

				if(!player[multiplayernum].goal)
				{
					feed[multiplayernum].count=feedcount;
					feed[multiplayernum].countend=feedcountend;
					feed[multiplayernum].mode=feedmode;
				}
				
			}
			else if(command==NETMSG_BAKUHUU)
			{
//				sprintf(Buffer,"%f,%f,%f,%f,%f,%f",p.x,p.y,p.z,sizemax,size,sizeadd);
				for(i=0;i<BOMB_MAX;i++)
				{
					if(Bomb[i].sizemax==0)
					{
						sscanf(Buffer,"%f,%f,%f,%f,%f,%f",&Bomb[i].p.x,&Bomb[i].p.y,&Bomb[i].p.z,
							&Bomb[i].sizemax,&Bomb[i].size,&Bomb[i].sizeadd);

						//軸とマトリックスを決める
						Bomb[i].axis=D3DXVECTOR3(rnd(1.0f)-0.5f,rnd(1.0f)-0.5f,rnd(1.0f)-0.5f);
						D3DXMatrixRotationX( &Bomb[i].mat, rnd(360)*rad );
						D3DXMatrixRotationY( &mat, rnd(360)*rad );
						Bomb[i].mat*=mat;
						D3DXMatrixRotationZ( &mat, rnd(360)*rad );
						Bomb[i].mat*=mat;
						
						break;
					}
				}

				//効果音再生

				if(play3d)
				{

					si=stopindex3d(sd.Bomb3D);
					sd.Bomb3D[si].Param.vPosition=Bomb[i].p;
					sd.Bomb3D[si].Param.vVelocity=D3DXVECTOR3(0,0,0);
					sd.Bomb3D[si].Buffer->SetAllParameters( &sd.Bomb3D[si].Param, DS3D_DEFERRED );
					SOUND_PLAY(sd.Bomb3D[si].Sound);

				}
				else
				{
					si=stopindex(sd.Bomb);
					SOUND_PLAY(sd.Bomb[si]);
					sd.Bomb[si]->GetBuffer(0)->SetVolume(getvolume(Bomb[i].p));
				}
				
			}

			else if(command==NETMSG_IWASTART)
			{
				//ボールと効果音のインデックスが送られてくるのでそれを元にサウンド再生！！

				sscanf(Buffer,"%d,%d",&i,&si);

				//効果音再生
				if(play3d)
				{

					sd.Iwa3D[si].Param.vPosition=D3DXVECTOR3(0,10000,0);//取り合えず場所が分からないので遠く
					sd.Iwa3D[si].Param.vVelocity=D3DXVECTOR3(0,0,0);
					sd.Iwa3D[si].Buffer->SetAllParameters( &sd.Iwa3D[si].Param, DS3D_DEFERRED );
					sd.Iwa3D[si].Sound->Stop();
					sd.Iwa3D[si].Sound->Reset();
					sd.Iwa3D[si].Sound->Play(0,DSBPLAY_LOOPING);
					ball[i].info[0]=si;
				}
				else
				{
					sd.Iwa[si]->GetBuffer(0)->SetVolume(-10000);
					sd.Iwa[si]->Stop();
					sd.Iwa[si]->Reset();
					sd.Iwa[si]->Play(0,DSBPLAY_LOOPING);
					ball[i].info[0]=si;
				}
				
			}

			else if(command==NETMSG_IWAEND)
			{
				//効果音のインデックスが送られてくるのでそれを元にサウンド再生！！

				sscanf(Buffer,"%d",&si);

				//効果音停止
				if(play3d)
					sd.Iwa3D[si].Sound->Stop();
				else
					sd.Iwa[si]->Stop();
				
			}


			else if(command==NETMSG_YUUDOUSTART)
			{
				//ボールと効果音のインデックスが送られてくるのでそれを元にサウンド再生！！

				sscanf(Buffer,"%d,%d",&i,&si);

				//効果音再生
				if(play3d)
				{

					si=stopindex3d(sd.Yudou3D);
					sd.Yudou3D[si].Param.vPosition=D3DXVECTOR3(0,10000,0);//取り合えず場所が分からないので遠く
					sd.Yudou3D[si].Param.vVelocity=D3DXVECTOR3(0,0,0);
					sd.Yudou3D[si].Buffer->SetAllParameters( &sd.Yudou3D[si].Param, DS3D_DEFERRED );
					sd.Yudou3D[si].Sound->Stop();
					sd.Yudou3D[si].Sound->Reset();
					sd.Yudou3D[si].Sound->Play(0,DSBPLAY_LOOPING);
					ball[i].info[1]=si;
				}
				else
				{
					si=stopindex(sd.Yudou);
					sd.Yudou[si]->GetBuffer(0)->SetVolume(-10000);
					sd.Yudou[si]->Stop();
					sd.Yudou[si]->Reset();
					sd.Yudou[si]->Play(0,DSBPLAY_LOOPING);
					ball[i].info[1]=si;
				}
				
				
			}

			else if(command==NETMSG_YUUDOUEND)
			{
				//効果音のインデックスが送られてくるのでそれを元にサウンド再生！！

				sscanf(Buffer,"%d",&si);

				//効果音停止
				if(play3d)
					sd.Yudou3D[si].Sound->Stop();
				else
					sd.Yudou[si]->Stop();

			}

			//NETMSG_SHOTSTART,NETMSG_SHOT,NETMSG_FIRE,NETMSG_MIZUSTART,NETMSG_TAIHOU,NETMSG_BOMBOUT,
			//NETMSG_GURABISTART,NETMSG_GURABI



			//アイテム効果音など
			if(command==NETMSG_TAIHOU)
			{//index
				sscanf(Buffer,"%d",&index);
				player[index].ClientItemKind=ITEMKIND_TAIHOU;
				player[index].ClientItem=1;
			}
			else if(command==NETMSG_FIRE)
			{//index,usecount
				sscanf(Buffer,"%d,%d",&index,&usecountw);
				player[index].ClientItemCount=usecountw;
				player[index].ClientItemKind=ITEMKIND_FIRE;
				player[index].ClientItem=2;
			}
			else if(command==NETMSG_FIRESTART)
			{//index
				sscanf(Buffer,"%d",&index);
				player[index].ClientItemKind=ITEMKIND_FIRE;
				player[index].ClientItem=1;
			}
			else if(command==NETMSG_MIZUSTART)
			{//index
				sscanf(Buffer,"%d",&index);
				player[index].ClientItemKind=ITEMKIND_MIZU;
				player[index].ClientItem=1;
			}
			else if(command==NETMSG_SHOT)
			{//index,usecount
				sscanf(Buffer,"%d,%d",&index,&usecountw);
				player[index].ClientItemCount=usecountw;
				player[index].ClientItemKind=ITEMKIND_SHOT;
				player[index].ClientItem=2;
			}
			else if(command==NETMSG_BOMB)
			{//index
				sscanf(Buffer,"%d",&index);
				player[index].ClientItemKind=ITEMKIND_BOMB;
				player[index].ClientItem=1;
			}
			else if(command==NETMSG_YUUDOU)
			{//index
				sscanf(Buffer,"%d",&index);
				player[index].ClientItemKind=ITEMKIND_YUUDOU;
				player[index].ClientItem=1;
			}
			else if(command==NETMSG_GURABI)
			{//index,usecount
				sscanf(Buffer,"%d,%d",&index,&usecountw);
				player[index].ClientItemCount=usecountw;
				player[index].ClientItemKind=ITEMKIND_GURABI;
				player[index].ClientItem=2;
			}
			else if(command==NETMSG_GURABISTART)
			{//index
				sscanf(Buffer,"%d",&index);
				player[index].ClientItemKind=ITEMKIND_GURABI;
				player[index].ClientItem=1;
			}


			else if(command==NETMSG_STAGESTATE)
			{

				if(stagenum==6)//ゆれる鉄球
				{
					sscanf(Buffer,"%f,%f,%f,%f",&stagestate[10].s,&stagestate[11].s,&stagestate[12].s,&stagestate[13].s);
				}
				else if(stagenum==8)//動く大砲
				{
					sscanf(Buffer,"%f,%f",&stagestate[1].s,&gun[0].v.z);
				}

			}




		}





	}



}




void SendAllPlayerInfo(int count)//プレイヤーの全情報
{

	int i;

	for(i=0;i<count-1;i++)
	{

		sprintf(Buffer,"%d,%d,%d,%d,%d,%d",playercount,stagenum,player[0].charnum,player[1].charnum,player[2].charnum,player[3].charnum);
		SetMsg(Buffer,myID,NETMSG_PLAYERINFO);
		sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));

	}

}


void SendMyPlayerInfo()//プレイヤーの情報
{
//	MessageBox(hWnd,"クライアント、プレイヤーチェンジ","",MB_OK);
	sprintf(Buffer,"%d",player[multiplayernum].charnum);
	SetMsg(Buffer,myID,NETMSG_SETPLAYER);
	sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&addr, (int)sizeof(addr));
}

void SendPlayerOut()
{
	//MessageBox(hWnd,"蔵ダウン","",MB_OK);
	Buffer[0]='\0';
	SetMsg(Buffer,myID,NETMSG_PLAYEROUT);
	sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&addr, (int)sizeof(addr));
}




void SendSeaverDown()
{
	//MessageBox(hWnd,"鯖ダウン","",MB_OK);
	int i;

	for(i=0;i<playercount-1;i++)
	{
		Buffer[0]='\0';
		SetMsg(Buffer,myID,NETMSG_SEAVERDOWN);
		sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
	}
	
}

void SendEndGame()
{
	int i;

	for(i=0;i<playercount-1;i++)
	{
		Buffer[0]='\0';
		SetMsg(Buffer,myID,NETMSG_ENDGAME);
		sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
	}
	
}



void Sendokcancel(bool ok)//決定か変更か
{
	Buffer[0]='\0';
	if(ok)
		SetMsg(Buffer,myID,NETMSG_KETTEI);
	else
		SetMsg(Buffer,myID,NETMSG_HENKOU);
	sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&addr, (int)sizeof(addr));

}

void SendGameStart()
{
	int i;

	for(i=0;i<playercount-1;i++)
	{
		Buffer[0]='\0';
		SetMsg(Buffer,myID,NETMSG_GAMESTART);
		sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
	}
	
}


void SendBakuhuu(int index)//indexには爆風のインデックスを格納
{
	int i;

	for(i=0;i<playercount-1;i++)
	{
		sprintf(Buffer,"%f,%f,%f,%f,%f,%f",Bomb[index].p.x,Bomb[index].p.y,Bomb[index].p.z,
			Bomb[index].sizemax,Bomb[index].size,Bomb[index].sizeadd);
		SetMsg(Buffer,myID,NETMSG_BAKUHUU);
		sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
	}
	
}

void SendIwaStart(int bi,int si)//biにはボールのインデックス、siには効果音ののインデックスを格納
{
	int i;

	for(i=0;i<playercount-1;i++)
	{
		sprintf(Buffer,"%d,%d",bi,si);
		SetMsg(Buffer,myID,NETMSG_IWASTART);
		sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
	}

}

void SendIwaEnd(int index)//indexには効果音ののインデックスを格納
{
	int i;

	for(i=0;i<playercount-1;i++)
	{
		sprintf(Buffer,"%d",index);
		SetMsg(Buffer,myID,NETMSG_IWAEND);
		sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
	}

}


void SendYuudouStart(int bi,int si)//ibiにはボールのインデックス、siには効果音ののインデックスを格納
{
	int i;

	for(i=0;i<playercount-1;i++)
	{
		sprintf(Buffer,"%d,%d",bi,si);
		SetMsg(Buffer,myID,NETMSG_YUUDOUSTART);
		sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
	}

}

void SendYuudouEnd(int index)//indexには効果音ののインデックスを格納
{
	int i;

	for(i=0;i<playercount-1;i++)
	{
		sprintf(Buffer,"%d",index);
		SetMsg(Buffer,myID,NETMSG_YUUDOUEND);
		sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
	}

}


void SendItem(int item,bool start=false,int index=0,int usecount=0)//itemにはアイテムの種類を格納,startはスタート時のイベントならtrueを格納,usecountにはusecountを格納,indexにはそのときによっていろいろ・・・
{
	int i;

	for(i=0;i<playercount-1;i++)
	{
		if(item==ITEMKIND_TAIHOU)
		{//誰が使ったか分かればいいのでindexが必要
			sprintf(Buffer,"%d",index);
			SetMsg(Buffer,myID,NETMSG_TAIHOU);
			sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
		}
		else if(item==ITEMKIND_FIRE)
		{
			if(start)
			{//誰が使ったか分かればいいのでindexが必要
				sprintf(Buffer,"%d",index);
				SetMsg(Buffer,myID,NETMSG_FIRESTART);
				sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
			}
			else
			{//誰が使ったか分かればいいのでindexとusecountが必要
				sprintf(Buffer,"%d,%d",index,usecount);
				SetMsg(Buffer,myID,NETMSG_FIRE);
				sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
			}
		}
		else if(item==ITEMKIND_MIZU)
		{//誰が使ったかが分かればいいのでindexが必要
			sprintf(Buffer,"%d",index);
			SetMsg(Buffer,myID,NETMSG_MIZUSTART);
			sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
		}
		else if(item==ITEMKIND_SHOT)
		{//誰が撃ったかわかるように、index,usecountが必要
			sprintf(Buffer,"%d,%d",index,usecount);
			SetMsg(Buffer,myID,NETMSG_SHOT);
			sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
		}
		else if(item==ITEMKIND_BOMB)
		{//誰から出たか分かればいいのでindexが必要
			sprintf(Buffer,"%d",index);
			SetMsg(Buffer,myID,NETMSG_BOMB);
			sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
		}
		else if(item==ITEMKIND_YUUDOU)
		{//誰から出たか分かればいいのでindexが必要
			sprintf(Buffer,"%d",index);
			SetMsg(Buffer,myID,NETMSG_YUUDOU);
			sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
		}
		else if(item==ITEMKIND_GURABI)
		{
			if(start)
			{//誰が使ったのか分かればいいのでindexが必要
				sprintf(Buffer,"%d",index);
				SetMsg(Buffer,myID,NETMSG_GURABISTART);
				sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
			}
			else
			{//誰が使ったのか分かればいいのでindexとusecountが必要
				sprintf(Buffer,"%d,%d",index,usecount);
				SetMsg(Buffer,myID,NETMSG_GURABI);
				sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
			}

		}
	}

}

void SendStageState()
{//ステージ固有の情報を送る
	int i;

	for(i=0;i<playercount-1;i++)
	{
		if(stagenum==6)//ゆれる鉄球
		{
			sprintf(Buffer,"%f,%f,%f,%f",stagestate[10].s,stagestate[11].s,stagestate[12].s,stagestate[13].s);
		}
		else if(stagenum==8)//動く大砲
		{
			sprintf(Buffer,"%f,%f",stagestate[1].s,gun[0].v.z);
		}
		SetMsg(Buffer,myID,NETMSG_STAGESTATE);
		sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
	}

}


void SendCountStart()
{
	//準備できたプレイヤーにのみ送る
	int i;

	for(i=0;i<playercount-1;i++)
	{
		if(multiplaystartcount[i])
		{
			Buffer[0]='\0';
			SetMsg(Buffer,myID,NETMSG_COUNTSTART);
			sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
		}
	}
	
}

//送られてきた文字列より、本文,ID,コマンドとに分ける関数(本文はsに格納！！)
void GetMsg(char *s,int *id,int *command)
{
	int i;
	for(i=0;true;i++)
		if(s[i]==':')
			break;
	sscanf(&s[i+1],"%d:%d",id,command);
	s[i]='\0';
}

//本文より,ID,コマンド、送る文字列に変換する関数(本文はsに格納！！)
void SetMsg(char *s,int id,int command)
{
	char str[100];
	sprintf(str,":%d:%d",id,command);
	strcat(s,str);
}




int GetNowPlayerCount()
{
	int i,count=1;
	for(i=0;i<playercount-1;i++)
	{
		if(fromID[i]!=-1)
			count++;
	}
	return count;
}




#endif
