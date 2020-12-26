#ifndef PROJECT_HED
#define PROJECT_HED


struct ProjectStruct{

	MeshClass mesh[12];
	char filename[12][MAX_PATH];
	D3DXVECTOR3 po[12],mv[12];
	D3DXVECTOR3 axis[12];
	float rpo[12],rmv[12];
	float side[12];

	int start[12];//スタートタイミング

//	CSound* sound;

	int frame;
}pro;


void ProjectReset()
{
	int i;

//	pro.onsound=false;
	pro.frame=-60;

	pro.side[0]=-0.85f;
	pro.side[1]=-0.694f;
	pro.side[2]=-0.535f;
	pro.side[3]=-0.347f;
	pro.side[4]=-0.204f;
	pro.side[5]=0.098f;
	pro.side[6]=0.27f;
	pro.side[7]=0.40f;
	pro.side[8]=0.498f;
	pro.side[9]=0.641f;
	pro.side[10]=0.784f;
	pro.side[11]=0.919f;

	for(i=0;i<12;i++)
	{
		pro.po[i].x=rnd(50)-25;
		pro.po[i].y=rnd(20)-10;
		pro.po[i].z=rnd(15)+20;
		pro.mv[i].x=rnd(0.8f)-0.4f;
		pro.mv[i].y=rnd(0.6f)-0.3f;
		pro.mv[i].z=-rnd(0.5f);

		pro.axis[i].x=rnd(20)-10;
		pro.axis[i].y=rnd(20)-10;
		pro.axis[i].z=rnd(20)-10;

		pro.rpo[i]=rnd(800)+800;
		
		pro.start[i]=(int)rnd(40);
	}

}


bool ProjectGraphicSetting()
{

	strcpy(&pro.filename[0][0],"Data/Object/GenkiProject/G.x");
	strcpy(&pro.filename[1][0],"Data/Object/GenkiProject/e.x");
	strcpy(&pro.filename[2][0],"Data/Object/GenkiProject/n.x");
	strcpy(&pro.filename[3][0],"Data/Object/GenkiProject/k.x");
	strcpy(&pro.filename[4][0],"Data/Object/GenkiProject/i.x");
	strcpy(&pro.filename[5][0],"Data/Object/GenkiProject/P.x");
	strcpy(&pro.filename[6][0],"Data/Object/GenkiProject/r.x");
	strcpy(&pro.filename[7][0],"Data/Object/GenkiProject/o.x");
	strcpy(&pro.filename[8][0],"Data/Object/GenkiProject/j.x");
	strcpy(&pro.filename[9][0],"Data/Object/GenkiProject/e2.x");
	strcpy(&pro.filename[10][0],"Data/Object/GenkiProject/c.x");
	strcpy(&pro.filename[11][0],"Data/Object/GenkiProject/t.x");

	int i;
	for(i=0;i<12;i++)
	{
		if(pro.mesh[i].Create(DG.Device,&pro.filename[i][0],Setting.MultiTextureEnable)==false)
			return false;
		//if(pro.mesh[i].SetFVF(DG.Device,D3DFVF_NORMAL|D3DFVF_XYZ|D3DFVF_TEX2)==false)
		//	return false;
	}

	return true;
}

void ProjectGraphicRelease()
{
	int i;
	for(i=0;i<12;i++)
		pro.mesh[i].Release();

}









//bool ProjectSoundSetting()
//{
//	pro.sound=NULL;
//
//
//		
//    //DWORD dwCreationFlags;
//    //dwCreationFlags = DSBCAPS_CTRLPAN | DSBCAPS_CTRLVOLUME | DSBCAPS_CTRLFREQUENCY;
//
//	if( FAILED(DS->Create( &pro.sound, "Data/Sound/Project.wav", 0, GUID_NULL )))
//		return false;
//
//	
//	return true;
//}

//void ProjectSoundRelease()
//{
//	pro.sound->Reset();
////	int i;
////	for(i=0;i<12;i++)
////		pro.mesh[i].Release();
//
//}
//
//
//





void ProjectMove()
{

	if(pro.frame<350)
	{
		pro.frame++;

		//if( pro.frame==30 )
		//{
		//	pro.sound->Play( 0, 0 );
		//}


		if(pro.frame>0)
		{

			int i;
			D3DXVECTOR3 pow;
			for(i=0;i<12;i++)
			{

				if(pro.start[i]>0)
					pro.start[i]--;
				else
				{


					pow=-pro.po[i];

					if(distance3(pro.po[i].x,pro.po[i].y,pro.po[i].z)>distance3(pro.po[i].x+pro.mv[i].x,pro.po[i].y+pro.mv[i].y,pro.po[i].z+pro.mv[i].z))
					{
						pow.x*=0.003f;
						pow.y*=0.003f;
						pow.z*=0.003f;
					}
					else
					{
						pow.x*=0.025f;
						pow.y*=0.025f;
						pow.z*=0.025f;
					}

					pro.mv[i]+=pow;

					pro.mv[i].x*=0.93f;
					pro.mv[i].y*=0.93f;
					pro.mv[i].z*=0.93f;
					pro.po[i]+=pro.mv[i];



					//回転制御
					pro.rpo[i]*=0.97f;

				}

			}

		}

	}

}

void ProjectRender()
{


	if(pro.frame<350)
	{


		//塗りつぶし
		if(Setting.ShadeEnable)
			DG.Device->Clear( 0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER | D3DCLEAR_STENCIL, 0, 1.0f, 0 );
		else
			DG.Device->Clear( 0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0, 1.0f, 0 );



		//カメラの位置調整
		D3DXMATRIX matView;

		D3DXMatrixLookAtLH( &matView, &D3DXVECTOR3( 0,0,-1 ), 
									&D3DXVECTOR3( 0,0,0 ), 
									&D3DXVECTOR3( 0.0f, 1.0f, 0.0f ) );


		DG.Device->SetTransform( D3DTS_VIEW, &matView );


		D3DXMATRIX matProj;
		D3DXMatrixPerspectiveFovLH( &matProj, D3DX_PI/2, (float)(4.0/3.0), 0.1f, 20 );
		DG.Device->SetTransform( D3DTS_PROJECTION, &matProj );







		//ライト設定

		DG.Device->SetRenderState( D3DRS_AMBIENT, 0xff000000 );

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








		D3DXMATRIX matWorld,matWorld2;

		static float a=0;
		a+=0.01f;

		int i;

		for(i=0;i<12;i++)
		{
			D3DXMatrixTranslation( &matWorld, -pro.side[i],0,0 );
			D3DXMatrixRotationAxis( &matWorld2, &pro.axis[i] ,pro.rpo[i]*rad );
			matWorld*=matWorld2;
			D3DXMatrixTranslation( &matWorld2, pro.po[i].x+pro.side[i],pro.po[i].y,pro.po[i].z );
			matWorld*=matWorld2;
			DG.Device->SetTransform( D3DTS_WORLD, &matWorld );
			pro.mesh[i].Render(DG.Device,NULL,NULL,0,0,0,ENVCHECK(&EnvTex[ENVKIND_PROJECT]),true);
		}




		if(pro.frame==250)
		{
			//普通のフェードアウト
 			feed[4].Start(FEEDMODE_BLACKOUT,100);
		}





	}



}






#endif
