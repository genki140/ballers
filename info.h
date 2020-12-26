#ifndef INFO_HED
#define INFO_HED

//ラップ、順位、マップ、速度、タイム、ステージ番号などのステータスを表示する

#define COUNTCHAR_MAX 100
#define ROOT_MAX 100
#define CHECK_MAX 100

enum {INFOCHAR_SLASH,INFOCHAR_STAGE,INFOCHAR_TIME,INFOCHAR_LAP,INFOCHAR_RANK,INFOCHAR_KM,INFOCHAR_DOT,INFOCHAR_CORON,INFOCHAR_MAX};
enum {INFOSTR_HSCORE,INFOSTR_FINAL,INFOSTR_BACK,INFOSTR_1ST,INFOSTR_2ND,INFOSTR_3RD,INFOSTR_4TH,INFOSTR_MAX};

struct InfoStruct
{
	//マップのメッシュ
	MeshClass mapmesh;
	float mapangle;


	LPDIRECT3DTEXTURE8 countdowntex[5];

	LPDIRECT3DTEXTURE8 numtex[10];

	LPDIRECT3DTEXTURE8 playernumtex[5];

	LPDIRECT3DTEXTURE8 chartex[INFOCHAR_MAX];
	LPDIRECT3DTEXTURE8 strtex[INFOSTR_MAX];

	int startcounter;
	int subcharcounter;
	int goalframe;


	//30を代入するとデクリされていき、それぞれのこうもくがアニメーションする
	int timeframe;
	int lapframe[4];
	int rankframe[4];

	//120を代入するとデクリされていき、それぞれのこうもくがアニメーションする
	int finalframe[4];
	int backframe[4];
	int goalrankframe[4];
	int hscoreframe;


	struct RootStruct
	{
		D3DXVECTOR3 po;
		float dis,sumdis;
	}root[ROOT_MAX];
	int rootcount;


	struct CheckStruct
	{
		float par;
		D3DXVECTOR3 po,gv,cpo,cup;
	}check[CHECK_MAX];
	int checkcount;





	//カウントダウンテクスチャをどんどん表示していくために使う構造体
	struct CountCharStruct
	{
		int num;//カウントの番号
		float scale,alpha,alpha2;
		//alphaの範囲は0～1で、0になったらレンダリングしない
		//alpha2は、最初フェードインするときに使う(実際の透明度の計算方法=>alpha*alpha2)
	}countchar[COUNTCHAR_MAX+1];


	int charcount;//文字が何個あるかのカウント



}info;


float InfoGetPar(int index)
{

	//現在位置のパーセントを取得
	int i;

	bool sphere=false;

	float r=40;

	float shortdis,shortdis2,dis,dis2;//shortdisは線の原点から先への距離,shortdis2は線からの距離
	int shortindex=-1;
	D3DXVECTOR3 wv,wv2;

	for(i=0;i<info.rootcount;i++)
	{
		wv=info.root[i+1].po-info.root[i].po;
		wv2=ball[index].ball.po-info.root[i].po;
		dis=dotpro3(wv.x,wv.y,wv.z,wv2.x,wv2.y,wv2.z);
		if(dis>=-10 && dis<=info.root[i+1].dis+10)
		{
			dis2=distanceaxis(wv2.x,wv2.y,wv2.z,wv.x,wv.y,wv.z);
			if(dis2<=r)//数値は適当
			{
				if(shortindex==-1 || shortdis2>dis2)
				{
					shortdis=dis;
					shortdis2=dis2;
					shortindex=i;
				}
			}
		}

	}

	////次は球との判定
	//for(i=0;i<info.rootcount;i++)
	//{
	//	dis=D3DXVec3Length(&(info.root[i].po-ball[index].ball.po));
	//	if(dis<=r && (shortindex==-1 || shortdis>dis) && shortindex!=i && shortindex+1!=i && (shortindex!=info.rootcount || i!=0))
	//	{
	//		sphere=true;
	//		shortdis=dis;
	//		shortindex=i;
	//	}
	//}


	//char str[100];
	//sprintf(str,"%d",shortindex);
	//MessageBox(NULL,str,"",MB_OK);


	if(shortindex==-1)
		return -1;

	float par;

	if(sphere)
		par=info.root[shortindex].sumdis/info.root[info.rootcount].sumdis;
	else
		par=(info.root[shortindex].sumdis+shortdis)/info.root[info.rootcount].sumdis;

	if(par>=1)
		par-=1;
	else if(par<0)
		par+=1;

	return par;

}







