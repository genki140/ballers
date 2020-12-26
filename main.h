#ifndef MAIN_HED
#define MAIN_HED





//---------------------------------�ŏ��̃C���N���[�h-------------------------------------

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


//���k�𓀗p���C�u����
typedef WORD(WINAPI *UNLHAGETVERSION)(void);
typedef int(WINAPI *UNLHA)(const HWND, LPCSTR, LPSTR , const DWORD);
UNLHA Unlha;
HINSTANCE lhalib;






//---------------------------------�萔�錾-------------------------------------

const char *AppName="�{�E���[�Y";
const char *AppCaption="�{�E���[�Y";

#define STAGE_MAX 30//�X�e�[�W��(����ɂ��R�[�X�̎n�܂�ԍ������ʂ����肷��)
#define NORMALSTAGE_COUNT 13//�m�[�}���X�e�[�W�̐�
#define CORCE_MAX 12
#define ITEM_MAX 50
#define BALL_MAX 50
#define BALLKIND_START 100//�����蔻�莞�̂����������̂̎�ނ��{�[���̏ꍇ�ǂ�����n�܂�̂����w��

#define SOUND_HZ 22050 //wav�̎��g��
//�������̓����Đ��̌��E��
#define SOUND_PLAYMAX 10

#define CAMERA_R 0.3f//�J�����̃T�C�Y(�ǐH�����ݖh�~�̂��߂ɂ��悤����)

//�������
#define BOMB_MAX 10

//�A�C�e�����擾����܂ł̎���
#define ITEM_COUNT 100
//�t�@�C�A�[�𕬎˂��鎞��
#define FIRE_COUNT 400
//�V���b�g��ł܂ł̎���
#define SHOT_COUNT 100

//�X�e�[�W���̍ő吔
#define STAGESTATE_MAX 100

//���̍ő吔
#define KEMURI_MAX 1000

//��C�̍ő吔
#define GUN_MAX 100

//���ˌ��̍ő吔
#define WIND_MAX 100

//---------------------------------�񌝐錾-------------------------------------


//�Q�[�����[�h�̎��
enum {GAMEMODE_PROJECT,GAMEMODE_TITLE,GAMEMODE_GAME};

//�{�[���̃��b�V���̎��
enum {BALLMESH_CHARA,BALLMESH_CHARAEND=BALLMESH_CHARA+4,BALLMESH_IWA,BALLMESH_IWA2,BALLMESH_TETU,BALLMESH_TAMA,
		BALLMESH_BOMB,BALLMESH_YUUDOU,BALLMESH_MINITETU,BALLMESH_BIGTETU,BALLMESH_BIGIWA,BALLMESH_IZIGENBALL,BALLMESH_TETU2,BALLMESH_TETU3,BALLMESH_TETU4,BALLMESH_MAX};

//�����蔻��̎��
enum {ITAKIND_CORCEOUT,ITAKIND_NORMAL,ITAKIND_MOVE,ITAKIND_ROTATE};////�R�[�X�A�E�g�A���ʂ̕ǁA��]�A�ړ��A�Ȃǂ̎��

//�u�Ő��A�؁A�S�v�Ȃǂ̍ގ��̎��(MATKIND_NULL�͂������Ă������ɕω����N�����Ȃ���)
enum {MATKIND_NULL,MATKIND_CHARA,MATKIND_CHARAEND=MATKIND_CHARA+5,MATKIND_SIBA,MATKIND_TUTI,MATKIND_KI,MATKIND_TETU,MATKIND_TETU2,MATKIND_TETUTAMA,
		MATKIND_ISI,MATKIND_SUNA,MATKIND_IZIGEN,MATKIND_GURABI,MATKIND_YUUDOU,MATKIND_GOMU,MATKIND_MAX};

//���}�b�v�̎��
enum {ENVKIND_PROJECT,ENVKIND_KI,ENVKIND_META,ENVKIND_TETU,ENVKIND_TETUMETA,ENVKIND_IZIGEN,ENVKIND_MAX};

//�A�C�e���̎��
enum {ITEMKIND_NONE,ITEMKIND_TAIHOU,ITEMKIND_FIRE,ITEMKIND_SHOT,ITEMKIND_BOMB,ITEMKIND_MIZU,ITEMKIND_YUUDOU,ITEMKIND_GURABI,ITEMKIND_MAX};

