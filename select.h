#ifndef SELECT_HED
#define SELECT_HED



//�v���O���������G�ɂȂ�Ƃ���Ȃ̂ŁA�����e�N�X�`���ł����x���ǂݍ��܂��邱�Ƃ�����
enum {	CAPTION_NONE=-1,CAPTION_GAMESELECT,CAPTION_STAGESELECT,CAPTION_CHARSELECT,CAPTION_NINZUUSELECT,
		CAPTION_ONE,CAPTION_TWO,CAPTION_THREE,CAPTION_FOUR,CAPTION_OWARU,
		CAPTION_VARSUS,CAPTION_STAGE,CAPTION_EXSTAGE,
		CAPTION_P1,CAPTION_P2,CAPTION_P3,CAPTION_P4,
		CAPTION_CHARTEX,CAPTION_CHARTEXEND=CAPTION_CHARTEX+4,CAPTION_STAGETEX,CAPTION_STAGETEXEND=CAPTION_STAGETEX+STAGE_MAX-1,
		CAPTION_CORCETEX,CAPTION_CORCETEXEND=CAPTION_CORCETEX+CORCE_MAX-1,
		CAPTION_STOP,CAPTION_RETRY,CAPTION_NEXT,
		CAPTION_BACKSTAGESELECT,CAPTION_BACKCHARSELECT,

		CAPTION_REPLAY,CAPTION_REPLAYSELECT,CAPTION_REPLAYSTAGE,CAPTION_REPLAYEXSTAGE,CAPTION_REPLAYVARSUS,

		CAPTION_NETSETTING,CAPTION_MULTIPLAY,CAPTION_SERVER,CAPTION_CLIENT,CAPTION_IP,CAPTION_PORT,CAPTION_KETTEI,CAPTION_HENKOU,
		CAPTION_INFO,CAPTION_BAR,CAPTION_SELECTING,CAPTION_CHAR1,CAPTION_CHAR2,CAPTION_CHAR3,CAPTION_CHAR4,CAPTION_CHAR5,

		CAPTION_ERROR,CAPTION_NINZUUERROR,CAPTION_SETUZOKUERROR,CAPTION_SEAVERERROR,

		CAPTION_MAX};


enum {	SELECTGAME_STAGE,SELECTGAME_VARSUS,SELECTGAME_MULTIPLAY,SELECTGAME_END };
enum {	CAPTIONKIND_PARENTS,CAPTIONKIND_CHILD,CAPTIONKIND_CAPTION};
enum {	SELECTMODE_X,SELECTMODE_Y,SELECTMODE_Z};
enum {  CALLMODE_GAMESELECT,CALLMODE_CHARSELECT,CALLMODE_STAGESELECT,CALLMODE_INFO,//�I�[�v�j���O�ł̌Ăяo��
		CALLMODE_GAME};//�Q�[�����̌Ăяo����



//�����f�[�^
struct CaptionStruct
{
	char filename[MAX_PATH];

	int kind;//PARENTS�͐e(��ԏ�ɕ\���������)�ŁACHILD�͕��ʂɑI�������ACAPTION�͂����̕���(�I�����邱�Ƃ��ł��Ȃ�)

	bool mini;//���������傫����(�e�N�X�`���̃T�C�Y�ɂ͂Q�i�K����)

	int childcount;//kind��parents�̎��̂ݎg�p�Achild�̐����w��
	int child[4];//kind��parents�̎��Achild�̃C���f�b�N�X���w��

	int jump;//kind��child�̎��Aparents�̃C���f�b�N�X���w��

	LPDIRECT3DTEXTURE8 tex;//�e�N�X�`��

};



//�Z���N�g�֌W�̕ϐ����܂Ƃ߂��\���̂̒�`
struct SelectStruct
{
	bool enable;//�o�Ă邩�o�ĂȂ���

	int nowparentsindex;//���݂̐eCaption�̃C���f�b�N�X
	int nowselectindex;//���݂̑I���C���f�b�N�X

	CaptionStruct caption[CAPTION_MAX];

	MeshClass mesh;//�̃��b�V��

//	CSound* sound;

	LPDIRECT3DTEXTURE8 selecttex;//�Z���N�g�J�[�\���e�N�X�`��

	int frame;
	int selectmode;
	bool back;

	float ang;


//	bool blackfeed;//�I���̂Ƃ��̂݃u���b�N�t�F�[�h
//	int feed;

	bool across;//�c�I�������I����

	int callframe;//���ԍ��ŌĂяo�����Ƃ��Ɏg��
	int callmode;
}sel;










bool GetClear()//���݃v���C���Ă���X�e�[�W�̓N���A���Ă��邩��Ԃ�
{
	if(stagekind==SELECTGAME_STAGE)
	{
		if(hTime[stagenum]!=0)
			return true;
	}
	else if(stagekind!=SELECTGAME_STAGE)
	{
		if(hTime[stagenum+STAGE_MAX]!=0)
			return true;
	}

	return false;
}









bool CallSelect(int callmode,int callframe=0);

bool CallSelect(int callmode,int callframe)//���Ăяo���I(frame�͎��ԍ��ŌĂяo�������Ƃ��Ɏg��)
{

	if(sel.callframe!=0)
		return false;
	
	if(callframe!=0)
	{
		sel.callframe=callframe;
		sel.callmode=callmode;
		return true;
	}

	sel.enable=true;

	sel.ang=0;

	sel.nowselectindex=0;

	sel.frame=29;//��������J�E���g�_�E������A�؂̔��߂��Ă���A�j���[�V�������n�܂�
	sel.selectmode=SELECTMODE_X;//X���ɉ�]
	sel.back=false;//���ǂ��ĂȂ����Ƃɂ���(�A�j���[�V�����͖߂�)

//	sel.feed=0;//�t�F�[�h�A�E�g���Ȃ�


	//callmode�ɂ���ăZ���N�g���ڂȂǂ̐ݒ�


	if(callmode==CALLMODE_GAMESELECT)
	{
		sel.nowparentsindex=CAPTION_GAMESELECT;

		sel.caption[CAPTION_GAMESELECT].childcount=1;

		if(clearstage>=NORMALSTAGE_COUNT)
		{
			sel.caption[CAPTION_GAMESELECT].child[sel.caption[CAPTION_GAMESELECT].childcount]=CAPTION_EXSTAGE;
			sel.caption[CAPTION_GAMESELECT].childcount++;
		}

		if(clearstage>=NORMALSTAGE_COUNT)
		{
			sel.caption[CAPTION_GAMESELECT].child[sel.caption[CAPTION_GAMESELECT].childcount]=CAPTION_VARSUS;
			sel.caption[CAPTION_GAMESELECT].childcount++;
		}
		if(clearstage>0)
		{
			sel.caption[CAPTION_GAMESELECT].child[sel.caption[CAPTION_GAMESELECT].childcount]=CAPTION_REPLAY;
			sel.caption[CAPTION_GAMESELECT].childcount++;
			
		}

		//if(clearstage>=20)
		//{
		//	sel.caption[CAPTION_GAMESELECT].child[sel.caption[CAPTION_GAMESELECT].childcount]=CAPTION_MULTIPLAY;
		//	sel.caption[CAPTION_GAMESELECT].childcount++;
		//}

		sel.caption[CAPTION_GAMESELECT].child[sel.caption[CAPTION_GAMESELECT].childcount]=CAPTION_OWARU;
		sel.caption[CAPTION_GAMESELECT].childcount++;
	}
	else if(callmode==CALLMODE_CHARSELECT)
	{
		sel.nowparentsindex=CAPTION_CHARSELECT;
		sel.nowselectindex=player[0].charnum;
		sel.caption[sel.nowparentsindex].child[0]=CAPTION_P1;
	}
	else if(callmode==CALLMODE_STAGESELECT)
	{
		sel.nowselectindex=stagenum;
		sel.nowparentsindex=CAPTION_STAGESELECT;
	}

	else if(callmode==CALLMODE_GAME)//�Q�[����
	{
		sel.nowparentsindex=CAPTION_STOP;

		if(replay)
		{
			sel.caption[CAPTION_STOP].child[1]=CAPTION_BACKSTAGESELECT;
			sel.caption[CAPTION_STOP].child[2]=CAPTION_OWARU;
			sel.caption[CAPTION_STOP].childcount=3;
		}
		else if(stagekind==SELECTGAME_STAGE)
		{
			if(clearstage==stagenum || stagenum==29)
			{
				sel.caption[CAPTION_STOP].childcount=3;
				sel.caption[CAPTION_STOP].child[1]=CAPTION_BACKSTAGESELECT;
				sel.caption[CAPTION_STOP].child[2]=CAPTION_OWARU;
			}
			else
			{
				sel.caption[CAPTION_STOP].childcount=4;
				sel.caption[CAPTION_STOP].child[1]=CAPTION_NEXT;
				sel.caption[CAPTION_STOP].child[2]=CAPTION_BACKSTAGESELECT;
				sel.caption[CAPTION_STOP].child[3]=CAPTION_OWARU;
			}
		}
		else
		{
			if(clearstage/5*3-1==stagenum)
			{
				sel.caption[CAPTION_STOP].childcount=4;
				sel.caption[CAPTION_STOP].child[1]=CAPTION_BACKSTAGESELECT;
				sel.caption[CAPTION_STOP].child[2]=CAPTION_BACKCHARSELECT;
				sel.caption[CAPTION_STOP].child[3]=CAPTION_OWARU;
			}
			else
			{
				sel.caption[CAPTION_STOP].childcount=5;
				sel.caption[CAPTION_STOP].child[1]=CAPTION_NEXT;
				sel.caption[CAPTION_STOP].child[2]=CAPTION_BACKSTAGESELECT;
				sel.caption[CAPTION_STOP].child[3]=CAPTION_BACKCHARSELECT;
				sel.caption[CAPTION_STOP].child[4]=CAPTION_OWARU;
			}
		}
	}
	else if(callmode=-CALLMODE_INFO)
	{
		sel.nowparentsindex=CAPTION_INFO;
	}
	return true;
}






