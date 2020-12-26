//自前で用意したサウンド系の関数たち



bool Create3DSound(SoundStruct3D *sound,char filename[MAX_PATH],DWORD flag,GUID guid)
{

//	DWORD flag;
	//プラスチックバウンド
	if( FAILED(DS->Create( &(*sound).Sound, filename, DSBCAPS_CTRL3D | flag, guid )))
		return false;
	if( FAILED( (*sound).Sound->Get3DBufferInterface( 0, &(*sound).Buffer ) ) )
		return false;
	(*sound).Param.dwSize = sizeof(DS3DBUFFER);
	(*sound).Buffer->GetAllParameters( &(*sound).Param );
	(*sound).Param.flMinDistance = 20;
	(*sound).Param.flMaxDistance = 1000;

	return true;
}



//音源の位置を渡すと再生すべき音量を返してくる関数(プレイヤー全員の位置などを考慮し、一番近いプレイヤーからの音量を調べる)※音量は最大で0
int getvolume(D3DXVECTOR3 vec)
{
	int start=0,end=playercount-1,i;
	float dis,mindis=10000;//mindisに大きな数字を入れておく(手抜きです)

	if(stagekind==SELECTGAME_MULTIPLAY)
		start=end=multiplayernum;

//	start=0,end=0;

	for(i=start;i<=end;i++)
	{
		//音源とカメラの位置で最小のものを探す
		dis=D3DXVec3Length(&(vec-player[i].cpo));
		if(mindis>dis)
			mindis=dis;
	}

	//mindisより、音量を求める(disを結果として使う)
	mindis-=5;
	if(mindis<0) mindis=0;
	dis=mindis*-18;

	return (int)dis;
}

//停止中のサウンドを探す
int stopindex(CSound **cs)
{
	int i;
	for(i=0;i<Setting.SoundMultiCount;i++)
	{
		if(!cs[i]->IsSoundPlaying())
			break;
	}

	if(i==Setting.SoundMultiCount)
	{
		int cursor,cursor2,cursormax=0,maxi=0;
		//一番カーソルが大きいやつを探す
		for(i=0;i<Setting.SoundMultiCount;i++)
		{
			cs[i]->GetBuffer(0)->GetCurrentPosition((LPDWORD)(&cursor),(LPDWORD)(&cursor2));
			if(cursor>cursormax)
			{
				cursormax=cursor;
				maxi=i;
			}
		}
		return maxi;
	}
	else
		return i;
}

//停止中のサウンドを探す(stopindexの3Dバージョン)
int stopindex3d(SoundStruct3D* s3)
{

	int i;
	for(i=0;i<Setting.SoundMultiCount;i++)
	{
		if(!s3[i].Sound->IsSoundPlaying())
			break;
	}

	if(i==Setting.SoundMultiCount)
	{
		int cursor,cursor2,cursormax=0,maxi=0;
		//一番カーソルが大きいやつを探す
		for(i=0;i<Setting.SoundMultiCount;i++)
		{
			s3[i].Sound->GetBuffer(0)->GetCurrentPosition((LPDWORD)(&cursor),(LPDWORD)(&cursor2));
			if(cursor>cursormax)
			{
				cursormax=cursor;
				maxi=i;
			}
		}
		return maxi;
	}
	else
		return i;

}


