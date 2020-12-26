
//※簡単なメッシュ関数と摩り替えてテストする！！


#include "meshclass.h"

//extern bool disget;
//extern float ansdis;


MeshClass::MeshClass()
{
	//環境マップマトリックス設定
	D3DXMATRIX mat;
	D3DXMatrixTranslation( &EnvMatrix, 1,1,0 );
	D3DXMatrixScaling( &mat, 0.5f,-0.5f,1 );
	EnvMatrix*=mat;

	Reset();
}


void MeshClass::Reset()
{
	//初期化
	Created=false;
}


bool MeshClass::Create( LPDIRECT3DDEVICE8 device, char *filename, bool MultiTexture)
{


	int i,j,k,l;
	char str[100];
	FILE* file;//ファイル存在確認用


	//ファイルパス(data/)、ファイル名(test)、拡張子(.x)に分ける
	char name[MAX_PATH],kakutyousi[MAX_PATH];
	PathDiv(filename,MeshRootPath,name,kakutyousi);


//Progressive=false;

	if(!Created)
	{



		////ファイル名より、メッシュの数を測定する


		//メッシュのカウンタ初期化

		MeshCount=0;

		char newfilename[MAX_PATH];


		//ここから繰り返す
		while(1)
		{

			//カウンタより、ファイル名の生成
			strcpy(newfilename,MeshRootPath);
			strcat(newfilename,name);
			if((MeshCount+1)!=1)
			{
				sprintf(str,"[%d]",(MeshCount+1));
				strcat(newfilename,str);
			}
			strcat(newfilename,kakutyousi);


			//ファイルが存在するか確認
			if((file=fopen(newfilename,"r"))!=NULL)
			{
				//ファイル発見！！
				fclose(file);
				strcpy(MeshFileName[MeshCount],newfilename);
				MeshCount++;
			}
			else
			{
				//ファイルが存在しない！！
				if(MeshCount==0)
					return false;//失敗

				break;
			}


		}




		//メッシュ再構築！
		Mesh=new LPD3DXMESH[MeshCount];

		MeshP = new D3DXVECTOR3[MeshCount];
		MeshR = new float[MeshCount];


		//その他の変数も再構築!!
		MeshMaterialCount=new short int[MeshCount];
//		MeshDistance=new float[MeshCount];
		



	


	}//Created



	//マテリアル再構築用変数
	int matcount=0;
	LPD3DXBUFFER *MtrlBuffer = new LPD3DXBUFFER[MeshCount];
	LPD3DXBUFFER pAdjacencyBuffer;
	DWORD *MCount = new DWORD[MeshCount];


	//境界球計算用変数
	D3DXVECTOR3 BoxMax,BoxMin;
	float dis;


	for(i=0;i<MeshCount;i++)
	{

		Mesh[i]=NULL;

		//読み込む
		if( FAILED( D3DXLoadMeshFromX( MeshFileName[i], D3DXMESH_MANAGED, 
									device, &pAdjacencyBuffer,
									&MtrlBuffer[i], &MCount[i],
									&Mesh[i] ) ) )
		{

			//みつからねー
			return false;
		}



		//面がなかったらスルー
		if(Mesh[i]->GetNumFaces()>0)
		{



			matcount+=(MeshMaterialCount[i]=(int)MCount[i]);



			//境界球算出

			LPD3DXMESH TempMesh = NULL;

			//メッシュのフォーマットを変更
			if( FAILED( Mesh[i]->CloneMeshFVF( D3DXMESH_SYSTEMMEM, D3DFVF_XYZ, device, &TempMesh ) ) )
				return false;

			LPDIRECT3DVERTEXBUFFER8 VB;
			TempMesh->GetVertexBuffer(&VB);

			//頂点の位置情報のみを吸い出す
			D3DXVECTOR3* vec;
			if( FAILED( VB->Lock( 0, 0, (BYTE**)&vec, 0 ) ) )
				return false;

			//境界ボックスを求める
			BoxMax=BoxMin=vec[0];			
			for(j=1;j<(int)TempMesh->GetNumVertices();j++)
			{
				if(BoxMax.x<vec[j].x)
					BoxMax.x=vec[j].x;
				if(BoxMax.y<vec[j].y)
					BoxMax.y=vec[j].y;
				if(BoxMax.z<vec[j].z)
					BoxMax.z=vec[j].z;
				if(BoxMin.x>vec[j].x)
					BoxMin.x=vec[j].x;
				if(BoxMin.y>vec[j].y)
					BoxMin.y=vec[j].y;
				if(BoxMin.z>vec[j].z)
					BoxMin.z=vec[j].z;
			}
		
			MeshP[i].x=(BoxMax.x+BoxMin.x)/2;
			MeshP[i].y=(BoxMax.y+BoxMin.y)/2;
			MeshP[i].z=(BoxMax.z+BoxMin.z)/2;


			//一番遠い点の距離を求める(半径)
			MeshR[i]=distance3(vec[0].x-MeshP[i].x,vec[0].y-MeshP[i].y,vec[0].z-MeshP[i].z);//sqrtf((vec[0].x-MeshP[i].x)*(vec[0].x-MeshP[i].x)+(vec[0].y-MeshP[i].y)*(vec[0].y-MeshP[i].y)+(vec[0].z-MeshP[i].z)*(vec[0].z-MeshP[i].z));

			for(j=1;j<(int)Mesh[i]->GetNumVertices();j++)
			{
				dis=distance3(vec[j].x-MeshP[i].x,vec[j].y-MeshP[i].y,vec[j].z-MeshP[i].z);
				if(dis>MeshR[i])
					MeshR[i]=dis;
			}


			
			VB->Unlock();

			TempMesh->Release();




//			if(Progressive)
//			{
//
//
//				//プログレッシブメッシュの作成
//				if( FAILED( D3DXGeneratePMesh( Mesh[i], (DWORD*)pAdjacencyBuffer->GetBufferPointer(),
//										NULL, NULL, 1, D3DXMESHSIMP_VERTEX, &PMesh[i] )))
//				{
//					//ミスった！
//					PMesh[i]=NULL;
//				}
//				else
//				{
////					PMesh[i]->SetNumVertices(PMesh[i]->GetMaxVertices());
//
//					//最適化しておく
//					if( FAILED( PMesh[i]->OptimizeBaseLOD(D3DXMESHOPT_VERTEXCACHE, NULL) ) )
//					{
//						//ミスった！
//						return false;
//					}
//				}
//
//
//			}
//





			//最適化しておく
			if( FAILED( Mesh[i]->OptimizeInplace(D3DXMESHOPT_COMPACT | D3DXMESHOPT_ATTRSORT | D3DXMESHOPT_VERTEXCACHE,
												(DWORD*)pAdjacencyBuffer->GetBufferPointer(), NULL, NULL, NULL) ) )
			{
				//ミスった！
				return false;
			}


		}


		pAdjacencyBuffer->Release();

	}






	if(!Created)
	{


		//作業用マテリアル(とりあえず大きめにとる)
		D3DMATERIAL8* WorkMaterial = new D3DMATERIAL8[matcount];


		//テクスチャファイル名をしらべる
		TextureCount=0;
		TextureKindCount=0;
		MaterialCount=0;


		//メッシュごとに調べる
		for(i=0;i<MeshCount;i++)
		{
			D3DXMATERIAL* d3dxMaterials=(D3DXMATERIAL*)MtrlBuffer[i]->GetBufferPointer();
	 
			//材質ごとに調べる
			for(j=0;j<(int)MeshMaterialCount[i];j++)
			{
				//i=メッシュ番号
				//j=材質番号



				//マテリアルチェック

				for(k=0;k<MaterialCount;k++)
				{
					if(MaterialCmp(&WorkMaterial[k],&d3dxMaterials[j].MatD3D))
					{
						//同じの発見!
						MeshMaterialIndex[i][j]=k;
						goto MaterialCheckEnd;
					}
				}

				//同じのがなかった
				WorkMaterial[MaterialCount]=d3dxMaterials[j].MatD3D;
				WorkMaterial[MaterialCount].Ambient=WorkMaterial[MaterialCount].Diffuse;
				MeshMaterialIndex[i][j]=MaterialCount;
				MaterialCount++;



	MaterialCheckEnd:;





				//テクスチャチェック

				if(d3dxMaterials[j].pTextureFilename==NULL)
				{
	//				d3dxMaterials[j].pTextureFilename= new char[MAX_PATH];
	//				strcpy(d3dxMaterials[j].pTextureFilename,"");
					d3dxMaterials[j].pTextureFilename="";
				}





				//そのテクスチャがすでに読み込まれているかのチェック
				for(k=0;k<TextureCount;k++)
				{
					if(stricmp(&TextureFileName[k][0],d3dxMaterials[j].pTextureFilename)==0)
					{
						//何番目の(種類)テクスチャか調べる
						for(l=0;l<TextureKindCount;l++)
						{
							if(TextureIndex[l]==k)
							{
								MeshTextureIndex[i][j]=l;

								//この材質のチェックは終わり!
								goto TextureCheckEnd;
							}
						}
					}
				}


				//まだ読み込まれていない!!

				//マルチテクスチャの枚数を測定する

				char newtexfilename[MAX_PATH];

				//ファイルパス(data/)、ファイル名(test)、拡張子(.x)に分ける
				char texpath[MAX_PATH],texname[MAX_PATH],texkakutyousi[MAX_PATH];
				PathDiv(d3dxMaterials[j].pTextureFilename,texpath,texname,texkakutyousi);



				//初期設定
				TextureIndex[TextureKindCount]=TextureCount;
				TextureMultiCount[TextureKindCount]=0;




				//まずは１枚目のテクスチャファイル名を格納
				strcpy(TextureFileName[TextureCount],texpath);
				strcat(TextureFileName[TextureCount],texname);
				strcat(TextureFileName[TextureCount],texkakutyousi);

				//ファイルが存在するか確認(アプリケーションからのフルパスで調べる)
				strcpy(newtexfilename,MeshRootPath);
				strcat(newtexfilename,TextureFileName[TextureCount]);

				//ファイルが存在したときの処理
				TextureCount++;
				TextureMultiCount[TextureKindCount]++;
				MeshTextureIndex[i][j]=TextureKindCount;




				if(MultiTexture==false)
				{
					TextureKindCount++;
				}
				else
				{

					//ここから繰り返す
					while(1)
					{

						//カウンタより、ファイル名の生成

						strcpy(TextureFileName[TextureCount],texpath);
						strcat(TextureFileName[TextureCount],texname);
						if((TextureMultiCount[TextureKindCount]+1)!=1)
						{
							sprintf(str,"[%d]",(TextureMultiCount[TextureKindCount]+1));
							strcat(TextureFileName[TextureCount],str);
						}
						strcat(TextureFileName[TextureCount],texkakutyousi);

						//ファイルが存在するか確認(アプリケーションからのフルパスで調べる)
						strcpy(newtexfilename,MeshRootPath);
						strcat(newtexfilename,TextureFileName[TextureCount]);
						if((file=fopen(newtexfilename,"r"))!=NULL)
						{
							fclose(file);

							//ファイルが存在したときの処理
							TextureCount++;
							TextureMultiCount[TextureKindCount]++;
							MeshTextureIndex[i][j]=TextureKindCount;
						}
						else
						{
							//ファイルが存在しない!

							if(TextureMultiCount[TextureKindCount]!=0)
							{
								TextureKindCount++;
							}

							//次の材質へ
							goto TextureCheckEnd;


						}


					}



				}


	TextureCheckEnd:;



			}


			//もう必要ない
			MtrlBuffer[i]->Release();

		}




		//マテリアル再構築!
		Material = new D3DMATERIAL8[MaterialCount];
		for(i=0;i<MaterialCount;i++)
		{
			Material[i]=WorkMaterial[i];
		}




		//テクスチャ再構築!!
		Texture = new LPDIRECT3DTEXTURE8[TextureCount];
		KeepTexture = new LPDIRECT3DTEXTURE8[TextureCount];



	}//Created

	

	//テクスチャ読み込み

	char TexFullPath[MAX_PATH];

	for(i=0;i<TextureCount;i++)
	{
		if(stricmp(&TextureFileName[i][0],"")==0)
		{
			Texture[i]=NULL;
			KeepTexture[i]=NULL;
		}
		else
		{

			strcpy(TexFullPath,MeshRootPath);
			strcat(TexFullPath,&TextureFileName[i][0]);

			if( FAILED( D3DXCreateTextureFromFileEx(
						device,					// デバイス
						TexFullPath,	// テクスチャファイル名
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
						&Texture[i] ) ) )		// テクスチャ
			{
				//みつからねー
				Texture[i]=NULL;
				KeepTexture[i]=NULL;

			}
			else
				KeepTexture[i]=Texture[i];

		}

	}






	//設定色々


	if(Created==false)
	{

		//EnvEnable=new bool[TextureCount];
		//for(i=0;i<TextureCount;i++)
		//	EnvEnable[i]=false;

		UVTranslationX=new float[TextureCount];
		UVTranslationY=new float[TextureCount];
		UVScalingX=new float[TextureCount];
		UVScalingY=new float[TextureCount];
		UVRotation=new float[TextureCount];
		ColorOpereter=new int[TextureCount];
		ColorArg1=new int[TextureCount];
		ColorArg2=new int[TextureCount];
		AlphaOpereter=new int[TextureCount];
		AlphaArg1=new int[TextureCount];
		AlphaArg2=new int[TextureCount];
//		Factor=new D3DXCOLOR[TextureCount];

		//マルチテクスチャのUVは、枚数ごとに、3.7倍し、35度ずつ回転させる。
		//この数値は、テクスチャができるだけ繰り返さないように試行錯誤した値(つまり適当)です

		for(i=0;i<TextureKindCount;i++)
		{
			for(j=0;j<TextureMultiCount[i];j++)
			{
				UVTranslationX[TextureIndex[i]+j]=0;
				UVTranslationY[TextureIndex[i]+j]=0;
				UVScalingX[TextureIndex[i]+j]=1/powf(3.7f,(float)j);
				UVScalingY[TextureIndex[i]+j]=1/powf(3.7f,(float)j);
				//UVScalingX[TextureIndex[i]+j]=10;
				//UVScalingY[TextureIndex[i]+j]=10;
				UVRotation[TextureIndex[i]+j]=(float)j*35;
				//オペレータ操作
				ColorOpereter[TextureIndex[i]+j]=D3DTOP_MODULATE;
				ColorArg1[TextureIndex[i]+j]=D3DTA_CURRENT;
				ColorArg2[TextureIndex[i]+j]=D3DTA_TEXTURE;
				AlphaOpereter[TextureIndex[i]+j]=D3DTOP_MODULATE;
				AlphaArg1[TextureIndex[i]+j]=D3DTA_CURRENT;
				AlphaArg2[TextureIndex[i]+j]=D3DTA_TEXTURE;
//				Factor[TextureIndex[i]+j]=D3DXCOLOR(255,255,255,255);
			}
		}


//
//		//メッシュの限界表示距離の設定
//		for(i=0;i<MeshCount;i++)
//		{
////			for(j=0;j<MeshLvCount[i]-1;j++)
////			{
////				MeshDistance[i+j]=powf(2,(float)j)*20;
////			}
//			MeshDistance[i]=10000;//どこまでも表示する！！
////			MeshDistance[i]=1000000000;
//		}
//
//


		////環境マップテクスチャの設定
		//EnvTexture=new LPDIRECT3DTEXTURE8[MeshCount*MeshMaterialCountMax];
		//for(i=0;i<MeshCount*MeshMaterialCountMax;i++)
		//	EnvTexture=NULL;


	}
	




	Created=true;

	return true;
}