//�ݒ�
void SelectSetting()
{
	int i;


	sel.enable=false;
	sel.callframe=0;

	//�L���v�V�����̐ݒ�

	for(i=0;i<CAPTION_MAX;i++)
		sel.caption[i].mini=false;


	int index;

	index=CAPTION_GAMESELECT;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/GameSelect");
	sel.caption[index].kind=CAPTIONKIND_PARENTS;
	sel.caption[CAPTION_GAMESELECT].child[0]=CAPTION_STAGE;


	index=CAPTION_STAGESELECT;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/StageSelect");
	sel.caption[index].kind=CAPTIONKIND_PARENTS;
	sel.caption[index].childcount=0;

	index=CAPTION_CHARSELECT;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/CharSelect");
	sel.caption[index].kind=CAPTIONKIND_PARENTS;
	sel.caption[index].childcount=1;
	sel.caption[index].child[0]=CAPTION_P1;

	index=CAPTION_NINZUUSELECT;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/NinzuuSelect");
	sel.caption[index].kind=CAPTIONKIND_PARENTS;
	sel.caption[index].childcount=4;
	sel.caption[index].child[0]=CAPTION_ONE;
	sel.caption[index].child[1]=CAPTION_TWO;
	sel.caption[index].child[2]=CAPTION_THREE;
	sel.caption[index].child[3]=CAPTION_FOUR;

	index=CAPTION_ONE;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/One");
	sel.caption[index].kind=CAPTIONKIND_CHILD;
	sel.caption[index].mini=true;

	index=CAPTION_TWO;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/Two");
	sel.caption[index].kind=CAPTIONKIND_CHILD;
	sel.caption[index].mini=true;

	index=CAPTION_THREE;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/Three");
	sel.caption[index].kind=CAPTIONKIND_CHILD;
	sel.caption[index].mini=true;

	index=CAPTION_FOUR;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/Four");
	sel.caption[index].kind=CAPTIONKIND_CHILD;
	sel.caption[index].mini=true;

	index=CAPTION_OWARU;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/Owaru");
	sel.caption[index].kind=CAPTIONKIND_CHILD;
	sel.caption[index].mini=true;

	index=CAPTION_STAGE;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/Stage");
	sel.caption[index].kind=CAPTIONKIND_CHILD;
	sel.caption[index].mini=true;

	index=CAPTION_EXSTAGE;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/ExStage");
	sel.caption[index].kind=CAPTIONKIND_CHILD;

	index=CAPTION_VARSUS;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/Varsus");
	sel.caption[index].kind=CAPTIONKIND_CHILD;
	sel.caption[index].mini=true;

	index=CAPTION_P1;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/P1");
	sel.caption[index].kind=CAPTIONKIND_CAPTION;

	index=CAPTION_P2;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/P2");
	sel.caption[index].kind=CAPTIONKIND_CAPTION;

	index=CAPTION_P3;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/P3");
	sel.caption[index].kind=CAPTIONKIND_CAPTION;

	index=CAPTION_P4;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/P4");
	sel.caption[index].kind=CAPTIONKIND_CAPTION;




	index=CAPTION_STOP;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/Stop");
	sel.caption[index].kind=CAPTIONKIND_PARENTS;
	sel.caption[index].child[0]=CAPTION_RETRY;
	sel.caption[index].child[1]=CAPTION_NEXT;
	sel.caption[index].child[2]=CAPTION_BACKSTAGESELECT;
	sel.caption[index].mini=true;

	index=CAPTION_RETRY;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/Retry");
	sel.caption[index].kind=CAPTIONKIND_CHILD;
	sel.caption[index].mini=true;

	index=CAPTION_NEXT;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/Next");
	sel.caption[index].kind=CAPTIONKIND_CHILD;

	index=CAPTION_BACKSTAGESELECT;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/StageSelect");
	sel.caption[index].kind=CAPTIONKIND_CHILD;

	index=CAPTION_BACKCHARSELECT;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/CharSelect");
	sel.caption[index].kind=CAPTIONKIND_CHILD;





	index=CAPTION_REPLAY;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/RePlay");
	sel.caption[index].kind=CAPTIONKIND_CHILD;
	sel.caption[index].mini=true;

	index=CAPTION_REPLAYSELECT;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/RePlaySelect");
	sel.caption[index].kind=CAPTIONKIND_PARENTS;
	sel.caption[index].child[0]=CAPTION_REPLAYSTAGE;
	sel.caption[index].child[1]=CAPTION_REPLAYEXSTAGE;
	sel.caption[index].child[2]=CAPTION_REPLAYVARSUS;

	index=CAPTION_REPLAYSTAGE;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/RePlayStage");
	sel.caption[index].kind=CAPTIONKIND_CHILD;
	sel.caption[index].mini=true;

	index=CAPTION_REPLAYEXSTAGE;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/RePlayExStage");
	sel.caption[index].kind=CAPTIONKIND_CHILD;

	index=CAPTION_REPLAYVARSUS;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/RePlayVarsus");
	sel.caption[index].kind=CAPTIONKIND_CHILD;
	sel.caption[index].mini=true;




	index=CAPTION_NETSETTING;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/NetSetting");
	sel.caption[index].kind=CAPTIONKIND_PARENTS;
	sel.caption[index].child[0]=CAPTION_SERVER;
	sel.caption[index].child[1]=CAPTION_CLIENT;
	sel.caption[index].childcount=2;

	index=CAPTION_SERVER;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/Seaver");
	sel.caption[index].kind=CAPTIONKIND_CHILD;
	sel.caption[index].mini=true;

	index=CAPTION_CLIENT;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/Client");
	sel.caption[index].kind=CAPTIONKIND_CHILD;
	sel.caption[index].mini=true;




	index=CAPTION_IP;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/IP");
	sel.caption[index].kind=CAPTIONKIND_PARENTS;
	sel.caption[index].child[0]=CAPTION_NONE;
	sel.caption[index].childcount=1;

	index=CAPTION_PORT;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/Port");
	sel.caption[index].kind=CAPTIONKIND_PARENTS;
	sel.caption[index].child[0]=CAPTION_NONE;
	sel.caption[index].childcount=1;




	index=CAPTION_MULTIPLAY;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/MultiPlay");
	sel.caption[index].kind=CAPTIONKIND_CHILD;

	index=CAPTION_KETTEI;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/Kettei");
	sel.caption[index].kind=CAPTIONKIND_CHILD;
	sel.caption[index].mini=true;

	index=CAPTION_HENKOU;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/Henkou");
	sel.caption[index].kind=CAPTIONKIND_CHILD;
	sel.caption[index].mini=true;

	index=CAPTION_INFO;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/Info");
	sel.caption[index].kind=CAPTIONKIND_PARENTS;




	index=CAPTION_BAR;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/Bar");
	sel.caption[index].kind=CAPTIONKIND_CHILD;
	sel.caption[index].mini=true;

	index=CAPTION_SELECTING;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/Selecting");
	sel.caption[index].kind=CAPTIONKIND_CHILD;
	sel.caption[index].mini=true;


	index=CAPTION_CHAR1;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/Char1");
	sel.caption[index].kind=CAPTIONKIND_CHILD;
	sel.caption[index].mini=true;

	index=CAPTION_CHAR2;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/Char2");
	sel.caption[index].kind=CAPTIONKIND_CHILD;
	sel.caption[index].mini=true;

	index=CAPTION_CHAR3;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/Char3");
	sel.caption[index].kind=CAPTIONKIND_CHILD;
	sel.caption[index].mini=true;

	index=CAPTION_CHAR4;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/Char4");
	sel.caption[index].kind=CAPTIONKIND_CHILD;
	sel.caption[index].mini=true;

	index=CAPTION_CHAR5;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/Char5");
	sel.caption[index].kind=CAPTIONKIND_CHILD;
	sel.caption[index].mini=true;



	index=CAPTION_ERROR;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/Error");
	sel.caption[index].childcount=1;
	sel.caption[index].kind=CAPTIONKIND_PARENTS;
	sel.caption[index].mini=true;


	index=CAPTION_SETUZOKUERROR;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/SetuzokuError");
	sel.caption[index].kind=CAPTIONKIND_CHILD;

	index=CAPTION_NINZUUERROR;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/NinzuuError");
	sel.caption[index].kind=CAPTIONKIND_CHILD;

	index=CAPTION_SEAVERERROR;
	strcpy(sel.caption[index].filename,"Data/Graphic/Select/SeaverError");
	sel.caption[index].kind=CAPTIONKIND_CHILD;



	for(i=0;i<5;i++)
	{
		index=CAPTION_CHARTEX+i;
		sprintf(sel.caption[index].filename,"Data/Graphic/Select/Char/%d",i+1);
	}

	for(i=0;i<STAGE_MAX;i++)
	{
		index=CAPTION_STAGETEX+i;
		sprintf(sel.caption[index].filename,"Data/Graphic/Select/Stages/%d",i+1);
	}

	for(i=0;i<CORCE_MAX;i++)
	{
		index=CAPTION_CORCETEX+i;
		sprintf(sel.caption[index].filename,"Data/Graphic/Select/Corces/%d",i+1);
	}
}


