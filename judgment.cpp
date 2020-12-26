#include "Judgment.h"

#include <stdio.h>
#include "mathematic.h"

JudClass::JudClass()
{
	loaded=false;
}

int JudClass::CreateJudFile(LPDIRECT3DDEVICE8 device,char JudFileName[MAX_PATH],char XFileName[MAX_PATH],int cutx,int cuty,int cutz)
{

	loaded=false;



	//Xファイルを読み込む

	LPD3DXMESH Mesh = NULL;
	DWORD NumMaterials;
    LPD3DXBUFFER D3DXMtrlBuffer;

    if( FAILED( D3DXLoadMeshFromX( XFileName, D3DXMESH_SYSTEMMEM, device, NULL, &D3DXMtrlBuffer, &NumMaterials, &Mesh ) ) )
    {
        return false;
    }

	//位置情報のみ使用
    Mesh->CloneMeshFVF( 0L, D3DFVF_XYZ, device, &Mesh );




	//点を読み込み

	LPDIRECT3DVERTEXBUFFER8 pVB;
	LPDIRECT3DINDEXBUFFER8  pIB;

	Mesh->GetVertexBuffer( &pVB );
	Mesh->GetIndexBuffer( &pIB );

	WORD*			indexbuffer;
	D3DXVECTOR3*    vertexbuffer;
	DWORD* attribuffer;

	pIB->Lock( 0,0,(BYTE**)&indexbuffer, 0 );
	pVB->Lock( 0,0,(BYTE**)&vertexbuffer, 0 );
	Mesh->LockAttributeBuffer( 0, &attribuffer );



	int i,j,k,x,y,z;	//ループ用変数
	bool ok;	//条件判断用変数

	//カウンタ初期化
	tricount=polcount=sphcount=0;


	D3DXVECTOR3 spos[3];//各頂点の位置を格納する変数(sphposition)
	int sindex[3];//各頂点に与えられるインデックスを格納する(sphindex)
	int pindex[3];//各辺に与えられるインデックスを格納する(polindex)



	//作業用に大きめに確保
	tri=new TriangleStruct[200000];
	pol=new PoleStruct[200000];
	sph=new SphereStruct[200000];



	//三角形ポリゴンループ
	for( i=0; i < (int)(Mesh->GetNumFaces()); i++ )
	{



		//ポリゴン(三角形)の各頂点の位置を設定
		for(j=0;j<3;j++)
			spos[j]=vertexbuffer[indexbuffer[3*i+j]];


		//球の作成(作成された球のインデックスはsindex[]に格納する)
		{





			//それぞれの頂点で、同じ位置の球がないかを調べながら球を作り、sindex[]を設定する
			for(j=0;j<3;j++)
			{

				ok=true;	//新しい球の作成を許可する


				for(k=0;k<sphcount;k++)//球ループ
				{
					if(spos[j]==sph[k].p)//同じ位置の球発見！
					{
						ok=false;	//新しい球の作成を拒否する
						break;
					}
				}



				if(ok==false)
				{
					//この球はすでに存在するので、その点と同じインデックスとなる(上書きされる)
					sindex[j]=k;
					if(sph[k].kind>(int)attribuffer[i])
						sph[k].kind=(short int)attribuffer[i];
				}
				else
				{
					//この球はまだ作られていないので、新しく作る
					sph[sphcount].p=spos[j];
					sph[sphcount].kind=(short int)attribuffer[i];
					sindex[j]=sphcount;
					sphcount++;
				}
				
				
			}






		}
		//円柱の作成(sindex[]を使う。作成された円柱のインデックスは、pindex[]に格納する)
		{





			//それぞれの円柱で、同じ位置のがないかを調べながら円柱を作り、pindex[]を設定する
			//(pindex[0]は、sindex[0]～sindex[1]の間の柱をあらわす)


			int ato;	//ato は、円柱の後方の球をあらわすのに使う


			for(j=0;j<3;j++)
			{

				//atoの設定(これで、この円柱の元と先の球のインデックスが、sindex[j]～sindex[ato]と、きまる！)
				ato=j+1;
				if(ato>=3)ato=0;


				ok=true;	//新しい円柱の作成を許可する


				for(k=0;k<polcount;k++)//円柱ループ
				{
					//同じ円柱があるかを調べるには、同じインデックスの球を頂点とする柱を探す)
					if(	(sindex[j]==pol[k].csph[0] || sindex[j]==pol[k].csph[1]) && 
						(sindex[ato]==pol[k].csph[0] || sindex[ato]==pol[k].csph[1]))//同じ位置の円柱発見！
					{
						ok=false;	//新しい円柱の作成を拒否する
						break;
					}
				}



				if(ok==false)
				{
					//この円柱はすでに存在するので、その円柱と同じインデックスとなる(上書きされる)
					pindex[j]=k;
					if(pol[k].kind>(int)attribuffer[i])
						pol[k].kind=(short int)attribuffer[i];
				}
				else
				{
					//この円柱はまだ作られていないので、新しく作る
					pol[polcount].csph[0]=sindex[j];
					pol[polcount].csph[1]=sindex[ato];
					pol[polcount].kind=(short int)attribuffer[i];
					pindex[j]=polcount;
					polcount++;
				}


			}






		}
		//三角形の作成(sindex[],pindex[]を使う)
		{



			//同じ三角形がすでに作られていないかを調べて、三角形を作成する
			

			ok=true;//新しい三角形の作成を許可する


			for(j=0;j<tricount;j++)
			{
				//同じ三角形があるかを調べるには、同じインデックスの球を頂点とする三角形を探す

				if(	(sindex[0]==tri[j].csph[0] || sindex[0]==tri[j].csph[1] || sindex[0]==tri[j].csph[2]) && 
					(sindex[1]==tri[j].csph[0] || sindex[1]==tri[j].csph[1] || sindex[1]==tri[j].csph[2]) && 
					(sindex[2]==tri[j].csph[0] || sindex[2]==tri[j].csph[1] || sindex[2]==tri[j].csph[2]))//同じ位置の三角形発見!
				{
					ok=false;	//新しい三角形の作成を拒否する
					break;
				}
			}


			if(ok==false)
			{
				//この三角形はすでに作られているので、種類だけ確認する
				if(tri[k].kind>(int)attribuffer[i])
					tri[k].kind=(short int)attribuffer[i];
			}
			else
			{
				//この三角形はまだ作られていないので、新しく作る
				tri[tricount].csph[0]=sindex[0];
				tri[tricount].csph[1]=sindex[1];
				tri[tricount].csph[2]=sindex[2];
				tri[tricount].cpol[0]=pindex[0];
				tri[tricount].cpol[1]=pindex[1];
				tri[tricount].cpol[2]=pindex[2];



				//後で行う三角形のマトリックス計算時に三角形の辺0(点0～点1)のデータを使うので、
				//三角形の点(0～1)と辺0の点(0～1)の点のインデックスが同じでなければならない

				int w;//数値入れ替え用変数


				if(tri[i].csph[0]!=pol[tri[i].cpol[0]].csph[0])//違ってたら
				{
					//三角形の球インデックスを入れ替える(0と1)
					w=tri[i].csph[0];
					tri[i].csph[0]=tri[i].csph[1];
					tri[i].csph[1]=w;

					//入れ替えた２点間の辺以外の辺インデックスも入れ替える！(1と2)
					w=tri[i].cpol[1];
					tri[i].cpol[1]=tri[i].cpol[2];
					tri[i].cpol[2]=w;
				}

				tri[tricount].kind=(short int)attribuffer[i];

				tricount++;
			}
		}


	}


	pVB->Unlock();
	pIB->Unlock();
	pVB->Release();
	pIB->Release();
	Mesh->UnlockAttributeBuffer();







	//Boxの設定
	//Boxは、判定するポリゴンをできる限り減らすために考えたあり後リズムで、
	//あるボックスに入っているときはそのボックスのポリゴンとノ判定を行うというもの

	if(cutx<1)cutx=1;
	if(cuty<1)cuty=1;
	if(cutz<1)cutz=1;
	if(cutx>BOX_X_MAX)cutx=BOX_X_MAX;
	if(cuty>BOX_Y_MAX)cuty=BOX_Y_MAX;
	if(cutz>BOX_Z_MAX)cutz=BOX_Z_MAX;

	box.cutx=cutx;
	box.cuty=cuty;
	box.cutz=cutz;


	//一番小さいx,y,zと、一番大きいx,y,zを求めてboxmin,boxmaxに格納
	box.min=box.max=sph[0].p;

	for(i=0;i<sphcount;i++)
	{
		if(box.min.x>sph[i].p.x)
			box.min.x=sph[i].p.x;
		if(box.min.y>sph[i].p.y)
			box.min.y=sph[i].p.y;
		if(box.min.z>sph[i].p.z)
			box.min.z=sph[i].p.z;

		if(box.max.x<sph[i].p.x)
			box.max.x=sph[i].p.x;
		if(box.max.y<sph[i].p.y)
			box.max.y=sph[i].p.y;
		if(box.max.z<sph[i].p.z)
			box.max.z=sph[i].p.z;
	}


	//念のため・・・
	box.max.x+=1;
	box.max.y+=1;
	box.max.z+=1;
	box.min.x-=1;
	box.min.y-=1;
	box.min.z-=1;



	//三角形がboxの中に含むかをしらべ、含むならそのインデックスを格納(各boxについて調べる)

	//box中心座標とサイズ格納変数(サイズは、box中心座標から直方体の頂点までの、成分が正のベクトル)
	D3DXVECTOR3 boxp,boxs=D3DXVECTOR3(	(box.max.x-box.min.x)/box.cutx/2,
										(box.max.y-box.min.y)/box.cuty/2,
										(box.max.z-box.min.z)/box.cutz/2);


	D3DXVECTOR3 dvec[3],tvec[3];//作業用ベクトル(dvecはアドレス渡し用,tvecは座標移動)


	//※zが0のときにバグが出る！！

	for(x=0;x<box.cutx;x++)
	{
		boxp.x=box.min.x+boxs.x+x*boxs.x*2;

		for(y=0;y<box.cuty;y++)
		{
			boxp.y=box.min.y+boxs.y+y*boxs.y*2;

			for(z=0;z<box.cutz;z++)
			{
				boxp.z=box.min.z+boxs.z+z*boxs.z*2;


				//ボックスインデックスカウンタ初期化
				box.count[x][y][z]=0;

				//三角形ループ
				for(i=0;i<tricount;i++)
				{

					ok=false;


					//tvecにsph[tri[].csph[]].pのbox座標を格納
					for(j=0;j<3;j++)
					{
						tvec[j]=sph[tri[i].csph[j]].p-boxp;
					}
					
					
					//①各点がboxの中にあるか調べる
					for(j=0;j<3;j++)
					{
						if(	tvec[j].x<=boxs.x && tvec[j].x>=-boxs.x && 
							tvec[j].y<=boxs.y && tvec[j].y>=-boxs.y && 
							tvec[j].z<=boxs.z && tvec[j].z>=-boxs.z)
						{
							ok=true;
						}
					}

					//②三角形の各辺が直方体の各面に触れているかを調べる
					{


						//+Y
						if(ok==false)
						{
							for(j=0;j<3;j++)
							{
								dvec[j].x=tvec[j].x;
								dvec[j].y=tvec[j].y-boxs.y;
								dvec[j].z=tvec[j].z;
							}

							ok=	rectlinejud(&dvec[0],&dvec[1],boxs.x,boxs.z) ||
								rectlinejud(&dvec[1],&dvec[2],boxs.x,boxs.z) ||
								rectlinejud(&dvec[2],&dvec[0],boxs.x,boxs.z);
						}

						//-Y
						if(ok==false)
						{
							for(j=0;j<3;j++)
							{
								dvec[j].x=tvec[j].x;
								dvec[j].y=tvec[j].y+boxs.y;
								dvec[j].z=tvec[j].z;
							}

							ok=	rectlinejud(&dvec[0],&dvec[1],boxs.x,boxs.z) ||
								rectlinejud(&dvec[1],&dvec[2],boxs.x,boxs.z) ||
								rectlinejud(&dvec[2],&dvec[0],boxs.x,boxs.z);
						}

						//+X
						if(ok==false)
						{

							for(j=0;j<3;j++)
							{
								dvec[j].x=tvec[j].y;
								dvec[j].y=tvec[j].x-boxs.x;
								dvec[j].z=tvec[j].z;
							}

							ok=	rectlinejud(&dvec[0],&dvec[1],boxs.y,boxs.z) ||
								rectlinejud(&dvec[1],&dvec[2],boxs.y,boxs.z) ||
								rectlinejud(&dvec[2],&dvec[0],boxs.y,boxs.z);
						}

						//-X
						if(ok==false)
						{
							for(j=0;j<3;j++)
							{
								dvec[j].x=tvec[j].y;
								dvec[j].y=tvec[j].x+boxs.x;
								dvec[j].z=tvec[j].z;
							}

							ok=	rectlinejud(&dvec[0],&dvec[1],boxs.y,boxs.z) ||
								rectlinejud(&dvec[1],&dvec[2],boxs.y,boxs.z) ||
								rectlinejud(&dvec[2],&dvec[0],boxs.y,boxs.z);
						}


						//+Z
						if(ok==false)
						{
							for(j=0;j<3;j++)
							{
								dvec[j].x=tvec[j].x;
								dvec[j].y=tvec[j].z-boxs.z;
								dvec[j].z=tvec[j].y;
							}

							ok=	rectlinejud(&dvec[0],&dvec[1],boxs.x,boxs.y) ||
								rectlinejud(&dvec[1],&dvec[2],boxs.x,boxs.y) ||
								rectlinejud(&dvec[2],&dvec[0],boxs.x,boxs.y);
						}

						//-Z
						if(ok==false)
						{
							for(j=0;j<3;j++)
							{
								dvec[j].x=tvec[j].x;
								dvec[j].y=tvec[j].z+boxs.z;
								dvec[j].z=tvec[j].y;
							}

							ok=	rectlinejud(&dvec[0],&dvec[1],boxs.x,boxs.y) ||
								rectlinejud(&dvec[1],&dvec[2],boxs.x,boxs.y) ||
								rectlinejud(&dvec[2],&dvec[0],boxs.x,boxs.y);
						}

					}

					//③直方体の各辺が三角形の各面に触れているかを調べる
					{
						//+X+Z
						if(ok==false)
						{
							for(j=0;j<3;j++)
							{
								dvec[j].x=tvec[j].x-boxs.x;
								dvec[j].y=tvec[j].y;
								dvec[j].z=tvec[j].z-boxs.z;
							}

							ok=	trilinejud(&dvec[0],&dvec[1],&dvec[2],boxs.y);
						}

						//+X-Z
						if(ok==false)
						{
							for(j=0;j<3;j++)
							{
								dvec[j].x=tvec[j].x-boxs.x;
								dvec[j].y=tvec[j].y;
								dvec[j].z=tvec[j].z+boxs.z;
							}

							ok=	trilinejud(&dvec[0],&dvec[1],&dvec[2],boxs.y);
						}

						//-X+Z
						if(ok==false)
						{
							for(j=0;j<3;j++)
							{
								dvec[j].x=tvec[j].x+boxs.x;
								dvec[j].y=tvec[j].y;
								dvec[j].z=tvec[j].z-boxs.z;
							}

							ok=	trilinejud(&dvec[0],&dvec[1],&dvec[2],boxs.y);
						}

						//-X-Z
						if(ok==false)
						{
							for(j=0;j<3;j++)
							{
								dvec[j].x=tvec[j].x+boxs.x;
								dvec[j].y=tvec[j].y;
								dvec[j].z=tvec[j].z+boxs.z;
							}

							ok=	trilinejud(&dvec[0],&dvec[1],&dvec[2],boxs.y);
						}


						//+Y+X
						if(ok==false)
						{
							for(j=0;j<3;j++)
							{
								dvec[j].x=tvec[j].x-boxs.x;
								dvec[j].y=tvec[j].z;
								dvec[j].z=tvec[j].y-boxs.y;
							}

							ok=	trilinejud(&dvec[0],&dvec[1],&dvec[2],boxs.z);
						}

						//+Y-X
						if(ok==false)
						{
							for(j=0;j<3;j++)
							{
								dvec[j].x=tvec[j].x+boxs.x;
								dvec[j].y=tvec[j].z;
								dvec[j].z=tvec[j].y-boxs.y;
							}

							ok=	trilinejud(&dvec[0],&dvec[1],&dvec[2],boxs.z);
						}

						//-Y+X
						if(ok==false)
						{
							for(j=0;j<3;j++)
							{
								dvec[j].x=tvec[j].x-boxs.x;
								dvec[j].y=tvec[j].z;
								dvec[j].z=tvec[j].y+boxs.y;
							}

							ok=	trilinejud(&dvec[0],&dvec[1],&dvec[2],boxs.z);
						}

						//-Y-X
						if(ok==false)
						{
							for(j=0;j<3;j++)
							{
								dvec[j].x=tvec[j].x+boxs.x;
								dvec[j].y=tvec[j].z;
								dvec[j].z=tvec[j].y+boxs.y;
							}

							ok=	trilinejud(&dvec[0],&dvec[1],&dvec[2],boxs.z);
						}


						//+Y+Z
						if(ok==false)
						{
							for(j=0;j<3;j++)
							{
								dvec[j].x=tvec[j].y-boxs.y;
								dvec[j].y=tvec[j].x;
								dvec[j].z=tvec[j].z-boxs.z;
							}

							ok=	trilinejud(&dvec[0],&dvec[1],&dvec[2],boxs.x);
						}

						//+Y-Z
						if(ok==false)
						{
							for(j=0;j<3;j++)
							{
								dvec[j].x=tvec[j].y-boxs.y;
								dvec[j].y=tvec[j].x;
								dvec[j].z=tvec[j].z+boxs.z;
							}

							ok=	trilinejud(&dvec[0],&dvec[1],&dvec[2],boxs.x);
						}

						//-Y+Z
						if(ok==false)
						{
							for(j=0;j<3;j++)
							{
								dvec[j].x=tvec[j].y+boxs.y;
								dvec[j].y=tvec[j].x;
								dvec[j].z=tvec[j].z-boxs.z;
							}

							ok=	trilinejud(&dvec[0],&dvec[1],&dvec[2],boxs.x);
						}

						//-Y-Z
						if(ok==false)
						{
							for(j=0;j<3;j++)
							{
								dvec[j].x=tvec[j].y+boxs.y;
								dvec[j].y=tvec[j].x;
								dvec[j].z=tvec[j].z+boxs.z;
							}

							ok=	trilinejud(&dvec[0],&dvec[1],&dvec[2],boxs.x);
						}

					}


					if(ok==true)
					{
						//この三角形を、このboxのインデックスリストに追加
						box.index[x][y][z][box.count[x][y][z]]=i;
						box.count[x][y][z]++;
					}

				}






			}
		}
	}








	//ファイルへの出力
	FILE* file;
	if((file=fopen(JudFileName,"w"))==NULL)
		return false;

	//球の数と種類と位置
	fprintf(file,"%d\n",sphcount);
	for(i=0;i<sphcount;i++)
	{
		fprintf(file,"%d\n",sph[i].kind);
		fprintf(file,"%f,%f,%f\n",sph[i].p.x,sph[i].p.y,sph[i].p.z);
	}

	//柱の数と種類と頂点の球インデックス
	fprintf(file,"%d\n",polcount);
	for(i=0;i<polcount;i++)
	{
		fprintf(file,"%d\n",pol[i].kind);
		fprintf(file,"%d,%d\n",pol[i].csph[0],pol[i].csph[1]);
	}

	//三角形の数と種類と頂点の球インデックスと辺の柱インデックス
	fprintf(file,"%d\n",tricount);
	for(i=0;i<tricount;i++)
	{
		fprintf(file,"%d\n",tri[i].kind);
		fprintf(file,"%d,%d,%d,%d,%d,%d\n",
				tri[i].csph[0],tri[i].csph[1],tri[i].csph[2],
				tri[i].cpol[0],tri[i].cpol[1],tri[i].cpol[2]);
	}
	
	//boxの分割数
	fprintf(file,"%d,%d,%d\n",box.cutx,box.cuty,box.cutz);

	//boxのminとmax
	fprintf(file,"%f,%f,%f\n",box.min.x,box.min.y,box.min.z);
	fprintf(file,"%f,%f,%f\n",box.max.x,box.max.y,box.max.z);

	//boxのcountとindex
	for(z=0;z<box.cutz;z++)
		for(y=0;y<box.cuty;y++)
			for(x=0;x<box.cutx;x++)
			{
				fprintf(file,"%d\n",box.count[x][y][z]);
				for(i=0;i<box.count[x][y][z];i++)
					fprintf(file,"%d\n",box.index[x][y][z][i]);
			}


	fclose(file);


	return true; 



}

