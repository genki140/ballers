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


//���C���v���O����
int WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR CmdLine, INT CmdShow)
{

//	checkfile("data/save/Replay/stage/0.lzh");


	if(mutexcheck()==false)
	{
		MessageBox(NULL,"���d�N���͂ł��܂���","�ݒ�",MB_OK);
		return false;
	}




	int i;

	//�����̃p�X�擾
	char mename[MAX_PATH];
	GetModuleFileName(NULL,mename,MAX_PATH-1);

	char path[MAX_PATH];
	strcpy(path,mename);
	//�p�X�̍Ōォ��/��T��
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

	//�������p�X���Z�b�g
	SetCurrentDirectory(path);



	lhalib = LoadLibrary("data/dll/unlha32.dll");
	if (lhalib == NULL){
        MessageBox(hWnd, "�K�v�ȃ��C�u�����t�@�C����������܂���", "�G���[", MB_OK);
        return false;
	}

	//�֐��쐬
	Unlha = (UNLHA)GetProcAddress(lhalib,"Unlha");



//	Unlha(NULL, "e Data/Save/Replay/Stage/0.lzh Data/Save/Replay/ RTemp -n1 -gm1", "" ,0);



	////�����W�F�l������������O�Ƀp�X���[�h�p�̐��l(������)���擾���A�`�F�b�N����
	//int randam=(int)rnd(65536);
	//char str[100];
	//sprintf(str,"%d",randam);
	//MessageBox(NULL,str,"�p�X���[�h",MB_OK);







    // DirectX8 �̃`�F�b�N
    HINSTANCE hDll = LoadLibrary( "d3d8.dll" );
    if ( hDll == NULL )
    {
        MessageBox(hWnd, "DirectX8��������܂���", "�G���[", MB_OK);
        return false;
    }
    FreeLibrary( hDll );

	//�ݒ�t�@�C���ǂݍ���
	if(!LoadSetting())
	{
		MessageBox(hWnd, "�ݒ�t�@�C���̓ǂݍ��݂Ɏ��s���܂���", "�G���[", MB_OK);
		return false;
	}

	//�N���A�f�[�^�ǂݍ���
	if(!LoadClear())
	{
		MessageBox(hWnd, "�Z�[�u�t�@�C���̓ǂݍ��݂Ɏ��s���܂���", "�G���[", MB_OK);
		return false;
	}

	//IP��PORT�̉��
	KeepIP=Setting.IPKeep;
	KeepPort=Setting.PortKeep;

	//Direct3D�쐬
	if(!DG.CreateD3D())
	{
	    Cleanup();
		MessageBox(hWnd, "DirectGraphic�̏������Ɏ��s���܂���", "�G���[", MB_OK);
		return false;
	}





    // �E�B���h�E�N���X�쐬
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


    // �E�B���h�E�쐬
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

		//���g���Œ�
		DG.Adapter.FullScreen_RefreshRateInHz=60;
	}
	else
	{
		D3DDISPLAYMODE d3ddm;
		if(!DG.GetDisplayMode( &d3ddm ))
		{
			MessageBox(hWnd, "�f�B�X�v���C���[�h�̎擾�Ɏ��s���܂���", "�G���[", MB_OK);
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


	// �E�B���h�E��\��
    ShowWindow( hWnd, CmdShow );
    UpdateWindow( hWnd );





	DG.Adapter.BackBufferWidth =Setting.BufferWidth;
	DG.Adapter.BackBufferHeight =Setting.BufferHeight;

	if(Setting.ShadeEnable)
	{
		//�X�e���V�����g��
		DG.Adapter.AutoDepthStencilFormat=D3DFMT_D24S8;
	}
	else
	{
		//�X�e���V���͎g��Ȃ�
		DG.Adapter.AutoDepthStencilFormat=D3DFMT_D16;
	}

	//�A���`�G�C���A�X�̐ݒ�
	DG.Adapter.MultiSampleType=(D3DMULTISAMPLE_TYPE)(Setting.Anti>0 ? Setting.Anti+1 : 0);




	//Input�ݒ�
	bool VibEnables[4];
	for(i=0;i<4;i++)
		VibEnables[i]=keynum[i+1].VibEnable;

	if(DI.Create( hWnd, Setting.FullScreen ,VibEnables, 4) == false)
	{
		Cleanup();
		MessageBox(hWnd, "DirectInput�̏������Ɏ��s���܂���", "�G���[", MB_OK);
		return false;
	}

	if(SoundSetting() == false)
	{
		Cleanup();
		MessageBox(hWnd, "DirectSound�̏������Ɏ��s���܂���", "�G���[", MB_OK);
		return false;
	}

	if(ShowSetting(0) == false)//�Ƃ肠�����I�[�v�j���O�ȓǂݍ��݂Ńe�X�g
	{
		Cleanup();
		MessageBox(hWnd, "DirectShow�̏������Ɏ��s���܂���", "�G���[", MB_OK);
		return false;
	}

	if(DG.Create( hWnd ) == false)
	{
	    Cleanup();
		MessageBox(hWnd, "DirectGraphicDevice�̏������Ɏ��s���܂���", "�G���[", MB_OK);
		return false;
	}


	//���̑��̃Z�b�e�B���O
	if(OtherSetting()==false)
	{
	    Cleanup();
		MessageBox(hWnd, "�Q�[���̐ݒ�Ɏ��s���܂���", "�G���[", MB_OK);
		return false;		
	}


	if(GraphicSetting() == false)
	{
	    Cleanup();
		MessageBox(hWnd, "DirectGraphic�I�u�W�F�N�g�̍쐬�Ɏ��s���܂���", "�G���[", MB_OK);
		return false;
	}

    // ���b�Z�[�W���[�v
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



			if(DG.GetDevice()==false)// || FullChange)//�f�o�C�X�����ł��Ă�����I
			{
				DeviceLost=true;
			}
			else if(DeviceLost==true)
			{
				////�f�o�C�X�����A���Ă�����
				DeviceLost=false;

				GraphicRelease();

				DG.Release();

				if(!DG.Create(hWnd))
				{
					Cleanup();
					MessageBox(hWnd,"�Đݒ�Ɏ��s���܂���","�G���[",MB_OK);
					return false;
				}

				if(!GraphicSetting())
				{
					Cleanup();
					MessageBox(hWnd,"�Đݒ�Ɏ��s���܂���","�G���[",MB_OK);
					return false;
				}

				if(gamemode==GAMEMODE_GAME)
				{
					//�X�e�[�W�ČĂяo��
					if(!StageMeshLoad())
					{
						Cleanup();
						MessageBox(hWnd,"�Đݒ�Ɏ��s���܂���","�G���[",MB_OK);
						return false;
					}
					if(!InfoStageSetting())
					{
						Cleanup();
						MessageBox(hWnd,"�Đݒ�Ɏ��s���܂���","�G���[",MB_OK);
						return false;
					}

				}

			}
			else
			{


				//�t���[�����[�g�������Ȃ���Move��Render���s��

				static float framecount=100;
				static long int startclock=clock(),movestartclock;
				int fps=60;

				//�Ƃ肠����������
				movestartclock=clock();
				if(!Move())
				{
					Cleanup();
					MessageBox(hWnd,"�G���[���������܂���","�G���[",MB_OK);
					return false;
				}

				//�����������ƁA�������łɒx��Ă���悤�Ȃ�ǂ����悤���Ȃ��̂ŁA�����_�����O���ď�����
				if (fps*( (clock()-movestartclock) / 1000.0f) > 1)
				{
					if(!Render())
					{
						Cleanup();
						MessageBox(hWnd,"�G���[���������܂���","�G���[",MB_OK);
						return false;
					}
					framecount=1;
					startclock=clock();
				}
				else
				{
					//���Ԃ��Ԃɍ����Ă�����
					if(fps*( (clock()-startclock) / 1000.0f) < framecount+5)//+5���Ă�̂́A�����̒x��͋�������
					{
						//�E�B���h�E���[�h�ł���Ύ��Ԃ܂ő҂��ă����_�����O
//						if(!Setting.FullScreen)
							while( fps*( (clock()-startclock) / 1000.0f) < framecount );
						if(!Render())
						{
							Cleanup();
							MessageBox(hWnd,"�G���[���������܂���","�G���[",MB_OK);
							return false;
						}
					}
				}

				//�J�E���^���C���N��
				framecount++;


			}
		}
	}

	//IP��PORT�̕���
	if(!Setting.IPKeep)
		Setting.IPKeep=KeepIP;
	if(!Setting.PortKeep)
		Setting.PortKeep=KeepPort;

	if(!SaveSetting())
		MessageBox(hWnd,"�ݒ�̕ۑ����ɃG���[���������܂���","�G���[",MB_OK);
	if(!SaveClear())
		MessageBox(hWnd,"�N���A���̕ۑ����ɃG���[���������܂���","�G���[",MB_OK);

	//��Еt��
    Cleanup();

	return true;
}






