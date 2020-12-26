#include "Socket.h"

//�N���C�A���g���ڑ����Ă����Ƃ��Ɏg�p����郁�b�Z�[�W


#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
//#include <WinSock2.h>


int SocketClass::AutoMsg(UINT Msg,LPARAM lParam,int *Event)
{

	if(Msg>=(UINT)MsgNum && Msg<=(UINT)MsgNum+ClientMax)//�l�b�g���[�N���b�Z�[�W���̃`�F�b�N
	{
		//�C�x���g�ԍ��擾(ACCEPT,CONNECT,READ,CLOSE�Ȃ�)
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
			//�T�[�o�[���A�V�K�ڑ��N���C�A���g����̃��b�Z�[�W

			if(*Event==FD_ACCEPT)
			{

				//�����Ă�ԍ���T��
				for(i=0;i<ClientMax;i++)
				{
					if(client[i].enable==false)
					{

						//����ς����Ŋm���H

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
			//�T�[�o�[���A�ڑ��ς݃N���C�A���g����̃��b�Z�[�W
			int ClientNum=(int)Msg-MsgNum-1;
			
			//���ԍX�V
			client[ClientNum].LastTime=(long)clock();

			if(*Event==FD_READ)
			{
				//�N���C�A���g�ԍ���Ԃ�
				return ClientNum;
			}
			else if(*Event==FD_CLOSE)
			{
				//����Ƀ\�P�b�g���Ĉꉞ�����ԍ���Ԃ�
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
			//�N���C�A���g���A�T�[�o�[����̃��b�Z�[�W
			//���ԍX�V
			LastTime=(long)clock();

			if(*Event==FD_CLOSE)
			{
				//�N���C�A���g�I��
				Exit();
			}

			return 0;//�N���C�A���g�̂Ƃ��͈ꉞ0��Ԃ�
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



	//�ڑ������I�I
	ClientEnable=true;
	LastTime=clock();
	return true;

}


void SocketClass::Exit()
{
	if(ServerEnable)
	{
		ServerEnable=false;

		//�S�\�P�b�g�ƃ��X���\�P�b�g�I��
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
	//�\�P�b�g�����
	closesocket(client[index].s);
	client[index].enable=false;
}























int SocketClass::CheckTimeOut()
{
	int i;

	if(ServerEnable)
	{
		//�N���C�A���g�������Ă��Ȃ����𒲂ׂ�
		for(i=0;i<ClientMax;i++)
		{
			if(client[i].enable)
			{
				if((float)((long)clock()-client[i].LastTime)/1000.0f>OutTime)
				{
					//����Ƀ\�P�b�g���Ĉꉞ�����ԍ���Ԃ�
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
			//�N���C�A���g�I��
			Exit();
			return 0;
		}
	}

	return -1;
}




//size��0�ȉ��̂Ƃ��̓w�b�_�̂ݑ��M
bool SocketClass::Send(short int kind,char* data,long int size,int index)
{
	//�w�b�_�������I�ɂ��đ��M����
	if(!ServerEnable && !ClientEnable)
		return false;

	//�w�b�_����
	HeadStruct head;
	head.kind=kind;
	head.size=size;
	head.rnd=(char)(rand()%256);

	//���M����f�[�^&�w�b�_�����ꂼ��Í���
	//(�Ƃ肠�����Ȃɂ����Ȃ��Ă���)

	if(ServerEnable)
	{
		//�w�b�_���M
		if(send(client[index].s,(char*)&head,sizeof(head),0)==SOCKET_ERROR)
			return false;

		//�f�[�^���M
		if(size>0)
		{
			if(send(client[index].s,data,size,0)==SOCKET_ERROR)
				return false;
		}
	}
	else
	{
		//�w�b�_���M
		if(send(s,(char*)&head,sizeof(head),0)==SOCKET_ERROR)
			return false;

		if(size>0)
		{
			//�f�[�^���M
			if(send(s,data,size,0)==SOCKET_ERROR)
				return false;
		}
	}
	return true;
}


bool SocketClass::SendAll(short int kind,char* data,long int size)
{
	//�T�[�o�[�I�����[
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
	HeadStruct headstruct;//�w�b�_���i�[�p
	SOCKET *sockp;//�\�P�b�g�|�C���^
	bool *headenp;//�w�b�_�L���|�C���^

	//�w�b�_�L���ƃ\�P�b�g���|�C���^��
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


	//�w�b�_��񂪖�����������擾���Ȃ�
	if(!(*headenp))
		return SOCKET_ERROR;

	//�Ƃ肠�����w�b�_�����擾
	if(recv(*sockp,(char*)&headstruct,sizeof(headstruct),0)==SOCKET_ERROR)
		return SOCKET_ERROR;	


	//�w�b�_�������I�I
	//(�Ƃ肠�������̂܂܂ł���)


	//���悢�������M
	if((getsize=recv(*sockp,data,headstruct.size,0))==SOCKET_ERROR)
		return SOCKET_ERROR;


	//��񕡍����I�I
	//(�Ƃ肠�������̂܂܂ł���)


	//��������M�ł����̂ŁA�w�b�_�𖳌��ɂ���
	*headenp=false;

	return getsize;
}





//���܂��Ă���f�[�^�̎�ނ�Ԃ�
bool SocketClass::GetMsgKind(int *kind,int *size,int index)
{
	if(!ServerEnable && !ClientEnable)
		return false;

	//�܂��擾���Ă��Ȃ��ꍇ�Asizeof(HeadStruct)���̃f�[�^�����܂��Ă��邩���ׁA���܂��Ă���������擾���A��ނ�Ԃ�(���܂��Ă��Ȃ�������false��Ԃ�)

	int getsize;//�T�C�Y�i�[�p
	HeadStruct headstruct;//�w�b�_���i�[�p
	SOCKET *sockp;//�\�P�b�g�|�C���^
	bool *headenp;//�w�b�_�L���|�C���^


	//�w�b�_�L���ƃ\�P�b�g���|�C���^��
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


	//�f�[�^�͎c�����܂܁A�w�b�_�����擾
	if((getsize=recv(*sockp,(char*)&headstruct,sizeof(headstruct),MSG_PEEK)) < sizeof(headstruct) )
		return false;


	//�w�b�_�������I�I
	//(�Ƃ肠�����������Ȃ�)


	//�w�b�_��񂪗L���ɂȂ��Ă�����܂��f�[�^��recv�ŏ����Ă��Ȃ��̂ŁA���̂܂܂̏���Ԃ�
	if(*headenp)
	{
		*kind=headstruct.kind;
		if(size) *size=headstruct.size;
		return true;
	}

	//��񕔂̃T�C�Y��0���������M��������Ď�ނ�Ԃ�(���̏ꍇ�Aheadenable��false�̂܂܂ɂ��Ă���)
	if(headstruct.size==0)//��ނ����̃f�[�^
	{
		if(recv(*sockp,(char*)&Buffer,sizeof(headstruct),0) == SOCKET_ERROR )//��M�����Ⴄ�I�I(�w�b�_�͂��łɕ���������Ă���̂�Buffer�ɏ�������)
			return false;
		*kind=headstruct.kind;
		if(size) *size=headstruct.size;
		return true;
	}


	//�\�P�b�g�Ƃ��܂��Ă���f�[�^�̃T�C�Y���擾�ł���T�C�Y���ǂ����𒲂ׂ�
	if(recv(*sockp,(char*)Buffer,sizeof(Buffer),MSG_PEEK) < (signed)(sizeof(headstruct)+headstruct.size) )
		return false;

	//�ǂ����f�[�^�͂����Ɠ͂��Ă���炵���̂ŁA�w�b�_��L���ɂ��A��ނȂǂ�Ԃ��ďI��
	*kind=headstruct.kind;
	if(size) *size=headstruct.size;
	*headenp=true;

	return true;
}



//�Í���
void SocketClass::Encryption(char *data,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		data[i]+=i+140;
	}
}

//������
void SocketClass::Composite(char *data,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		data[i]-=i+140;
	}
}

