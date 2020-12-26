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
#define BOX_I_MAX 10000//(4000��byte=4��KB=40MByte)


#define POL_LIST_MAX 5000
#define SPH_LIST_MAX 5000

class JudClass
{





private:

//public:







	struct TriangleStruct
	{
		short int kind;
		float h;//���W�ύX��̎O�p�`�̍������i�[
		D3DXVECTOR2 s,sp[3];//���W�ϊ���̒��_���W���i�[
		D3DXMATRIX mat;//���W�ϊ��p
		unsigned int cpol[3],csph[3];//�`���C���h�C���f�b�N�X
		bool check;
	}*tri;
	struct PoleStruct
	{
		short int kind;
		D3DXMATRIX mat;//���W�ϊ��p
		unsigned int csph[2];//�`���C���h�C���f�b�N�X
		float h;//���W�ϊ���̉~���̍���(���_�Ԃ̋���)
		bool check;
	}*pol;
	struct SphereStruct
	{
		short int kind;
		D3DXVECTOR3 p;//�ʒu���W
		bool check;
	}*sph;





	struct BoxStruct
	{
		unsigned short int count[BOX_X_MAX+1][BOX_Y_MAX+1][BOX_Z_MAX+1];//���z��̗v�f����1�����Ă�̂̓o�O�h�~�I�I(�������o�O)
		unsigned int index[BOX_X_MAX][BOX_Y_MAX][BOX_Z_MAX][BOX_I_MAX];
		D3DXVECTOR3 max,min,s;//s�́Ap�𒆐S�Ƃ��钸�_�܂ł̃x�N�g��������킷(box�̑傫����\��)
		short int cutx,cuty,cutz;
	}box;



	bool loaded;


//	TriangleStruct *tri;
//	PoleStruct *pol;
//	SphereStruct *sph;
	int tricount,polcount,sphcount;

	//�O�p�`�𒲂ׂ��Ƃ��Acpol��csph�̃C���f�b�N�X�����X�g�ɋL�^���A��ł��̃��X�g����A���ׂ�C���f�b�N�X�𔻒f����
	int pollistcount,pollist[POL_LIST_MAX];
	int sphlistcount,sphlist[SPH_LIST_MAX];

	//y����ɂ��鍂��h*2�̐���(Y�����W�Ō����� -h�`h )�ƁA�O�p�`p1-p2-p3���G��邩�𒲂ׂ�֐�
	bool trilinejud(D3DXVECTOR3* p1,D3DXVECTOR3* p2,D3DXVECTOR3* p3,float h);
	//x-z����ɂ���A��w*2,���s��h*2�̖ʂƁA����p1-p2���G��邩�𒲂ׂ�֐�
	bool rectlinejud(D3DXVECTOR3* p1,D3DXVECTOR3* p2,float w,float h);

public:



	//kind�́A���񂾈Ⴄ��ނ̎O�p�`�̉~���̏ꍇ�A�������������D�悳���
	struct JudStruct 
	{
		unsigned short int count;
		D3DXVECTOR3 v[JUDSTRUCT_MAX],n[JUDSTRUCT_MAX];
		float p[JUDSTRUCT_MAX];//���������������i�[
		short int kind[JUDSTRUCT_MAX];
		float dis[JUDSTRUCT_MAX];//���ёւ��p
	}judres;//����̌��ʂ��i�[����\����;


	JudClass();
	//��CreateJudFile�́A�v�Z������Ƃ��� tri,pol,sph���g���̂ŁAtri,pol,sph�̒l�͕ς���Ă��܂��B(�������̐ߖ�)
	int CreateJudFile(LPDIRECT3DDEVICE8 device,char JudFileName[],char XFileName[],int cutx,int cuty,int cutz);
	int LoadJudFile(char JudFileName[]);//,int kind);
	int FieldJud(bool line,float r,D3DXVECTOR3* p,D3DXVECTOR3* p2);
	//��̋��̔���Asp�͔����̋��Ap,p2�́A������Ƃ̋��̋O���Asr�͔����̋��̔��a�Ar�͔�����Ƃ̋��̔��a
	void SphereJud(bool line,int kind,float sr,float r,D3DXVECTOR3* sp,D3DXVECTOR3* p,D3DXVECTOR3* p2);
	void sort();
	void reset();

};


#endif
