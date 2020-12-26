#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include "mathematic.h"

//0以上rndmax未満 のランダムな数値を実数で返す関数
float rnd(float rndmax)
{
	float random=(float)rand();
	random/=RAND_MAX;
	if(random>=1)random=0;
	random*=rndmax;
	return random;
}

//ランダムジェネレータのランダム化
void srnd()
{
	srand((unsigned int)(GetTickCount()*time(NULL)));
}

//2つの座標の角度を、反時計回りにplusangle回転する関数
void rotation(float *x,float *y,float plusangle)
{
	float dx=*x,dy=*y,sin=sinf(plusangle*rad),cos=cosf(plusangle*rad);
	*x=dx*cos-dy*sin;
	*y=dx*sin+dy*cos;
}

//2つの座標の距離を、原点よりもとめる関数
float distance(float x,float y)
{
	return sqrtf(x*x+y*y);
}

//3つの座標の距離を、原点よりもとめる関数
float distance3(float x,float y,float z)
{
	return sqrtf(x*x+y*y+z*z);
}

//2つの座標が、dis*2を１辺とする正方形の中にあるかをもとめる関数(あればtrueを返す)
bool cubedistance(float x,float y,float dis)
{
	if(x<=dis && x>=-dis && y<=dis && y>=-dis) 
		return true; 
	else 
		return false;
}

//3つの座標が、dis*2を１辺とする立方体の中にあるかをもとめる関数(あればtrueを返す)
bool cubedistance3(float x,float y,float z,float dis)
{
	if(x<=dis && x>=-dis && y<=dis && y>=-dis && z<=dis && z>=-dis) 
		return true; 
	else 
		return false;
}

//2つの座標の角度を、原点よりもとめる関数(X軸の正方向を0°とし、反時計回り)
float angle(float x,float y)
{
	float ang;
	if((x>=0) && (y==0))
		return 0.0f;
	else if((x==0) && (y>=0))
		return 90.0f;
	else if((x<=0) && (y==0))
		return 180.0f;
	else if((x==0) && (y<=0))
		return 270.0f;
	ang=(float)(57.295779513*atan(y/x));//(57.295779513=180/3.141592)
	if(x<0)
		ang+=180;
	else if((x>0) && (y<0))
		ang+=360;

	return ang;
}

//角度を0以上360未満の範囲に修正する関数
float reangle(float angle)
{
	while((angle < 0) || (angle >= 360))
	{
		if(angle < 0)
			angle+=360;
		if(angle >= 360)
			angle-=360;
	}
	return angle;
}

//2次元ベクトルの長さを変更する関数
void changedistance(float *x,float *y,float dis)
{
	float d;

	d=distance(*x,*y);
	*x/=d;
	*y/=d;
	*x*=dis;
	*y*=dis;
}

//3次元ベクトルの長さを変更する関数
void changedistance3(float *x,float *y,float *z,float dis)
{
	float d;

	d=distance3(*x,*y,*z);
	if(d>0)
	{
		*x/=d;
		*y/=d;
		*z/=d;
		*x*=dis;
		*y*=dis;
		*z*=dis;
	}
	else
	{
		*x=0;
		*y=0;
		*z=0;
	}
}









//物理計算(物体1が左、物体2が右にあるとして計算している)
float sayou(float m1,float v1,float m2,float v2,float keisuu)
{
	if(v1-v2<=0)
		return 0;

	//ぶつかった後のv1の移動量
	float newv=(m1*v1+m2*v2+keisuu*m2*(v2-v1))/(m1+m2);

	//newvより、加わった力を求める
	float power=(v1-newv)*m1;

	return power;
}






//ベクトルAの方向成分がベクトルBにどれだけあるかをスカラーで返す関数
float dotpro(float ax,float ay,float bx,float by)
{
	//aを単位ベクトルにする
	float dis=sqrtf(ax*ax+ay*ay);
	ax/=dis;
	ay/=dis;

	return ax*bx+ay*by;
}

//ベクトルAの方向成分がベクトルBにどれだけあるかをスカラーで返す関数
float dotpro3(float ax,float ay,float az,float bx,float by,float bz)
{
	//aを単位ベクトルにする
	float dis=sqrtf(ax*ax+ay*ay+az*az);
	ax/=dis;
	ay/=dis;
	az/=dis;

	return ax*bx+ay*by+az*bz;

}


