#define rad 0.0174533f//(3.141592/180)
#define deg 57.2957795f//(180/3.141592)
#define pi 3.1415926536f

//0�ȏ�rndmax���� �̃����_���Ȑ��l�������ŕԂ��֐�
float rnd(float rndmax);

//�����_���W�F�l���[�^�̏�����
void srnd();

//2�̍��W�̋������A���_�����Ƃ߂�֐�
float distance(float x,float y);

//3�̍��W�̋������A���_�����Ƃ߂�֐�
float distance3(float x,float y,float z);



//2�̍��W���Adis*2���P�ӂƂ��鐳���`�̒��ɂ��邩�����Ƃ߂�֐�(�����true��Ԃ�)
bool cubedistance(float x,float y,float dis);

//3�̍��W���Adis*2���P�ӂƂ��闧���̂̒��ɂ��邩�����Ƃ߂�֐�(�����true��Ԃ�)
bool cubedistance3(float x,float y,float z,float dis);

//2�̍��W�̊p�x���A���_�����Ƃ߂�֐�
float angle(float x,float y);

//��̃x�N�g���̂Ȃ��p�x�����߂�
float angle3(float x1,float y1,float z1,float x2,float y2,float z2);


//�p�x��0�ȏ�360�����͈̔͂ɏC������֐�
float reangle(float angle);

//2�����x�N�g���̒�����ύX����֐�
void changedistance(float *x,float *y,float dis);

//3�����x�N�g���̒�����ύX����֐�
void changedistance3(float *x,float *y,float *z,float dis);

//2�̍��W�̊p�x���Aplusangle�v���X����֐�
void rotation(float *x,float *y,float plusangle);
//
////�x�N�g����C�ӎ��ŉ�]������
//void rotationaxis(float *x,float *y,float *z,float vx,float vy,float vz,float ang);
////
////�x�N�g����C�ӎ��ŐL�k����
//void scalaxis(float *x,float *y,float *z,float vx,float vy,float vz,float scal);


//2�̕��̂̏d���ƈړ����x���A�Ԃ������Ƃ��ɐ�����͂̌v�Z������֐�
//float sayou(float m1,float v1,float m2,float v2,double kyoyou);
float sayou(float m1,float v1,float m2,float v2,float keisuu);

//�x�N�g��A�̕����������x�N�g��B�ɂǂꂾ�����邩���X�J���[�ŕԂ��֐�
float dotpro(float ax,float ay,float bx,float by);

//�x�N�g��A�̕����������x�N�g��B�ɂǂꂾ�����邩���X�J���[�ŕԂ��֐�
float dotpro3(float ax,float ay,float az,float bx,float by,float bz);

//�x�N�g��A�ƃx�N�g��B�̖@����Ԃ��֐�(���_��A��B�̏��Ɏ��v��肪�\)
void crosspro3(float *x,float *y,float *z,float ax,float ay,float az,float bx,float by,float bz);





//����_�̋��������鎲��苁�߂�֐�
float distanceaxis(float x,float y,float z,float vx,float vy,float vz);


//����_�ւ̃x�N�g�������鎲��́A�_�Ɉ�ԋ߂��Ƃ����苁�߂�֐�(���[�J��)
void axisvector(float *x,float *y, float *z,float ax,float ay,float az,float vx,float vy,float vz);


//
////����_�ւ̃x�N�g�������鎲��́A�_�Ɉ�ԋ߂��Ƃ����苁�߂�֐�(���[���h)
//float axisvectorW(float x*,float y* float z*,float vx,float vy,float vz,float vx,float vy,float vz);
//




//
////���Ɛ����G��Ă��邩���ׁA�G��Ă����炻�̈ʒu��Ԃ��֐�
////(point�́A���̒[���G��Ă����Ƃ��̔�������邩���u�[���l�Ŋi�[endless��true�ɂ���Ɩ����Ȑ��ɂȂ�)
//bool linejud(float *bx,float *by,
//			 float l1x1,float l1y1,float l1x2,float l1y2,float l2x1,float l2y1,float l2x2,float l2y2,
//			 bool point=false,bool endless=false);
//
////�_���O�p�`�͈̔͂����ׂ�֐�
//bool pointtrianglejud(float px,float py,float x1,float y1,float x2,float y2,float x3,float y3,bool point=false,bool line=false);
//
////�O�p�`�ƎO�p�`���G��Ă��邩���ׂ�֐�
//bool trianglejud(float tri1x1,float tri1y1,float tri1x2,float tri1y2,float tri1x3,float tri1y3,
//				  float tri2x1,float tri2y1,float tri2x2,float tri2y2,float tri2x3,float tri2y3);
//
////�O�p�`�̖ʐς����߂�֐�
//float trianglearea(float x1,float y1,float x2,float y2,float x3,float y3);
//
////�O�p�`�̏d�S�����߂�֐�
//void trianglegravity(float *bx,float *by,float x1,float y1,float x2,float y2,float x3,float y3);
//
////�����̓_�̏d�S�����߂�֐�(count�ɂ́A�z��̗v�f����n��)
//void pointgravity(float *bx,float *by,float *bw,float x[],float y[],float w[],int count);
//
////���p�`���E��肩���ׂ�֐�
//bool rotationright(float x[],float y[],int count);
//
////���p�`�̉����������ꂩ����֐�
//void rotationchange(float x[],float y[],int count);
//
////�ő���񐔂����߂�֐�
//int kouyaku(int num1,int num2);
//
////�ŏ����{�������߂�֐�
//int koubai(int num1,int num2);
//
////a��b���r���AaBig��true�Ȃ�a�̕����Afalse�Ȃ�b�̕����傫���Ȃ�悤�ɓ���ւ���֐�
//void change(bool aBig,float *a,float *b);
//
////�O�p�`�̊O�ډ~�̌��_�Ɣ��a�����߂�֐�
//void gaisetu(float *x,float *y,float *r,float x1,float y1,float x2,float y2,float x3,float y3);
//
////�O�p�`�̓��ډ~�̌��_�Ɣ��a�����߂�֐�
//void naisetu(float *x,float *y,float *r,float x1,float y1,float x2,float y2,float x3,float y3);
//
////�@���x�N�g�������߂�֐�
//void housen(float *nxs,float *nys,float *nzs,
//			float x1s,float y1s,float z1s,float x2s,float y2s,float z2s,float x3s,float y3s,float z3s);

////�O�̓_a,b,c�́�b�̒���p���͂��邩�𒲂ׂ�֐� hukumu�́Ap��a�Ɠ���������Ac�Ɠ����������܂ނ����w�肷��
////(a,b,c�Ƃ��ǂ�A�E���̊p�ɂ���)
//bool inangle(float px,float py,float ax,float ay,float bx,float by,float cx,float cy,bool hukumu=true);
//
////�_���A���p�`�̒��ɂ��邩�𒲂ׂ�֐�(px,py�́A�_�̈ʒu�Ax[],y[],count�́A���p�`�̓_�Ƃ��̐�������킷)
//bool polygonpointjud(float px,float py,float x[],float y[],int count);
//
////���p�`�Ƒ��p�`���G��Ă��邩�𒲂ׂ�֐�(x1,y1,count1�͈�ڂ̑��p�`�Ax2,y2,count2�͓�ڂ̑��p�`������킷)
//bool polygonjud(float x1[],float y1[],int count1,float x2[],float y2[],int count2);