void MeshClass::Render( LPDIRECT3DDEVICE8 device, D3DXVECTOR3* po, D3DXVECTOR3* look, float fovy, int start, int count, LPDIRECT3DTEXTURE8* EnvTexture ,bool Reflection )
{

	if(Created==true)
	{


		D3DXVECTOR3 WorkMuki;

		//カリングするか(メッシュのレベルわけも)
		//bool progressive = (po!=NULL) && (look!=NULL);
		bool cull = (fovy>0) && (po!=NULL) && (look!=NULL);

		cull=false;


		D3DXVECTOR3 Muki;//カメラの向きを格納

		float dis,width,ballwidth,camerawidth;
		//ballwidth( r/cos(視野/2) )
		//camerawidthは、カメラから見た境界球のいち(z)のカメラの幅を格納

		D3DXVECTOR4 vec4;
		D3DXMATRIX mat;

		if(cull)
		{
			Muki.x=look->x-po->x;
			Muki.y=look->y-po->y;
			Muki.z=look->z-po->z;

			device->GetTransform( D3DTS_WORLD, &mat );
		}






		//範囲チェック
		if(count<=0)
			count=MeshCount;
		if(start<0)
			start=0;
		if(start>=MeshCount)
			start=MeshCount-1;
		if(start+count>MeshCount)
			count=MeshCount-start;

		//count=MeshCount;
		//start=0;


		int i,k,l;



		for(i=start;i<start+count;i++)
		{





			if(cull)
			{
				//物体の中心点をトランスフォーム
				D3DXVec3Transform(&vec4,&MeshP[i],&mat);
				//カメラの座標へ移動
				vec4.x-=po->x;
				vec4.y-=po->y;
				vec4.z-=po->z;

				//距離や幅計算
				dis=dotpro3(Muki.x,Muki.y,Muki.z,vec4.x,vec4.y,vec4.z);
//				dis=D3DXVec3Length(&D3DXVECTOR3(vec4.x,vec4.y,vec4.z));



				//カリング
				WorkMuki=Muki;
				changedistance3(&WorkMuki.x,&WorkMuki.y,&WorkMuki.z,dis);
				width=distance3(WorkMuki.x-vec4.x,WorkMuki.y-vec4.y,WorkMuki.z-vec4.z);
				ballwidth=MeshR[i]/cosf(fovy/2*rad);//カメラからボールがちょうど見えなくなる位置を求めるために使う
				camerawidth=dis*tanf(fovy/2*rad);

				if(width-ballwidth>camerawidth)
				{
					//次のメッシュへ
					continue;

				}

			}





			for(k=0;k<MeshMaterialCount[i];k++)
			{




				//レンダリングステージなどの設定

				//テクスチャの枚数分ループ
				for(l=0;l<TextureMultiCount[MeshTextureIndex[i][k]];l++)
				{


					D3DXMATRIX mat;
					D3DXMATRIX mat2;

					D3DXMatrixIdentity(&mat);
					D3DXMatrixIdentity(&mat2);

					//移動
					mat._31 = UVTranslationX[TextureIndex[MeshTextureIndex[i][k]]+l];
					mat._32 = UVTranslationY[TextureIndex[MeshTextureIndex[i][k]]+l];

					//回転
					float	cosans, sinans;
					cosans = cosf(UVRotation[TextureIndex[MeshTextureIndex[i][k]]+l]*rad);
					sinans = sinf(UVRotation[TextureIndex[MeshTextureIndex[i][k]]+l]*rad);
					mat._11 = mat._22 = cosans;
					mat._12 = sinans;
					mat._21 =-sinans;

					//拡大
					mat2._11=UVScalingX[TextureIndex[MeshTextureIndex[i][k]]+l];
					mat2._22=UVScalingY[TextureIndex[MeshTextureIndex[i][k]]+l];

//							D3DXMatrixScaling(&mat2,0.1f,0.1f,0.1f);


					mat*=mat2;


					device->SetTransform( (_D3DTRANSFORMSTATETYPE)(D3DTS_TEXTURE0+l), &mat );
					device->SetTextureStageState( l, D3DTSS_TEXCOORDINDEX, 0  );




					device->SetTextureStageState( l, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_COUNT2 );

					device->SetTextureStageState( l, D3DTSS_COLORARG1, ColorArg1[TextureIndex[MeshTextureIndex[i][k]]+l] );
					device->SetTextureStageState( l, D3DTSS_COLORARG2, ColorArg2[TextureIndex[MeshTextureIndex[i][k]]+l] );
					device->SetTextureStageState( l, D3DTSS_COLOROP,   ColorOpereter[TextureIndex[MeshTextureIndex[i][k]]+l] );

					device->SetTextureStageState( l, D3DTSS_ALPHAARG1, AlphaArg1[TextureIndex[MeshTextureIndex[i][k]]+l] );
					device->SetTextureStageState( l, D3DTSS_ALPHAARG2, AlphaArg2[TextureIndex[MeshTextureIndex[i][k]]+l] );
					device->SetTextureStageState( l, D3DTSS_ALPHAOP,   AlphaOpereter[TextureIndex[MeshTextureIndex[i][k]]+l] );

					device->SetTexture( l, Texture[TextureIndex[MeshTextureIndex[i][k]]+l] );

				}


				//最後のテクスチャステージに環境マップ貼り付け！！
				if(EnvTexture!=NULL)
				{

					device->SetTextureStageState( l, D3DTSS_COLORARG1, D3DTA_TEXTURE );
					device->SetTextureStageState( l, D3DTSS_COLORARG2, D3DTA_CURRENT );
					device->SetTextureStageState( l, D3DTSS_COLOROP,   D3DTOP_ADD );
					device->SetTextureStageState( l, D3DTSS_ALPHAARG1,   D3DTA_CURRENT );
					device->SetTextureStageState( l, D3DTSS_ALPHAOP,   D3DTOP_SELECTARG1 );
					device->SetTransform( (_D3DTRANSFORMSTATETYPE)(D3DTS_TEXTURE0+l), &EnvMatrix );
					if(Reflection)
						device->SetTextureStageState( l, D3DTSS_TEXCOORDINDEX, D3DTSS_TCI_CAMERASPACEREFLECTIONVECTOR  );
					else
						device->SetTextureStageState( l, D3DTSS_TEXCOORDINDEX, D3DTSS_TCI_CAMERASPACENORMAL  );
					device->SetTextureStageState( l, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_COUNT2 );
					device->SetTexture( l, *EnvTexture );
					l++;
				}



				device->SetTextureStageState( l, D3DTSS_COLOROP,   D3DTOP_DISABLE );
				device->SetTextureStageState( l, D3DTSS_ALPHAOP,   D3DTOP_DISABLE );


//						device->SetRenderState( D3DRS_TEXTUREFACTOR ,Factor[TextureIndex[MeshTextureIndex[i+j][k]]+l]);




				//マテリアルセットし、レンダリング
				device->SetMaterial( &Material[MeshMaterialIndex[i][k]] );
//				if(PMesh[i]!=NULL && progressive)
//				{
////							int vmin=PMesh[i]->GetMinVertices(),vmax=PMesh[i]->GetMaxVertices();
////							float rat=1.0f-(dis-MeshR[i])/MeshDistance[i];
////							if(rat<0) rat=0;
////							else if(rat>1) rat=1;
//////							float ans=rat;
//////							rat=powf(rat,100);
//////							for(j=0;j<7;j++)
//////								rat*=rat;
////							int vnum=(int)((float)vmin+(float)(vmax-vmin)*rat);
////							if(vnum<vmin) vnum=vmin;
////							else if(vnum>vmax) vnum=vmax;
////							PMesh[i]->SetNumVertices(vnum);
//					PMesh[i]->DrawSubset( k );
//				}
//				else
				{
					Mesh[i]->DrawSubset( k );
				}







			}

		}



		device->SetTextureStageState( 1, D3DTSS_COLOROP,   D3DTOP_DISABLE );
		device->SetTextureStageState( 1, D3DTSS_ALPHAOP,   D3DTOP_DISABLE );


	}

}


