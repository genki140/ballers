

//アップロード、ダウンロードのEnableの設定(クリアしていないステージはダウンロードできなくする)


void getname(char *str)
{
	FILE *file=fopen("data/save/name","r");
	if(file!=NULL)
	{
		if(fscanf(file,"%s",str)==EOF)
			str[0]='\0';
		else if(strlen(str)>20)
			str[0]='\0';
	}
	else
		str[0]='\0';

	fclose(file);
}


void LinkReset()
{
	SDelete1->Enabled=false;
	SDelete2->Enabled=false;
	SDelete3->Enabled=false;
	SDelete4->Enabled=false;
	SDelete5->Enabled=false;
	SDelete6->Enabled=false;
	SDelete7->Enabled=false;
	SDelete8->Enabled=false;
	SDelete9->Enabled=false;
	SDelete10->Enabled=false;
	SDelete11->Enabled=false;
	SDelete12->Enabled=false;
	SDelete13->Enabled=false;
	SDelete14->Enabled=false;
	SDelete15->Enabled=false;
	SDelete16->Enabled=false;
	SDelete17->Enabled=false;
	SDelete18->Enabled=false;
	SDelete19->Enabled=false;
	SDelete20->Enabled=false;
	SDelete21->Enabled=false;
	SDelete22->Enabled=false;
	SDelete23->Enabled=false;
	SDelete24->Enabled=false;
	SDelete25->Enabled=false;
	SDelete26->Enabled=false;
	SDelete27->Enabled=false;
	SDelete28->Enabled=false;
	SDelete29->Enabled=false;
	SDelete30->Enabled=false;
	SUpLoad1->Enabled=false;
	SUpLoad2->Enabled=false;
	SUpLoad3->Enabled=false;
	SUpLoad4->Enabled=false;
	SUpLoad5->Enabled=false;
	SUpLoad6->Enabled=false;
	SUpLoad7->Enabled=false;
	SUpLoad8->Enabled=false;
	SUpLoad9->Enabled=false;
	SUpLoad10->Enabled=false;
	SUpLoad11->Enabled=false;
	SUpLoad12->Enabled=false;
	SUpLoad13->Enabled=false;
	SUpLoad14->Enabled=false;
	SUpLoad15->Enabled=false;
	SUpLoad16->Enabled=false;
	SUpLoad17->Enabled=false;
	SUpLoad18->Enabled=false;
	SUpLoad19->Enabled=false;
	SUpLoad20->Enabled=false;
	SUpLoad21->Enabled=false;
	SUpLoad22->Enabled=false;
	SUpLoad23->Enabled=false;
	SUpLoad24->Enabled=false;
	SUpLoad25->Enabled=false;
	SUpLoad26->Enabled=false;
	SUpLoad27->Enabled=false;
	SUpLoad28->Enabled=false;
	SUpLoad29->Enabled=false;
	SUpLoad30->Enabled=false;
	SDownLoad1->Enabled=false;
	SDownLoad2->Enabled=false;
	SDownLoad3->Enabled=false;
	SDownLoad4->Enabled=false;
	SDownLoad5->Enabled=false;
	SDownLoad6->Enabled=false;
	SDownLoad7->Enabled=false;
	SDownLoad8->Enabled=false;
	SDownLoad9->Enabled=false;
	SDownLoad10->Enabled=false;
	SDownLoad11->Enabled=false;
	SDownLoad12->Enabled=false;
	SDownLoad13->Enabled=false;
	SDownLoad14->Enabled=false;
	SDownLoad15->Enabled=false;
	SDownLoad16->Enabled=false;
	SDownLoad17->Enabled=false;
	SDownLoad18->Enabled=false;
	SDownLoad19->Enabled=false;
	SDownLoad20->Enabled=false;
	SDownLoad21->Enabled=false;
	SDownLoad22->Enabled=false;
	SDownLoad23->Enabled=false;
	SDownLoad24->Enabled=false;
	SDownLoad25->Enabled=false;
	SDownLoad26->Enabled=false;
	SDownLoad27->Enabled=false;
	SDownLoad28->Enabled=false;
	SDownLoad29->Enabled=false;
	SDownLoad30->Enabled=false;
	CDelete1->Enabled=false;
	CDelete2->Enabled=false;
	CDelete3->Enabled=false;
	CDelete4->Enabled=false;
	CDelete5->Enabled=false;
	CDelete6->Enabled=false;
	CDelete7->Enabled=false;
	CDelete8->Enabled=false;
	CDelete9->Enabled=false;
	CDelete10->Enabled=false;
	CDelete11->Enabled=false;
	CDelete12->Enabled=false;
	CUpLoad1->Enabled=false;
	CUpLoad2->Enabled=false;
	CUpLoad3->Enabled=false;
	CUpLoad4->Enabled=false;
	CUpLoad5->Enabled=false;
	CUpLoad6->Enabled=false;
	CUpLoad7->Enabled=false;
	CUpLoad8->Enabled=false;
	CUpLoad9->Enabled=false;
	CUpLoad10->Enabled=false;
	CUpLoad11->Enabled=false;
	CUpLoad12->Enabled=false;
	CDownLoad1->Enabled=false;
	CDownLoad2->Enabled=false;
	CDownLoad3->Enabled=false;
	CDownLoad4->Enabled=false;
	CDownLoad5->Enabled=false;
	CDownLoad6->Enabled=false;
	CDownLoad7->Enabled=false;
	CDownLoad8->Enabled=false;
	CDownLoad9->Enabled=false;
	CDownLoad10->Enabled=false;
	CDownLoad11->Enabled=false;
	CDownLoad12->Enabled=false;

	OFFSTime1->Text="0.00";
	OFFSTime2->Text="0.00";
	OFFSTime3->Text="0.00";
	OFFSTime4->Text="0.00";
	OFFSTime5->Text="0.00";
	OFFSTime6->Text="0.00";
	OFFSTime7->Text="0.00";
	OFFSTime8->Text="0.00";
	OFFSTime9->Text="0.00";
	OFFSTime10->Text="0.00";
	OFFSTime11->Text="0.00";
	OFFSTime12->Text="0.00";
	OFFSTime13->Text="0.00";
	OFFSTime14->Text="0.00";
	OFFSTime15->Text="0.00";
	OFFSTime16->Text="0.00";
	OFFSTime17->Text="0.00";
	OFFSTime18->Text="0.00";
	OFFSTime19->Text="0.00";
	OFFSTime20->Text="0.00";
	OFFSTime21->Text="0.00";
	OFFSTime22->Text="0.00";
	OFFSTime23->Text="0.00";
	OFFSTime24->Text="0.00";
	OFFSTime25->Text="0.00";
	OFFSTime26->Text="0.00";
	OFFSTime27->Text="0.00";
	OFFSTime28->Text="0.00";
	OFFSTime29->Text="0.00";
	OFFSTime30->Text="0.00";
	ONSTime1->Text="0.00";
	ONSTime2->Text="0.00";
	ONSTime3->Text="0.00";
	ONSTime4->Text="0.00";
	ONSTime5->Text="0.00";
	ONSTime6->Text="0.00";
	ONSTime7->Text="0.00";
	ONSTime8->Text="0.00";
	ONSTime9->Text="0.00";
	ONSTime10->Text="0.00";
	ONSTime11->Text="0.00";
	ONSTime12->Text="0.00";
	ONSTime13->Text="0.00";
	ONSTime14->Text="0.00";
	ONSTime15->Text="0.00";
	ONSTime16->Text="0.00";
	ONSTime17->Text="0.00";
	ONSTime18->Text="0.00";
	ONSTime19->Text="0.00";
	ONSTime20->Text="0.00";
	ONSTime21->Text="0.00";
	ONSTime22->Text="0.00";
	ONSTime23->Text="0.00";
	ONSTime24->Text="0.00";
	ONSTime25->Text="0.00";
	ONSTime26->Text="0.00";
	ONSTime27->Text="0.00";
	ONSTime28->Text="0.00";
	ONSTime29->Text="0.00";
	ONSTime30->Text="0.00";

	OFFCTime1->Text="0.00";
	OFFCTime2->Text="0.00";
	OFFCTime3->Text="0.00";
	OFFCTime4->Text="0.00";
	OFFCTime5->Text="0.00";
	OFFCTime6->Text="0.00";
	OFFCTime7->Text="0.00";
	OFFCTime8->Text="0.00";
	OFFCTime9->Text="0.00";
	OFFCTime10->Text="0.00";
	OFFCTime11->Text="0.00";
	OFFCTime12->Text="0.00";
	ONCTime1->Text="0.00";
	ONCTime2->Text="0.00";
	ONCTime3->Text="0.00";
	ONCTime4->Text="0.00";
	ONCTime5->Text="0.00";
	ONCTime6->Text="0.00";
	ONCTime7->Text="0.00";
	ONCTime8->Text="0.00";
	ONCTime9->Text="0.00";
	ONCTime10->Text="0.00";
	ONCTime11->Text="0.00";
	ONCTime12->Text="0.00";

	SName1->Text="";
	SName2->Text="";
	SName3->Text="";
	SName4->Text="";
	SName5->Text="";
	SName6->Text="";
	SName7->Text="";
	SName8->Text="";
	SName9->Text="";
	SName10->Text="";
	SName11->Text="";
	SName12->Text="";
	SName13->Text="";
	SName14->Text="";
	SName15->Text="";
	SName16->Text="";
	SName17->Text="";
	SName18->Text="";
	SName19->Text="";
	SName20->Text="";
	SName21->Text="";
	SName22->Text="";
	SName23->Text="";
	SName24->Text="";
	SName25->Text="";
	SName26->Text="";
	SName27->Text="";
	SName28->Text="";
	SName29->Text="";
	SName30->Text="";

	CName1->Text="";
	CName2->Text="";
	CName3->Text="";
	CName4->Text="";
	CName5->Text="";
	CName6->Text="";
	CName7->Text="";
	CName8->Text="";
	CName9->Text="";
	CName10->Text="";
	CName11->Text="";
	CName12->Text="";

}


