#ifndef REPLAY_HED
#define REPLAY_HED


//リプレイの保存、読み込み、などに使用する
FILE *WriteReplayFile=NULL;
FILE *ReadReplayFile=NULL;



bool ReplayStart()
{
	if(playercount==1)
	{
		char filename[MAX_PATH];

		if(!replay)
			if((WriteReplayFile=fopen("Data/Save/Replay/Temp","w"))==NULL) return false;
		if(stagekind==SELECTGAME_STAGE)
		{
			if(GetClear())
			{
				sprintf(filename,"Data/Save/Replay/Stage/%d.lzh",stagenum);
				//テストで読み込む
				if((ReadReplayFile=fopen(filename,"r"))==NULL) return false;
				fclose(ReadReplayFile);

				//すでにあるRTempを削除
				remove("Data/Save/Replay/RTemp");
				//解凍して移動
				char command[500];
				sprintf(command,"e %s Data/Save/Replay/ RTemp -n1 -gm1",filename);
				Unlha(NULL, command, "" ,0);

				if((ReadReplayFile=fopen("Data/Save/Replay/RTemp","r"))==NULL) return false;
			}
		}
		if(stagekind==SELECTGAME_VARSUS)
		{
			if(GetClear())
			{
				sprintf(filename,"Data/Save/Replay/Corce/%d.lzh",stagenum);
				//テストで読み込む
				if((ReadReplayFile=fopen(filename,"r"))==NULL) return false;
				fclose(ReadReplayFile);

				//すでにあるRTempを削除
				remove("Data/Save/Replay/RTemp");
				//解凍して移動
				char command[500];
				sprintf(command,"e %s Data/Save/Replay/ RTemp -n1 -gm1",filename);
				Unlha(NULL, command, "" ,0);

				if((ReadReplayFile=fopen("Data/Save/Replay/RTemp","r"))==NULL) return false;
			}
		}


		if(replay)
		{
			fscanf(ReadReplayFile,"%d",&player[0].charnum);
		}
		else if(stagekind!=SELECTGAME_MULTIPLAY)
		{

			if(GetClear())
			{
				fscanf(ReadReplayFile,"%d",&ball[BALL_MAX-1].meshindex);
				if(ball[BALL_MAX-1].meshindex==5) ball[BALL_MAX-1].meshindex=0;
			}

			fprintf(WriteReplayFile,"%d\n",player[0].charnum);
		}

		replayend=false;
	}
	
	return true;
}


void ReplayEnd()//記録、再生終了
{
//	MessageBox(NULL,"リプレイ終了","デバッグ",MB_OK);
	if(ReadReplayFile)
		fclose(ReadReplayFile);
	if(WriteReplayFile)
		fclose(WriteReplayFile);
}

bool ReplayCopy()//一時ファイルからリプレイファイルに保存
{
	char filename[MAX_PATH];


	if(stagekind==SELECTGAME_STAGE)
		sprintf(filename,"Data/Save/Replay/Stage/%d.lzh",stagenum);
	else if(stagekind==SELECTGAME_VARSUS)
		sprintf(filename,"Data/Save/Replay/Corce/%d.lzh",stagenum);
	//すでにあるものの消去
	remove(filename);


	//すでにあるRTempを削除
	remove("Data/Save/Replay/RTemp");
	//Temp→RTempへファイル名を変更
	rename("Data/Save/Replay/Temp","Data/Save/Replay/RTemp");

	//圧縮して移動
	char command[500];
	sprintf(command,"a %s Data/Save/Replay/RTemp -n1 -gm1",filename);
	Unlha(NULL, command, "" ,0);

	//※このチェックファイルはファイルアップロード時にのみ使用する
	createcheckfile(filename);
	
	return true;
	
}




bool readreplaydata()
{

	int i;
	int enable;
	for(i=0;i<BALL_MAX;i++)
	{
		if(fscanf(ReadReplayFile,"%d",&enable)==EOF)
			return false;

		if(enable)
		{
			fscanf(ReadReplayFile,"%f,%f,%f,%f,%f,%f,%f,%f,%f",
				&ball[i].ball.po.x,&ball[i].ball.po.y,&ball[i].ball.po.z,
				&ball[i].ball.mv.x,&ball[i].ball.mv.y,&ball[i].ball.mv.z,
				&ball[i].ball.axis.x,&ball[i].ball.axis.y,&ball[i].ball.axis.z);
			ball[i].enable=true;
		}
		else
			ball[i].enable=false;
	}


	return true;
}

void writereplaydata()
{
	//全てのボールのデータを保存する


	//ファイル構造
	//0番目のボールのEnable
	//0番目のボールがEnableの場合、ボール情報を書き込む
	//BALL_MAX-1まで繰り返し・・・

	int i;
	for(i=0;i<BALL_MAX;i++)
	{
		if(ball[i].enable)
		{
			fprintf(WriteReplayFile,"1\n%f,%f,%f,%f,%f,%f,%f,%f,%f\n",
				ball[i].ball.po.x,ball[i].ball.po.y,ball[i].ball.po.z,
				ball[i].ball.mv.x,ball[i].ball.mv.y,ball[i].ball.mv.z,
				ball[i].ball.axis.x,ball[i].ball.axis.y,ball[i].ball.axis.z);
		}
		else
		{
			fprintf(WriteReplayFile,"0\n");
		}
	}
	

}

bool readreplayGhostdata()
{

	int i;
	static char tempstr[1000];
	int enable;
	for(i=0;i<BALL_MAX;i++)
	{
		if(fscanf(ReadReplayFile,"%d",&enable)==EOF)
			return false;

		if(enable)
		{
			if(i==0)
			{
				fscanf(ReadReplayFile,"%f,%f,%f,%f,%f,%f,%f,%f,%f",
					&ball[BALL_MAX-1].ball.po.x,&ball[BALL_MAX-1].ball.po.y,&ball[BALL_MAX-1].ball.po.z,
					&ball[BALL_MAX-1].ball.mv.x,&ball[BALL_MAX-1].ball.mv.y,&ball[BALL_MAX-1].ball.mv.z,
					&ball[BALL_MAX-1].ball.axis.x,&ball[BALL_MAX-1].ball.axis.y,&ball[BALL_MAX-1].ball.axis.z);
			}
			else
				fscanf(ReadReplayFile,"%s",tempstr);
		}
	}


	return true;
}



#endif
