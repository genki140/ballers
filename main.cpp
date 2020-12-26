#include "main.h"



bool mutexcheck()
{
	HANDLE hMutex;
	hMutex = OpenMutex(MUTEX_ALL_ACCESS, false, "BallerMutex");
	if( hMutex != 0 )
	{
		CloseHandle(hMutex);
		return false;
	}
	hMutex = CreateMutex( NULL, true, "BallerMutex");
	return true;
}


//メインプログラム
int WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR CmdLine, INT CmdShow)
{

//	checkfile("data/save/Replay/stage/0.lzh");


	if(mutexcheck()==false)
	{
		MessageBox(NULL,"多重起動はできません","設定",MB_OK);
		return false;
	}




	int i;

	//自分のパス取得
	char mename[MAX_PATH];
	GetModuleFileName(NULL,mename,MAX_PATH-1);

	char path[MAX_PATH];
	strcpy(path,mename);
	//パスの最後から/を探す
	int len=(int)strlen(path);
	for(i=0;i<len;i++)
		if(path[i]=='\\')
			path[i]='/';
	for(i=len-1;i>=0;i--)
	{
		if(path[i]=='/')
		{
			path[i]='\0';
			break;
		}
	}

	//正しいパスをセット
	SetCurrentDirectory(path);



	lhalib = LoadLibrary("data/dll/unlha32.dll");
	if (lhalib == NULL){
        MessageBox(hWnd, "必要なライブラリファイルが見つかりません", "エラー", MB_OK);
        return false;
	}

	//関数作成
	Unlha = (UNLHA)GetProcAddress(lhalib,"Unlha");



//	Unlha(NULL, "e Data/Save/Replay/Stage/0.lzh Data/Save/Replay/ RTemp -n1 -gm1", "" ,0);



	////ランジェネを初期化する前にパスワード用の数値(文字列化)を取得し、チェックする
	//int randam=(int)rnd(65536);
	//char str[100];
	//sprintf(str,"%d",randam);
	//MessageBox(NULL,str,"パスワード",MB_OK);







    // DirectX8 のチェック
    HINSTANCE hDll = LoadLibrary( "d3d8.dll" );
    if ( hDll == NULL )
    {
        MessageBox(hWnd, "DirectX8が見つかりません", "エラー", MB_OK);
        return false;
    }
    FreeLibrary( hDll );

	//設定ファイル読み込み
	if(!LoadSetting())
	{
		MessageBox(hWnd, "設定ファイルの読み込みに失敗しました", "エラー", MB_OK);
		return false;
	}

	//クリアデータ読み込み
	if(!LoadClear())
	{
		MessageBox(hWnd, "セーブファイルの読み込みに失敗しました", "エラー", MB_OK);
		return false;
	}

	//IPとPORTの回避
	KeepIP=Setting.IPKeep;
	KeepPort=Setting.PortKeep;

	//Direct3D作成
	if(!DG.CreateD3D())
	{
	    Cleanup();
		MessageBox(hWnd, "DirectGraphicの初期化に失敗しました", "エラー", MB_OK);
		return false;
	}





    // ウィンドウクラス作成
	wc.cbSize		= sizeof(WNDCLASSEX);
	wc.style		= 0;
	wc.lpfnWndProc	= MsgProc;
	wc.cbClsExtra	= 0;
	wc.cbWndExtra	= 0;
	wc.hInstance	= hInst;
	wc.hIcon		= LoadIcon(hInst,MAKEINTRESOURCE(IDI_ICON2));
	wc.hCursor		= LoadCursor(NULL,IDC_ARROW);
	wc.hbrBackground= (HBRUSH)(COLOR_WINDOW+2);
	wc.lpszMenuName = NULL;
	wc.lpszClassName= AppName;
	wc.hIconSm		= LoadIcon(hInst,MAKEINTRESOURCE(IDI_ICON2));

	RegisterClassEx( &wc );


    // ウィンドウ作成
	if(Setting.FullScreen)
	{
		hWnd = CreateWindow(	AppName, AppCaption, 
								WS_BORDER, 0, 0, 0, 0,
								NULL, NULL, wc.hInstance, NULL );

		DG.Adapter.Windowed =false;
		if(Setting.BufferFormat==32)
			DG.Adapter.BackBufferFormat=D3DFMT_X8R8G8B8;
		else
			DG.Adapter.BackBufferFormat=D3DFMT_R5G6B5;

		//周波数固定
		DG.Adapter.FullScreen_RefreshRateInHz=60;
	}
	else
	{
		D3DDISPLAYMODE d3ddm;
		if(!DG.GetDisplayMode( &d3ddm ))
		{
			MessageBox(hWnd, "ディスプレイモードの取得に失敗しました", "エラー", MB_OK);
			return false;
		}

		int formwidth=Setting.FormWidth+GetSystemMetrics(SM_CXSIZEFRAME)*2;
		int formheight=Setting.FormHeight+GetSystemMetrics(SM_CYSIZEFRAME)*2+GetSystemMetrics(SM_CYCAPTION);

		hWnd = CreateWindow(	AppName, AppCaption, 
								WS_BORDER | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, 
								d3ddm.Width/2-formwidth/2, 
								d3ddm.Height/2-formheight/2,
								formwidth, formheight,
								NULL, NULL, wc.hInstance, NULL );


		DG.Adapter.Windowed =true;
		DG.Adapter.BackBufferFormat = d3ddm.Format;
	}


	// ウィンドウを表示
    ShowWindow( hWnd, CmdShow );
    UpdateWindow( hWnd );





	DG.Adapter.BackBufferWidth =Setting.BufferWidth;
	DG.Adapter.BackBufferHeight =Setting.BufferHeight;

	if(Setting.ShadeEnable)
	{
		//ステンシルを使う
		DG.Adapter.AutoDepthStencilFormat=D3DFMT_D24S8;
	}
	else
	{
		//ステンシルは使わない
		DG.Adapter.AutoDepthStencilFormat=D3DFMT_D16;
	}

	//アンチエイリアスの設定
	DG.Adapter.MultiSampleType=(D3DMULTISAMPLE_TYPE)(Setting.Anti>0 ? Setting.Anti+1 : 0);




	//Input設定
	bool VibEnables[4];
	for(i=0;i<4;i++)
		VibEnables[i]=keynum[i+1].VibEnable;

	if(DI.Create( hWnd, Setting.FullScreen ,VibEnables, 4) == false)
	{
		Cleanup();
		MessageBox(hWnd, "DirectInputの初期化に失敗しました", "エラー", MB_OK);
		return false;
	}

	if(SoundSetting() == false)
	{
		Cleanup();
		MessageBox(hWnd, "DirectSoundの初期化に失敗しました", "エラー", MB_OK);
		return false;
	}

	if(ShowSetting(0) == false)//とりあえずオープニング曲読み込みでテスト
	{
		Cleanup();
		MessageBox(hWnd, "DirectShowの初期化に失敗しました", "エラー", MB_OK);
		return false;
	}

	if(DG.Create( hWnd ) == false)
	{
	    Cleanup();
		MessageBox(hWnd, "DirectGraphicDeviceの初期化に失敗しました", "エラー", MB_OK);
		return false;
	}


	//その他のセッティング
	if(OtherSetting()==false)
	{
	    Cleanup();
		MessageBox(hWnd, "ゲームの設定に失敗しました", "エラー", MB_OK);
		return false;		
	}


	if(GraphicSetting() == false)
	{
	    Cleanup();
		MessageBox(hWnd, "DirectGraphicオブジェクトの作成に失敗しました", "エラー", MB_OK);
		return false;
	}

    // メッセージループ
    MSG msg;
    ZeroMemory( &msg, sizeof(msg) );
    while( end==false )
    {
        if( PeekMessage( &msg, NULL, 0U, 0U, PM_REMOVE ) )
        {
            TranslateMessage( &msg );
            DispatchMessage( &msg );
        }
	    else
		{
			static bool DeviceLost=false;



			if(DG.GetDevice()==false)// || FullChange)//デバイスが消滅していたら！
			{
				DeviceLost=true;
			}
			else if(DeviceLost==true)
			{
				////デバイスが復帰していたら
				DeviceLost=false;

				GraphicRelease();

				DG.Release();

				if(!DG.Create(hWnd))
				{
					Cleanup();
					MessageBox(hWnd,"再設定に失敗しました","エラー",MB_OK);
					return false;
				}

				if(!GraphicSetting())
				{
					Cleanup();
					MessageBox(hWnd,"再設定に失敗しました","エラー",MB_OK);
					return false;
				}

				if(gamemode==GAMEMODE_GAME)
				{
					//ステージ再呼び出し
					if(!StageMeshLoad())
					{
						Cleanup();
						MessageBox(hWnd,"再設定に失敗しました","エラー",MB_OK);
						return false;
					}
					if(!InfoStageSetting())
					{
						Cleanup();
						MessageBox(hWnd,"再設定に失敗しました","エラー",MB_OK);
						return false;
					}

				}

			}
			else
			{


				//フレームレート調整しながらMoveとRenderを行う

				static float framecount=100;
				static long int startclock=clock(),movestartclock;
				int fps=60;

				//とりあえず動かす
				movestartclock=clock();
				if(!Move())
				{
					Cleanup();
					MessageBox(hWnd,"エラーが発生しました","エラー",MB_OK);
					return false;
				}

				//動かしたあと、もうすでに遅れているようならどうしようもないので、レンダリングして初期化
				if (fps*( (clock()-movestartclock) / 1000.0f) > 1)
				{
					if(!Render())
					{
						Cleanup();
						MessageBox(hWnd,"エラーが発生しました","エラー",MB_OK);
						return false;
					}
					framecount=1;
					startclock=clock();
				}
				else
				{
					//時間が間に合っていたら
					if(fps*( (clock()-startclock) / 1000.0f) < framecount+5)//+5してるのは、多少の遅れは許すため
					{
						//ウィンドウモードであれば時間まで待ってレンダリング
//						if(!Setting.FullScreen)
							while( fps*( (clock()-startclock) / 1000.0f) < framecount );
						if(!Render())
						{
							Cleanup();
							MessageBox(hWnd,"エラーが発生しました","エラー",MB_OK);
							return false;
						}
					}
				}

				//カウンタをインクリ
				framecount++;


			}
		}
	}

	//IPとPORTの復元
	if(!Setting.IPKeep)
		Setting.IPKeep=KeepIP;
	if(!Setting.PortKeep)
		Setting.PortKeep=KeepPort;

	if(!SaveSetting())
		MessageBox(hWnd,"設定の保存時にエラーが発生しました","エラー",MB_OK);
	if(!SaveClear())
		MessageBox(hWnd,"クリア情報の保存時にエラーが発生しました","エラー",MB_OK);

	//後片付け
    Cleanup();

	return true;
}






//ルート、チェック、アイテム情報をセーブするために使用する変数
//FILE *rfile;