void setmydata()
{
	//最初、ダウンロード後に呼び出される関数

	//秒数部分=(hTime / 60)
	//少数部分=(float)(hTime % 60)/60.0f*100.0f

	char str[10];int index=-1;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFSTime1->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFSTime2->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFSTime3->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFSTime4->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFSTime5->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFSTime6->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFSTime7->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFSTime8->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFSTime9->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFSTime10->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFSTime11->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFSTime12->Text=str;
	index++;
	if(clearstage>index)
		sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	else
		sprintf(str,"0.00");
	OFFSTime13->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFSTime14->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFSTime15->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFSTime16->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFSTime17->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFSTime18->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFSTime19->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFSTime20->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFSTime21->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFSTime22->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFSTime23->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFSTime24->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFSTime25->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFSTime26->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFSTime27->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFSTime28->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFSTime29->Text=str;
	index++;
	if(clearstage>index)
		sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	else
		sprintf(str,"0.00");
	OFFSTime30->Text=str;

	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFCTime1->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFCTime2->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFCTime3->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFCTime4->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFCTime5->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFCTime6->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFCTime7->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFCTime8->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFCTime9->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFCTime10->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFCTime11->Text=str;
	index++;
	sprintf(str,"%.2f",(float)hTime[index] / 60.0f);
	OFFCTime12->Text=str;



	SDelete1->Enabled=false;
	SDelete2->Enabled=false;
	SDelete3->Enabled=false;
	SDelete4->Enabled=false;
	SDelete5->Enabled=false;
	SDelete6->Enabled=false;
	SDelete7->Enabled=false;
	SDelete8->Enabled=false;
	SDelete9->Enabled=false;
	SDelete10->Enabled=false;
	SDelete11->Enabled=false;
	SDelete12->Enabled=false;
	SDelete13->Enabled=false;
	SDelete14->Enabled=false;
	SDelete15->Enabled=false;
	SDelete16->Enabled=false;
	SDelete17->Enabled=false;
	SDelete18->Enabled=false;
	SDelete19->Enabled=false;
	SDelete20->Enabled=false;
	SDelete21->Enabled=false;
	SDelete22->Enabled=false;
	SDelete23->Enabled=false;
	SDelete24->Enabled=false;
	SDelete25->Enabled=false;
	SDelete26->Enabled=false;
	SDelete27->Enabled=false;
	SDelete28->Enabled=false;
	SDelete29->Enabled=false;
	SDelete30->Enabled=false;

	CDelete1->Enabled=false;
	CDelete2->Enabled=false;
	CDelete3->Enabled=false;
	CDelete4->Enabled=false;
	CDelete5->Enabled=false;
	CDelete6->Enabled=false;
	CDelete7->Enabled=false;
	CDelete8->Enabled=false;
	CDelete9->Enabled=false;
	CDelete10->Enabled=false;
	CDelete11->Enabled=false;
	CDelete12->Enabled=false;


	if(hTime[0]!=0 && clearstage>0)
		SDelete1->Enabled=true;
	if(hTime[1]!=0 && clearstage>1)
		SDelete2->Enabled=true;
	if(hTime[2]!=0 && clearstage>2)
		SDelete3->Enabled=true;
	if(hTime[3]!=0 && clearstage>3)
		SDelete4->Enabled=true;
	if(hTime[4]!=0 && clearstage>4)
		SDelete5->Enabled=true;
	if(hTime[5]!=0 && clearstage>5)
		SDelete6->Enabled=true;
	if(hTime[6]!=0 && clearstage>6)
		SDelete7->Enabled=true;
	if(hTime[7]!=0 && clearstage>7)
		SDelete8->Enabled=true;
	if(hTime[8]!=0 && clearstage>8)
		SDelete9->Enabled=true;
	if(hTime[9]!=0 && clearstage>9)
		SDelete10->Enabled=true;
	if(hTime[10]!=0 && clearstage>10)
		SDelete11->Enabled=true;
	if(hTime[11]!=0 && clearstage>11)
		SDelete12->Enabled=true;
	if(hTime[12]!=0 && clearstage>12)
		SDelete13->Enabled=true;
	if(hTime[13]!=0 && clearstage>13)
		SDelete14->Enabled=true;
	if(hTime[14]!=0 && clearstage>14)
		SDelete15->Enabled=true;
	if(hTime[15]!=0 && clearstage>15)
		SDelete16->Enabled=true;
	if(hTime[16]!=0 && clearstage>16)
		SDelete17->Enabled=true;
	if(hTime[17]!=0 && clearstage>17)
		SDelete18->Enabled=true;
	if(hTime[18]!=0 && clearstage>18)
		SDelete19->Enabled=true;
	if(hTime[19]!=0 && clearstage>19)
		SDelete20->Enabled=true;
	if(hTime[20]!=0 && clearstage>20)
		SDelete21->Enabled=true;
	if(hTime[21]!=0 && clearstage>21)
		SDelete22->Enabled=true;
	if(hTime[22]!=0 && clearstage>22)
		SDelete23->Enabled=true;
	if(hTime[23]!=0 && clearstage>23)
		SDelete24->Enabled=true;
	if(hTime[24]!=0 && clearstage>24)
		SDelete25->Enabled=true;
	if(hTime[25]!=0 && clearstage>25)
		SDelete26->Enabled=true;
	if(hTime[26]!=0 && clearstage>26)
		SDelete27->Enabled=true;
	if(hTime[27]!=0 && clearstage>27)
		SDelete28->Enabled=true;
	if(hTime[28]!=0 && clearstage>28)
		SDelete29->Enabled=true;
	if(hTime[29]!=0 && clearstage>29)
		SDelete30->Enabled=true;

	if(hTime[30]!=0)
		CDelete1->Enabled=true;
	if(hTime[31]!=0)
		CDelete2->Enabled=true;
	if(hTime[32]!=0)
		CDelete3->Enabled=true;
	if(hTime[33]!=0)
		CDelete4->Enabled=true;
	if(hTime[34]!=0)
		CDelete5->Enabled=true;
	if(hTime[35]!=0)
		CDelete6->Enabled=true;
	if(hTime[36]!=0)
		CDelete7->Enabled=true;
	if(hTime[37]!=0)
		CDelete8->Enabled=true;
	if(hTime[38]!=0)
		CDelete9->Enabled=true;
	if(hTime[39]!=0)
		CDelete10->Enabled=true;
	if(hTime[40]!=0)
		CDelete11->Enabled=true;
	if(hTime[41]!=0)
		CDelete12->Enabled=true;

}


