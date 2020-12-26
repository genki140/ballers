#include "feed.h"



void FeedClass::Reset()
{
	count=0;
}

void FeedClass::Move()
{
	if(count!=0)
	{
		count++;
		if(count>countend-1)
		{
			if(mode==FEEDMODE_BLACKIN || mode==FEEDMODE_WHITEIN)
			{
				count=0;
			}
			else
			{
				count=countend-1;
			}
		}
	}
}

void FeedClass::Start(int feedmode,int feedcount)
{
	if(feedcount>0)
	{
		mode=feedmode;
		countend=feedcount;
		count=1;
	}
}

void FeedClass::End()
{
	count=0;
}

void FeedClass::Render(LPDIRECT3DDEVICE8 device,int width,int height)//,float color)
{

	float alphar;//“§–¾“x‚ðŒvŽZ‚µ‚ÄŠi”[‚·‚é
	bool black;//•‚È‚çTrue‚ðŠi”[



	if(GetEnable()==false)
		goto jump;


	if(mode==FEEDMODE_BLACKIN)//•‚­‚È‚­‚È‚é
	{
		black=true;
		alphar=1-(float)count/countend;
	}
	else if(mode==FEEDMODE_BLACKOUT)//•‚­‚È‚é
	{
		black=true;
		alphar=(float)count/countend;
	}
	else if(mode==FEEDMODE_WHITEIN)//”’‚­‚È‚­‚È‚é
	{
		black=false;
		alphar=1-(float)count/countend;
	}
	else if(mode==FEEDMODE_WHITEOUT)//”’‚­‚È‚é
	{
		black=false;
		alphar=(float)count/countend;
	}




	//ƒŒƒ“ƒ_ƒŠƒ“ƒO




	DWORD alphaenable,srcblend,destblend,blendop,light,zenable,zwrite,stencil,cullmode;

	//Žæ“¾
	device->GetRenderState (D3DRS_ALPHABLENDENABLE, &alphaenable);
	device->GetRenderState( D3DRS_SRCBLEND,  &srcblend );
	device->GetRenderState( D3DRS_DESTBLEND, &destblend );
	device->GetRenderState( D3DRS_BLENDOP, &blendop );
	device->GetRenderState( D3DRS_LIGHTING, &light );
	device->GetRenderState( D3DRS_ZENABLE,          &zenable );
	device->GetRenderState( D3DRS_ZWRITEENABLE,     &zwrite );
	device->GetRenderState( D3DRS_STENCILENABLE,    &stencil );
	device->GetRenderState( D3DRS_CULLMODE,  &cullmode );

	//Ý’è
	device->SetRenderState (D3DRS_ALPHABLENDENABLE, true);
	device->SetRenderState( D3DRS_SRCBLEND,  D3DBLEND_SRCALPHA );
	device->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );
	device->SetRenderState( D3DRS_BLENDOP, D3DBLENDOP_ADD );
	device->SetRenderState( D3DRS_LIGHTING, false );
	device->SetRenderState( D3DRS_ZENABLE,          false );
	device->SetRenderState( D3DRS_ZWRITEENABLE,     false );
	device->SetRenderState( D3DRS_STENCILENABLE,    false );
	device->SetRenderState( D3DRS_CULLMODE,  D3DCULL_CCW );

	device->SetTexture( 0,NULL );


	//‚½‚¾‚Ì”Â‚ð‰æ–Ê‚¢‚Á‚Ï‚¢‚ÉƒŒƒ“ƒ_[

	DWORD Dcolor;
	if(black)
		Dcolor=D3DCOLOR_RGBA(0,0,0,(DWORD)(alphar*256));
	else
		Dcolor=D3DCOLOR_RGBA(255,255,255,(DWORD)(alphar*255));

	LVERTEX Vertex[4] = {
		//  x   y  z rhw color
		{   0,   0, 0, 1,					Dcolor,},
		{(float)width,   0, 0, 1,			Dcolor,},
		{(float)width,(float)height, 0, 1,	Dcolor,},
		{   0,(float)height, 0, 1,			Dcolor,},
	};
	device->SetVertexShader( D3DFVF_XYZRHW | D3DFVF_DIFFUSE );



	device->DrawPrimitiveUP( D3DPT_TRIANGLEFAN, 2, Vertex, sizeof( LVERTEX ) );



	//•œŒ³
	device->SetRenderState (D3DRS_ALPHABLENDENABLE, alphaenable);
	device->SetRenderState( D3DRS_SRCBLEND,  srcblend );
	device->SetRenderState( D3DRS_DESTBLEND, destblend );
	device->SetRenderState( D3DRS_BLENDOP, blendop );
	device->SetRenderState( D3DRS_LIGHTING, light );
	device->SetRenderState( D3DRS_ZENABLE,          zenable );
	device->SetRenderState( D3DRS_ZWRITEENABLE,     zwrite );
	device->SetRenderState( D3DRS_STENCILENABLE,    stencil );
	device->SetRenderState( D3DRS_CULLMODE,  cullmode );



jump:;

}

bool FeedClass::GetEnable()
{
	return !(count==0);
}