//���[�g�A�`�F�b�N�A�A�C�e�������Z�[�u���邽�߂Ɏg�p����ϐ�
//FILE *rfile;


bool Move()
{
	////���{�^��
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

	//�C���v�b�g�f�[�^�擾

	DI.Acquire();
	DI.GetData();
	DI.Move();


	//----------------------------���͊֌W----------------------------



	int DIloopend=4;
	if(stagekind==SELECTGAME_MULTIPLAY && gamemode==GAMEMODE_GAME) DIloopend=1;

	//DI�����Ԃ��擾���A�ҏW����(���͈̔͂�0�`1)
	for(i=0;i<DIloopend;i++)
	{
		//�L�[�{�[�h
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

			//�΂߂̂Ƃ��������ς���Ă��܂��̂Œ���
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



			//�͈͓��Ȃ�0�ɂ���
			if(buttonstate[i].x<keynum[i-Setting.Key1p+1].axisover*10000 && buttonstate[i].x>-keynum[i-Setting.Key1p+1].axisover*10000)
				buttonstate[i].x=0;
			if(buttonstate[i].y<keynum[i-Setting.Key1p+1].axisover*10000 && buttonstate[i].y>-keynum[i-Setting.Key1p+1].axisover*10000)
				buttonstate[i].y=0;

			if(buttonstate[i].x2<keynum[i-Setting.Key1p+1].axisover2*10000 && buttonstate[i].x2>-keynum[i-Setting.Key1p+1].axisover2*10000)
				buttonstate[i].x2=0;
			if(buttonstate[i].y2<keynum[i-Setting.Key1p+1].axisover2*10000 && buttonstate[i].y2>-keynum[i-Setting.Key1p+1].axisover2*10000)
				buttonstate[i].y2=0;



			//�͈͊O�̂Ƃ��̔�����
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




			//�΂߂̂Ƃ��������ς���Ă��܂��̂Œ���
			if(distance(buttonstate[i].x,buttonstate[i].y)>10000)
				changedistance(&buttonstate[i].x,&buttonstate[i].y,10000);
			if(distance(buttonstate[i].x2,buttonstate[i].y2)>10000)
				changedistance(&buttonstate[i].x2,&buttonstate[i].y2,10000);




			//�O�Ɣ�r���Abx,by�̂����Ă�
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

	//�S�̂̃`�F�b�N�I�I

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




	//�Z���N�g������
	SelectMove();

	//�S�̂̃t�F�[�h�A�E�g�i�s
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
			//�t�F�[�h�A�E�g
			if((buttonstate[4].ok || buttonstate[4].start) && feed[4].count==0)
				feed[4].Start(FEEDMODE_WHITEOUT,30);
		}



		//�t�F�[�h�A�E�g��Ԃ̂܂܂��ƍ���̂Ō��ɖ߂�
		if(title.frame==0)
		{
			for(i=0;i<5;i++)
				feed[i].End();
		}


		//�^�C�g����ʂ𓮂���
		TitleMove();

		

		//��莞�ԑ��삪�Ȃ��Ƃ��̓��v���C�ɓ���
		if(title.frame>=710)
		{
			if(sel.enable)
			{
				autoReplay=false;
				autoReplayCount=0;
			}
			else
			{
				if(autoReplayCount<20*60)//20�b
				{
					autoReplayCount++;
				}
				else
				{

					//�X�e�[�W�������_���ɑI��
					static int oldreplaystage=-1;//�O�Ɠ����̂͑I�΂Ȃ��I�I
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

						//����I
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


		//�Z���N�g��ʌĂяo��
		if(gamemode==GAMEMODE_TITLE && title.frame>=720 && (buttonstate[4].ok || buttonstate[4].start) && sel.enable==false && feed[4].count==0)
		{
			CallSelect(CALLMODE_GAMESELECT);
		}
		
		//�Z���N�g��ʂł̑���
		if(sel.enable==true && feed[4].count==0)
		{



			//�L�����N�^�[�Z���N�g�̂Ƃ��́A�L�����Z���ȊO�̃L�[�͑I�𒆂̃v���C���[��������ł��Ȃ�
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
					//���ʉ��Đ�
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

			
			//�N���C�A���g�ŃG���[�ł���
			//�T�[�o�[�Ɉꉞ�M���𑗂��Ă���
			if(!Setting.Seaver && sel.nowparentsindex==CAPTION_ERROR && sel.frame==1)//frame��0�ɂȂ�O�ɏ�������
				SendPlayerOut();



		}



		if(sel.nowparentsindex==CAPTION_INFO)
		{
			//�C���t�H���[�V�����\���֌W
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



			//�Q�����Ă���v���C���[�S���������Ɛڑ����Ă��邩�����I�ɒ��ׂ�(10�b�ԉ������Ȃ��ꍇ�̓_�E���Ƃ���)

//				CheckPlayer();



			//�Q�[���ֈړ��ł��邩�𒲂ׂ�
			bool ok=true;
			if(sel.frame==0 && multiplayreadymy)
			{
				for(i=0;i<playercount-1;i++)
					if(multiplayready[i]==false)
						ok=false;


				//�Ƃ肠�����e�X�g�p��ok�ɂ���
//					ok=true;player[1].charnum=0;


				if(ok)
				{
					//�Q�[���ֈړ�
					SendGameStart();
					MultiPlayStart=true;//����ɂ��Z���N�g������

					//�X�^�[�g�J�E���g�J�n�����p�ϐ��̏�����
					for(i=0;i<playercount-1;i++)
						multiplaystartcount[i]=false;
				}
			}


		}
		



		//�t�F�[�h�A�E�g���̏����i�Q�[���I���A�Q�[���ֈړ��A�Ȃǁj
		if(feed[4].count==feed[4].countend-1 && (stagekind!=SELECTGAME_MULTIPLAY || Error==CAPTION_NONE))
		{
			sel.frame=0;

			if(feed[4].mode==FEEDMODE_BLACKOUT)
			{
				if(stagekind==SELECTGAME_END)//�I��
					end=true;
			}
			else if(feed[4].mode==FEEDMODE_WHITEOUT)
			{





				//�ɂ񂸂��ݒ�
				if(stagekind==SELECTGAME_STAGE)//�X�e�[�W
				{
					playercount=1;
					//�L�����N�^�[�����ݒ�
					player[0].charnum=5;//�X�e�[�W�p�L�����N�^�[
				}


				//���s������X�^�[�g���Ȃ�
				//if(!StageSetting() || !InfoStageSetting())
				//{
				//	//�߂鏈
				//	feed[4].Start(FEEDMODE_WHITEIN,60);
				//	CallSelect(CALLMODE_STAGESELECT,0);
				//	return true;
				//}

				if(!StageSetting())return false;
				if(!InfoStageSetting())return false;

				gamemode=GAMEMODE_GAME;

				//�l�����Z�b�e�B���O
				for(i=0;i<playercount;i++)
				{

					//�����_�����O�̈�̐ݒ�
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



				//�ȃ`�F���W
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

				//���̂��߂ɃJ�E���g��߂�
				autoReplayCount=0;

				ReplayStart();



				feed[4].Start(FEEDMODE_WHITEIN,60);


				//�Q�[���X�^�[�g�ł����`�@�@�ƎI�ɑ���
				Buffer[0]='\0';
				SetMsg(Buffer,myID,NETMSG_READY);
				sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&addr, (int)sizeof(addr));




			}





		}


	}
	else if(gamemode==GAMEMODE_GAME)//�Q�[�����
	{

		bool gameok=true;


		if(stagekind==SELECTGAME_MULTIPLAY)
		{
			if(Setting.Seaver)
			{



				//�S������̃��b�Z�[�W����莞�ԓ��ɗ��Ȃ��ꍇ�͂��Ȃ������v���C���[�������ăX�^�[�g

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
					//�������Ȃ��I�I(���Ă�v���C���[�ɂ��������đ��s�I)
					ok=true;

				}
				else ok=false;


				if(ok)
				{
					//�ڑ�����Ă���S���ɊJ�n�̃��b�Z�[�W�𑗂�
					SendCountStart();
					//�����Ď������X�^�[�g
					MultiPlayCountStart=true;

					//���y�Đ�
					ShowSetting(stagenum%3+6);

				}




			}
			else
			{




				//�N���C�A���g�͎I����̃��b�Z�[�W��҂�
				if(gamestartlimit<10*60 && !MultiPlayCountStart)
				{
					gameok=false;
					gamestartlimit++;
					feed[4].Start(FEEDMODE_WHITEIN,60);
				}
				else if(!MultiPlayCountStart)
				{
					//�������Ȃ��I�I
					//�Z���N�g��ʂɖ߂�
					feed[4].Start(FEEDMODE_WHITEIN,60);
					CallSelect(CALLMODE_INFO,0);
					Error=CAPTION_SETUZOKUERROR;
					gamemode=GAMEMODE_TITLE;
				}



			}
		}

		if(gameok)//�Q�[���ɓ���Ă�����E�E
		{


			//���Ō�ɂ͏���


			//if(rootsave)
			//{

			//	//���[�g�L�^���[�h
			//	static float sumdis=0;
			//	static D3DXVECTOR3 oldpo;
			//	float dis;
			//	
			//	if(DI.joy[0].down[3])//���{�^��
			//	{
			//		dis=D3DXVec3Length(&(ball[0].ball.po-oldpo));
			//		sumdis+=dis;
			//		fprintf(rfile,"%f,%f,%f,%f,%f\n",ball[0].ball.po.x,ball[0].ball.po.y,ball[0].ball.po.z,dis,sumdis);
			//		oldpo=ball[0].ball.po;
			//	}
			//}

			//if(checksave)
			//{
			//	//�`�F�b�N�L�^���[�h
			//	if(DI.joy[0].down[3])//���{�^��
			//	{
			//		fprintf(rfile,"%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n",player[0].temppar,
			//				ball[0].ball.po.x,ball[0].ball.po.y,ball[0].ball.po.z,
			//				ball[0].gv.x,ball[0].gv.y,ball[0].gv.z,player[0].cpo.x,player[0].cpo.y,player[0].cpo.z,
			//				player[0].cup.x,player[0].cup.y,player[0].cup.z);
			//	}
			//}


			//if(itemsave)
			//{
			//	//�A�C�e���L�^���[�h
			//	if(DI.joy[0].down[3])//���{�^��
			//	{
			//		fprintf(rfile,"%f,%f,%f\n",ball[0].ball.po.x,ball[0].ball.po.y,ball[0].ball.po.z);
			//	}
			//}





			if(stagekind==SELECTGAME_MULTIPLAY && !Setting.Seaver)
			{
				//�}���`�v���C���[�h�ŃN���C�A���g�̂Ƃ��͓��̓f�[�^���T�[�o�[�֑���
				sprintf(Buffer,"%d,%d,%f,%f",buttonstate[0].item,buttonstate[0].jump,buttonstate[0].x,buttonstate[0].y);
				SetMsg(Buffer,myID,NETMSG_INPUT);
				sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&addr, (int)sizeof(addr));


				//����������͏��̏����I�I(�J�����ړ��n�͏������Ȃ�)
				//�c���Ă������̂����ł��Amultiplayernum�̑���Ƃ��ăR�s�[���Ă���

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


				//���łɃJ�������������Ă���
				sprintf(Buffer,"%f,%f,%f,%f,%f,%f",
					player[multiplayernum].cponext.x,player[multiplayernum].cponext.y,player[multiplayernum].cponext.z,
					player[multiplayernum].cupnext.x,player[multiplayernum].cupnext.y,player[multiplayernum].cupnext.z);
				SetMsg(Buffer,myID,NETMSG_CAMERA);
				sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&addr, (int)sizeof(addr));

			}



			//�V���O���v���C�Ȃ�S�Ă̓��̓f�o�C�X���g�p����
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


			//�X�g�b�v


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
					//�I������
					feed[4].Start(FEEDMODE_BLACKOUT,60);

					if(stagekind==SELECTGAME_MULTIPLAY)
						player[multiplayernum].goal=true;
					else
						player[0].goal=true;

//					autoReplay=false;

					//�Q�[���̏I����`����
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

				//------���܂��܂ȍX�V����------

				//�t�F�[�h�X�V
				for(i=0;i<4;i++)
					feed[i].Move();

				//�X�e�[�W�X�V
				StageMove();

				//���X�V
				InfoMove();



				//�^�C�}�[�𓮂���
				if(info.startcounter==0 && 
					((stagekind==SELECTGAME_STAGE && player[0].InputEnable==true) || 
					(stagekind==SELECTGAME_VARSUS && player[0].lap<=lap)))//stagekind==SELECTGAME_STAGE)
				{
					if(Time<rTime || stagekind==SELECTGAME_VARSUS)
					{
						//�^�C�}�[�𓮂���
						Time++;

						if(Time%60==1 && Time>rTime-10*60 && stagekind==SELECTGAME_STAGE)
							info.timeframe=30;
					}
					else//���Ԑ؂�
					{
						player[0].InputEnable=false;
						autostop=true;
						CallSelect(CALLMODE_GAME,60);
					}
				}


				//�}���`�v���C���A���v���C���̃N���A(�����I��)�Ŗ߂鏈���i�����t�F�[�h�A�E�g���ꂽ�Ƃ��ɍ쓮�I)
				if((stagekind==SELECTGAME_MULTIPLAY || replay) && player[multiplayernum].goal && feed[4].count==feed[4].countend-1 && feed[4].mode==FEEDMODE_BLACKOUT)
				{
					if(stagekind==SELECTGAME_MULTIPLAY)
					{
						//�I���I
						multiplayreadymy=false;
						for(i=0;i<3;i++)
							multiplayready[i]=false;
						feed[4].Start(FEEDMODE_BLACKIN,60);
						sel.enable=false;
						CallSelect(CALLMODE_INFO);
						//�ȃ`�F���W(�I�[�v�j���O)
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
					//���ʉ�����
					SoundReset();

				}




				//------���v���C�n����-------

				//�S�[�X�g�{�^��
				if(playercount==1 && buttonstate[0].item==true && GetClear() && !replay && !staff)
					Ghost=!Ghost;

//				char replaystr[200];
				if(playercount==1)
				{
					if(!replayend)
					{


						////��x������˂��Ė߂�(������˂₻�̋t�Ȃǂ������Ƃ��ɏo��덷���Ȃ�������)
						//sprintf(replaystr,"%f,%f,%f,%f,%f,%f,%f,%f,%f\n",
						//	ball[0].ball.po.x,ball[0].ball.po.y,ball[0].ball.po.z,
						//	ball[0].ball.mv.x,ball[0].ball.mv.y,ball[0].ball.mv.z,
						//	ball[0].ball.axis.x,ball[0].ball.axis.y,ball[0].ball.axis.z);
						//sscanf(replaystr,"%f,%f,%f,%f,%f,%f,%f,%f,%f",
						//	&ball[0].ball.po.x,&ball[0].ball.po.y,&ball[0].ball.po.z,
						//	&ball[0].ball.mv.x,&ball[0].ball.mv.y,&ball[0].ball.mv.z,
						//	&ball[0].ball.axis.x,&ball[0].ball.axis.y,&ball[0].ball.axis.z);



						//���v���C
						if(replay || staff)
						{
							//�ǂݍ���
							readreplaydata();
							Ghost=false;
						}
						else
						{
							writereplaydata();

							if(GetClear() && ReadReplayFile)
							{
								//�ǂݍ���(�S�[�X�g)
								if(!readreplayGhostdata())
								{
									replayend=true;
								}
							}

							////�X�^�b�t���[�����v���C�Đ�
							//if(staff)
							//{
							//	//�S�[�X�g�̈ʒu�ֈړ�
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







			//�����ȏ������I������̂ŏ����N���C�A���g�ɓ]���I�I

			if(stagekind==SELECTGAME_MULTIPLAY && Setting.Seaver)
			{
				//�}���`�v���C���[�h�ŃT�[�o�[�̂Ƃ��͐��E�̃f�[�^���N���C�A���g�֑���


				char TempStr[1000];


				//���Ƀv���C���[�S�������f�[�^��]��

				//NETMSG_BALL

				sprintf(Buffer,"%d,",gameframe);
				for(i=0;i<BALL_MAX;i++)
				{

					if(ball[i].enable)//�L���Ȃ��̂̂ݑ���
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







				//�A�C�e�����(�S���̂������Ă�A�C�e���̏�ԂȂǂ�)

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



				////���Ƀv���C���[���ƂɈႤ�f�[�^��]��



				//�C���t�H(�����N�Ƃ����b�v�Ƃ��A�C�e���Ƃ��t�F�[�h�A�E�g�Ƃ�)
				
				for(i=0;i<playercount-1;i++)
				{
					sprintf(Buffer,"%d,%d,%d,%d,%d,%d",player[i+1].lap,player[i+1].rank,
						feed[i+1].count,feed[i+1].countend,feed[i+1].mode,player[i+1].itemkind);

					SetMsg(Buffer,myID,NETMSG_INFO);

					sendto(s, Buffer, (int)strlen(Buffer), 0, (SOCKADDR *)&from[i], (int)sizeof(from[i]));
				}
			}





			if(sel.enable==true && sel.frame==1 && sel.back==true)//�Z���N�g��frame��0�ɂȂ�O�ɏ�������
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

					//���ʉ�����
					SoundReset();

				}
				else if(sel.caption[sel.nowparentsindex].child[sel.nowselectindex]==CAPTION_NEXT)
				{
					stagenum++;

					//�ȃ`�F���W
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

					//���ʉ�����
					SoundReset();
				}
				else
				{
					//�ȃ`�F���W(�I�[�v�j���O)
					ShowSetting(0);
					pMediaControl->Run();
					gamemode=GAMEMODE_TITLE;
					//���ʉ�����
					SoundReset();
				}


				if(sel.caption[sel.nowparentsindex].child[sel.nowselectindex]==CAPTION_BACKSTAGESELECT)
				{
					CallSelect(CALLMODE_STAGESELECT);
					feed[4].Start(FEEDMODE_WHITEIN,40);
					ReplayEnd();
					//���ʉ�����
					SoundReset();
				}
				else if(sel.caption[sel.nowparentsindex].child[sel.nowselectindex]==CAPTION_BACKCHARSELECT)
				{
					CallSelect(CALLMODE_CHARSELECT);
					feed[4].Start(FEEDMODE_WHITEIN,40);
					ReplayEnd();
					//���ʉ�����
					SoundReset();
				}
				else if(sel.caption[sel.nowparentsindex].child[sel.nowselectindex]==CAPTION_OWARU)
				{
					feed[4].Start(FEEDMODE_BLACKIN,60);
					ReplayEnd();
					//���ʉ�����
					SoundReset();
				}




			}



		}
	}



	//�o�[�T�X���A�J�E���g�I����ɉ��y���Đ����鏈��
	if(info.startcounter==1 && stagekind!=SELECTGAME_STAGE)
	{ 
		pMediaControl->Stop();

		//�����߂�
		LONGLONG llPos = 0;
		pMediaSeeking->SetPositions(&llPos, AM_SEEKING_AbsolutePositioning,
									&llPos, AM_SEEKING_NoPositioning);
		pMediaControl->Run();
	}

	//�}���`�v���C���̃N���C�A���g�̏���(INPUT�֌W)

	if(stagekind==SELECTGAME_MULTIPLAY && Setting.Seaver)
	{

		for(i=DIloopend;i<4;i++)
		{
			//���X�V�I�I
			buttonstate[i].jump=false;
			buttonstate[i].item=false;
		}

	}




	//���y���[�v�Đ�(�I������������������x�Đ��I)
	long evCode, param1, param2;
	if(SUCCEEDED(pEvent->GetEvent(&evCode, &param1, &param2, 0)))
	{
		pEvent->FreeEventParams(evCode, param1, param2);
		if ((EC_COMPLETE == evCode))
		{
			pMediaControl->Stop();

			//�����߂�
			LONGLONG llPos = 0;
			pMediaSeeking->SetPositions(&llPos, AM_SEEKING_AbsolutePositioning,
										&llPos, AM_SEEKING_NoPositioning);
			pMediaControl->Run();
		} 
	}





	//3D�T�E���h���X�V
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

		//�v�Z
		static int CommitCount=0;
		CommitCount++;
		if(CommitCount>=Setting.SoundCommit)
		{
			CommitCount=0;
			sd.Listener->CommitDeferredSettings();
		}

	}



	//ESC�L�[�ŏI�����鏈��
	if(DI.key.up[DIK_ESCAPE])
	{
		//if(rootsave || checksave || itemsave)
		//	fclose(rfile);
		end=true;
	}






	////�N���A�X�e�[�W�ϓ�
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



	//�J�����ݒ�
	D3DXMATRIX matView;
	D3DXMATRIX matProj;
	D3DXMatrixPerspectiveFovLH( &matProj, D3DX_PI/3, (float)(4.0/3.0), CAMERA_R/2, 10000.0f );//CAMERA_R/2�͓K��
	DG.Device->SetTransform( D3DTS_PROJECTION, &matProj );






	//-----------------------�����ݒ�------------------------



	//�A���t�@�ݒ�
	DG.Device->SetRenderState (D3DRS_ALPHABLENDENABLE, true);
	DG.Device->SetRenderState( D3DRS_SRCBLEND,  D3DBLEND_SRCALPHA );
	DG.Device->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );



	//�e�N�X�`���t�B���^�����O�ݒ�
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


	//�t�H�O�ݒ�
	DG.Device->SetRenderState( D3DRS_FOGVERTEXMODE,  D3DFOG_NONE );
	DG.Device->SetRenderState( D3DRS_FOGTABLEMODE,   D3DFOG_LINEAR );


	// �e�N�X�`���̃~�b�v�}�b�v�t�B���^��ݒ肷��B
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
		// �~�b�v�}�b�v�ڍ׃��x����ݒ肷��B
		DG.Device->SetTextureStageState( 0, D3DTSS_MIPMAPLODBIAS, *((LPDWORD)(&LODBias)) );
		DG.Device->SetTextureStageState( 1, D3DTSS_MIPMAPLODBIAS, *((LPDWORD)(&LODBias)) );
		DG.Device->SetTextureStageState( 2, D3DTSS_MIPMAPLODBIAS, *((LPDWORD)(&LODBias)) );
		DG.Device->SetTextureStageState( 3, D3DTSS_MIPMAPLODBIAS, *((LPDWORD)(&LODBias)) );
		DG.Device->SetTextureStageState( 4, D3DTSS_MIPMAPLODBIAS, *((LPDWORD)(&LODBias)) );
	}




	//���̑���RenderState�ݒ�
	DG.Device->SetRenderState( D3DRS_ZENABLE, true );
	DG.Device->SetRenderState( D3DRS_LIGHTING, true );

	DG.Device->SetRenderState( D3DRS_SPECULARENABLE,true);



	//���C�g�z�u

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


	//�����_�����O�̈�ݒ�
	
	D3DVIEWPORT8 vp;

	vp.X =0;
	vp.Y =0;
	vp.Width =DG.Adapter.BackBufferWidth;
	vp.Height=DG.Adapter.BackBufferHeight;
	vp.MinZ=0;
	vp.MaxZ=1;

	DG.Device->SetViewport( &vp );





	//------------------------�w�i�h��Ԃ�------------------------



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

			if(playercount==2 || playercount==3)//���̐l�����Ɣw�i�������Ă��܂��̂ŐF������������K�v������
				targetflag=true;
		}
	}

	DG.Device->Clear( 0, NULL, (targetflag ? D3DCLEAR_TARGET : 0) | D3DCLEAR_ZBUFFER | 
								(Setting.ShadeEnable ? D3DCLEAR_STENCIL : 0), backcolor, 1.0f, 0 );





	//------------------------�����_�����O------------------------


	int index;


	//�����_�����O�J�n
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


			//���C�g�ݒ肪�ς���Ă���\��������̂Ŗ߂�
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





		//�r���[�|�[�g��S�̂ɖ߂�
		DG.Device->SetViewport( &vp );

		//Z�o�b�t�@�[�N���A
		DG.Device->Clear( 0, NULL, D3DCLEAR_ZBUFFER, 0, 1.0f, 0 );



		if(gamemode==GAMEMODE_GAME)
		{

			//�C���t�H�����_�����O
			for(index=loopstart;index<=loopend;index++)
			{
				if(stagekind!=SELECTGAME_MULTIPLAY)
					DG.Device->SetViewport( &player[index].vp );
				InfoRender(index);
			}

			//�t�F�[�h�����_�����O
			for(index=loopstart;index<=loopend;index++)
			{
				if(stagekind!=SELECTGAME_MULTIPLAY)
					DG.Device->SetViewport( &player[index].vp );
				feed[index].Render(DG.Device,(int)DG.Adapter.BackBufferWidth,(int)DG.Adapter.BackBufferHeight);
			}

		}



		//�r���[�|�[�g��S�̂ɖ߂�
		DG.Device->SetViewport( &vp );


		//�S�̂̃C���t�H�����_�����O
		if(gamemode==GAMEMODE_GAME)
			InfoRender(-1);

		//�Z���N�g�����_�����O
		SelectRender();

		//�S�̂̃t�F�[�h�����_�����O
		feed[4].Render(DG.Device,(int)DG.Adapter.BackBufferWidth,(int)DG.Adapter.BackBufferHeight);




		////�e�X�g�ŃX�e�[�W�ԍ���\������
		//DG.Device->SetRenderState(D3DRS_ZENABLE,false);
		//DG.Device->SetTransform( D3DTS_WORLD, &D3DXMATRIX(0.1,0,0,0,0,0.1,0,0,0,0,0.1,0,3.2,-2.8,0,1) );
		//char str[100];
		//sprintf(str,"%f",player[0].par*100);
		//InfoNetRender(str);
		//DG.Device->SetRenderState(D3DRS_ZENABLE,true);




		//�����_�����O�I��
		DG.Device->EndScene();

	}


	//�t���b�v�I
	DG.Device->Present( NULL, NULL, hWnd, NULL );


	return true;
}












