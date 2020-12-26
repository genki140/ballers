#ifndef NET_HED
#define NET_HED


#include <winsock.h>
#include <conio.h>


enum NETMSG_ENUM{	NETMSG_INOK,NETMSG_PLAYERMAX,NETMSG_SEAVERDOWN,NETMSG_ENDGAME,NETMSG_GAMESTART,NETMSG_COUNTSTART,NETMSG_READY,
					NETMSG_PLAYERINFO,NETMSG_INPUT,
					NETMSG_PLAYERIN,NETMSG_PLAYEROUT,NETMSG_SETPLAYER,NETMSG_KETTEI,NETMSG_HENKOU,
					NETMSG_BALL,NETMSG_CAMERA,NETMSG_ITEM,
					NETMSG_INFO,//NETMSG_INFO�́A�v���C���[�S���̃��b�v�ƃ����N�A�����A�C�e���ƌ��ʒ��A�C�e�����

					//���̑��̂�����Ƃ����f�[�^(�T�[�o�[����N���C�A���g�ֈ���I�ɑ���f�[�^)
					NETMSG_BAKUHUU,NETMSG_IWASTART,NETMSG_IWAEND,NETMSG_YUUDOUSTART,NETMSG_YUUDOUEND,

					NETMSG_SHOT,NETMSG_FIRE,NETMSG_FIRESTART,NETMSG_MIZUSTART,NETMSG_TAIHOU,
					NETMSG_BOMB,NETMSG_YUUDOU,NETMSG_GURABISTART,NETMSG_GURABI,

					NETMSG_STAGESTATE

					};


//�l�b�g���[�N�p
char Buffer[65536];



//�l�b�g���[�N�֌W�̕ϐ�
#define MY_MSG (WM_USER+1)

WSADATA wsaData;
SOCKADDR_IN addr,from[3],tempsock;
HOSTENT *lpHost;



//bool AddOK;//�Ղꂢ��[�Q���n�j���ǂ������A�T�[�o�[����A���Ă����Ƃ��Ɋi�[���Ă���


void GetMsg(char *s,int *id,int *command);
void SetMsg(char *s,int id,int command);





