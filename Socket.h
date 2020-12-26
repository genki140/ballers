/*���̊֐��̗��p���@

�@SocketClass�ϐ��쐬
�AInitServer��InitClient�ŒʐM�̏������s��
�B�f�[�^���O�����瑗���Ă���ƃE�B���h�E���b�Z�[�W�Ƃ��ē͂��̂�
�͂����Ɠ�����AutoMsg�֐����Ăяo���āA���M���ԍ��ƃ��b�Z�[�W�̎�ނ��擾����
�CAutoMsg��SOCK_NONE���Ԃ�܂Ń��[�v����



*/


#ifndef SOCKET_HED
#define SOCKET_HED

#define SD_RECEIVE      0x00
#define SD_SEND         0x01
#define SD_BOTH         0x02

#include <conio.h>
#include <time.h>
#include <windows.h>

#define CLIENT_MAX		10000

class SocketClass
{
private:
public:

	HWND hWnd;
	int MsgNum;
	bool ServerEnable;
	bool ClientEnable;
	int ClientMax;
	float OutTime;
	long int LastTime;//clock()���i�[���Ă���



	//keephead�Ƀw�b�_��񂪈ꎞ�I�Ɋi�[����Ă��邩
	bool headenable;//�܂��w�b�_�͖���

	//�w�b�_�\����(���M���鎞�K���擪�ɂ��������)(7�o�C�g)
	struct HeadStruct
	{
		long int size;//�f�[�^�T�C�Y(4�o�C�g)
		short int kind;//�A�v���P�[�V�����ŔC�ӂɌ��߂�f�[�^�̎��(2�o�C�g)
		char rnd;//�Í����p�Ƀ����_���ɂ���(1�o�C�g)
	};


	//�N���C�A���g���\����(�T�[�o�[���g�p)
	struct ClientStruct
	{
		bool enable;
		SOCKET s;
		long int LastTime;
		bool headenable;
//		HeadStruct keephead;

		ClientStruct()
		{
			enable=false;
			headenable=false;
		}

	};

	ClientStruct *client;



	//�T�[�o�[����s�����X���p�ɂ��Acs���N���C�A���g���Ƃ̃\�P�b�g�ɂ���
	SOCKET s;
	SOCKADDR_IN saddr;
	HOSTENT *lpHost;
	unsigned int addr;

	//�f�[�^�T�C�Y�擾�p�o�b�t�@
	char Buffer[10000000];//10M�ȏ�̃f�[�^����x�ɑ��邱�Ƃ͂ł��Ȃ�

	//�Í���
	void Encryption(char *data,int size);
	//������
	void Composite(char *data,int size);



public:

	//Max�͍ő�̃N���C�A���g���ATime�͌��E��������
	bool InitServer(int port,HWND wnd,int Msg,int Max,float Time);
	bool InitClient(char *ip,int port,HWND hWnd,int Msg,float Time);

	//�f�[�^�𑗐M����
	bool Send(short int kind,char* data=NULL,long int size=0,int index=0);//�N���C�A���g����index�͏����Ȃ��Ă悢
	//�f�[�^����M����(��ނ͂��ł�GetKind�Ŏ擾���Ă����A���ڍ\���̂Ȃǂփ|�C���^�ŏ�������)
	int Recv(char* data,int index=0);//�N���C�A���g����index�͏����Ȃ��Ă悢

	//�T�[�o�[���A���ׂẴN���C�A���g�Ƀf�[�^�𑗐M����
	bool SendAll(short int kind,char* data=NULL,long int size=0);

	//�T�[�o�[���A�N���C�A���g��ؒf
	void DeleteClient(int index);
	//�l�b�g���[�N����؂藣��
	void Exit();



	//���b�Z�[�W�����������I�I(�T�[�o�[���A�T�[�o�[����������ׂ����b�Z�[�W�����Ă�����)
	//��ނƃC���f�b�N�X��Ԃ��Bevent�����(READ,CONNECT�Ȃ�)�ŁA�߂�l��index(�\�P�b�g�ԍ�)
	int AutoMsg(UINT Msg,LPARAM lParam,int *Event);

	//���Ɏ擾�ł���f�[�^�̎�ނ��擾����(�߂�l��false�̎��A�f�[�^�͖���)��size��NULL�̂Ƃ��A�T�C�Y�͕Ԃ��Ȃ�
	bool GetMsgKind(int *kind,int *size=NULL,int index=0);//�N���C�A���g����index�͏����Ȃ��Ă悢


	//�T�[�o�[���̓N���C�A���g�������Ă��Ȃ����𒲂ׁA�N���C�A���g���͎���or�T�[�o�[�������Ă��Ȃ����𒲂ׂ�
	int CheckTimeOut();


	SocketClass()
	{
		ServerEnable=false;
		ClientEnable=false;
		headenable=false;
	}

};





#endif