bool Move()
{
	////□ボタン
	//bool rootsave=false;
	//bool checksave=false;
	//bool itemsave=false;
	//char rootfile[]="data/data/corce/root/5";
	//char checkfile[]="data/data/corce/check/5";
	//char itemfile[]="data/data/corce/item/12";

	//static bool saisyonohitokoma=true;
	//if(rootsave && saisyonohitokoma)
	//{
	//	rfile=fopen(rootfile,"w");
	//	saisyonohitokoma=false;
	//}
	//if(checksave && saisyonohitokoma)
	//{
	//	rfile=fopen(checkfile,"w");
	//	saisyonohitokoma=false;
	//}
	//if(itemsave && saisyonohitokoma)
	//{
	//	rfile=fopen(itemfile,"w");
	//	saisyonohitokoma=false;
	//}


	int i;

	//インプットデータ取得

	DI.Acquire();
	DI.GetData();
	DI.Move();


	//----------------------------入力関係----------------------------



	int DIloopend=4;
	if(stagekind==SELECTGAME_MULTIPLAY && gamemode==GAMEMODE_GAME) DIloopend=1;

	//DIから状態を取得し、編集する(軸の範囲は0～1)
	for(i=0;i<DIloopend;i++)
	{
		//キーボード
		if(i==0 && Setting.Key1p)
		{
			buttonstate[i].ok=keynum[0].ok!=-1					? DI.key.down[keynum[0].ok] : false;
			buttonstate[i].cancel=keynum[0].cancel!=-1			? DI.key.down[keynum[0].cancel] : false;
			buttonstate[i].start=keynum[0].start!=-1			? DI.key.down[keynum[0].start] : false;
			buttonstate[i].startpress=keynum[0].start!=-1		? DI.key.press[keynum[0].start] : false;
			buttonstate[i].rightrote=keynum[0].rightrote!=-1	? DI.key.press[keynum[0].rightrote] : false;
			buttonstate[i].leftrote=keynum[0].leftrote!=-1		? DI.key.press[keynum[0].leftrote] : false;
			buttonstate[i].jump=keynum[0].jump!=-1				? DI.key.down[keynum[0].jump] : false;
			buttonstate[i].item=keynum[0].item!=-1				? DI.key.down[keynum[0].item] : false;

			buttonstate[i].bx=	(keynum[0].right!=-1	? DI.key.down[keynum[0].right] : false) || 
								(keynum[0].left!=-1		? DI.key.down[keynum[0].left] : false);
			buttonstate[i].by=	(keynum[0].down!=-1		? DI.key.down[keynum[0].down] : false) || 
								(keynum[0].up!=-1		? DI.key.down[keynum[0].up] : false);

			buttonstate[i].x=0;
			buttonstate[i].y=0;
			buttonstate[i].x2=0;
			buttonstate[i].y2=0;

			if(keynum[0].right!=-1 ? DI.key.press[keynum[0].right] : false)
				buttonstate[i].x=10000;
			else if(keynum[0].left!=-1 ? DI.key.press[keynum[0].left] : false)
				buttonstate[i].x=-10000;
			if(keynum[0].up!=-1 ? DI.key.press[keynum[0].up] : false)
				buttonstate[i].y=10000;
			else if(keynum[0].down!=-1 ? DI.key.press[keynum[0].down] : false)
				buttonstate[i].y=-10000;

			if(keynum[0].right2!=-1 ? DI.key.press[keynum[0].right2] : false)
				buttonstate[i].x2=10000;
			else if(keynum[0].left2!=-1 ? DI.key.press[keynum[0].left2] : false)
				buttonstate[i].x2=-10000;
			if(keynum[0].up2!=-1 ? DI.key.press[keynum[0].up2] : false)
				buttonstate[i].y2=10000;
			else if(keynum[0].down2!=-1 ? DI.key.press[keynum[0].down2] : false)
				buttonstate[i].y2=-10000;

			//斜めのとき長さが変わってしまうので調整
			if(distance(buttonstate[i].x,buttonstate[i].y)>10000)
				changedistance(&buttonstate[i].x,&buttonstate[i].y,10000);
			if(distance(buttonstate[i].x2,buttonstate[i].y2)>10000)
				changedistance(&buttonstate[i].x2,&buttonstate[i].y2,10000);
		}
		else
		{
			buttonstate[i].ok=keynum[i-Setting.Key1p+1].ok!=-1 ? DI.joy[i-Setting.Key1p].down[keynum[i-Setting.Key1p+1].ok] : false;
			buttonstate[i].cancel=keynum[i-Setting.Key1p+1].cancel!=-1 ? DI.joy[i-Setting.Key1p].down[keynum[i-Setting.Key1p+1].cancel] : false;
			buttonstate[i].start=keynum[i-Setting.Key1p+1].start!=-1 ? DI.joy[i-Setting.Key1p].down[keynum[i-Setting.Key1p+1].start] : false;
			buttonstate[i].startpress=keynum[i-Setting.Key1p+1].start!=-1 ? DI.joy[i-Setting.Key1p].press[keynum[i-Setting.Key1p+1].start] : false;
			buttonstate[i].rightrote=keynum[i-Setting.Key1p+1].rightrote!=-1 ? DI.joy[i-Setting.Key1p].press[keynum[i-Setting.Key1p+1].rightrote] : false;
			buttonstate[i].leftrote=keynum[i-Setting.Key1p+1].leftrote!=-1 ? DI.joy[i-Setting.Key1p].press[keynum[i-Setting.Key1p+1].leftrote] : false;
			buttonstate[i].jump=keynum[i-Setting.Key1p+1].jump!=-1 ? DI.joy[i-Setting.Key1p].down[keynum[i-Setting.Key1p+1].jump] : false;
			buttonstate[i].item=keynum[i-Setting.Key1p+1].item!=-1 ? DI.joy[i-Setting.Key1p].down[keynum[i-Setting.Key1p+1].item] : false;

			buttonstate[i].x=keynum[i-Setting.Key1p+1].axis!=-1 ? (float)DI.joy[i-Setting.Key1p].x[keynum[i-Setting.Key1p+1].axis] : 0;
			buttonstate[i].y=keynum[i-Setting.Key1p+1].axis!=-1 ? (float)DI.joy[i-Setting.Key1p].y[keynum[i-Setting.Key1p+1].axis] : 0;
			buttonstate[i].x2=keynum[i-Setting.Key1p+1].axis2!=-1 ? (float)DI.joy[i-Setting.Key1p].x[keynum[i-Setting.Key1p+1].axis2] : 0;
			buttonstate[i].y2=keynum[i-Setting.Key1p+1].axis2!=-1 ? (float)DI.joy[i-Setting.Key1p].y[keynum[i-Setting.Key1p+1].axis2] : 0;



			//範囲内なら0にする
			if(buttonstate[i].x<keynum[i-Setting.Key1p+1].axisover*10000 && buttonstate[i].x>-keynum[i-Setting.Key1p+1].axisover*10000)
				buttonstate[i].x=0;
			if(buttonstate[i].y<keynum[i-Setting.Key1p+1].axisover*10000 && buttonstate[i].y>-keynum[i-Setting.Key1p+1].axisover*10000)
				buttonstate[i].y=0;

			if(buttonstate[i].x2<keynum[i-Setting.Key1p+1].axisover2*10000 && buttonstate[i].x2>-keynum[i-Setting.Key1p+1].axisover2*10000)
				buttonstate[i].x2=0;
			if(buttonstate[i].y2<keynum[i-Setting.Key1p+1].axisover2*10000 && buttonstate[i].y2>-keynum[i-Setting.Key1p+1].axisover2*10000)
				buttonstate[i].y2=0;



			//範囲外のときの微調整
			if(buttonstate[i].x>0)
			{
				buttonstate[i].x-=keynum[i-Setting.Key1p+1].axisover*10000;
				buttonstate[i].x*=1/(1-keynum[i-Setting.Key1p+1].axisover);
			}
			else if(buttonstate[i].x<0)
			{
				buttonstate[i].x+=keynum[i-Setting.Key1p+1].axisover*10000;
				buttonstate[i].x*=1/(1-keynum[i-Setting.Key1p+1].axisover);
			}
			if(buttonstate[i].y>0)
			{
				buttonstate[i].y-=keynum[i-Setting.Key1p+1].axisover*10000;
				buttonstate[i].y*=1/(1-keynum[i-Setting.Key1p+1].axisover);
			}
			else if(buttonstate[i].y<0)
			{
				buttonstate[i].y+=keynum[i-Setting.Key1p+1].axisover*10000;
				buttonstate[i].y*=1/(1-keynum[i-Setting.Key1p+1].axisover);
			}




			//斜めのとき長さが変わってしまうので調整
			if(distance(buttonstate[i].x,buttonstate[i].y)>10000)
				changedistance(&buttonstate[i].x,&buttonstate[i].y,10000);
			if(distance(buttonstate[i].x2,buttonstate[i].y2)>10000)
				changedistance(&buttonstate[i].x2,&buttonstate[i].y2,10000);




			//前と比較し、bx,byのせってい
			if(	(DI.joy[i-Setting.Key1p].Keepx[keynum[i-Setting.Key1p+1].axis]<keynum[i-Setting.Key1p+1].axisover*10000 && buttonstate[i].x>0) || 
				(DI.joy[i-Setting.Key1p].Keepx[keynum[i-Setting.Key1p+1].axis]>-keynum[i-Setting.Key1p+1].axisover*10000 && buttonstate[i].x<0))
				buttonstate[i].bx=true;
			else
				buttonstate[i].bx=false;

			if(	(DI.joy[i-Setting.Key1p].Keepy[keynum[i-Setting.Key1p+1].axis]<keynum[i-Setting.Key1p+1].axisover*10000 && buttonstate[i].y>0) ||
				(DI.joy[i-Setting.Key1p].Keepy[keynum[i-Setting.Key1p+1].axis]>-keynum[i-Setting.Key1p+1].axisover*10000 && buttonstate[i].y<0))
				buttonstate[i].by=true;
			else
				buttonstate[i].by=false;

		}
	}

	//全体のチェック！！

	buttonstate[4].ok=false;
	buttonstate[4].cancel=false;
	buttonstate[4].start=false;
	buttonstate[4].startpress=false;
	buttonstate[4].x=0;
	buttonstate[4].y=0;

	for(i=0;i<4;i++)
	{
		buttonstate[4].ok |= buttonstate[i].ok;
		buttonstate[4].cancel |= buttonstate[i].cancel;
		buttonstate[4].start |= buttonstate[i].start;
		buttonstate[4].startpress |= buttonstate[i].startpress;
		if(buttonstate[4].x==0 && buttonstate[i].bx==true)
			buttonstate[4].x = buttonstate[i].x;
		if(buttonstate[4].y==0 && buttonstate[i].by==true)
			buttonstate[4].y = buttonstate[i].y;
	}



	//----------------------------------------------------------------




	//セレクト動かす
	SelectMove();

	//全体のフェードアウト進行
	feed[4].Move();




	if(gamemode==GAMEMODE_PROJECT)
	{
		ProjectMove();
		if( pro.frame==30 )
		{
			sd.Project->Play( 0, 0 );
		}
		if(pro.frame>=350)
		{
			ProjectReset();
			gamemode=GAMEMODE_TITLE;
			pMediaControl->Run();
			title.frame=0;
		}
	}
	else if(gamemode==GAMEMODE_TITLE)
	{

		if(title.frame<590)
		{
			//フェードアウト
			if((buttonstate[4].ok || buttonstate[4].start) && feed[4].count==0)
				feed[4].Start(FEEDMODE_WHITEOUT,30);
		}



		//フェードアウト状態のままだと困るので元に戻す
		if(title.frame==0)
		{
			for(i=0;i<5;i++)
				feed[i].End();
		}


		//タイトル画面を動かす
		TitleMove();

		

		//一定時間操作がないときはリプレイに入る
		if(title.frame>=710)
		{
			if(sel.enable)
			{
				autoReplay=false;
				autoReplayCount=0;
			}
			else
			{
				if(autoReplayCount<20*60)//20秒
				{
					autoReplayCount++;
				}
				else
				{

					//ステージをランダムに選ぶ
					static int oldreplaystage=-1;//前と同じのは選ばない！！
					if(clearstage==1) oldreplaystage=-1;
					int replaystagelist[STAGE_MAX+12],replaystagecount=0;
					bool replaystagestage[STAGE_MAX+12];
					for(i=0;i<STAGE_MAX+12;i++)
					{
						if(hTime[i]!=0)
						{
							if(i!=oldreplaystage)
							{

								replaystagelist[replaystagecount]=i;
								replaystagestage[replaystagecount]=(i<STAGE_MAX);
								replaystagecount++;

							}
						}
					}

					if(replaystagecount!=0)
					{

						//入る！
						autoReplayCount=0;
						feed[4].Start(FEEDMODE_WHITEOUT,60);
						autoReplay=true;
						replay=true;
						playercount=1;

						int stagenumrnd=(int)rnd((float)replaystagecount);

						oldreplaystage=stagenumrnd;


						stagenum=replaystagelist[stagenumrnd];


						if(replaystagestage[stagenumrnd])
						{
							stagekind=SELECTGAME_STAGE;
						}
						else
						{
							stagekind=SELECTGAME_VARSUS;
							stagenum-=STAGE_MAX;
						}
					}

				}
			}
		}


		//セレクト画面呼び出し
		if(gamemode==GAMEMODE_TITLE && title.frame>=720 && (buttonstate[4].ok || buttonstate[4].start) && sel.enable==false && feed[4].count==0)
		{
			CallSelect(CALLMODE_GAMESELECT);
		}
		
		//セレクト画面での操作
		if(sel.enable==true && feed[4].count==0)
		{



			//キャラクターセレクトのときは、キャンセル以外のキーは選択中のプレイヤーしか操作できない
			int buttonindex=4;

//			if(sel.nowparentsindex==CAPTION_CHARSELECT && stagekind==SELECTGAME_VARSUS && playercount!=1)
//				buttonindex=sel.caption[CAPTION_CHARSELECT].child[0]-CAPTION_P1;

			if(buttonstate[buttonindex].y>0)
				changeselect(false,false);
			if(buttonstate[buttonindex].y<0)
				changeselect(true,false);

			if(buttonstate[buttonindex].x<0)
				changeselect(false);
			if(buttonstate[buttonindex].x>0)
				changeselect(true);


			if(buttonstate[buttonindex].ok || buttonstate[buttonindex].start)
			{
				setokcancel(true);

				
				if(sel.nowparentsindex==CAPTION_INFO)
				{
					//効果音再生
					if(!Setting.Seaver) Sendokcancel(multiplayreadymy);
				}


			}

			if(buttonstate[4].cancel)
				setokcancel(false);





			int len;

			if(sel.frame==0)
			{
				if(sel.nowparentsindex==CAPTION_IP)
				{
					for(i=0;i<10;i++)
					{
						len=(int)strlen(Setting.ip);
						if(DI.key.down[DIK_1+i] && len<15)
						{
							if(i==9)//0
							{
								Setting.ip[len]='0';
								Setting.ip[len+1]='\0';
							}
							else
							{
								Setting.ip[len]='1'+i;
								Setting.ip[len+1]='\0';
							}
						}
					}

					len=(int)strlen(Setting.ip);
					if(DI.key.down[DIK_PERIOD] && len<15)
					{
						Setting.ip[len]='.';
						Setting.ip[len+1]='\0';
					}

					len=(int)strlen(Setting.ip);
					if(DI.key.down[DIK_BACKSPACE] && len>0)
					{
						Setting.ip[len-1]='\0';
					}

				}
				if(sel.nowparentsindex==CAPTION_PORT)
				{



					for(i=0;i<10;i++)
					{
						len=(int)strlen(Setting.port);
						if(DI.key.down[DIK_1+i] && len<6)
						{
							if(i==9)//0
							{
								Setting.port[len]='0';
								Setting.port[len+1]='\0';
							}
							else
							{
								Setting.port[len]='1'+i;
								Setting.port[len+1]='\0';
							}
						}
					}

					len=(int)strlen(Setting.port);
					if(DI.key.down[DIK_BACKSPACE] && len>0)
					{
						Setting.port[len-1]='\0';
					}


				}
			}

			
			//クライアントでエラーでたら
			//サーバーに一応信号を送っておく
			if(!Setting.Seaver && sel.nowparentsindex==CAPTION_ERROR && sel.frame==1)//frameが0になる前に処理する
				SendPlayerOut();



		}



		if(sel.nowparentsindex==CAPTION_INFO)
		{
			//インフォメーション表示関係
			for(i=0;i<playercount;i++)
			{
				if(i==0)
					sel.caption[CAPTION_INFO].child[i]=CAPTION_CHAR1+player[i].charnum;
				else
					if(fromID[i-1]!=-1)
						sel.caption[CAPTION_INFO].child[i]=CAPTION_CHAR1+player[i].charnum;
				else
					sel.caption[CAPTION_INFO].child[i]=CAPTION_BAR;
			}

			sel.caption[CAPTION_INFO].childcount=playercount+1;
			if(multiplayreadymy)
				sel.caption[CAPTION_INFO].child[playercount]=CAPTION_HENKOU;
			else
				sel.caption[CAPTION_INFO].child[playercount]=CAPTION_KETTEI;
			sel.nowselectindex=playercount;



			//参加しているプレイヤー全員がちゃんと接続しているかを定期的に調べる(10秒間応答がない場合はダウンとする)

//				CheckPlayer();



			//ゲームへ移動できるかを調べる
			bool ok=true;
			if(sel.frame==0 && multiplayreadymy)
			{
				for(i=0;i<playercount-1;i++)
					if(multiplayready[i]==false)
						ok=false;


				//とりあえずテスト用にokにする
//					ok=true;player[1].charnum=0;


				if(ok)
				{
					//ゲームへ移動
					SendGameStart();
					MultiPlayStart=true;//これによりセレクトが動く

					//スタートカウント開始同期用変数の初期化
					for(i=0;i<playercount-1;i++)
						multiplaystartcount[i]=false;
				}
			}


		}
		



		//フェードアウト時の処理（ゲーム終了、ゲームへ移動、など）
		if(feed[4].count==feed[4].countend-1 && (stagekind!=SELECTGAME_MULTIPLAY || Error==CAPTION_NONE))
		{
			sel.frame=0;

			if(feed[4].mode==FEEDMODE_BLACKOUT)
			{
				if(stagekind==SELECTGAME_END)//終了
					end=true;
			}
			else if(feed[4].mode==FEEDMODE_WHITEOUT)
			{





				//にんずう設定
				if(stagekind==SELECTGAME_STAGE)//ステージ
				{
					playercount=1;
					//キャラクター強制設定
					player[0].charnum=5;//ステージ用キャラクター
				}


				//失敗したらスタートしない
				//if(!StageSetting() || !InfoStageSetting())
				//{
				//	//戻る処
				//	feed[4].Start(FEEDMODE_WHITEIN,60);
				//	CallSelect(CALLMODE_STAGESELECT,0);
				//	return true;
				//}

				if(!StageSetting())return false;
				if(!InfoStageSetting())return false;

				gamemode=GAMEMODE_GAME;

				//人数分セッティング
				for(i=0;i<playercount;i++)
				{

					//レンダリング領域の設定
					if(i<playercount)
					{
						if(playercount==1)
						{
							player[i].vp.X=0;
							player[i].vp.Y=0;
							player[i].vp.Width=DG.Adapter.BackBufferWidth;
							player[i].vp.Height=DG.Adapter.BackBufferHeight;
							player[i].vp.MinZ=0;
							player[i].vp.MaxZ=1;
						}
						else if(playercount==2)
						{

							if(i==0)
							{
								player[i].vp.X=0;
								player[i].vp.Y=0;
								player[i].vp.Width=DG.Adapter.BackBufferWidth/2;
								player[i].vp.Height=DG.Adapter.BackBufferHeight/2;
								player[i].vp.MinZ=0;
								player[i].vp.MaxZ=1;
							}
							else if(i==1)
							{
								player[i].vp.X=DG.Adapter.BackBufferWidth/2;
								player[i].vp.Y=0;
								player[i].vp.Width=DG.Adapter.BackBufferWidth/2;
								player[i].vp.Height=DG.Adapter.BackBufferHeight/2;
								player[i].vp.MinZ=0;
								player[i].vp.MaxZ=1;
							}

						}
						else if(playercount==3)
						{

							if(i==0)
							{
								player[i].vp.X=0;
								player[i].vp.Y=0;
								player[i].vp.Width=DG.Adapter.BackBufferWidth/2;
								player[i].vp.Height=DG.Adapter.BackBufferHeight/2;
								player[i].vp.MinZ=0;
								player[i].vp.MaxZ=1;
							}
							else if(i==1)
							{
								player[i].vp.X=DG.Adapter.BackBufferWidth/2;
								player[i].vp.Y=0;
								player[i].vp.Width=DG.Adapter.BackBufferWidth/2;
								player[i].vp.Height=DG.Adapter.BackBufferHeight/2;
								player[i].vp.MinZ=0;
								player[i].vp.MaxZ=1;
							}
							else if(i==2)
							{
								player[i].vp.X=0;
								player[i].vp.Y=DG.Adapter.BackBufferHeight/2;
								player[i].vp.Width=DG.Adapter.BackBufferWidth/2;
								player[i].vp.Height=DG.Adapter.BackBufferHeight/2;
								player[i].vp.MinZ=0;
								player[i].vp.MaxZ=1;
							}

						}
						else if(playercount==4)
						{

							if(i==0)
							{
								player[i].vp.X=0;
								player[i].vp.Y=0;
								player[i].vp.Width=DG.Adapter.BackBufferWidth/2;
								player[i].vp.Height=DG.Adapter.BackBufferHeight/2;
								player[i].vp.MinZ=0;
								player[i].vp.MaxZ=1;
							}
							else if(i==1)
							{
								player[i].vp.X=DG.Adapter.BackBufferWidth/2;
								player[i].vp.Y=0;
								player[i].vp.Width=DG.Adapter.BackBufferWidth/2;
								player[i].vp.Height=DG.Adapter.BackBufferHeight/2;
								player[i].vp.MinZ=0;
								player[i].vp.MaxZ=1;
							}
							else if(i==2)
							{
								player[i].vp.X=0;
								player[i].vp.Y=DG.Adapter.BackBufferHeight/2;
								player[i].vp.Width=DG.Adapter.BackBufferWidth/2;
								player[i].vp.Height=DG.Adapter.BackBufferHeight/2;
								player[i].vp.MinZ=0;
								player[i].vp.MaxZ=1;
							}
							else if(i==3)
							{
								player[i].vp.X=DG.Adapter.BackBufferWidth/2;
								player[i].vp.Y=DG.Adapter.BackBufferHeight/2;
								player[i].vp.Width=DG.Adapter.BackBufferWidth/2;
								player[i].vp.Height=DG.Adapter.BackBufferHeight/2;
								player[i].vp.MinZ=0;
								player[i].vp.MaxZ=1;
							}
						}

					}


				}



				//曲チェンジ
				if(stagekind==SELECTGAME_STAGE)
				{
					if(stagenum==12 || stagenum==29)
						ShowSetting(1);
					else if(stagenum<12)
						ShowSetting(stagenum/4+2);
					else
						ShowSetting((stagenum-13)/4+2);
					pMediaControl->Run();
				}
				else
				{
					ShowSetting(stagenum%3+6);
				}

				//次のためにカウントを戻す
				autoReplayCount=0;

				ReplayStart();



				feed[4].Start(FEEDMODE_WHITEIN,60);


				//ゲームスタートできるよ～　　と鯖に送る
				Buffer[0]='\0';
				SetMsg(Buffer,myID,NETMSG_READY);
				sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&addr, (int)sizeof(addr));




			}





		}


	}
	else if(gamemode==GAMEMODE_GAME)//ゲーム画面
	{

		bool gameok=true;


		if(stagekind==SELECTGAME_MULTIPLAY)
		{
			if(Setting.Seaver)
			{



				//全員からのメッセージが一定時間内に来ない場合はこなかったプレイヤーを消してスタート

				bool ok=true;
				for(i=0;i<playercount-1;i++)
				{
					if(multiplaystartcount[i]==false)
					{
						ok=false;
						break;
					}
				}


				if(gamestartlimit<10*60 && !MultiPlayCountStart)
				{
					gameok=false;
					gamestartlimit++;
					feed[4].Start(FEEDMODE_WHITEIN,60);
				}
				else if(!MultiPlayCountStart)
				{
					//応答がない！！(来てるプレイヤーにだけ送って続行！)
					ok=true;

				}
				else ok=false;


				if(ok)
				{
					//接続されている全員に開始のメッセージを送る
					SendCountStart();
					//そして自分もスタート
					MultiPlayCountStart=true;

					//音楽再生
					ShowSetting(stagenum%3+6);

				}




			}
			else
			{




				//クライアントは鯖からのメッセージを待つ
				if(gamestartlimit<10*60 && !MultiPlayCountStart)
				{
					gameok=false;
					gamestartlimit++;
					feed[4].Start(FEEDMODE_WHITEIN,60);
				}
				else if(!MultiPlayCountStart)
				{
					//応答がない！！
					//セレクト画面に戻る
					feed[4].Start(FEEDMODE_WHITEIN,60);
					CallSelect(CALLMODE_INFO,0);
					Error=CAPTION_SETUZOKUERROR;
					gamemode=GAMEMODE_TITLE;
				}



			}
		}

		if(gameok)//ゲームに入れていたら・・
		{


			//※最後には消す


			//if(rootsave)
			//{

			//	//ルート記録モード
			//	static float sumdis=0;
			//	static D3DXVECTOR3 oldpo;
			//	float dis;
			//	
			//	if(DI.joy[0].down[3])//□ボタン
			//	{
			//		dis=D3DXVec3Length(&(ball[0].ball.po-oldpo));
			//		sumdis+=dis;
			//		fprintf(rfile,"%f,%f,%f,%f,%f\n",ball[0].ball.po.x,ball[0].ball.po.y,ball[0].ball.po.z,dis,sumdis);
			//		oldpo=ball[0].ball.po;
			//	}
			//}

			//if(checksave)
			//{
			//	//チェック記録モード
			//	if(DI.joy[0].down[3])//□ボタン
			//	{
			//		fprintf(rfile,"%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n",player[0].temppar,
			//				ball[0].ball.po.x,ball[0].ball.po.y,ball[0].ball.po.z,
			//				ball[0].gv.x,ball[0].gv.y,ball[0].gv.z,player[0].cpo.x,player[0].cpo.y,player[0].cpo.z,
			//				player[0].cup.x,player[0].cup.y,player[0].cup.z);
			//	}
			//}


			//if(itemsave)
			//{
			//	//アイテム記録モード
			//	if(DI.joy[0].down[3])//□ボタン
			//	{
			//		fprintf(rfile,"%f,%f,%f\n",ball[0].ball.po.x,ball[0].ball.po.y,ball[0].ball.po.z);
			//	}
			//}





			if(stagekind==SELECTGAME_MULTIPLAY && !Setting.Seaver)
			{
				//マルチプレイモードでクライアントのときは入力データをサーバーへ送る
				sprintf(Buffer,"%d,%d,%f,%f",buttonstate[0].item,buttonstate[0].jump,buttonstate[0].x,buttonstate[0].y);
				SetMsg(Buffer,myID,NETMSG_INPUT);
				sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&addr, (int)sizeof(addr));


				//送ったら入力情報の消去！！(カメラ移動系は消去しない)
				//残しておくものだけでも、multiplayernumの操作としてコピーしておく

				buttonstate[multiplayernum].rightrote=buttonstate[0].rightrote;
				buttonstate[multiplayernum].leftrote=buttonstate[0].leftrote;
				buttonstate[multiplayernum].x2=buttonstate[0].x2;
				buttonstate[multiplayernum].y2=buttonstate[0].y2;
				buttonstate[multiplayernum].jump=buttonstate[0].jump;
				buttonstate[0].jump=false;
				buttonstate[0].item=false;
				buttonstate[0].rightrote=false;
				buttonstate[0].leftrote=false;
				buttonstate[0].x=0;
				buttonstate[0].y=0;
				buttonstate[0].x2=0;
				buttonstate[0].y2=0;


				//ついでにカメラ情報も送っておく
				sprintf(Buffer,"%f,%f,%f,%f,%f,%f",
					player[multiplayernum].cponext.x,player[multiplayernum].cponext.y,player[multiplayernum].cponext.z,
					player[multiplayernum].cupnext.x,player[multiplayernum].cupnext.y,player[multiplayernum].cupnext.z);
				SetMsg(Buffer,myID,NETMSG_CAMERA);
				sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&addr, (int)sizeof(addr));

			}



			//シングルプレイなら全ての入力デバイスを使用する
			if(playercount==1 && !Setting.only1p)
			{
				for(i=1;i<4;i++)
				{
					buttonstate[0].ok |= buttonstate[i].ok;
					buttonstate[0].cancel |= buttonstate[i].cancel;
					buttonstate[0].jump |= buttonstate[i].jump;
					buttonstate[0].item |= buttonstate[i].item;
					buttonstate[0].start |= buttonstate[i].start;
					buttonstate[0].startpress |= buttonstate[i].startpress;
					buttonstate[0].leftrote |= buttonstate[i].leftrote;
					buttonstate[0].rightrote |= buttonstate[i].rightrote;
					buttonstate[0].bx |= buttonstate[i].bx;
					buttonstate[0].by |= buttonstate[i].by;
					buttonstate[0].x+=buttonstate[i].x;
					buttonstate[0].y+=buttonstate[i].y;
					buttonstate[0].x2+=buttonstate[i].x2;
					buttonstate[0].y2+=buttonstate[i].y2;
				}

				if(distance(buttonstate[0].x,buttonstate[0].y)>10000)
					changedistance(&buttonstate[0].x,&buttonstate[0].y,10000);
				if(distance(buttonstate[0].x2,buttonstate[0].y2)>10000)
					changedistance(&buttonstate[0].x2,&buttonstate[0].y2,10000);
			}


			//ストップ


			if(stagekind==SELECTGAME_MULTIPLAY || autoReplay)
			{
				static int stoppress=0;
//				if(buttonstate[4].startpress)
//					stoppress++;
//				else
//					stoppress=0;
//				if(stoppress>=60 && ((stagekind==SELECTGAME_MULTIPLAY && feed[multiplayernum].count==0) || 
//									(autoReplay && feed[4].count==0)))
				if((buttonstate[4].start || buttonstate[4].ok) && ((stagekind==SELECTGAME_MULTIPLAY && feed[multiplayernum].count==0) || 
									(autoReplay && feed[4].count==0)))
				{

//			MessageBox(NULL,"","",MB_OK);

					startend=true;

					stoppress=0;
					//終了処理
					feed[4].Start(FEEDMODE_BLACKOUT,60);

					if(stagekind==SELECTGAME_MULTIPLAY)
						player[multiplayernum].goal=true;
					else
						player[0].goal=true;

//					autoReplay=false;

					//ゲームの終了を伝える
					if(Setting.Seaver)
						SendEndGame();

				}
			}
			else if(info.startcounter==0)
			{

				for(i=0;i<playercount;i++)
				{
					if(buttonstate[i].start==true && sel.enable==false)
					{
//						MessageBox(NULL,"","",MB_OK);
						stopplayer=i;
						if(CallSelect(CALLMODE_GAME))
							autostop=false;
					}
				}

			}


			if(sel.enable==true)
			{
//				if(playercount==1 && !Setting.only1p)
//					stopplayer=0;

				if(buttonstate[stopplayer].y>0 && (buttonstate[stopplayer].by==true || stopplayer==4))
					changeselect(false,false);
				if(buttonstate[stopplayer].y<0 && (buttonstate[stopplayer].by==true || stopplayer==4))
					changeselect(true,false);

				if(buttonstate[stopplayer].x<0 && (buttonstate[stopplayer].bx==true || stopplayer==4))
					changeselect(false);
				if(buttonstate[stopplayer].x>0 && (buttonstate[stopplayer].bx==true || stopplayer==4))
					changeselect(true);


				if(buttonstate[stopplayer].cancel || buttonstate[stopplayer].start)
					setokcancel(false);
				if(buttonstate[stopplayer].ok)
					setokcancel(true);

			}


			
			if(sel.enable==false || autostop==true)
			{

				//------さまざまな更新処理------

				//フェード更新
				for(i=0;i<4;i++)
					feed[i].Move();

				//ステージ更新
				StageMove();

				//情報更新
				InfoMove();



				//タイマーを動かす
				if(info.startcounter==0 && 
					((stagekind==SELECTGAME_STAGE && player[0].InputEnable==true) || 
					(stagekind==SELECTGAME_VARSUS && player[0].lap<=lap)))//stagekind==SELECTGAME_STAGE)
				{
					if(Time<rTime || stagekind==SELECTGAME_VARSUS)
					{
						//タイマーを動かす
						Time++;

						if(Time%60==1 && Time>rTime-10*60 && stagekind==SELECTGAME_STAGE)
							info.timeframe=30;
					}
					else//時間切れ
					{
						player[0].InputEnable=false;
						autostop=true;
						CallSelect(CALLMODE_GAME,60);
					}
				}


				//マルチプレイ時、リプレイ時のクリア(強制終了)で戻る処理（黒くフェードアウトされたときに作動！)
				if((stagekind==SELECTGAME_MULTIPLAY || replay) && player[multiplayernum].goal && feed[4].count==feed[4].countend-1 && feed[4].mode==FEEDMODE_BLACKOUT)
				{
					if(stagekind==SELECTGAME_MULTIPLAY)
					{
						//終了！
						multiplayreadymy=false;
						for(i=0;i<3;i++)
							multiplayready[i]=false;
						feed[4].Start(FEEDMODE_BLACKIN,60);
						sel.enable=false;
						CallSelect(CALLMODE_INFO);
						//曲チェンジ(オープニング)
						ShowSetting(0);
						pMediaControl->Run();
						gamemode=GAMEMODE_TITLE;
					}
					else
					{
						ReplayEnd();
						if(autoReplay && !startend)
						{
							feed[4].End();
							pMediaControl->Stop();
							ShowSetting(0);
							gamemode=GAMEMODE_PROJECT;
							pro.frame=0;
							feed[4].Start(FEEDMODE_BLACKIN,60);
						}
						else
						{
							startend=false;
//							MessageBox(NULL,"","",MB_OK);
							feed[4].End();
							pMediaControl->Stop();
							ShowSetting(0);
							pMediaControl->Run();
							gamemode=GAMEMODE_TITLE;
							feed[4].Start(FEEDMODE_BLACKIN,60);
						}
					}

//					MessageBox(NULL,"","",MB_OK);
					//効果音消し
					SoundReset();

				}




				//------リプレイ系処理-------

				//ゴーストボタン
				if(playercount==1 && buttonstate[0].item==true && GetClear() && !replay && !staff)
					Ghost=!Ghost;

//				char replaystr[200];
				if(playercount==1)
				{
					if(!replayend)
					{


						////一度文字列ｲﾋして戻す(文字列ｲﾋやその逆などをしたときに出る誤差をなくすため)
						//sprintf(replaystr,"%f,%f,%f,%f,%f,%f,%f,%f,%f\n",
						//	ball[0].ball.po.x,ball[0].ball.po.y,ball[0].ball.po.z,
						//	ball[0].ball.mv.x,ball[0].ball.mv.y,ball[0].ball.mv.z,
						//	ball[0].ball.axis.x,ball[0].ball.axis.y,ball[0].ball.axis.z);
						//sscanf(replaystr,"%f,%f,%f,%f,%f,%f,%f,%f,%f",
						//	&ball[0].ball.po.x,&ball[0].ball.po.y,&ball[0].ball.po.z,
						//	&ball[0].ball.mv.x,&ball[0].ball.mv.y,&ball[0].ball.mv.z,
						//	&ball[0].ball.axis.x,&ball[0].ball.axis.y,&ball[0].ball.axis.z);



						//リプレイ
						if(replay || staff)
						{
							//読み込み
							readreplaydata();
							Ghost=false;
						}
						else
						{
							writereplaydata();

							if(GetClear() && ReadReplayFile)
							{
								//読み込み(ゴースト)
								if(!readreplayGhostdata())
								{
									replayend=true;
								}
							}

							////スタッフロールリプレイ再生
							//if(staff)
							//{
							//	//ゴーストの位置へ移動
							//	ball[0].ball.axis=ball[BALL_MAX-1].ball.axis;
							//	ball[0].ball.mat=ball[BALL_MAX-1].ball.mat;
							//	ball[0].ball.mv=ball[BALL_MAX-1].ball.mv;
							//	ball[0].ball.po=ball[BALL_MAX-1].ball.po;
							//	ball[0].ball.rotamat=ball[BALL_MAX-1].ball.rotamat;
							//	ball[0].ball.r=ball[BALL_MAX-1].ball.r;
							//	ball[0].ball.w=ball[BALL_MAX-1].ball.w;
							//	Ghost=false;
							//}

						}
					}

				}
			}







			//いろんな処理が終わったので情報をクライアントに転送！！

			if(stagekind==SELECTGAME_MULTIPLAY && Setting.Seaver)
			{
				//マルチプレイモードでサーバーのときは世界のデータをクライアントへ送る


				char TempStr[1000];


				//次にプレイヤー全員同じデータを転送

				//NETMSG_BALL

				sprintf(Buffer,"%d,",gameframe);
				for(i=0;i<BALL_MAX;i++)
				{

					if(ball[i].enable)//有効なもののみ送る
					{
						sprintf(TempStr,"1,%d,%d,%d,%d,%d,%d,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,",
									ball[i].info[0],ball[i].info[1],ball[i].nojudindex,ball[i].deletecount,
									ball[i].meshindex,ball[i].matindex,
									ball[i].gv.x,ball[i].gv.y,ball[i].gv.z,ball[i].ball.w,ball[i].ball.r,
									ball[i].ball.po.x,ball[i].ball.po.y,ball[i].ball.po.z,
									ball[i].ball.mv.x,ball[i].ball.mv.y,ball[i].ball.mv.z,
									ball[i].ball.axis.x,ball[i].ball.axis.y,ball[i].ball.axis.z);
						strcat(Buffer,TempStr);
					}
					else
						strcat(Buffer,"0,");
				}



				SetMsg(Buffer,myID,NETMSG_BALL);

				for(i=0;i<playercount-1;i++)
					sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));







				//アイテム情報(全員のかかってるアイテムの状態なども)

				sprintf(Buffer,"%d,",gameframe);

				for(i=0;i<itemcount;i++)
				{
					sprintf(TempStr,"%d,%d,",item[i].kind,item[i].getter);
					strcat(Buffer,TempStr);
				}

				for(i=0;i<playercount;i++)
				{
					sprintf(TempStr,"%d,%d,",
								player[i].usekind,player[i].usecount);
					strcat(Buffer,TempStr);
				}

				SetMsg(Buffer,myID,NETMSG_ITEM);


				for(i=0;i<playercount-1;i++)
				{
					sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
				}



				////次にプレイヤーごとに違うデータを転送



				//インフォ(ランクとかラップとかアイテムとかフェードアウトとか)
				
				for(i=0;i<playercount-1;i++)
				{
					sprintf(Buffer,"%d,%d,%d,%d,%d,%d",player[i+1].lap,player[i+1].rank,
						feed[i+1].count,feed[i+1].countend,feed[i+1].mode,player[i+1].itemkind);

					SetMsg(Buffer,myID,NETMSG_INFO);

					sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
				}
			}





			if(sel.enable==true && sel.frame==1 && sel.back==true)//セレクトのframeが0になる前に処理する
			{

				sel.enable=false;


				if(sel.caption[sel.nowparentsindex].child[sel.nowselectindex]==CAPTION_RETRY)
				{
					if(stagekind!=SELECTGAME_STAGE)
						pMediaControl->Stop();

					ReplayEnd();
					ReplayStart();

					if(!StageSetting()) return false;
					if(!InfoStageSetting()) return false;
					feed[4].Start(FEEDMODE_WHITEIN,40);	

					//効果音消し
					SoundReset();

				}
				else if(sel.caption[sel.nowparentsindex].child[sel.nowselectindex]==CAPTION_NEXT)
				{
					stagenum++;

					//曲チェンジ
					if(stagekind==SELECTGAME_STAGE)
					{
						if(stagekind==SELECTGAME_STAGE)
						{
							if(stagenum==12 || stagenum==29)
								ShowSetting(1);
							else if(stagenum<12)
							{
								if(stagenum%4==0)
									ShowSetting(stagenum/4+2);
							}
							else
							{
								if((stagenum-13)%4==0)
									ShowSetting((stagenum-13)/4+2);
							}
							pMediaControl->Run();
						}
						else
						{
							ShowSetting(stagenum%3+6);
						}
					}
					else
					{
						pMediaControl->Stop();
						ShowSetting(stagenum%3+6);
					}
					
					ReplayEnd();
					ReplayStart();

					if(!StageSetting()) return false;
					if(!InfoStageSetting()) return false;
					feed[4].Start(FEEDMODE_WHITEIN,40);

					//効果音消し
					SoundReset();
				}
				else
				{
					//曲チェンジ(オープニング)
					ShowSetting(0);
					pMediaControl->Run();
					gamemode=GAMEMODE_TITLE;
					//効果音消し
					SoundReset();
				}


				if(sel.caption[sel.nowparentsindex].child[sel.nowselectindex]==CAPTION_BACKSTAGESELECT)
				{
					CallSelect(CALLMODE_STAGESELECT);
					feed[4].Start(FEEDMODE_WHITEIN,40);
					ReplayEnd();
					//効果音消し
					SoundReset();
				}
				else if(sel.caption[sel.nowparentsindex].child[sel.nowselectindex]==CAPTION_BACKCHARSELECT)
				{
					CallSelect(CALLMODE_CHARSELECT);
					feed[4].Start(FEEDMODE_WHITEIN,40);
					ReplayEnd();
					//効果音消し
					SoundReset();
				}
				else if(sel.caption[sel.nowparentsindex].child[sel.nowselectindex]==CAPTION_OWARU)
				{
					feed[4].Start(FEEDMODE_BLACKIN,60);
					ReplayEnd();
					//効果音消し
					SoundReset();
				}




			}



		}
	}



	//バーサス時、カウント終了後に音楽を再生する処理
	if(info.startcounter==1 && stagekind!=SELECTGAME_STAGE)
	{ 
		pMediaControl->Stop();

		//巻き戻し
		LONGLONG llPos = 0;
		pMediaSeeking->SetPositions(&llPos, AM_SEEKING_AbsolutePositioning,
									&llPos, AM_SEEKING_NoPositioning);
		pMediaControl->Run();
	}

	//マルチプレイ時のクライアントの処理(INPUT関係)

	if(stagekind==SELECTGAME_MULTIPLAY && Setting.Seaver)
	{

		for(i=DIloopend;i<4;i++)
		{
			//情報更新！！
			buttonstate[i].jump=false;
			buttonstate[i].item=false;
		}

	}




	//音楽ループ再生(終了しちゃったらもう一度再生！)
	long evCode, param1, param2;
	if(SUCCEEDED(pEvent->GetEvent(&evCode, &param1, &param2, 0)))
	{
		pEvent->FreeEventParams(evCode, param1, param2);
		if ((EC_COMPLETE == evCode))
		{
			pMediaControl->Stop();

			//巻き戻し
			LONGLONG llPos = 0;
			pMediaSeeking->SetPositions(&llPos, AM_SEEKING_AbsolutePositioning,
										&llPos, AM_SEEKING_NoPositioning);
			pMediaControl->Run();
		} 
	}





	//3Dサウンド情報更新
	if(play3d)
	{


		int index=0;
		if(stagekind==SELECTGAME_MULTIPLAY) index=multiplayernum;


		D3DXVECTOR3 frontv;
		D3DXVec3Normalize(&frontv,&(ball[index].ball.po-player[index].cpo));

		sd.ListenerParam.vPosition = player[index].cpo;
		sd.ListenerParam.vVelocity = (D3DXVECTOR3)(player[index].cpo-player[index].cpoold)*60;
		sd.ListenerParam.vOrientFront = frontv;
		sd.ListenerParam.vOrientTop = player[index].cup;

		if( sd.Listener )
			sd.Listener->SetAllParameters( &sd.ListenerParam, DS3D_DEFERRED );

		//計算
		static int CommitCount=0;
		CommitCount++;
		if(CommitCount>=Setting.SoundCommit)
		{
			CommitCount=0;
			sd.Listener->CommitDeferredSettings();
		}

	}



	//ESCキーで終了する処理
	if(DI.key.up[DIK_ESCAPE])
	{
		//if(rootsave || checksave || itemsave)
		//	fclose(rfile);
		end=true;
	}






	////クリアステージ変動
	//if(DI.key.up[DIK_Q])
	//	if(clearstage>0)clearstage--;
	//if(DI.key.up[DIK_W])
	//	if(clearstage<STAGE_MAX)clearstage++;



	return true;
}














