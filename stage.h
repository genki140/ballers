#ifndef STAGE_HED
#define STAGE_HED













//���e�𔚔�������
void Bakuhatu(int index)
{


	int i,j,si;
	float dis;
	D3DXMATRIX mat;


	ball[index].enable=false;

	//�U���Ȃ���ʉ�������
	if(ball[index].meshindex==BALLMESH_YUUDOU)
	{
		if(play3d)
			sd.Yudou3D[ball[index].info[1]].Sound->Stop();
		else
			sd.Yudou[ball[index].info[1]]->Stop();

		//�N���C�A���g�Ƀf�[�^����
		if(seaver)
			SendYuudouEnd(ball[index].info[1]);
	}

	//����ɂ���{�[���𐁂���΂�
	for(i=0;i<BALL_MAX;i++)
	{
		if(ball[i].enable && i!=index)
		{
			D3DXVECTOR3 wv=ball[i].ball.po-ball[index].ball.po;
			dis=D3DXVec3Length(&wv)/2.4f;
			dis=50000.0f/(dis*dis);
			if(dis>1000) dis=1000;
			if(dis<100) dis=0;
			changedistance3(&wv.x,&wv.y,&wv.z,dis);
			ball[i].ball.setmoveres(matstruct[ball[i].matindex].moveres,wv);

			if(i<playercount)
				if(!autoReplay)
					DI.SetEffect(multiplayindex(i),dis/20,(int)(dis/20),0);
		}
	}



	if(seaver)
	{

		//��������
		for(j=0;j<BOMB_MAX;j++)
		{
			if(Bomb[j].sizemax==0)
			{
				Bomb[j].sizemax=80;
				Bomb[j].p=ball[index].ball.po;
				Bomb[j].size=1.0f;
				Bomb[j].sizeadd=1.5f;
				Bomb[j].axis=D3DXVECTOR3(rnd(1.0f)-0.5f,rnd(1.0f)-0.5f,rnd(1.0f)-0.5f);
				D3DXMatrixRotationX( &Bomb[j].mat, rnd(360)*rad );
				D3DXMatrixRotationY( &mat, rnd(360)*rad );
				Bomb[j].mat*=mat;
				D3DXMatrixRotationZ( &mat, rnd(360)*rad );
				Bomb[j].mat*=mat;


				//�N���C�A���g�Ƀf�[�^�𑗂�
				SendBakuhuu(j);

				break;
			}
		}


		//���ʉ��Đ�
		if(play3d)
		{

			si=stopindex3d(sd.Bomb3D);
			sd.Bomb3D[si].Param.vPosition=ball[index].ball.po;
			sd.Bomb3D[si].Param.vVelocity=D3DXVECTOR3(0,0,0);
			sd.Bomb3D[si].Buffer->SetAllParameters( &sd.Bomb3D[si].Param, DS3D_DEFERRED );
			SOUND_PLAY(sd.Bomb3D[si].Sound);

		}
		else
		{
			si=stopindex(sd.Bomb);
			SOUND_PLAY(sd.Bomb[si]);
			sd.Bomb[si]->GetBuffer(0)->SetVolume(getvolume(ball[index].ball.po));
		}


	}


}




bool StageMeshLoad()
{
	char xfilename[MAX_PATH];

	if(stagekind==SELECTGAME_STAGE)
		sprintf(xfilename,"Data/Object/Stage/%d.x",stagenum+1);
	else
		sprintf(xfilename,"Data/Object/Corce/%d.x",stagenum+1);

//	stagemesh.Release();
	if(stagemesh.Create(DG.Device,xfilename,Setting.MultiTextureEnable)==false)
	{
		return false;
	}
	return true;
}



