#ifndef TITLE_HED
#define TITLE_HED


struct TitleStruct
{

	MeshClass mesh;
	MeshClass groundmesh;

	D3DXMATRIX ball1,ball2;
	float ang[5],rota[5];//rotaは速度
	D3DXVECTOR3 defang[5],po[5];

	int frame;
}title;


void TitleReset()
{
	int i;

	for(i=0;i<5;i++)
	{
		title.rota[i]=rnd(4)-2;
	}
	
	title.po[0]=D3DXVECTOR3(-1.5f,1,-5);
	title.po[1]=D3DXVECTOR3(1.5f,1,-5);
	title.po[2]=D3DXVECTOR3(-4,0.7f,-3);
	title.po[3]=D3DXVECTOR3(0,1.3f,-3);
	title.po[4]=D3DXVECTOR3(4,0.8f,-2);


	//最初に適当に回転
	title.defang[0]=D3DXVECTOR3(rnd(1000),rnd(1000),rnd(1000));
	title.defang[1]=D3DXVECTOR3(rnd(1000),rnd(1000),rnd(1000));
	title.defang[2]=D3DXVECTOR3(rnd(1000),rnd(1000),rnd(1000));
	title.defang[3]=D3DXVECTOR3(rnd(1000),rnd(1000),rnd(1000));
	title.defang[4]=D3DXVECTOR3(rnd(1000),rnd(1000),rnd(1000));


	//回転マトリックス
//	title.doom=D3DXMATRIX(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
	D3DXMatrixRotationAxis( &title.ball1, &title.defang[i], distance3(title.defang[i].x,title.defang[i].y,title.defang[i].z) );
	D3DXMatrixRotationAxis( &title.ball2, &title.defang[i], distance3(title.defang[i].x,title.defang[i].y,title.defang[i].z) );


	title.frame=0;
}


bool TitleGraphicSetting()
{

	if(title.mesh.Create(DG.Device,"data/object/title/title.x",Setting.MultiTextureEnable)==false)
		return false;

	if(title.groundmesh.Create(DG.Device,"data/object/title/ground.x",Setting.MultiTextureEnable)==false)
		return false;


	return true;
}

void TitleGraphicRelease()
{
	title.mesh.Release();
	title.groundmesh.Release();

}







void TitleMove()
{

	if(title.frame==0)
	{
		// グラフの実行。
		pMediaControl->Run();
	}


	title.frame++;
	if(title.frame>800)
	{
		title.frame=800;
	}

	if(title.frame>620)
	{
		//キャラクターの回転
		int i;
		for(i=0;i<5;i++)
		{
			title.rota[i]+=rnd(0.02f)-0.01f;
			if(title.rota[i]>10)
				title.rota[i]=10;
			if(title.rota[i]<-10)
				title.rota[i]=-10;
			title.ang[i]+=title.rota[i];
		}

	}


	//フェードアウト処理
	if(title.frame==590 && feed[4].count==0)
		feed[4].Start(FEEDMODE_WHITEOUT,30);
	if(feed[4].count==29 && title.frame<620)
	{
		title.frame=620-2;
		feed[4].Start(FEEDMODE_WHITEIN,100);
	}



}

