#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include "mathematic.h"

//0�ȏ�rndmax���� �̃����_���Ȑ��l�������ŕԂ��֐�
float rnd(float rndmax)
{
	float random=(float)rand();
	random/=RAND_MAX;
	if(random>=1)random=0;
	random*=rndmax;
	return random;
}

//�����_���W�F�l���[�^�̃����_����
void srnd()
{
	srand((unsigned int)(GetTickCount()*time(NULL)));
}

//2�̍��W�̊p�x���A�����v����plusangle��]����֐�
void rotation(float *x,float *y,float plusangle)
{
	float dx=*x,dy=*y,sin=sinf(plusangle*rad),cos=cosf(plusangle*rad);
	*x=dx*cos-dy*sin;
	*y=dx*sin+dy*cos;
}

//2�̍��W�̋������A���_�����Ƃ߂�֐�
float distance(float x,float y)
{
	return sqrtf(x*x+y*y);
}

//3�̍��W�̋������A���_�����Ƃ߂�֐�
float distance3(float x,float y,float z)
{
	return sqrtf(x*x+y*y+z*z);
}

//2�̍��W���Adis*2���P�ӂƂ��鐳���`�̒��ɂ��邩�����Ƃ߂�֐�(�����true��Ԃ�)
bool cubedistance(float x,float y,float dis)
{
	if(x<=dis && x>=-dis && y<=dis && y>=-dis) 
		return true; 
	else 
		return false;
}

//3�̍��W���Adis*2���P�ӂƂ��闧���̂̒��ɂ��邩�����Ƃ߂�֐�(�����true��Ԃ�)
bool cubedistance3(float x,float y,float z,float dis)
{
	if(x<=dis && x>=-dis && y<=dis && y>=-dis && z<=dis && z>=-dis) 
		return true; 
	else 
		return false;
}

//2�̍��W�̊p�x���A���_�����Ƃ߂�֐�(X���̐�������0���Ƃ��A�����v���)
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

//�p�x��0�ȏ�360�����͈̔͂ɏC������֐�
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

//2�����x�N�g���̒�����ύX����֐�
void changedistance(float *x,float *y,float dis)
{
	float d;

	d=distance(*x,*y);
	*x/=d;
	*y/=d;
	*x*=dis;
	*y*=dis;
}

//3�����x�N�g���̒�����ύX����֐�
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









//�����v�Z(����1�����A����2���E�ɂ���Ƃ��Čv�Z���Ă���)
float sayou(float m1,float v1,float m2,float v2,float keisuu)
{
	if(v1-v2<=0)
		return 0;

	//�Ԃ��������v1�̈ړ���
	float newv=(m1*v1+m2*v2+keisuu*m2*(v2-v1))/(m1+m2);

	//newv���A��������͂����߂�
	float power=(v1-newv)*m1;

	return power;
}






//�x�N�g��A�̕����������x�N�g��B�ɂǂꂾ�����邩���X�J���[�ŕԂ��֐�
float dotpro(float ax,float ay,float bx,float by)
{
	//a��P�ʃx�N�g���ɂ���
	float dis=sqrtf(ax*ax+ay*ay);
	ax/=dis;
	ay/=dis;

	return ax*bx+ay*by;
}

//�x�N�g��A�̕����������x�N�g��B�ɂǂꂾ�����邩���X�J���[�ŕԂ��֐�
float dotpro3(float ax,float ay,float az,float bx,float by,float bz)
{
	//a��P�ʃx�N�g���ɂ���
	float dis=sqrtf(ax*ax+ay*ay+az*az);
	ax/=dis;
	ay/=dis;
	az/=dis;

	return ax*bx+ay*by+az*bz;

}