bool SelectGraphicSetting()
{
	if(sel.mesh.Create(DG.Device,"data/object/Select/Kanban.x",Setting.MultiTextureEnable)==false)
		return false;

	//������e�N�X�`���ǂݍ���
	int i;
	for(i=0;i<CAPTION_MAX;i++)
	{
		if(!DG.CreateTexture(&sel.caption[i].tex,sel.caption[i].filename))
			return false;
	}

	if(!DG.CreateTexture(&sel.selecttex,"Data/Graphic/Select/Select")) return false;


	return true;
}

void SelectGraphicRelease()
{
	int i;
	sel.mesh.Release();

	if(sel.selecttex!=NULL)
	{
		sel.selecttex->Release();
		sel.selecttex=NULL;
	}

	for(i=0;i<CAPTION_MAX;i++)
	{
		if(sel.caption[i].tex!=NULL)
		{
  			sel.caption[i].tex->Release();
			sel.caption[i].tex=NULL;
		}
	}

}





void changeselect(bool down,bool across=true)//�㉺�Z���N�g(���E�̂Ƃ�������A���̂Ƃ���true�ŉE��)(across��false�̂Ƃ��A�㉺�I��)
{
	if(sel.frame==0)//�A�j���[�V�������łȂ����
	{

		switch(sel.nowparentsindex)//���݂̐e�����񂪁E�E�E
		{
		case CAPTION_GAMESELECT:
		case CAPTION_NINZUUSELECT:
		case CAPTION_STOP:
		case CAPTION_REPLAYSELECT:
		case CAPTION_NETSETTING:
			//���ʂ̑I��

			SOUND_PLAY(sd.Select);

			if(down)
			{
				if(sel.caption[sel.nowparentsindex].childcount<=sel.nowselectindex+1)//�J�[�\������ԉ��܂ŗ��Ă���
				{
					//��ԏ�̕����͎q�H
					if(sel.caption[sel.caption[sel.nowparentsindex].child[0]].kind==CAPTIONKIND_CHILD)
					{
						sel.nowselectindex=0;//��ԏ��I������
					}
					else
					{
						sel.nowselectindex=1;//��ԏォ������I������
					}

				}
				else
					sel.nowselectindex++;//�����I������
			}
			else
			{
				//��ԏォ�A�オ�q����Ȃ��Ƃ�
				if(sel.nowselectindex==0 || (sel.nowselectindex==1 && sel.caption[sel.caption[sel.nowparentsindex].child[0]].kind!=CAPTIONKIND_CHILD))
					sel.nowselectindex=sel.caption[sel.nowparentsindex].childcount-1;//��ԉ���I������
				else
					sel.nowselectindex--;//����I������
			}

			if(sel.nowparentsindex==CAPTION_NINZUUSELECT && stagekind==SELECTGAME_MULTIPLAY)
			{//�}���`�v���C���l���Z���N�g
				if(sel.nowselectindex==0)
				{
					if(down)
					{
						sel.nowselectindex=1;
					}
					else
					{
						sel.nowselectindex=3;
					}
				}
			}

			break;


		case CAPTION_CHARSELECT:

			//��x�I�񂾃L�����͎g���Ȃ�


			sel.frame =60;
			sel.selectmode=SELECTMODE_Y;
			sel.back=!down;

			//���ʉ��Đ�
			if(sel.frame==60)
				sd.RotaStart->Play();

			break;

		case CAPTION_STAGESELECT:


			sel.frame =60;
			sel.selectmode=SELECTMODE_Y;
			sel.back=!down;
			sel.across=across;

			//���ʉ��Đ�
			if(sel.frame==60)
				sd.RotaStart->Play();

			break;


		}
		

	}

}