void LinkKousin()
{
	//rankdataを元に、それぞれのデータを更新する


	char str[10];int index=-1;
	index++;
	SName1->Text=rankdata.name[index];
	index++;
	SName2->Text=rankdata.name[index];
	index++;
	SName3->Text=rankdata.name[index];
	index++;
	SName4->Text=rankdata.name[index];
	index++;
	SName5->Text=rankdata.name[index];
	index++;
	SName6->Text=rankdata.name[index];
	index++;
	SName7->Text=rankdata.name[index];
	index++;
	SName8->Text=rankdata.name[index];
	index++;
	SName9->Text=rankdata.name[index];
	index++;
	SName10->Text=rankdata.name[index];
	index++;
	SName11->Text=rankdata.name[index];
	index++;
	SName12->Text=rankdata.name[index];
	index++;
	SName13->Text=rankdata.name[index];
	index++;
	SName14->Text=rankdata.name[index];
	index++;
	SName15->Text=rankdata.name[index];
	index++;
	SName16->Text=rankdata.name[index];
	index++;
	SName17->Text=rankdata.name[index];
	index++;
	SName18->Text=rankdata.name[index];
	index++;
	SName19->Text=rankdata.name[index];
	index++;
	SName20->Text=rankdata.name[index];
	index++;
	SName21->Text=rankdata.name[index];
	index++;
	SName22->Text=rankdata.name[index];
	index++;
	SName23->Text=rankdata.name[index];
	index++;
	SName24->Text=rankdata.name[index];
	index++;
	SName25->Text=rankdata.name[index];
	index++;
	SName26->Text=rankdata.name[index];
	index++;
	SName27->Text=rankdata.name[index];
	index++;
	SName28->Text=rankdata.name[index];
	index++;
	SName29->Text=rankdata.name[index];
	index++;
	SName30->Text=rankdata.name[index];
	index++;
	CName1->Text=rankdata.name[index];
	index++;
	CName2->Text=rankdata.name[index];
	index++;
	CName3->Text=rankdata.name[index];
	index++;
	CName4->Text=rankdata.name[index];
	index++;
	CName5->Text=rankdata.name[index];
	index++;
	CName6->Text=rankdata.name[index];
	index++;
	CName7->Text=rankdata.name[index];
	index++;
	CName8->Text=rankdata.name[index];
	index++;
	CName9->Text=rankdata.name[index];
	index++;
	CName10->Text=rankdata.name[index];
	index++;
	CName11->Text=rankdata.name[index];
	index++;
	CName12->Text=rankdata.name[index];

	index=30;
	sprintf(str,"キャラ%d",rankdata.chara[index]+1);
	Char1->Text=str;
	index++;
	sprintf(str,"キャラ%d",rankdata.chara[index]+1);
	Char2->Text=str;
	index++;
	sprintf(str,"キャラ%d",rankdata.chara[index]+1);
	Char3->Text=str;
	index++;
	sprintf(str,"キャラ%d",rankdata.chara[index]+1);
	Char4->Text=str;
	index++;
	sprintf(str,"キャラ%d",rankdata.chara[index]+1);
	Char5->Text=str;
	index++;
	sprintf(str,"キャラ%d",rankdata.chara[index]+1);
	Char6->Text=str;
	index++;
	sprintf(str,"キャラ%d",rankdata.chara[index]+1);
	Char7->Text=str;
	index++;
	sprintf(str,"キャラ%d",rankdata.chara[index]+1);
	Char8->Text=str;
	index++;
	sprintf(str,"キャラ%d",rankdata.chara[index]+1);
	Char9->Text=str;
	index++;
	sprintf(str,"キャラ%d",rankdata.chara[index]+1);
	Char10->Text=str;
	index++;
	sprintf(str,"キャラ%d",rankdata.chara[index]+1);
	Char11->Text=str;
	index++;
	sprintf(str,"キャラ%d",rankdata.chara[index]+1);
	Char12->Text=str;


	index=-1;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONSTime1->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONSTime2->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONSTime3->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONSTime4->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONSTime5->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONSTime6->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONSTime7->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONSTime8->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONSTime9->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONSTime10->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONSTime11->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONSTime12->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONSTime13->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONSTime14->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONSTime15->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONSTime16->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONSTime17->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONSTime18->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONSTime19->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONSTime20->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONSTime21->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONSTime22->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONSTime23->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONSTime24->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONSTime25->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONSTime26->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONSTime27->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONSTime28->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONSTime29->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONSTime30->Text=str;

	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONCTime1->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONCTime2->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONCTime3->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONCTime4->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONCTime5->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONCTime6->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONCTime7->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONCTime8->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONCTime9->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONCTime10->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONCTime11->Text=str;
	index++;
	sprintf(str,"%.2f",(float)rankdata.time[index] / 60.0f);
	ONCTime12->Text=str;





	SUpLoad1->Enabled=false;
	SUpLoad2->Enabled=false;
	SUpLoad3->Enabled=false;
	SUpLoad4->Enabled=false;
	SUpLoad5->Enabled=false;
	SUpLoad6->Enabled=false;
	SUpLoad7->Enabled=false;
	SUpLoad8->Enabled=false;
	SUpLoad9->Enabled=false;
	SUpLoad10->Enabled=false;
	SUpLoad11->Enabled=false;
	SUpLoad12->Enabled=false;
	SUpLoad13->Enabled=false;
	SUpLoad14->Enabled=false;
	SUpLoad15->Enabled=false;
	SUpLoad16->Enabled=false;
	SUpLoad17->Enabled=false;
	SUpLoad18->Enabled=false;
	SUpLoad19->Enabled=false;
	SUpLoad20->Enabled=false;
	SUpLoad21->Enabled=false;
	SUpLoad22->Enabled=false;
	SUpLoad23->Enabled=false;
	SUpLoad24->Enabled=false;
	SUpLoad25->Enabled=false;
	SUpLoad26->Enabled=false;
	SUpLoad27->Enabled=false;
	SUpLoad28->Enabled=false;
	SUpLoad29->Enabled=false;
	SUpLoad30->Enabled=false;
	SDownLoad1->Enabled=false;
	SDownLoad2->Enabled=false;
	SDownLoad3->Enabled=false;
	SDownLoad4->Enabled=false;
	SDownLoad5->Enabled=false;
	SDownLoad6->Enabled=false;
	SDownLoad7->Enabled=false;
	SDownLoad8->Enabled=false;
	SDownLoad9->Enabled=false;
	SDownLoad10->Enabled=false;
	SDownLoad11->Enabled=false;
	SDownLoad12->Enabled=false;
	SDownLoad13->Enabled=false;
	SDownLoad14->Enabled=false;
	SDownLoad15->Enabled=false;
	SDownLoad16->Enabled=false;
	SDownLoad17->Enabled=false;
	SDownLoad18->Enabled=false;
	SDownLoad19->Enabled=false;
	SDownLoad20->Enabled=false;
	SDownLoad21->Enabled=false;
	SDownLoad22->Enabled=false;
	SDownLoad23->Enabled=false;
	SDownLoad24->Enabled=false;
	SDownLoad25->Enabled=false;
	SDownLoad26->Enabled=false;
	SDownLoad27->Enabled=false;
	SDownLoad28->Enabled=false;
	SDownLoad29->Enabled=false;
	SDownLoad30->Enabled=false;

	CUpLoad1->Enabled=false;
	CUpLoad2->Enabled=false;
	CUpLoad3->Enabled=false;
	CUpLoad4->Enabled=false;
	CUpLoad5->Enabled=false;
	CUpLoad6->Enabled=false;
	CUpLoad7->Enabled=false;
	CUpLoad8->Enabled=false;
	CUpLoad9->Enabled=false;
	CUpLoad10->Enabled=false;
	CUpLoad11->Enabled=false;
	CUpLoad12->Enabled=false;
	CDownLoad1->Enabled=false;
	CDownLoad2->Enabled=false;
	CDownLoad3->Enabled=false;
	CDownLoad4->Enabled=false;
	CDownLoad5->Enabled=false;
	CDownLoad6->Enabled=false;
	CDownLoad7->Enabled=false;
	CDownLoad8->Enabled=false;
	CDownLoad9->Enabled=false;
	CDownLoad10->Enabled=false;
	CDownLoad11->Enabled=false;
	CDownLoad12->Enabled=false;



	index=0;
	if(rankdata.time[index]!=0 && clearstage>index && rankdata.time[index]!=hTime[index])
		SDownLoad1->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && clearstage>index && rankdata.time[index]!=hTime[index])
		SDownLoad2->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && clearstage>index && rankdata.time[index]!=hTime[index])
		SDownLoad3->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && clearstage>index && rankdata.time[index]!=hTime[index])
		SDownLoad4->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && clearstage>index && rankdata.time[index]!=hTime[index])
		SDownLoad5->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && clearstage>index && rankdata.time[index]!=hTime[index])
		SDownLoad6->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && clearstage>index && rankdata.time[index]!=hTime[index])
		SDownLoad7->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && clearstage>index && rankdata.time[index]!=hTime[index])
		SDownLoad8->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && clearstage>index && rankdata.time[index]!=hTime[index])
		SDownLoad9->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && clearstage>index && rankdata.time[index]!=hTime[index])
		SDownLoad10->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && clearstage>index && rankdata.time[index]!=hTime[index])
		SDownLoad11->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && clearstage>index && rankdata.time[index]!=hTime[index])
		SDownLoad12->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && clearstage>index && rankdata.time[index]!=hTime[index])
		SDownLoad13->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && clearstage>index && rankdata.time[index]!=hTime[index])
		SDownLoad14->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && clearstage>index && rankdata.time[index]!=hTime[index])
		SDownLoad15->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && clearstage>index && rankdata.time[index]!=hTime[index])
		SDownLoad16->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && clearstage>index && rankdata.time[index]!=hTime[index])
		SDownLoad17->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && clearstage>index && rankdata.time[index]!=hTime[index])
		SDownLoad18->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && clearstage>index && rankdata.time[index]!=hTime[index])
		SDownLoad19->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && clearstage>index && rankdata.time[index]!=hTime[index])
		SDownLoad20->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && clearstage>index && rankdata.time[index]!=hTime[index])
		SDownLoad21->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && clearstage>index && rankdata.time[index]!=hTime[index])
		SDownLoad22->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && clearstage>index && rankdata.time[index]!=hTime[index])
		SDownLoad23->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && clearstage>index && rankdata.time[index]!=hTime[index])
		SDownLoad24->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && clearstage>index && rankdata.time[index]!=hTime[index])
		SDownLoad25->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && clearstage>index && rankdata.time[index]!=hTime[index])
		SDownLoad26->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && clearstage>index && rankdata.time[index]!=hTime[index])
		SDownLoad27->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && clearstage>index && rankdata.time[index]!=hTime[index])
		SDownLoad28->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && clearstage>index && rankdata.time[index]!=hTime[index])
		SDownLoad29->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && clearstage>index && rankdata.time[index]!=hTime[index])
		SDownLoad30->Enabled=true;

	index++;
	if(rankdata.time[index]!=0 && rankdata.time[index]!=hTime[index])
		CDownLoad1->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && rankdata.time[index]!=hTime[index])
		CDownLoad2->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && rankdata.time[index]!=hTime[index])
		CDownLoad3->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && rankdata.time[index]!=hTime[index])
		CDownLoad4->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && rankdata.time[index]!=hTime[index])
		CDownLoad5->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && rankdata.time[index]!=hTime[index])
		CDownLoad6->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && rankdata.time[index]!=hTime[index])
		CDownLoad7->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && rankdata.time[index]!=hTime[index])
		CDownLoad8->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && rankdata.time[index]!=hTime[index])
		CDownLoad9->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && rankdata.time[index]!=hTime[index])
		CDownLoad10->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && rankdata.time[index]!=hTime[index])
		CDownLoad11->Enabled=true;
	index++;
	if(rankdata.time[index]!=0 && rankdata.time[index]!=hTime[index])
		CDownLoad12->Enabled=true;


	index=0;
	if(rankdata.time[index]!=0 && clearstage>index && rankdata.time[index]!=hTime[index])
		SDownLoad1->Enabled=true;
	index++;

	index=0;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && clearstage>index && hTime[index]!=0)
		SUpLoad1->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && clearstage>index && hTime[index]!=0)
		SUpLoad2->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && clearstage>index && hTime[index]!=0)
		SUpLoad3->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && clearstage>index && hTime[index]!=0)
		SUpLoad4->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && clearstage>index && hTime[index]!=0)
		SUpLoad5->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && clearstage>index && hTime[index]!=0)
		SUpLoad6->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && clearstage>index && hTime[index]!=0)
		SUpLoad7->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && clearstage>index && hTime[index]!=0)
		SUpLoad8->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && clearstage>index && hTime[index]!=0)
		SUpLoad9->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && clearstage>index && hTime[index]!=0)
		SUpLoad10->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && clearstage>index && hTime[index]!=0)
		SUpLoad11->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && clearstage>index && hTime[index]!=0)
		SUpLoad12->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && clearstage>index && hTime[index]!=0)
		SUpLoad13->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && clearstage>index && hTime[index]!=0)
		SUpLoad14->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && clearstage>index && hTime[index]!=0)
		SUpLoad15->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && clearstage>index && hTime[index]!=0)
		SUpLoad16->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && clearstage>index && hTime[index]!=0)
		SUpLoad17->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && clearstage>index && hTime[index]!=0)
		SUpLoad18->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && clearstage>index && hTime[index]!=0)
		SUpLoad19->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && clearstage>index && hTime[index]!=0)
		SUpLoad20->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && clearstage>index && hTime[index]!=0)
		SUpLoad21->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && clearstage>index && hTime[index]!=0)
		SUpLoad22->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && clearstage>index && hTime[index]!=0)
		SUpLoad23->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && clearstage>index && hTime[index]!=0)
		SUpLoad24->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && clearstage>index && hTime[index]!=0)
		SUpLoad25->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && clearstage>index && hTime[index]!=0)
		SUpLoad26->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && clearstage>index && hTime[index]!=0)
		SUpLoad27->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && clearstage>index && hTime[index]!=0)
		SUpLoad28->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && clearstage>index && hTime[index]!=0)
		SUpLoad29->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && clearstage>index && hTime[index]!=0)
		SUpLoad30->Enabled=true;

	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && hTime[index]!=0)
		CUpLoad1->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && hTime[index]!=0)
		CUpLoad2->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && hTime[index]!=0)
		CUpLoad3->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && hTime[index]!=0)
		CUpLoad4->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && hTime[index]!=0)
		CUpLoad5->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && hTime[index]!=0)
		CUpLoad6->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && hTime[index]!=0)
		CUpLoad7->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && hTime[index]!=0)
		CUpLoad8->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && hTime[index]!=0)
		CUpLoad9->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && hTime[index]!=0)
		CUpLoad10->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && hTime[index]!=0)
		CUpLoad11->Enabled=true;
	index++;
	if((rankdata.time[index]==0 || rankdata.time[index]>hTime[index]) && hTime[index]!=0)
		CUpLoad12->Enabled=true;

}













