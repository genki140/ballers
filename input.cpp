#include "input.h"



#include<stdio.h>



BOOL CALLBACK EnumJoyCallback( const DIDEVICEINSTANCE* pdidInstance,
                                     VOID* pContext )
{
	// 列挙されたジョイスティックへのインターフェイスを取得する。
	//コールバックはInputClass内にないので、クラス内の関数に引数を渡し処理させる
	return ((InputClass*)pContext)->JoyEnum( pdidInstance->guidInstance );
}




BOOL CALLBACK EnumAxesCallback( const DIDEVICEOBJECTINSTANCE* pdidoi,
                                VOID* pContext )
{
    DWORD* pdwNumForceFeedbackAxis = (DWORD*) pContext;

    if( (pdidoi->dwFlags & DIDOI_FFACTUATOR) != 0 )
        (*pdwNumForceFeedbackAxis)++;

    return DIENUM_CONTINUE;
}







InputClass::InputClass()
{
	int i,j;

	debug_fp=NULL;

	DI=NULL;
	MDevice=NULL;
	KDevice=NULL;

	for(i=0; i<JOY_MAX; i++)
	{
		JDevice[i]=NULL;
		JEffect[i]=NULL;
		for(j=0;j<EFFECT_MAX;j++)
		{
			effect[i][j].enable=false;
		}
	}

	//初めにボタンを放したことにする
	for(i=0;i<8;i++)
		mouse.Keep[i]=false;

	for(i=0;i<256;i++)
		key.Keep[i]=false;

	for(i=0;i<JOY_MAX;i++)
	{
		for(int j=0;j<2;j++)
			joy[i].Keepx[j]=joy[i].Keepy[j]=0;
		for(int j=0;j<128;j++)
			joy[i].Keep[j]=false;
	}

}

//InputClass::~InputClass()
//{
//	Release();
//}

int InputClass::JoyEnum(GUID guid)
{
	//コントローラをログに記録
	

	if( FAILED( DI->CreateDevice( guid, &JDevice[JoyCount], NULL ) ) )
	{
		//1007.12.8 作成に失敗した場合は次を作成するように修正
		//return DIENUM_STOP;

		fprintf(debug_fp,"FAILED\n");
		return DIENUM_CONTINUE;
	}

	fprintf(debug_fp,"SUCCEED\n" );

	JoyCount++;
	if(JoyCount>JOY_MAX)
		return DIENUM_STOP;
	
	return DIENUM_CONTINUE;
}

//-----------------------------------------------------------------------------
// Name: InitDirectInput()
// Desc: Initialize the DirectInput variables.
//-----------------------------------------------------------------------------
bool InputClass::Create( HWND hWnd, bool Ex, bool Effect[], int count)
{

	DWORD flag=DISCL_FOREGROUND;
	if(Ex) flag |= DISCL_EXCLUSIVE;
	else flag |= DISCL_NONEXCLUSIVE;

	//DirectInput作成
    if( FAILED( DirectInput8Create( GetModuleHandle(NULL), DIRECTINPUT_VERSION, 
                                         IID_IDirectInput8, (VOID**)&DI, NULL ) ) )
        return false;

	//マウスデバイス作成

    if( FAILED( DI->CreateDevice( GUID_SysMouse, &MDevice, NULL ) ) )
        return false;

    if( FAILED( MDevice->SetDataFormat( &c_dfDIMouse2 ) ) )
        return false;

	if( FAILED( MDevice->SetCooperativeLevel( hWnd, flag ) ) )
		return false;


	//キーボードデバイス作成

    if( FAILED( DI->CreateDevice( GUID_SysKeyboard, &KDevice, NULL ) ) ) 
        return false;

    if( FAILED( KDevice->SetDataFormat( &c_dfDIKeyboard ) ) )
        return false;

    if( FAILED( KDevice->SetCooperativeLevel( hWnd, flag ) ) )
		return false;




	debug_fp=fopen("data/input.log","w");

	// ジョイスティックの列挙
	JoyCount = 0;
	if FAILED(
		DI->EnumDevices( DI8DEVCLASS_GAMECTRL, EnumJoyCallback, 
									this, DIEDFL_ATTACHEDONLY ) )
	{
		if(debug_fp!=NULL) fclose(debug_fp);
		return false;
	}




	//ジョイスティックデバイスの設定
	for(int i=0; i<JoyCount; i++)
	{
		if( FAILED( JDevice[i]->SetDataFormat( &c_dfDIJoystick2 ) ) )
		{
			fprintf(debug_fp,"SetDataFormat Error %d\n",i);
			if(debug_fp!=NULL) fclose(debug_fp);
			return false;
		}

		if( FAILED( JDevice[i]->SetCooperativeLevel( hWnd,	DISCL_FOREGROUND | DISCL_EXCLUSIVE ) ) )
		{
			fprintf(debug_fp,"SetCooperativeLevel Error %d\n",i);
			if(debug_fp!=NULL) fclose(debug_fp);
			return false;
		}

		bool ok=false;

		if(i<count)
		{
			if(Effect[i])
				ok=true;
		}

		if(ok)
		{

			//エフェクト関係(振動)


			DWORD           rgdwAxes[2]     = { DIJOFS_X, DIJOFS_Y };
			LONG            rglDirection[2] = { 0, 0 };
			DICONSTANTFORCE cf              = { 0 };

			DIEFFECT eff;



			DWORD TempAxis;


			DIPROPDWORD dipdw;
			dipdw.diph.dwSize       = sizeof(DIPROPDWORD);
			dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
			dipdw.diph.dwObj        = 0;
			dipdw.diph.dwHow        = DIPH_DEVICE;
			dipdw.dwData            = FALSE;

			if( FAILED( JDevice[i]->SetProperty( DIPROP_AUTOCENTER, &dipdw.diph ) ) )
				goto next;

			if ( FAILED( JDevice[i]->EnumObjects( EnumAxesCallback, &TempAxis, DIDFT_AXIS ) ) )
				goto next;

			ZeroMemory( &eff, sizeof(eff) );
			eff.dwSize                  = sizeof(DIEFFECT);
			eff.dwFlags                 = DIEFF_CARTESIAN | DIEFF_OBJECTOFFSETS;
			eff.dwDuration              = INFINITE;
			eff.dwSamplePeriod          = 0;
			eff.dwGain                  = DI_FFNOMINALMAX;
			eff.dwTriggerButton         = DIEB_NOTRIGGER;
			eff.dwTriggerRepeatInterval = 0;
			eff.cAxes                   = 1;
			eff.rgdwAxes                = rgdwAxes;
			eff.rglDirection            = rglDirection;
			eff.lpEnvelope              = 0;
			eff.cbTypeSpecificParams    = sizeof(DICONSTANTFORCE);
			eff.lpvTypeSpecificParams   = &cf;
			eff.dwStartDelay            = 0;

			if( FAILED( JDevice[i]->CreateEffect( GUID_ConstantForce, 
													&eff, &JEffect[i], NULL ) ) )
			{
				goto next;
			}




			continue;
	next:;
			JEffect[i]=NULL;

		}
		

	}

	if(debug_fp!=NULL) fclose(debug_fp);




    return true;
}