void setokcancel(bool ok)//����ƃL�����Z��
{
	int i;
//	bool black=false;//�L�����N�^�[�������\�����邩�𒲂ׂ�Ƃ��Ɏg����Ɨp�ϐ�

	if(sel.frame==0)//�A�j���[�V�������ĂȂ�������
	{

		if(ok)//����L�[
		{
			sel.back=false;
			sel.frame=60;
			sel.selectmode=SELECTMODE_Z;

			int child0 = sel.caption[sel.nowparentsindex].child[0];//�ϐ����ȗ��p�ϐ�(��ԏ�̎q�̃C���f�b�N�X���i�[)

			int oldcount;

			switch(sel.nowparentsindex)//���݂̐e�����񂪁E�E�E
			{

			case CAPTION_GAMESELECT:
				if(sel.nowparentsindex==CAPTION_STAGE || sel.nowparentsindex==CAPTION_EXSTAGE)
					stagekind=SELECTGAME_STAGE;
				else if(sel.nowparentsindex==CAPTION_VARSUS)
					stagekind=SELECTGAME_VARSUS;

				else if(sel.caption[CAPTION_GAMESELECT].child[sel.nowselectindex]==CAPTION_OWARU)
				{
					//�I������
					stagekind=SELECTGAME_END;
					sel.selectmode=SELECTMODE_X;
					sel.back=true;
					feed[4].Start(FEEDMODE_BLACKOUT,60);
//					sel.feed=1;
				}

				break;


			case CAPTION_CHARSELECT:



				//��x�I�񂾃L�����͎g���Ȃ�


				player[child0-CAPTION_P1].charnum=sel.nowselectindex;

				if(stagekind==SELECTGAME_MULTIPLAY)
					if(Setting.Seaver)
						SendAllPlayerInfo(playercount);
					else
						SendMyPlayerInfo();


				break;

			case CAPTION_STAGESELECT:
				{
					int realstagenum=sel.nowselectindex;


					//���łɐ��삳��Ă���X�e�[�W���𒲂ׂ�
					char xfilename[MAX_PATH];

					if(stagekind==SELECTGAME_STAGE)
						sprintf(xfilename,"Data/Object/Stage/%d.x",realstagenum+1);
					else
						sprintf(xfilename,"Data/Object/Corce/%d.x",realstagenum+1);
					FILE *fp=fopen(xfilename,"r");
					if(fp==NULL)
					{
						sel.frame=0;
						break;
					}
					fclose(fp);



					if(stagekind!=SELECTGAME_MULTIPLAY)
					{





						if(replay)
						{
							if(stagekind==SELECTGAME_STAGE)
							{
								if(hTime[realstagenum]==0)
								{//�x����

									sel.frame=0;
									break;
								}
							}
							else if(stagekind==SELECTGAME_VARSUS)
							{
								if(hTime[realstagenum+STAGE_MAX]==0)
								{//�x����

									sel.frame=0;
									break;
								}
							}
						}

						stagenum=realstagenum;
						sel.selectmode=SELECTMODE_X;
						sel.back=true;

						feed[4].Start(FEEDMODE_WHITEOUT,60);

					}
					else
					{
						stagenum=realstagenum;
						SendAllPlayerInfo(playercount);
					}
				}

				break;


			case CAPTION_NINZUUSELECT:


				oldcount=playercount;
				playercount=sel.nowselectindex+1;

				if(stagekind==SELECTGAME_MULTIPLAY)
				{

					for(i=playercount-1;i<4;i++)
						fromID[i]=-1;

					SendAllPlayerInfo(oldcount);

				}

				break;





			case CAPTION_PORT:

				
				//�N���C�A���g��������
				if(!Setting.Seaver)
				{
//					AddOK=false;
					if(SetNetwork())
					{
						Error=CAPTION_ERROR;//����͓��ʂȎg�����A�|�[�g��ʂ���ړ��̍ہA�ω����Ȃ����SETUZOKUERROR�ɂ���
					}
					else
					{//�G���[��ʂփW�����v
						Error=CAPTION_SETUZOKUERROR;
					}
				}



				break;




			case CAPTION_STOP:
				{

					//���̃X�e�[�W������������L�����Z��

					if(sel.caption[sel.nowparentsindex].child[sel.nowselectindex]==CAPTION_NEXT)
					{
						//���łɐ��삳��Ă���X�e�[�W���𒲂ׂ�
						char xfilename[MAX_PATH];

						if(stagekind==SELECTGAME_STAGE)
							sprintf(xfilename,"Data/Object/Stage/%d.x",stagenum+2);
						else
							sprintf(xfilename,"Data/Object/Corce/%d.x",stagenum+2);
						FILE *fp=fopen(xfilename,"r");
						if(fp==NULL)
						{
							sel.frame=0;
							break;
						}
						fclose(fp);
					}

					if(sel.caption[sel.nowparentsindex].child[sel.nowselectindex]!=CAPTION_OWARU)
						feed[4].Start(FEEDMODE_WHITEOUT,60);
					else
						feed[4].Start(FEEDMODE_BLACKOUT,60);

					sel.selectmode=SELECTMODE_X;
					sel.back=true;

					break;

				}
			case CAPTION_INFO:

				multiplayreadymy=!multiplayreadymy;
				//���ʉ��Đ�
				SOUND_PLAY(sd.Select);

//				if(sel.caption[CAPTION_INFO].child[playercount]==CAPTION_KETTEI)
				//if(multiplayreadymy==true)
				//{
				//	sel.caption[CAPTION_INFO].child[playercount]=CAPTION_HENKOU;
				//	if(!Setting.Seaver) Sendokcancel(true);
				//}
				//else
				//{
				//	sel.caption[CAPTION_INFO].child[playercount]=CAPTION_KETTEI;
				//	if(!Setting.Seaver) Sendokcancel(false);
				//}

				sel.frame=0;

				break;
			
			case CAPTION_ERROR:

				sel.back=true;
				break;

			}


		}
		else//�L�����Z���L�[
		{
			if(sel.nowparentsindex==CAPTION_GAMESELECT)
			{
				sel.frame=60;
				sel.selectmode=SELECTMODE_X;
				sel.back=true;
			}
			else if(sel.nowparentsindex==CAPTION_STOP)//�X�g�b�v�̂Ƃ��͉��ɖ߂�
			{
				if(autostop==false)
				{
					sel.nowselectindex=-1;//���������Ă������ƂŃL�����Z�����ꂽ���Ƃ𔻒f����
					sel.frame=60;
					sel.selectmode=SELECTMODE_X;
					sel.back=true;
				}
			}
			else
			{

				sel.frame=60;
				sel.selectmode=SELECTMODE_Z;
				sel.back=true;

				if(sel.nowparentsindex==CAPTION_INFO)
				{
					multiplayreadymy=false;
					if(!Setting.Seaver) Sendokcancel(false);
				}

			}
		}

	}

	


	//���ʉ��Đ�
	if(sel.frame==60)
		sd.RotaStart->Play();

}






