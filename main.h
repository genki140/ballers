#ifndef MAIN_HED
#define MAIN_HED





//---------------------------------最初のインクルード-------------------------------------

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "resource.h"

#include "mathematic.h"
#include "graphic.h"
#include "meshclass.h"
#include "input.h"
#include "sound.h"
#include "feed.h"
#include "ball.h"
#include "Judgment.h"


//圧縮解凍用ライブラリ
typedef WORD(WINAPI *UNLHAGETVERSION)(void);
typedef int(WINAPI *UNLHA)(const HWND, LPCSTR, LPSTR , const DWORD);
UNLHA Unlha;
HINSTANCE lhalib;






//---------------------------------定数宣言-------------------------------------

const char *AppName="ボウラーズ";
const char *AppCaption="ボウラーズ";

#define STAGE_MAX 30//ステージ数(これによりコースの始まり番号を識別したりする)
#define NORMALSTAGE_COUNT 13//ノーマルステージの数
#define CORCE_MAX 12
#define ITEM_MAX 50
#define BALL_MAX 50
#define BALLKIND_START 100//あたり判定時のあたった物体の種類がボールの場合どこから始まるのかを指定

#define SOUND_HZ 22050 //wavの周波数
//同じ音の同時再生の限界数
#define SOUND_PLAYMAX 10

#define CAMERA_R 0.3f//カメラのサイズ(壁食い込み防止のためにしようする)

//爆発情報
#define BOMB_MAX 10

//アイテムを取得するまでの時間
#define ITEM_COUNT 100
//ファイアーを噴射する時間
#define FIRE_COUNT 400
//ショットを打つまでの時間
#define SHOT_COUNT 100

//ステージ情報の最大数
#define STAGESTATE_MAX 100

//煙の最大数
#define KEMURI_MAX 1000

//大砲の最大数
#define GUN_MAX 100

//噴射口の最大数
#define WIND_MAX 100

//---------------------------------列拳宣言-------------------------------------


//ゲームモードの種類
enum {GAMEMODE_PROJECT,GAMEMODE_TITLE,GAMEMODE_GAME};

//ボールのメッシュの種類
enum {BALLMESH_CHARA,BALLMESH_CHARAEND=BALLMESH_CHARA+4,BALLMESH_IWA,BALLMESH_IWA2,BALLMESH_TETU,BALLMESH_TAMA,
		BALLMESH_BOMB,BALLMESH_YUUDOU,BALLMESH_MINITETU,BALLMESH_BIGTETU,BALLMESH_BIGIWA,BALLMESH_IZIGENBALL,BALLMESH_TETU2,BALLMESH_TETU3,BALLMESH_TETU4,BALLMESH_MAX};

//当たり判定板の種類
enum {ITAKIND_CORCEOUT,ITAKIND_NORMAL,ITAKIND_MOVE,ITAKIND_ROTATE};////コースアウト、普通の壁、回転、移動、などの種類

//「芝生、木、鉄」などの材質の種類(MATKIND_NULLはあたっても動きに変化を起こさない板)
enum {MATKIND_NULL,MATKIND_CHARA,MATKIND_CHARAEND=MATKIND_CHARA+5,MATKIND_SIBA,MATKIND_TUTI,MATKIND_KI,MATKIND_TETU,MATKIND_TETU2,MATKIND_TETUTAMA,
		MATKIND_ISI,MATKIND_SUNA,MATKIND_IZIGEN,MATKIND_GURABI,MATKIND_YUUDOU,MATKIND_GOMU,MATKIND_MAX};

//環境マップの種類
enum {ENVKIND_PROJECT,ENVKIND_KI,ENVKIND_META,ENVKIND_TETU,ENVKIND_TETUMETA,ENVKIND_IZIGEN,ENVKIND_MAX};

//アイテムの種類
enum {ITEMKIND_NONE,ITEMKIND_TAIHOU,ITEMKIND_FIRE,ITEMKIND_SHOT,ITEMKIND_BOMB,ITEMKIND_MIZU,ITEMKIND_YUUDOU,ITEMKIND_GURABI,ITEMKIND_MAX};

//サウンドの種類
enum {SOUNDKIND_PURA,SOUNDKIND_TETU,SOUNDKIND_SIBA,SOUNDKIND_IZIGEN,SOUNDKIND_GOMU};





//---------------------------------変数宣言-------------------------------------


WNDCLASSEX wc;
HWND hWnd;


//-----複雑な変数-----