VOID InputClass::Release()
{
	if( MDevice )
	{
		MDevice->Unacquire();
		MDevice->Release();
		MDevice=NULL;
	}
	if( KDevice )
	{
		KDevice->Unacquire();
		KDevice->Release();
		KDevice=NULL;
	}

	for(int i=0; i<JOY_MAX; i++)
	{
		if( JDevice[i] )
		{
			JDevice[i]->Unacquire();
			JDevice[i]->Release();
			JDevice[i]=NULL;
		}
		if( JEffect[i] )
		{
			JEffect[i]->Release();
			JEffect[i]=NULL;
		}
	}

	if( DI )
	{
		DI->Release();
		DI=NULL;
	}


}


void InputClass::Acquire()
{
    if ( MDevice )
	    MDevice->Acquire();

	if ( KDevice )
	    KDevice->Acquire();

	for(int i=0; i<JOY_MAX; i++)
	{
		if(JDevice[i])
			JDevice[i]->Acquire();

        if( JEffect[i] ) 
            JEffect[i]->Start( 1, 0 );
	}
}






void InputClass::GetData()
{

	//マウスデータ取得
    if( MDevice != NULL )
    {
        DIMOUSESTATE2 mstate;
        if( SUCCEEDED ( MDevice->GetDeviceState( sizeof(DIMOUSESTATE2), &mstate ) ) )
        {
			mouse.x=mstate.lX;
			mouse.y=mstate.lY;
			mouse.z=mstate.lZ;

			for( int i = 0; i < 8; i++ )
			{
				mouse.press[i] = ( ( mstate.rgbButtons[i] & 0x80 ) == 0x80 );

				mouse.down[i] = (mouse.press[i]==true && mouse.Keep[i]==false);
				mouse.up[i] = (mouse.press[i]==false && mouse.Keep[i]==true);

				mouse.Keep[i]=mouse.press[i];
			}
        }
    }


	//キーボードデータ取得
	if( KDevice != NULL )
    {
		char kstate[256];

        if( SUCCEEDED ( KDevice->GetDeviceState( 256, kstate ) ) )
        {
            for ( int i = 0; i < 256; i++ )
            {
                key.press[i] = ( ( kstate[i] >> 7 ) & 0x01 );

				key.down[i] = (key.press[i]==true && key.Keep[i]==false);
				key.up[i] = (key.press[i]==false && key.Keep[i]==true);

				key.Keep[i]=key.press[i];
			}

        }

	}


	//ジョイスティックデータ取得
	for(int i=0; i<JOY_MAX; i++)
	{
		if( JDevice[i] != NULL && i<JoyCount )
		{
			DIJOYSTATE2 jstate;

			if( SUCCEEDED ( JDevice[i]->GetDeviceState( sizeof(DIJOYSTATE2), &jstate ) ) )
			{
				//前の状態を保存
				joy[i].Keepx[0]=joy[i].x[0];
				joy[i].Keepy[0]=joy[i].y[0];
				joy[i].Keepx[1]=joy[i].x[1];
				joy[i].Keepy[1]=joy[i].y[1];

				//軸(範囲 -10000～10000)
				joy[i].x[0]=(int) ( ((float)jstate.lX - 32768.0) * 0.30517578125);
				joy[i].y[0]=-(int) ( ((float)jstate.lY - 32768.0) * 0.30517578125);

				//ジョイスティック用
				if(false)
				{
					joy[i].x[1]=-(int) ( ((float)jstate.lRz - 32768.0) * 0.30517578125);
					joy[i].y[1]=0;
				}
				else
				{
					joy[i].x[1]=(int) ( ((float)jstate.lZ - 32768.0) * 0.30517578125);
					joy[i].y[1]=-(int) ( ((float)jstate.lRz - 32768.0) * 0.30517578125);
				}



				//POV
				joy[i].keeppov=joy[i].pov;
				if(jstate.rgdwPOV[0] == -1)
					joy[i].pov=-1;
				else
					joy[i].pov=(int)jstate.rgdwPOV[0] / 100;

				for ( int j = 0; j < 128; j++ )
				{
					if(jstate.rgbButtons[j]==0)
						joy[i].press[j]=false;
					else
						joy[i].press[j]=true;

					joy[i].down[j] = (joy[i].press[j]==true && joy[i].Keep[j]==false);
					joy[i].up[j] = (joy[i].press[j]==false && joy[i].Keep[j]==true);

					joy[i].Keep[j]=joy[i].press[j];
				}

			}

		}
		else
		{
			//念のため初期化
			int k;
			for(k=0;k<2;k++)
				joy[i].x[k]=joy[i].y[k]=joy[i].Keepx[k]=joy[i].Keepy[k]=0;
			joy[i].pov=joy[i].keeppov=-1;
			for(k=0;k<128;k++)
				joy[i].down[k]=joy[i].up[k]=joy[i].press[k]=joy[i].Keep[k]=0;
		}

	}


}