void MeshClass::Release()
{
	int i;

	//メッシュ開放
	for(i=0;i<MeshCount;i++)
	{
		if(Mesh[i]!=NULL)
		{
			Mesh[i]->Release();
			Mesh[i]=NULL;
		}

	}

	//テクスチャ開放
	for(i=0;i<TextureCount;i++)
	{
		if(KeepTexture[i]!=NULL)
		{
			KeepTexture[i]->Release();
			Texture[i]=NULL;
			KeepTexture[i]=NULL;
		}
	}

}




//これらの関数はテクスチャやマテリアル変更したりしたい時用

void MeshClass::SetMaterial( D3DMATERIAL8 *Mat, int Num )
{
	if( Num >= 0 && Num < MaterialCount)
		Material[Num]=*Mat;
}

void MeshClass::GetMaterial( D3DMATERIAL8 *Mat, int Num )
{
	if( Num >= 0 && Num < MaterialCount)
		*Mat=Material[Num];
}



void MeshClass::SetTexture( LPDIRECT3DTEXTURE8 Tex, int Num )
{
	if( Num >= 0 && Num < TextureCount)
	{
		Texture[Num]=Tex;
	}
}

void MeshClass::GetTexture( LPDIRECT3DTEXTURE8 Tex, int Num )
{
	if( Num >= 0 && Num < TextureCount)
	{
		Tex=Texture[Num];
	}
}