bool SetNetwork()
{
	//�l�b�g���[�N�̐ݒ������(�߂�ǂ��̂�UDP)

	if (WSAStartup(MAKEWORD(1, 1), &wsaData))
		return false;

	//�\�P�b�g�I�[�v��
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
//		GetNowPlayerCount=1;//1�͎���

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

		//�]���ł��邩�ȁH(�ꉞ�e�X�g)
		if (sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&addr, (int)sizeof(addr)) == SOCKET_ERROR)
		{
			closesocket(s);
			WSACleanup();
			return false;
		}

		//��̓��b�Z�[�W������܂ő҂̂݁I�I(��莞�ԗ��Ȃ���������������G���[���b�Z�[�W�\��)


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

	GetMsg(Buffer,&ID,&command);//�f�[�^�ҏW

	if(ID!=myID)//��������̃��b�Z�[�W�łȂ����
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

						//�����Ă�Ƃ����T��
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
					{//�����l�������ς��I�I
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
						//�v���C���[i+1�𓮂���

						i++;
//						MessageBox(hWnd,Buffer,"",MB_OK);

						sscanf(Buffer,"%d,%d,%f,%f",&item,&jump,&buttonstate[i].x,&buttonstate[i].y);

						if(jump)
							buttonstate[i].jump=true;
						if(item)
						{
							buttonstate[i].item=true;
							if(0)//�Ӗ��Ȃ���(����������ƃo�O���E�E�Eorz)
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


			else if(command==NETMSG_READY)//�N���C�A���g���Q�[���J�n�������ł���
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
		{//�N���C�A���g


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
				//�Q�[������������
				if(gamemode==GAMEMODE_GAME)
				{
					//�Z���N�g��ʂɖ߂�
					feed[4].Start(FEEDMODE_BLACKOUT,60);
					player[multiplayernum].goal=true;
				}
				Error=CAPTION_SETUZOKUERROR;
			}
			else if(command==NETMSG_ENDGAME)
			{
				//�Q�[������������
				if(gamemode==GAMEMODE_GAME)
				{
					//�Z���N�g��ʂɖ߂�
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

				//���y�Đ�
				ShowSetting(stagenum%3+6);

			}
			else if(command==NETMSG_BALL)//gameframe�������Ɋ܂�
			{


				char str[100];
				int gamef;

				j=0;//j�����������ʒu�Ƃ��Ďg��

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
							//�{�[���̏������X�Ɗi�[

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

							//�����U���ł܂����݂��Ȃ�������}�g���b�N�X�̃��Z�b�g
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

				j=0;//j�����������ʒu�Ƃ��Ďg��

				k=0;
				while((str[k]=Buffer[j])!=',')
				{k++;j++;}
				str[k]='\0';
				gamef=atoi(str);



				for(i=0;i<itemcount;i++)
				{
					//�A�C�e���̏������X�Ɗi�[

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

						//���ƃ}�g���b�N�X�����߂�
						Bomb[i].axis=D3DXVECTOR3(rnd(1.0f)-0.5f,rnd(1.0f)-0.5f,rnd(1.0f)-0.5f);
						D3DXMatrixRotationX( &Bomb[i].mat, rnd(360)*rad );
						D3DXMatrixRotationY( &mat, rnd(360)*rad );
						Bomb[i].mat*=mat;
						D3DXMatrixRotationZ( &mat, rnd(360)*rad );
						Bomb[i].mat*=mat;
						
						break;
					}
				}

				//���ʉ��Đ�

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
				//�{�[���ƌ��ʉ��̃C���f�b�N�X�������Ă���̂ł�������ɃT�E���h�Đ��I�I

				sscanf(Buffer,"%d,%d",&i,&si);

				//���ʉ��Đ�
				if(play3d)
				{

					sd.Iwa3D[si].Param.vPosition=D3DXVECTOR3(0,10000,0);//��荇�����ꏊ��������Ȃ��̂ŉ���
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
				//���ʉ��̃C���f�b�N�X�������Ă���̂ł�������ɃT�E���h�Đ��I�I

				sscanf(Buffer,"%d",&si);

				//���ʉ���~
				if(play3d)
					sd.Iwa3D[si].Sound->Stop();
				else
					sd.Iwa[si]->Stop();
				
			}


			else if(command==NETMSG_YUUDOUSTART)
			{
				//�{�[���ƌ��ʉ��̃C���f�b�N�X�������Ă���̂ł�������ɃT�E���h�Đ��I�I

				sscanf(Buffer,"%d,%d",&i,&si);

				//���ʉ��Đ�
				if(play3d)
				{

					si=stopindex3d(sd.Yudou3D);
					sd.Yudou3D[si].Param.vPosition=D3DXVECTOR3(0,10000,0);//��荇�����ꏊ��������Ȃ��̂ŉ���
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
				//���ʉ��̃C���f�b�N�X�������Ă���̂ł�������ɃT�E���h�Đ��I�I

				sscanf(Buffer,"%d",&si);

				//���ʉ���~
				if(play3d)
					sd.Yudou3D[si].Sound->Stop();
				else
					sd.Yudou[si]->Stop();

			}

			//NETMSG_SHOTSTART,NETMSG_SHOT,NETMSG_FIRE,NETMSG_MIZUSTART,NETMSG_TAIHOU,NETMSG_BOMBOUT,
			//NETMSG_GURABISTART,NETMSG_GURABI



			//�A�C�e�����ʉ��Ȃ�
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

				if(stagenum==6)//����S��
				{
					sscanf(Buffer,"%f,%f,%f,%f",&stagestate[10].s,&stagestate[11].s,&stagestate[12].s,&stagestate[13].s);
				}
				else if(stagenum==8)//������C
				{
					sscanf(Buffer,"%f,%f",&stagestate[1].s,&gun[0].v.z);
				}

			}




		}





	}



}




void SendAllPlayerInfo(int count)//�v���C���[�̑S���
{

	int i;

	for(i=0;i<count-1;i++)
	{

		sprintf(Buffer,"%d,%d,%d,%d,%d,%d",playercount,stagenum,player[0].charnum,player[1].charnum,player[2].charnum,player[3].charnum);
		SetMsg(Buffer,myID,NETMSG_PLAYERINFO);
		sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));

	}

}


void SendMyPlayerInfo()//�v���C���[�̏��
{
//	MessageBox(hWnd,"�N���C�A���g�A�v���C���[�`�F���W","",MB_OK);
	sprintf(Buffer,"%d",player[multiplayernum].charnum);
	SetMsg(Buffer,myID,NETMSG_SETPLAYER);
	sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&addr, (int)sizeof(addr));
}

void SendPlayerOut()
{
	//MessageBox(hWnd,"���_�E��","",MB_OK);
	Buffer[0]='\0';
	SetMsg(Buffer,myID,NETMSG_PLAYEROUT);
	sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&addr, (int)sizeof(addr));
}




