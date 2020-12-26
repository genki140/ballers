#ifndef FEED_HED
#define FEED_HED


#include <d3dx8.h>



//フェードイン、フェードアウトをするためのプログラム

enum { FEEDMODE_BLACKIN,FEEDMODE_BLACKOUT,FEEDMODE_WHITEIN,FEEDMODE_WHITEOUT};
//OUTはだんだん黒（白）くなって行く



class FeedClass
{
public:

	void Reset();
	void Move();
	void Start(int feedmode,int feedcount);
	void End();
	//colorの範囲は-1～1で、マイナスなら黒く、プラスなら白くなるようにレンダリングする
	//colorが0の時は、FeedStartで指定したとおりにフェードする
	void Render(LPDIRECT3DDEVICE8 device,int width,int height);//,float color=0);

	bool GetEnable();//フェード中かのチェック



	int mode,count,countend;//modeはFEEDMODE_を格納、countは現在のカウントを格納し、countendはカウント終了位置を格納

private:


	//ただの板用
	typedef struct{
		float   x, y, z, w;
		DWORD   color;
	} LVERTEX;

	//bool autoend;

};

#endif