//�x�N�g��A�ƃx�N�g��B�̖@����Ԃ��֐�(���_��A��B�̏��Ɏ��v��肪�\)
void crosspro3(float *x,float *y,float *z,float ax,float ay,float az,float bx,float by,float bz)
{
	*x=ay*bz-az*by;
	*y=az*bx-ax*bz;
	*z=ax*by-ay*bx;
	changedistance3(x,y,z,1);
}


//��̃x�N�g���̂Ȃ��p�x�𒲂ׂ�֐�
float angle3(float x1,float y1,float z1,float x2,float y2,float z2)
{
	//��̃x�N�g����P�ʃx�N�g���ɂ���
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





//����_�̋��������鎲��苁�߂�֐�
float distanceaxis(float x,float y,float z,float vx,float vy,float vz)
{
	//���ς��g���A�x�N�g����ň�ԋ߂��_��������
	float dis=dotpro3(vx,vy,vz,x,y,z);
	changedistance3(&vx,&vy,&vz,dis);
	return distance3(vx-x,vy-y,vz-z);	
}














//����_�ւ̃x�N�g�������鎲��́A�_�Ɉ�ԋ߂��Ƃ����苁�߂�֐�
void axisvector(float *x,float *y, float *z,float ax,float ay,float az,float vx,float vy,float vz)
{

	//���ς��g���A�x�N�g����ň�ԋ߂��_��������
	float dis=dotpro3(ax,ay,az,vx,vy,vz);
	changedistance3(&ax,&ay,&az,dis);


	*x=vx-ax;*y=vy-ay;*z=vz-az;

}









////�x�N�g����C�ӎ��ŉ�]������
//void rotationaxis(float *x,float *y,float *z,float vx,float vy,float vz,float ang)
//{
//	float wx=*x,wy=*y,wz=*z,wsin=sinf(ang*rad),wcos=cosf(ang*rad);
//
//	//�C�ӎ����̉�]�}�g���b�N�X�����߁A����Ƀx�N�g���������Ă���
//	*x=((wcos+(1-wcos)*vx*vx)*wx)		+ (((1-wcos)*vx*vy+vz*wsin)*wy)		+ (((1-wcos)*vz*vx-vy*wsin)*wz);
//	*y=(((1-wcos)*vx*vy-vz*wsin)*wx)	+ ((wcos+(1-wcos)*vy*vy)*wy)		+ (((1-wcos)*vy*vz+vx*wsin)*wz);
//	*z=(((1-wcos)*vz*vx+vy*wsin)*wx)	+ (((1-wcos)*vy*vz-vx*wsin)*wy)		+ ((wcos+(1-wcos)*vz*vz)*wz);
//}








////�x�N�g����C�ӎ��ŐL�k����
//void scalaxis(float *x,float *y,float *z,float vx,float vy,float vz,float scal)
//{
//}





//
//
//
//
//
//2�̕��̂̏d���ƈړ����x���A�Ԃ������Ƃ��ɐ�����͂̌v�Z������֐�
//float sayou(float m1,float v1,float m2,float v2)
//{
//	double kyoyou=0.0001f;
//
//	if(v1-v2<=0)
//		return 0;
//
//	double power,step,enagy;
//	double vd1,vd2;//�p���[������������̈ړ��ʊi�[�ϐ�
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
//		�G�l���M�[�v�Z
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
////�}�`�v�Z
//
//
//
//
////���Ɛ����G��Ă��邩���ׁA�G��Ă����炻�̈ʒu��Ԃ��֐�
////(point�́A���̒[���G��Ă����Ƃ��̔�������邩���u�[���l�Ŋi�[endless��true�ɂ���Ɩ����Ȑ��ɂȂ�)
//bool linejud(float *bx,float *by,
//			 float l1x1,float l1y1,float l1x2,float l1y2,float l2x1,float l2y1,float l2x2,float l2y2,
//																					bool point,bool endless)
//{
//	float ang,dis;
//	float y;//�G��Ă�ʒu��Y���W���i�[
//	float px,py;//�������Ă�ʒu���i�[
//
//	//endless��false�ŁA���݂��̓_���ǂꂩ�ł������ʒu�ɂ�������G��Ă��Ȃ����ƂƂ���
//	if((		(l1x1==l2x1 && l1y1==l2y1) || (l1x1==l2x2 && l1y1==l2y2) || 
//				(l1x2==l2x1 && l1y2==l2y1) || (l1x2==l2x2 && l1y2==l2y2))
//														&& endless==false)
//		return false;
//
//	//endless��true�ŁA���������ʒu�ɂ�������G��Ă��Ȃ����ƂƂ���
//	else if((	(l1x1==l2x1 && l1y1==l2y1 && l1x2==l2x2 && l1y2==l2y2) || 
//				(l1x2==l2x1 && l1y2==l2y1 && l1x1==l2x2 && l1y1==l2y2))
//														&& endless==true)
//
//		return false;
//	
//	//Line2��Line1�̃��[�J�����W�Ɉړ�
//	l2x1-=l1x1;l2y1-=l1y1;l2x2-=l1x1;l2y2-=l1y1;
//
//	//Line1�̒����Ɗp�x�����߂�
//	ang=angle(l1x2-l1x1,l1y2-l1y1);
//	dis=distance(l1x2-l1x1,l1y2-l1y1);
//
//	//Line2��Line1�̃��[�J�����W�ɉ�]
//	rotation(&l2x1,&l2y1,-ang);
//	rotation(&l2x2,&l2y2,-ang);
//
//	if(((l2x1>=0 && l2x2>=0) || (l2x1<=0 && l2x2<=0)) && endless==false)
//		return false;
//
//	if(endless==true && l2x1==l2x2 && endless==true)//���s����������
//		return false;
//
//	//�G��Ă�ʒu�𒲂ׂ�
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
////�_���O�p�`�͈̔͂����ׂ�֐�(point�́A�O�p�`�̓_����܂ނ�)
//bool pointtrianglejud(float px,float py,float x1,float y1,float x2,float y2,float x3,float y3,bool point,bool line)
//{
//
//	float x,y;//��Ɨp�ϐ�
//	float dx,dy;//��Ɨp�ϐ�
//
//	//�O�p�̓_�ゾ������
//	if((px==x1 && py==y1) || (px==x2 && py==y2) || (px==x3 && py==y3))
//		return point;
//	
//
//	//����肩�H
//	if(reangle(angle(x3-x1,y3-y1)-angle(x2-x1,y2-y1))>180)	
//	{
//		//�������t�ɂ���
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
//	//line��true����������̏�͊܂�
//	if((x<=0 && line==false) || (x<0 && line==true))
//		return false;
//
//	x=px;y=py;
//	x-=x2;y-=y2;
//	rotation(&x,&y,-angle(x3-x2,y3-y2));
//
//	//line��true����������̏�͊܂�
//	if((x<=0 && line==false) || (x<0 && line==true))
//		return false;
//
//	x=px;y=py;
//	x-=x3;y-=y3;
//	rotation(&x,&y,-angle(x1-x3,y1-y3));
//
//	//line��true����������̏�͊܂�
//	if((x<=0 && line==false) || (x<0 && line==true))
//		return false;
//
//	return true;
//}
//
//
//
////�O�p�`�ƎO�p�`���G��Ă��邩���ׂ�֐�
//bool trianglejud(float tri1x1,float tri1y1,float tri1x2,float tri1y2,float tri1x3,float tri1y3,
//				  float tri2x1,float tri2y1,float tri2x2,float tri2y2,float tri2x3,float tri2y3)
//{
//	//�_���O�p�`�̒��ɓ����Ă��邩���ׂ�
//
//	//1�|1��2�𒲂ׂ�
//	if(pointtrianglejud(tri1x1,tri1y1,tri2x1,tri2y1,tri2x2,tri2y2,tri2x3,tri2y3)==true)
//		return true;
//	//1�|2��2�𒲂ׂ�
//	if(pointtrianglejud(tri1x2,tri1y2,tri2x1,tri2y1,tri2x2,tri2y2,tri2x3,tri2y3)==true)
//		return true;
//	//1�|3��2�𒲂ׂ�
//	if(pointtrianglejud(tri1x3,tri1y3,tri2x1,tri2y1,tri2x2,tri2y2,tri2x3,tri2y3)==true)
//		return true;
//	//2�|1��1�𒲂ׂ�
//	if(pointtrianglejud(tri2x1,tri2y1,tri1x1,tri1y1,tri1x2,tri1y2,tri1x3,tri1y3)==true)
//		return true;
//	//2�|2��1�𒲂ׂ�
//	if(pointtrianglejud(tri2x2,tri2y2,tri1x1,tri1y1,tri1x2,tri1y2,tri1x3,tri1y3)==true)
//		return true;
//	//2�|3��1�𒲂ׂ�
//	if(pointtrianglejud(tri2x3,tri2y3,tri1x1,tri1y1,tri1x2,tri1y2,tri1x3,tri1y3)==true)
//		return true;
//
//	//���݂��̂��ׂĂ̕ӂǂ����𒲂ׂ�
//	float x,y;
//
//	//1�|1�`1�|2��2�|1�`2�|2�𒲂ׂ�
//	if(linejud(&x,&y,tri1x1,tri1y1,tri1x2,tri1y2,tri2x1,tri2y1,tri2x2,tri2y2)==true)//�G��Ă���
//		return true;
//	//1�|1�`1�|2��2�|2�`2�|3�𒲂ׂ�
//	if(linejud(&x,&y,tri1x1,tri1y1,tri1x2,tri1y2,tri2x2,tri2y2,tri2x3,tri2y3)==true)//�G��Ă���
//		return true;
//	//1�|1�`1�|2��2�|3�`2�|1�𒲂ׂ�
//	if(linejud(&x,&y,tri1x1,tri1y1,tri1x2,tri1y2,tri2x3,tri2y3,tri2x1,tri2y1)==true)//�G��Ă���
//		return true;
//	//1�|2�`1�|3��2�|1�`2�|2�𒲂ׂ�
//	if(linejud(&x,&y,tri1x2,tri1y2,tri1x3,tri1y3,tri2x1,tri2y1,tri2x2,tri2y2)==true)//�G��Ă���
//		return true;
//	//1�|2�`1�|3��2�|2�`2�|3�𒲂ׂ�
//	if(linejud(&x,&y,tri1x2,tri1y2,tri1x3,tri1y3,tri2x2,tri2y2,tri2x3,tri2y3)==true)//�G��Ă���
//		return true;
//	//1�|2�`1�|3��2�|3�`2�|1�𒲂ׂ�
//	if(linejud(&x,&y,tri1x2,tri1y2,tri1x3,tri1y3,tri2x3,tri2y3,tri2x1,tri2y1)==true)//�G��Ă���
//		return true;
//	//1�|3�`1�|1��2�|1�`2�|2�𒲂ׂ�
//	if(linejud(&x,&y,tri1x3,tri1y3,tri1x1,tri1y1,tri2x1,tri2y1,tri2x2,tri2y2)==true)//�G��Ă���
//		return true;
//	//1�|3�`1�|1��2�|2�`2�|3�𒲂ׂ�
//	if(linejud(&x,&y,tri1x3,tri1y3,tri1x1,tri1y1,tri2x2,tri2y2,tri2x3,tri2y3)==true)//�G��Ă���
//		return true;
//	//1�|3�`1�|1��2�|3�`2�|1�𒲂ׂ�
//	if(linejud(&x,&y,tri1x3,tri1y3,tri1x1,tri1y1,tri2x3,tri2y3,tri2x1,tri2y1)==true)//�G��Ă���
//		return true;
//
//	return false;
//}
//
//
////�O�p�`�̖ʐς����߂�֐�
//float trianglearea(float x1,float y1,float x2,float y2,float x3,float y3)
//{
//	//x1����̃��[�J�����W�ɕϊ�
//	float lx2=x2-x1;
//	float ly2=y2-y1;
//	float lx3=x3-x1;
//	float ly3=y3-y1;
//
//	//����肩�H
//	if(reangle(angle(lx3,ly3)-angle(lx2,ly2))>180)	
//	{
//		//�������t�ɂ���
//		float dx,dy;
//		dx=lx2;dy=ly2;
//		lx2=lx3,ly2=ly3;
//		lx3=dx,ly3=dy;
//	}
//
//	return 0.5f*distance(lx2,ly2)*distance(lx3,ly3)*sinf((angle(lx3,ly3)-angle(lx2,ly2))*rad);
//}
//
////�O�p�`�̏d�S�����߂�֐�
//void trianglegravity(float *bx,float *by,float x1,float y1,float x2,float y2,float x3,float y3)
//{
//	*bx=(x1+x2+x3)/3;
//	*by=(y1+y2+y3)/3;
//}
//
////�����̓_�̏d�S�����߂�֐�(count�ɂ́A�z��̗v�f����n��)
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
////���p�`���E��肩���ׂ�֐�
//bool rotationright(float x[],float y[],int count)
//{
//	//�ӂ����ԂɁA���x�i�p�x�j�Ȃ������������Z���Ă����A�v���X�Ȃ�E���ƂȂ�
//
//	int i;
//
//	//oldang�͑O�̕ӂ̊p�x,nowang�͍����݂̕ӂ̊p�x,workang�͍�Ɨp,angsum�͍��v�̋Ȃ�������
//	float oldang,nowang,workang,angsum=0;
//
//	//�O�p�ȉ��͑��p�`�Ƃ����Ȃ�
//	if(count>=3)
//	{
//
//		for(i=0;i<count;i++)
//		{
//			if(i==0)
//				oldang=angle(x[i]-x[count-1],y[i]-y[count-1]);//�O�̕ӂ̊p�x
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
//		if(angsum>0)//�E���
//			return true;
//
//	}
//
//	return false;
//}
//
////���p�`�̉����������ꂩ����֐�
//void rotationchange(float x[],float y[],int count)
//{
//	int i;
//	float *dx=NULL,*dy=NULL;
//
//	//�O�p�ȉ��͑��p�`�Ƃ����Ȃ�
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
////�O�p�`�̊O�ډ~�̌��_�Ɣ��a�����߂�֐�
//void gaisetu(float *x,float *y,float *r,float x1,float y1,float x2,float y2,float x3,float y3)
//{
//	float l1x1,l1y1,l1x2,l1y2,l2x1,l2y1,l2x2,l2y2;
//	float ang;
//	float dx,dy;//��Ɨp�ϐ�
//	
//	//����肩�H
//	if(reangle(angle(x3-x1,y3-y1)-angle(x2-x1,y2-y1))>180)	
//	{
//		//�������t�ɂ���
//		dx=x2;dy=y2;
//		x2=x3,y2=y3;
//		x3=dx,y3=dy;
//	}
//
//	//��ڂ̓_�����߂�
//	l1x1=x1+(x2-x1)/2;
//	l1y1=y1+(y2-y1)/2;
//	l2x1=x2+(x3-x2)/2;
//	l2y1=y2+(y3-y2)/2;
//
//	//���̊p�x���A�ӂ��ڂ̓_�����߂�
//	ang=angle(x2-x1,y2-y1)+90;//�ςɐ����Ȋp�x
//	l1x2=l1x1+sinf(rad*ang);
//	l1y2=l1y1+cosf(rad*ang);
//	ang=angle(x3-x2,y3-y2)+90;//�ςɐ����Ȋp�x
//	l2x2=l2x1+sinf(rad*ang);
//	l2y2=l2y1+cosf(rad*ang);
//
//	//���̃f�[�^����������Ƃ���Ō���
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
////�O�p�`�̓��ډ~�̌��_�Ɣ��a�����߂�֐�
//void naisetu(float *x,float *y,float *r,float x1,float y1,float x2,float y2,float x3,float y3)
//{
//	float l1x1,l1y1,l1x2,l1y2,l2x1,l2y1,l2x2,l2y2;
//	float ang,ang2;
//	float dx,dy;//��Ɨp�ϐ�
//	
//	//����肩�H
//	if(reangle(angle(x3-x1,y3-y1)-angle(x2-x1,y2-y1))>180)	
//	{
//		//�������t�ɂ���
//		dx=x2;dy=y2;
//		x2=x3,y2=y3;
//		x3=dx,y3=dy;
//	}
//
//	//��ڂ̓_�����߂�
//	l1x1=x1;
//	l1y1=y1;
//	l2x1=x2;
//	l2y1=y2;
//
//	//���̊p�x���A�ӂ��ڂ̓_�����߂�
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
//	//���̃f�[�^����������Ƃ���Ō���
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

////�@���x�N�g�������߂�֐�
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
////�O�̓_a,b,c�́�b�̒���p���͂��邩�𒲂ׂ�֐�(a,b,c�Ƃ��ǂ�A�E���̊p�ɂ���)
//bool inangle(float px,float py,float ax,float ay,float bx,float by,float cx,float cy,bool hukumu)
//{
//	float ang,ang2;
//
//	//(b���猩��p�̊p�x - b���猩��c�̊p�x) > (b���猩��a�̊p�x - b���猩��c�̊p�x)�@�Ȃ�A�_�́�b�̒��Ɋ܂܂�Ȃ�
//	//��hukumu��true�Ȃ�A>=�Œ��ׁA0�x�����ׂ�
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
////�_���A���p�`�̒��ɂ��邩�𒲂ׂ�֐�(px,py�́A�_�̈ʒu�Ax[],y[],count�́A���p�`�̓_�Ƃ��̐�������킷)
//bool polygonpointjud(float px,float py,float x[],float y[],int count)
//{
//	int i,j,mae,ato;
//
//	float dx,dy;//�߂�l�p�_�~�[�ϐ�
//
//	bool ok;//���f�p�ϐ�
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
////���p�`�Ƒ��p�`���G��Ă��邩�𒲂ׂ�֐�(x1,y1,count1�͈�ڂ̑��p�`�Ax2,y2,count2�͓�ڂ̑��p�`������킷)
//bool polygonjud(float x1[],float y1[],int count1,float x2[],float y2[],int count2)
//{
//	int i,j,next1,next2;
//	float dx,dy;//�߂�l�i�[�p�_�~�[�ϐ�
//
//	//�|���S��1�̂��ꂼ��̓_���A�|���S��2�̒��ɂ��邩���ׂ�
//	for(i=0;i<count1;i++)
//	{
//		if(polygonpointjud(x1[i],y1[i],x2,y2,count2)==true)
//			return true;
//	}
//	
//	//�|���S��2�̂��ꂼ��̓_���A�|���S��1�̒��ɂ��邩���ׂ�
//	for(i=0;i<count2;i++)
//	{
//		if(polygonpointjud(x2[i],y2[i],x1,y1,count1)==true)
//			return true;
//	}
//
//	//�|���S��1�̐��ƃ|���S��2�̐����G��Ă��Ȃ����𒲂ׂ�
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
////�ő���񐔂����߂�֐�
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
////�ŏ����{�������߂�֐�
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
////a��b���r���AaBig��true�Ȃ�a�̕����Afalse�Ȃ�b�̕����傫���Ȃ�悤�ɓ���ւ���֐�
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
