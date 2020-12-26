
//���ȒP�ȃ��b�V���֐��Ɩ���ւ��ăe�X�g����I�I


#include "meshclass.h"

//extern bool disget;
//extern float ansdis;


MeshClass::MeshClass()
{
	//���}�b�v�}�g���b�N�X�ݒ�
	D3DXMATRIX mat;
	D3DXMatrixTranslation( &EnvMatrix, 1,1,0 );
	D3DXMatrixScaling( &mat, 0.5f,-0.5f,1 );
	EnvMatrix*=mat;

	Reset();
}


void MeshClass::Reset()
{
	//������
	Created=false;
}


bool MeshClass::Create( LPDIRECT3DDEVICE8 device, char *filename, bool MultiTexture)
{


	int i,j,k,l;
	char str[100];
	FILE* file;//�t�@�C�����݊m�F�p


	//�t�@�C���p�X(data/)�A�t�@�C����(test)�A�g���q(.x)�ɕ�����
	char name[MAX_PATH],kakutyousi[MAX_PATH];
	PathDiv(filename,MeshRootPath,name,kakutyousi);


//Progressive=false;

	if(!Created)
	{



		////�t�@�C�������A���b�V���̐��𑪒肷��


		//���b�V���̃J�E���^������

		MeshCount=0;

		char newfilename[MAX_PATH];


		//��������J��Ԃ�
		while(1)
		{

			//�J�E���^���A�t�@�C�����̐���
			strcpy(newfilename,MeshRootPath);
			strcat(newfilename,name);
			if((MeshCount+1)!=1)
			{
				sprintf(str,"[%d]",(MeshCount+1));
				strcat(newfilename,str);
			}
			strcat(newfilename,kakutyousi);


			//�t�@�C�������݂��邩�m�F
			if((file=fopen(newfilename,"r"))!=NULL)
			{
				//�t�@�C�������I�I
				fclose(file);
				strcpy(MeshFileName[MeshCount],newfilename);
				MeshCount++;
			}
			else
			{
				//�t�@�C�������݂��Ȃ��I�I
				if(MeshCount==0)
					return false;//���s

				break;
			}


		}




		//���b�V���č\�z�I
		Mesh=new LPD3DXMESH[MeshCount];

		MeshP = new D3DXVECTOR3[MeshCount];
		MeshR = new float[MeshCount];


		//���̑��̕ϐ����č\�z!!
		MeshMaterialCount=new short int[MeshCount];
//		MeshDistance=new float[MeshCount];
		



	


	}//Created



	//�}�e���A���č\�z�p�ϐ�
	int matcount=0;
	LPD3DXBUFFER *MtrlBuffer = new LPD3DXBUFFER[MeshCount];
	LPD3DXBUFFER pAdjacencyBuffer;
	DWORD *MCount = new DWORD[MeshCount];


	//���E���v�Z�p�ϐ�
	D3DXVECTOR3 BoxMax,BoxMin;
	float dis;


	for(i=0;i<MeshCount;i++)
	{

		Mesh[i]=NULL;

		//�ǂݍ���
		if( FAILED( D3DXLoadMeshFromX( MeshFileName[i], D3DXMESH_MANAGED, 
									device, &pAdjacencyBuffer,
									&MtrlBuffer[i], &MCount[i],
									&Mesh[i] ) ) )
		{

			//�݂���ˁ[
			return false;
		}



		//�ʂ��Ȃ�������X���[
		if(Mesh[i]->GetNumFaces()>0)
		{



			matcount+=(MeshMaterialCount[i]=(int)MCount[i]);



			//���E���Z�o

			LPD3DXMESH TempMesh = NULL;

			//���b�V���̃t�H�[�}�b�g��ύX
			if( FAILED( Mesh[i]->CloneMeshFVF( D3DXMESH_SYSTEMMEM, D3DFVF_XYZ, device, &TempMesh ) ) )
				return false;

			LPDIRECT3DVERTEXBUFFER8 VB;
			TempMesh->GetVertexBuffer(&VB);

			//���_�̈ʒu���݂̂��z���o��
			D3DXVECTOR3* vec;
			if( FAILED( VB->Lock( 0, 0, (BYTE**)&vec, 0 ) ) )
				return false;

			//���E�{�b�N�X�����߂�
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


			//��ԉ����_�̋��������߂�(���a)
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
//				//�v���O���b�V�u���b�V���̍쐬
//				if( FAILED( D3DXGeneratePMesh( Mesh[i], (DWORD*)pAdjacencyBuffer->GetBufferPointer(),
//										NULL, NULL, 1, D3DXMESHSIMP_VERTEX, &PMesh[i] )))
//				{
//					//�~�X�����I
//					PMesh[i]=NULL;
//				}
//				else
//				{
////					PMesh[i]->SetNumVertices(PMesh[i]->GetMaxVertices());
//
//					//�œK�����Ă���
//					if( FAILED( PMesh[i]->OptimizeBaseLOD(D3DXMESHOPT_VERTEXCACHE, NULL) ) )
//					{
//						//�~�X�����I
//						return false;
//					}
//				}
//
//
//			}
//





			//�œK�����Ă���
			if( FAILED( Mesh[i]->OptimizeInplace(D3DXMESHOPT_COMPACT | D3DXMESHOPT_ATTRSORT | D3DXMESHOPT_VERTEXCACHE,
												(DWORD*)pAdjacencyBuffer->GetBufferPointer(), NULL, NULL, NULL) ) )
			{
				//�~�X�����I
				return false;
			}


		}


		pAdjacencyBuffer->Release();

	}






	if(!Created)
	{


		//��Ɨp�}�e���A��(�Ƃ肠�����傫�߂ɂƂ�)
		D3DMATERIAL8* WorkMaterial = new D3DMATERIAL8[matcount];


		//�e�N�X�`���t�@�C����������ׂ�
		TextureCount=0;
		TextureKindCount=0;
		MaterialCount=0;


		//���b�V�����Ƃɒ��ׂ�
		for(i=0;i<MeshCount;i++)
		{
			D3DXMATERIAL* d3dxMaterials=(D3DXMATERIAL*)MtrlBuffer[i]->GetBufferPointer();
	 
			//�ގ����Ƃɒ��ׂ�
			for(j=0;j<(int)MeshMaterialCount[i];j++)
			{
				//i=���b�V���ԍ�
				//j=�ގ��ԍ�



				//�}�e���A���`�F�b�N

				for(k=0;k<MaterialCount;k++)
				{
					if(MaterialCmp(&WorkMaterial[k],&d3dxMaterials[j].MatD3D))
					{
						//�����̔���!
						MeshMaterialIndex[i][j]=k;
						goto MaterialCheckEnd;
					}
				}

				//�����̂��Ȃ�����
				WorkMaterial[MaterialCount]=d3dxMaterials[j].MatD3D;
				WorkMaterial[MaterialCount].Ambient=WorkMaterial[MaterialCount].Diffuse;
				MeshMaterialIndex[i][j]=MaterialCount;
				MaterialCount++;



	MaterialCheckEnd:;





				//�e�N�X�`���`�F�b�N

				if(d3dxMaterials[j].pTextureFilename==NULL)
				{
	//				d3dxMaterials[j].pTextureFilename= new char[MAX_PATH];
	//				strcpy(d3dxMaterials[j].pTextureFilename,"");
					d3dxMaterials[j].pTextureFilename="";
				}





				//���̃e�N�X�`�������łɓǂݍ��܂�Ă��邩�̃`�F�b�N
				for(k=0;k<TextureCount;k++)
				{
					if(stricmp(&TextureFileName[k][0],d3dxMaterials[j].pTextureFilename)==0)
					{
						//���Ԗڂ�(���)�e�N�X�`�������ׂ�
						for(l=0;l<TextureKindCount;l++)
						{
							if(TextureIndex[l]==k)
							{
								MeshTextureIndex[i][j]=l;

								//���̍ގ��̃`�F�b�N�͏I���!
								goto TextureCheckEnd;
							}
						}
					}
				}


				//�܂��ǂݍ��܂�Ă��Ȃ�!!

				//�}���`�e�N�X�`���̖����𑪒肷��

				char newtexfilename[MAX_PATH];

				//�t�@�C���p�X(data/)�A�t�@�C����(test)�A�g���q(.x)�ɕ�����
				char texpath[MAX_PATH],texname[MAX_PATH],texkakutyousi[MAX_PATH];
				PathDiv(d3dxMaterials[j].pTextureFilename,texpath,texname,texkakutyousi);



				//�����ݒ�
				TextureIndex[TextureKindCount]=TextureCount;
				TextureMultiCount[TextureKindCount]=0;




				//�܂��͂P���ڂ̃e�N�X�`���t�@�C�������i�[
				strcpy(TextureFileName[TextureCount],texpath);
				strcat(TextureFileName[TextureCount],texname);
				strcat(TextureFileName[TextureCount],texkakutyousi);

				//�t�@�C�������݂��邩�m�F(�A�v���P�[�V��������̃t���p�X�Œ��ׂ�)
				strcpy(newtexfilename,MeshRootPath);
				strcat(newtexfilename,TextureFileName[TextureCount]);

				//�t�@�C�������݂����Ƃ��̏���
				TextureCount++;
				TextureMultiCount[TextureKindCount]++;
				MeshTextureIndex[i][j]=TextureKindCount;




				if(MultiTexture==false)
				{
					TextureKindCount++;
				}
				else
				{

					//��������J��Ԃ�
					while(1)
					{

						//�J�E���^���A�t�@�C�����̐���

						strcpy(TextureFileName[TextureCount],texpath);
						strcat(TextureFileName[TextureCount],texname);
						if((TextureMultiCount[TextureKindCount]+1)!=1)
						{
							sprintf(str,"[%d]",(TextureMultiCount[TextureKindCount]+1));
							strcat(TextureFileName[TextureCount],str);
						}
						strcat(TextureFileName[TextureCount],texkakutyousi);

						//�t�@�C�������݂��邩�m�F(�A�v���P�[�V��������̃t���p�X�Œ��ׂ�)
						strcpy(newtexfilename,MeshRootPath);
						strcat(newtexfilename,TextureFileName[TextureCount]);
						if((file=fopen(newtexfilename,"r"))!=NULL)
						{
							fclose(file);

							//�t�@�C�������݂����Ƃ��̏���
							TextureCount++;
							TextureMultiCount[TextureKindCount]++;
							MeshTextureIndex[i][j]=TextureKindCount;
						}
						else
						{
							//�t�@�C�������݂��Ȃ�!

							if(TextureMultiCount[TextureKindCount]!=0)
							{
								TextureKindCount++;
							}

							//���̍ގ���
							goto TextureCheckEnd;


						}


					}



				}


	TextureCheckEnd:;



			}


			//�����K�v�Ȃ�
			MtrlBuffer[i]->Release();

		}




		//�}�e���A���č\�z!
		Material = new D3DMATERIAL8[MaterialCount];
		for(i=0;i<MaterialCount;i++)
		{
			Material[i]=WorkMaterial[i];
		}




		//�e�N�X�`���č\�z!!
		Texture = new LPDIRECT3DTEXTURE8[TextureCount];
		KeepTexture = new LPDIRECT3DTEXTURE8[TextureCount];



	}//Created

	

	//�e�N�X�`���ǂݍ���

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
						device,					// �f�o�C�X
						TexFullPath,	// �e�N�X�`���t�@�C����
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
						&Texture[i] ) ) )		// �e�N�X�`��
			{
				//�݂���ˁ[
				Texture[i]=NULL;
				KeepTexture[i]=NULL;

			}
			else
				KeepTexture[i]=Texture[i];

		}

	}






	//�ݒ�F�X


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

		//�}���`�e�N�X�`����UV�́A�������ƂɁA3.7�{���A35�x����]������B
		//���̐��l�́A�e�N�X�`�����ł��邾���J��Ԃ��Ȃ��悤�Ɏ��s���낵���l(�܂�K��)�ł�

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
				//�I�y���[�^����
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
//		//���b�V���̌��E�\�������̐ݒ�
//		for(i=0;i<MeshCount;i++)
//		{
////			for(j=0;j<MeshLvCount[i]-1;j++)
////			{
////				MeshDistance[i+j]=powf(2,(float)j)*20;
////			}
//			MeshDistance[i]=10000;//�ǂ��܂ł��\������I�I
////			MeshDistance[i]=1000000000;
//		}
//
//


		////���}�b�v�e�N�X�`���̐ݒ�
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

		//�J�����O���邩(���b�V���̃��x���킯��)
		//bool progressive = (po!=NULL) && (look!=NULL);
		bool cull = (fovy>0) && (po!=NULL) && (look!=NULL);

		cull=false;


		D3DXVECTOR3 Muki;//�J�����̌������i�[

		float dis,width,ballwidth,camerawidth;
		//ballwidth( r/cos(����/2) )
		//camerawidth�́A�J�������猩�����E���̂���(z)�̃J�����̕����i�[

		D3DXVECTOR4 vec4;
		D3DXMATRIX mat;

		if(cull)
		{
			Muki.x=look->x-po->x;
			Muki.y=look->y-po->y;
			Muki.z=look->z-po->z;

			device->GetTransform( D3DTS_WORLD, &mat );
		}






		//�͈̓`�F�b�N
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
				//���̂̒��S�_���g�����X�t�H�[��
				D3DXVec3Transform(&vec4,&MeshP[i],&mat);
				//�J�����̍��W�ֈړ�
				vec4.x-=po->x;
				vec4.y-=po->y;
				vec4.z-=po->z;

				//�����╝�v�Z
				dis=dotpro3(Muki.x,Muki.y,Muki.z,vec4.x,vec4.y,vec4.z);