//IP,PORTを表示するときに使う(Selectから呼び出す)
void InfoNetRender(char *str)
{
	float w=3;

	D3DXMATRIX mat,mat2;
	DG.Device->GetTransform( D3DTS_WORLD, &mat2 );

	int len=(int)strlen(str);
	int i;

	for(i=0;i<len;i++)
	{
		if(str[i]!=' ')
		{

			D3DXMatrixTranslation( &mat, (i*w-len/2.0f*w+w/2),0,0 );
			mat*=mat2;

			DG.Device->SetTransform( D3DTS_WORLD, &mat );

			if(str[i]>='0' && str[i]<='9')
				ita.SetTexture(info.numtex[str[i]-'0'],0);
			else if(str[i]=='.')
				ita.SetTexture(info.chartex[INFOCHAR_DOT],0);

			ita.Material[0].Ambient=ita.Material[0].Diffuse=D3DXCOLOR(0.3f,0.7f,0.2f,1);
			ita.Render(DG.Device);

		}

	}

	//材質を戻す
	ita.Material[0].Ambient=ita.Material[0].Diffuse=D3DXCOLOR(1,1,1,1);
};








void InfoStrRender(int kind,int frame)
{
	if(frame<=0 || frame>120) return;
	
	D3DXMATRIX mat,mat2;
	float x,y,sx,sy;

	if(kind==INFOSTR_HSCORE)
	{
		x=0;y=-2.7f;sx=2*0.7f;sy=0.5f*0.7f;
	}
	else if(kind==INFOSTR_FINAL)
	{
		x=0;y=-2;sx=3.5f*0.7f;sy=0.5f*0.7f;
	}
	else if(kind==INFOSTR_BACK)
	{
		x=0;y=-2;sx=3.2f*0.7f;sy=1.2f*0.7f;
	}

	if(kind>=INFOSTR_1ST && kind<=INFOSTR_4TH)
	{
		x=0;y=0;sx=4*0.7f;sy=3*0.7f;
		ita.Material[0].Ambient.a=ita.Material[0].Diffuse.a=1-frame/120.0f;
	}
	else
	{
		if(frame>30)
			ita.Material[0].Ambient.a=ita.Material[0].Diffuse.a=1-(frame-30)/90.0f;
		else
			ita.Material[0].Ambient.a=ita.Material[0].Diffuse.a=frame/30.0f;
	}

	sx*=1+cosf((1-frame/120.0f)*270*rad)*(frame/120.0f);
	sy*=1-cosf(((1-frame/120.0f)*270-30)*rad)*(frame/120.0f);
	
	D3DXMatrixScaling( &mat, sx,sy,1 );
	D3DXMatrixTranslation( &mat2, x,y,0 );
	mat*=mat2;
	DG.Device->SetTransform( D3DTS_WORLD, &mat );

	ita.SetTexture(info.strtex[kind],0);

	ita.Render(DG.Device);

	ita.Material[0].Ambient.a=ita.Material[0].Diffuse.a=1;

}











//表示できるのは→数字、ドット、コロン
void InfoNumRender(char *str,D3DXCOLOR color,float x,float y,float s=1)
{

	D3DXMATRIX mat1,mat2;

	int len=(int)strlen(str);
	int i;


	for(i=0;i<len;i++)
	{
		if(str[i]!=' ')
		{

			D3DXMatrixScaling( &mat1, 0.12f,0.15f*s,1 );
			D3DXMatrixTranslation( &mat2, x+i*0.35f,y,0 );
			mat1*=mat2;
			DG.Device->SetTransform( D3DTS_WORLD, &mat1 );

			if(str[i]>='0' && str[i]<='9')
				ita.SetTexture(info.numtex[str[i]-'0'],0);
			else if(str[i]=='/')
				ita.SetTexture(info.chartex[INFOCHAR_SLASH],0);
			else if(str[i]=='.')
				ita.SetTexture(info.chartex[INFOCHAR_DOT],0);
			else if(str[i]==':')
				ita.SetTexture(info.chartex[INFOCHAR_CORON],0);

			ita.Material[0].Ambient=ita.Material[0].Diffuse=color;
			ita.Render(DG.Device);

		}

	}

	//材質を戻す
	ita.Material[0].Ambient=ita.Material[0].Diffuse=D3DXCOLOR(1,1,1,1);

}


bool InfoStageLoad()
{
	char str[MAX_PATH];
	sprintf(str,"data/Object/Map/%d.x",stagenum+1);
	if(!info.mapmesh.Create(DG.Device,str,Setting.MultiTextureEnable)) return false;
	return true;
}