//
//ファイルを読み、チェック用数値を作成する
int createcheck(char *filename)
{
	FILE* file;
	int ans=0,count=0;
	char c,*p=filename;

	//クリアファイルをバイナリで開いて数値を作る
	if((file=fopen(filename,"rb"))==NULL) return false;

	while(fscanf(file,"%c",&c)!=EOF)
	{
		count+=2;
		ans+=(c*count)%256;
	}

	//ファイル名で同じ事をする
	while(*p!='\0')
	{
		count++;
		ans+=((*p)*count)%256;
		p++;
	}

	fclose(file);

	return ans;
}

//ファイルが不正でないかチェックする
bool checkfile(char *filename)
{
	//createcheckの結果とfilename+"c"の中身を比較して結果を返す
	char checkfilename[256];
	strcpy(checkfilename,filename);
	strcat(checkfilename,"c");
	FILE *file=fopen(checkfilename,"r");

	if(file==NULL)
		return false;
	
	int c;
	fscanf(file,"%d",&c);
	fclose(file);

	if(c!=createcheck(filename))
		return false;

	return true;
}

//チェックファイルを作成する
bool createcheckfile(char *filename)
{
	char checkfilename[256];
	strcpy(checkfilename,filename);
	strcat(checkfilename,"c");
	FILE *file=fopen(checkfilename,"w");

	if(file==NULL)
		return false;
	
	fprintf(file,"%d",createcheck(filename));
	fclose(file);

	return true;
}