//�T�E���h�̎��
enum {SOUNDKIND_PURA,SOUNDKIND_TETU,SOUNDKIND_SIBA,SOUNDKIND_IZIGEN,SOUNDKIND_GOMU};





//---------------------------------�ϐ��錾-------------------------------------


WNDCLASSEX wc;
HWND hWnd;


//-----���G�ȕϐ�-----

GraphicClass DG;
InputClass DI;
CSoundManager*          DS       = NULL;
LPDIRECTSOUND3DLISTENER DSListener         = NULL;   // 3D listener object

JudClass judc;
FeedClass feed[5];//�v�f4�͑S�̂�


//�X�e�[�W���b�V��
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



//-----�P���ȕϐ�-----

float Version;

int gamemode;

bool end;


float fovy=distance(D3DX_PI/3,D3DX_PI/3*(4.0f/3.0f))*deg;



int playercount;//�v���[���[�̂ɂ񂸂�


//�����I�ɃZ���N�g���o�����Ƃ���true�ɂ���
bool autostop;

//�X�e�[�W���
int stagekind;
int stagenum;


//�~�߂��l�̔ԍ����o���Ă���
int stopplayer;

int itemcount;


float itemkakuritu[ITEMKIND_MAX];//�A�C�e���̏o�������i�[
float itemkakurituend[ITEMKIND_MAX];//�A�C�e���̏o�����̌v�Z�ɂ��悤
float itemkakuritusum;//�A�C�e���̏o�����̌v�Z�ɂ��悤





int Time,rTime,hTime[STAGE_MAX+CORCE_MAX];//hTime��[0�`29]�܂ł��X�e�[�W�AhTime��[30�`42]�܂ł��R�[�X
int lap;



int clearstage;//�X�e�[�W�̃N���A��

bool Ghost;//���v���C��\������z(�S�[�X�g)

int autoReplayCount;//�������v���C�ɓ���J�E���g
bool replay,replayend;
bool autoReplay;//�����I�Ƀ��v���C�Đ��ɓ������Ƃ���ON�ɂ��Ă���
bool startend;//�������v���C���A�X�^�[�g�{�^���ŏI�������Ƃ�ON�ɂ���

int multiplayernum;//�}���`�v���C���A�v���C���[���Ԃ����i�[


int gameframe;//�}���`�v���C���A�Â��f�[�^�͎󂯕t���Ȃ��I�I






//-----�l�b�g���[�N�n-----

bool KeepIP;
bool KeepPort;

//�ق��̃v���O����������Q�Ƃ������̂ŁA�\�P�b�g�͂����Ő錾�I�I
SOCKET s;

bool MultiPlayCountStart;//�Q�[�����X�^�[�g����
bool MultiPlayStart;//�Q�[����ʂֈړ�����

int Error;//�G���[�����������Ƃ��ɃG���[���b�Z�[�W�̔ԍ����i�[���Ă���(�l�b�g���[�N)
//��Error�̒l�ɂ��A�G���[��ʂ֋����I�ɂǂ�����ꍇ������

int myID,fromID[3];//��������̃��b�Z�[�W��F�����邽�߂̂���
bool multiplayready[3];//�Q�[���ɓ���邩�𒲂ׂ�Ƃ��Ɏg��
bool multiplayreadymy;//���������������̂Ƃ��Atrue�ɂ���

bool multiplaystartcount[3];//�X�^�[�g�J�E���g�ɓ���邩�𒲂ׂ�Ƃ��Ɏg��

int gamestartlimit;//�������Ȃ��ꍇ�̌��E�҂����ԂƂ��Ŏg���ϐ�







//---------------------------------�\���̐錾---------------------------------


//�ǂ̃{�^�����ǂ̃L�[�����i�[����\����(-1)�͐ݒ�Ȃ�
struct keynumstruct
{
	//�{�^��
	int ok;
	int cancel;
	int jump;
	int item;
	int start;
	int rightrote;//�J�����E�Ɉړ�
	int leftrote;//�J�������Ɉړ�

