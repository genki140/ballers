
char Buffer[65536];

#define PORT 14142
#define SERVER ""
#define NET_MSG (WM_USER + 1)

enum {	NETMSG_CHECK,NETMSG_GETVERSION,NETMSG_VERSION,NETMSG_LOGIN,NETMSG_LOGOUT,NETMSG_LOGINOK,NETMSG_LOGINYET,NETMSG_NEW,NETMSG_NEWOK,
		NETMSG_LOGINNAMEMISS,NETMSG_LOGINPASSMISS,NETMSG_LOGINCOUNTMISS,NETMSG_NEWNAMEMISS,NETMSG_NEWCOUNTMISS,
		NETMSG_CHATMSG,NETMSG_ALLUSERINFO};


//ユーザー状態
enum{USERSTATE_NORMAL,USERSTATE_WAIT,USERSTATE_BUTTLE,USERSTATE_LOSE};


//配列要素数定義
#define USERNAME_MAX 10
#define USERPASS_MAX 10
#define VERSION_MAX 15

#define CHATMSG_MAX 150





//ゲーム系カウンタ

#define LOGIN_MAX 100
#define CHARA_MAX 4//キャラクター人数
#define GAME_MAX 10//ゲーム最大収容人数
//#define GAME_MAX 10




//送信用構造体

//バージョン情報
struct VersionMsgStruct
{
	char Version[VERSION_MAX];
};
//ログイン情報
struct LoginMsgStruct
{
	WCHAR name[USERNAME_MAX+1];
	WCHAR pass[USERPASS_MAX+1];
};
//新規登録情報
struct NewMsgStruct
{
	WCHAR name[USERNAME_MAX+1];
	WCHAR pass[USERPASS_MAX+1];
};

//新規登録情報
struct ChatMsgStruct
{
	WCHAR msg[CHATMSG_MAX+1];
};


struct UserInfoMsgStruct
{
	WCHAR name[USERNAME_MAX+1];
	unsigned int point;
	int rank;//サーバーで計算してくれてるから送っちゃう
	unsigned short int state;
	int waitcount;
};

//全プレイヤーログイン情報
struct AllUserInfoMsgStruct
{
	int LoginCount;//ログイン人数(※この人数分読み込む)

	UserInfoMsgStruct UserInfo[LOGIN_MAX];
};