//チェックファイルの数値を読む
int readcheck(char *filename)
{
	//createcheckの結果とfilename+"c"の中身を比較して結果を返す
	char checkfilename[256];
	strcpy(checkfilename,filename);
	strcat(checkfilename,"c");
	FILE *file=fopen(checkfilename,"r");

	if(file==NULL)
		return false;

	int c;
	fscanf(file,"%d",&c);
	fclose(file);

	return c;
}









//
bool LoadClear()
{
	FILE* file;

	//※最後はこのコメントをはずす
	if(checkfile("data/save/Clear")==false)
	{//データ初期化
		clearstage=0;
		for(int i=0;i<32;i++)
			hTime[i]=0;
	}
	else
	{

		if((file=fopen("data/save/Clear","r"))==NULL) return false;

		fscanf(file,"%d",&clearstage);
		for(int i=0;i<42;i++)
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
	for(int i=0;i<42;i++)
		fprintf(file,"%d\n",hTime[i]);

	fclose(file);


	//チェックファイルを作成
	createcheckfile("data/save/Clear");

//	if((file=fopen("data/save/Clearc","w"))==NULL) return false;
//	fprintf(file,"%d",createcheck("data/save/Clear"));
//	fclose(file);

	return true;
}






void update()
{
	//アップロード、ダウンロードのEnableの設定(クリアしていないステージはダウンロードできなくする)
	rankdatastruct trankdata;
	if(updateinfo(&trankdata))
	{
		//rankdataを反映
		for(int i=0;i<42;i++)
		{
			strcpy(rankdata.name[i],trankdata.name[i]);
			rankdata.chara[i]=trankdata.chara[i];
			rankdata.time[i]=trankdata.time[i];
		}
		LinkKousin();
		setmydata();
	}
	else
	{
		LinkReset();
		setmydata();
	}
}






//
void Delete(bool stage,int index)
{
	char str[100];
	if(stage)
	{
		if(index<=13)
			sprintf(str,"ステージ%dの最短記録とリプレイデータを削除してもよろしいですか？",index);
		else
			sprintf(str,"EXステージ%dの最短記録とリプレイデータを削除してもよろしいですか？",index-13);
		if(MessageBox::Show(str,"ランキング",MessageBoxButtons::YesNo)==DialogResult::Yes)
		{
			//データの消去
			hTime[index-1]=0;
			setmydata();
			LinkKousin();
			if(SaveClear()==false)
				MessageBox::Show("セーブファイルの更新に失敗しました","エラー");
		}
	}
	else
	{
		sprintf(str,"コース%dの最短記録とリプレイデータを削除してもよろしいですか？",index);
		if(MessageBox::Show(str,"ランキング",MessageBoxButtons::YesNo)==DialogResult::Yes)
		{
			//データの消去
			hTime[index+30-1]=0;
			setmydata();
			LinkKousin();
			if(SaveClear()==false)
				MessageBox::Show("セーブファイルの更新に失敗しました","エラー");
		}
	}
}

void UpLoad(bool stage,int index)
{
	//アップロードするに値するかを調べる(アップロード後もちゃんとできたか調べる)
	char str[100];

	char tname[100];
	getname(tname);

	//名前チェック
	if(strcmp(tname,"")==0)
	{
		MessageBox::Show("ユーザー名を入力してください","ランキング");
		return;
	}

	//不正チェック(他人のリプレイデータはアップロードできない※checkファイルが作られていない)
	char filename[256],filename2[256];
	if(stage)
		sprintf(filename,"Data/Save/Replay/Stage/%d.lzh",index-1);
	else
		sprintf(filename,"Data/Save/Replay/Corce/%d.lzh",index-1);

	//チェックファイルを開く
	strcpy(filename2,filename);
	strcat(filename2,"c");
	FILE *file;
	if((file=fopen(filename2,"r"))==NULL)
	{MessageBox::Show("このリプレイデータはダウンロードしたものです","ランキング");return;}
	fclose(file);

	if(!checkfile(filename))
	{MessageBox::Show("リプレイデータが不正です","エラー");return;}


	if(stage)
	{
		if(index<=13)
			sprintf(str,"ステージ%dを、ユーザー名「%s」でアップロードしてもよろしいですか？",index,tname);
		else
			sprintf(str,"EXステージ%dを、ユーザー名「%s」でアップロードしてもよろしいですか？",index-13,tname);
		if(MessageBox::Show(str,"ランキング",MessageBoxButtons::YesNo)==DialogResult::Yes)
		{
			//サーバーに接続＆問い合わせ
			if(sendreplay(stage,index,hTime[index-1],readcheck(filename),tname))
				update();
		}
	}
	else
	{
		sprintf(str,"コース%dを、ユーザー名「%s」でアップロードしてもよろしいですか？",index,tname);
		if(MessageBox::Show(str,"ランキング",MessageBoxButtons::YesNo)==DialogResult::Yes)
		{
			//サーバーに接続＆問い合わせ
			if(sendreplay(stage,index,hTime[index-1+30],readcheck(filename),tname))
				update();
		}
	}

}

void DownLoad(bool stage,int index)
{
	char str[100];
	if(stage)
	{
		if(index<=13)
			sprintf(str,"ステージ%dのリプレイデータをダウンロードし、上書きしてもよろしいですか？",index);
		else
			sprintf(str,"EXステージ%dのリプレイデータをダウンロードし、上書きしてもよろしいですか？",index-13);

		if(MessageBox::Show(str,"ランキング",MessageBoxButtons::YesNo)==DialogResult::Yes)
		{
			if(hTime[index-1]<rankdata.time[index-1] && hTime[index-1]!=0)
				if(MessageBox::Show("ランキングに入ることのできる記録がすでに存在します！\n本当に上書きしてもよろしいですか？","ランキング",MessageBoxButtons::YesNo)==DialogResult::No)
					return;

			int onlinetime;
			if(recvreplay(stage,index,&onlinetime))
			{
				hTime[index-1]=onlinetime;
				update();
				SaveClear();
			}
		}
	}
	else
	{
		sprintf(str,"コース%dのリプレイデータをダウンロードし、上書きしてもよろしいですか？",index);
		if(MessageBox::Show(str,"ランキング",MessageBoxButtons::YesNo)==DialogResult::Yes)
		{
			if(hTime[index-1+30]<rankdata.time[index-1+30] && hTime[index-1+30]!=0)
				if(MessageBox::Show("ランキングに入ることのできる記録がすでに存在します！\n本当に上書きしてもよろしいですか？","ランキング",MessageBoxButtons::YesNo)==DialogResult::No)
					return;

			int onlinetime;
			if(recvreplay(stage,index,&onlinetime))
			{
				hTime[index-1+30]=onlinetime;
				update();
				SaveClear();
			}
		}
	}
}


private: System::Void Form1_Load(System::Object *  sender, System::EventArgs *  e)
		 {//フォームロード

			 if(mutexcheck()==false)
			 {
				 MessageBox::Show("多重起動はできません","ランキング");
				 Form::Close();
			 }

			 //ユーザー名の読み込み
			 FILE *file;
			 if((file=fopen("data/save/name","r"))!=NULL)
			 {
				 fscanf(file,"%s",name);
				 fclose(file);
			 }

			 if(strlen(name)>20)//全角10文字
				UserNameText->Text="";
			 else
				UserNameText->Text=name;

			 //セーブデータの読み込み
			if(LoadClear()==false)
			{MessageBox::Show("セーブファイルがオープンできませんでした","エラー");Form::Close();}

			LinkReset();
			update();
			setmydata();

		 }

private: System::Void UserNameText_TextChanged(System::Object *  sender, System::EventArgs *  e)
		 {//テキスト内容変更(即座に保存)

			 //ユーザー名の保存
			 FILE *file;

			 if((file=fopen("data/save/name","w"))!=NULL)
			 {
				 fprintf(file,"%s",UserNameText->Text);
				 fclose(file);
			 }
		 }

private: System::Void KousinButton_Click(System::Object *  sender, System::EventArgs *  e)
		 {//更新ボタン
			 //更新フォームの表示
			 update();
		 }











private: System::Void SDelete1_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(true,1);
		 }