int JudClass::LoadJudFile(char JudFileName[MAX_PATH])
{

	int i,x,y,z;



	//点を読み込む

	FILE* file; 
	if((file=fopen(JudFileName,"r"))==NULL)
		return false;

	//球の数と位置
	fscanf(file,"%d",&sphcount);
	sph=new SphereStruct[sphcount];
	for(i=0;i<sphcount;i++)
	{
		fscanf(file,"%d",&sph[i].kind);
		fscanf(file,"%f,%f,%f",&sph[i].p.x,&sph[i].p.y,&sph[i].p.z);
	}

	//柱の数と頂点の球インデックス
	fscanf(file,"%d",&polcount);
	pol=new PoleStruct[polcount];
	for(i=0;i<polcount;i++)
	{
		fscanf(file,"%d",&pol[i].kind);
		fscanf(file,"%d,%d",&pol[i].csph[0],&pol[i].csph[1]);
	}

	//三角形の頂点の球インデックスと辺の柱インデックス
	fscanf(file,"%d",&tricount);
	tri=new TriangleStruct[tricount];
	for(i=0;i<tricount;i++)
	{
		fscanf(file,"%d",&tri[i].kind);
		fscanf(file,"%d,%d,%d,%d,%d,%d",
				&tri[i].csph[0],&tri[i].csph[1],&tri[i].csph[2],
				&tri[i].cpol[0],&tri[i].cpol[1],&tri[i].cpol[2]);
	}

	//boxの分割数
	fscanf(file,"%d,%d,%d",&box.cutx,&box.cuty,&box.cutz);

	//boxのminとmax
	fscanf(file,"%f,%f,%f",&box.min.x,&box.min.y,&box.min.z);
	fscanf(file,"%f,%f,%f",&box.max.x,&box.max.y,&box.max.z);




	//boxのcountとindex
	for(z=0;z<box.cutz;z++)
	{
		for(y=0;y<box.cuty;y++)
		{
			for(x=0;x<box.cutx;x++)
			{
				fscanf(file,"%d",&box.count[x][y][z]);

				for(i=0;i<box.count[x][y][z];i++)
					fscanf(file,"%d",&box.index[x][y][z][i]);
			}
		}
	}


	fclose(file);






	//char str[100];
	//sprintf(str,"%d",box.count[4][0][0]);
	//MessageBox(hWnd,str,"",0);




	//点の位置から、マトリックスや、変換後の座標など、高速計算の準備

	float ang,dot;
	D3DXMATRIX mat;
	D3DXVECTOR3 yvec=D3DXVECTOR3(0,1,0),pvec;//yvecはyじくを単位ベクトルにしてあらわしたもの。pvecは、円柱の終点をローカル座標で表す時に使う







	//円柱について
	for(i=0;i<polcount;i++)
	{
		//円柱の終点のローカル座標を格納
		pvec=sph[pol[i].csph[1]].p-sph[pol[i].csph[0]].p;


		//円柱の長さ
		pol[i].h=D3DXVec3Length(&pvec);


		//円柱の座標変換マトリックス
		{
			//円柱の始点が原点となるように移動する行列
			D3DXMatrixTranslation(&pol[i].mat,-sph[pol[i].csph[0]].p.x,-sph[pol[i].csph[0]].p.y,-sph[pol[i].csph[0]].p.z);

			//単位行列作成
			D3DXMatrixIdentity(&mat);

			//pvecの角度を上から見てしらべる
			ang=angle(pvec.x,pvec.z);
			D3DXMatrixRotationY(&mat,ang*rad);//上から見て時計回りにang°まわす行列


			//行列の掛け算
			pol[i].mat*=mat;

			//円柱がY軸から何度傾いているかを調べる

			//y軸と円柱のベクトルの内積を調べる
			dot=D3DXVec3Dot(&yvec,&pvec);
			//内積よりベクトル間の角度を求める
			ang=acosf(dot/pol[i].h)*deg;
			D3DXMatrixRotationZ(&mat,ang*rad);//正面(-Z)から見て反時計回りにang°まわす行列

			//行列の掛け算
			pol[i].mat*=mat;

			////逆行列を求める
			//D3DXMatrixInverse(&pol[i].dmat,NULL,&pol[i].mat);

		}


		
	}









	D3DXVECTOR4 vec4;//マトリックスとの掛け算の結果を格納する変数

	//作業用変数
	float dis,ang2,ang3;

	//三角形について
	for(i=0;i<tricount;i++)
	{
		//三角形の座標変換マトリックス
		{

			//点3を辺0のマトリックスにかける
			D3DXVec3Transform(&vec4,&sph[tri[i].csph[2]].p,&pol[tri[i].cpol[0]].mat);

			//座標変換後の点3を上から見た角度を調べる
			ang=angle(vec4.x,vec4.z);
			D3DXMatrixRotationY(&tri[i].mat,ang*rad);//上から見て時計回りにang°まわす行列

			//行列の掛け算
			tri[i].mat=pol[tri[i].cpol[0]].mat*tri[i].mat;

			////逆行列を求める
			//D3DXMatrixInverse(&tri[i].dmat,NULL,&tri[i].mat);

		}

		//vec4を、0°の位置に回転させたとき三角形の幅を、vec4.x,vec4.zの距離で求める
		tri[i].s.x=distance(vec4.x,vec4.z);
		tri[i].s.y=vec4.y;

		//三角形の高さに辺0のhを代入
		tri[i].h=pol[tri[i].cpol[0]].h;


		//sp[]を求める！

		//sp[]は、半径が1の円の中心が入れない三角形を、元の三角形の各点からの座標であらわしたもの。
		//(この三角形に円の中心が入らなければ、円が元の三角形に触れることはない)

		

		//点1について

		//点1の角の角度を求める(XとYが逆なところに注目)
		ang=angle(tri[i].s.y,tri[i].s.x);
		//元の点から変換後の点への距離を求める
		dis=1/sinf(ang*rad/2);

		//最終的な点の座標を求める
		tri[i].sp[0].x=sinf((ang/2+180)*rad)*dis;
		tri[i].sp[0].y=cosf((ang/2+180)*rad)*dis;
		

		//点2について

		//点2の角の角度を求める(XとYが逆なところに注目)
		ang2=angle(-tri[i].s.y+tri[i].h,tri[i].s.x);
		//元の点から変換後の点への距離を求める
		dis=1/sinf(ang2*rad/2);

		//最終的な点の座標を求める
		tri[i].sp[1].x=sinf((ang2/2+180)*rad)*dis;
		tri[i].sp[1].y=-cosf((ang2/2+180)*rad)*dis;


		//点3について

		//点3の角の角度を求める
		ang3=180-ang-ang2;
		//元の点から変換後の点への距離を求める
		dis=1/sinf(ang3*rad/2);
		
		//最終的な点の座標を求める
		tri[i].sp[2].x=-sinf((ang3/2+ang2+180)*rad)*dis;
		tri[i].sp[2].y=cosf((ang3/2+ang2+180)*rad)*dis;

	}





	//////ファイルへ出力！
	////



	//if((file=fopen("高速化.txt","w"))==NULL)
	//	return false;

	//for(i=0;i<tricount;i++)
	//{
	//	for(j=0;j<3;j++)
	//		fprintf(file,"%f,%f,%f\n",sph[tri[i].csph[j]].p.x,sph[tri[i].csph[j]].p.y,sph[tri[i].csph[j]].p.z);

	//	fprintf(file,"s.x = %f\n",tri[i].s.x);
	//	fprintf(file,"s.y = %f\n",tri[i].s.y);
	//	fprintf(file,"h   = %f\n",tri[i].h);

	//	for(j=0;j<3;j++)
	//		fprintf(file,"%f,%f\n",tri[i].sp[j].x,tri[i].sp[j].y);


	//	
	//}

	//fclose(file);











	loaded=true;


	return true;
}

