#include "ball.h"

BallClass::BallClass()
{
	reset();
}

void BallClass::reset()
{
	rotamat=D3DXMATRIX(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
	po=D3DXVECTOR3(0,0,0);
	mv=D3DXVECTOR3(0,0,0);
	axis=D3DXVECTOR3(0,0,0);
	r=1;
	w=1;
}

void BallClass::move(bool move,bool rota)
{
	D3DXMATRIX matrix;

	if(move)
		po+=mv;

	if(rota && axis!=D3DXVECTOR3(0,0,0))
	{
		//�{�[���̃}�g���b�N�X�v�Z(p,v,m)
		D3DXMatrixRotationAxis( &matrix, &axis, (360*distance3(axis.x,axis.y,axis.z))/(2*pi*r)*rad);
		rotamat*=matrix;
	}

	D3DXMatrixTranslation( &matrix, po.x,po.y,po.z);
	mat=rotamat*matrix;
	
}




D3DXVECTOR3 BallClass::getrota(D3DXVECTOR3 p)//��]�݂̂��l�����A����_�̈ړ����x�����߂�
{


	if(axis!=D3DXVECTOR3(0,0,0))
	{
		float ang,ang2,dis;

		//axis����ɗ��Ă�悤��p����]���Ă���

		//X-Z����ŁAX����axis������悤�ɉ�]
		ang=angle(axis.x,axis.z);
		rotation(&p.x,&p.z,-ang);

		//X-Y����ŁAY����axis������悤�ɉ�]
		ang2=angle(axis.y,distance(axis.x,axis.z));
		rotation(&p.y,&p.x,-ang2);


		//p�̔��a��X-Z���W��ŋ��߂�
		dis=distance(p.x,p.z);

		//������ݒ�
		rotation(&p.x,&p.z,-90);
		p.y=0;

		//�傫����ݒ�
		changedistance(&p.x,&p.z,dis/r*distance3(axis.x,axis.y,axis.z));


		//p�����[���h���W�֖߂�

		rotation(&p.y,&p.x,ang2);
		rotation(&p.x,&p.z,ang);

		return p;
	}
	else
	{
		return axis;
	}

}


D3DXVECTOR3 BallClass::getmove(D3DXVECTOR3 p)//���̈ړ��݂̂��l�����A����_�̈ړ����x�����߂�i����_�Ƌ��̐ږʏ�ɋ��߂�)
{
	//p�̃x�N�g���ƈړ��ʂ̃x�N�g���̊p�x�����߂�
	float mvdis=distance3(mv.x,mv.y,mv.z);
	float pDotv=(p.x*mv.x+p.y*mv.y+p.z*mv.z)/(distance3(p.x,p.y,p.z)*mvdis);

	//�덷����
	if(pDotv>1)
		pDotv=1;
	if(pDotv<-1)
		pDotv=-1;

	float ang=acosf(pDotv);



	//�ʏ�̈ړ��ʃx�N�g�������߂�

	//p�̒�����ύX
	D3DXVECTOR3 subv=p;

	changedistance3(&subv.x,&subv.y,&subv.z,mvdis*cosf(ang));

	return mv-subv;
}






void BallClass::setmove(D3DXVECTOR3 v)//�ړ�(�d�����l����)
{
	mv.x+=v.x/w;
	mv.y+=v.y/w;
	mv.z+=v.z/w;
}

void BallClass::setrota(D3DXVECTOR3 v)//��](�d�����l����)
{
	axis.x+=v.x/w;
	axis.y+=v.y/w;
	axis.z+=v.z/w;
}


void BallClass::setpower(D3DXVECTOR3 p,D3DXVECTOR3 v,float n,float df,float sf,float rat)//��]�A�ړ��̗����ɗ͂�������(rat�͈ړ��̊���)
{
	//��]�A�ړ��̗����ɗ͂�������(n�͐ړ_�̂Ԃ���������(����*�d��),df�͓����C�W��,sf�͐Î~���C�W��,rat�͈ړ��̊���)
	//n��0�̂Ƃ��͖��C��100%

	//fps�Ŋ���
	df/=60;
	sf/=60;




	//v��p�����łԂ�
	float dis=dotpro3(p.x,p.y,p.z,v.x,v.y,v.z);

	//up�̒�����dis�ɂ��Awvec����Ђ�
	D3DXVECTOR3 wvec=p;
	changedistance3(&wvec.x,&wvec.y,&wvec.z,dis);
	v-=wvec;





	D3DXVECTOR3 pointv=getrota(p)+getmove(p);//�������Ă��_�̈ړ��ʂ����߂�

	//v�Ƃ̍������߂�
	pointv=v-pointv;


	if(n!=0)
	{


		//���C�֌W

		//�Î~���C�͂�菬�����悤�Ȃ炻�̂܂�
		float dis=distance3(pointv.x,pointv.y,pointv.z);//�_p�̎���


		if(dis > n*sf)
		{
			//�Î~���C�͂��傫���I

			//�����C�͂ɐ���
			float f=n*df;
			{
				changedistance3(&pointv.x,&pointv.y,&pointv.z,f);

			}

		}



	}




	//�ړ�
	mv+=D3DXVECTOR3(pointv.x*rat,pointv.y*rat,pointv.z*rat);



	//��]
	D3DXMATRIX matrix;
	D3DXVECTOR4 ansv;
	D3DXVECTOR3 rotav=D3DXVECTOR3(pointv.x*(1-rat),pointv.y*(1-rat),pointv.z*(1-rat));



	D3DXMatrixRotationAxis( &matrix, &rotav, -90*rad );
	D3DXVec3Transform(&ansv,&p,&matrix);

	//�������܂����̂Ō�͉��Z���邾��

	//��������
	changedistance3(&ansv.x,&ansv.y,&ansv.z,distance3(rotav.x,rotav.y,rotav.z));

	//��]�����̕ύX
	axis.x+=ansv.x;
	axis.y+=ansv.y;
	axis.z+=ansv.z;

	
}

void BallClass::setmoveres(float res,D3DXVECTOR3 windv)//�ړ��ɋ�C��R��������(r=1,v=1�̂Ƃ��̒�R�͂�res�Ƃ���)
{
	//�t�����x�N�g�������߂�
	D3DXVECTOR3 v=(windv-mv);
	float mul=res*r;
	v.x*=mul;
	v.y*=mul;
	v.z*=mul;
	mv+=v/w;
}


void BallClass::setrotares(float res)//��]�ɋ�C��R��������(r=1,v=1�̂Ƃ��̒�R�͂�res�Ƃ���)
{
	if(axis!=D3DXVECTOR3(0,0,0))
	{
		//�t�����x�N�g�������߂�
		D3DXVECTOR3 v;
		v=-axis;
		changedistance3(&v.x,&v.y,&v.z,res*r*distance3(axis.x,axis.y,axis.z)/w);
		axis+=v;
	}
}




//��Ɉ��̒�R��������
void BallClass::setrotaressub(float res)//��]�ɒ�R��������
{
	if(axis!=D3DXVECTOR3(0,0,0))
	{
		if(distance3(axis.x,axis.y,axis.z)<=res)
			axis=D3DXVECTOR3(0,0,0);
		else
		{
			//�t�����x�N�g�������߂�
			D3DXVECTOR3 v;
			v=-axis;
			changedistance3(&v.x,&v.y,&v.z,res);
			axis+=v;
		}
	}
}