//---------------------���b�Z�[�W���󂯎��֐�--------------------
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
	//�O�̂��߃_�E����`����
	SendPlayerOut();
	SendSeaverDown();


	GraphicRelease();
	SoundRelease();
	ShowRelease();

	DG.Release();
	DI.Release();

	//���v���C��Temp���폜
	remove("Data/Save/Replay/Temp");
	remove("Data/Save/Replay/RTemp");

	UnregisterClass( AppName, wc.hInstance );

	// ���[�h����DLL(lha)���J�����܂��B
	FreeLibrary(lhalib);
}


//-----------------�O���t�B�b�N�֌W�̃f�[�^�̏�����------------------------
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




	//�{�[���O���t�B�b�N�ǂݍ���
	for(i=0;i<BALLMESH_MAX;i++)
	{
		sprintf(filename,"Data/Object/Ball/Ball%d.x",i+1);

		if(ballmesh[i].Create(DG.Device,filename,Setting.MultiTextureEnable)==false)
			return false;

	}


	//�A�C�e���O���t�B�b�N�ǂݍ���
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


//-----------------�O���t�B�b�N�֌W�̃f�[�^�̊J��------------------------
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


//-----------------�T�E���h�֌W�̃f�[�^�̏�����------------------------
bool SoundSetting()
{

	int i;



	//�T�E���h�ݒ�

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








	//���ʂ̃T�E���h
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



	//�Q�[�����ɍĐ������T�E���h
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

		//���X�i�[�̐ݒ�
		if( FAILED( DS->Get3DListenerInterface( &sd.Listener ) ) )
			return false;

		sd.ListenerParam.dwSize = sizeof(DS3DLISTENER);
		sd.Listener->GetAllParameters( &sd.ListenerParam );

		sd.ListenerParam.flDopplerFactor = 0.8f;
		sd.ListenerParam.flRolloffFactor = 1.5f;




		//3D�T�E���h�̐ݒ�




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













		//�Đ��ʒu�擾
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


//-----------------�T�E���h�֌W�̃f�[�^�̊J��------------------------
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



//-----------------���̑��̂��܂��܂Ȃ̃f�[�^�̏�����------------------------
bool OtherSetting()
{


	//�����W�F�l������
	srnd();

	//�o�[�W����
	Version=1.0f;

	end=false;
	Ghost=true;

	ProjectReset();
	TitleReset();
	SelectSetting();


	gamemode=GAMEMODE_PROJECT;

	//���Ō�ɂ͏���
//	gamemode=GAMEMODE_TITLE;
//	title.frame=710;

	//�}���`�v���C�p�̐ݒ�
	myID=(int)rnd(65536);
	Error=CAPTION_NONE;
	MultiPlayStart=false;
	startend=false;

	//�ގ��̐ݒ�
	int index=MATKIND_CHARA;


	//�L�����N�^�[�̐ݒ�
	character[0].r=1;
	character[0].w=70;
	character[0].power=0.011f*1.5f*60*1.2f;
	character[0].speed=0.33f*2*1.1f;
	character[0].jump=0.15f*7*0.63f;//*3�͂͂����I�I
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



	//�X�e�[�W�p
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
	matstruct[index].bound		=0.9f;//�悭�͂˂��ق����ʔ���
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





	//�A�C�e���o����

	itemkakuritu[ITEMKIND_TAIHOU]=10.0f;
	itemkakuritu[ITEMKIND_FIRE]=8.0f;
	itemkakuritu[ITEMKIND_SHOT]=10.0f;
	itemkakuritu[ITEMKIND_BOMB]=9.0f;
	itemkakuritu[ITEMKIND_MIZU]=5.0f;
	itemkakuritu[ITEMKIND_YUUDOU]=5.0f;
	itemkakuritu[ITEMKIND_GURABI]=6.0f;

	//�v�Z
	itemkakuritusum=0;
	for(int i=1;i<ITEMKIND_MAX;i++)
	{
		itemkakuritusum+=itemkakuritu[i];
		itemkakurituend[i]=itemkakuritusum;
	}

	//�A�C�e���J���[�ݒ�

	itemcolor[ITEMKIND_TAIHOU]=D3DXCOLOR(1.0f,1.0f,1.0f,0.7f);
	itemcolor[ITEMKIND_FIRE]=D3DXCOLOR(1.0f,0.5f,0.5f,0.7f);
	itemcolor[ITEMKIND_SHOT]=D3DXCOLOR(1.0f,1.0f,0.0f,0.7f);
	itemcolor[ITEMKIND_BOMB]=D3DXCOLOR(0.2f,0.2f,0.2f,0.7f);
	itemcolor[ITEMKIND_MIZU]=D3DXCOLOR(0.5f,0.5f,1.0f,0.7f);
	itemcolor[ITEMKIND_GURABI]=D3DXCOLOR(0.2f,0.0f,0.6f,0.7f);
	itemcolor[ITEMKIND_YUUDOU]=D3DXCOLOR(0.4f,0.3f,0.2f,0.7f);




	return true;
}




//---------------------------------�f�[�^�̃Z�[�u�ƃ��[�h----------------------------------------

bool LoadSetting()
{
	int i;

	FILE* file;
	if((file=fopen("data/save/setting","r"))==NULL) return false;

	//��ʂɂ���
	fscanf(file,"%d",&Setting.FullScreen);
	fscanf(file,"%d",&Setting.FormWidth);
	fscanf(file,"%d",&Setting.FormHeight);
	fscanf(file,"%d",&Setting.BufferWidth);
	fscanf(file,"%d",&Setting.BufferHeight);
	fscanf(file,"%d",&Setting.BufferFormat);

	//�O���t�B�b�N�֌W
	fscanf(file,"%d",&Setting.MultiTextureEnable);
	fscanf(file,"%d",&Setting.FiltarEnable);
	fscanf(file,"%d",&Setting.MipmapEnable);
	fscanf(file,"%d",&Setting.MipmapFiltarEnable);
	fscanf(file,"%f",&Setting.MipmapBias); 
	fscanf(file,"%f",&Setting.KemuriMaxDis);
	fscanf(file,"%f",&Setting.ItemMaxDis);
	fscanf(file,"%d",&Setting.EnvEnable);
	fscanf(file,"%d",&Setting.ShadeEnable);

	//�T�E���h�ɂ���
	fscanf(file,"%d",&Setting.BGM);
	bool bgmtemp=Setting.BGM;
	int multicount;
	fscanf(file,"%d",&multicount);
	fscanf(file,"%d",&Setting.Sound3D);
	bool keepsound3d=Setting.Sound3D;
	fscanf(file,"%d",&Setting.SoundAlg);
	fscanf(file,"%d",&Setting.SoundCommit);

	//�l�b�g���[�N
	fscanf(file,"%s",Setting.ip);
	fscanf(file,"%s",Setting.port);
	fscanf(file,"%d",&Setting.IPKeep);
	fscanf(file,"%d",&Setting.PortKeep);

	//���o��
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


	//�������Ȃ��ƂȂ����o�O��
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


	//��ʂɂ���
	fprintf(file,"%d\n",Setting.FullScreen);
	fprintf(file,"%d\n",Setting.FormWidth);
	fprintf(file,"%d\n",Setting.FormHeight);
	fprintf(file,"%d\n",Setting.BufferWidth);
	fprintf(file,"%d\n",Setting.BufferHeight);
	fprintf(file,"%d\n",Setting.BufferFormat);

	//�O���t�B�b�N�֌W
	fprintf(file,"%d\n",Setting.MultiTextureEnable);
	fprintf(file,"%d\n",Setting.FiltarEnable);
	fprintf(file,"%d\n",Setting.MipmapEnable);
	fprintf(file,"%d\n",Setting.MipmapFiltarEnable);
	fprintf(file,"%f\n",Setting.MipmapBias);
	fprintf(file,"%f\n",Setting.KemuriMaxDis);
	fprintf(file,"%f\n",Setting.ItemMaxDis);
	fprintf(file,"%d\n",Setting.EnvEnable);
	fprintf(file,"%d\n",Setting.ShadeEnable);

	//�T�E���h�ɂ���
	fprintf(file,"%d\n",Setting.BGM);
	fprintf(file,"%d\n",Setting.SoundMultiCount);
	fprintf(file,"%d\n",Setting.Sound3D);
	fprintf(file,"%d\n",Setting.SoundAlg);
	fprintf(file,"%d\n",Setting.SoundCommit);

	//�l�b�g���[�N
	fprintf(file,"%s\n",Setting.ip);
	fprintf(file,"%s\n",Setting.port);
	fprintf(file,"%d\n",Setting.IPKeep);
	fprintf(file,"%d\n",Setting.PortKeep);

	//���o��
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

//	���Ō�͂��̃R�����g���͂���
	if(checkfile("data/save/Clear")==false)
	{//�f�[�^������
		MessageBox(NULL,"�Z�[�u�f�[�^���s���ł��B\n������ԂŃQ�[�����X�^�[�g���܂�","�G���[",MB_OK);
		clearstage=0;
		for(int i=0;i<STAGE_MAX+CORCE_MAX;i++)
			hTime[i]=0;
		//�X�^�b�t���[���̐ݒ�
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

	////�`�F�b�N�t�@�C�����쐬
	createcheckfile("data/save/Clear");


	return true;
}
