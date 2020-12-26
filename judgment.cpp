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



	//X�t�@�C����ǂݍ���

	LPD3DXMESH Mesh = NULL;
	DWORD NumMaterials;
    LPD3DXBUFFER D3DXMtrlBuffer;

    if( FAILED( D3DXLoadMeshFromX( XFileName, D3DXMESH_SYSTEMMEM, device, NULL, &D3DXMtrlBuffer, &NumMaterials, &Mesh ) ) )
    {
        return false;
    }

	//�ʒu���̂ݎg�p
    Mesh->CloneMeshFVF( 0L, D3DFVF_XYZ, device, &Mesh );




	//�_��ǂݍ���

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



	int i,j,k,x,y,z;	//���[�v�p�ϐ�
	bool ok;	//�������f�p�ϐ�

	//�J�E���^������
	tricount=polcount=sphcount=0;


	D3DXVECTOR3 spos[3];//�e���_�̈ʒu���i�[����ϐ�(sphposition)
	int sindex[3];//�e���_�ɗ^������C���f�b�N�X���i�[����(sphindex)
	int pindex[3];//�e�ӂɗ^������C���f�b�N�X���i�[����(polindex)



	//��Ɨp�ɑ傫�߂Ɋm��
	tri=new TriangleStruct[200000];
	pol=new PoleStruct[200000];
	sph=new SphereStruct[200000];



	//�O�p�`�|���S�����[�v
	for( i=0; i < (int)(Mesh->GetNumFaces()); i++ )
	{



		//�|���S��(�O�p�`)�̊e���_�̈ʒu��ݒ�
		for(j=0;j<3;j++)
			spos[j]=vertexbuffer[indexbuffer[3*i+j]];


		//���̍쐬(�쐬���ꂽ���̃C���f�b�N�X��sindex[]�Ɋi�[����)
		{





			//���ꂼ��̒��_�ŁA�����ʒu�̋����Ȃ����𒲂ׂȂ��狅�����Asindex[]��ݒ肷��
			for(j=0;j<3;j++)
			{

				ok=true;	//�V�������̍쐬��������


				for(k=0;k<sphcount;k++)//�����[�v
				{
					if(spos[j]==sph[k].p)//�����ʒu�̋������I
					{
						ok=false;	//�V�������̍쐬�����ۂ���
						break;
					}
				}



				if(ok==false)
				{
					//���̋��͂��łɑ��݂���̂ŁA���̓_�Ɠ����C���f�b�N�X�ƂȂ�(�㏑�������)
					sindex[j]=k;
					if(sph[k].kind>(int)attribuffer[i])
						sph[k].kind=(short int)attribuffer[i];
				}
				else
				{
					//���̋��͂܂�����Ă��Ȃ��̂ŁA�V�������
					sph[sphcount].p=spos[j];
					sph[sphcount].kind=(short int)attribuffer[i];
					sindex[j]=sphcount;
					sphcount++;
				}
				
				
			}






		}
		//�~���̍쐬(sindex[]���g���B�쐬���ꂽ�~���̃C���f�b�N�X�́Apindex[]�Ɋi�[����)
		{





			//���ꂼ��̉~���ŁA�����ʒu�̂��Ȃ����𒲂ׂȂ���~�������Apindex[]��ݒ肷��
			//(pindex[0]�́Asindex[0]�`sindex[1]�̊Ԃ̒�������킷)


			int ato;	//ato �́A�~���̌���̋�������킷�̂Ɏg��


			for(j=0;j<3;j++)
			{

				//ato�̐ݒ�(����ŁA���̉~���̌��Ɛ�̋��̃C���f�b�N�X���Asindex[j]�`sindex[ato]�ƁA���܂�I)
				ato=j+1;
				if(ato>=3)ato=0;


				ok=true;	//�V�����~���̍쐬��������


				for(k=0;k<polcount;k++)//�~�����[�v
				{
					//�����~�������邩�𒲂ׂ�ɂ́A�����C���f�b�N�X�̋��𒸓_�Ƃ��钌��T��)
					if(	(sindex[j]==pol[k].csph[0] || sindex[j]==pol[k].csph[1]) && 
						(sindex[ato]==pol[k].csph[0] || sindex[ato]==pol[k].csph[1]))//�����ʒu�̉~�������I
					{
						ok=false;	//�V�����~���̍쐬�����ۂ���
						break;
					}
				}



				if(ok==false)
				{
					//���̉~���͂��łɑ��݂���̂ŁA���̉~���Ɠ����C���f�b�N�X�ƂȂ�(�㏑�������)
					pindex[j]=k;
					if(pol[k].kind>(int)attribuffer[i])
						pol[k].kind=(short int)attribuffer[i];
				}
				else
				{
					//���̉~���͂܂�����Ă��Ȃ��̂ŁA�V�������
					pol[polcount].csph[0]=sindex[j];
					pol[polcount].csph[1]=sindex[ato];
					pol[polcount].kind=(short int)attribuffer[i];
					pindex[j]=polcount;
					polcount++;
				}


			}






		}
		//�O�p�`�̍쐬(sindex[],pindex[]���g��)
		{



			//�����O�p�`�����łɍ���Ă��Ȃ����𒲂ׂāA�O�p�`���쐬����
			

			ok=true;//�V�����O�p�`�̍쐬��������


			for(j=0;j<tricount;j++)
			{
				//�����O�p�`�����邩�𒲂ׂ�ɂ́A�����C���f�b�N�X�̋��𒸓_�Ƃ���O�p�`��T��

				if(	(sindex[0]==tri[j].csph[0] || sindex[0]==tri[j].csph[1] || sindex[0]==tri[j].csph[2]) && 
					(sindex[1]==tri[j].csph[0] || sindex[1]==tri[j].csph[1] || sindex[1]==tri[j].csph[2]) && 
					(sindex[2]==tri[j].csph[0] || sindex[2]==tri[j].csph[1] || sindex[2]==tri[j].csph[2]))//�����ʒu�̎O�p�`����!
				{
					ok=false;	//�V�����O�p�`�̍쐬�����ۂ���
					break;
				}
			}


			if(ok==false)
			{
				//���̎O�p�`�͂��łɍ���Ă���̂ŁA��ނ����m�F����
				if(tri[k].kind>(int)attribuffer[i])
					tri[k].kind=(short int)attribuffer[i];
			}
			else
			{
				//���̎O�p�`�͂܂�����Ă��Ȃ��̂ŁA�V�������
				tri[tricount].csph[0]=sindex[0];
				tri[tricount].csph[1]=sindex[1];
				tri[tricount].csph[2]=sindex[2];
				tri[tricount].cpol[0]=pindex[0];
				tri[tricount].cpol[1]=pindex[1];
				tri[tricount].cpol[2]=pindex[2];



				//��ōs���O�p�`�̃}�g���b�N�X�v�Z���ɎO�p�`�̕�0(�_0�`�_1)�̃f�[�^���g���̂ŁA
				//�O�p�`�̓_(0�`1)�ƕ�0�̓_(0�`1)�̓_�̃C���f�b�N�X�������łȂ���΂Ȃ�Ȃ�

				int w;//���l����ւ��p�ϐ�


				if(tri[i].csph[0]!=pol[tri[i].cpol[0]].csph[0])//����Ă���
				{
					//�O�p�`�̋��C���f�b�N�X�����ւ���(0��1)
					w=tri[i].csph[0];
					tri[i].csph[0]=tri[i].csph[1];
					tri[i].csph[1]=w;

					//����ւ����Q�_�Ԃ̕ӈȊO�̕ӃC���f�b�N�X������ւ���I(1��2)
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







	//Box�̐ݒ�
	//Box�́A���肷��|���S�����ł�����茸�炷���߂ɍl��������ナ�Y���ŁA
	//����{�b�N�X�ɓ����Ă���Ƃ��͂��̃{�b�N�X�̃|���S���ƃm������s���Ƃ�������

	if(cutx<1)cutx=1;
	if(cuty<1)cuty=1;
	if(cutz<1)cutz=1;
	if(cutx>BOX_X_MAX)cutx=BOX_X_MAX;
	if(cuty>BOX_Y_MAX)cuty=BOX_Y_MAX;
	if(cutz>BOX_Z_MAX)cutz=BOX_Z_MAX;

	box.cutx=cutx;
	box.cuty=cuty;
	box.cutz=cutz;


	//��ԏ�����x,y,z�ƁA��ԑ傫��x,y,z�����߂�boxmin,boxmax�Ɋi�[
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


	//�O�̂��߁E�E�E
	box.max.x+=1;
	box.max.y+=1;
	box.max.z+=1;
	box.min.x-=1;
	box.min.y-=1;
	box.min.z-=1;



	//�O�p�`��box�̒��Ɋ܂ނ�������ׁA�܂ނȂ炻�̃C���f�b�N�X���i�[(�ebox�ɂ��Ē��ׂ�)

	//box���S���W�ƃT�C�Y�i�[�ϐ�(�T�C�Y�́Abox���S���W���璼���̂̒��_�܂ł́A���������̃x�N�g��)
	D3DXVECTOR3 boxp,boxs=D3DXVECTOR3(	(box.max.x-box.min.x)/box.cutx/2,
										(box.max.y-box.min.y)/box.cuty/2,
										(box.max.z-box.min.z)/box.cutz/2);


	D3DXVECTOR3 dvec[3],tvec[3];//��Ɨp�x�N�g��(dvec�̓A�h���X�n���p,tvec�͍��W�ړ�)


	//��z��0�̂Ƃ��Ƀo�O���o��I�I

	for(x=0;x<box.cutx;x++)
	{
		boxp.x=box.min.x+boxs.x+x*boxs.x*2;

		for(y=0;y<box.cuty;y++)
		{
			boxp.y=box.min.y+boxs.y+y*boxs.y*2;

			for(z=0;z<box.cutz;z++)
			{
				boxp.z=box.min.z+boxs.z+z*boxs.z*2;


				//�{�b�N�X�C���f�b�N�X�J�E���^������
				box.count[x][y][z]=0;

				//�O�p�`���[�v
				for(i=0;i<tricount;i++)
				{

					ok=false;


					//tvec��sph[tri[].csph[]].p��box���W���i�[
					for(j=0;j<3;j++)
					{
						tvec[j]=sph[tri[i].csph[j]].p-boxp;
					}
					
					
					//�@�e�_��box�̒��ɂ��邩���ׂ�
					for(j=0;j<3;j++)
					{
						if(	tvec[j].x<=boxs.x && tvec[j].x>=-boxs.x && 
							tvec[j].y<=boxs.y && tvec[j].y>=-boxs.y && 
							tvec[j].z<=boxs.z && tvec[j].z>=-boxs.z)
						{
							ok=true;
						}
					}

					//�A�O�p�`�̊e�ӂ������̂̊e�ʂɐG��Ă��邩�𒲂ׂ�
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

					//�B�����̂̊e�ӂ��O�p�`�̊e�ʂɐG��Ă��邩�𒲂ׂ�
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
						//���̎O�p�`���A����box�̃C���f�b�N�X���X�g�ɒǉ�
						box.index[x][y][z][box.count[x][y][z]]=i;
						box.count[x][y][z]++;
					}

				}






			}
		}
	}








	//�t�@�C���ւ̏o��
	FILE* file;
	if((file=fopen(JudFileName,"w"))==NULL)
		return false;

	//���̐��Ǝ�ނƈʒu
	fprintf(file,"%d\n",sphcount);
	for(i=0;i<sphcount;i++)
	{
		fprintf(file,"%d\n",sph[i].kind);
		fprintf(file,"%f,%f,%f\n",sph[i].p.x,sph[i].p.y,sph[i].p.z);
	}

	//���̐��Ǝ�ނƒ��_�̋��C���f�b�N�X
	fprintf(file,"%d\n",polcount);
	for(i=0;i<polcount;i++)
	{
		fprintf(file,"%d\n",pol[i].kind);
		fprintf(file,"%d,%d\n",pol[i].csph[0],pol[i].csph[1]);
	}

	//�O�p�`�̐��Ǝ�ނƒ��_�̋��C���f�b�N�X�ƕӂ̒��C���f�b�N�X
	fprintf(file,"%d\n",tricount);
	for(i=0;i<tricount;i++)
	{
		fprintf(file,"%d\n",tri[i].kind);
		fprintf(file,"%d,%d,%d,%d,%d,%d\n",
				tri[i].csph[0],tri[i].csph[1],tri[i].csph[2],
				tri[i].cpol[0],tri[i].cpol[1],tri[i].cpol[2]);
	}
	
	//box�̕�����
	fprintf(file,"%d,%d,%d\n",box.cutx,box.cuty,box.cutz);

	//box��min��max
	fprintf(file,"%f,%f,%f\n",box.min.x,box.min.y,box.min.z);
	fprintf(file,"%f,%f,%f\n",box.max.x,box.max.y,box.max.z);

	//box��count��index
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



	//�_��ǂݍ���

	FILE* file; 
	if((file=fopen(JudFileName,"r"))==NULL)
		return false;

	//���̐��ƈʒu
	fscanf(file,"%d",&sphcount);
	sph=new SphereStruct[sphcount];
	for(i=0;i<sphcount;i++)
	{
		fscanf(file,"%d",&sph[i].kind);
		fscanf(file,"%f,%f,%f",&sph[i].p.x,&sph[i].p.y,&sph[i].p.z);
	}

	//���̐��ƒ��_�̋��C���f�b�N�X
	fscanf(file,"%d",&polcount);
	pol=new PoleStruct[polcount];
	for(i=0;i<polcount;i++)
	{
		fscanf(file,"%d",&pol[i].kind);
		fscanf(file,"%d,%d",&pol[i].csph[0],&pol[i].csph[1]);
	}

	//�O�p�`�̒��_�̋��C���f�b�N�X�ƕӂ̒��C���f�b�N�X
	fscanf(file,"%d",&tricount);
	tri=new TriangleStruct[tricount];
	for(i=0;i<tricount;i++)
	{
		fscanf(file,"%d",&tri[i].kind);
		fscanf(file,"%d,%d,%d,%d,%d,%d",
				&tri[i].csph[0],&tri[i].csph[1],&tri[i].csph[2],
				&tri[i].cpol[0],&tri[i].cpol[1],&tri[i].cpol[2]);
	}

	//box�̕�����
	fscanf(file,"%d,%d,%d",&box.cutx,&box.cuty,&box.cutz);

	//box��min��max
	fscanf(file,"%f,%f,%f",&box.min.x,&box.min.y,&box.min.z);
	fscanf(file,"%f,%f,%f",&box.max.x,&box.max.y,&box.max.z);




	//box��count��index
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




	//�_�̈ʒu����A�}�g���b�N�X��A�ϊ���̍��W�ȂǁA�����v�Z�̏���

	float ang,dot;
	D3DXMATRIX mat;
	D3DXVECTOR3 yvec=D3DXVECTOR3(0,1,0),pvec;//yvec��y������P�ʃx�N�g���ɂ��Ă���킵�����́Bpvec�́A�~���̏I�_�����[�J�����W�ŕ\�����Ɏg��







	//�~���ɂ���
	for(i=0;i<polcount;i++)
	{
		//�~���̏I�_�̃��[�J�����W���i�[
		pvec=sph[pol[i].csph[1]].p-sph[pol[i].csph[0]].p;


		//�~���̒���
		pol[i].h=D3DXVec3Length(&pvec);


		//�~���̍��W�ϊ��}�g���b�N�X
		{
			//�~���̎n�_�����_�ƂȂ�悤�Ɉړ�����s��
			D3DXMatrixTranslation(&pol[i].mat,-sph[pol[i].csph[0]].p.x,-sph[pol[i].csph[0]].p.y,-sph[pol[i].csph[0]].p.z);

			//�P�ʍs��쐬
			D3DXMatrixIdentity(&mat);

			//pvec�̊p�x���ォ�猩�Ă���ׂ�
			ang=angle(pvec.x,pvec.z);
			D3DXMatrixRotationY(&mat,ang*rad);//�ォ�猩�Ď��v����ang���܂킷�s��


			//�s��̊|���Z
			pol[i].mat*=mat;

			//�~����Y�����牽�x�X���Ă��邩�𒲂ׂ�

			//y���Ɖ~���̃x�N�g���̓��ς𒲂ׂ�
			dot=D3DXVec3Dot(&yvec,&pvec);
			//���ς��x�N�g���Ԃ̊p�x�����߂�
			ang=acosf(dot/pol[i].h)*deg;
			D3DXMatrixRotationZ(&mat,ang*rad);//����(-Z)���猩�Ĕ����v����ang���܂킷�s��

			//�s��̊|���Z
			pol[i].mat*=mat;

			////�t�s������߂�
			//D3DXMatrixInverse(&pol[i].dmat,NULL,&pol[i].mat);

		}


		
	}









	D3DXVECTOR4 vec4;//�}�g���b�N�X�Ƃ̊|���Z�̌��ʂ��i�[����ϐ�

	//��Ɨp�ϐ�
	float dis,ang2,ang3;

	//�O�p�`�ɂ���
	for(i=0;i<tricount;i++)
	{
		//�O�p�`�̍��W�ϊ��}�g���b�N�X
		{

			//�_3���0�̃}�g���b�N�X�ɂ�����
			D3DXVec3Transform(&vec4,&sph[tri[i].csph[2]].p,&pol[tri[i].cpol[0]].mat);

			//���W�ϊ���̓_3���ォ�猩���p�x�𒲂ׂ�
			ang=angle(vec4.x,vec4.z);
			D3DXMatrixRotationY(&tri[i].mat,ang*rad);//�ォ�猩�Ď��v����ang���܂킷�s��

			//�s��̊|���Z
			tri[i].mat=pol[tri[i].cpol[0]].mat*tri[i].mat;

			////�t�s������߂�
			//D3DXMatrixInverse(&tri[i].dmat,NULL,&tri[i].mat);

		}

		//vec4���A0���̈ʒu�ɉ�]�������Ƃ��O�p�`�̕����Avec4.x,vec4.z�̋����ŋ��߂�
		tri[i].s.x=distance(vec4.x,vec4.z);
		tri[i].s.y=vec4.y;

		//�O�p�`�̍����ɕ�0��h����
		tri[i].h=pol[tri[i].cpol[0]].h;


		//sp[]�����߂�I

		//sp[]�́A���a��1�̉~�̒��S������Ȃ��O�p�`���A���̎O�p�`�̊e�_����̍��W�ł���킵�����́B
		//(���̎O�p�`�ɉ~�̒��S������Ȃ���΁A�~�����̎O�p�`�ɐG��邱�Ƃ͂Ȃ�)

		

		//�_1�ɂ���

		//�_1�̊p�̊p�x�����߂�(X��Y���t�ȂƂ���ɒ���)
		ang=angle(tri[i].s.y,tri[i].s.x);
		//���̓_����ϊ���̓_�ւ̋��������߂�
		dis=1/sinf(ang*rad/2);

		//�ŏI�I�ȓ_�̍��W�����߂�
		tri[i].sp[0].x=sinf((ang/2+180)*rad)*dis;
		tri[i].sp[0].y=cosf((ang/2+180)*rad)*dis;
		

		//�_2�ɂ���

		//�_2�̊p�̊p�x�����߂�(X��Y���t�ȂƂ���ɒ���)
		ang2=angle(-tri[i].s.y+tri[i].h,tri[i].s.x);
		//���̓_����ϊ���̓_�ւ̋��������߂�
		dis=1/sinf(ang2*rad/2);

		//�ŏI�I�ȓ_�̍��W�����߂�
		tri[i].sp[1].x=sinf((ang2/2+180)*rad)*dis;
		tri[i].sp[1].y=-cosf((ang2/2+180)*rad)*dis;


		//�_3�ɂ���

		//�_3�̊p�̊p�x�����߂�
		ang3=180-ang-ang2;
		//���̓_����ϊ���̓_�ւ̋��������߂�
		dis=1/sinf(ang3*rad/2);
		
		//�ŏI�I�ȓ_�̍��W�����߂�
		tri[i].sp[2].x=-sinf((ang3/2+ang2+180)*rad)*dis;
		tri[i].sp[2].y=cosf((ang3/2+ang2+180)*rad)*dis;

	}





	//////�t�@�C���֏o�́I
	////



	//if((file=fopen("������.txt","w"))==NULL)
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



		//box�ƐG��Ă��邩�𒲂ׂ�Ƃ��A�����̂Ŕ��肷��̂ŁA���̂̋O���┼�a�Ȃǂ���A�����̂����

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

		//���̒����̂�box�̂ǂ��͈̔͂Ɋ܂܂�邩�𒲂ׂ�

		int boxminx=box.cutx,boxminy=box.cuty,boxminz=box.cutz,boxmaxx=-1,boxmaxy=-1,boxmaxz=-1;//���ׂ�box�͈̔͂��C���f�b�N�X�Ŋi�[

		//X���ɂ��Ē��ׂ�
		for(i=0;i<box.cutx;i++)
		{
			if(	box.min.x+(box.max.x-box.min.x)/box.cutx*(i)	<= mymax.x && 
				box.min.x+(box.max.x-box.min.x)/box.cutx*(i+1)	>= mymin.x )	//box��mybox��X����ŐG��Ă��邩�𒲂ׂ�
			{
				//min���܂��X�V����Ă��Ȃ�������X�V����
				if(boxminx==box.cutx)
					boxminx=i;

				boxmaxx=i;
			}
			else
			{
				//max���X�V�ς݂������烋�[�v�𔲂���
				if(boxmaxx!=-1)
					break;
			}
		}

		//Y���ɂ��Ē��ׂ�
		for(i=0;i<box.cuty;i++)
		{
			if(	box.min.y+(box.max.y-box.min.y)/box.cuty*(i)	<= mymax.y && 
				box.min.y+(box.max.y-box.min.y)/box.cuty*(i+1)	>= mymin.y )	//box��mybox��Y����ŐG��Ă��邩�𒲂ׂ�
			{
				//min���܂��X�V����Ă��Ȃ�������X�V����
				if(boxminy==box.cuty)
					boxminy=i;

				boxmaxy=i;
			}
			else
			{
				//max���X�V�ς݂������烋�[�v�𔲂���
				if(boxmaxy!=-1)
					break;
			}			
		}

		//Z���ɂ��Ē��ׂ�
		for(i=0;i<box.cutz;i++)
		{
			if(	box.min.z+(box.max.z-box.min.z)/box.cutz*(i)	<= mymax.z && 
				box.min.z+(box.max.z-box.min.z)/box.cutz*(i+1)	>= mymin.z )	//box��mybox��Z����ŐG��Ă��邩�𒲂ׂ�
			{
				//min���܂��X�V����Ă��Ȃ�������X�V����
				if(boxminz==box.cutz)
					boxminz=i;

				boxmaxz=i;
			}
			else
			{
				//max���X�V�ς݂������烋�[�v�𔲂���
				if(boxmaxz!=-1)
					break;
			}			
		}





		//�͈͓���box���̎O�p�`�A�~���A����check��false�ɂ���

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





		//���X�g������
		pollistcount=0;
		sphlistcount=0;






		//�͈͓���box���̎O�p�`�̓����蔻��(�ȒP����Ɛ�������)

		int index;//�ϐ����ȗ�

		D3DXMATRIX dmat;//���W�����p�t�s��
		D3DXVECTOR4 tvec,tvec2,tvec3;//�}�g���b�N�X�Ƃ̊|���Z�̌��ʂ��i�[����ϐ�
		D3DXVECTOR3 pvec,pvec2;//��Ɨp�x�N�g��
		float w,h,h2,triz,rat;//,hx,hy;//��Ɨp�ϐ�

		for(x=boxminx;x<=boxmaxx;x++){
		for(y=boxminy;y<=boxmaxy;y++){
		for(z=boxminz;z<=boxmaxz;z++)
		{

			for(i=0;i<box.count[x][y][z];i++)
			{

				//����ɂ��Atri[index]�Ƃ����Q�Ƃ��ł���B
				index=box.index[x][y][z][i];



				if(tri[index].check==false)
				{
					tri[index].check=true;

					//�ړ���̓_1���O�p�`�̍��W�ɕϊ�
					D3DXVec3Transform(&tvec,p,&tri[index].mat);

					if(line)
					{

						//�ړ����̓_2���O�p�`�̍��W�ɕϊ�
						D3DXVec3Transform(&tvec2,p2,&tri[index].mat);


						//���ׂĂ̕ӂ��O����1�g�債�����W�̓_�����_�ɗ���悤�Ɉړ�
						pvec.x=tvec.x-tri[index].sp[0].x*r;
						pvec.y=tvec.y-tri[index].sp[0].y*r;
						pvec.z=tvec.z;
						pvec2.x=tvec2.x-tri[index].sp[0].x*r;
						pvec2.y=tvec2.y-tri[index].sp[0].y*r;
						pvec2.z=tvec2.z;

						//�g���̎O�p�`�̎O�p�`�̏���ϐ��Ɋi�[
						w=tri[index].s.x+tri[index].sp[2].x*r-tri[index].sp[0].x*r;
						h=tri[index].h+tri[index].sp[1].y*r-tri[index].sp[0].y*r;

						//�O�p�`�̓_3��X���ɂ��悤�ɁApvec,pvec2�����񂾂�
						h2=tri[index].s.y+tri[index].sp[2].y*r-tri[index].sp[0].y*r;//�g���̓_3��Y���W��h2�Ɋi�[
						pvec.y-=(h2)*(pvec.x/w);
						pvec2.y-=(h2)*(pvec2.x/w);
						

						ok=true;

						//�͈̓e�X�g
						{

							//Z���e�X�g
							if(pvec.z<=-r && pvec2.z<=-r)
								ok=false;
							if(pvec.z>=r && pvec2.z>=r)
								ok=false;

							//X���e�X�g
							if(pvec.x<=0 && pvec2.x<=0)
								ok=false;
							if(pvec.x>=w && pvec2.x>=w)
								ok=false;
							
							//Y���e�X�g
							if(pvec.y<=0 && pvec2.y<=0)
								ok=false;
							if(pvec.y>=h && pvec2.y>=h)
								ok=false;

						}



						if(ok)
						{
							//�O���ƎO�p���Ƃ̊ȒP����


							//tvec.z���H������ł�����O�֖߂�
							if(tvec.z<r && tvec.z>=0)
								tvec.z=r;
							else if(tvec.z>-r && tvec.z<0)
								tvec.z=-r;

							//�O�p�`�̕��A������1�ɂȂ�悤�ɓ_���k��(�������̃f�[�^�������p���Ō�������)
							pvec.x/=w;
							pvec.y/=h;
							pvec2.x/=w;
							pvec2.y/=h;

							ok=false;



							//�O�p���ƐG��Ă��邩�̃e�X�g


							//�@���̎O�p�`��(����1,��1�̒��p�O�p�`)�Ȃ��ɓ_�����邩�𒲂ׂ�
							if(pvec.x+pvec.y<=1 && pvec.x>=0 && pvec.y>=0)
								ok=true;
							if(pvec2.x+pvec2.y<=1 && pvec2.x>=0 && pvec2.y>=0)
								ok=true;


							//�A2���̎O�p�`�ƃe�X�g(������)

							if(!ok)
							{

								////���ׂ�O�p�`��Z�ʒu��ϐ�triz�Ɋi�[
								//if(tvec.z>0)
								//	triz=r;
								//else
								//	triz=-r;


								////p1��p2���ʂ̗����ɂ��邩���ׂ�
								//if(p->y * p2->y > 0)
								//	return false;

								//float rat= -p->y / (p2->y-p1->y);
								//float x=p->x + (p2->x - p1->x)*rat;
								//float z=p->z + (p2->z - p1->z)*rat;

								//if(x<=w && x>=-w && z<=h && z>=-h)
								//	ok=true;;		


							}

							//�B���̖ʂƃe�X�g
							if(!ok)
							{
							}
							

							//�C���̖ʂƃe�X�g
							if(!ok)
							{
							}


							//�D�Ζʂƃe�X�g
							if(!ok)
							{
							}
							
							



							ok=true;

							if(ok)
							{
								//�O�p�`�̐�������

								//tvec��tvec2��Z���A���肷��ɒl���邩�����߂�
								if((tvec.z>0 && tvec.z<=tvec2.z) || (tvec.z<0 && tvec.z>=tvec2.z))
									ok=false;

								if(ok)
								{

									//tvec���g���A�O�p�`�Ɛ��̌�_���O�p�`�̒��ɂ��邩�����߂�


									//���ׂ�O�p�`��Z�ʒu��ϐ�triz�Ɋi�[
									if(tvec.z>0)
										triz=r;
									else
										triz=-r;


									rat=(triz-tvec.z)/(tvec2.z-tvec.z);
									w=pvec.x=tvec.x+(tvec2.x-tvec.x)*rat;
									h=pvec.y=tvec.y+(tvec2.y-tvec.y)*rat;
									pvec.z=triz;


									//�O�p�`�̓_3��X���ɂ��悤�ɁAw,h������f
									h-=tri[index].s.y*(w/tri[index].s.x);
									//�O�p�`�̕��A������1�ɂȂ�悤��w,h���k��
									w/=tri[index].s.x;
									h/=tri[index].h;

								}


								//�_���O�p�`�̒��ɂ��邩�𒲂ׂ�
								if(w>=0 && h>=0 && w+h<=1 && ok)
								{
									//�t�s������߂�
									D3DXMatrixInverse(&dmat,NULL,&tri[index].mat);

									//��ސݒ�
									judres.kind[judres.count]=tri[index].kind;

									//���������߂�
									{
										//���������ʒu�ƏI�_�̋���
										judres.dis[judres.count]=distance3(pvec.x-tvec2.x,pvec.y-tvec2.y,pvec.z-tvec2.z);
									}


									//���������ʒu�����߂�
									{
										//���̍��W�ɕϊ��I
										D3DXVec3Transform(&tvec3,&pvec,&dmat);
										judres.v[judres.count].x=tvec3.x;
										judres.v[judres.count].y=tvec3.y;
										judres.v[judres.count].z=tvec3.z;
									}



									//�@�������߂�
									{
										//���̍��W�ɕϊ��I
										pvec.x=pvec.y=0;
										if(triz>0)
											pvec.z=1;
										else
											pvec.z=-1;

										D3DXVec3Transform(&tvec3,&pvec,&dmat);

										//�ϊ��������W����A�O�p�`�̓_1�̍��W������
										judres.n[judres.count].x=tvec3.x-sph[tri[index].csph[0]].p.x;
										judres.n[judres.count].y=tvec3.y-sph[tri[index].csph[0]].p.y;
										judres.n[judres.count].z=tvec3.z-sph[tri[index].csph[0]].p.z;

									}


									//���������߂�
									{
										judres.p[judres.count]=pvec.z*(tvec.z-tvec2.z);
									}


									judres.count++;

//									char str[100];
////									sprintf(str,"%f,%f",po.y,mv.y);
//									MessageBox(hWnd,str,"",MB_OK);

									//���̎O�p�`�ɂ��������Ƃ������Ƃ�cpol,csph�ɂ͂�����Ȃ��̂ŁAcheck��true�ɂ���
									for(j=0;j<3;j++)
									{
										pol[tri[index].cpol[j]].check=true;
										sph[tri[index].csph[j]].check=true;
									}
									

									
								}
								else
								{
									//cpol,csph�����X�g�ɒǉ�
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

						//�H�����ݔ���́A�ړ��������݂̈ʒu�Ƃ��A�v�Z����i�ړ���́A�����v�Z�ł̂ݎg���j



						//�ϊ���̓_��Z�����A�͈͓����𒲂ׂ�
						if(tvec.z>-r && tvec.z<r)
						{
							//���ׂĂ̕ӂ��O����1�g�債�����W�̓_0�����_�ɗ���悤�Ɉړ�
							pvec.x=tvec.x-tri[index].sp[0].x*r;
							pvec.y=tvec.y-tri[index].sp[0].y*r;

							//�g���̎O�p�`�̓_3�̏���ϐ��Ɋi�[
							w=tri[index].s.x+tri[index].sp[2].x*r-tri[index].sp[0].x*r;
							h=tri[index].s.y+tri[index].sp[2].y*r-tri[index].sp[0].y*r;

							//�O�p�`�̓_3��X���ɂ��悤�ɁApvec������f
							pvec.y-=h*(pvec.x/w);

							//�O�p�`�̕��A������1�ɂȂ�悤��pvec���k��
							pvec.x/=w;
							pvec.y/=tri[index].h+tri[index].sp[1].y*r-tri[index].sp[0].y*r;

							//���̎O�p�`��(����1,��1�̒��p�O�p�`)�Ȃ��ɓ_�����邩�𒲂ׂ�
							if(pvec.x+pvec.y<=1 && pvec.x>=0 && pvec.y>=0)
							{

								//��������J�n�I�I

								//�͂��߂ɎO�p�`�̍��W�ɕϊ�����tvec���g���A�O�p���̒��ɓ_�����邩�����߂�
								
								//�O�p�`�̓_3��X���ɂ��悤�ɁAtvec������f���Apvec�Ɋi�[
								pvec.x=tvec.x;
								pvec.y=tvec.y-tri[index].s.y*(tvec.x/tri[index].s.x);
								pvec.z=tvec.z;
								//�O�p�`�̕��A������1�ɂȂ�悤��pvec���k��
								pvec.x/=tri[index].s.x;
								pvec.y/=tri[index].h;

								//���̎O�p�`��(����1,��1�̒��p�O�p�`)�Ȃ��ɓ_�����邩�𒲂ׂ�
								if(pvec.x+pvec.y<=1 && pvec.x>=0 && pvec.y>=0)
								{

									//�t�s������߂�
									D3DXMatrixInverse(&dmat,NULL,&tri[index].mat);

									
									pvec.x=0;
									pvec.y=0;
									
									//��ސݒ�
									judres.kind[judres.count]=tri[index].kind;

									//�H�����݃x�N�g���̑���
									{

										//�H������ł�[��(dis)�Ɩʂ̈ʒu�ɖ߂����Ƃ��̃x�N�g��(p)�𒲂ׂ�
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


										//���̍��W�ɕϊ��I
										D3DXVec3Transform(&tvec3,&pvec,&dmat);

										//�ϊ��������W����A�O�p�`�̓_1�̍��W������
										judres.v[judres.count].x=tvec3.x-sph[tri[index].csph[0]].p.x;
										judres.v[judres.count].y=tvec3.y-sph[tri[index].csph[0]].p.y;
										judres.v[judres.count].z=tvec3.z-sph[tri[index].csph[0]].p.z;

									}


									//�@���x�N�g�������߂�
									{

										if(pvec.z>=0)
											pvec.z=1;
										else
											pvec.z=-1;

										//���̍��W�ɕϊ��I
										D3DXVec3Transform(&tvec3,&pvec,&dmat);

										//�ϊ��������W����A�O�p�`�̓_1�̍��W������
										judres.n[judres.count].x=tvec3.x-sph[tri[index].csph[0]].p.x;
										judres.n[judres.count].y=tvec3.y-sph[tri[index].csph[0]].p.y;
										judres.n[judres.count].z=tvec3.z-sph[tri[index].csph[0]].p.z;

									}


									//�H�����ݐ����𑪒�(�O���x�N�g�����)
									{

										//�ړ����̓_2���O�p�`�̍��W�ɕϊ�
										D3DXVec3Transform(&tvec2,p2,&tri[index].mat);


										//�ړ����ƈړ���̈ʒu���A�����𒲂ׂ�
										if(pvec.z>=0)
											judres.p[judres.count]=tvec.z-tvec2.z;
										else
											judres.p[judres.count]=tvec2.z-tvec.z;

									}


									judres.count++;


									//���̎O�p�`�ɂ��������Ƃ������Ƃ�cpol,csph�ɂ͂�����Ȃ��̂ŁAcheck��true�ɂ���
									for(j=0;j<3;j++)
									{
										pol[tri[index].cpol[j]].check=true;
										sph[tri[index].csph[j]].check=true;
									}


								}
								else
								{
									//cpol,csph�����X�g�ɒǉ�
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

		//���X�g�̉~���̓����蔻��(��������)
		for(i=0;i<pollistcount;i++)
		{
			index=pollist[i];

			if(pol[index].check==false)
			{

				pol[index].check=true;

				//�ړ���̓_1���O�p�`�̍��W�ɕϊ�
				D3DXVec3Transform(&tvec,p,&pol[index].mat);

				if(line)
				{

					//�ړ����̓_2���O�p�`�̍��W�ɕϊ�
					D3DXVec3Transform(&tvec2,p2,&pol[index].mat);

					//tvec���ォ�猩�ĉ~���̒��ɂ�������O�ɏo��

					if(distance(tvec.x,tvec.z)<r)
					{
						changedistance(&tvec.x,&tvec.z,r);
					}


					//�ォ�猩�āA�_1�����_�ɁA�_2��+X���W��Ɉړ������Ƃ��̉~���̍��W�����߂�
					pvec.x=-tvec.x;
					pvec.z=-tvec.z;
					pvec2.x=tvec2.x-tvec.x;
					pvec2.z=tvec2.z-tvec.z;
					ang=angle(pvec2.x,pvec2.z);
					rotation(&pvec.x,&pvec.z,-ang);

					//�ォ�猩���낵���Ƃ��̓_1�Ɠ_2�̋��������߂�
					dis=distance(pvec2.x,pvec2.z);


					//�ȒP�`�F�b�N
					if(pvec.x>0 && pvec.x<=dis+r && pvec.z>-r && pvec.z<r)
					{

						//�~��X���W��̌�_�����߁Aw�ɑ��
						w=pvec.x-sqrtf(r*r-pvec.z*pvec.z);

						if(w<dis)
						{

							//w��0�`1�ɕς���
							rat=w/dis;

							//rat���A�������Ă邢����tvec,tvec2��苁�߂�
							pvec2.y=tvec.y+(tvec2.y-tvec.y)*rat;

							if(pvec2.y>=0 && pvec2.y<=pol[index].h)
							{

								pvec2.x=tvec.x+(tvec2.x-tvec.x)*rat;
								pvec2.z=tvec.z+(tvec2.z-tvec.z)*rat;

								//�t�s������߂�
								D3DXMatrixInverse(&dmat,NULL,&pol[index].mat);

								//��ސݒ�
								judres.kind[judres.count]=pol[index].kind;

								//dis�����߂�
								{
									judres.dis[judres.count]=distance3(tvec2.x-pvec2.x,tvec2.y-pvec2.y,tvec2.z-pvec2.z);
								}


								//�����Ă�ʒu
								{

									//���̍��W�ɕϊ��I
									D3DXVec3Transform(&tvec3,&pvec2,&dmat);

									judres.v[judres.count].x=tvec3.x;
									judres.v[judres.count].y=tvec3.y;
									judres.v[judres.count].z=tvec3.z;

								}


								//�@���x�N�g��
								{
									pvec2.y=0;
									changedistance(&pvec2.x,&pvec2.z,1);

									//���̍��W�ɕϊ��I
									D3DXVec3Transform(&tvec3,&pvec2,&dmat);

									//�ϊ��������W����A�~���̓_1�̍��W������
									judres.n[judres.count].x=tvec3.x-sph[pol[index].csph[0]].p.x;
									judres.n[judres.count].y=tvec3.y-sph[pol[index].csph[0]].p.y;
									judres.n[judres.count].z=tvec3.z-sph[pol[index].csph[0]].p.z;
								}

								//���������߂�
								{
									//�O�ɋ��߂��~���̋O�����[�J�����W��w��dis���g���Đ��������߂�
									ang=angle(pvec.x-w,pvec.z);
									judres.p[judres.count]=dis*cosf(ang*rad);
								}


								judres.count++;

								//���̉~���ɂ��������Ƃ������Ƃ�csph�ɂ͂�����Ȃ��̂ŁAcheck��true�ɂ���
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
					//�H�����ݔ���́A�ړ��������݂̈ʒu�Ƃ��A�v�Z����i�ړ���́A�����v�Z�ł̂ݎg���j

					//Y�����猩���Ƃ��̌��_����̓_�̋��������߂�
					dis=distance(tvec.x,tvec.z);

					//�ϊ���̓_���~���͈͓̔����𒲂ׂ�
					if(dis<r && tvec.y>=0 && tvec.y<=pol[index].h)
					{

						
						//�t�s������߂�
						D3DXMatrixInverse(&dmat,NULL,&pol[index].mat);

						//��ސݒ�
						judres.kind[judres.count]=pol[index].kind;

						pvec.x=tvec.x;
						pvec.y=0;
						pvec.z=tvec.z;


						//��Ŗ@���x�N�g�������߂�Ƃ��Ɏg��
						w=pvec.x;
						h=pvec.z;

						//�H�����݃x�N�g���̑���
						{

							//�H������ł�[��(dis)�Ɩʂ̈ʒu�ɖ߂����Ƃ��̃x�N�g��(p)�𒲂ׂ�
							judres.dis[judres.count]=r-dis;

							//pvec.x,pvec.z�̒�����r-dis�ɂ���
							changedistance(&pvec.x,&pvec.z,r-dis);


							//���̍��W�ɕϊ��I
							D3DXVec3Transform(&tvec3,&pvec,&dmat);

							//�ϊ��������W����A�~���̓_1�̍��W������
							judres.v[judres.count].x=tvec3.x-sph[pol[index].csph[0]].p.x;
							judres.v[judres.count].y=tvec3.y-sph[pol[index].csph[0]].p.y;
							judres.v[judres.count].z=tvec3.z-sph[pol[index].csph[0]].p.z;


						}


						//�@���x�N�g�������߂�
						{
							pvec.x=w;
							pvec.z=h;

							//pvec.x,pvec.z�̒�����1�ɂ���
							changedistance(&pvec.x,&pvec.z,1);

							//���̍��W�ɕϊ��I
							D3DXVec3Transform(&tvec3,&pvec,&dmat);

							//�ϊ��������W����A�O�p�`�̓_1�̍��W������
							judres.n[judres.count].x=tvec3.x-sph[pol[index].csph[0]].p.x;
							judres.n[judres.count].y=tvec3.y-sph[pol[index].csph[0]].p.y;
							judres.n[judres.count].z=tvec3.z-sph[pol[index].csph[0]].p.z;

						}


						//�H�����ݐ����𑪒�(�O���x�N�g�����)
						{

							//�ړ����̓_2���O�p�`�̍��W�ɕϊ�
							D3DXVec3Transform(&tvec2,p2,&pol[index].mat);


							//�ړ����ƈړ���̈ʒu���A�����𒲂ׂ�
							
							//�_1�̊p�x�����߂�
							ang=angle(tvec.x,tvec.z);
							
							//�_2�̍��W���A�_�P��0���ɂ���悤�ɉ�]
							pvec.x=tvec2.x;
							pvec.z=tvec2.z;
							rotation(&pvec.x,&pvec.z,-ang);

							judres.p[judres.count]=-pvec.x+dis;

						}


						judres.count++;


						//���̉~���ɂ��������Ƃ������Ƃ�csph�ɂ͂�����Ȃ��̂ŁAcheck��true�ɂ���
						for(j=0;j<2;j++)
						{
							sph[pol[index].csph[j]].check=true;
						}






					}

				}

			}
		}


		//���X�g�̋��̓����蔻��(��������)
		for(i=0;i<sphlistcount;i++)
		{
			index=sphlist[i];

			if(sph[index].check==false)
			{
				sph[index].check=true;

				//�ړ���̓_1�����̍��W�ɕϊ�
				tvec.x=p->x-sph[index].p.x;
				tvec.y=p->y-sph[index].p.y;
				tvec.z=p->z-sph[index].p.z;

				if(line)
				{

					//�ړ���̓_2�����̍��W�ɕϊ�
					tvec2.x=p2->x-sph[index].p.x;
					tvec2.y=p2->y-sph[index].p.y;
					tvec2.z=p2->z-sph[index].p.z;

					//tvec�����̒��ɂ�������O�ɏo��

					if(distance3(tvec.x,tvec.y,tvec.z)<r)
					{
						changedistance3(&tvec.x,&tvec.y,&tvec.z,r);
					}



					//�_�P�����_�ɁA�_2��+X���W��Ɉړ������Ƃ��̋��Ɠ_2�̍��W�����߂�
					pvec.x=-tvec.x;
					pvec.y=-tvec.y;
					pvec.z=-tvec.z;
					pvec2.x=tvec2.x-tvec.x;
					pvec2.y=tvec2.y-tvec.y;
					pvec2.z=tvec2.z-tvec.z;

					//�܂��A�ォ�猩��X���W��ɉ�]
					ang=angle(pvec2.x,pvec2.z);
					rotation(&pvec.x,&pvec.z,-ang);
					

					//�ォ�猩�ē_1�Ɠ_2�̋��������߂�
					dis=distance(pvec2.x,pvec2.z);
					//�����Ɠ_2��Y���W���A�O(-Z)���猩��X���W��ɉ�]
					ang=angle(dis,pvec2.y);
					rotation(&pvec.x,&pvec.y,-ang);

					
					//�_1�Ɠ_2�̋��������߂�
					dis=distance3(pvec2.x,pvec2.y,pvec2.z);

					//�ȒP�`�F�b�N
					if(pvec.x>0 && pvec.x<=dis+r && pvec.z>-r && pvec.z<r && pvec.y>-r && pvec.y<r)
					{

						//����X���W��̌�_�����߁Aw�ɑ��

						w=pvec.x-sqrtf(r*r - (pvec.z*pvec.z + pvec.y*pvec.y));


						if(w<dis)
						{

							//w��0�`1�ɕς���
							rat=w/dis;

							//rat���A�������Ă邢����tvec,tvec2��苁�߂�
							pvec2.y=tvec.y+(tvec2.y-tvec.y)*rat;
							pvec2.x=tvec.x+(tvec2.x-tvec.x)*rat;
							pvec2.z=tvec.z+(tvec2.z-tvec.z)*rat;

							//��ސݒ�
							judres.kind[judres.count]=sph[index].kind;


							//dis�����߂�
							{
								judres.dis[judres.count]=distance3(tvec2.x-pvec2.x,tvec2.y-pvec2.y,tvec2.z-pvec2.z);
							}


							//�����Ă�ʒu
							{

								//���W�����[���h�ɕϊ�
								judres.v[judres.count].x=pvec2.x+sph[index].p.x;
								judres.v[judres.count].y=pvec2.y+sph[index].p.y;
								judres.v[judres.count].z=pvec2.z+sph[index].p.z;

							}


							//�@���x�N�g��
							{
								changedistance3(&pvec2.x,&pvec2.y,&pvec2.z,1);

								judres.n[judres.count].x=pvec2.x;
								judres.n[judres.count].y=pvec2.y;
								judres.n[judres.count].z=pvec2.z;
							}

							//���������߂�
							{
								//�O�ɋ��߂��~���̋O�����[�J�����W��w��dis���g���Đ��������߂�
								ang=angle(pvec.x-w,distance(pvec.z,pvec.y));
								judres.p[judres.count]=dis*cosf(ang*rad);
							}


							judres.count++;
						
						}
						
					}








				}
				else
				{

					//���_����̋��������߂�
					dis=distance3(tvec.x,tvec.y,tvec.z);

					//���_����̋������͈͓���������
					if(dis<r)
					{
						//��ސݒ�
						judres.kind[judres.count]=sph[index].kind;

						//dis�����߂�
						judres.dis[judres.count]=r-dis;

						//v�����߂�
						judres.v[judres.count].x=tvec.x;
						judres.v[judres.count].y=tvec.y;
						judres.v[judres.count].z=tvec.z;
						changedistance3(&judres.v[judres.count].x,&judres.v[judres.count].y,&judres.v[judres.count].z,r-dis);

						//n�����߂�
						judres.n[judres.count].x=tvec.x;
						judres.n[judres.count].y=tvec.y;
						judres.n[judres.count].z=tvec.z;
						changedistance3(&judres.n[judres.count].x,&judres.n[judres.count].y,&judres.n[judres.count].z,1);

						//p�����߂�
						{

							//�ړ���̓_2�����̍��W�ɕϊ�
							tvec2.x=p2->x-sph[index].p.x;
							tvec2.y=p2->y-sph[index].p.y;
							tvec2.z=p2->z-sph[index].p.z;

							//�ォ�猩���_1�̊p�x�𒲂ׂ�
							ang=angle(tvec.x,tvec.z);
							//�_2��-ang��]
							rotation(&tvec2.x,&tvec2.z,-ang);
							
							//����(-Z)����݂��_1�̊p�x�𒲂ׁA�_2�����̊p�x�̋t�ɉ�]
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


	//�ړ���̓_1�����̍��W�ɕϊ�
	tvec.x=p->x-sp->x;
	tvec.y=p->y-sp->y;
	tvec.z=p->z-sp->z;


	if(line)
	{

		//�ړ���̓_2�����̍��W�ɕϊ�
		tvec2.x=p2->x-sp->x;
		tvec2.y=p2->y-sp->y;
		tvec2.z=p2->z-sp->z;


		//tvec�����̒��ɂ�������O�ɏo��
		if(distance3(tvec.x,tvec.y,tvec.z)<sr+r)
		{
			changedistance3(&tvec.x,&tvec.y,&tvec.z,sr+r);
		}



		//�_�P�����_�ɁA�_2��+X���W��Ɉړ������Ƃ��̋��Ɠ_2�̍��W�����߂�
		pvec.x=-tvec.x;
		pvec.y=-tvec.y;
		pvec.z=-tvec.z;
		pvec2.x=tvec2.x-tvec.x;
		pvec2.y=tvec2.y-tvec.y;
		pvec2.z=tvec2.z-tvec.z;

		//�܂��A�ォ�猩��X���W��ɉ�]
		ang=angle(pvec2.x,pvec2.z);
		rotation(&pvec.x,&pvec.z,-ang);


		//�ォ�猩�ē_1�Ɠ_2�̋��������߂�
		dis=distance(pvec2.x,pvec2.z);
		//�����Ɠ_2��Y���W���A�O(-Z)���猩��X���W��ɉ�]
		ang=angle(dis,pvec2.y);
		rotation(&pvec.x,&pvec.y,-ang);


		//�_1�Ɠ_2�̋��������߂�
		dis=distance3(pvec2.x,pvec2.y,pvec2.z);

		//�ȒP�`�F�b�N
		if(pvec.x>0 && pvec.x<=dis+sr+r && pvec.z>-(sr+r) && pvec.z<sr+r && pvec.y>-(sr+r) && pvec.y<sr+r)
		{

			//����X���W��̌�_�����߁Aw�ɑ��

			w=pvec.x-sqrtf((sr+r)*(sr+r) - (pvec.z*pvec.z + pvec.y*pvec.y));


			if(w<dis)
			{

				//w��0�`1�ɕς���
				rat=w/dis;

				//rat���A�������Ă邢����tvec,tvec2��苁�߂�
				pvec2.y=tvec.y+(tvec2.y-tvec.y)*rat;
				pvec2.x=tvec.x+(tvec2.x-tvec.x)*rat;
				pvec2.z=tvec.z+(tvec2.z-tvec.z)*rat;

				//��ސݒ�
				judres.kind[judres.count]=kind;


				//dis�����߂�
				{
					judres.dis[judres.count]=distance3(tvec2.x-pvec2.x,tvec2.y-pvec2.y,tvec2.z-pvec2.z);
				}


				//�����Ă�ʒu
				{

					//���W�����[���h�ɕϊ�
					judres.v[judres.count].x=pvec2.x+sp->x;
					judres.v[judres.count].y=pvec2.y+sp->y;
					judres.v[judres.count].z=pvec2.z+sp->z;

				}


				//�@���x�N�g��
				{
					changedistance3(&pvec2.x,&pvec2.y,&pvec2.z,1);

					judres.n[judres.count].x=pvec2.x;
					judres.n[judres.count].y=pvec2.y;
					judres.n[judres.count].z=pvec2.z;
				}

				//���������߂�
				{
					//�O�ɋ��߂��~���̋O�����[�J�����W��w��dis���g���Đ��������߂�
					ang=angle(pvec.x-w,distance(pvec.z,pvec.y));
					judres.p[judres.count]=dis*cosf(ang*rad);
				}


				judres.count++;
			
			}
			
		}




	}
	else
	{
		//���_����̋��������߂�
		dis=distance3(tvec.x,tvec.y,tvec.z);

		//���̂̈�ԋ߂��ʂƂ̋������͈͓���������
		if(dis-r<sr)
		{

			//��ސݒ�
			judres.kind[judres.count]=kind;

			//dis�����߂�
			judres.dis[judres.count]=r+sr-dis;

			//v�����߂�
			judres.v[judres.count].x=tvec.x;
			judres.v[judres.count].y=tvec.y;
			judres.v[judres.count].z=tvec.z;
			changedistance3(&judres.v[judres.count].x,&judres.v[judres.count].y,&judres.v[judres.count].z,r+sr-dis);

			//n�����߂�
			judres.n[judres.count].x=tvec.x;
			judres.n[judres.count].y=tvec.y;
			judres.n[judres.count].z=tvec.z;
			changedistance3(&judres.n[judres.count].x,&judres.n[judres.count].y,&judres.n[judres.count].z,1);

			//p�����߂�
			{

				//�ړ���̓_2�����̍��W�ɕϊ�
				tvec2.x=p2->x-sp->x;
				tvec2.y=p2->y-sp->y;
				tvec2.z=p2->z-sp->z;

				//�ォ�猩���_1�̊p�x�𒲂ׂ�
				ang=angle(tvec.x,tvec.z);
				//�_2��-ang��]
				rotation(&tvec2.x,&tvec2.z,-ang);
				
				//����(-Z)����݂��_1�̊p�x�𒲂ׁA�_2�����̊p�x�̋t�ɉ�]
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

	//��Ɨp�ϐ�
	int kind;
	float dis,p;
	D3DXVECTOR3 v,n;

	//dis�̑傫�����ɕ��ёւ���
	for(i=0;i<judres.count-1;i++)
	{
		for(j=i+1;j<judres.count;j++)
		{
			if(judres.dis[i]<judres.dis[j])
			{
				//����ւ�
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



//y����ɂ��鍂��h*2�̐���(Y�����W�Ō����� -h�`h )�ƁA�O�p�`p1-p2-p3���G��邩�𒲂ׂ�֐�
bool JudClass::trilinejud(D3DXVECTOR3* p1,D3DXVECTOR3* p2,D3DXVECTOR3* p3,float h)
{


	bool cross[3]={false,false,false};//�e�ӂ�X���ƌ������邩���i�[����ϐ�

	if(p1->x * p2->x <= 0)
		cross[0]=true;
	if(p2->x * p3->x <= 0)
		cross[1]=true;
	if(p3->x * p1->x <= 0)
		cross[2]=true;


	if((int)cross[0]+(int)cross[1]+(int)cross[2]<2)//X���ƌ������Ă��Ȃ��̂ŁA���ƎO�p�`�͌������Ȃ�
		return false;

	//X���̗����ɓ_�̂���ӂŁAX����ɂ����Ƃ���̓_�����
	float z[2],y[2],rat;
	int count=0;

	if(cross[0]==true)//p1�`p2��X���ƌ�������΂���
	{
		rat=-p1->x / (p2->x - p1->x);
		z[count]=p1->z + (p2->z - p1->z)*rat;
		y[count]=p1->y + (p2->y - p1->y)*rat;
		count++;
	}
	if(cross[1]==true)//p2�`p3��X���ƌ�������΂���
	{
		rat=-p2->x / (p3->x - p2->x);
		z[count]=p2->z + (p3->z - p2->z)*rat;
		y[count]=p2->y + (p3->y - p2->y)*rat;
		count++;

		//�������̒n�_��count��2�ŁA(z[0]-z[1])���AZ�����͂���ł��Ȃ�������Acount������
		if(z[0]*z[1] > 0 && count>=2)
			count--;

	}
	if(cross[2]==true && count<2)//p3�`p1��X���ƌ�������΂���
	{
		rat=-p3->x / (p1->x - p3->x);
		z[count]=p3->z + (p1->z - p3->z)*rat;
		y[count]=p3->y + (p1->y - p3->y)*rat;
		count++;
	}


	//(z[0],y[0])-(z[1],y[1])���AZ���ƌ������邩�����߂�
	if(z[0]*z[1] > 0)
		return false;


	//(z[0],y[0])-(z[1],y[1])�ƁAZ���Ƃ̌�_�����߂�

	float hity;	//���ۂɐG��Ă���_�̍������i�[����ϐ�

	hity= y[0] + (y[1]-y[0]) * ( -z[0] / (z[1]-z[0]) );


	if(hity<=h && hity>=-h)
		return true;

	return false;
}

//x-z����ɂ���A��w*2,���s��h*2�̖ʂƁA����p1-p2���G��邩�𒲂ׂ�֐�
bool JudClass::rectlinejud(D3DXVECTOR3* p1,D3DXVECTOR3* p2,float w,float h)
{
	//p1��p2���ʂ̗����ɂ��邩���ׂ�
	if(p1->y * p2->y > 0)
		return false;

	float rat= -p1->y / (p2->y-p1->y);
	float x=p1->x + (p2->x - p1->x)*rat;
	float z=p1->z + (p2->z - p1->z)*rat;

	if(x<=w && x>=-w && z<=h && z>=-h)
		return true;

	return false;

}
