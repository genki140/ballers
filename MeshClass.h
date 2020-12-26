#ifndef MESHCLASS_HED
#define MESHCLASS_HED

#include <d3dx8.h>
#include <stdio.h>
#include "mathematic.h"



//������Ȃɂ�������̃��b�V����e�N�X�`����ǂݍ��ނ��Ƃ͂��肦�Ȃ��Ɖ��肷��B
//	�v���O������P���ɂ��邽�߂ɁA�����Č��E�����͂��Ȃ��B
//	�܂�A����ȏ�̃��b�V����e�N�X�`����ǂݍ��ނƃG���[�ƂȂ�B

//1�����z��͉\�Ȍ���|�C���^�Ƃ��č쐬���A�K�v�ȕ��������������m�ۂ���悤�ɂ���B
//2�����z��͕��G�ɂȂ�̂Ń|�C���^�Ƃ��Ăł͂Ȃ��͂��߂���z��Ƃ��Đ錾����B

#define MESH_MAX 100			//���b�V���̍ő吔
#define TEXTURE_MAX 100		//�e�N�X�`���̍ő吔
#define MULTI_MAX 10		//�}���`�e�N�X�`���̍ő吔
#define MATERIAL_MAX 100		//�}�e���A���̍ő吔

class MeshClass
{
public:
//private:

	bool Created;

	//�}�e���A����r�֐�
	bool MaterialCmp( D3DMATERIAL8* mat1,D3DMATERIAL8* mat2);
	//�t�@�C�����t���p�X���A�p�X�A�t�@�C�����A�g���q�ɕ����ĕԂ��֐�
	void PathDiv( char* file, char* path, char* name, char* kakutyousi);

	char MeshRootPath[MAX_PATH];//���b�V���̂���t�H���_��

	//�J�E���^�Ȃ�

	//���v
	short int MeshCount;//���ׂẴ��b�V���̐�
	short int MaterialCount;//���ׂĂ̍ގ��̐�
	short int TextureCount;//���ׂẴe�N�X�`���̐�

	//���b�V��(���ׂẴ��b�V���ɕK�v�ȃX�e�[�^�X)
	char MeshFileName[MESH_MAX][MAX_PATH];//���b�V���̃t�@�C����
	short int *MeshMaterialCount;//���b�V���̃}�e���A����
	short int MeshMaterialIndex[MESH_MAX][MATERIAL_MAX];//���b�V���̃}�e���A�����ƂɃ}�e���A���̔ԍ�(Material[])���i�[
	short int MeshTextureIndex[MESH_MAX][MATERIAL_MAX];//���b�V���̃}�e���A�����ƂɃe�N�X�`���̔ԍ�(TextureIndex[])���i�[


	//�e�N�X�`��(���ׂẴe�N�X�`���ɕK�v�ȃX�e�[�^�X)
	char TextureFileName[TEXTURE_MAX][MAX_PATH];
	//�}���`�e�N�X�`���pUV����ϐ�
	float *UVRotation;
	float *UVScalingX;
	float *UVScalingY;
	float *UVTranslationX;
	float *UVTranslationY;
	//���Z���@
	int *ColorOpereter;
	int *ColorArg1;
	int *ColorArg2;
	int *AlphaOpereter;
	int *AlphaArg1;
	int *AlphaArg2;

	//�e�N�X�`��(��ނ��ƂɕK�v�ȃX�e�[�^�X)
	short int TextureKindCount;//����ނ̃e�N�X�`����ǂݍ��񂾂����i�[
	//�}���`�e�N�X�`���p
	short int TextureIndex[TEXTURE_MAX];//���Ԗڂ�Direct3DTexture���g�p���Ă��邩?
	short int TextureMultiCount[TEXTURE_MAX];//�����̃}���`?
	

	//���E���X�e�[�^�X
	D3DXVECTOR3 *MeshP;
	float *MeshR;


	//���̑�D3D�̂Ł[����

	//���b�V��(PMesh�̓v���O���b�V�u���b�V��)
	LPD3DXMESH*             Mesh;//�v�f����MeshCount
	//�}�e���A��
	D3DMATERIAL8*           Material;//�v�f����MaterialCount
	//�e�N�X�`��
	LPDIRECT3DTEXTURE8*     Texture;//�v�f����TextureCount
	LPDIRECT3DTEXTURE8*     KeepTexture;//�v�f����TextureCount


	D3DXMATRIX EnvMatrix;

public:




	MeshClass();

	bool Create( LPDIRECT3DDEVICE8 device, char *filename, bool MultiTexture=true);

	void Release();

	void Reset();

	//�����_�����O�֐�(fovy�ɂ́A����̊p�x��x�Ŏw�肷��)
	void Render( LPDIRECT3DDEVICE8 device, D3DXVECTOR3* po=NULL, D3DXVECTOR3* look=NULL, float fovy=0, int start=0, int count=0, LPDIRECT3DTEXTURE8* EnvTexture=NULL ,bool Reflection=false);

	void SetMaterial( D3DMATERIAL8 *Mat, int Num );
	void SetTexture( LPDIRECT3DTEXTURE8 Tex, int Num );
	void GetMaterial( D3DMATERIAL8 *Mat, int Num );
	void GetTexture( LPDIRECT3DTEXTURE8 Tex, int Num );

	int TexNameIndex( char *filename );//�t�@�C�����̂݋L�q����i�p�X�Ȃ��A�g���q����j�����̃t�@�C���������݂��Ȃ��ꍇ-1��Ԃ�

};




#endif