bool Render()
{



//	if(gamemode==GAMEMODE_GAME && stagekind==SELECTGAME_MULTIPLAY && Setting.Seaver)
//		return true;


	D3DXMATRIX matWorld,matWorld2;



	//カメラ設定
	D3DXMATRIX matView;
	D3DXMATRIX matProj;
	D3DXMatrixPerspectiveFovLH( &matProj, D3DX_PI/3, (float)(4.0/3.0), CAMERA_R/2, 10000.0f );//CAMERA_R/2は適当
	DG.Device->SetTransform( D3DTS_PROJECTION, &matProj );






	//-----------------------初期設定------------------------



	//アルファ設定
	DG.Device->SetRenderState (D3DRS_ALPHABLENDENABLE, true);
	DG.Device->SetRenderState( D3DRS_SRCBLEND,  D3DBLEND_SRCALPHA );
	DG.Device->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );



	//テクスチャフィルタリング設定
	if(Setting.FiltarEnable)
	{
		DG.Device->SetTextureStageState( 0, D3DTSS_MINFILTER, D3DTEXF_LINEAR );
		DG.Device->SetTextureStageState( 0, D3DTSS_MAGFILTER, D3DTEXF_LINEAR );
		DG.Device->SetTextureStageState( 1, D3DTSS_MINFILTER, D3DTEXF_LINEAR );
		DG.Device->SetTextureStageState( 1, D3DTSS_MAGFILTER, D3DTEXF_LINEAR );
		DG.Device->SetTextureStageState( 2, D3DTSS_MINFILTER, D3DTEXF_LINEAR );
		DG.Device->SetTextureStageState( 2, D3DTSS_MAGFILTER, D3DTEXF_LINEAR );
		DG.Device->SetTextureStageState( 3, D3DTSS_MINFILTER, D3DTEXF_LINEAR );
		DG.Device->SetTextureStageState( 3, D3DTSS_MAGFILTER, D3DTEXF_LINEAR );
		DG.Device->SetTextureStageState( 4, D3DTSS_MINFILTER, D3DTEXF_LINEAR );
		DG.Device->SetTextureStageState( 4, D3DTSS_MAGFILTER, D3DTEXF_LINEAR );
	}
	else
	{
		DG.Device->SetTextureStageState( 0, D3DTSS_MINFILTER, D3DTEXF_POINT );
		DG.Device->SetTextureStageState( 0, D3DTSS_MAGFILTER, D3DTEXF_POINT );
		DG.Device->SetTextureStageState( 1, D3DTSS_MINFILTER, D3DTEXF_POINT );
		DG.Device->SetTextureStageState( 1, D3DTSS_MAGFILTER, D3DTEXF_POINT );
		DG.Device->SetTextureStageState( 2, D3DTSS_MINFILTER, D3DTEXF_POINT );
		DG.Device->SetTextureStageState( 2, D3DTSS_MAGFILTER, D3DTEXF_POINT );
		DG.Device->SetTextureStageState( 3, D3DTSS_MINFILTER, D3DTEXF_POINT );
		DG.Device->SetTextureStageState( 3, D3DTSS_MAGFILTER, D3DTEXF_POINT );
		DG.Device->SetTextureStageState( 4, D3DTSS_MINFILTER, D3DTEXF_POINT );
		DG.Device->SetTextureStageState( 4, D3DTSS_MAGFILTER, D3DTEXF_POINT );
	}


	//フォグ設定
	DG.Device->SetRenderState( D3DRS_FOGVERTEXMODE,  D3DFOG_NONE );
	DG.Device->SetRenderState( D3DRS_FOGTABLEMODE,   D3DFOG_LINEAR );


	// テクスチャのミップマップフィルタを設定する。
	if(Setting.MipmapEnable)
	{
		if(Setting.MipmapFiltarEnable)
		{
			DG.Device->SetTextureStageState( 0, D3DTSS_MIPFILTER, D3DTEXF_LINEAR );
			DG.Device->SetTextureStageState( 1, D3DTSS_MIPFILTER, D3DTEXF_LINEAR );
			DG.Device->SetTextureStageState( 2, D3DTSS_MIPFILTER, D3DTEXF_LINEAR );
			DG.Device->SetTextureStageState( 3, D3DTSS_MIPFILTER, D3DTEXF_LINEAR );
			DG.Device->SetTextureStageState( 4, D3DTSS_MIPFILTER, D3DTEXF_LINEAR );
		}
		else
		{
			DG.Device->SetTextureStageState( 0, D3DTSS_MIPFILTER, D3DTEXF_POINT );
			DG.Device->SetTextureStageState( 1, D3DTSS_MIPFILTER, D3DTEXF_POINT );
			DG.Device->SetTextureStageState( 2, D3DTSS_MIPFILTER, D3DTEXF_POINT );
			DG.Device->SetTextureStageState( 3, D3DTSS_MIPFILTER, D3DTEXF_POINT );
			DG.Device->SetTextureStageState( 4, D3DTSS_MIPFILTER, D3DTEXF_POINT );
		}

		float LODBias = Setting.MipmapBias;
		// ミップマップ詳細レベルを設定する。
		DG.Device->SetTextureStageState( 0, D3DTSS_MIPMAPLODBIAS, *((LPDWORD)(&LODBias)) );
		DG.Device->SetTextureStageState( 1, D3DTSS_MIPMAPLODBIAS, *((LPDWORD)(&LODBias)) );
		DG.Device->SetTextureStageState( 2, D3DTSS_MIPMAPLODBIAS, *((LPDWORD)(&LODBias)) );
		DG.Device->SetTextureStageState( 3, D3DTSS_MIPMAPLODBIAS, *((LPDWORD)(&LODBias)) );
		DG.Device->SetTextureStageState( 4, D3DTSS_MIPMAPLODBIAS, *((LPDWORD)(&LODBias)) );
	}




	//その他のRenderState設定
	DG.Device->SetRenderState( D3DRS_ZENABLE, true );
	DG.Device->SetRenderState( D3DRS_LIGHTING, true );

	DG.Device->SetRenderState( D3DRS_SPECULARENABLE,true);



	//ライト配置

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
	Light.Specular.r=0.8f;
	Light.Specular.g=0.8f;
	Light.Specular.b=0.8f;
	Light.Specular.a=1.0f;
	Light.Direction.x = 3.0f;
	Light.Direction.y = -7.0f;
	Light.Direction.z = 5.0f;

	DG.Device->SetLight(0,&Light);
	DG.Device->LightEnable (0,true);


	//レンダリング領域設定
	
	D3DVIEWPORT8 vp;

	vp.X =0;
	vp.Y =0;
	vp.Width =DG.Adapter.BackBufferWidth;
	vp.Height=DG.Adapter.BackBufferHeight;
	vp.MinZ=0;
	vp.MaxZ=1;

	DG.Device->SetViewport( &vp );





	//------------------------背景塗りつぶし------------------------



	D3DCOLOR backcolor=D3DXCOLOR(0,0,0,1);
	bool targetflag=true;

	if(gamemode==GAMEMODE_GAME)
	{
		if(stagekind==SELECTGAME_STAGE)
		{
			if(stagenum<12)
			{
				if(stagenum/4==0)
				{
					targetflag=true;
					backcolor=D3DXCOLOR(0,0.15f,0,1);
				}
				else if(stagenum/4==1)
				{
					backcolor=D3DXCOLOR(0.15f,0.07f,0,1);
				}
				else if(stagenum/4==2)
				{
	//				targetflag=false;
					backcolor=D3DXCOLOR(0.1f,0.1f,0.1f,1);
				}
				else if(stagenum/4==3)
				{
					targetflag=false;
					backcolor=D3DXCOLOR(0,0,0.15f,1);
				}
			}
			else
			{
				if((stagenum-13)/4==0)
				{
					targetflag=true;
					backcolor=D3DXCOLOR(0,0.15f,0,1);
				}
				else if((stagenum-13)/4==1)
				{
					backcolor=D3DXCOLOR(0.15f,0.07f,0,1);
				}
				else if((stagenum-13)/4==2)
				{
	//				targetflag=false;
					backcolor=D3DXCOLOR(0.1f,0.1f,0.1f,1);
				}
				else if((stagenum-13)/4==3)
				{
					targetflag=false;
					backcolor=D3DXCOLOR(0,0,0.15f,1);
				}	
			}
		}
		else
		{
			if(stagenum/3==0)
			{
				targetflag=false;
				backcolor=D3DXCOLOR(0,0.15f,0,1);
			}
			else if(stagenum/3==1)
			{
				targetflag=false;
				backcolor=D3DXCOLOR(0.15f,0.07f,0,1);
			}
			else if(stagenum/3==2)
			{
				targetflag=false;
				backcolor=D3DXCOLOR(0.1f,0.1f,0.1f,1);
			}
			else if(stagenum/3==3)
			{
				targetflag=false;
				backcolor=D3DXCOLOR(0,0,0.15f,1);
			}

			if(playercount==2 || playercount==3)//この人数だと背景が見えてしまうので色も書き換える必要がある
				targetflag=true;
		}
	}

	DG.Device->Clear( 0, NULL, (targetflag ? D3DCLEAR_TARGET : 0) | D3DCLEAR_ZBUFFER | 
								(Setting.ShadeEnable ? D3DCLEAR_STENCIL : 0), backcolor, 1.0f, 0 );





	//------------------------レンダリング------------------------


	int index;


	//レンダリング開始
	if( SUCCEEDED( DG.Device->BeginScene() ) )
	{


		int loopstart,loopend;

		if(gamemode==GAMEMODE_PROJECT)
		{
			ProjectRender();
		}
		else if(gamemode==GAMEMODE_TITLE)
		{
			TitleRender();
		}
		else if(gamemode==GAMEMODE_GAME)
		{

			if(stagekind==SELECTGAME_MULTIPLAY)
			{
				loopstart=loopend=multiplayernum;
			}
			else
			{
				loopstart=0;
				loopend=playercount-1;
			}

			StageRender(loopstart,loopend);


			//ライト設定が変わっている可能性があるので戻す
			Light.Type = D3DLIGHT_DIRECTIONAL;
			Light.Ambient.r = 0.0f;
			Light.Ambient.g = 0.0f;
			Light.Ambient.b = 0.0f;
			Light.Ambient.a = 1.0f;
			Light.Diffuse.r = 1.0f;
			Light.Diffuse.g = 1.0f;
			Light.Diffuse.b = 1.0f;
			Light.Diffuse.a = 1.0f;
			Light.Specular.r=0.8f;
			Light.Specular.g=0.8f;
			Light.Specular.b=0.8f;
			Light.Specular.a=1.0f;
			Light.Direction.x = 3.0f;
			Light.Direction.y = -7.0f;
			Light.Direction.z = 5.0f;

			DG.Device->SetLight(0,&Light);
			DG.Device->LightEnable (0,true);

		}





		//ビューポートを全体に戻す
		DG.Device->SetViewport( &vp );

		//Zバッファークリア
		DG.Device->Clear( 0, NULL, D3DCLEAR_ZBUFFER, 0, 1.0f, 0 );



		if(gamemode==GAMEMODE_GAME)
		{

			//インフォレンダリング
			for(index=loopstart;index<=loopend;index++)
			{
				if(stagekind!=SELECTGAME_MULTIPLAY)
					DG.Device->SetViewport( &player[index].vp );
				InfoRender(index);
			}

			//フェードレンダリング
			for(index=loopstart;index<=loopend;index++)
			{
				if(stagekind!=SELECTGAME_MULTIPLAY)
					DG.Device->SetViewport( &player[index].vp );
				feed[index].Render(DG.Device,(int)DG.Adapter.BackBufferWidth,(int)DG.Adapter.BackBufferHeight);
			}

		}



		//ビューポートを全体に戻す
		DG.Device->SetViewport( &vp );


		//全体のインフォレンダリング
		if(gamemode==GAMEMODE_GAME)
			InfoRender(-1);

		//セレクトレンダリング
		SelectRender();

		//全体のフェードレンダリング
		feed[4].Render(DG.Device,(int)DG.Adapter.BackBufferWidth,(int)DG.Adapter.BackBufferHeight);




		////テストでステージ番号を表示する
		//DG.Device->SetRenderState(D3DRS_ZENABLE,false);
		//DG.Device->SetTransform( D3DTS_WORLD, &D3DXMATRIX(0.1,0,0,0,0,0.1,0,0,0,0,0.1,0,3.2,-2.8,0,1) );
		//char str[100];
		//sprintf(str,"%f",player[0].par*100);
		//InfoNetRender(str);
		//DG.Device->SetRenderState(D3DRS_ZENABLE,true);




		//レンダリング終了
		DG.Device->EndScene();

	}


	//フリップ！
	DG.Device->Present( NULL, NULL, hWnd, NULL );


	return true;
}