//�X�e�[�W�ݒ�!!(3D���ǂݍ��݂܂�)
bool StageSetting()
{

	int i;

	InfoReset();
	InfoStartCount();

	gameframe=0;

	//�S�{�[���̏�����
	for(i=0;i<BALL_MAX;i++)
	{
		ball[i].enable=false;
		ball[i].gv=D3DXVECTOR3(0,1,0);
	}

//	Ghost=true;

	for(i=0;i<5;i++)
		feed[i].Reset();

	//-------------------------------�L�����z�u----------------------------------

	for(i=0;i<playercount;i++)
	{
		ball[i].enable=true;
		ball[i].deletecount=0;
		ball[i].ball.reset();
		ball[i].meshindex=(player[i].charnum==5 ? 0 : player[i].charnum);
		ball[i].matindex=MATKIND_CHARA+player[i].charnum;

		player[i].goal=false;
		player[i].FinalLap=false;
		player[i].InputEnable=true;
		player[i].par=player[i].temppar=0;
		player[i].lap=1;
		player[i].itemkind=ITEMKIND_NONE;
		player[i].usekind=ITEMKIND_NONE;
		player[i].ClientItem=ITEMKIND_NONE;
		player[i].MutekiCount=0;

		if(stagekind==SELECTGAME_STAGE)
		{
			ball[i].ball.po.y=5;
			player[i].cpo=player[i].cponext=D3DXVECTOR3(0,10,-20);
//			ball[i].ball.po=D3DXVECTOR3(240,60,220);
		}
		else
		{
			//�l���ɂ���Ĉʒu�͈Ⴄ
			ball[i].ball.po.x=(playercount-1)*-2+i*4.0f;

			if(playercount==1)
				ball[i].ball.po.y=5;
			else
				ball[i].ball.po.y=3+rnd(4);

			player[i].cpo=player[i].cponext=D3DXVECTOR3(ball[i].ball.po.x,8,-50);
		}

		player[i].ballold=ball[i].ball.po;

		ball[i].ball.w=character[player[i].charnum].w;
		ball[i].ball.r=character[player[i].charnum].r;


		//�J�����ʒu�����ݒ�
		player[i].cup=player[i].cupnext=D3DXVECTOR3(0,1,0);


//		ball[i].ball.po=D3DXVECTOR3(-203.5f,10.8f,-243.41f);
//		ball[i].ball.po=D3DXVECTOR3(0,0,-129.75);

//		ball[i].ball.po=D3DXVECTOR3(-70.0f,70.0f,-400);

	}


	//ball[1].gv=D3DXVECTOR3(0,-1,0);
	//ball[0].ball.po=D3DXVECTOR3(0,10,0);
	//ball[1].ball.po=D3DXVECTOR3(0,7,0);



	//���ʉ�����
	SoundReset();


	//��������
	for(i=0;i<BOMB_MAX;i++)
		Bomb[i].sizemax=0;
	
	//stagestage������
	for(i=0;i<STAGESTATE_MAX;i++)
	{
		stagestate[i].s=0;
		stagestate[i].s2=0;
		stagestate[i].v=D3DXVECTOR3(0,0,0);
		stagestate[i].v2=D3DXVECTOR3(0,0,0);
	}

	//---------------------------------------------------------------------------



	//��judfilename2�͂��������

	char judfilename[MAX_PATH],judfilename2[MAX_PATH];

	if(stagekind==SELECTGAME_STAGE)
	{
		sprintf(judfilename,"Data/Data/Judgment/Stage/%d.jud",stagenum+1);
		sprintf(judfilename2,"Data/Object/Stage/Jud/%d.x",stagenum+1);
	}
	else
	{
		sprintf(judfilename,"Data/Data/Judgment/Corce/%d.jud",stagenum+1);
		sprintf(judfilename2,"Data/Object/Corce/Jud/%d.x",stagenum+1);
	}



//	//�����蔻��ǂݍ���
//
//	if(buttonstate[4].startpress)
//	{
////	MessageBox(NULL,"����t�@�C�������o��","",MB_OK);
//		judc.CreateJudFile(DG.Device,judfilename,judfilename2,10,10,10);
////		MessageBox(NULL,"����t�@�C���̏����o������","",MB_OK);
//	}


	//�`�F�b�N�t�@�C���쐬
	//createcheckfile(judfilename);
	//�s���`�F�b�N
	if(checkfile(judfilename)==false)
		return false;


	if(judc.LoadJudFile(judfilename)==false)
		return false;

	//���b�V�������S�ɏ�����
	stagemesh.Reset();
	stagemesh.Release();
	//���b�V���ǂݍ���
	if(StageMeshLoad()==false)
	{
		return false;
	}

	//���[�X�������犽���Đ�

	if(stagekind!=SELECTGAME_STAGE)
		SOUND_PLAY(sd.Kansei);




	Time=0;




	//�X�e�[�W�Z�b�e�B���O!!

	int index;
	D3DXMATRIX matrix;

	guncount=0;
	windcount=0;
	itemcount=0;





	if(stagekind==SELECTGAME_STAGE)//�X�e�[�W���[�h
	{


		//�X�e�[�W�S�̂̊ȒP�Ȑݒ�

		//����
		if((stagenum>=0 && stagenum<=3) || (stagenum>=13 && stagenum<=16))
		{

			index=0;
			stagestate[index].kind=ITAKIND_CORCEOUT;
			stagestate[index].matindex=MATKIND_SIBA;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_KI;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_ISI;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_SUNA;

		}

		//���A
		else if((stagenum>=4 && stagenum<=7) || (stagenum>=17 && stagenum<=20))
		{
			index=0;
			stagestate[index].kind=ITAKIND_CORCEOUT;
			stagestate[index].matindex=MATKIND_NULL;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_TUTI;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_ISI;

		}

		else if(stagenum==10)//�e�N�m3
		{
			index=0;
			stagestate[index].kind=ITAKIND_CORCEOUT;
			stagestate[index].matindex=MATKIND_TETU;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_TETU;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_TETU2;
		}
		else if(stagenum==21)//EX�e�N�m1
		{
			index=0;
			stagestate[index].kind=ITAKIND_CORCEOUT;
			stagestate[index].matindex=MATKIND_TETU;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_TETU;
			index++;
			stagestate[index].kind=ITAKIND_ROTATE;
			stagestate[index].matindex=MATKIND_TETU;
			stagestate[index].v=D3DXVECTOR3(-58.67f,-46.26f,-3.38f);
			stagestate[index].v2=D3DXVECTOR3(0,2,0);
		}
		else if(stagenum==22)//EX�e�N�m2
		{
			index=0;
			stagestate[index].kind=ITAKIND_CORCEOUT;
			stagestate[index].matindex=MATKIND_TETU;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_TETU;
			index++;
			stagestate[index].kind=ITAKIND_ROTATE;
			stagestate[index].matindex=MATKIND_TETU;
			stagestate[index].v=D3DXVECTOR3(-54.74f,0,33.56f);
			stagestate[index].v2=D3DXVECTOR3(0,2,0);
			index++;
			stagestate[index].kind=ITAKIND_ROTATE;
			stagestate[index].matindex=MATKIND_TETU;
			stagestate[index].v=D3DXVECTOR3(-105.4f,30.38f,0);
			stagestate[index].v2=D3DXVECTOR3(0,0,-1.5f);
			index++;
			stagestate[index].kind=ITAKIND_ROTATE;
			stagestate[index].matindex=MATKIND_TETU;
			stagestate[index].v=D3DXVECTOR3(-119.80f,30.38f,0);
			stagestate[index].v2=D3DXVECTOR3(0,0,1.5f);

		}
		else if(stagenum==23)//EX�e�N�m3
		{
			index=0;
			stagestate[index].kind=ITAKIND_CORCEOUT;
			stagestate[index].matindex=MATKIND_TETU;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_TETU;
			index++;
			stagestate[index].kind=ITAKIND_ROTATE;
			stagestate[index].matindex=MATKIND_TETU;
			stagestate[index].v=D3DXVECTOR3(63.09f,0,-28.88f);
			stagestate[index].v2=D3DXVECTOR3(0,10,0);
		}
		else if(stagenum==24)//EX�e�N�m4
		{
			index=0;
			stagestate[index].kind=ITAKIND_CORCEOUT;
			stagestate[index].matindex=MATKIND_TETU;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_TETU;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_TETU;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_TETU;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_TETU;

			index++;
			stagestate[index].kind=ITAKIND_ROTATE;
			stagestate[index].matindex=MATKIND_TETU;
			stagestate[index].v=D3DXVECTOR3(0.0f,8.81f,-10.12f);
			stagestate[index].v2=D3DXVECTOR3(4,0,0);

			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_TETU;

			index++;
			stagestate[index].kind=ITAKIND_MOVE;
			stagestate[index].matindex=MATKIND_GOMU;
			stagestate[index].v=D3DXVECTOR3(-0.3f,0,0);
			index++;
			stagestate[index].kind=ITAKIND_MOVE;
			stagestate[index].matindex=MATKIND_GOMU;
			stagestate[index].v=D3DXVECTOR3(0.3f,0,0);

			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_TETU;

			index++;
			stagestate[index].kind=ITAKIND_ROTATE;
			stagestate[index].matindex=MATKIND_TETU;
			stagestate[index].v=D3DXVECTOR3(18.28f,0.0f,45.66f);
			stagestate[index].v2=D3DXVECTOR3(0,3,0);

		}



		//���̑��̃e�N�m
		else if((stagenum>=8 && stagenum<=11) || (stagenum>=21 && stagenum<=24))
		{
			index=0;
			stagestate[index].kind=ITAKIND_CORCEOUT;
			stagestate[index].matindex=MATKIND_TETU;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_TETU;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_TETU;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_TETU;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_TETU;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_TETU;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_TETU;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_TETU;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_TETU;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_TETU;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_TETU;

		}


		//�َ���
		else if(stagenum==12 || (stagenum>=25 && stagenum<=29))
		{
			index=0;
			stagestate[index].kind=ITAKIND_CORCEOUT;
			stagestate[index].matindex=MATKIND_NULL;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_IZIGEN;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_GURABI;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_IZIGEN;
		}















		//�X�e�[�W���Ƃׂ̍��Ȑݒ�



		if(stagenum==9)
		{

			//��C�ݒu
			gun[guncount].p=D3DXVECTOR3(0.0f,-60.31f,137.27f);
			gun[guncount].v=D3DXVECTOR3(1.5f,0,0);
			gun[guncount].kind=1;
			gun[guncount].mat=D3DXMATRIX(0,0,-1,0,0,1,0,0,1,0,0,0,0,0,0,1);
			gun[guncount].mat._41=gun[guncount].p.x;
			gun[guncount].mat._42=gun[guncount].p.y;
			gun[guncount].mat._43=gun[guncount].p.z;
			guncount++;
		}


		else if(stagenum==11)
		{
			index=4;
			ball[index].enable=true;
			ball[index].deletecount=0;
			ball[index].meshindex=BALLMESH_TETU2;
			ball[index].ball.reset();
			ball[index].ball.po=D3DXVECTOR3(-7.15f,9.92f,55.62f);
			ball[index].ball.r=0.77f-0.02f;
			ball[index].ball.w=50;
			ball[index].matindex=MATKIND_TETUTAMA;
			index++;
			ball[index].enable=true;
			ball[index].deletecount=0;
			ball[index].meshindex=BALLMESH_TETU3;
			ball[index].ball.reset();
			ball[index].ball.po=D3DXVECTOR3(-3.99f,6.81f,43.09f);
			ball[index].ball.r=2.55f-0.04f;
			ball[index].ball.w=200;
			ball[index].matindex=MATKIND_TETUTAMA;
			index++;
			ball[index].enable=true;
			ball[index].deletecount=0;
			ball[index].meshindex=BALLMESH_TETU4;
			ball[index].ball.reset();
			ball[index].ball.po=D3DXVECTOR3(-50.96f,31.62f,36.65f);
			ball[index].ball.r=3.8f;
			ball[index].ball.w=500;
			ball[index].matindex=MATKIND_TETUTAMA;

			//��C�ݒu
			gun[guncount].p=D3DXVECTOR3(26.44f,-9.58f+1.5f,24.29f);
			gun[guncount].v=D3DXVECTOR3(0,0,0.7f);
			gun[guncount].kind=1;
			gun[guncount].mat=D3DXMATRIX(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
			gun[guncount].mat._41=gun[guncount].p.x;
			gun[guncount].mat._42=gun[guncount].p.y;
			gun[guncount].mat._43=gun[guncount].p.z;
			guncount++;
		}




		else if(stagenum==17)
		{
			index=4;
			ball[index].enable=true;
			ball[index].deletecount=0;
			ball[index].meshindex=BALLMESH_IWA;
			ball[index].ball.reset();
			ball[index].ball.po=D3DXVECTOR3(-1.55f,21.8f,-26.26f);
			ball[index].ball.r=2.3f;
			ball[index].ball.w=200;
			ball[index].matindex=MATKIND_ISI;
		}

		else if(stagenum==19)
		{
			index=4;
			ball[index].enable=true;
			ball[index].deletecount=0;
			ball[index].meshindex=BALLMESH_IWA2;
			ball[index].ball.reset();
			ball[index].ball.po=D3DXVECTOR3(0.0f,-23.43f,185.18f);
			ball[index].ball.r=15.0f;
			ball[index].ball.w=1000;
			ball[index].matindex=MATKIND_ISI;
		}


		else if(stagenum==24)
		{

			//��C�ݒu
			gun[guncount].p=D3DXVECTOR3(112.05f,33.94f,49.8f);
			gun[guncount].v=D3DXVECTOR3(0,-2.0f,0);
			gun[guncount].kind=1;
			D3DXMatrixRotationX(&gun[guncount].mat,90*rad);
			D3DXMatrixRotationY(&matrix,90*rad);
			gun[guncount].mat*=matrix;
			gun[guncount].mat._41=gun[guncount].p.x;
			gun[guncount].mat._42=gun[guncount].p.y;
			gun[guncount].mat._43=gun[guncount].p.z;
			guncount++;

			gun[guncount].p=D3DXVECTOR3(112.05f,33.94f,41.19f);
			gun[guncount].v=D3DXVECTOR3(0,-2.0f,0);
			gun[guncount].kind=1;
			D3DXMatrixRotationX(&gun[guncount].mat,90*rad);
			D3DXMatrixRotationY(&matrix,90*rad);
			gun[guncount].mat*=matrix;
			gun[guncount].mat._41=gun[guncount].p.x;
			gun[guncount].mat._42=gun[guncount].p.y;
			gun[guncount].mat._43=gun[guncount].p.z;
			guncount++;

			gun[guncount].p=D3DXVECTOR3(196.93f,43.47f+1.5f,56.4f-10.0f);
			gun[guncount].v=D3DXVECTOR3(0,0,2.0f);
			gun[guncount].kind=1;
			gun[guncount].mat=D3DXMATRIX(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
			gun[guncount].mat._41=gun[guncount].p.x;
			gun[guncount].mat._42=gun[guncount].p.y;
			gun[guncount].mat._43=gun[guncount].p.z;
			guncount++;

			gun[guncount].p=D3DXVECTOR3(174.83f,43.77f+1.8f,93.07f);
			gun[guncount].v=D3DXVECTOR3(1.0f,0,0);
			gun[guncount].kind=1;
			D3DXMatrixRotationY(&gun[guncount].mat,90*rad);
			gun[guncount].mat._41=gun[guncount].p.x;
			gun[guncount].mat._42=gun[guncount].p.y;
			gun[guncount].mat._43=gun[guncount].p.z;
			guncount++;
			gun[guncount].p=D3DXVECTOR3(174.83f,43.77f+1.8f,167.99f);
			gun[guncount].v=D3DXVECTOR3(1.0f,0,0);
			gun[guncount].kind=1;
			D3DXMatrixRotationY(&gun[guncount].mat,90*rad);
			gun[guncount].mat._41=gun[guncount].p.x;
			gun[guncount].mat._42=gun[guncount].p.y;
			gun[guncount].mat._43=gun[guncount].p.z;
			guncount++;
			gun[guncount].p=D3DXVECTOR3(220.06f,43.77f+1.8f,129.69f);
			gun[guncount].v=D3DXVECTOR3(-1.0f,0,0);
			gun[guncount].kind=1;
			D3DXMatrixRotationY(&gun[guncount].mat,-90*rad);
			gun[guncount].mat._41=gun[guncount].p.x;
			gun[guncount].mat._42=gun[guncount].p.y;
			gun[guncount].mat._43=gun[guncount].p.z;
			guncount++;

		
		}

		//�Ō�̃X�^�b�t���[��
		else if(stagenum==29)
		{
			gun[guncount].p=D3DXVECTOR3(105.73f,-51.0f,107.98f);
			gun[guncount].v=D3DXVECTOR3(0.0f,1.5f,0.0f);
			gun[guncount].kind=2;
			D3DXMatrixRotationX(&matrix,-90*rad);
			gun[guncount].mat=matrix;
			D3DXMatrixRotationY(&matrix,-45*rad);
			gun[guncount].mat*=matrix;
			gun[guncount].mat._41=gun[guncount].p.x;
			gun[guncount].mat._42=gun[guncount].p.y;
			gun[guncount].mat._43=gun[guncount].p.z;
			guncount++;

			gun[guncount].p=D3DXVECTOR3(105.73f,18.0f,107.98f);
			gun[guncount].v=D3DXVECTOR3(-0.9f,0.0f,-0.9f);
			gun[guncount].kind=2;
			D3DXMatrixRotationX(&matrix,-90*rad);
			gun[guncount].mat=matrix;
			D3DXMatrixRotationZ(&matrix,90*rad);
			gun[guncount].mat*=matrix;
			D3DXMatrixRotationY(&matrix,-45*rad);
			gun[guncount].mat*=matrix;
			gun[guncount].mat._41=gun[guncount].p.x;
			gun[guncount].mat._42=gun[guncount].p.y;
			gun[guncount].mat._43=gun[guncount].p.z;
			guncount++;

			gun[guncount].p=D3DXVECTOR3(-161.42f,-88.0f,-78.19f);
			gun[guncount].v=D3DXVECTOR3(0.0f,2.0f,0.0f);
			gun[guncount].kind=2;
			D3DXMatrixRotationX(&matrix,-90*rad);
			gun[guncount].mat=matrix;
			gun[guncount].mat._41=gun[guncount].p.x;
			gun[guncount].mat._42=gun[guncount].p.y;
			gun[guncount].mat._43=gun[guncount].p.z;
			guncount++;
		}


		goal.p=D3DXVECTOR3(22.11f,10000.03f,83.55f);
		goal.v=D3DXVECTOR3(0,0.5f,0);
		rTime=1000*60;

		//�S�[���z�u
		if(stagenum==0)
		{
			rTime=50*60;
			goal.p=D3DXVECTOR3(-39.87f,1.73f,-76.92f);
		}
		else if(stagenum==1)
		{
			rTime=80*60;
			goal.p=D3DXVECTOR3(19.97f,-1.61f,174.09f);
		}
		else if(stagenum==2)
		{
			rTime=80*60;
			goal.p=D3DXVECTOR3(146.0f,-3.2f,65.58f);
		}
		else if(stagenum==3)
		{
			rTime=100*60;
			goal.p=D3DXVECTOR3(22.64f,0.03f,89.89f);
		}
		else if(stagenum==13)
		{
			rTime=120*60;
			goal.p=D3DXVECTOR3(55.91f,0,-15.83f);
		}
		else if(stagenum==14)
		{
			rTime=100*60;
			goal.p=D3DXVECTOR3(-8.29f,-0.21f,72.85f);
		}
		else if(stagenum==15)
		{
			rTime=200*60;
			goal.p=D3DXVECTOR3(-29.11f,29.36f,16.49f);
		}
		else if(stagenum==16)
		{
			rTime=200*60;
			goal.p=D3DXVECTOR3(-31.40f,13.40f,171.79f);
		}


		else if(stagenum==4)
		{
			rTime=150*60;
			goal.p=D3DXVECTOR3(36.15f,88.65f,126.18f);
		}
		else if(stagenum==5)
		{
			rTime=150*60;
			goal.p=D3DXVECTOR3(32.34f,-50.60f,350.36f);
		}
		else if(stagenum==6)
		{
			rTime=200*60;
			goal.p=D3DXVECTOR3(-122.18f,-12.6f,77.81f);
		}
		else if(stagenum==7)
		{
			rTime=120*60;
			goal.p=D3DXVECTOR3(-26.04f,-15.28f,183.82f);
		}

		else if(stagenum==8)
		{
			rTime=200*60;
			goal.p=D3DXVECTOR3(30.51f,25.55f,103.19f);
		}
		else if(stagenum==9)
		{
			rTime=160*60;
			goal.p=D3DXVECTOR3(11.13f,-73.98f,205.21f);
		}
		else if(stagenum==10)
		{
			rTime=120*60;
			goal.p=D3DXVECTOR3(88.87f,40.19f,188.36f);
		}
		else if(stagenum==11)
		{
			rTime=300*60;
			goal.p=D3DXVECTOR3(26.33f,-18.66f,62.36f);
		}

		else if(stagenum==17)
		{
			rTime=160*60;
			goal.p=D3DXVECTOR3(-71.69f,51.52f,-104.13f);
		}
		else if(stagenum==18)
		{
			rTime=200*60;
			goal.p=D3DXVECTOR3(-49.89f,195.71f,22.56f);
		}
		else if(stagenum==19)
		{
			rTime=300*60;
			goal.p=D3DXVECTOR3(183.85f,-39.16f,285.35f);
		}
		else if(stagenum==20)
		{
			rTime=300*60;
			goal.p=D3DXVECTOR3(0.0f,74.49f,256.44f);
		}

		else if(stagenum==21)
		{
			rTime=300*60;
			goal.p=D3DXVECTOR3(-58.67f,-46.26f,-3.38f);
		}
		else if(stagenum==22)
		{
			rTime=150*60;
			goal.p=D3DXVECTOR3(-134.66f,36.56f,152.98f);
		}
		else if(stagenum==23)
		{
			rTime=300*60;
			goal.p=D3DXVECTOR3(-31.51f,76.47f,52.37f);
		}
		else if(stagenum==24)
		{
			rTime=400*60;
			goal.p=D3DXVECTOR3(196.93f,43.47f,56.4f);
		}

		else if(stagenum==25)
		{
			rTime=120*60;
			goal.p=D3DXVECTOR3(-88.1f,-11.83f,72.68f);
			goal.v=D3DXVECTOR3(0,0,0.5f);
		}

		else if(stagenum==26)
		{
			rTime=120*60;
			goal.p=D3DXVECTOR3(49.78f,-274.0f,-10.34f);
			goal.v=D3DXVECTOR3(0,-0.5f,0);
		}
		else if(stagenum==27)
		{
			rTime=300*60;
			goal.p=D3DXVECTOR3(-0.01f,-1.04f,19.86f);
		}
		else if(stagenum==28)
		{
			rTime=200*60;
			goal.p=D3DXVECTOR3(0.0f,-14.57f,0.0f);
			goal.v=D3DXVECTOR3(0,-0.5f,0);
		}
		else if(stagenum==29)
		{
			rTime=200*60;
			goal.p=D3DXVECTOR3(-160.23f,100.0f,-78.19f);
			goal.v=D3DXVECTOR3(-0.3f,0.3f,0);
		}

		else if(stagenum==12)
		{
			rTime=150*60;
			goal.p=D3DXVECTOR3(-121.42f,-251.32f,127.88f);
		}








		//�S�[���̕��ˌ��z�u
		goal.index=windcount;
		wind[windcount].enable=true;
		wind[windcount].kind=stagenum<12 ? stagenum/4 : (stagenum-13)/4;
		if(stagenum==12 || stagenum==29) wind[windcount].kind=3;//�X�^�b�t���[���َ͈����̉�
		wind[windcount].p=goal.p;
		wind[windcount].v=goal.v;
		wind[windcount].dis=10;
		wind[windcount].ang=30;
		wind[windcount].mat=D3DXMATRIX(1,0,0,0,0,1,0,0,0,0,1,0,wind[windcount].p.x,wind[windcount].p.y,wind[windcount].p.z,1);

		if(stagenum==25)
		{
			D3DXMatrixRotationX(&matrix,90*rad);
			wind[windcount].mat=matrix*D3DXMATRIX(1,0,0,0,0,1,0,0,0,0,1,0,wind[windcount].p.x,wind[windcount].p.y,wind[windcount].p.z,1);
		}
		else if(stagenum==29)
		{
//			D3DXMatrixRotationX(&matrix,180*rad);
			wind[windcount].mat=matrix*D3DXMATRIX(1,0,0,0,0,1,0,0,0,0,1,0,0,-1000000,0,1);
		}

		windcount++;


		//�X�^�[�g�̕��ˌ��z�u
		wind[windcount].enable=true;
		wind[windcount].kind=stagenum<12 ? stagenum/4 : (stagenum-13)/4;
		if(stagenum==12 || stagenum==29) wind[windcount].kind=3;//�X�^�b�t���[���َ͈����̉�
		wind[windcount].p=D3DXVECTOR3(0,0,0);
		wind[windcount].v=D3DXVECTOR3(0,0.5f,0);
		wind[windcount].dis=10;
		wind[windcount].ang=30;
		wind[windcount].mat=D3DXMATRIX(1,0,0,0,0,1,0,0,0,0,1,0,wind[windcount].p.x,wind[windcount].p.y,wind[windcount].p.z,1);
		windcount++;



	}
	else//�o�[�T�X���[�h
	{

		lap=2;


		if(stagenum==0)//����1
		{



			index=0;

			stagestate[index].kind=ITAKIND_CORCEOUT;
			stagestate[index].matindex=MATKIND_SIBA;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_KI;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_ISI;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_SUNA;
			index++;
			stagestate[index].kind=ITAKIND_CORCEOUT;
			stagestate[index].matindex=MATKIND_NULL;



			//stagestate[index].v=D3DXVECTOR3(217.29f,10.79f,256.76f);
			//stagestate[index].v2=D3DXVECTOR3(1.0f,0,0);

			index=stagemesh.TexNameIndex("Suna[2].tga");
			if(index!=-1)
			{
				stagemesh.ColorOpereter[index]=D3DTOP_ADD;
				stagemesh.AlphaOpereter[index]=D3DTOP_MODULATE;
				stagemesh.UVScalingX[index]=0.1f;
				stagemesh.UVScalingY[index]=0.1f;
				stagemesh.UVTranslationX[index]=4.5f;
				stagemesh.UVTranslationY[index]=4.5f;
				stagemesh.UVRotation[index]=0;

			}



			wind[windcount].enable=true;
			wind[windcount].kind=0;
			wind[windcount].p=D3DXVECTOR3(170.95f,-0.12f,-6.45f);
			wind[windcount].v=D3DXVECTOR3(0,0.5f,0);
			wind[windcount].dis=20;
			wind[windcount].ang=30;
			wind[windcount].mat=D3DXMATRIX(1,0,0,0,0,1,0,0,0,0,1,0,wind[windcount].p.x,wind[windcount].p.y,wind[windcount].p.z,1);
			windcount++;


			wind[windcount].enable=true;
			wind[windcount].kind=0;
			wind[windcount].p=D3DXVECTOR3(41.28f,1.8f,-103.90f);
			wind[windcount].v=D3DXVECTOR3(0,0,-0.5f);
			wind[windcount].dis=10;
			wind[windcount].ang=40;
			D3DXMatrixRotationX(&wind[windcount].mat,-90*rad);
			matrix=D3DXMATRIX(1,0,0,0,0,1,0,0,0,0,1,0,wind[windcount].p.x,wind[windcount].p.y,wind[windcount].p.z,1);
			wind[windcount].mat*=matrix;
			windcount++;


			wind[windcount].enable=true;
			wind[windcount].kind=0;
			wind[windcount].p=D3DXVECTOR3(87.27f,1.8f,-100.43f);
			wind[windcount].v=D3DXVECTOR3(0,0,0.5f);
			wind[windcount].dis=10;
			wind[windcount].ang=40;
			D3DXMatrixRotationX(&wind[windcount].mat,90*rad);
			matrix=D3DXMATRIX(1,0,0,0,0,1,0,0,0,0,1,0,wind[windcount].p.x,wind[windcount].p.y,wind[windcount].p.z,1);
			wind[windcount].mat*=matrix;
			windcount++;



			wind[windcount].enable=true;
			wind[windcount].kind=0;
			wind[windcount].p=D3DXVECTOR3(140.67f,1.8f,-110.31f);
			wind[windcount].v=D3DXVECTOR3(0,0,-0.5f);
			wind[windcount].dis=10;
			wind[windcount].ang=40;
			D3DXMatrixRotationX(&wind[windcount].mat,-90*rad);
			matrix=D3DXMATRIX(1,0,0,0,0,1,0,0,0,0,1,0,wind[windcount].p.x,wind[windcount].p.y,wind[windcount].p.z,1);
			wind[windcount].mat*=matrix;
			windcount++;




		}

		else if(stagenum==1)//����2
		{

			index=0;

			stagestate[index].kind=ITAKIND_CORCEOUT;
			stagestate[index].matindex=MATKIND_SIBA;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_KI;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_ISI;
//			index++;
//			stagestate[index].kind=ITAKIND_NORMAL;
//			stagestate[index].matindex=MATKIND_KI;
//			stagestate[index].matindex=MATKIND_MIZU;
			index++;
			stagestate[index].kind=ITAKIND_CORCEOUT;
			stagestate[index].matindex=MATKIND_NULL;


			wind[windcount].enable=true;
			wind[windcount].kind=0;
			wind[windcount].p=D3DXVECTOR3(50.99f,0.09f,-335.29f);
			wind[windcount].v=D3DXVECTOR3(0,0.5f,0.5f);
			wind[windcount].dis=15;
			wind[windcount].ang=45;
			D3DXMatrixRotationX(&wind[windcount].mat,45*rad);
			matrix=D3DXMATRIX(1,0,0,0,0,1,0,0,0,0,1,0,wind[windcount].p.x,wind[windcount].p.y,wind[windcount].p.z,1);
			wind[windcount].mat*=matrix;
			windcount++;


			wind[windcount].enable=true;
			wind[windcount].kind=0;
			wind[windcount].p=D3DXVECTOR3(50.99f,0.09f,-308.93f);
			wind[windcount].v=D3DXVECTOR3(0,0.5f,-0.5f);
			wind[windcount].dis=15;
			wind[windcount].ang=45;
			D3DXMatrixRotationX(&wind[windcount].mat,-45*rad);
			matrix=D3DXMATRIX(1,0,0,0,0,1,0,0,0,0,1,0,wind[windcount].p.x,wind[windcount].p.y,wind[windcount].p.z,1);
			wind[windcount].mat*=matrix;
			windcount++;

		}



		else if(stagenum==2)//����3
		{

			index=0;

			stagestate[index].kind=ITAKIND_CORCEOUT;
			stagestate[index].matindex=MATKIND_SIBA;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_KI;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_ISI;
			index++;
			stagestate[index].kind=ITAKIND_CORCEOUT;
			stagestate[index].matindex=MATKIND_NULL;



		}




		else if(stagenum==3)//���A1
		{

			index=0;

			stagestate[index].kind=ITAKIND_CORCEOUT;
			stagestate[index].matindex=MATKIND_TUTI;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_TUTI;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_ISI;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_TETU;
			index++;
			stagestate[index].kind=ITAKIND_CORCEOUT;
			stagestate[index].matindex=MATKIND_NULL;


			//��C�ݒ�

			gun[guncount].p=D3DXVECTOR3(229.97f,-421.26f,-325.92f);
			gun[guncount].v=D3DXVECTOR3(0,1.5f,0);
			gun[guncount].kind=0;
			D3DXMatrixRotationX(&gun[guncount].mat,-90*rad);
			gun[guncount].mat._41=gun[guncount].p.x;
			gun[guncount].mat._42=gun[guncount].p.y;
			gun[guncount].mat._43=gun[guncount].p.z;
			guncount++;

			gun[guncount].p=D3DXVECTOR3(215.97f,-421.26f,-325.92f);
			gun[guncount].v=D3DXVECTOR3(0,1.5f,0);
			gun[guncount].kind=0;
			D3DXMatrixRotationX(&gun[guncount].mat,-90*rad);
			gun[guncount].mat._41=gun[guncount].p.x;
			gun[guncount].mat._42=gun[guncount].p.y;
			gun[guncount].mat._43=gun[guncount].p.z;
			guncount++;


			gun[guncount].p=D3DXVECTOR3(229.97f+1.0f,-232.90f,-231.32f);
			gun[guncount].v=D3DXVECTOR3(0,1.5f,0);
			gun[guncount].kind=0;
			D3DXMatrixRotationX(&gun[guncount].mat,-90*rad);
			D3DXMatrixRotationY(&matrix,90*rad);
			gun[guncount].mat*=matrix;
			gun[guncount].mat._41=gun[guncount].p.x;
			gun[guncount].mat._42=gun[guncount].p.y;
			gun[guncount].mat._43=gun[guncount].p.z;
			guncount++;

			gun[guncount].p=D3DXVECTOR3(229.97f+1.0f,-232.90f,-245.32f);
			gun[guncount].v=D3DXVECTOR3(0,1.5f,0);
			gun[guncount].kind=0;
			D3DXMatrixRotationX(&gun[guncount].mat,-90*rad);
			D3DXMatrixRotationY(&matrix,90*rad);
			gun[guncount].mat*=matrix;
			gun[guncount].mat._41=gun[guncount].p.x;
			gun[guncount].mat._42=gun[guncount].p.y;
			gun[guncount].mat._43=gun[guncount].p.z;
			guncount++;


			gun[guncount].p=D3DXVECTOR3(596.26f,24.96f,-222.28f);
			gun[guncount].v=D3DXVECTOR3(-1.3f,1.5f,0.24f);
			gun[guncount].kind=0;
			D3DXMatrixRotationX(&gun[guncount].mat,-90*rad);
			D3DXMatrixRotationY(&matrix,90*rad);
			gun[guncount].mat*=matrix;
			D3DXMatrixRotationZ(&matrix,50*rad);
			gun[guncount].mat*=matrix;
			gun[guncount].mat._41=gun[guncount].p.x;
			gun[guncount].mat._42=gun[guncount].p.y;
			gun[guncount].mat._43=gun[guncount].p.z;
			guncount++;


			gun[guncount].p=D3DXVECTOR3(596.26f,24.96f,-238.50f);
			gun[guncount].v=D3DXVECTOR3(-1.3f,1.5f,0.24f);
			gun[guncount].kind=0;
			D3DXMatrixRotationX(&gun[guncount].mat,-90*rad);
			D3DXMatrixRotationY(&matrix,90*rad);
			gun[guncount].mat*=matrix;
			D3DXMatrixRotationZ(&matrix,50*rad);
			gun[guncount].mat*=matrix;
			gun[guncount].mat._41=gun[guncount].p.x;
			gun[guncount].mat._42=gun[guncount].p.y;
			gun[guncount].mat._43=gun[guncount].p.z;
			guncount++;

		}




		else if(stagenum==4)//���A2
		{

			index=0;

			stagestate[index].kind=ITAKIND_CORCEOUT;
			stagestate[index].matindex=MATKIND_TUTI;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_TUTI;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_ISI;
			index++;
			stagestate[index].kind=ITAKIND_CORCEOUT;
			stagestate[index].matindex=MATKIND_NULL;
		}


		else if(stagenum==5)//���A3
		{

			index=0;

			stagestate[index].kind=ITAKIND_CORCEOUT;
			stagestate[index].matindex=MATKIND_NULL;
			index++;
			stagestate[index].kind=ITAKIND_CORCEOUT;
			stagestate[index].matindex=MATKIND_TUTI;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_TUTI;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_ISI;
			index++;

			//��C�ݒ�

			gun[guncount].p=D3DXVECTOR3(206.62f,-95.3f,0);
			gun[guncount].v=D3DXVECTOR3(-0.78f,0.9f,0);
			gun[guncount].kind=0;
			D3DXMatrixRotationX(&gun[guncount].mat,-120*rad);
			D3DXMatrixRotationY(&matrix,90*rad);
			gun[guncount].mat*=matrix;
			gun[guncount].mat._41=gun[guncount].p.x;
			gun[guncount].mat._42=gun[guncount].p.y;
			gun[guncount].mat._43=gun[guncount].p.z;
			guncount++;

			gun[guncount].p=D3DXVECTOR3(-1.79f,-70.61f,-155.9f);
			gun[guncount].v=D3DXVECTOR3(0,0.9f,0.58f);
			gun[guncount].kind=0;
			D3DXMatrixRotationX(&gun[guncount].mat,-50*rad);
			gun[guncount].mat._41=gun[guncount].p.x;
			gun[guncount].mat._42=gun[guncount].p.y;
			gun[guncount].mat._43=gun[guncount].p.z;
			guncount++;





			gun[guncount].p=D3DXVECTOR3(-300.72f,-258.8f,33.46f);
			gun[guncount].v=D3DXVECTOR3(-0.8f,0.2f,0.6f);
			gun[guncount].kind=0;
			D3DXMatrixRotationX(&gun[guncount].mat,-90*rad);
			D3DXMatrixRotationZ(&matrix,-70*rad);
			gun[guncount].mat*=matrix;
			D3DXMatrixRotationY(&matrix,-150*rad);
			gun[guncount].mat*=matrix;
			gun[guncount].mat._41=gun[guncount].p.x;
			gun[guncount].mat._42=gun[guncount].p.y;
			gun[guncount].mat._43=gun[guncount].p.z;
			guncount++;


			gun[guncount].p=D3DXVECTOR3(-411.77f,-201.1f,-89.39f);
			gun[guncount].v=D3DXVECTOR3(1.0f,0.2f,0.15f);
			gun[guncount].kind=0;
			D3DXMatrixRotationX(&gun[guncount].mat,-90*rad);
			D3DXMatrixRotationZ(&matrix,70*rad);
			gun[guncount].mat*=matrix;
			D3DXMatrixRotationY(&matrix,-150*rad);
			gun[guncount].mat*=matrix;
			gun[guncount].mat._41=gun[guncount].p.x;
			gun[guncount].mat._42=gun[guncount].p.y;
			gun[guncount].mat._43=gun[guncount].p.z;
			guncount++;


			gun[guncount].p=D3DXVECTOR3(-389.75f,-151.88f,-234.88f);
			gun[guncount].v=D3DXVECTOR3(-0.8f,0.2f,0.6f);
			gun[guncount].kind=0;
			D3DXMatrixRotationX(&gun[guncount].mat,-90*rad);
			D3DXMatrixRotationZ(&matrix,-70*rad);
			gun[guncount].mat*=matrix;
			D3DXMatrixRotationY(&matrix,-150*rad);
			gun[guncount].mat*=matrix;
			gun[guncount].mat._41=gun[guncount].p.x;
			gun[guncount].mat._42=gun[guncount].p.y;
			gun[guncount].mat._43=gun[guncount].p.z;
			guncount++;


		}



		else if(stagenum==6)//�e�N�m1
		{

			index=0;

			stagestate[index].kind=ITAKIND_CORCEOUT;
			stagestate[index].matindex=MATKIND_TETU;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_TETU;

			index++;
			stagestate[index].kind=ITAKIND_ROTATE;
			stagestate[index].matindex=MATKIND_TETU;
			stagestate[index].v=D3DXVECTOR3(235.62f,-38.5f,253.05f);
			stagestate[index].v2=D3DXVECTOR3(-0.5f,0,0);

			index++;
			stagestate[index].kind=ITAKIND_ROTATE;
			stagestate[index].matindex=MATKIND_TETU;
			stagestate[index].v=D3DXVECTOR3(235.62f,-38.5f,253.05f);
			stagestate[index].v2=D3DXVECTOR3(0.7f,0,0);

			index++;
			stagestate[index].kind=ITAKIND_ROTATE;
			stagestate[index].matindex=MATKIND_TETU;
			stagestate[index].v=D3DXVECTOR3(270.94f,-6.27f,0.0f);
			stagestate[index].v2=D3DXVECTOR3(0,0,0.5f);

			index++;
			stagestate[index].kind=ITAKIND_ROTATE;
			stagestate[index].matindex=MATKIND_TETU;
			stagestate[index].v=D3DXVECTOR3(125.5f,0.0f,-181.52f);
			stagestate[index].v2=D3DXVECTOR3(0,1.3f,0);






			//����S��

			//�V��̍���=88.4
			index=4;//stagestate[10,11].s���g�p
			ball[index].enable=true;
			ball[index].deletecount=0;
			ball[index].meshindex=BALLMESH_BIGTETU;
			ball[index].ball.reset();
			ball[index].ball.po=D3DXVECTOR3(0,5.4f,104.1f);
			ball[index].ball.r=10.0f;
			ball[index].ball.w=1000;
			ball[index].matindex=MATKIND_TETU;
			stagestate[10].s=10;
			stagestate[10].v=D3DXVECTOR3(0,88.4f,104.1f);


			index++;//stagestate[12,13].s���g�p
			ball[index].enable=true;
			ball[index].deletecount=0;
			ball[index].meshindex=BALLMESH_BIGTETU;
			ball[index].ball.reset();
			ball[index].ball.po=D3DXVECTOR3(0,31.9f,-97.6f);
			ball[index].ball.r=10.0f;
			ball[index].ball.w=1000;
			ball[index].matindex=MATKIND_TETU;
			stagestate[12].s=17;
			stagestate[12].v=D3DXVECTOR3(0,88.4f,-97.6f);



			//�]����S��

			index++;
			ball[index].enable=true;
			ball[index].deletecount=0;
			ball[index].meshindex=BALLMESH_TETU;
			ball[index].ball.reset();
			ball[index].ball.po=D3DXVECTOR3(284.0f,5.0f,110.0f);
			ball[index].ball.r=2.3f;
			ball[index].ball.w=400;
			ball[index].matindex=MATKIND_TETU;

			index++;
			ball[index].enable=true;
			ball[index].deletecount=0;
			ball[index].meshindex=BALLMESH_TETU;
			ball[index].ball.reset();
			ball[index].ball.po=D3DXVECTOR3(280.0f,6.0f,115.0f);
			ball[index].ball.r=2.3f;
			ball[index].ball.w=400;
			ball[index].matindex=MATKIND_TETU;







			//��C
			gun[guncount].p=D3DXVECTOR3(-27.0f,-18.5f,292.6f);
			gun[guncount].v=D3DXVECTOR3(0.64f,0.77f,0);
			gun[guncount].kind=0;
			D3DXMatrixRotationX(&gun[guncount].mat,-45*rad);
			D3DXMatrixRotationY(&matrix,90*rad);
			gun[guncount].mat*=matrix;
			gun[guncount].mat._41=gun[guncount].p.x;
			gun[guncount].mat._42=gun[guncount].p.y;
			gun[guncount].mat._43=gun[guncount].p.z;
			guncount++;




		}




		else if(stagenum==7)//�e�N�m2
		{


			index=0;
			stagestate[index].kind=ITAKIND_CORCEOUT;
			stagestate[index].matindex=MATKIND_TETU;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_TETU;

			index++;
			stagestate[index].kind=ITAKIND_ROTATE;
			stagestate[index].matindex=MATKIND_TETU;
			stagestate[index].v=D3DXVECTOR3(-21.53f,-50.95f,351.57f);
			stagestate[index].v2=D3DXVECTOR3(0,0.5f,0);

			index++;
			stagestate[index].kind=ITAKIND_MOVE;
			stagestate[index].matindex=MATKIND_GOMU;
			stagestate[index].v=D3DXVECTOR3(0.45f,0,0);

			index++;
			stagestate[index].kind=ITAKIND_MOVE;
			stagestate[index].matindex=MATKIND_GOMU;
			stagestate[index].v=D3DXVECTOR3(-0.45f,0,0);






			gun[guncount].p=D3DXVECTOR3(-90.98f,-23.5f,366.5f);
			gun[guncount].v=D3DXVECTOR3(0,1.5f,0);
			gun[guncount].kind=1;
			D3DXMatrixRotationX(&gun[guncount].mat,-90*rad);
			D3DXMatrixRotationY(&matrix,180*rad);
			gun[guncount].mat*=matrix;
			gun[guncount].mat._41=gun[guncount].p.x;
			gun[guncount].mat._42=gun[guncount].p.y;
			gun[guncount].mat._43=gun[guncount].p.z;
			guncount++;


			gun[guncount].p=D3DXVECTOR3(-239.39f,-56.0f-6.4f,-55.24f);
			gun[guncount].v=D3DXVECTOR3(-0.2f,3.0f,-0.2f);
			gun[guncount].kind=1;
			D3DXMatrixRotationX(&gun[guncount].mat,-90*rad);
			gun[guncount].mat._41=gun[guncount].p.x;
			gun[guncount].mat._42=gun[guncount].p.y;
			gun[guncount].mat._43=gun[guncount].p.z;
			guncount++;


			index=4;
			ball[index].enable=true;
			ball[index].deletecount=0;
			ball[index].meshindex=BALLMESH_TETU;
			ball[index].ball.reset();
			ball[index].ball.po=D3DXVECTOR3(-300.0f,30.0f,-10.0f);
			ball[index].ball.r=2.3f;
			ball[index].ball.w=400;
			ball[index].matindex=MATKIND_TETU;

			index++;
			ball[index].enable=true;
			ball[index].deletecount=0;
			ball[index].meshindex=BALLMESH_TETU;
			ball[index].ball.reset();
			ball[index].ball.po=D3DXVECTOR3(-250.0f,30.0f,-10.0f);
			ball[index].ball.r=2.3f;
			ball[index].ball.w=400;
			ball[index].matindex=MATKIND_TETU;

			index++;
			ball[index].enable=true;
			ball[index].deletecount=0;
			ball[index].meshindex=BALLMESH_TETU;
			ball[index].ball.reset();
			ball[index].ball.po=D3DXVECTOR3(-250.0f,30.0f,-40.0f);
			ball[index].ball.r=2.3f;
			ball[index].ball.w=400;
			ball[index].matindex=MATKIND_TETU;




		}






		else if(stagenum==8)//�e�N�m3
		{

			index=0;
			stagestate[index].kind=ITAKIND_CORCEOUT;
			stagestate[index].matindex=MATKIND_TETU;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_TETU;

			index++;
			stagestate[index].kind=ITAKIND_MOVE;
			stagestate[index].matindex=MATKIND_GOMU;
			stagestate[index].v=D3DXVECTOR3(0,0,-0.7f);

			index++;
			stagestate[index].kind=ITAKIND_ROTATE;
			stagestate[index].matindex=MATKIND_TETU;
			stagestate[index].v=D3DXVECTOR3(-188.09f,0,-107.71f);
			stagestate[index].v2=D3DXVECTOR3(0,-0.7f,0);

			index++;
			stagestate[index].kind=ITAKIND_ROTATE;
			stagestate[index].matindex=MATKIND_TETU;
			stagestate[index].v=D3DXVECTOR3(-153.02f,0,-84.12f);
			stagestate[index].v2=D3DXVECTOR3(0,0.7f,0);

			index++;
			stagestate[index].kind=ITAKIND_ROTATE;
			stagestate[index].matindex=MATKIND_TETU;
			stagestate[index].v=D3DXVECTOR3(0,5.5f,-116.56f);
			stagestate[index].v2=D3DXVECTOR3(1.2f,0,0);

			index++;
			stagestate[index].kind=ITAKIND_ROTATE;
			stagestate[index].matindex=MATKIND_TETU;
			stagestate[index].v=D3DXVECTOR3(-49.58f,0,-152.31f);
			stagestate[index].v2=D3DXVECTOR3(0,-0.7f,0);

			index++;
			stagestate[index].kind=ITAKIND_ROTATE;
			stagestate[index].matindex=MATKIND_TETU;
			stagestate[index].v=D3DXVECTOR3(-21.28f,0,-139.36f);
			stagestate[index].v2=D3DXVECTOR3(0,1.0f,0);

			index++;
			stagestate[index].kind=ITAKIND_ROTATE;
			stagestate[index].matindex=MATKIND_TETU;
			stagestate[index].v=D3DXVECTOR3(-31.27f,0,-109.39f);
			stagestate[index].v2=D3DXVECTOR3(0,-0.9f,0);

			index++;
			stagestate[index].kind=ITAKIND_ROTATE;
			stagestate[index].matindex=MATKIND_TETU;
			stagestate[index].v=D3DXVECTOR3(-4.74f,0,-91.17f);
			stagestate[index].v2=D3DXVECTOR3(0,1.2f,0);


			//�e���ˑ�C

			gun[guncount].p=D3DXVECTOR3(-282.66f,12.02f,-243.41f);
			gun[guncount].v=D3DXVECTOR3(2.0f*0.9f,-0.5f*0.9f,0.3f*0.9f);
			gun[guncount].kind=1;
			guncount++;

			gun[guncount].p=D3DXVECTOR3(-10.0f,27.3f,-467.44f);
			gun[guncount].v=D3DXVECTOR3(0,0,1.5f);
			gun[guncount].kind=1;
			D3DXMatrixRotationY(&gun[guncount].mat,0);
			gun[guncount].mat._41=gun[guncount].p.x;
			gun[guncount].mat._42=gun[guncount].p.y;
			gun[guncount].mat._43=gun[guncount].p.z;
			guncount++;

			gun[guncount].p=D3DXVECTOR3(45.0f,27.3f,-467.44f);
			gun[guncount].v=D3DXVECTOR3(-1.8f,0,0);
			gun[guncount].kind=1;
			D3DXMatrixRotationY(&gun[guncount].mat,-90*rad);
			gun[guncount].mat._41=gun[guncount].p.x;
			gun[guncount].mat._42=gun[guncount].p.y;
			gun[guncount].mat._43=gun[guncount].p.z;
			guncount++;

		}




		else if(stagenum==9)
		{


			index=0;

			stagestate[index].kind=ITAKIND_CORCEOUT;
			stagestate[index].matindex=MATKIND_NULL;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_IZIGEN;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_GURABI;



			gun[guncount].p=D3DXVECTOR3(22.5f,13.88f,-38.67f);
			gun[guncount].v=D3DXVECTOR3(-0.1f,0,1.0f);
			gun[guncount].kind=2;
			D3DXMatrixRotationY(&gun[guncount].mat,0);
			gun[guncount].mat._41=gun[guncount].p.x;
			gun[guncount].mat._42=gun[guncount].p.y;
			gun[guncount].mat._43=gun[guncount].p.z;
			guncount++;

			gun[guncount].p=D3DXVECTOR3(-22.5f,13.88f,-38.67f);
			gun[guncount].v=D3DXVECTOR3(0.1f,0,1.0f);
			gun[guncount].kind=2;
			D3DXMatrixRotationY(&gun[guncount].mat,0);
			gun[guncount].mat._41=gun[guncount].p.x;
			gun[guncount].mat._42=gun[guncount].p.y;
			gun[guncount].mat._43=gun[guncount].p.z;
			guncount++;

			gun[guncount].p=D3DXVECTOR3(284.94f,0,676.33f);
			gun[guncount].v=D3DXVECTOR3(0,1.0f,0);
			gun[guncount].kind=2;
			D3DXMatrixRotationX(&gun[guncount].mat,-90*rad);
			D3DXMatrixRotationY(&matrix,180*rad);
			gun[guncount].mat*=matrix;
			gun[guncount].mat._41=gun[guncount].p.x;
			gun[guncount].mat._42=gun[guncount].p.y;
			gun[guncount].mat._43=gun[guncount].p.z;
			guncount++;


		}







		else if(stagenum==10)
		{

			index=0;

			stagestate[index].kind=ITAKIND_CORCEOUT;
			stagestate[index].matindex=MATKIND_NULL;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_IZIGEN;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_GURABI;
			index++;
			stagestate[index].kind=ITAKIND_MOVE;//�O��
			stagestate[index].matindex=MATKIND_IZIGEN;
			stagestate[index].v=D3DXVECTOR3(0,0,-0.2f);
			index++;
			stagestate[index].kind=ITAKIND_ROTATE;//����
			stagestate[index].matindex=MATKIND_GURABI;
			stagestate[index].v=D3DXVECTOR3(-192.83f,162.11f,-285.6f);
			stagestate[index].v2=D3DXVECTOR3(0,0.33f,0.33f);

			stagematrix=D3DXMATRIX(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);


			index=4;
			ball[index].enable=true;
			ball[index].deletecount=0;
			ball[index].meshindex=BALLMESH_IZIGENBALL;
			ball[index].ball.reset();
			ball[index].ball.po=D3DXVECTOR3(-192.83f+70,162.11f,-285.6f);
			ball[index].gv=D3DXVECTOR3(1,0,0);
			ball[index].ball.r=30.0f;
			ball[index].ball.w=200;
			ball[index].matindex=MATKIND_IZIGEN;

			index++;
			ball[index].enable=true;
			ball[index].deletecount=0;
			ball[index].meshindex=BALLMESH_IZIGENBALL;
			ball[index].ball.reset();
			ball[index].ball.po=D3DXVECTOR3(-192.83f-70,162.11f,-285.6f);
			ball[index].gv=D3DXVECTOR3(-1,0,0);
			ball[index].ball.r=30.0f;
			ball[index].ball.w=200;
			ball[index].matindex=MATKIND_IZIGEN;


		}





		else if(stagenum==11)
		{

			index=0;

			stagestate[index].kind=ITAKIND_CORCEOUT;
			stagestate[index].matindex=MATKIND_NULL;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_IZIGEN;
			index++;
			stagestate[index].kind=ITAKIND_NORMAL;
			stagestate[index].matindex=MATKIND_GURABI;

			stagematrix=D3DXMATRIX(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);


			//index=4;
			//ball[index].enable=true;
			//ball[index].deletecount=0;
			//ball[index].meshindex=BALLMESH_IZIGENBALL;
			//ball[index].ball.reset();
			//ball[index].ball.po=D3DXVECTOR3(-192.83f+70,162.11f,-285.6f);
			//ball[index].gv=D3DXVECTOR3(1,0,0);
			//ball[index].ball.r=30.0f;
			//ball[index].ball.w=200;
			//ball[index].matindex=MATKIND_IZIGEN;

			//index++;
			//ball[index].enable=true;
			//ball[index].deletecount=0;
			//ball[index].meshindex=BALLMESH_IZIGENBALL;
			//ball[index].ball.reset();
			//ball[index].ball.po=D3DXVECTOR3(-192.83f-70,162.11f,-285.6f);
			//ball[index].gv=D3DXVECTOR3(-1,0,0);
			//ball[index].ball.r=30.0f;
			//ball[index].ball.w=200;
			//ball[index].matindex=MATKIND_IZIGEN;


		}



		//���ˌ��z�u

		for(i=0;i<playercount;i++)
		{
			wind[windcount].enable=true;
			wind[windcount].kind=stagenum/3;
			wind[windcount].p=D3DXVECTOR3(ball[i].ball.po.x,0,0);
			wind[windcount].v=D3DXVECTOR3(0,0.5f,0);
			wind[windcount].dis=10;
			wind[windcount].ang=30;
			wind[windcount].mat=D3DXMATRIX(1,0,0,0,0,1,0,0,0,0,1,0,wind[windcount].p.x,wind[windcount].p.y,wind[windcount].p.z,1);
			windcount++;
		}








		if(playercount>1)
		{

			//�A�C�e���ǂݍ���
			char str[MAX_PATH];

			FILE *file;

			itemcount=0;

			sprintf(str,"data/data/corce/item/%d",stagenum+1);
			if((file=fopen(str,"r"))==NULL) return false;

			while(fscanf(file,"%f,%f,%f",&item[itemcount].po.x,&item[itemcount].po.y,&item[itemcount].po.z)!=EOF)
			{
				//�A�C�e���̐ݒ�
				item[itemcount].getter=-1;
				item[itemcount].deletecount=1;
				item[itemcount].nowpo=item[itemcount].po;
				itemcount++;
			}


		}



		
	}




	//��������
	for(i=0;i<KEMURI_MAX;i++)
		kemuri[i].frame=0;








	return true;

}







void StageMove()
{




	int i,j,k;
	float ang,dis;

	int si;//���ʉ��̃C���f�b�N�X�w��Ɏg��


	if(stagekind==SELECTGAME_MULTIPLAY && Setting.Seaver)
		gameframe++;





	////�X�^�[�g�i���˂��Ƃ߂�)

	if(info.startcounter==1)
	{
		//���˂Ƃ߂�
		for(i=0;i<playercount;i++)
		{
			wind[windcount-1-i].enable=false;
		}
	}



	//�S�[�����Ă�����{�[�����S�[���n�_�łƂ߂�
	if(stagekind==SELECTGAME_STAGE)
	{
		if(info.goalframe==1)
		{
			ball[0].ball.mv.x=ball[0].ball.mv.y=ball[0].ball.mv.z=0;
		}
		else if(info.goalframe!=0)
		{
			ball[0].gv=goal.v;
			changedistance3(&ball[0].gv.x,&ball[0].gv.y,&ball[0].gv.z,1);
			ball[0].ball.mv.x*=0.96f;
			ball[0].ball.mv.z*=0.96f;
			ball[0].ball.mv.y*=0.96f;
			ball[0].ball.mv.x+=((goal.p.x+ball[0].gv.x*4.5f)-ball[0].ball.po.x)*0.008f;
			ball[0].ball.mv.y+=((goal.p.y+ball[0].gv.y*4.5f)-ball[0].ball.po.y)*0.008f;
			ball[0].ball.mv.z+=((goal.p.z+ball[0].gv.z*4.5f)-ball[0].ball.po.z)*0.008f;
		}

	}


	


	//�A�C�e���֌W

	D3DXMATRIX mat;


	for(i=0;i<itemcount;i++)
	{
		item[i].angle++;

		if(item[i].deletecount>0)
		{
			item[i].deletecount--;
			if(item[i].deletecount==0)
			{

				int keepgetter=item[i].getter;
				item[i].getter=-1;

				//�v���C���[�̃A�C�e���擾����
				if( player[keepgetter].itemkind==ITEMKIND_NONE )
				{
					//�ق��̃A�C�e��������Ă��Ȃ����𒲂ׂ�
					bool ok=true;
					for(j=0;j<itemcount;j++)
					{
						if(item[j].getter==keepgetter)
						{
							ok=false;
							break;
						}
					}

					if(ok)
						player[keepgetter].itemkind=item[i].kind;
				}

				item[i].deletecount=-50;

				//�A�C�e���̎�ނ�I��
				float itemrnd;
				if(izigen)	itemrnd=rnd(itemkakuritusum);
				else			itemrnd=rnd(itemkakuritusum-itemkakuritu[ITEMKIND_GURABI]);

				for(j=1;j<ITEMKIND_MAX;j++)
					if(itemrnd <= itemkakurituend[j])
					{
						item[i].kind=j;
						break;
					}


				item[i].nowpo=item[i].po;

				D3DXMatrixRotationX( &item[i].mat, rnd(360)*rad );
				D3DXMatrixRotationY( &mat, rnd(360)*rad );
				item[i].mat*=mat;
				D3DXMatrixRotationZ( &mat, rnd(360)*rad );
				item[i].mat*=mat;


				D3DXMatrixRotationY( &item[i].mat, 0 );
			}
		}
		else if(item[i].deletecount<0)
			item[i].deletecount++;

		if(item[i].getter!=-1)
		{
			item[i].nowpo.x=ball[item[i].getter].ball.po.x+(item[i].po.x-ball[item[i].getter].ball.po.x)*item[i].deletecount/ITEM_COUNT;
			item[i].nowpo.y=ball[item[i].getter].ball.po.y+(item[i].po.y-ball[item[i].getter].ball.po.y)*item[i].deletecount/ITEM_COUNT;
			item[i].nowpo.z=ball[item[i].getter].ball.po.z+(item[i].po.z-ball[item[i].getter].ball.po.z)*item[i].deletecount/ITEM_COUNT;
		}
	}





	//�����A�j���[�V����


	for(i=0;i<BOMB_MAX;i++)
	{
		if(Bomb[i].sizemax!=0)
		{

			Bomb[i].size+=Bomb[i].sizeadd;
			if(Bomb[i].size>Bomb[i].sizemax)
				Bomb[i].sizemax=0;

			D3DXMatrixRotationAxis( &mat, &Bomb[i].axis ,rad*10 );
			Bomb[i].mat*=mat;

		}
	}



















	int index;

	float mulw,muldf,mulsf,mulgrab;

	for(index=0;index<BALL_MAX;index++)
	{

		//�o�O�h�~�I�I
		if(ball[index].ball.axis.x==0) ball[index].ball.axis.x=0.0000001f;
		if(ball[index].ball.axis.y==0) ball[index].ball.axis.y=0.0000001f;
		if(ball[index].ball.axis.z==0) ball[index].ball.axis.z=0.0000001f;


		if(ball[index].enable)
		{


			//���C�͂�d���̔{������

			mulw=1;muldf=1;mulsf=1;mulgrab=1;

			if(index<playercount)
			{
				if(player[index].usekind==ITEMKIND_FIRE)
				{
					muldf=2;mulsf=2;
				}
				else if(player[index].usekind==ITEMKIND_MIZU && player[index].MutekiCount==0)
				{
					mulw=0.7f;mulgrab=0.7f;
				}




				//���ʂɉ����Ă��ω�����(1�ʂ���Ƃ��Alap+par�̍��ŋ��߂�)

				//��ʂ̃C���f�b�N�X�����߂�
				for(i=0;i<playercount;i++)
					if(player[i].rank==1)
					{
						float tempmulf=(player[i].lap+player[i].par)-(player[index].lap+player[index].par);
						tempmulf*=0.2f;
						tempmulf++;
						if(tempmulf>1.3f) tempmulf=1.3f;
						if(tempmulf<1.0f) tempmulf=1.0f;
						muldf*=tempmulf;
						mulsf*=tempmulf;
						break;
					}



			}





			if(ball[index].deletecount>0)//�{�[���t�F�[�h�A�E�g
			{
				ball[index].deletecount--;



				//�{�[�������e��������
				if(ball[index].meshindex==BALLMESH_BOMB || ball[index].meshindex==BALLMESH_YUUDOU)
				{
					//�J�E���g��100�ɂ��Ă��玩������
					if(ball[index].deletecount==100)
					{//�����I�I
						Bakuhatu(index);
					}

				}

				//�`�F�b�N�|�C���g�֖߂�
				if(ball[index].deletecount==0)
				{
					if(index<playercount)
					{
						feed[index].Start(FEEDMODE_BLACKIN,50);

						//�߂�ʒu�𒲂ׂ�
						for(i=0;i<info.checkcount;i++)
						{
							if(player[index].par<info.check[i].par)
							{
								i--;
								if(stagekind==SELECTGAME_VARSUS && stagenum==11)//�َ����ŏI�R�[�X��2�T�ڂ͗��Ԃ�
								{
									if(player[index].lap % 2 == 1)
									{
										ball[index].ball.po=info.check[i].po;
										ball[index].gv=info.check[i].gv;
										player[index].cponext=player[index].cpo=info.check[i].cpo;
										player[index].cupnext=player[index].cup=info.check[i].cup;
									}
									else
									{
										ball[index].ball.po=info.check[i].po-info.check[i].gv*55;
										ball[index].gv=-info.check[i].gv;
										player[index].cponext=player[index].cpo=info.check[i].cpo-info.check[i].gv*65;
										float d=D3DXVec3Dot(&info.check[i].cup,&info.check[i].gv);
										player[index].cupnext=player[index].cup=info.check[i].cup-info.check[i].gv*d*2;
									}
								}
								else if(stagekind==SELECTGAME_VARSUS)
								{
									ball[index].ball.po=info.check[i].po;
									ball[index].gv=info.check[i].gv;
									player[index].cponext=player[index].cpo=info.check[i].cpo;
									player[index].cupnext=player[index].cup=info.check[i].cup;
								}
								ball[index].ball.mv=ball[index].ball.axis=D3DXVECTOR3(0,0,0);
								player[index].ballold=ball[index].ball.po;
								break;
							}
						}

						ball[index].deletecount=-50;
						player[index].InputEnable=true;
					}
					else
						ball[index].enable=false;



					if(ball[index].meshindex==BALLMESH_BIGIWA)
					{
						//���ʉ���~
						if(play3d)
							sd.Iwa3D[ball[index].info[0]].Sound->Stop();
						else
							sd.Iwa[ball[index].info[0]]->Stop();

						//�N���C�A���g�Ƀf�[�^�𑗂�
						SendIwaEnd(ball[index].info[0]);
					}



				}

				else if(ball[index].deletecount==50 && index<playercount)
					feed[index].Start(FEEDMODE_BLACKOUT,50);



			}
			else if(ball[index].deletecount<0)//�{�[���t�F�[�h�C��
			{
				ball[index].deletecount++;
			}




			//�U�����܂̏ꍇ����ȏ���������
			if(ball[index].meshindex==BALLMESH_YUUDOU)
			{


				//��]����߂Ă����A���̑��x�ɂȂ�����ǐՊJ�n�I�I
				if(D3DXVec3Length(&ball[index].ball.axis)<=0.1f)
				{

					//�ǐՊJ�n�I�I

					float mindis=0;
					int minindex=-1;

					//��ԋ߂��v���C���[��T��
					for(i=minindex+1;i<playercount;i++)
					{
						if(ball[index].info[0]!=i)
						{
							dis=D3DXVec3Length(&(ball[index].ball.po-ball[i].ball.po));
							if(dis<mindis || minindex==-1)
							{
								mindis=dis;
								minindex=i;
							}
						}
					}

					//minindex�Ɍ������ē˂����ށI�I
					D3DXVECTOR3 tv;
					tv=ball[minindex].ball.po-ball[index].ball.po;
					changedistance3(&tv.x,&tv.y,&tv.z,0.016f);
					ball[index].ball.mv+=tv;

					ball[index].ball.mv.x*=0.98f;
					ball[index].ball.mv.y*=0.98f;
					ball[index].ball.mv.z*=0.98f;


				}
				else
				{
					ball[index].ball.axis.x*=0.99f;
					ball[index].ball.axis.y*=0.99f;
					ball[index].ball.axis.z*=0.99f;
					ball[index].ball.mv.x*=0.98f;
					ball[index].ball.mv.y*=0.98f;
					ball[index].ball.mv.z*=0.98f;
				}


				//�����ʒu��ς���

				if(play3d)
				{
					sd.Yudou3D[ball[index].info[1]].Param.vPosition=ball[index].ball.po;
					sd.Yudou3D[ball[index].info[1]].Param.vVelocity=ball[index].ball.mv;
					sd.Yudou3D[ball[index].info[1]].Buffer->SetAllParameters( &sd.Yudou3D[ball[index].info[1]].Param, DS3D_DEFERRED );
				}
				else
				{
					sd.Yudou[ball[index].info[1]]->GetBuffer(0)->SetVolume(getvolume(ball[index].ball.po));
				}



			}
			else
			{
				//����ȊO�̕��ʂ̃{�[��

				if(ball[index].meshindex==BALLMESH_BIGIWA)
				{

					//�����ʒu��ς���

					if(play3d)
					{
						sd.Iwa3D[ball[index].info[0]].Param.vPosition=ball[index].ball.po;
						sd.Iwa3D[ball[index].info[0]].Param.vVelocity=ball[index].ball.mv;
						sd.Iwa3D[ball[index].info[0]].Buffer->SetAllParameters( &sd.Iwa3D[ball[index].info[0]].Param, DS3D_DEFERRED );
					}
					else
					{
						sd.Iwa[ball[index].info[0]]->GetBuffer(0)->SetVolume(getvolume(ball[index].ball.po));
					}

				}



				//�d��
				dis=9.8f/60/60*mulgrab;

				ball[index].ball.mv.x-=ball[index].gv.x*dis;
				ball[index].ball.mv.y-=ball[index].gv.y*dis;
				ball[index].ball.mv.z-=ball[index].gv.z*dis;
			}


			//��C��R
			ball[index].ball.setrotares(matstruct[ball[index].matindex].rotares);

			D3DXVECTOR3 windv=D3DXVECTOR3(0,0,0);//�{�[���̂���ʒu�̋�C�̗���̃x�N�g��
			float dot,wx,wy,wz,wx2,wy2,wz2;

			for(i=0;i<windcount;i++)
			{
				if(wind[i].enable)
				{
					//�����e�X�g
					dot=dotpro3(wind[i].v.x,wind[i].v.y,wind[i].v.z,
							ball[index].ball.po.x-wind[i].p.x,ball[index].ball.po.y-wind[i].p.y,ball[index].ball.po.z-wind[i].p.z);


					if(dot>=0 && dot <=wind[i].dis)
					{


						//�͈̓e�X�g
						axisvector(&wx,&wy,&wz,wind[i].v.x,wind[i].v.y,wind[i].v.z,
							ball[index].ball.po.x-wind[i].p.x,ball[index].ball.po.y-wind[i].p.y,ball[index].ball.po.z-wind[i].p.z);

						dis=distance3(wx,wy,wz)-ball[index].ball.r*0.7f;
						if(dis<=0) dis=0;
						else changedistance3(&wx,&wy,&wz,dis);


						wx2=wind[i].v.x;wy2=wind[i].v.y;wz2=wind[i].v.z;
						changedistance3(&wx2,&wy2,&wz2,dot);

						//��ׂ̂��Ƃ�̊p�x�����߂�I�I
						ang=angle3(wind[i].v.x,wind[i].v.y,wind[i].v.z,wx2+wx,wy2+wy,wz2+wz);


						if(ang<=wind[i].ang/2)
						{

							//���̉e���͌v�Z
							changedistance3(&wx2,&wy2,&wz2,
											(1-dot/wind[i].dis)*(1-ang/(wind[i].ang/2))*distance3(wind[i].v.x,wind[i].v.y,wind[i].v.z)*30);	

							windv.x+=wx2;
							windv.y+=wy2;
							windv.z+=wz2;


							//�S�[���̔���
							if(stagekind==SELECTGAME_STAGE && i==goal.index && player[index].InputEnable==true)
							{
								//�S�[���I�I

								SOUND_PLAY(sd.Kansei);

								if(!replay)
								{

									if(clearstage==stagenum)
									{
										clearstage++;
									}
									if(hTime[stagenum]>Time || hTime[stagenum]==0)
									{
										ReplayEnd();
										ReplayCopy();
										info.hscoreframe=120;
										hTime[stagenum]=Time;
									}
									SaveClear();
								}

								player[index].InputEnable=false;
								player[index].goal=true;

								autostop=true;
								if(autoReplay)
									feed[4].Start(FEEDMODE_BLACKOUT,300);
								else
								{
									stopplayer=0;
									CallSelect(CALLMODE_GAME,150);
								}
								InfoGoal();
							}


						}

					}
				}
			}



			ball[index].ball.setmoveres(matstruct[ball[index].matindex].moveres,windv);







			D3DXVECTOR3 vec;





			//��C����(�ŏ��͑�C�̒��S�Ɍ������Đi�ށA���S�܂ł������΂��A���΂炭��C�Ɠ����蔻�肵�Ȃ�)


			for(i=0;i<guncount;i++)
			{
				dis=distance3(ball[index].ball.po.x-gun[i].p.x,ball[index].ball.po.y-gun[i].p.y,ball[index].ball.po.z-gun[i].p.z)-ball[index].ball.r;

				if(dis<=0.1f)
				{
					vec=gun[i].v;
					changedistance3(&vec.x,&vec.y,&vec.z,1.5f+ball[index].ball.r);
					ball[index].ball.po=gun[i].p+vec;
					ball[index].ball.mv=gun[i].v;

					//����f��

					//�X�e�[�W�ɂ���āA��ԂƂ��Ɉ�u��������
					if(stagenum==5 && index<playercount && i<2)
					{
						feed[index].Start(FEEDMODE_WHITEOUT,40);
						player[index].MutekiCount=7*60;
					}


					for(j=0;j<20;j++)
					{
						for(k=0;k<KEMURI_MAX;k++)
						{
							if(kemuri[k].frame==0)
							{
								kemuri[k].kind=(int)rnd(4)/3;
								kemuri[k].frame=1;
								kemuri[k].framemax=(int)rnd(100)+50;
								kemuri[k].po=gun[i].p;
								kemuri[k].mv=D3DXVECTOR3((gun[i].v.x+rnd(0.2f)-0.1f)*(rnd(0.3f)+0.05f),(gun[i].v.y+rnd(0.2f)-0.1f)*(rnd(0.3f)+0.05f),(gun[i].v.z+rnd(0.2f)-0.1f)*(rnd(0.3f)+0.05f));

								k=KEMURI_MAX;
							}
						}
					}

					if(index<playercount)
						if(!autoReplay)
							DI.SetEffect(multiplayindex(index),1,60,0);

					//���ʉ��Đ�
					if(play3d)
					{

						si=stopindex3d(sd.Bomb3D);
						sd.Bomb3D[si].Param.vPosition=gun[i].p;
						sd.Bomb3D[si].Param.vVelocity=D3DXVECTOR3(0,0,0);
						sd.Bomb3D[si].Buffer->SetAllParameters( &sd.Bomb3D[si].Param, DS3D_DEFERRED );
						SOUND_PLAY(sd.Bomb3D[si].Sound);

					}
					else
					{
						si=stopindex(sd.Bomb);
						SOUND_PLAY(sd.Bomb[si]);
						sd.Bomb[si]->GetBuffer(0)->SetVolume(getvolume(gun[i].p));
					}

				}
				else if(dis<1.5f)
				{
					vec=gun[i].p-ball[index].ball.po;
					changedistance3(&vec.x,&vec.y,&vec.z,0.15f);
					ball[index].ball.mv=vec;
				}

			}









			//�o�O�h�~
			if(ball[index].nojudindex==index)
				ball[index].nojudindex=-1;


			//nojudindex�̃{�[���ƐH������łȂ�������nojudindex=-1�ɂ���
			else if(ball[index].nojudindex!=-1)
			{
				//�H������ł��Ȃ����`�F�b�N
				dis=distance3(ball[index].ball.po.x-ball[ball[index].nojudindex].ball.po.x,ball[index].ball.po.y-ball[ball[index].nojudindex].ball.po.y,ball[index].ball.po.z-ball[ball[index].nojudindex].ball.po.z );

				char str[100];
				sprintf(str,"%d\n%f\n%f",ball[index].nojudindex,dis,ball[index].ball.r+ball[ball[index].nojudindex].ball.r);
				if(dis>=ball[index].ball.r+ball[ball[index].nojudindex].ball.r)
				{
					ball[index].nojudindex=-1;
				}
			}
			


			//�{�[�����m���H������ł�����߂�
//			if(ball[index].nojudindex==-1)
			{
				for(i=0;i<BALL_MAX;i++)
				{
					//��������Ȃ�&�{�[��������
					if(index!=i && ball[i].enable && ball[index].nojudindex!=i && ball[i].nojudindex!=index)
					{
						dis=distance3(ball[index].ball.po.x-ball[i].ball.po.x,ball[index].ball.po.y-ball[i].ball.po.y,ball[index].ball.po.z-ball[i].ball.po.z );
						if(dis<ball[index].ball.r+ball[i].ball.r)
						{
//							MessageBox(NULL,"","",MB_OK);
							vec=ball[i].ball.po-ball[index].ball.po;//vec=i���猩��index�̈ʒu
							if(vec==D3DXVECTOR3(0,0,0))vec.y=1;
							changedistance3(&vec.x,&vec.y,&vec.z,ball[index].ball.r+ball[i].ball.r-dis);
							vec.x*=0.5f;
							vec.y*=0.5f;
							vec.z*=0.5f;
							ball[index].ball.po-=vec;
							ball[i].ball.po+=vec;
						}
					}
				}
			}



















			//�O�������蔻��

			int counter;
			for(counter=0;counter<5;counter++)
			{
				judc.reset();

				judc.FieldJud(true,ball[index].ball.r,&ball[index].ball.po,&(ball[index].ball.po+ball[index].ball.mv));

				for(i=0;i<BALL_MAX;i++)
				{
					if(i!=index && ball[i].enable && i!=ball[index].nojudindex && index!=ball[i].nojudindex)
					{
						judc.SphereJud(true,BALLKIND_START+i,ball[i].ball.r,ball[index].ball.r,&ball[i].ball.po,&ball[index].ball.po,&(ball[index].ball.po+ball[index].ball.mv));
					}
				}

				if(judc.judres.count!=0)
				{
					judc.sort();

					//���S�΍�
					if(judc.judres.p[0]<0)
						judc.judres.p[0]=0;


					if(judc.judres.kind[0]<BALLKIND_START)//�ǂɓ������Ă���
					{


						//��]�ʂ��A��̕����Ɖ�]�����߂�

						//���̂��������ʒu�����߂�
						D3DXVECTOR3 pointp=judc.judres.n[0];
						pointp.x*=-ball[index].ball.r;
						pointp.y*=-ball[index].ball.r;
						pointp.z*=-ball[index].ball.r;

						//���������ʒu�̈ړ��ʂ����߂�
						D3DXVECTOR3 attpointmove=ball[index].ball.getrota(pointp),attpointrota=ball[index].ball.getrota(pointp);



						float avgdf=((matstruct[ball[index].matindex].df*muldf)+matstruct[stagestate[judc.judres.kind[0]].matindex].df)/2;
						float avgsf=((matstruct[ball[index].matindex].sf*mulsf)+matstruct[stagestate[judc.judres.kind[0]].matindex].sf)/2;
						float addrollres=matstruct[ball[index].matindex].rollres+matstruct[stagestate[judc.judres.kind[0]].matindex].rollres;



						if(ball[index].meshindex==BALLMESH_YUUDOU)
						{
							//���C��0
							avgdf=0;avgsf=0;

						}




						//�����ނɂ���Ă��낢��ȃG�t�F�N�g

						if(stagestate[judc.judres.kind[0]].matindex==MATKIND_SUNA)
						{

							if(judc.judres.p[0]*(ball[index].ball.w*mulw)>2.0f)
							{
								//���Ȃ��{�����I�I��

								for(j=0;j<(judc.judres.p[0]*(ball[index].ball.w*mulw)-2.0f)*2+1;j++)
								{
	//								if(rnd(100)<50)
									{
										for(i=0;i<KEMURI_MAX;i++)
										{
											if(kemuri[i].frame==0)
											{
												kemuri[i].frame=1;
												kemuri[i].kind=0;
												kemuri[i].framemax=100+(int)rnd(20);
												kemuri[i].po=pointp+ball[index].ball.po;
												kemuri[i].mv=D3DXVECTOR3(rnd(0.1f)-0.05f,rnd(0.1f)-0.05f,rnd(0.1f)-0.05f);

												i=KEMURI_MAX;
											}
										}
									}
								}

							}


							dis=distance3(attpointmove.x+attpointrota.x,attpointmove.y+attpointrota.y,attpointmove.z+attpointrota.z);

							if(dis>0.5f)
							{
								//���ɕ�����

	//							for(j=0;j<3;j++)
								{
									if(rnd(100)<10+dis*20)
									{
										for(i=0;i<KEMURI_MAX;i++)
										{
											if(kemuri[i].frame==0)
											{
												kemuri[i].frame=1;
												kemuri[i].kind=0;
												kemuri[i].framemax=60+(int)rnd(10);
												kemuri[i].po=pointp+ball[index].ball.po;
												kemuri[i].mv=D3DXVECTOR3(	(attpointmove.x+attpointrota.x)/6+rnd(0.2f)-0.1f,
																			(attpointmove.y+attpointrota.y)/6+rnd(0.2f)-0.1f,
																			(attpointmove.z+attpointrota.z)/6+rnd(0.2f)-0.1f);

												i=KEMURI_MAX;
											}
										}
									}
								}

							}




						}







						//�d�͕����ύX(�َ���)
						if(stagestate[judc.judres.kind[0]].matindex==MATKIND_GURABI || player[index].usekind==ITEMKIND_GURABI)
							ball[index].gv=judc.judres.n[0];




						//�v���C���[�ŃR�[�X�A�E�g�ȊO�̂Ƃ�
						if(index<playercount && ball[index].deletecount==0 && stagestate[judc.judres.kind[0]].kind!=ITAKIND_CORCEOUT)
						{
							if(player[index].InputEnable)
							{
								//�n�ʂƏd�͕����Ƃ̊p�x�ɂ��Apar�̐ݒ�(���ςŌv�Z)
								if(	ball[index].gv.x*judc.judres.n[0].x+
									ball[index].gv.y*judc.judres.n[0].y+
									ball[index].gv.z*judc.judres.n[0].z>0.6f)
								{
									player[index].par=player[index].temppar;
								}
							}
						}





						//�{�[���ɗ͂�������
						if(stagestate[judc.judres.kind[0]].kind==ITAKIND_NORMAL)//����
						{

							ball[index].ball.setpower(pointp,D3DXVECTOR3(0,0,0),judc.judres.p[0]*(ball[index].ball.w*mulw),avgdf,avgsf,0.5f);

						}
						else if(stagestate[judc.judres.kind[0]].kind==ITAKIND_CORCEOUT)//�R�[�X�A�E�g
						{

							if(index<playercount)
							{

								player[index].InputEnable=false;

								if(stagekind==SELECTGAME_STAGE && sel.enable==false)
								{
									autostop=true;
									stopplayer=0;
									CallSelect(CALLMODE_GAME,60);

									if(stagestate[judc.judres.kind[0]].matindex==MATKIND_NULL && stagenum!=20)
										feed[index].Start(FEEDMODE_BLACKOUT,100);
								}
								else if(stagekind==SELECTGAME_VARSUS || stagekind==SELECTGAME_MULTIPLAY)
								{
									if(index<playercount && ball[index].deletecount==0)
										ball[index].deletecount=150;
								}


								if(player[index].goal==true)
									ball[index].deletecount=0;
							}


							if(stagestate[judc.judres.kind[0]].matindex!=MATKIND_NULL)
								ball[index].ball.setpower(pointp,D3DXVECTOR3(0,0,0),judc.judres.p[0]*(ball[index].ball.w*mulw),avgdf,avgsf,0.5f);

						}
						else if(stagestate[judc.judres.kind[0]].kind==ITAKIND_MOVE)//�ړ�
						{
							ball[index].ball.setpower(pointp, stagestate[judc.judres.kind[0]].v, judc.judres.p[0]*(ball[index].ball.w*mulw),avgdf,avgsf,0.5f);

						}
						else if(stagestate[judc.judres.kind[0]].kind==ITAKIND_ROTATE)//��]
						{
							D3DXVECTOR3 atpo=ball[index].ball.po+pointp-stagestate[judc.judres.kind[0]].v;//AttackPoint

							D3DXVECTOR3 wv,mv;

							//���������ʒu����]�������Ƃ߂�
							axisvector(&wv.x,&wv.y,&wv.z,stagestate[judc.judres.kind[0]].v2.x,stagestate[judc.judres.kind[0]].v2.y,
										stagestate[judc.judres.kind[0]].v2.z,atpo.x,atpo.y,atpo.z);


							//wv�Ɖ�]���ƂŊO�ς����
							crosspro3(&mv.x,&mv.y,&mv.z,stagestate[judc.judres.kind[0]].v2.x,
										stagestate[judc.judres.kind[0]].v2.y,stagestate[judc.judres.kind[0]].v2.z,
										wv.x,wv.y,wv.z);

							float l=2*pi*distance3(wv.x,wv.y,wv.z)*distance3(stagestate[judc.judres.kind[0]].v2.x,
										stagestate[judc.judres.kind[0]].v2.y,stagestate[judc.judres.kind[0]].v2.z)/360;

							mv.x*=l;
							mv.y*=l;
							mv.z*=l;

							ball[index].ball.setpower(pointp,mv,judc.judres.p[0]*(ball[index].ball.w*mulw),avgdf,avgsf,0.5f);
						}


						if(stagestate[judc.judres.kind[0]].matindex!=MATKIND_NULL)
						{






							//�{�[�������e��������
							if(ball[index].meshindex==BALLMESH_BOMB)
							{
								//��]���~�܂��Ă�p�����Ȃ������甚��

								if(judc.judres.p[0]<0.03f && D3DXVec3Length(&ball[index].ball.axis)<0.3f)
								{//�����I�I

									Bakuhatu(index);

								}

							}
							else if(ball[index].meshindex==BALLMESH_YUUDOU)//�U�����܂�������
							{


								//�ǂɂ͐��ʂ���Ԃ���Ȃ��Ɣ������Ȃ�
								float mul=ball[index].ball.mv.x*judc.judres.n[0].x+
									ball[index].ball.mv.y*judc.judres.n[0].y+
									ball[index].ball.mv.z*judc.judres.n[0].z;
								if(	mul>0.4f || mul<-0.4f)//����
								{
									Bakuhatu(index);
								}


							//	//�ǂɂ͋��߂ɓ�����Ȃ��Ɣ������Ȃ�
							//	if(judc.judres.p[0]>0.1f)
							}

							else if(ball[index].meshindex==BALLMESH_TAMA)
							{
								ball[index].enable=false;
							}









							//�͂˂�
							ball[index].ball.mv.x+=judc.judres.n[0].x*judc.judres.p[0]*(1+matstruct[ball[index].matindex].bound*matstruct[stagestate[judc.judres.kind[0]].matindex].bound);
							ball[index].ball.mv.y+=judc.judres.n[0].y*judc.judres.p[0]*(1+matstruct[ball[index].matindex].bound*matstruct[stagestate[judc.judres.kind[0]].matindex].bound);
							ball[index].ball.mv.z+=judc.judres.n[0].z*judc.judres.p[0]*(1+matstruct[ball[index].matindex].bound*matstruct[stagestate[judc.judres.kind[0]].matindex].bound);


							//�G��Ă�n�ʂ̎�ނɂ��A�{�[���̉�]����߂�
							ball[index].ball.setrotaressub(addrollres);




							if(index<playercount && stagekind!=SELECTGAME_STAGE)
							{
								//�J������UPNext��ς���
								player[index].cupnext.x+=(judc.judres.n[0].x-player[index].cupnext.x)*0.4f;
								player[index].cupnext.y+=(judc.judres.n[0].y-player[index].cupnext.y)*0.4f;
								player[index].cupnext.z+=(judc.judres.n[0].z-player[index].cupnext.z)*0.4f;
								changedistance3(&player[index].cupnext.x,&player[index].cupnext.y,&player[index].cupnext.z,1);
							}







							//�U��

							float vib=judc.judres.p[0]*(ball[index].ball.w)/10.0f;
							if(vib>0.05f)
								if(!autoReplay)
									DI.SetEffect(multiplayindex(index),vib,(int)(vib*5),0);



							//�ǂ̎�ނɉ����Č��ʉ����Đ�

							//���ʂƎ��g���̐ݒ�
							float vol,hz;

							vol=judc.judres.p[0]*(ball[index].ball.w)/8.0f;
							if(vol>1)vol=1;
							hz=70.0f/ball[index].ball.w;

							//�Đ����鉹�̎�ނ𒲂ׂ�
							int soundkind;
							soundkind=stagestate[judc.judres.kind[0]].matindex;

							if(soundkind==MATKIND_SIBA || soundkind==MATKIND_SUNA)
							{
								//�Ő��͓��ʂɈړ����Ă邾���ŉ����o��

								if(soundkind==MATKIND_SIBA)
								{
									vol+=D3DXVec3Length(&ball[index].ball.mv)*5;
								}
								else
								{
									vol+=distance3(attpointmove.x+attpointrota.x,attpointmove.y+attpointrota.y,
										attpointmove.z+attpointrota.z);
								}
								if(vol>1)vol=1;


								if(soundkind==MATKIND_SUNA)
									hz*=0.8f;
								soundkind=SOUNDKIND_SIBA;


							}
							else if(soundkind==MATKIND_TUTI)
							{
								soundkind=SOUNDKIND_PURA;
								hz*=0.6f;
								vol*=0.9f;
							}
							else if(soundkind==MATKIND_GOMU)
							{
								soundkind=SOUNDKIND_GOMU;
							}
							else if(soundkind==MATKIND_KI)
							{
								soundkind=SOUNDKIND_PURA;
							}
							else if(soundkind==MATKIND_TETU || soundkind==MATKIND_TETU2)
							{
								soundkind=SOUNDKIND_TETU;

							}
							else if(soundkind==MATKIND_ISI)
							{
								if(ball[index].meshindex==BALLMESH_CHARA+4 || 
									ball[index].meshindex==BALLMESH_BOMB || ball[index].meshindex==BALLMESH_YUUDOU)
								{
									soundkind=SOUNDKIND_TETU;
									hz*=0.8f;
								}
								else
								{
									soundkind=SOUNDKIND_PURA;
									hz*=1.2f;
								}
							}
							else if(soundkind==MATKIND_IZIGEN || soundkind==MATKIND_GURABI)
							{
								soundkind=SOUNDKIND_IZIGEN;
							}

							if(hz<0.1f)hz=0.1f;

							static int sibacount=0;
							if(sibacount>0)
								sibacount--;

//							soundkind=SOUNDKIND_PURA;

							if(vol>0.06f)
							{


								if(soundkind==SOUNDKIND_SIBA)
								{

									if(sibacount==0)
									{
										sibacount=10;

										SoundPlay(soundkind,index,vol,hz);

									}
								}
								else
								{
									SoundPlay(soundkind,index,vol,hz);
								}


							}






						}
						else
						{
//							feed[index].FeedStart(FEEDMODE_BLACKOUT,60);
							counter=0;
							break;
						}


					}
					else//�{�[���ɂ������Ă���
					{

						float vib=judc.judres.p[0]*(ball[index].ball.w*mulw)/10.0f;
						if(vib>0.05f)
							if(!autoReplay)
								DI.SetEffect(multiplayindex(index),vib,(int)(vib*5),0);



//						if(ball[judc.judres.kind[0]-BALLKIND_START].deletecount)


						int index2=judc.judres.kind[0]-BALLKIND_START;

//						judc.judres.p[0]*=0.5;


						D3DXVECTOR3 pointp=-judc.judres.n[0];


						//�����̂Ԃ����������𒲂ׂ�
						float v1=dotpro3(pointp.x,pointp.y,pointp.z,ball[index].ball.mv.x,ball[index].ball.mv.y,ball[index].ball.mv.z);
						//����̂Ԃ����������𒲂ׂ�
						float v2=dotpro3(pointp.x,pointp.y,pointp.z,ball[index2].ball.mv.x,ball[index2].ball.mv.y,ball[index2].ball.mv.z);

						//�������Ă鑊��̐����Əd���A�����̐����Əd�����A������͂����߂�
						float tikara=sayou( (ball[index].ball.w*mulw), v1, ball[index2].ball.w, v2, matstruct[ball[index].matindex].bound*matstruct[ball[index2].matindex].bound );

						if(tikara>0)
						{

							//���̂��������ʒu�����߂�(����)
							pointp.x*=ball[index].ball.r;
							pointp.y*=ball[index].ball.r;
							pointp.z*=ball[index].ball.r;

							D3DXVECTOR3 pointp2=judc.judres.n[0];
							pointp2.x*=ball[index2].ball.r;
							pointp2.y*=ball[index2].ball.r;
							pointp2.z*=ball[index2].ball.r;


							//�͂˂�

							//�����ɗ͂�������
							D3DXVECTOR3 powerp=judc.judres.n[0];
							powerp.x*=tikara;
							powerp.y*=tikara;
							powerp.z*=tikara;
							ball[index].ball.setmove(powerp);
							
							//����ɗ͂�������
							ball[index2].ball.setmove(-powerp);


							float avgdf=((matstruct[ball[index].matindex].df*muldf)+matstruct[ball[index2].matindex].df)/2.0f;//�������Ă��������̂Ŏキ����
							float avgsf=((matstruct[ball[index].matindex].sf*mulsf)+matstruct[ball[index2].matindex].sf)/2.0f;//�������Ă��������̂Ŏキ����
							float addrollres=matstruct[ball[index].matindex].rollres+matstruct[ball[index2].matindex].rollres;





							//�{�[���ɗ͂�������
							//�������Ă�ʒu�̈ړ��ʂ��������W�ŋ��߂�!

							//�����ɂ�����͂̊���
							float powerres=ball[index2].ball.w/((ball[index].ball.w*mulw)+ball[index2].ball.w);


							D3DXVECTOR3 movev;
							movev=ball[index2].ball.getmove(pointp2)+ball[index2].ball.getrota(pointp2);
							ball[index].ball.setpower(pointp,movev,tikara*2*(powerres),avgdf,avgsf,0.5f);

							movev=ball[index].ball.getmove(pointp)+ball[index].ball.getrota(pointp);
							ball[index2].ball.setpower(pointp2,movev,tikara*2*(1-powerres),avgdf,avgsf,0.5f);




							//���肪�v���C���[�ŁA�������t�@�C���[�������瑊��ɂ��ڂ�
							if(index<playercount && index2<playercount)
							{
								if(player[index].usekind==ITEMKIND_FIRE && player[index2].usekind!=ITEMKIND_FIRE)
								{
									player[index2].usekind=ITEMKIND_FIRE;
									player[index2].usecount=player[index].usecount*2;
									if(player[index2].usecount>FIRE_COUNT)
										player[index2].usecount=FIRE_COUNT;
								}
								if(player[index2].usekind==ITEMKIND_FIRE && player[index].usekind!=ITEMKIND_FIRE)
								{
									player[index].usekind=ITEMKIND_FIRE;
									player[index].usecount=player[index2].usecount*2;
									if(player[index].usecount>FIRE_COUNT)
										player[index].usecount=FIRE_COUNT;
								}
							}


							//�G��Ă�{�[���̎�ނɂ��A�{�[���̉�]����߂�
							ball[index].ball.setrotaressub(addrollres);



							if(ball[index].meshindex==BALLMESH_TAMA)
							{
								ball[index].enable=false;
							}
							if(ball[index2].meshindex==BALLMESH_TAMA)
							{
								ball[index2].enable=false;
							}

							if(ball[index].meshindex==BALLMESH_YUUDOU)//�U�����܂�������
							{
									Bakuhatu(index);
							}
							if(ball[index2].meshindex==BALLMESH_YUUDOU)//�U�����܂�������
							{
									Bakuhatu(index2);
							}



							//�U��

							float vib=judc.judres.p[0]*(ball[index].ball.w)/10.0f;
							if(vib>0.05f)
								if(!autoReplay)
									DI.SetEffect(multiplayindex(index),vib,(int)(vib*5),0);




							//�{�[���̎�ނɉ����Č��ʉ����Đ�(2���ʉ���炷)

							int indexs[2]={index,index2};
							//�Đ����鉹�̎�ނ𒲂ׂ�
							int soundkind;//={SOUNDKIND_PURA,SOUNDKIND_PURA};

							for(i=0;i<2;i++)
							{

								//���ʂƎ��g���̐ݒ�
								float vol,hz;

								vol=judc.judres.p[0]*(ball[indexs[i]].ball.w)/8.0f;
								if(vol>1)vol=1;
								hz=70.0f/ball[indexs[i]].ball.w;

								if(hz<0.1f)hz=0.1f;

								//�{�[���̍ގ��ɂ͎��̂��̂�����
								//�v���X�`�b�N�A�����A��
								//���̎�ނɂ̓v���X�`�b�N�ƓS�̂�


								soundkind=SOUNDKIND_PURA;

								if(ball[indexs[i]].matindex==MATKIND_CHARA+4 || ball[indexs[i]].matindex==MATKIND_TETU || ball[indexs[i]].matindex==MATKIND_TETU2 || ball[indexs[i]].matindex==MATKIND_YUUDOU)
									soundkind=SOUNDKIND_TETU;



								if(vol>0.06f)
								{

									SoundPlay(soundkind,index,vol,hz);


								}//�T�E���h�Đ������I��

							}//2�̉����[�v�I��


						}

					}


				}
				else
				{
					counter=0;
					break;
				}

			}


			//�{�[�������ۂɓ�����
			if(counter==0)
				ball[index].ball.move();
			else
				ball[index].ball.move(false,true);



			if(stagekind==SELECTGAME_STAGE && index<playercount && !(replay && autoReplay) && !staff)
			{
//				player[index].cpoold=player[index].cpo;
				player[index].cpo+=ball[index].ball.mv;
				player[index].cponext+=ball[index].ball.mv;
			}



		}
	}






	//�S�[�X�g�p�ɂ����������
	ball[BALL_MAX-1].ball.move();




























	float mulpow,mulsp;




	//�v���C���[���[�v
	static oldlap[4];

	for(index=0;index<playercount;index++)
	{

		if(player[index].MutekiCount>0) player[index].MutekiCount--;

		mulpow=1;mulsp=1;

		//�A�C�e���ɉ����ĕω�����
		if(player[index].usekind==ITEMKIND_FIRE)
		{
			mulpow=1.3f;mulsp=1.3f;
		}
		else if(player[index].usekind==ITEMKIND_MIZU)
		{
			mulpow=0.7f;mulsp=0.7f;
		}

		//���ʂɉ����Ă��ω�����(1�ʂ���Ƃ��Alap+par�̍��ŋ��߂�)

		//��ʂ̃C���f�b�N�X�����߂�
		for(i=0;i<playercount;i++)
			if(player[i].rank==1)
			{
				float tempmulsp=(player[i].lap+player[i].par)-(player[index].lap+player[index].par);
				tempmulsp*=0.2f;
				tempmulsp++;
				if(tempmulsp>1.3f) tempmulsp=1.3f;
				if(tempmulsp<1.0f) tempmulsp=1.0f;
				mulsp*=tempmulsp;
				break;
			}



		//�t�F�[�h�A�E�g����(��C�ŊO�ɔ�яo���Ƃ�)
		if(feed[index].mode==FEEDMODE_WHITEOUT && feed[index].count==feed[index].countend/2)
		{
//			feed[index].Start(FEEDMODE_WHITEIN,150);
			feed[index].countend=150;
			feed[index].count=feed[index].countend/2;
			feed[index].mode=FEEDMODE_WHITEIN;
		}


		//�c���̉�]�������I�I(�Q�[���ɂȂ�Ȃ��̂�)
		float rollres=matstruct[ball[index].matindex].rollres*40;

		//��]���̕������������߁Aaddrollres�ň���
		D3DXVECTOR3 svec=ball[index].gv;
		dis=dotpro3(svec.x,svec.y,svec.z,ball[index].ball.axis.x,ball[index].ball.axis.y,ball[index].ball.axis.z);
		if(dis>0 && dis>rollres)
		{
			changedistance3(&svec.x,&svec.y,&svec.z,-rollres);
		}
		else if(dis<0 && dis<-rollres)
		{
			changedistance3(&svec.x,&svec.y,&svec.z,rollres);
		}
		else
		{
			changedistance3(&svec.x,&svec.y,&svec.z,-dis);
		}

		ball[index].ball.axis+=svec;






		if(player[index].goal==false)
		{

			//�R�[�X�̈ʒu���v�Z
			float w=InfoGetPar(index),old=player[index].temppar;
			if(w!=-1)
			{
				if(w>=1)
					w--;
				else if(w<0)
					w++;
				player[index].temppar=w;
			}


			if(stagekind!=SELECTGAME_STAGE)
			{
				if(old>player[index].temppar && D3DXVec3Length(&ball[index].ball.mv)>0.27f)
				{
					if(player[index].backcount<60)
					{
						player[index].backcount++;
					}
					else
					{
						//�t���\������
						if(info.backframe[index]==0)
							info.backframe[index]=120;
					}
				}
				else
				{
					//���񂾂�J�E���g��߂��Ă���
					player[index].backcount-=3;
					if(player[index].backcount<0)
						player[index].backcount=0;
				}
			}


			if(old>0.7f && player[index].temppar<0.3f)
			{
				player[index].lap++;
				if((stagekind==SELECTGAME_VARSUS || stagekind==SELECTGAME_MULTIPLAY) && player[index].lap>lap)
				{
					//�S�[��
					player[index].goal=true;
					if(playercount==1)
					{
						SOUND_PLAY(sd.Kansei);

						if(!replay)
						{
							if(hTime[stagenum+STAGE_MAX]>Time || hTime[stagenum+STAGE_MAX]==0)
							{
								ReplayEnd();
								ReplayCopy();
								info.hscoreframe=120;
								hTime[stagenum+STAGE_MAX]=Time;
							}
							SaveClear();
						}
						
						player[index].InputEnable=false;
						autostop=true;
						if(autoReplay)
							feed[4].Start(FEEDMODE_BLACKOUT,300);
						else
						{
							stopplayer=0;
							CallSelect(CALLMODE_GAME,200);
						}
						InfoGoal();


					}
					else
					{
						info.goalrankframe[index]=120;
						player[index].InputEnable=false;

						//�ǂ������Ȃ��悤�ȏ���
						if(player[index].rank==1)
							player[index].lap=lap+3;
						else if(player[index].rank==2)
							player[index].lap=lap+2;
						else if(player[index].rank==3)
							player[index].lap=lap+1;

						if(player[index].rank>=playercount-1)//�Ō��1�l�O�̂���S�[��
						{

							SOUND_PLAY(sd.Kansei);
							
							for(i=0;i<playercount;i++)
							{
								if(player[i].goal==false)
								{
									info.goalrankframe[i]=120;
									player[i].InputEnable=false;
									autostop=true;
									if(stagekind!=SELECTGAME_MULTIPLAY)
									{
										for(j=0;j<playercount;j++)
											player[j].goal=true;
										if(autoReplay)
											feed[4].Start(FEEDMODE_BLACKOUT,300);
										else
										{
											stopplayer=4;
											CallSelect(CALLMODE_GAME,200);
										}
									}
									else
									{
										//�S���t�F�[�h�A�E�g
										for(j=0;j<playercount;j++)
											player[j].goal=true;
										feed[4].Start(FEEDMODE_BLACKOUT,300);
									}


									break;
								}
							}
						}
					}
				}
			}
			else if(old<0.3f && player[index].temppar>0.7f && player[index].lap<=lap)
				player[index].lap--;

			if(oldlap[index]!=player[index].lap && oldlap[index]>0 && oldlap[index]<=lap && player[index].lap>0 && player[index].lap<=lap)
			{
				info.lapframe[index]=30;
				if(player[index].lap==lap && player[index].FinalLap==false)
				{
					//�t�@�C�i�����b�v

					//�}���`�v���C�̂Ƃ��͎��������Đ�
//					if(stagekind!=SELECTGAME_MULTIPLAY || index==multiplayernum)
//					SOUND_PLAY(sd.Final);

					info.finalframe[index]=120;
					player[index].FinalLap=true;
				}
			}
			oldlap[index]=player[index].lap;

		}






		//�N���C�A���g���́A�T�[�o�[���瑗���Ă�������X�V�����ϐ��AClientItem�𔻒f���ăA�C�e���������s��

		if(stagekind==SELECTGAME_MULTIPLAY && !Setting.Seaver)//�N���C�A���g��������
		{

			if(player[index].ClientItem==1)
				player[index].itemkind=player[index].ClientItemKind;
			if(player[index].ClientItem==2)
			{
				player[index].usekind=player[index].ClientItemKind;
				player[index].usecount=player[index].ClientItemCount;
			}
		}

		int wi;
		float ws;

		//�V���b�g�ƃO���r,�t�@�C�A�[,�E�H�[�^�[�̈ꕔ�͐�ɏ���(�}���`�v���C�N���C�A���g�p)


		if(player[index].usekind==ITEMKIND_FIRE)
		{

			//�t�@�C���[���T���U�炷


			if(rnd(10)<4)
			{
				for(k=0;k<KEMURI_MAX;k++)
				{

					if(kemuri[k].frame==0)
					{
						kemuri[k].kind=4+(int)rnd(2);
						kemuri[k].frame=1;
						if(kemuri[k].kind==4)
						{
							kemuri[k].framemax=(int)rnd(40)+50;
							kemuri[k].mv=D3DXVECTOR3(ball[index].gv.x/15.0f+rnd(0.06f)-0.03f,ball[index].gv.y/15.0f+rnd(0.06f)-0.03f,ball[index].gv.z/15.0f+rnd(0.06f)-0.03f);
						}
						else
						{
							kemuri[k].framemax=(int)rnd(20)+30;
							kemuri[k].mv=D3DXVECTOR3(ball[index].gv.x/30.0f+rnd(0.04f)-0.02f,ball[index].gv.y/30.0f+rnd(0.04f)-0.02f,ball[index].gv.z/30.0f+rnd(0.04f)-0.02f);
						}
						kemuri[k].po=ball[index].ball.po;

						break;
					}
				}
			}

		}
		else if(player[index].usekind==ITEMKIND_SHOT)
		{

			//1�������甭�ˁI�I

			//�܂��ɂ��Ĉ�ԋ߂��L�����N�^�[(���������˂����ȊO�̗U�����e��)��T��(���ȏ�̋�������������J�[�\���͐i�s������)


			ws=300;//�łĂ���E�͈̔�
			wi=index;

			for(i=0;i<BALL_MAX;i++)
			{
				if((i!=index && i<playercount) || (ball[i].meshindex==BALLMESH_YUUDOU && ball[i].info[0]!=index))
				{
					dis=D3DXVec3Length(&(ball[index].ball.po-ball[i].ball.po));
					if(dis<ws)
					{
						ws=dis;
						wi=i;
					}
				}
			}

			kemuri[KEMURI_MAX-1-index].kind=6;
			kemuri[KEMURI_MAX-1-index].framemax=SHOT_COUNT+30;
			kemuri[KEMURI_MAX-1-index].frame=player[index].usecount+30;
			kemuri[KEMURI_MAX-1-index].mv=D3DXVECTOR3(0,0,0);
			kemuri[KEMURI_MAX-1-index].po=ball[wi].ball.po;
		}
		else if(player[index].usekind==ITEMKIND_GURABI)
		{

			//�����T���U�炷

			if(rnd(10)<8)
			{
				for(k=0;k<KEMURI_MAX;k++)
				{

					if(kemuri[k].frame==0)
					{
						kemuri[k].kind=3;
						kemuri[k].frame=1;
						kemuri[k].framemax=(int)rnd(60)+70;
						kemuri[k].po=ball[index].ball.po;
						kemuri[k].mv=D3DXVECTOR3(rnd(0.1f)-0.05f,rnd(0.1f)-0.05f,rnd(0.1f)-0.05f);
						break;
					}
				}
			}
		}
		else if(player[index].usekind==ITEMKIND_MIZU)
		{

			//�����T���U�炷


			if(rnd(100)<3)
			{
				for(k=0;k<KEMURI_MAX;k++)
				{

					if(kemuri[k].frame==0)
					{
						kemuri[k].kind=7;
						kemuri[k].frame=1;

						kemuri[k].framemax=(int)rnd(70)+350;
						kemuri[k].mv=D3DXVECTOR3(ball[index].gv.x/20.0f+rnd(0.02f)-0.01f,ball[index].gv.y/20.0f+rnd(0.02f)-0.01f,ball[index].gv.z/20.0f+rnd(0.02f)-0.01f);

						kemuri[k].po=ball[index].ball.po;

						break;
					}
				}


				//���ʉ��Đ�
				if(play3d)
				{

					si=stopindex3d(sd.Mizu3D);
					sd.Mizu3D[si].Param.vPosition=ball[index].ball.po;
					sd.Mizu3D[si].Param.vVelocity=D3DXVECTOR3(0,0,0);
					sd.Mizu3D[si].Buffer->SetAllParameters( &sd.Mizu3D[si].Param, DS3D_DEFERRED );
					SOUND_PLAY(sd.Mizu3D[si].Sound);

				}
				else
				{
					si=stopindex(sd.Mizu);
					SOUND_PLAY(sd.Mizu[si]);
					sd.Mizu[si]->GetBuffer(0)->SetVolume(getvolume(ball[index].ball.po));
				}


				//�U��
				if(!autoReplay)
					DI.SetEffect(multiplayindex(index),0.5f,10);

			}


		}








		if(seaver || player[index].ClientItem==2)
		{


		if(player[index].usekind==ITEMKIND_FIRE)
		{


			//���ʉ��Đ�
			if((player[index].usecount+1)%40==0)
			{

				if(play3d)
				{

					si=stopindex3d(sd.Fire3D);
					sd.Fire3D[si].Param.vPosition=ball[index].ball.po;
					sd.Fire3D[si].Param.vVelocity=D3DXVECTOR3(0,0,0);
					sd.Fire3D[si].Buffer->SetAllParameters( &sd.Fire3D[si].Param, DS3D_DEFERRED );
					SOUND_PLAY(sd.Fire3D[si].Sound);

				}
				else
				{
					si=stopindex(sd.Fire);
					SOUND_PLAY(sd.Fire[si]);
					sd.Fire[si]->GetBuffer(0)->SetVolume(getvolume(ball[index].ball.po));
				}

			}


			//�N���C�A���g�Ƀf�[�^�𑗂�
			if(seaver)
				SendItem(ITEMKIND_FIRE,false,index,player[index].usecount);

		}

		else if(player[index].usekind==ITEMKIND_SHOT)
		{

			//1�������甭�ˁI�I





			if(player[index].usecount==1)
			{

				D3DXVECTOR3 shotv=ball[wi].ball.po+(-(D3DXVECTOR3)(ball[wi].gv)*0.3f)-ball[index].ball.po;



				kemuri[KEMURI_MAX-1-index].frame=1;
				kemuri[KEMURI_MAX-1-index].framemax=30;
				kemuri[KEMURI_MAX-1-index].mv=D3DXVECTOR3(0,0,0);

				if(wi!=index)
				{



					//�������牌���o��
					for(j=0;j<10;j++)
					{
						for(k=0;k<KEMURI_MAX;k++)
						{
							if(kemuri[k].frame==0)
							{
								kemuri[k].kind=2;
								kemuri[k].frame=1;
								kemuri[k].framemax=(int)rnd(50)+30;
								kemuri[k].po=ball[index].ball.po;
								kemuri[k].mv=shotv;
								changedistance3(&kemuri[k].mv.x,&kemuri[k].mv.y,&kemuri[k].mv.z,rnd(0.3f)+0.1f);
								kemuri[k].mv+=D3DXVECTOR3(rnd(0.1f)-0.05f,rnd(0.1f)-0.05f,rnd(0.1f)-0.05f);

								break;
							}
						}
					}


					//�{�[���𔭎�
					for(i=0;i<BALL_MAX;i++)
					{
						if(ball[i].enable==false)
						{
							ball[i].deletecount=60;
							ball[i].ball.reset();
							ball[i].enable=true;
							ball[i].deletecount=0;
							ball[i].gv=D3DXVECTOR3(0,0,0);
							ball[i].matindex=MATKIND_TETU;
							ball[i].meshindex=BALLMESH_TAMA;
							ball[i].nojudindex=index;
							ball[index].nojudindex=i;
							ball[i].ball.po=ball[index].ball.po;
							ball[i].ball.w=1.5f;
							ball[i].ball.r=0.02f;
							//��������_��
							ball[i].ball.mv=shotv;
							changedistance3(&ball[i].ball.mv.x,&ball[i].ball.mv.y,&ball[i].ball.mv.z,20);
							ball[i].ball.move(false,true);

							break;
						}
					}



					//�������������ɔ��
					changedistance3(&shotv.x,&shotv.y,&shotv.z,3.0f);
					ball[index].ball.setmove(-shotv);


				}




				//���ʉ��Đ�
				if(play3d)
				{

					si=stopindex3d(sd.Shot3D);
					sd.Shot3D[si].Param.vPosition=ball[index].ball.po;
					sd.Shot3D[si].Param.vVelocity=ball[index].ball.mv;
					sd.Shot3D[si].Buffer->SetAllParameters( &sd.Shot3D[si].Param, DS3D_DEFERRED );
					SOUND_PLAY(sd.Shot3D[si].Sound);

				}
				else
				{
					si=stopindex(sd.Shot);
					SOUND_PLAY(sd.Shot[si]);
					sd.Shot[si]->GetBuffer(0)->SetVolume(getvolume(ball[index].ball.po));
				}

				if(!autoReplay)
					DI.SetEffect(multiplayindex(index),0.8f,20);


				//�N���C�A���g�Ƀf�[�^�𑗂�
				if(seaver)
					SendItem(ITEMKIND_SHOT,false,index,player[index].usecount);

			}
			else
			{

				//���Ԋu�Ō��ʉ��Đ��i���񂾂�Z���Ȃ���)

				bool playok=false;
				for(i=0;i<100;i++) 
				{

					if(kemuri[KEMURI_MAX-1-index].frame-30==(int)(powf((float)i,1.8f)*2))
						playok=true;
				}

				if(playok)
				{

					//���ʉ��Đ�
					if(play3d)
					{

						si=stopindex3d(sd.ShotCount3D);
						sd.ShotCount3D[si].Param.vPosition=ball[wi].ball.po;
						sd.ShotCount3D[si].Param.vVelocity=ball[wi].ball.mv;
						sd.ShotCount3D[si].Buffer->SetAllParameters( &sd.ShotCount3D[si].Param, DS3D_DEFERRED );
						SOUND_PLAY(sd.ShotCount3D[si].Sound);

					}
					else
					{
						si=stopindex(sd.ShotCount);
						sd.ShotCount[si]->GetBuffer(0)->SetVolume(getvolume(ball[index].ball.po));
						SOUND_PLAY(sd.ShotCount[si]);
					}

				}

				//�N���C�A���g�Ƀf�[�^�𑗂�
				if(seaver)
					SendItem(ITEMKIND_SHOT,false,index,player[index].usecount);


			}
			

		}

		if(player[index].usekind==ITEMKIND_GURABI)
		{


			//���ʉ��Đ�
			if((player[index].usecount)%40==0)
			{

				if(play3d)
				{

					si=stopindex3d(sd.Gurabi3D);
					sd.Gurabi3D[si].Param.vPosition=ball[index].ball.po;
					sd.Gurabi3D[si].Param.vVelocity=D3DXVECTOR3(0,0,0);
					sd.Gurabi3D[si].Buffer->SetAllParameters( &sd.Gurabi3D[si].Param, DS3D_DEFERRED );
					SOUND_PLAY(sd.Gurabi3D[si].Sound);

				}
				else
				{
					si=stopindex(sd.Gurabi);
					SOUND_PLAY(sd.Gurabi[si]);
					sd.Gurabi[si]->GetBuffer(0)->SetVolume(getvolume(ball[index].ball.po));
				}

			}


			//�N���C�A���g�Ƀf�[�^�𑗂�
			if(seaver)
				SendItem(ITEMKIND_GURABI,false,index,player[index].usecount);

		}


		}//�N���C�A���g����






		//�A�C�e������
		if(player[index].usecount>0)
		{
			player[index].usecount--;
			if(player[index].usecount==0)
				player[index].usekind=ITEMKIND_NONE;
		}











		//�A�C�e�����g���I�I

		//for(int testi=0;testi<10;testi++)
		{

		//player[index].itemkind=ITEMKIND_BOMB;
//		player[index].itemkind=ITEMKIND_YUUDOU;

		player[index].itemangle++;
		if((buttonstate[index].item && player[index].InputEnable) || player[index].ClientItem==1)
		{
//				if(!seaver)
//					MessageBox(NULL,"","",MB_OK);



			switch(player[index].itemkind)
			{
			case ITEMKIND_TAIHOU:

				dis=D3DXVec3Length(&ball[index].ball.mv);
				changedistance3(&ball[index].ball.mv.x,&ball[index].ball.mv.y,&ball[index].ball.mv.z,dis+0.5f);


				//����f��
				for(j=0;j<20;j++)
				{
					for(k=0;k<KEMURI_MAX;k++)
					{
						if(kemuri[k].frame==0)
						{
							kemuri[k].kind=2;
							kemuri[k].frame=1;
							kemuri[k].framemax=(int)rnd(100)+50;
							kemuri[k].po=ball[index].ball.po;
							kemuri[k].mv=D3DXVECTOR3((ball[index].ball.mv.x+rnd(0.2f)-0.1f)*(rnd(0.3f)+0.05f),(ball[index].ball.mv.y+rnd(0.2f)-0.1f)*(rnd(0.3f)+0.05f),(ball[index].ball.mv.z+rnd(0.2f)-0.1f)*(rnd(0.3f)+0.05f));

							break;
						}
					}
				}


				//�R���g���[���[�U��
				if(!autoReplay)
					DI.SetEffect(multiplayindex(index),1,60,0);

				//���ʉ��Đ�
				if(play3d)
				{

					si=stopindex3d(sd.Bomb3D);
					sd.Bomb3D[si].Param.vPosition=ball[index].ball.po;
					sd.Bomb3D[si].Param.vVelocity=D3DXVECTOR3(0,0,0);
					sd.Bomb3D[si].Buffer->SetAllParameters( &sd.Bomb3D[si].Param, DS3D_DEFERRED );
					SOUND_PLAY(sd.Bomb3D[si].Sound);

				}
				else
				{
					si=stopindex(sd.Bomb);
					SOUND_PLAY(sd.Bomb[si]);
					sd.Bomb[si]->GetBuffer(0)->SetVolume(getvolume(ball[index].ball.po));
				}


				//�N���C�A���g�Ƀf�[�^�𑗂�
				if(seaver)
					SendItem(ITEMKIND_TAIHOU,true,index);


				break;
			case ITEMKIND_FIRE:

				player[index].usekind=player[index].itemkind;
				player[index].usecount=FIRE_COUNT;

				//�R���g���[���[�U���J�n�I
				if(!autoReplay)
					DI.SetEffect(multiplayindex(index),0.16f,FIRE_COUNT,0);


				//�N���C�A���g�Ƀf�[�^�𑗂�
				if(seaver)
					SendItem(ITEMKIND_FIRE,true,index);


				break;

			case ITEMKIND_MIZU:

				//�����̎���ɐ����o���I�I

				//�t�@�C�A�[�����������
				if(player[index].usekind==ITEMKIND_FIRE)
					player[index].usekind=ITEMKIND_NONE;

				for(i=0;i<20;i++)
				{
					for(k=0;k<KEMURI_MAX;k++)
					{

						if(kemuri[k].frame==0)
						{
							kemuri[k].kind=7;
							kemuri[k].frame=1;

							kemuri[k].framemax=(int)rnd(70)+350;
							kemuri[k].mv=D3DXVECTOR3(rnd(0.08f)-0.04f,rnd(0.08f)-0.04f,rnd(0.08f)-0.04f)+ball[index].ball.mv;

							kemuri[k].po=ball[index].ball.po;

							k=KEMURI_MAX;

						}
					}
				}


				//���ʉ��Đ�
				if(play3d)
				{
					si=stopindex3d(sd.MizuStart3D);
					sd.MizuStart3D[si].Param.vPosition=ball[index].ball.po;
					sd.MizuStart3D[si].Param.vVelocity=D3DXVECTOR3(0,0,0);
					sd.MizuStart3D[si].Buffer->SetAllParameters( &sd.MizuStart3D[si].Param, DS3D_DEFERRED );
					SOUND_PLAY(sd.MizuStart3D[si].Sound);
				}
				else
				{
					si=stopindex(sd.MizuStart);
					sd.MizuStart[si]->GetBuffer(0)->SetVolume(getvolume(ball[index].ball.po));
					SOUND_PLAY(sd.MizuStart[si]);
				}


				for(i=0;i<playercount;i++)
				{
					if(i!=index)
					{
						feed[i].Start(FEEDMODE_WHITEIN,50);
						player[i].usekind=player[index].itemkind;
						player[i].usecount=400;
						//ball[i].ball.mv.x*=0.7f;
						//ball[i].ball.mv.y*=0.7f;
						//ball[i].ball.mv.z*=0.7f;
						ball[i].ball.axis.x*=0.7f;
						ball[i].ball.axis.y*=0.7f;
						ball[i].ball.axis.z*=0.7f;
					}

					if(!autoReplay)
						DI.SetEffect(multiplayindex(i),0.8f,30);

				}



				//�N���C�A���g�Ƀf�[�^�𑗂�
				if(seaver)
					SendItem(ITEMKIND_MIZU,true,index);


				break;



			case ITEMKIND_SHOT:

				player[index].usekind=player[index].itemkind;
				player[index].usecount=SHOT_COUNT;


				//�N���C�A���g�Ƀf�[�^�𑗂�
				if(seaver)
					SendItem(ITEMKIND_SHOT,true,index);

				break;


			case ITEMKIND_BOMB:


				//���ʉ��Đ�
				if(play3d)
				{
					si=stopindex3d(sd.BombOut3D);
					sd.BombOut3D[si].Param.vPosition=ball[index].ball.po;
					sd.BombOut3D[si].Param.vVelocity=D3DXVECTOR3(0,0,0);
					sd.BombOut3D[si].Buffer->SetAllParameters( &sd.BombOut3D[si].Param, DS3D_DEFERRED );
					SOUND_PLAY(sd.BombOut3D[si].Sound);
				}
				else
				{
					si=stopindex(sd.BombOut);
					sd.BombOut[si]->GetBuffer(0)->SetVolume(getvolume(ball[index].ball.po));
					SOUND_PLAY(sd.BombOut[si]);
				}



				for(i=0;i<BALL_MAX;i++)
				{
					if(ball[i].enable==false)
					{
						ball[i].ball.reset();
						ball[i].enable=true;
						ball[i].deletecount=10*60+100;//��deletecount��100�ɂȂ����玩������
						ball[i].gv=ball[index].gv;
						ball[i].matindex=MATKIND_TETU;
						ball[i].meshindex=BALLMESH_BOMB;
						ball[i].nojudindex=index;
						ball[index].nojudindex=i;
						ball[i].ball.po=ball[index].ball.po+D3DXVECTOR3(rnd(0.2f)-0.1f,rnd(0.2f)-0.1f,rnd(0.2f)-0.1f);
						ball[i].ball.w=100.0f;
						ball[i].ball.r=0.5f;
						ball[i].ball.mv=ball[index].gv;
						ball[i].ball.axis=D3DXVECTOR3(rnd(0.4f)-0.2f,rnd(0.4f)-0.2f,rnd(0.4f)-0.2f);
						changedistance3(&ball[i].ball.mv.x,&ball[i].ball.mv.y,&ball[i].ball.mv.z,0.15f);
						ball[i].ball.move(false,true);
						break;
					}
				}
				if(!autoReplay)
					DI.SetEffect(multiplayindex(index),0.8f,10);


				//�N���C�A���g�Ƀf�[�^�𑗂�
				if(seaver)
					SendItem(ITEMKIND_BOMB,true,index);

				break;

			case ITEMKIND_YUUDOU:


				//���ʉ��Đ�
				if(play3d)
				{
					si=stopindex3d(sd.BombOut3D);
					sd.BombOut3D[si].Param.vPosition=ball[index].ball.po;
					sd.BombOut3D[si].Param.vVelocity=D3DXVECTOR3(0,0,0);
					sd.BombOut3D[si].Buffer->SetAllParameters( &sd.BombOut3D[si].Param, DS3D_DEFERRED );
					SOUND_PLAY(sd.BombOut3D[si].Sound);
				}
				else
				{
					si=stopindex(sd.BombOut);
					sd.BombOut[si]->GetBuffer(0)->SetVolume(getvolume(ball[index].ball.po));
					SOUND_PLAY(sd.BombOut[si]);
				}


				for(i=0;i<BALL_MAX;i++)
				{
					if(ball[i].enable==false)
					{
						ball[i].info[0]=index;
						ball[i].ball.reset();
						ball[i].enable=true;
						ball[i].deletecount=20*60+100;//��deletecount��100�ɂȂ����玩������
						ball[i].gv=ball[index].gv;
						ball[i].matindex=MATKIND_YUUDOU;
						ball[i].meshindex=BALLMESH_YUUDOU;
						ball[i].nojudindex=index;
						ball[index].nojudindex=i;
						ball[i].ball.po=ball[index].ball.po;
						ball[i].ball.w=200;
						ball[i].ball.r=0.6f;
						ball[i].ball.mv=ball[index].ball.mv;
						ball[i].ball.axis=D3DXVECTOR3(0,0.6f,0);
						ball[i].ball.move(false,true);



						//���ʉ�
								

						//���ʉ��Đ�(�I�̂�)

						if(seaver)
						{
							if(play3d)
							{

								si=stopindex3d(sd.Yudou3D);
								sd.Yudou3D[si].Param.vPosition=ball[index].ball.po;
								sd.Yudou3D[si].Param.vVelocity=ball[index].ball.mv;
								sd.Yudou3D[si].Buffer->SetAllParameters( &sd.Yudou3D[si].Param, DS3D_DEFERRED );
								sd.Yudou3D[si].Sound->Stop();
								sd.Yudou3D[si].Sound->Reset();
								sd.Yudou3D[si].Sound->Play(0,DSBPLAY_LOOPING);
								ball[i].info[1]=si;
							}
							else
							{
								si=stopindex(sd.Yudou);
								sd.Yudou[si]->GetBuffer(0)->SetVolume(getvolume(ball[index].ball.po));
								sd.Yudou[si]->Stop();
								sd.Yudou[si]->Reset();
								sd.Yudou[si]->Play(0,DSBPLAY_LOOPING);
								ball[i].info[1]=si;
							}
						}

						//�N���C�A���g�Ƀf�[�^����
						if(seaver)
							SendYuudouStart(i,si);


						break;
					}
				}
				if(!autoReplay)
					DI.SetEffect(multiplayindex(index),0.8f,10);

				//�N���C�A���g�Ƀf�[�^�𑗂�
				if(seaver)
					SendItem(ITEMKIND_YUUDOU,true,index);


				break;



			case ITEMKIND_GURABI:



				//���ʉ��Đ�
				if(play3d)
				{
					si=stopindex3d(sd.GurabiStart3D);
					sd.GurabiStart3D[si].Param.vPosition=ball[index].ball.po;
					sd.GurabiStart3D[si].Param.vVelocity=D3DXVECTOR3(0,0,0);
					sd.GurabiStart3D[si].Buffer->SetAllParameters( &sd.GurabiStart3D[si].Param, DS3D_DEFERRED );
					SOUND_PLAY(sd.GurabiStart3D[si].Sound);
				}
				else
				{
					si=stopindex(sd.GurabiStart);
					sd.GurabiStart[si]->GetBuffer(0)->SetVolume(getvolume(ball[index].ball.po));
					SOUND_PLAY(sd.GurabiStart[si]);
				}



				player[index].usekind=player[index].itemkind;
				player[index].usecount=600;


				//�N���C�A���g�Ƀf�[�^�𑗂�
				if(seaver)
					SendItem(ITEMKIND_GURABI,true,index);

				break;


			}

			player[index].itemkind=ITEMKIND_NONE;
		}
		}

		player[index].ClientItem=0;





		//�A�C�e�����Ƃ�I�I
		for(i=0;i<itemcount;i++)
		{
			if(item[i].deletecount==0)
			{
				if(D3DXVec3Length(&(item[i].po-ball[index].ball.po))<ball[index].ball.r+0.7f)
				{

					item[i].getter=index;
					item[i].deletecount=ITEM_COUNT;

					//���ʉ��Đ�
					if(play3d)
					{

						si=stopindex3d(sd.Item3D);
						sd.Item3D[si].Param.vPosition=item[i].po;
						sd.Item3D[si].Param.vVelocity=D3DXVECTOR3(0,0,0);
						sd.Item3D[si].Buffer->SetAllParameters( &sd.Item3D[si].Param, DS3D_DEFERRED );
						SOUND_PLAY(sd.Item3D[si].Sound);

					}
					else
					{
						si=stopindex(sd.Item);
						SOUND_PLAY(sd.Item[si]);
						sd.Item[si]->GetBuffer(0)->SetVolume(getvolume(item[i].po));
					}

				}
			}
		}



		//�J��������



		//�J������UPNext��gv�ɋ߂Â��čs��
		player[index].cupnext.x+=(ball[index].gv.x-player[index].cupnext.x)*0.1f;
		player[index].cupnext.y+=(ball[index].gv.y-player[index].cupnext.y)*0.1f;
		player[index].cupnext.z+=(ball[index].gv.z-player[index].cupnext.z)*0.1f;
		changedistance3(&player[index].cupnext.x,&player[index].cupnext.y,&player[index].cupnext.z,1);



		//if(seaver)
		{



			if(info.startcounter>0)
			{
				if(stagekind==SELECTGAME_STAGE)
				{

					//�p�x�v�Z
					ang=360*sinf((1-(float)info.startcounter/249)*90*rad);
					player[index].cponext=D3DXVECTOR3(ball[index].ball.po.x-sinf(ang*rad)*7,ball[index].ball.po.y+7,ball[index].ball.po.z-cosf(ang*rad)*7);
				}
				else
				{
					player[index].cponext=D3DXVECTOR3(ball[index].ball.po.x,ball[index].ball.po.y+3,-47+40*sinf((1-(float)info.startcounter/249)*90*rad));
				}
			}
			else
			{

				//nextpo�̑���(��苗���ɂ��Ă��獂������)


				D3DXVECTOR3 disvec,provec;
				disvec=player[index].cponext-ball[index].ball.po;


				if(stagekind==SELECTGAME_STAGE)
					changedistance3(&disvec.x,&disvec.y,&disvec.z,15);
				else
					changedistance3(&disvec.x,&disvec.y,&disvec.z,5);


				//cup�����̍����𒲐�
				dis=dotpro3(player[index].cup.x,player[index].cup.y,player[index].cup.z,disvec.x,disvec.y,disvec.z);
				provec=player[index].cup;


				if(stagekind==SELECTGAME_STAGE)
					changedistance3(&provec.x,&provec.y,&provec.z,dis-8);//��������
				else
					changedistance3(&provec.x,&provec.y,&provec.z,dis-2);//��������


				disvec-=provec;

				player[index].cponext=ball[index].ball.po+disvec;

			}











			//�L�^���Ƃ�(Sound�p)
			player[index].cpoold=player[index].cpo;

			//�J�����̈ʒu�������I�ɃX���[�Y�ɐi��
			if(stagekind==SELECTGAME_STAGE)
			{
				player[index].ballold=ball[index].ball.po;
//				player[index].cameraold=player[index].cpo;
			}
			else
			{
				player[index].ballold+=(D3DXVECTOR3)((ball[index].ball.po)-player[index].ballold)*0.3f;
//				player[index].cameraold+=(D3DXVECTOR3)((player[index].cpo)-player[index].cameraold)*0.3f;
			}


			//�J������Po��Next�ɋ߂Â���
			player[index].cpo.x+=(player[index].cponext.x-player[index].cpo.x)*0.1f;
			player[index].cpo.y+=(player[index].cponext.y-player[index].cpo.y)*0.1f;
			player[index].cpo.z+=(player[index].cponext.z-player[index].cpo.z)*0.1f;



			//�J������UP��Next�ɋ߂Â���
			player[index].cup.x+=(player[index].cupnext.x-player[index].cup.x)*0.02f;
			player[index].cup.y+=(player[index].cupnext.y-player[index].cup.y)*0.02f;
			player[index].cup.z+=(player[index].cupnext.z-player[index].cup.z)*0.02f;
			changedistance3(&player[index].cup.x,&player[index].cup.y,&player[index].cup.z,1);









			if(info.startcounter==0 && !(replay && autoReplay) && !staff)
			{


				//�J������]����(UP��PO�̊O�ς��g���A�J���������E�ɓ�����)

				if(buttonstate[index].rightrote || buttonstate[index].leftrote || buttonstate[index].x2!=0)
				{
					//�O�ς����߂�
					D3DXVECTOR3 cameramuki,gaiseki;
					cameramuki=ball[index].ball.po+player[index].cup-player[index].cpo;
					crosspro3(&gaiseki.x,&gaiseki.y,&gaiseki.z,player[index].cup.x,player[index].cup.y,player[index].cup.z,
																					cameramuki.x,cameramuki.y,cameramuki.z);
					if(buttonstate[index].x2==0)
					{
						gaiseki.x*=((int)buttonstate[index].rightrote-(int)buttonstate[index].leftrote)*0.3f;
						gaiseki.y*=((int)buttonstate[index].rightrote-(int)buttonstate[index].leftrote)*0.3f;
						gaiseki.z*=((int)buttonstate[index].rightrote-(int)buttonstate[index].leftrote)*0.3f;
					}
					else
					{
						gaiseki.x*=(buttonstate[index].x2/10000)*0.3f;
						gaiseki.y*=(buttonstate[index].x2/10000)*0.3f;
						gaiseki.z*=(buttonstate[index].x2/10000)*0.3f;
					}

					player[index].cponext+=gaiseki;
				}




				//(UP���g���A�J�������㉺�ɓ�����)
				if(buttonstate[index].y2!=0)
				{
					D3DXVECTOR3 vec3=player[index].cup;

					if(stagekind==SELECTGAME_STAGE)
						changedistance3(&vec3.x,&vec3.y,&vec3.z,(buttonstate[index].y2/10000)*0.5f);
					else
						changedistance3(&vec3.x,&vec3.y,&vec3.z,(buttonstate[index].y2/10000)*0.3f);

					player[index].cpo+=vec3;
				}






			}




		}



		if(player[index].InputEnable && !staff)
		{




			//�����L�[����

			if(buttonstate[index].x!=0 || buttonstate[index].y!=0)
			{
				ang=angle(buttonstate[index].y,buttonstate[index].x);//Z��������0�x�Ƃ��A�ォ�猩�Ď��v���

				//�J�����̕�����cup����ang�x�񂵂���������]�����ɂȂ�



				//�J�����̕����x�N�g����cup�����łԂ�

				D3DXVECTOR3 wvec=ball[index].ball.po+player[index].cup-player[index].cpo;//�J���������i�[
				dis=dotpro3(player[index].cup.x,player[index].cup.y,player[index].cup.z,wvec.x,wvec.y,wvec.z);//�J����������up�����̐�Βl���i�[



				//up�̒�����dis�ɂ��Awvec����Ђ�
				D3DXVECTOR3 wvec2=player[index].cup;
				changedistance3(&wvec2.x,&wvec2.y,&wvec2.z,dis);//�J�����̍���������
				wvec-=wvec2;


				//(wvec�ɂ̓J����������up�łԂ������̂��i�[����Ă���)


				//��]
				D3DXMATRIX mat;
				D3DXMatrixRotationAxis(&mat,&player[index].cup,ang*rad);
				//wvec����]
				D3DXVECTOR4 vec4;
				D3DXVec3Transform(&vec4,&wvec,&mat);

				wvec.x=vec4.x;wvec.y=vec4.y;wvec.z=vec4.z;


				//�������X�e�B�b�N�̓|���x�Œ���
				dis=distance(buttonstate[index].x/10000,buttonstate[index].y/10000)*character[player[index].charnum].speed;
				changedistance3(&wvec.x,&wvec.y,&wvec.z,dis);



				wvec+=ball[index].ball.mv;

				//�Ă�wvec��cup�����ɂԂ�
				dis=dotpro3(player[index].cup.x,player[index].cup.y,player[index].cup.z,wvec.x,wvec.y,wvec.z);//�J����������up�����̐�Βl���i�[
				//up�̒�����dis�ɂ��Awvec����Ђ�
				wvec2=player[index].cup;
				changedistance3(&wvec2.x,&wvec2.y,&wvec2.z,dis);
				wvec-=wvec2;




				////�͂�������ʒu�̑���
				wvec2=player[index].cup;
				changedistance3(&wvec2.x,&wvec2.y,&wvec2.z,ball[index].ball.r);
				
				wvec.x*=mulsp;wvec.y*=mulsp;wvec.z*=mulsp;
				ball[index].ball.setpower(wvec2,wvec,1,character[player[index].charnum].power*mulpow,0,0);






			}

//			�c��]�e�X�g
//			if(buttonstate[index].item)ball[index].ball.axis.y-=0.1f;


			//�W�����v����(�n�ʂɂ��������邱�ƂŃW�����v����������)

			if(buttonstate[index].jump)//�W�����v�L�[
			{




				//�������������̍����Ɠ������������i�[���Ă����A�W�����v�Ɏg��
//				D3DXVECTOR3 hitsum=D3DXVECTOR3(0,0,0);

				judc.reset();
				judc.FieldJud(false,ball[index].ball.r+0.2f,&ball[index].ball.po,&(ball[index].ball.po+ball[index].ball.mv));

				for(i=0;i<BALL_MAX;i++)
				{
					if(i!=index && ball[i].enable && ball[i].nojudindex!=index && ball[index].nojudindex!=i)
					{
						judc.SphereJud(true,BALLKIND_START+i,ball[i].ball.r+0.2f,ball[index].ball.r,&ball[i].ball.po,&ball[index].ball.po,&(ball[index].ball.po+ball[index].ball.mv));
					}
				}

				if(judc.judres.count!=0)
				{

					judc.sort();



					//�ړ��ʃx�N�g���́Ahitsum����������jump�ȉ��Ȃ�jump�ɂ���
					judc.judres.n[0]=-judc.judres.n[0];//�t�x�N�g���ɂ���

					float dis;
					dis=dotpro3(judc.judres.n[0].x,judc.judres.n[0].y,judc.judres.n[0].z,
								ball[index].ball.mv.x,ball[index].ball.mv.y,ball[index].ball.mv.z);

					if(dis<character[player[index].charnum].jump)
					{
						changedistance3(&judc.judres.n[0].x,&judc.judres.n[0].y,&judc.judres.n[0].z,1);

						ball[index].ball.mv.x+=judc.judres.n[0].x*(character[player[index].charnum].jump-dis);
						ball[index].ball.mv.y+=judc.judres.n[0].y*(character[player[index].charnum].jump-dis);
						ball[index].ball.mv.z+=judc.judres.n[0].z*(character[player[index].charnum].jump-dis);
					}




				}


			}






		}














		if(stagekind==SELECTGAME_VARSUS || stagekind==SELECTGAME_MULTIPLAY)
		{


			//�J�����H�����ݖh�~


			judc.reset();

			judc.FieldJud(true,CAMERA_R,&(player[index].ballold),&(player[index].cpo));

			if(judc.judres.count!=0)
			{
				judc.sort();

				for(i=0;i<judc.judres.count;i++)
				{
					if(stagestate[judc.judres.kind[i]].matindex!=MATKIND_NULL)
					{
						//�J�����̈ʒu��G�ꂽ�ʒu+�m�[�}��*0.01�ɐݒ�!!
						player[index].cpo=judc.judres.v[i]+(D3DXVECTOR3)judc.judres.n[0]*0.01f;
						break;
					}
				}

			}



		}







	}






	static int oldrank[4];

	//���ʂ̔���(lap+temppar���傫����)
	int rankindex[4],worki;//�Ղꂢ��[�ԍ�
	float rankpo[4],workpo;//�ʒu
	if(playercount>1)
	{
		for(i=0;i<playercount;i++)
		{
			rankindex[i]=i;
			rankpo[i]=player[i].lap+player[i].temppar;
		}

		for(i=0;i<playercount-1;i++)
		{
			for(j=i+1;j<playercount;j++)
			{
				if(rankpo[i]<rankpo[j])
				{
					workpo=rankpo[i];
					rankpo[i]=rankpo[j];
					rankpo[j]=workpo;
					worki=rankindex[i];
					rankindex[i]=rankindex[j];
					rankindex[j]=worki;
				}
			}
		}

		for(i=0;i<playercount;i++)
		{
			player[rankindex[i]].rank=i+1;
			if(oldrank[rankindex[i]]!=player[rankindex[i]].rank)
				info.rankframe[rankindex[i]]=30;
			oldrank[rankindex[i]]=player[rankindex[i]].rank;
		}

	}










	//���ˌ����琁���o�鉌�����
	for(i=0;i<windcount;i++)
	{
		if(wind[i].enable)
		{
			for(int k=0;k<3*wind[i].dis/30.0f;k++)
			{
				if(rnd(100)<50)
				{
					for(j=0;j<KEMURI_MAX;j++)
					{
						if(kemuri[j].frame==0)
						{
							dis=distance3(wind[i].v.x,wind[i].v.y,wind[i].v.z);

							if(wind[i].kind==0 || wind[i].kind==1)
								kemuri[j].kind=0;
							else
								kemuri[j].kind=wind[i].kind;

							kemuri[j].frame=1;
							kemuri[j].framemax=(int)(wind[i].dis/dis)+(int)rnd(4)-2;
							kemuri[j].po=wind[i].p;


							//���U�͈͌v�Z
							dis=dis*tanf(wind[i].ang/2*rad);

							kemuri[j].mv=D3DXVECTOR3(wind[i].v.x+rnd(dis*2)-dis,wind[i].v.y+rnd(dis*2)-dis,wind[i].v.z+rnd(dis*2)-dis);

							break;
						}
					}
				}
			}
		}
	}






	//���ړ�
	for(i=0;i<KEMURI_MAX;i++)
	{
		if(kemuri[i].frame>0)
		{
			kemuri[i].po+=kemuri[i].mv;
			dis=distance3(kemuri[i].mv.x,kemuri[i].mv.y,kemuri[i].mv.z);
			kemuri[i].frame++;
			if(kemuri[i].frame>=kemuri[i].framemax)
				kemuri[i].frame=0;
		}
	}









	//�X�e�[�W���ƂŁA�t�u�Ȃǂ𓮂���

	//�ً�Ԃ̑�C
	taihoumesh[2].UVTranslationX[0]-=0.003f;

	index=stagemesh.TexNameIndex("�w�i2[2].bmp");

	if(index!=-1)
	{
		stagemesh.ColorOpereter[index]=D3DTOP_MODULATE;

		stagemesh.UVRotation[index]=0;
		stagemesh.UVScalingX[index]=1;
		stagemesh.UVScalingY[index]=1;
		stagemesh.UVTranslationY[index]=0;
		stagemesh.UVTranslationX[index]+=0.005f;
		stagemesh.UVTranslationX[index-1]-=0.001f;
	}


	index=ballmesh[BALLMESH_IZIGENBALL].TexNameIndex("izigenball.png");
	if(index!=-1)
	{
		ballmesh[BALLMESH_IZIGENBALL].UVTranslationX[index]+=0.005f;
		ballmesh[BALLMESH_IZIGENBALL].AlphaOpereter[index+1]=D3DTOP_ADD;
		ballmesh[BALLMESH_IZIGENBALL].ColorOpereter[index+1]=D3DTOP_ADD;
		ballmesh[BALLMESH_IZIGENBALL].UVTranslationX[index+1]-=0.005f;
		ballmesh[BALLMESH_IZIGENBALL].UVRotation[index+1]=0;
		ballmesh[BALLMESH_IZIGENBALL].UVScalingX[index+1]=1;
		ballmesh[BALLMESH_IZIGENBALL].UVScalingY[index+1]=1;
	}

	if(stagekind==SELECTGAME_STAGE)//�X�e�[�W���[�h
	{
		if(stagenum==21)//�e�N�m1
		{
			i=2;
			stagestate[i].s+=D3DXVec3Length( &stagestate[i].v2);
		}
		else if(stagenum==22)//�e�N�m2
		{
			i=2;
			stagestate[i].s+=D3DXVec3Length( &stagestate[i].v2);
			i++;
			stagestate[i].s+=D3DXVec3Length( &stagestate[i].v2);
			i++;
			stagestate[i].s+=D3DXVec3Length( &stagestate[i].v2);


		}
		else if(stagenum==23)//�e�N�m3
		{
			i=2;
			stagestate[i].s+=D3DXVec3Length( &stagestate[i].v2);
		}
		else if(stagenum==24)//�e�N�m4
		{
			stagestate[0].s++;
			if(stagestate[0].s==100)
			{
				for(i=0;i<BALL_MAX;i++)
				{
					if(!ball[i].enable)
					{
						ball[i].enable=true;
						ball[i].deletecount=400;
						ball[i].meshindex=BALLMESH_MINITETU;
						ball[i].ball.reset();
						ball[i].ball.po=gun[0].p;//��C�̒��ɁI�I
						ball[i].ball.r=0.5f;
						ball[i].ball.w=200;
						ball[i].matindex=MATKIND_TETU2;
						ball[i].ball.move(false,true);
						break;
					}
				}
			}
			else if(stagestate[0].s>=200)
			{
				stagestate[0].s=0;
				for(i=0;i<BALL_MAX;i++)
				{
					if(!ball[i].enable)
					{
						ball[i].enable=true;
						ball[i].deletecount=400;
						ball[i].meshindex=BALLMESH_MINITETU;
						ball[i].ball.reset();
						ball[i].ball.po=gun[1].p;//��C�̒��ɁI�I
						ball[i].ball.r=0.5f;
						ball[i].ball.w=200;
						ball[i].matindex=MATKIND_TETU2;
						ball[i].ball.move(false,true);
						break;
					}
				}
			}

			stagestate[1].s++;
			stagestate[10].v2=D3DXVECTOR3(0,sinf(stagestate[1].s*rad)*3,0);

			//��C����
			stagestate[2].s++;
			//�E�A�E�A��
			stagestate[3].s++;
			stagestate[4].s++;
			stagestate[6].s++;

			if(stagestate[2].s>170)
			{
				stagestate[2].s=-30;
				for(i=0;i<BALL_MAX;i++)
				{
					if(!ball[i].enable)
					{
						ball[i].enable=true;
						ball[i].deletecount=120;
						ball[i].meshindex=BALLMESH_MINITETU;
						ball[i].ball.reset();
						ball[i].ball.po=gun[2].p;//��C�̒��ɁI�I
						ball[i].ball.r=0.5f;
						ball[i].ball.w=200;
						ball[i].matindex=MATKIND_TETU2;
						ball[i].ball.move(false,true);
						break;
					}
				}
			}

			if(stagestate[3].s>50)
			{
				stagestate[3].s=0;
				for(i=0;i<BALL_MAX;i++)
				{
					if(!ball[i].enable)
					{
						ball[i].enable=true;
						ball[i].deletecount=50;
						ball[i].meshindex=BALLMESH_MINITETU;
						ball[i].ball.reset();
						ball[i].ball.po=gun[3].p;//��C�̒��ɁI�I
						ball[i].ball.r=0.5f;
						ball[i].ball.w=200;
						ball[i].matindex=MATKIND_TETU2;
						ball[i].ball.move(false,true);
						break;
					}
				}
			}
			if(stagestate[4].s>150)
			{
				stagestate[4].s=0;
				for(i=0;i<BALL_MAX;i++)
				{
					if(!ball[i].enable)
					{
						ball[i].enable=true;
						ball[i].deletecount=44;
						ball[i].meshindex=BALLMESH_MINITETU;
						ball[i].ball.reset();
						ball[i].ball.po=gun[4].p;//��C�̒��ɁI�I
						ball[i].ball.r=0.5f;
						ball[i].ball.w=200;
						ball[i].matindex=MATKIND_TETU2;
						ball[i].ball.move(false,true);
						break;
					}
				}
			}
			if(stagestate[6].s>100)
			{
				stagestate[6].s=0;
				for(i=0;i<BALL_MAX;i++)
				{
					if(!ball[i].enable)
					{
						ball[i].enable=true;
						ball[i].deletecount=37;
						ball[i].meshindex=BALLMESH_MINITETU;
						ball[i].ball.reset();
						ball[i].ball.po=gun[5].p;//��C�̒��ɁI�I
						ball[i].ball.r=0.5f;
						ball[i].ball.w=200;
						ball[i].matindex=MATKIND_TETU2;
						ball[i].ball.move(false,true);
						break;
					}
				}
			}
			stagestate[5].s+=D3DXVec3Length( &stagestate[5].v2);
			stagestate[10].s+=stagestate[10].v2.y;
			stagemesh.UVTranslationY[stagemesh.TexNameIndex("konbea.jpg")]+=stagestate[7].v.x/2;

		}

	}
	else if(stagekind==SELECTGAME_VARSUS || stagekind==SELECTGAME_MULTIPLAY)
	{


		if(stagenum==5)//���A3
		{

			if(seaver)
			{
				//���a20�̊��]����
				//stagestate[0]���J�E���g�Ɏg�p	
				
				stagestate[0].s++;
				if(stagestate[0].s>10*60)
				{
					stagestate[0].s=0;
					//�{�[�����쐬�I

					for(i=0;i<BALL_MAX;i++)
					{
						if(!ball[i].enable)
						{
							ball[i].enable=true;
							ball[i].deletecount=1000;
							ball[i].meshindex=BALLMESH_BIGIWA;
							ball[i].ball.reset();
							ball[i].ball.po=D3DXVECTOR3(-453.55f,80.0f,-346.37f);
							ball[i].ball.mv=D3DXVECTOR3(0,-4.0f,0);
							ball[i].ball.r=20;
							ball[i].ball.w=1000;
							ball[i].matindex=MATKIND_ISI;
							ball[i].ball.move(false,true);


							//���ʉ��Đ�
							

							if(play3d)
							{
								si=stopindex3d(sd.Iwa3D);
								sd.Iwa3D[si].Param.vPosition=D3DXVECTOR3(0,10000,0);
								sd.Iwa3D[si].Param.vVelocity=D3DXVECTOR3(0,0,0);
								sd.Iwa3D[si].Buffer->SetAllParameters( &sd.Iwa3D[si].Param, DS3D_DEFERRED );
								sd.Iwa3D[si].Sound->Stop();
								sd.Iwa3D[si].Sound->Reset();
								sd.Iwa3D[si].Sound->Play(0,DSBPLAY_LOOPING);
								ball[i].info[0]=si;
							}
							else
							{
								si=stopindex(sd.Iwa);
								sd.Iwa[si]->GetBuffer(0)->SetVolume(-10000);
								sd.Iwa[si]->Stop();
								sd.Iwa[si]->Reset();
								sd.Iwa[si]->Play(0,DSBPLAY_LOOPING);
								ball[i].info[0]=si;
							}

							//�N���C�A���g�Ƀf�[�^�𑗂�
							SendIwaStart(i,si);

							break;
						}
					}
				}
			}
		}
		else if(stagenum==6)//�e�N�m1
		{


			i=2;
			stagestate[i].s+=D3DXVec3Length( &stagestate[i].v2);
			i=3;
			stagestate[i].s+=D3DXVec3Length( &stagestate[i].v2);
			i=4;
			stagestate[i].v2.z+=(stagestate[i].s2>0 ? 0.003f : -0.003f);
			if(stagestate[i].v2.z>0.7f)
			{
				stagestate[i].v2.z=0.7f;
				stagestate[i].s2=-1;
			}
			if(stagestate[i].v2.z<-0.7f)
			{
				stagestate[i].v2.z=-0.7f;
				stagestate[i].s2=1;
			}
//			stagestate[i].v2=D3DXVECTOR3(0,0,0.5);
			stagestate[i].s+=stagestate[i].v2.z;
			i=5;
			stagestate[i].s+=D3DXVec3Length( &stagestate[i].v2);


			//����S���̏���
			if(stagestate[10].s>0) stagestate[11].s-=0.003f;
			else if(stagestate[10].s<0) stagestate[11].s+=0.003f;
			stagestate[10].s+=stagestate[11].s;
			if(stagestate[12].s>0) stagestate[13].s-=0.0045f;
			else if(stagestate[12].s<0) stagestate[13].s+=0.0045f;
			stagestate[12].s+=stagestate[13].s;


			D3DXVECTOR3 nextpo;

			nextpo.x=sinf(stagestate[10].s*rad)*(88.4f-5.4f);
			nextpo.y=-cosf(stagestate[10].s*rad)*(88.4f-5.4f)+88.4f;
			nextpo.z=104.1f;
			index=4;
			ball[index].ball.mv=nextpo-ball[index].ball.po;
//			ball[index].ball.po=nextpo;

			nextpo.x=sinf(stagestate[12].s*rad)*(88.4f-31.9f);
			nextpo.y=-cosf(stagestate[12].s*rad)*(88.4f-31.9f)+88.4f;
			nextpo.z=-97.6f;
			index++;
			ball[index].ball.mv=nextpo-ball[index].ball.po;
//			ball[index].ball.po=nextpo;



			//�X�e�[�W�ŗL�̏��𑗂�
			if(seaver)
				SendStageState();



		}
		else if(stagenum==7)
		{

			stagemesh.UVTranslationY[stagemesh.TexNameIndex("konbea.jpg")]+=stagestate[3].v.x/4;
			stagemesh.UVTranslationY[stagemesh.TexNameIndex("Konbea2.jpg")]+=stagestate[4].v.x/4;
			stagestate[2].s+=D3DXVec3Length( &stagestate[2].v2);
		}
		else if(stagenum==8)
		{
			//�e������

			if(seaver)
			{
				stagestate[0].s++;
				if(stagestate[0].s>=40)
				{
					//���ˁI�I
					stagestate[0].s=0;

					for(i=0;i<BALL_MAX;i++)
					{
						if(!ball[i].enable)
						{
							ball[i].enable=true;
							ball[i].deletecount=200;
							ball[i].meshindex=BALLMESH_MINITETU;
							ball[i].ball.reset();
							ball[i].ball.po=gun[0].p;//��C�̒��ɁI�I
							ball[i].ball.r=0.5f;
							ball[i].ball.w=120;
							ball[i].matindex=MATKIND_TETU;
							ball[i].ball.move(false,true);
							break;
						}
					}

				}
			}

			//��C�̌�����ς���(stagestate[1].s�����悤)
			if(gun[0].v.z>0)stagestate[1].s-=0.001f;
			else if(gun[0].v.z<0)stagestate[1].s+=0.001f;
			gun[0].v.z+=stagestate[1].s;

			//��C�}�g���b�N�X�ύX
			D3DXMatrixRotationY(&gun[0].mat,angle(gun[0].v.z,gun[0].v.x)*rad);
			D3DXMatrixRotationZ(&mat,-10*rad);
			gun[0].mat*=mat;
			gun[0].mat._41=gun[0].p.x;
			gun[0].mat._42=gun[0].p.y;
			gun[0].mat._43=gun[0].p.z;



			//�x���g�R���x�A
			stagemesh.UVTranslationY[stagemesh.TexNameIndex("konbea.jpg")]+=stagestate[2].v.z/10;



			//��]��
			for(i=3;i<10;i++)
				stagestate[i].s+=D3DXVec3Length( &stagestate[i].v2);


			//�X�e�[�W�ŗL�̏��𑗂�
			if(seaver)
				SendStageState();



		}
		else if(stagenum==10)
		{//�َ���2
			stagemesh.UVTranslationY[stagemesh.TexNameIndex("izigen2.bmp")]+=stagestate[3].v.z/40.15f*2;
			rotation(&stagestate[4].v2.x,&stagestate[4].v2.z,1.7f);
			D3DXMatrixRotationAxis( &mat, &stagestate[4].v2, D3DXVec3Length(&stagestate[4].v2)*rad );
			stagematrix*=mat;
		}
	}








	//���ʉ�����(��Ƀe�N�m�̋@�B��)



	if(stagekind==SELECTGAME_STAGE)//�X�e�[�W���[�h
	{
		if(stagenum==20)
		{
			//���̒�R
			float p=ball[0].ball.po.y+18.06f-1;
			p*=-0.5;
			if(p<0)p=0;
			if(p>1)p=1;

			ball[0].ball.setmoveres(1.5f*p,D3DXVECTOR3(0,0,0));
			ball[0].ball.setrotares(1.5f*p);

			ball[0].ball.mv.y+=0.006f*p;
		}
		else if (stagenum==21)
		{
			//���ʉ��z�u�ʒu=(-58.67f,-46.26f,-3.38)

			int vol;

			si=0;
			vol=getvolume(D3DXVECTOR3(-58.67f,-46.26f,-3.38f))+1000;
			if(vol<-3000)
			{
				if(sd.Meka[si]->IsSoundPlaying())
					sd.Meka[si]->Stop();
			}
			else
			{
				sd.Meka[si]->GetBuffer(0)->SetVolume(vol<=1?vol:1);
				if(!sd.Meka[si]->IsSoundPlaying())
					sd.Meka[si]->Play(0,DSBPLAY_LOOPING);
			}


		}
		else if (stagenum==22)
		{
			//���ʉ��z�u�ʒu=(-54.74f,-1.44f,33.56)(-112.59f,30.38f,113.14)

			int vol;

			si=0;
			vol=getvolume(D3DXVECTOR3(-54.74f,-1.44f,33.56f))+1000;
			if(vol<-3000)
			{
				if(sd.Meka[si]->IsSoundPlaying())
					sd.Meka[si]->Stop();
			}
			else
			{
				sd.Meka[si]->GetBuffer(0)->SetVolume(vol<=1?vol:1);
				if(!sd.Meka[si]->IsSoundPlaying())
					sd.Meka[si]->Play(0,DSBPLAY_LOOPING);
			}

			si++;
			vol=getvolume(D3DXVECTOR3(-112.59f,30.38f,113.14f))+1000;
			if(vol<-3000)
			{
				if(sd.Meka[si]->IsSoundPlaying())
					sd.Meka[si]->Stop();
			}
			else
			{
				sd.Meka[si]->GetBuffer(0)->SetVolume(vol<=1?vol:1);
				if(!sd.Meka[si]->IsSoundPlaying())
					sd.Meka[si]->Play(0,DSBPLAY_LOOPING);
			}

		}
		else if (stagenum==23)
		{
			//���ʉ��z�u�ʒu=(63.16f,39.77f,-28.76)

			int vol;

			si=0;
			vol=getvolume(D3DXVECTOR3(63.16f,39.77f,-28.76f))+1000;
			if(vol<-3000)
			{
				if(sd.Meka[si]->IsSoundPlaying())
					sd.Meka[si]->Stop();
			}
			else
			{
				sd.Meka[si]->GetBuffer(0)->SetVolume(vol<=1?vol:1);
				if(!sd.Meka[si]->IsSoundPlaying())
					sd.Meka[si]->Play(0,DSBPLAY_LOOPING);
			}



		}
		else if (stagenum==24)
		{
			//���ʉ��z�u�ʒu=(18.34f,3.6f,45.73)

			int vol;

			si=0;
			vol=getvolume(D3DXVECTOR3(18.34f,3.6f,45.73f))+1000;
			if(vol<-3000)
			{
				if(sd.Meka[si]->IsSoundPlaying())
					sd.Meka[si]->Stop();
			}
			else
			{
				sd.Meka[si]->GetBuffer(0)->SetVolume(vol<=1?vol:1);
				if(!sd.Meka[si]->IsSoundPlaying())
					sd.Meka[si]->Play(0,DSBPLAY_LOOPING);
			}



		}
	}
	else if(stagekind==SELECTGAME_VARSUS || stagekind==SELECTGAME_MULTIPLAY)
	{

		if(stagenum==6)//�e�N�m1
		{

			//���ʉ��z�u�ʒu=(162,-38.5f,255)(271,-6.5f,156)(125.5f,13,-181.5f)

			int vol;

			si=0;
			vol=getvolume(D3DXVECTOR3(162,-38.5f,255))+1000;
			if(vol<-3000)
			{
				if(sd.Meka[si]->IsSoundPlaying())
					sd.Meka[si]->Stop();
			}
			else
			{
				sd.Meka[si]->GetBuffer(0)->SetVolume(vol<=1?vol:1);
				if(!sd.Meka[si]->IsSoundPlaying())
					sd.Meka[si]->Play(0,DSBPLAY_LOOPING);
			}

			si++;
			vol=getvolume(D3DXVECTOR3(271,-6.5f,156))+1000;
			if(vol<-3000)
			{
				if(sd.Meka[si]->IsSoundPlaying())
					sd.Meka[si]->Stop();
			}
			else
			{
				sd.Meka[si]->GetBuffer(0)->SetVolume(vol<=1?vol:1);
				if(!sd.Meka[si]->IsSoundPlaying())
					sd.Meka[si]->Play(0,DSBPLAY_LOOPING);
			}

			si++;
			vol=getvolume(D3DXVECTOR3(125.5f,13,-181.5f))+1000;
			if(vol<-3000)
			{
				if(sd.Meka[si]->IsSoundPlaying())
					sd.Meka[si]->Stop();
			}
			else
			{
				sd.Meka[si]->GetBuffer(0)->SetVolume(vol<=1?vol:1);
				if(!sd.Meka[si]->IsSoundPlaying())
					sd.Meka[si]->Play(0,DSBPLAY_LOOPING);
			}


		}
		else if(stagenum==7)
		{

			//���ʉ��z�u�ʒu=(-21.5f,-2.6f,351.5f)(-193.3f,74.5f,369.8f)

			int vol;

			si=0;
			vol=getvolume(D3DXVECTOR3(-21.5f,-2.6f,351.5f))+1000;
			if(vol<-3000)
			{
				if(sd.Meka[si]->IsSoundPlaying())
					sd.Meka[si]->Stop();
			}
			else
			{
				sd.Meka[si]->GetBuffer(0)->SetVolume(vol<=1?vol:1);
				if(!sd.Meka[si]->IsSoundPlaying())
					sd.Meka[si]->Play(0,DSBPLAY_LOOPING);
			}

			si++;
			vol=getvolume(D3DXVECTOR3(-193.3f,74.5f,369.8f))+1000;
			if(vol<-3000)
			{
				if(sd.Meka[si]->IsSoundPlaying())
					sd.Meka[si]->Stop();
			}
			else
			{
				sd.Meka[si]->GetBuffer(0)->SetVolume(vol<=1?vol:1);
				if(!sd.Meka[si]->IsSoundPlaying())
					sd.Meka[si]->Play(0,DSBPLAY_LOOPING);
			}




		}
		else if(stagenum==8)
		{



			//���ʉ��z�u�ʒu=(44,28,-161)(44,28,-328)(-161.9f,-10,-117.1f)(-47,-20,-117.1f)

			int vol;

			si=0;
			vol=getvolume(D3DXVECTOR3(44,28,-161))+1000;
			if(vol<-3000)
			{
				if(sd.Meka[si]->IsSoundPlaying())
					sd.Meka[si]->Stop();
			}
			else
			{
				sd.Meka[si]->GetBuffer(0)->SetVolume(vol<=1?vol:1);
				if(!sd.Meka[si]->IsSoundPlaying())
					sd.Meka[si]->Play(0,DSBPLAY_LOOPING);
			}

			si++;
			vol=getvolume(D3DXVECTOR3(44,28,-328))+1000;
			if(vol<-3000)
			{
				if(sd.Meka[si]->IsSoundPlaying())
					sd.Meka[si]->Stop();
			}
			else
			{
				sd.Meka[si]->GetBuffer(0)->SetVolume(vol<=1?vol:1);
				if(!sd.Meka[si]->IsSoundPlaying())
					sd.Meka[si]->Play(0,DSBPLAY_LOOPING);
			}

			si++;
			vol=getvolume(D3DXVECTOR3(-161.9f,-10,-117.1f))+1000;
			if(vol<-3000)
			{
				if(sd.Meka[si]->IsSoundPlaying())
					sd.Meka[si]->Stop();
			}
			else
			{
				sd.Meka[si]->GetBuffer(0)->SetVolume(vol<=1?vol:1);
				if(!sd.Meka[si]->IsSoundPlaying())
					sd.Meka[si]->Play(0,DSBPLAY_LOOPING);
			}

			si++;
			vol=getvolume(D3DXVECTOR3(-47,-20,-117.1f))+1000;
			if(vol<-3000)
			{
				if(sd.Meka[si]->IsSoundPlaying())
					sd.Meka[si]->Stop();
			}
			else
			{
				sd.Meka[si]->GetBuffer(0)->SetVolume(vol<=1?vol:1);
				if(!sd.Meka[si]->IsSoundPlaying())
					sd.Meka[si]->Play(0,DSBPLAY_LOOPING);
			}


		}
	}







}




//�{�[���������ݑO�̃X�e�[�W�����_�����O
void FirstRender(int index)
{

	int i;
	D3DXMATRIX mat,mat2;






	if(!izigen)
	{



		if(stagekind==SELECTGAME_STAGE)//�X�e�[�W���[�h
		{
			//�X�e�[�W�ɂ���Ă̓t�H�O��������


			if((stagenum<12 && stagenum/4==1) || (stagenum>12 && (stagenum-13)/4==1))
			{
				DG.Device->SetRenderState( D3DRS_FOGSTART,   FtoDW(50) );
				DG.Device->SetRenderState( D3DRS_FOGEND,     FtoDW(500) );
				DG.Device->SetRenderState( D3DRS_FOGCOLOR,  D3DXCOLOR(0.15f,0.07f,0,1) );
				DG.Device->SetRenderState( D3DRS_FOGENABLE, true);
			}


			if(stagenum==20)
			{
				///����
				D3DXMatrixTranslation( &mat, 0,0,0 );
				DG.Device->SetTransform( D3DTS_WORLD, &mat );

				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 0, 1);
			}
			else if(stagenum==8)
			{
				D3DXMatrixTranslation( &mat, 0,0,0 );
				DG.Device->SetTransform( D3DTS_WORLD, &mat );

				//0�͒ʘH�A1�͓S��
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 0, 1);
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 1, 1 ,ENVCHECK(&EnvTex[ENVKIND_TETUMETA]),true);

			}
			else if(stagenum==9)
			{
				D3DXMatrixTranslation( &mat, 0,0,0 );
				DG.Device->SetTransform( D3DTS_WORLD, &mat );

				//0�͒ʘH�A1�͓S��
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 0, 1);
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 1, 1 ,ENVCHECK(&EnvTex[ENVKIND_TETUMETA]),true);

			}
			else if(stagenum==10)
			{
				D3DXMatrixTranslation( &mat, 0,0,0 );
				DG.Device->SetTransform( D3DTS_WORLD, &mat );

				//0�͒ʘH�A1�͓S��
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 0, 1);
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 1, 1 ,ENVCHECK(&EnvTex[ENVKIND_TETUMETA]),true);

			}
			else if(stagenum==11)
			{
				D3DXMatrixTranslation( &mat, 0,0,0 );
				DG.Device->SetTransform( D3DTS_WORLD, &mat );

				//0�͒ʘH�A1�͓S��
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 0, 1);
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 1, 1 ,ENVCHECK(&EnvTex[ENVKIND_TETUMETA]),true);

			}

			else if(stagenum==21)
			{

				D3DXMatrixTranslation( &mat, 0,0,0 );
				DG.Device->SetTransform( D3DTS_WORLD, &mat );

				//0�͒ʘH�A1�͓S���A2�͉�]��
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 0, 1);
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 1, 1 ,ENVCHECK(&EnvTex[ENVKIND_TETUMETA]),true);

				i=2;
				D3DXMatrixTranslation( &mat, -stagestate[i].v.x,-stagestate[i].v.y,-stagestate[i].v.z );
				D3DXMatrixRotationY( &mat2, stagestate[i].s*rad );
				mat*=mat2;
				D3DXMatrixTranslation( &mat2, stagestate[i].v.x,stagestate[i].v.y,stagestate[i].v.z );
				mat*=mat2;
				DG.Device->SetTransform( D3DTS_WORLD, &mat );
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy,2,1);

			}
			else if(stagenum==22)
			{
				D3DXMatrixTranslation( &mat, 0,0,0 );
				DG.Device->SetTransform( D3DTS_WORLD, &mat );

				//0�͒ʘH�A1�͏c��]�A2�̓��[���[1�A3�̓��[���[2
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 0, 1);

				i=2;
				D3DXMatrixTranslation( &mat, -stagestate[i].v.x,-stagestate[i].v.y,-stagestate[i].v.z );
				D3DXMatrixRotationY( &mat2, stagestate[i].s*rad );
				mat*=mat2;
				D3DXMatrixTranslation( &mat2, stagestate[i].v.x,stagestate[i].v.y,stagestate[i].v.z );
				mat*=mat2;
				DG.Device->SetTransform( D3DTS_WORLD, &mat );
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy,1,1);

				i=3;
				D3DXMatrixTranslation( &mat, -stagestate[i].v.x,-stagestate[i].v.y,-stagestate[i].v.z );
				D3DXMatrixRotationZ( &mat2, -stagestate[i].s*rad );
				mat*=mat2;
				D3DXMatrixTranslation( &mat2, stagestate[i].v.x,stagestate[i].v.y,stagestate[i].v.z );
				mat*=mat2;
				DG.Device->SetTransform( D3DTS_WORLD, &mat );
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy,2,1);
				i=4;
				D3DXMatrixTranslation( &mat, -stagestate[i].v.x,-stagestate[i].v.y,-stagestate[i].v.z );
				D3DXMatrixRotationZ( &mat2, stagestate[i].s*rad );
				mat*=mat2;
				D3DXMatrixTranslation( &mat2, stagestate[i].v.x,stagestate[i].v.y,stagestate[i].v.z );
				mat*=mat2;
				DG.Device->SetTransform( D3DTS_WORLD, &mat );
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy,3,1);
			}
			else if(stagenum==23)
			{


				D3DXMatrixTranslation( &mat, 0,0,0 );
				DG.Device->SetTransform( D3DTS_WORLD, &mat );

				//0�͒ʘH�A1�͋����A2�͉�]
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 0, 1);
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 1, 1,ENVCHECK(&EnvTex[ENVKIND_TETUMETA]),true);

				i=2;
				D3DXMatrixTranslation( &mat, -stagestate[i].v.x,-stagestate[i].v.y,-stagestate[i].v.z );
				D3DXMatrixRotationY( &mat2, stagestate[i].s*rad );
				mat*=mat2;
				D3DXMatrixTranslation( &mat2, stagestate[i].v.x,stagestate[i].v.y,stagestate[i].v.z );
				mat*=mat2;
				DG.Device->SetTransform( D3DTS_WORLD, &mat );
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy,2,1);


			}
			else if(stagenum==24)
			{


				D3DXMatrixTranslation( &mat, 0,0,0 );
				DG.Device->SetTransform( D3DTS_WORLD, &mat );

				//0�͒ʘH�A1��X����]�A2��Y����]
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 0, 1);

				i=5;
				D3DXMatrixTranslation( &mat, -stagestate[i].v.x,-stagestate[i].v.y,-stagestate[i].v.z );
				D3DXMatrixRotationX( &mat2, stagestate[i].s*rad );
				mat*=mat2;
				D3DXMatrixTranslation( &mat2, stagestate[i].v.x,stagestate[i].v.y,stagestate[i].v.z );
				mat*=mat2;
				DG.Device->SetTransform( D3DTS_WORLD, &mat );
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy,1,1);

				i=10;
				D3DXMatrixTranslation( &mat, -stagestate[i].v.x,-stagestate[i].v.y,-stagestate[i].v.z );
				D3DXMatrixRotationY( &mat2, stagestate[i].s*rad );
				mat*=mat2;
				D3DXMatrixTranslation( &mat2, stagestate[i].v.x,stagestate[i].v.y,stagestate[i].v.z );
				mat*=mat2;
				DG.Device->SetTransform( D3DTS_WORLD, &mat );
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy,2,1);

			}
			else
			{

				D3DXMatrixTranslation( &mat, 0,0,0 );
				DG.Device->SetTransform( D3DTS_WORLD, &mat );
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy);

			}

			DG.Device->SetRenderState( D3DRS_FOGENABLE, false);

		}
		else
		{


			if(stagenum==3)//���A1
			{
				//0�͒n��A1�͓��A�A2�͐΁A3�͓S�i�q
				//�J�����̈ʒu�Ŕ��f����
				D3DXMatrixTranslation( &mat, 0,0,0 );
				DG.Device->SetTransform( D3DTS_WORLD, &mat );

				if(player[index].cpo.y>-180)
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 0, 1);
				if(player[index].cpo.y<20 && (player[index].cpo.x<138 || player[index].cpo.y<-343))
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 1, 1);
				if(player[index].cpo.z<-160)
				{
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 2, 1);
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 3, 1,ENVCHECK(&EnvTex[ENVKIND_META]),true);
				}
			}
			else if(stagenum==4)//���A2
			{
				//�J�����̈ʒu�Ŕ��f����
				D3DXMatrixTranslation( &mat, 0,0,0 );
				DG.Device->SetTransform( D3DTS_WORLD, &mat );

				if(player[index].cpo.z<-29 && player[index].cpo.x<-64)
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 0, 1);
				if(player[index].cpo.z>-202 || (player[index].cpo.z>-380 && player[index].cpo.x<-70))
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 1, 1);
				if((player[index].cpo.z<60 && player[index].cpo.x>-128) || player[index].cpo.z<-412)
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 2, 1);
			}
			else if(stagenum==5)//���A3
			{
				//0�͓����A1�͒n��A2�͒ʘH�i������t�߁j�A3�͒ʘH�i�����t��),4�͊₪�]�����Ă��镔��
				//5�͓��A�̂��镔���A6�͗����镔���A7�͂��ł������_�����O

				D3DXMatrixTranslation( &mat, 0,0,0 );
				DG.Device->SetTransform( D3DTS_WORLD, &mat );

				//�n��t�߂ɂ�����n��̃����_�����O
				if(player[index].cpo.y>-42 || (player[index].cpo.y>-120 && 
					((player[index].cpo.x<35 && player[index].cpo.x>-35) || (player[index].cpo.z<35 && player[index].cpo.z>-35))))
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 1, 1);

				//�n��1�̃����_�����O
				//���a440(15.27,-74.95)
				if(distance(player[index].cpo.x-15.27f,player[index].cpo.z+74.95f)<440)
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 2, 1);

				//�₪�]�����Ă镔���̃����_�����O
				if(player[index].cpo.z>2.5f*player[index].cpo.x+480)
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 4, 1);

				//�n��2�̃����_�����O
				//���a600(-731.2,-463.7)
				if(distance(player[index].cpo.x+731.2f,player[index].cpo.z+463.7f)<600)
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 3, 1);

				//�����ƕ����̃����_�����O
				//���a230(-302.5,-560)
				if(distance(player[index].cpo.x+282.5f,player[index].cpo.z+560)<230)
				{
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 5, 1);
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 0, 1,ENVCHECK(&EnvTex[ENVKIND_META]),true);
				}

				//������Ƃ��̃����_�����O
				//���a390(63.85,-538.26)
				if(distance(player[index].cpo.x-63.85f,player[index].cpo.z+538.26f)<390)
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 6, 1);

				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 7, 1);

			}
			else if(stagenum==6)//�e�N�m1
			{


				D3DXMatrixTranslation( &mat, 0,0,0 );
				DG.Device->SetTransform( D3DTS_WORLD, &mat );

				//0�͒ʘH�A1�̓X�^�[�g�̓��A2�̓��X�g�̉~�̓��A10�͓S�̖_
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 0, 1);
				if(player[index].cpo.x<154)
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 2, 1);
				if(player[index].cpo.x<29 || player[index].cpo.z>209)
				{
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 1, 1);
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 10, 1,ENVCHECK(&EnvTex[ENVKIND_TETUMETA]),true);

					//�h���S���̒�������


					i=10;
					D3DXMatrixTranslation( &mat, -stagestate[i].v.x,-stagestate[i].v.y,-stagestate[i].v.z );
					D3DXMatrixRotationZ( &mat2, stagestate[i].s*rad );
					mat*=mat2;
					D3DXMatrixTranslation( &mat2, stagestate[i].v.x,stagestate[i].v.y,stagestate[i].v.z );
					mat*=mat2;
					DG.Device->SetTransform( D3DTS_WORLD, &mat );
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy,7,1,ENVCHECK(&EnvTex[ENVKIND_TETUMETA]),true);

					i=12;
					D3DXMatrixTranslation( &mat, -stagestate[i].v.x,-stagestate[i].v.y,-stagestate[i].v.z );
					D3DXMatrixRotationZ( &mat2, stagestate[i].s*rad );
					mat*=mat2;
					D3DXMatrixTranslation( &mat2, stagestate[i].v.x,stagestate[i].v.y,stagestate[i].v.z );
					mat*=mat2;
					DG.Device->SetTransform( D3DTS_WORLD, &mat );
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy,8,1,ENVCHECK(&EnvTex[ENVKIND_TETUMETA]),true);
				}


				if(player[index].cpo.z>50)
				{
					i=2;
					D3DXMatrixTranslation( &mat, -stagestate[i].v.x,-stagestate[i].v.y,-stagestate[i].v.z );
					D3DXMatrixRotationX( &mat2, -stagestate[i].s*rad );
					mat*=mat2;
					D3DXMatrixTranslation( &mat2, stagestate[i].v.x,stagestate[i].v.y,stagestate[i].v.z );
					mat*=mat2;
					DG.Device->SetTransform( D3DTS_WORLD, &mat );
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy,3,1);

					i=3;
					D3DXMatrixTranslation( &mat, -stagestate[i].v.x,-stagestate[i].v.y,-stagestate[i].v.z );
					D3DXMatrixRotationX( &mat2, stagestate[i].s*rad );
					mat*=mat2;
					D3DXMatrixTranslation( &mat2, stagestate[i].v.x,stagestate[i].v.y,stagestate[i].v.z );
					mat*=mat2;
					DG.Device->SetTransform( D3DTS_WORLD, &mat );
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy,4,1);
				}

				if(player[index].cpo.x>50)
				{
					i=4;
					D3DXMatrixTranslation( &mat, -stagestate[i].v.x,-stagestate[i].v.y,-stagestate[i].v.z );
					D3DXMatrixRotationZ( &mat2, stagestate[i].s*rad );
					mat*=mat2;
					D3DXMatrixTranslation( &mat2, stagestate[i].v.x,stagestate[i].v.y,stagestate[i].v.z );
					mat*=mat2;
					DG.Device->SetTransform( D3DTS_WORLD, &mat );
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy,5,1);
				}

				if(player[index].cpo.z<-100)
				{
					i=5;
					D3DXMatrixTranslation( &mat, -stagestate[i].v.x,-stagestate[i].v.y,-stagestate[i].v.z );
					D3DXMatrixRotationY( &mat2, stagestate[i].s*rad );
					mat*=mat2;
					D3DXMatrixTranslation( &mat2, stagestate[i].v.x,stagestate[i].v.y,stagestate[i].v.z );
					mat*=mat2;
					DG.Device->SetTransform( D3DTS_WORLD, &mat );
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy,6,1);
				}
			}
			else if(stagenum==7)
			{//�e�N�m2

				D3DXMatrixTranslation( &mat, 0,0,0 );
				DG.Device->SetTransform( D3DTS_WORLD, &mat );

				//0�͒ʘH�A1��1�ڂ̕����A2��2�ڂ̕���
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 0, 1);
				if(player[index].cpo.x<129 || player[index].cpo.z>169)
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 1, 1);
				if(distance(player[index].cpo.x+170.39f,player[index].cpo.z)<200)//���a200
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 2, 1);


				i=2;
				D3DXMatrixTranslation( &mat, -stagestate[i].v.x,-stagestate[i].v.y,-stagestate[i].v.z );
				D3DXMatrixRotationY( &mat2, stagestate[i].s*rad );
				mat*=mat2;
				D3DXMatrixTranslation( &mat2, stagestate[i].v.x,stagestate[i].v.y,stagestate[i].v.z );
				mat*=mat2;
				DG.Device->SetTransform( D3DTS_WORLD, &mat );
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy,4,1);



			}
			else if(stagenum==8)
			{//�e�N�m3

				D3DXMatrixTranslation( &mat, 0,0,0 );
				DG.Device->SetTransform( D3DTS_WORLD, &mat );

				//0�͑S��,1�`7�͉�]��,8�͍ŏ��̃|�[��,9�͓r���̃|�[��,10�͍Ō�̓�

				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 0, 1);

				//��
				if(player[index].cpo.x<24 && player[index].cpo.x>-139 && player[index].cpo.z>-205)
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 10, 1);

				//�ŏ��̃|�[��
				if(player[index].cpo.y<21.7f && player[index].cpo.z>-60)
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 8, 1 ,ENVCHECK(&EnvTex[ENVKIND_TETUMETA]),true);

				//�r���̃|�[��
				if(player[index].cpo.x>-27.5f && player[index].cpo.y>21.7f)
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 9, 1 ,ENVCHECK(&EnvTex[ENVKIND_TETUMETA]),true);

				//�����̒�
				if(player[index].cpo.x<20 && player[index].cpo.x>-236 && player[index].cpo.z<-20 && player[index].cpo.z>-200)
				{				
					for(i=3;i<10;i++)
					{
						D3DXMatrixTranslation( &mat, -stagestate[i].v.x,-stagestate[i].v.y,-stagestate[i].v.z );
						if(i==3)
							D3DXMatrixRotationY( &mat2, -stagestate[i].s*rad );
						else if(i==4)
							D3DXMatrixRotationY( &mat2, stagestate[i].s*rad );
						else if(i==5)
							D3DXMatrixRotationX( &mat2, stagestate[i].s*rad );
						else if(i==6)
							D3DXMatrixRotationY( &mat2, -stagestate[i].s*rad );
						else if(i==7)
							D3DXMatrixRotationY( &mat2, stagestate[i].s*rad );
						else if(i==8)
							D3DXMatrixRotationY( &mat2, -stagestate[i].s*rad );
						else if(i==9)
							D3DXMatrixRotationY( &mat2, stagestate[i].s*rad );
						mat*=mat2;
						D3DXMatrixTranslation( &mat2, stagestate[i].v.x,stagestate[i].v.y,stagestate[i].v.z );
						mat*=mat2;
						DG.Device->SetTransform( D3DTS_WORLD, &mat );
						stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy,i-2,1);
					}
				}

			}
			else
			{
				D3DXMatrixTranslation( &mat, 0,0,0 );
				DG.Device->SetTransform( D3DTS_WORLD, &mat );
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy);
			}


		}














		for(i=0;i<guncount;i++)
		{

			DG.Device->SetTransform( D3DTS_WORLD, &gun[i].mat );
			taihoumesh[gun[i].kind].Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy);

		}



		for(i=0;i<windcount;i++)
		{

			DG.Device->SetTransform( D3DTS_WORLD, &wind[i].mat );
			windmesh[wind[i].kind].Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy);

		}







	}
	else//�َ���
	{
		//�w�i�������I





		//�َ����R�[�X
		DG.Device->SetRenderState( D3DRS_ALPHABLENDENABLE, false );

		if(stagekind==SELECTGAME_STAGE)
		{
			//����̐�
			D3DXMatrixTranslation( &mat, 0,0,0 );
			DG.Device->SetTransform( D3DTS_WORLD, &mat );
			stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy,1,1);
		}
		else
		{
			if(stagenum>=9)
			{

				if(stagenum==9)
				{
					D3DXMatrixTranslation( &mat, 0,0,0 );
					DG.Device->SetTransform( D3DTS_WORLD, &mat );
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy,0,1);
				}
				if(stagenum==10)
				{
					D3DXMatrixTranslation( &mat, 0,0,0 );
					DG.Device->SetTransform( D3DTS_WORLD, &mat );
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy,0,1);
				}
				if(stagenum==11)
				{
					D3DXMatrixTranslation( &mat, 0,0,0 );
					DG.Device->SetTransform( D3DTS_WORLD, &mat );
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy,0,1);
				}
				
			}
		}

		DG.Device->SetRenderState( D3DRS_ALPHABLENDENABLE, true );
	}





	//�A�C�e�������_�����O

	float itemmaxdis=Setting.ItemMaxDis,itemmindis=Setting.ItemMaxDis*0.7f;
	float dis;

	DG.Device->SetRenderState(D3DRS_NORMALIZENORMALS,TRUE);

	float s;
	for(i=0;i<itemcount;i++)
	{
		dis=D3DXVec3Length(&(item[i].nowpo-player[index].cpo));
		if(dis<itemmaxdis)
		{

			if(item[i].deletecount>0)
				s=(float)item[i].deletecount/ITEM_COUNT;
			else
				s=(float)item[i].deletecount/50+1;

			if(dis>itemmindis)
				s*=1-(dis-itemmindis)/(itemmaxdis-itemmindis);

			D3DXMatrixScaling( &mat,  s,s,s);
			D3DXMatrixRotationY( &mat2,  item[i].angle*rad );
			mat*=mat2;
			mat*=item[i].mat;
			D3DXMatrixTranslation( &mat2, item[i].nowpo.x, item[i].nowpo.y, item[i].nowpo.z );		
			mat*=mat2;

			DG.Device->SetTransform( D3DTS_WORLD, &mat );
			itemmesh[item[i].kind].Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy);
			itemmesh[0].Material[0].Ambient=itemmesh[0].Material[0].Diffuse=itemcolor[item[i].kind];
			itemmesh[0].Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy,0,0,ENVCHECK(&EnvTex[ENVKIND_PROJECT]),true);

		}
	}

	DG.Device->SetRenderState(D3DRS_NORMALIZENORMALS,false);



}