GraphicClass DG;
InputClass DI;
CSoundManager*          DS       = NULL;
LPDIRECTSOUND3DLISTENER DSListener         = NULL;   // 3D listener object

JudClass judc;
FeedClass feed[5];//要素4は全体の


//ステージメッシュ
MeshClass stagemesh;

MeshClass shade;
MeshClass ita;
MeshClass ballmesh[BALLMESH_MAX];
MeshClass itemmesh[ITEMKIND_MAX];
MeshClass taihoumesh[3];
MeshClass windmesh[4];

D3DXCOLOR itemcolor[ITEMKIND_MAX];

LPDIRECT3DTEXTURE8 EnvTex[ENVKIND_MAX];
LPDIRECT3DTEXTURE8 KemuriTex[8];



//-----単純な変数-----

float Version;

int gamemode;

bool end;


float fovy=distance(D3DX_PI/3,D3DX_PI/3*(4.0f/3.0f))*deg;



int playercount;//プレーヤーのにんずう


//自動的にセレクト板を出したときはtrueにする
bool autostop;

//ステージ情報
int stagekind;
int stagenum;


//止めた人の番号を覚えておく
int stopplayer;

int itemcount;


float itemkakuritu[ITEMKIND_MAX];//アイテムの出現率を格納
float itemkakurituend[ITEMKIND_MAX];//アイテムの出現率の計算にしよう
float itemkakuritusum;//アイテムの出現率の計算にしよう





int Time,rTime,hTime[STAGE_MAX+CORCE_MAX];//hTimeの[0～29]までがステージ、hTimeの[30～42]までがコース
int lap;



int clearstage;//ステージのクリア数

bool Ghost;//リプレイを表示する奴(ゴースト)

int autoReplayCount;//自動リプレイに入るカウント
bool replay,replayend;
bool autoReplay;//自動的にリプレイ再生に入ったときはONにしておく
bool startend;//自動リプレイ時、スタートボタンで終了したときONにする

int multiplayernum;//マルチプレイ時、プレイヤー何番かを格納


int gameframe;//マルチプレイ時、古いデータは受け付けない！！






//-----ネットワーク系-----

bool KeepIP;
bool KeepPort;

//ほかのプログラムからも参照したいので、ソケットはここで宣言！！
SOCKET s;

bool MultiPlayCountStart;//ゲームがスタートする
bool MultiPlayStart;//ゲーム画面へ移動する

int Error;//エラーが発生したときにエラーメッセージの番号を格納しておく(ネットワーク)
//※Errorの値により、エラー画面へ強制的にどうする場合もある

int myID,fromID[3];//自分からのメッセージを認識するためのもの
bool multiplayready[3];//ゲームに入れるかを調べるときに使う
bool multiplayreadymy;//自分が準備完了のとき、trueにする

bool multiplaystartcount[3];//スタートカウントに入れるかを調べるときに使う

int gamestartlimit;//応答がない場合の限界待ち時間とかで使う変数







//---------------------------------構造体宣言---------------------------------


//どのボタンがどのキーかを格納する構造体(-1)は設定なし
struct keynumstruct
{
	//ボタン
	int ok;
	int cancel;
	int jump;
	int item;
	int start;
	int rightrote;//カメラ右に移動
	int leftrote;//カメラ左に移動

	//軸(キーボードの場合はボタン)
	int axis,axis2;//ジョイパッド用
	int up,down,left,right,up2,down2,left2,right2;//キーボード用、2はカメラ回転用

	float axisover,axisover2;//どこまでが軸を曲げてないことにするかを％で指定する(0～1)

	bool VibEnable;//バイブレーションの有無

}keynum[5];//[0]はキーボード用


//どのボタンが押されたかなどを格納する構造体
struct buttonstatestruct
{
	//軸が曲げられた瞬間が分かるように前の状態を記録しておく

	bool ok;
	bool cancel;
	bool start;
	bool startpress;
	bool rightrote;
	bool leftrote;
	bool jump;
	bool item;

	float x,y,x2,y2;
	bool bx,by;//スティックが倒された瞬間だけTrueにする
	
}buttonstate[5];//添え字はプレイヤー番号、[4]は全体ができる操作用に、０～３までのORみたいなのを格納



//ゲームの設定などに必要な変数
struct GameSetting
{
	int Key1p;//1Pがキーボード操作ならtrue
	bool only1p;
	//bool VibEnable;