private: System::Void SDelete2_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(true,2);
		 }
private: System::Void SDelete3_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(true,3);
		 }
private: System::Void SDelete4_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(true,4);
		 }
private: System::Void SDelete5_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(true,5);
		 }
private: System::Void SDelete6_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(true,6);
		 }
private: System::Void SDelete7_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(true,7);
		 }
private: System::Void SDelete8_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(true,8);
		 }
private: System::Void SDelete9_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(true,9);
		 }
private: System::Void SDelete10_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(true,10);
		 }
private: System::Void SDelete11_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(true,11);
		 }
private: System::Void SDelete12_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(true,12);
		 }
private: System::Void SDelete13_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(true,13);
		 }
private: System::Void SDelete14_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(true,14);
		 }
private: System::Void SDelete15_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(true,15);
		 }
private: System::Void SDelete16_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(true,16);
		 }
private: System::Void SDelete17_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(true,17);
		 }
private: System::Void SDelete18_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(true,18);
		 }
private: System::Void SDelete19_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(true,19);
		 }
private: System::Void SDelete20_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(true,20);
		 }
private: System::Void SDelete21_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(true,21);
		 }
private: System::Void SDelete22_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(true,22);
		 }
private: System::Void SDelete23_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(true,23);
		 }
private: System::Void SDelete24_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(true,24);
		 }