//�{�[���������݌�̃X�e�[�W�����_�����O
void SecondRender(int index)
{


	int i;
	D3DXMATRIX mat,mat2;







	if(izigen)
	{






		//�X�e�[�W�����_�����O


		DG.Device->SetRenderState( D3DRS_LIGHTING, false );
		DG.Device->SetRenderState( D3DRS_ZWRITEENABLE,  FALSE );
		DG.Device->SetRenderState( D3DRS_SRCBLEND,  D3DBLEND_ONE );
		DG.Device->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_ONE );
		DG.Device->SetRenderState( D3DRS_CULLMODE,  D3DCULL_NONE );
		DG.Device->SetRenderState( D3DRS_BLENDOP, D3DBLENDOP_ADD );


		//�܂������ł͗L���ɂ��Ȃ�
		DG.Device->SetRenderState( D3DRS_FOGSTART,   FtoDW(100) );
		DG.Device->SetRenderState( D3DRS_FOGEND,     FtoDW(1000) );
		DG.Device->SetRenderState( D3DRS_FOGCOLOR,  0 );





		DG.Device->SetRenderState( D3DRS_FOGENABLE, true);


		//��C�Ƃ�

		for(i=0;i<guncount;i++)
		{

			DG.Device->SetTransform( D3DTS_WORLD, &gun[i].mat );
			taihoumesh[gun[i].kind].Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy);

		}



		for(i=0;i<windcount;i++)
		{

			DG.Device->SetTransform( D3DTS_WORLD, &wind[i].mat );
			windmesh[wind[i].kind].Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy);

		}

		DG.Device->SetRenderState( D3DRS_FOGENABLE, false);













		//�َ����R�[�X

		if(stagekind==SELECTGAME_STAGE)
		{
			D3DXMatrixTranslation( &mat, 0,0,0 );
			DG.Device->SetTransform( D3DTS_WORLD, &mat );
			DG.Device->SetRenderState( D3DRS_FOGENABLE, TRUE );
			stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy,0,1);
			DG.Device->SetRenderState( D3DRS_FOGENABLE, false);
		}
		else
		{
			if(stagenum>=9)
			{

				if(stagenum==9)
				{

					D3DXMatrixTranslation( &mat, 0,0,0 );
					DG.Device->SetTransform( D3DTS_WORLD, &mat );
					DG.Device->SetRenderState( D3DRS_FOGENABLE, TRUE );
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy,1);
					DG.Device->SetRenderState( D3DRS_FOGENABLE, false);
				}
				else if(stagenum==10)
				{

					DG.Device->SetRenderState( D3DRS_FOGENABLE, TRUE );
					//��]�}�g���b�N�X�K�p
					D3DXMatrixTranslation( &mat, -stagestate[4].v.x,-stagestate[4].v.y,-stagestate[4].v.z );
					mat*=stagematrix;
					D3DXMatrixTranslation( &mat2, stagestate[4].v.x,stagestate[4].v.y,stagestate[4].v.z );
					mat*=mat2;
					DG.Device->SetTransform( D3DTS_WORLD, &mat );
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy,1,1);
					D3DXMatrixTranslation( &mat, 0,0,0 );
					DG.Device->SetTransform( D3DTS_WORLD, &mat );
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy,2);
					DG.Device->SetRenderState( D3DRS_FOGENABLE, false);
				}
				else if(stagenum==11)
				{

					D3DXMatrixTranslation( &mat, 0,0,0 );
					DG.Device->SetTransform( D3DTS_WORLD, &mat );
					DG.Device->SetRenderState( D3DRS_FOGENABLE, TRUE );
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy,1,5);
					DG.Device->SetRenderState( D3DRS_FOGENABLE, false);
				}

			}
		}









		//�ݒ��߂�
		DG.Device->SetRenderState( D3DRS_LIGHTING, true );
		DG.Device->SetRenderState( D3DRS_ZWRITEENABLE,  true );
		DG.Device->SetRenderState( D3DRS_SRCBLEND,  D3DBLEND_SRCALPHA );
		DG.Device->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );
		DG.Device->SetRenderState( D3DRS_CULLMODE,  D3DCULL_CCW );
		DG.Device->SetRenderState( D3DRS_BLENDOP, D3DBLENDOP_ADD );
		DG.Device->SetRenderState( D3DRS_FOGENABLE, false );
		DG.Device->SetRenderState( D3DRS_ZENABLE,     true );






	}
	else if(stagenum==20)
	{
		///����
		D3DXMatrixTranslation( &mat, 0,0,0 );
		DG.Device->SetTransform( D3DTS_WORLD, &mat );

		stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 1, 1, ENVCHECK(&EnvTex[ENVKIND_TETUMETA]));
	}


}