//ベクトルAとベクトルBの法線を返す関数(原点→A→Bの順に時計回りが表)
void crosspro3(float *x,float *y,float *z,float ax,float ay,float az,float bx,float by,float bz)
{
	*x=ay*bz-az*by;
	*y=az*bx-ax*bz;
	*z=ax*by-ay*bx;
	changedistance3(x,y,z,1);
}


//二つのベクトルのなす角度を調べる関数
float angle3(float x1,float y1,float z1,float x2,float y2,float z2)
{
	//二つのベクトルを単位ベクトルにする
	float dis=sqrtf(x1*x1+y1*y1+z1*z1);
	x1/=dis;
	y1/=dis;
	z1/=dis;
	dis=sqrtf(x2*x2+y2*y2+z2*z2);
	x2/=dis;
	y2/=dis;
	z2/=dis;
	return acosf(x1*x2+y1*y2+z1*z2)*deg;
}





//ある点の距離をある軸より求める関数
float distanceaxis(float x,float y,float z,float vx,float vy,float vz)
{
	//内積を使い、ベクトル上で一番近い点を見つける
	float dis=dotpro3(vx,vy,vz,x,y,z);
	changedistance3(&vx,&vy,&vz,dis);
	return distance3(vx-x,vy-y,vz-z);	
}














//ある点へのベクトルをある軸上の、点に一番近いところより求める関数
void axisvector(float *x,float *y, float *z,float ax,float ay,float az,float vx,float vy,float vz)
{

	//内積を使い、ベクトル上で一番近い点を見つける
	float dis=dotpro3(ax,ay,az,vx,vy,vz);
	changedistance3(&ax,&ay,&az,dis);


	*x=vx-ax;*y=vy-ay;*z=vz-az;

}









////ベクトルを任意軸で回転させる
//void rotationaxis(float *x,float *y,float *z,float vx,float vy,float vz,float ang)
//{
//	float wx=*x,wy=*y,wz=*z,wsin=sinf(ang*rad),wcos=cosf(ang*rad);
//
//	//任意軸回りの回転マトリックスを求め、それにベクトルをかけている
//	*x=((wcos+(1-wcos)*vx*vx)*wx)		+ (((1-wcos)*vx*vy+vz*wsin)*wy)		+ (((1-wcos)*vz*vx-vy*wsin)*wz);
//	*y=(((1-wcos)*vx*vy-vz*wsin)*wx)	+ ((wcos+(1-wcos)*vy*vy)*wy)		+ (((1-wcos)*vy*vz+vx*wsin)*wz);
//	*z=(((1-wcos)*vz*vx+vy*wsin)*wx)	+ (((1-wcos)*vy*vz-vx*wsin)*wy)		+ ((wcos+(1-wcos)*vz*vz)*wz);
//}








////ベクトルを任意軸で伸縮する
//void scalaxis(float *x,float *y,float *z,float vx,float vy,float vz,float scal)
//{
//}





//
//
//
//
//
//2つの物体の重さと移動速度より、ぶつかったときに生じる力の計算をする関数
//float sayou(float m1,float v1,float m2,float v2)
//{
//	double kyoyou=0.0001f;
//
//	if(v1-v2<=0)
//		return 0;
//
//	double power,step,enagy;
//	double vd1,vd2;//パワーがかかった後の移動量格納変数
//
//	power=0;
//
//	if(m1>=m2)
//		step=m2*(v1-v2);
//	else
//		step=m1*(v1-v2);
//
//	double dm1=m1,dv1=v1,dm2=m2,dv2=v2;
//
//	do
//	{
//		power+=step;
//
//		vd1=dv1-power/dm1;
//		vd2=dv2+power/dm2;
//
//		エネルギー計算
//		enagy=(dm1*dv1*dv1+dm2*dv2*dv2)-(dm1*vd1*vd1+dm2*vd2*vd2);
//
//		if((enagy<0 && step>0) || (enagy>0 && step<0))
//			step*=-0.5;
//
//		if(enagy<=kyoyou && enagy>=-kyoyou)
//			step=0;
//
//	}while(step!=0);
//
//	return (float)power;
//}
//















