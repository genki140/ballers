#ifndef STAGE_HED
#define STAGE_HED













//爆弾を爆発させる
void Bakuhatu(int index)
{


	int i,j,si;
	float dis;
	D3DXMATRIX mat;


	ball[index].enable=false;

	//誘導なら効果音を消す
	if(ball[index].meshindex==BALLMESH_YUUDOU)
	{
		if(play3d)
			sd.Yudou3D[ball[index].info[1]].Sound->Stop();
		else
			sd.Yudou[ball[index].info[1]]->Stop();

		//クライアントにデータ送る
		if(seaver)
			SendYuudouEnd(ball[index].info[1]);
	}

	//周りにいるボールを吹き飛ばす
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

		//爆風発生
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


				//クライアントにデータを送る
				SendBakuhuu(j);

				break;
			}
		}


		//効果音再生
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



//ステージ設定!!(3Dも読み込みます)
bool StageSetting()
{

	int i;

	InfoReset();
	InfoStartCount();

	gameframe=0;

	//全ボールの初期化
	for(i=0;i<BALL_MAX;i++)
	{
		ball[i].enable=false;
		ball[i].gv=D3DXVECTOR3(0,1,0);
	}

//	Ghost=true;

	for(i=0;i<5;i++)
		feed[i].Reset();

	//-------------------------------キャラ配置----------------------------------

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
			//人数によって位置は違う
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


		//カメラ位置初期設定
		player[i].cup=player[i].cupnext=D3DXVECTOR3(0,1,0);


//		ball[i].ball.po=D3DXVECTOR3(-203.5f,10.8f,-243.41f);
//		ball[i].ball.po=D3DXVECTOR3(0,0,-129.75);

//		ball[i].ball.po=D3DXVECTOR3(-70.0f,70.0f,-400);

	}


	//ball[1].gv=D3DXVECTOR3(0,-1,0);
	//ball[0].ball.po=D3DXVECTOR3(0,10,0);
	//ball[1].ball.po=D3DXVECTOR3(0,7,0);



	//効果音消し
	SoundReset();


	//爆風けし
	for(i=0;i<BOMB_MAX;i++)
		Bomb[i].sizemax=0;
	
	//stagestage初期化
	for(i=0;i<STAGESTATE_MAX;i++)
	{
		stagestate[i].s=0;
		stagestate[i].s2=0;
		stagestate[i].v=D3DXVECTOR3(0,0,0);
		stagestate[i].v2=D3DXVECTOR3(0,0,0);
	}

	//---------------------------------------------------------------------------



	//※judfilename2はいずれ消す

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



//	//当たり判定読み込み
//
//	if(buttonstate[4].startpress)
//	{
////	MessageBox(NULL,"判定ファイル書き出し","",MB_OK);
//		judc.CreateJudFile(DG.Device,judfilename,judfilename2,10,10,10);
////		MessageBox(NULL,"判定ファイルの書き出し成功","",MB_OK);
//	}


	//チェックファイル作成
	//createcheckfile(judfilename);
	//不正チェック
	if(checkfile(judfilename)==false)
		return false;


	if(judc.LoadJudFile(judfilename)==false)
		return false;

	//メッシュを完全に初期化
	stagemesh.Reset();
	stagemesh.Release();
	//メッシュ読み込み
	if(StageMeshLoad()==false)
	{
		return false;
	}

	//レースだったら歓声再生

	if(stagekind!=SELECTGAME_STAGE)
		SOUND_PLAY(sd.Kansei);




	Time=0;




	//ステージセッティング!!

	int index;
	D3DXMATRIX matrix;

	guncount=0;
	windcount=0;
	itemcount=0;





	if(stagekind==SELECTGAME_STAGE)//ステージモード
	{


		//ステージ全体の簡単な設定

		//草原
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

		//洞窟
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

		else if(stagenum==10)//テクノ3
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
		else if(stagenum==21)//EXテクノ1
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
		else if(stagenum==22)//EXテクノ2
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
		else if(stagenum==23)//EXテクノ3
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
		else if(stagenum==24)//EXテクノ4
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



		//その他のテクノ
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


		//異次元
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















		//ステージごとの細かな設定



		if(stagenum==9)
		{

			//大砲設置
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

			//大砲設置
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

			//大砲設置
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

		//最後のスタッフロール
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

		//ゴール配置
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








		//ゴールの噴射口配置
		goal.index=windcount;
		wind[windcount].enable=true;
		wind[windcount].kind=stagenum<12 ? stagenum/4 : (stagenum-13)/4;
		if(stagenum==12 || stagenum==29) wind[windcount].kind=3;//スタッフロールは異次元の煙
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


		//スタートの噴射口配置
		wind[windcount].enable=true;
		wind[windcount].kind=stagenum<12 ? stagenum/4 : (stagenum-13)/4;
		if(stagenum==12 || stagenum==29) wind[windcount].kind=3;//スタッフロールは異次元の煙
		wind[windcount].p=D3DXVECTOR3(0,0,0);
		wind[windcount].v=D3DXVECTOR3(0,0.5f,0);
		wind[windcount].dis=10;
		wind[windcount].ang=30;
		wind[windcount].mat=D3DXMATRIX(1,0,0,0,0,1,0,0,0,0,1,0,wind[windcount].p.x,wind[windcount].p.y,wind[windcount].p.z,1);
		windcount++;



	}
	else//バーサスモード
	{

		lap=2;


		if(stagenum==0)//草原1
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

		else if(stagenum==1)//草原2
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



		else if(stagenum==2)//草原3
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




		else if(stagenum==3)//洞窟1
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


			//大砲設定

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




		else if(stagenum==4)//洞窟2
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


		else if(stagenum==5)//洞窟3
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

			//大砲設定

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



		else if(stagenum==6)//テクノ1
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






			//ゆれる鉄球

			//天井の高さ=88.4
			index=4;//stagestate[10,11].sを使用
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


			index++;//stagestate[12,13].sを使用
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



			//転がる鉄球

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







			//大砲
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




		else if(stagenum==7)//テクノ2
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






		else if(stagenum==8)//テクノ3
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


			//弾発射大砲

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
			stagestate[index].kind=ITAKIND_MOVE;//外側
			stagestate[index].matindex=MATKIND_IZIGEN;
			stagestate[index].v=D3DXVECTOR3(0,0,-0.2f);
			index++;
			stagestate[index].kind=ITAKIND_ROTATE;//内側
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



		//噴射口配置

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

			//アイテム読み込み
			char str[MAX_PATH];

			FILE *file;

			itemcount=0;

			sprintf(str,"data/data/corce/item/%d",stagenum+1);
			if((file=fopen(str,"r"))==NULL) return false;

			while(fscanf(file,"%f,%f,%f",&item[itemcount].po.x,&item[itemcount].po.y,&item[itemcount].po.z)!=EOF)
			{
				//アイテムの設定
				item[itemcount].getter=-1;
				item[itemcount].deletecount=1;
				item[itemcount].nowpo=item[itemcount].po;
				itemcount++;
			}


		}



		
	}




	//煙をけす
	for(i=0;i<KEMURI_MAX;i++)
		kemuri[i].frame=0;








	return true;

}







