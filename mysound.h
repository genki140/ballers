//���O�ŗp�ӂ����T�E���h�n�̊֐�����



bool Create3DSound(SoundStruct3D *sound,char filename[MAX_PATH],DWORD flag,GUID guid)
{

//	DWORD flag;
	//�v���X�`�b�N�o�E���h
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



//�����̈ʒu��n���ƍĐ����ׂ����ʂ�Ԃ��Ă���֐�(�v���C���[�S���̈ʒu�Ȃǂ��l�����A��ԋ߂��v���C���[����̉��ʂ𒲂ׂ�)�����ʂ͍ő��0
int getvolume(D3DXVECTOR3 vec)
{
	int start=0,end=playercount-1,i;
	float dis,mindis=10000;//mindis�ɑ傫�Ȑ��������Ă���(�蔲���ł�)

	if(stagekind==SELECTGAME_MULTIPLAY)
		start=end=multiplayernum;

//	start=0,end=0;

	for(i=start;i<=end;i++)
	{
		//�����ƃJ�����̈ʒu�ōŏ��̂��̂�T��
		dis=D3DXVec3Length(&(vec-player[i].cpo));
		if(mindis>dis)
			mindis=dis;
	}

	//mindis���A���ʂ����߂�(dis�����ʂƂ��Ďg��)
	mindis-=5;
	if(mindis<0) mindis=0;
	dis=mindis*-18;

	return (int)dis;
}

//��~���̃T�E���h��T��
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
		//��ԃJ�[�\�����傫�����T��
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

//��~���̃T�E���h��T��(stopindex��3D�o�[�W����)
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
		//��ԃJ�[�\�����傫�����T��
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


//��ނɉ��������ʉ��̍Đ�
void SoundPlay(int soundkind,int index,float vol,float hz)
{

	int si;

	if(soundkind==SOUNDKIND_SIBA)
	{
		//���ʉ��Đ�
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

		//���ʉ��Đ�
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

		//���ʉ��Đ�
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

		//���ʉ��Đ�
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

		//���ʉ��Đ�
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