	//��(�L�[�{�[�h�̏ꍇ�̓{�^��)
	int axis,axis2;//�W���C�p�b�h�p
	int up,down,left,right,up2,down2,left2,right2;//�L�[�{�[�h�p�A2�̓J������]�p

	float axisover,axisover2;//�ǂ��܂ł������Ȃ��ĂȂ����Ƃɂ��邩�����Ŏw�肷��(0�`1)

	bool VibEnable;//�o�C�u���[�V�����̗L��

}keynum[5];//[0]�̓L�[�{�[�h�p


//�ǂ̃{�^���������ꂽ���Ȃǂ��i�[����\����
struct buttonstatestruct
{
	//�����Ȃ���ꂽ�u�Ԃ�������悤�ɑO�̏�Ԃ��L�^���Ă���

	bool ok;
	bool cancel;
	bool start;
	bool startpress;
	bool rightrote;
	bool leftrote;
	bool jump;
	bool item;

	float x,y,x2,y2;
	bool bx,by;//�X�e�B�b�N���|���ꂽ�u�Ԃ���True�ɂ���
	
}buttonstate[5];//�Y�����̓v���C���[�ԍ��A[4]�͑S�̂��ł��鑀��p�ɁA�O�`�R�܂ł�OR�݂����Ȃ̂��i�[



//�Q�[���̐ݒ�ȂǂɕK�v�ȕϐ�
struct GameSetting
{
	int Key1p;//1P���L�[�{�[�h����Ȃ�true
	bool only1p;
	//bool VibEnable;

	bool BGM;
	bool Sound3D;//3D�T�E���h�����邩
	int SoundAlg;//0���Œ�A1���ō�
	int SoundCommit;//���R�}��1��X�V���邩���i�[

	bool FullScreen;
	int FormWidth,FormHeight;
	int BufferWidth,BufferHeight;
	int BufferFormat;
	bool ShadeEnable;
	float KemuriMaxDis;//�����ǂ��܂ŕ\�����邩
	float ItemMaxDis;//�A�C�e�����ǂ��܂ŕ\�����邩
	bool MultiTextureEnable;
//	bool ProgMeshEnable;
//	float MultiMeshRat;//�f�t�H���g�̋����̂ǂ̂��炢�ŏ����邩
	bool FiltarEnable;
	bool MipmapEnable;
	bool MipmapFiltarEnable;
	float MipmapBias;//�݂��Ճ}�b�v�̃o�C�A�X
	bool EnvEnable;

	bool Seaver;
	char ip[16];
	char port[7];
	bool IPKeep;
	bool PortKeep;

	int SoundMultiCount;//���������Đ���

	int Anti;

}Setting;



//�ގ��\����(moveres,rotares�̓{�[���ɂ����֌W�Ȃ�)
struct MaterialStruct
{
	float df,sf,moveres,rotares,bound,rollres;//res�͋�C��R�W��,rollres�͏�Ɉ��Ȓ�R
}matstruct[MATKIND_MAX];



//�L�����N�^�[�\����(�قƂ�ǂ̃f�[�^�͍ގ��\���̂ɂ���)
struct CharaStruct
{
	float r,w,power,speed,jump;
}character[6];//player[].charnum��Y�����Ƃ���



//�v���C���[�������
struct PlayerStruct
{
	bool goal,FinalLap;
	int lap,rank;
	float par,temppar;
	//par�͌��肳�ꂽ���݈ʒu�p�[�Z���g(�����ƒ��n�����Ƃ��Ɍ��܂�)�Atemppar�͈ꎞ�I�Ȍ��݈ʒu�p�[�Z���g(�󒆂ł����܂�)

	D3DXVECTOR3 cpo,cpoold,cup,ballold;//,cameraold;//�J�����̈ʒu�Ə�
	//(ballold,cameraold�̓}���`�v���C�ł̉������x�̒x���ɑΉ����邽�߂ɍ�����ϐ��ŁA�X���[�Y�Ɉړ�������)
	D3DXVECTOR3 cponext,cupnext;//cpo,cup�����̃x�N�g���ɂȂ�悤�ɒǂ����Ă���
    D3DVIEWPORT8 vp;
	int charnum;//���삷��L�����N�^�[�̔ԍ�

	bool InputEnable;//����\�����i�[