//
//
//
//
////図形計算
//
//
//
//
////線と線が触れているか調べ、触れていたらその位置を返す関数
////(pointは、線の端が触れていたときの判定をするかをブール値で格納endlessはtrueにすると無限な線になる)
//bool linejud(float *bx,float *by,
//			 float l1x1,float l1y1,float l1x2,float l1y2,float l2x1,float l2y1,float l2x2,float l2y2,
//																					bool point,bool endless)
//{
//	float ang,dis;
//	float y;//触れてる位置のY座標を格納
//	float px,py;//当たってる位置を格納
//
//	//endlessがfalseで、お互いの点がどれかでも同じ位置にあったら触れていないこととする
//	if((		(l1x1==l2x1 && l1y1==l2y1) || (l1x1==l2x2 && l1y1==l2y2) || 
//				(l1x2==l2x1 && l1y2==l2y1) || (l1x2==l2x2 && l1y2==l2y2))
//														&& endless==false)
//		return false;
//
//	//endlessがtrueで、線が同じ位置にあったら触れていないこととする
//	else if((	(l1x1==l2x1 && l1y1==l2y1 && l1x2==l2x2 && l1y2==l2y2) || 
//				(l1x2==l2x1 && l1y2==l2y1 && l1x1==l2x2 && l1y1==l2y2))
//														&& endless==true)
//
//		return false;
//	
//	//Line2をLine1のローカル座標に移動
//	l2x1-=l1x1;l2y1-=l1y1;l2x2-=l1x1;l2y2-=l1y1;
//
//	//Line1の長さと角度を求める
//	ang=angle(l1x2-l1x1,l1y2-l1y1);
//	dis=distance(l1x2-l1x1,l1y2-l1y1);
//
//	//Line2をLine1のローカル座標に回転
//	rotation(&l2x1,&l2y1,-ang);
//	rotation(&l2x2,&l2y2,-ang);
//
//	if(((l2x1>=0 && l2x2>=0) || (l2x1<=0 && l2x2<=0)) && endless==false)
//		return false;
//
//	if(endless==true && l2x1==l2x2 && endless==true)//平行線だったら
//		return false;
//
//	//触れてる位置を調べる
//	y=l2y1+(l2y2-l2y1)*(-l2x1/(l2x2-l2x1));
//
//	if(point==false)
//	{
//		if((y<=0 || y>=dis) && endless==false)
//			return false;
//	}
//	else
//	{
//		if((y<0 || y>dis) && endless==false)
//			return false;
//	}
//
//	px=l1x2-l1x1;py=l1y2-l1y1;
//	changedistance(&px,&py,1);
//	px*=y;
//	py*=y;
//	*bx=l1x1+px;
//	*by=l1y1+py;
//
//	return true;
//
//}
//
//
////点が三角形の範囲か調べる関数(pointは、三角形の点上を含むか)
//bool pointtrianglejud(float px,float py,float x1,float y1,float x2,float y2,float x3,float y3,bool point,bool line)
//{
//
//	float x,y;//作業用変数
//	float dx,dy;//作業用変数
//
//	//三角の点上だったら
//	if((px==x1 && py==y1) || (px==x2 && py==y2) || (px==x3 && py==y3))
//		return point;
//	
//
//	//左回りか？
//	if(reangle(angle(x3-x1,y3-y1)-angle(x2-x1,y2-y1))>180)	
//	{
//		//方向を逆にする
//		dx=x2;dy=y2;
//		x2=x3,y2=y3;
//		x3=dx,y3=dy;
//	}
//
//
//	x=px;y=py;
//	x-=x1;y-=y1;
//	rotation(&x,&y,-angle(x2-x1,y2-y1));
//
//	//lineがtrueだったら線の上は含む
//	if((x<=0 && line==false) || (x<0 && line==true))
//		return false;
//
//	x=px;y=py;
//	x-=x2;y-=y2;
//	rotation(&x,&y,-angle(x3-x2,y3-y2));
//
//	//lineがtrueだったら線の上は含む
//	if((x<=0 && line==false) || (x<0 && line==true))
//		return false;
//
//	x=px;y=py;
//	x-=x3;y-=y3;
//	rotation(&x,&y,-angle(x1-x3,y1-y3));
//
//	//lineがtrueだったら線の上は含む
//	if((x<=0 && line==false) || (x<0 && line==true))
//		return false;
//
//	return true;
//}
//
//
//
////三角形と三角形が触れているか調べる関数
//bool trianglejud(float tri1x1,float tri1y1,float tri1x2,float tri1y2,float tri1x3,float tri1y3,
//				  float tri2x1,float tri2y1,float tri2x2,float tri2y2,float tri2x3,float tri2y3)
//{
//	//点が三角形の中に入っているか調べる
//
//	//1－1と2を調べる
//	if(pointtrianglejud(tri1x1,tri1y1,tri2x1,tri2y1,tri2x2,tri2y2,tri2x3,tri2y3)==true)
//		return true;
//	//1－2と2を調べる
//	if(pointtrianglejud(tri1x2,tri1y2,tri2x1,tri2y1,tri2x2,tri2y2,tri2x3,tri2y3)==true)
//		return true;
//	//1－3と2を調べる
//	if(pointtrianglejud(tri1x3,tri1y3,tri2x1,tri2y1,tri2x2,tri2y2,tri2x3,tri2y3)==true)
//		return true;
//	//2－1と1を調べる
//	if(pointtrianglejud(tri2x1,tri2y1,tri1x1,tri1y1,tri1x2,tri1y2,tri1x3,tri1y3)==true)
//		return true;
//	//2－2と1を調べる
//	if(pointtrianglejud(tri2x2,tri2y2,tri1x1,tri1y1,tri1x2,tri1y2,tri1x3,tri1y3)==true)
//		return true;
//	//2－3と1を調べる
//	if(pointtrianglejud(tri2x3,tri2y3,tri1x1,tri1y1,tri1x2,tri1y2,tri1x3,tri1y3)==true)
//		return true;
//
//	//お互いのすべての辺どうしを調べる
//	float x,y;
//
//	//1－1～1－2と2－1～2－2を調べる
//	if(linejud(&x,&y,tri1x1,tri1y1,tri1x2,tri1y2,tri2x1,tri2y1,tri2x2,tri2y2)==true)//触れていた
//		return true;
//	//1－1～1－2と2－2～2－3を調べる
//	if(linejud(&x,&y,tri1x1,tri1y1,tri1x2,tri1y2,tri2x2,tri2y2,tri2x3,tri2y3)==true)//触れていた
//		return true;
//	//1－1～1－2と2－3～2－1を調べる
//	if(linejud(&x,&y,tri1x1,tri1y1,tri1x2,tri1y2,tri2x3,tri2y3,tri2x1,tri2y1)==true)//触れていた
//		return true;
//	//1－2～1－3と2－1～2－2を調べる
//	if(linejud(&x,&y,tri1x2,tri1y2,tri1x3,tri1y3,tri2x1,tri2y1,tri2x2,tri2y2)==true)//触れていた
//		return true;
//	//1－2～1－3と2－2～2－3を調べる
//	if(linejud(&x,&y,tri1x2,tri1y2,tri1x3,tri1y3,tri2x2,tri2y2,tri2x3,tri2y3)==true)//触れていた
//		return true;
//	//1－2～1－3と2－3～2－1を調べる
//	if(linejud(&x,&y,tri1x2,tri1y2,tri1x3,tri1y3,tri2x3,tri2y3,tri2x1,tri2y1)==true)//触れていた
//		return true;
//	//1－3～1－1と2－1～2－2を調べる
//	if(linejud(&x,&y,tri1x3,tri1y3,tri1x1,tri1y1,tri2x1,tri2y1,tri2x2,tri2y2)==true)//触れていた
//		return true;
//	//1－3～1－1と2－2～2－3を調べる
//	if(linejud(&x,&y,tri1x3,tri1y3,tri1x1,tri1y1,tri2x2,tri2y2,tri2x3,tri2y3)==true)//触れていた
//		return true;
//	//1－3～1－1と2－3～2－1を調べる
//	if(linejud(&x,&y,tri1x3,tri1y3,tri1x1,tri1y1,tri2x3,tri2y3,tri2x1,tri2y1)==true)//触れていた
//		return true;
//
//	return false;
//}
//
//
////三角形の面積を求める関数
//float trianglearea(float x1,float y1,float x2,float y2,float x3,float y3)
//{
//	//x1からのローカル座標に変換
//	float lx2=x2-x1;
//	float ly2=y2-y1;
//	float lx3=x3-x1;
//	float ly3=y3-y1;
//
//	//左回りか？
//	if(reangle(angle(lx3,ly3)-angle(lx2,ly2))>180)	
//	{
//		//方向を逆にする
//		float dx,dy;
//		dx=lx2;dy=ly2;
//		lx2=lx3,ly2=ly3;
//		lx3=dx,ly3=dy;
//	}
//
//	return 0.5f*distance(lx2,ly2)*distance(lx3,ly3)*sinf((angle(lx3,ly3)-angle(lx2,ly2))*rad);
//}
//
////三角形の重心を求める関数
//void trianglegravity(float *bx,float *by,float x1,float y1,float x2,float y2,float x3,float y3)
//{
//	*bx=(x1+x2+x3)/3;
//	*by=(y1+y2+y3)/3;
//}
//
////複数の点の重心を求める関数(countには、配列の要素数を渡す)
//void pointgravity(float *bx,float *by,float *bw,float x[],float y[],float w[],int count)
//{
//	int i;
//	float gravx=0,gravy=0,sumw=0;
//
//	for(i=0;i<count;i++)
//	{
//		gravx+=x[i]*w[i];
//		gravy+=y[i]*w[i];
//		sumw+=w[i];
//	}
//
//	*bx=gravx/sumw;
//	*by=gravy/sumw;
//	*bw=sumw;
//}
//
////多角形が右回りか調べる関数
//bool rotationright(float x[],float y[],int count)
//{
//	//辺を順番に、何度（角度）曲がったかを加算していき、プラスなら右回りとなる
//
//	int i;
//
//	//oldangは前の辺の角度,nowangは今現在の辺の角度,workangは作業用,angsumは合計の曲がった量
//	float oldang,nowang,workang,angsum=0;
//
//	//三角以下は多角形といえない
//	if(count>=3)
//	{
//
//		for(i=0;i<count;i++)
//		{
//			if(i==0)
//				oldang=angle(x[i]-x[count-1],y[i]-y[count-1]);//前の辺の角度
//
//			nowang=angle(x[i+1]-x[i],y[i+1]-y[i]);
//
//			workang=reangle(nowang-oldang);
//
//			if(workang>180)
//				workang-=360;
//
//			oldang=nowang;
//
//			angsum+=workang;
//		}
//
//		if(angsum>0)//右回り
//			return true;
//
//	}
//
//	return false;
//}
//
////多角形の回る方向をいれかえる関数
//void rotationchange(float x[],float y[],int count)
//{
//	int i;
//	float *dx=NULL,*dy=NULL;
//
//	//三角以下は多角形といえない
//	if(count>=3)
//	{
//
//		for(i=0;i<count;i++)
//		{
//			dx[i]=x[i];
//			dy[i]=y[i];
//		}
//
//		for(i=0;i<count;i++)
//		{
//			x[i]=dx[count-i-1];
//			y[i]=dy[count-i-1];
//		}
//
//	}
//
//}
//
//
//
////三角形の外接円の原点と半径を求める関数
//void gaisetu(float *x,float *y,float *r,float x1,float y1,float x2,float y2,float x3,float y3)
//{
//	float l1x1,l1y1,l1x2,l1y2,l2x1,l2y1,l2x2,l2y2;
//	float ang;
//	float dx,dy;//作業用変数
//	
//	//左回りか？
//	if(reangle(angle(x3-x1,y3-y1)-angle(x2-x1,y2-y1))>180)	
//	{
//		//方向を逆にする
//		dx=x2;dy=y2;
//		x2=x3,y2=y3;
//		x3=dx,y3=dy;
//	}
//
//	//一つ目の点を求める
//	l1x1=x1+(x2-x1)/2;
//	l1y1=y1+(y2-y1)/2;
//	l2x1=x2+(x3-x2)/2;
//	l2y1=y2+(y3-y2)/2;
//
//	//線の角度より、ふたつ目の点を求める
//	ang=angle(x2-x1,y2-y1)+90;//変に垂直な角度
//	l1x2=l1x1+sinf(rad*ang);
//	l1y2=l1y1+cosf(rad*ang);
//	ang=angle(x3-x2,y3-y2)+90;//変に垂直な角度
//	l2x2=l2x1+sinf(rad*ang);
//	l2y2=l2y1+cosf(rad*ang);
//
//	//線のデータがそろったところで検査
//	if(linejud(&dx,&dy,l1x1,l1y1,l1x2,l1y2,l2x1,l2y1,l2x2,l2y2,false,true)==false)
//	{
//		*x=0;
//		*y=0;
//		*r=0;
//	}
//	else
//	{
//		*x=dx;
//		*y=dy;
//		*r=distance(x1-dx,y1-dy);
//	}
//
//}
//
////三角形の内接円の原点と半径を求める関数
//void naisetu(float *x,float *y,float *r,float x1,float y1,float x2,float y2,float x3,float y3)
//{
//	float l1x1,l1y1,l1x2,l1y2,l2x1,l2y1,l2x2,l2y2;
//	float ang,ang2;
//	float dx,dy;//作業用変数
//	
//	//左回りか？
//	if(reangle(angle(x3-x1,y3-y1)-angle(x2-x1,y2-y1))>180)	
//	{
//		//方向を逆にする
//		dx=x2;dy=y2;
//		x2=x3,y2=y3;
//		x3=dx,y3=dy;
//	}
//
//	//一つ目の点を求める
//	l1x1=x1;
//	l1y1=y1;
//	l2x1=x2;
//	l2y1=y2;
//
//	//線の角度より、ふたつ目の点を求める
//	ang=angle(x2-x1,y2-y1);
//	ang2=angle(x3-x1,y3-y1);
//	ang2=(ang2-ang)/2;
//	ang+=ang2;
//	l1x2=l1x1+sinf(rad*ang);
//	l1y2=l1y1+cosf(rad*ang);
//	ang=angle(x3-x2,y3-y2);
//	ang+=(angle(x1-x2,y1-y2)-ang)/2;
//	l2x2=l2x1+sinf(rad*ang);
//	l2y2=l2y1+cosf(rad*ang);
//
//	//線のデータがそろったところで検査
//	if(linejud(&dx,&dy,l1x1,l1y1,l1x2,l1y2,l2x1,l2y1,l2x2,l2y2,false,true)==false)
//	{
//		*x=0;
//		*y=0;
//	}
//	else
//	{
//		*x=dx;
//		*y=dy;
//		*r=sinf(rad*ang2)*distance(x1-dx,y1-dy);
//	}
//
//}