	bool BGM;
	bool Sound3D;//3Dサウンドをするか
	int SoundAlg;//0が最低、1が最高
	int SoundCommit;//何コマに1回更新するかを格納

	bool FullScreen;
	int FormWidth,FormHeight;
	int BufferWidth,BufferHeight;
	int BufferFormat;
	bool ShadeEnable;
	float KemuriMaxDis;//煙をどこまで表示するか
	float ItemMaxDis;//アイテムをどこまで表示するか
	bool MultiTextureEnable;
//	bool ProgMeshEnable;
//	float MultiMeshRat;//デフォルトの距離のどのくらいで消えるか
	bool FiltarEnable;
	bool MipmapEnable;
	bool MipmapFiltarEnable;
	float MipmapBias;//みっぷマップのバイアス
	bool EnvEnable;

	bool Seaver;
	char ip[16];
	char port[7];
	bool IPKeep;
	bool PortKeep;

	int SoundMultiCount;//音声同時再生数

	int Anti;

}Setting;



//材質構造体(moveres,rotaresはボールにしか関係ない)
struct MaterialStruct
{
	float df,sf,moveres,rotares,bound,rollres;//resは空気抵抗係数,rollresは常に一定な抵抗
}matstruct[MATKIND_MAX];



//キャラクター構造体(ほとんどのデータは材質構造体にある)
struct CharaStruct
{
	float r,w,power,speed,jump;
}character[6];//player[].charnumを添え字とする



//プレイヤーが持つ情報
struct PlayerStruct
{
	bool goal,FinalLap;
	int lap,rank;
	float par,temppar;
	//parは決定された現在位置パーセント(ちゃんと着地したときに決まる)、tempparは一時的な現在位置パーセント(空中でも決まる)

	D3DXVECTOR3 cpo,cpoold,cup,ballold;//,cameraold;//カメラの位置と上
	//(ballold,cameraoldはマルチプレイでの応答速度の遅さに対応するために作った変数で、スムーズに移動させる)
	D3DXVECTOR3 cponext,cupnext;//cpo,cupがこのベクトルになるように追いついてくる
    D3DVIEWPORT8 vp;
	int charnum;//操作するキャラクターの番号

	bool InputEnable;//操作可能かを格納

	//アイテム関係の変数
	int itemkind,usekind,usecount;//itemkind=持ってるアイテム,usekind=使ってるアイテム,usecount=使ってるアイテムの残り時間
	//int damagekind,damagecount;//敵にやられた以上状態の種類を敵が使ったアイテムの種類で格納！！(いろいろ使われると上書き)
	float itemangle;
	int backcount;//逆走かうんと

	int ClientItem;//クライアントでアイテムの効果がほしいときに使用する。(0はなし、1はスタート系、2は持続系)
	int ClientItemKind;//↑と一緒に使うアイテムのインデックス
	int ClientItemCount;//↑と一緒に使うアイテムのカウント

	int MutekiCount;//0以外のときはウォーターの影響を受けない
}player[4];



//サウンド関係の構造体
struct SoundStruct3D
{
	CSound* Sound;
	LPDIRECTSOUND3DBUFFER   Buffer;
	DS3DBUFFER              Param;
};

struct SoundStruct
{

	LPDIRECTSOUND3DLISTENER Listener;
	DS3DLISTENER            ListenerParam;


	CSound* Project;//プロジェクトの文字表示時の音

	CSound* Select;//セレクト時、選択するときの音
	CSound* RotaStart;//セレクト時、画面が変わり始めの音
	CSound* RotaEnd;//セレクト時、画面が変わる終わるときの音

	CSound* Kansei;//歓声音(スタート前、ゴール後にながす)
	CSound* Count;//カウントダウンの音
	CSound* Start;//カウント終了（スタート）の音
	CSound* Final;//ファイナルラップ


	CSound* Item[SOUND_PLAYMAX];//アイテムをとったときの音
	SoundStruct3D Item3D[SOUND_PLAYMAX];

	CSound* Fire[SOUND_PLAYMAX];//ファイアーを吹いてるときの音
	SoundStruct3D Fire3D[SOUND_PLAYMAX];

	CSound* Mizu[SOUND_PLAYMAX];//水中のときの音
	SoundStruct3D Mizu3D[SOUND_PLAYMAX];

	CSound* Bomb[SOUND_PLAYMAX];//爆発したときの音
	SoundStruct3D Bomb3D[SOUND_PLAYMAX];

	CSound* Shot[SOUND_PLAYMAX];//球を撃ったときの音
	SoundStruct3D Shot3D[SOUND_PLAYMAX];