//コースマップ&ルート&チェックポイントの読み込み
bool InfoStageSetting()
{
	char str[MAX_PATH];

	if(stagekind==SELECTGAME_VARSUS || stagekind==SELECTGAME_MULTIPLAY)
	{

		info.mapmesh.Reset();
		info.mapmesh.Release();
		if(!InfoStageLoad()) return false;

		FILE *file;


		info.rootcount=0;
		
		//マップ記録モードのとき、↓を消す
		{


			sprintf(str,"data/data/corce/root/%d",stagenum+1);
			if((file=fopen(str,"r"))==NULL) return false;

			info.root[info.rootcount].po=D3DXVECTOR3(0,0,0);
			info.root[info.rootcount].dis=0;
			info.root[info.rootcount].sumdis=0;
			info.rootcount++;

			while(fscanf(file,"%f,%f,%f,%f,%f",&info.root[info.rootcount].po.x,&info.root[info.rootcount].po.y,&info.root[info.rootcount].po.z,&info.root[info.rootcount].dis,&info.root[info.rootcount].sumdis)!=EOF)
			{
				info.rootcount++;
			}

			info.root[info.rootcount].po=D3DXVECTOR3(0,0,0);
			info.root[info.rootcount].dis=D3DXVec3Length(&info.root[info.rootcount-1].po);
			info.root[info.rootcount].sumdis=info.root[info.rootcount-1].sumdis+info.root[info.rootcount].dis;

		}



		info.checkcount=0;

		//チェック記録モードのとき、↓を消す
		{


			sprintf(str,"data/data/corce/check/%d",stagenum+1);
			if((file=fopen(str,"r"))==NULL) return false;

			info.check[info.checkcount].par=0;
			info.check[info.checkcount].po=D3DXVECTOR3(0,10,0);
			info.check[info.checkcount].gv=D3DXVECTOR3(0,1,0);
			info.check[info.checkcount].cpo=D3DXVECTOR3(0,15,-5);
			info.check[info.checkcount].cup=D3DXVECTOR3(0,1,0);
			info.checkcount++;

			while(fscanf(file,"%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n",&info.check[info.checkcount].par,
							&info.check[info.checkcount].po.x,&info.check[info.checkcount].po.y,&info.check[info.checkcount].po.z,
							&info.check[info.checkcount].gv.x,&info.check[info.checkcount].gv.y,&info.check[info.checkcount].gv.z,
							&info.check[info.checkcount].cpo.x,&info.check[info.checkcount].cpo.y,&info.check[info.checkcount].cpo.z,
							&info.check[info.checkcount].cup.x,&info.check[info.checkcount].cup.y,&info.check[info.checkcount].cup.z)!=EOF)
			{
				info.checkcount++;
			}

			info.check[info.checkcount].par=1;
			info.checkcount++;


		}




	}


	return true;
}



void InfoReset()
{
	int i;

	info.startcounter=0;
	info.goalframe=0;
	info.charcount=0;

	info.timeframe=0;

	for(i=0;i<4;i++)
		info.lapframe[i]=0;
	for(i=0;i<4;i++)
		info.rankframe[i]=0;


	info.hscoreframe=0;

	for(i=0;i<4;i++)
		info.finalframe[i]=0;
	for(i=0;i<4;i++)
		info.backframe[i]=0;
	for(i=0;i<4;i++)
		info.goalrankframe[i]=0;


	for(i=0;i<=COUNTCHAR_MAX;i++)
		info.countchar[i].alpha=0;
}


bool InfoGraphicSetting()
{
	int i;

	char str[MAX_PATH];



	for(i=0;i<10;i++)
	{
		sprintf(str,"data/graphic/info/Char/%d",i);

		if(!DG.CreateTexture(&info.numtex[i],str)) return false;
	}


	for(i=0;i<5;i++)
	{
		sprintf(str,"data/graphic/info/Count/%d",i);

		if(!DG.CreateTexture(&info.countdowntex[i],str)) return false;
	}

	for(i=0;i<5;i++)
	{
		sprintf(str,"data/graphic/info/Num/%d",i+1);

		if(!DG.CreateTexture(&info.playernumtex[i],str)) return false;
	}





	if(!DG.CreateTexture(&info.chartex[INFOCHAR_SLASH],"data/graphic/info/Char/Slash")) return false;
	if(!DG.CreateTexture(&info.chartex[INFOCHAR_STAGE],"data/graphic/info/Char/Stage")) return false;
	if(!DG.CreateTexture(&info.chartex[INFOCHAR_TIME],"data/graphic/info/Char/Time")) return false;
	if(!DG.CreateTexture(&info.chartex[INFOCHAR_LAP],"data/graphic/info/Char/Lap")) return false;
	if(!DG.CreateTexture(&info.chartex[INFOCHAR_RANK],"data/graphic/info/Char/Rank")) return false;
	if(!DG.CreateTexture(&info.chartex[INFOCHAR_KM],"data/graphic/info/Char/Km")) return false;
	if(!DG.CreateTexture(&info.chartex[INFOCHAR_DOT],"data/graphic/info/Char/Dot")) return false;
	if(!DG.CreateTexture(&info.chartex[INFOCHAR_CORON],"data/graphic/info/Char/Coron")) return false;

	if(!DG.CreateTexture(&info.strtex[INFOSTR_HSCORE],"data/graphic/info/Char/HScore")) return false;
	if(!DG.CreateTexture(&info.strtex[INFOSTR_FINAL],"data/graphic/info/Char/Final")) return false;
	if(!DG.CreateTexture(&info.strtex[INFOSTR_BACK],"data/graphic/info/Char/Back")) return false;
	if(!DG.CreateTexture(&info.strtex[INFOSTR_1ST],"data/graphic/info/Char/1st")) return false;
	if(!DG.CreateTexture(&info.strtex[INFOSTR_2ND],"data/graphic/info/Char/2nd")) return false;
	if(!DG.CreateTexture(&info.strtex[INFOSTR_3RD],"data/graphic/info/Char/3rd")) return false;
	if(!DG.CreateTexture(&info.strtex[INFOSTR_4TH],"data/graphic/info/Char/4th")) return false;

	return true;
}