//---------------------メッセージを受け取る関数--------------------
LRESULT WINAPI MsgProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
    switch( msg )
    {
	case MY_MSG:

		GetNetMsg();

		break;
	case WM_DESTROY:
		end=true;
		return 0;
    }

    return DefWindowProc( hWnd, msg, wParam, lParam );
}




void Cleanup()
{
	//念のためダウンを伝える
	SendPlayerOut();
	SendSeaverDown();


	GraphicRelease();
	SoundRelease();
	ShowRelease();

	DG.Release();
	DI.Release();

	//リプレイのTempを削除
	remove("Data/Save/Replay/Temp");
	remove("Data/Save/Replay/RTemp");

	UnregisterClass( AppName, wc.hInstance );

	// ロードしたDLL(lha)を開放します。
	FreeLibrary(lhalib);
}


//-----------------グラフィック関係のデータの初期化------------------------
bool GraphicSetting()
{
	int i;//,j;


	if(Setting.Anti!=0)
		DG.Device->SetRenderState (D3DRS_MULTISAMPLEANTIALIAS, true);


	if(ProjectGraphicSetting()==false)
		return false;

	if(TitleGraphicSetting()==false)
		return false;

	if(SelectGraphicSetting()==false)
		return false;

	if(InfoGraphicSetting()==false)
		return false;





	char filename[MAX_PATH];


	for(i=0;i<8;i++)
	{

		sprintf(filename,"data/graphic/Kemuri/%d",i+1);
		if(!DG.CreateTexture(&KemuriTex[i],filename)) return false;
	}

	for(i=0;i<ENVKIND_MAX;i++)
	{

		sprintf(filename,"data/graphic/Env/%d",i+1);
		if(!DG.CreateTexture(&EnvTex[i],filename)) return false;


	}



	if(shade.Create(DG.Device,"Data/Object/Other/shade.x",false)==false)
	{
		return false;
	}

	if(ita.Create(DG.Device,"Data/Object/Other/ita.x",false)==false)
	{
		return false;
	}


	if(taihoumesh[0].Create(DG.Device,"Data/Object/taihou/1.x",Setting.MultiTextureEnable)==false)
	{
		return false;
	}
	if(taihoumesh[1].Create(DG.Device,"Data/Object/taihou/2.x",Setting.MultiTextureEnable)==false)
	{
		return false;
	}
	if(taihoumesh[2].Create(DG.Device,"Data/Object/taihou/3.x",Setting.MultiTextureEnable)==false)
	{
		return false;
	}

	if(windmesh[0].Create(DG.Device,"Data/Object/wind/1.x",Setting.MultiTextureEnable)==false)
	{
		return false;
	}
	if(windmesh[1].Create(DG.Device,"Data/Object/wind/2.x",Setting.MultiTextureEnable)==false)
	{
		return false;
	}
	if(windmesh[2].Create(DG.Device,"Data/Object/wind/3.x",Setting.MultiTextureEnable)==false)
	{
		return false;
	}
	if(windmesh[3].Create(DG.Device,"Data/Object/wind/4.x",Setting.MultiTextureEnable)==false)
	{
		return false;
	}




	//ボールグラフィック読み込み
	for(i=0;i<BALLMESH_MAX;i++)
	{
		sprintf(filename,"Data/Object/Ball/Ball%d.x",i+1);

		if(ballmesh[i].Create(DG.Device,filename,Setting.MultiTextureEnable)==false)
			return false;

	}


	//アイテムグラフィック読み込み
	for(i=0;i<ITEMKIND_MAX;i++)
	{
		sprintf(filename,"Data/Object/Item/Item%d.x",i);

		if(itemmesh[i].Create(DG.Device,filename,Setting.MultiTextureEnable)==false)
			return false;

	}


	if(bombmesh.Create(DG.Device,"Data/Object/Other/Bomb.x",Setting.MultiTextureEnable)==false)
		return false;

	return true;

}