void StageMove()
{




	int i,j,k;
	float ang,dis;

	int si;//効果音のインデックス指定に使う


	if(stagekind==SELECTGAME_MULTIPLAY && Setting.Seaver)
		gameframe++;





	////スタート（噴射をとめる)

	if(info.startcounter==1)
	{
		//噴射とめる
		for(i=0;i<playercount;i++)
		{
			wind[windcount-1-i].enable=false;
		}
	}



	//ゴールしていたらボールをゴール地点でとめる
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


	


	//アイテム関係

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

				//プレイヤーのアイテム取得処理
				if( player[keepgetter].itemkind==ITEMKIND_NONE )
				{
					//ほかのアイテムも取っていないかを調べる
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

				//アイテムの種類を選ぶ
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





	//爆風アニメーション


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

		//バグ防止！！
		if(ball[index].ball.axis.x==0) ball[index].ball.axis.x=0.0000001f;
		if(ball[index].ball.axis.y==0) ball[index].ball.axis.y=0.0000001f;
		if(ball[index].ball.axis.z==0) ball[index].ball.axis.z=0.0000001f;


		if(ball[index].enable)
		{


			//摩擦力や重さの倍率調整

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




				//順位に応じても変化する(1位を基準とし、lap+parの差で求める)

				//一位のインデックスを求める
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





			if(ball[index].deletecount>0)//ボールフェードアウト
			{
				ball[index].deletecount--;



				//ボールが爆弾だったら
				if(ball[index].meshindex==BALLMESH_BOMB || ball[index].meshindex==BALLMESH_YUUDOU)
				{
					//カウントが100にってたら自動爆発
					if(ball[index].deletecount==100)
					{//爆発！！
						Bakuhatu(index);
					}

				}

				//チェックポイントへ戻す
				if(ball[index].deletecount==0)
				{
					if(index<playercount)
					{
						feed[index].Start(FEEDMODE_BLACKIN,50);

						//戻る位置を調べる
						for(i=0;i<info.checkcount;i++)
						{
							if(player[index].par<info.check[i].par)
							{
								i--;
								if(stagekind==SELECTGAME_VARSUS && stagenum==11)//異次元最終コースの2週目は裏返す
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
						//効果音停止
						if(play3d)
							sd.Iwa3D[ball[index].info[0]].Sound->Stop();
						else
							sd.Iwa[ball[index].info[0]]->Stop();

						//クライアントにデータを送る
						SendIwaEnd(ball[index].info[0]);
					}



				}

				else if(ball[index].deletecount==50 && index<playercount)
					feed[index].Start(FEEDMODE_BLACKOUT,50);



			}
			else if(ball[index].deletecount<0)//ボールフェードイン
			{
				ball[index].deletecount++;
			}




			//誘導だまの場合特殊な処理をする
			if(ball[index].meshindex==BALLMESH_YUUDOU)
			{


				//回転を弱めていき、一定の速度になったら追跡開始！！
				if(D3DXVec3Length(&ball[index].ball.axis)<=0.1f)
				{

					//追跡開始！！

					float mindis=0;
					int minindex=-1;

					//一番近いプレイヤーを探す
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

					//minindexに向かって突っ込む！！
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


				//音声位置を変える

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
				//それ以外の普通のボール

				if(ball[index].meshindex==BALLMESH_BIGIWA)
				{

					//音声位置を変える

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



				//重力
				dis=9.8f/60/60*mulgrab;

				ball[index].ball.mv.x-=ball[index].gv.x*dis;
				ball[index].ball.mv.y-=ball[index].gv.y*dis;
				ball[index].ball.mv.z-=ball[index].gv.z*dis;
			}


			//空気抵抗
			ball[index].ball.setrotares(matstruct[ball[index].matindex].rotares);

			D3DXVECTOR3 windv=D3DXVECTOR3(0,0,0);//ボールのある位置の空気の流れのベクトル
			float dot,wx,wy,wz,wx2,wy2,wz2;

			for(i=0;i<windcount;i++)
			{
				if(wind[i].enable)
				{
					//距離テスト
					dot=dotpro3(wind[i].v.x,wind[i].v.y,wind[i].v.z,
							ball[index].ball.po.x-wind[i].p.x,ball[index].ball.po.y-wind[i].p.y,ball[index].ball.po.z-wind[i].p.z);


					if(dot>=0 && dot <=wind[i].dis)
					{


						//範囲テスト
						axisvector(&wx,&wy,&wz,wind[i].v.x,wind[i].v.y,wind[i].v.z,
							ball[index].ball.po.x-wind[i].p.x,ball[index].ball.po.y-wind[i].p.y,ball[index].ball.po.z-wind[i].p.z);

						dis=distance3(wx,wy,wz)-ball[index].ball.r*0.7f;
						if(dis<=0) dis=0;
						else changedistance3(&wx,&wy,&wz,dis);


						wx2=wind[i].v.x;wy2=wind[i].v.y;wz2=wind[i].v.z;
						changedistance3(&wx2,&wy2,&wz2,dot);

						//二つのべくとるの角度を求める！！
						ang=angle3(wind[i].v.x,wind[i].v.y,wind[i].v.z,wx2+wx,wy2+wy,wz2+wz);


						if(ang<=wind[i].ang/2)
						{

							//風の影響力計算
							changedistance3(&wx2,&wy2,&wz2,
											(1-dot/wind[i].dis)*(1-ang/(wind[i].ang/2))*distance3(wind[i].v.x,wind[i].v.y,wind[i].v.z)*30);	

							windv.x+=wx2;
							windv.y+=wy2;
							windv.z+=wz2;


							//ゴールの判定
							if(stagekind==SELECTGAME_STAGE && i==goal.index && player[index].InputEnable==true)
							{
								//ゴール！！

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





			//大砲処理(最初は大砲の中心に向かって進む、中心まできたら飛ばし、しばらく大砲と当たり判定しない)


			for(i=0;i<guncount;i++)
			{
				dis=distance3(ball[index].ball.po.x-gun[i].p.x,ball[index].ball.po.y-gun[i].p.y,ball[index].ball.po.z-gun[i].p.z)-ball[index].ball.r;

				if(dis<=0.1f)
				{
					vec=gun[i].v;
					changedistance3(&vec.x,&vec.y,&vec.z,1.5f+ball[index].ball.r);
					ball[index].ball.po=gun[i].p+vec;
					ball[index].ball.mv=gun[i].v;

					//煙を吐く

					//ステージによって、飛ぶときに一瞬白く光る
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

					//効果音再生
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









			//バグ防止
			if(ball[index].nojudindex==index)
				ball[index].nojudindex=-1;


			//nojudindexのボールと食い込んでなかったらnojudindex=-1にする
			else if(ball[index].nojudindex!=-1)
			{
				//食い込んでいないかチェック
				dis=distance3(ball[index].ball.po.x-ball[ball[index].nojudindex].ball.po.x,ball[index].ball.po.y-ball[ball[index].nojudindex].ball.po.y,ball[index].ball.po.z-ball[ball[index].nojudindex].ball.po.z );

				char str[100];
				sprintf(str,"%d\n%f\n%f",ball[index].nojudindex,dis,ball[index].ball.r+ball[ball[index].nojudindex].ball.r);
				if(dis>=ball[index].ball.r+ball[ball[index].nojudindex].ball.r)
				{
					ball[index].nojudindex=-1;
				}
			}
			


			//ボール同士が食い込んでいたら戻す
//			if(ball[index].nojudindex==-1)
			{
				for(i=0;i<BALL_MAX;i++)
				{
					//自分じゃない&ボールがある
					if(index!=i && ball[i].enable && ball[index].nojudindex!=i && ball[i].nojudindex!=index)
					{
						dis=distance3(ball[index].ball.po.x-ball[i].ball.po.x,ball[index].ball.po.y-ball[i].ball.po.y,ball[index].ball.po.z-ball[i].ball.po.z );
						if(dis<ball[index].ball.r+ball[i].ball.r)
						{
//							MessageBox(NULL,"","",MB_OK);
							vec=ball[i].ball.po-ball[index].ball.po;//vec=iから見たindexの位置
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



















			//軌道当たり判定

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

					//安全対策
					if(judc.judres.p[0]<0)
						judc.judres.p[0]=0;


					if(judc.judres.kind[0]<BALLKIND_START)//壁に当たってたら
					{


						//回転量より、後の方向と回転を求める

						//球のあたった位置を求める
						D3DXVECTOR3 pointp=judc.judres.n[0];
						pointp.x*=-ball[index].ball.r;
						pointp.y*=-ball[index].ball.r;
						pointp.z*=-ball[index].ball.r;

						//当たった位置の移動量を求める
						D3DXVECTOR3 attpointmove=ball[index].ball.getrota(pointp),attpointrota=ball[index].ball.getrota(pointp);



						float avgdf=((matstruct[ball[index].matindex].df*muldf)+matstruct[stagestate[judc.judres.kind[0]].matindex].df)/2;
						float avgsf=((matstruct[ball[index].matindex].sf*mulsf)+matstruct[stagestate[judc.judres.kind[0]].matindex].sf)/2;
						float addrollres=matstruct[ball[index].matindex].rollres+matstruct[stagestate[judc.judres.kind[0]].matindex].rollres;



						if(ball[index].meshindex==BALLMESH_YUUDOU)
						{
							//摩擦力0
							avgdf=0;avgsf=0;

						}




						//判定種類によっていろいろなエフェクト

						if(stagestate[judc.judres.kind[0]].matindex==MATKIND_SUNA)
						{

							if(judc.judres.p[0]*(ball[index].ball.w*mulw)>2.0f)
							{
								//すなをボワっ！！と

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
								//後ろに舞う煙

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







						//重力方向変更(異次元)
						if(stagestate[judc.judres.kind[0]].matindex==MATKIND_GURABI || player[index].usekind==ITEMKIND_GURABI)
							ball[index].gv=judc.judres.n[0];




						//プレイヤーでコースアウト以外のとき
						if(index<playercount && ball[index].deletecount==0 && stagestate[judc.judres.kind[0]].kind!=ITAKIND_CORCEOUT)
						{
							if(player[index].InputEnable)
							{
								//地面と重力方向との角度により、parの設定(内積で計算)
								if(	ball[index].gv.x*judc.judres.n[0].x+
									ball[index].gv.y*judc.judres.n[0].y+
									ball[index].gv.z*judc.judres.n[0].z>0.6f)
								{
									player[index].par=player[index].temppar;
								}
							}
						}





						//ボールに力を加える
						if(stagestate[judc.judres.kind[0]].kind==ITAKIND_NORMAL)//普通
						{

							ball[index].ball.setpower(pointp,D3DXVECTOR3(0,0,0),judc.judres.p[0]*(ball[index].ball.w*mulw),avgdf,avgsf,0.5f);

						}
						else if(stagestate[judc.judres.kind[0]].kind==ITAKIND_CORCEOUT)//コースアウト
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
						else if(stagestate[judc.judres.kind[0]].kind==ITAKIND_MOVE)//移動
						{
							ball[index].ball.setpower(pointp, stagestate[judc.judres.kind[0]].v, judc.judres.p[0]*(ball[index].ball.w*mulw),avgdf,avgsf,0.5f);

						}
						else if(stagestate[judc.judres.kind[0]].kind==ITAKIND_ROTATE)//回転
						{
							D3DXVECTOR3 atpo=ball[index].ball.po+pointp-stagestate[judc.judres.kind[0]].v;//AttackPoint

							D3DXVECTOR3 wv,mv;

							//当たった位置を回転軸よりもとめる
							axisvector(&wv.x,&wv.y,&wv.z,stagestate[judc.judres.kind[0]].v2.x,stagestate[judc.judres.kind[0]].v2.y,
										stagestate[judc.judres.kind[0]].v2.z,atpo.x,atpo.y,atpo.z);


							//wvと回転軸とで外積を取る
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






							//ボールが爆弾だったら
							if(ball[index].meshindex==BALLMESH_BOMB)
							{
								//回転が止まっててpが少なかったら爆発

								if(judc.judres.p[0]<0.03f && D3DXVec3Length(&ball[index].ball.axis)<0.3f)
								{//爆発！！

									Bakuhatu(index);

								}

							}
							else if(ball[index].meshindex==BALLMESH_YUUDOU)//誘導だまだったら
							{


								//壁には正面からぶつからないと爆発しない
								float mul=ball[index].ball.mv.x*judc.judres.n[0].x+
									ball[index].ball.mv.y*judc.judres.n[0].y+
									ball[index].ball.mv.z*judc.judres.n[0].z;
								if(	mul>0.4f || mul<-0.4f)//両面
								{
									Bakuhatu(index);
								}


							//	//壁には強めに当たらないと爆発しない
							//	if(judc.judres.p[0]>0.1f)
							}

							else if(ball[index].meshindex==BALLMESH_TAMA)
							{
								ball[index].enable=false;
							}









							//はねる
							ball[index].ball.mv.x+=judc.judres.n[0].x*judc.judres.p[0]*(1+matstruct[ball[index].matindex].bound*matstruct[stagestate[judc.judres.kind[0]].matindex].bound);
							ball[index].ball.mv.y+=judc.judres.n[0].y*judc.judres.p[0]*(1+matstruct[ball[index].matindex].bound*matstruct[stagestate[judc.judres.kind[0]].matindex].bound);
							ball[index].ball.mv.z+=judc.judres.n[0].z*judc.judres.p[0]*(1+matstruct[ball[index].matindex].bound*matstruct[stagestate[judc.judres.kind[0]].matindex].bound);


							//触れてる地面の種類により、ボールの回転を弱める
							ball[index].ball.setrotaressub(addrollres);




							if(index<playercount && stagekind!=SELECTGAME_STAGE)
							{
								//カメラのUPNextを変える
								player[index].cupnext.x+=(judc.judres.n[0].x-player[index].cupnext.x)*0.4f;
								player[index].cupnext.y+=(judc.judres.n[0].y-player[index].cupnext.y)*0.4f;
								player[index].cupnext.z+=(judc.judres.n[0].z-player[index].cupnext.z)*0.4f;
								changedistance3(&player[index].cupnext.x,&player[index].cupnext.y,&player[index].cupnext.z,1);
							}







							//振動

							float vib=judc.judres.p[0]*(ball[index].ball.w)/10.0f;
							if(vib>0.05f)
								if(!autoReplay)
									DI.SetEffect(multiplayindex(index),vib,(int)(vib*5),0);



							//壁の種類に応じて効果音を再生

							//音量と周波数の設定
							float vol,hz;

							vol=judc.judres.p[0]*(ball[index].ball.w)/8.0f;
							if(vol>1)vol=1;
							hz=70.0f/ball[index].ball.w;

							//再生する音の種類を調べる
							int soundkind;
							soundkind=stagestate[judc.judres.kind[0]].matindex;

							if(soundkind==MATKIND_SIBA || soundkind==MATKIND_SUNA)
							{
								//芝生は特別に移動してるだけで音を出す

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
					else//ボールにあたってたら
					{

						float vib=judc.judres.p[0]*(ball[index].ball.w*mulw)/10.0f;
						if(vib>0.05f)
							if(!autoReplay)
								DI.SetEffect(multiplayindex(index),vib,(int)(vib*5),0);



//						if(ball[judc.judres.kind[0]-BALLKIND_START].deletecount)


						int index2=judc.judres.kind[0]-BALLKIND_START;

//						judc.judres.p[0]*=0.5;


						D3DXVECTOR3 pointp=-judc.judres.n[0];


						//自分のぶつかった勢いを調べる
						float v1=dotpro3(pointp.x,pointp.y,pointp.z,ball[index].ball.mv.x,ball[index].ball.mv.y,ball[index].ball.mv.z);
						//相手のぶつかった勢いを調べる
						float v2=dotpro3(pointp.x,pointp.y,pointp.z,ball[index2].ball.mv.x,ball[index2].ball.mv.y,ball[index2].ball.mv.z);

						//当たってる相手の勢いと重さ、自分の勢いと重さより、生じる力を求める
						float tikara=sayou( (ball[index].ball.w*mulw), v1, ball[index2].ball.w, v2, matstruct[ball[index].matindex].bound*matstruct[ball[index2].matindex].bound );

						if(tikara>0)
						{

							//球のあたった位置を求める(方向)
							pointp.x*=ball[index].ball.r;
							pointp.y*=ball[index].ball.r;
							pointp.z*=ball[index].ball.r;

							D3DXVECTOR3 pointp2=judc.judres.n[0];
							pointp2.x*=ball[index2].ball.r;
							pointp2.y*=ball[index2].ball.r;
							pointp2.z*=ball[index2].ball.r;


							//はねる

							//自分に力を加える
							D3DXVECTOR3 powerp=judc.judres.n[0];
							powerp.x*=tikara;
							powerp.y*=tikara;
							powerp.z*=tikara;
							ball[index].ball.setmove(powerp);
							
							//相手に力を加える
							ball[index2].ball.setmove(-powerp);


							float avgdf=((matstruct[ball[index].matindex].df*muldf)+matstruct[ball[index2].matindex].df)/2.0f;//強すぎておかしいので弱くする
							float avgsf=((matstruct[ball[index].matindex].sf*mulsf)+matstruct[ball[index2].matindex].sf)/2.0f;//強すぎておかしいので弱くする
							float addrollres=matstruct[ball[index].matindex].rollres+matstruct[ball[index2].matindex].rollres;





							//ボールに力を加える
							//当たってる位置の移動量を自分座標で求める!

							//自分にかかる力の割合
							float powerres=ball[index2].ball.w/((ball[index].ball.w*mulw)+ball[index2].ball.w);


							D3DXVECTOR3 movev;
							movev=ball[index2].ball.getmove(pointp2)+ball[index2].ball.getrota(pointp2);
							ball[index].ball.setpower(pointp,movev,tikara*2*(powerres),avgdf,avgsf,0.5f);

							movev=ball[index].ball.getmove(pointp)+ball[index].ball.getrota(pointp);
							ball[index2].ball.setpower(pointp2,movev,tikara*2*(1-powerres),avgdf,avgsf,0.5f);




							//相手がプレイヤーで、自分がファイヤーだったら相手にも移す
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


							//触れてるボールの種類により、ボールの回転を弱める
							ball[index].ball.setrotaressub(addrollres);



							if(ball[index].meshindex==BALLMESH_TAMA)
							{
								ball[index].enable=false;
							}
							if(ball[index2].meshindex==BALLMESH_TAMA)
							{
								ball[index2].enable=false;
							}

							if(ball[index].meshindex==BALLMESH_YUUDOU)//誘導だまだったら
							{
									Bakuhatu(index);
							}
							if(ball[index2].meshindex==BALLMESH_YUUDOU)//誘導だまだったら
							{
									Bakuhatu(index2);
							}



							//振動

							float vib=judc.judres.p[0]*(ball[index].ball.w)/10.0f;
							if(vib>0.05f)
								if(!autoReplay)
									DI.SetEffect(multiplayindex(index),vib,(int)(vib*5),0);




							//ボールの種類に応じて効果音を再生(2つ効果音を鳴らす)

							int indexs[2]={index,index2};
							//再生する音の種類を調べる
							int soundkind;//={SOUNDKIND_PURA,SOUNDKIND_PURA};

							for(i=0;i<2;i++)
							{

								//音量と周波数の設定
								float vol,hz;

								vol=judc.judres.p[0]*(ball[indexs[i]].ball.w)/8.0f;
								if(vol>1)vol=1;
								hz=70.0f/ball[indexs[i]].ball.w;

								if(hz<0.1f)hz=0.1f;

								//ボールの材質には次のものがある
								//プラスチック、金属、石
								//音の種類にはプラスチックと鉄のみ


								soundkind=SOUNDKIND_PURA;

								if(ball[indexs[i]].matindex==MATKIND_CHARA+4 || ball[indexs[i]].matindex==MATKIND_TETU || ball[indexs[i]].matindex==MATKIND_TETU2 || ball[indexs[i]].matindex==MATKIND_YUUDOU)
									soundkind=SOUNDKIND_TETU;



								if(vol>0.06f)
								{

									SoundPlay(soundkind,index,vol,hz);


								}//サウンド再生条件終了

							}//2つの音ループ終了


						}

					}


				}
				else
				{
					counter=0;
					break;
				}

			}


			//ボールを実際に動かす
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






	//ゴースト用にこれも動かす
	ball[BALL_MAX-1].ball.move();




























	float mulpow,mulsp;




	//プレイヤーループ
	static oldlap[4];

	for(index=0;index<playercount;index++)
	{

		if(player[index].MutekiCount>0) player[index].MutekiCount--;

		mulpow=1;mulsp=1;

		//アイテムに応じて変化する
		if(player[index].usekind==ITEMKIND_FIRE)
		{
			mulpow=1.3f;mulsp=1.3f;
		}
		else if(player[index].usekind==ITEMKIND_MIZU)
		{
			mulpow=0.7f;mulsp=0.7f;
		}

		//順位に応じても変化する(1位を基準とし、lap+parの差で求める)

		//一位のインデックスを求める
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



		//フェードアウト処理(大砲で外に飛び出すとき)
		if(feed[index].mode==FEEDMODE_WHITEOUT && feed[index].count==feed[index].countend/2)
		{
//			feed[index].Start(FEEDMODE_WHITEIN,150);
			feed[index].countend=150;
			feed[index].count=feed[index].countend/2;
			feed[index].mode=FEEDMODE_WHITEIN;
		}


		//縦軸の回転を減速！！(ゲームにならないので)
		float rollres=matstruct[ball[index].matindex].rollres*40;

		//回転軸の方向成分を求め、addrollresで引く
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

			//コースの位置を計算
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
						//逆走表示する
						if(info.backframe[index]==0)
							info.backframe[index]=120;
					}
				}
				else
				{
					//だんだんカウントを戻していく
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
					//ゴール
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

						//追い抜けないような処理
						if(player[index].rank==1)
							player[index].lap=lap+3;
						else if(player[index].rank==2)
							player[index].lap=lap+2;
						else if(player[index].rank==3)
							player[index].lap=lap+1;

						if(player[index].rank>=playercount-1)//最後の1人前のやつがゴール
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
										//全員フェードアウト
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
					//ファイナルラップ

					//マルチプレイのときは自分だけ再生
//					if(stagekind!=SELECTGAME_MULTIPLAY || index==multiplayernum)
//					SOUND_PLAY(sd.Final);

					info.finalframe[index]=120;
					player[index].FinalLap=true;
				}
			}
			oldlap[index]=player[index].lap;

		}






		//クライアント時は、サーバーから送られてくる情報を更新した変数、ClientItemを判断してアイテム処理を行う

		if(stagekind==SELECTGAME_MULTIPLAY && !Setting.Seaver)//クライアントだったら
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

		//ショットとグラビ,ファイアー,ウォーターの一部は先に処理(マルチプレイクライアント用)


		if(player[index].usekind==ITEMKIND_FIRE)
		{

			//ファイヤーを撒き散らす


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

			//1だったら発射！！

			//まえにいて一番近いキャラクター(自分が発射した以外の誘導爆弾も)を探す(一定以上の距離があったらカーソルは進行方向に)


			ws=300;//打てる限界の範囲
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

			//光を撒き散らす

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

			//水を撒き散らす


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


				//効果音再生
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


				//振動
				if(!autoReplay)
					DI.SetEffect(multiplayindex(index),0.5f,10);

			}


		}








		if(seaver || player[index].ClientItem==2)
		{


		if(player[index].usekind==ITEMKIND_FIRE)
		{


			//効果音再生
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


			//クライアントにデータを送る
			if(seaver)
				SendItem(ITEMKIND_FIRE,false,index,player[index].usecount);

		}

		else if(player[index].usekind==ITEMKIND_SHOT)
		{

			//1だったら発射！！





			if(player[index].usecount==1)
			{

				D3DXVECTOR3 shotv=ball[wi].ball.po+(-(D3DXVECTOR3)(ball[wi].gv)*0.3f)-ball[index].ball.po;



				kemuri[KEMURI_MAX-1-index].frame=1;
				kemuri[KEMURI_MAX-1-index].framemax=30;
				kemuri[KEMURI_MAX-1-index].mv=D3DXVECTOR3(0,0,0);

				if(wi!=index)
				{



					//自分から煙も出す
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


					//ボールを発射
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
							//少し下を狙う
							ball[i].ball.mv=shotv;
							changedistance3(&ball[i].ball.mv.x,&ball[i].ball.mv.y,&ball[i].ball.mv.z,20);
							ball[i].ball.move(false,true);

							break;
						}
					}



					//自分も少し後ろに飛ぶ
					changedistance3(&shotv.x,&shotv.y,&shotv.z,3.0f);
					ball[index].ball.setmove(-shotv);


				}




				//効果音再生
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


				//クライアントにデータを送る
				if(seaver)
					SendItem(ITEMKIND_SHOT,false,index,player[index].usecount);

			}
			else
			{

				//一定間隔で効果音再生（だんだん短くなるやつ)

				bool playok=false;
				for(i=0;i<100;i++) 
				{

					if(kemuri[KEMURI_MAX-1-index].frame-30==(int)(powf((float)i,1.8f)*2))
						playok=true;
				}

				if(playok)
				{

					//効果音再生
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

				//クライアントにデータを送る
				if(seaver)
					SendItem(ITEMKIND_SHOT,false,index,player[index].usecount);


			}
			

		}

		if(player[index].usekind==ITEMKIND_GURABI)
		{


			//効果音再生
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


			//クライアントにデータを送る
			if(seaver)
				SendItem(ITEMKIND_GURABI,false,index,player[index].usecount);

		}


		}//クライアント分岐






		//アイテム効果
		if(player[index].usecount>0)
		{
			player[index].usecount--;
			if(player[index].usecount==0)
				player[index].usekind=ITEMKIND_NONE;
		}











		//アイテムを使う！！

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


				//煙を吐く
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


				//コントローラー振動
				if(!autoReplay)
					DI.SetEffect(multiplayindex(index),1,60,0);

				//効果音再生
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


				//クライアントにデータを送る
				if(seaver)
					SendItem(ITEMKIND_TAIHOU,true,index);


				break;
			case ITEMKIND_FIRE:

				player[index].usekind=player[index].itemkind;
				player[index].usecount=FIRE_COUNT;

				//コントローラー振動開始！
				if(!autoReplay)
					DI.SetEffect(multiplayindex(index),0.16f,FIRE_COUNT,0);


				//クライアントにデータを送る
				if(seaver)
					SendItem(ITEMKIND_FIRE,true,index);


				break;

			case ITEMKIND_MIZU:

				//自分の周りに水を出す！！

				//ファイアーだったら消す
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


				//効果音再生
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



				//クライアントにデータを送る
				if(seaver)
					SendItem(ITEMKIND_MIZU,true,index);


				break;



			case ITEMKIND_SHOT:

				player[index].usekind=player[index].itemkind;
				player[index].usecount=SHOT_COUNT;


				//クライアントにデータを送る
				if(seaver)
					SendItem(ITEMKIND_SHOT,true,index);

				break;


			case ITEMKIND_BOMB:


				//効果音再生
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
						ball[i].deletecount=10*60+100;//※deletecountが100になったら自動爆発
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


				//クライアントにデータを送る
				if(seaver)
					SendItem(ITEMKIND_BOMB,true,index);

				break;

			case ITEMKIND_YUUDOU:


				//効果音再生
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
						ball[i].deletecount=20*60+100;//※deletecountが100になったら自動爆発
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



						//効果音
								

						//効果音再生(鯖のみ)

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

						//クライアントにデータ送る
						if(seaver)
							SendYuudouStart(i,si);


						break;
					}
				}
				if(!autoReplay)
					DI.SetEffect(multiplayindex(index),0.8f,10);

				//クライアントにデータを送る
				if(seaver)
					SendItem(ITEMKIND_YUUDOU,true,index);


				break;



			case ITEMKIND_GURABI:



				//効果音再生
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


				//クライアントにデータを送る
				if(seaver)
					SendItem(ITEMKIND_GURABI,true,index);

				break;


			}

			player[index].itemkind=ITEMKIND_NONE;
		}
		}

		player[index].ClientItem=0;





		//アイテムをとる！！
		for(i=0;i<itemcount;i++)
		{
			if(item[i].deletecount==0)
			{
				if(D3DXVec3Length(&(item[i].po-ball[index].ball.po))<ball[index].ball.r+0.7f)
				{

					item[i].getter=index;
					item[i].deletecount=ITEM_COUNT;

					//効果音再生
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



		//カメラ操作



		//カメラのUPNextをgvに近づけて行く
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

					//角度計算
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

				//nextpoの操作(一定距離にしてから高さ調整)


				D3DXVECTOR3 disvec,provec;
				disvec=player[index].cponext-ball[index].ball.po;


				if(stagekind==SELECTGAME_STAGE)
					changedistance3(&disvec.x,&disvec.y,&disvec.z,15);
				else
					changedistance3(&disvec.x,&disvec.y,&disvec.z,5);


				//cup方向の高さを調整
				dis=dotpro3(player[index].cup.x,player[index].cup.y,player[index].cup.z,disvec.x,disvec.y,disvec.z);
				provec=player[index].cup;


				if(stagekind==SELECTGAME_STAGE)
					changedistance3(&provec.x,&provec.y,&provec.z,dis-8);//高さ調整
				else
					changedistance3(&provec.x,&provec.y,&provec.z,dis-2);//高さ調整


				disvec-=provec;

				player[index].cponext=ball[index].ball.po+disvec;

			}











			//記録をとる(Sound用)
			player[index].cpoold=player[index].cpo;

			//カメラの位置を自動的にスムーズに進む
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


			//カメラのPoをNextに近づける
			player[index].cpo.x+=(player[index].cponext.x-player[index].cpo.x)*0.1f;
			player[index].cpo.y+=(player[index].cponext.y-player[index].cpo.y)*0.1f;
			player[index].cpo.z+=(player[index].cponext.z-player[index].cpo.z)*0.1f;



			//カメラのUPをNextに近づける
			player[index].cup.x+=(player[index].cupnext.x-player[index].cup.x)*0.02f;
			player[index].cup.y+=(player[index].cupnext.y-player[index].cup.y)*0.02f;
			player[index].cup.z+=(player[index].cupnext.z-player[index].cup.z)*0.02f;
			changedistance3(&player[index].cup.x,&player[index].cup.y,&player[index].cup.z,1);









			if(info.startcounter==0 && !(replay && autoReplay) && !staff)
			{


				//カメラ回転操作(UPとPOの外積を使い、カメラを左右に動かす)

				if(buttonstate[index].rightrote || buttonstate[index].leftrote || buttonstate[index].x2!=0)
				{
					//外積を求める
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




				//(UPを使い、カメラを上下に動かす)
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




			//方向キー操作

			if(buttonstate[index].x!=0 || buttonstate[index].y!=0)
			{
				ang=angle(buttonstate[index].y,buttonstate[index].x);//Z軸方向を0度とし、上から見て時計回り

				//カメラの方向をcup軸にang度回した方向が回転方向になる



				//カメラの方向ベクトルをcup方向でつぶす

				D3DXVECTOR3 wvec=ball[index].ball.po+player[index].cup-player[index].cpo;//カメラ方向格納
				dis=dotpro3(player[index].cup.x,player[index].cup.y,player[index].cup.z,wvec.x,wvec.y,wvec.z);//カメラ方向のup成分の絶対値を格納



				//upの長さをdisにし、wvecからひく
				D3DXVECTOR3 wvec2=player[index].cup;
				changedistance3(&wvec2.x,&wvec2.y,&wvec2.z,dis);//カメラの高さを引く
				wvec-=wvec2;


				//(wvecにはカメラ方向をupでつぶしたものが格納されている)


				//回転
				D3DXMATRIX mat;
				D3DXMatrixRotationAxis(&mat,&player[index].cup,ang*rad);
				//wvecを回転
				D3DXVECTOR4 vec4;
				D3DXVec3Transform(&vec4,&wvec,&mat);

				wvec.x=vec4.x;wvec.y=vec4.y;wvec.z=vec4.z;


				//長さをスティックの倒し度で調整
				dis=distance(buttonstate[index].x/10000,buttonstate[index].y/10000)*character[player[index].charnum].speed;
				changedistance3(&wvec.x,&wvec.y,&wvec.z,dis);



				wvec+=ball[index].ball.mv;

				//再びwvecをcup方向につぶす
				dis=dotpro3(player[index].cup.x,player[index].cup.y,player[index].cup.z,wvec.x,wvec.y,wvec.z);//カメラ方向のup成分の絶対値を格納
				//upの長さをdisにし、wvecからひく
				wvec2=player[index].cup;
				changedistance3(&wvec2.x,&wvec2.y,&wvec2.z,dis);
				wvec-=wvec2;




				////力を加える位置の測定
				wvec2=player[index].cup;
				changedistance3(&wvec2.x,&wvec2.y,&wvec2.z,ball[index].ball.r);
				
				wvec.x*=mulsp;wvec.y*=mulsp;wvec.z*=mulsp;
				ball[index].ball.setpower(wvec2,wvec,1,character[player[index].charnum].power*mulpow,0,0);






			}

//			縦回転テスト
//			if(buttonstate[index].item)ball[index].ball.axis.y-=0.1f;


			//ジャンプ判定(地面にたたきつけることでジャンプを実現する)

			if(buttonstate[index].jump)//ジャンプキー
			{




				//当たった方向の合成と当たった数を格納しておき、ジャンプに使う
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



					//移動量ベクトルの、hitsum方向成分がjump以下ならjumpにする
					judc.judres.n[0]=-judc.judres.n[0];//逆ベクトルにする

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


			//カメラ食い込み防止


			judc.reset();

			judc.FieldJud(true,CAMERA_R,&(player[index].ballold),&(player[index].cpo));

			if(judc.judres.count!=0)
			{
				judc.sort();

				for(i=0;i<judc.judres.count;i++)
				{
					if(stagestate[judc.judres.kind[i]].matindex!=MATKIND_NULL)
					{
						//カメラの位置を触れた位置+ノーマル*0.01に設定!!
						player[index].cpo=judc.judres.v[i]+(D3DXVECTOR3)judc.judres.n[0]*0.01f;
						break;
					}
				}

			}



		}







	}






	static int oldrank[4];

	//順位の判定(lap+tempparが大きい順)
	int rankindex[4],worki;//ぷれいやー番号
	float rankpo[4],workpo;//位置
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










	//噴射口から吹き出る煙を作る
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


							//分散範囲計算
							dis=dis*tanf(wind[i].ang/2*rad);

							kemuri[j].mv=D3DXVECTOR3(wind[i].v.x+rnd(dis*2)-dis,wind[i].v.y+rnd(dis*2)-dis,wind[i].v.z+rnd(dis*2)-dis);

							break;
						}
					}
				}
			}
		}
	}






	//煙移動
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









	//ステージごとで、ＵＶなどを動かす

	//異空間の大砲
	taihoumesh[2].UVTranslationX[0]-=0.003f;

	index=stagemesh.TexNameIndex("背景2[2].bmp");

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

	if(stagekind==SELECTGAME_STAGE)//ステージモード
	{
		if(stagenum==21)//テクノ1
		{
			i=2;
			stagestate[i].s+=D3DXVec3Length( &stagestate[i].v2);
		}
		else if(stagenum==22)//テクノ2
		{
			i=2;
			stagestate[i].s+=D3DXVec3Length( &stagestate[i].v2);
			i++;
			stagestate[i].s+=D3DXVec3Length( &stagestate[i].v2);
			i++;
			stagestate[i].s+=D3DXVec3Length( &stagestate[i].v2);


		}
		else if(stagenum==23)//テクノ3
		{
			i=2;
			stagestate[i].s+=D3DXVec3Length( &stagestate[i].v2);
		}
		else if(stagenum==24)//テクノ4
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
						ball[i].ball.po=gun[0].p;//大砲の中に！！
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
						ball[i].ball.po=gun[1].p;//大砲の中に！！
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

			//大砲正面
			stagestate[2].s++;
			//右、右、左
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
						ball[i].ball.po=gun[2].p;//大砲の中に！！
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
						ball[i].ball.po=gun[3].p;//大砲の中に！！
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
						ball[i].ball.po=gun[4].p;//大砲の中に！！
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
						ball[i].ball.po=gun[5].p;//大砲の中に！！
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


		if(stagenum==5)//洞窟3
		{

			if(seaver)
			{
				//半径20の岩を転がす
				//stagestate[0]をカウントに使用	
				
				stagestate[0].s++;
				if(stagestate[0].s>10*60)
				{
					stagestate[0].s=0;
					//ボールを作成！

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


							//効果音再生
							

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

							//クライアントにデータを送る
							SendIwaStart(i,si);

							break;
						}
					}
				}
			}
		}
		else if(stagenum==6)//テクノ1
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


			//ゆれる鉄球の処理
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



			//ステージ固有の情報を送る
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
			//弾を撃つ

			if(seaver)
			{
				stagestate[0].s++;
				if(stagestate[0].s>=40)
				{
					//発射！！
					stagestate[0].s=0;

					for(i=0;i<BALL_MAX;i++)
					{
						if(!ball[i].enable)
						{
							ball[i].enable=true;
							ball[i].deletecount=200;
							ball[i].meshindex=BALLMESH_MINITETU;
							ball[i].ball.reset();
							ball[i].ball.po=gun[0].p;//大砲の中に！！
							ball[i].ball.r=0.5f;
							ball[i].ball.w=120;
							ball[i].matindex=MATKIND_TETU;
							ball[i].ball.move(false,true);
							break;
						}
					}

				}
			}

			//大砲の向きを変える(stagestate[1].sをしよう)
			if(gun[0].v.z>0)stagestate[1].s-=0.001f;
			else if(gun[0].v.z<0)stagestate[1].s+=0.001f;
			gun[0].v.z+=stagestate[1].s;

			//大砲マトリックス変更
			D3DXMatrixRotationY(&gun[0].mat,angle(gun[0].v.z,gun[0].v.x)*rad);
			D3DXMatrixRotationZ(&mat,-10*rad);
			gun[0].mat*=mat;
			gun[0].mat._41=gun[0].p.x;
			gun[0].mat._42=gun[0].p.y;
			gun[0].mat._43=gun[0].p.z;



			//ベルトコンベア
			stagemesh.UVTranslationY[stagemesh.TexNameIndex("konbea.jpg")]+=stagestate[2].v.z/10;



			//回転台
			for(i=3;i<10;i++)
				stagestate[i].s+=D3DXVec3Length( &stagestate[i].v2);


			//ステージ固有の情報を送る
			if(seaver)
				SendStageState();



		}
		else if(stagenum==10)
		{//異次元2
			stagemesh.UVTranslationY[stagemesh.TexNameIndex("izigen2.bmp")]+=stagestate[3].v.z/40.15f*2;
			rotation(&stagestate[4].v2.x,&stagestate[4].v2.z,1.7f);
			D3DXMatrixRotationAxis( &mat, &stagestate[4].v2, D3DXVec3Length(&stagestate[4].v2)*rad );
			stagematrix*=mat;
		}
	}








	//効果音処理(主にテクノの機械音)



	if(stagekind==SELECTGAME_STAGE)//ステージモード
	{
		if(stagenum==20)
		{
			//水の抵抗
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
			//効果音配置位置=(-58.67f,-46.26f,-3.38)

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
			//効果音配置位置=(-54.74f,-1.44f,33.56)(-112.59f,30.38f,113.14)

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
			//効果音配置位置=(63.16f,39.77f,-28.76)

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
			//効果音配置位置=(18.34f,3.6f,45.73)

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

		if(stagenum==6)//テクノ1
		{

			//効果音配置位置=(162,-38.5f,255)(271,-6.5f,156)(125.5f,13,-181.5f)

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

			//効果音配置位置=(-21.5f,-2.6f,351.5f)(-193.3f,74.5f,369.8f)

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



			//効果音配置位置=(44,28,-161)(44,28,-328)(-161.9f,-10,-117.1f)(-47,-20,-117.1f)

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




//ボール書き込み前のステージレンダリング
void FirstRender(int index)
{

	int i;
	D3DXMATRIX mat,mat2;






	if(!izigen)
	{



		if(stagekind==SELECTGAME_STAGE)//ステージモード
		{
			//ステージによってはフォグをかける


			if((stagenum<12 && stagenum/4==1) || (stagenum>12 && (stagenum-13)/4==1))
			{
				DG.Device->SetRenderState( D3DRS_FOGSTART,   FtoDW(50) );
				DG.Device->SetRenderState( D3DRS_FOGEND,     FtoDW(500) );
				DG.Device->SetRenderState( D3DRS_FOGCOLOR,  D3DXCOLOR(0.15f,0.07f,0,1) );
				DG.Device->SetRenderState( D3DRS_FOGENABLE, true);
			}


			if(stagenum==20)
			{
				///水洞
				D3DXMatrixTranslation( &mat, 0,0,0 );
				DG.Device->SetTransform( D3DTS_WORLD, &mat );

				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 0, 1);
			}
			else if(stagenum==8)
			{
				D3DXMatrixTranslation( &mat, 0,0,0 );
				DG.Device->SetTransform( D3DTS_WORLD, &mat );

				//0は通路、1は鉄柱
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 0, 1);
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 1, 1 ,ENVCHECK(&EnvTex[ENVKIND_TETUMETA]),true);

			}
			else if(stagenum==9)
			{
				D3DXMatrixTranslation( &mat, 0,0,0 );
				DG.Device->SetTransform( D3DTS_WORLD, &mat );

				//0は通路、1は鉄柱
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 0, 1);
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 1, 1 ,ENVCHECK(&EnvTex[ENVKIND_TETUMETA]),true);

			}
			else if(stagenum==10)
			{
				D3DXMatrixTranslation( &mat, 0,0,0 );
				DG.Device->SetTransform( D3DTS_WORLD, &mat );

				//0は通路、1は鉄柱
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 0, 1);
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 1, 1 ,ENVCHECK(&EnvTex[ENVKIND_TETUMETA]),true);

			}
			else if(stagenum==11)
			{
				D3DXMatrixTranslation( &mat, 0,0,0 );
				DG.Device->SetTransform( D3DTS_WORLD, &mat );

				//0は通路、1は鉄柱
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 0, 1);
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 1, 1 ,ENVCHECK(&EnvTex[ENVKIND_TETUMETA]),true);

			}

			else if(stagenum==21)
			{

				D3DXMatrixTranslation( &mat, 0,0,0 );
				DG.Device->SetTransform( D3DTS_WORLD, &mat );

				//0は通路、1は鉄柱、2は回転盤
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

				//0は通路、1は縦回転、2はローラー1、3はローラー2
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

				//0は通路、1は金属、2は回転
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

				//0は通路、1はX軸回転、2はY軸回転
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


			if(stagenum==3)//洞窟1
			{
				//0は地上、1は洞窟、2は石、3は鉄格子
				//カメラの位置で判断する
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
			else if(stagenum==4)//洞窟2
			{
				//カメラの位置で判断する
				D3DXMatrixTranslation( &mat, 0,0,0 );
				DG.Device->SetTransform( D3DTS_WORLD, &mat );

				if(player[index].cpo.z<-29 && player[index].cpo.x<-64)
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 0, 1);
				if(player[index].cpo.z>-202 || (player[index].cpo.z>-380 && player[index].cpo.x<-70))
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 1, 1);
				if((player[index].cpo.z<60 && player[index].cpo.x>-128) || player[index].cpo.z<-412)
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 2, 1);
			}
			else if(stagenum==5)//洞窟3
			{
				//0は銅像、1は地上、2は通路（入り口付近）、3は通路（銅像付近),4は岩が転がってくる部屋
				//5は洞窟のある部屋、6は落ちる部屋、7はいつでもレンダリング

				D3DXMatrixTranslation( &mat, 0,0,0 );
				DG.Device->SetTransform( D3DTS_WORLD, &mat );

				//地上付近にいたら地上のレンダリング
				if(player[index].cpo.y>-42 || (player[index].cpo.y>-120 && 
					((player[index].cpo.x<35 && player[index].cpo.x>-35) || (player[index].cpo.z<35 && player[index].cpo.z>-35))))
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 1, 1);

				//地下1のレンダリング
				//半径440(15.27,-74.95)
				if(distance(player[index].cpo.x-15.27f,player[index].cpo.z+74.95f)<440)
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 2, 1);

				//岩が転がってる部屋のレンダリング
				if(player[index].cpo.z>2.5f*player[index].cpo.x+480)
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 4, 1);

				//地下2のレンダリング
				//半径600(-731.2,-463.7)
				if(distance(player[index].cpo.x+731.2f,player[index].cpo.z+463.7f)<600)
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 3, 1);

				//銅像と部屋のレンダリング
				//半径230(-302.5,-560)
				if(distance(player[index].cpo.x+282.5f,player[index].cpo.z+560)<230)
				{
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 5, 1);
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 0, 1,ENVCHECK(&EnvTex[ENVKIND_META]),true);
				}

				//落ちるとこのレンダリング
				//半径390(63.85,-538.26)
				if(distance(player[index].cpo.x-63.85f,player[index].cpo.z+538.26f)<390)
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 6, 1);

				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 7, 1);

			}
			else if(stagenum==6)//テクノ1
			{


				D3DXMatrixTranslation( &mat, 0,0,0 );
				DG.Device->SetTransform( D3DTS_WORLD, &mat );

				//0は通路、1はスタートの道、2はラストの円の筒、10は鉄の棒
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 0, 1);
				if(player[index].cpo.x<154)
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 2, 1);
				if(player[index].cpo.x<29 || player[index].cpo.z>209)
				{
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 1, 1);
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 10, 1,ENVCHECK(&EnvTex[ENVKIND_TETUMETA]),true);

					//揺れる鉄球の柱を書く


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
			{//テクノ2

				D3DXMatrixTranslation( &mat, 0,0,0 );
				DG.Device->SetTransform( D3DTS_WORLD, &mat );

				//0は通路、1は1つ目の部屋、2は2つ目の部屋
				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 0, 1);
				if(player[index].cpo.x<129 || player[index].cpo.z>169)
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 1, 1);
				if(distance(player[index].cpo.x+170.39f,player[index].cpo.z)<200)//半径200
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
			{//テクノ3

				D3DXMatrixTranslation( &mat, 0,0,0 );
				DG.Device->SetTransform( D3DTS_WORLD, &mat );

				//0は全体,1～7は回転台,8は最初のポール,9は途中のポール,10は最後の筒

				stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 0, 1);

				//筒
				if(player[index].cpo.x<24 && player[index].cpo.x>-139 && player[index].cpo.z>-205)
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 10, 1);

				//最初のポール
				if(player[index].cpo.y<21.7f && player[index].cpo.z>-60)
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 8, 1 ,ENVCHECK(&EnvTex[ENVKIND_TETUMETA]),true);

				//途中のポール
				if(player[index].cpo.x>-27.5f && player[index].cpo.y>21.7f)
					stagemesh.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy, 9, 1 ,ENVCHECK(&EnvTex[ENVKIND_TETUMETA]),true);

				//部屋の中
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
	else//異次元
	{
		//背景を書く！





		//異次元コース
		DG.Device->SetRenderState( D3DRS_ALPHABLENDENABLE, false );

		if(stagekind==SELECTGAME_STAGE)
		{
			//周りの線
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





	//アイテムレンダリング

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


//ボール書き込み後のステージレンダリング
void SecondRender(int index)
{


	int i;
	D3DXMATRIX mat,mat2;







	if(izigen)
	{






		//ステージレンダリング


		DG.Device->SetRenderState( D3DRS_LIGHTING, false );
		DG.Device->SetRenderState( D3DRS_ZWRITEENABLE,  FALSE );
		DG.Device->SetRenderState( D3DRS_SRCBLEND,  D3DBLEND_ONE );
		DG.Device->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_ONE );
		DG.Device->SetRenderState( D3DRS_CULLMODE,  D3DCULL_NONE );
		DG.Device->SetRenderState( D3DRS_BLENDOP, D3DBLENDOP_ADD );


		//まだここでは有効にしない
		DG.Device->SetRenderState( D3DRS_FOGSTART,   FtoDW(100) );
		DG.Device->SetRenderState( D3DRS_FOGEND,     FtoDW(1000) );
		DG.Device->SetRenderState( D3DRS_FOGCOLOR,  0 );





		DG.Device->SetRenderState( D3DRS_FOGENABLE, true);


		//大砲とか

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













		//異次元コース

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
					//回転マトリックス適用
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









		//設定を戻す
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
		///水洞
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


	//ステージをレンダー




	for(index=loopstart;index<=loopend;index++)
	{


		//カメラと画面サイズの設定

		D3DXMatrixLookAtLH( &matView,	&player[index].cpo,
										&player[index].ballold,
										&player[index].cup);


		//if(index==2)//3P
		//for(i=0;i<BALL_MAX;i++)
		//	if(ball[i].meshindex==BALLMESH_YUUDOU && ball[i].enable==true)//こいつのカメラにしてしまう！！
		//	{
		//		D3DXMatrixLookAtLH( &matView,	&(ball[i].ball.po-((D3DXVECTOR3)ball[i].ball.mv*3)+D3DXVECTOR3(0,1,0)),
		//										&(ball[i].ball.po+((D3DXVECTOR3)ball[i].ball.mv*10)),
		//										&D3DXVECTOR3(0,1,0));
		//		break;
		//	}


		DG.Device->SetTransform( D3DTS_VIEW, &matView );


		if(stagekind!=SELECTGAME_MULTIPLAY)
			DG.Device->SetViewport( &player[index].vp );





		//ステージとボールの位置によりライティングの設定
		//if((stagekind==SELECTGAME_STAGE && stagenum/5==2) || (stagekind!=SELECTGAME_STAGE && stagenum/3==2))
		//	ambient=0x88888888;//テクノコースは環境光強め
		//else
			ambient=0x77777777;
		DG.Device->SetRenderState( D3DRS_AMBIENT, ambient );



		//異次元コースのとき、ステージは跡で書く





		////1回目のレンダリング
		FirstRender(index);






		DG.Device->SetRenderState( D3DRS_AMBIENT, ambient );



		//異次元コースのとき、影は書かない

		if(Setting.ShadeEnable && !izigen)
		{


		//陰をステンシルバッファに書く
		//{



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




			for(i=0;i<BALL_MAX;i++)
			{
				if(ball[i].enable)
				{

					//陰のマトリックスセット
					D3DXMatrixScaling( &matWorld, ball[i].ball.r,ball[i].ball.r,ball[i].ball.r );
					D3DXMatrixRotationZ( &matWorld2, rad*30 );
					matWorld*=matWorld2;
					D3DXMatrixTranslation( &matWorld2, ball[i].ball.po.x,ball[i].ball.po.y,ball[i].ball.po.z );
					matWorld*=matWorld2;
					DG.Device->SetTransform( D3DTS_WORLD, &matWorld );


					//表を書く
					DG.Device->SetRenderState( D3DRS_CULLMODE,   D3DCULL_CCW );
					DG.Device->SetRenderState( D3DRS_STENCILPASS,      D3DSTENCILOP_INCR );
					shade.Render( DG.Device, &player[index].cpo, &player[index].ballold, fovy);


					//裏側を書く
					DG.Device->SetRenderState( D3DRS_CULLMODE,   D3DCULL_CW );
					DG.Device->SetRenderState( D3DRS_STENCILPASS, D3DSTENCILOP_DECR );
					shade.Render(DG.Device, &player[index].cpo, &player[index].ballold, fovy);

				}

			}



			// 設定復元
			DG.Device->SetRenderState( D3DRS_CULLMODE,  D3DCULL_CCW );
			DG.Device->SetRenderState( D3DRS_ZWRITEENABLE,     TRUE );
			DG.Device->SetRenderState( D3DRS_STENCILENABLE,    FALSE );
			DG.Device->SetRenderState( D3DRS_SRCBLEND,  D3DBLEND_SRCALPHA );
			DG.Device->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );

		//}



		//影を実際のバッファに書く
		//{

			//前処理
			DG.Device->SetRenderState( D3DRS_ZENABLE,          FALSE );
			DG.Device->SetRenderState( D3DRS_ZWRITEENABLE,     FALSE );
			DG.Device->SetRenderState( D3DRS_STENCILENABLE,    TRUE );
			DG.Device->SetRenderState( D3DRS_STENCILREF,  0x1 );
			DG.Device->SetRenderState( D3DRS_STENCILFUNC, D3DCMP_LESSEQUAL );
			DG.Device->SetRenderState( D3DRS_STENCILPASS, D3DSTENCILOP_KEEP );


			//ただの板を画面いっぱいにレンダー
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


			// 設定復元
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







		//ボールのレンダリング(遠いボールから書き込む)

		int ballsortindex[BALL_MAX],sortworki,ballindex;
		float ballsortdis[BALL_MAX],sortworkf,ballalpha;

		//データ読み込み
		for(i=0;i<BALL_MAX;i++)
		{
			ballsortindex[i]=i;
			if(ball[i].enable || (i==BALL_MAX-1 && Ghost && !replayend && GetClear() && ReadReplayFile && !replay))
			{
				ballsortdis[i]=distance3(ball[i].ball.po.x-player[index].cpo.x,
					ball[i].ball.po.y-player[index].cpo.y,ball[i].ball.po.z-player[index].cpo.z);
			}
		}

		//インデックスの並び替え
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



		//プレイヤーボールの反射テクスチャを調べる
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
					//外に出ているときはステージ1の反射をさせる
					envindex[i]=-1;
				}
				else if(stagenum/3==2)
				{
					if(player[i].charnum==4)//次郎
						envindex[i]=ENVKIND_TETUMETA;
					else
						envindex[i]=ENVKIND_TETU;
				}
				else if(stagenum/3==3)
					envindex[i]=ENVKIND_IZIGEN;
			}
		}



		//並び替えたようにレンダリング
		for(i=0;i<BALL_MAX;i++)
		{
			ballindex=ballsortindex[i];
			if(ball[ballindex].enable || (ballindex==BALL_MAX-1 && Ghost && !replayend && GetClear() && ReadReplayFile && !replay && !staff))
			{
				//透明度の変更
				if(ball[ballindex].deletecount!=0 && ball[ballindex].deletecount<50 && ball[ballindex].deletecount>-50)
				{
					if(ball[ballindex].deletecount>0)
						ballalpha=ball[ballindex].deletecount/50.0f;
					else if(ball[ballindex].deletecount<0)
						ballalpha=1+ball[ballindex].deletecount/50.0f;
					for(j=0;j<ballmesh[ball[ballindex].meshindex].MaterialCount;j++)
						ballmesh[ball[ballindex].meshindex].Material[j].Diffuse.a=ballalpha;

				}


				//ゴーストの透明化
				if(ballindex==BALL_MAX-1)
					for(j=0;j<ballmesh[ball[ballindex].meshindex].MaterialCount;j++)
						ballmesh[ball[ballindex].meshindex].Material[j].Diffuse.a*=0.4f;

				DG.Device->SetTransform( D3DTS_WORLD, &ball[ballindex].ball.mat );

				if(ball[ballindex].meshindex<5 && ballindex!=BALL_MAX-1)//キャラクターなら
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



				//透明度を元に戻す
				//if(ball[ballindex].deletecount!=0 && ball[ballindex].deletecount<50 && ball[ballindex].deletecount>-50)
				{
					for(j=0;j<ballmesh[ball[ballindex].meshindex].MaterialCount;j++)
						ballmesh[ball[ballindex].meshindex].Material[j].Diffuse.a=1;
				}
			}

		}





		//ボールも書き終えたことだし爆風を書く！！


		DG.Device->SetRenderState( D3DRS_LIGHTING, true );
		DG.Device->LightEnable (0,false);
		DG.Device->SetRenderState( D3DRS_AMBIENT, 0xffffffff );

		for(i=0;i<BOMB_MAX;i++)
		{
			if(Bomb[i].sizemax!=0)
			{
				//レンダリング
				float alp=(Bomb[i].sizemax-Bomb[i].size)/Bomb[i].sizemax;

				//透明度変更
				for(j=0;j<bombmesh.MaterialCount;j++)
					bombmesh.Material[j].Diffuse.a=alp;

				//サイズ変更(カリング用)
				for(j=0;j<bombmesh.MeshCount;j++)
					bombmesh.MeshR[j]=Bomb[i].size;

				//マトリックス設定
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


		////2回目のレンダリング
		SecondRender(index);



		float dis;


		//煙レンダリング設定

		DG.Device->SetRenderState( D3DRS_LIGHTING, true );
		DG.Device->LightEnable (0,false);
		DG.Device->SetRenderState( D3DRS_AMBIENT, 0xffffffff );


		DG.Device->SetRenderState( D3DRS_ZWRITEENABLE,     FALSE );


		////煙を描く


		//ビルボード用回転マトリックスの計算
		D3DXVECTOR3 cameramuki=-(ball[index].ball.po+player[index].cup-player[index].cpo);//カメラへの向きベクトル
		D3DXMATRIX kemurimat;
		D3DXMatrixRotationX( &kemurimat, angle(distance(cameramuki.x,cameramuki.z),cameramuki.y)*rad );
		D3DXMatrixRotationY( &matWorld, (angle(cameramuki.z,cameramuki.x)+180)*rad );
		kemurimat*=matWorld;


		float par;//現在のフレームのパーセントを求める時に使う

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

					if(kemuri[i].kind==6)//ショット!!
						DG.Device->SetRenderState( D3DRS_ZENABLE,     false );

					if(kemuri[i].kind==3)//異次元!!
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






		//設定を戻す
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