	CSound* ShotCount[SOUND_PLAYMAX];//球を撃つときのカウント
	SoundStruct3D ShotCount3D[SOUND_PLAYMAX];

	CSound* Tetu[SOUND_PLAYMAX];//金属などがあたったときの音
	SoundStruct3D Tetu3D[SOUND_PLAYMAX];

	CSound* Pura[SOUND_PLAYMAX];//プラスチックなどがあたったときの音
	SoundStruct3D Pura3D[SOUND_PLAYMAX];

	CSound* Ki[SOUND_PLAYMAX];//木などがあたったときの音
	SoundStruct3D Ki3D[SOUND_PLAYMAX];

	CSound* Siba[SOUND_PLAYMAX];//芝生にあたったときの音
	SoundStruct3D Siba3D[SOUND_PLAYMAX];

	CSound* Izigen[SOUND_PLAYMAX];
	SoundStruct3D Izigen3D[SOUND_PLAYMAX];

	CSound* Gomu[SOUND_PLAYMAX];
	SoundStruct3D Gomu3D[SOUND_PLAYMAX];

	CSound* Yudou[SOUND_PLAYMAX];//誘導爆弾の移動音
	SoundStruct3D Yudou3D[SOUND_PLAYMAX];

	CSound* Gurabi[SOUND_PLAYMAX];//重力アイテム音
	SoundStruct3D Gurabi3D[SOUND_PLAYMAX];

	CSound* GurabiStart[SOUND_PLAYMAX];//重力アイテム使用音
	SoundStruct3D GurabiStart3D[SOUND_PLAYMAX];

	CSound* BombOut[SOUND_PLAYMAX];//ボムを落とす音
	SoundStruct3D BombOut3D[SOUND_PLAYMAX];


	CSound* Meka[SOUND_PLAYMAX];//メカ音
//	SoundStruct3D Meka3D[SOUND_PLAYMAX];

	CSound* MizuStart[SOUND_PLAYMAX];//水発動音
	SoundStruct3D MizuStart3D[SOUND_PLAYMAX];

	CSound* Iwa[SOUND_PLAYMAX];//岩の転がる音
	SoundStruct3D Iwa3D[SOUND_PLAYMAX];

}sd;


//ただのボールが持つ情報
struct BallStruct
{

	//その他のいろいろな情報(サウンドインデックスとか)
	int info[2];

	int matindex;//材質

	D3DXVECTOR3 gv;//重力の方向

	BallClass ball;
	int meshindex;
	bool enable;
	int deletecount;//0のときは消さないという意味

	int nojudindex;//優一ひとつだけ当たり判定しないボールを設定するとしたらこの変数を変える
	//※nojudindexは、ボール同士が離れていたら、自動的に-1になる！

}ball[BALL_MAX];


//アイテム情報
struct ItemStruct
{
	int kind;
	int getter;//アイテムをとった人のインデックスを格納する
	D3DXVECTOR3 po,nowpo;
	int deletecount;//消すときは10に、現れるときは-50にする
	float angle;//回転
	D3DXMATRIX mat;
}item[ITEM_MAX];


//爆発情報
struct BombStruct
{
	D3DXVECTOR3 p;
	//sizemaxが0のとき、爆発はない
	float sizemax,size,sizeadd;//sizeにsizeaddを足していき、sizemaxで終わる
	D3DXMATRIX mat;
	D3DXVECTOR3 axis;//回転軸
}Bomb[BOMB_MAX];
MeshClass bombmesh;




//ステージ情報を格納する
struct StageStruct
{
	short int kind;//コースアウト、普通の壁、回転、移動、などの種類
	short int matindex;//芝生、木、鉄、などの種類
	D3DXVECTOR3 v,v2;//いろんな目的に使う変数
	float s,s2;//いろんな目的に使うスカラー
}stagestate[STAGESTATE_MAX];

D3DXMATRIX stagematrix;//ステージ特有のマトリックスが有る場合に使う

/*StageStructの説明

Kind=0 : 普通な地面
v,v2 は使用しない

Kind=1 : コースアウト地面
v,v2 は使用しない

Kind=2 : 移動地面
v=移動方向と速度,v2.x.y=現在の移動位置

Kind=3 : 回転地面
v=回転の原点,v2=回転軸と回転量,s=現在の回転量

*/