	//�A�C�e���֌W�̕ϐ�
	int itemkind,usekind,usecount;//itemkind=�����Ă�A�C�e��,usekind=�g���Ă�A�C�e��,usecount=�g���Ă�A�C�e���̎c�莞��
	//int damagekind,damagecount;//�G�ɂ��ꂽ�ȏ��Ԃ̎�ނ�G���g�����A�C�e���̎�ނŊi�[�I�I(���낢��g����Ə㏑��)
	float itemangle;
	int backcount;//�t���������

	int ClientItem;//�N���C�A���g�ŃA�C�e���̌��ʂ��ق����Ƃ��Ɏg�p����B(0�͂Ȃ��A1�̓X�^�[�g�n�A2�͎����n)
	int ClientItemKind;//���ƈꏏ�Ɏg���A�C�e���̃C���f�b�N�X
	int ClientItemCount;//���ƈꏏ�Ɏg���A�C�e���̃J�E���g

	int MutekiCount;//0�ȊO�̂Ƃ��̓E�H�[�^�[�̉e�����󂯂Ȃ�
}player[4];



//�T�E���h�֌W�̍\����
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


	CSound* Project;//�v���W�F�N�g�̕����\�����̉�

	CSound* Select;//�Z���N�g���A�I������Ƃ��̉�
	CSound* RotaStart;//�Z���N�g���A��ʂ��ς��n�߂̉�
	CSound* RotaEnd;//�Z���N�g���A��ʂ��ς��I���Ƃ��̉�

	CSound* Kansei;//������(�X�^�[�g�O�A�S�[����ɂȂ���)
	CSound* Count;//�J�E���g�_�E���̉�
	CSound* Start;//�J�E���g�I���i�X�^�[�g�j�̉�
	CSound* Final;//�t�@�C�i�����b�v


	CSound* Item[SOUND_PLAYMAX];//�A�C�e�����Ƃ����Ƃ��̉�
	SoundStruct3D Item3D[SOUND_PLAYMAX];

	CSound* Fire[SOUND_PLAYMAX];//�t�@�C�A�[�𐁂��Ă�Ƃ��̉�
	SoundStruct3D Fire3D[SOUND_PLAYMAX];

	CSound* Mizu[SOUND_PLAYMAX];//�����̂Ƃ��̉�
	SoundStruct3D Mizu3D[SOUND_PLAYMAX];

	CSound* Bomb[SOUND_PLAYMAX];//���������Ƃ��̉�
	SoundStruct3D Bomb3D[SOUND_PLAYMAX];

	CSound* Shot[SOUND_PLAYMAX];//�����������Ƃ��̉�
	SoundStruct3D Shot3D[SOUND_PLAYMAX];

	CSound* ShotCount[SOUND_PLAYMAX];//�������Ƃ��̃J�E���g
	SoundStruct3D ShotCount3D[SOUND_PLAYMAX];

	CSound* Tetu[SOUND_PLAYMAX];//�����Ȃǂ����������Ƃ��̉�
	SoundStruct3D Tetu3D[SOUND_PLAYMAX];

	CSound* Pura[SOUND_PLAYMAX];//�v���X�`�b�N�Ȃǂ����������Ƃ��̉�
	SoundStruct3D Pura3D[SOUND_PLAYMAX];

	CSound* Ki[SOUND_PLAYMAX];//�؂Ȃǂ����������Ƃ��̉�
	SoundStruct3D Ki3D[SOUND_PLAYMAX];

	CSound* Siba[SOUND_PLAYMAX];//�Ő��ɂ��������Ƃ��̉�
	SoundStruct3D Siba3D[SOUND_PLAYMAX];

	CSound* Izigen[SOUND_PLAYMAX];
	SoundStruct3D Izigen3D[SOUND_PLAYMAX];

	CSound* Gomu[SOUND_PLAYMAX];
	SoundStruct3D Gomu3D[SOUND_PLAYMAX];

	CSound* Yudou[SOUND_PLAYMAX];//�U�����e�̈ړ���
	SoundStruct3D Yudou3D[SOUND_PLAYMAX];

	CSound* Gurabi[SOUND_PLAYMAX];//�d�̓A�C�e����
	SoundStruct3D Gurabi3D[SOUND_PLAYMAX];

	CSound* GurabiStart[SOUND_PLAYMAX];//�d�̓A�C�e���g�p��
	SoundStruct3D GurabiStart3D[SOUND_PLAYMAX];

	CSound* BombOut[SOUND_PLAYMAX];//�{���𗎂Ƃ���
	SoundStruct3D BombOut3D[SOUND_PLAYMAX];


	CSound* Meka[SOUND_PLAYMAX];//���J��
//	SoundStruct3D Meka3D[SOUND_PLAYMAX];

	CSound* MizuStart[SOUND_PLAYMAX];//��������
	SoundStruct3D MizuStart3D[SOUND_PLAYMAX];

	CSound* Iwa[SOUND_PLAYMAX];//��̓]���鉹
	SoundStruct3D Iwa3D[SOUND_PLAYMAX];

}sd;


//�����̃{�[���������
struct BallStruct
{

	//���̑��̂��낢��ȏ��(�T�E���h�C���f�b�N�X�Ƃ�)
	int info[2];

	int matindex;//�ގ�

	D3DXVECTOR3 gv;//�d�͂̕���

	BallClass ball;
	int meshindex;
	bool enable;
	int deletecount;//0�̂Ƃ��͏����Ȃ��Ƃ����Ӗ�

	int nojudindex;//�D��ЂƂ��������蔻�肵�Ȃ��{�[����ݒ肷��Ƃ����炱�̕ϐ���ς���
	//��nojudindex�́A�{�[�����m������Ă�����A�����I��-1�ɂȂ�I

}ball[BALL_MAX];


//�A�C�e�����
struct ItemStruct
{
	int kind;
	int getter;//�A�C�e�����Ƃ����l�̃C���f�b�N�X���i�[����
	D3DXVECTOR3 po,nowpo;
	int deletecount;//�����Ƃ���10�ɁA�����Ƃ���-50�ɂ���
	float angle;//��]
	D3DXMATRIX mat;
}item[ITEM_MAX];


//�������
struct BombStruct
{
	D3DXVECTOR3 p;
	//sizemax��0�̂Ƃ��A�����͂Ȃ�
	float sizemax,size,sizeadd;//size��sizeadd�𑫂��Ă����Asizemax�ŏI���
	D3DXMATRIX mat;
	D3DXVECTOR3 axis;//��]��
}Bomb[BOMB_MAX];
MeshClass bombmesh;




//�X�e�[�W�����i�[����
struct StageStruct
{
	short int kind;//�R�[�X�A�E�g�A���ʂ̕ǁA��]�A�ړ��A�Ȃǂ̎��
	short int matindex;//�Ő��A�؁A�S�A�Ȃǂ̎��
	D3DXVECTOR3 v,v2;//�����ȖړI�Ɏg���ϐ�
	float s,s2;//�����ȖړI�Ɏg���X�J���[
}stagestate[STAGESTATE_MAX];

D3DXMATRIX stagematrix;//�X�e�[�W���L�̃}�g���b�N�X���L��ꍇ�Ɏg��

/*StageStruct�̐���

Kind=0 : ���ʂȒn��
v,v2 �͎g�p���Ȃ�

Kind=1 : �R�[�X�A�E�g�n��
v,v2 �͎g�p���Ȃ�

Kind=2 : �ړ��n��
v=�ړ������Ƒ��x,v2.x.y=���݂̈ړ��ʒu

Kind=3 : ��]�n��
v=��]�̌��_,v2=��]���Ɖ�]��,s=���݂̉�]��

*/



//��C�����i�[����
struct GunStruct
{
	short int kind;//�O���t�B�b�N�̎��
	D3DXVECTOR3 p;//�ʒu
	D3DXVECTOR3 v;//��΂������Ɛ����x�N�g��
	D3DXMATRIX mat;//�g�����X�t�H�[���p�}�g���b�N�X
}gun[GUN_MAX];

int guncount;

//���ˌ������i�[����
struct WindStruct
{
	bool enable;
	short int kind;//�O���t�B�b�N�̎��
	D3DXVECTOR3 p;//�ʒu
	D3DXVECTOR3 v;//��΂������Ɛ����x�N�g��
	float dis;//�ǂꂾ���̋�����Ԃ����i�[
	float ang;//���ˊp�x���i�[
	D3DXMATRIX mat;//�g�����X�t�H�[���p�}�g���b�N�X
}wind[WIND_MAX];