bool MeshClass::MaterialCmp( D3DMATERIAL8* mat1,D3DMATERIAL8* mat2)
{
	return	(mat1->Diffuse.a==mat2->Diffuse.a) && (mat1->Diffuse.r==mat2->Diffuse.r) && (mat1->Diffuse.g==mat2->Diffuse.g) && (mat1->Diffuse.b==mat2->Diffuse.b) && 
			(mat1->Emissive.a==mat2->Emissive.a) && (mat1->Emissive.r==mat2->Emissive.r) && (mat1->Emissive.g==mat2->Emissive.g) && (mat1->Emissive.b==mat2->Emissive.b) && 
			(mat1->Specular.a==mat2->Specular.a) && (mat1->Specular.r==mat2->Specular.r) && (mat1->Specular.g==mat2->Specular.g) && (mat1->Specular.b==mat2->Specular.b) && 
			(mat1->Power==mat2->Power);

}


void MeshClass::PathDiv( char* file, char* path, char* name, char* kakutyousi)
{
	int i,j;

	//パスとファイル名を求める(最後の文字から一番近い/を探す)
	strcpy(path,file);
	strcpy(name,file);
	for(i=(int)strlen(file)-1;i>=0;i--)
		if(file[i]=='/')
		{
			//パス
			path[i+1]='\0';

			//ファイル名
			for(j=i+1;j<=(int)strlen(file);j++)
				name[j-(i+1)]=name[j];

			goto Jump;
		}

	//スラッシュが見つからなかった!!
	strcpy(path,"");

Jump:;

	//拡張子を求める(最後の文字から一番近い/を探す)
	strcpy(kakutyousi,file);
	for(i=(int)strlen(file)-1;i>=0;i--)
		if(file[i]=='.')
		{
			//拡張子
			for(j=i;j<=(int)strlen(file);j++)
				kakutyousi[j-i]=kakutyousi[j];

			//nameの拡張子を消す
			name[(int)strlen(name)-((int)strlen(file)-i)]='\0';
		}
}






