#include "stdafx.h"
#include <windows.h>
#include <winsock2.h>
#include "resource.h"



//���łɃv���O�������N�����Ă��Ȃ����𒲂ׂ�
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

	//�t�@�C�����œ�����������
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
 
	/* �t�@�C���T�C�Y�𒲍� */ 
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

	//�N���C�A���g�����������ăX�^�[�g�I�I

	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(2, 0), &wsaData))
	{
		WSACleanup();
		MessageBox(NULL,"�N���C�A���g�̏������Ɏ��s���܂���","�G���[",MB_OK);
		return false;
	}

	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
	if (s < 0) {
		MessageBox(NULL,"�N���C�A���g�̏������Ɏ��s���܂���","�G���[",MB_OK);
		return false;
	}

	HOSTENT *lpHost = gethostbyname(url);

	if (lpHost == NULL) {
		unsigned int addr = inet_addr(url);
		lpHost = gethostbyaddr((char *)&addr, 4, AF_INET);
	}

	if (lpHost == NULL) {
		closesocket(s);
		MessageBox(NULL,"�T�[�o�[��������܂���ł���","�G���[",MB_OK);
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
			MessageBox(NULL,"�T�[�o�[�Ƃ̒ʐM�Ɏ��s���܂���\n�T�[�o�[�����s����Ă��Ȃ���,�ق��̃��[�U�[���ڑ����ł�","�X�V�G���[",MB_OK);
			return false;
		}
	}


	//�T�[�o�[����̃��b�Z�[�W��҂�

	char buf[1024];

	timeval waittime;
	fd_set rdps;
	int ret;

	waittime.tv_sec = 10;	/* �^�C���A�E�g�b����ݒ肷�� */
	waittime.tv_usec = 0;
	FD_ZERO(&rdps);			/* ���������� */
	FD_SET(s,&rdps);		/* select����\�P�b�g��ǉ����� */

	ret = select(FD_SETSIZE,&rdps,(fd_set *)0,(fd_set *)0,&waittime);
	if(ret == SOCKET_ERROR)
	{
		//�\�����ʃG���[
		MessageBox(NULL,"�\�����ʃG���[���������܂���","�G���[",MB_OK);
		return false;
	}
	if(ret == 0)
	{
		//�^�C���A�E�g
		MessageBox(NULL,"�T�[�o�[����̉������������߃^�C���A�E�g���܂���","�G���[",MB_OK);
		return false;
	}
	if (FD_ISSET(s, &rdps)) {
		//2�����ǂݍ���
		recv(s,buf,1024,0);
		if(strcmp(buf,"OK")!=0)
		{
			MessageBox(NULL,"�T�[�o�[�Ƃ̒ʐM�Ɏ��s���܂���","�G���[",MB_OK);
			return false;
		}
	}



	//���M����

	/*�f�[�^�̎�M��(�S��unsigned)
	��"OK"
	��4�o�C�g=���
	��4�o�C�g=�X�e�[�W�ԍ�(21�ȍ~�Ńo�[�T�X�ƌ����Ӗ�)
	��4�o�C�g=�L�^����(�t���[��)
	��4�o�C�g=�Í��f�[�^
	��4�o�C�g=�t�@�C���T�C�Y
	��30�o�C�g=���O
	���ۂ̃f�[�^�𑗐M*/

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

	send(s,(char*)(&kind),4,0);//���
	send(s,(char*)(&index),4,0);
	send(s,(char*)(&time),4,0);
	send(s,(char*)(&timeangou),4,0);
	send(s,(char*)(&angou),4,0);
	send(s,(char*)(&size),4,0);
	send(s,name,30,0);


	//���ۂ̃f�[�^(1024�����Â���)
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
				//���M
				send(s,buf,count,0);
				count=0;
			}
		}
		else
		{
			//EOF
			if(count!=0)
			{
				//���M
				send(s,buf,count,0);

				break;
			}
		}
	}	
	fclose(file);


	//�T�[�o�[����̃��b�Z�[�W��҂�

	ret = select(FD_SETSIZE,&rdps,(fd_set *)0,(fd_set *)0,&waittime);
	if(ret == SOCKET_ERROR)
	{
		//�\�����ʃG���[
		MessageBox(NULL,"�\�����ʃG���[���������܂���","�G���[",MB_OK);
		return false;
	}
	if(ret == 0)
	{
		//�^�C���A�E�g
		MessageBox(NULL,"�T�[�o�[����̉������������߃^�C���A�E�g���܂���","�G���[",MB_OK);
		return false;
	}
	if (FD_ISSET(s, &rdps)) {
		//7�����ǂݍ���
		recv(s,buf,7,0);
		if(strcmp(buf,"DATAOK")!=0)
		{
			MessageBox(NULL,"�f�[�^�̑��M�~�X��,�f�[�^���s���ł�","�G���[",MB_OK);
//			MessageBox(NULL,buf,"",MB_OK);
			return false;
		}
	}


	Sleep(1000);
	MessageBox(NULL,"�A�b�v���[�h�͖����Ɋ������܂���","�����L���O",MB_OK);

	return true;
}