void SelectMove()
{

	if(sel.callframe>0)
	{
		sel.callframe--;
		if(sel.callframe==0)
		{
			CallSelect(sel.callmode);
		}
	}

	if(sel.enable==true)
	{

		sel.ang+=1;

		if(sel.frame>0)
		{
			sel.frame--;
			//���ʉ��Đ�
			if(sel.frame==0 && (sel.selectmode!=SELECTMODE_X || sel.back==false))
				sd.RotaEnd->Play();
		}



		//�G���[���������Ă����玩���I�ɃG���[��ʂ֔��(�l�b�g���[�N�֌W)
		if(Error!=CAPTION_NONE && (sel.frame==0))
		{
			sel.back=false;
			sel.frame=60;
			sel.selectmode=SELECTMODE_Z;
			sd.RotaStart->Play();
		}

		//�Q�[���J�n���b�Z�[�W�����Ă����玩���I�ɃQ�[����ʂ֔��(�l�b�g���[�N�֌W)
		if(MultiPlayStart==true && (sel.frame==0))
		{
			MultiPlayStart=false;
			sel.back=true;
			sel.frame=60;
			sel.selectmode=SELECTMODE_X;
			feed[4].Start(FEEDMODE_WHITEOUT,60);
			sd.RotaStart->Play();
		}




		if(sel.selectmode==SELECTMODE_Z)
		{

			if(sel.back==false)//�i��
			{

				if(sel.frame==30)
				{
					//�L���v�V�����ύX�̏���

					if(Error!=CAPTION_NONE)
					{
						//�G���[��ʂֈړ�

						//������Ɠ���ȍ��
						if(Error==CAPTION_ERROR) Error=CAPTION_SETUZOKUERROR;


						sel.nowparentsindex=CAPTION_ERROR;
						sel.caption[CAPTION_ERROR].child[0]=Error;
						sel.nowselectindex=0;

						Error=CAPTION_NONE;

					}
					else
					{

						switch(sel.nowparentsindex)//�e�����񂪁E�E�E
						{


						case CAPTION_GAMESELECT:

							switch(sel.caption[CAPTION_GAMESELECT].child[sel.nowselectindex])//�I������Ă�q���E�E�E
							{
							case CAPTION_STAGE://�X�e�[�W
								sel.nowparentsindex=CAPTION_STAGESELECT;
								sel.nowselectindex=0;
								stagekind=SELECTGAME_STAGE;
								replay=false;
								break;
							case CAPTION_EXSTAGE://EX�X�e�[�W
								sel.nowparentsindex=CAPTION_STAGESELECT;
								sel.nowselectindex=NORMALSTAGE_COUNT;
								stagekind=SELECTGAME_STAGE;
								replay=false;
								break;
							case CAPTION_VARSUS://�o�[�T�X
								sel.nowparentsindex=CAPTION_NINZUUSELECT;
								sel.caption[CAPTION_NINZUUSELECT].childcount=(clearstage-NORMALSTAGE_COUNT)/4+1;
								if(sel.caption[CAPTION_NINZUUSELECT].childcount>4)sel.caption[CAPTION_NINZUUSELECT].childcount=4;
								sel.caption[CAPTION_NINZUUSELECT].child[0]=CAPTION_ONE;
								sel.caption[sel.caption[CAPTION_NINZUUSELECT].child[0]].kind=CAPTIONKIND_CHILD;
								sel.nowselectindex=0;
								stagekind=SELECTGAME_VARSUS;
								replay=false;
								break;
							case CAPTION_REPLAY:
								sel.nowparentsindex=CAPTION_REPLAYSELECT;
								sel.nowselectindex=0;

								sel.caption[CAPTION_REPLAYSELECT].child[0]=CAPTION_REPLAYSTAGE;
								sel.caption[CAPTION_REPLAYSELECT].childcount=1;

								if(clearstage>NORMALSTAGE_COUNT)
								{
									sel.caption[CAPTION_REPLAYSELECT].child[sel.caption[CAPTION_REPLAYSELECT].childcount]=CAPTION_REPLAYEXSTAGE;
									sel.caption[CAPTION_REPLAYSELECT].childcount++;
								}
								if(clearstage>=NORMALSTAGE_COUNT)
								{
									sel.caption[CAPTION_REPLAYSELECT].child[sel.caption[CAPTION_REPLAYSELECT].childcount]=CAPTION_REPLAYVARSUS;
									sel.caption[CAPTION_REPLAYSELECT].childcount++;
								}

								sel.nowselectindex=0;
								break;
							case CAPTION_MULTIPLAY:
								sel.nowparentsindex=CAPTION_NETSETTING;
								sel.nowselectindex=0;
								stagekind=SELECTGAME_MULTIPLAY;
								replay=false;
								break;
							case CAPTION_OWARU:
								stagekind=SELECTGAME_END;
								break;
							}
							
							break;






						case CAPTION_NINZUUSELECT:

							//�L�����Z���N�g��&������ꂽ�����Ă������ǂ�
							sel.caption[CAPTION_ONE].kind=CAPTIONKIND_CHILD;
							sel.caption[CAPTION_NINZUUSELECT].child[0]=CAPTION_ONE;
							sel.caption[CAPTION_CHARSELECT].child[0]=CAPTION_P1;
							sel.nowparentsindex=CAPTION_CHARSELECT;
							sel.nowselectindex=0;

							break;


						case CAPTION_CHARSELECT:


							if(stagekind==SELECTGAME_STAGE)
							{
								sel.nowparentsindex=CAPTION_STAGESELECT;
								sel.nowselectindex=0;
							}
							else if(stagekind==SELECTGAME_VARSUS)//VS
							{
								if(sel.caption[CAPTION_CHARSELECT].child[0]>=CAPTION_P1 && sel.caption[CAPTION_CHARSELECT].child[0]<=CAPTION_P4)
								{
									if(sel.caption[CAPTION_CHARSELECT].child[0]-CAPTION_P1+1<playercount)
									{
										sel.caption[CAPTION_CHARSELECT].child[0]++;
										sel.nowselectindex=0;
									}
									else
									{
										sel.nowparentsindex=CAPTION_STAGESELECT;
										sel.nowselectindex=0;
									}

								}

							}
							else if(stagekind==SELECTGAME_MULTIPLAY)
							{
								if(Setting.Seaver)
								{
									sel.nowparentsindex=CAPTION_STAGESELECT;
									sel.nowselectindex=0;
								}
								else
								{
									//�C���t�H���[�V������ʂֈړ�
									sel.nowparentsindex=CAPTION_INFO;
									multiplayreadymy=false;
								}
							}




							break;


						case CAPTION_STAGESELECT:

							//�C���t�H���[�V������ʂֈړ�

							sel.nowparentsindex=CAPTION_INFO;
							multiplayreadymy=false;

							break;



						case CAPTION_STOP:

							feed[4].Start(FEEDMODE_WHITEIN,30);

							break;








						case CAPTION_REPLAYSELECT:

							switch(sel.caption[CAPTION_REPLAYSELECT].child[sel.nowselectindex])//�I������Ă�q���E�E�E
							{
							case CAPTION_REPLAYSTAGE://�X�e�[�W
								sel.nowparentsindex=CAPTION_STAGESELECT;
								sel.nowselectindex=0;
								stagekind=SELECTGAME_STAGE;
								replay=true;
								break;
							case CAPTION_REPLAYEXSTAGE://EX�X�e�[�W
								sel.nowparentsindex=CAPTION_STAGESELECT;
								sel.nowselectindex=NORMALSTAGE_COUNT;
								stagekind=SELECTGAME_STAGE;
								replay=true;
								break;
							case CAPTION_REPLAYVARSUS://�o�[�T�X
								sel.nowparentsindex=CAPTION_STAGESELECT;
								sel.nowselectindex=0;
								stagekind=SELECTGAME_VARSUS;
								playercount=1;
								replay=true;
								break;
							}
							
							break;




						case CAPTION_NETSETTING:

							switch(sel.caption[CAPTION_NETSETTING].child[sel.nowselectindex])//�I������Ă�q���E�E�E
							{
							case CAPTION_SERVER://�T�[�o�[
								Setting.Seaver=true;
								sel.nowparentsindex=CAPTION_PORT;
								sel.nowselectindex=0;
								break;
							case CAPTION_CLIENT://�N���C�A���g
								Setting.Seaver=false;
								sel.nowparentsindex=CAPTION_IP;
								sel.nowselectindex=0;
								break;
							}
							
							break;



						case CAPTION_IP:

							sel.nowparentsindex=CAPTION_PORT;
							sel.nowselectindex=0;
							
							break;
 


						case CAPTION_PORT:


							//�T�[�o��������
							if(Setting.Seaver)
							{

								if(SetNetwork())
								{
									player[0].charnum=-1;
									player[1].charnum=-1;
									player[2].charnum=-1;
									player[3].charnum=-1;
									playercount=0;
									multiplayernum=0;
									sel.nowparentsindex=CAPTION_NINZUUSELECT;
									sel.caption[CAPTION_NINZUUSELECT].childcount=4;
									sel.caption[CAPTION_ONE].kind=CAPTIONKIND_CAPTION;
									sel.caption[CAPTION_NINZUUSELECT].child[0]=CAPTION_NONE;
									sel.nowselectindex=1;
								}
								else
								{//�G���[��ʂփW�����v
									sel.nowparentsindex=CAPTION_ERROR;
									sel.caption[CAPTION_ERROR].child[0]=CAPTION_SETUZOKUERROR;
									sel.nowselectindex=0;
								}

							}
							else//�N���C�A���g��������
							{

								if(Error==CAPTION_NONE)
								{
									sel.caption[CAPTION_CHARSELECT].child[0]=CAPTION_P1+multiplayernum;
									sel.nowparentsindex=CAPTION_CHARSELECT;
									sel.nowselectindex=0;
								}

							}
							
							break;





						}

					}

				}

			}
			else//�߂�
			{
				if(sel.frame==30)
				{



					if(sel.nowparentsindex==CAPTION_CHARSELECT && (stagekind!=SELECTGAME_MULTIPLAY || Setting.Seaver))
					{


						if(stagekind==SELECTGAME_MULTIPLAY)
						{
							if(Setting.Seaver)
							{
								//�ɂ񂸂����ꂭ�Ƃ��߂�ɂ��ǂ�
								sel.nowparentsindex=CAPTION_NINZUUSELECT;
								sel.caption[CAPTION_NINZUUSELECT].childcount=4;
								sel.caption[CAPTION_ONE].kind=CAPTIONKIND_CAPTION;
								sel.caption[CAPTION_NINZUUSELECT].child[0]=CAPTION_NONE;
								sel.nowselectindex=playercount-1;
							}
							else
							{
								//�|�[�g�ݒ��ʂɖ߂�
								sel.nowparentsindex=CAPTION_PORT;
								sel.nowselectindex=0;
							}
						}
						else if(sel.caption[CAPTION_CHARSELECT].child[0]==CAPTION_P4)
						{
							sel.caption[CAPTION_CHARSELECT].child[0]=CAPTION_P3;
							sel.nowselectindex=player[2].charnum;
						}
						else if(sel.caption[CAPTION_CHARSELECT].child[0]==CAPTION_P3)
						{
							sel.caption[CAPTION_CHARSELECT].child[0]=CAPTION_P2;
							sel.nowselectindex=player[1].charnum;
						}
						else if(sel.caption[CAPTION_CHARSELECT].child[0]==CAPTION_P2)
						{
							sel.caption[CAPTION_CHARSELECT].child[0]=CAPTION_P1;
							sel.nowselectindex=player[0].charnum;
						}
						else if(sel.caption[CAPTION_CHARSELECT].child[0]==CAPTION_P1)
						{
							sel.nowparentsindex=CAPTION_NINZUUSELECT;
							sel.caption[CAPTION_NINZUUSELECT].childcount=(clearstage-NORMALSTAGE_COUNT)/4+1;
							if(sel.caption[CAPTION_NINZUUSELECT].childcount>4)sel.caption[CAPTION_NINZUUSELECT].childcount=4;
							sel.caption[CAPTION_NINZUUSELECT].child[0]=CAPTION_ONE;
							sel.caption[sel.caption[CAPTION_NINZUUSELECT].child[0]].kind=CAPTIONKIND_CHILD;
							sel.nowselectindex=playercount-1;
						}


					}
					else if(sel.nowparentsindex==CAPTION_STAGESELECT)
					{


						if(replay)
						{
							sel.nowparentsindex=CAPTION_REPLAYSELECT;

							if(stagekind==SELECTGAME_STAGE)
							{
								if(sel.nowselectindex<NORMALSTAGE_COUNT)
									sel.nowselectindex=0;
								else
									sel.nowselectindex=1;
							}
							else
							{
								if(clearstage<=NORMALSTAGE_COUNT)
									sel.nowselectindex=1;
								else
									sel.nowselectindex=2;
							}
						}
						else if(stagekind==SELECTGAME_STAGE)//�X�e�[�W���[�h
						{

							sel.nowparentsindex=CAPTION_GAMESELECT;

							sel.caption[CAPTION_GAMESELECT].childcount=1;

							if(clearstage>=NORMALSTAGE_COUNT)
							{
								sel.caption[CAPTION_GAMESELECT].child[sel.caption[CAPTION_GAMESELECT].childcount]=CAPTION_EXSTAGE;
								sel.caption[CAPTION_GAMESELECT].childcount++;
							}

							if(clearstage>=NORMALSTAGE_COUNT)
							{
								sel.caption[CAPTION_GAMESELECT].child[sel.caption[CAPTION_GAMESELECT].childcount]=CAPTION_VARSUS;
								sel.caption[CAPTION_GAMESELECT].childcount++;
							}
							if(clearstage>0)
							{
								sel.caption[CAPTION_GAMESELECT].child[sel.caption[CAPTION_GAMESELECT].childcount]=CAPTION_REPLAY;
								sel.caption[CAPTION_GAMESELECT].childcount++;
							}
							//if(clearstage>=20)
							//{
							//	sel.caption[CAPTION_GAMESELECT].child[sel.caption[CAPTION_GAMESELECT].childcount]=CAPTION_MULTIPLAY;
							//	sel.caption[CAPTION_GAMESELECT].childcount++;
							//}

							sel.caption[CAPTION_GAMESELECT].child[sel.caption[CAPTION_GAMESELECT].childcount]=CAPTION_OWARU;
							sel.caption[CAPTION_GAMESELECT].childcount++;

							if(sel.nowselectindex<NORMALSTAGE_COUNT)
								sel.nowselectindex=0;
							else
								sel.nowselectindex=1;

						}
						else if(stagekind==SELECTGAME_VARSUS)//�ΐ탂�[�h
						{
							sel.nowparentsindex=CAPTION_CHARSELECT;
							sel.nowselectindex=player[playercount-1].charnum;
						}
						else if(stagekind==SELECTGAME_MULTIPLAY)
						{
							sel.nowparentsindex=CAPTION_CHARSELECT;
							sel.caption[CAPTION_CHARSELECT].child[0]=CAPTION_P1+multiplayernum;
							sel.nowselectindex=player[multiplayernum].charnum;
							player[multiplayernum].charnum=-1;
							SendAllPlayerInfo(playercount);
						}




					}
					else if(sel.nowparentsindex==CAPTION_NETSETTING || sel.nowparentsindex==CAPTION_REPLAYSELECT ||
							sel.nowparentsindex==CAPTION_NINZUUSELECT || sel.nowparentsindex==CAPTION_CHARSELECT)
					{


						if(stagekind==SELECTGAME_MULTIPLAY && 
							((sel.nowparentsindex==CAPTION_NINZUUSELECT && Setting.Seaver) || 
							(sel.nowparentsindex==CAPTION_CHARSELECT && !Setting.Seaver)))
						{
							sel.nowparentsindex=CAPTION_PORT;
							sel.nowselectindex=0;
							//�I���̃��b�Z�[�W�𗬂�

							if(Setting.Seaver)
								SendSeaverDown();
							else
								SendPlayerOut();

							//��莞�ԊԂ�����
							wait(0.5f);


							closesocket(s);
							WSACleanup();
						}
						else
						{

							sel.caption[CAPTION_GAMESELECT].childcount=1;

							if(clearstage>=NORMALSTAGE_COUNT)
							{
								sel.caption[CAPTION_GAMESELECT].child[sel.caption[CAPTION_GAMESELECT].childcount]=CAPTION_EXSTAGE;
								sel.caption[CAPTION_GAMESELECT].childcount++;
							}

							if(clearstage>=NORMALSTAGE_COUNT)
							{
								sel.caption[CAPTION_GAMESELECT].child[sel.caption[CAPTION_GAMESELECT].childcount]=CAPTION_VARSUS;
								sel.caption[CAPTION_GAMESELECT].childcount++;
							}
							sel.caption[CAPTION_GAMESELECT].child[sel.caption[CAPTION_GAMESELECT].childcount]=CAPTION_REPLAY;
							sel.caption[CAPTION_GAMESELECT].childcount++;
							//if(clearstage>=20)
							//{
							//	sel.caption[CAPTION_GAMESELECT].child[sel.caption[CAPTION_GAMESELECT].childcount]=CAPTION_MULTIPLAY;
							//	sel.caption[CAPTION_GAMESELECT].childcount++;
							//}

							sel.caption[CAPTION_GAMESELECT].child[sel.caption[CAPTION_GAMESELECT].childcount]=CAPTION_OWARU;
							sel.caption[CAPTION_GAMESELECT].childcount++;


							if(sel.nowparentsindex==CAPTION_NINZUUSELECT)
							{
								sel.nowselectindex=2;
							}
							else if(sel.nowparentsindex==CAPTION_REPLAYSELECT)
							{
								//�N���A���Ă�X�e�[�W���ɂ���Ĕ����ɕς���Ă���
								if(clearstage<NORMALSTAGE_COUNT)
									sel.nowselectindex=1;
								else
									sel.nowselectindex=3;
							}
							else if(sel.nowparentsindex==CAPTION_NETSETTING)
								sel.nowselectindex=3;

							sel.nowparentsindex=CAPTION_GAMESELECT;

						}

						
					}
					else if(sel.nowparentsindex==CAPTION_PORT)
					{

						if(Setting.Seaver)
						{
							sel.nowparentsindex=CAPTION_NETSETTING;
							sel.nowselectindex=0;
						}
						else
						{//�N���C�A���g�Ń|�[�g���

							sel.nowparentsindex=CAPTION_IP;
							sel.nowselectindex=0;

							//break;
						}


					}
					else if(sel.nowparentsindex==CAPTION_IP)
					{
						sel.nowparentsindex=CAPTION_NETSETTING;
						sel.nowselectindex=1;

					}
					else if(sel.nowparentsindex==CAPTION_INFO)
					{
						if(Setting.Seaver)
						{//�X�e�[�W�Z���N�g��
							sel.nowparentsindex=CAPTION_STAGESELECT;
							sel.nowselectindex=stagenum;
							stagenum=-1;
							SendAllPlayerInfo(playercount);
						}
						else
						{//�L�����Z���N�g��
							sel.nowparentsindex=CAPTION_CHARSELECT;
							sel.caption[CAPTION_CHARSELECT].child[0]=CAPTION_P1+multiplayernum;
							sel.nowselectindex=player[multiplayernum].charnum;
							player[multiplayernum].charnum=-1;

							if(Setting.Seaver)
								SendAllPlayerInfo(playercount);
							else
								SendMyPlayerInfo();

						}


					}
					else if(sel.nowparentsindex==CAPTION_ERROR)
					{
						sel.nowparentsindex=CAPTION_PORT;
						sel.nowselectindex=0;
					}



				}
			}


		}
		else if(sel.selectmode==SELECTMODE_Y)
		{

			if(sel.frame==30)
			{

				if(sel.nowparentsindex==CAPTION_CHARSELECT)
				{
					//12�ɂȂ�Ɩl�Ă����Ă��Ƒ����R�[�X���v���C�ł���
					//16�ɂȂ�Ɩl�ł��ƒn���R�[�X���v���C�ł���
					//20�ɂȂ�Ɩl�ł��ƃe�N�m�R�[�X���v���C�ł���
					//25�ɂȂ�Ǝ��Y�ƈَ����R�[�X���v���C�ł���

					if(!sel.back)
					{
						sel.nowselectindex++;
						if(sel.nowselectindex>(clearstage<=25 ? (clearstage-13)/4 : (clearstage==30 ? 4 : 3)))
							sel.nowselectindex=0;
					}
					else
					{
						sel.nowselectindex--;
						if(sel.nowselectindex<0)
							sel.nowselectindex=(clearstage<=25 ? (clearstage-13)/4 : (clearstage==30 ? 4 : 3));
					}

				}
				else if(stagekind==SELECTGAME_STAGE && sel.nowparentsindex==CAPTION_STAGESELECT && sel.nowselectindex<NORMALSTAGE_COUNT)//�X�e�[�W
				{

					int rep=replay ? 1 : 0;
					int cstage=clearstage-rep;
					if(cstage>NORMALSTAGE_COUNT-1)
						cstage=NORMALSTAGE_COUNT-1;//�������Ă������ƂőI��͈͂𒲐�


					if(sel.across==true)
					{
						if(!sel.back)
						{
							sel.nowselectindex++;
							if(cstage<sel.nowselectindex)
								sel.nowselectindex=0;
						}
						else
						{
							sel.nowselectindex--;
							if(sel.nowselectindex<0)
								sel.nowselectindex=cstage;
						}
					}
					else
					{
						if(!sel.back)
						{
							sel.nowselectindex+=4;
							if(cstage<sel.nowselectindex)
								sel.nowselectindex=0;
						}
						else
						{
							sel.nowselectindex-=4;
							if(sel.nowselectindex<0)
								sel.nowselectindex=cstage;
						}
					}


				}
				else if(stagekind==SELECTGAME_STAGE && sel.nowparentsindex==CAPTION_STAGESELECT && sel.nowselectindex>=NORMALSTAGE_COUNT)//EX�X�e�[�W
				{

					int rep=replay ? 1 : 0;
					int cstage=clearstage-rep;
					if(cstage>STAGE_MAX-1)
						cstage=STAGE_MAX-1;//�������Ă������ƂőI��͈͂𒲐�

					if(sel.across==true)
					{
						if(!sel.back)
						{
							sel.nowselectindex++;
							if(cstage<sel.nowselectindex)
								sel.nowselectindex=NORMALSTAGE_COUNT;
						}
						else
						{
							sel.nowselectindex--;
							if(sel.nowselectindex<NORMALSTAGE_COUNT)
								sel.nowselectindex=cstage;
						}
					}
					else
					{
						if(!sel.back)
						{
							sel.nowselectindex+=4;
							if(cstage<sel.nowselectindex)
								sel.nowselectindex=NORMALSTAGE_COUNT;
						}
						else
						{
							sel.nowselectindex-=4;
							if(sel.nowselectindex<NORMALSTAGE_COUNT)
								sel.nowselectindex=cstage;
						}
					}


				}
				else if(stagekind!=SELECTGAME_STAGE)//�o�[�T�X
				{

//					int corcecount=(clearstage<=25 ? (clearstage-13)/4 : (clearstage==30 ? 4 : 3))/5*3+2;
//					if(corcecount<3)corcecount=3;

					int corcecount;
					if(clearstage<21)corcecount=2;
					else if(clearstage<25)corcecount=5;
					else if(clearstage<30)corcecount=8;
					else corcecount=11;

					if(sel.across==true)
					{
						if(!sel.back)
						{
							sel.nowselectindex++;
							if(corcecount<sel.nowselectindex)
								sel.nowselectindex=0;
						}
						else
						{
							sel.nowselectindex--;
							if(sel.nowselectindex<0)
								sel.nowselectindex=corcecount;
						}
					}
					else
					{
						if(!sel.back)
						{
							sel.nowselectindex+=3;
							if(corcecount<sel.nowselectindex)
								sel.nowselectindex=0;
						}
						else
						{
							sel.nowselectindex-=3;
							if(sel.nowselectindex<0)
								sel.nowselectindex=corcecount;
						}
					}


				}

			}

		}
		else if(sel.back==true)
		{
			if((sel.nowparentsindex==CAPTION_STOP && 
				sel.nowselectindex==-1 && sel.frame<30) || sel.frame<=0)
			{
				sel.enable=false;
			}

		}





	}


}










