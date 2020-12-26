#include "graphic.h"


GraphicClass::GraphicClass()
{
	D3D=NULL;
	Device=NULL;

	//Adapter�����l�ݒ�
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


//��{�I�ȃe�N�X�`��(�~�b�v�}�b�v����)�����
bool GraphicClass::CreateTexture(LPDIRECT3DTEXTURE8 *Texture,char *FileName)
{

	if( FAILED( D3DXCreateTextureFromFileEx(
				Device,				// �f�o�C�X
				FileName,	// �e�N�X�`���t�@�C����
				D3DX_DEFAULT,			// ��
				D3DX_DEFAULT,			// ����
				D3DX_DEFAULT,			// �~�b�v���x���̐�
				0,						// �g�p���@
				D3DFMT_UNKNOWN,			// �t�H�[�}�b�g
				D3DPOOL_DEFAULT,		// �z�u��
				D3DX_DEFAULT,			// �t�B���^�����O���@
				D3DX_DEFAULT,			// �~�b�v�t�B���^�����O���@
				0x00000000,				// �J���[�L�[
				NULL,					// �\�[�X�C���[�W�t�@�C�����̋L�q
				NULL,					// �p���b�g
				Texture ) ) )		// �e�N�X�`��
	{
		//�݂���ˁ[
		*Texture=NULL;
		return false;
	}

	return true;

}