//-----------------グラフィック関係のデータの開放------------------------
void GraphicRelease()
{
	ProjectGraphicRelease();
	TitleGraphicRelease();
	SelectGraphicRelease();
	InfoGraphicRelease();

	stagemesh.Release();

	int i;

	for(i=0;i<BALLMESH_MAX;i++)
		ballmesh[i].Release();
	for(i=0;i<ITEMKIND_MAX;i++)
		itemmesh[i].Release();

	bombmesh.Release();

	shade.Release();
	ita.Release();
	taihoumesh[0].Release();
	taihoumesh[1].Release();
	windmesh[0].Release();


	for(i=0;i<ENVKIND_MAX;i++)
	{
		if(EnvTex[i]!=NULL)
		{
			EnvTex[i]->Release();
			EnvTex[i]=NULL;
		}
	}

	for(i=0;i<4;i++)
	{
		if(KemuriTex[i]!=NULL)
		{
			KemuriTex[i]->Release();
			KemuriTex[i]=NULL;
		}
	}

}


//-----------------サウンド関係のデータの初期化------------------------
bool SoundSetting()
{

	int i;



	//サウンド設定

	GUID Guid3D;
	if(Setting.SoundAlg==0)
		Guid3D=DS3DALG_NO_VIRTUALIZATION;
	else if(Setting.SoundAlg==1)
		Guid3D=DS3DALG_HRTF_LIGHT;
	else if(Setting.SoundAlg==2)
		Guid3D=DS3DALG_HRTF_FULL;






    DS = new CSoundManager();
    if( FAILED( DS->Initialize( hWnd, DSSCL_PRIORITY, 2, 22050, 16 ) ) )
		return false;








	//普通のサウンド
	if( FAILED(DS->Create( &sd.Project, "Data/Sound/Project.wav", 0, GUID_NULL )))
		return false;

	if( FAILED(DS->Create( &sd.RotaStart, "Data/Sound/SelectStart.wav", 0, GUID_NULL )))
		return false;

	if( FAILED(DS->Create( &sd.RotaEnd, "Data/Sound/SelectEnd.wav", 0, GUID_NULL )))
		return false;

	if( FAILED(DS->Create( &sd.Select, "Data/Sound/Select.wav", 0, GUID_NULL )))
		return false;

	if( FAILED(DS->Create( &sd.Count, "Data/Sound/Count.wav", 0, GUID_NULL )))
		return false;

	if( FAILED(DS->Create( &sd.Start, "Data/Sound/Start.wav", 0, GUID_NULL )))
		return false;

	if( FAILED(DS->Create( &sd.Kansei, "Data/Sound/Kansei.wav", 0, GUID_NULL )))
		return false;

	if( FAILED(DS->Create( &sd.Final, "Data/Sound/Final.wav", 0, GUID_NULL )))
		return false;



	//ゲーム中に再生されるサウンド
	DWORD flag=DSBCAPS_CTRLVOLUME | DSBCAPS_CTRLFREQUENCY;

	for(i=0;i<Setting.SoundMultiCount;i++)
	{

		if( FAILED(DS->Create( &sd.Pura[i], "Data/Sound/Pura.wav", flag, GUID_NULL )))
			return false;
		if( FAILED(DS->Create( &sd.Tetu[i], "Data/Sound/Tetu.wav", flag, GUID_NULL )))
			return false;
		if( FAILED(DS->Create( &sd.Siba[i], "Data/Sound/Siba.wav", flag, GUID_NULL )))
			return false;
		if( FAILED(DS->Create( &sd.Izigen[i], "Data/Sound/Izigen.wav", flag, GUID_NULL )))
			return false;
		if( FAILED(DS->Create( &sd.Gomu[i], "Data/Sound/Gomu.wav", flag, GUID_NULL )))
			return false;

		if( FAILED(DS->Create( &sd.Yudou[i], "Data/Sound/Yudou.wav", flag, GUID_NULL )))
			return false;
		if( FAILED(DS->Create( &sd.Item[i], "Data/Sound/Item.wav", flag, GUID_NULL )))
			return false;
		if( FAILED(DS->Create( &sd.Fire[i], "Data/Sound/Fire.wav", flag, GUID_NULL )))
			return false;
		if( FAILED(DS->Create( &sd.Mizu[i], "Data/Sound/Mizu.wav", flag, GUID_NULL )))
			return false;
		if( FAILED(DS->Create( &sd.Bomb[i], "Data/Sound/Bomb.wav", flag, GUID_NULL )))
			return false;
		if( FAILED(DS->Create( &sd.Shot[i], "Data/Sound/Shot.wav", flag, GUID_NULL )))
			return false;
		if( FAILED(DS->Create( &sd.ShotCount[i], "Data/Sound/ShotCount.wav", flag, GUID_NULL )))
			return false;

		if( FAILED(DS->Create( &sd.Gurabi[i], "Data/Sound/Gurabi.wav", flag, GUID_NULL )))
			return false;
		if( FAILED(DS->Create( &sd.GurabiStart[i], "Data/Sound/GurabiStart.wav", flag, GUID_NULL )))
			return false;
		if( FAILED(DS->Create( &sd.BombOut[i], "Data/Sound/BombOut.wav", flag, GUID_NULL )))
			return false;


		if( FAILED(DS->Create( &sd.Meka[i], "Data/Sound/Meka.wav", flag, GUID_NULL )))
			return false;
		if( FAILED(DS->Create( &sd.MizuStart[i], "Data/Sound/MizuStart.wav", flag, GUID_NULL )))
			return false;
		if( FAILED(DS->Create( &sd.Iwa[i], "Data/Sound/Iwa.wav", flag, GUID_NULL )))
			return false;

	}



	if(Setting.Sound3D)
	{

		//リスナーの設定
		if( FAILED( DS->Get3DListenerInterface( &sd.Listener ) ) )
			return false;

		sd.ListenerParam.dwSize = sizeof(DS3DLISTENER);
		sd.Listener->GetAllParameters( &sd.ListenerParam );

		sd.ListenerParam.flDopplerFactor = 0.8f;
		sd.ListenerParam.flRolloffFactor = 1.5f;




		//3Dサウンドの設定




		for(i=0;i<Setting.SoundMultiCount;i++)
		{
			if(!Create3DSound(&sd.Pura3D[i], "Data/Sound/Pura.wav",flag,Guid3D))
				return false;
			if(!Create3DSound(&sd.Tetu3D[i], "Data/Sound/Tetu.wav",flag,Guid3D))
				return false;
			if(!Create3DSound(&sd.Siba3D[i], "Data/Sound/Siba.wav",flag,Guid3D))
				return false;
			if(!Create3DSound(&sd.Izigen3D[i], "Data/Sound/Izigen.wav",flag,Guid3D))
				return false;
			if(!Create3DSound(&sd.Gomu3D[i], "Data/Sound/Gomu.wav",flag,Guid3D))
				return false;
			if(!Create3DSound(&sd.Yudou3D[i], "Data/Sound/Yudou.wav",flag,Guid3D))
				return false;
			if(!Create3DSound(&sd.Item3D[i], "Data/Sound/Item.wav",flag,Guid3D))
				return false;
			if(!Create3DSound(&sd.Fire3D[i], "Data/Sound/Fire.wav",flag,Guid3D))
				return false;
			if(!Create3DSound(&sd.Bomb3D[i], "Data/Sound/Bomb.wav",flag,Guid3D))
				return false;
			if(!Create3DSound(&sd.Shot3D[i], "Data/Sound/Shot.wav",flag,Guid3D))
				return false;
			if(!Create3DSound(&sd.ShotCount3D[i], "Data/Sound/ShotCount.wav",flag,Guid3D))
				return false;
			if(!Create3DSound(&sd.Gurabi3D[i], "Data/Sound/Gurabi.wav",flag,Guid3D))
				return false;
			if(!Create3DSound(&sd.GurabiStart3D[i], "Data/Sound/GurabiStart.wav",flag,Guid3D))
				return false;
			if(!Create3DSound(&sd.BombOut3D[i], "Data/Sound/BombOut.wav",flag,Guid3D))
				return false;
			if(!Create3DSound(&sd.Mizu3D[i], "Data/Sound/Mizu.wav",flag,Guid3D))
				return false;
			if(!Create3DSound(&sd.MizuStart3D[i], "Data/Sound/MizuStart.wav",flag,Guid3D))
				return false;
			if(!Create3DSound(&sd.Iwa3D[i], "Data/Sound/Iwa.wav",flag,Guid3D))
				return false;


		}

	}













		//再生位置取得
//		(sd.BoundTetu3D->GetBuffer(0))->GetCurrentPosition()

//		sd.BoundPura3D->Play(0,DSBPLAY_LOOPING);
//
//    LPDIRECTSOUNDBUFFER pDSB = g_pSound->GetBuffer( 0 );
//
////    pDSB->SetFrequency( 22050 );
//    pDSB->SetFrequency( 30000 );
//    pDSB->SetVolume( 0 );
//    pDSB->SetPan( 0 );


	return true;
}


