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
		//ボールのマトリックス計算(p,v,m)
		D3DXMatrixRotationAxis( &matrix, &axis, (360*distance3(axis.x,axis.y,axis.z))/(2*pi*r)*rad);
		rotamat*=matrix;
	}

	D3DXMatrixTranslation( &matrix, po.x,po.y,po.z);
	mat=rotamat*matrix;
	
}




D3DXVECTOR3 BallClass::getrota(D3DXVECTOR3 p)//回転のみを考慮し、ある点の移動速度を求める
{


	if(axis!=D3DXVECTOR3(0,0,0))
	{
		float ang,ang2,dis;

		//axisを上に立てるようにpを回転していく

		//X-Z軸上で、X軸にaxisが来るように回転
		ang=angle(axis.x,axis.z);
		rotation(&p.x,&p.z,-ang);

		//X-Y軸上で、Y軸にaxisが来るように回転
		ang2=angle(axis.y,distance(axis.x,axis.z));
		rotation(&p.y,&p.x,-ang2);


		//pの半径をX-Z座標上で求める
		dis=distance(p.x,p.z);

		//方向を設定
		rotation(&p.x,&p.z,-90);
		p.y=0;

		//大きさを設定
		changedistance(&p.x,&p.z,dis/r*distance3(axis.x,axis.y,axis.z));


		//pをワールド座標へ戻す

		rotation(&p.y,&p.x,ang2);
		rotation(&p.x,&p.z,ang);

		return p;
	}
	else
	{
		return axis;
	}

}


D3DXVECTOR3 BallClass::getmove(D3DXVECTOR3 p)//球の移動のみを考慮し、ある点の移動速度を求める（ある点と球の接面上に求める)
{
	//pのベクトルと移動量のベクトルの角度を求める
	float mvdis=distance3(mv.x,mv.y,mv.z);
	float pDotv=(p.x*mv.x+p.y*mv.y+p.z*mv.z)/(distance3(p.x,p.y,p.z)*mvdis);

	//誤差調整
	if(pDotv>1)
		pDotv=1;
	if(pDotv<-1)
		pDotv=-1;

	float ang=acosf(pDotv);



	//面上の移動量ベクトルを求める

	//pの長さを変更
	D3DXVECTOR3 subv=p;

	changedistance3(&subv.x,&subv.y,&subv.z,mvdis*cosf(ang));

	return mv-subv;
}






void BallClass::setmove(D3DXVECTOR3 v)//移動(重さも考える)
{
	mv.x+=v.x/w;
	mv.y+=v.y/w;
	mv.z+=v.z/w;
}

void BallClass::setrota(D3DXVECTOR3 v)//回転(重さも考える)
{
	axis.x+=v.x/w;
	axis.y+=v.y/w;
	axis.z+=v.z/w;
}


void BallClass::setpower(D3DXVECTOR3 p,D3DXVECTOR3 v,float n,float df,float sf,float rat)//回転、移動の両方に力をかける(ratは移動の割合)
{
	//回転、移動の両方に力をかける(nは接点のぶつかった強さ(速さ*重さ),dfは動摩擦係数,sfは静止摩擦係数,ratは移動の割合)
	//nが0のときは摩擦力100%

	//fpsで割る
	df/=60;
	sf/=60;




	//vをp方向でつぶす
	float dis=dotpro3(p.x,p.y,p.z,v.x,v.y,v.z);

	//upの長さをdisにし、wvecからひく
	D3DXVECTOR3 wvec=p;
	changedistance3(&wvec.x,&wvec.y,&wvec.z,dis);
	v-=wvec;





	D3DXVECTOR3 pointv=getrota(p)+getmove(p);//当たってる一点の移動量を求める

	//vとの差を求める
	pointv=v-pointv;


	if(n!=0)
	{


		//摩擦関係

		//静止摩擦力より小さいようならそのまま
		float dis=distance3(pointv.x,pointv.y,pointv.z);//点pの質量


		if(dis > n*sf)
		{
			//静止摩擦力より大きい！

			//動摩擦力に制限
			float f=n*df;
			{
				changedistance3(&pointv.x,&pointv.y,&pointv.z,f);

			}

		}



	}




	//移動
	mv+=D3DXVECTOR3(pointv.x*rat,pointv.y*rat,pointv.z*rat);



	//回転
	D3DXMATRIX matrix;
	D3DXVECTOR4 ansv;
	D3DXVECTOR3 rotav=D3DXVECTOR3(pointv.x*(1-rat),pointv.y*(1-rat),pointv.z*(1-rat));



	D3DXMatrixRotationAxis( &matrix, &rotav, -90*rad );
	D3DXVec3Transform(&ansv,&p,&matrix);

	//軸が求まったので後は加算するだけ

	//長さ調整
	changedistance3(&ansv.x,&ansv.y,&ansv.z,distance3(rotav.x,rotav.y,rotav.z));

	//回転方向の変更
	axis.x+=ansv.x;
	axis.y+=ansv.y;
	axis.z+=ansv.z;

	
}

void BallClass::setmoveres(float res,D3DXVECTOR3 windv)//移動に空気抵抗をかける(r=1,v=1のときの抵抗力をresとする)
{
	//逆向きベクトルを求める
	D3DXVECTOR3 v=(windv-mv);
	float mul=res*r;
	v.x*=mul;
	v.y*=mul;
	v.z*=mul;
	mv+=v/w;
}


void BallClass::setrotares(float res)//回転に空気抵抗をかける(r=1,v=1のときの抵抗力をresとする)
{
	if(axis!=D3DXVECTOR3(0,0,0))
	{
		//逆向きベクトルを求める
		D3DXVECTOR3 v;
		v=-axis;
		changedistance3(&v.x,&v.y,&v.z,res*r*distance3(axis.x,axis.y,axis.z)/w);
		axis+=v;
	}
}




//常に一定の抵抗をかける
void BallClass::setrotaressub(float res)//回転に抵抗をかける
{
	if(axis!=D3DXVECTOR3(0,0,0))
	{
		if(distance3(axis.x,axis.y,axis.z)<=res)
			axis=D3DXVECTOR3(0,0,0);
		else
		{
			//逆向きベクトルを求める
			D3DXVECTOR3 v;
			v=-axis;
			changedistance3(&v.x,&v.y,&v.z,res);
			axis+=v;
		}
	}
}