private: System::Void SDelete25_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(true,25);
		 }
private: System::Void SDelete26_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(true,26);
		 }
private: System::Void SDelete27_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(true,27);
		 }
private: System::Void SDelete28_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(true,28);
		 }
private: System::Void SDelete29_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(true,29);
		 }
private: System::Void SDelete30_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(true,30);
		 }


private: System::Void CDelete1_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(false,1);
		 }
private: System::Void CDelete2_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(false,2);
		 }
private: System::Void CDelete3_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(false,3);
		 }
private: System::Void CDelete4_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(false,4);
		 }
private: System::Void CDelete5_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(false,5);
		 }
private: System::Void CDelete6_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(false,6);
		 }
private: System::Void CDelete7_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(false,7);
		 }
private: System::Void CDelete8_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(false,8);
		 }
private: System::Void CDelete9_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(false,9);
		 }
private: System::Void CDelete10_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(false,10);
		 }
private: System::Void CDelete11_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(false,11);
		 }
private: System::Void CDelete12_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 Delete(false,12);
		 }












private: System::Void SUpLoad1_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(true,1);
		 }
private: System::Void SUpLoad2_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(true,2);
		 }
private: System::Void SUpLoad3_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(true,3);
		 }
private: System::Void SUpLoad4_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(true,4);
		 }