//-----------------サウンド関係のデータの開放------------------------
void SoundRelease()
{
	if(sd.Project){delete(sd.Project);sd.Project=NULL;}
	if(sd.RotaStart){delete(sd.RotaStart);sd.RotaStart=NULL;}
	if(sd.RotaEnd){delete(sd.RotaEnd);sd.RotaEnd=NULL;}
	if(sd.Select){delete(sd.Select);sd.Select=NULL;}

	if(sd.Count){delete(sd.Count);sd.Count=NULL;}
//	if(sd.Goal){delete(sd.Goal);sd.Goal=NULL;}
	if(sd.Kansei){delete(sd.Kansei);sd.Kansei=NULL;}
	if(sd.Start){delete(sd.Start);sd.Start=NULL;}
	if(sd.Final){delete(sd.Final);sd.Final=NULL;}


	int i;
	for(i=0;i<Setting.SoundMultiCount;i++)
	{
		if(sd.Bomb[i]){delete(sd.Bomb[i]);sd.Bomb[i]=NULL;}
		if(sd.Fire[i]){delete(sd.Fire[i]);sd.Fire[i]=NULL;}
		if(sd.Mizu[i]){delete(sd.Mizu[i]);sd.Mizu[i]=NULL;}
		if(sd.Item[i]){delete(sd.Item[i]);sd.Item[i]=NULL;}
		if(sd.Shot[i]){delete(sd.Shot[i]);sd.Shot[i]=NULL;}
		if(sd.ShotCount[i]){delete(sd.ShotCount[i]);sd.ShotCount[i]=NULL;}
		if(sd.Ki[i]){delete(sd.Ki[i]);sd.Ki[i]=NULL;}
		if(sd.Tetu[i]){delete(sd.Tetu[i]);sd.Tetu[i]=NULL;}
		if(sd.Pura[i]){delete(sd.Pura[i]);sd.Pura[i]=NULL;}
		if(sd.Siba[i]){delete(sd.Siba[i]);sd.Siba[i]=NULL;}
		if(sd.Izigen[i]){delete(sd.Izigen[i]);sd.Izigen[i]=NULL;}
		if(sd.Yudou[i]){delete(sd.Yudou[i]);sd.Yudou[i]=NULL;}
		if(sd.Gomu[i]){delete(sd.Gomu[i]);sd.Gomu[i]=NULL;}
		if(sd.Gurabi[i]){delete(sd.Gurabi[i]);sd.Gurabi[i]=NULL;}
		if(sd.GurabiStart[i]){delete(sd.GurabiStart[i]);sd.GurabiStart[i]=NULL;}
		if(sd.BombOut[i]){delete(sd.BombOut[i]);sd.BombOut[i]=NULL;}
		if(sd.Meka[i]){delete(sd.Meka[i]);sd.Meka[i]=NULL;}
		if(sd.MizuStart[i]){delete(sd.MizuStart[i]);sd.MizuStart[i]=NULL;}
		if(sd.Iwa[i]){delete(sd.Meka[i]);sd.Meka[i]=NULL;}


		if(sd.Bomb3D[i].Sound){delete(sd.Bomb3D[i].Sound);sd.Bomb3D[i].Sound=NULL;}
		if(sd.Fire3D[i].Sound){delete(sd.Fire3D[i].Sound);sd.Fire3D[i].Sound=NULL;}
		if(sd.Mizu3D[i].Sound){delete(sd.Mizu3D[i].Sound);sd.Mizu3D[i].Sound=NULL;}
		if(sd.Shot3D[i].Sound){delete(sd.Shot3D[i].Sound);sd.Shot3D[i].Sound=NULL;}
		if(sd.ShotCount3D[i].Sound){delete(sd.ShotCount3D[i].Sound);sd.ShotCount3D[i].Sound=NULL;}
		if(sd.Item3D[i].Sound){delete(sd.Item3D[i].Sound);sd.Item3D[i].Sound=NULL;}
		if(sd.Ki3D[i].Sound){delete(sd.Ki3D[i].Sound);sd.Ki3D[i].Sound=NULL;}
		if(sd.Tetu3D[i].Sound){delete(sd.Tetu3D[i].Sound);sd.Tetu3D[i].Sound=NULL;}
		if(sd.Pura3D[i].Sound){delete(sd.Pura3D[i].Sound);sd.Pura3D[i].Sound=NULL;}
		if(sd.Siba3D[i].Sound){delete(sd.Siba3D[i].Sound);sd.Siba3D[i].Sound=NULL;}
		if(sd.Izigen3D[i].Sound){delete(sd.Izigen3D[i].Sound);sd.Izigen3D[i].Sound=NULL;}
		if(sd.Yudou3D[i].Sound){delete(sd.Yudou3D[i].Sound);sd.Yudou3D[i].Sound=NULL;}
		if(sd.Gomu3D[i].Sound){delete(sd.Gomu3D[i].Sound);sd.Gomu3D[i].Sound=NULL;}
		if(sd.Gurabi3D[i].Sound){delete(sd.Gurabi3D[i].Sound);sd.Gurabi3D[i].Sound=NULL;}
		if(sd.GurabiStart3D[i].Sound){delete(sd.GurabiStart3D[i].Sound);sd.GurabiStart3D[i].Sound=NULL;}
		if(sd.BombOut3D[i].Sound){delete(sd.BombOut3D[i].Sound);sd.BombOut3D[i].Sound=NULL;}
//		if(sd.Meka3D[i].Sound){delete(sd.Meka3D[i].Sound);sd.Meka3D[i].Sound=NULL;}
		if(sd.MizuStart3D[i].Sound){delete(sd.MizuStart3D[i].Sound);sd.MizuStart3D[i].Sound=NULL;}
	}

//	if(DS){delete(DS);DS=NULL;}
}