int JudClass::FieldJud(bool line,float r,D3DXVECTOR3* p,D3DXVECTOR3* p2)
{
	if(loaded==true)
	{
		bool ok;
		int i,j,x,y,z;



		//boxと触れているかを調べるとき、直方体で判定するので、球体の軌道や半径などから、直方体を作る

		D3DXVECTOR3 mymin,mymax;

		if(line)
		{
			if(p->x < p2->x)
			{
				mymin.x=p->x-r;
				mymax.x=p2->x+r;
			}
			else
			{
				mymin.x=p2->x-r;
				mymax.x=p->x+r;
			}
			if(p->y < p2->y)
			{
				mymin.y=p->y-r; 
				mymax.y=p2->y+r;
			}
			else
			{
				mymin.y=p2->y-r;
				mymax.y=p->y+r;
			}
			if(p->z < p2->z)
			{
				mymin.z=p->z-r;
				mymax.z=p2->z+r;
			}
			else
			{
				mymin.z=p2->z-r;
				mymax.z=p->z+r;
			}
		}
		else
		{
			mymin.x=p->x-r;
			mymax.x=p->x+r;
			mymin.y=p->y-r;
			mymax.y=p->y+r;
			mymin.z=p->z-r;
			mymax.z=p->z+r;
		}

		//その直方体がboxのどこの範囲に含まれるかを調べる

		int boxminx=box.cutx,boxminy=box.cuty,boxminz=box.cutz,boxmaxx=-1,boxmaxy=-1,boxmaxz=-1;//調べるboxの範囲をインデックスで格納

		//X軸について調べる
		for(i=0;i<box.cutx;i++)
		{
			if(	box.min.x+(box.max.x-box.min.x)/box.cutx*(i)	<= mymax.x && 
				box.min.x+(box.max.x-box.min.x)/box.cutx*(i+1)	>= mymin.x )	//boxとmyboxがX軸上で触れているかを調べる
			{
				//minがまだ更新されていなかったら更新する
				if(boxminx==box.cutx)
					boxminx=i;

				boxmaxx=i;
			}
			else
			{
				//maxが更新済みだったらループを抜ける
				if(boxmaxx!=-1)
					break;
			}
		}

		//Y軸について調べる
		for(i=0;i<box.cuty;i++)
		{
			if(	box.min.y+(box.max.y-box.min.y)/box.cuty*(i)	<= mymax.y && 
				box.min.y+(box.max.y-box.min.y)/box.cuty*(i+1)	>= mymin.y )	//boxとmyboxがY軸上で触れているかを調べる
			{
				//minがまだ更新されていなかったら更新する
				if(boxminy==box.cuty)
					boxminy=i;

				boxmaxy=i;
			}
			else
			{
				//maxが更新済みだったらループを抜ける
				if(boxmaxy!=-1)
					break;
			}			
		}

		//Z軸について調べる
		for(i=0;i<box.cutz;i++)
		{
			if(	box.min.z+(box.max.z-box.min.z)/box.cutz*(i)	<= mymax.z && 
				box.min.z+(box.max.z-box.min.z)/box.cutz*(i+1)	>= mymin.z )	//boxとmyboxがZ軸上で触れているかを調べる
			{
				//minがまだ更新されていなかったら更新する
				if(boxminz==box.cutz)
					boxminz=i;

				boxmaxz=i;
			}
			else
			{
				//maxが更新済みだったらループを抜ける
				if(boxmaxz!=-1)
					break;
			}			
		}





		//範囲内のbox内の三角形、円柱、球のcheckをfalseにする

		for(x=boxminx;x<=boxmaxx;x++){
		for(y=boxminy;y<=boxmaxy;y++){
		for(z=boxminz;z<=boxmaxz;z++)
		{
			for(i=0;i<box.count[x][y][z];i++) 
			{
				tri[box.index[x][y][z][i]].check=false;
				for(j=0;j<3;j++)
					pol[tri[box.index[x][y][z][i]].cpol[j]].check=false;
				for(j=0;j<3;j++)
					sph[tri[box.index[x][y][z][i]].csph[j]].check=false;
			}
		}}}





		//リスト初期化
		pollistcount=0;
		sphlistcount=0;






		//範囲内のbox内の三角形の当たり判定(簡単判定と精密判定)

		int index;//変数名省略

		D3DXMATRIX dmat;//座標復元用逆行列
		D3DXVECTOR4 tvec,tvec2,tvec3;//マトリックスとの掛け算の結果を格納する変数
		D3DXVECTOR3 pvec,pvec2;//作業用ベクトル
		float w,h,h2,triz,rat;//,hx,hy;//作業用変数

		for(x=boxminx;x<=boxmaxx;x++){
		for(y=boxminy;y<=boxmaxy;y++){
		for(z=boxminz;z<=boxmaxz;z++)
		{

			for(i=0;i<box.count[x][y][z];i++)
			{

				//これにより、tri[index]という参照ができる。
				index=box.index[x][y][z][i];



				if(tri[index].check==false)
				{
					tri[index].check=true;

					//移動先の点1を三角形の座標に変換
					D3DXVec3Transform(&tvec,p,&tri[index].mat);

					if(line)
					{

						//移動元の点2を三角形の座標に変換
						D3DXVec3Transform(&tvec2,p2,&tri[index].mat);


						//すべての辺を外側へ1拡大した座標の点が原点に来るように移動
						pvec.x=tvec.x-tri[index].sp[0].x*r;
						pvec.y=tvec.y-tri[index].sp[0].y*r;
						pvec.z=tvec.z;
						pvec2.x=tvec2.x-tri[index].sp[0].x*r;
						pvec2.y=tvec2.y-tri[index].sp[0].y*r;
						pvec2.z=tvec2.z;

						//拡大後の三角形の三角形の情報を変数に格納
						w=tri[index].s.x+tri[index].sp[2].x*r-tri[index].sp[0].x*r;
						h=tri[index].h+tri[index].sp[1].y*r-tri[index].sp[0].y*r;

						//三角形の点3がX軸につくように、pvec,pvec2をせんだん
						h2=tri[index].s.y+tri[index].sp[2].y*r-tri[index].sp[0].y*r;//拡大後の点3のY座標をh2に格納
						pvec.y-=(h2)*(pvec.x/w);
						pvec2.y-=(h2)*(pvec2.x/w);
						

						ok=true;

						//範囲テスト
						{

							//Z軸テスト
							if(pvec.z<=-r && pvec2.z<=-r)
								ok=false;
							if(pvec.z>=r && pvec2.z>=r)
								ok=false;

							//X軸テスト
							if(pvec.x<=0 && pvec2.x<=0)
								ok=false;
							if(pvec.x>=w && pvec2.x>=w)
								ok=false;
							
							//Y軸テスト
							if(pvec.y<=0 && pvec2.y<=0)
								ok=false;
							if(pvec.y>=h && pvec2.y>=h)
								ok=false;

						}



						if(ok)
						{
							//軌道と三角柱との簡単判定


							//tvec.zが食い込んでいたら外へ戻す
							if(tvec.z<r && tvec.z>=0)
								tvec.z=r;
							else if(tvec.z>-r && tvec.z<0)
								tvec.z=-r;

							//三角形の幅、高さが1になるように点を縮小(さっきのデータを引き継いで検査する)
							pvec.x/=w;
							pvec.y/=h;
							pvec2.x/=w;
							pvec2.y/=h;

							ok=false;



							//三角柱と触れているかのテスト


							//①その三角形の(高さ1,幅1の直角三角形)なかに点があるかを調べる
							if(pvec.x+pvec.y<=1 && pvec.x>=0 && pvec.y>=0)
								ok=true;
							if(pvec2.x+pvec2.y<=1 && pvec2.x>=0 && pvec2.y>=0)
								ok=true;


							//②2枚の三角形とテスト(未完成)

							if(!ok)
							{

								////調べる三角形のZ位置を変数trizに格納
								//if(tvec.z>0)
								//	triz=r;
								//else
								//	triz=-r;


								////p1とp2が面の両側にあるか調べる
								//if(p->y * p2->y > 0)
								//	return false;

								//float rat= -p->y / (p2->y-p1->y);
								//float x=p->x + (p2->x - p1->x)*rat;
								//float z=p->z + (p2->z - p1->z)*rat;

								//if(x<=w && x>=-w && z<=h && z>=-h)
								//	ok=true;;		


							}

							//③左の面とテスト
							if(!ok)
							{
							}
							

							//④下の面とテスト
							if(!ok)
							{
							}


							//⑤斜面とテスト
							if(!ok)
							{
							}
							
							



							ok=true;

							if(ok)
							{
								//三角形の精密判定

								//tvecとtvec2のZより、判定するに値するかを求める
								if((tvec.z>0 && tvec.z<=tvec2.z) || (tvec.z<0 && tvec.z>=tvec2.z))
									ok=false;

								if(ok)
								{

									//tvecを使い、三角形と線の交点が三角形の中にあるかを求める


									//調べる三角形のZ位置を変数trizに格納
									if(tvec.z>0)
										triz=r;
									else
										triz=-r;


									rat=(triz-tvec.z)/(tvec2.z-tvec.z);
									w=pvec.x=tvec.x+(tvec2.x-tvec.x)*rat;
									h=pvec.y=tvec.y+(tvec2.y-tvec.y)*rat;
									pvec.z=triz;


									//三角形の点3がX軸につくように、w,hをせん断
									h-=tri[index].s.y*(w/tri[index].s.x);
									//三角形の幅、高さが1になるようにw,hを縮小
									w/=tri[index].s.x;
									h/=tri[index].h;

								}


								//点が三角形の中にあるかを調べる
								if(w>=0 && h>=0 && w+h<=1 && ok)
								{
									//逆行列を求める
									D3DXMatrixInverse(&dmat,NULL,&tri[index].mat);

									//種類設定
									judres.kind[judres.count]=tri[index].kind;

									//距離を求める
									{
										//当たった位置と終点の距離
										judres.dis[judres.count]=distance3(pvec.x-tvec2.x,pvec.y-tvec2.y,pvec.z-tvec2.z);
									}


									//当たった位置を求める
									{
										//元の座標に変換！
										D3DXVec3Transform(&tvec3,&pvec,&dmat);
										judres.v[judres.count].x=tvec3.x;
										judres.v[judres.count].y=tvec3.y;
										judres.v[judres.count].z=tvec3.z;
									}



									//法線を求める
									{
										//元の座標に変換！
										pvec.x=pvec.y=0;
										if(triz>0)
											pvec.z=1;
										else
											pvec.z=-1;

										D3DXVec3Transform(&tvec3,&pvec,&dmat);

										//変換した座標から、三角形の点1の座標を引く
										judres.n[judres.count].x=tvec3.x-sph[tri[index].csph[0]].p.x;
										judres.n[judres.count].y=tvec3.y-sph[tri[index].csph[0]].p.y;
										judres.n[judres.count].z=tvec3.z-sph[tri[index].csph[0]].p.z;

									}


									//勢いを求める
									{
										judres.p[judres.count]=pvec.z*(tvec.z-tvec2.z);
									}


									judres.count++;

//									char str[100];
////									sprintf(str,"%f,%f",po.y,mv.y);
//									MessageBox(hWnd,str,"",MB_OK);

									//この三角形にあたったということはcpol,csphにはあたらないので、checkをtrueにする
									for(j=0;j<3;j++)
									{
										pol[tri[index].cpol[j]].check=true;
										sph[tri[index].csph[j]].check=true;
									}
									

									
								}
								else
								{
									//cpol,csphをリストに追加
									for(j=0;j<3;j++)
									{
										pollist[pollistcount++]=tri[index].cpol[j];
										sphlist[sphlistcount++]=tri[index].csph[j];
									}

								}





							}
							



						}



						

						
						

					}
					else
					{

						//食い込み判定は、移動元を現在の位置とし、計算する（移動先は、勢い計算でのみ使う）



						//変換後の点のZ軸が、範囲内かを調べる
						if(tvec.z>-r && tvec.z<r)
						{
							//すべての辺を外側へ1拡大した座標の点0が原点に来るように移動
							pvec.x=tvec.x-tri[index].sp[0].x*r;
							pvec.y=tvec.y-tri[index].sp[0].y*r;

							//拡大後の三角形の点3の情報を変数に格納
							w=tri[index].s.x+tri[index].sp[2].x*r-tri[index].sp[0].x*r;
							h=tri[index].s.y+tri[index].sp[2].y*r-tri[index].sp[0].y*r;

							//三角形の点3がX軸につくように、pvecをせん断
							pvec.y-=h*(pvec.x/w);

							//三角形の幅、高さが1になるようにpvecを縮小
							pvec.x/=w;
							pvec.y/=tri[index].h+tri[index].sp[1].y*r-tri[index].sp[0].y*r;

							//その三角形の(高さ1,幅1の直角三角形)なかに点があるかを調べる
							if(pvec.x+pvec.y<=1 && pvec.x>=0 && pvec.y>=0)
							{

								//精密判定開始！！

								//はじめに三角形の座標に変換したtvecを使い、三角柱の中に点があるかを求める
								
								//三角形の点3がX軸につくように、tvecをせん断し、pvecに格納
								pvec.x=tvec.x;
								pvec.y=tvec.y-tri[index].s.y*(tvec.x/tri[index].s.x);
								pvec.z=tvec.z;
								//三角形の幅、高さが1になるようにpvecを縮小
								pvec.x/=tri[index].s.x;
								pvec.y/=tri[index].h;

								//その三角形の(高さ1,幅1の直角三角形)なかに点があるかを調べる
								if(pvec.x+pvec.y<=1 && pvec.x>=0 && pvec.y>=0)
								{

									//逆行列を求める
									D3DXMatrixInverse(&dmat,NULL,&tri[index].mat);

									
									pvec.x=0;
									pvec.y=0;
									
									//種類設定
									judres.kind[judres.count]=tri[index].kind;

									//食い込みベクトルの測定
									{

										//食い込んでる深さ(dis)と面の位置に戻したときのベクトル(p)を調べる
										if(pvec.z>=0)
										{
											judres.dis[judres.count]=r-pvec.z;
											pvec.z=r-pvec.z;
										}
										else
										{
											judres.dis[judres.count]=r+pvec.z;
											pvec.z=-r-pvec.z;
										}


										//元の座標に変換！
										D3DXVec3Transform(&tvec3,&pvec,&dmat);

										//変換した座標から、三角形の点1の座標を引く
										judres.v[judres.count].x=tvec3.x-sph[tri[index].csph[0]].p.x;
										judres.v[judres.count].y=tvec3.y-sph[tri[index].csph[0]].p.y;
										judres.v[judres.count].z=tvec3.z-sph[tri[index].csph[0]].p.z;

									}


									//法線ベクトルを求める
									{

										if(pvec.z>=0)
											pvec.z=1;
										else
											pvec.z=-1;

										//元の座標に変換！
										D3DXVec3Transform(&tvec3,&pvec,&dmat);

										//変換した座標から、三角形の点1の座標を引く
										judres.n[judres.count].x=tvec3.x-sph[tri[index].csph[0]].p.x;
										judres.n[judres.count].y=tvec3.y-sph[tri[index].csph[0]].p.y;
										judres.n[judres.count].z=tvec3.z-sph[tri[index].csph[0]].p.z;

									}


									//食い込み勢いを測定(軌道ベクトルより)
									{

										//移動元の点2を三角形の座標に変換
										D3DXVec3Transform(&tvec2,p2,&tri[index].mat);


										//移動元と移動先の位置より、勢いを調べる
										if(pvec.z>=0)
											judres.p[judres.count]=tvec.z-tvec2.z;
										else
											judres.p[judres.count]=tvec2.z-tvec.z;

									}


									judres.count++;


									//この三角形にあたったということはcpol,csphにはあたらないので、checkをtrueにする
									for(j=0;j<3;j++)
									{
										pol[tri[index].cpol[j]].check=true;
										sph[tri[index].csph[j]].check=true;
									}


								}
								else
								{
									//cpol,csphをリストに追加
									for(j=0;j<3;j++)
									{
										pollist[pollistcount++]=tri[index].cpol[j];
										sphlist[sphlistcount++]=tri[index].csph[j];
									}

								}

							}
						}
					
					}




				}


			}

		}}}



		float dis,ang;

		//リストの円柱の当たり判定(精密判定)
		for(i=0;i<pollistcount;i++)
		{
			index=pollist[i];

			if(pol[index].check==false)
			{

				pol[index].check=true;

				//移動先の点1を三角形の座標に変換
				D3DXVec3Transform(&tvec,p,&pol[index].mat);

				if(line)
				{

					//移動元の点2を三角形の座標に変換
					D3DXVec3Transform(&tvec2,p2,&pol[index].mat);

					//tvecを上から見て円柱の中にあったら外に出す

					if(distance(tvec.x,tvec.z)<r)
					{
						changedistance(&tvec.x,&tvec.z,r);
					}


					//上から見て、点1を原点に、点2を+X座標上に移動したときの円柱の座標を求める
					pvec.x=-tvec.x;
					pvec.z=-tvec.z;
					pvec2.x=tvec2.x-tvec.x;
					pvec2.z=tvec2.z-tvec.z;
					ang=angle(pvec2.x,pvec2.z);
					rotation(&pvec.x,&pvec.z,-ang);

					//上から見下ろしたときの点1と点2の距離を求める
					dis=distance(pvec2.x,pvec2.z);


					//簡単チェック
					if(pvec.x>0 && pvec.x<=dis+r && pvec.z>-r && pvec.z<r)
					{

						//円とX座標上の交点を求め、wに代入
						w=pvec.x-sqrtf(r*r-pvec.z*pvec.z);

						if(w<dis)
						{

							//wを0～1に変える
							rat=w/dis;

							//ratより、当たってるいちをtvec,tvec2より求める
							pvec2.y=tvec.y+(tvec2.y-tvec.y)*rat;

							if(pvec2.y>=0 && pvec2.y<=pol[index].h)
							{

								pvec2.x=tvec.x+(tvec2.x-tvec.x)*rat;
								pvec2.z=tvec.z+(tvec2.z-tvec.z)*rat;

								//逆行列を求める
								D3DXMatrixInverse(&dmat,NULL,&pol[index].mat);

								//種類設定
								judres.kind[judres.count]=pol[index].kind;

								//disを求める
								{
									judres.dis[judres.count]=distance3(tvec2.x-pvec2.x,tvec2.y-pvec2.y,tvec2.z-pvec2.z);
								}


								//あってる位置
								{

									//元の座標に変換！
									D3DXVec3Transform(&tvec3,&pvec2,&dmat);

									judres.v[judres.count].x=tvec3.x;
									judres.v[judres.count].y=tvec3.y;
									judres.v[judres.count].z=tvec3.z;

								}


								//法線ベクトル
								{
									pvec2.y=0;
									changedistance(&pvec2.x,&pvec2.z,1);

									//元の座標に変換！
									D3DXVec3Transform(&tvec3,&pvec2,&dmat);

									//変換した座標から、円柱の点1の座標を引く
									judres.n[judres.count].x=tvec3.x-sph[pol[index].csph[0]].p.x;
									judres.n[judres.count].y=tvec3.y-sph[pol[index].csph[0]].p.y;
									judres.n[judres.count].z=tvec3.z-sph[pol[index].csph[0]].p.z;
								}

								//勢いを求める
								{
									//前に求めた円柱の軌道ローカル座標とwとdisを使って勢いを求める
									ang=angle(pvec.x-w,pvec.z);
									judres.p[judres.count]=dis*cosf(ang*rad);
								}


								judres.count++;

								//この円柱にあたったということはcsphにはあたらないので、checkをtrueにする
								for(j=0;j<2;j++)
								{
									sph[pol[index].csph[j]].check=true;
								}


							
							}							
						}
						
					}


					

					
					

				}
				else
				{
					//食い込み判定は、移動元を現在の位置とし、計算する（移動先は、勢い計算でのみ使う）

					//Y軸から見たときの原点からの点の距離を求める
					dis=distance(tvec.x,tvec.z);

					//変換後の点が円柱の範囲内かを調べる
					if(dis<r && tvec.y>=0 && tvec.y<=pol[index].h)
					{

						
						//逆行列を求める
						D3DXMatrixInverse(&dmat,NULL,&pol[index].mat);

						//種類設定
						judres.kind[judres.count]=pol[index].kind;

						pvec.x=tvec.x;
						pvec.y=0;
						pvec.z=tvec.z;


						//後で法線ベクトルを求めるときに使う
						w=pvec.x;
						h=pvec.z;

						//食い込みベクトルの測定
						{

							//食い込んでる深さ(dis)と面の位置に戻したときのベクトル(p)を調べる
							judres.dis[judres.count]=r-dis;

							//pvec.x,pvec.zの長さをr-disにする
							changedistance(&pvec.x,&pvec.z,r-dis);


							//元の座標に変換！
							D3DXVec3Transform(&tvec3,&pvec,&dmat);

							//変換した座標から、円柱の点1の座標を引く
							judres.v[judres.count].x=tvec3.x-sph[pol[index].csph[0]].p.x;
							judres.v[judres.count].y=tvec3.y-sph[pol[index].csph[0]].p.y;
							judres.v[judres.count].z=tvec3.z-sph[pol[index].csph[0]].p.z;


						}


						//法線ベクトルを求める
						{
							pvec.x=w;
							pvec.z=h;

							//pvec.x,pvec.zの長さを1にする
							changedistance(&pvec.x,&pvec.z,1);

							//元の座標に変換！
							D3DXVec3Transform(&tvec3,&pvec,&dmat);

							//変換した座標から、三角形の点1の座標を引く
							judres.n[judres.count].x=tvec3.x-sph[pol[index].csph[0]].p.x;
							judres.n[judres.count].y=tvec3.y-sph[pol[index].csph[0]].p.y;
							judres.n[judres.count].z=tvec3.z-sph[pol[index].csph[0]].p.z;

						}


						//食い込み勢いを測定(軌道ベクトルより)
						{

							//移動元の点2を三角形の座標に変換
							D3DXVec3Transform(&tvec2,p2,&pol[index].mat);


							//移動元と移動先の位置より、勢いを調べる
							
							//点1の角度を求める
							ang=angle(tvec.x,tvec.z);
							
							//点2の座標を、点１が0°にくるように回転
							pvec.x=tvec2.x;
							pvec.z=tvec2.z;
							rotation(&pvec.x,&pvec.z,-ang);

							judres.p[judres.count]=-pvec.x+dis;

						}


						judres.count++;


						//この円柱にあたったということはcsphにはあたらないので、checkをtrueにする
						for(j=0;j<2;j++)
						{
							sph[pol[index].csph[j]].check=true;
						}






					}

				}

			}
		}


		//リストの球の当たり判定(精密判定)
		for(i=0;i<sphlistcount;i++)
		{
			index=sphlist[i];

			if(sph[index].check==false)
			{
				sph[index].check=true;

				//移動先の点1を球の座標に変換
				tvec.x=p->x-sph[index].p.x;
				tvec.y=p->y-sph[index].p.y;
				tvec.z=p->z-sph[index].p.z;

				if(line)
				{

					//移動先の点2を球の座標に変換
					tvec2.x=p2->x-sph[index].p.x;
					tvec2.y=p2->y-sph[index].p.y;
					tvec2.z=p2->z-sph[index].p.z;

					//tvecが球の中にあったら外に出す

					if(distance3(tvec.x,tvec.y,tvec.z)<r)
					{
						changedistance3(&tvec.x,&tvec.y,&tvec.z,r);
					}



					//点１を原点に、点2を+X座標上に移動したときの球と点2の座標を求める
					pvec.x=-tvec.x;
					pvec.y=-tvec.y;
					pvec.z=-tvec.z;
					pvec2.x=tvec2.x-tvec.x;
					pvec2.y=tvec2.y-tvec.y;
					pvec2.z=tvec2.z-tvec.z;

					//まず、上から見てX座標上に回転
					ang=angle(pvec2.x,pvec2.z);
					rotation(&pvec.x,&pvec.z,-ang);
					

					//上から見て点1と点2の距離を求める
					dis=distance(pvec2.x,pvec2.z);
					//距離と点2のY座標より、前(-Z)から見てX座標上に回転
					ang=angle(dis,pvec2.y);
					rotation(&pvec.x,&pvec.y,-ang);

					
					//点1と点2の距離を求める
					dis=distance3(pvec2.x,pvec2.y,pvec2.z);

					//簡単チェック
					if(pvec.x>0 && pvec.x<=dis+r && pvec.z>-r && pvec.z<r && pvec.y>-r && pvec.y<r)
					{

						//球とX座標上の交点を求め、wに代入

						w=pvec.x-sqrtf(r*r - (pvec.z*pvec.z + pvec.y*pvec.y));


						if(w<dis)
						{

							//wを0～1に変える
							rat=w/dis;

							//ratより、当たってるいちをtvec,tvec2より求める
							pvec2.y=tvec.y+(tvec2.y-tvec.y)*rat;
							pvec2.x=tvec.x+(tvec2.x-tvec.x)*rat;
							pvec2.z=tvec.z+(tvec2.z-tvec.z)*rat;

							//種類設定
							judres.kind[judres.count]=sph[index].kind;


							//disを求める
							{
								judres.dis[judres.count]=distance3(tvec2.x-pvec2.x,tvec2.y-pvec2.y,tvec2.z-pvec2.z);
							}


							//あってる位置
							{

								//座標をワールドに変換
								judres.v[judres.count].x=pvec2.x+sph[index].p.x;
								judres.v[judres.count].y=pvec2.y+sph[index].p.y;
								judres.v[judres.count].z=pvec2.z+sph[index].p.z;

							}


							//法線ベクトル
							{
								changedistance3(&pvec2.x,&pvec2.y,&pvec2.z,1);

								judres.n[judres.count].x=pvec2.x;
								judres.n[judres.count].y=pvec2.y;
								judres.n[judres.count].z=pvec2.z;
							}

							//勢いを求める
							{
								//前に求めた円柱の軌道ローカル座標とwとdisを使って勢いを求める
								ang=angle(pvec.x-w,distance(pvec.z,pvec.y));
								judres.p[judres.count]=dis*cosf(ang*rad);
							}


							judres.count++;
						
						}
						
					}








				}
				else
				{

					//原点からの距離を求める
					dis=distance3(tvec.x,tvec.y,tvec.z);

					//原点からの距離が範囲内だったら
					if(dis<r)
					{
						//種類設定
						judres.kind[judres.count]=sph[index].kind;

						//disを求める
						judres.dis[judres.count]=r-dis;

						//vを求める
						judres.v[judres.count].x=tvec.x;
						judres.v[judres.count].y=tvec.y;
						judres.v[judres.count].z=tvec.z;
						changedistance3(&judres.v[judres.count].x,&judres.v[judres.count].y,&judres.v[judres.count].z,r-dis);

						//nを求める
						judres.n[judres.count].x=tvec.x;
						judres.n[judres.count].y=tvec.y;
						judres.n[judres.count].z=tvec.z;
						changedistance3(&judres.n[judres.count].x,&judres.n[judres.count].y,&judres.n[judres.count].z,1);

						//pを求める
						{

							//移動先の点2を球の座標に変換
							tvec2.x=p2->x-sph[index].p.x;
							tvec2.y=p2->y-sph[index].p.y;
							tvec2.z=p2->z-sph[index].p.z;

							//上から見た点1の角度を調べる
							ang=angle(tvec.x,tvec.z);
							//点2を-ang回転
							rotation(&tvec2.x,&tvec2.z,-ang);
							
							//正面(-Z)からみた点1の角度を調べ、点2をその角度の逆に回転
							rotation(&tvec2.x,&tvec2.y,-angle(distance(tvec.x,tvec.z),tvec.y));
							
							judres.p[judres.count]=-tvec2.x+dis;
						}

						judres.count++;

						
					}


				}

			}
		}


		return true;
	}
	return false;
}