void InfoGraphicRelease()
{

	int i;

	info.mapmesh.Release();

	for(i=0;i<10;i++)
	{
		if(info.numtex[i]!=NULL)
		{
			info.numtex[i]->Release();
			info.numtex[i]=NULL;
		}
	}


	for(i=0;i<5;i++)
	{
		if(info.countdowntex[i]!=NULL)
		{
			info.countdowntex[i]->Release();
			info.countdowntex[i]=NULL;
		}
	}

	for(i=0;i<5;i++)
	{
		if(info.playernumtex[i]!=NULL)
		{
			info.playernumtex[i]->Release();
			info.playernumtex[i]=NULL;
		}
	}


	for(i=0;i<INFOCHAR_MAX;i++)
	{
		if(info.chartex[i]!=NULL)
		{
			info.chartex[i]->Release();
			info.chartex[i]=NULL;
		}
	}

	for(i=0;i<INFOSTR_MAX;i++)
	{
		if(info.strtex[i]!=NULL)
		{
			info.strtex[i]->Release();
			info.strtex[i]=NULL;
		}
	}

}







void InfoMove()
{

	info.mapangle+=0.1f;

	info.subcharcounter=(info.subcharcounter+1)%7;



	//文字を作る

	if(info.startcounter>0)
	{
		info.startcounter--;
		//カウンター
		if(info.startcounter<=180 && info.startcounter%60==0)//メイン文字
		{
			info.countchar[COUNTCHAR_MAX].alpha=1;//0.0167づつ減らしていく・・・
			info.countchar[COUNTCHAR_MAX].alpha2=0;
			info.countchar[COUNTCHAR_MAX].num=(info.startcounter+59)/60;
			info.countchar[COUNTCHAR_MAX].scale=1;

			//音声再生
			if(info.countchar[COUNTCHAR_MAX].num==0)
				SOUND_PLAY(sd.Start);
			else
				SOUND_PLAY(sd.Count);
		}

	}
	else if(info.goalframe>0)
	{
		info.goalframe--;
	}

	if(info.countchar[COUNTCHAR_MAX].alpha>0 && info.subcharcounter%10==0)//サブ文字
	{
		info.countchar[info.charcount].alpha=info.countchar[COUNTCHAR_MAX].alpha*info.countchar[COUNTCHAR_MAX].alpha2;
		info.countchar[info.charcount].alpha2=0;
		info.countchar[info.charcount].num=info.countchar[COUNTCHAR_MAX].num;
		info.countchar[info.charcount].scale=info.countchar[COUNTCHAR_MAX].scale;
		info.charcount++;
	}





	//文字アニメーション


	if(info.goalframe==0)
	{
		if(info.countchar[COUNTCHAR_MAX].alpha>0) info.countchar[COUNTCHAR_MAX].alpha-=0.0167f;
		if(info.countchar[COUNTCHAR_MAX].alpha2<1) info.countchar[COUNTCHAR_MAX].alpha2+=0.08f;
		info.countchar[COUNTCHAR_MAX].scale*=1.02f;
	}
	else
	{
		if(info.countchar[COUNTCHAR_MAX].alpha>0) info.countchar[COUNTCHAR_MAX].alpha-=0.0167f/2.5f;
		if(info.countchar[COUNTCHAR_MAX].alpha2<1) info.countchar[COUNTCHAR_MAX].alpha2+=0.08f;
		info.countchar[COUNTCHAR_MAX].scale*=1.01f;
	}

	int i;
	for(i=0;i<info.charcount;i++)
	{
		if(info.countchar[i].alpha>0) info.countchar[i].alpha-=0.03f;
		if(info.countchar[i].alpha2<1) info.countchar[i].alpha2+=0.15f;
		info.countchar[i].scale*=1.05f;
	}


	//数値アニメーション
	if(info.timeframe>0)info.timeframe--;
	for(i=0;i<4;i++)
		if(info.lapframe[i]>0)info.lapframe[i]--;
	for(i=0;i<4;i++)
		if(info.rankframe[i]>0)info.rankframe[i]--;



	//文字列アニメーション
	for(i=0;i<4;i++)
		if(info.goalrankframe[i]>1)info.goalrankframe[i]--;
	for(i=0;i<4;i++)
		if(info.finalframe[i]>0)info.finalframe[i]--;
	for(i=0;i<4;i++)
		if(info.backframe[i]>0)info.backframe[i]--;
	if(info.hscoreframe>0)info.hscoreframe--;


}