//-----------------その他のさまざまなのデータの初期化------------------------
bool OtherSetting()
{


	//ランジェネ初期化
	srnd();

	//バージョン
	Version=1.0f;

	end=false;
	Ghost=true;

	ProjectReset();
	TitleReset();
	SelectSetting();


	gamemode=GAMEMODE_PROJECT;

	//※最後には消す
//	gamemode=GAMEMODE_TITLE;
//	title.frame=710;

	//マルチプレイ用の設定
	myID=(int)rnd(65536);
	Error=CAPTION_NONE;
	MultiPlayStart=false;
	startend=false;

	//材質の設定
	int index=MATKIND_CHARA;


	//キャラクターの設定
	character[0].r=1;
	character[0].w=70;
	character[0].power=0.011f*1.5f*60*1.2f;
	character[0].speed=0.33f*2*1.1f;
	character[0].jump=0.15f*7*0.63f;//*3ははずす！！
	matstruct[index].moveres=0.05f;
	matstruct[index].rotares=0.01f*3;
	matstruct[index].rollres=0.008f/90.0f;
	matstruct[index].df=2.0f*0.7f;
	matstruct[index].sf=3.3f*0.7f;
	matstruct[index].bound=0.4f*1.3f;

	index++;
	character[1].r=1;
	character[1].w=75;
	character[1].power=0.012f*1.5f*60*1.2f;
	character[1].speed=0.35f*2*1.1f;
	character[1].jump=0.166f*7*0.61f;
	matstruct[index].moveres=0.05f;
	matstruct[index].rotares=0.01f*3;
	matstruct[index].rollres=0.008f/90.0f;
	matstruct[index].df=1.8f*0.7f;
	matstruct[index].sf=3.1f*0.7f;
	matstruct[index].bound=0.4f*1.3f;

	index++;
	character[2].r=0.7f;
	character[2].w=50;
	character[2].power=0.017f*1.5f*60*1.2f;
	character[2].speed=0.315f*2*1.1f;
	character[2].jump=0.13f*7*0.54f;
	matstruct[index].moveres=0.025f;
	matstruct[index].rotares=0.03f*3;
	matstruct[index].rollres=0.015f/90.0f;
	matstruct[index].df=5.5f*0.7f;
	matstruct[index].sf=8.0f*0.7f;
	matstruct[index].bound=0.5f*1.3f;

	index++;
	character[3].r=1.3f;
	character[3].w=80;
	character[3].power=0.007f*1.5f*60*1.2f;
	character[3].speed=0.39f*2*1.1f;
	character[3].jump=0.19f*7*0.6f;
	matstruct[index].moveres=0.06f;
	matstruct[index].rotares=0.004f*3;
	matstruct[index].rollres=0.012f/90.0f;
	matstruct[index].df=1.5f*0.7f;
	matstruct[index].sf=3.0f*0.7f;
	matstruct[index].bound=0.3f*1.3f;

	index++;
	character[4].r=0.8f;
	character[4].w=110;
	character[4].power=0.008f*1.5f*60*1.2f;
	character[4].speed=0.40f*2*1.1f;
	character[4].jump=0.19f*7*0.5f;
	matstruct[index].moveres=0.05f;
	matstruct[index].rotares=0.004f*3;
	matstruct[index].rollres=0.005f/90.0f;
	matstruct[index].df=0.3f;
	matstruct[index].sf=0.5f;
	matstruct[index].bound=0.5f*1.3f;



	//ステージ用
	index++;

	character[5].r=1;
	character[5].w=70;
	character[5].power=0.008f*60*1.2f;
	character[5].speed=0.6f;
	character[5].jump=0.1f*7.5f*0.6f;
	matstruct[index].moveres=0.05f;
	matstruct[index].rotares=0.01f*3;
	matstruct[index].rollres=0.008f/90.0f;
	matstruct[index].df=2.5f*0.7f;
	matstruct[index].sf=3.0f*0.7f;
	matstruct[index].bound=0.4f*1.3f;



	index=MATKIND_SIBA;
	matstruct[index].bound		=0.1f*1.3f;
	matstruct[index].df			=2.0f*1.3f;
	matstruct[index].sf			=2.2f*1.3f;
	matstruct[index].moveres=0.05f;
	matstruct[index].rotares=0.01f*3;
	matstruct[index].rollres	=0.3f/90.0f;

	index=MATKIND_KI;
	matstruct[index].bound		=0.3f*1.3f;
	matstruct[index].df			=2.5f*1.3f;
	matstruct[index].sf			=4.5f*1.3f;
	matstruct[index].moveres=0.05f;
	matstruct[index].rotares=0.01f*3;
	matstruct[index].rollres	=0.02f/90.0f;

	index=MATKIND_TUTI;
	matstruct[index].bound		=0.3f*1.3f;
	matstruct[index].df			=2.7f*1.3f;
	matstruct[index].sf			=4.7f*1.3f;
	matstruct[index].moveres=0.05f;
	matstruct[index].rotares=0.01f*3;
	matstruct[index].rollres	=0.02f/90.0f;

	index=MATKIND_ISI;
	matstruct[index].bound		=0.38f*1.3f;
	matstruct[index].df			=2.2f*1.3f;
	matstruct[index].sf			=3.7f*1.3f;
	matstruct[index].moveres=0.05f;
	matstruct[index].rotares=0.01f*3;
	matstruct[index].rollres	=0.005f/90.0f;

	index=MATKIND_TETU;
	matstruct[index].bound		=0.34f*1.3f;
	matstruct[index].df			=2.2f*1.3f;
	matstruct[index].sf			=3.7f*1.3f;
	matstruct[index].moveres=0.05f;
	matstruct[index].rotares=0.01f*3;
	matstruct[index].rollres	=0.005f/90.0f;

	index=MATKIND_TETU2;
	matstruct[index].bound		=0.34f;
	matstruct[index].df			=2.2f*0.8f;
	matstruct[index].sf			=3.7f*0.8f;
	matstruct[index].moveres=0.05f;
	matstruct[index].rotares=0.01f*3;
	matstruct[index].rollres	=0.005f/90.0f;

	index=MATKIND_TETUTAMA;
	matstruct[index].bound		=0.34f*1.3f;
	matstruct[index].df			=1.2f;
	matstruct[index].sf			=1.7f;
	matstruct[index].moveres=0.05f;
	matstruct[index].rotares=0.01f*3;
	matstruct[index].rollres	=0.005f/90.0f;

	index=MATKIND_SUNA;
	matstruct[index].bound		=0.2f*1.3f;
	matstruct[index].df			=0.2f*1.3f;
	matstruct[index].sf			=4.5f*1.3f;
	matstruct[index].moveres=0.05f;
	matstruct[index].rotares=0.01f*3;
	matstruct[index].rollres	=0.07f/90.0f;

	index=MATKIND_IZIGEN;
	matstruct[index].bound		=0.36f*1.3f;
	matstruct[index].df			=2.2f*1.3f;
	matstruct[index].sf			=3.7f*1.3f;
	matstruct[index].moveres=0.05f;
	matstruct[index].rotares=0.01f*3;
	matstruct[index].rollres	=0.005f/90.0f;

	index=MATKIND_GURABI;
	matstruct[index].bound		=0.36f*1.3f;
	matstruct[index].df			=2.2f*1.3f;
	matstruct[index].sf			=3.7f*1.3f;
	matstruct[index].moveres=0.05f;
	matstruct[index].rotares=0.01f*3;
	matstruct[index].rollres	=0.005f/90.0f;

	index=MATKIND_YUUDOU;
	matstruct[index].bound		=0.9f;//よくはねたほうが面白い
	matstruct[index].df			=0;
	matstruct[index].sf			=0;
	matstruct[index].moveres	=0.05f;
	matstruct[index].rotares	=0;
	matstruct[index].rollres	=0;


	index=MATKIND_GOMU;
	matstruct[index].bound		=0.3f*1.1f;
	matstruct[index].df			=2.7f*2.3f;
	matstruct[index].sf			=4.7f*2.3f;
	matstruct[index].moveres=0.05f;
	matstruct[index].rotares=0.01f*3;
	matstruct[index].rollres	=0.02f/90.0f;





	//アイテム出現率

	itemkakuritu[ITEMKIND_TAIHOU]=10.0f;
	itemkakuritu[ITEMKIND_FIRE]=8.0f;
	itemkakuritu[ITEMKIND_SHOT]=10.0f;
	itemkakuritu[ITEMKIND_BOMB]=9.0f;
	itemkakuritu[ITEMKIND_MIZU]=5.0f;
	itemkakuritu[ITEMKIND_YUUDOU]=5.0f;
	itemkakuritu[ITEMKIND_GURABI]=6.0f;

	//計算
	itemkakuritusum=0;
	for(int i=1;i<ITEMKIND_MAX;i++)
	{
		itemkakuritusum+=itemkakuritu[i];
		itemkakurituend[i]=itemkakuritusum;
	}

	//アイテムカラー設定

	itemcolor[ITEMKIND_TAIHOU]=D3DXCOLOR(1.0f,1.0f,1.0f,0.7f);
	itemcolor[ITEMKIND_FIRE]=D3DXCOLOR(1.0f,0.5f,0.5f,0.7f);
	itemcolor[ITEMKIND_SHOT]=D3DXCOLOR(1.0f,1.0f,0.0f,0.7f);
	itemcolor[ITEMKIND_BOMB]=D3DXCOLOR(0.2f,0.2f,0.2f,0.7f);
	itemcolor[ITEMKIND_MIZU]=D3DXCOLOR(0.5f,0.5f,1.0f,0.7f);
	itemcolor[ITEMKIND_GURABI]=D3DXCOLOR(0.2f,0.0f,0.6f,0.7f);
	itemcolor[ITEMKIND_YUUDOU]=D3DXCOLOR(0.4f,0.3f,0.2f,0.7f);




	return true;
}




