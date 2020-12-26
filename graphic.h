#ifndef GRAPHIC_HED
#define GRAPHIC_HED

#include <d3dx8.h>




class GraphicClass
{

private:

	LPDIRECT3D8			D3D;

public:

	LPDIRECT3DDEVICE8		Device;
	D3DPRESENT_PARAMETERS	Adapter;

	GraphicClass();

	bool CreateD3D();
	bool Create(HWND hWnd);
	void Release();
//	bool ChangeAdapter(HWND hWnd);

	//デバイスがあるかもとめる
	bool GetDevice();

	bool GetDisplayMode(D3DDISPLAYMODE *mode);
	

	//基本的なミップマップテクスチャを作る
	bool CreateTexture(LPDIRECT3DTEXTURE8 *Texture,char *FileName);

};



//
//
//
//
//
//class MeshClass
//{
//
//private:
//
//	LPD3DXMESH             Mesh;
//	D3DMATERIAL8*           Material;
//	LPDIRECT3DTEXTURE8*     Texture;
//	DWORD					MaterialCount;
//	
//public:
//
//	MeshClass();
//
//	bool Create( LPDIRECT3DDEVICE8 device, char *filename);
//	void Release();
//	bool SetFVF( LPDIRECT3DDEVICE8 device, DWORD dwFVF );
//	void Render( LPDIRECT3DDEVICE8 device );
//	void SetMaterial( D3DMATERIAL8 *Mat, DWORD num );
//	void SetTexture( LPDIRECT3DTEXTURE8 Tex, DWORD num );
//	void GetMaterial( D3DMATERIAL8 *Mat, DWORD num );
//	void GetTexture( LPDIRECT3DTEXTURE8 Tex, DWORD num );
//
//};
//
//



#endif