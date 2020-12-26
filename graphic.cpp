#include "graphic.h"


GraphicClass::GraphicClass()
{
	D3D=NULL;
	Device=NULL;

	//Adapter初期値設定
	ZeroMemory( &Adapter, sizeof(Adapter) );
	Adapter.Windowed = false;
	Adapter.BackBufferWidth = 640;
	Adapter.BackBufferHeight =480;
    Adapter.SwapEffect = D3DSWAPEFFECT_DISCARD;
    Adapter.BackBufferFormat = D3DFMT_R5G6B5;
    Adapter.EnableAutoDepthStencil = true;
    Adapter.AutoDepthStencilFormat = D3DFMT_D16;
//	Adapter.FullScreen_PresentationInterval=D3DPRESENT_INTERVAL_IMMEDIATE;
}

bool GraphicClass::GetDisplayMode(D3DDISPLAYMODE *mode)
{
	if( FAILED( D3D->GetAdapterDisplayMode( D3DADAPTER_DEFAULT, mode ) ) )
		return false;
	return true;
}

bool GraphicClass::CreateD3D()
{
	if( D3D!=NULL )return true;

    if( NULL == ( D3D = Direct3DCreate8( D3D_SDK_VERSION ) ) )
        return false;
	return true;
}

bool GraphicClass::Create(HWND hWnd)
{

    if( !CreateD3D() )
        return false;

	if( Device!=NULL )return true;

    if( FAILED( D3D->CreateDevice(	D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
									D3DCREATE_SOFTWARE_VERTEXPROCESSING,
									&Adapter, &Device ) ) )
    {
        return false;
    }

	return true;


}




void GraphicClass::Release()
{
	if(Device != NULL)
	{
		Device->Release();
		Device=NULL;
	}

	if(D3D != NULL)
	{
		D3D->Release();
		D3D=NULL;
	}
}


bool GraphicClass::GetDevice()
{
	if( D3DERR_DEVICELOST == Device->TestCooperativeLevel() )
		return false;
	return true;
}


//基本的なテクスチャ(ミップマップあり)を作る
bool GraphicClass::CreateTexture(LPDIRECT3DTEXTURE8 *Texture,char *FileName)
{

	if( FAILED( D3DXCreateTextureFromFileEx(
				Device,				// デバイス
				FileName,	// テクスチャファイル名
				D3DX_DEFAULT,			// 幅
				D3DX_DEFAULT,			// 高さ
				D3DX_DEFAULT,			// ミップレベルの数
				0,						// 使用方法
				D3DFMT_UNKNOWN,			// フォーマット
				D3DPOOL_DEFAULT,		// 配置先
				D3DX_DEFAULT,			// フィルタリング方法
				D3DX_DEFAULT,			// ミップフィルタリング方法
				0x00000000,				// カラーキー
				NULL,					// ソースイメージファイル内の記述
				NULL,					// パレット
				Texture ) ) )		// テクスチャ
	{
		//みつからねー
		*Texture=NULL;
		return false;
	}

	return true;

}