void JudClass::SphereJud(bool line,int kind,float sr,float r,D3DXVECTOR3* sp,D3DXVECTOR3* p,D3DXVECTOR3* p2)
{

	D3DXVECTOR3 tvec,tvec2,pvec,pvec2;
	float dis,ang,w,rat;


	//移動先の点1を球の座標に変換
	tvec.x=p->x-sp->x;
	tvec.y=p->y-sp->y;
	tvec.z=p->z-sp->z;


	if(line)
	{

		//移動先の点2を球の座標に変換
		tvec2.x=p2->x-sp->x;
		tvec2.y=p2->y-sp->y;
		tvec2.z=p2->z-sp->z;


		//tvecが球の中にあったら外に出す
		if(distance3(tvec.x,tvec.y,tvec.z)<sr+r)
		{
			changedistance3(&tvec.x,&tvec.y,&tvec.z,sr+r);
		}



		//点１を原点に、点2を+X座標上に移動したときの球と点2の座標を求める
		pvec.x=-tvec.x;
		pvec.y=-tvec.y;
		pvec.z=-tvec.z;
		pvec2.x=tvec2.x-tvec.x;
		pvec2.y=tvec2.y-tvec.y;
		pvec2.z=tvec2.z-tvec.z;

		//まず、上から見てX座標上に回転
		ang=angle(pvec2.x,pvec2.z);
		rotation(&pvec.x,&pvec.z,-ang);


		//上から見て点1と点2の距離を求める
		dis=distance(pvec2.x,pvec2.z);
		//距離と点2のY座標より、前(-Z)から見てX座標上に回転
		ang=angle(dis,pvec2.y);
		rotation(&pvec.x,&pvec.y,-ang);


		//点1と点2の距離を求める
		dis=distance3(pvec2.x,pvec2.y,pvec2.z);

		//簡単チェック
		if(pvec.x>0 && pvec.x<=dis+sr+r && pvec.z>-(sr+r) && pvec.z<sr+r && pvec.y>-(sr+r) && pvec.y<sr+r)
		{

			//球とX座標上の交点を求め、wに代入

			w=pvec.x-sqrtf((sr+r)*(sr+r) - (pvec.z*pvec.z + pvec.y*pvec.y));


			if(w<dis)
			{

				//wを0～1に変える
				rat=w/dis;

				//ratより、当たってるいちをtvec,tvec2より求める
				pvec2.y=tvec.y+(tvec2.y-tvec.y)*rat;
				pvec2.x=tvec.x+(tvec2.x-tvec.x)*rat;
				pvec2.z=tvec.z+(tvec2.z-tvec.z)*rat;

				//種類設定
				judres.kind[judres.count]=kind;


				//disを求める
				{
					judres.dis[judres.count]=distance3(tvec2.x-pvec2.x,tvec2.y-pvec2.y,tvec2.z-pvec2.z);
				}


				//あってる位置
				{

					//座標をワールドに変換
					judres.v[judres.count].x=pvec2.x+sp->x;
					judres.v[judres.count].y=pvec2.y+sp->y;
					judres.v[judres.count].z=pvec2.z+sp->z;

				}


				//法線ベクトル
				{
					changedistance3(&pvec2.x,&pvec2.y,&pvec2.z,1);

					judres.n[judres.count].x=pvec2.x;
					judres.n[judres.count].y=pvec2.y;
					judres.n[judres.count].z=pvec2.z;
				}

				//勢いを求める
				{
					//前に求めた円柱の軌道ローカル座標とwとdisを使って勢いを求める
					ang=angle(pvec.x-w,distance(pvec.z,pvec.y));
					judres.p[judres.count]=dis*cosf(ang*rad);
				}


				judres.count++;
			
			}
			
		}




	}
	else
	{
		//原点からの距離を求める
		dis=distance3(tvec.x,tvec.y,tvec.z);

		//球体の一番近い面との距離が範囲内だったら
		if(dis-r<sr)
		{

			//種類設定
			judres.kind[judres.count]=kind;

			//disを求める
			judres.dis[judres.count]=r+sr-dis;

			//vを求める
			judres.v[judres.count].x=tvec.x;
			judres.v[judres.count].y=tvec.y;
			judres.v[judres.count].z=tvec.z;
			changedistance3(&judres.v[judres.count].x,&judres.v[judres.count].y,&judres.v[judres.count].z,r+sr-dis);

			//nを求める
			judres.n[judres.count].x=tvec.x;
			judres.n[judres.count].y=tvec.y;
			judres.n[judres.count].z=tvec.z;
			changedistance3(&judres.n[judres.count].x,&judres.n[judres.count].y,&judres.n[judres.count].z,1);

			//pを求める
			{

				//移動先の点2を球の座標に変換
				tvec2.x=p2->x-sp->x;
				tvec2.y=p2->y-sp->y;
				tvec2.z=p2->z-sp->z;

				//上から見た点1の角度を調べる
				ang=angle(tvec.x,tvec.z);
				//点2を-ang回転
				rotation(&tvec2.x,&tvec2.z,-ang);
				
				//正面(-Z)からみた点1の角度を調べ、点2をその角度の逆に回転
				rotation(&tvec2.x,&tvec2.y,-angle(distance(tvec.x,tvec.z),tvec.y));

				judres.p[judres.count]=dis-tvec2.x;
			}

			judres.count++;

			
		}


	}


}


