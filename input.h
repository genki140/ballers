#ifndef INPUT_HED
#define INPUT_HED

#include<dinput.h>
#include<stdio.h>



#define JOY_MAX 8
#define EFFECT_MAX 100 //1つのデバイスにつき、エフェクトアニメーションを同時にいくつ再生できるか


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








	//キーなどの情報を格納する構造体
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
		int Keepx[2],Keepy[2];//この変数にはただ記録しておくだけにする(他のプログラムで使われる)
		int pov;
		int keeppov;//この変数にはただ記録しておくだけにする(他のプログラムで使われる)
		bool down[128],up[128],press[128];
		bool Keep[128];
	}joy[JOY_MAX];




	InputClass();
	//~InputClass();


	bool Create( HWND hDlg, bool Ex=false, bool Effect[]=NULL, int count=0);//Ex=排他的にするか？(Effect配列はありかなしかを含む、countは要素数)
	VOID Release();
	void Acquire();
	void GetData();
	//sizeは大きさを表す(０～１) lastsizeが-1のときはsizeと同じ
	void SetEffect(int index,float size,int frame,float lastsize=-1);
	void Move();//エフェクトを自動的に動かすときに使う

	int JoyEnum(GUID guid);

};









#endif