int MeshClass::TexNameIndex( char *filename )//ファイル名のみ記述する（パスなし、拡張子あり）※そのファイル名が存在しない場合-1を返す
{
	if(!Created) return -1;

	for(int i=0;i<TextureCount;i++)
	{
//		MessageBox(NULL,TextureFileName[i],"",MB_OK);
		if(stricmp(filename,TextureFileName[i])==0) return i;
	}

	return -1;
}








//とりあえずあとでいい
//
//bool MeshClass::SetFVF( LPDIRECT3DDEVICE8 device, DWORD FVF, int MeshNum )
//{
//    LPD3DXMESH TempMesh = NULL;
//
//	if(MeshNum!=-1)
//	{
//	
//		//メッシュのフォーマットを変更
//		if( FAILED( Mesh[MeshNum]->CloneMeshFVF( D3DXMESH_MANAGED, FVF,
//													device, &TempMesh ) ) )
//			return false;
//
//		Mesh[MeshNum]->Release();
//		Mesh[MeshNum] = TempMesh;
//
//
//		//法線情報のないメッシュに法線情報をつける時用に法線の算出をする
//		D3DXComputeNormals( Mesh[MeshNum], NULL );
//
//	}
//	else
//	{
//
//		int i;
//		for(i=0;i<MeshCount;i++)
//		{
//	
//			//メッシュのフォーマットを変更
//			if( FAILED( Mesh[i]->CloneMeshFVF( D3DXMESH_MANAGED, FVF,
//														device, &TempMesh ) ) )
//				return false;
//
//			Mesh[i]->Release();
//			Mesh[i] = TempMesh;
//
//
//			//法線情報のないメッシュに法線情報をつける時用に法線の算出をする
//			D3DXComputeNormals( Mesh[i], NULL );
//
//		}
//
//	}
//
//    return true;
//}
//
//
//


