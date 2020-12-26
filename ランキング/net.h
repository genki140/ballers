
//‚·‚Å‚É‚ ‚Á‚½‚çfalse‚ð•Ô‚·
bool mutexcheck();

struct rankdatastruct
{
	char name[42][30];
	int chara[42];
	int time[42];
	int check;
};

bool sendreplay(bool stage,int index,int time,int angou,char *name);
bool recvreplay(bool stage,int index,int *onlinetime);
bool updateinfo(rankdatastruct *rankdata);