//				dis=D3DXVec3Length(&D3DXVECTOR3(vec4.x,vec4.y,vec4.z));



				//�J�����O
				WorkMuki=Muki;
				changedistance3(&WorkMuki.x,&WorkMuki.y,&WorkMuki.z,dis);
				width=distance3(WorkMuki.x-vec4.x,WorkMuki.y-vec4.y,WorkMuki.z-vec4.z);
				ballwidth=MeshR[i]/cosf(fovy/2*rad);//�J��������{�[�������傤�ǌ����Ȃ��Ȃ�ʒu�����߂邽�߂Ɏg��
				camerawidth=dis*tanf(fovy/2*rad);

				if(width-ballwidth>camerawidth)
				{
					//���̃��b�V����
					continue;

				}

			}





			for(k=0;k<MeshMaterialCount[i];k++)
			{




				//�����_�����O�X�e�[�W�Ȃǂ̐ݒ�

				//�e�N�X�`���̖��������[�v
				for(l=0;l<TextureMultiCount[MeshTextureIndex[i][k]];l++)
				{


					D3DXMATRIX mat;
					D3DXMATRIX mat2;

					D3DXMatrixIdentity(&mat);
					D3DXMatrixIdentity(&mat2);

					//�ړ�
					mat._31 = UVTranslationX[TextureIndex[MeshTextureIndex[i][k]]+l];
					mat._32 = UVTranslationY[TextureIndex[MeshTextureIndex[i][k]]+l];

					//��]
					float	cosans, sinans;
					cosans = cosf(UVRotation[TextureIndex[MeshTextureIndex[i][k]]+l]*rad);
					sinans = sinf(UVRotation[TextureIndex[MeshTextureIndex[i][k]]+l]*rad);
					mat._11 = mat._22 = cosans;
					mat._12 = sinans;
					mat._21 =-sinans;

					//�g��
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


				//�Ō�̃e�N�X�`���X�e�[�W�Ɋ��}�b�v�\��t���I�I
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




				//�}�e���A���Z�b�g���A�����_�����O
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

	//���b�V���J��
	for(i=0;i<MeshCount;i++)
	{
		if(Mesh[i]!=NULL)
		{
			Mesh[i]->Release();
			Mesh[i]=NULL;
		}

	}

	//�e�N�X�`���J��
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




//�����̊֐��̓e�N�X�`����}�e���A���ύX�����肵�������p

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

	//�p�X�ƃt�@�C���������߂�(�Ō�̕��������ԋ߂�/��T��)
	strcpy(path,file);
	strcpy(name,file);
	for(i=(int)strlen(file)-1;i>=0;i--)
		if(file[i]=='/')
		{
			//�p�X
			path[i+1]='\0';

			//�t�@�C����
			for(j=i+1;j<=(int)strlen(file);j++)
				name[j-(i+1)]=name[j];

			goto Jump;
		}

	//�X���b�V����������Ȃ�����!!
	strcpy(path,"");

Jump:;

	//�g���q�����߂�(�Ō�̕��������ԋ߂�/��T��)
	strcpy(kakutyousi,file);
	for(i=(int)strlen(file)-1;i>=0;i--)
		if(file[i]=='.')
		{
			//�g���q
			for(j=i;j<=(int)strlen(file);j++)
				kakutyousi[j-i]=kakutyousi[j];

			//name�̊g���q������
			name[(int)strlen(name)-((int)strlen(file)-i)]='\0';
		}
}






int MeshClass::TexNameIndex( char *filename )//�t�@�C�����̂݋L�q����i�p�X�Ȃ��A�g���q����j�����̃t�@�C���������݂��Ȃ��ꍇ-1��Ԃ�
{
	if(!Created) return -1;

	for(int i=0;i<TextureCount;i++)
	{
//		MessageBox(NULL,TextureFileName[i],"",MB_OK);
		if(stricmp(filename,TextureFileName[i])==0) return i;
	}

	return -1;
}








//�Ƃ肠�������Ƃł���
//
//bool MeshClass::SetFVF( LPDIRECT3DDEVICE8 device, DWORD FVF, int MeshNum )
//{
//    LPD3DXMESH TempMesh = NULL;
//
//	if(MeshNum!=-1)
//	{
//	
//		//���b�V���̃t�H�[�}�b�g��ύX
//		if( FAILED( Mesh[MeshNum]->CloneMeshFVF( D3DXMESH_MANAGED, FVF,
//													device, &TempMesh ) ) )
//			return false;
//
//		Mesh[MeshNum]->Release();
//		Mesh[MeshNum] = TempMesh;
//
//
//		//�@�����̂Ȃ����b�V���ɖ@���������鎞�p�ɖ@���̎Z�o������
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
//			//���b�V���̃t�H�[�}�b�g��ύX
//			if( FAILED( Mesh[i]->CloneMeshFVF( D3DXMESH_MANAGED, FVF,
//														device, &TempMesh ) ) )
//				return false;
//
//			Mesh[i]->Release();
//			Mesh[i] = TempMesh;
//
//
//			//�@�����̂Ȃ����b�V���ɖ@���������鎞�p�ɖ@���̎Z�o������
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