int windcount;



//�������i�[����
struct KemuriStruct
{
	int kind;//���
	int frame;//���
	int framemax;//���R�}�ŏ����邩�E�E�E
	D3DXVECTOR3 po;//�ʒu
	D3DXVECTOR3 mv;//�ړ���
}kemuri[KEMURI_MAX];




struct GoalStruct
{
	D3DXVECTOR3 p;
	D3DXVECTOR3 v;//���̏o�����
	int index;//�S�[���ƂȂ鉌�̃C���f�b�N�X
}goal;



//---------------------------------�֐��錾-------------------------------------

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



//�����C���֐��Ńv���g�^�C�v�錾���Ȃ��ƃG���[���o���Ⴄ�l�b�g���[�N�n�֐��̃v���g�^�C�v�錾

void InfoNetRender(char *str);
void SendAllPlayerInfo(int count);//�S�v���C���[�̏�񑗐M(�X�e�[�W����)
void SendMyPlayerInfo();//�v���C���[�̏��
void SendPlayerOut();
void SendSeaverDown();
int GetNowPlayerCount();
void Sendokcancel(bool ok);




//�ȒP�Ȋ֐���}�N��

//t�b��~�I�I
void wait(float t)
{
	int oldclock=clock();
	while(oldclock+(t*1000.0f)>clock());
}


//float��DWORD�ɕϊ�����
inline DWORD FtoDW( FLOAT f ) { return *((DWORD*)&f); }

//��~�A���Z�b�g�A�Đ����܂Ƃ߂Ă��}�N��
#define SOUND_PLAY(p) p->Stop(),p->Reset(),p->Play()

//���}�b�v���L���̂Ƃ��͂��̂܂܁A�����̂Ƃ���NULL��Ԃ�
#define ENVCHECK(p) (Setting.EnvEnable ? p : NULL)

//�}���`�v���C���T�[�o�[�̂Ƃ���true��Ԃ�
#define seaver (stagekind!=SELECTGAME_MULTIPLAY || Setting.Seaver)

//3D�T�E���h���Đ����邩��Ԃ�
#define play3d (Setting.Sound3D && (playercount==1 || stagekind==SELECTGAME_MULTIPLAY))

//�U������R���g���[���̃C���f�b�N�X��Ԃ�
#define multiplayindex(p) (stagekind!=SELECTGAME_MULTIPLAY ? p : (p==multiplayernum ? 0 : -1) )

//�َ����R�[�X���̃`�F�b�N
#define izigen ((stagekind!=SELECTGAME_STAGE && stagenum>=9) || (stagekind==SELECTGAME_STAGE && stagenum>=25 || stagenum==12))

//�X�^�b�t���[���ŃN���A���ĂȂ����̃`�F�b�N
#define staff (stagekind==SELECTGAME_STAGE && ((stagenum==12 && clearstage<13) || (stagenum==29 && clearstage<30)))





//�t�@�C����ǂ݁A�`�F�b�N�p���l���쐬����(�啶���A���������d�v�Ȃ̂Œ��ӂ��K�v)
int createcheck(char *filename)
{
	FILE* file;
	int ans=0,count=0;
	char c,*p=filename;

	//�|�C���^��߂�
	p=filename;

	//�N���A�t�@�C�����o�C�i���ŊJ���Đ��l�����
	if((file=fopen(filename,"rb"))==NULL) return false;

	while(fscanf(file,"%c",&c)!=EOF)
	{
		count+=2;
		ans+=(c*count)%256;
	}

	//�t�@�C�����œ�����������
	while(*p!='\0')
	{
		count++;
		ans+=((*p)*count)%256;
		p++;
	}

	fclose(file);


	return ans;
}





//�t�@�C�����s���łȂ����`�F�b�N����
bool checkfile(char *filename)
{
	//createcheck�̌��ʂ�filename+"c"�̒��g���r���Č��ʂ�Ԃ�
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

//�`�F�b�N�t�@�C�����쐬����
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






//---------------------------------�Ō�̃C���N���[�h---------------------------------


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
