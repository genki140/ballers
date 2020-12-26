/*この関数の利用方法

①SocketClass変数作成
②InitServerかInitClientで通信の準備を行う
③データが外部から送られてくるとウィンドウメッセージとして届くので
届いたと同時にAutoMsg関数を呼び出して、送信元番号とメッセージの種類を取得する
④AutoMsgでSOCK_NONEが返るまでループする



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
	long int LastTime;//clock()を格納しておく



	//keepheadにヘッダ情報が一時的に格納されているか
	bool headenable;//まだヘッダは無い

	//ヘッダ構造体(送信する時必ず先頭にこれをつける)(7バイト)
	struct HeadStruct
	{
		long int size;//データサイズ(4バイト)
		short int kind;//アプリケーションで任意に決めるデータの種類(2バイト)
		char rnd;//暗号化用にランダムにつける(1バイト)
	};


	//クライアント情報構造体(サーバー時使用)
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



	//サーバー時はsをリスン用にし、csをクライアントごとのソケットにする
	SOCKET s;
	SOCKADDR_IN saddr;
	HOSTENT *lpHost;
	unsigned int addr;

	//データサイズ取得用バッファ
	char Buffer[10000000];//10M以上のデータを一度に送ることはできない

	//暗号化
	void Encryption(char *data,int size);
	//複合化
	void Composite(char *data,int size);



public:

	//Maxは最大のクライアント数、Timeは限界応答時間
	bool InitServer(int port,HWND wnd,int Msg,int Max,float Time);
	bool InitClient(char *ip,int port,HWND hWnd,int Msg,float Time);

	//データを送信する
	bool Send(short int kind,char* data=NULL,long int size=0,int index=0);//クライアント時はindexは書かなくてよい
	//データを受信する(種類はすでにGetKindで取得しておき、直接構造体などへポインタで書き込む)
	int Recv(char* data,int index=0);//クライアント時はindexは書かなくてよい

	//サーバー時、すべてのクライアントにデータを送信する
	bool SendAll(short int kind,char* data=NULL,long int size=0);

	//サーバー時、クライアントを切断
	void DeleteClient(int index);
	//ネットワークから切り離す
	void Exit();



	//メッセージを自動処理！！(サーバー時、サーバーが処理するべきメッセージが来ていたら)
	//種類とインデックスを返す。eventが種類(READ,CONNECTなど)で、戻り値がindex(ソケット番号)
	int AutoMsg(UINT Msg,LPARAM lParam,int *Event);

	//次に取得できるデータの種類を取得する(戻り値がfalseの時、データは無い)※sizeがNULLのとき、サイズは返さない
	bool GetMsgKind(int *kind,int *size=NULL,int index=0);//クライアント時はindexは書かなくてよい


	//サーバー時はクライアントが落ちていないかを調べ、クライアント時は自分orサーバーが落ちていないかを調べる
	int CheckTimeOut();


	SocketClass()
	{
		ServerEnable=false;
		ClientEnable=false;
		headenable=false;
	}

};





#endif