void SelectRender()
{
	if(sel.enable==true && (sel.selectmode!=SELECTMODE_X || sel.frame>30 || sel.back==false))
	{


		//�J�����̈ʒu����
		D3DXMATRIX matView;


		D3DXMatrixLookAtLH( &matView, &D3DXVECTOR3( 0,3,-10 ),
									&D3DXVECTOR3( 0,0,0 ), 
									&D3DXVECTOR3( 0.0f, 1.0f, 0.0f ) );

		DG.Device->SetTransform( D3DTS_VIEW, &matView );

		D3DXMATRIX matProj;
		D3DXMatrixPerspectiveFovLH( &matProj, D3DX_PI/3, (float)(4.0/3.0), 0.1f, 1000 );
		DG.Device->SetTransform( D3DTS_PROJECTION, &matProj );


		DG.Device->SetRenderState( D3DRS_AMBIENT, 0xff666666 );


		int i;

		D3DXMATRIX matWorld,matWorld2,matWorld3;


		if(sel.frame==0)
			matWorld=D3DXMATRIX(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
		else if(sel.selectmode==SELECTMODE_X)
		{
			if(sel.back==false)
				D3DXMatrixRotationX( &matWorld, sel.frame/60.0f*360*rad );
			else
				D3DXMatrixRotationX( &matWorld, -sel.frame/60.0f*360*rad );
		}
		else if(sel.selectmode==SELECTMODE_Y)
		{
			if(sel.back==false)
				D3DXMatrixRotationY( &matWorld, -sel.frame/60.0f*360*rad );
			else
				D3DXMatrixRotationY( &matWorld, sel.frame/60.0f*360*rad );
		}
		else if(sel.selectmode==SELECTMODE_Z)
		{
			if(sel.back==false)
				D3DXMatrixRotationZ( &matWorld, -sel.frame/60.0f*360*rad );
			else
				D3DXMatrixRotationZ( &matWorld, sel.frame/60.0f*360*rad );
		}
		D3DXMatrixTranslation( &matWorld2, 0,1,-8.5 );
		matWorld*=matWorld2;
		DG.Device->SetTransform( D3DTS_WORLD, &matWorld );
		sel.mesh.Render(DG.Device);










		//�Z���N�g���[�h�ɂ��A�L�����A�X�e�[�W�Ȃǂ�\������
		

		if(sel.nowparentsindex==CAPTION_CHARSELECT)
		{
			//�L���������_�[



			D3DXMatrixScaling( &matWorld2, 0.25f,0.25f,1 );
			D3DXMatrixTranslation( &matWorld3, 0,1.25f,-0.05f );
			matWorld2*=matWorld3;
			matWorld2*=matWorld;
			DG.Device->SetTransform( D3DTS_WORLD, &matWorld2 );

			ita.SetTexture(sel.caption[CAPTION_CHARTEX+sel.nowselectindex].tex,0);
			ita.Render(DG.Device);

		}
		else if(sel.nowparentsindex==CAPTION_STAGESELECT)
		{
			//�X�e�[�W�����_�[
			if(stagekind==SELECTGAME_STAGE)//�X�e�[�W�^�C�v
			{

				if(replay && hTime[sel.nowselectindex]==0)
				{
					ita.Material[0].Diffuse.a=0.4f;
				}

				D3DXMatrixScaling( &matWorld2, 0.25f,0.25f,1 );
				D3DXMatrixTranslation( &matWorld3, 0,1.25f,-0.05f );
				matWorld2*=matWorld3;
				matWorld2*=matWorld;
				DG.Device->SetTransform( D3DTS_WORLD, &matWorld2 );

				ita.SetTexture(sel.caption[CAPTION_STAGETEX+sel.nowselectindex].tex,0);
				ita.Render(DG.Device);

				ita.Material[0].Diffuse.a=1.0f;
			}
			else
			{

				if(replay && hTime[sel.nowselectindex+STAGE_MAX]==0)
				{
					ita.Material[0].Diffuse.a=0.4f;
				}


				D3DXMatrixScaling( &matWorld2, 0.25f,0.25f,1 );
				D3DXMatrixTranslation( &matWorld3, 0,1.25f,-0.05f );
				matWorld2*=matWorld3;
				matWorld2*=matWorld;
				DG.Device->SetTransform( D3DTS_WORLD, &matWorld2 );

				ita.SetTexture(sel.caption[CAPTION_CORCETEX+sel.nowselectindex].tex,0);
				ita.Render(DG.Device);

				ita.Material[0].Diffuse.a=1.0f;
			}

		}
		else if(sel.nowparentsindex==CAPTION_INFO)
		{

			if(stagenum!=-1)
			{

				D3DXMatrixScaling( &matWorld2, 0.25f,0.25f,1 );
				D3DXMatrixTranslation( &matWorld3, 0,1.25f,-0.05f );
				matWorld2*=matWorld3;
				matWorld2*=matWorld;
				DG.Device->SetTransform( D3DTS_WORLD, &matWorld2 );

				ita.SetTexture(sel.caption[CAPTION_CORCETEX+stagenum].tex,0);
				ita.Render(DG.Device);

			}

		}






		//�����̃����_�����O

		DG.Device->SetRenderState(D3DRS_ZENABLE,false);

		int nowparents=sel.nowparentsindex;
		int nowselect=sel.nowselectindex;


		//�eCAPTION
		if(sel.caption[nowparents].mini==false)
			D3DXMatrixScaling( &matWorld2, 0.33f,0.05f,1 );
		else
			D3DXMatrixScaling( &matWorld2, 0.17f,0.05f,1 );
		D3DXMatrixTranslation( &matWorld3, 0,2,-0.05f );
		matWorld2*=matWorld3;
		matWorld2*=matWorld;
		DG.Device->SetTransform( D3DTS_WORLD, &matWorld2 );
		ita.SetTexture(sel.caption[nowparents].tex,0);
		ita.Render(DG.Device);

		//CHILDCAPTION(���S�ʒu=1.45)
		for(i=0;i<sel.caption[nowparents].childcount;i++)
		{
			if(sel.nowparentsindex==CAPTION_IP || sel.nowparentsindex==CAPTION_PORT)
			{
				D3DXMatrixScaling( &matWorld2, 0.03f,0.04f,1 );
				D3DXMatrixTranslation( &matWorld3, 0,1.25f+0.2f/2.0f,-0.05f );
				matWorld2*=matWorld3;
				matWorld2*=matWorld;
				DG.Device->SetTransform( D3DTS_WORLD, &matWorld2 );
				if(sel.nowparentsindex==CAPTION_IP)
					InfoNetRender(Setting.ip);
				else
					InfoNetRender(Setting.port);
			}
			else if(sel.caption[nowparents].child[i]!=CAPTION_NONE)
			{
				if(sel.caption[sel.caption[nowparents].child[i]].mini==false)
					D3DXMatrixScaling( &matWorld2, 0.33f,0.05f,1 );
				else
					D3DXMatrixScaling( &matWorld2, 0.17f,0.05f,1 );

				if(sel.caption[sel.caption[nowparents].child[i]].kind==CAPTIONKIND_CAPTION)
					D3DXMatrixTranslation( &matWorld3, 0,2-0.2f,-0.05f );
				else
					D3DXMatrixTranslation( &matWorld3, 0,1.25f+(sel.caption[nowparents].childcount*0.2f/2.0f)-(i*0.2f),-0.05f );

				matWorld2*=matWorld3;
				matWorld2*=matWorld;
				DG.Device->SetTransform( D3DTS_WORLD, &matWorld2 );

				ita.SetTexture(sel.caption[sel.caption[nowparents].child[i]].tex,0);
				ita.Render(DG.Device);

			}
		}



		if(sel.nowparentsindex!=CAPTION_CHARSELECT && sel.nowparentsindex!=CAPTION_STAGESELECT)
		{

			//�J�[�\��
			D3DXMatrixScaling( &matWorld2, 0.33f,0.05f,1 );
			D3DXMatrixTranslation( &matWorld3, 0,1.25f+(sel.caption[nowparents].childcount*0.2f/2.0f)-(nowselect*0.2f),-0.05f );
			matWorld2*=matWorld3;
			matWorld2*=matWorld;
			DG.Device->SetTransform( D3DTS_WORLD, &matWorld2 );
			ita.SetTexture(sel.selecttex,0);
			ita.Render(DG.Device);


		}





		DG.Device->SetRenderState(D3DRS_ZENABLE,true);

	}

}







#endif
