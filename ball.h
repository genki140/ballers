#ifndef BALL_HED
#define BALL_HED


#include <math.h>
#include <D3dx8math.h>
#include "mathematic.h"

//#define BALLMOVE_MOVE 1
//#define BALLMOVE_ROTA 2
//#define BALLMOVE_MAT 4


class BallClass
{

public:

	D3DXMATRIX mat,rotamat;
	D3DXVECTOR3 po,mv,axis;
	float w,r;


	//Friction(摩擦)

	BallClass();

	void reset();

	void move(bool move=true,bool rota=true);


	D3DXVECTOR3 getmove(D3DXVECTOR3 p);//球の移動のみを考慮し、ある点の移動速度を求める（ある点と球の接面上に求める)
	D3DXVECTOR3 getrota(D3DXVECTOR3 p);//回転のみを考慮し、ある点の移動速度を求める


	//	void setrota(D3DXVECTOR3 p,D3DXVECTOR3 v,float df,float sf);//pがvの速度になるよう、fを摩擦力として計算(重さも考える)


	void setpower(D3DXVECTOR3 p,D3DXVECTOR3 v,float n=0,float df=0,float sf=0,float rat=0.5f);
	//回転、移動の両方に力をかける(nは接点のぶつかった勢い,dfは動摩擦係数,sfは静止摩擦係数,ratは移動の割合)
	//pが0のときは摩擦力100%

	void setmove(D3DXVECTOR3 v);//移動量変動(重さも考える)
	void setrota(D3DXVECTOR3 v);//回転量変動(重さも考える)

	void setmoveres(float res,D3DXVECTOR3 windv);//移動に空気抵抗をかける(r=1,v=1のときの抵抗力をresとする)(vは空気の流れをあらわす)
	void setrotares(float res);//移動に空気抵抗をかける(r=1,v=1のときの抵抗力をresとする)
	void setrotaressub(float res);//単純に回転ベクトルの長さを減らす


//	void rota(D3DXVECTOR3 p,D3DXVECTOR3 v,float f);//限界速度を考慮してまわす
//
//	void rotationpvf(D3DXVECTOR3 p,D3DXVECTOR3 v,float f);//fは摩擦力
////	void rotationaxisf(D3DXVECTOR3 vec,float f);//fは摩擦力
//
//	void rotationpv(D3DXVECTOR3 p,D3DXVECTOR3 v);//力を加える(摩擦などはまったく考えない)
////	void rotationaxis(D3DXVECTOR3 vec);//力を加える(摩擦などはまったく考えない)

};





#endif
