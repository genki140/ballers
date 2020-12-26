#ifndef JUDGMENT_HED
#define JUDGMENT_HED

#include <math.h>
#include <D3dx8math.h>
#include "mathematic.h"

//JUDSTRUCT_MAX*36byte
#define JUDSTRUCT_MAX 1000





#define BOX_X_MAX 10
#define BOX_Y_MAX 10
#define BOX_Z_MAX 10

//JUDSTRUCT_MAX*BOX_X_MAX*BOX_Y_MAX*BOX_Z_MAX*4byte
#define BOX_I_MAX 10000//(4000万byte=4万KB=40MByte)


#define POL_LIST_MAX 5000
#define SPH_LIST_MAX 5000

class JudClass
{





private:

//public:







	struct TriangleStruct
	{
		short int kind;
		float h;//座標変更後の三角形の高さを格納
		D3DXVECTOR2 s,sp[3];//座標変換後の頂点座標を格納
		D3DXMATRIX mat;//座標変換用
		unsigned int cpol[3],csph[3];//チャイルドインデックス
		bool check;
	}*tri;
	struct PoleStruct
	{
		short int kind;
		D3DXMATRIX mat;//座標変換用
		unsigned int csph[2];//チャイルドインデックス
		float h;//座標変換後の円柱の高さ(頂点間の距離)
		bool check;
	}*pol;
	struct SphereStruct
	{
		short int kind;
		D3DXVECTOR3 p;//位置座標
		bool check;
	}*sph;





	struct BoxStruct
	{
		unsigned short int count[BOX_X_MAX+1][BOX_Y_MAX+1][BOX_Z_MAX+1];//←配列の要素数を1つ足してるのはバグ防止！！(未解決バグ)
		unsigned int index[BOX_X_MAX][BOX_Y_MAX][BOX_Z_MAX][BOX_I_MAX];
		D3DXVECTOR3 max,min,s;//sは、pを中心とする頂点までのベクトルをあらわす(boxの大きさを表す)
		short int cutx,cuty,cutz;
	}box;



	bool loaded;


//	TriangleStruct *tri;
//	PoleStruct *pol;
//	SphereStruct *sph;
	int tricount,polcount,sphcount;

	//三角形を調べたとき、cpolとcsphのインデックスをリストに記録し、後でそのリストから、調べるインデックスを判断する
	int pollistcount,pollist[POL_LIST_MAX];
	int sphlistcount,sphlist[SPH_LIST_MAX];

	//y軸上にある高さh*2の線分(Y軸座標で言うと -h～h )と、三角形p1-p2-p3が触れるかを調べる関数
	bool trilinejud(D3DXVECTOR3* p1,D3DXVECTOR3* p2,D3DXVECTOR3* p3,float h);
	//x-z軸上にある、幅w*2,奥行きh*2の面と、線分p1-p2が触れるかを調べる関数
	bool rectlinejud(D3DXVECTOR3* p1,D3DXVECTOR3* p2,float w,float h);

public:



	//kindは、並んだ違う種類の三角形の円柱の場合、小さい数字が優先される
	struct JudStruct 
	{
		unsigned short int count;
		D3DXVECTOR3 v[JUDSTRUCT_MAX],n[JUDSTRUCT_MAX];
		float p[JUDSTRUCT_MAX];//当たった勢いを格納
		short int kind[JUDSTRUCT_MAX];
		float dis[JUDSTRUCT_MAX];//並び替え用
	}judres;//判定の結果を格納する構造体;


	JudClass();
	//※CreateJudFileは、計算をするときに tri,pol,sphを使うので、tri,pol,sphの値は変わってしまう。(メモリの節約)
	int CreateJudFile(LPDIRECT3DDEVICE8 device,char JudFileName[],char XFileName[],int cutx,int cuty,int cutz);
	int LoadJudFile(char JudFileName[]);//,int kind);
	int FieldJud(bool line,float r,D3DXVECTOR3* p,D3DXVECTOR3* p2);
	//二つの球の判定、spは判定先の球、p,p2は、判定もとの球の軌道、srは判定先の球の半径、rは判定もとの球の半径
	void SphereJud(bool line,int kind,float sr,float r,D3DXVECTOR3* sp,D3DXVECTOR3* p,D3DXVECTOR3* p2);
	void sort();
	void reset();

};


#endif