//大砲情報を格納する
struct GunStruct
{
	short int kind;//グラフィックの種類
	D3DXVECTOR3 p;//位置
	D3DXVECTOR3 v;//飛ばす方向と勢いベクトル
	D3DXMATRIX mat;//トランスフォーム用マトリックス
}gun[GUN_MAX];

int guncount;

//噴射口情報を格納する
struct WindStruct
{
	bool enable;
	short int kind;//グラフィックの種類
	D3DXVECTOR3 p;//位置
	D3DXVECTOR3 v;//飛ばす方向と勢いベクトル
	float dis;//どれだけの距離飛ぶかを格納
	float ang;//噴射角度を格納
	D3DXMATRIX mat;//トランスフォーム用マトリックス
}wind[WIND_MAX];

int windcount;



//煙情報を格納する
struct KemuriStruct
{
	int kind;//種類
	int frame;//状態
	int framemax;//何コマで消えるか・・・
	D3DXVECTOR3 po;//位置
	D3DXVECTOR3 mv;//移動量
}kemuri[KEMURI_MAX];




struct GoalStruct
{
	D3DXVECTOR3 p;
	D3DXVECTOR3 v;//煙の出る方向
	int index;//ゴールとなる煙のインデックス
}goal;



//---------------------------------関数宣言-------------------------------------

LRESULT WINAPI MsgProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam );
int WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR, INT );
void Cleanup();

bool LoadSetting();
bool SaveSetting();
bool LoadClear();
bool SaveClear();

bool GraphicSetting();
void GraphicRelease();

bool SoundSetting();
void SoundRelease();
bool OtherSetting();

bool ShowSetting(int num);
void ShowRelease();

bool Move();
bool Render();

bool SetNetwork();



//※メイン関数でプロトタイプ宣言しないとエラーが出ちゃうネットワーク系関数のプロトタイプ宣言

void InfoNetRender(char *str);
void SendAllPlayerInfo(int count);//全プレイヤーの情報送信(ステージ情報も)
void SendMyPlayerInfo();//プレイヤーの情報
void SendPlayerOut();
void SendSeaverDown();
int GetNowPlayerCount();
void Sendokcancel(bool ok);




//簡単な関数やマクロ

//t秒停止！！
void wait(float t)
{
	int oldclock=clock();
	while(oldclock+(t*1000.0f)>clock());
}


//floatをDWORDに変換する
inline DWORD FtoDW( FLOAT f ) { return *((DWORD*)&f); }

//停止、リセット、再生をまとめてやるマクロ
#define SOUND_PLAY(p) p->Stop(),p->Reset(),p->Play()

//環境マップが有効のときはそのまま、無効のときはNULLを返す
#define ENVCHECK(p) (Setting.EnvEnable ? p : NULL)

//マルチプレイ時サーバーのときはtrueを返す
#define seaver (stagekind!=SELECTGAME_MULTIPLAY || Setting.Seaver)

//3Dサウンドを再生するかを返す
#define play3d (Setting.Sound3D && (playercount==1 || stagekind==SELECTGAME_MULTIPLAY))

//振動するコントローラのインデックスを返す
#define multiplayindex(p) (stagekind!=SELECTGAME_MULTIPLAY ? p : (p==multiplayernum ? 0 : -1) )

//異次元コースかのチェック
#define izigen ((stagekind!=SELECTGAME_STAGE && stagenum>=9) || (stagekind==SELECTGAME_STAGE && stagenum>=25 || stagenum==12))

//スタッフロールでクリアしてないかのチェック
#define staff (stagekind==SELECTGAME_STAGE && ((stagenum==12 && clearstage<13) || (stagenum==29 && clearstage<30)))





//ファイルを読み、チェック用数値を作成する(大文字、小文字が重要なので注意が必要)
int createcheck(char *filename)
{
	FILE* file;
	int ans=0,count=0;
	char c,*p=filename;

	//ポインタを戻す
	p=filename;

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
	char checkfilename[MAX_PATH];
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
	char checkfilename[MAX_PATH];
	strcpy(checkfilename,filename);
	strcat(checkfilename,"c");
	FILE *file=fopen(checkfilename,"w");

	if(file==NULL)
		return false;

	fprintf(file,"%d",createcheck(filename));
	fclose(file);

	return true;
}






//---------------------------------最後のインクルード---------------------------------


#include "show.h"
#include "project.h"
#include "select.h"
#include "mysound.h"
#include "net.h"
#include "replay.h"
#include "info.h"
#include "title.h"
#include "stage.h"


#endif
