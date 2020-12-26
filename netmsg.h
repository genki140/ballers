
char Buffer[65536];

#define PORT 14142
#define SERVER ""
#define NET_MSG (WM_USER + 1)

enum {	NETMSG_CHECK,NETMSG_GETVERSION,NETMSG_VERSION,NETMSG_LOGIN,NETMSG_LOGOUT,NETMSG_LOGINOK,NETMSG_LOGINYET,NETMSG_NEW,NETMSG_NEWOK,
		NETMSG_LOGINNAMEMISS,NETMSG_LOGINPASSMISS,NETMSG_LOGINCOUNTMISS,NETMSG_NEWNAMEMISS,NETMSG_NEWCOUNTMISS,
		NETMSG_CHATMSG,NETMSG_ALLUSERINFO};


//���[�U�[���
enum{USERSTATE_NORMAL,USERSTATE_WAIT,USERSTATE_BUTTLE,USERSTATE_LOSE};


//�z��v�f����`
#define USERNAME_MAX 10
#define USERPASS_MAX 10
#define VERSION_MAX 15

#define CHATMSG_MAX 150





//�Q�[���n�J�E���^

#define LOGIN_MAX 100
#define CHARA_MAX 4//�L�����N�^�[�l��
#define GAME_MAX 10//�Q�[���ő���e�l��
//#define GAME_MAX 10




//���M�p�\����

//�o�[�W�������
struct VersionMsgStruct
{
	char Version[VERSION_MAX];
};
//���O�C�����
struct LoginMsgStruct
{
	WCHAR name[USERNAME_MAX+1];
	WCHAR pass[USERPASS_MAX+1];
};
//�V�K�o�^���
struct NewMsgStruct
{
	WCHAR name[USERNAME_MAX+1];
	WCHAR pass[USERPASS_MAX+1];
};

//�V�K�o�^���
struct ChatMsgStruct
{
	WCHAR msg[CHATMSG_MAX+1];
};


struct UserInfoMsgStruct
{
	WCHAR name[USERNAME_MAX+1];
	unsigned int point;
	int rank;//�T�[�o�[�Ōv�Z���Ă���Ă邩�瑗�����Ⴄ
	unsigned short int state;
	int waitcount;
};

//�S�v���C���[���O�C�����
struct AllUserInfoMsgStruct
{
	int LoginCount;//���O�C���l��(�����̐l�����ǂݍ���)

	UserInfoMsgStruct UserInfo[LOGIN_MAX];
};