bool recvreplay(bool stage,int index,int *onlinetime)
{





	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(2, 0), &wsaData))
	{
		WSACleanup();
		MessageBox(NULL,"�N���C�A���g�̏������Ɏ��s���܂���","�G���[",MB_OK);
		return false;
	}

	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
	if (s < 0) {
		MessageBox(NULL,"�N���C�A���g�̏������Ɏ��s���܂���","�G���[",MB_OK);
		return false;
	}

	HOSTENT *lpHost = gethostbyname(url);

	if (lpHost == NULL) {
		unsigned int addr = inet_addr(url);
		lpHost = gethostbyaddr((char *)&addr, 4, AF_INET);
	}

	if (lpHost == NULL) {
		closesocket(s);
		MessageBox(NULL,"�T�[�o�[��������܂���ł���","�G���[",MB_OK);
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
			MessageBox(NULL,"�T�[�o�[�Ƃ̒ʐM�Ɏ��s���܂���\n�T�[�o�[�����s����Ă��Ȃ���,�ق��̃��[�U�[���ڑ����ł�","�X�V�G���[",MB_OK);
			return false;
		}
	}


	//�T�[�o�[����̃��b�Z�[�W��҂�

	char buf[1024];

	timeval waittime;
	fd_set rdps;
	int ret;

	waittime.tv_sec = 10;	/* �^�C���A�E�g�b����ݒ肷�� */
	waittime.tv_usec = 0;
	FD_ZERO(&rdps);			/* ���������� */
	FD_SET(s,&rdps);		/* select����\�P�b�g��ǉ����� */

	ret = select(FD_SETSIZE,&rdps,(fd_set *)0,(fd_set *)0,&waittime);
	if(ret == SOCKET_ERROR)
	{
		//�\�����ʃG���[
		MessageBox(NULL,"�\�����ʃG���[���������܂���","�G���[",MB_OK);
		return false;
	}
	if(ret == 0)
	{
		//�^�C���A�E�g
		MessageBox(NULL,"�T�[�o�[����̉������������߃^�C���A�E�g���܂���","�G���[",MB_OK);
		return false;
	}
	if (FD_ISSET(s, &rdps)) {
		//2�����ǂݍ���
		recv(s,buf,3,0);
		if(strcmp(buf,"OK")!=0)
		{
			MessageBox(NULL,"�T�[�o�[�Ƃ̒ʐM�Ɏ��s���܂���","�G���[",MB_OK);
			return false;
		}
	}



	//���M����


	char filename[MAX_PATH];
	if(stage)
		sprintf(filename,"Data/Save/Replay/Stage/%d.lzh",index-1);
	else
		sprintf(filename,"Data/Save/Replay/Corce/%d.lzh",index-1);

	if(!stage)
		index+=30;

	int size;
	int kind=1;

	send(s,(char*)(&kind),4,0);//���
	send(s,(char*)(&index),4,0);//�X�e�[�W�ԍ�

	int readlevel=0;

	FILE *file;
	file=fopen("data/save/replay/DTemp","wb");


	while(1)
	{

		ret = select(FD_SETSIZE,&rdps,(fd_set *)0,(fd_set *)0,&waittime);

		if(ret == SOCKET_ERROR)
		{
			//�\�����ʃG���[
			MessageBox(NULL,"�\�����ʃG���[���������܂���","�G���[",MB_OK);
			fclose(file);
			return false;
		}
		if(ret == 0)
		{
			//�^�C���A�E�g
			MessageBox(NULL,"�T�[�o�[����̉������������߃^�C���A�E�g���܂���","",MB_OK);
			fclose(file);
			return false;
		}



		/* s�ɓǂݍ��݉\�f�[�^������ꍇ */
		if (FD_ISSET(s, &rdps))
		{
			if(readlevel==0)
			{
//				MessageBox(NULL,"�f�[�^�����܂���","",MB_OK);
				ret=recv(s,(char*)(&size),4,0);
				if(ret==SOCKET_ERROR)
				{
					fclose(file);
					return false;
				}
			}
			else if(readlevel==1)
			{
//				MessageBox(NULL,"�f�[�^�����܂���","",MB_OK);
				ret=recv(s,(char*)onlinetime,4,0);
				if(ret==SOCKET_ERROR)
				{
					fclose(file);
					return false;
				}
			}
			else
			{
				//�f�[�^�{�̂������Ă���

				ret=recv(s,buf,1024,0);
				if(ret==SOCKET_ERROR)
				{
					MessageBox(NULL,"�\�����ʃG���[���������܂���","�G���[",MB_OK);
					fclose(file);
					return false;
				}
				size-=ret;
				if(size<0)
				{
					MessageBox(NULL,"��M�����f�[�^�ɃG���[�������܂���","�G���[",MB_OK);
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
	MessageBox(NULL,"�_�E�����[�h�͖����Ɋ������܂���","�����L���O",MB_OK);

	return true;
}
bool updateinfo(rankdatastruct *rankdata)
{




	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(2, 0), &wsaData))
	{
		WSACleanup();
		MessageBox(NULL,"�N���C�A���g�̏������Ɏ��s���܂���","�X�V�G���[",MB_OK);
		return false;
	}

	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
	if (s < 0) {
		MessageBox(NULL,"�N���C�A���g�̏������Ɏ��s���܂���","�X�V�G���[",MB_OK);
		return false;
	}

	HOSTENT *lpHost = gethostbyname(url);

	if (lpHost == NULL) {
		unsigned int addr = inet_addr(url);
		lpHost = gethostbyaddr((char *)&addr, 4, AF_INET);
	}

	if (lpHost == NULL) {
		closesocket(s);
		MessageBox(NULL,"�T�[�o�[��������܂���ł���","�X�V�G���[",MB_OK);
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
			MessageBox(NULL,"�T�[�o�[�ւ̐ڑ��Ɏ��s���܂���","�X�V�G���[",MB_OK);
			return false;
		}
	}


	//�T�[�o�[����̃��b�Z�[�W��҂�

	char buf[1024];

	timeval waittime;
	fd_set rdps;
	int ret;

	waittime.tv_sec = 10;	/* �^�C���A�E�g�b����ݒ肷�� */
	waittime.tv_usec = 0;
	FD_ZERO(&rdps);			/* ���������� */
	FD_SET(s,&rdps);		/* select����\�P�b�g��ǉ����� */

	ret = select(FD_SETSIZE,&rdps,(fd_set *)0,(fd_set *)0,&waittime);
	if(ret == SOCKET_ERROR)
	{
		//�\�����ʃG���[
		MessageBox(NULL,"�\�����ʃG���[���������܂���","�X�V�G���[",MB_OK);
		return false;
	}
	if(ret == 0)
	{
		//�^�C���A�E�g
		MessageBox(NULL,"�T�[�o�[����̉������������߃^�C���A�E�g���܂���","�X�V�G���[",MB_OK);
		return false;
	}
	if (FD_ISSET(s, &rdps)) {
		//2�����ǂݍ���
		recv(s,buf,3,0);
		if(strcmp(buf,"OK")!=0)
		{
			MessageBox(NULL,"�T�[�o�[�Ƃ̒ʐM�Ɏ��s���܂���\n�T�[�o�[�����s����Ă��Ȃ���,�ق��̃��[�U�[���ڑ����ł�","�X�V�G���[",MB_OK);
			return false;
		}
	}


	int kind=2;
	send(s,(char*)(&kind),4,0);//���


	//��M�ҋ@
	ret = select(FD_SETSIZE,&rdps,(fd_set *)0,(fd_set *)0,&waittime);
	if(ret == SOCKET_ERROR)
	{
		//�\�����ʃG���[
		MessageBox(NULL,"�\�����ʃG���[���������܂���","�X�V�G���[",MB_OK);
		return false;
	}
	if(ret == 0)
	{
		//�^�C���A�E�g
		MessageBox(NULL,"�T�[�o�[����̉������������߃^�C���A�E�g���܂���","�X�V�G���[",MB_OK);
		return false;
	}
	if (FD_ISSET(s, &rdps)) {
		//�f�[�^���S���͂����炢�̎��ԑ҂�
		Sleep(500);
		recv(s,(char*)rankdata,sizeof(rankdatastruct),0);
	}

	if(rankdata->check!=12345)
	{
		MessageBox(NULL,"�T�[�o�[�Ƃ̒ʐM�Ɏ��s���܂���","�X�V�G���[",MB_OK);
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