//---------------------------------データのセーブとロード----------------------------------------

bool LoadSetting()
{
	int i;

	FILE* file;
	if((file=fopen("data/save/setting","r"))==NULL) return false;

	//画面について
	fscanf(file,"%d",&Setting.FullScreen);
	fscanf(file,"%d",&Setting.FormWidth);
	fscanf(file,"%d",&Setting.FormHeight);
	fscanf(file,"%d",&Setting.BufferWidth);
	fscanf(file,"%d",&Setting.BufferHeight);
	fscanf(file,"%d",&Setting.BufferFormat);

	//グラフィック関係
	fscanf(file,"%d",&Setting.MultiTextureEnable);
	fscanf(file,"%d",&Setting.FiltarEnable);
	fscanf(file,"%d",&Setting.MipmapEnable);
	fscanf(file,"%d",&Setting.MipmapFiltarEnable);
	fscanf(file,"%f",&Setting.MipmapBias); 
	fscanf(file,"%f",&Setting.KemuriMaxDis);
	fscanf(file,"%f",&Setting.ItemMaxDis);
	fscanf(file,"%d",&Setting.EnvEnable);
	fscanf(file,"%d",&Setting.ShadeEnable);

	//サウンドについて
	fscanf(file,"%d",&Setting.BGM);
	bool bgmtemp=Setting.BGM;
	int multicount;
	fscanf(file,"%d",&multicount);
	fscanf(file,"%d",&Setting.Sound3D);
	bool keepsound3d=Setting.Sound3D;
	fscanf(file,"%d",&Setting.SoundAlg);
	fscanf(file,"%d",&Setting.SoundCommit);

	//ネットワーク
	fscanf(file,"%s",Setting.ip);
	fscanf(file,"%s",Setting.port);
	fscanf(file,"%d",&Setting.IPKeep);
	fscanf(file,"%d",&Setting.PortKeep);

	//入出力
	fscanf(file,"%d",&Setting.Key1p);
	fscanf(file,"%d",&Setting.only1p);

	for(i=0;i<5;i++)
	{
		fscanf(file,"%d",&keynum[i].ok);
		fscanf(file,"%d",&keynum[i].cancel);
		fscanf(file,"%d",&keynum[i].jump);
		fscanf(file,"%d",&keynum[i].item);
		fscanf(file,"%d",&keynum[i].start);
		fscanf(file,"%d",&keynum[i].rightrote);
		fscanf(file,"%d",&keynum[i].leftrote);
		fscanf(file,"%d",&keynum[i].axis);
		fscanf(file,"%d",&keynum[i].axis2);
		fscanf(file,"%d",&keynum[i].up);
		fscanf(file,"%d",&keynum[i].down);
		fscanf(file,"%d",&keynum[i].left);
		fscanf(file,"%d",&keynum[i].right);
		fscanf(file,"%d",&keynum[i].up2);
		fscanf(file,"%d",&keynum[i].down2);
		fscanf(file,"%d",&keynum[i].left2);
		fscanf(file,"%d",&keynum[i].right2);
		fscanf(file,"%f",&keynum[i].axisover);
		fscanf(file,"%f",&keynum[i].axisover2);
		fscanf(file,"%d",&keynum[i].VibEnable);
	}

	fscanf(file,"%d",&Setting.Anti);


	//こうやらないとなぜかバグる
	Setting.SoundMultiCount=multicount;
	Setting.Sound3D=keepsound3d;

	fclose(file);

	Setting.BGM=bgmtemp;

	return true;
}



bool SaveSetting()
{
	int i;

	FILE* file;
	if((file=fopen("data/save/setting","w"))==NULL) return false;


	//画面について
	fprintf(file,"%d\n",Setting.FullScreen);
	fprintf(file,"%d\n",Setting.FormWidth);
	fprintf(file,"%d\n",Setting.FormHeight);
	fprintf(file,"%d\n",Setting.BufferWidth);
	fprintf(file,"%d\n",Setting.BufferHeight);
	fprintf(file,"%d\n",Setting.BufferFormat);

	//グラフィック関係
	fprintf(file,"%d\n",Setting.MultiTextureEnable);
	fprintf(file,"%d\n",Setting.FiltarEnable);
	fprintf(file,"%d\n",Setting.MipmapEnable);
	fprintf(file,"%d\n",Setting.MipmapFiltarEnable);
	fprintf(file,"%f\n",Setting.MipmapBias);
	fprintf(file,"%f\n",Setting.KemuriMaxDis);
	fprintf(file,"%f\n",Setting.ItemMaxDis);
	fprintf(file,"%d\n",Setting.EnvEnable);
	fprintf(file,"%d\n",Setting.ShadeEnable);

	//サウンドについて
	fprintf(file,"%d\n",Setting.BGM);
	fprintf(file,"%d\n",Setting.SoundMultiCount);
	fprintf(file,"%d\n",Setting.Sound3D);
	fprintf(file,"%d\n",Setting.SoundAlg);
	fprintf(file,"%d\n",Setting.SoundCommit);

	//ネットワーク
	fprintf(file,"%s\n",Setting.ip);
	fprintf(file,"%s\n",Setting.port);
	fprintf(file,"%d\n",Setting.IPKeep);
	fprintf(file,"%d\n",Setting.PortKeep);

	//入出力
	fprintf(file,"%d\n",Setting.Key1p);
	fprintf(file,"%d\n",Setting.only1p);

	for(i=0;i<5;i++)
	{
		fprintf(file,"%d\n",keynum[i].ok);
		fprintf(file,"%d\n",keynum[i].cancel);
		fprintf(file,"%d\n",keynum[i].jump);
		fprintf(file,"%d\n",keynum[i].item);
		fprintf(file,"%d\n",keynum[i].start);
		fprintf(file,"%d\n",keynum[i].rightrote);
		fprintf(file,"%d\n",keynum[i].leftrote);
		fprintf(file,"%d\n",keynum[i].axis);
		fprintf(file,"%d\n",keynum[i].axis2);
		fprintf(file,"%d\n",keynum[i].up);
		fprintf(file,"%d\n",keynum[i].down);
		fprintf(file,"%d\n",keynum[i].left);
		fprintf(file,"%d\n",keynum[i].right);
		fprintf(file,"%d\n",keynum[i].up2);
		fprintf(file,"%d\n",keynum[i].down2);
		fprintf(file,"%d\n",keynum[i].left2);
		fprintf(file,"%d\n",keynum[i].right2);
		fprintf(file,"%f\n",keynum[i].axisover);
		fprintf(file,"%f\n",keynum[i].axisover2);
		fprintf(file,"%d\n",keynum[i].VibEnable);
	}

	fprintf(file,"%d\n",Setting.Anti);

	fclose(file);


	return true;
}










bool LoadClear()
{

	FILE *file;

//	※最後はこのコメントをはずす
	if(checkfile("data/save/Clear")==false)
	{//データ初期化
		MessageBox(NULL,"セーブデータが不正です。\n初期状態でゲームをスタートします","エラー",MB_OK);
		clearstage=0;
		for(int i=0;i<STAGE_MAX+CORCE_MAX;i++)
			hTime[i]=0;
		//スタッフロールの設定
		hTime[12]=5478;
		hTime[29]=5302;
	}
	else
	{

		if((file=fopen("data/save/Clear","r"))==NULL) return false;

		fscanf(file,"%d",&clearstage);
		for(int i=0;i<STAGE_MAX+CORCE_MAX;i++)
			fscanf(file,"%d",&hTime[i]);

		fclose(file);
	}

	return true;
}

bool SaveClear()
{
	FILE* file;
	if((file=fopen("data/save/Clear","w"))==NULL) return false;

	fprintf(file,"%d\n",clearstage);
	for(int i=0;i<STAGE_MAX+CORCE_MAX;i++)
		fprintf(file,"%d\n",hTime[i]);

	fclose(file);

	////チェックファイルを作成
	createcheckfile("data/save/Clear");


	return true;
}