void SendSeaverDown()
{
	//MessageBox(hWnd,"�I�_�E��","",MB_OK);
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



void Sendokcancel(bool ok)//���肩�ύX��
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


void SendBakuhuu(int index)//index�ɂ͔����̃C���f�b�N�X���i�[
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

void SendIwaStart(int bi,int si)//bi�ɂ̓{�[���̃C���f�b�N�X�Asi�ɂ͌��ʉ��̂̃C���f�b�N�X���i�[
{
	int i;

	for(i=0;i<playercount-1;i++)
	{
		sprintf(Buffer,"%d,%d",bi,si);
		SetMsg(Buffer,myID,NETMSG_IWASTART);
		sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
	}

}

void SendIwaEnd(int index)//index�ɂ͌��ʉ��̂̃C���f�b�N�X���i�[
{
	int i;

	for(i=0;i<playercount-1;i++)
	{
		sprintf(Buffer,"%d",index);
		SetMsg(Buffer,myID,NETMSG_IWAEND);
		sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
	}

}


void SendYuudouStart(int bi,int si)//ibi�ɂ̓{�[���̃C���f�b�N�X�Asi�ɂ͌��ʉ��̂̃C���f�b�N�X���i�[
{
	int i;

	for(i=0;i<playercount-1;i++)
	{
		sprintf(Buffer,"%d,%d",bi,si);
		SetMsg(Buffer,myID,NETMSG_YUUDOUSTART);
		sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
	}

}

void SendYuudouEnd(int index)//index�ɂ͌��ʉ��̂̃C���f�b�N�X���i�[
{
	int i;

	for(i=0;i<playercount-1;i++)
	{
		sprintf(Buffer,"%d",index);
		SetMsg(Buffer,myID,NETMSG_YUUDOUEND);
		sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
	}

}


void SendItem(int item,bool start=false,int index=0,int usecount=0)//item�ɂ̓A�C�e���̎�ނ��i�[,start�̓X�^�[�g���̃C�x���g�Ȃ�true���i�[,usecount�ɂ�usecount���i�[,index�ɂ͂��̂Ƃ��ɂ���Ă��낢��E�E�E
{
	int i;

	for(i=0;i<playercount-1;i++)
	{
		if(item==ITEMKIND_TAIHOU)
		{//�N���g������������΂����̂�index���K�v
			sprintf(Buffer,"%d",index);
			SetMsg(Buffer,myID,NETMSG_TAIHOU);
			sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
		}
		else if(item==ITEMKIND_FIRE)
		{
			if(start)
			{//�N���g������������΂����̂�index���K�v
				sprintf(Buffer,"%d",index);
				SetMsg(Buffer,myID,NETMSG_FIRESTART);
				sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
			}
			else
			{//�N���g������������΂����̂�index��usecount���K�v
				sprintf(Buffer,"%d,%d",index,usecount);
				SetMsg(Buffer,myID,NETMSG_FIRE);
				sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
			}
		}
		else if(item==ITEMKIND_MIZU)
		{//�N���g��������������΂����̂�index���K�v
			sprintf(Buffer,"%d",index);
			SetMsg(Buffer,myID,NETMSG_MIZUSTART);
			sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
		}
		else if(item==ITEMKIND_SHOT)
		{//�N�����������킩��悤�ɁAindex,usecount���K�v
			sprintf(Buffer,"%d,%d",index,usecount);
			SetMsg(Buffer,myID,NETMSG_SHOT);
			sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
		}
		else if(item==ITEMKIND_BOMB)
		{//�N����o����������΂����̂�index���K�v
			sprintf(Buffer,"%d",index);
			SetMsg(Buffer,myID,NETMSG_BOMB);
			sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
		}
		else if(item==ITEMKIND_YUUDOU)
		{//�N����o����������΂����̂�index���K�v
			sprintf(Buffer,"%d",index);
			SetMsg(Buffer,myID,NETMSG_YUUDOU);
			sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
		}
		else if(item==ITEMKIND_GURABI)
		{
			if(start)
			{//�N���g�����̂�������΂����̂�index���K�v
				sprintf(Buffer,"%d",index);
				SetMsg(Buffer,myID,NETMSG_GURABISTART);
				sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
			}
			else
			{//�N���g�����̂�������΂����̂�index��usecount���K�v
				sprintf(Buffer,"%d,%d",index,usecount);
				SetMsg(Buffer,myID,NETMSG_GURABI);
				sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
			}

		}
	}

}

void SendStageState()
{//�X�e�[�W�ŗL�̏��𑗂�
	int i;

	for(i=0;i<playercount-1;i++)
	{
		if(stagenum==6)//����S��
		{
			sprintf(Buffer,"%f,%f,%f,%f",stagestate[10].s,stagestate[11].s,stagestate[12].s,stagestate[13].s);
		}
		else if(stagenum==8)//������C
		{
			sprintf(Buffer,"%f,%f",stagestate[1].s,gun[0].v.z);
		}
		SetMsg(Buffer,myID,NETMSG_STAGESTATE);
		sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
	}

}


void SendCountStart()
{
	//�����ł����v���C���[�ɂ̂ݑ���
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

//�����Ă�����������A�{��,ID,�R�}���h�Ƃɕ�����֐�(�{����s�Ɋi�[�I�I)
void GetMsg(char *s,int *id,int *command)
{
	int i;
	for(i=0;true;i++)
		if(s[i]==':')
			break;
	sscanf(&s[i+1],"%d:%d",id,command);
	s[i]='\0';
}

//�{�����,ID,�R�}���h�A���镶����ɕϊ�����֐�(�{����s�Ɋi�[�I�I)
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