void JudClass::sort()
{
	int i,j;

	//作業用変数
	int kind;
	float dis,p;
	D3DXVECTOR3 v,n;

	//disの大きい順に並び替える
	for(i=0;i<judres.count-1;i++)
	{
		for(j=i+1;j<judres.count;j++)
		{
			if(judres.dis[i]<judres.dis[j])
			{
				//入れ替え
				kind=judres.kind[i];
				dis=judres.dis[i];
				p=judres.p[i];
				v=judres.v[i];
				n=judres.n[i];
				judres.kind[i]=judres.kind[j];
				judres.dis[i]=judres.dis[j];
				judres.p[i]=judres.p[j];
				judres.v[i]=judres.v[j];
				judres.n[i]=judres.n[j];
				judres.kind[j]=kind;
				judres.dis[j]=dis;
				judres.p[j]=p;
				judres.v[j]=v;
				judres.n[j]=n;
			}
		}
	}

}


void JudClass::reset()
{
	judres.count = 0;
}



//y軸上にある高さh*2の線分(Y軸座標で言うと -h～h )と、三角形p1-p2-p3が触れるかを調べる関数
bool JudClass::trilinejud(D3DXVECTOR3* p1,D3DXVECTOR3* p2,D3DXVECTOR3* p3,float h)
{


	bool cross[3]={false,false,false};//各辺がX軸と交差するかを格納する変数

	if(p1->x * p2->x <= 0)
		cross[0]=true;
	if(p2->x * p3->x <= 0)
		cross[1]=true;
	if(p3->x * p1->x <= 0)
		cross[2]=true;


	if((int)cross[0]+(int)cross[1]+(int)cross[2]<2)//X軸と交差していないので、線と三角形は交差しない
		return false;

	//X軸の両側に点のある辺で、X軸上にきたところの点を取る
	float z[2],y[2],rat;
	int count=0;

	if(cross[0]==true)//p1～p2がX軸と交差するばあい
	{
		rat=-p1->x / (p2->x - p1->x);
		z[count]=p1->z + (p2->z - p1->z)*rat;
		y[count]=p1->y + (p2->y - p1->y)*rat;
		count++;
	}
	if(cross[1]==true)//p2～p3がX軸と交差するばあい
	{
		rat=-p2->x / (p3->x - p2->x);
		z[count]=p2->z + (p3->z - p2->z)*rat;
		y[count]=p2->y + (p3->y - p2->y)*rat;
		count++;

		//もしこの地点でcountが2で、(z[0]-z[1])が、Z軸をはさんでいなかったら、countを引く
		if(z[0]*z[1] > 0 && count>=2)
			count--;

	}
	if(cross[2]==true && count<2)//p3～p1がX軸と交差するばあい
	{
		rat=-p3->x / (p1->x - p3->x);
		z[count]=p3->z + (p1->z - p3->z)*rat;
		y[count]=p3->y + (p1->y - p3->y)*rat;
		count++;
	}


	//(z[0],y[0])-(z[1],y[1])が、Z軸と交差するかを求める
	if(z[0]*z[1] > 0)
		return false;


	//(z[0],y[0])-(z[1],y[1])と、Z軸との交点を求める

	float hity;	//実際に触れている点の高さを格納する変数

	hity= y[0] + (y[1]-y[0]) * ( -z[0] / (z[1]-z[0]) );


	if(hity<=h && hity>=-h)
		return true;

	return false;
}

//x-z軸上にある、幅w*2,奥行きh*2の面と、線分p1-p2が触れるかを調べる関数
bool JudClass::rectlinejud(D3DXVECTOR3* p1,D3DXVECTOR3* p2,float w,float h)
{
	//p1とp2が面の両側にあるか調べる
	if(p1->y * p2->y > 0)
		return false;

	float rat= -p1->y / (p2->y-p1->y);
	float x=p1->x + (p2->x - p1->x)*rat;
	float z=p1->z + (p2->z - p1->z)*rat;

	if(x<=w && x>=-w && z<=h && z>=-h)
		return true;

	return false;

}
