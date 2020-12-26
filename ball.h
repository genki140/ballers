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


	//Friction(���C)

	BallClass();

	void reset();

	void move(bool move=true,bool rota=true);


	D3DXVECTOR3 getmove(D3DXVECTOR3 p);//���̈ړ��݂̂��l�����A����_�̈ړ����x�����߂�i����_�Ƌ��̐ږʏ�ɋ��߂�)
	D3DXVECTOR3 getrota(D3DXVECTOR3 p);//��]�݂̂��l�����A����_�̈ړ����x�����߂�


	//	void setrota(D3DXVECTOR3 p,D3DXVECTOR3 v,float df,float sf);//p��v�̑��x�ɂȂ�悤�Af�𖀎C�͂Ƃ��Čv�Z(�d�����l����)


	void setpower(D3DXVECTOR3 p,D3DXVECTOR3 v,float n=0,float df=0,float sf=0,float rat=0.5f);
	//��]�A�ړ��̗����ɗ͂�������(n�͐ړ_�̂Ԃ���������,df�͓����C�W��,sf�͐Î~���C�W��,rat�͈ړ��̊���)
	//p��0�̂Ƃ��͖��C��100%

	void setmove(D3DXVECTOR3 v);//�ړ��ʕϓ�(�d�����l����)
	void setrota(D3DXVECTOR3 v);//��]�ʕϓ�(�d�����l����)

	void setmoveres(float res,D3DXVECTOR3 windv);//�ړ��ɋ�C��R��������(r=1,v=1�̂Ƃ��̒�R�͂�res�Ƃ���)(v�͋�C�̗��������킷)
	void setrotares(float res);//�ړ��ɋ�C��R��������(r=1,v=1�̂Ƃ��̒�R�͂�res�Ƃ���)
	void setrotaressub(float res);//�P���ɉ�]�x�N�g���̒��������炷


//	void rota(D3DXVECTOR3 p,D3DXVECTOR3 v,float f);//���E���x���l�����Ă܂킷
//
//	void rotationpvf(D3DXVECTOR3 p,D3DXVECTOR3 v,float f);//f�͖��C��
////	void rotationaxisf(D3DXVECTOR3 vec,float f);//f�͖��C��
//
//	void rotationpv(D3DXVECTOR3 p,D3DXVECTOR3 v);//�͂�������(���C�Ȃǂ͂܂������l���Ȃ�)
////	void rotationaxis(D3DXVECTOR3 vec);//�͂�������(���C�Ȃǂ͂܂������l���Ȃ�)

};





#endif