void StageRender(int loopstart,int loopend)
{


	int i,j,index;
	DWORD ambient;

	D3DXMATRIX mat,mat2,matWorld,matWorld2,matView;


	//�X�e�[�W�������_�[




	for(index=loopstart;index<=loopend;index++)
	{


		//�J�����Ɖ�ʃT�C�Y�̐ݒ�

		D3DXMatrixLookAtLH( &matView,	&player[index].cpo,
										&player[index].ballold,
										&player[index].cup);


		//if(index==2)//3P
		//for(i=0;i<BALL_MAX;i++)
		//	if(ball[i].meshindex==BALLMESH_YUUDOU && ball[i].enable==true)//�����̃J�����ɂ��Ă��܂��I�I
		//	{
		//		D3DXMatrixLookAtLH( &matView,	&(ball[i].ball.po-((D3DXVECTOR3)ball[i].ball.mv*3)+D3DXVECTOR3(0,1,0)),
		//										&(ball[i].ball.po+((D3DXVECTOR3)ball[i].ball.mv*10)),
		//										&D3DXVECTOR3(0,1,0));
		//		break;
		//	}


		DG.Device->SetTransform( D3DTS_VIEW, &matView );


		if(stagekind!=SELECTGAME_MULTIPLAY)
			DG.Device->SetViewport( &player[index].vp );





		//�X�e�[�W�ƃ{�[���̈ʒu�ɂ�胉�C�e�B���O�̐ݒ�
		//if((stagekind==SELECTGAME_STAGE && stagenum/5==2) || (stagekind!=SELECTGAME_STAGE && stagenum/3==2))
		//	ambient=0x88888888;//�e�N�m�R�[�X�͊�������
		//else
			ambient=0x77777777;
		DG.Device->SetRenderState( D3DRS_AMBIENT, ambient );



		//�َ����R�[�X�̂Ƃ��A�X�e�[�W�͐Ղŏ���





		////1��ڂ̃����_�����O
		FirstRender(index);






		DG.Device->SetRenderState( D3DRS_AMBIENT, ambient );



		//�َ����R�[�X�̂Ƃ��A�e�͏����Ȃ�

		if(Setting.ShadeEnable && !izigen)
		{


		//�A���X�e���V���o�b�t�@�ɏ���
		//{



			//�O�ݒ�
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




			for(i=0;i<BALL_MAX;i++)
			{
				if(ball[i].enable)
				{

					//�A�̃}�g���b�N�X�Z�b�g
					D3DXMatrixScaling( &matWorld, ball[i].ball.r,ball[i].ball.r,ball[i].ball.r );
					D3DXMatrixRotationZ( &matWorld2, rad*30 );
					matWorld*=matWorld2;
					D3DXMatrixTranslation( &matWorld2, ball[i].ball.po.x,ball[i].ball.po.y,ball[i].ball.po.z );
					matWorld*=matWorld2;
					DG.Device->SetTransform( D3DTS_WORLD, &matWorld );


					//�\������
					DG.Device->SetRenderState( D3DRS_CULLMODE,   D3DCULL_CCW );
					DG.Device->SetRenderState( D3DRS_STENCILPASS,      D3DSTENCILOP_INCR );
					shade.Render( DG.Device, &player[index].cpo, &player[index].ballold, fovy);


					//����������
					DG.Device->SetRenderState( D3DRS_CULLMODE,   D3DCULL_CW );
					DG.Device->SetRenderState( D3DRS_STENCILPASS, D3DSTENCILOP_DECR );
					shade.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy);

				}

			}



			// �ݒ蕜��
			DG.Device->SetRenderState( D3DRS_CULLMODE,  D3DCULL_CCW );
			DG.Device->SetRenderState( D3DRS_ZWRITEENABLE,     TRUE );
			DG.Device->SetRenderState( D3DRS_STENCILENABLE,    FALSE );
			DG.Device->SetRenderState( D3DRS_SRCBLEND,  D3DBLEND_SRCALPHA );
			DG.Device->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );

		//}



		//�e�����ۂ̃o�b�t�@�ɏ���
		//{

			//�O����
			DG.Device->SetRenderState( D3DRS_ZENABLE,          FALSE );
			DG.Device->SetRenderState( D3DRS_ZWRITEENABLE,     FALSE );
			DG.Device->SetRenderState( D3DRS_STENCILENABLE,    TRUE );
			DG.Device->SetRenderState( D3DRS_STENCILREF,  0x1 );
			DG.Device->SetRenderState( D3DRS_STENCILFUNC, D3DCMP_LESSEQUAL );
			DG.Device->SetRenderState( D3DRS_STENCILPASS, D3DSTENCILOP_KEEP );


			//�����̔���ʂ����ς��Ƀ����_�[
			//{

				int shadealpha=0x40;
				typedef struct{
					float   x, y, z, w;
					DWORD   color;
				} LVERTEX;
				LVERTEX Vertex[4] = {
					//  x   y  z rhw color
					{   0,   0, 0, 1, D3DCOLOR_RGBA(0x0,0x0,0x0,shadealpha),},
					{(float)DG.Adapter.BackBufferWidth,   0, 0, 1, D3DCOLOR_RGBA(0x0,0x0,0x0,shadealpha),},
					{(float)DG.Adapter.BackBufferWidth,(float)DG.Adapter.BackBufferHeight, 0, 1, D3DCOLOR_RGBA(0x0,0x0,0x0,shadealpha),},
					{   0,(float)DG.Adapter.BackBufferHeight, 0, 1, D3DCOLOR_RGBA(0x0,0x0,0x0,shadealpha),},
				};
				DG.Device->SetVertexShader( D3DFVF_XYZRHW | D3DFVF_DIFFUSE );
				DG.Device->DrawPrimitiveUP( D3DPT_TRIANGLEFAN, 2, Vertex, sizeof( LVERTEX ) );
			//}


			// �ݒ蕜��
			DG.Device->SetRenderState( D3DRS_ZENABLE,          TRUE );
			DG.Device->SetRenderState( D3DRS_ZWRITEENABLE,          TRUE );
			DG.Device->SetRenderState( D3DRS_STENCILENABLE,    FALSE );
			DG.Device->SetRenderState( D3DRS_SHADEMODE, D3DSHADE_GOURAUD );

			DG.Device->SetRenderState( D3DRS_LIGHTING, true );
			DG.Device->SetTextureStageState( 0, D3DTSS_COLORARG1, D3DTA_TEXTURE );
			DG.Device->SetTextureStageState( 0, D3DTSS_COLOROP,   D3DTOP_MODULATE );
			DG.Device->SetTextureStageState( 0, D3DTSS_COLORARG2, D3DTA_DIFFUSE );
			DG.Device->SetTextureStageState( 0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE );
			DG.Device->SetTextureStageState( 0, D3DTSS_ALPHAOP,   D3DTOP_MODULATE );
			DG.Device->SetTextureStageState( 0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE );
			DG.Device->SetTextureStageState( 1, D3DTSS_COLOROP,   D3DTOP_DISABLE );
			DG.Device->SetTextureStageState( 1, D3DTSS_ALPHAOP,   D3DTOP_DISABLE );

			DG.Device->SetRenderState( D3DRS_SRCBLEND,  D3DBLEND_SRCALPHA );
			DG.Device->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );
			DG.Device->SetRenderState( D3DRS_BLENDOP, D3DBLENDOP_ADD );



		}







		//�{�[���̃����_�����O(�����{�[�����珑������)

		int ballsortindex[BALL_MAX],sortworki,ballindex;
		float ballsortdis[BALL_MAX],sortworkf,ballalpha;

		//�f�[�^�ǂݍ���
		for(i=0;i<BALL_MAX;i++)
		{
			ballsortindex[i]=i;
			if(ball[i].enable || (i==BALL_MAX-1 && Ghost && !replayend && GetClear() && ReadReplayFile && !replay))
			{
				ballsortdis[i]=distance3(ball[i].ball.po.x-player[index].cpo.x,
					ball[i].ball.po.y-player[index].cpo.y,ball[i].ball.po.z-player[index].cpo.z);
			}
		}

		//�C���f�b�N�X�̕��ёւ�
		for(i=0;i<BALL_MAX-1;i++)
		{
			for(j=i+1;j<BALL_MAX;j++)
			{
				if(ballsortdis[i]<ballsortdis[j])
				{
					sortworkf=ballsortdis[i];
					ballsortdis[i]=ballsortdis[j];
					ballsortdis[j]=sortworkf;

					sortworki=ballsortindex[i];
					ballsortindex[i]=ballsortindex[j];
					ballsortindex[j]=sortworki;
				}
			}
		}



		//�v���C���[�{�[���̔��˃e�N�X�`���𒲂ׂ�
		int envindex[4];

		for(i=0;i<playercount;i++)
		{
			if(stagekind==SELECTGAME_STAGE)
			{
				if(stagenum<12)
				{
					if(stagenum/4==0)
						envindex[i]=ENVKIND_KI;
					else if(stagenum/4==1)
						envindex[i]=-1;
					else if(stagenum/4==2)
						envindex[i]=ENVKIND_TETU;
					else if(stagenum/4==3 || stagenum==12)
						envindex[i]=ENVKIND_IZIGEN;
				}
				else
				{
					if((stagenum-13)/4==0)
						envindex[i]=ENVKIND_KI;
					else if((stagenum-13)/4==1)
						envindex[i]=-1;
					else if((stagenum-13)/4==2)
						envindex[i]=ENVKIND_TETU;
					else if((stagenum-13)/4==3 || stagenum==29)
						envindex[i]=ENVKIND_IZIGEN;
				}
			}
			else
			{
				if(stagenum/3==0)
					envindex[i]=ENVKIND_KI;
				else if(stagenum/3==1)
				{
					//�O�ɏo�Ă���Ƃ��̓X�e�[�W1�̔��˂�������
					envindex[i]=-1;
				}
				else if(stagenum/3==2)
				{
					if(player[i].charnum==4)//���Y
						envindex[i]=ENVKIND_TETUMETA;
					else
						envindex[i]=ENVKIND_TETU;
				}
				else if(stagenum/3==3)
					envindex[i]=ENVKIND_IZIGEN;
			}
		}



		//���ёւ����悤�Ƀ����_�����O
		for(i=0;i<BALL_MAX;i++)
		{
			ballindex=ballsortindex[i];
			if(ball[ballindex].enable || (ballindex==BALL_MAX-1 && Ghost && !replayend && GetClear() && ReadReplayFile && !replay && !staff))
			{
				//�����x�̕ύX
				if(ball[ballindex].deletecount!=0 && ball[ballindex].deletecount<50 && ball[ballindex].deletecount>-50)
				{
					if(ball[ballindex].deletecount>0)
						ballalpha=ball[ballindex].deletecount/50.0f;
					else if(ball[ballindex].deletecount<0)
						ballalpha=1+ball[ballindex].deletecount/50.0f;
					for(j=0;j<ballmesh[ball[ballindex].meshindex].MaterialCount;j++)
						ballmesh[ball[ballindex].meshindex].Material[j].Diffuse.a=ballalpha;

				}


				//�S�[�X�g�̓�����
				if(ballindex==BALL_MAX-1)
					for(j=0;j<ballmesh[ball[ballindex].meshindex].MaterialCount;j++)
						ballmesh[ball[ballindex].meshindex].Material[j].Diffuse.a*=0.4f;

				DG.Device->SetTransform( D3DTS_WORLD, &ball[ballindex].ball.mat );

				if(ball[ballindex].meshindex<5 && ballindex!=BALL_MAX-1)//�L�����N�^�[�Ȃ�
				{
					if(Setting.EnvEnable && envindex[ballindex]!=-1)
					{
						ballmesh[ball[ballindex].meshindex].Render(DG.Device, &player[index].cpo, 
								&player[index].ballold, fovy, 0,1);
						ballmesh[ball[ballindex].meshindex].Render(DG.Device, &player[index].cpo, 
								&player[index].ballold, fovy, 1,1,&EnvTex[envindex[ballindex]]);

					}
					else
						ballmesh[ball[ballindex].meshindex].Render(DG.Device, &player[index].cpo, 
								&player[index].ballold, fovy);
				}
				else if(ball[ballindex].meshindex==BALLMESH_TETU || ball[ballindex].meshindex==BALLMESH_MINITETU || ball[ballindex].meshindex==BALLMESH_BIGTETU || ball[ballindex].meshindex==BALLMESH_BOMB || ball[ballindex].meshindex==BALLMESH_YUUDOU)
				{
//					ballmesh[ball[ballindex].meshindex].Render(DG.Device, &player[index].cpo, 
//							&player[index].ballold, fovy, 0,1);
					ballmesh[ball[ballindex].meshindex].Render(DG.Device, &player[index].cpo, 
							&player[index].ballold, fovy, 0,0,ENVCHECK(&EnvTex[ENVKIND_TETUMETA]));
				}
				else if(ball[ballindex].meshindex==BALLMESH_IZIGENBALL)
				{
					DG.Device->SetRenderState( D3DRS_ZWRITEENABLE,     FALSE );
					ballmesh[ball[ballindex].meshindex].Render(DG.Device, &player[index].cpo, 
							&player[index].ballold, fovy, 0,0,ENVCHECK(&EnvTex[ENVKIND_TETUMETA]));
					DG.Device->SetRenderState( D3DRS_ZWRITEENABLE,     true );
				}
				else
				{
						ballmesh[ball[ballindex].meshindex].Render(DG.Device, &player[index].cpo, 
								&player[index].ballold, fovy);
				}



				//�����x�����ɖ߂�
				//if(ball[ballindex].deletecount!=0 && ball[ballindex].deletecount<50 && ball[ballindex].deletecount>-50)
				{
					for(j=0;j<ballmesh[ball[ballindex].meshindex].MaterialCount;j++)
						ballmesh[ball[ballindex].meshindex].Material[j].Diffuse.a=1;
				}
			}

		}





		//�{�[���������I�������Ƃ��������������I�I


		DG.Device->SetRenderState( D3DRS_LIGHTING, true );
		DG.Device->LightEnable (0,false);
		DG.Device->SetRenderState( D3DRS_AMBIENT, 0xffffffff );

		for(i=0;i<BOMB_MAX;i++)
		{
			if(Bomb[i].sizemax!=0)
			{
				//�����_�����O
				float alp=(Bomb[i].sizemax-Bomb[i].size)/Bomb[i].sizemax;

				//�����x�ύX
				for(j=0;j<bombmesh.MaterialCount;j++)
					bombmesh.Material[j].Diffuse.a=alp;

				//�T�C�Y�ύX(�J�����O�p)
				for(j=0;j<bombmesh.MeshCount;j++)
					bombmesh.MeshR[j]=Bomb[i].size;

				//�}�g���b�N�X�ݒ�
				D3DXMatrixScaling( &mat, Bomb[i].size,Bomb[i].size,Bomb[i].size );
				mat*=Bomb[i].mat;
				D3DXMatrixTranslation( &mat2, Bomb[i].p.x,Bomb[i].p.y,Bomb[i].p.z );
				mat*=mat2;

				DG.Device->SetTransform( D3DTS_WORLD, &mat );

				bombmesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy);
			}
		}

		DG.Device->LightEnable (0,true);
		DG.Device->SetRenderState( D3DRS_AMBIENT, ambient );


		////2��ڂ̃����_�����O
		SecondRender(index);



		float dis;


		//�������_�����O�ݒ�

		DG.Device->SetRenderState( D3DRS_LIGHTING, true );
		DG.Device->LightEnable (0,false);
		DG.Device->SetRenderState( D3DRS_AMBIENT, 0xffffffff );


		DG.Device->SetRenderState( D3DRS_ZWRITEENABLE,     FALSE );


		////����`��


		//�r���{�[�h�p��]�}�g���b�N�X�̌v�Z
		D3DXVECTOR3 cameramuki=-(ball[index].ball.po+player[index].cup-player[index].cpo);//�J�����ւ̌����x�N�g��
		D3DXMATRIX kemurimat;
		D3DXMatrixRotationX( &kemurimat, angle(distance(cameramuki.x,cameramuki.z),cameramuki.y)*rad );
		D3DXMatrixRotationY( &matWorld, (angle(cameramuki.z,cameramuki.x)+180)*rad );
		kemurimat*=matWorld;


		float par;//���݂̃t���[���̃p�[�Z���g�����߂鎞�Ɏg��

		for(i=0;i<KEMURI_MAX;i++)
		{

			if(kemuri[i].frame>0)
			{
				dis=D3DXVec3Length(&(player[index].cpo-kemuri[i].po));
				if(dis<Setting.KemuriMaxDis)
				{


					par=((float)kemuri[i].frame/kemuri[i].framemax);

					D3DXMatrixScaling( &matWorld, par*2,par*2,par*2 );
					matWorld*=kemurimat;
					D3DXMatrixTranslation( &matWorld2, kemuri[i].po.x,kemuri[i].po.y,kemuri[i].po.z );
					matWorld*=matWorld2;

					DG.Device->SetTransform( D3DTS_WORLD, &matWorld );


					if(dis>Setting.KemuriMaxDis/2)
						dis=1-(dis-Setting.KemuriMaxDis/2)/(Setting.KemuriMaxDis/2);
					else
						dis=1;

					ita.SetTexture(KemuriTex[kemuri[i].kind],0);

					if(kemuri[i].kind==6)//�V���b�g!!
						DG.Device->SetRenderState( D3DRS_ZENABLE,     false );

					if(kemuri[i].kind==3)//�َ���!!
					{
						DG.Device->SetRenderState( D3DRS_SRCBLEND,  D3DBLEND_ONE );
						DG.Device->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_ONE );
						DG.Device->SetRenderState( D3DRS_ZENABLE,     true );
						float lks=cosf(par*dis*90*rad);
						DG.Device->SetRenderState( D3DRS_AMBIENT, D3DXCOLOR(lks,lks,lks,1));
					}
					else
					{
						ita.Material[0].Diffuse.a=(1-par)*dis;
						DG.Device->SetRenderState( D3DRS_AMBIENT, 0xffffffff );
					}

					ita.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy);

					DG.Device->SetRenderState( D3DRS_SRCBLEND,  D3DBLEND_SRCALPHA );
					DG.Device->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );
					DG.Device->SetRenderState( D3DRS_ZENABLE,     true );

				}
			}

		}






		//�ݒ��߂�
		ita.Material[0].Diffuse.r=ita.Material[0].Diffuse.g=ita.Material[0].Diffuse.b=1;
		ita.Material[0].Ambient.a=ita.Material[0].Diffuse.a=1;

		DG.Device->SetRenderState( D3DRS_ZWRITEENABLE,     TRUE );
		DG.Device->SetRenderState( D3DRS_LIGHTING, true );
		DG.Device->LightEnable (0,true);
		DG.Device->SetRenderState( D3DRS_AMBIENT, ambient );

		DG.Device->SetRenderState( D3DRS_SRCBLEND,  D3DBLEND_SRCALPHA );
		DG.Device->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );
		DG.Device->SetRenderState( D3DRS_CULLMODE,  D3DCULL_CCW );
		DG.Device->SetRenderState( D3DRS_ZWRITEENABLE,  true );
		DG.Device->SetRenderState( D3DRS_FOGENABLE, false );

		DG.Device->SetRenderState( D3DRS_ZENABLE,     true );

	}







}








#endif