void InputClass::SetEffect(int index,float size,int frame,float lastsize)
{
	if(index<0 || index>=JOY_MAX) return;
	
	int i;
	for(i=0;i<EFFECT_MAX;i++)
	{
		if(	effect[index][i].enable==false )
		{
			if(size<0) size=0;
			else if(size>1) size=1;
			if(lastsize<0) lastsize=0;
			else if(lastsize>1) lastsize=1;

			effect[index][i].enable=true;

			effect[index][i].fastsize=size;
			if(lastsize==-1)
				effect[index][i].lastsize=size;
			else
				effect[index][i].lastsize=lastsize;

			effect[index][i].startframe=effect[index][i].nowframe=frame;

			break;
		}
	}
}

void InputClass::Move()
{

    LONG rglDirection = 0;
    DICONSTANTFORCE cf;

	DIEFFECT eff;
	ZeroMemory( &eff, sizeof(eff) );
	eff.dwSize                = sizeof(DIEFFECT);
	eff.dwFlags               = DIEFF_CARTESIAN | DIEFF_OBJECTOFFSETS;
	eff.cAxes                 = 1;
	eff.rglDirection          = &rglDirection;
	eff.lpEnvelope            = 0;
	eff.cbTypeSpecificParams  = sizeof(DICONSTANTFORCE);
	eff.lpvTypeSpecificParams = &cf;
	eff.dwStartDelay            = 0;


	static float keep[JOY_MAX];

	int i,j;
	float sum;//振動の合計
	for(i=0;i<JoyCount;i++)
	{
		if(JDevice[i] && JEffect[i])//エフェクトが存在したら
		{
			sum=0;

			for(j=0;j<EFFECT_MAX;j++)
			{
				if(effect[i][j].enable)
				{

					effect[i][j].nowframe--;
					if(effect[i][j].nowframe<=0)
						effect[i][j].enable=false;

					sum+=effect[i][j].lastsize+(effect[i][j].fastsize-effect[i][j].lastsize)
												*effect[i][j].nowframe/effect[i][j].startframe;

				}
			}

			if(sum>1)sum=1;
			
			if(keep[i]+0.05f<sum || keep[i]-0.05f>sum || (keep[i]!=0 && sum==0) || (keep[i]!=1 && sum==1))
			{
				keep[i]=sum;

				cf.lMagnitude = (int)(sum*(float)DI_FFNOMINALMAX);
				JEffect[i]->SetParameters( &eff, DIEP_DIRECTION | DIEP_TYPESPECIFICPARAMS | DIEP_START );
			}
		}
	}

}