private: System::Void SUpLoad5_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(true,5);
		 }
private: System::Void SUpLoad6_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(true,6);
		 }
private: System::Void SUpLoad7_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(true,7);
		 }
private: System::Void SUpLoad8_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(true,8);
		 }
private: System::Void SUpLoad9_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(true,9);
		 }
private: System::Void SUpLoad10_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(true,10);
		 }
private: System::Void SUpLoad11_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(true,11);
		 }
private: System::Void SUpLoad12_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(true,12);
		 }
private: System::Void SUpLoad13_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(true,13);
		 }
private: System::Void SUpLoad14_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(true,14);
		 }
private: System::Void SUpLoad15_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(true,15);
		 }
private: System::Void SUpLoad16_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(true,16);
		 }
private: System::Void SUpLoad17_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(true,17);
		 }
private: System::Void SUpLoad18_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(true,18);
		 }
private: System::Void SUpLoad19_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(true,19);
		 }
private: System::Void SUpLoad20_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(true,20);
		 }
private: System::Void SUpLoad21_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(true,21);
		 }
private: System::Void SUpLoad22_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(true,22);
		 }
private: System::Void SUpLoad23_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(true,23);
		 }
private: System::Void SUpLoad24_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(true,24);
		 }
private: System::Void SUpLoad25_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(true,25);
		 }
private: System::Void SUpLoad26_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(true,26);
		 }
private: System::Void SUpLoad27_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(true,27);
		 }
private: System::Void SUpLoad28_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(true,28);
		 }
private: System::Void SUpLoad29_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(true,29);
		 }
private: System::Void SUpLoad30_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(true,30);
		 }



private: System::Void CUpLoad1_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(false,1);
		 }
private: System::Void CUpLoad2_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(false,2);
		 }
private: System::Void CUpLoad3_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(false,3);
		 }
private: System::Void CUpLoad4_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(false,4);
		 }
private: System::Void CUpLoad5_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(false,5);
		 }
private: System::Void CUpLoad6_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(false,6);
		 }
private: System::Void CUpLoad7_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(false,7);
		 }
private: System::Void CUpLoad8_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(false,8);
		 }
private: System::Void CUpLoad9_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(false,9);
		 }
private: System::Void CUpLoad10_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(false,10);
		 }
private: System::Void CUpLoad11_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(false,11);
		 }
private: System::Void CUpLoad12_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 UpLoad(false,12);
		 }













private: System::Void SDownLoad1_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(true,1);
		 }
private: System::Void SDownLoad2_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(true,2);
		 }
private: System::Void SDownLoad3_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(true,3);
		 }
private: System::Void SDownLoad4_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(true,4);
		 }
private: System::Void SDownLoad5_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(true,5);
		 }
private: System::Void SDownLoad6_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(true,6);
		 }
private: System::Void SDownLoad7_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(true,7);
		 }
private: System::Void SDownLoad8_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(true,8);
		 }
private: System::Void SDownLoad9_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(true,9);
		 }
private: System::Void SDownLoad10_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(true,10);
		 }
private: System::Void SDownLoad11_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(true,11);
		 }
private: System::Void SDownLoad12_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(true,12);
		 }
private: System::Void SDownLoad13_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(true,13);
		 }
private: System::Void SDownLoad14_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(true,14);
		 }
private: System::Void SDownLoad15_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(true,15);
		 }
private: System::Void SDownLoad16_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(true,16);
		 }
private: System::Void SDownLoad17_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(true,17);
		 }
private: System::Void SDownLoad18_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(true,18);
		 }
private: System::Void SDownLoad19_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(true,19);
		 }
private: System::Void SDownLoad20_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(true,20);
		 }
private: System::Void SDownLoad21_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(true,21);
		 }
private: System::Void SDownLoad22_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(true,22);
		 }
private: System::Void SDownLoad23_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(true,23);
		 }
private: System::Void SDownLoad24_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(true,24);
		 }
private: System::Void SDownLoad25_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(true,25);
		 }
private: System::Void SDownLoad26_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(true,26);
		 }
private: System::Void SDownLoad27_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(true,27);
		 }
private: System::Void SDownLoad28_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(true,28);
		 }
private: System::Void SDownLoad29_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(true,29);
		 }
private: System::Void SDownLoad30_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(true,30);
		 }



private: System::Void CDownLoad1_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(false,1);
		 }
private: System::Void CDownLoad2_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(false,2);
		 }
private: System::Void CDownLoad3_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(false,3);
		 }
private: System::Void CDownLoad4_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(false,4);
		 }
private: System::Void CDownLoad5_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(false,5);
		 }
private: System::Void CDownLoad6_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(false,6);
		 }
private: System::Void CDownLoad7_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(false,7);
		 }
private: System::Void CDownLoad8_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(false,8);
		 }
private: System::Void CDownLoad9_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(false,9);
		 }
private: System::Void CDownLoad10_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(false,10);
		 }
private: System::Void CDownLoad11_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(false,11);
		 }
private: System::Void CDownLoad12_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			 DownLoad(false,12);
		 }