void TitleRender()
{

	D3DXMATRIX matWorld,matWorld2;



	//塗りつぶし
	if(Setting.ShadeEnable)
		DG.Device->Clear( 0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER | D3DCLEAR_STENCIL, 0, 1.0f, 0 );
	else
		DG.Device->Clear( 0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0, 1.0f, 0 );


	//カメラの位置調整
	D3DXMATRIX matView;

	D3DXMatrixLookAtLH( &matView, &D3DXVECTOR3( 0,3,-10 ),
								&D3DXVECTOR3( 0,0,0 ), 
								&D3DXVECTOR3( 0.0f, 1.0f, 0.0f ) );


	DG.Device->SetTransform( D3DTS_VIEW, &matView );


	D3DXMATRIX matProj;
	D3DXMatrixPerspectiveFovLH( &matProj, D3DX_PI/3, (float)(4.0/3.0), 0.1f, 10000 );
	DG.Device->SetTransform( D3DTS_PROJECTION, &matProj );





	if(title.frame<750)
	{


		//ライト設定

		DG.Device->SetRenderState( D3DRS_AMBIENT, 0xff000000 );

		D3DLIGHT8 Light;

		Light.Type = D3DLIGHT_SPOT;
		
		Light.Ambient.r = 0.3f;
		Light.Ambient.g = 0.3f;
		Light.Ambient.b = 0.3f;
		Light.Ambient.a = 1.0f;
		Light.Diffuse.r = 1.0f;
		Light.Diffuse.g = 1.0f;
		Light.Diffuse.b = 1.0f;
		Light.Diffuse.a = 1.0f;
		Light.Specular.r=0.6f;
		Light.Specular.g=0.6f;
		Light.Specular.b=0.6f;
		Light.Specular.a=1.0f;
		Light.Position.x = 0.0f;
		Light.Position.y = 20.0f;
		Light.Position.z = 5.0f;
		Light.Direction.x = 0.0f;
		Light.Direction.y = -1.0f;
		Light.Direction.z = 0.0f;
		Light.Attenuation0=1;
		Light.Attenuation1=0;
		Light.Attenuation2=0;
		Light.Range=500;
		Light.Phi=1.0f;
		Light.Theta=0.1f;
		Light.Falloff=1.0f;

		DG.Device->SetLight(0,&Light);
		DG.Device->LightEnable (0,true);
		DG.Device->LightEnable (1,false);
		DG.Device->LightEnable (2,false);
		DG.Device->LightEnable (3,false);
		DG.Device->LightEnable (4,false);
		DG.Device->LightEnable (5,false);
		DG.Device->LightEnable (6,false);
		DG.Device->LightEnable (7,false);





		if(title.frame<350)//移動
		{
			D3DXMatrixRotationY( &matWorld, 90*rad );
			D3DXMatrixTranslation( &matWorld2, -20+((float)title.frame/350*20),0,5 );
			matWorld*=matWorld2;
			DG.Device->SetTransform( D3DTS_WORLD, &matWorld );
			title.mesh.Render(DG.Device);


			//ball1,ball2を回転
			D3DXMatrixRotationZ( &matWorld, -2.0f*rad );
			title.ball1*=matWorld;
			title.ball2*=matWorld;

			D3DXMatrixTranslation( &matWorld, -20-2+((float)title.frame/350*20),1,5-4 );
			matWorld=title.ball1*matWorld;
			DG.Device->SetTransform( D3DTS_WORLD, &matWorld );
			ballmesh[0].Render(DG.Device);


			D3DXMatrixTranslation( &matWorld, -20-2+((float)title.frame/350*20),1,5+4 );
			matWorld=title.ball2*matWorld;
			DG.Device->SetTransform( D3DTS_WORLD, &matWorld );
			ballmesh[1].Render(DG.Device);



		}
		else if(title.frame<500)//ball2の移動
		{
			D3DXMatrixRotationY( &matWorld, 90*rad );
			D3DXMatrixTranslation( &matWorld2, 0,0,5 );
			matWorld*=matWorld2;
			DG.Device->SetTransform( D3DTS_WORLD, &matWorld );
			title.mesh.Render(DG.Device);


			//ball2を回転
			D3DXMatrixRotationAxis( &matWorld, &D3DXVECTOR3(-cosf((((float)title.frame-350)/150*180)*rad),0,sinf((((float)title.frame-350)/150*180)*rad)), -2.0f*rad );
			title.ball2*=matWorld;

			D3DXMatrixTranslation( &matWorld, -2,1,5-4 );
			matWorld=title.ball1*matWorld;
			DG.Device->SetTransform( D3DTS_WORLD, &matWorld );
			ballmesh[0].Render(DG.Device);



			D3DXMatrixTranslation( &matWorld, -cosf(((float)title.frame-350)/150*180*rad)*2,1,5+4+sinf(((float)title.frame-350)/150*180*rad)*2 );
			matWorld=title.ball2*matWorld;
			DG.Device->SetTransform( D3DTS_WORLD, &matWorld );
			ballmesh[1].Render(DG.Device);



		}
		else if(title.frame<620)//ロゴの回転
		{
			D3DXMatrixRotationY( &matWorld, (90-((float)title.frame-500)/100*70)*rad );
			D3DXMatrixTranslation( &matWorld2, 0,0,5 );
			matWorld*=matWorld2;
			DG.Device->SetTransform( D3DTS_WORLD, &matWorld );
			title.mesh.Render(DG.Device);


			//ball1、ball2を回転
			D3DXMatrixRotationZ( &matWorld, -2.0f*rad );
			title.ball1*=matWorld;
			D3DXMatrixRotationZ( &matWorld, 2.0f*rad );
			title.ball2*=matWorld;

			D3DXMatrixTranslation( &matWorld, -2,0,-4 );
			matWorld=title.ball1*matWorld;
			D3DXMatrixRotationY( &matWorld2, -(((float)title.frame-500)/100*70)*rad );
			matWorld*=matWorld2;
			D3DXMatrixTranslation( &matWorld2, -0,1,5 );
			matWorld*=matWorld2;
			DG.Device->SetTransform( D3DTS_WORLD, &matWorld );
			ballmesh[0].Render(DG.Device);


			D3DXMatrixTranslation( &matWorld, 2,0,4 );
			matWorld=title.ball2*matWorld;
			D3DXMatrixRotationY( &matWorld2, -(((float)title.frame-500)/100*70)*rad );
			matWorld*=matWorld2;
			D3DXMatrixTranslation( &matWorld2, 0,1,5 );
			matWorld*=matWorld2;
			DG.Device->SetTransform( D3DTS_WORLD, &matWorld );
			ballmesh[1].Render(DG.Device);


		}


	}

	if(title.frame>620)
	{





		//ライト設定

		DG.Device->SetRenderState( D3DRS_AMBIENT, 0x55555555 );

		D3DLIGHT8 Light;

		Light.Type = D3DLIGHT_DIRECTIONAL;
		Light.Ambient.r = 0.0f;
		Light.Ambient.g = 0.0f;
		Light.Ambient.b = 0.0f;
		Light.Ambient.a = 1.0f;
		Light.Diffuse.r = 1.0f;
		Light.Diffuse.g = 1.0f;
		Light.Diffuse.b = 1.0f;
		Light.Diffuse.a = 1.0f;
		Light.Specular.r=0.6f;
		Light.Specular.g=0.6f;
		Light.Specular.b=0.6f;
		Light.Specular.a=1.0f;
		Light.Direction.x = 2.0f;
		Light.Direction.y = -4.0f;
		Light.Direction.z = 5.0f;

		DG.Device->SetLight(0,&Light);
		DG.Device->LightEnable (0,true);
		DG.Device->LightEnable (1,false);
		DG.Device->LightEnable (2,false);
		DG.Device->LightEnable (3,false);
		DG.Device->LightEnable (4,false);
		DG.Device->LightEnable (5,false);
		DG.Device->LightEnable (6,false);
		DG.Device->LightEnable (7,false);




		D3DXMatrixTranslation( &matWorld, 0,0,5 );
		DG.Device->SetTransform( D3DTS_WORLD, &matWorld );
		title.mesh.Render(DG.Device,&D3DXVECTOR3(0,0,-10),&D3DXVECTOR3(0,0,0));


		DG.Device->SetTransform( D3DTS_WORLD, &D3DXMATRIX(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1) );
		title.groundmesh.Render(DG.Device);




		int i;


		//陰をステンシルバッファに書く

		if(Setting.ShadeEnable)
		{

			for(i=0;i<5;i++)
			{

				//陰のマトリックスセット
				D3DXMatrixScaling( &matWorld, character[i].r,1,character[i].r );
				D3DXMatrixRotationZ( &matWorld2, rad*30 );
				matWorld*=matWorld2;
				D3DXMatrixRotationY( &matWorld2, rad*30 );
				matWorld*=matWorld2;
				D3DXMatrixTranslation( &matWorld2, title.po[i].x,title.po[i].y,title.po[i].z );
				matWorld*=matWorld2;
				DG.Device->SetTransform( D3DTS_WORLD, &matWorld );



				//前設定
				DG.Device->SetRenderState( D3DRS_ZWRITEENABLE,  FALSE );
				DG.Device->SetRenderState( D3DRS_STENCILENABLE, TRUE );
				DG.Device->SetRenderState( D3DRS_SHADEMODE,     D3DSHADE_FLAT );
				DG.Device->SetRenderState( D3DRS_STENCILFUNC,  D3DCMP_ALWAYS );
				DG.Device->SetRenderState( D3DRS_STENCILZFAIL, D3DSTENCILOP_KEEP );
				DG.Device->SetRenderState( D3DRS_STENCILFAIL,  D3DSTENCILOP_KEEP );
				DG.Device->SetRenderState( D3DRS_STENCILREF,       0x1 );
				DG.Device->SetRenderState( D3DRS_STENCILMASK,      0xffffffff );
				DG.Device->SetRenderState( D3DRS_STENCILWRITEMASK, 0xffffffff );
				DG.Device->SetRenderState( D3DRS_SRCBLEND,  D3DBLEND_ZERO );
				DG.Device->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_ONE );


				//表を書く
				DG.Device->SetRenderState( D3DRS_CULLMODE,   D3DCULL_CCW );
				DG.Device->SetRenderState( D3DRS_STENCILPASS,      D3DSTENCILOP_INCR );
				shade.Render(DG.Device);


				//裏側を書く
				DG.Device->SetRenderState( D3DRS_CULLMODE,   D3DCULL_CW );
				DG.Device->SetRenderState( D3DRS_STENCILPASS, D3DSTENCILOP_DECR );
				shade.Render(DG.Device);


				// 設定復元
				DG.Device->SetRenderState( D3DRS_CULLMODE,  D3DCULL_CCW );
				DG.Device->SetRenderState( D3DRS_ZWRITEENABLE,     TRUE );
				DG.Device->SetRenderState( D3DRS_STENCILENABLE,    FALSE );
				DG.Device->SetRenderState( D3DRS_SRCBLEND,  D3DBLEND_SRCALPHA );
				DG.Device->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );

			}



			//影を実際のバッファに書く
			{

				//前処理
				DG.Device->SetRenderState( D3DRS_ZENABLE,          FALSE );
				DG.Device->SetRenderState( D3DRS_STENCILENABLE,    TRUE );
				DG.Device->SetRenderState( D3DRS_STENCILREF,  0x1 );
				DG.Device->SetRenderState( D3DRS_STENCILFUNC, D3DCMP_LESSEQUAL );
				DG.Device->SetRenderState( D3DRS_STENCILPASS, D3DSTENCILOP_KEEP );


				//ただの板を画面いっぱいにレンダー
				{
					#define     FVF_LVERTEX         (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)
					float size = 1000.0f;
					typedef struct{
						float   x, y, z, w;
						DWORD   color;
					} LVERTEX;
					LVERTEX Vertex[4] = {
						//  x   y  z rhw color
						{   0,   0, 0, 1, D3DCOLOR_RGBA(0x0,0x0,0x0,0x30),},
						{(float)DG.Adapter.BackBufferWidth,   0, 0, 1, D3DCOLOR_RGBA(0x0,0x0,0x0,0x30),},
						{(float)DG.Adapter.BackBufferWidth,(float)DG.Adapter.BackBufferHeight, 0, 1, D3DCOLOR_RGBA(0x0,0x0,0x0,0x30),},
						{   0,(float)DG.Adapter.BackBufferHeight, 0, 1, D3DCOLOR_RGBA(0x0,0x0,0x0,0x30),},
					};
					DG.Device->SetVertexShader( FVF_LVERTEX );
					DG.Device->DrawPrimitiveUP( D3DPT_TRIANGLEFAN, 2, Vertex, sizeof( LVERTEX ) );
				}


				// 設定復元
				DG.Device->SetRenderState( D3DRS_ZENABLE,          TRUE );
				DG.Device->SetRenderState( D3DRS_STENCILENABLE,    FALSE );
				DG.Device->SetRenderState( D3DRS_SHADEMODE, D3DSHADE_GOURAUD );

			}

		}





		//キャラクターのレンダリング
		for(i=4;i>=0;i--)
		{
			D3DXMatrixRotationAxis( &matWorld, &title.defang[i], distance3(title.defang[i].x,title.defang[i].y,title.defang[i].z) );
			D3DXMatrixRotationY( &matWorld2, title.ang[i]*rad );
			matWorld*=matWorld2;
			D3DXMatrixTranslation( &matWorld2, title.po[i].x,title.po[i].y,title.po[i].z );
			matWorld*=matWorld2;
			DG.Device->SetTransform( D3DTS_WORLD, &matWorld );




			ballmesh[i].Render(DG.Device, NULL, NULL, 0,0,1);
			ballmesh[i].Render(DG.Device, NULL, NULL, 0,1,1,ENVCHECK(&EnvTex[ENVKIND_KI]));

			//if(Setting.EnvEnable)
			//{
			//	ballmesh[i].Render(DG.Device,&D3DXVECTOR3(0,0,-10),&D3DXVECTOR3(0,0,0),0,0,1);
			//	ballmesh[i].Render(DG.Device,&D3DXVECTOR3(0,0,-10),&D3DXVECTOR3(0,0,0),0,1,1,&EnvTex[ENVKIND_KI]);
			//}
			//else
			//	ballmesh[i].Render(DG.Device,&D3DXVECTOR3(0,0,-10),&D3DXVECTOR3(0,0,0),0,0,0);

		}


	}



}






#endif