//種類に応じた効果音の再生
void SoundPlay(int soundkind,int index,float vol,float hz)
{

	int si;

	if(soundkind==SOUNDKIND_SIBA)
	{
		//効果音再生
		if(play3d)
		{
			si=stopindex3d(sd.Izigen3D);
			vol=(vol-1)*5000;
			if(vol>0) vol=0; else if(vol<-10000) vol=-10000;
			if(vol>-2000)
			{
				sd.Siba3D[si].Param.vPosition=ball[index].ball.po-(D3DXVECTOR3)judc.judres.n[0]*ball[index].ball.r;
				sd.Siba3D[si].Param.vVelocity=D3DXVECTOR3(0,0,0);
				sd.Siba3D[si].Buffer->SetAllParameters( &sd.Siba3D[si].Param, DS3D_DEFERRED );
				sd.Siba3D[si].Sound->GetBuffer(0)->SetVolume((int)vol);
 				sd.Siba3D[si].Sound->GetBuffer(0)->SetFrequency( (int)(hz*SOUND_HZ) );
				SOUND_PLAY(sd.Siba3D[si].Sound);
			}
		}
		else
		{
			si=stopindex(sd.Siba);
			vol=(float)(getvolume(ball[index].ball.po-(D3DXVECTOR3)judc.judres.n[0]*ball[index].ball.r)+(int)((vol-1)*5000));
			if(vol>-2000)
			{
				if(vol>0) vol=0;
				sd.Siba[si]->GetBuffer(0)->SetVolume((int)vol);
 				sd.Siba[si]->GetBuffer(0)->SetFrequency( (int)(hz*SOUND_HZ) );
				SOUND_PLAY(sd.Siba[si]);
			}
		}
	}
	else if(soundkind==SOUNDKIND_PURA)
	{

		//効果音再生
		if(play3d)
		{
			si=stopindex3d(sd.Izigen3D);
			vol=(vol-1)*5000;
			if(vol>0) vol=0; else if(vol<-10000) vol=-10000;
			if(vol>-2000)
			{
				sd.Pura3D[si].Param.vPosition=ball[index].ball.po-(D3DXVECTOR3)judc.judres.n[0]*ball[index].ball.r;
				sd.Pura3D[si].Param.vVelocity=D3DXVECTOR3(0,0,0);
				sd.Pura3D[si].Buffer->SetAllParameters( &sd.Pura3D[si].Param, DS3D_DEFERRED );
				sd.Pura3D[si].Sound->GetBuffer(0)->SetVolume((int)vol);
 				sd.Pura3D[si].Sound->GetBuffer(0)->SetFrequency( (int)(hz*SOUND_HZ) );
				SOUND_PLAY(sd.Pura3D[si].Sound);
			}
		}
		else
		{
			si=stopindex(sd.Pura);
			vol=(float)(getvolume(ball[index].ball.po-(D3DXVECTOR3)judc.judres.n[0]*ball[index].ball.r)+(int)((vol-1)*5000));
			if(vol>-2000)
			{
				if(vol>0) vol=0; else if(vol<-10000) vol=-10000;
				sd.Pura[si]->GetBuffer(0)->SetVolume((int)vol);
				sd.Pura[si]->GetBuffer(0)->SetFrequency( (int)(hz*SOUND_HZ) );
				SOUND_PLAY(sd.Pura[si]);
			}
		}
		
	}
	else if(soundkind==SOUNDKIND_TETU)
	{

		//効果音再生
		if(play3d)
		{
			si=stopindex3d(sd.Izigen3D);
			vol=(vol-1)*5000;
			if(vol>0) vol=0; else if(vol<-10000) vol=-10000;
			if(vol>-2000)
			{
				sd.Tetu3D[si].Param.vPosition=ball[index].ball.po-(D3DXVECTOR3)judc.judres.n[0]*ball[index].ball.r;
				sd.Tetu3D[si].Param.vVelocity=D3DXVECTOR3(0,0,0);
				sd.Tetu3D[si].Buffer->SetAllParameters( &sd.Tetu3D[si].Param, DS3D_DEFERRED );
				sd.Tetu3D[si].Sound->GetBuffer(0)->SetVolume((int)vol);
 				sd.Tetu3D[si].Sound->GetBuffer(0)->SetFrequency( (int)(hz*SOUND_HZ) );
				SOUND_PLAY(sd.Tetu3D[si].Sound);
			}
		}
		else
		{
			si=stopindex(sd.Tetu);
			vol=(float)(getvolume(ball[index].ball.po-(D3DXVECTOR3)judc.judres.n[0]*ball[index].ball.r)+(int)((vol-1)*5000));
			if(vol>-2000)
			{
				if(vol>0) vol=0; else if(vol<-10000) vol=-10000;
				sd.Tetu[si]->GetBuffer(0)->SetVolume((int)vol);
 				sd.Tetu[si]->GetBuffer(0)->SetFrequency( (int)(hz*SOUND_HZ) );
				SOUND_PLAY(sd.Tetu[si]);
			}
		}
		
	}
	else if(soundkind==SOUNDKIND_IZIGEN)
	{

		//効果音再生
		if(play3d)
		{
			si=stopindex3d(sd.Izigen3D);
			vol=(vol-1)*5000;
			if(vol>0) vol=0; else if(vol<-10000) vol=-10000;
			if(vol>-2000)
			{
				sd.Izigen3D[si].Param.vPosition=ball[index].ball.po-(D3DXVECTOR3)judc.judres.n[0]*ball[index].ball.r;
				sd.Izigen3D[si].Param.vVelocity=D3DXVECTOR3(0,0,0);
				sd.Izigen3D[si].Buffer->SetAllParameters( &sd.Izigen3D[si].Param, DS3D_DEFERRED );
				sd.Izigen3D[si].Sound->GetBuffer(0)->SetVolume((int)vol);
 				sd.Izigen3D[si].Sound->GetBuffer(0)->SetFrequency( (int)(hz*SOUND_HZ) );
				SOUND_PLAY(sd.Izigen3D[si].Sound);
			}
		}
		else
		{
			si=stopindex(sd.Izigen);
			vol=(float)(getvolume(ball[index].ball.po-(D3DXVECTOR3)judc.judres.n[0]*ball[index].ball.r)+(int)((vol-1)*5000));
			if(vol>-2000)
			{
				if(vol>0) vol=0; else if(vol<-10000) vol=-10000;
				sd.Izigen[si]->GetBuffer(0)->SetVolume((int)vol);
 				sd.Izigen[si]->GetBuffer(0)->SetFrequency( (int)(hz*SOUND_HZ) );
				SOUND_PLAY(sd.Izigen[si]);
			}
		}
		
	}
	else if(soundkind==SOUNDKIND_GOMU)
	{

		//効果音再生
		if(play3d)
		{
			si=stopindex3d(sd.Gomu3D);
			vol=(vol-1)*5000;
			if(vol>0) vol=0; else if(vol<-10000) vol=-10000;
			if(vol>-2000)
			{
				sd.Gomu3D[si].Param.vPosition=ball[index].ball.po-(D3DXVECTOR3)judc.judres.n[0]*ball[index].ball.r;
				sd.Gomu3D[si].Param.vVelocity=D3DXVECTOR3(0,0,0);
				sd.Gomu3D[si].Buffer->SetAllParameters( &sd.Gomu3D[si].Param, DS3D_DEFERRED );
				sd.Gomu3D[si].Sound->GetBuffer(0)->SetVolume((int)vol);
 				sd.Gomu3D[si].Sound->GetBuffer(0)->SetFrequency( (int)(hz*SOUND_HZ) );
				SOUND_PLAY(sd.Gomu3D[si].Sound);
			}
		}
		else
		{
			si=stopindex(sd.Gomu);
			vol=(float)(getvolume(ball[index].ball.po-(D3DXVECTOR3)judc.judres.n[0]*ball[index].ball.r)+(int)((vol-1)*5000));
			if(vol>-2000)
			{
				if(vol>0) vol=0; else if(vol<-10000) vol=-10000;
				sd.Gomu[si]->GetBuffer(0)->SetVolume((int)vol);
 				sd.Gomu[si]->GetBuffer(0)->SetFrequency( (int)(hz*SOUND_HZ) );
				SOUND_PLAY(sd.Gomu[si]);
			}
		}
		
	}







}


void SoundReset()
{

	int i; 

	for(i=0;i<Setting.SoundMultiCount;i++)
	{
		sd.Meka[i]->Stop();
		sd.Meka[i]->Reset();
		if(play3d)
		{
			sd.Yudou3D[i].Sound->Stop();
			sd.Yudou3D[i].Sound->Reset();
			sd.Iwa3D[i].Sound->Stop();
			sd.Iwa3D[i].Sound->Reset();
		}
		else
		{
			sd.Yudou[i]->Stop();
			sd.Yudou[i]->Reset();
			sd.Iwa[i]->Stop();
			sd.Iwa[i]->Reset();
		}
	}

}

