#ifndef INPUT_HED
#define INPUT_HED

#include<dinput.h>
#include<stdio.h>



#define JOY_MAX 8
#define EFFECT_MAX 100 //1�̃f�o�C�X�ɂ��A�G�t�F�N�g�A�j���[�V�����𓯎��ɂ����Đ��ł��邩


class InputClass
{
private:

	LPDIRECTINPUT8       DI;
	LPDIRECTINPUTDEVICE8 MDevice;
	LPDIRECTINPUTDEVICE8 KDevice;

	LPDIRECTINPUTDEVICE8 JDevice[8];
	LPDIRECTINPUTEFFECT  JEffect[8];
	
	struct EffectStruct
	{
		bool enable;
		float fastsize,lastsize;
		int startframe,nowframe;
	}effect[8][EFFECT_MAX];

	int JoyCount;

	FILE *debug_fp;

public:








	//�L�[�Ȃǂ̏����i�[����\����
	struct MouseState
	{
		int x,y,z;
		bool down[8],up[8],press[8];
		bool Keep[8];
	}mouse;

	struct KeyState
	{
		bool down[256],up[256],press[256];
		bool Keep[256];
	}key;

	struct JoyState
	{
		int x[2],y[2];
		int Keepx[2],Keepy[2];//���̕ϐ��ɂ͂����L�^���Ă��������ɂ���(���̃v���O�����Ŏg����)
		int pov;
		int keeppov;//���̕ϐ��ɂ͂����L�^���Ă��������ɂ���(���̃v���O�����Ŏg����)
		bool down[128],up[128],press[128];
		bool Keep[128];
	}joy[JOY_MAX];




	InputClass();
	//~InputClass();


	bool Create( HWND hDlg, bool Ex=false, bool Effect[]=NULL, int count=0);//Ex=�r���I�ɂ��邩�H(Effect�z��͂��肩�Ȃ������܂ށAcount�͗v�f��)
	VOID Release();
	void Acquire();
	void GetData();
	//size�͑傫����\��(�O�`�P) lastsize��-1�̂Ƃ���size�Ɠ���
	void SetEffect(int index,float size,int frame,float lastsize=-1);
	void Move();//�G�t�F�N�g�������I�ɓ������Ƃ��Ɏg��

	int JoyEnum(GUID guid);

};









#endif