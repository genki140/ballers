#ifndef MESHCLASS_HED
#define MESHCLASS_HED

#include <d3dx8.h>
#include <stdio.h>
#include "mathematic.h"



//※こんなにたくさんのメッシュやテクスチャを読み込むことはありえないと仮定する。
//	プログラムを単純にするために、あえて限界処理はしない。
//	つまり、これ以上のメッシュやテクスチャを読み込むとエラーとなる。

//1次元配列は可能な限りポインタとして作成し、必要な分だけメモリを確保するようにする。
//2次元配列は複雑になるのでポインタとしてではなくはじめから配列として宣言する。

#define MESH_MAX 100			//メッシュの最大数
#define TEXTURE_MAX 100		//テクスチャの最大数
#define MULTI_MAX 10		//マルチテクスチャの最大数
#define MATERIAL_MAX 100		//マテリアルの最大数

class MeshClass
{
public:
//private:

	bool Created;

	//マテリアル比較関数
	bool MaterialCmp( D3DMATERIAL8* mat1,D3DMATERIAL8* mat2);
	//ファイル名フルパスより、パス、ファイル名、拡張子に分けて返す関数
	void PathDiv( char* file, char* path, char* name, char* kakutyousi);

	char MeshRootPath[MAX_PATH];//メッシュのあるフォルダ名

	//カウンタなど

	//合計
	short int MeshCount;//すべてのメッシュの数
	short int MaterialCount;//すべての材質の数
	short int TextureCount;//すべてのテクスチャの数

	//メッシュ(すべてのメッシュに必要なステータス)
	char MeshFileName[MESH_MAX][MAX_PATH];//メッシュのファイル名
	short int *MeshMaterialCount;//メッシュのマテリアル数
	short int MeshMaterialIndex[MESH_MAX][MATERIAL_MAX];//メッシュのマテリアルごとにマテリアルの番号(Material[])を格納
	short int MeshTextureIndex[MESH_MAX][MATERIAL_MAX];//メッシュのマテリアルごとにテクスチャの番号(TextureIndex[])を格納


	//テクスチャ(すべてのテクスチャに必要なステータス)
	char TextureFileName[TEXTURE_MAX][MAX_PATH];
	//マルチテクスチャ用UV操作変数
	float *UVRotation;
	float *UVScalingX;
	float *UVScalingY;
	float *UVTranslationX;
	float *UVTranslationY;
	//演算方法
	int *ColorOpereter;
	int *ColorArg1;
	int *ColorArg2;
	int *AlphaOpereter;
	int *AlphaArg1;
	int *AlphaArg2;

	//テクスチャ(種類ごとに必要なステータス)
	short int TextureKindCount;//何種類のテクスチャを読み込んだかを格納
	//マルチテクスチャ用
	short int TextureIndex[TEXTURE_MAX];//何番目のDirect3DTextureを使用しているか?
	short int TextureMultiCount[TEXTURE_MAX];//何枚のマルチ?
	

	//境界球ステータス
	D3DXVECTOR3 *MeshP;
	float *MeshR;


	//その他D3Dのでーた等

	//メッシュ(PMeshはプログレッシブメッシュ)
	LPD3DXMESH*             Mesh;//要素数はMeshCount
	//マテリアル
	D3DMATERIAL8*           Material;//要素数はMaterialCount
	//テクスチャ
	LPDIRECT3DTEXTURE8*     Texture;//要素数はTextureCount
	LPDIRECT3DTEXTURE8*     KeepTexture;//要素数はTextureCount


	D3DXMATRIX EnvMatrix;

public:




	MeshClass();

	bool Create( LPDIRECT3DDEVICE8 device, char *filename, bool MultiTexture=true);

	void Release();

	void Reset();

	//レンダリング関数(fovyには、視野の角度を度で指定する)
	void Render( LPDIRECT3DDEVICE8 device, D3DXVECTOR3* po=NULL, D3DXVECTOR3* look=NULL, float fovy=0, int start=0, int count=0, LPDIRECT3DTEXTURE8* EnvTexture=NULL ,bool Reflection=false);

	void SetMaterial( D3DMATERIAL8 *Mat, int Num );
	void SetTexture( LPDIRECT3DTEXTURE8 Tex, int Num );
	void GetMaterial( D3DMATERIAL8 *Mat, int Num );
	void GetTexture( LPDIRECT3DTEXTURE8 Tex, int Num );

	int TexNameIndex( char *filename );//ファイル名のみ記述する（パスなし、拡張子あり）※そのファイル名が存在しない場合-1を返す

};




#endif
