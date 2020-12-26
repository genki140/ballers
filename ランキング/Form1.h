#pragma once




int clearstage;//ステージのクリア数
int hTime[42];//hTimeの[0～29]までがステージ、hTimeの[30～41]までがコース
//char ontime[42][10];
//char offtime[42][10];

rankdatastruct rankdata;
char name[100];


namespace My
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary> 
	/// Form1 の概要
	///
	/// 警告 : このクラスの名前を変更する場合、このクラスが依存するすべての .resx ファイルに関連付けられた 
	///          マネージ リソース コンパイラ ツールに対して 'Resource File Name' プロパティを
	///          変更する必要があります。この変更を行わないと、
	///          デザイナと、このフォームに関連付けられたローカライズ済みリソースとが正しく相互に利用できなくなります。
	/// </summary>
	public __gc class Form1 : public System::Windows::Forms::Form
	{	
	public:
		Form1(void)
		{
			InitializeComponent();
		}
  
	protected:
		void Dispose(Boolean disposing)
		{
			if (disposing && components)
			{
				components->Dispose();
			}
			__super::Dispose(disposing);
		}
	private: System::Windows::Forms::TabControl *  tabControl1;
	private: System::Windows::Forms::Button *  KousinButton;

	private: System::Windows::Forms::Label *  label1;
	private: System::Windows::Forms::Label *  OFFChar1;
	private: System::Windows::Forms::Label *  OFFCorce1;

	private: System::Windows::Forms::GroupBox *  groupBox21;
	private: System::Windows::Forms::GroupBox *  groupBox20;






	private: System::Windows::Forms::GroupBox *  groupBox11;
	private: System::Windows::Forms::GroupBox *  groupBox12;
	private: System::Windows::Forms::GroupBox *  groupBox13;
	private: System::Windows::Forms::GroupBox *  groupBox14;
	private: System::Windows::Forms::GroupBox *  groupBox15;
	private: System::Windows::Forms::GroupBox *  groupBox16;
	private: System::Windows::Forms::GroupBox *  groupBox17;
	private: System::Windows::Forms::GroupBox *  groupBox18;
	private: System::Windows::Forms::GroupBox *  groupBox19;
	private: System::Windows::Forms::GroupBox *  groupBox10;
	private: System::Windows::Forms::GroupBox *  groupBox9;
	private: System::Windows::Forms::GroupBox *  groupBox8;
	private: System::Windows::Forms::GroupBox *  groupBox7;
	private: System::Windows::Forms::GroupBox *  groupBox6;
	private: System::Windows::Forms::GroupBox *  groupBox5;
	private: System::Windows::Forms::Label *  OFFStage4;
	private: System::Windows::Forms::GroupBox *  groupBox4;
	private: System::Windows::Forms::Label *  OFFStage3;
	private: System::Windows::Forms::GroupBox *  groupBox3;
	private: System::Windows::Forms::Label *  OFFStage2;
	private: System::Windows::Forms::GroupBox *  groupBox2;
	private: System::Windows::Forms::Label *  OFFStage1;
	private: System::Windows::Forms::GroupBox *  groupBox1;
	private: System::Windows::Forms::TabPage *  OFFPage;
	private: System::Windows::Forms::Label *  OFFCorce2;
	private: System::Windows::Forms::GroupBox *  groupBox22;
	private: System::Windows::Forms::Label *  label18;
	private: System::Windows::Forms::GroupBox *  groupBox23;
	private: System::Windows::Forms::Label *  label27;
	private: System::Windows::Forms::GroupBox *  groupBox24;
	private: System::Windows::Forms::Label *  label36;
	private: System::Windows::Forms::GroupBox *  groupBox25;
	private: System::Windows::Forms::Label *  label45;
	private: System::Windows::Forms::GroupBox *  groupBox26;
	private: System::Windows::Forms::Label *  label51;
	private: System::Windows::Forms::GroupBox *  groupBox27;
	private: System::Windows::Forms::Label *  label54;
	private: System::Windows::Forms::GroupBox *  groupBox28;
	private: System::Windows::Forms::Label *  label57;
	private: System::Windows::Forms::GroupBox *  groupBox29;
	private: System::Windows::Forms::Label *  label60;
	private: System::Windows::Forms::GroupBox *  groupBox30;
	private: System::Windows::Forms::Label *  label63;
	private: System::Windows::Forms::GroupBox *  groupBox31;
	private: System::Windows::Forms::Label *  label66;
	private: System::Windows::Forms::GroupBox *  groupBox32;
	private: System::Windows::Forms::GroupBox *  groupBox33;
	private: System::Windows::Forms::TabPage *  ONPage;
	private: System::Windows::Forms::GroupBox *  groupBox34;

	private: System::Windows::Forms::Label *  label69;
	private: System::Windows::Forms::GroupBox *  groupBox35;

	private: System::Windows::Forms::Label *  label72;
	private: System::Windows::Forms::GroupBox *  groupBox36;

	private: System::Windows::Forms::Label *  label75;
	private: System::Windows::Forms::GroupBox *  groupBox37;

	private: System::Windows::Forms::Label *  label78;
	private: System::Windows::Forms::GroupBox *  groupBox38;

	private: System::Windows::Forms::Label *  label81;
	private: System::Windows::Forms::GroupBox *  groupBox39;

	private: System::Windows::Forms::Label *  label84;
	private: System::Windows::Forms::GroupBox *  groupBox40;

	private: System::Windows::Forms::Label *  label87;
	private: System::Windows::Forms::GroupBox *  groupBox41;

	private: System::Windows::Forms::Label *  label90;
	private: System::Windows::Forms::GroupBox *  groupBox42;

	private: System::Windows::Forms::Label *  label93;
	private: System::Windows::Forms::GroupBox *  groupBox43;

	private: System::Windows::Forms::Label *  label96;
	private: System::Windows::Forms::GroupBox *  groupBox44;

	private: System::Windows::Forms::Label *  label99;
	private: System::Windows::Forms::GroupBox *  groupBox45;

	private: System::Windows::Forms::Label *  label102;
	private: System::Windows::Forms::GroupBox *  groupBox46;
	private: System::Windows::Forms::GroupBox *  groupBox47;
	private: System::Windows::Forms::Label *  label104;
	private: System::Windows::Forms::Label *  label106;
	private: System::Windows::Forms::GroupBox *  groupBox48;
	private: System::Windows::Forms::Label *  label108;
	private: System::Windows::Forms::GroupBox *  groupBox49;
	private: System::Windows::Forms::Label *  label110;
	private: System::Windows::Forms::GroupBox *  groupBox50;
	private: System::Windows::Forms::Label *  label112;
	private: System::Windows::Forms::GroupBox *  groupBox51;
	private: System::Windows::Forms::Label *  label114;
	private: System::Windows::Forms::GroupBox *  groupBox52;
	private: System::Windows::Forms::Label *  label116;
	private: System::Windows::Forms::GroupBox *  groupBox53;
	private: System::Windows::Forms::Label *  label118;
	private: System::Windows::Forms::GroupBox *  groupBox54;
	private: System::Windows::Forms::Label *  label120;
	private: System::Windows::Forms::GroupBox *  groupBox55;
	private: System::Windows::Forms::Label *  label122;
	private: System::Windows::Forms::GroupBox *  groupBox56;
	private: System::Windows::Forms::Label *  label124;
	private: System::Windows::Forms::GroupBox *  groupBox57;
	private: System::Windows::Forms::Label *  label126;
	private: System::Windows::Forms::GroupBox *  groupBox58;
	private: System::Windows::Forms::Label *  label128;
	private: System::Windows::Forms::GroupBox *  groupBox59;
	private: System::Windows::Forms::Label *  label130;
	private: System::Windows::Forms::GroupBox *  groupBox60;
	private: System::Windows::Forms::Label *  label132;
	private: System::Windows::Forms::GroupBox *  groupBox61;
	private: System::Windows::Forms::Label *  label134;
	private: System::Windows::Forms::GroupBox *  groupBox62;
	private: System::Windows::Forms::Label *  label136;
	private: System::Windows::Forms::GroupBox *  groupBox63;
	private: System::Windows::Forms::Label *  label138;
	private: System::Windows::Forms::GroupBox *  groupBox64;
	private: System::Windows::Forms::Label *  label140;
	private: System::Windows::Forms::GroupBox *  groupBox65;
	private: System::Windows::Forms::Label *  label142;
	private: System::Windows::Forms::GroupBox *  groupBox66;
	private: System::Windows::Forms::Label *  OFFCTime12;
	private: System::Windows::Forms::Label *  OFFCTime11;
	private: System::Windows::Forms::Label *  OFFCTime10;
	private: System::Windows::Forms::Label *  OFFCTime9;
	private: System::Windows::Forms::Label *  OFFCTime8;
	private: System::Windows::Forms::Label *  OFFCTime7;
	private: System::Windows::Forms::Label *  OFFSTime20;
	private: System::Windows::Forms::Label *  OFFStage20;
	private: System::Windows::Forms::Label *  OFFSTime19;
	private: System::Windows::Forms::Label *  OFFStage19;
	private: System::Windows::Forms::Label *  OFFSTime18;
	private: System::Windows::Forms::Label *  OFFStage18;
	private: System::Windows::Forms::Label *  OFFSTime17;
	private: System::Windows::Forms::Label *  OFFStage17;
	private: System::Windows::Forms::Label *  OFFSTime16;
	private: System::Windows::Forms::Label *  OFFStage16;
	private: System::Windows::Forms::Label *  OFFSTime15;
	private: System::Windows::Forms::Label *  OFFStage15;
	private: System::Windows::Forms::Label *  OFFSTime14;
	private: System::Windows::Forms::Label *  OFFStage14;
	private: System::Windows::Forms::Label *  OFFSTime13;
	private: System::Windows::Forms::Label *  OFFStage13;
	private: System::Windows::Forms::Label *  OFFSTime12;
	private: System::Windows::Forms::Label *  OFFStage12;
	private: System::Windows::Forms::Label *  OFFSTime11;
	private: System::Windows::Forms::Label *  OFFStage11;
	private: System::Windows::Forms::Label *  OFFSTime10;
	private: System::Windows::Forms::Label *  OFFStage10;
	private: System::Windows::Forms::Label *  OFFSTime9;
	private: System::Windows::Forms::Label *  OFFStage9;
	private: System::Windows::Forms::Label *  OFFSTime8;
	private: System::Windows::Forms::Label *  OFFStage8;
	private: System::Windows::Forms::Label *  OFFSTime7;
	private: System::Windows::Forms::Label *  OFFStage7;
	private: System::Windows::Forms::Label *  OFFSTime6;
	private: System::Windows::Forms::Label *  OFFStage6;
	private: System::Windows::Forms::Label *  OFFSTime5;
	private: System::Windows::Forms::Label *  OFFStage5;
	private: System::Windows::Forms::Label *  OFFSTime4;
	private: System::Windows::Forms::Label *  OFFSTime3;
	private: System::Windows::Forms::Label *  OFFSTime2;
	private: System::Windows::Forms::Label *  OFFSTime1;
	private: System::Windows::Forms::Label *  OFFCTime6;
	private: System::Windows::Forms::Label *  OFFCTime5;
	private: System::Windows::Forms::Label *  OFFCTime4;
	private: System::Windows::Forms::Label *  OFFCTime3;
	private: System::Windows::Forms::Label *  OFFCTime2;
	private: System::Windows::Forms::Label *  OFFCTime1;
	private: System::Windows::Forms::Label *  OFFChar12;
	private: System::Windows::Forms::Label *  OFFChar11;
	private: System::Windows::Forms::Label *  OFFChar10;
	private: System::Windows::Forms::Label *  OFFChar9;
	private: System::Windows::Forms::Label *  OFFChar8;
	private: System::Windows::Forms::Label *  OFFChar7;
	private: System::Windows::Forms::Label *  OFFChar6;
	private: System::Windows::Forms::Label *  OFFChar5;
	private: System::Windows::Forms::Label *  OFFChar4;
	private: System::Windows::Forms::Label *  OFFChar3;
	private: System::Windows::Forms::Label *  OFFChar2;
	private: System::Windows::Forms::LinkLabel *  CUpLoad12;
	private: System::Windows::Forms::LinkLabel *  CUpLoad11;
	private: System::Windows::Forms::LinkLabel *  CUpLoad10;
	private: System::Windows::Forms::LinkLabel *  CUpLoad9;
	private: System::Windows::Forms::LinkLabel *  CUpLoad8;
	private: System::Windows::Forms::LinkLabel *  CUpLoad7;
	private: System::Windows::Forms::LinkLabel *  CUpLoad6;
	private: System::Windows::Forms::LinkLabel *  CUpLoad5;
	private: System::Windows::Forms::LinkLabel *  CUpLoad4;
	private: System::Windows::Forms::LinkLabel *  CUpLoad3;
	private: System::Windows::Forms::LinkLabel *  CUpLoad2;
	private: System::Windows::Forms::LinkLabel *  CUpLoad1;
	private: System::Windows::Forms::LinkLabel *  SUpLoad20;
	private: System::Windows::Forms::LinkLabel *  SUpLoad19;
	private: System::Windows::Forms::LinkLabel *  SUpLoad18;
	private: System::Windows::Forms::LinkLabel *  SUpLoad17;
	private: System::Windows::Forms::LinkLabel *  SUpLoad16;
	private: System::Windows::Forms::LinkLabel *  SUpLoad15;
	private: System::Windows::Forms::LinkLabel *  SUpLoad14;
	private: System::Windows::Forms::LinkLabel *  SUpLoad13;
	private: System::Windows::Forms::LinkLabel *  SUpLoad12;
	private: System::Windows::Forms::LinkLabel *  SUpLoad11;
	private: System::Windows::Forms::LinkLabel *  SUpLoad10;
	private: System::Windows::Forms::LinkLabel *  SUpLoad9;
	private: System::Windows::Forms::LinkLabel *  SUpLoad8;
	private: System::Windows::Forms::LinkLabel *  SUpLoad7;
	private: System::Windows::Forms::LinkLabel *  SUpLoad6;
	private: System::Windows::Forms::LinkLabel *  SUpLoad5;
	private: System::Windows::Forms::LinkLabel *  SUpLoad4;
	private: System::Windows::Forms::LinkLabel *  SUpLoad3;
	private: System::Windows::Forms::LinkLabel *  SUpLoad2;
	private: System::Windows::Forms::LinkLabel *  SUpLoad1;
	private: System::Windows::Forms::LinkLabel *  SDownLoad8;
	private: System::Windows::Forms::LinkLabel *  SDownLoad7;
	private: System::Windows::Forms::LinkLabel *  SDownLoad6;
	private: System::Windows::Forms::LinkLabel *  SDownLoad5;
	private: System::Windows::Forms::LinkLabel *  SDownLoad4;
	private: System::Windows::Forms::LinkLabel *  SDownLoad3;
	private: System::Windows::Forms::LinkLabel *  SDownLoad2;
	private: System::Windows::Forms::LinkLabel *  SDownLoad1;
	private: System::Windows::Forms::Label *  ONCTime12;
	private: System::Windows::Forms::Label *  ONCTime11;
	private: System::Windows::Forms::Label *  ONCTime10;
	private: System::Windows::Forms::Label *  ONCTime9;
	private: System::Windows::Forms::Label *  ONCTime8;
	private: System::Windows::Forms::Label *  ONCTime7;
	private: System::Windows::Forms::Label *  ONCTime6;
	private: System::Windows::Forms::Label *  ONCTime5;
	private: System::Windows::Forms::Label *  ONCTime4;
	private: System::Windows::Forms::Label *  ONCTime3;
	private: System::Windows::Forms::Label *  ONCTime2;
	private: System::Windows::Forms::Label *  ONCTime1;
	private: System::Windows::Forms::Label *  ONSTime20;
	private: System::Windows::Forms::Label *  ONSTime19;
	private: System::Windows::Forms::Label *  ONSTime18;
	private: System::Windows::Forms::Label *  ONSTime17;
	private: System::Windows::Forms::Label *  ONSTime16;
	private: System::Windows::Forms::Label *  ONSTime15;
	private: System::Windows::Forms::Label *  ONSTime14;
	private: System::Windows::Forms::Label *  ONSTime13;
	private: System::Windows::Forms::Label *  ONSTime12;
	private: System::Windows::Forms::Label *  ONSTime11;
	private: System::Windows::Forms::Label *  ONSTime10;
	private: System::Windows::Forms::Label *  ONSTime9;
	private: System::Windows::Forms::Label *  ONSTime8;
	private: System::Windows::Forms::Label *  ONSTime7;
	private: System::Windows::Forms::Label *  ONSTime6;
	private: System::Windows::Forms::Label *  ONSTime5;
	private: System::Windows::Forms::Label *  ONSTime4;
	private: System::Windows::Forms::Label *  ONSTime3;
	private: System::Windows::Forms::Label *  ONSTime2;
	private: System::Windows::Forms::Label *  ONSTime1;
	private: System::Windows::Forms::LinkLabel *  SDelete1;
	private: System::Windows::Forms::LinkLabel *  SDelete2;
	private: System::Windows::Forms::LinkLabel *  SDelete3;
	private: System::Windows::Forms::LinkLabel *  SDelete6;
	private: System::Windows::Forms::LinkLabel *  SDelete5;
	private: System::Windows::Forms::LinkLabel *  SDelete4;
	private: System::Windows::Forms::LinkLabel *  SDelete9;
	private: System::Windows::Forms::LinkLabel *  SDelete8;
	private: System::Windows::Forms::LinkLabel *  SDelete7;
	private: System::Windows::Forms::LinkLabel *  SDelete12;
	private: System::Windows::Forms::LinkLabel *  SDelete11;
	private: System::Windows::Forms::LinkLabel *  SDelete10;
	private: System::Windows::Forms::LinkLabel *  SDelete15;
	private: System::Windows::Forms::LinkLabel *  SDelete14;
	private: System::Windows::Forms::LinkLabel *  SDelete13;
	private: System::Windows::Forms::LinkLabel *  SDelete18;
	private: System::Windows::Forms::LinkLabel *  SDelete17;
	private: System::Windows::Forms::LinkLabel *  SDelete16;
	private: System::Windows::Forms::LinkLabel *  SDelete20;
	private: System::Windows::Forms::LinkLabel *  SDelete19;
	private: System::Windows::Forms::LinkLabel *  CDelete12;
	private: System::Windows::Forms::LinkLabel *  CDelete11;
	private: System::Windows::Forms::LinkLabel *  CDelete10;
	private: System::Windows::Forms::LinkLabel *  CDelete9;
	private: System::Windows::Forms::LinkLabel *  CDelete8;
	private: System::Windows::Forms::LinkLabel *  CDelete7;
	private: System::Windows::Forms::LinkLabel *  CDelete6;
	private: System::Windows::Forms::LinkLabel *  CDelete5;
	private: System::Windows::Forms::LinkLabel *  CDelete4;
	private: System::Windows::Forms::LinkLabel *  CDelete3;
	private: System::Windows::Forms::LinkLabel *  CDelete2;
	private: System::Windows::Forms::LinkLabel *  CDelete1;
	private: System::Windows::Forms::Label *  SName6;
	private: System::Windows::Forms::Label *  SName5;
	private: System::Windows::Forms::Label *  SName4;
	private: System::Windows::Forms::Label *  SName3;
	private: System::Windows::Forms::Label *  SName2;
	private: System::Windows::Forms::Label *  SName1;
	private: System::Windows::Forms::Label *  SName8;
	private: System::Windows::Forms::Label *  SName7;
	private: System::Windows::Forms::Label *  SName14;
	private: System::Windows::Forms::Label *  SName13;
	private: System::Windows::Forms::Label *  SName12;
	private: System::Windows::Forms::Label *  SName11;
	private: System::Windows::Forms::Label *  SName10;
	private: System::Windows::Forms::Label *  SName9;
	private: System::Windows::Forms::Label *  SName20;
	private: System::Windows::Forms::Label *  SName19;
	private: System::Windows::Forms::Label *  SName18;
	private: System::Windows::Forms::Label *  SName17;
	private: System::Windows::Forms::Label *  SName16;
	private: System::Windows::Forms::Label *  SName15;
	private: System::Windows::Forms::Label *  CName12;
	private: System::Windows::Forms::Label *  CName11;
	private: System::Windows::Forms::Label *  CName10;
	private: System::Windows::Forms::Label *  CName9;
	private: System::Windows::Forms::Label *  CName8;
	private: System::Windows::Forms::Label *  CName7;
	private: System::Windows::Forms::Label *  CName6;
	private: System::Windows::Forms::Label *  CName5;
	private: System::Windows::Forms::Label *  CName4;
	private: System::Windows::Forms::Label *  CName3;
	private: System::Windows::Forms::Label *  CName2;
	private: System::Windows::Forms::LinkLabel *  CDownLoad12;
	private: System::Windows::Forms::LinkLabel *  CDownLoad11;
	private: System::Windows::Forms::LinkLabel *  CDownLoad10;
	private: System::Windows::Forms::LinkLabel *  CDownLoad9;
	private: System::Windows::Forms::LinkLabel *  CDownLoad8;
	private: System::Windows::Forms::LinkLabel *  CDownLoad7;
	private: System::Windows::Forms::LinkLabel *  CDownLoad6;
	private: System::Windows::Forms::LinkLabel *  CDownLoad5;
	private: System::Windows::Forms::LinkLabel *  CDownLoad4;
	private: System::Windows::Forms::LinkLabel *  CDownLoad3;
	private: System::Windows::Forms::LinkLabel *  CDownLoad2;
	private: System::Windows::Forms::LinkLabel *  CDownLoad1;
	private: System::Windows::Forms::LinkLabel *  SDownLoad20;
	private: System::Windows::Forms::LinkLabel *  SDownLoad19;
	private: System::Windows::Forms::LinkLabel *  SDownLoad18;
	private: System::Windows::Forms::LinkLabel *  SDownLoad17;
	private: System::Windows::Forms::LinkLabel *  SDownLoad16;
	private: System::Windows::Forms::LinkLabel *  SDownLoad15;
	private: System::Windows::Forms::LinkLabel *  SDownLoad14;
	private: System::Windows::Forms::LinkLabel *  SDownLoad13;
	private: System::Windows::Forms::LinkLabel *  SDownLoad12;
	private: System::Windows::Forms::LinkLabel *  SDownLoad11;
	private: System::Windows::Forms::LinkLabel *  SDownLoad10;
	private: System::Windows::Forms::LinkLabel *  SDownLoad9;
	private: System::Windows::Forms::Label *  CName1;
	private: System::Windows::Forms::TextBox *  UserNameText;
private: System::Windows::Forms::LinkLabel *  SDelete28;
private: System::Windows::Forms::LinkLabel *  SDelete27;
private: System::Windows::Forms::LinkLabel *  SDelete26;
private: System::Windows::Forms::LinkLabel *  SDelete25;
private: System::Windows::Forms::LinkLabel *  SDelete24;
private: System::Windows::Forms::LinkLabel *  SDelete23;
private: System::Windows::Forms::LinkLabel *  SDelete22;
private: System::Windows::Forms::LinkLabel *  SDelete21;
private: System::Windows::Forms::GroupBox *  groupBox67;

private: System::Windows::Forms::Label *  OFFStage28;


private: System::Windows::Forms::Label *  OFFStage27;

private: System::Windows::Forms::GroupBox *  groupBox68;

private: System::Windows::Forms::Label *  OFFStage26;

private: System::Windows::Forms::GroupBox *  groupBox69;

private: System::Windows::Forms::Label *  OFFStage25;

private: System::Windows::Forms::GroupBox *  groupBox70;

private: System::Windows::Forms::Label *  OFFStage24;

private: System::Windows::Forms::GroupBox *  groupBox71;

private: System::Windows::Forms::Label *  OFFStage23;

private: System::Windows::Forms::GroupBox *  groupBox72;

private: System::Windows::Forms::Label *  OFFStage22;

private: System::Windows::Forms::GroupBox *  groupBox73;

private: System::Windows::Forms::Label *  OFFStage21;

private: System::Windows::Forms::GroupBox *  groupBox74;
private: System::Windows::Forms::LinkLabel *  SDelete30;
private: System::Windows::Forms::LinkLabel *  SDelete29;
private: System::Windows::Forms::GroupBox *  groupBox75;

private: System::Windows::Forms::Label *  OFFStage30;


private: System::Windows::Forms::Label *  OFFStage29;

private: System::Windows::Forms::GroupBox *  groupBox76;
private: System::Windows::Forms::Label *  OFFSTime28;
private: System::Windows::Forms::LinkLabel *  SUpLoad28;
private: System::Windows::Forms::Label *  OFFSTime27;
private: System::Windows::Forms::LinkLabel *  SUpLoad27;
private: System::Windows::Forms::Label *  OFFSTime26;
private: System::Windows::Forms::LinkLabel *  SUpLoad26;
private: System::Windows::Forms::Label *  OFFSTime25;
private: System::Windows::Forms::LinkLabel *  SUpLoad25;
private: System::Windows::Forms::Label *  OFFSTime24;
private: System::Windows::Forms::LinkLabel *  SUpLoad24;
private: System::Windows::Forms::Label *  OFFSTime23;
private: System::Windows::Forms::LinkLabel *  SUpLoad23;
private: System::Windows::Forms::Label *  OFFSTime22;
private: System::Windows::Forms::LinkLabel *  SUpLoad22;
private: System::Windows::Forms::Label *  OFFSTime21;
private: System::Windows::Forms::LinkLabel *  SUpLoad21;
private: System::Windows::Forms::Label *  OFFSTime30;
private: System::Windows::Forms::LinkLabel *  SUpLoad30;
private: System::Windows::Forms::Label *  OFFSTime29;
private: System::Windows::Forms::LinkLabel *  SUpLoad29;
private: System::Windows::Forms::GroupBox *  groupBox77;
private: System::Windows::Forms::Label *  SName23;
private: System::Windows::Forms::Label *  SName22;
private: System::Windows::Forms::Label *  SName21;
private: System::Windows::Forms::Label *  SName29;
private: System::Windows::Forms::Label *  SName28;
private: System::Windows::Forms::Label *  SName27;
private: System::Windows::Forms::Label *  SName26;
private: System::Windows::Forms::Label *  SName25;
private: System::Windows::Forms::Label *  SName24;
private: System::Windows::Forms::GroupBox *  groupBox78;
private: System::Windows::Forms::Label *  label11;
private: System::Windows::Forms::LinkLabel *  SDownLoad29;
private: System::Windows::Forms::Label *  label12;
private: System::Windows::Forms::LinkLabel *  SDownLoad28;
private: System::Windows::Forms::GroupBox *  groupBox79;
private: System::Windows::Forms::Label *  label13;
private: System::Windows::Forms::LinkLabel *  SDownLoad27;
private: System::Windows::Forms::GroupBox *  groupBox80;
private: System::Windows::Forms::Label *  label14;
private: System::Windows::Forms::LinkLabel *  SDownLoad26;
private: System::Windows::Forms::GroupBox *  groupBox81;
private: System::Windows::Forms::Label *  label15;
private: System::Windows::Forms::LinkLabel *  SDownLoad25;
private: System::Windows::Forms::GroupBox *  groupBox82;
private: System::Windows::Forms::Label *  label16;
private: System::Windows::Forms::LinkLabel *  SDownLoad24;
private: System::Windows::Forms::GroupBox *  groupBox83;
private: System::Windows::Forms::Label *  label17;
private: System::Windows::Forms::LinkLabel *  SDownLoad23;
private: System::Windows::Forms::GroupBox *  groupBox84;
private: System::Windows::Forms::Label *  label19;
private: System::Windows::Forms::LinkLabel *  SDownLoad22;
private: System::Windows::Forms::GroupBox *  groupBox85;
private: System::Windows::Forms::Label *  label20;
private: System::Windows::Forms::LinkLabel *  SDownLoad21;
private: System::Windows::Forms::GroupBox *  groupBox86;
private: System::Windows::Forms::Label *  ONSTime29;
private: System::Windows::Forms::Label *  ONSTime28;
private: System::Windows::Forms::Label *  ONSTime27;
private: System::Windows::Forms::Label *  ONSTime26;
private: System::Windows::Forms::Label *  ONSTime25;
private: System::Windows::Forms::Label *  ONSTime24;
private: System::Windows::Forms::Label *  ONSTime23;
private: System::Windows::Forms::Label *  ONSTime22;
private: System::Windows::Forms::Label *  ONSTime21;
private: System::Windows::Forms::Label *  SName30;
private: System::Windows::Forms::GroupBox *  groupBox87;
private: System::Windows::Forms::Label *  label32;
private: System::Windows::Forms::LinkLabel *  SDownLoad30;
private: System::Windows::Forms::Label *  ONSTime30;
private: System::Windows::Forms::Label *  Char12;
private: System::Windows::Forms::Label *  Char11;
private: System::Windows::Forms::Label *  Char10;
private: System::Windows::Forms::Label *  Char9;
private: System::Windows::Forms::Label *  Char8;
private: System::Windows::Forms::Label *  Char7;
private: System::Windows::Forms::Label *  Char6;
private: System::Windows::Forms::Label *  Char5;
private: System::Windows::Forms::Label *  Char4;
private: System::Windows::Forms::Label *  Char3;
private: System::Windows::Forms::Label *  Char2;
private: System::Windows::Forms::Label *  Char1;


	private:
		/// <summary>
		/// 必要なデザイナ変数です。
		/// </summary>
		System::ComponentModel::Container * components;

		/// <summary>
		/// デザイナ サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディタで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			System::Resources::ResourceManager *  resources = new System::Resources::ResourceManager(__typeof(My::Form1));
			this->tabControl1 = new System::Windows::Forms::TabControl();
			this->OFFPage = new System::Windows::Forms::TabPage();
			this->groupBox77 = new System::Windows::Forms::GroupBox();
			this->SDelete30 = new System::Windows::Forms::LinkLabel();
			this->SDelete29 = new System::Windows::Forms::LinkLabel();
			this->groupBox75 = new System::Windows::Forms::GroupBox();
			this->OFFSTime30 = new System::Windows::Forms::Label();
			this->OFFStage30 = new System::Windows::Forms::Label();
			this->SUpLoad30 = new System::Windows::Forms::LinkLabel();
			this->OFFSTime29 = new System::Windows::Forms::Label();
			this->OFFStage29 = new System::Windows::Forms::Label();
			this->SUpLoad29 = new System::Windows::Forms::LinkLabel();
			this->groupBox76 = new System::Windows::Forms::GroupBox();
			this->SDelete28 = new System::Windows::Forms::LinkLabel();
			this->SDelete27 = new System::Windows::Forms::LinkLabel();
			this->SDelete26 = new System::Windows::Forms::LinkLabel();
			this->SDelete25 = new System::Windows::Forms::LinkLabel();
			this->SDelete24 = new System::Windows::Forms::LinkLabel();
			this->SDelete23 = new System::Windows::Forms::LinkLabel();
			this->SDelete22 = new System::Windows::Forms::LinkLabel();
			this->SDelete21 = new System::Windows::Forms::LinkLabel();
			this->groupBox67 = new System::Windows::Forms::GroupBox();
			this->OFFSTime28 = new System::Windows::Forms::Label();
			this->OFFStage28 = new System::Windows::Forms::Label();
			this->SUpLoad28 = new System::Windows::Forms::LinkLabel();
			this->OFFSTime27 = new System::Windows::Forms::Label();
			this->OFFStage27 = new System::Windows::Forms::Label();
			this->SUpLoad27 = new System::Windows::Forms::LinkLabel();
			this->groupBox68 = new System::Windows::Forms::GroupBox();
			this->OFFSTime26 = new System::Windows::Forms::Label();
			this->OFFStage26 = new System::Windows::Forms::Label();
			this->SUpLoad26 = new System::Windows::Forms::LinkLabel();
			this->groupBox69 = new System::Windows::Forms::GroupBox();
			this->OFFSTime25 = new System::Windows::Forms::Label();
			this->OFFStage25 = new System::Windows::Forms::Label();
			this->SUpLoad25 = new System::Windows::Forms::LinkLabel();
			this->groupBox70 = new System::Windows::Forms::GroupBox();
			this->OFFSTime24 = new System::Windows::Forms::Label();
			this->OFFStage24 = new System::Windows::Forms::Label();
			this->SUpLoad24 = new System::Windows::Forms::LinkLabel();
			this->groupBox71 = new System::Windows::Forms::GroupBox();
			this->OFFSTime23 = new System::Windows::Forms::Label();
			this->OFFStage23 = new System::Windows::Forms::Label();
			this->SUpLoad23 = new System::Windows::Forms::LinkLabel();
			this->groupBox72 = new System::Windows::Forms::GroupBox();
			this->OFFSTime22 = new System::Windows::Forms::Label();
			this->OFFStage22 = new System::Windows::Forms::Label();
			this->SUpLoad22 = new System::Windows::Forms::LinkLabel();
			this->groupBox73 = new System::Windows::Forms::GroupBox();
			this->OFFSTime21 = new System::Windows::Forms::Label();
			this->OFFStage21 = new System::Windows::Forms::Label();
			this->SUpLoad21 = new System::Windows::Forms::LinkLabel();
			this->groupBox74 = new System::Windows::Forms::GroupBox();
			this->CDelete12 = new System::Windows::Forms::LinkLabel();
			this->CDelete11 = new System::Windows::Forms::LinkLabel();
			this->CDelete10 = new System::Windows::Forms::LinkLabel();
			this->CDelete9 = new System::Windows::Forms::LinkLabel();
			this->CDelete8 = new System::Windows::Forms::LinkLabel();
			this->CDelete7 = new System::Windows::Forms::LinkLabel();
			this->CDelete6 = new System::Windows::Forms::LinkLabel();
			this->CDelete5 = new System::Windows::Forms::LinkLabel();
			this->CDelete4 = new System::Windows::Forms::LinkLabel();
			this->CDelete3 = new System::Windows::Forms::LinkLabel();
			this->CDelete2 = new System::Windows::Forms::LinkLabel();
			this->CDelete1 = new System::Windows::Forms::LinkLabel();
			this->SDelete20 = new System::Windows::Forms::LinkLabel();
			this->SDelete19 = new System::Windows::Forms::LinkLabel();
			this->SDelete18 = new System::Windows::Forms::LinkLabel();
			this->SDelete17 = new System::Windows::Forms::LinkLabel();
			this->SDelete16 = new System::Windows::Forms::LinkLabel();
			this->SDelete15 = new System::Windows::Forms::LinkLabel();
			this->SDelete14 = new System::Windows::Forms::LinkLabel();
			this->SDelete13 = new System::Windows::Forms::LinkLabel();
			this->SDelete12 = new System::Windows::Forms::LinkLabel();
			this->SDelete11 = new System::Windows::Forms::LinkLabel();
			this->SDelete10 = new System::Windows::Forms::LinkLabel();
			this->SDelete9 = new System::Windows::Forms::LinkLabel();
			this->SDelete8 = new System::Windows::Forms::LinkLabel();
			this->SDelete7 = new System::Windows::Forms::LinkLabel();
			this->SDelete6 = new System::Windows::Forms::LinkLabel();
			this->SDelete5 = new System::Windows::Forms::LinkLabel();
			this->SDelete4 = new System::Windows::Forms::LinkLabel();
			this->SDelete3 = new System::Windows::Forms::LinkLabel();
			this->SDelete2 = new System::Windows::Forms::LinkLabel();
			this->SDelete1 = new System::Windows::Forms::LinkLabel();
			this->groupBox33 = new System::Windows::Forms::GroupBox();
			this->OFFCTime12 = new System::Windows::Forms::Label();
			this->OFFChar12 = new System::Windows::Forms::Label();
			this->label57 = new System::Windows::Forms::Label();
			this->CUpLoad12 = new System::Windows::Forms::LinkLabel();
			this->groupBox29 = new System::Windows::Forms::GroupBox();
			this->OFFCTime11 = new System::Windows::Forms::Label();
			this->OFFChar11 = new System::Windows::Forms::Label();
			this->label60 = new System::Windows::Forms::Label();
			this->CUpLoad11 = new System::Windows::Forms::LinkLabel();
			this->groupBox30 = new System::Windows::Forms::GroupBox();
			this->OFFCTime10 = new System::Windows::Forms::Label();
			this->OFFChar10 = new System::Windows::Forms::Label();
			this->label63 = new System::Windows::Forms::Label();
			this->CUpLoad10 = new System::Windows::Forms::LinkLabel();
			this->groupBox31 = new System::Windows::Forms::GroupBox();
			this->OFFCTime9 = new System::Windows::Forms::Label();
			this->OFFChar9 = new System::Windows::Forms::Label();
			this->label66 = new System::Windows::Forms::Label();
			this->CUpLoad9 = new System::Windows::Forms::LinkLabel();
			this->groupBox32 = new System::Windows::Forms::GroupBox();
			this->OFFCTime8 = new System::Windows::Forms::Label();
			this->OFFChar8 = new System::Windows::Forms::Label();
			this->label36 = new System::Windows::Forms::Label();
			this->CUpLoad8 = new System::Windows::Forms::LinkLabel();
			this->groupBox25 = new System::Windows::Forms::GroupBox();
			this->OFFCTime7 = new System::Windows::Forms::Label();
			this->OFFChar7 = new System::Windows::Forms::Label();
			this->label45 = new System::Windows::Forms::Label();
			this->CUpLoad7 = new System::Windows::Forms::LinkLabel();
			this->groupBox26 = new System::Windows::Forms::GroupBox();
			this->OFFChar6 = new System::Windows::Forms::Label();
			this->label51 = new System::Windows::Forms::Label();
			this->CUpLoad6 = new System::Windows::Forms::LinkLabel();
			this->groupBox27 = new System::Windows::Forms::GroupBox();
			this->OFFChar5 = new System::Windows::Forms::Label();
			this->label54 = new System::Windows::Forms::Label();
			this->CUpLoad5 = new System::Windows::Forms::LinkLabel();
			this->groupBox28 = new System::Windows::Forms::GroupBox();
			this->OFFChar4 = new System::Windows::Forms::Label();
			this->label18 = new System::Windows::Forms::Label();
			this->CUpLoad4 = new System::Windows::Forms::LinkLabel();
			this->groupBox23 = new System::Windows::Forms::GroupBox();
			this->OFFChar3 = new System::Windows::Forms::Label();
			this->label27 = new System::Windows::Forms::Label();
			this->CUpLoad3 = new System::Windows::Forms::LinkLabel();
			this->groupBox24 = new System::Windows::Forms::GroupBox();
			this->OFFChar2 = new System::Windows::Forms::Label();
			this->OFFCorce2 = new System::Windows::Forms::Label();
			this->CUpLoad2 = new System::Windows::Forms::LinkLabel();
			this->groupBox22 = new System::Windows::Forms::GroupBox();
			this->OFFChar1 = new System::Windows::Forms::Label();
			this->OFFCorce1 = new System::Windows::Forms::Label();
			this->CUpLoad1 = new System::Windows::Forms::LinkLabel();
			this->groupBox21 = new System::Windows::Forms::GroupBox();
			this->groupBox20 = new System::Windows::Forms::GroupBox();
			this->OFFSTime20 = new System::Windows::Forms::Label();
			this->OFFStage20 = new System::Windows::Forms::Label();
			this->SUpLoad20 = new System::Windows::Forms::LinkLabel();
			this->OFFSTime19 = new System::Windows::Forms::Label();
			this->OFFStage19 = new System::Windows::Forms::Label();
			this->SUpLoad19 = new System::Windows::Forms::LinkLabel();
			this->groupBox11 = new System::Windows::Forms::GroupBox();
			this->OFFSTime18 = new System::Windows::Forms::Label();
			this->OFFStage18 = new System::Windows::Forms::Label();
			this->SUpLoad18 = new System::Windows::Forms::LinkLabel();
			this->groupBox12 = new System::Windows::Forms::GroupBox();
			this->OFFSTime17 = new System::Windows::Forms::Label();
			this->OFFStage17 = new System::Windows::Forms::Label();
			this->SUpLoad17 = new System::Windows::Forms::LinkLabel();
			this->groupBox13 = new System::Windows::Forms::GroupBox();
			this->OFFSTime16 = new System::Windows::Forms::Label();
			this->OFFStage16 = new System::Windows::Forms::Label();
			this->SUpLoad16 = new System::Windows::Forms::LinkLabel();
			this->groupBox14 = new System::Windows::Forms::GroupBox();
			this->OFFSTime15 = new System::Windows::Forms::Label();
			this->OFFStage15 = new System::Windows::Forms::Label();
			this->SUpLoad15 = new System::Windows::Forms::LinkLabel();
			this->groupBox15 = new System::Windows::Forms::GroupBox();
			this->OFFSTime14 = new System::Windows::Forms::Label();
			this->OFFStage14 = new System::Windows::Forms::Label();
			this->SUpLoad14 = new System::Windows::Forms::LinkLabel();
			this->groupBox16 = new System::Windows::Forms::GroupBox();
			this->OFFSTime13 = new System::Windows::Forms::Label();
			this->OFFStage13 = new System::Windows::Forms::Label();
			this->SUpLoad13 = new System::Windows::Forms::LinkLabel();
			this->groupBox17 = new System::Windows::Forms::GroupBox();
			this->OFFSTime12 = new System::Windows::Forms::Label();
			this->OFFStage12 = new System::Windows::Forms::Label();
			this->SUpLoad12 = new System::Windows::Forms::LinkLabel();
			this->groupBox18 = new System::Windows::Forms::GroupBox();
			this->OFFSTime11 = new System::Windows::Forms::Label();
			this->OFFStage11 = new System::Windows::Forms::Label();
			this->SUpLoad11 = new System::Windows::Forms::LinkLabel();
			this->groupBox19 = new System::Windows::Forms::GroupBox();
			this->OFFSTime10 = new System::Windows::Forms::Label();
			this->OFFStage10 = new System::Windows::Forms::Label();
			this->SUpLoad10 = new System::Windows::Forms::LinkLabel();
			this->groupBox10 = new System::Windows::Forms::GroupBox();
			this->OFFSTime9 = new System::Windows::Forms::Label();
			this->OFFStage9 = new System::Windows::Forms::Label();
			this->SUpLoad9 = new System::Windows::Forms::LinkLabel();
			this->groupBox9 = new System::Windows::Forms::GroupBox();
			this->OFFSTime8 = new System::Windows::Forms::Label();
			this->OFFStage8 = new System::Windows::Forms::Label();
			this->SUpLoad8 = new System::Windows::Forms::LinkLabel();
			this->groupBox8 = new System::Windows::Forms::GroupBox();
			this->OFFSTime7 = new System::Windows::Forms::Label();
			this->OFFStage7 = new System::Windows::Forms::Label();
			this->SUpLoad7 = new System::Windows::Forms::LinkLabel();
			this->groupBox7 = new System::Windows::Forms::GroupBox();
			this->OFFSTime6 = new System::Windows::Forms::Label();
			this->OFFStage6 = new System::Windows::Forms::Label();
			this->SUpLoad6 = new System::Windows::Forms::LinkLabel();
			this->groupBox6 = new System::Windows::Forms::GroupBox();
			this->OFFSTime5 = new System::Windows::Forms::Label();
			this->OFFStage5 = new System::Windows::Forms::Label();
			this->SUpLoad5 = new System::Windows::Forms::LinkLabel();
			this->groupBox5 = new System::Windows::Forms::GroupBox();
			this->OFFSTime4 = new System::Windows::Forms::Label();
			this->OFFStage4 = new System::Windows::Forms::Label();
			this->SUpLoad4 = new System::Windows::Forms::LinkLabel();
			this->groupBox4 = new System::Windows::Forms::GroupBox();
			this->OFFSTime3 = new System::Windows::Forms::Label();
			this->OFFStage3 = new System::Windows::Forms::Label();
			this->SUpLoad3 = new System::Windows::Forms::LinkLabel();
			this->groupBox3 = new System::Windows::Forms::GroupBox();
			this->OFFSTime2 = new System::Windows::Forms::Label();
			this->OFFStage2 = new System::Windows::Forms::Label();
			this->SUpLoad2 = new System::Windows::Forms::LinkLabel();
			this->groupBox2 = new System::Windows::Forms::GroupBox();
			this->OFFSTime1 = new System::Windows::Forms::Label();
			this->OFFStage1 = new System::Windows::Forms::Label();
			this->SUpLoad1 = new System::Windows::Forms::LinkLabel();
			this->groupBox1 = new System::Windows::Forms::GroupBox();
			this->OFFCTime6 = new System::Windows::Forms::Label();
			this->OFFCTime5 = new System::Windows::Forms::Label();
			this->OFFCTime4 = new System::Windows::Forms::Label();
			this->OFFCTime3 = new System::Windows::Forms::Label();
			this->OFFCTime2 = new System::Windows::Forms::Label();
			this->OFFCTime1 = new System::Windows::Forms::Label();
			this->ONPage = new System::Windows::Forms::TabPage();
			this->SName30 = new System::Windows::Forms::Label();
			this->groupBox87 = new System::Windows::Forms::GroupBox();
			this->label32 = new System::Windows::Forms::Label();
			this->SDownLoad30 = new System::Windows::Forms::LinkLabel();
			this->ONSTime30 = new System::Windows::Forms::Label();
			this->SName23 = new System::Windows::Forms::Label();
			this->SName22 = new System::Windows::Forms::Label();
			this->SName21 = new System::Windows::Forms::Label();
			this->SName29 = new System::Windows::Forms::Label();
			this->SName28 = new System::Windows::Forms::Label();
			this->SName27 = new System::Windows::Forms::Label();
			this->SName26 = new System::Windows::Forms::Label();
			this->SName25 = new System::Windows::Forms::Label();
			this->SName24 = new System::Windows::Forms::Label();
			this->groupBox78 = new System::Windows::Forms::GroupBox();
			this->label11 = new System::Windows::Forms::Label();
			this->SDownLoad29 = new System::Windows::Forms::LinkLabel();
			this->label12 = new System::Windows::Forms::Label();
			this->SDownLoad28 = new System::Windows::Forms::LinkLabel();
			this->groupBox79 = new System::Windows::Forms::GroupBox();
			this->label13 = new System::Windows::Forms::Label();
			this->SDownLoad27 = new System::Windows::Forms::LinkLabel();
			this->groupBox80 = new System::Windows::Forms::GroupBox();
			this->label14 = new System::Windows::Forms::Label();
			this->SDownLoad26 = new System::Windows::Forms::LinkLabel();
			this->groupBox81 = new System::Windows::Forms::GroupBox();
			this->label15 = new System::Windows::Forms::Label();
			this->SDownLoad25 = new System::Windows::Forms::LinkLabel();
			this->groupBox82 = new System::Windows::Forms::GroupBox();
			this->label16 = new System::Windows::Forms::Label();
			this->SDownLoad24 = new System::Windows::Forms::LinkLabel();
			this->groupBox83 = new System::Windows::Forms::GroupBox();
			this->label17 = new System::Windows::Forms::Label();
			this->SDownLoad23 = new System::Windows::Forms::LinkLabel();
			this->groupBox84 = new System::Windows::Forms::GroupBox();
			this->label19 = new System::Windows::Forms::Label();
			this->SDownLoad22 = new System::Windows::Forms::LinkLabel();
			this->groupBox85 = new System::Windows::Forms::GroupBox();
			this->label20 = new System::Windows::Forms::Label();
			this->SDownLoad21 = new System::Windows::Forms::LinkLabel();
			this->groupBox86 = new System::Windows::Forms::GroupBox();
			this->ONSTime29 = new System::Windows::Forms::Label();
			this->ONSTime28 = new System::Windows::Forms::Label();
			this->ONSTime27 = new System::Windows::Forms::Label();
			this->ONSTime26 = new System::Windows::Forms::Label();
			this->ONSTime25 = new System::Windows::Forms::Label();
			this->ONSTime24 = new System::Windows::Forms::Label();
			this->ONSTime23 = new System::Windows::Forms::Label();
			this->ONSTime22 = new System::Windows::Forms::Label();
			this->ONSTime21 = new System::Windows::Forms::Label();
			this->SName6 = new System::Windows::Forms::Label();
			this->SName5 = new System::Windows::Forms::Label();
			this->SName4 = new System::Windows::Forms::Label();
			this->SName3 = new System::Windows::Forms::Label();
			this->SName2 = new System::Windows::Forms::Label();
			this->SName1 = new System::Windows::Forms::Label();
			this->SName8 = new System::Windows::Forms::Label();
			this->SName7 = new System::Windows::Forms::Label();
			this->SName14 = new System::Windows::Forms::Label();
			this->SName13 = new System::Windows::Forms::Label();
			this->SName12 = new System::Windows::Forms::Label();
			this->SName11 = new System::Windows::Forms::Label();
			this->SName10 = new System::Windows::Forms::Label();
			this->SName9 = new System::Windows::Forms::Label();
			this->SName20 = new System::Windows::Forms::Label();
			this->SName19 = new System::Windows::Forms::Label();
			this->SName18 = new System::Windows::Forms::Label();
			this->SName17 = new System::Windows::Forms::Label();
			this->SName16 = new System::Windows::Forms::Label();
			this->SName15 = new System::Windows::Forms::Label();
			this->CName12 = new System::Windows::Forms::Label();
			this->CName11 = new System::Windows::Forms::Label();
			this->CName10 = new System::Windows::Forms::Label();
			this->CName9 = new System::Windows::Forms::Label();
			this->CName8 = new System::Windows::Forms::Label();
			this->CName7 = new System::Windows::Forms::Label();
			this->CName6 = new System::Windows::Forms::Label();
			this->CName5 = new System::Windows::Forms::Label();
			this->CName4 = new System::Windows::Forms::Label();
			this->CName3 = new System::Windows::Forms::Label();
			this->CName2 = new System::Windows::Forms::Label();
			this->groupBox34 = new System::Windows::Forms::GroupBox();
			this->Char12 = new System::Windows::Forms::Label();
			this->label69 = new System::Windows::Forms::Label();
			this->CDownLoad12 = new System::Windows::Forms::LinkLabel();
			this->groupBox35 = new System::Windows::Forms::GroupBox();
			this->Char11 = new System::Windows::Forms::Label();
			this->label72 = new System::Windows::Forms::Label();
			this->CDownLoad11 = new System::Windows::Forms::LinkLabel();
			this->groupBox36 = new System::Windows::Forms::GroupBox();
			this->Char10 = new System::Windows::Forms::Label();
			this->label75 = new System::Windows::Forms::Label();
			this->CDownLoad10 = new System::Windows::Forms::LinkLabel();
			this->groupBox37 = new System::Windows::Forms::GroupBox();
			this->Char9 = new System::Windows::Forms::Label();
			this->label78 = new System::Windows::Forms::Label();
			this->CDownLoad9 = new System::Windows::Forms::LinkLabel();
			this->groupBox38 = new System::Windows::Forms::GroupBox();
			this->Char8 = new System::Windows::Forms::Label();
			this->label81 = new System::Windows::Forms::Label();
			this->CDownLoad8 = new System::Windows::Forms::LinkLabel();
			this->groupBox39 = new System::Windows::Forms::GroupBox();
			this->Char7 = new System::Windows::Forms::Label();
			this->label84 = new System::Windows::Forms::Label();
			this->CDownLoad7 = new System::Windows::Forms::LinkLabel();
			this->groupBox40 = new System::Windows::Forms::GroupBox();
			this->Char6 = new System::Windows::Forms::Label();
			this->label87 = new System::Windows::Forms::Label();
			this->CDownLoad6 = new System::Windows::Forms::LinkLabel();
			this->groupBox41 = new System::Windows::Forms::GroupBox();
			this->Char5 = new System::Windows::Forms::Label();
			this->label90 = new System::Windows::Forms::Label();
			this->CDownLoad5 = new System::Windows::Forms::LinkLabel();
			this->groupBox42 = new System::Windows::Forms::GroupBox();
			this->Char4 = new System::Windows::Forms::Label();
			this->label93 = new System::Windows::Forms::Label();
			this->CDownLoad4 = new System::Windows::Forms::LinkLabel();
			this->groupBox43 = new System::Windows::Forms::GroupBox();
			this->Char3 = new System::Windows::Forms::Label();
			this->label96 = new System::Windows::Forms::Label();
			this->CDownLoad3 = new System::Windows::Forms::LinkLabel();
			this->groupBox44 = new System::Windows::Forms::GroupBox();
			this->Char2 = new System::Windows::Forms::Label();
			this->label99 = new System::Windows::Forms::Label();
			this->CDownLoad2 = new System::Windows::Forms::LinkLabel();
			this->groupBox45 = new System::Windows::Forms::GroupBox();
			this->Char1 = new System::Windows::Forms::Label();
			this->label102 = new System::Windows::Forms::Label();
			this->CDownLoad1 = new System::Windows::Forms::LinkLabel();
			this->groupBox46 = new System::Windows::Forms::GroupBox();
			this->groupBox47 = new System::Windows::Forms::GroupBox();
			this->label104 = new System::Windows::Forms::Label();
			this->SDownLoad20 = new System::Windows::Forms::LinkLabel();
			this->label106 = new System::Windows::Forms::Label();
			this->SDownLoad19 = new System::Windows::Forms::LinkLabel();
			this->groupBox48 = new System::Windows::Forms::GroupBox();
			this->label108 = new System::Windows::Forms::Label();
			this->SDownLoad18 = new System::Windows::Forms::LinkLabel();
			this->groupBox49 = new System::Windows::Forms::GroupBox();
			this->label110 = new System::Windows::Forms::Label();
			this->SDownLoad17 = new System::Windows::Forms::LinkLabel();
			this->groupBox50 = new System::Windows::Forms::GroupBox();
			this->label112 = new System::Windows::Forms::Label();
			this->SDownLoad16 = new System::Windows::Forms::LinkLabel();
			this->groupBox51 = new System::Windows::Forms::GroupBox();
			this->label114 = new System::Windows::Forms::Label();
			this->SDownLoad15 = new System::Windows::Forms::LinkLabel();
			this->groupBox52 = new System::Windows::Forms::GroupBox();
			this->label116 = new System::Windows::Forms::Label();
			this->SDownLoad14 = new System::Windows::Forms::LinkLabel();
			this->groupBox53 = new System::Windows::Forms::GroupBox();
			this->label118 = new System::Windows::Forms::Label();
			this->SDownLoad13 = new System::Windows::Forms::LinkLabel();
			this->groupBox54 = new System::Windows::Forms::GroupBox();
			this->label120 = new System::Windows::Forms::Label();
			this->SDownLoad12 = new System::Windows::Forms::LinkLabel();
			this->groupBox55 = new System::Windows::Forms::GroupBox();
			this->label122 = new System::Windows::Forms::Label();
			this->SDownLoad11 = new System::Windows::Forms::LinkLabel();
			this->groupBox56 = new System::Windows::Forms::GroupBox();
			this->label124 = new System::Windows::Forms::Label();
			this->SDownLoad10 = new System::Windows::Forms::LinkLabel();
			this->groupBox57 = new System::Windows::Forms::GroupBox();
			this->label126 = new System::Windows::Forms::Label();
			this->SDownLoad9 = new System::Windows::Forms::LinkLabel();
			this->groupBox58 = new System::Windows::Forms::GroupBox();
			this->label128 = new System::Windows::Forms::Label();
			this->SDownLoad8 = new System::Windows::Forms::LinkLabel();
			this->groupBox59 = new System::Windows::Forms::GroupBox();
			this->label130 = new System::Windows::Forms::Label();
			this->SDownLoad7 = new System::Windows::Forms::LinkLabel();
			this->groupBox60 = new System::Windows::Forms::GroupBox();
			this->label132 = new System::Windows::Forms::Label();
			this->SDownLoad6 = new System::Windows::Forms::LinkLabel();
			this->groupBox61 = new System::Windows::Forms::GroupBox();
			this->label134 = new System::Windows::Forms::Label();
			this->SDownLoad5 = new System::Windows::Forms::LinkLabel();
			this->groupBox62 = new System::Windows::Forms::GroupBox();
			this->label136 = new System::Windows::Forms::Label();
			this->SDownLoad4 = new System::Windows::Forms::LinkLabel();
			this->groupBox63 = new System::Windows::Forms::GroupBox();
			this->label138 = new System::Windows::Forms::Label();
			this->SDownLoad3 = new System::Windows::Forms::LinkLabel();
			this->groupBox64 = new System::Windows::Forms::GroupBox();
			this->label140 = new System::Windows::Forms::Label();
			this->SDownLoad2 = new System::Windows::Forms::LinkLabel();
			this->groupBox65 = new System::Windows::Forms::GroupBox();
			this->label142 = new System::Windows::Forms::Label();
			this->SDownLoad1 = new System::Windows::Forms::LinkLabel();
			this->groupBox66 = new System::Windows::Forms::GroupBox();
			this->ONCTime12 = new System::Windows::Forms::Label();
			this->ONCTime11 = new System::Windows::Forms::Label();
			this->ONCTime10 = new System::Windows::Forms::Label();
			this->ONCTime9 = new System::Windows::Forms::Label();
			this->ONCTime8 = new System::Windows::Forms::Label();
			this->ONCTime7 = new System::Windows::Forms::Label();
			this->ONCTime6 = new System::Windows::Forms::Label();
			this->ONCTime5 = new System::Windows::Forms::Label();
			this->ONCTime4 = new System::Windows::Forms::Label();
			this->ONCTime3 = new System::Windows::Forms::Label();
			this->ONCTime2 = new System::Windows::Forms::Label();
			this->ONCTime1 = new System::Windows::Forms::Label();
			this->ONSTime20 = new System::Windows::Forms::Label();
			this->ONSTime19 = new System::Windows::Forms::Label();
			this->ONSTime18 = new System::Windows::Forms::Label();
			this->ONSTime17 = new System::Windows::Forms::Label();
			this->ONSTime16 = new System::Windows::Forms::Label();
			this->ONSTime15 = new System::Windows::Forms::Label();
			this->ONSTime14 = new System::Windows::Forms::Label();
			this->ONSTime13 = new System::Windows::Forms::Label();
			this->ONSTime12 = new System::Windows::Forms::Label();
			this->ONSTime11 = new System::Windows::Forms::Label();
			this->ONSTime10 = new System::Windows::Forms::Label();
			this->ONSTime9 = new System::Windows::Forms::Label();
			this->ONSTime8 = new System::Windows::Forms::Label();
			this->ONSTime7 = new System::Windows::Forms::Label();
			this->ONSTime6 = new System::Windows::Forms::Label();
			this->ONSTime5 = new System::Windows::Forms::Label();
			this->ONSTime4 = new System::Windows::Forms::Label();
			this->ONSTime3 = new System::Windows::Forms::Label();
			this->ONSTime2 = new System::Windows::Forms::Label();
			this->ONSTime1 = new System::Windows::Forms::Label();
			this->CName1 = new System::Windows::Forms::Label();
			this->KousinButton = new System::Windows::Forms::Button();
			this->UserNameText = new System::Windows::Forms::TextBox();
			this->label1 = new System::Windows::Forms::Label();
			this->tabControl1->SuspendLayout();
			this->OFFPage->SuspendLayout();
			this->ONPage->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->OFFPage);
			this->tabControl1->Controls->Add(this->ONPage);
			this->tabControl1->Location = System::Drawing::Point(8, 16);
			this->tabControl1->Name = S"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(520, 392);
			this->tabControl1->TabIndex = 0;
			// 
			// OFFPage
			// 
			this->OFFPage->AutoScroll = true;
			this->OFFPage->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->OFFPage->Controls->Add(this->groupBox77);
			this->OFFPage->Controls->Add(this->SDelete30);
			this->OFFPage->Controls->Add(this->SDelete29);
			this->OFFPage->Controls->Add(this->groupBox75);
			this->OFFPage->Controls->Add(this->OFFSTime30);
			this->OFFPage->Controls->Add(this->OFFStage30);
			this->OFFPage->Controls->Add(this->SUpLoad30);
			this->OFFPage->Controls->Add(this->OFFSTime29);
			this->OFFPage->Controls->Add(this->OFFStage29);
			this->OFFPage->Controls->Add(this->SUpLoad29);
			this->OFFPage->Controls->Add(this->groupBox76);
			this->OFFPage->Controls->Add(this->SDelete28);
			this->OFFPage->Controls->Add(this->SDelete27);
			this->OFFPage->Controls->Add(this->SDelete26);
			this->OFFPage->Controls->Add(this->SDelete25);
			this->OFFPage->Controls->Add(this->SDelete24);
			this->OFFPage->Controls->Add(this->SDelete23);
			this->OFFPage->Controls->Add(this->SDelete22);
			this->OFFPage->Controls->Add(this->SDelete21);
			this->OFFPage->Controls->Add(this->groupBox67);
			this->OFFPage->Controls->Add(this->OFFSTime28);
			this->OFFPage->Controls->Add(this->OFFStage28);
			this->OFFPage->Controls->Add(this->SUpLoad28);
			this->OFFPage->Controls->Add(this->OFFSTime27);
			this->OFFPage->Controls->Add(this->OFFStage27);
			this->OFFPage->Controls->Add(this->SUpLoad27);
			this->OFFPage->Controls->Add(this->groupBox68);
			this->OFFPage->Controls->Add(this->OFFSTime26);
			this->OFFPage->Controls->Add(this->OFFStage26);
			this->OFFPage->Controls->Add(this->SUpLoad26);
			this->OFFPage->Controls->Add(this->groupBox69);
			this->OFFPage->Controls->Add(this->OFFSTime25);
			this->OFFPage->Controls->Add(this->OFFStage25);
			this->OFFPage->Controls->Add(this->SUpLoad25);
			this->OFFPage->Controls->Add(this->groupBox70);
			this->OFFPage->Controls->Add(this->OFFSTime24);
			this->OFFPage->Controls->Add(this->OFFStage24);
			this->OFFPage->Controls->Add(this->SUpLoad24);
			this->OFFPage->Controls->Add(this->groupBox71);
			this->OFFPage->Controls->Add(this->OFFSTime23);
			this->OFFPage->Controls->Add(this->OFFStage23);
			this->OFFPage->Controls->Add(this->SUpLoad23);
			this->OFFPage->Controls->Add(this->groupBox72);
			this->OFFPage->Controls->Add(this->OFFSTime22);
			this->OFFPage->Controls->Add(this->OFFStage22);
			this->OFFPage->Controls->Add(this->SUpLoad22);
			this->OFFPage->Controls->Add(this->groupBox73);
			this->OFFPage->Controls->Add(this->OFFSTime21);
			this->OFFPage->Controls->Add(this->OFFStage21);
			this->OFFPage->Controls->Add(this->SUpLoad21);
			this->OFFPage->Controls->Add(this->groupBox74);
			this->OFFPage->Controls->Add(this->CDelete12);
			this->OFFPage->Controls->Add(this->CDelete11);
			this->OFFPage->Controls->Add(this->CDelete10);
			this->OFFPage->Controls->Add(this->CDelete9);
			this->OFFPage->Controls->Add(this->CDelete8);
			this->OFFPage->Controls->Add(this->CDelete7);
			this->OFFPage->Controls->Add(this->CDelete6);
			this->OFFPage->Controls->Add(this->CDelete5);
			this->OFFPage->Controls->Add(this->CDelete4);
			this->OFFPage->Controls->Add(this->CDelete3);
			this->OFFPage->Controls->Add(this->CDelete2);
			this->OFFPage->Controls->Add(this->CDelete1);
			this->OFFPage->Controls->Add(this->SDelete20);
			this->OFFPage->Controls->Add(this->SDelete19);
			this->OFFPage->Controls->Add(this->SDelete18);
			this->OFFPage->Controls->Add(this->SDelete17);
			this->OFFPage->Controls->Add(this->SDelete16);
			this->OFFPage->Controls->Add(this->SDelete15);
			this->OFFPage->Controls->Add(this->SDelete14);
			this->OFFPage->Controls->Add(this->SDelete13);
			this->OFFPage->Controls->Add(this->SDelete12);
			this->OFFPage->Controls->Add(this->SDelete11);
			this->OFFPage->Controls->Add(this->SDelete10);
			this->OFFPage->Controls->Add(this->SDelete9);
			this->OFFPage->Controls->Add(this->SDelete8);
			this->OFFPage->Controls->Add(this->SDelete7);
			this->OFFPage->Controls->Add(this->SDelete6);
			this->OFFPage->Controls->Add(this->SDelete5);
			this->OFFPage->Controls->Add(this->SDelete4);
			this->OFFPage->Controls->Add(this->SDelete3);
			this->OFFPage->Controls->Add(this->SDelete2);
			this->OFFPage->Controls->Add(this->SDelete1);
			this->OFFPage->Controls->Add(this->groupBox33);
			this->OFFPage->Controls->Add(this->OFFCTime12);
			this->OFFPage->Controls->Add(this->OFFChar12);
			this->OFFPage->Controls->Add(this->label57);
			this->OFFPage->Controls->Add(this->CUpLoad12);
			this->OFFPage->Controls->Add(this->groupBox29);
			this->OFFPage->Controls->Add(this->OFFCTime11);
			this->OFFPage->Controls->Add(this->OFFChar11);
			this->OFFPage->Controls->Add(this->label60);
			this->OFFPage->Controls->Add(this->CUpLoad11);
			this->OFFPage->Controls->Add(this->groupBox30);
			this->OFFPage->Controls->Add(this->OFFCTime10);
			this->OFFPage->Controls->Add(this->OFFChar10);
			this->OFFPage->Controls->Add(this->label63);
			this->OFFPage->Controls->Add(this->CUpLoad10);
			this->OFFPage->Controls->Add(this->groupBox31);
			this->OFFPage->Controls->Add(this->OFFCTime9);
			this->OFFPage->Controls->Add(this->OFFChar9);
			this->OFFPage->Controls->Add(this->label66);
			this->OFFPage->Controls->Add(this->CUpLoad9);
			this->OFFPage->Controls->Add(this->groupBox32);
			this->OFFPage->Controls->Add(this->OFFCTime8);
			this->OFFPage->Controls->Add(this->OFFChar8);
			this->OFFPage->Controls->Add(this->label36);
			this->OFFPage->Controls->Add(this->CUpLoad8);
			this->OFFPage->Controls->Add(this->groupBox25);
			this->OFFPage->Controls->Add(this->OFFCTime7);
			this->OFFPage->Controls->Add(this->OFFChar7);
			this->OFFPage->Controls->Add(this->label45);
			this->OFFPage->Controls->Add(this->CUpLoad7);
			this->OFFPage->Controls->Add(this->groupBox26);
			this->OFFPage->Controls->Add(this->OFFChar6);
			this->OFFPage->Controls->Add(this->label51);
			this->OFFPage->Controls->Add(this->CUpLoad6);
			this->OFFPage->Controls->Add(this->groupBox27);
			this->OFFPage->Controls->Add(this->OFFChar5);
			this->OFFPage->Controls->Add(this->label54);
			this->OFFPage->Controls->Add(this->CUpLoad5);
			this->OFFPage->Controls->Add(this->groupBox28);
			this->OFFPage->Controls->Add(this->OFFChar4);
			this->OFFPage->Controls->Add(this->label18);
			this->OFFPage->Controls->Add(this->CUpLoad4);
			this->OFFPage->Controls->Add(this->groupBox23);
			this->OFFPage->Controls->Add(this->OFFChar3);
			this->OFFPage->Controls->Add(this->label27);
			this->OFFPage->Controls->Add(this->CUpLoad3);
			this->OFFPage->Controls->Add(this->groupBox24);
			this->OFFPage->Controls->Add(this->OFFChar2);
			this->OFFPage->Controls->Add(this->OFFCorce2);
			this->OFFPage->Controls->Add(this->CUpLoad2);
			this->OFFPage->Controls->Add(this->groupBox22);
			this->OFFPage->Controls->Add(this->OFFChar1);
			this->OFFPage->Controls->Add(this->OFFCorce1);
			this->OFFPage->Controls->Add(this->CUpLoad1);
			this->OFFPage->Controls->Add(this->groupBox21);
			this->OFFPage->Controls->Add(this->groupBox20);
			this->OFFPage->Controls->Add(this->OFFSTime20);
			this->OFFPage->Controls->Add(this->OFFStage20);
			this->OFFPage->Controls->Add(this->SUpLoad20);
			this->OFFPage->Controls->Add(this->OFFSTime19);
			this->OFFPage->Controls->Add(this->OFFStage19);
			this->OFFPage->Controls->Add(this->SUpLoad19);
			this->OFFPage->Controls->Add(this->groupBox11);
			this->OFFPage->Controls->Add(this->OFFSTime18);
			this->OFFPage->Controls->Add(this->OFFStage18);
			this->OFFPage->Controls->Add(this->SUpLoad18);
			this->OFFPage->Controls->Add(this->groupBox12);
			this->OFFPage->Controls->Add(this->OFFSTime17);
			this->OFFPage->Controls->Add(this->OFFStage17);
			this->OFFPage->Controls->Add(this->SUpLoad17);
			this->OFFPage->Controls->Add(this->groupBox13);
			this->OFFPage->Controls->Add(this->OFFSTime16);
			this->OFFPage->Controls->Add(this->OFFStage16);
			this->OFFPage->Controls->Add(this->SUpLoad16);
			this->OFFPage->Controls->Add(this->groupBox14);
			this->OFFPage->Controls->Add(this->OFFSTime15);
			this->OFFPage->Controls->Add(this->OFFStage15);
			this->OFFPage->Controls->Add(this->SUpLoad15);
			this->OFFPage->Controls->Add(this->groupBox15);
			this->OFFPage->Controls->Add(this->OFFSTime14);
			this->OFFPage->Controls->Add(this->OFFStage14);
			this->OFFPage->Controls->Add(this->SUpLoad14);
			this->OFFPage->Controls->Add(this->groupBox16);
			this->OFFPage->Controls->Add(this->OFFSTime13);
			this->OFFPage->Controls->Add(this->OFFStage13);
			this->OFFPage->Controls->Add(this->SUpLoad13);
			this->OFFPage->Controls->Add(this->groupBox17);
			this->OFFPage->Controls->Add(this->OFFSTime12);
			this->OFFPage->Controls->Add(this->OFFStage12);
			this->OFFPage->Controls->Add(this->SUpLoad12);
			this->OFFPage->Controls->Add(this->groupBox18);
			this->OFFPage->Controls->Add(this->OFFSTime11);
			this->OFFPage->Controls->Add(this->OFFStage11);
			this->OFFPage->Controls->Add(this->SUpLoad11);
			this->OFFPage->Controls->Add(this->groupBox19);
			this->OFFPage->Controls->Add(this->OFFSTime10);
			this->OFFPage->Controls->Add(this->OFFStage10);
			this->OFFPage->Controls->Add(this->SUpLoad10);
			this->OFFPage->Controls->Add(this->groupBox10);
			this->OFFPage->Controls->Add(this->OFFSTime9);
			this->OFFPage->Controls->Add(this->OFFStage9);
			this->OFFPage->Controls->Add(this->SUpLoad9);
			this->OFFPage->Controls->Add(this->groupBox9);
			this->OFFPage->Controls->Add(this->OFFSTime8);
			this->OFFPage->Controls->Add(this->OFFStage8);
			this->OFFPage->Controls->Add(this->SUpLoad8);
			this->OFFPage->Controls->Add(this->groupBox8);
			this->OFFPage->Controls->Add(this->OFFSTime7);
			this->OFFPage->Controls->Add(this->OFFStage7);
			this->OFFPage->Controls->Add(this->SUpLoad7);
			this->OFFPage->Controls->Add(this->groupBox7);
			this->OFFPage->Controls->Add(this->OFFSTime6);
			this->OFFPage->Controls->Add(this->OFFStage6);
			this->OFFPage->Controls->Add(this->SUpLoad6);
			this->OFFPage->Controls->Add(this->groupBox6);
			this->OFFPage->Controls->Add(this->OFFSTime5);
			this->OFFPage->Controls->Add(this->OFFStage5);
			this->OFFPage->Controls->Add(this->SUpLoad5);
			this->OFFPage->Controls->Add(this->groupBox5);
			this->OFFPage->Controls->Add(this->OFFSTime4);
			this->OFFPage->Controls->Add(this->OFFStage4);
			this->OFFPage->Controls->Add(this->SUpLoad4);
			this->OFFPage->Controls->Add(this->groupBox4);
			this->OFFPage->Controls->Add(this->OFFSTime3);
			this->OFFPage->Controls->Add(this->OFFStage3);
			this->OFFPage->Controls->Add(this->SUpLoad3);
			this->OFFPage->Controls->Add(this->groupBox3);
			this->OFFPage->Controls->Add(this->OFFSTime2);
			this->OFFPage->Controls->Add(this->OFFStage2);
			this->OFFPage->Controls->Add(this->SUpLoad2);
			this->OFFPage->Controls->Add(this->groupBox2);
			this->OFFPage->Controls->Add(this->OFFSTime1);
			this->OFFPage->Controls->Add(this->OFFStage1);
			this->OFFPage->Controls->Add(this->SUpLoad1);
			this->OFFPage->Controls->Add(this->groupBox1);
			this->OFFPage->Controls->Add(this->OFFCTime6);
			this->OFFPage->Controls->Add(this->OFFCTime5);
			this->OFFPage->Controls->Add(this->OFFCTime4);
			this->OFFPage->Controls->Add(this->OFFCTime3);
			this->OFFPage->Controls->Add(this->OFFCTime2);
			this->OFFPage->Controls->Add(this->OFFCTime1);
			this->OFFPage->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFPage->Location = System::Drawing::Point(4, 21);
			this->OFFPage->Name = S"OFFPage";
			this->OFFPage->Size = System::Drawing::Size(512, 367);
			this->OFFPage->TabIndex = 0;
			this->OFFPage->Text = S"ローカルランキング";
			// 
			// groupBox77
			// 
			this->groupBox77->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox77->Location = System::Drawing::Point(24, 1728);
			this->groupBox77->Name = S"groupBox77";
			this->groupBox77->Size = System::Drawing::Size(448, 0);
			this->groupBox77->TabIndex = 244;
			this->groupBox77->TabStop = false;
			// 
			// SDelete30
			// 
			this->SDelete30->AutoSize = true;
			this->SDelete30->Enabled = false;
			this->SDelete30->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDelete30->Location = System::Drawing::Point(160, 1184);
			this->SDelete30->Name = S"SDelete30";
			this->SDelete30->Size = System::Drawing::Size(39, 19);
			this->SDelete30->TabIndex = 243;
			this->SDelete30->TabStop = true;
			this->SDelete30->Text = S"削除";
			this->SDelete30->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDelete30_LinkClicked);
			// 
			// SDelete29
			// 
			this->SDelete29->AutoSize = true;
			this->SDelete29->Enabled = false;
			this->SDelete29->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDelete29->Location = System::Drawing::Point(160, 1144);
			this->SDelete29->Name = S"SDelete29";
			this->SDelete29->Size = System::Drawing::Size(39, 19);
			this->SDelete29->TabIndex = 242;
			this->SDelete29->TabStop = true;
			this->SDelete29->Text = S"削除";
			this->SDelete29->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDelete29_LinkClicked);
			// 
			// groupBox75
			// 
			this->groupBox75->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox75->Location = System::Drawing::Point(24, 1200);
			this->groupBox75->Name = S"groupBox75";
			this->groupBox75->Size = System::Drawing::Size(448, 9);
			this->groupBox75->TabIndex = 241;
			this->groupBox75->TabStop = false;
			// 
			// OFFSTime30
			// 
			this->OFFSTime30->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFSTime30->Location = System::Drawing::Point(296, 1184);
			this->OFFSTime30->Name = S"OFFSTime30";
			this->OFFSTime30->Size = System::Drawing::Size(80, 19);
			this->OFFSTime30->TabIndex = 240;
			this->OFFSTime30->Text = S"0：0";
			this->OFFSTime30->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFStage30
			// 
			this->OFFStage30->AutoSize = true;
			this->OFFStage30->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFStage30->Location = System::Drawing::Point(32, 1184);
			this->OFFStage30->Name = S"OFFStage30";
			this->OFFStage30->Size = System::Drawing::Size(94, 19);
			this->OFFStage30->TabIndex = 239;
			this->OFFStage30->Text = S"EXステージ17";
			// 
			// SUpLoad30
			// 
			this->SUpLoad30->AutoSize = true;
			this->SUpLoad30->Enabled = false;
			this->SUpLoad30->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SUpLoad30->Location = System::Drawing::Point(384, 1184);
			this->SUpLoad30->Name = S"SUpLoad30";
			this->SUpLoad30->Size = System::Drawing::Size(77, 19);
			this->SUpLoad30->TabIndex = 238;
			this->SUpLoad30->TabStop = true;
			this->SUpLoad30->Text = S"アップロード";
			this->SUpLoad30->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SUpLoad30_LinkClicked);
			// 
			// OFFSTime29
			// 
			this->OFFSTime29->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFSTime29->Location = System::Drawing::Point(296, 1144);
			this->OFFSTime29->Name = S"OFFSTime29";
			this->OFFSTime29->Size = System::Drawing::Size(80, 19);
			this->OFFSTime29->TabIndex = 237;
			this->OFFSTime29->Text = S"0：0";
			this->OFFSTime29->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFStage29
			// 
			this->OFFStage29->AutoSize = true;
			this->OFFStage29->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFStage29->Location = System::Drawing::Point(32, 1144);
			this->OFFStage29->Name = S"OFFStage29";
			this->OFFStage29->Size = System::Drawing::Size(94, 19);
			this->OFFStage29->TabIndex = 235;
			this->OFFStage29->Text = S"EXステージ16";
			// 
			// SUpLoad29
			// 
			this->SUpLoad29->AutoSize = true;
			this->SUpLoad29->Enabled = false;
			this->SUpLoad29->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SUpLoad29->Location = System::Drawing::Point(384, 1144);
			this->SUpLoad29->Name = S"SUpLoad29";
			this->SUpLoad29->Size = System::Drawing::Size(77, 19);
			this->SUpLoad29->TabIndex = 234;
			this->SUpLoad29->TabStop = true;
			this->SUpLoad29->Text = S"アップロード";
			this->SUpLoad29->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SUpLoad29_LinkClicked);
			// 
			// groupBox76
			// 
			this->groupBox76->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox76->Location = System::Drawing::Point(24, 1160);
			this->groupBox76->Name = S"groupBox76";
			this->groupBox76->Size = System::Drawing::Size(448, 9);
			this->groupBox76->TabIndex = 236;
			this->groupBox76->TabStop = false;
			// 
			// SDelete28
			// 
			this->SDelete28->AutoSize = true;
			this->SDelete28->Enabled = false;
			this->SDelete28->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDelete28->Location = System::Drawing::Point(160, 1104);
			this->SDelete28->Name = S"SDelete28";
			this->SDelete28->Size = System::Drawing::Size(39, 19);
			this->SDelete28->TabIndex = 233;
			this->SDelete28->TabStop = true;
			this->SDelete28->Text = S"削除";
			this->SDelete28->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDelete28_LinkClicked);
			// 
			// SDelete27
			// 
			this->SDelete27->AutoSize = true;
			this->SDelete27->Enabled = false;
			this->SDelete27->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDelete27->Location = System::Drawing::Point(160, 1064);
			this->SDelete27->Name = S"SDelete27";
			this->SDelete27->Size = System::Drawing::Size(39, 19);
			this->SDelete27->TabIndex = 232;
			this->SDelete27->TabStop = true;
			this->SDelete27->Text = S"削除";
			this->SDelete27->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDelete27_LinkClicked);
			// 
			// SDelete26
			// 
			this->SDelete26->AutoSize = true;
			this->SDelete26->Enabled = false;
			this->SDelete26->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDelete26->Location = System::Drawing::Point(160, 1024);
			this->SDelete26->Name = S"SDelete26";
			this->SDelete26->Size = System::Drawing::Size(39, 19);
			this->SDelete26->TabIndex = 231;
			this->SDelete26->TabStop = true;
			this->SDelete26->Text = S"削除";
			this->SDelete26->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDelete26_LinkClicked);
			// 
			// SDelete25
			// 
			this->SDelete25->AutoSize = true;
			this->SDelete25->Enabled = false;
			this->SDelete25->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDelete25->Location = System::Drawing::Point(160, 984);
			this->SDelete25->Name = S"SDelete25";
			this->SDelete25->Size = System::Drawing::Size(39, 19);
			this->SDelete25->TabIndex = 230;
			this->SDelete25->TabStop = true;
			this->SDelete25->Text = S"削除";
			this->SDelete25->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDelete25_LinkClicked);
			// 
			// SDelete24
			// 
			this->SDelete24->AutoSize = true;
			this->SDelete24->Enabled = false;
			this->SDelete24->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDelete24->Location = System::Drawing::Point(160, 944);
			this->SDelete24->Name = S"SDelete24";
			this->SDelete24->Size = System::Drawing::Size(39, 19);
			this->SDelete24->TabIndex = 229;
			this->SDelete24->TabStop = true;
			this->SDelete24->Text = S"削除";
			this->SDelete24->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDelete24_LinkClicked);
			// 
			// SDelete23
			// 
			this->SDelete23->AutoSize = true;
			this->SDelete23->Enabled = false;
			this->SDelete23->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDelete23->Location = System::Drawing::Point(160, 904);
			this->SDelete23->Name = S"SDelete23";
			this->SDelete23->Size = System::Drawing::Size(39, 19);
			this->SDelete23->TabIndex = 228;
			this->SDelete23->TabStop = true;
			this->SDelete23->Text = S"削除";
			this->SDelete23->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDelete23_LinkClicked);
			// 
			// SDelete22
			// 
			this->SDelete22->AutoSize = true;
			this->SDelete22->Enabled = false;
			this->SDelete22->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDelete22->Location = System::Drawing::Point(160, 864);
			this->SDelete22->Name = S"SDelete22";
			this->SDelete22->Size = System::Drawing::Size(39, 19);
			this->SDelete22->TabIndex = 227;
			this->SDelete22->TabStop = true;
			this->SDelete22->Text = S"削除";
			this->SDelete22->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDelete22_LinkClicked);
			// 
			// SDelete21
			// 
			this->SDelete21->AutoSize = true;
			this->SDelete21->Enabled = false;
			this->SDelete21->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDelete21->Location = System::Drawing::Point(160, 824);
			this->SDelete21->Name = S"SDelete21";
			this->SDelete21->Size = System::Drawing::Size(39, 19);
			this->SDelete21->TabIndex = 226;
			this->SDelete21->TabStop = true;
			this->SDelete21->Text = S"削除";
			this->SDelete21->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDelete21_LinkClicked);
			// 
			// groupBox67
			// 
			this->groupBox67->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox67->Location = System::Drawing::Point(24, 1120);
			this->groupBox67->Name = S"groupBox67";
			this->groupBox67->Size = System::Drawing::Size(448, 9);
			this->groupBox67->TabIndex = 225;
			this->groupBox67->TabStop = false;
			// 
			// OFFSTime28
			// 
			this->OFFSTime28->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFSTime28->Location = System::Drawing::Point(296, 1104);
			this->OFFSTime28->Name = S"OFFSTime28";
			this->OFFSTime28->Size = System::Drawing::Size(80, 19);
			this->OFFSTime28->TabIndex = 224;
			this->OFFSTime28->Text = S"0：0";
			this->OFFSTime28->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFStage28
			// 
			this->OFFStage28->AutoSize = true;
			this->OFFStage28->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFStage28->Location = System::Drawing::Point(32, 1104);
			this->OFFStage28->Name = S"OFFStage28";
			this->OFFStage28->Size = System::Drawing::Size(94, 19);
			this->OFFStage28->TabIndex = 223;
			this->OFFStage28->Text = S"EXステージ15";
			// 
			// SUpLoad28
			// 
			this->SUpLoad28->AutoSize = true;
			this->SUpLoad28->Enabled = false;
			this->SUpLoad28->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SUpLoad28->Location = System::Drawing::Point(384, 1104);
			this->SUpLoad28->Name = S"SUpLoad28";
			this->SUpLoad28->Size = System::Drawing::Size(77, 19);
			this->SUpLoad28->TabIndex = 222;
			this->SUpLoad28->TabStop = true;
			this->SUpLoad28->Text = S"アップロード";
			this->SUpLoad28->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SUpLoad28_LinkClicked);
			// 
			// OFFSTime27
			// 
			this->OFFSTime27->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFSTime27->Location = System::Drawing::Point(296, 1064);
			this->OFFSTime27->Name = S"OFFSTime27";
			this->OFFSTime27->Size = System::Drawing::Size(80, 19);
			this->OFFSTime27->TabIndex = 221;
			this->OFFSTime27->Text = S"0：0";
			this->OFFSTime27->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFStage27
			// 
			this->OFFStage27->AutoSize = true;
			this->OFFStage27->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFStage27->Location = System::Drawing::Point(32, 1064);
			this->OFFStage27->Name = S"OFFStage27";
			this->OFFStage27->Size = System::Drawing::Size(94, 19);
			this->OFFStage27->TabIndex = 219;
			this->OFFStage27->Text = S"EXステージ14";
			// 
			// SUpLoad27
			// 
			this->SUpLoad27->AutoSize = true;
			this->SUpLoad27->Enabled = false;
			this->SUpLoad27->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SUpLoad27->Location = System::Drawing::Point(384, 1064);
			this->SUpLoad27->Name = S"SUpLoad27";
			this->SUpLoad27->Size = System::Drawing::Size(77, 19);
			this->SUpLoad27->TabIndex = 218;
			this->SUpLoad27->TabStop = true;
			this->SUpLoad27->Text = S"アップロード";
			this->SUpLoad27->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SUpLoad27_LinkClicked);
			// 
			// groupBox68
			// 
			this->groupBox68->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox68->Location = System::Drawing::Point(24, 1080);
			this->groupBox68->Name = S"groupBox68";
			this->groupBox68->Size = System::Drawing::Size(448, 9);
			this->groupBox68->TabIndex = 220;
			this->groupBox68->TabStop = false;
			// 
			// OFFSTime26
			// 
			this->OFFSTime26->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFSTime26->Location = System::Drawing::Point(296, 1024);
			this->OFFSTime26->Name = S"OFFSTime26";
			this->OFFSTime26->Size = System::Drawing::Size(80, 19);
			this->OFFSTime26->TabIndex = 217;
			this->OFFSTime26->Text = S"0：0";
			this->OFFSTime26->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFStage26
			// 
			this->OFFStage26->AutoSize = true;
			this->OFFStage26->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFStage26->Location = System::Drawing::Point(32, 1024);
			this->OFFStage26->Name = S"OFFStage26";
			this->OFFStage26->Size = System::Drawing::Size(94, 19);
			this->OFFStage26->TabIndex = 215;
			this->OFFStage26->Text = S"EXステージ13";
			// 
			// SUpLoad26
			// 
			this->SUpLoad26->AutoSize = true;
			this->SUpLoad26->Enabled = false;
			this->SUpLoad26->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SUpLoad26->Location = System::Drawing::Point(384, 1024);
			this->SUpLoad26->Name = S"SUpLoad26";
			this->SUpLoad26->Size = System::Drawing::Size(77, 19);
			this->SUpLoad26->TabIndex = 214;
			this->SUpLoad26->TabStop = true;
			this->SUpLoad26->Text = S"アップロード";
			this->SUpLoad26->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SUpLoad26_LinkClicked);
			// 
			// groupBox69
			// 
			this->groupBox69->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox69->Location = System::Drawing::Point(24, 1040);
			this->groupBox69->Name = S"groupBox69";
			this->groupBox69->Size = System::Drawing::Size(448, 9);
			this->groupBox69->TabIndex = 216;
			this->groupBox69->TabStop = false;
			// 
			// OFFSTime25
			// 
			this->OFFSTime25->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFSTime25->Location = System::Drawing::Point(296, 984);
			this->OFFSTime25->Name = S"OFFSTime25";
			this->OFFSTime25->Size = System::Drawing::Size(80, 19);
			this->OFFSTime25->TabIndex = 213;
			this->OFFSTime25->Text = S"0：0";
			this->OFFSTime25->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFStage25
			// 
			this->OFFStage25->AutoSize = true;
			this->OFFStage25->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFStage25->Location = System::Drawing::Point(32, 984);
			this->OFFStage25->Name = S"OFFStage25";
			this->OFFStage25->Size = System::Drawing::Size(94, 19);
			this->OFFStage25->TabIndex = 211;
			this->OFFStage25->Text = S"EXステージ12";
			// 
			// SUpLoad25
			// 
			this->SUpLoad25->AutoSize = true;
			this->SUpLoad25->Enabled = false;
			this->SUpLoad25->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SUpLoad25->Location = System::Drawing::Point(384, 984);
			this->SUpLoad25->Name = S"SUpLoad25";
			this->SUpLoad25->Size = System::Drawing::Size(77, 19);
			this->SUpLoad25->TabIndex = 210;
			this->SUpLoad25->TabStop = true;
			this->SUpLoad25->Text = S"アップロード";
			this->SUpLoad25->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SUpLoad25_LinkClicked);
			// 
			// groupBox70
			// 
			this->groupBox70->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox70->Location = System::Drawing::Point(24, 1000);
			this->groupBox70->Name = S"groupBox70";
			this->groupBox70->Size = System::Drawing::Size(448, 9);
			this->groupBox70->TabIndex = 212;
			this->groupBox70->TabStop = false;
			// 
			// OFFSTime24
			// 
			this->OFFSTime24->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFSTime24->Location = System::Drawing::Point(296, 944);
			this->OFFSTime24->Name = S"OFFSTime24";
			this->OFFSTime24->Size = System::Drawing::Size(80, 19);
			this->OFFSTime24->TabIndex = 209;
			this->OFFSTime24->Text = S"0：0";
			this->OFFSTime24->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFStage24
			// 
			this->OFFStage24->AutoSize = true;
			this->OFFStage24->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFStage24->Location = System::Drawing::Point(32, 944);
			this->OFFStage24->Name = S"OFFStage24";
			this->OFFStage24->Size = System::Drawing::Size(94, 19);
			this->OFFStage24->TabIndex = 207;
			this->OFFStage24->Text = S"EXステージ11";
			// 
			// SUpLoad24
			// 
			this->SUpLoad24->AutoSize = true;
			this->SUpLoad24->Enabled = false;
			this->SUpLoad24->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SUpLoad24->Location = System::Drawing::Point(384, 944);
			this->SUpLoad24->Name = S"SUpLoad24";
			this->SUpLoad24->Size = System::Drawing::Size(77, 19);
			this->SUpLoad24->TabIndex = 206;
			this->SUpLoad24->TabStop = true;
			this->SUpLoad24->Text = S"アップロード";
			this->SUpLoad24->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SUpLoad24_LinkClicked);
			// 
			// groupBox71
			// 
			this->groupBox71->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox71->Location = System::Drawing::Point(24, 960);
			this->groupBox71->Name = S"groupBox71";
			this->groupBox71->Size = System::Drawing::Size(448, 9);
			this->groupBox71->TabIndex = 208;
			this->groupBox71->TabStop = false;
			// 
			// OFFSTime23
			// 
			this->OFFSTime23->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFSTime23->Location = System::Drawing::Point(296, 904);
			this->OFFSTime23->Name = S"OFFSTime23";
			this->OFFSTime23->Size = System::Drawing::Size(80, 19);
			this->OFFSTime23->TabIndex = 205;
			this->OFFSTime23->Text = S"0：0";
			this->OFFSTime23->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFStage23
			// 
			this->OFFStage23->AutoSize = true;
			this->OFFStage23->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFStage23->Location = System::Drawing::Point(32, 904);
			this->OFFStage23->Name = S"OFFStage23";
			this->OFFStage23->Size = System::Drawing::Size(94, 19);
			this->OFFStage23->TabIndex = 203;
			this->OFFStage23->Text = S"EXステージ10";
			// 
			// SUpLoad23
			// 
			this->SUpLoad23->AutoSize = true;
			this->SUpLoad23->Enabled = false;
			this->SUpLoad23->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SUpLoad23->Location = System::Drawing::Point(384, 904);
			this->SUpLoad23->Name = S"SUpLoad23";
			this->SUpLoad23->Size = System::Drawing::Size(77, 19);
			this->SUpLoad23->TabIndex = 202;
			this->SUpLoad23->TabStop = true;
			this->SUpLoad23->Text = S"アップロード";
			this->SUpLoad23->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SUpLoad23_LinkClicked);
			// 
			// groupBox72
			// 
			this->groupBox72->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox72->Location = System::Drawing::Point(24, 920);
			this->groupBox72->Name = S"groupBox72";
			this->groupBox72->Size = System::Drawing::Size(448, 9);
			this->groupBox72->TabIndex = 204;
			this->groupBox72->TabStop = false;
			// 
			// OFFSTime22
			// 
			this->OFFSTime22->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFSTime22->Location = System::Drawing::Point(296, 864);
			this->OFFSTime22->Name = S"OFFSTime22";
			this->OFFSTime22->Size = System::Drawing::Size(80, 19);
			this->OFFSTime22->TabIndex = 201;
			this->OFFSTime22->Text = S"0：0";
			this->OFFSTime22->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFStage22
			// 
			this->OFFStage22->AutoSize = true;
			this->OFFStage22->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFStage22->Location = System::Drawing::Point(32, 864);
			this->OFFStage22->Name = S"OFFStage22";
			this->OFFStage22->Size = System::Drawing::Size(86, 19);
			this->OFFStage22->TabIndex = 199;
			this->OFFStage22->Text = S"EXステージ9";
			// 
			// SUpLoad22
			// 
			this->SUpLoad22->AutoSize = true;
			this->SUpLoad22->Enabled = false;
			this->SUpLoad22->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SUpLoad22->Location = System::Drawing::Point(384, 864);
			this->SUpLoad22->Name = S"SUpLoad22";
			this->SUpLoad22->Size = System::Drawing::Size(77, 19);
			this->SUpLoad22->TabIndex = 198;
			this->SUpLoad22->TabStop = true;
			this->SUpLoad22->Text = S"アップロード";
			this->SUpLoad22->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SUpLoad22_LinkClicked);
			// 
			// groupBox73
			// 
			this->groupBox73->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox73->Location = System::Drawing::Point(24, 880);
			this->groupBox73->Name = S"groupBox73";
			this->groupBox73->Size = System::Drawing::Size(448, 9);
			this->groupBox73->TabIndex = 200;
			this->groupBox73->TabStop = false;
			// 
			// OFFSTime21
			// 
			this->OFFSTime21->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFSTime21->Location = System::Drawing::Point(296, 824);
			this->OFFSTime21->Name = S"OFFSTime21";
			this->OFFSTime21->Size = System::Drawing::Size(80, 19);
			this->OFFSTime21->TabIndex = 197;
			this->OFFSTime21->Text = S"0：0";
			this->OFFSTime21->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFStage21
			// 
			this->OFFStage21->AutoSize = true;
			this->OFFStage21->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFStage21->Location = System::Drawing::Point(32, 824);
			this->OFFStage21->Name = S"OFFStage21";
			this->OFFStage21->Size = System::Drawing::Size(86, 19);
			this->OFFStage21->TabIndex = 195;
			this->OFFStage21->Text = S"EXステージ8";
			// 
			// SUpLoad21
			// 
			this->SUpLoad21->AutoSize = true;
			this->SUpLoad21->Enabled = false;
			this->SUpLoad21->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SUpLoad21->Location = System::Drawing::Point(384, 824);
			this->SUpLoad21->Name = S"SUpLoad21";
			this->SUpLoad21->Size = System::Drawing::Size(77, 19);
			this->SUpLoad21->TabIndex = 194;
			this->SUpLoad21->TabStop = true;
			this->SUpLoad21->Text = S"アップロード";
			this->SUpLoad21->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SUpLoad21_LinkClicked);
			// 
			// groupBox74
			// 
			this->groupBox74->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox74->Location = System::Drawing::Point(24, 840);
			this->groupBox74->Name = S"groupBox74";
			this->groupBox74->Size = System::Drawing::Size(448, 9);
			this->groupBox74->TabIndex = 196;
			this->groupBox74->TabStop = false;
			// 
			// CDelete12
			// 
			this->CDelete12->AutoSize = true;
			this->CDelete12->Enabled = false;
			this->CDelete12->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CDelete12->Location = System::Drawing::Point(160, 1688);
			this->CDelete12->Name = S"CDelete12";
			this->CDelete12->Size = System::Drawing::Size(39, 19);
			this->CDelete12->TabIndex = 193;
			this->CDelete12->TabStop = true;
			this->CDelete12->Text = S"削除";
			this->CDelete12->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CDelete12_LinkClicked);
			// 
			// CDelete11
			// 
			this->CDelete11->AutoSize = true;
			this->CDelete11->Enabled = false;
			this->CDelete11->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CDelete11->Location = System::Drawing::Point(160, 1648);
			this->CDelete11->Name = S"CDelete11";
			this->CDelete11->Size = System::Drawing::Size(39, 19);
			this->CDelete11->TabIndex = 192;
			this->CDelete11->TabStop = true;
			this->CDelete11->Text = S"削除";
			this->CDelete11->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CDelete11_LinkClicked);
			// 
			// CDelete10
			// 
			this->CDelete10->AutoSize = true;
			this->CDelete10->Enabled = false;
			this->CDelete10->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CDelete10->Location = System::Drawing::Point(160, 1608);
			this->CDelete10->Name = S"CDelete10";
			this->CDelete10->Size = System::Drawing::Size(39, 19);
			this->CDelete10->TabIndex = 191;
			this->CDelete10->TabStop = true;
			this->CDelete10->Text = S"削除";
			this->CDelete10->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CDelete10_LinkClicked);
			// 
			// CDelete9
			// 
			this->CDelete9->AutoSize = true;
			this->CDelete9->Enabled = false;
			this->CDelete9->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CDelete9->Location = System::Drawing::Point(160, 1568);
			this->CDelete9->Name = S"CDelete9";
			this->CDelete9->Size = System::Drawing::Size(39, 19);
			this->CDelete9->TabIndex = 190;
			this->CDelete9->TabStop = true;
			this->CDelete9->Text = S"削除";
			this->CDelete9->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CDelete9_LinkClicked);
			// 
			// CDelete8
			// 
			this->CDelete8->AutoSize = true;
			this->CDelete8->Enabled = false;
			this->CDelete8->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CDelete8->Location = System::Drawing::Point(160, 1528);
			this->CDelete8->Name = S"CDelete8";
			this->CDelete8->Size = System::Drawing::Size(39, 19);
			this->CDelete8->TabIndex = 189;
			this->CDelete8->TabStop = true;
			this->CDelete8->Text = S"削除";
			this->CDelete8->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CDelete8_LinkClicked);
			// 
			// CDelete7
			// 
			this->CDelete7->AutoSize = true;
			this->CDelete7->Enabled = false;
			this->CDelete7->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CDelete7->Location = System::Drawing::Point(160, 1488);
			this->CDelete7->Name = S"CDelete7";
			this->CDelete7->Size = System::Drawing::Size(39, 19);
			this->CDelete7->TabIndex = 188;
			this->CDelete7->TabStop = true;
			this->CDelete7->Text = S"削除";
			this->CDelete7->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CDelete7_LinkClicked);
			// 
			// CDelete6
			// 
			this->CDelete6->AutoSize = true;
			this->CDelete6->Enabled = false;
			this->CDelete6->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CDelete6->Location = System::Drawing::Point(160, 1448);
			this->CDelete6->Name = S"CDelete6";
			this->CDelete6->Size = System::Drawing::Size(39, 19);
			this->CDelete6->TabIndex = 187;
			this->CDelete6->TabStop = true;
			this->CDelete6->Text = S"削除";
			this->CDelete6->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CDelete6_LinkClicked);
			// 
			// CDelete5
			// 
			this->CDelete5->AutoSize = true;
			this->CDelete5->Enabled = false;
			this->CDelete5->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CDelete5->Location = System::Drawing::Point(160, 1408);
			this->CDelete5->Name = S"CDelete5";
			this->CDelete5->Size = System::Drawing::Size(39, 19);
			this->CDelete5->TabIndex = 186;
			this->CDelete5->TabStop = true;
			this->CDelete5->Text = S"削除";
			this->CDelete5->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CDelete5_LinkClicked);
			// 
			// CDelete4
			// 
			this->CDelete4->AutoSize = true;
			this->CDelete4->Enabled = false;
			this->CDelete4->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CDelete4->Location = System::Drawing::Point(160, 1368);
			this->CDelete4->Name = S"CDelete4";
			this->CDelete4->Size = System::Drawing::Size(39, 19);
			this->CDelete4->TabIndex = 185;
			this->CDelete4->TabStop = true;
			this->CDelete4->Text = S"削除";
			this->CDelete4->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CDelete4_LinkClicked);
			// 
			// CDelete3
			// 
			this->CDelete3->AutoSize = true;
			this->CDelete3->Enabled = false;
			this->CDelete3->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CDelete3->Location = System::Drawing::Point(160, 1328);
			this->CDelete3->Name = S"CDelete3";
			this->CDelete3->Size = System::Drawing::Size(39, 19);
			this->CDelete3->TabIndex = 184;
			this->CDelete3->TabStop = true;
			this->CDelete3->Text = S"削除";
			this->CDelete3->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CDelete3_LinkClicked);
			// 
			// CDelete2
			// 
			this->CDelete2->AutoSize = true;
			this->CDelete2->Enabled = false;
			this->CDelete2->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CDelete2->Location = System::Drawing::Point(160, 1288);
			this->CDelete2->Name = S"CDelete2";
			this->CDelete2->Size = System::Drawing::Size(39, 19);
			this->CDelete2->TabIndex = 183;
			this->CDelete2->TabStop = true;
			this->CDelete2->Text = S"削除";
			this->CDelete2->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CDelete2_LinkClicked);
			// 
			// CDelete1
			// 
			this->CDelete1->AutoSize = true;
			this->CDelete1->Enabled = false;
			this->CDelete1->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CDelete1->Location = System::Drawing::Point(160, 1248);
			this->CDelete1->Name = S"CDelete1";
			this->CDelete1->Size = System::Drawing::Size(39, 19);
			this->CDelete1->TabIndex = 182;
			this->CDelete1->TabStop = true;
			this->CDelete1->Text = S"削除";
			this->CDelete1->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CDelete1_LinkClicked);
			// 
			// SDelete20
			// 
			this->SDelete20->AutoSize = true;
			this->SDelete20->Enabled = false;
			this->SDelete20->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDelete20->Location = System::Drawing::Point(160, 784);
			this->SDelete20->Name = S"SDelete20";
			this->SDelete20->Size = System::Drawing::Size(39, 19);
			this->SDelete20->TabIndex = 181;
			this->SDelete20->TabStop = true;
			this->SDelete20->Text = S"削除";
			this->SDelete20->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDelete20_LinkClicked);
			// 
			// SDelete19
			// 
			this->SDelete19->AutoSize = true;
			this->SDelete19->Enabled = false;
			this->SDelete19->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDelete19->Location = System::Drawing::Point(160, 744);
			this->SDelete19->Name = S"SDelete19";
			this->SDelete19->Size = System::Drawing::Size(39, 19);
			this->SDelete19->TabIndex = 180;
			this->SDelete19->TabStop = true;
			this->SDelete19->Text = S"削除";
			this->SDelete19->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDelete19_LinkClicked);
			// 
			// SDelete18
			// 
			this->SDelete18->AutoSize = true;
			this->SDelete18->Enabled = false;
			this->SDelete18->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDelete18->Location = System::Drawing::Point(160, 704);
			this->SDelete18->Name = S"SDelete18";
			this->SDelete18->Size = System::Drawing::Size(39, 19);
			this->SDelete18->TabIndex = 179;
			this->SDelete18->TabStop = true;
			this->SDelete18->Text = S"削除";
			this->SDelete18->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDelete18_LinkClicked);
			// 
			// SDelete17
			// 
			this->SDelete17->AutoSize = true;
			this->SDelete17->Enabled = false;
			this->SDelete17->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDelete17->Location = System::Drawing::Point(160, 664);
			this->SDelete17->Name = S"SDelete17";
			this->SDelete17->Size = System::Drawing::Size(39, 19);
			this->SDelete17->TabIndex = 178;
			this->SDelete17->TabStop = true;
			this->SDelete17->Text = S"削除";
			this->SDelete17->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDelete17_LinkClicked);
			// 
			// SDelete16
			// 
			this->SDelete16->AutoSize = true;
			this->SDelete16->Enabled = false;
			this->SDelete16->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDelete16->Location = System::Drawing::Point(160, 624);
			this->SDelete16->Name = S"SDelete16";
			this->SDelete16->Size = System::Drawing::Size(39, 19);
			this->SDelete16->TabIndex = 177;
			this->SDelete16->TabStop = true;
			this->SDelete16->Text = S"削除";
			this->SDelete16->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDelete16_LinkClicked);
			// 
			// SDelete15
			// 
			this->SDelete15->AutoSize = true;
			this->SDelete15->Enabled = false;
			this->SDelete15->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDelete15->Location = System::Drawing::Point(160, 584);
			this->SDelete15->Name = S"SDelete15";
			this->SDelete15->Size = System::Drawing::Size(39, 19);
			this->SDelete15->TabIndex = 176;
			this->SDelete15->TabStop = true;
			this->SDelete15->Text = S"削除";
			this->SDelete15->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDelete15_LinkClicked);
			// 
			// SDelete14
			// 
			this->SDelete14->AutoSize = true;
			this->SDelete14->Enabled = false;
			this->SDelete14->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDelete14->Location = System::Drawing::Point(160, 544);
			this->SDelete14->Name = S"SDelete14";
			this->SDelete14->Size = System::Drawing::Size(39, 19);
			this->SDelete14->TabIndex = 175;
			this->SDelete14->TabStop = true;
			this->SDelete14->Text = S"削除";
			this->SDelete14->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDelete14_LinkClicked);
			// 
			// SDelete13
			// 
			this->SDelete13->AutoSize = true;
			this->SDelete13->Enabled = false;
			this->SDelete13->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDelete13->Location = System::Drawing::Point(160, 504);
			this->SDelete13->Name = S"SDelete13";
			this->SDelete13->Size = System::Drawing::Size(39, 19);
			this->SDelete13->TabIndex = 174;
			this->SDelete13->TabStop = true;
			this->SDelete13->Text = S"削除";
			this->SDelete13->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDelete13_LinkClicked);
			// 
			// SDelete12
			// 
			this->SDelete12->AutoSize = true;
			this->SDelete12->Enabled = false;
			this->SDelete12->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDelete12->Location = System::Drawing::Point(160, 464);
			this->SDelete12->Name = S"SDelete12";
			this->SDelete12->Size = System::Drawing::Size(39, 19);
			this->SDelete12->TabIndex = 173;
			this->SDelete12->TabStop = true;
			this->SDelete12->Text = S"削除";
			this->SDelete12->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDelete12_LinkClicked);
			// 
			// SDelete11
			// 
			this->SDelete11->AutoSize = true;
			this->SDelete11->Enabled = false;
			this->SDelete11->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDelete11->Location = System::Drawing::Point(160, 424);
			this->SDelete11->Name = S"SDelete11";
			this->SDelete11->Size = System::Drawing::Size(39, 19);
			this->SDelete11->TabIndex = 172;
			this->SDelete11->TabStop = true;
			this->SDelete11->Text = S"削除";
			this->SDelete11->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDelete11_LinkClicked);
			// 
			// SDelete10
			// 
			this->SDelete10->AutoSize = true;
			this->SDelete10->Enabled = false;
			this->SDelete10->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDelete10->Location = System::Drawing::Point(160, 384);
			this->SDelete10->Name = S"SDelete10";
			this->SDelete10->Size = System::Drawing::Size(39, 19);
			this->SDelete10->TabIndex = 171;
			this->SDelete10->TabStop = true;
			this->SDelete10->Text = S"削除";
			this->SDelete10->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDelete10_LinkClicked);
			// 
			// SDelete9
			// 
			this->SDelete9->AutoSize = true;
			this->SDelete9->Enabled = false;
			this->SDelete9->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDelete9->Location = System::Drawing::Point(160, 344);
			this->SDelete9->Name = S"SDelete9";
			this->SDelete9->Size = System::Drawing::Size(39, 19);
			this->SDelete9->TabIndex = 170;
			this->SDelete9->TabStop = true;
			this->SDelete9->Text = S"削除";
			this->SDelete9->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDelete9_LinkClicked);
			// 
			// SDelete8
			// 
			this->SDelete8->AutoSize = true;
			this->SDelete8->Enabled = false;
			this->SDelete8->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDelete8->Location = System::Drawing::Point(160, 304);
			this->SDelete8->Name = S"SDelete8";
			this->SDelete8->Size = System::Drawing::Size(39, 19);
			this->SDelete8->TabIndex = 169;
			this->SDelete8->TabStop = true;
			this->SDelete8->Text = S"削除";
			this->SDelete8->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDelete8_LinkClicked);
			// 
			// SDelete7
			// 
			this->SDelete7->AutoSize = true;
			this->SDelete7->Enabled = false;
			this->SDelete7->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDelete7->Location = System::Drawing::Point(160, 264);
			this->SDelete7->Name = S"SDelete7";
			this->SDelete7->Size = System::Drawing::Size(39, 19);
			this->SDelete7->TabIndex = 168;
			this->SDelete7->TabStop = true;
			this->SDelete7->Text = S"削除";
			this->SDelete7->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDelete7_LinkClicked);
			// 
			// SDelete6
			// 
			this->SDelete6->AutoSize = true;
			this->SDelete6->Enabled = false;
			this->SDelete6->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDelete6->Location = System::Drawing::Point(160, 224);
			this->SDelete6->Name = S"SDelete6";
			this->SDelete6->Size = System::Drawing::Size(39, 19);
			this->SDelete6->TabIndex = 167;
			this->SDelete6->TabStop = true;
			this->SDelete6->Text = S"削除";
			this->SDelete6->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDelete6_LinkClicked);
			// 
			// SDelete5
			// 
			this->SDelete5->AutoSize = true;
			this->SDelete5->Enabled = false;
			this->SDelete5->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDelete5->Location = System::Drawing::Point(160, 184);
			this->SDelete5->Name = S"SDelete5";
			this->SDelete5->Size = System::Drawing::Size(39, 19);
			this->SDelete5->TabIndex = 166;
			this->SDelete5->TabStop = true;
			this->SDelete5->Text = S"削除";
			this->SDelete5->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDelete5_LinkClicked);
			// 
			// SDelete4
			// 
			this->SDelete4->AutoSize = true;
			this->SDelete4->Enabled = false;
			this->SDelete4->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDelete4->Location = System::Drawing::Point(160, 144);
			this->SDelete4->Name = S"SDelete4";
			this->SDelete4->Size = System::Drawing::Size(39, 19);
			this->SDelete4->TabIndex = 165;
			this->SDelete4->TabStop = true;
			this->SDelete4->Text = S"削除";
			this->SDelete4->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDelete4_LinkClicked);
			// 
			// SDelete3
			// 
			this->SDelete3->AutoSize = true;
			this->SDelete3->Enabled = false;
			this->SDelete3->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDelete3->Location = System::Drawing::Point(160, 104);
			this->SDelete3->Name = S"SDelete3";
			this->SDelete3->Size = System::Drawing::Size(39, 19);
			this->SDelete3->TabIndex = 164;
			this->SDelete3->TabStop = true;
			this->SDelete3->Text = S"削除";
			this->SDelete3->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDelete3_LinkClicked);
			// 
			// SDelete2
			// 
			this->SDelete2->AutoSize = true;
			this->SDelete2->Enabled = false;
			this->SDelete2->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDelete2->Location = System::Drawing::Point(160, 64);
			this->SDelete2->Name = S"SDelete2";
			this->SDelete2->Size = System::Drawing::Size(39, 19);
			this->SDelete2->TabIndex = 163;
			this->SDelete2->TabStop = true;
			this->SDelete2->Text = S"削除";
			this->SDelete2->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDelete2_LinkClicked);
			// 
			// SDelete1
			// 
			this->SDelete1->AutoSize = true;
			this->SDelete1->Enabled = false;
			this->SDelete1->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDelete1->Location = System::Drawing::Point(160, 24);
			this->SDelete1->Name = S"SDelete1";
			this->SDelete1->Size = System::Drawing::Size(39, 19);
			this->SDelete1->TabIndex = 162;
			this->SDelete1->TabStop = true;
			this->SDelete1->Text = S"削除";
			this->SDelete1->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDelete1_LinkClicked);
			// 
			// groupBox33
			// 
			this->groupBox33->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox33->Location = System::Drawing::Point(24, 1416);
			this->groupBox33->Name = S"groupBox33";
			this->groupBox33->Size = System::Drawing::Size(448, 0);
			this->groupBox33->TabIndex = 161;
			this->groupBox33->TabStop = false;
			// 
			// OFFCTime12
			// 
			this->OFFCTime12->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFCTime12->Location = System::Drawing::Point(296, 1688);
			this->OFFCTime12->Name = S"OFFCTime12";
			this->OFFCTime12->Size = System::Drawing::Size(80, 19);
			this->OFFCTime12->TabIndex = 160;
			this->OFFCTime12->Text = S"0：0";
			this->OFFCTime12->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFChar12
			// 
			this->OFFChar12->AutoSize = true;
			this->OFFChar12->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFChar12->Location = System::Drawing::Point(256, 1688);
			this->OFFChar12->Name = S"OFFChar12";
			this->OFFChar12->Size = System::Drawing::Size(42, 19);
			this->OFFChar12->TabIndex = 158;
			this->OFFChar12->Text = S"キャラ";
			this->OFFChar12->Visible = false;
			// 
			// label57
			// 
			this->label57->AutoSize = true;
			this->label57->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label57->Location = System::Drawing::Point(32, 1688);
			this->label57->Name = S"label57";
			this->label57->Size = System::Drawing::Size(60, 19);
			this->label57->TabIndex = 157;
			this->label57->Text = S"コース12";
			// 
			// CUpLoad12
			// 
			this->CUpLoad12->AutoSize = true;
			this->CUpLoad12->Enabled = false;
			this->CUpLoad12->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CUpLoad12->Location = System::Drawing::Point(384, 1688);
			this->CUpLoad12->Name = S"CUpLoad12";
			this->CUpLoad12->Size = System::Drawing::Size(77, 19);
			this->CUpLoad12->TabIndex = 156;
			this->CUpLoad12->TabStop = true;
			this->CUpLoad12->Text = S"アップロード";
			this->CUpLoad12->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CUpLoad12_LinkClicked);
			// 
			// groupBox29
			// 
			this->groupBox29->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox29->Location = System::Drawing::Point(24, 1704);
			this->groupBox29->Name = S"groupBox29";
			this->groupBox29->Size = System::Drawing::Size(448, 9);
			this->groupBox29->TabIndex = 159;
			this->groupBox29->TabStop = false;
			// 
			// OFFCTime11
			// 
			this->OFFCTime11->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFCTime11->Location = System::Drawing::Point(296, 1648);
			this->OFFCTime11->Name = S"OFFCTime11";
			this->OFFCTime11->Size = System::Drawing::Size(80, 19);
			this->OFFCTime11->TabIndex = 155;
			this->OFFCTime11->Text = S"0：0";
			this->OFFCTime11->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFChar11
			// 
			this->OFFChar11->AutoSize = true;
			this->OFFChar11->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFChar11->Location = System::Drawing::Point(256, 1648);
			this->OFFChar11->Name = S"OFFChar11";
			this->OFFChar11->Size = System::Drawing::Size(42, 19);
			this->OFFChar11->TabIndex = 153;
			this->OFFChar11->Text = S"キャラ";
			this->OFFChar11->Visible = false;
			// 
			// label60
			// 
			this->label60->AutoSize = true;
			this->label60->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label60->Location = System::Drawing::Point(32, 1648);
			this->label60->Name = S"label60";
			this->label60->Size = System::Drawing::Size(60, 19);
			this->label60->TabIndex = 152;
			this->label60->Text = S"コース11";
			// 
			// CUpLoad11
			// 
			this->CUpLoad11->AutoSize = true;
			this->CUpLoad11->Enabled = false;
			this->CUpLoad11->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CUpLoad11->Location = System::Drawing::Point(384, 1648);
			this->CUpLoad11->Name = S"CUpLoad11";
			this->CUpLoad11->Size = System::Drawing::Size(77, 19);
			this->CUpLoad11->TabIndex = 151;
			this->CUpLoad11->TabStop = true;
			this->CUpLoad11->Text = S"アップロード";
			this->CUpLoad11->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CUpLoad11_LinkClicked);
			// 
			// groupBox30
			// 
			this->groupBox30->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox30->Location = System::Drawing::Point(24, 1664);
			this->groupBox30->Name = S"groupBox30";
			this->groupBox30->Size = System::Drawing::Size(448, 9);
			this->groupBox30->TabIndex = 154;
			this->groupBox30->TabStop = false;
			// 
			// OFFCTime10
			// 
			this->OFFCTime10->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFCTime10->Location = System::Drawing::Point(296, 1608);
			this->OFFCTime10->Name = S"OFFCTime10";
			this->OFFCTime10->Size = System::Drawing::Size(80, 19);
			this->OFFCTime10->TabIndex = 150;
			this->OFFCTime10->Text = S"0：0";
			this->OFFCTime10->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFChar10
			// 
			this->OFFChar10->AutoSize = true;
			this->OFFChar10->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFChar10->Location = System::Drawing::Point(256, 1608);
			this->OFFChar10->Name = S"OFFChar10";
			this->OFFChar10->Size = System::Drawing::Size(42, 19);
			this->OFFChar10->TabIndex = 148;
			this->OFFChar10->Text = S"キャラ";
			this->OFFChar10->Visible = false;
			// 
			// label63
			// 
			this->label63->AutoSize = true;
			this->label63->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label63->Location = System::Drawing::Point(32, 1608);
			this->label63->Name = S"label63";
			this->label63->Size = System::Drawing::Size(60, 19);
			this->label63->TabIndex = 147;
			this->label63->Text = S"コース10";
			// 
			// CUpLoad10
			// 
			this->CUpLoad10->AutoSize = true;
			this->CUpLoad10->Enabled = false;
			this->CUpLoad10->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CUpLoad10->Location = System::Drawing::Point(384, 1608);
			this->CUpLoad10->Name = S"CUpLoad10";
			this->CUpLoad10->Size = System::Drawing::Size(77, 19);
			this->CUpLoad10->TabIndex = 146;
			this->CUpLoad10->TabStop = true;
			this->CUpLoad10->Text = S"アップロード";
			this->CUpLoad10->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CUpLoad10_LinkClicked);
			// 
			// groupBox31
			// 
			this->groupBox31->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox31->Location = System::Drawing::Point(24, 1624);
			this->groupBox31->Name = S"groupBox31";
			this->groupBox31->Size = System::Drawing::Size(448, 9);
			this->groupBox31->TabIndex = 149;
			this->groupBox31->TabStop = false;
			// 
			// OFFCTime9
			// 
			this->OFFCTime9->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFCTime9->Location = System::Drawing::Point(296, 1568);
			this->OFFCTime9->Name = S"OFFCTime9";
			this->OFFCTime9->Size = System::Drawing::Size(80, 19);
			this->OFFCTime9->TabIndex = 145;
			this->OFFCTime9->Text = S"0：0";
			this->OFFCTime9->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFChar9
			// 
			this->OFFChar9->AutoSize = true;
			this->OFFChar9->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFChar9->Location = System::Drawing::Point(256, 1568);
			this->OFFChar9->Name = S"OFFChar9";
			this->OFFChar9->Size = System::Drawing::Size(42, 19);
			this->OFFChar9->TabIndex = 143;
			this->OFFChar9->Text = S"キャラ";
			this->OFFChar9->Visible = false;
			// 
			// label66
			// 
			this->label66->AutoSize = true;
			this->label66->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label66->Location = System::Drawing::Point(32, 1568);
			this->label66->Name = S"label66";
			this->label66->Size = System::Drawing::Size(52, 19);
			this->label66->TabIndex = 142;
			this->label66->Text = S"コース9";
			// 
			// CUpLoad9
			// 
			this->CUpLoad9->AutoSize = true;
			this->CUpLoad9->Enabled = false;
			this->CUpLoad9->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CUpLoad9->Location = System::Drawing::Point(384, 1568);
			this->CUpLoad9->Name = S"CUpLoad9";
			this->CUpLoad9->Size = System::Drawing::Size(77, 19);
			this->CUpLoad9->TabIndex = 141;
			this->CUpLoad9->TabStop = true;
			this->CUpLoad9->Text = S"アップロード";
			this->CUpLoad9->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CUpLoad9_LinkClicked);
			// 
			// groupBox32
			// 
			this->groupBox32->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox32->Location = System::Drawing::Point(24, 1584);
			this->groupBox32->Name = S"groupBox32";
			this->groupBox32->Size = System::Drawing::Size(448, 9);
			this->groupBox32->TabIndex = 144;
			this->groupBox32->TabStop = false;
			// 
			// OFFCTime8
			// 
			this->OFFCTime8->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFCTime8->Location = System::Drawing::Point(296, 1528);
			this->OFFCTime8->Name = S"OFFCTime8";
			this->OFFCTime8->Size = System::Drawing::Size(80, 19);
			this->OFFCTime8->TabIndex = 140;
			this->OFFCTime8->Text = S"0：0";
			this->OFFCTime8->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFChar8
			// 
			this->OFFChar8->AutoSize = true;
			this->OFFChar8->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFChar8->Location = System::Drawing::Point(256, 1528);
			this->OFFChar8->Name = S"OFFChar8";
			this->OFFChar8->Size = System::Drawing::Size(42, 19);
			this->OFFChar8->TabIndex = 138;
			this->OFFChar8->Text = S"キャラ";
			this->OFFChar8->Visible = false;
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label36->Location = System::Drawing::Point(32, 1528);
			this->label36->Name = S"label36";
			this->label36->Size = System::Drawing::Size(52, 19);
			this->label36->TabIndex = 137;
			this->label36->Text = S"コース8";
			// 
			// CUpLoad8
			// 
			this->CUpLoad8->AutoSize = true;
			this->CUpLoad8->Enabled = false;
			this->CUpLoad8->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CUpLoad8->Location = System::Drawing::Point(384, 1528);
			this->CUpLoad8->Name = S"CUpLoad8";
			this->CUpLoad8->Size = System::Drawing::Size(77, 19);
			this->CUpLoad8->TabIndex = 136;
			this->CUpLoad8->TabStop = true;
			this->CUpLoad8->Text = S"アップロード";
			this->CUpLoad8->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CUpLoad8_LinkClicked);
			// 
			// groupBox25
			// 
			this->groupBox25->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox25->Location = System::Drawing::Point(24, 1544);
			this->groupBox25->Name = S"groupBox25";
			this->groupBox25->Size = System::Drawing::Size(448, 9);
			this->groupBox25->TabIndex = 139;
			this->groupBox25->TabStop = false;
			// 
			// OFFCTime7
			// 
			this->OFFCTime7->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFCTime7->Location = System::Drawing::Point(296, 1488);
			this->OFFCTime7->Name = S"OFFCTime7";
			this->OFFCTime7->Size = System::Drawing::Size(80, 19);
			this->OFFCTime7->TabIndex = 135;
			this->OFFCTime7->Text = S"0：0";
			this->OFFCTime7->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFChar7
			// 
			this->OFFChar7->AutoSize = true;
			this->OFFChar7->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFChar7->Location = System::Drawing::Point(256, 1488);
			this->OFFChar7->Name = S"OFFChar7";
			this->OFFChar7->Size = System::Drawing::Size(42, 19);
			this->OFFChar7->TabIndex = 133;
			this->OFFChar7->Text = S"キャラ";
			this->OFFChar7->Visible = false;
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label45->Location = System::Drawing::Point(32, 1488);
			this->label45->Name = S"label45";
			this->label45->Size = System::Drawing::Size(52, 19);
			this->label45->TabIndex = 132;
			this->label45->Text = S"コース7";
			// 
			// CUpLoad7
			// 
			this->CUpLoad7->AutoSize = true;
			this->CUpLoad7->Enabled = false;
			this->CUpLoad7->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CUpLoad7->Location = System::Drawing::Point(384, 1488);
			this->CUpLoad7->Name = S"CUpLoad7";
			this->CUpLoad7->Size = System::Drawing::Size(77, 19);
			this->CUpLoad7->TabIndex = 131;
			this->CUpLoad7->TabStop = true;
			this->CUpLoad7->Text = S"アップロード";
			this->CUpLoad7->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CUpLoad7_LinkClicked);
			// 
			// groupBox26
			// 
			this->groupBox26->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox26->Location = System::Drawing::Point(24, 1504);
			this->groupBox26->Name = S"groupBox26";
			this->groupBox26->Size = System::Drawing::Size(448, 9);
			this->groupBox26->TabIndex = 134;
			this->groupBox26->TabStop = false;
			// 
			// OFFChar6
			// 
			this->OFFChar6->AutoSize = true;
			this->OFFChar6->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFChar6->Location = System::Drawing::Point(256, 1448);
			this->OFFChar6->Name = S"OFFChar6";
			this->OFFChar6->Size = System::Drawing::Size(42, 19);
			this->OFFChar6->TabIndex = 128;
			this->OFFChar6->Text = S"キャラ";
			this->OFFChar6->Visible = false;
			// 
			// label51
			// 
			this->label51->AutoSize = true;
			this->label51->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label51->Location = System::Drawing::Point(32, 1448);
			this->label51->Name = S"label51";
			this->label51->Size = System::Drawing::Size(52, 19);
			this->label51->TabIndex = 127;
			this->label51->Text = S"コース6";
			// 
			// CUpLoad6
			// 
			this->CUpLoad6->AutoSize = true;
			this->CUpLoad6->Enabled = false;
			this->CUpLoad6->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CUpLoad6->Location = System::Drawing::Point(384, 1448);
			this->CUpLoad6->Name = S"CUpLoad6";
			this->CUpLoad6->Size = System::Drawing::Size(77, 19);
			this->CUpLoad6->TabIndex = 126;
			this->CUpLoad6->TabStop = true;
			this->CUpLoad6->Text = S"アップロード";
			this->CUpLoad6->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CUpLoad6_LinkClicked);
			// 
			// groupBox27
			// 
			this->groupBox27->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox27->Location = System::Drawing::Point(24, 1464);
			this->groupBox27->Name = S"groupBox27";
			this->groupBox27->Size = System::Drawing::Size(448, 9);
			this->groupBox27->TabIndex = 129;
			this->groupBox27->TabStop = false;
			// 
			// OFFChar5
			// 
			this->OFFChar5->AutoSize = true;
			this->OFFChar5->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFChar5->Location = System::Drawing::Point(256, 1408);
			this->OFFChar5->Name = S"OFFChar5";
			this->OFFChar5->Size = System::Drawing::Size(42, 19);
			this->OFFChar5->TabIndex = 123;
			this->OFFChar5->Text = S"キャラ";
			this->OFFChar5->Visible = false;
			// 
			// label54
			// 
			this->label54->AutoSize = true;
			this->label54->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label54->Location = System::Drawing::Point(32, 1408);
			this->label54->Name = S"label54";
			this->label54->Size = System::Drawing::Size(52, 19);
			this->label54->TabIndex = 122;
			this->label54->Text = S"コース5";
			// 
			// CUpLoad5
			// 
			this->CUpLoad5->AutoSize = true;
			this->CUpLoad5->Enabled = false;
			this->CUpLoad5->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CUpLoad5->Location = System::Drawing::Point(384, 1408);
			this->CUpLoad5->Name = S"CUpLoad5";
			this->CUpLoad5->Size = System::Drawing::Size(77, 19);
			this->CUpLoad5->TabIndex = 121;
			this->CUpLoad5->TabStop = true;
			this->CUpLoad5->Text = S"アップロード";
			this->CUpLoad5->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CUpLoad5_LinkClicked);
			// 
			// groupBox28
			// 
			this->groupBox28->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox28->Location = System::Drawing::Point(24, 1424);
			this->groupBox28->Name = S"groupBox28";
			this->groupBox28->Size = System::Drawing::Size(448, 9);
			this->groupBox28->TabIndex = 124;
			this->groupBox28->TabStop = false;
			// 
			// OFFChar4
			// 
			this->OFFChar4->AutoSize = true;
			this->OFFChar4->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFChar4->Location = System::Drawing::Point(256, 1368);
			this->OFFChar4->Name = S"OFFChar4";
			this->OFFChar4->Size = System::Drawing::Size(42, 19);
			this->OFFChar4->TabIndex = 118;
			this->OFFChar4->Text = S"キャラ";
			this->OFFChar4->Visible = false;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label18->Location = System::Drawing::Point(32, 1368);
			this->label18->Name = S"label18";
			this->label18->Size = System::Drawing::Size(52, 19);
			this->label18->TabIndex = 117;
			this->label18->Text = S"コース4";
			// 
			// CUpLoad4
			// 
			this->CUpLoad4->AutoSize = true;
			this->CUpLoad4->Enabled = false;
			this->CUpLoad4->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CUpLoad4->Location = System::Drawing::Point(384, 1368);
			this->CUpLoad4->Name = S"CUpLoad4";
			this->CUpLoad4->Size = System::Drawing::Size(77, 19);
			this->CUpLoad4->TabIndex = 116;
			this->CUpLoad4->TabStop = true;
			this->CUpLoad4->Text = S"アップロード";
			this->CUpLoad4->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CUpLoad4_LinkClicked);
			// 
			// groupBox23
			// 
			this->groupBox23->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox23->Location = System::Drawing::Point(24, 1384);
			this->groupBox23->Name = S"groupBox23";
			this->groupBox23->Size = System::Drawing::Size(448, 9);
			this->groupBox23->TabIndex = 119;
			this->groupBox23->TabStop = false;
			// 
			// OFFChar3
			// 
			this->OFFChar3->AutoSize = true;
			this->OFFChar3->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFChar3->Location = System::Drawing::Point(256, 1328);
			this->OFFChar3->Name = S"OFFChar3";
			this->OFFChar3->Size = System::Drawing::Size(42, 19);
			this->OFFChar3->TabIndex = 113;
			this->OFFChar3->Text = S"キャラ";
			this->OFFChar3->Visible = false;
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label27->Location = System::Drawing::Point(32, 1328);
			this->label27->Name = S"label27";
			this->label27->Size = System::Drawing::Size(52, 19);
			this->label27->TabIndex = 112;
			this->label27->Text = S"コース3";
			// 
			// CUpLoad3
			// 
			this->CUpLoad3->AutoSize = true;
			this->CUpLoad3->Enabled = false;
			this->CUpLoad3->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CUpLoad3->Location = System::Drawing::Point(384, 1328);
			this->CUpLoad3->Name = S"CUpLoad3";
			this->CUpLoad3->Size = System::Drawing::Size(77, 19);
			this->CUpLoad3->TabIndex = 111;
			this->CUpLoad3->TabStop = true;
			this->CUpLoad3->Text = S"アップロード";
			this->CUpLoad3->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CUpLoad3_LinkClicked);
			// 
			// groupBox24
			// 
			this->groupBox24->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox24->Location = System::Drawing::Point(24, 1344);
			this->groupBox24->Name = S"groupBox24";
			this->groupBox24->Size = System::Drawing::Size(448, 9);
			this->groupBox24->TabIndex = 114;
			this->groupBox24->TabStop = false;
			// 
			// OFFChar2
			// 
			this->OFFChar2->AutoSize = true;
			this->OFFChar2->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFChar2->Location = System::Drawing::Point(256, 1288);
			this->OFFChar2->Name = S"OFFChar2";
			this->OFFChar2->Size = System::Drawing::Size(42, 19);
			this->OFFChar2->TabIndex = 108;
			this->OFFChar2->Text = S"キャラ";
			this->OFFChar2->Visible = false;
			// 
			// OFFCorce2
			// 
			this->OFFCorce2->AutoSize = true;
			this->OFFCorce2->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFCorce2->Location = System::Drawing::Point(32, 1288);
			this->OFFCorce2->Name = S"OFFCorce2";
			this->OFFCorce2->Size = System::Drawing::Size(52, 19);
			this->OFFCorce2->TabIndex = 107;
			this->OFFCorce2->Text = S"コース2";
			// 
			// CUpLoad2
			// 
			this->CUpLoad2->AutoSize = true;
			this->CUpLoad2->Enabled = false;
			this->CUpLoad2->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CUpLoad2->Location = System::Drawing::Point(384, 1288);
			this->CUpLoad2->Name = S"CUpLoad2";
			this->CUpLoad2->Size = System::Drawing::Size(77, 19);
			this->CUpLoad2->TabIndex = 106;
			this->CUpLoad2->TabStop = true;
			this->CUpLoad2->Text = S"アップロード";
			this->CUpLoad2->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CUpLoad2_LinkClicked);
			// 
			// groupBox22
			// 
			this->groupBox22->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox22->Location = System::Drawing::Point(24, 1304);
			this->groupBox22->Name = S"groupBox22";
			this->groupBox22->Size = System::Drawing::Size(448, 9);
			this->groupBox22->TabIndex = 109;
			this->groupBox22->TabStop = false;
			// 
			// OFFChar1
			// 
			this->OFFChar1->AutoSize = true;
			this->OFFChar1->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFChar1->Location = System::Drawing::Point(256, 1248);
			this->OFFChar1->Name = S"OFFChar1";
			this->OFFChar1->Size = System::Drawing::Size(42, 19);
			this->OFFChar1->TabIndex = 103;
			this->OFFChar1->Text = S"キャラ";
			this->OFFChar1->Visible = false;
			// 
			// OFFCorce1
			// 
			this->OFFCorce1->AutoSize = true;
			this->OFFCorce1->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFCorce1->Location = System::Drawing::Point(32, 1248);
			this->OFFCorce1->Name = S"OFFCorce1";
			this->OFFCorce1->Size = System::Drawing::Size(52, 19);
			this->OFFCorce1->TabIndex = 102;
			this->OFFCorce1->Text = S"コース1";
			// 
			// CUpLoad1
			// 
			this->CUpLoad1->AutoSize = true;
			this->CUpLoad1->Enabled = false;
			this->CUpLoad1->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CUpLoad1->Location = System::Drawing::Point(384, 1248);
			this->CUpLoad1->Name = S"CUpLoad1";
			this->CUpLoad1->Size = System::Drawing::Size(77, 19);
			this->CUpLoad1->TabIndex = 101;
			this->CUpLoad1->TabStop = true;
			this->CUpLoad1->Text = S"アップロード";
			this->CUpLoad1->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CUpLoad1_LinkClicked);
			// 
			// groupBox21
			// 
			this->groupBox21->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox21->Location = System::Drawing::Point(24, 1264);
			this->groupBox21->Name = S"groupBox21";
			this->groupBox21->Size = System::Drawing::Size(448, 9);
			this->groupBox21->TabIndex = 104;
			this->groupBox21->TabStop = false;
			// 
			// groupBox20
			// 
			this->groupBox20->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox20->Location = System::Drawing::Point(24, 800);
			this->groupBox20->Name = S"groupBox20";
			this->groupBox20->Size = System::Drawing::Size(448, 9);
			this->groupBox20->TabIndex = 100;
			this->groupBox20->TabStop = false;
			// 
			// OFFSTime20
			// 
			this->OFFSTime20->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFSTime20->Location = System::Drawing::Point(296, 784);
			this->OFFSTime20->Name = S"OFFSTime20";
			this->OFFSTime20->Size = System::Drawing::Size(80, 19);
			this->OFFSTime20->TabIndex = 99;
			this->OFFSTime20->Text = S"0：0";
			this->OFFSTime20->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFStage20
			// 
			this->OFFStage20->AutoSize = true;
			this->OFFStage20->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFStage20->Location = System::Drawing::Point(32, 784);
			this->OFFStage20->Name = S"OFFStage20";
			this->OFFStage20->Size = System::Drawing::Size(86, 19);
			this->OFFStage20->TabIndex = 97;
			this->OFFStage20->Text = S"EXステージ7";
			// 
			// SUpLoad20
			// 
			this->SUpLoad20->AutoSize = true;
			this->SUpLoad20->Enabled = false;
			this->SUpLoad20->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SUpLoad20->Location = System::Drawing::Point(384, 784);
			this->SUpLoad20->Name = S"SUpLoad20";
			this->SUpLoad20->Size = System::Drawing::Size(77, 19);
			this->SUpLoad20->TabIndex = 96;
			this->SUpLoad20->TabStop = true;
			this->SUpLoad20->Text = S"アップロード";
			this->SUpLoad20->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SUpLoad20_LinkClicked);
			// 
			// OFFSTime19
			// 
			this->OFFSTime19->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFSTime19->Location = System::Drawing::Point(296, 744);
			this->OFFSTime19->Name = S"OFFSTime19";
			this->OFFSTime19->Size = System::Drawing::Size(80, 19);
			this->OFFSTime19->TabIndex = 95;
			this->OFFSTime19->Text = S"0：0";
			this->OFFSTime19->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFStage19
			// 
			this->OFFStage19->AutoSize = true;
			this->OFFStage19->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFStage19->Location = System::Drawing::Point(32, 744);
			this->OFFStage19->Name = S"OFFStage19";
			this->OFFStage19->Size = System::Drawing::Size(86, 19);
			this->OFFStage19->TabIndex = 92;
			this->OFFStage19->Text = S"EXステージ6";
			// 
			// SUpLoad19
			// 
			this->SUpLoad19->AutoSize = true;
			this->SUpLoad19->Enabled = false;
			this->SUpLoad19->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SUpLoad19->Location = System::Drawing::Point(384, 744);
			this->SUpLoad19->Name = S"SUpLoad19";
			this->SUpLoad19->Size = System::Drawing::Size(77, 19);
			this->SUpLoad19->TabIndex = 91;
			this->SUpLoad19->TabStop = true;
			this->SUpLoad19->Text = S"アップロード";
			this->SUpLoad19->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SUpLoad19_LinkClicked);
			// 
			// groupBox11
			// 
			this->groupBox11->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox11->Location = System::Drawing::Point(24, 760);
			this->groupBox11->Name = S"groupBox11";
			this->groupBox11->Size = System::Drawing::Size(448, 9);
			this->groupBox11->TabIndex = 94;
			this->groupBox11->TabStop = false;
			// 
			// OFFSTime18
			// 
			this->OFFSTime18->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFSTime18->Location = System::Drawing::Point(296, 704);
			this->OFFSTime18->Name = S"OFFSTime18";
			this->OFFSTime18->Size = System::Drawing::Size(80, 19);
			this->OFFSTime18->TabIndex = 90;
			this->OFFSTime18->Text = S"0：0";
			this->OFFSTime18->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFStage18
			// 
			this->OFFStage18->AutoSize = true;
			this->OFFStage18->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFStage18->Location = System::Drawing::Point(32, 704);
			this->OFFStage18->Name = S"OFFStage18";
			this->OFFStage18->Size = System::Drawing::Size(86, 19);
			this->OFFStage18->TabIndex = 87;
			this->OFFStage18->Text = S"EXステージ5";
			// 
			// SUpLoad18
			// 
			this->SUpLoad18->AutoSize = true;
			this->SUpLoad18->Enabled = false;
			this->SUpLoad18->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SUpLoad18->Location = System::Drawing::Point(384, 704);
			this->SUpLoad18->Name = S"SUpLoad18";
			this->SUpLoad18->Size = System::Drawing::Size(77, 19);
			this->SUpLoad18->TabIndex = 86;
			this->SUpLoad18->TabStop = true;
			this->SUpLoad18->Text = S"アップロード";
			this->SUpLoad18->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SUpLoad18_LinkClicked);
			// 
			// groupBox12
			// 
			this->groupBox12->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox12->Location = System::Drawing::Point(24, 720);
			this->groupBox12->Name = S"groupBox12";
			this->groupBox12->Size = System::Drawing::Size(448, 9);
			this->groupBox12->TabIndex = 89;
			this->groupBox12->TabStop = false;
			// 
			// OFFSTime17
			// 
			this->OFFSTime17->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFSTime17->Location = System::Drawing::Point(296, 664);
			this->OFFSTime17->Name = S"OFFSTime17";
			this->OFFSTime17->Size = System::Drawing::Size(80, 19);
			this->OFFSTime17->TabIndex = 85;
			this->OFFSTime17->Text = S"0：0";
			this->OFFSTime17->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFStage17
			// 
			this->OFFStage17->AutoSize = true;
			this->OFFStage17->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFStage17->Location = System::Drawing::Point(32, 664);
			this->OFFStage17->Name = S"OFFStage17";
			this->OFFStage17->Size = System::Drawing::Size(86, 19);
			this->OFFStage17->TabIndex = 82;
			this->OFFStage17->Text = S"EXステージ4";
			// 
			// SUpLoad17
			// 
			this->SUpLoad17->AutoSize = true;
			this->SUpLoad17->Enabled = false;
			this->SUpLoad17->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SUpLoad17->Location = System::Drawing::Point(384, 664);
			this->SUpLoad17->Name = S"SUpLoad17";
			this->SUpLoad17->Size = System::Drawing::Size(77, 19);
			this->SUpLoad17->TabIndex = 81;
			this->SUpLoad17->TabStop = true;
			this->SUpLoad17->Text = S"アップロード";
			this->SUpLoad17->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SUpLoad17_LinkClicked);
			// 
			// groupBox13
			// 
			this->groupBox13->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox13->Location = System::Drawing::Point(24, 680);
			this->groupBox13->Name = S"groupBox13";
			this->groupBox13->Size = System::Drawing::Size(448, 9);
			this->groupBox13->TabIndex = 84;
			this->groupBox13->TabStop = false;
			// 
			// OFFSTime16
			// 
			this->OFFSTime16->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFSTime16->Location = System::Drawing::Point(296, 624);
			this->OFFSTime16->Name = S"OFFSTime16";
			this->OFFSTime16->Size = System::Drawing::Size(80, 19);
			this->OFFSTime16->TabIndex = 80;
			this->OFFSTime16->Text = S"0：0";
			this->OFFSTime16->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFStage16
			// 
			this->OFFStage16->AutoSize = true;
			this->OFFStage16->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFStage16->Location = System::Drawing::Point(32, 624);
			this->OFFStage16->Name = S"OFFStage16";
			this->OFFStage16->Size = System::Drawing::Size(86, 19);
			this->OFFStage16->TabIndex = 77;
			this->OFFStage16->Text = S"EXステージ3";
			// 
			// SUpLoad16
			// 
			this->SUpLoad16->AutoSize = true;
			this->SUpLoad16->Enabled = false;
			this->SUpLoad16->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SUpLoad16->Location = System::Drawing::Point(384, 624);
			this->SUpLoad16->Name = S"SUpLoad16";
			this->SUpLoad16->Size = System::Drawing::Size(77, 19);
			this->SUpLoad16->TabIndex = 76;
			this->SUpLoad16->TabStop = true;
			this->SUpLoad16->Text = S"アップロード";
			this->SUpLoad16->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SUpLoad16_LinkClicked);
			// 
			// groupBox14
			// 
			this->groupBox14->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox14->Location = System::Drawing::Point(24, 640);
			this->groupBox14->Name = S"groupBox14";
			this->groupBox14->Size = System::Drawing::Size(448, 9);
			this->groupBox14->TabIndex = 79;
			this->groupBox14->TabStop = false;
			// 
			// OFFSTime15
			// 
			this->OFFSTime15->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFSTime15->Location = System::Drawing::Point(296, 584);
			this->OFFSTime15->Name = S"OFFSTime15";
			this->OFFSTime15->Size = System::Drawing::Size(80, 19);
			this->OFFSTime15->TabIndex = 75;
			this->OFFSTime15->Text = S"0：0";
			this->OFFSTime15->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFStage15
			// 
			this->OFFStage15->AutoSize = true;
			this->OFFStage15->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFStage15->Location = System::Drawing::Point(32, 584);
			this->OFFStage15->Name = S"OFFStage15";
			this->OFFStage15->Size = System::Drawing::Size(86, 19);
			this->OFFStage15->TabIndex = 72;
			this->OFFStage15->Text = S"EXステージ2";
			// 
			// SUpLoad15
			// 
			this->SUpLoad15->AutoSize = true;
			this->SUpLoad15->Enabled = false;
			this->SUpLoad15->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SUpLoad15->Location = System::Drawing::Point(384, 584);
			this->SUpLoad15->Name = S"SUpLoad15";
			this->SUpLoad15->Size = System::Drawing::Size(77, 19);
			this->SUpLoad15->TabIndex = 71;
			this->SUpLoad15->TabStop = true;
			this->SUpLoad15->Text = S"アップロード";
			this->SUpLoad15->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SUpLoad15_LinkClicked);
			// 
			// groupBox15
			// 
			this->groupBox15->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox15->Location = System::Drawing::Point(24, 600);
			this->groupBox15->Name = S"groupBox15";
			this->groupBox15->Size = System::Drawing::Size(448, 9);
			this->groupBox15->TabIndex = 74;
			this->groupBox15->TabStop = false;
			// 
			// OFFSTime14
			// 
			this->OFFSTime14->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFSTime14->Location = System::Drawing::Point(296, 544);
			this->OFFSTime14->Name = S"OFFSTime14";
			this->OFFSTime14->Size = System::Drawing::Size(80, 19);
			this->OFFSTime14->TabIndex = 70;
			this->OFFSTime14->Text = S"0：0";
			this->OFFSTime14->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFStage14
			// 
			this->OFFStage14->AutoSize = true;
			this->OFFStage14->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFStage14->Location = System::Drawing::Point(32, 544);
			this->OFFStage14->Name = S"OFFStage14";
			this->OFFStage14->Size = System::Drawing::Size(86, 19);
			this->OFFStage14->TabIndex = 67;
			this->OFFStage14->Text = S"EXステージ1";
			// 
			// SUpLoad14
			// 
			this->SUpLoad14->AutoSize = true;
			this->SUpLoad14->Enabled = false;
			this->SUpLoad14->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SUpLoad14->Location = System::Drawing::Point(384, 544);
			this->SUpLoad14->Name = S"SUpLoad14";
			this->SUpLoad14->Size = System::Drawing::Size(77, 19);
			this->SUpLoad14->TabIndex = 66;
			this->SUpLoad14->TabStop = true;
			this->SUpLoad14->Text = S"アップロード";
			this->SUpLoad14->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SUpLoad14_LinkClicked);
			// 
			// groupBox16
			// 
			this->groupBox16->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox16->Location = System::Drawing::Point(24, 560);
			this->groupBox16->Name = S"groupBox16";
			this->groupBox16->Size = System::Drawing::Size(448, 9);
			this->groupBox16->TabIndex = 69;
			this->groupBox16->TabStop = false;
			// 
			// OFFSTime13
			// 
			this->OFFSTime13->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFSTime13->Location = System::Drawing::Point(296, 504);
			this->OFFSTime13->Name = S"OFFSTime13";
			this->OFFSTime13->Size = System::Drawing::Size(80, 19);
			this->OFFSTime13->TabIndex = 65;
			this->OFFSTime13->Text = S"0：0";
			this->OFFSTime13->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFStage13
			// 
			this->OFFStage13->AutoSize = true;
			this->OFFStage13->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFStage13->Location = System::Drawing::Point(32, 504);
			this->OFFStage13->Name = S"OFFStage13";
			this->OFFStage13->Size = System::Drawing::Size(75, 19);
			this->OFFStage13->TabIndex = 62;
			this->OFFStage13->Text = S"ステージ13";
			// 
			// SUpLoad13
			// 
			this->SUpLoad13->AutoSize = true;
			this->SUpLoad13->Enabled = false;
			this->SUpLoad13->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SUpLoad13->Location = System::Drawing::Point(384, 504);
			this->SUpLoad13->Name = S"SUpLoad13";
			this->SUpLoad13->Size = System::Drawing::Size(77, 19);
			this->SUpLoad13->TabIndex = 61;
			this->SUpLoad13->TabStop = true;
			this->SUpLoad13->Text = S"アップロード";
			this->SUpLoad13->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SUpLoad13_LinkClicked);
			// 
			// groupBox17
			// 
			this->groupBox17->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox17->Location = System::Drawing::Point(24, 520);
			this->groupBox17->Name = S"groupBox17";
			this->groupBox17->Size = System::Drawing::Size(448, 9);
			this->groupBox17->TabIndex = 64;
			this->groupBox17->TabStop = false;
			// 
			// OFFSTime12
			// 
			this->OFFSTime12->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFSTime12->Location = System::Drawing::Point(296, 464);
			this->OFFSTime12->Name = S"OFFSTime12";
			this->OFFSTime12->Size = System::Drawing::Size(80, 19);
			this->OFFSTime12->TabIndex = 60;
			this->OFFSTime12->Text = S"0：0";
			this->OFFSTime12->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFStage12
			// 
			this->OFFStage12->AutoSize = true;
			this->OFFStage12->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFStage12->Location = System::Drawing::Point(32, 464);
			this->OFFStage12->Name = S"OFFStage12";
			this->OFFStage12->Size = System::Drawing::Size(75, 19);
			this->OFFStage12->TabIndex = 57;
			this->OFFStage12->Text = S"ステージ12";
			// 
			// SUpLoad12
			// 
			this->SUpLoad12->AutoSize = true;
			this->SUpLoad12->Enabled = false;
			this->SUpLoad12->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SUpLoad12->Location = System::Drawing::Point(384, 464);
			this->SUpLoad12->Name = S"SUpLoad12";
			this->SUpLoad12->Size = System::Drawing::Size(77, 19);
			this->SUpLoad12->TabIndex = 56;
			this->SUpLoad12->TabStop = true;
			this->SUpLoad12->Text = S"アップロード";
			this->SUpLoad12->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SUpLoad12_LinkClicked);
			// 
			// groupBox18
			// 
			this->groupBox18->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox18->Location = System::Drawing::Point(24, 480);
			this->groupBox18->Name = S"groupBox18";
			this->groupBox18->Size = System::Drawing::Size(448, 9);
			this->groupBox18->TabIndex = 59;
			this->groupBox18->TabStop = false;
			// 
			// OFFSTime11
			// 
			this->OFFSTime11->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFSTime11->Location = System::Drawing::Point(296, 424);
			this->OFFSTime11->Name = S"OFFSTime11";
			this->OFFSTime11->Size = System::Drawing::Size(80, 19);
			this->OFFSTime11->TabIndex = 55;
			this->OFFSTime11->Text = S"0：0";
			this->OFFSTime11->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFStage11
			// 
			this->OFFStage11->AutoSize = true;
			this->OFFStage11->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFStage11->Location = System::Drawing::Point(32, 424);
			this->OFFStage11->Name = S"OFFStage11";
			this->OFFStage11->Size = System::Drawing::Size(75, 19);
			this->OFFStage11->TabIndex = 52;
			this->OFFStage11->Text = S"ステージ11";
			// 
			// SUpLoad11
			// 
			this->SUpLoad11->AutoSize = true;
			this->SUpLoad11->Enabled = false;
			this->SUpLoad11->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SUpLoad11->Location = System::Drawing::Point(384, 424);
			this->SUpLoad11->Name = S"SUpLoad11";
			this->SUpLoad11->Size = System::Drawing::Size(77, 19);
			this->SUpLoad11->TabIndex = 51;
			this->SUpLoad11->TabStop = true;
			this->SUpLoad11->Text = S"アップロード";
			this->SUpLoad11->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SUpLoad11_LinkClicked);
			// 
			// groupBox19
			// 
			this->groupBox19->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox19->Location = System::Drawing::Point(24, 440);
			this->groupBox19->Name = S"groupBox19";
			this->groupBox19->Size = System::Drawing::Size(448, 9);
			this->groupBox19->TabIndex = 54;
			this->groupBox19->TabStop = false;
			// 
			// OFFSTime10
			// 
			this->OFFSTime10->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFSTime10->Location = System::Drawing::Point(296, 384);
			this->OFFSTime10->Name = S"OFFSTime10";
			this->OFFSTime10->Size = System::Drawing::Size(80, 19);
			this->OFFSTime10->TabIndex = 50;
			this->OFFSTime10->Text = S"0：0";
			this->OFFSTime10->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFStage10
			// 
			this->OFFStage10->AutoSize = true;
			this->OFFStage10->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFStage10->Location = System::Drawing::Point(32, 384);
			this->OFFStage10->Name = S"OFFStage10";
			this->OFFStage10->Size = System::Drawing::Size(75, 19);
			this->OFFStage10->TabIndex = 47;
			this->OFFStage10->Text = S"ステージ10";
			// 
			// SUpLoad10
			// 
			this->SUpLoad10->AutoSize = true;
			this->SUpLoad10->Enabled = false;
			this->SUpLoad10->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SUpLoad10->Location = System::Drawing::Point(384, 384);
			this->SUpLoad10->Name = S"SUpLoad10";
			this->SUpLoad10->Size = System::Drawing::Size(77, 19);
			this->SUpLoad10->TabIndex = 46;
			this->SUpLoad10->TabStop = true;
			this->SUpLoad10->Text = S"アップロード";
			this->SUpLoad10->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SUpLoad10_LinkClicked);
			// 
			// groupBox10
			// 
			this->groupBox10->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox10->Location = System::Drawing::Point(24, 400);
			this->groupBox10->Name = S"groupBox10";
			this->groupBox10->Size = System::Drawing::Size(448, 9);
			this->groupBox10->TabIndex = 49;
			this->groupBox10->TabStop = false;
			// 
			// OFFSTime9
			// 
			this->OFFSTime9->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFSTime9->Location = System::Drawing::Point(296, 344);
			this->OFFSTime9->Name = S"OFFSTime9";
			this->OFFSTime9->Size = System::Drawing::Size(80, 19);
			this->OFFSTime9->TabIndex = 45;
			this->OFFSTime9->Text = S"0：0";
			this->OFFSTime9->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFStage9
			// 
			this->OFFStage9->AutoSize = true;
			this->OFFStage9->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFStage9->Location = System::Drawing::Point(32, 344);
			this->OFFStage9->Name = S"OFFStage9";
			this->OFFStage9->Size = System::Drawing::Size(66, 19);
			this->OFFStage9->TabIndex = 42;
			this->OFFStage9->Text = S"ステージ9";
			// 
			// SUpLoad9
			// 
			this->SUpLoad9->AutoSize = true;
			this->SUpLoad9->Enabled = false;
			this->SUpLoad9->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SUpLoad9->Location = System::Drawing::Point(384, 344);
			this->SUpLoad9->Name = S"SUpLoad9";
			this->SUpLoad9->Size = System::Drawing::Size(77, 19);
			this->SUpLoad9->TabIndex = 41;
			this->SUpLoad9->TabStop = true;
			this->SUpLoad9->Text = S"アップロード";
			this->SUpLoad9->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SUpLoad9_LinkClicked);
			// 
			// groupBox9
			// 
			this->groupBox9->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox9->Location = System::Drawing::Point(24, 360);
			this->groupBox9->Name = S"groupBox9";
			this->groupBox9->Size = System::Drawing::Size(448, 9);
			this->groupBox9->TabIndex = 44;
			this->groupBox9->TabStop = false;
			// 
			// OFFSTime8
			// 
			this->OFFSTime8->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFSTime8->Location = System::Drawing::Point(296, 304);
			this->OFFSTime8->Name = S"OFFSTime8";
			this->OFFSTime8->Size = System::Drawing::Size(80, 19);
			this->OFFSTime8->TabIndex = 40;
			this->OFFSTime8->Text = S"0：0";
			this->OFFSTime8->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFStage8
			// 
			this->OFFStage8->AutoSize = true;
			this->OFFStage8->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFStage8->Location = System::Drawing::Point(32, 304);
			this->OFFStage8->Name = S"OFFStage8";
			this->OFFStage8->Size = System::Drawing::Size(66, 19);
			this->OFFStage8->TabIndex = 37;
			this->OFFStage8->Text = S"ステージ8";
			// 
			// SUpLoad8
			// 
			this->SUpLoad8->AutoSize = true;
			this->SUpLoad8->Enabled = false;
			this->SUpLoad8->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SUpLoad8->Location = System::Drawing::Point(384, 304);
			this->SUpLoad8->Name = S"SUpLoad8";
			this->SUpLoad8->Size = System::Drawing::Size(77, 19);
			this->SUpLoad8->TabIndex = 36;
			this->SUpLoad8->TabStop = true;
			this->SUpLoad8->Text = S"アップロード";
			this->SUpLoad8->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SUpLoad8_LinkClicked);
			// 
			// groupBox8
			// 
			this->groupBox8->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox8->Location = System::Drawing::Point(24, 320);
			this->groupBox8->Name = S"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(448, 9);
			this->groupBox8->TabIndex = 39;
			this->groupBox8->TabStop = false;
			// 
			// OFFSTime7
			// 
			this->OFFSTime7->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFSTime7->Location = System::Drawing::Point(296, 264);
			this->OFFSTime7->Name = S"OFFSTime7";
			this->OFFSTime7->Size = System::Drawing::Size(80, 19);
			this->OFFSTime7->TabIndex = 35;
			this->OFFSTime7->Text = S"0：0";
			this->OFFSTime7->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFStage7
			// 
			this->OFFStage7->AutoSize = true;
			this->OFFStage7->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFStage7->Location = System::Drawing::Point(32, 264);
			this->OFFStage7->Name = S"OFFStage7";
			this->OFFStage7->Size = System::Drawing::Size(66, 19);
			this->OFFStage7->TabIndex = 32;
			this->OFFStage7->Text = S"ステージ7";
			// 
			// SUpLoad7
			// 
			this->SUpLoad7->AutoSize = true;
			this->SUpLoad7->Enabled = false;
			this->SUpLoad7->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SUpLoad7->Location = System::Drawing::Point(384, 264);
			this->SUpLoad7->Name = S"SUpLoad7";
			this->SUpLoad7->Size = System::Drawing::Size(77, 19);
			this->SUpLoad7->TabIndex = 31;
			this->SUpLoad7->TabStop = true;
			this->SUpLoad7->Text = S"アップロード";
			this->SUpLoad7->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SUpLoad7_LinkClicked);
			// 
			// groupBox7
			// 
			this->groupBox7->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox7->Location = System::Drawing::Point(24, 280);
			this->groupBox7->Name = S"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(448, 9);
			this->groupBox7->TabIndex = 34;
			this->groupBox7->TabStop = false;
			// 
			// OFFSTime6
			// 
			this->OFFSTime6->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFSTime6->Location = System::Drawing::Point(296, 224);
			this->OFFSTime6->Name = S"OFFSTime6";
			this->OFFSTime6->Size = System::Drawing::Size(80, 19);
			this->OFFSTime6->TabIndex = 30;
			this->OFFSTime6->Text = S"0：0";
			this->OFFSTime6->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFStage6
			// 
			this->OFFStage6->AutoSize = true;
			this->OFFStage6->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFStage6->Location = System::Drawing::Point(32, 224);
			this->OFFStage6->Name = S"OFFStage6";
			this->OFFStage6->Size = System::Drawing::Size(66, 19);
			this->OFFStage6->TabIndex = 27;
			this->OFFStage6->Text = S"ステージ6";
			// 
			// SUpLoad6
			// 
			this->SUpLoad6->AutoSize = true;
			this->SUpLoad6->Enabled = false;
			this->SUpLoad6->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SUpLoad6->Location = System::Drawing::Point(384, 224);
			this->SUpLoad6->Name = S"SUpLoad6";
			this->SUpLoad6->Size = System::Drawing::Size(77, 19);
			this->SUpLoad6->TabIndex = 26;
			this->SUpLoad6->TabStop = true;
			this->SUpLoad6->Text = S"アップロード";
			this->SUpLoad6->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SUpLoad6_LinkClicked);
			// 
			// groupBox6
			// 
			this->groupBox6->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox6->Location = System::Drawing::Point(24, 240);
			this->groupBox6->Name = S"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(448, 9);
			this->groupBox6->TabIndex = 29;
			this->groupBox6->TabStop = false;
			// 
			// OFFSTime5
			// 
			this->OFFSTime5->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFSTime5->Location = System::Drawing::Point(296, 184);
			this->OFFSTime5->Name = S"OFFSTime5";
			this->OFFSTime5->Size = System::Drawing::Size(80, 19);
			this->OFFSTime5->TabIndex = 25;
			this->OFFSTime5->Text = S"0：0";
			this->OFFSTime5->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFStage5
			// 
			this->OFFStage5->AutoSize = true;
			this->OFFStage5->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFStage5->Location = System::Drawing::Point(32, 184);
			this->OFFStage5->Name = S"OFFStage5";
			this->OFFStage5->Size = System::Drawing::Size(66, 19);
			this->OFFStage5->TabIndex = 22;
			this->OFFStage5->Text = S"ステージ5";
			// 
			// SUpLoad5
			// 
			this->SUpLoad5->AutoSize = true;
			this->SUpLoad5->Enabled = false;
			this->SUpLoad5->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SUpLoad5->Location = System::Drawing::Point(384, 184);
			this->SUpLoad5->Name = S"SUpLoad5";
			this->SUpLoad5->Size = System::Drawing::Size(77, 19);
			this->SUpLoad5->TabIndex = 21;
			this->SUpLoad5->TabStop = true;
			this->SUpLoad5->Text = S"アップロード";
			this->SUpLoad5->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SUpLoad5_LinkClicked);
			// 
			// groupBox5
			// 
			this->groupBox5->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox5->Location = System::Drawing::Point(24, 200);
			this->groupBox5->Name = S"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(448, 9);
			this->groupBox5->TabIndex = 24;
			this->groupBox5->TabStop = false;
			// 
			// OFFSTime4
			// 
			this->OFFSTime4->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFSTime4->Location = System::Drawing::Point(296, 144);
			this->OFFSTime4->Name = S"OFFSTime4";
			this->OFFSTime4->Size = System::Drawing::Size(80, 19);
			this->OFFSTime4->TabIndex = 20;
			this->OFFSTime4->Text = S"0：0";
			this->OFFSTime4->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFStage4
			// 
			this->OFFStage4->AutoSize = true;
			this->OFFStage4->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFStage4->Location = System::Drawing::Point(32, 144);
			this->OFFStage4->Name = S"OFFStage4";
			this->OFFStage4->Size = System::Drawing::Size(66, 19);
			this->OFFStage4->TabIndex = 17;
			this->OFFStage4->Text = S"ステージ4";
			// 
			// SUpLoad4
			// 
			this->SUpLoad4->AutoSize = true;
			this->SUpLoad4->Enabled = false;
			this->SUpLoad4->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SUpLoad4->Location = System::Drawing::Point(384, 144);
			this->SUpLoad4->Name = S"SUpLoad4";
			this->SUpLoad4->Size = System::Drawing::Size(77, 19);
			this->SUpLoad4->TabIndex = 16;
			this->SUpLoad4->TabStop = true;
			this->SUpLoad4->Text = S"アップロード";
			this->SUpLoad4->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SUpLoad4_LinkClicked);
			// 
			// groupBox4
			// 
			this->groupBox4->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox4->Location = System::Drawing::Point(24, 160);
			this->groupBox4->Name = S"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(448, 9);
			this->groupBox4->TabIndex = 19;
			this->groupBox4->TabStop = false;
			// 
			// OFFSTime3
			// 
			this->OFFSTime3->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFSTime3->Location = System::Drawing::Point(296, 104);
			this->OFFSTime3->Name = S"OFFSTime3";
			this->OFFSTime3->Size = System::Drawing::Size(80, 19);
			this->OFFSTime3->TabIndex = 15;
			this->OFFSTime3->Text = S"0：0";
			this->OFFSTime3->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFStage3
			// 
			this->OFFStage3->AutoSize = true;
			this->OFFStage3->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFStage3->Location = System::Drawing::Point(32, 104);
			this->OFFStage3->Name = S"OFFStage3";
			this->OFFStage3->Size = System::Drawing::Size(66, 19);
			this->OFFStage3->TabIndex = 12;
			this->OFFStage3->Text = S"ステージ3";
			// 
			// SUpLoad3
			// 
			this->SUpLoad3->AutoSize = true;
			this->SUpLoad3->Enabled = false;
			this->SUpLoad3->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SUpLoad3->Location = System::Drawing::Point(384, 104);
			this->SUpLoad3->Name = S"SUpLoad3";
			this->SUpLoad3->Size = System::Drawing::Size(77, 19);
			this->SUpLoad3->TabIndex = 11;
			this->SUpLoad3->TabStop = true;
			this->SUpLoad3->Text = S"アップロード";
			this->SUpLoad3->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SUpLoad3_LinkClicked);
			// 
			// groupBox3
			// 
			this->groupBox3->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox3->Location = System::Drawing::Point(24, 120);
			this->groupBox3->Name = S"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(448, 9);
			this->groupBox3->TabIndex = 14;
			this->groupBox3->TabStop = false;
			// 
			// OFFSTime2
			// 
			this->OFFSTime2->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFSTime2->Location = System::Drawing::Point(296, 64);
			this->OFFSTime2->Name = S"OFFSTime2";
			this->OFFSTime2->Size = System::Drawing::Size(80, 19);
			this->OFFSTime2->TabIndex = 10;
			this->OFFSTime2->Text = S"0：0";
			this->OFFSTime2->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFStage2
			// 
			this->OFFStage2->AutoSize = true;
			this->OFFStage2->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFStage2->Location = System::Drawing::Point(32, 64);
			this->OFFStage2->Name = S"OFFStage2";
			this->OFFStage2->Size = System::Drawing::Size(66, 19);
			this->OFFStage2->TabIndex = 7;
			this->OFFStage2->Text = S"ステージ2";
			// 
			// SUpLoad2
			// 
			this->SUpLoad2->AutoSize = true;
			this->SUpLoad2->Enabled = false;
			this->SUpLoad2->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SUpLoad2->Location = System::Drawing::Point(384, 64);
			this->SUpLoad2->Name = S"SUpLoad2";
			this->SUpLoad2->Size = System::Drawing::Size(77, 19);
			this->SUpLoad2->TabIndex = 6;
			this->SUpLoad2->TabStop = true;
			this->SUpLoad2->Text = S"アップロード";
			this->SUpLoad2->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SUpLoad2_LinkClicked);
			// 
			// groupBox2
			// 
			this->groupBox2->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox2->Location = System::Drawing::Point(24, 80);
			this->groupBox2->Name = S"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(448, 9);
			this->groupBox2->TabIndex = 9;
			this->groupBox2->TabStop = false;
			// 
			// OFFSTime1
			// 
			this->OFFSTime1->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFSTime1->Location = System::Drawing::Point(296, 24);
			this->OFFSTime1->Name = S"OFFSTime1";
			this->OFFSTime1->Size = System::Drawing::Size(80, 19);
			this->OFFSTime1->TabIndex = 5;
			this->OFFSTime1->Text = S"0：0";
			this->OFFSTime1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFStage1
			// 
			this->OFFStage1->AutoSize = true;
			this->OFFStage1->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFStage1->Location = System::Drawing::Point(32, 24);
			this->OFFStage1->Name = S"OFFStage1";
			this->OFFStage1->Size = System::Drawing::Size(66, 19);
			this->OFFStage1->TabIndex = 2;
			this->OFFStage1->Text = S"ステージ1";
			// 
			// SUpLoad1
			// 
			this->SUpLoad1->AutoSize = true;
			this->SUpLoad1->Enabled = false;
			this->SUpLoad1->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SUpLoad1->Location = System::Drawing::Point(384, 24);
			this->SUpLoad1->Name = S"SUpLoad1";
			this->SUpLoad1->Size = System::Drawing::Size(77, 19);
			this->SUpLoad1->TabIndex = 1;
			this->SUpLoad1->TabStop = true;
			this->SUpLoad1->Text = S"アップロード";
			this->SUpLoad1->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SUpLoad1_LinkClicked);
			// 
			// groupBox1
			// 
			this->groupBox1->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox1->Location = System::Drawing::Point(24, 40);
			this->groupBox1->Name = S"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(448, 9);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			// 
			// OFFCTime6
			// 
			this->OFFCTime6->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFCTime6->Location = System::Drawing::Point(296, 1448);
			this->OFFCTime6->Name = S"OFFCTime6";
			this->OFFCTime6->Size = System::Drawing::Size(80, 19);
			this->OFFCTime6->TabIndex = 130;
			this->OFFCTime6->Text = S"0：0";
			this->OFFCTime6->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFCTime5
			// 
			this->OFFCTime5->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFCTime5->Location = System::Drawing::Point(296, 1408);
			this->OFFCTime5->Name = S"OFFCTime5";
			this->OFFCTime5->Size = System::Drawing::Size(80, 19);
			this->OFFCTime5->TabIndex = 125;
			this->OFFCTime5->Text = S"0：0";
			this->OFFCTime5->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFCTime4
			// 
			this->OFFCTime4->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFCTime4->Location = System::Drawing::Point(296, 1368);
			this->OFFCTime4->Name = S"OFFCTime4";
			this->OFFCTime4->Size = System::Drawing::Size(80, 19);
			this->OFFCTime4->TabIndex = 120;
			this->OFFCTime4->Text = S"0：0";
			this->OFFCTime4->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFCTime3
			// 
			this->OFFCTime3->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFCTime3->Location = System::Drawing::Point(296, 1328);
			this->OFFCTime3->Name = S"OFFCTime3";
			this->OFFCTime3->Size = System::Drawing::Size(80, 19);
			this->OFFCTime3->TabIndex = 115;
			this->OFFCTime3->Text = S"0：0";
			this->OFFCTime3->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFCTime2
			// 
			this->OFFCTime2->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFCTime2->Location = System::Drawing::Point(296, 1288);
			this->OFFCTime2->Name = S"OFFCTime2";
			this->OFFCTime2->Size = System::Drawing::Size(80, 19);
			this->OFFCTime2->TabIndex = 110;
			this->OFFCTime2->Text = S"0：0";
			this->OFFCTime2->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// OFFCTime1
			// 
			this->OFFCTime1->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->OFFCTime1->Location = System::Drawing::Point(296, 1248);
			this->OFFCTime1->Name = S"OFFCTime1";
			this->OFFCTime1->Size = System::Drawing::Size(80, 19);
			this->OFFCTime1->TabIndex = 105;
			this->OFFCTime1->Text = S"0：0";
			this->OFFCTime1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONPage
			// 
			this->ONPage->AutoScroll = true;
			this->ONPage->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->ONPage->Controls->Add(this->SName30);
			this->ONPage->Controls->Add(this->groupBox87);
			this->ONPage->Controls->Add(this->label32);
			this->ONPage->Controls->Add(this->SDownLoad30);
			this->ONPage->Controls->Add(this->ONSTime30);
			this->ONPage->Controls->Add(this->SName23);
			this->ONPage->Controls->Add(this->SName22);
			this->ONPage->Controls->Add(this->SName21);
			this->ONPage->Controls->Add(this->SName29);
			this->ONPage->Controls->Add(this->SName28);
			this->ONPage->Controls->Add(this->SName27);
			this->ONPage->Controls->Add(this->SName26);
			this->ONPage->Controls->Add(this->SName25);
			this->ONPage->Controls->Add(this->SName24);
			this->ONPage->Controls->Add(this->groupBox78);
			this->ONPage->Controls->Add(this->label11);
			this->ONPage->Controls->Add(this->SDownLoad29);
			this->ONPage->Controls->Add(this->label12);
			this->ONPage->Controls->Add(this->SDownLoad28);
			this->ONPage->Controls->Add(this->groupBox79);
			this->ONPage->Controls->Add(this->label13);
			this->ONPage->Controls->Add(this->SDownLoad27);
			this->ONPage->Controls->Add(this->groupBox80);
			this->ONPage->Controls->Add(this->label14);
			this->ONPage->Controls->Add(this->SDownLoad26);
			this->ONPage->Controls->Add(this->groupBox81);
			this->ONPage->Controls->Add(this->label15);
			this->ONPage->Controls->Add(this->SDownLoad25);
			this->ONPage->Controls->Add(this->groupBox82);
			this->ONPage->Controls->Add(this->label16);
			this->ONPage->Controls->Add(this->SDownLoad24);
			this->ONPage->Controls->Add(this->groupBox83);
			this->ONPage->Controls->Add(this->label17);
			this->ONPage->Controls->Add(this->SDownLoad23);
			this->ONPage->Controls->Add(this->groupBox84);
			this->ONPage->Controls->Add(this->label19);
			this->ONPage->Controls->Add(this->SDownLoad22);
			this->ONPage->Controls->Add(this->groupBox85);
			this->ONPage->Controls->Add(this->label20);
			this->ONPage->Controls->Add(this->SDownLoad21);
			this->ONPage->Controls->Add(this->groupBox86);
			this->ONPage->Controls->Add(this->ONSTime29);
			this->ONPage->Controls->Add(this->ONSTime28);
			this->ONPage->Controls->Add(this->ONSTime27);
			this->ONPage->Controls->Add(this->ONSTime26);
			this->ONPage->Controls->Add(this->ONSTime25);
			this->ONPage->Controls->Add(this->ONSTime24);
			this->ONPage->Controls->Add(this->ONSTime23);
			this->ONPage->Controls->Add(this->ONSTime22);
			this->ONPage->Controls->Add(this->ONSTime21);
			this->ONPage->Controls->Add(this->SName6);
			this->ONPage->Controls->Add(this->SName5);
			this->ONPage->Controls->Add(this->SName4);
			this->ONPage->Controls->Add(this->SName3);
			this->ONPage->Controls->Add(this->SName2);
			this->ONPage->Controls->Add(this->SName1);
			this->ONPage->Controls->Add(this->SName8);
			this->ONPage->Controls->Add(this->SName7);
			this->ONPage->Controls->Add(this->SName14);
			this->ONPage->Controls->Add(this->SName13);
			this->ONPage->Controls->Add(this->SName12);
			this->ONPage->Controls->Add(this->SName11);
			this->ONPage->Controls->Add(this->SName10);
			this->ONPage->Controls->Add(this->SName9);
			this->ONPage->Controls->Add(this->SName20);
			this->ONPage->Controls->Add(this->SName19);
			this->ONPage->Controls->Add(this->SName18);
			this->ONPage->Controls->Add(this->SName17);
			this->ONPage->Controls->Add(this->SName16);
			this->ONPage->Controls->Add(this->SName15);
			this->ONPage->Controls->Add(this->CName12);
			this->ONPage->Controls->Add(this->CName11);
			this->ONPage->Controls->Add(this->CName10);
			this->ONPage->Controls->Add(this->CName9);
			this->ONPage->Controls->Add(this->CName8);
			this->ONPage->Controls->Add(this->CName7);
			this->ONPage->Controls->Add(this->CName6);
			this->ONPage->Controls->Add(this->CName5);
			this->ONPage->Controls->Add(this->CName4);
			this->ONPage->Controls->Add(this->CName3);
			this->ONPage->Controls->Add(this->CName2);
			this->ONPage->Controls->Add(this->groupBox34);
			this->ONPage->Controls->Add(this->Char12);
			this->ONPage->Controls->Add(this->label69);
			this->ONPage->Controls->Add(this->CDownLoad12);
			this->ONPage->Controls->Add(this->groupBox35);
			this->ONPage->Controls->Add(this->Char11);
			this->ONPage->Controls->Add(this->label72);
			this->ONPage->Controls->Add(this->CDownLoad11);
			this->ONPage->Controls->Add(this->groupBox36);
			this->ONPage->Controls->Add(this->Char10);
			this->ONPage->Controls->Add(this->label75);
			this->ONPage->Controls->Add(this->CDownLoad10);
			this->ONPage->Controls->Add(this->groupBox37);
			this->ONPage->Controls->Add(this->Char9);
			this->ONPage->Controls->Add(this->label78);
			this->ONPage->Controls->Add(this->CDownLoad9);
			this->ONPage->Controls->Add(this->groupBox38);
			this->ONPage->Controls->Add(this->Char8);
			this->ONPage->Controls->Add(this->label81);
			this->ONPage->Controls->Add(this->CDownLoad8);
			this->ONPage->Controls->Add(this->groupBox39);
			this->ONPage->Controls->Add(this->Char7);
			this->ONPage->Controls->Add(this->label84);
			this->ONPage->Controls->Add(this->CDownLoad7);
			this->ONPage->Controls->Add(this->groupBox40);
			this->ONPage->Controls->Add(this->Char6);
			this->ONPage->Controls->Add(this->label87);
			this->ONPage->Controls->Add(this->CDownLoad6);
			this->ONPage->Controls->Add(this->groupBox41);
			this->ONPage->Controls->Add(this->Char5);
			this->ONPage->Controls->Add(this->label90);
			this->ONPage->Controls->Add(this->CDownLoad5);
			this->ONPage->Controls->Add(this->groupBox42);
			this->ONPage->Controls->Add(this->Char4);
			this->ONPage->Controls->Add(this->label93);
			this->ONPage->Controls->Add(this->CDownLoad4);
			this->ONPage->Controls->Add(this->groupBox43);
			this->ONPage->Controls->Add(this->Char3);
			this->ONPage->Controls->Add(this->label96);
			this->ONPage->Controls->Add(this->CDownLoad3);
			this->ONPage->Controls->Add(this->groupBox44);
			this->ONPage->Controls->Add(this->Char2);
			this->ONPage->Controls->Add(this->label99);
			this->ONPage->Controls->Add(this->CDownLoad2);
			this->ONPage->Controls->Add(this->groupBox45);
			this->ONPage->Controls->Add(this->Char1);
			this->ONPage->Controls->Add(this->label102);
			this->ONPage->Controls->Add(this->CDownLoad1);
			this->ONPage->Controls->Add(this->groupBox46);
			this->ONPage->Controls->Add(this->groupBox47);
			this->ONPage->Controls->Add(this->label104);
			this->ONPage->Controls->Add(this->SDownLoad20);
			this->ONPage->Controls->Add(this->label106);
			this->ONPage->Controls->Add(this->SDownLoad19);
			this->ONPage->Controls->Add(this->groupBox48);
			this->ONPage->Controls->Add(this->label108);
			this->ONPage->Controls->Add(this->SDownLoad18);
			this->ONPage->Controls->Add(this->groupBox49);
			this->ONPage->Controls->Add(this->label110);
			this->ONPage->Controls->Add(this->SDownLoad17);
			this->ONPage->Controls->Add(this->groupBox50);
			this->ONPage->Controls->Add(this->label112);
			this->ONPage->Controls->Add(this->SDownLoad16);
			this->ONPage->Controls->Add(this->groupBox51);
			this->ONPage->Controls->Add(this->label114);
			this->ONPage->Controls->Add(this->SDownLoad15);
			this->ONPage->Controls->Add(this->groupBox52);
			this->ONPage->Controls->Add(this->label116);
			this->ONPage->Controls->Add(this->SDownLoad14);
			this->ONPage->Controls->Add(this->groupBox53);
			this->ONPage->Controls->Add(this->label118);
			this->ONPage->Controls->Add(this->SDownLoad13);
			this->ONPage->Controls->Add(this->groupBox54);
			this->ONPage->Controls->Add(this->label120);
			this->ONPage->Controls->Add(this->SDownLoad12);
			this->ONPage->Controls->Add(this->groupBox55);
			this->ONPage->Controls->Add(this->label122);
			this->ONPage->Controls->Add(this->SDownLoad11);
			this->ONPage->Controls->Add(this->groupBox56);
			this->ONPage->Controls->Add(this->label124);
			this->ONPage->Controls->Add(this->SDownLoad10);
			this->ONPage->Controls->Add(this->groupBox57);
			this->ONPage->Controls->Add(this->label126);
			this->ONPage->Controls->Add(this->SDownLoad9);
			this->ONPage->Controls->Add(this->groupBox58);
			this->ONPage->Controls->Add(this->label128);
			this->ONPage->Controls->Add(this->SDownLoad8);
			this->ONPage->Controls->Add(this->groupBox59);
			this->ONPage->Controls->Add(this->label130);
			this->ONPage->Controls->Add(this->SDownLoad7);
			this->ONPage->Controls->Add(this->groupBox60);
			this->ONPage->Controls->Add(this->label132);
			this->ONPage->Controls->Add(this->SDownLoad6);
			this->ONPage->Controls->Add(this->groupBox61);
			this->ONPage->Controls->Add(this->label134);
			this->ONPage->Controls->Add(this->SDownLoad5);
			this->ONPage->Controls->Add(this->groupBox62);
			this->ONPage->Controls->Add(this->label136);
			this->ONPage->Controls->Add(this->SDownLoad4);
			this->ONPage->Controls->Add(this->groupBox63);
			this->ONPage->Controls->Add(this->label138);
			this->ONPage->Controls->Add(this->SDownLoad3);
			this->ONPage->Controls->Add(this->groupBox64);
			this->ONPage->Controls->Add(this->label140);
			this->ONPage->Controls->Add(this->SDownLoad2);
			this->ONPage->Controls->Add(this->groupBox65);
			this->ONPage->Controls->Add(this->label142);
			this->ONPage->Controls->Add(this->SDownLoad1);
			this->ONPage->Controls->Add(this->groupBox66);
			this->ONPage->Controls->Add(this->ONCTime12);
			this->ONPage->Controls->Add(this->ONCTime11);
			this->ONPage->Controls->Add(this->ONCTime10);
			this->ONPage->Controls->Add(this->ONCTime9);
			this->ONPage->Controls->Add(this->ONCTime8);
			this->ONPage->Controls->Add(this->ONCTime7);
			this->ONPage->Controls->Add(this->ONCTime6);
			this->ONPage->Controls->Add(this->ONCTime5);
			this->ONPage->Controls->Add(this->ONCTime4);
			this->ONPage->Controls->Add(this->ONCTime3);
			this->ONPage->Controls->Add(this->ONCTime2);
			this->ONPage->Controls->Add(this->ONCTime1);
			this->ONPage->Controls->Add(this->ONSTime20);
			this->ONPage->Controls->Add(this->ONSTime19);
			this->ONPage->Controls->Add(this->ONSTime18);
			this->ONPage->Controls->Add(this->ONSTime17);
			this->ONPage->Controls->Add(this->ONSTime16);
			this->ONPage->Controls->Add(this->ONSTime15);
			this->ONPage->Controls->Add(this->ONSTime14);
			this->ONPage->Controls->Add(this->ONSTime13);
			this->ONPage->Controls->Add(this->ONSTime12);
			this->ONPage->Controls->Add(this->ONSTime11);
			this->ONPage->Controls->Add(this->ONSTime10);
			this->ONPage->Controls->Add(this->ONSTime9);
			this->ONPage->Controls->Add(this->ONSTime8);
			this->ONPage->Controls->Add(this->ONSTime7);
			this->ONPage->Controls->Add(this->ONSTime6);
			this->ONPage->Controls->Add(this->ONSTime5);
			this->ONPage->Controls->Add(this->ONSTime4);
			this->ONPage->Controls->Add(this->ONSTime3);
			this->ONPage->Controls->Add(this->ONSTime2);
			this->ONPage->Controls->Add(this->ONSTime1);
			this->ONPage->Controls->Add(this->CName1);
			this->ONPage->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONPage->Location = System::Drawing::Point(4, 21);
			this->ONPage->Name = S"ONPage";
			this->ONPage->Size = System::Drawing::Size(512, 367);
			this->ONPage->TabIndex = 1;
			this->ONPage->Text = S"グローバルランキング";
			// 
			// SName30
			// 
			this->SName30->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SName30->Location = System::Drawing::Point(128, 1184);
			this->SName30->Name = S"SName30";
			this->SName30->Size = System::Drawing::Size(144, 19);
			this->SName30->TabIndex = 244;
			this->SName30->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// groupBox87
			// 
			this->groupBox87->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox87->Location = System::Drawing::Point(24, 1200);
			this->groupBox87->Name = S"groupBox87";
			this->groupBox87->Size = System::Drawing::Size(448, 9);
			this->groupBox87->TabIndex = 243;
			this->groupBox87->TabStop = false;
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label32->Location = System::Drawing::Point(32, 1184);
			this->label32->Name = S"label32";
			this->label32->Size = System::Drawing::Size(94, 19);
			this->label32->TabIndex = 241;
			this->label32->Text = S"EXステージ17";
			// 
			// SDownLoad30
			// 
			this->SDownLoad30->AutoSize = true;
			this->SDownLoad30->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDownLoad30->Location = System::Drawing::Point(384, 1184);
			this->SDownLoad30->Name = S"SDownLoad30";
			this->SDownLoad30->Size = System::Drawing::Size(80, 19);
			this->SDownLoad30->TabIndex = 240;
			this->SDownLoad30->TabStop = true;
			this->SDownLoad30->Text = S"ダウンロード";
			this->SDownLoad30->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDownLoad30_LinkClicked);
			// 
			// ONSTime30
			// 
			this->ONSTime30->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONSTime30->Location = System::Drawing::Point(296, 1184);
			this->ONSTime30->Name = S"ONSTime30";
			this->ONSTime30->Size = System::Drawing::Size(80, 19);
			this->ONSTime30->TabIndex = 242;
			this->ONSTime30->Text = S"0：0";
			this->ONSTime30->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// SName23
			// 
			this->SName23->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SName23->Location = System::Drawing::Point(128, 904);
			this->SName23->Name = S"SName23";
			this->SName23->Size = System::Drawing::Size(144, 19);
			this->SName23->TabIndex = 239;
			this->SName23->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SName22
			// 
			this->SName22->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SName22->Location = System::Drawing::Point(128, 864);
			this->SName22->Name = S"SName22";
			this->SName22->Size = System::Drawing::Size(144, 19);
			this->SName22->TabIndex = 238;
			this->SName22->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SName21
			// 
			this->SName21->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SName21->Location = System::Drawing::Point(128, 824);
			this->SName21->Name = S"SName21";
			this->SName21->Size = System::Drawing::Size(144, 19);
			this->SName21->TabIndex = 237;
			this->SName21->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SName29
			// 
			this->SName29->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SName29->Location = System::Drawing::Point(128, 1144);
			this->SName29->Name = S"SName29";
			this->SName29->Size = System::Drawing::Size(144, 19);
			this->SName29->TabIndex = 236;
			this->SName29->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SName28
			// 
			this->SName28->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SName28->Location = System::Drawing::Point(128, 1104);
			this->SName28->Name = S"SName28";
			this->SName28->Size = System::Drawing::Size(144, 19);
			this->SName28->TabIndex = 235;
			this->SName28->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SName27
			// 
			this->SName27->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SName27->Location = System::Drawing::Point(128, 1064);
			this->SName27->Name = S"SName27";
			this->SName27->Size = System::Drawing::Size(144, 19);
			this->SName27->TabIndex = 234;
			this->SName27->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SName26
			// 
			this->SName26->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SName26->Location = System::Drawing::Point(128, 1024);
			this->SName26->Name = S"SName26";
			this->SName26->Size = System::Drawing::Size(144, 19);
			this->SName26->TabIndex = 233;
			this->SName26->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SName25
			// 
			this->SName25->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SName25->Location = System::Drawing::Point(128, 984);
			this->SName25->Name = S"SName25";
			this->SName25->Size = System::Drawing::Size(144, 19);
			this->SName25->TabIndex = 232;
			this->SName25->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SName24
			// 
			this->SName24->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SName24->Location = System::Drawing::Point(128, 944);
			this->SName24->Name = S"SName24";
			this->SName24->Size = System::Drawing::Size(144, 19);
			this->SName24->TabIndex = 231;
			this->SName24->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// groupBox78
			// 
			this->groupBox78->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox78->Location = System::Drawing::Point(24, 1160);
			this->groupBox78->Name = S"groupBox78";
			this->groupBox78->Size = System::Drawing::Size(448, 9);
			this->groupBox78->TabIndex = 230;
			this->groupBox78->TabStop = false;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label11->Location = System::Drawing::Point(32, 1144);
			this->label11->Name = S"label11";
			this->label11->Size = System::Drawing::Size(94, 19);
			this->label11->TabIndex = 228;
			this->label11->Text = S"EXステージ16";
			// 
			// SDownLoad29
			// 
			this->SDownLoad29->AutoSize = true;
			this->SDownLoad29->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDownLoad29->Location = System::Drawing::Point(384, 1144);
			this->SDownLoad29->Name = S"SDownLoad29";
			this->SDownLoad29->Size = System::Drawing::Size(80, 19);
			this->SDownLoad29->TabIndex = 227;
			this->SDownLoad29->TabStop = true;
			this->SDownLoad29->Text = S"ダウンロード";
			this->SDownLoad29->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDownLoad29_LinkClicked);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label12->Location = System::Drawing::Point(32, 1104);
			this->label12->Name = S"label12";
			this->label12->Size = System::Drawing::Size(94, 19);
			this->label12->TabIndex = 224;
			this->label12->Text = S"EXステージ15";
			// 
			// SDownLoad28
			// 
			this->SDownLoad28->AutoSize = true;
			this->SDownLoad28->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDownLoad28->Location = System::Drawing::Point(384, 1104);
			this->SDownLoad28->Name = S"SDownLoad28";
			this->SDownLoad28->Size = System::Drawing::Size(80, 19);
			this->SDownLoad28->TabIndex = 223;
			this->SDownLoad28->TabStop = true;
			this->SDownLoad28->Text = S"ダウンロード";
			this->SDownLoad28->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDownLoad28_LinkClicked);
			// 
			// groupBox79
			// 
			this->groupBox79->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox79->Location = System::Drawing::Point(24, 1120);
			this->groupBox79->Name = S"groupBox79";
			this->groupBox79->Size = System::Drawing::Size(448, 9);
			this->groupBox79->TabIndex = 225;
			this->groupBox79->TabStop = false;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label13->Location = System::Drawing::Point(32, 1064);
			this->label13->Name = S"label13";
			this->label13->Size = System::Drawing::Size(94, 19);
			this->label13->TabIndex = 220;
			this->label13->Text = S"EXステージ14";
			// 
			// SDownLoad27
			// 
			this->SDownLoad27->AutoSize = true;
			this->SDownLoad27->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDownLoad27->Location = System::Drawing::Point(384, 1064);
			this->SDownLoad27->Name = S"SDownLoad27";
			this->SDownLoad27->Size = System::Drawing::Size(80, 19);
			this->SDownLoad27->TabIndex = 219;
			this->SDownLoad27->TabStop = true;
			this->SDownLoad27->Text = S"ダウンロード";
			this->SDownLoad27->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDownLoad27_LinkClicked);
			// 
			// groupBox80
			// 
			this->groupBox80->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox80->Location = System::Drawing::Point(24, 1080);
			this->groupBox80->Name = S"groupBox80";
			this->groupBox80->Size = System::Drawing::Size(448, 9);
			this->groupBox80->TabIndex = 221;
			this->groupBox80->TabStop = false;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label14->Location = System::Drawing::Point(32, 1024);
			this->label14->Name = S"label14";
			this->label14->Size = System::Drawing::Size(94, 19);
			this->label14->TabIndex = 216;
			this->label14->Text = S"EXステージ13";
			// 
			// SDownLoad26
			// 
			this->SDownLoad26->AutoSize = true;
			this->SDownLoad26->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDownLoad26->Location = System::Drawing::Point(384, 1024);
			this->SDownLoad26->Name = S"SDownLoad26";
			this->SDownLoad26->Size = System::Drawing::Size(80, 19);
			this->SDownLoad26->TabIndex = 215;
			this->SDownLoad26->TabStop = true;
			this->SDownLoad26->Text = S"ダウンロード";
			this->SDownLoad26->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDownLoad26_LinkClicked);
			// 
			// groupBox81
			// 
			this->groupBox81->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox81->Location = System::Drawing::Point(24, 1040);
			this->groupBox81->Name = S"groupBox81";
			this->groupBox81->Size = System::Drawing::Size(448, 9);
			this->groupBox81->TabIndex = 217;
			this->groupBox81->TabStop = false;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label15->Location = System::Drawing::Point(32, 984);
			this->label15->Name = S"label15";
			this->label15->Size = System::Drawing::Size(94, 19);
			this->label15->TabIndex = 212;
			this->label15->Text = S"EXステージ12";
			// 
			// SDownLoad25
			// 
			this->SDownLoad25->AutoSize = true;
			this->SDownLoad25->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDownLoad25->Location = System::Drawing::Point(384, 984);
			this->SDownLoad25->Name = S"SDownLoad25";
			this->SDownLoad25->Size = System::Drawing::Size(80, 19);
			this->SDownLoad25->TabIndex = 211;
			this->SDownLoad25->TabStop = true;
			this->SDownLoad25->Text = S"ダウンロード";
			this->SDownLoad25->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDownLoad25_LinkClicked);
			// 
			// groupBox82
			// 
			this->groupBox82->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox82->Location = System::Drawing::Point(24, 1000);
			this->groupBox82->Name = S"groupBox82";
			this->groupBox82->Size = System::Drawing::Size(448, 9);
			this->groupBox82->TabIndex = 213;
			this->groupBox82->TabStop = false;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label16->Location = System::Drawing::Point(32, 944);
			this->label16->Name = S"label16";
			this->label16->Size = System::Drawing::Size(94, 19);
			this->label16->TabIndex = 208;
			this->label16->Text = S"EXステージ11";
			// 
			// SDownLoad24
			// 
			this->SDownLoad24->AutoSize = true;
			this->SDownLoad24->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDownLoad24->Location = System::Drawing::Point(384, 944);
			this->SDownLoad24->Name = S"SDownLoad24";
			this->SDownLoad24->Size = System::Drawing::Size(80, 19);
			this->SDownLoad24->TabIndex = 207;
			this->SDownLoad24->TabStop = true;
			this->SDownLoad24->Text = S"ダウンロード";
			this->SDownLoad24->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDownLoad24_LinkClicked);
			// 
			// groupBox83
			// 
			this->groupBox83->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox83->Location = System::Drawing::Point(24, 960);
			this->groupBox83->Name = S"groupBox83";
			this->groupBox83->Size = System::Drawing::Size(448, 9);
			this->groupBox83->TabIndex = 209;
			this->groupBox83->TabStop = false;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label17->Location = System::Drawing::Point(32, 904);
			this->label17->Name = S"label17";
			this->label17->Size = System::Drawing::Size(94, 19);
			this->label17->TabIndex = 204;
			this->label17->Text = S"EXステージ10";
			// 
			// SDownLoad23
			// 
			this->SDownLoad23->AutoSize = true;
			this->SDownLoad23->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDownLoad23->Location = System::Drawing::Point(384, 904);
			this->SDownLoad23->Name = S"SDownLoad23";
			this->SDownLoad23->Size = System::Drawing::Size(80, 19);
			this->SDownLoad23->TabIndex = 203;
			this->SDownLoad23->TabStop = true;
			this->SDownLoad23->Text = S"ダウンロード";
			this->SDownLoad23->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDownLoad23_LinkClicked);
			// 
			// groupBox84
			// 
			this->groupBox84->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox84->Location = System::Drawing::Point(24, 920);
			this->groupBox84->Name = S"groupBox84";
			this->groupBox84->Size = System::Drawing::Size(448, 9);
			this->groupBox84->TabIndex = 205;
			this->groupBox84->TabStop = false;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label19->Location = System::Drawing::Point(32, 864);
			this->label19->Name = S"label19";
			this->label19->Size = System::Drawing::Size(86, 19);
			this->label19->TabIndex = 200;
			this->label19->Text = S"EXステージ9";
			// 
			// SDownLoad22
			// 
			this->SDownLoad22->AutoSize = true;
			this->SDownLoad22->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDownLoad22->Location = System::Drawing::Point(384, 864);
			this->SDownLoad22->Name = S"SDownLoad22";
			this->SDownLoad22->Size = System::Drawing::Size(80, 19);
			this->SDownLoad22->TabIndex = 199;
			this->SDownLoad22->TabStop = true;
			this->SDownLoad22->Text = S"ダウンロード";
			this->SDownLoad22->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDownLoad22_LinkClicked);
			// 
			// groupBox85
			// 
			this->groupBox85->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox85->Location = System::Drawing::Point(24, 880);
			this->groupBox85->Name = S"groupBox85";
			this->groupBox85->Size = System::Drawing::Size(448, 9);
			this->groupBox85->TabIndex = 201;
			this->groupBox85->TabStop = false;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label20->Location = System::Drawing::Point(32, 824);
			this->label20->Name = S"label20";
			this->label20->Size = System::Drawing::Size(86, 19);
			this->label20->TabIndex = 196;
			this->label20->Text = S"EXステージ8";
			// 
			// SDownLoad21
			// 
			this->SDownLoad21->AutoSize = true;
			this->SDownLoad21->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDownLoad21->Location = System::Drawing::Point(384, 824);
			this->SDownLoad21->Name = S"SDownLoad21";
			this->SDownLoad21->Size = System::Drawing::Size(80, 19);
			this->SDownLoad21->TabIndex = 195;
			this->SDownLoad21->TabStop = true;
			this->SDownLoad21->Text = S"ダウンロード";
			this->SDownLoad21->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDownLoad21_LinkClicked);
			// 
			// groupBox86
			// 
			this->groupBox86->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox86->Location = System::Drawing::Point(24, 840);
			this->groupBox86->Name = S"groupBox86";
			this->groupBox86->Size = System::Drawing::Size(448, 9);
			this->groupBox86->TabIndex = 197;
			this->groupBox86->TabStop = false;
			// 
			// ONSTime29
			// 
			this->ONSTime29->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONSTime29->Location = System::Drawing::Point(296, 1144);
			this->ONSTime29->Name = S"ONSTime29";
			this->ONSTime29->Size = System::Drawing::Size(80, 19);
			this->ONSTime29->TabIndex = 229;
			this->ONSTime29->Text = S"0：0";
			this->ONSTime29->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONSTime28
			// 
			this->ONSTime28->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONSTime28->Location = System::Drawing::Point(296, 1104);
			this->ONSTime28->Name = S"ONSTime28";
			this->ONSTime28->Size = System::Drawing::Size(80, 19);
			this->ONSTime28->TabIndex = 226;
			this->ONSTime28->Text = S"0：0";
			this->ONSTime28->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONSTime27
			// 
			this->ONSTime27->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONSTime27->Location = System::Drawing::Point(296, 1064);
			this->ONSTime27->Name = S"ONSTime27";
			this->ONSTime27->Size = System::Drawing::Size(80, 19);
			this->ONSTime27->TabIndex = 222;
			this->ONSTime27->Text = S"0：0";
			this->ONSTime27->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONSTime26
			// 
			this->ONSTime26->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONSTime26->Location = System::Drawing::Point(296, 1024);
			this->ONSTime26->Name = S"ONSTime26";
			this->ONSTime26->Size = System::Drawing::Size(80, 19);
			this->ONSTime26->TabIndex = 218;
			this->ONSTime26->Text = S"0：0";
			this->ONSTime26->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONSTime25
			// 
			this->ONSTime25->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONSTime25->Location = System::Drawing::Point(296, 984);
			this->ONSTime25->Name = S"ONSTime25";
			this->ONSTime25->Size = System::Drawing::Size(80, 19);
			this->ONSTime25->TabIndex = 214;
			this->ONSTime25->Text = S"0：0";
			this->ONSTime25->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONSTime24
			// 
			this->ONSTime24->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONSTime24->Location = System::Drawing::Point(296, 944);
			this->ONSTime24->Name = S"ONSTime24";
			this->ONSTime24->Size = System::Drawing::Size(80, 19);
			this->ONSTime24->TabIndex = 210;
			this->ONSTime24->Text = S"0：0";
			this->ONSTime24->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONSTime23
			// 
			this->ONSTime23->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONSTime23->Location = System::Drawing::Point(296, 904);
			this->ONSTime23->Name = S"ONSTime23";
			this->ONSTime23->Size = System::Drawing::Size(80, 19);
			this->ONSTime23->TabIndex = 206;
			this->ONSTime23->Text = S"0：0";
			this->ONSTime23->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONSTime22
			// 
			this->ONSTime22->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONSTime22->Location = System::Drawing::Point(296, 864);
			this->ONSTime22->Name = S"ONSTime22";
			this->ONSTime22->Size = System::Drawing::Size(80, 19);
			this->ONSTime22->TabIndex = 202;
			this->ONSTime22->Text = S"0：0";
			this->ONSTime22->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONSTime21
			// 
			this->ONSTime21->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONSTime21->Location = System::Drawing::Point(296, 824);
			this->ONSTime21->Name = S"ONSTime21";
			this->ONSTime21->Size = System::Drawing::Size(80, 19);
			this->ONSTime21->TabIndex = 198;
			this->ONSTime21->Text = S"0：0";
			this->ONSTime21->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// SName6
			// 
			this->SName6->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SName6->Location = System::Drawing::Point(128, 224);
			this->SName6->Name = S"SName6";
			this->SName6->Size = System::Drawing::Size(144, 19);
			this->SName6->TabIndex = 194;
			this->SName6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SName5
			// 
			this->SName5->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SName5->Location = System::Drawing::Point(128, 184);
			this->SName5->Name = S"SName5";
			this->SName5->Size = System::Drawing::Size(144, 19);
			this->SName5->TabIndex = 193;
			this->SName5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SName4
			// 
			this->SName4->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SName4->Location = System::Drawing::Point(128, 144);
			this->SName4->Name = S"SName4";
			this->SName4->Size = System::Drawing::Size(144, 19);
			this->SName4->TabIndex = 192;
			this->SName4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SName3
			// 
			this->SName3->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SName3->Location = System::Drawing::Point(128, 104);
			this->SName3->Name = S"SName3";
			this->SName3->Size = System::Drawing::Size(144, 19);
			this->SName3->TabIndex = 191;
			this->SName3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SName2
			// 
			this->SName2->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SName2->Location = System::Drawing::Point(128, 64);
			this->SName2->Name = S"SName2";
			this->SName2->Size = System::Drawing::Size(144, 19);
			this->SName2->TabIndex = 190;
			this->SName2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SName1
			// 
			this->SName1->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SName1->Location = System::Drawing::Point(128, 24);
			this->SName1->Name = S"SName1";
			this->SName1->Size = System::Drawing::Size(144, 19);
			this->SName1->TabIndex = 189;
			this->SName1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SName8
			// 
			this->SName8->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SName8->Location = System::Drawing::Point(128, 304);
			this->SName8->Name = S"SName8";
			this->SName8->Size = System::Drawing::Size(144, 19);
			this->SName8->TabIndex = 188;
			this->SName8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SName7
			// 
			this->SName7->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SName7->Location = System::Drawing::Point(128, 264);
			this->SName7->Name = S"SName7";
			this->SName7->Size = System::Drawing::Size(144, 19);
			this->SName7->TabIndex = 187;
			this->SName7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SName14
			// 
			this->SName14->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SName14->Location = System::Drawing::Point(128, 544);
			this->SName14->Name = S"SName14";
			this->SName14->Size = System::Drawing::Size(144, 19);
			this->SName14->TabIndex = 186;
			this->SName14->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SName13
			// 
			this->SName13->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SName13->Location = System::Drawing::Point(128, 504);
			this->SName13->Name = S"SName13";
			this->SName13->Size = System::Drawing::Size(144, 19);
			this->SName13->TabIndex = 185;
			this->SName13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SName12
			// 
			this->SName12->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SName12->Location = System::Drawing::Point(128, 464);
			this->SName12->Name = S"SName12";
			this->SName12->Size = System::Drawing::Size(144, 19);
			this->SName12->TabIndex = 184;
			this->SName12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SName11
			// 
			this->SName11->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SName11->Location = System::Drawing::Point(128, 424);
			this->SName11->Name = S"SName11";
			this->SName11->Size = System::Drawing::Size(144, 19);
			this->SName11->TabIndex = 183;
			this->SName11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SName10
			// 
			this->SName10->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SName10->Location = System::Drawing::Point(128, 384);
			this->SName10->Name = S"SName10";
			this->SName10->Size = System::Drawing::Size(144, 19);
			this->SName10->TabIndex = 182;
			this->SName10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SName9
			// 
			this->SName9->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SName9->Location = System::Drawing::Point(128, 344);
			this->SName9->Name = S"SName9";
			this->SName9->Size = System::Drawing::Size(144, 19);
			this->SName9->TabIndex = 181;
			this->SName9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SName20
			// 
			this->SName20->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SName20->Location = System::Drawing::Point(128, 784);
			this->SName20->Name = S"SName20";
			this->SName20->Size = System::Drawing::Size(144, 19);
			this->SName20->TabIndex = 180;
			this->SName20->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SName19
			// 
			this->SName19->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SName19->Location = System::Drawing::Point(128, 744);
			this->SName19->Name = S"SName19";
			this->SName19->Size = System::Drawing::Size(144, 19);
			this->SName19->TabIndex = 179;
			this->SName19->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SName18
			// 
			this->SName18->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SName18->Location = System::Drawing::Point(128, 704);
			this->SName18->Name = S"SName18";
			this->SName18->Size = System::Drawing::Size(144, 19);
			this->SName18->TabIndex = 178;
			this->SName18->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SName17
			// 
			this->SName17->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SName17->Location = System::Drawing::Point(128, 664);
			this->SName17->Name = S"SName17";
			this->SName17->Size = System::Drawing::Size(144, 19);
			this->SName17->TabIndex = 177;
			this->SName17->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SName16
			// 
			this->SName16->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SName16->Location = System::Drawing::Point(128, 624);
			this->SName16->Name = S"SName16";
			this->SName16->Size = System::Drawing::Size(144, 19);
			this->SName16->TabIndex = 176;
			this->SName16->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SName15
			// 
			this->SName15->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SName15->Location = System::Drawing::Point(128, 584);
			this->SName15->Name = S"SName15";
			this->SName15->Size = System::Drawing::Size(144, 19);
			this->SName15->TabIndex = 175;
			this->SName15->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// CName12
			// 
			this->CName12->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CName12->Location = System::Drawing::Point(104, 1696);
			this->CName12->Name = S"CName12";
			this->CName12->Size = System::Drawing::Size(144, 19);
			this->CName12->TabIndex = 174;
			this->CName12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// CName11
			// 
			this->CName11->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CName11->Location = System::Drawing::Point(104, 1656);
			this->CName11->Name = S"CName11";
			this->CName11->Size = System::Drawing::Size(144, 19);
			this->CName11->TabIndex = 173;
			this->CName11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// CName10
			// 
			this->CName10->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CName10->Location = System::Drawing::Point(104, 1616);
			this->CName10->Name = S"CName10";
			this->CName10->Size = System::Drawing::Size(144, 19);
			this->CName10->TabIndex = 172;
			this->CName10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// CName9
			// 
			this->CName9->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CName9->Location = System::Drawing::Point(104, 1576);
			this->CName9->Name = S"CName9";
			this->CName9->Size = System::Drawing::Size(144, 19);
			this->CName9->TabIndex = 171;
			this->CName9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// CName8
			// 
			this->CName8->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CName8->Location = System::Drawing::Point(104, 1536);
			this->CName8->Name = S"CName8";
			this->CName8->Size = System::Drawing::Size(144, 19);
			this->CName8->TabIndex = 170;
			this->CName8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// CName7
			// 
			this->CName7->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CName7->Location = System::Drawing::Point(104, 1496);
			this->CName7->Name = S"CName7";
			this->CName7->Size = System::Drawing::Size(144, 19);
			this->CName7->TabIndex = 169;
			this->CName7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// CName6
			// 
			this->CName6->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CName6->Location = System::Drawing::Point(104, 1456);
			this->CName6->Name = S"CName6";
			this->CName6->Size = System::Drawing::Size(144, 19);
			this->CName6->TabIndex = 168;
			this->CName6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// CName5
			// 
			this->CName5->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CName5->Location = System::Drawing::Point(104, 1416);
			this->CName5->Name = S"CName5";
			this->CName5->Size = System::Drawing::Size(144, 19);
			this->CName5->TabIndex = 167;
			this->CName5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// CName4
			// 
			this->CName4->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CName4->Location = System::Drawing::Point(104, 1376);
			this->CName4->Name = S"CName4";
			this->CName4->Size = System::Drawing::Size(144, 19);
			this->CName4->TabIndex = 166;
			this->CName4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// CName3
			// 
			this->CName3->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CName3->Location = System::Drawing::Point(104, 1336);
			this->CName3->Name = S"CName3";
			this->CName3->Size = System::Drawing::Size(144, 19);
			this->CName3->TabIndex = 165;
			this->CName3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// CName2
			// 
			this->CName2->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CName2->Location = System::Drawing::Point(104, 1296);
			this->CName2->Name = S"CName2";
			this->CName2->Size = System::Drawing::Size(144, 19);
			this->CName2->TabIndex = 164;
			this->CName2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// groupBox34
			// 
			this->groupBox34->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox34->Location = System::Drawing::Point(24, 1736);
			this->groupBox34->Name = S"groupBox34";
			this->groupBox34->Size = System::Drawing::Size(448, 0);
			this->groupBox34->TabIndex = 161;
			this->groupBox34->TabStop = false;
			// 
			// Char12
			// 
			this->Char12->AutoSize = true;
			this->Char12->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->Char12->Location = System::Drawing::Point(256, 1696);
			this->Char12->Name = S"Char12";
			this->Char12->Size = System::Drawing::Size(42, 19);
			this->Char12->TabIndex = 158;
			this->Char12->Text = S"キャラ";
			// 
			// label69
			// 
			this->label69->AutoSize = true;
			this->label69->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label69->Location = System::Drawing::Point(32, 1696);
			this->label69->Name = S"label69";
			this->label69->Size = System::Drawing::Size(60, 19);
			this->label69->TabIndex = 157;
			this->label69->Text = S"コース12";
			// 
			// CDownLoad12
			// 
			this->CDownLoad12->AutoSize = true;
			this->CDownLoad12->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CDownLoad12->Location = System::Drawing::Point(384, 1696);
			this->CDownLoad12->Name = S"CDownLoad12";
			this->CDownLoad12->Size = System::Drawing::Size(80, 19);
			this->CDownLoad12->TabIndex = 156;
			this->CDownLoad12->TabStop = true;
			this->CDownLoad12->Text = S"ダウンロード";
			this->CDownLoad12->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CDownLoad12_LinkClicked);
			// 
			// groupBox35
			// 
			this->groupBox35->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox35->Location = System::Drawing::Point(24, 1712);
			this->groupBox35->Name = S"groupBox35";
			this->groupBox35->Size = System::Drawing::Size(448, 9);
			this->groupBox35->TabIndex = 159;
			this->groupBox35->TabStop = false;
			// 
			// Char11
			// 
			this->Char11->AutoSize = true;
			this->Char11->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->Char11->Location = System::Drawing::Point(256, 1656);
			this->Char11->Name = S"Char11";
			this->Char11->Size = System::Drawing::Size(42, 19);
			this->Char11->TabIndex = 153;
			this->Char11->Text = S"キャラ";
			// 
			// label72
			// 
			this->label72->AutoSize = true;
			this->label72->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label72->Location = System::Drawing::Point(32, 1656);
			this->label72->Name = S"label72";
			this->label72->Size = System::Drawing::Size(60, 19);
			this->label72->TabIndex = 152;
			this->label72->Text = S"コース11";
			// 
			// CDownLoad11
			// 
			this->CDownLoad11->AutoSize = true;
			this->CDownLoad11->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CDownLoad11->Location = System::Drawing::Point(384, 1656);
			this->CDownLoad11->Name = S"CDownLoad11";
			this->CDownLoad11->Size = System::Drawing::Size(80, 19);
			this->CDownLoad11->TabIndex = 151;
			this->CDownLoad11->TabStop = true;
			this->CDownLoad11->Text = S"ダウンロード";
			this->CDownLoad11->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CDownLoad11_LinkClicked);
			// 
			// groupBox36
			// 
			this->groupBox36->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox36->Location = System::Drawing::Point(24, 1672);
			this->groupBox36->Name = S"groupBox36";
			this->groupBox36->Size = System::Drawing::Size(448, 9);
			this->groupBox36->TabIndex = 154;
			this->groupBox36->TabStop = false;
			// 
			// Char10
			// 
			this->Char10->AutoSize = true;
			this->Char10->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->Char10->Location = System::Drawing::Point(256, 1616);
			this->Char10->Name = S"Char10";
			this->Char10->Size = System::Drawing::Size(42, 19);
			this->Char10->TabIndex = 148;
			this->Char10->Text = S"キャラ";
			// 
			// label75
			// 
			this->label75->AutoSize = true;
			this->label75->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label75->Location = System::Drawing::Point(32, 1616);
			this->label75->Name = S"label75";
			this->label75->Size = System::Drawing::Size(60, 19);
			this->label75->TabIndex = 147;
			this->label75->Text = S"コース10";
			// 
			// CDownLoad10
			// 
			this->CDownLoad10->AutoSize = true;
			this->CDownLoad10->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CDownLoad10->Location = System::Drawing::Point(384, 1616);
			this->CDownLoad10->Name = S"CDownLoad10";
			this->CDownLoad10->Size = System::Drawing::Size(80, 19);
			this->CDownLoad10->TabIndex = 146;
			this->CDownLoad10->TabStop = true;
			this->CDownLoad10->Text = S"ダウンロード";
			this->CDownLoad10->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CDownLoad10_LinkClicked);
			// 
			// groupBox37
			// 
			this->groupBox37->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox37->Location = System::Drawing::Point(24, 1632);
			this->groupBox37->Name = S"groupBox37";
			this->groupBox37->Size = System::Drawing::Size(448, 9);
			this->groupBox37->TabIndex = 149;
			this->groupBox37->TabStop = false;
			// 
			// Char9
			// 
			this->Char9->AutoSize = true;
			this->Char9->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->Char9->Location = System::Drawing::Point(256, 1576);
			this->Char9->Name = S"Char9";
			this->Char9->Size = System::Drawing::Size(42, 19);
			this->Char9->TabIndex = 143;
			this->Char9->Text = S"キャラ";
			// 
			// label78
			// 
			this->label78->AutoSize = true;
			this->label78->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label78->Location = System::Drawing::Point(32, 1576);
			this->label78->Name = S"label78";
			this->label78->Size = System::Drawing::Size(52, 19);
			this->label78->TabIndex = 142;
			this->label78->Text = S"コース9";
			// 
			// CDownLoad9
			// 
			this->CDownLoad9->AutoSize = true;
			this->CDownLoad9->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CDownLoad9->Location = System::Drawing::Point(384, 1576);
			this->CDownLoad9->Name = S"CDownLoad9";
			this->CDownLoad9->Size = System::Drawing::Size(80, 19);
			this->CDownLoad9->TabIndex = 141;
			this->CDownLoad9->TabStop = true;
			this->CDownLoad9->Text = S"ダウンロード";
			this->CDownLoad9->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CDownLoad9_LinkClicked);
			// 
			// groupBox38
			// 
			this->groupBox38->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox38->Location = System::Drawing::Point(24, 1592);
			this->groupBox38->Name = S"groupBox38";
			this->groupBox38->Size = System::Drawing::Size(448, 9);
			this->groupBox38->TabIndex = 144;
			this->groupBox38->TabStop = false;
			// 
			// Char8
			// 
			this->Char8->AutoSize = true;
			this->Char8->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->Char8->Location = System::Drawing::Point(256, 1536);
			this->Char8->Name = S"Char8";
			this->Char8->Size = System::Drawing::Size(42, 19);
			this->Char8->TabIndex = 138;
			this->Char8->Text = S"キャラ";
			// 
			// label81
			// 
			this->label81->AutoSize = true;
			this->label81->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label81->Location = System::Drawing::Point(32, 1536);
			this->label81->Name = S"label81";
			this->label81->Size = System::Drawing::Size(52, 19);
			this->label81->TabIndex = 137;
			this->label81->Text = S"コース8";
			// 
			// CDownLoad8
			// 
			this->CDownLoad8->AutoSize = true;
			this->CDownLoad8->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CDownLoad8->Location = System::Drawing::Point(384, 1536);
			this->CDownLoad8->Name = S"CDownLoad8";
			this->CDownLoad8->Size = System::Drawing::Size(80, 19);
			this->CDownLoad8->TabIndex = 136;
			this->CDownLoad8->TabStop = true;
			this->CDownLoad8->Text = S"ダウンロード";
			this->CDownLoad8->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CDownLoad8_LinkClicked);
			// 
			// groupBox39
			// 
			this->groupBox39->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox39->Location = System::Drawing::Point(24, 1552);
			this->groupBox39->Name = S"groupBox39";
			this->groupBox39->Size = System::Drawing::Size(448, 9);
			this->groupBox39->TabIndex = 139;
			this->groupBox39->TabStop = false;
			// 
			// Char7
			// 
			this->Char7->AutoSize = true;
			this->Char7->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->Char7->Location = System::Drawing::Point(256, 1496);
			this->Char7->Name = S"Char7";
			this->Char7->Size = System::Drawing::Size(42, 19);
			this->Char7->TabIndex = 133;
			this->Char7->Text = S"キャラ";
			// 
			// label84
			// 
			this->label84->AutoSize = true;
			this->label84->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label84->Location = System::Drawing::Point(32, 1496);
			this->label84->Name = S"label84";
			this->label84->Size = System::Drawing::Size(52, 19);
			this->label84->TabIndex = 132;
			this->label84->Text = S"コース7";
			// 
			// CDownLoad7
			// 
			this->CDownLoad7->AutoSize = true;
			this->CDownLoad7->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CDownLoad7->Location = System::Drawing::Point(384, 1496);
			this->CDownLoad7->Name = S"CDownLoad7";
			this->CDownLoad7->Size = System::Drawing::Size(80, 19);
			this->CDownLoad7->TabIndex = 131;
			this->CDownLoad7->TabStop = true;
			this->CDownLoad7->Text = S"ダウンロード";
			this->CDownLoad7->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CDownLoad7_LinkClicked);
			// 
			// groupBox40
			// 
			this->groupBox40->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox40->Location = System::Drawing::Point(24, 1512);
			this->groupBox40->Name = S"groupBox40";
			this->groupBox40->Size = System::Drawing::Size(448, 9);
			this->groupBox40->TabIndex = 134;
			this->groupBox40->TabStop = false;
			// 
			// Char6
			// 
			this->Char6->AutoSize = true;
			this->Char6->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->Char6->Location = System::Drawing::Point(256, 1456);
			this->Char6->Name = S"Char6";
			this->Char6->Size = System::Drawing::Size(42, 19);
			this->Char6->TabIndex = 128;
			this->Char6->Text = S"キャラ";
			// 
			// label87
			// 
			this->label87->AutoSize = true;
			this->label87->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label87->Location = System::Drawing::Point(32, 1456);
			this->label87->Name = S"label87";
			this->label87->Size = System::Drawing::Size(52, 19);
			this->label87->TabIndex = 127;
			this->label87->Text = S"コース6";
			// 
			// CDownLoad6
			// 
			this->CDownLoad6->AutoSize = true;
			this->CDownLoad6->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CDownLoad6->Location = System::Drawing::Point(384, 1456);
			this->CDownLoad6->Name = S"CDownLoad6";
			this->CDownLoad6->Size = System::Drawing::Size(80, 19);
			this->CDownLoad6->TabIndex = 126;
			this->CDownLoad6->TabStop = true;
			this->CDownLoad6->Text = S"ダウンロード";
			this->CDownLoad6->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CDownLoad6_LinkClicked);
			// 
			// groupBox41
			// 
			this->groupBox41->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox41->Location = System::Drawing::Point(24, 1472);
			this->groupBox41->Name = S"groupBox41";
			this->groupBox41->Size = System::Drawing::Size(448, 9);
			this->groupBox41->TabIndex = 129;
			this->groupBox41->TabStop = false;
			// 
			// Char5
			// 
			this->Char5->AutoSize = true;
			this->Char5->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->Char5->Location = System::Drawing::Point(256, 1416);
			this->Char5->Name = S"Char5";
			this->Char5->Size = System::Drawing::Size(42, 19);
			this->Char5->TabIndex = 123;
			this->Char5->Text = S"キャラ";
			// 
			// label90
			// 
			this->label90->AutoSize = true;
			this->label90->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label90->Location = System::Drawing::Point(32, 1416);
			this->label90->Name = S"label90";
			this->label90->Size = System::Drawing::Size(52, 19);
			this->label90->TabIndex = 122;
			this->label90->Text = S"コース5";
			// 
			// CDownLoad5
			// 
			this->CDownLoad5->AutoSize = true;
			this->CDownLoad5->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CDownLoad5->Location = System::Drawing::Point(384, 1416);
			this->CDownLoad5->Name = S"CDownLoad5";
			this->CDownLoad5->Size = System::Drawing::Size(80, 19);
			this->CDownLoad5->TabIndex = 121;
			this->CDownLoad5->TabStop = true;
			this->CDownLoad5->Text = S"ダウンロード";
			this->CDownLoad5->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CDownLoad5_LinkClicked);
			// 
			// groupBox42
			// 
			this->groupBox42->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox42->Location = System::Drawing::Point(24, 1432);
			this->groupBox42->Name = S"groupBox42";
			this->groupBox42->Size = System::Drawing::Size(448, 9);
			this->groupBox42->TabIndex = 124;
			this->groupBox42->TabStop = false;
			// 
			// Char4
			// 
			this->Char4->AutoSize = true;
			this->Char4->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->Char4->Location = System::Drawing::Point(256, 1376);
			this->Char4->Name = S"Char4";
			this->Char4->Size = System::Drawing::Size(42, 19);
			this->Char4->TabIndex = 118;
			this->Char4->Text = S"キャラ";
			// 
			// label93
			// 
			this->label93->AutoSize = true;
			this->label93->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label93->Location = System::Drawing::Point(32, 1376);
			this->label93->Name = S"label93";
			this->label93->Size = System::Drawing::Size(52, 19);
			this->label93->TabIndex = 117;
			this->label93->Text = S"コース4";
			// 
			// CDownLoad4
			// 
			this->CDownLoad4->AutoSize = true;
			this->CDownLoad4->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CDownLoad4->Location = System::Drawing::Point(384, 1376);
			this->CDownLoad4->Name = S"CDownLoad4";
			this->CDownLoad4->Size = System::Drawing::Size(80, 19);
			this->CDownLoad4->TabIndex = 116;
			this->CDownLoad4->TabStop = true;
			this->CDownLoad4->Text = S"ダウンロード";
			this->CDownLoad4->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CDownLoad4_LinkClicked);
			// 
			// groupBox43
			// 
			this->groupBox43->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox43->Location = System::Drawing::Point(24, 1392);
			this->groupBox43->Name = S"groupBox43";
			this->groupBox43->Size = System::Drawing::Size(448, 9);
			this->groupBox43->TabIndex = 119;
			this->groupBox43->TabStop = false;
			// 
			// Char3
			// 
			this->Char3->AutoSize = true;
			this->Char3->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->Char3->Location = System::Drawing::Point(256, 1336);
			this->Char3->Name = S"Char3";
			this->Char3->Size = System::Drawing::Size(42, 19);
			this->Char3->TabIndex = 113;
			this->Char3->Text = S"キャラ";
			// 
			// label96
			// 
			this->label96->AutoSize = true;
			this->label96->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label96->Location = System::Drawing::Point(32, 1336);
			this->label96->Name = S"label96";
			this->label96->Size = System::Drawing::Size(52, 19);
			this->label96->TabIndex = 112;
			this->label96->Text = S"コース3";
			// 
			// CDownLoad3
			// 
			this->CDownLoad3->AutoSize = true;
			this->CDownLoad3->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CDownLoad3->Location = System::Drawing::Point(384, 1336);
			this->CDownLoad3->Name = S"CDownLoad3";
			this->CDownLoad3->Size = System::Drawing::Size(80, 19);
			this->CDownLoad3->TabIndex = 111;
			this->CDownLoad3->TabStop = true;
			this->CDownLoad3->Text = S"ダウンロード";
			this->CDownLoad3->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CDownLoad3_LinkClicked);
			// 
			// groupBox44
			// 
			this->groupBox44->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox44->Location = System::Drawing::Point(24, 1352);
			this->groupBox44->Name = S"groupBox44";
			this->groupBox44->Size = System::Drawing::Size(448, 9);
			this->groupBox44->TabIndex = 114;
			this->groupBox44->TabStop = false;
			// 
			// Char2
			// 
			this->Char2->AutoSize = true;
			this->Char2->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->Char2->Location = System::Drawing::Point(256, 1296);
			this->Char2->Name = S"Char2";
			this->Char2->Size = System::Drawing::Size(42, 19);
			this->Char2->TabIndex = 108;
			this->Char2->Text = S"キャラ";
			// 
			// label99
			// 
			this->label99->AutoSize = true;
			this->label99->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label99->Location = System::Drawing::Point(32, 1296);
			this->label99->Name = S"label99";
			this->label99->Size = System::Drawing::Size(52, 19);
			this->label99->TabIndex = 107;
			this->label99->Text = S"コース2";
			// 
			// CDownLoad2
			// 
			this->CDownLoad2->AutoSize = true;
			this->CDownLoad2->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CDownLoad2->Location = System::Drawing::Point(384, 1296);
			this->CDownLoad2->Name = S"CDownLoad2";
			this->CDownLoad2->Size = System::Drawing::Size(80, 19);
			this->CDownLoad2->TabIndex = 106;
			this->CDownLoad2->TabStop = true;
			this->CDownLoad2->Text = S"ダウンロード";
			this->CDownLoad2->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CDownLoad2_LinkClicked);
			// 
			// groupBox45
			// 
			this->groupBox45->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox45->Location = System::Drawing::Point(24, 1312);
			this->groupBox45->Name = S"groupBox45";
			this->groupBox45->Size = System::Drawing::Size(448, 9);
			this->groupBox45->TabIndex = 109;
			this->groupBox45->TabStop = false;
			// 
			// Char1
			// 
			this->Char1->AutoSize = true;
			this->Char1->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->Char1->Location = System::Drawing::Point(256, 1256);
			this->Char1->Name = S"Char1";
			this->Char1->Size = System::Drawing::Size(42, 19);
			this->Char1->TabIndex = 103;
			this->Char1->Text = S"キャラ";
			// 
			// label102
			// 
			this->label102->AutoSize = true;
			this->label102->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label102->Location = System::Drawing::Point(32, 1256);
			this->label102->Name = S"label102";
			this->label102->Size = System::Drawing::Size(52, 19);
			this->label102->TabIndex = 102;
			this->label102->Text = S"コース1";
			// 
			// CDownLoad1
			// 
			this->CDownLoad1->AutoSize = true;
			this->CDownLoad1->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CDownLoad1->Location = System::Drawing::Point(384, 1256);
			this->CDownLoad1->Name = S"CDownLoad1";
			this->CDownLoad1->Size = System::Drawing::Size(80, 19);
			this->CDownLoad1->TabIndex = 101;
			this->CDownLoad1->TabStop = true;
			this->CDownLoad1->Text = S"ダウンロード";
			this->CDownLoad1->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, CDownLoad1_LinkClicked);
			// 
			// groupBox46
			// 
			this->groupBox46->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox46->Location = System::Drawing::Point(24, 1272);
			this->groupBox46->Name = S"groupBox46";
			this->groupBox46->Size = System::Drawing::Size(448, 9);
			this->groupBox46->TabIndex = 104;
			this->groupBox46->TabStop = false;
			// 
			// groupBox47
			// 
			this->groupBox47->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox47->Location = System::Drawing::Point(24, 800);
			this->groupBox47->Name = S"groupBox47";
			this->groupBox47->Size = System::Drawing::Size(448, 9);
			this->groupBox47->TabIndex = 100;
			this->groupBox47->TabStop = false;
			// 
			// label104
			// 
			this->label104->AutoSize = true;
			this->label104->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label104->Location = System::Drawing::Point(32, 784);
			this->label104->Name = S"label104";
			this->label104->Size = System::Drawing::Size(86, 19);
			this->label104->TabIndex = 97;
			this->label104->Text = S"EXステージ7";
			// 
			// SDownLoad20
			// 
			this->SDownLoad20->AutoSize = true;
			this->SDownLoad20->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDownLoad20->Location = System::Drawing::Point(384, 784);
			this->SDownLoad20->Name = S"SDownLoad20";
			this->SDownLoad20->Size = System::Drawing::Size(80, 19);
			this->SDownLoad20->TabIndex = 96;
			this->SDownLoad20->TabStop = true;
			this->SDownLoad20->Text = S"ダウンロード";
			this->SDownLoad20->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDownLoad20_LinkClicked);
			// 
			// label106
			// 
			this->label106->AutoSize = true;
			this->label106->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label106->Location = System::Drawing::Point(32, 744);
			this->label106->Name = S"label106";
			this->label106->Size = System::Drawing::Size(86, 19);
			this->label106->TabIndex = 92;
			this->label106->Text = S"EXステージ6";
			// 
			// SDownLoad19
			// 
			this->SDownLoad19->AutoSize = true;
			this->SDownLoad19->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDownLoad19->Location = System::Drawing::Point(384, 744);
			this->SDownLoad19->Name = S"SDownLoad19";
			this->SDownLoad19->Size = System::Drawing::Size(80, 19);
			this->SDownLoad19->TabIndex = 91;
			this->SDownLoad19->TabStop = true;
			this->SDownLoad19->Text = S"ダウンロード";
			this->SDownLoad19->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDownLoad19_LinkClicked);
			// 
			// groupBox48
			// 
			this->groupBox48->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox48->Location = System::Drawing::Point(24, 760);
			this->groupBox48->Name = S"groupBox48";
			this->groupBox48->Size = System::Drawing::Size(448, 9);
			this->groupBox48->TabIndex = 94;
			this->groupBox48->TabStop = false;
			// 
			// label108
			// 
			this->label108->AutoSize = true;
			this->label108->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label108->Location = System::Drawing::Point(32, 704);
			this->label108->Name = S"label108";
			this->label108->Size = System::Drawing::Size(86, 19);
			this->label108->TabIndex = 87;
			this->label108->Text = S"EXステージ5";
			// 
			// SDownLoad18
			// 
			this->SDownLoad18->AutoSize = true;
			this->SDownLoad18->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDownLoad18->Location = System::Drawing::Point(384, 704);
			this->SDownLoad18->Name = S"SDownLoad18";
			this->SDownLoad18->Size = System::Drawing::Size(80, 19);
			this->SDownLoad18->TabIndex = 86;
			this->SDownLoad18->TabStop = true;
			this->SDownLoad18->Text = S"ダウンロード";
			this->SDownLoad18->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDownLoad18_LinkClicked);
			// 
			// groupBox49
			// 
			this->groupBox49->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox49->Location = System::Drawing::Point(24, 720);
			this->groupBox49->Name = S"groupBox49";
			this->groupBox49->Size = System::Drawing::Size(448, 9);
			this->groupBox49->TabIndex = 89;
			this->groupBox49->TabStop = false;
			// 
			// label110
			// 
			this->label110->AutoSize = true;
			this->label110->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label110->Location = System::Drawing::Point(32, 664);
			this->label110->Name = S"label110";
			this->label110->Size = System::Drawing::Size(86, 19);
			this->label110->TabIndex = 82;
			this->label110->Text = S"EXステージ4";
			// 
			// SDownLoad17
			// 
			this->SDownLoad17->AutoSize = true;
			this->SDownLoad17->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDownLoad17->Location = System::Drawing::Point(384, 664);
			this->SDownLoad17->Name = S"SDownLoad17";
			this->SDownLoad17->Size = System::Drawing::Size(80, 19);
			this->SDownLoad17->TabIndex = 81;
			this->SDownLoad17->TabStop = true;
			this->SDownLoad17->Text = S"ダウンロード";
			this->SDownLoad17->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDownLoad17_LinkClicked);
			// 
			// groupBox50
			// 
			this->groupBox50->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox50->Location = System::Drawing::Point(24, 680);
			this->groupBox50->Name = S"groupBox50";
			this->groupBox50->Size = System::Drawing::Size(448, 9);
			this->groupBox50->TabIndex = 84;
			this->groupBox50->TabStop = false;
			// 
			// label112
			// 
			this->label112->AutoSize = true;
			this->label112->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label112->Location = System::Drawing::Point(32, 624);
			this->label112->Name = S"label112";
			this->label112->Size = System::Drawing::Size(86, 19);
			this->label112->TabIndex = 77;
			this->label112->Text = S"EXステージ3";
			// 
			// SDownLoad16
			// 
			this->SDownLoad16->AutoSize = true;
			this->SDownLoad16->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDownLoad16->Location = System::Drawing::Point(384, 624);
			this->SDownLoad16->Name = S"SDownLoad16";
			this->SDownLoad16->Size = System::Drawing::Size(80, 19);
			this->SDownLoad16->TabIndex = 76;
			this->SDownLoad16->TabStop = true;
			this->SDownLoad16->Text = S"ダウンロード";
			this->SDownLoad16->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDownLoad16_LinkClicked);
			// 
			// groupBox51
			// 
			this->groupBox51->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox51->Location = System::Drawing::Point(24, 640);
			this->groupBox51->Name = S"groupBox51";
			this->groupBox51->Size = System::Drawing::Size(448, 9);
			this->groupBox51->TabIndex = 79;
			this->groupBox51->TabStop = false;
			// 
			// label114
			// 
			this->label114->AutoSize = true;
			this->label114->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label114->Location = System::Drawing::Point(32, 584);
			this->label114->Name = S"label114";
			this->label114->Size = System::Drawing::Size(86, 19);
			this->label114->TabIndex = 72;
			this->label114->Text = S"EXステージ2";
			// 
			// SDownLoad15
			// 
			this->SDownLoad15->AutoSize = true;
			this->SDownLoad15->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDownLoad15->Location = System::Drawing::Point(384, 584);
			this->SDownLoad15->Name = S"SDownLoad15";
			this->SDownLoad15->Size = System::Drawing::Size(80, 19);
			this->SDownLoad15->TabIndex = 71;
			this->SDownLoad15->TabStop = true;
			this->SDownLoad15->Text = S"ダウンロード";
			this->SDownLoad15->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDownLoad15_LinkClicked);
			// 
			// groupBox52
			// 
			this->groupBox52->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox52->Location = System::Drawing::Point(24, 600);
			this->groupBox52->Name = S"groupBox52";
			this->groupBox52->Size = System::Drawing::Size(448, 9);
			this->groupBox52->TabIndex = 74;
			this->groupBox52->TabStop = false;
			// 
			// label116
			// 
			this->label116->AutoSize = true;
			this->label116->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label116->Location = System::Drawing::Point(32, 544);
			this->label116->Name = S"label116";
			this->label116->Size = System::Drawing::Size(86, 19);
			this->label116->TabIndex = 67;
			this->label116->Text = S"EXステージ1";
			// 
			// SDownLoad14
			// 
			this->SDownLoad14->AutoSize = true;
			this->SDownLoad14->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDownLoad14->Location = System::Drawing::Point(384, 544);
			this->SDownLoad14->Name = S"SDownLoad14";
			this->SDownLoad14->Size = System::Drawing::Size(80, 19);
			this->SDownLoad14->TabIndex = 66;
			this->SDownLoad14->TabStop = true;
			this->SDownLoad14->Text = S"ダウンロード";
			this->SDownLoad14->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDownLoad14_LinkClicked);
			// 
			// groupBox53
			// 
			this->groupBox53->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox53->Location = System::Drawing::Point(24, 560);
			this->groupBox53->Name = S"groupBox53";
			this->groupBox53->Size = System::Drawing::Size(448, 9);
			this->groupBox53->TabIndex = 69;
			this->groupBox53->TabStop = false;
			// 
			// label118
			// 
			this->label118->AutoSize = true;
			this->label118->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label118->Location = System::Drawing::Point(32, 504);
			this->label118->Name = S"label118";
			this->label118->Size = System::Drawing::Size(75, 19);
			this->label118->TabIndex = 62;
			this->label118->Text = S"ステージ13";
			// 
			// SDownLoad13
			// 
			this->SDownLoad13->AutoSize = true;
			this->SDownLoad13->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDownLoad13->Location = System::Drawing::Point(384, 504);
			this->SDownLoad13->Name = S"SDownLoad13";
			this->SDownLoad13->Size = System::Drawing::Size(80, 19);
			this->SDownLoad13->TabIndex = 61;
			this->SDownLoad13->TabStop = true;
			this->SDownLoad13->Text = S"ダウンロード";
			this->SDownLoad13->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDownLoad13_LinkClicked);
			// 
			// groupBox54
			// 
			this->groupBox54->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox54->Location = System::Drawing::Point(24, 520);
			this->groupBox54->Name = S"groupBox54";
			this->groupBox54->Size = System::Drawing::Size(448, 9);
			this->groupBox54->TabIndex = 64;
			this->groupBox54->TabStop = false;
			// 
			// label120
			// 
			this->label120->AutoSize = true;
			this->label120->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label120->Location = System::Drawing::Point(32, 464);
			this->label120->Name = S"label120";
			this->label120->Size = System::Drawing::Size(75, 19);
			this->label120->TabIndex = 57;
			this->label120->Text = S"ステージ12";
			// 
			// SDownLoad12
			// 
			this->SDownLoad12->AutoSize = true;
			this->SDownLoad12->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDownLoad12->Location = System::Drawing::Point(384, 464);
			this->SDownLoad12->Name = S"SDownLoad12";
			this->SDownLoad12->Size = System::Drawing::Size(80, 19);
			this->SDownLoad12->TabIndex = 56;
			this->SDownLoad12->TabStop = true;
			this->SDownLoad12->Text = S"ダウンロード";
			this->SDownLoad12->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDownLoad12_LinkClicked);
			// 
			// groupBox55
			// 
			this->groupBox55->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox55->Location = System::Drawing::Point(24, 480);
			this->groupBox55->Name = S"groupBox55";
			this->groupBox55->Size = System::Drawing::Size(448, 9);
			this->groupBox55->TabIndex = 59;
			this->groupBox55->TabStop = false;
			// 
			// label122
			// 
			this->label122->AutoSize = true;
			this->label122->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label122->Location = System::Drawing::Point(32, 424);
			this->label122->Name = S"label122";
			this->label122->Size = System::Drawing::Size(75, 19);
			this->label122->TabIndex = 52;
			this->label122->Text = S"ステージ11";
			// 
			// SDownLoad11
			// 
			this->SDownLoad11->AutoSize = true;
			this->SDownLoad11->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDownLoad11->Location = System::Drawing::Point(384, 424);
			this->SDownLoad11->Name = S"SDownLoad11";
			this->SDownLoad11->Size = System::Drawing::Size(80, 19);
			this->SDownLoad11->TabIndex = 51;
			this->SDownLoad11->TabStop = true;
			this->SDownLoad11->Text = S"ダウンロード";
			this->SDownLoad11->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDownLoad11_LinkClicked);
			// 
			// groupBox56
			// 
			this->groupBox56->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox56->Location = System::Drawing::Point(24, 440);
			this->groupBox56->Name = S"groupBox56";
			this->groupBox56->Size = System::Drawing::Size(448, 9);
			this->groupBox56->TabIndex = 54;
			this->groupBox56->TabStop = false;
			// 
			// label124
			// 
			this->label124->AutoSize = true;
			this->label124->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label124->Location = System::Drawing::Point(32, 384);
			this->label124->Name = S"label124";
			this->label124->Size = System::Drawing::Size(75, 19);
			this->label124->TabIndex = 47;
			this->label124->Text = S"ステージ10";
			// 
			// SDownLoad10
			// 
			this->SDownLoad10->AutoSize = true;
			this->SDownLoad10->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDownLoad10->Location = System::Drawing::Point(384, 384);
			this->SDownLoad10->Name = S"SDownLoad10";
			this->SDownLoad10->Size = System::Drawing::Size(80, 19);
			this->SDownLoad10->TabIndex = 46;
			this->SDownLoad10->TabStop = true;
			this->SDownLoad10->Text = S"ダウンロード";
			this->SDownLoad10->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDownLoad10_LinkClicked);
			// 
			// groupBox57
			// 
			this->groupBox57->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox57->Location = System::Drawing::Point(24, 400);
			this->groupBox57->Name = S"groupBox57";
			this->groupBox57->Size = System::Drawing::Size(448, 9);
			this->groupBox57->TabIndex = 49;
			this->groupBox57->TabStop = false;
			// 
			// label126
			// 
			this->label126->AutoSize = true;
			this->label126->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label126->Location = System::Drawing::Point(32, 344);
			this->label126->Name = S"label126";
			this->label126->Size = System::Drawing::Size(66, 19);
			this->label126->TabIndex = 42;
			this->label126->Text = S"ステージ9";
			// 
			// SDownLoad9
			// 
			this->SDownLoad9->AutoSize = true;
			this->SDownLoad9->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDownLoad9->Location = System::Drawing::Point(384, 344);
			this->SDownLoad9->Name = S"SDownLoad9";
			this->SDownLoad9->Size = System::Drawing::Size(80, 19);
			this->SDownLoad9->TabIndex = 41;
			this->SDownLoad9->TabStop = true;
			this->SDownLoad9->Text = S"ダウンロード";
			this->SDownLoad9->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDownLoad9_LinkClicked);
			// 
			// groupBox58
			// 
			this->groupBox58->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox58->Location = System::Drawing::Point(24, 360);
			this->groupBox58->Name = S"groupBox58";
			this->groupBox58->Size = System::Drawing::Size(448, 9);
			this->groupBox58->TabIndex = 44;
			this->groupBox58->TabStop = false;
			// 
			// label128
			// 
			this->label128->AutoSize = true;
			this->label128->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label128->Location = System::Drawing::Point(32, 304);
			this->label128->Name = S"label128";
			this->label128->Size = System::Drawing::Size(66, 19);
			this->label128->TabIndex = 37;
			this->label128->Text = S"ステージ8";
			// 
			// SDownLoad8
			// 
			this->SDownLoad8->AutoSize = true;
			this->SDownLoad8->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDownLoad8->Location = System::Drawing::Point(384, 304);
			this->SDownLoad8->Name = S"SDownLoad8";
			this->SDownLoad8->Size = System::Drawing::Size(80, 19);
			this->SDownLoad8->TabIndex = 36;
			this->SDownLoad8->TabStop = true;
			this->SDownLoad8->Text = S"ダウンロード";
			this->SDownLoad8->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDownLoad8_LinkClicked);
			// 
			// groupBox59
			// 
			this->groupBox59->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox59->Location = System::Drawing::Point(24, 320);
			this->groupBox59->Name = S"groupBox59";
			this->groupBox59->Size = System::Drawing::Size(448, 9);
			this->groupBox59->TabIndex = 39;
			this->groupBox59->TabStop = false;
			// 
			// label130
			// 
			this->label130->AutoSize = true;
			this->label130->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label130->Location = System::Drawing::Point(32, 264);
			this->label130->Name = S"label130";
			this->label130->Size = System::Drawing::Size(66, 19);
			this->label130->TabIndex = 32;
			this->label130->Text = S"ステージ7";
			// 
			// SDownLoad7
			// 
			this->SDownLoad7->AutoSize = true;
			this->SDownLoad7->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDownLoad7->Location = System::Drawing::Point(384, 264);
			this->SDownLoad7->Name = S"SDownLoad7";
			this->SDownLoad7->Size = System::Drawing::Size(80, 19);
			this->SDownLoad7->TabIndex = 31;
			this->SDownLoad7->TabStop = true;
			this->SDownLoad7->Text = S"ダウンロード";
			this->SDownLoad7->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDownLoad7_LinkClicked);
			// 
			// groupBox60
			// 
			this->groupBox60->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox60->Location = System::Drawing::Point(24, 280);
			this->groupBox60->Name = S"groupBox60";
			this->groupBox60->Size = System::Drawing::Size(448, 9);
			this->groupBox60->TabIndex = 34;
			this->groupBox60->TabStop = false;
			// 
			// label132
			// 
			this->label132->AutoSize = true;
			this->label132->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label132->Location = System::Drawing::Point(32, 224);
			this->label132->Name = S"label132";
			this->label132->Size = System::Drawing::Size(66, 19);
			this->label132->TabIndex = 27;
			this->label132->Text = S"ステージ6";
			// 
			// SDownLoad6
			// 
			this->SDownLoad6->AutoSize = true;
			this->SDownLoad6->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDownLoad6->Location = System::Drawing::Point(384, 224);
			this->SDownLoad6->Name = S"SDownLoad6";
			this->SDownLoad6->Size = System::Drawing::Size(80, 19);
			this->SDownLoad6->TabIndex = 26;
			this->SDownLoad6->TabStop = true;
			this->SDownLoad6->Text = S"ダウンロード";
			this->SDownLoad6->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDownLoad6_LinkClicked);
			// 
			// groupBox61
			// 
			this->groupBox61->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox61->Location = System::Drawing::Point(24, 240);
			this->groupBox61->Name = S"groupBox61";
			this->groupBox61->Size = System::Drawing::Size(448, 9);
			this->groupBox61->TabIndex = 29;
			this->groupBox61->TabStop = false;
			// 
			// label134
			// 
			this->label134->AutoSize = true;
			this->label134->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label134->Location = System::Drawing::Point(32, 184);
			this->label134->Name = S"label134";
			this->label134->Size = System::Drawing::Size(66, 19);
			this->label134->TabIndex = 22;
			this->label134->Text = S"ステージ5";
			// 
			// SDownLoad5
			// 
			this->SDownLoad5->AutoSize = true;
			this->SDownLoad5->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDownLoad5->Location = System::Drawing::Point(384, 184);
			this->SDownLoad5->Name = S"SDownLoad5";
			this->SDownLoad5->Size = System::Drawing::Size(80, 19);
			this->SDownLoad5->TabIndex = 21;
			this->SDownLoad5->TabStop = true;
			this->SDownLoad5->Text = S"ダウンロード";
			this->SDownLoad5->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDownLoad5_LinkClicked);
			// 
			// groupBox62
			// 
			this->groupBox62->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox62->Location = System::Drawing::Point(24, 200);
			this->groupBox62->Name = S"groupBox62";
			this->groupBox62->Size = System::Drawing::Size(448, 9);
			this->groupBox62->TabIndex = 24;
			this->groupBox62->TabStop = false;
			// 
			// label136
			// 
			this->label136->AutoSize = true;
			this->label136->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label136->Location = System::Drawing::Point(32, 144);
			this->label136->Name = S"label136";
			this->label136->Size = System::Drawing::Size(66, 19);
			this->label136->TabIndex = 17;
			this->label136->Text = S"ステージ4";
			// 
			// SDownLoad4
			// 
			this->SDownLoad4->AutoSize = true;
			this->SDownLoad4->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDownLoad4->Location = System::Drawing::Point(384, 144);
			this->SDownLoad4->Name = S"SDownLoad4";
			this->SDownLoad4->Size = System::Drawing::Size(80, 19);
			this->SDownLoad4->TabIndex = 16;
			this->SDownLoad4->TabStop = true;
			this->SDownLoad4->Text = S"ダウンロード";
			this->SDownLoad4->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDownLoad4_LinkClicked);
			// 
			// groupBox63
			// 
			this->groupBox63->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox63->Location = System::Drawing::Point(24, 160);
			this->groupBox63->Name = S"groupBox63";
			this->groupBox63->Size = System::Drawing::Size(448, 9);
			this->groupBox63->TabIndex = 19;
			this->groupBox63->TabStop = false;
			// 
			// label138
			// 
			this->label138->AutoSize = true;
			this->label138->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label138->Location = System::Drawing::Point(32, 104);
			this->label138->Name = S"label138";
			this->label138->Size = System::Drawing::Size(66, 19);
			this->label138->TabIndex = 12;
			this->label138->Text = S"ステージ3";
			// 
			// SDownLoad3
			// 
			this->SDownLoad3->AutoSize = true;
			this->SDownLoad3->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDownLoad3->Location = System::Drawing::Point(384, 104);
			this->SDownLoad3->Name = S"SDownLoad3";
			this->SDownLoad3->Size = System::Drawing::Size(80, 19);
			this->SDownLoad3->TabIndex = 11;
			this->SDownLoad3->TabStop = true;
			this->SDownLoad3->Text = S"ダウンロード";
			this->SDownLoad3->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDownLoad3_LinkClicked);
			// 
			// groupBox64
			// 
			this->groupBox64->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox64->Location = System::Drawing::Point(24, 120);
			this->groupBox64->Name = S"groupBox64";
			this->groupBox64->Size = System::Drawing::Size(448, 9);
			this->groupBox64->TabIndex = 14;
			this->groupBox64->TabStop = false;
			// 
			// label140
			// 
			this->label140->AutoSize = true;
			this->label140->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label140->Location = System::Drawing::Point(32, 64);
			this->label140->Name = S"label140";
			this->label140->Size = System::Drawing::Size(66, 19);
			this->label140->TabIndex = 7;
			this->label140->Text = S"ステージ2";
			// 
			// SDownLoad2
			// 
			this->SDownLoad2->AutoSize = true;
			this->SDownLoad2->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDownLoad2->Location = System::Drawing::Point(384, 64);
			this->SDownLoad2->Name = S"SDownLoad2";
			this->SDownLoad2->Size = System::Drawing::Size(80, 19);
			this->SDownLoad2->TabIndex = 6;
			this->SDownLoad2->TabStop = true;
			this->SDownLoad2->Text = S"ダウンロード";
			this->SDownLoad2->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDownLoad2_LinkClicked);
			// 
			// groupBox65
			// 
			this->groupBox65->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox65->Location = System::Drawing::Point(24, 80);
			this->groupBox65->Name = S"groupBox65";
			this->groupBox65->Size = System::Drawing::Size(448, 9);
			this->groupBox65->TabIndex = 9;
			this->groupBox65->TabStop = false;
			// 
			// label142
			// 
			this->label142->AutoSize = true;
			this->label142->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label142->Location = System::Drawing::Point(32, 24);
			this->label142->Name = S"label142";
			this->label142->Size = System::Drawing::Size(66, 19);
			this->label142->TabIndex = 2;
			this->label142->Text = S"ステージ1";
			// 
			// SDownLoad1
			// 
			this->SDownLoad1->AutoSize = true;
			this->SDownLoad1->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->SDownLoad1->Location = System::Drawing::Point(384, 24);
			this->SDownLoad1->Name = S"SDownLoad1";
			this->SDownLoad1->Size = System::Drawing::Size(80, 19);
			this->SDownLoad1->TabIndex = 1;
			this->SDownLoad1->TabStop = true;
			this->SDownLoad1->Text = S"ダウンロード";
			this->SDownLoad1->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SDownLoad1_LinkClicked);
			// 
			// groupBox66
			// 
			this->groupBox66->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->groupBox66->Location = System::Drawing::Point(24, 40);
			this->groupBox66->Name = S"groupBox66";
			this->groupBox66->Size = System::Drawing::Size(448, 9);
			this->groupBox66->TabIndex = 4;
			this->groupBox66->TabStop = false;
			// 
			// ONCTime12
			// 
			this->ONCTime12->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONCTime12->Location = System::Drawing::Point(296, 1696);
			this->ONCTime12->Name = S"ONCTime12";
			this->ONCTime12->Size = System::Drawing::Size(80, 19);
			this->ONCTime12->TabIndex = 160;
			this->ONCTime12->Text = S"0：0";
			this->ONCTime12->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONCTime11
			// 
			this->ONCTime11->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONCTime11->Location = System::Drawing::Point(296, 1656);
			this->ONCTime11->Name = S"ONCTime11";
			this->ONCTime11->Size = System::Drawing::Size(80, 19);
			this->ONCTime11->TabIndex = 155;
			this->ONCTime11->Text = S"0：0";
			this->ONCTime11->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONCTime10
			// 
			this->ONCTime10->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONCTime10->Location = System::Drawing::Point(296, 1616);
			this->ONCTime10->Name = S"ONCTime10";
			this->ONCTime10->Size = System::Drawing::Size(80, 19);
			this->ONCTime10->TabIndex = 150;
			this->ONCTime10->Text = S"0：0";
			this->ONCTime10->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONCTime9
			// 
			this->ONCTime9->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONCTime9->Location = System::Drawing::Point(296, 1576);
			this->ONCTime9->Name = S"ONCTime9";
			this->ONCTime9->Size = System::Drawing::Size(80, 19);
			this->ONCTime9->TabIndex = 145;
			this->ONCTime9->Text = S"0：0";
			this->ONCTime9->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONCTime8
			// 
			this->ONCTime8->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONCTime8->Location = System::Drawing::Point(296, 1536);
			this->ONCTime8->Name = S"ONCTime8";
			this->ONCTime8->Size = System::Drawing::Size(80, 19);
			this->ONCTime8->TabIndex = 140;
			this->ONCTime8->Text = S"0：0";
			this->ONCTime8->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONCTime7
			// 
			this->ONCTime7->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONCTime7->Location = System::Drawing::Point(296, 1496);
			this->ONCTime7->Name = S"ONCTime7";
			this->ONCTime7->Size = System::Drawing::Size(80, 19);
			this->ONCTime7->TabIndex = 135;
			this->ONCTime7->Text = S"0：0";
			this->ONCTime7->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONCTime6
			// 
			this->ONCTime6->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONCTime6->Location = System::Drawing::Point(296, 1456);
			this->ONCTime6->Name = S"ONCTime6";
			this->ONCTime6->Size = System::Drawing::Size(80, 19);
			this->ONCTime6->TabIndex = 130;
			this->ONCTime6->Text = S"0：0";
			this->ONCTime6->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONCTime5
			// 
			this->ONCTime5->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONCTime5->Location = System::Drawing::Point(296, 1416);
			this->ONCTime5->Name = S"ONCTime5";
			this->ONCTime5->Size = System::Drawing::Size(80, 19);
			this->ONCTime5->TabIndex = 125;
			this->ONCTime5->Text = S"0：0";
			this->ONCTime5->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONCTime4
			// 
			this->ONCTime4->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONCTime4->Location = System::Drawing::Point(296, 1376);
			this->ONCTime4->Name = S"ONCTime4";
			this->ONCTime4->Size = System::Drawing::Size(80, 19);
			this->ONCTime4->TabIndex = 120;
			this->ONCTime4->Text = S"0：0";
			this->ONCTime4->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONCTime3
			// 
			this->ONCTime3->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONCTime3->Location = System::Drawing::Point(296, 1336);
			this->ONCTime3->Name = S"ONCTime3";
			this->ONCTime3->Size = System::Drawing::Size(80, 19);
			this->ONCTime3->TabIndex = 115;
			this->ONCTime3->Text = S"0：0";
			this->ONCTime3->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONCTime2
			// 
			this->ONCTime2->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONCTime2->Location = System::Drawing::Point(296, 1296);
			this->ONCTime2->Name = S"ONCTime2";
			this->ONCTime2->Size = System::Drawing::Size(80, 19);
			this->ONCTime2->TabIndex = 110;
			this->ONCTime2->Text = S"0：0";
			this->ONCTime2->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONCTime1
			// 
			this->ONCTime1->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONCTime1->Location = System::Drawing::Point(296, 1256);
			this->ONCTime1->Name = S"ONCTime1";
			this->ONCTime1->Size = System::Drawing::Size(80, 19);
			this->ONCTime1->TabIndex = 105;
			this->ONCTime1->Text = S"0：0";
			this->ONCTime1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONSTime20
			// 
			this->ONSTime20->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONSTime20->Location = System::Drawing::Point(296, 784);
			this->ONSTime20->Name = S"ONSTime20";
			this->ONSTime20->Size = System::Drawing::Size(80, 19);
			this->ONSTime20->TabIndex = 99;
			this->ONSTime20->Text = S"0：0";
			this->ONSTime20->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONSTime19
			// 
			this->ONSTime19->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONSTime19->Location = System::Drawing::Point(296, 744);
			this->ONSTime19->Name = S"ONSTime19";
			this->ONSTime19->Size = System::Drawing::Size(80, 19);
			this->ONSTime19->TabIndex = 95;
			this->ONSTime19->Text = S"0：0";
			this->ONSTime19->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONSTime18
			// 
			this->ONSTime18->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONSTime18->Location = System::Drawing::Point(296, 704);
			this->ONSTime18->Name = S"ONSTime18";
			this->ONSTime18->Size = System::Drawing::Size(80, 19);
			this->ONSTime18->TabIndex = 90;
			this->ONSTime18->Text = S"0：0";
			this->ONSTime18->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONSTime17
			// 
			this->ONSTime17->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONSTime17->Location = System::Drawing::Point(296, 664);
			this->ONSTime17->Name = S"ONSTime17";
			this->ONSTime17->Size = System::Drawing::Size(80, 19);
			this->ONSTime17->TabIndex = 85;
			this->ONSTime17->Text = S"0：0";
			this->ONSTime17->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONSTime16
			// 
			this->ONSTime16->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONSTime16->Location = System::Drawing::Point(296, 624);
			this->ONSTime16->Name = S"ONSTime16";
			this->ONSTime16->Size = System::Drawing::Size(80, 19);
			this->ONSTime16->TabIndex = 80;
			this->ONSTime16->Text = S"0：0";
			this->ONSTime16->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONSTime15
			// 
			this->ONSTime15->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONSTime15->Location = System::Drawing::Point(296, 584);
			this->ONSTime15->Name = S"ONSTime15";
			this->ONSTime15->Size = System::Drawing::Size(80, 19);
			this->ONSTime15->TabIndex = 75;
			this->ONSTime15->Text = S"0：0";
			this->ONSTime15->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONSTime14
			// 
			this->ONSTime14->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONSTime14->Location = System::Drawing::Point(296, 544);
			this->ONSTime14->Name = S"ONSTime14";
			this->ONSTime14->Size = System::Drawing::Size(80, 19);
			this->ONSTime14->TabIndex = 70;
			this->ONSTime14->Text = S"0：0";
			this->ONSTime14->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONSTime13
			// 
			this->ONSTime13->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONSTime13->Location = System::Drawing::Point(296, 504);
			this->ONSTime13->Name = S"ONSTime13";
			this->ONSTime13->Size = System::Drawing::Size(80, 19);
			this->ONSTime13->TabIndex = 65;
			this->ONSTime13->Text = S"0：0";
			this->ONSTime13->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONSTime12
			// 
			this->ONSTime12->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONSTime12->Location = System::Drawing::Point(296, 464);
			this->ONSTime12->Name = S"ONSTime12";
			this->ONSTime12->Size = System::Drawing::Size(80, 19);
			this->ONSTime12->TabIndex = 60;
			this->ONSTime12->Text = S"0：0";
			this->ONSTime12->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONSTime11
			// 
			this->ONSTime11->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONSTime11->Location = System::Drawing::Point(296, 424);
			this->ONSTime11->Name = S"ONSTime11";
			this->ONSTime11->Size = System::Drawing::Size(80, 19);
			this->ONSTime11->TabIndex = 55;
			this->ONSTime11->Text = S"0：0";
			this->ONSTime11->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONSTime10
			// 
			this->ONSTime10->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONSTime10->Location = System::Drawing::Point(296, 384);
			this->ONSTime10->Name = S"ONSTime10";
			this->ONSTime10->Size = System::Drawing::Size(80, 19);
			this->ONSTime10->TabIndex = 50;
			this->ONSTime10->Text = S"0：0";
			this->ONSTime10->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONSTime9
			// 
			this->ONSTime9->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONSTime9->Location = System::Drawing::Point(296, 344);
			this->ONSTime9->Name = S"ONSTime9";
			this->ONSTime9->Size = System::Drawing::Size(80, 19);
			this->ONSTime9->TabIndex = 45;
			this->ONSTime9->Text = S"0：0";
			this->ONSTime9->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONSTime8
			// 
			this->ONSTime8->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONSTime8->Location = System::Drawing::Point(296, 304);
			this->ONSTime8->Name = S"ONSTime8";
			this->ONSTime8->Size = System::Drawing::Size(80, 19);
			this->ONSTime8->TabIndex = 40;
			this->ONSTime8->Text = S"0：0";
			this->ONSTime8->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONSTime7
			// 
			this->ONSTime7->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONSTime7->Location = System::Drawing::Point(296, 264);
			this->ONSTime7->Name = S"ONSTime7";
			this->ONSTime7->Size = System::Drawing::Size(80, 19);
			this->ONSTime7->TabIndex = 35;
			this->ONSTime7->Text = S"0：0";
			this->ONSTime7->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONSTime6
			// 
			this->ONSTime6->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONSTime6->Location = System::Drawing::Point(296, 224);
			this->ONSTime6->Name = S"ONSTime6";
			this->ONSTime6->Size = System::Drawing::Size(80, 19);
			this->ONSTime6->TabIndex = 30;
			this->ONSTime6->Text = S"0：0";
			this->ONSTime6->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONSTime5
			// 
			this->ONSTime5->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONSTime5->Location = System::Drawing::Point(296, 184);
			this->ONSTime5->Name = S"ONSTime5";
			this->ONSTime5->Size = System::Drawing::Size(80, 19);
			this->ONSTime5->TabIndex = 25;
			this->ONSTime5->Text = S"0：0";
			this->ONSTime5->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONSTime4
			// 
			this->ONSTime4->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONSTime4->Location = System::Drawing::Point(296, 144);
			this->ONSTime4->Name = S"ONSTime4";
			this->ONSTime4->Size = System::Drawing::Size(80, 19);
			this->ONSTime4->TabIndex = 20;
			this->ONSTime4->Text = S"0：0";
			this->ONSTime4->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONSTime3
			// 
			this->ONSTime3->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONSTime3->Location = System::Drawing::Point(296, 104);
			this->ONSTime3->Name = S"ONSTime3";
			this->ONSTime3->Size = System::Drawing::Size(80, 19);
			this->ONSTime3->TabIndex = 15;
			this->ONSTime3->Text = S"0：0";
			this->ONSTime3->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONSTime2
			// 
			this->ONSTime2->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONSTime2->Location = System::Drawing::Point(296, 64);
			this->ONSTime2->Name = S"ONSTime2";
			this->ONSTime2->Size = System::Drawing::Size(80, 19);
			this->ONSTime2->TabIndex = 10;
			this->ONSTime2->Text = S"0：0";
			this->ONSTime2->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ONSTime1
			// 
			this->ONSTime1->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->ONSTime1->Location = System::Drawing::Point(296, 24);
			this->ONSTime1->Name = S"ONSTime1";
			this->ONSTime1->Size = System::Drawing::Size(80, 19);
			this->ONSTime1->TabIndex = 5;
			this->ONSTime1->Text = S"0：0";
			this->ONSTime1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// CName1
			// 
			this->CName1->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->CName1->Location = System::Drawing::Point(104, 1256);
			this->CName1->Name = S"CName1";
			this->CName1->Size = System::Drawing::Size(144, 19);
			this->CName1->TabIndex = 163;
			this->CName1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// KousinButton
			// 
			this->KousinButton->Location = System::Drawing::Point(456, 416);
			this->KousinButton->Name = S"KousinButton";
			this->KousinButton->Size = System::Drawing::Size(72, 24);
			this->KousinButton->TabIndex = 1;
			this->KousinButton->Text = S"更新";
			this->KousinButton->Click += new System::EventHandler(this, KousinButton_Click);
			// 
			// UserNameText
			// 
			this->UserNameText->Location = System::Drawing::Point(72, 416);
			this->UserNameText->MaxLength = 10;
			this->UserNameText->Name = S"UserNameText";
			this->UserNameText->Size = System::Drawing::Size(144, 19);
			this->UserNameText->TabIndex = 2;
			this->UserNameText->Text = S"";
			this->UserNameText->TextChanged += new System::EventHandler(this, UserNameText_TextChanged);
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(8, 400);
			this->label1->Name = S"label1";
			this->label1->Size = System::Drawing::Size(64, 56);
			this->label1->TabIndex = 3;
			this->label1->Text = S"ユーザー名";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Form1
			// 
			this->AutoScaleBaseSize = System::Drawing::Size(5, 12);
			this->ClientSize = System::Drawing::Size(534, 441);
			this->Controls->Add(this->UserNameText);
			this->Controls->Add(this->KousinButton);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (__try_cast<System::Drawing::Icon *  >(resources->GetObject(S"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = S"Form1";
			this->Text = S"ランキング";
			this->Load += new System::EventHandler(this, Form1_Load);
			this->tabControl1->ResumeLayout(false);
			this->OFFPage->ResumeLayout(false);
			this->ONPage->ResumeLayout(false);
			this->ResumeLayout(false);

		}	



#include "Event.h"


};
}