////法線ベクトルを求める関数
//void housen(float *nxs,float *nys,float *nzs,
//			float x1s,float y1s,float z1s,float x2s,float y2s,float z2s,float x3s,float y3s,float z3s)
//{
//	float xs,ys,zs,rs;
//
//	x1s-=x3s;
//	y1s-=y3s;
//	z1s-=z3s;
//	x2s-=x3s;
//	y2s-=y3s;
//	z2s-=z3s;
//
//	xs=y1s*z2s-z1s*y2s;
//	ys=z1s*x2s-x1s*z2s;
//	zs=x1s*y2s-y1s*x2s;
//
//	rs=sqrt(xs*xs+ys*ys+zs*zs);
//
//	xs/=rs;
//	ys/=rs;
//	zs/=rs;
//
//	*nxs=xs;
//	*nys=ys;
//	*nzs=zs;
//}

//
////三つの点a,b,cの∠bの中にpがはいるかを調べる関数(a,b,cとたどる、右側の角について)
//bool inangle(float px,float py,float ax,float ay,float bx,float by,float cx,float cy,bool hukumu)
//{
//	float ang,ang2;
//
//	//(bから見たpの角度 - bから見たcの角度) > (bから見たaの角度 - bから見たcの角度)　なら、点は∠bの中に含まれない
//	//※hukumuがtrueなら、>=で調べ、0度も調べる
//
//	ang=angle(cx-bx,cy-by);
//	ang2=angle(px-bx,py-by);
//
//	if(hukumu==true)
//	{
//		if(reangle(ang2-ang) > reangle(angle(ax-bx,ay-by)-ang))
//			return false;
//	}
//	else
//	{
//		if(reangle(ang2-ang) >= reangle(angle(ax-bx,ay-by)-ang) || reangle(ang2-ang)==0)
//			return false;
//	}
//
//	return true;
//}
//
//
//
//
////点が、多角形の中にあるかを調べる関数(px,pyは、点の位置、x[],y[],countは、多角形の点とその数をあらわす)
//bool polygonpointjud(float px,float py,float x[],float y[],int count)
//{
//	int i,j,mae,ato;
//
//	float dx,dy;//戻り値用ダミー変数
//
//	bool ok;//判断用変数
//
//	for(i=0;i<count;i++)
//	{
//		mae=i-1;
//		if(mae<0)
//			mae=count-1;
//		ato=i+1;
//		if(ato>=count)
//			ato=0;
//		
//		if(inangle(px,py,x[mae],y[mae],x[i],y[i],x[ato],y[ato],false)==true)
//		{
//			ok=true;
//
//			for(j=0;j<count;j++)
//			{
//				ato=j+1;
//				if(ato>=count)
//					ato=0;
//
//				if(linejud(&dx,&dy,x[j],y[j],x[ato],y[ato],
//							x[i],y[i],px,py)==true)
//				{
//					ok=false;
//					j=count;
//				}
//			}
//
//			if(ok==true)
//				return true;
//		}
//	}
//
//	return false;
//}
//
//
//
////多角形と多角形が触れているかを調べる関数(x1,y1,count1は一つ目の多角形、x2,y2,count2は二つ目の多角形をあらわす)
//bool polygonjud(float x1[],float y1[],int count1,float x2[],float y2[],int count2)
//{
//	int i,j,next1,next2;
//	float dx,dy;//戻り値格納用ダミー変数
//
//	//ポリゴン1のそれぞれの点が、ポリゴン2の中にあるか調べる
//	for(i=0;i<count1;i++)
//	{
//		if(polygonpointjud(x1[i],y1[i],x2,y2,count2)==true)
//			return true;
//	}
//	
//	//ポリゴン2のそれぞれの点が、ポリゴン1の中にあるか調べる
//	for(i=0;i<count2;i++)
//	{
//		if(polygonpointjud(x2[i],y2[i],x1,y1,count1)==true)
//			return true;
//	}
//
//	//ポリゴン1の線とポリゴン2の線が触れていないかを調べる
//	for(i=0;i<count1;i++)
//	{
//		next1=i+1;
//		if(next1>=count1)
//			next1=0;
//
//		for(j=0;j<count2;j++)
//		{
//			next2=j+1;
//			if(next2>=count2)
//				next2=0;
//
//			if(linejud(&dx,&dy,x1[i],y1[i],x1[next1],y1[next1],x2[j],y2[j],x2[next2],y2[next2])==true)
//				return true;
//		}
//	}
//
//	return false;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
////最大公約数を求める関数
//int kouyaku(int num1,int num2)
//{
//	if(num1<=0 || num2<=0)
//		return 0;
//
//	while(true)
//	{
//		if(num1==num2)
//			return num1;
//		else if(num1>num2)
//			num1-=num2;
//		else
//			num2-=num1;
//	}
//	
//	return 0;
//}
//
////最小公倍数を求める関数
//int koubai(int num1,int num2)
//{
//	int kakeru1=1,kakeru2=1;
//
//	if(num1<=0 || num2<=0)
//		return 0;
//
//	while(true)
//	{
//		if(num1*kakeru1==num2*kakeru2)
//			return num1*kakeru1;
//		
//		else if(num1*kakeru1<num2*kakeru2)
//			kakeru1++;
//		else
//			kakeru2++;
//	}
//
//	return 0;
//}
//
////aとbを比較し、aBigがtrueならaの方を、falseならbの方が大きくなるように入れ替える関数
//void change(bool aBig,float *a,float *b)
//{
//	float work;
//	if((aBig==true && *a<*b) || (aBig==false && *a>*b))
//	{
//		work=*a;
//		*a=*b;
//		*b=work;
//	}
//}
//