void InfoRender(int index)//indexには情報をレンダリングするキャラクター番号を格納する、-1を入れると全体の表示(ステージ、カウント、etc)
{

	D3DXMATRIX matWorld,matWorld2,matWorld3;

	int i,j;
//	float dis;
	char str[100];

	//カメラの位置調整
	D3DXMATRIX matView;


	D3DXMatrixLookAtLH( &matView, &D3DXVECTOR3( 0,0,-10 ),
								&D3DXVECTOR3( 0,0,0 ), 
								&D3DXVECTOR3( 0.0f, 1.0f, 0.0f ) );

	DG.Device->SetTransform( D3DTS_VIEW, &matView );

	D3DXMATRIX matProj;
	D3DXMatrixPerspectiveFovLH( &matProj, D3DX_PI/3, (float)(4.0/3.0), 0.1f, 100000 );
	DG.Device->SetTransform( D3DTS_PROJECTION, &matProj );





	if(index==-1)
	{


		if(stagekind==SELECTGAME_VARSUS || stagekind==SELECTGAME_MULTIPLAY)
		{
			float mapsize;//拡大率
			float ox,oy,oz;//コースの中心位置
			switch (stagenum)
			{
			case 0:
				ox=155.73f;
				oy=-70.0f;
				oz=128.07f;
				mapsize=0.018f;
				break;
			case 1:
				ox=75.54f;
				oy=-70.0f;
				oz=-28.30f;
				mapsize=0.013f;
				break;
			case 2:
				ox=374.36f;
				oy=-100.0f;
				oz=-169.39f;
				mapsize=0.010f;
				break;
			case 3:
				ox=127.84f;
				oy=-145.31f;
				oz=-49.66f;
				mapsize=0.009f;
				break;

			case 4:
				ox=-110.88f;
				oy=-11.45f-80;
				oz=-219.99f;
				mapsize=0.009f*1.7f;
				break;

			case 5:
				ox=-158.0f;
				oy=-290.0f;
				oz=-222.0f;
				mapsize=0.009f;
				break;
			case 6:
				ox=132.17f;
				oy=-90.0f;
				oz=-7.76f;
				mapsize=0.015f;
				break;
			case 7:
				ox=-147.97f;
				oy=-90.0f;
				oz=123.52f;
				mapsize=0.014f;
				break;
			case 8:
				ox=-35.0f;
				oy=-90.0f;
				oz=-190.0f;
				mapsize=0.016f;
				break;
			case 9:
				ox=224.02f;
				oy=-0.0f;
				oz=228.59f;
				mapsize=0.009f;
				break;

			case 10:
				ox=-110.77f;
				oy=85.93f-100;
				oz=-128.21f;
				mapsize=0.009f*1.4f;
				break;

			case 11:
				ox=-110.77f;
				oy=85.93f-100;
				oz=-178.21f;
				mapsize=0.005f;
				break;

			};



			DG.Device->SetRenderState( D3DRS_LIGHTING, true );
			DG.Device->SetRenderState( D3DRS_ZENABLE,     true );
			DG.Device->SetRenderState( D3DRS_AMBIENT, 0x66666666 );


			//ビューボードを設定
			D3DVIEWPORT8 vp,keepvp;
			vp.MinZ=0;
			vp.MaxZ=1;

			if(playercount==1 || stagekind==SELECTGAME_MULTIPLAY)
			{
				vp.X=(DWORD)(0.025f*DG.Adapter.BackBufferWidth);
				vp.Y=(DWORD)(0.6f*DG.Adapter.BackBufferHeight);
				vp.Width=(DWORD)(0.35f*DG.Adapter.BackBufferWidth);
				vp.Height=(DWORD)(0.35f*DG.Adapter.BackBufferHeight);
			}
			else if(playercount==2)
			{
				vp.X=(DWORD)(0.3f*DG.Adapter.BackBufferWidth);
				vp.Y=(DWORD)(0.55f*DG.Adapter.BackBufferHeight);
				vp.Width=(DWORD)(0.4f*DG.Adapter.BackBufferWidth);
				vp.Height=(DWORD)(0.4f*DG.Adapter.BackBufferHeight);
			}
			else if(playercount==3)
			{
				vp.X=(DWORD)(0.55f*DG.Adapter.BackBufferWidth);
				vp.Y=(DWORD)(0.55f*DG.Adapter.BackBufferHeight);
				vp.Width=(DWORD)(0.4f*DG.Adapter.BackBufferWidth);
				vp.Height=(DWORD)(0.4f*DG.Adapter.BackBufferHeight);
			}
			else if(playercount==4)
			{
				vp.X=(DWORD)(0.35f*DG.Adapter.BackBufferWidth);
				vp.Y=(DWORD)(0.35f*DG.Adapter.BackBufferHeight);
				vp.Width=(DWORD)(0.3f*DG.Adapter.BackBufferWidth);
				vp.Height=(DWORD)(0.3f*DG.Adapter.BackBufferHeight);
			}


			DG.Device->GetViewport( &keepvp );
			DG.Device->SetViewport( &vp );



			//ステージマップを表示
			DG.Device->SetRenderState(D3DRS_NORMALIZENORMALS,TRUE);
			D3DXMatrixTranslation( &matWorld, -ox,-oy,-oz );
			D3DXMatrixScaling( &matWorld2, mapsize,mapsize,mapsize );
			matWorld*=matWorld2;
			D3DXMatrixRotationY( &matWorld2, info.mapangle*rad );
			matWorld*=matWorld2;
			D3DXMatrixRotationX( &matWorld2, -40*rad );
			matWorld*=matWorld2;
			DG.Device->SetTransform( D3DTS_WORLD, &matWorld );
			info.mapmesh.Render(DG.Device);
			DG.Device->SetRenderState(D3DRS_NORMALIZENORMALS,false);
				



			DG.Device->SetRenderState( D3DRS_ZENABLE,     false );






			//要素5は作業用
			D3DXVECTOR4 playerp[6];
			int playerindex[6];

			//位置を調べる
			for(i=0;i<playercount;i++)
			{
				playerindex[i]=i;
				D3DXVec3Transform(&playerp[i],&ball[i].ball.po,&matWorld);
			}

			playerindex[i]=4;//ゴースト
			D3DXVec3Transform(&playerp[i],&ball[BALL_MAX-1].ball.po,&matWorld);

			//ソート
			for(i=0;i<playercount;i++)
			{
				for(j=i+1;j<playercount+1;j++)
				{
					if(playerp[i].z<playerp[j].z)
					{
						playerp[5]=playerp[i];
						playerp[i]=playerp[j];
						playerp[j]=playerp[5];
						playerindex[5]=playerindex[i];
						playerindex[i]=playerindex[j];
						playerindex[j]=playerindex[5];
					}
				}
			}

			//順番通りにレンダリング
			D3DXMatrixScaling( &matWorld2, 0.5f,1.0f,0.5f );

			for(i=0;i<playercount+1;i++)
			{
				if(playerindex[i]==4 && (!Ghost || replayend || !GetClear() || !ReadReplayFile || replay)) continue;

				D3DXMatrixTranslation( &matWorld3, playerp[i].x,playerp[i].y,playerp[i].z );
				matWorld3=matWorld2*matWorld3;
				DG.Device->SetTransform( D3DTS_WORLD, &matWorld3 );

				ita.SetTexture(info.playernumtex[playerindex[i]],0);
				ita.Render(DG.Device);
			}


			DG.Device->SetViewport( &keepvp );

		}



		DG.Device->SetRenderState( D3DRS_ZENABLE,     false );
		DG.Device->LightEnable (0,false);
		DG.Device->SetRenderState( D3DRS_LIGHTING, true );
		DG.Device->SetRenderState( D3DRS_AMBIENT, 0xffffffff );


		//ハイスコアなら表示
		InfoStrRender(INFOSTR_HSCORE,info.hscoreframe);




		//カウンター表示

		for(i=0;i<=COUNTCHAR_MAX;i++)
		{

			if(info.countchar[i].alpha>0)
			{
				
				if(info.countchar[i].num==0)
					D3DXMatrixScaling( &matWorld, info.countchar[i].scale*2,info.countchar[i].scale,1 );
				else if(info.countchar[i].num==4)
					D3DXMatrixScaling( &matWorld, info.countchar[i].scale*3,info.countchar[i].scale,1 );
				else
					D3DXMatrixScaling( &matWorld, info.countchar[i].scale,info.countchar[i].scale,1 );

				DG.Device->SetTransform( D3DTS_WORLD, &matWorld );
				ita.SetTexture(info.countdowntex[info.countchar[i].num],0);
				ita.Material[0].Diffuse.a=info.countchar[i].alpha*info.countchar[i].alpha2;
				ita.Render(DG.Device);

			}

		}


		


		//材質を戻す
		ita.Material[0].Diffuse.a=1;



		DG.Device->SetRenderState( D3DRS_ZENABLE,     TRUE );
		DG.Device->SetRenderState( D3DRS_LIGHTING, true );
		DG.Device->LightEnable (0,true);




	}
	else
	{

		DG.Device->SetRenderState( D3DRS_LIGHTING, true );
		DG.Device->LightEnable (0,false);
		DG.Device->SetRenderState( D3DRS_AMBIENT, 0xffffffff );

		DG.Device->SetRenderState( D3DRS_ZENABLE,     false );


		InfoStrRender(INFOSTR_FINAL,info.finalframe[index]);
		InfoStrRender(INFOSTR_BACK,info.backframe[index]);
		InfoStrRender(INFOSTR_1ST+player[index].rank-1,info.goalrankframe[index]);


		if(stagekind==SELECTGAME_STAGE)
		{
			D3DXMatrixScaling( &matWorld, 0.6f,0.15f,1 );
			D3DXMatrixTranslation( &matWorld2, 4.0f-9.5f,5,0 );
			matWorld*=matWorld2;
			DG.Device->SetTransform( D3DTS_WORLD, &matWorld );
			ita.SetTexture(info.chartex[INFOCHAR_STAGE],0);
			ita.Render(DG.Device);


			if(stagenum<=12)
				sprintf(str,"%d",stagenum+1);
			else
				sprintf(str,"%d",stagenum+1-13);
			InfoNumRender(str,D3DXCOLOR(0.2f,1,0.5f,1),6.0f-9.6f,5);



			D3DXMatrixScaling( &matWorld, 0.44f,0.15f,1 );
			D3DXMatrixTranslation( &matWorld2, -3.0f+1,-5,0 );
			matWorld*=matWorld2;
			DG.Device->SetTransform( D3DTS_WORLD, &matWorld );
			ita.SetTexture(info.chartex[INFOCHAR_TIME],0);
			ita.Render(DG.Device);


			if(!GetClear() || staff)
				sprintf(str,"%.2f/%.2f",Time/60.0f,rTime/60.0f);
			else
				sprintf(str,"%.2f/%.2f :%.2f",Time/60.0f,rTime/60.0f,hTime[stagenum]/60.0f);
			InfoNumRender(str,D3DXCOLOR(0.5,0.7f,1.0f,1),-1.5f+1,-5,1+info.timeframe/30.0f);

		}
		else
		{
			if(playercount==1)
			{


				D3DXMatrixScaling( &matWorld, 0.44f,0.15f,1 );
				D3DXMatrixTranslation( &matWorld2, -6.0f,5,0 );
				matWorld*=matWorld2;
				DG.Device->SetTransform( D3DTS_WORLD, &matWorld );
				ita.SetTexture(info.chartex[INFOCHAR_LAP],0);
				ita.Render(DG.Device);

				int playerlap=player[index].lap;
				if(playerlap<1)
					playerlap=1;
				else if(playerlap>lap)
					playerlap=lap;
				sprintf(str,"%d/%d",playerlap,lap);
				InfoNumRender(str,D3DXCOLOR(0.2f,1,0.5f,1),-4.4f,5,1+info.lapframe[index]/30.0f);




				D3DXMatrixScaling( &matWorld, 0.44f,0.15f,1 );
				D3DXMatrixTranslation( &matWorld2, -3.0f+1.5f,5,0 );
				matWorld*=matWorld2;
				DG.Device->SetTransform( D3DTS_WORLD, &matWorld );
				ita.SetTexture(info.chartex[INFOCHAR_TIME],0);
				ita.Render(DG.Device);


				if(!GetClear())
					sprintf(str,"%.2f",Time/60.0f);
				else
					sprintf(str,"%.2f :%.2f",Time/60.0f,hTime[stagenum+STAGE_MAX]/60.0f);
				InfoNumRender(str,D3DXCOLOR(0.5,0.7f,1.0f,1),-1.5f+1.5f,5,1+info.timeframe/30.0f);




				D3DXMatrixScaling( &matWorld, 1.0f,0.15f,1 );
				D3DXMatrixTranslation( &matWorld2, 4.7f,-5,0 );
				matWorld*=matWorld2;
				DG.Device->SetTransform( D3DTS_WORLD, &matWorld );
				ita.SetTexture(info.chartex[INFOCHAR_KM],0);
				ita.Render(DG.Device);



				sprintf(str,"%.1f",(distance3(ball[index].ball.mv.x,ball[index].ball.mv.y,ball[index].ball.mv.z)*60*60*60/1000));
				InfoNumRender(str,D3DXCOLOR(0.3f,0.8f,0.8f,1),1.0f,-5);
				sprintf(str,"%.1f",(360*distance3(ball[index].ball.axis.x,ball[index].ball.axis.y,ball[index].ball.axis.z)/(2*pi*ball[index].ball.r)/360*60));
				InfoNumRender(str,D3DXCOLOR(0.3f,0.8f,0.8f,1),4.2f,-5);


				//sprintf(str,"%f",player[0].temppar);
				//InfoNumRender(str,D3DXCOLOR(0.2f,1,0.5f,1),0,0);


			}
			else
			{




				D3DXMatrixScaling( &matWorld, 0.44f,0.15f,1 );
				D3DXMatrixTranslation( &matWorld2, -6.0f+3-0.5f,5,0 );
				matWorld*=matWorld2;
				DG.Device->SetTransform( D3DTS_WORLD, &matWorld );
				ita.SetTexture(info.chartex[INFOCHAR_LAP],0);
				ita.Render(DG.Device);

				int playerlap=player[index].lap;
				if(playerlap<1)
					playerlap=1;
				else if(playerlap>lap)
					playerlap=lap;
				sprintf(str,"%d/%d",playerlap,lap);
				InfoNumRender(str,D3DXCOLOR(0.2f,1,0.5f,1),-4.4f+3-0.5f,5,1+info.lapframe[index]/30.0f);




				D3DXMatrixScaling( &matWorld, 0.44f,0.15f,1 );
				D3DXMatrixTranslation( &matWorld2, -6.0f+6+1.5f,5,0 );
				matWorld*=matWorld2;
				DG.Device->SetTransform( D3DTS_WORLD, &matWorld );
				ita.SetTexture(info.chartex[INFOCHAR_RANK],0);
				ita.Render(DG.Device);

				sprintf(str,"%d/%d",player[index].rank,playercount);
				InfoNumRender(str,D3DXCOLOR(1.0f,0.5f,0.5f,1),-4.4f+6+1.5f,5,1+info.rankframe[index]/30.0f);




				D3DXMatrixScaling( &matWorld, 1.0f,0.15f,1 );
				D3DXMatrixTranslation( &matWorld2, 4.7f-2-1.7f,-5,0 );
				matWorld*=matWorld2;
				DG.Device->SetTransform( D3DTS_WORLD, &matWorld );
				ita.SetTexture(info.chartex[INFOCHAR_KM],0);
				ita.Render(DG.Device);



				sprintf(str,"%.1f",(distance3(ball[index].ball.mv.x,ball[index].ball.mv.y,ball[index].ball.mv.z)*60*60*60/1000));
				InfoNumRender(str,D3DXCOLOR(0.3f,0.8f,0.8f,1),1.0f-2-1.7f,-5);
				sprintf(str,"%.1f",(360*distance3(ball[index].ball.axis.x,ball[index].ball.axis.y,ball[index].ball.axis.z)/(2*pi*ball[index].ball.r)/360*60));
				InfoNumRender(str,D3DXCOLOR(0.3f,0.8f,0.8f,1),4.2f-2-1.7f,-5);


 

				//ディレクションライト有効
				DG.Device->LightEnable (0,true);


				//アイテム表示

				DG.Device->SetRenderState( D3DRS_LIGHTING, true );
				DG.Device->SetRenderState( D3DRS_ZENABLE,     true );
				DG.Device->SetRenderState( D3DRS_AMBIENT, 0x66666666 );

				if(player[index].itemkind!=ITEMKIND_NONE)
				{


					D3DXMatrixRotationY( &matWorld, player[index].itemangle*rad );
					D3DXMatrixTranslation( &matWorld2, -2,-4,0 );
					matWorld*=matWorld2;
					DG.Device->SetTransform( D3DTS_WORLD, &matWorld );
					itemmesh[player[index].itemkind].Render(DG.Device, &D3DXVECTOR3(0,0,-10), &D3DXVECTOR3(0,0,0));
				}

				if(player[index].usekind!=ITEMKIND_NONE)
				{


					D3DXMatrixRotationY( &matWorld, player[index].itemangle*rad );
					D3DXMatrixTranslation( &matWorld2, 2,-4,0 );
					matWorld*=matWorld2;
					DG.Device->SetTransform( D3DTS_WORLD, &matWorld );
					itemmesh[player[index].usekind].Render(DG.Device, &D3DXVECTOR3(0,0,-10), &D3DXVECTOR3(0,0,0));
				}


			}			
		}







		DG.Device->SetRenderState( D3DRS_ZENABLE,     TRUE );
		DG.Device->SetRenderState( D3DRS_LIGHTING, true );
		DG.Device->LightEnable (0,true);



	}





}



void InfoStartCount()
{
	info.startcounter=250;
	info.charcount=0;
}



void InfoGoal()
{
	info.goalframe=150;
	info.charcount=0;

	info.countchar[COUNTCHAR_MAX].alpha=1;
	info.countchar[COUNTCHAR_MAX].alpha2=0;
	info.countchar[COUNTCHAR_MAX].num=4;
	info.countchar[COUNTCHAR_MAX].scale=0.7f;

}



#endif
