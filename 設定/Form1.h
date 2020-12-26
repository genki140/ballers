#pragma once



#include<stdio.h>



/****************************************************************************
 *
 *      DirectInput keyboard scan codes
 *
 ****************************************************************************/
#define DIK_ESCAPE          0x01
#define DIK_1               0x02
#define DIK_2               0x03
#define DIK_3               0x04
#define DIK_4               0x05
#define DIK_5               0x06
#define DIK_6               0x07
#define DIK_7               0x08
#define DIK_8               0x09
#define DIK_9               0x0A
#define DIK_0               0x0B
#define DIK_MINUS           0x0C    /* - on main keyboard */
#define DIK_EQUALS          0x0D
#define DIK_BACK            0x0E    /* backspace */
#define DIK_TAB             0x0F
#define DIK_Q               0x10
#define DIK_W               0x11
#define DIK_E               0x12
#define DIK_R               0x13
#define DIK_T               0x14
#define DIK_Y               0x15
#define DIK_U               0x16
#define DIK_I               0x17
#define DIK_O               0x18
#define DIK_P               0x19
#define DIK_LBRACKET        0x1A
#define DIK_RBRACKET        0x1B
#define DIK_RETURN          0x1C    /* Enter on main keyboard */
#define DIK_LCONTROL        0x1D
#define DIK_A               0x1E
#define DIK_S               0x1F
#define DIK_D               0x20
#define DIK_F               0x21
#define DIK_G               0x22
#define DIK_H               0x23
#define DIK_J               0x24
#define DIK_K               0x25
#define DIK_L               0x26
#define DIK_SEMICOLON       0x27
#define DIK_APOSTROPHE      0x28
#define DIK_GRAVE           0x29    /* accent grave */
#define DIK_LSHIFT          0x2A
#define DIK_BACKSLASH       0x2B
#define DIK_Z               0x2C
#define DIK_X               0x2D
#define DIK_C               0x2E
#define DIK_V               0x2F
#define DIK_B               0x30
#define DIK_N               0x31
#define DIK_M               0x32
#define DIK_COMMA           0x33
#define DIK_PERIOD          0x34    /* . on main keyboard */
#define DIK_SLASH           0x35    /* / on main keyboard */
#define DIK_RSHIFT          0x36
#define DIK_MULTIPLY        0x37    /* * on numeric keypad */
#define DIK_LMENU           0x38    /* left Alt */
#define DIK_SPACE           0x39
#define DIK_CAPITAL         0x3A
#define DIK_F1              0x3B
#define DIK_F2              0x3C
#define DIK_F3              0x3D
#define DIK_F4              0x3E
#define DIK_F5              0x3F
#define DIK_F6              0x40
#define DIK_F7              0x41
#define DIK_F8              0x42
#define DIK_F9              0x43
#define DIK_F10             0x44
#define DIK_NUMLOCK         0x45
#define DIK_SCROLL          0x46    /* Scroll Lock */
#define DIK_NUMPAD7         0x47
#define DIK_NUMPAD8         0x48
#define DIK_NUMPAD9         0x49
#define DIK_SUBTRACT        0x4A    /* - on numeric keypad */
#define DIK_NUMPAD4         0x4B
#define DIK_NUMPAD5         0x4C
#define DIK_NUMPAD6         0x4D
#define DIK_ADD             0x4E    /* + on numeric keypad */
#define DIK_NUMPAD1         0x4F
#define DIK_NUMPAD2         0x50
#define DIK_NUMPAD3         0x51
#define DIK_NUMPAD0         0x52
#define DIK_DECIMAL         0x53    /* . on numeric keypad */
#define DIK_OEM_102         0x56    /* <> or \| on RT 102-key keyboard (Non-U.S.) */
#define DIK_F11             0x57
#define DIK_F12             0x58
#define DIK_F13             0x64    /*                     (NEC PC98) */
#define DIK_F14             0x65    /*                     (NEC PC98) */
#define DIK_F15             0x66    /*                     (NEC PC98) */
#define DIK_KANA            0x70    /* (Japanese keyboard)            */
#define DIK_ABNT_C1         0x73    /* /? on Brazilian keyboard */
#define DIK_CONVERT         0x79    /* (Japanese keyboard)            */
#define DIK_NOCONVERT       0x7B    /* (Japanese keyboard)            */
#define DIK_YEN             0x7D    /* (Japanese keyboard)            */
#define DIK_ABNT_C2         0x7E    /* Numpad . on Brazilian keyboard */
#define DIK_NUMPADEQUALS    0x8D    /* = on numeric keypad (NEC PC98) */
#define DIK_PREVTRACK       0x90    /* Previous Track (DIK_CIRCUMFLEX on Japanese keyboard) */
#define DIK_AT              0x91    /*                     (NEC PC98) */
#define DIK_COLON           0x92    /*                     (NEC PC98) */
#define DIK_UNDERLINE       0x93    /*                     (NEC PC98) */
#define DIK_KANJI           0x94    /* (Japanese keyboard)            */
#define DIK_STOP            0x95    /*                     (NEC PC98) */
#define DIK_AX              0x96    /*                     (Japan AX) */
#define DIK_UNLABELED       0x97    /*                        (J3100) */
#define DIK_NEXTTRACK       0x99    /* Next Track */
#define DIK_NUMPADENTER     0x9C    /* Enter on numeric keypad */
#define DIK_RCONTROL        0x9D
#define DIK_MUTE            0xA0    /* Mute */
#define DIK_CALCULATOR      0xA1    /* Calculator */
#define DIK_PLAYPAUSE       0xA2    /* Play / Pause */
#define DIK_MEDIASTOP       0xA4    /* Media Stop */
#define DIK_VOLUMEDOWN      0xAE    /* Volume - */
#define DIK_VOLUMEUP        0xB0    /* Volume + */
#define DIK_WEBHOME         0xB2    /* Web home */
#define DIK_NUMPADCOMMA     0xB3    /* , on numeric keypad (NEC PC98) */
#define DIK_DIVIDE          0xB5    /* / on numeric keypad */
#define DIK_SYSRQ           0xB7
#define DIK_RMENU           0xB8    /* right Alt */
#define DIK_PAUSE           0xC5    /* Pause */
#define DIK_HOME            0xC7    /* Home on arrow keypad */
#define DIK_UP              0xC8    /* UpArrow on arrow keypad */
#define DIK_PRIOR           0xC9    /* PgUp on arrow keypad */
#define DIK_LEFT            0xCB    /* LeftArrow on arrow keypad */
#define DIK_RIGHT           0xCD    /* RightArrow on arrow keypad */
#define DIK_END             0xCF    /* End on arrow keypad */
#define DIK_DOWN            0xD0    /* DownArrow on arrow keypad */
#define DIK_NEXT            0xD1    /* PgDn on arrow keypad */
#define DIK_INSERT          0xD2    /* Insert on arrow keypad */
#define DIK_DELETE          0xD3    /* Delete on arrow keypad */
#define DIK_LWIN            0xDB    /* Left Windows key */
#define DIK_RWIN            0xDC    /* Right Windows key */
#define DIK_APPS            0xDD    /* AppMenu key */
#define DIK_POWER           0xDE    /* System Power */
#define DIK_SLEEP           0xDF    /* System Sleep */
#define DIK_WAKE            0xE3    /* System Wake */
#define DIK_WEBSEARCH       0xE5    /* Web Search */
#define DIK_WEBFAVORITES    0xE6    /* Web Favorites */
#define DIK_WEBREFRESH      0xE7    /* Web Refresh */
#define DIK_WEBSTOP         0xE8    /* Web Stop */
#define DIK_WEBFORWARD      0xE9    /* Web Forward */
#define DIK_WEBBACK         0xEA    /* Web Back */
#define DIK_MYCOMPUTER      0xEB    /* My Computer */
#define DIK_MAIL            0xEC    /* Mail */
#define DIK_MEDIASELECT     0xED    /* Media Select */

/*
 *  Alternate names for keys, to facilitate transition from DOS.
 */
#define DIK_BACKSPACE       DIK_BACK            /* backspace */
#define DIK_NUMPADSTAR      DIK_MULTIPLY        /* * on numeric keypad */
#define DIK_LALT            DIK_LMENU           /* left Alt */
#define DIK_CAPSLOCK        DIK_CAPITAL         /* CapsLock */
#define DIK_NUMPADMINUS     DIK_SUBTRACT        /* - on numeric keypad */
#define DIK_NUMPADPLUS      DIK_ADD             /* + on numeric keypad */
#define DIK_NUMPADPERIOD    DIK_DECIMAL         /* . on numeric keypad */
#define DIK_NUMPADSLASH     DIK_DIVIDE          /* / on numeric keypad */
#define DIK_RALT            DIK_RMENU           /* right Alt */
#define DIK_UPARROW         DIK_UP              /* UpArrow on arrow keypad */
#define DIK_PGUP            DIK_PRIOR           /* PgUp on arrow keypad */
#define DIK_LEFTARROW       DIK_LEFT            /* LeftArrow on arrow keypad */
#define DIK_RIGHTARROW      DIK_RIGHT           /* RightArrow on arrow keypad */
#define DIK_DOWNARROW       DIK_DOWN            /* DownArrow on arrow keypad */
#define DIK_PGDN            DIK_NEXT            /* PgDn on arrow keypad */




//キー設定コンボボックスの番号と上の番号を関連づける変数
int getkey[100];






struct GameSetting
{
	int Key1p;//1Pがキーボード操作ならtrue
	bool only1p;//ほかの入力を受け付けるか

	bool BGM;
	bool Sound3D;//3Dサウンドをするか
	int SoundAlg;//0が最低、2が最高
	int SoundCommit;//何コマに1回更新するかを格納
	int SoundMultiCount;

	bool FullScreen;
	int FormWidth,FormHeight;
	int BufferWidth,BufferHeight;
	int BufferFormat;
	bool ShadeEnable;
	float KemuriMaxDis;//煙をどこまで表示するか
	float ItemMaxDis;//アイテムをどこまで表示するか
	bool MultiTextureEnable;
	bool MultiMeshEnable;
	float MultiMeshRat;//デフォルトの距離のどのくらいで消えるか
	bool FiltarEnable;
	bool MipmapEnable;
	bool MipmapFiltarEnable;
	float MipmapBias;//みっぷマップのバイアス
	bool EnvEnable;

	char ip[16];
	char port[7];
	bool IPKeep;
	bool PortKeep;

	int anti;
}setting;


struct keynumstruct//どのボタンがどのキーかを格納する構造体(-1)は設定なし
{

	//ボタン
	int ok;
	int cancel;
	int jump;
	int item;
	int start;
	int rightrote;//カメラ右に移動
	int leftrote;//カメラ左に移動

	//軸(キーボードの場合はボタン)
	int axis,axis2;//ジョイパッド用
	int up,down,left,right,up2,down2,left2,right2;//キーボード用、2はカメラ回転用

	float axisover,axisover2;//どこまでが軸を曲げてないことにするかを％で指定する(0～1)

	bool VibEnable;//バイブレーションの有無

}keynum[5];//[0]はキーボード用

int SelectCtrl;//選択してるコントローラ(キーボード=0)番号









namespace Setting
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

	private: System::Windows::Forms::Button *  Cancel;
	private: System::Windows::Forms::Button *  OK;




















	private: System::Windows::Forms::PictureBox *  pictureBox1;
	private: System::Windows::Forms::PictureBox *  pictureBox2;
	private: System::Windows::Forms::Label *  label1;
	private: System::Windows::Forms::Label *  label2;
	private: System::Windows::Forms::Label *  label3;

	private: System::Windows::Forms::Label *  label4;
	private: System::Windows::Forms::Label *  label5;
	private: System::Windows::Forms::LinkLabel *  SoundLink3;
	private: System::Windows::Forms::LinkLabel *  SoundLink2;
	private: System::Windows::Forms::LinkLabel *  SoundLink1;
	private: System::Windows::Forms::LinkLabel *  BGMLink;
	private: System::Windows::Forms::LinkLabel *  HPLink;


	private: System::Windows::Forms::CheckBox *  KeyCheck;




	private: System::Windows::Forms::GroupBox *  KeyGroup;

	private: System::Windows::Forms::ComboBox *  OKCombo;
	private: System::Windows::Forms::Label *  label6;
	private: System::Windows::Forms::Label *  label7;
	private: System::Windows::Forms::Label *  label8;
	private: System::Windows::Forms::Label *  label9;
	private: System::Windows::Forms::Label *  label10;
	private: System::Windows::Forms::Label *  label11;
	private: System::Windows::Forms::Label *  label12;
	private: System::Windows::Forms::ComboBox *  CancelCombo;
	private: System::Windows::Forms::ComboBox *  StartCombo;
	private: System::Windows::Forms::ComboBox *  JumpCombo;
	private: System::Windows::Forms::ComboBox *  ItemCombo;
	private: System::Windows::Forms::ComboBox *  RRoteCombo;
	private: System::Windows::Forms::ComboBox *  LRoteCombo;
	private: System::Windows::Forms::ComboBox *  UMoveCombo;
	private: System::Windows::Forms::Label *  label13;
	private: System::Windows::Forms::ComboBox *  DRoteCombo;
	private: System::Windows::Forms::ComboBox *  URoteCombo;
	private: System::Windows::Forms::Label *  label14;
	private: System::Windows::Forms::Label *  label15;
	private: System::Windows::Forms::ComboBox *  DMoveCombo;
	private: System::Windows::Forms::Label *  label16;
	private: System::Windows::Forms::ComboBox *  RMoveCombo;
	private: System::Windows::Forms::Label *  label17;
	private: System::Windows::Forms::ComboBox *  LMoveCombo;
	private: System::Windows::Forms::Label *  label18;
	private: System::Windows::Forms::CheckBox *  VibCheck;

	private: System::Windows::Forms::Label *  label28;

	private: System::Windows::Forms::Label *  label27;

	private: System::Windows::Forms::Label *  label26;






	private: System::Windows::Forms::Label *  label20;
	private: System::Windows::Forms::Label *  label21;
	private: System::Windows::Forms::Label *  label22;
	private: System::Windows::Forms::Label *  label23;
	private: System::Windows::Forms::Label *  label24;
	private: System::Windows::Forms::Label *  label25;
	private: System::Windows::Forms::ComboBox *  OKComboJ;
	private: System::Windows::Forms::Label *  label19;
	private: System::Windows::Forms::GroupBox *  JoyGroup;

	private: System::Windows::Forms::Label *  label29;


private: System::Windows::Forms::Label *  label30;

private: System::Windows::Forms::Label *  label31;

private: System::Windows::Forms::Label *  label32;
private: System::Windows::Forms::Label *  label33;

private: System::Windows::Forms::GroupBox *  groupBox1;
private: System::Windows::Forms::GroupBox *  groupBox2;



private: System::Windows::Forms::Label *  label34;


private: System::Windows::Forms::GroupBox *  groupBox3;
private: System::Windows::Forms::Label *  label35;



private: System::Windows::Forms::Label *  label36;
private: System::Windows::Forms::Label *  label37;
private: System::Windows::Forms::CheckBox *  ShadeCheck;
private: System::Windows::Forms::ComboBox *  PMeshCombo;
private: System::Windows::Forms::CheckBox *  MipFilterCheck;
private: System::Windows::Forms::ComboBox *  MipCombo;
private: System::Windows::Forms::CheckBox *  EnvCheck;
private: System::Windows::Forms::CheckBox *  TexMultiCheck;
private: System::Windows::Forms::CheckBox *  TexFilterCheck;
private: System::Windows::Forms::ComboBox *  BSizeCombo;
private: System::Windows::Forms::ComboBox *  FSizeCombo;
private: System::Windows::Forms::CheckBox *  FullCheck;

private: System::Windows::Forms::ComboBox *  SoundQuaCombo;
private: System::Windows::Forms::CheckBox *  Sound3DCheck;
private: System::Windows::Forms::RadioButton *  CtrlRadio4;
private: System::Windows::Forms::RadioButton *  CtrlRadio3;
private: System::Windows::Forms::RadioButton *  CtrlRadio2;
private: System::Windows::Forms::RadioButton *  CtrlRadio1;
private: System::Windows::Forms::ComboBox *  KemuriCombo;
private: System::Windows::Forms::ComboBox *  ColorCombo;
private: System::Windows::Forms::TabControl *  TabControl;
private: System::Windows::Forms::TabPage *  PageG;
private: System::Windows::Forms::TabPage *  PageS;

private: System::Windows::Forms::TabPage *  PageC;
private: System::Windows::Forms::TabPage *  PageV;
private: System::Windows::Forms::ComboBox *  SoundComCombo;


private: System::Windows::Forms::NumericUpDown *  MoveAxisNumeric;
private: System::Windows::Forms::NumericUpDown *  RoteAxisNumeric;

private: System::Windows::Forms::ComboBox *  MoveAxisComboJ;
private: System::Windows::Forms::ComboBox *  LRoteComboJ;
private: System::Windows::Forms::ComboBox *  RRoteComboJ;
private: System::Windows::Forms::ComboBox *  ItemComboJ;
private: System::Windows::Forms::ComboBox *  JumpComboJ;
private: System::Windows::Forms::ComboBox *  StartComboJ;
private: System::Windows::Forms::ComboBox *  CancelComboJ;
private: System::Windows::Forms::ComboBox *  RoteAxisComboJ;
private: System::Windows::Forms::CheckBox *  BGMCheck;
private: System::Windows::Forms::ComboBox *  ItemDisCombo;
private: System::Windows::Forms::Label *  label38;
private: System::Windows::Forms::ComboBox *  SoundMultiCombo;
private: System::Windows::Forms::Label *  label39;
private: System::Windows::Forms::CheckBox *  myselfcheck;
private: System::Windows::Forms::GroupBox *  groupBox4;
private: System::Windows::Forms::Button *  button1;
private: System::Windows::Forms::Button *  button2;
private: System::Windows::Forms::Label *  label40;
private: System::Windows::Forms::Button *  button3;
private: System::Windows::Forms::Label *  label41;
private: System::Windows::Forms::Button *  button4;
private: System::Windows::Forms::Button *  button5;
private: System::Windows::Forms::ComboBox *  anticombo;
private: System::Windows::Forms::Label *  label42;
private: System::Windows::Forms::TextBox *  IP1;
private: System::Windows::Forms::TextBox *  IP2;
private: System::Windows::Forms::TextBox *  IP3;
private: System::Windows::Forms::TextBox *  IP4;
private: System::Windows::Forms::TextBox *  Port;
private: System::Windows::Forms::CheckBox *  IPCheck;
private: System::Windows::Forms::CheckBox *  PortCheck;

















































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
			System::Resources::ResourceManager *  resources = new System::Resources::ResourceManager(__typeof(Setting::Form1));
			this->TabControl = new System::Windows::Forms::TabControl();
			this->PageG = new System::Windows::Forms::TabPage();
			this->groupBox4 = new System::Windows::Forms::GroupBox();
			this->button5 = new System::Windows::Forms::Button();
			this->button4 = new System::Windows::Forms::Button();
			this->label41 = new System::Windows::Forms::Label();
			this->button3 = new System::Windows::Forms::Button();
			this->button2 = new System::Windows::Forms::Button();
			this->button1 = new System::Windows::Forms::Button();
			this->label40 = new System::Windows::Forms::Label();
			this->groupBox3 = new System::Windows::Forms::GroupBox();
			this->anticombo = new System::Windows::Forms::ComboBox();
			this->label42 = new System::Windows::Forms::Label();
			this->ItemDisCombo = new System::Windows::Forms::ComboBox();
			this->label38 = new System::Windows::Forms::Label();
			this->KemuriCombo = new System::Windows::Forms::ComboBox();
			this->label36 = new System::Windows::Forms::Label();
			this->ShadeCheck = new System::Windows::Forms::CheckBox();
			this->PMeshCombo = new System::Windows::Forms::ComboBox();
			this->label35 = new System::Windows::Forms::Label();
			this->groupBox2 = new System::Windows::Forms::GroupBox();
			this->MipFilterCheck = new System::Windows::Forms::CheckBox();
			this->MipCombo = new System::Windows::Forms::ComboBox();
			this->label34 = new System::Windows::Forms::Label();
			this->EnvCheck = new System::Windows::Forms::CheckBox();
			this->TexMultiCheck = new System::Windows::Forms::CheckBox();
			this->TexFilterCheck = new System::Windows::Forms::CheckBox();
			this->groupBox1 = new System::Windows::Forms::GroupBox();
			this->ColorCombo = new System::Windows::Forms::ComboBox();
			this->label37 = new System::Windows::Forms::Label();
			this->label33 = new System::Windows::Forms::Label();
			this->BSizeCombo = new System::Windows::Forms::ComboBox();
			this->FSizeCombo = new System::Windows::Forms::ComboBox();
			this->FullCheck = new System::Windows::Forms::CheckBox();
			this->label32 = new System::Windows::Forms::Label();
			this->PageC = new System::Windows::Forms::TabPage();
			this->myselfcheck = new System::Windows::Forms::CheckBox();
			this->CtrlRadio4 = new System::Windows::Forms::RadioButton();
			this->CtrlRadio3 = new System::Windows::Forms::RadioButton();
			this->CtrlRadio2 = new System::Windows::Forms::RadioButton();
			this->CtrlRadio1 = new System::Windows::Forms::RadioButton();
			this->KeyCheck = new System::Windows::Forms::CheckBox();
			this->KeyGroup = new System::Windows::Forms::GroupBox();
			this->LMoveCombo = new System::Windows::Forms::ComboBox();
			this->label18 = new System::Windows::Forms::Label();
			this->RMoveCombo = new System::Windows::Forms::ComboBox();
			this->label17 = new System::Windows::Forms::Label();
			this->DMoveCombo = new System::Windows::Forms::ComboBox();
			this->label16 = new System::Windows::Forms::Label();
			this->DRoteCombo = new System::Windows::Forms::ComboBox();
			this->URoteCombo = new System::Windows::Forms::ComboBox();
			this->label14 = new System::Windows::Forms::Label();
			this->label15 = new System::Windows::Forms::Label();
			this->UMoveCombo = new System::Windows::Forms::ComboBox();
			this->label13 = new System::Windows::Forms::Label();
			this->LRoteCombo = new System::Windows::Forms::ComboBox();
			this->RRoteCombo = new System::Windows::Forms::ComboBox();
			this->ItemCombo = new System::Windows::Forms::ComboBox();
			this->JumpCombo = new System::Windows::Forms::ComboBox();
			this->StartCombo = new System::Windows::Forms::ComboBox();
			this->CancelCombo = new System::Windows::Forms::ComboBox();
			this->label12 = new System::Windows::Forms::Label();
			this->label11 = new System::Windows::Forms::Label();
			this->label10 = new System::Windows::Forms::Label();
			this->label9 = new System::Windows::Forms::Label();
			this->label8 = new System::Windows::Forms::Label();
			this->label7 = new System::Windows::Forms::Label();
			this->OKCombo = new System::Windows::Forms::ComboBox();
			this->label6 = new System::Windows::Forms::Label();
			this->JoyGroup = new System::Windows::Forms::GroupBox();
			this->MoveAxisNumeric = new System::Windows::Forms::NumericUpDown();
			this->label29 = new System::Windows::Forms::Label();
			this->VibCheck = new System::Windows::Forms::CheckBox();
			this->RoteAxisNumeric = new System::Windows::Forms::NumericUpDown();
			this->label28 = new System::Windows::Forms::Label();
			this->RoteAxisComboJ = new System::Windows::Forms::ComboBox();
			this->label27 = new System::Windows::Forms::Label();
			this->MoveAxisComboJ = new System::Windows::Forms::ComboBox();
			this->label26 = new System::Windows::Forms::Label();
			this->LRoteComboJ = new System::Windows::Forms::ComboBox();
			this->RRoteComboJ = new System::Windows::Forms::ComboBox();
			this->ItemComboJ = new System::Windows::Forms::ComboBox();
			this->JumpComboJ = new System::Windows::Forms::ComboBox();
			this->StartComboJ = new System::Windows::Forms::ComboBox();
			this->CancelComboJ = new System::Windows::Forms::ComboBox();
			this->label20 = new System::Windows::Forms::Label();
			this->label21 = new System::Windows::Forms::Label();
			this->label22 = new System::Windows::Forms::Label();
			this->label23 = new System::Windows::Forms::Label();
			this->label24 = new System::Windows::Forms::Label();
			this->label25 = new System::Windows::Forms::Label();
			this->OKComboJ = new System::Windows::Forms::ComboBox();
			this->label19 = new System::Windows::Forms::Label();
			this->PageS = new System::Windows::Forms::TabPage();
			this->SoundMultiCombo = new System::Windows::Forms::ComboBox();
			this->label39 = new System::Windows::Forms::Label();
			this->BGMCheck = new System::Windows::Forms::CheckBox();
			this->SoundComCombo = new System::Windows::Forms::ComboBox();
			this->label31 = new System::Windows::Forms::Label();
			this->SoundQuaCombo = new System::Windows::Forms::ComboBox();
			this->label30 = new System::Windows::Forms::Label();
			this->Sound3DCheck = new System::Windows::Forms::CheckBox();
			this->PageV = new System::Windows::Forms::TabPage();
			this->SoundLink3 = new System::Windows::Forms::LinkLabel();
			this->SoundLink2 = new System::Windows::Forms::LinkLabel();
			this->SoundLink1 = new System::Windows::Forms::LinkLabel();
			this->label5 = new System::Windows::Forms::Label();
			this->label4 = new System::Windows::Forms::Label();
			this->BGMLink = new System::Windows::Forms::LinkLabel();
			this->label3 = new System::Windows::Forms::Label();
			this->label2 = new System::Windows::Forms::Label();
			this->pictureBox2 = new System::Windows::Forms::PictureBox();
			this->label1 = new System::Windows::Forms::Label();
			this->HPLink = new System::Windows::Forms::LinkLabel();
			this->pictureBox1 = new System::Windows::Forms::PictureBox();
			this->Cancel = new System::Windows::Forms::Button();
			this->OK = new System::Windows::Forms::Button();
			this->IP1 = new System::Windows::Forms::TextBox();
			this->IP2 = new System::Windows::Forms::TextBox();
			this->IP3 = new System::Windows::Forms::TextBox();
			this->IP4 = new System::Windows::Forms::TextBox();
			this->Port = new System::Windows::Forms::TextBox();
			this->IPCheck = new System::Windows::Forms::CheckBox();
			this->PortCheck = new System::Windows::Forms::CheckBox();
			this->TabControl->SuspendLayout();
			this->PageG->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->PageC->SuspendLayout();
			this->KeyGroup->SuspendLayout();
			this->JoyGroup->SuspendLayout();
			(__try_cast<System::ComponentModel::ISupportInitialize *  >(this->MoveAxisNumeric))->BeginInit();
			(__try_cast<System::ComponentModel::ISupportInitialize *  >(this->RoteAxisNumeric))->BeginInit();
			this->PageS->SuspendLayout();
			this->PageV->SuspendLayout();
			this->SuspendLayout();
			// 
			// TabControl
			// 
			this->TabControl->Controls->Add(this->PageG);
			this->TabControl->Controls->Add(this->PageC);
			this->TabControl->Controls->Add(this->PageS);
			this->TabControl->Controls->Add(this->PageV);
			this->TabControl->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->TabControl->Location = System::Drawing::Point(8, 16);
			this->TabControl->Name = S"TabControl";
			this->TabControl->SelectedIndex = 0;
			this->TabControl->Size = System::Drawing::Size(520, 392);
			this->TabControl->TabIndex = 0;
			this->TabControl->SelectedIndexChanged += new System::EventHandler(this, TabControl_SelectedIndexChanged);
			// 
			// PageG
			// 
			this->PageG->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->PageG->Controls->Add(this->groupBox4);
			this->PageG->Controls->Add(this->groupBox3);
			this->PageG->Controls->Add(this->groupBox2);
			this->PageG->Controls->Add(this->groupBox1);
			this->PageG->Location = System::Drawing::Point(4, 21);
			this->PageG->Name = S"PageG";
			this->PageG->Size = System::Drawing::Size(512, 367);
			this->PageG->TabIndex = 1;
			this->PageG->Text = S"グラフィック";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->button5);
			this->groupBox4->Controls->Add(this->button4);
			this->groupBox4->Controls->Add(this->label41);
			this->groupBox4->Controls->Add(this->button3);
			this->groupBox4->Controls->Add(this->button2);
			this->groupBox4->Controls->Add(this->button1);
			this->groupBox4->Controls->Add(this->label40);
			this->groupBox4->Location = System::Drawing::Point(312, 24);
			this->groupBox4->Name = S"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(176, 168);
			this->groupBox4->TabIndex = 8;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = S"簡易設定";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(120, 128);
			this->button5->Name = S"button5";
			this->button5->Size = System::Drawing::Size(40, 24);
			this->button5->TabIndex = 6;
			this->button5->Text = S"最悪";
			this->button5->Click += new System::EventHandler(this, button5_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(72, 128);
			this->button4->Name = S"button4";
			this->button4->Size = System::Drawing::Size(48, 24);
			this->button4->TabIndex = 5;
			this->button4->Text = S"低め";
			this->button4->Click += new System::EventHandler(this, button4_Click);
			// 
			// label41
			// 
			this->label41->Location = System::Drawing::Point(16, 80);
			this->label41->Name = S"label41";
			this->label41->Size = System::Drawing::Size(144, 12);
			this->label41->TabIndex = 4;
			this->label41->Text = S"パソコンの性能は？";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(16, 128);
			this->button3->Name = S"button3";
			this->button3->Size = System::Drawing::Size(56, 24);
			this->button3->TabIndex = 3;
			this->button3->Text = S"普通";
			this->button3->Click += new System::EventHandler(this, button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(96, 104);
			this->button2->Name = S"button2";
			this->button2->Size = System::Drawing::Size(64, 24);
			this->button2->TabIndex = 1;
			this->button2->Text = S"高め";
			this->button2->Click += new System::EventHandler(this, button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(16, 104);
			this->button1->Name = S"button1";
			this->button1->Size = System::Drawing::Size(80, 24);
			this->button1->TabIndex = 0;
			this->button1->Text = S"自信満々";
			this->button1->Click += new System::EventHandler(this, button1_Click);
			// 
			// label40
			// 
			this->label40->Location = System::Drawing::Point(16, 24);
			this->label40->Name = S"label40";
			this->label40->Size = System::Drawing::Size(144, 48);
			this->label40->TabIndex = 2;
			this->label40->Text = S"グラフィックの細かい設定が分からない場合、以下のボタンを押して簡易設定を行ってください。";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->anticombo);
			this->groupBox3->Controls->Add(this->label42);
			this->groupBox3->Controls->Add(this->ItemDisCombo);
			this->groupBox3->Controls->Add(this->label38);
			this->groupBox3->Controls->Add(this->KemuriCombo);
			this->groupBox3->Controls->Add(this->label36);
			this->groupBox3->Controls->Add(this->ShadeCheck);
			this->groupBox3->Controls->Add(this->PMeshCombo);
			this->groupBox3->Controls->Add(this->label35);
			this->groupBox3->Location = System::Drawing::Point(240, 208);
			this->groupBox3->Name = S"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(248, 136);
			this->groupBox3->TabIndex = 7;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = S"その他";
			// 
			// anticombo
			// 
			this->anticombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			System::Object* __mcTemp__1[] = new System::Object*[4];
			__mcTemp__1[0] = S"無効";
			__mcTemp__1[1] = S"弱";
			__mcTemp__1[2] = S"中";
			__mcTemp__1[3] = S"強";
			this->anticombo->Items->AddRange(__mcTemp__1);
			this->anticombo->Location = System::Drawing::Point(152, 104);
			this->anticombo->Name = S"anticombo";
			this->anticombo->Size = System::Drawing::Size(56, 20);
			this->anticombo->TabIndex = 16;
			this->anticombo->SelectedIndexChanged += new System::EventHandler(this, anticombo_SelectedIndexChanged);
			// 
			// label42
			// 
			this->label42->Location = System::Drawing::Point(40, 104);
			this->label42->Name = S"label42";
			this->label42->Size = System::Drawing::Size(128, 16);
			this->label42->TabIndex = 15;
			this->label42->Text = S"アンチエイリアス";
			this->label42->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// ItemDisCombo
			// 
			this->ItemDisCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			System::Object* __mcTemp__2[] = new System::Object*[3];
			__mcTemp__2[0] = S"遠";
			__mcTemp__2[1] = S"中";
			__mcTemp__2[2] = S"近";
			this->ItemDisCombo->Items->AddRange(__mcTemp__2);
			this->ItemDisCombo->Location = System::Drawing::Point(152, 80);
			this->ItemDisCombo->Name = S"ItemDisCombo";
			this->ItemDisCombo->Size = System::Drawing::Size(56, 20);
			this->ItemDisCombo->TabIndex = 14;
			this->ItemDisCombo->SelectedIndexChanged += new System::EventHandler(this, ItemDisCombo_SelectedIndexChanged);
			// 
			// label38
			// 
			this->label38->Location = System::Drawing::Point(40, 80);
			this->label38->Name = S"label38";
			this->label38->Size = System::Drawing::Size(128, 16);
			this->label38->TabIndex = 13;
			this->label38->Text = S"アイテムの表示距離";
			this->label38->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// KemuriCombo
			// 
			this->KemuriCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			System::Object* __mcTemp__3[] = new System::Object*[3];
			__mcTemp__3[0] = S"遠";
			__mcTemp__3[1] = S"中";
			__mcTemp__3[2] = S"近";
			this->KemuriCombo->Items->AddRange(__mcTemp__3);
			this->KemuriCombo->Location = System::Drawing::Point(152, 56);
			this->KemuriCombo->Name = S"KemuriCombo";
			this->KemuriCombo->Size = System::Drawing::Size(56, 20);
			this->KemuriCombo->TabIndex = 12;
			this->KemuriCombo->SelectedIndexChanged += new System::EventHandler(this, KemuriCombo_SelectedIndexChanged);
			// 
			// label36
			// 
			this->label36->Location = System::Drawing::Point(40, 56);
			this->label36->Name = S"label36";
			this->label36->Size = System::Drawing::Size(104, 16);
			this->label36->TabIndex = 8;
			this->label36->Text = S"煙の表示距離";
			this->label36->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// ShadeCheck
			// 
			this->ShadeCheck->Location = System::Drawing::Point(40, 32);
			this->ShadeCheck->Name = S"ShadeCheck";
			this->ShadeCheck->Size = System::Drawing::Size(80, 16);
			this->ShadeCheck->TabIndex = 10;
			this->ShadeCheck->Text = S"影の表示";
			this->ShadeCheck->CheckedChanged += new System::EventHandler(this, ShadeCheck_CheckedChanged);
			// 
			// PMeshCombo
			// 
			this->PMeshCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			System::Object* __mcTemp__4[] = new System::Object*[4];
			__mcTemp__4[0] = S"無効";
			__mcTemp__4[1] = S"弱";
			__mcTemp__4[2] = S"中";
			__mcTemp__4[3] = S"強";
			this->PMeshCombo->Items->AddRange(__mcTemp__4);
			this->PMeshCombo->Location = System::Drawing::Point(144, 16);
			this->PMeshCombo->Name = S"PMeshCombo";
			this->PMeshCombo->Size = System::Drawing::Size(56, 20);
			this->PMeshCombo->TabIndex = 11;
			this->PMeshCombo->Visible = false;
			this->PMeshCombo->SelectedIndexChanged += new System::EventHandler(this, PMeshCombo_SelectedIndexChanged);
			// 
			// label35
			// 
			this->label35->Location = System::Drawing::Point(32, 16);
			this->label35->Name = S"label35";
			this->label35->Size = System::Drawing::Size(104, 24);
			this->label35->TabIndex = 5;
			this->label35->Text = S"プログレッシブメッシュ";
			this->label35->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label35->Visible = false;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->MipFilterCheck);
			this->groupBox2->Controls->Add(this->MipCombo);
			this->groupBox2->Controls->Add(this->label34);
			this->groupBox2->Controls->Add(this->EnvCheck);
			this->groupBox2->Controls->Add(this->TexMultiCheck);
			this->groupBox2->Controls->Add(this->TexFilterCheck);
			this->groupBox2->Location = System::Drawing::Point(24, 152);
			this->groupBox2->Name = S"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(192, 192);
			this->groupBox2->TabIndex = 6;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = S"テクスチャ設定";
			// 
			// MipFilterCheck
			// 
			this->MipFilterCheck->Location = System::Drawing::Point(24, 152);
			this->MipFilterCheck->Name = S"MipFilterCheck";
			this->MipFilterCheck->Size = System::Drawing::Size(152, 16);
			this->MipFilterCheck->TabIndex = 9;
			this->MipFilterCheck->Text = S"ミップマップの境界のぼかし";
			this->MipFilterCheck->CheckedChanged += new System::EventHandler(this, MipFilterCheck_CheckedChanged);
			// 
			// MipCombo
			// 
			this->MipCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			System::Object* __mcTemp__5[] = new System::Object*[4];
			__mcTemp__5[0] = S"無効";
			__mcTemp__5[1] = S"弱";
			__mcTemp__5[2] = S"中";
			__mcTemp__5[3] = S"強";
			this->MipCombo->Items->AddRange(__mcTemp__5);
			this->MipCombo->Location = System::Drawing::Point(88, 124);
			this->MipCombo->Name = S"MipCombo";
			this->MipCombo->Size = System::Drawing::Size(56, 20);
			this->MipCombo->TabIndex = 8;
			this->MipCombo->SelectedIndexChanged += new System::EventHandler(this, MipCombo_SelectedIndexChanged);
			// 
			// label34
			// 
			this->label34->Location = System::Drawing::Point(24, 128);
			this->label34->Name = S"label34";
			this->label34->Size = System::Drawing::Size(72, 16);
			this->label34->TabIndex = 3;
			this->label34->Text = S"ミップマップ";
			// 
			// EnvCheck
			// 
			this->EnvCheck->Location = System::Drawing::Point(24, 80);
			this->EnvCheck->Name = S"EnvCheck";
			this->EnvCheck->Size = System::Drawing::Size(88, 16);
			this->EnvCheck->TabIndex = 7;
			this->EnvCheck->Text = S"反射マップ";
			this->EnvCheck->CheckedChanged += new System::EventHandler(this, EnvCheck_CheckedChanged);
			// 
			// TexMultiCheck
			// 
			this->TexMultiCheck->Location = System::Drawing::Point(24, 56);
			this->TexMultiCheck->Name = S"TexMultiCheck";
			this->TexMultiCheck->Size = System::Drawing::Size(112, 16);
			this->TexMultiCheck->TabIndex = 6;
			this->TexMultiCheck->Text = S"マルチテクスチャ";
			this->TexMultiCheck->CheckedChanged += new System::EventHandler(this, TexMultiCheck_CheckedChanged);
			// 
			// TexFilterCheck
			// 
			this->TexFilterCheck->Location = System::Drawing::Point(24, 24);
			this->TexFilterCheck->Name = S"TexFilterCheck";
			this->TexFilterCheck->Size = System::Drawing::Size(112, 16);
			this->TexFilterCheck->TabIndex = 5;
			this->TexFilterCheck->Text = S"テクスチャのぼかし";
			this->TexFilterCheck->CheckedChanged += new System::EventHandler(this, TexFilterCheck_CheckedChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->ColorCombo);
			this->groupBox1->Controls->Add(this->label37);
			this->groupBox1->Controls->Add(this->label33);
			this->groupBox1->Controls->Add(this->BSizeCombo);
			this->groupBox1->Controls->Add(this->FSizeCombo);
			this->groupBox1->Controls->Add(this->FullCheck);
			this->groupBox1->Controls->Add(this->label32);
			this->groupBox1->Location = System::Drawing::Point(24, 24);
			this->groupBox1->Name = S"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(272, 112);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = S"ディスプレイ設定";
			// 
			// ColorCombo
			// 
			this->ColorCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			System::Object* __mcTemp__6[] = new System::Object*[2];
			__mcTemp__6[0] = S"16 bit";
			__mcTemp__6[1] = S"32 bit";
			this->ColorCombo->Items->AddRange(__mcTemp__6);
			this->ColorCombo->Location = System::Drawing::Point(176, 24);
			this->ColorCombo->Name = S"ColorCombo";
			this->ColorCombo->Size = System::Drawing::Size(72, 20);
			this->ColorCombo->TabIndex = 2;
			this->ColorCombo->SelectedIndexChanged += new System::EventHandler(this, ColorCombo_SelectedIndexChanged);
			// 
			// label37
			// 
			this->label37->Location = System::Drawing::Point(144, 28);
			this->label37->Name = S"label37";
			this->label37->Size = System::Drawing::Size(32, 16);
			this->label37->TabIndex = 5;
			this->label37->Text = S"色数";
			// 
			// label33
			// 
			this->label33->Location = System::Drawing::Point(144, 56);
			this->label33->Name = S"label33";
			this->label33->Size = System::Drawing::Size(96, 16);
			this->label33->TabIndex = 4;
			this->label33->Text = S"バッファサイズ";
			// 
			// BSizeCombo
			// 
			this->BSizeCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			System::Object* __mcTemp__7[] = new System::Object*[5];
			__mcTemp__7[0] = S"400x300";
			__mcTemp__7[1] = S"640x480";
			__mcTemp__7[2] = S"800x600";
			__mcTemp__7[3] = S"1024x768";
			__mcTemp__7[4] = S"1280x1024";
			this->BSizeCombo->Items->AddRange(__mcTemp__7);
			this->BSizeCombo->Location = System::Drawing::Point(144, 72);
			this->BSizeCombo->Name = S"BSizeCombo";
			this->BSizeCombo->Size = System::Drawing::Size(104, 20);
			this->BSizeCombo->TabIndex = 4;
			this->BSizeCombo->SelectedIndexChanged += new System::EventHandler(this, BSizeCombo_SelectedIndexChanged);
			// 
			// FSizeCombo
			// 
			this->FSizeCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			System::Object* __mcTemp__8[] = new System::Object*[5];
			__mcTemp__8[0] = S"400x300";
			__mcTemp__8[1] = S"640x480";
			__mcTemp__8[2] = S"800x600";
			__mcTemp__8[3] = S"1024x768";
			__mcTemp__8[4] = S"1280x1024";
			this->FSizeCombo->Items->AddRange(__mcTemp__8);
			this->FSizeCombo->Location = System::Drawing::Point(24, 72);
			this->FSizeCombo->Name = S"FSizeCombo";
			this->FSizeCombo->Size = System::Drawing::Size(104, 20);
			this->FSizeCombo->TabIndex = 3;
			this->FSizeCombo->SelectedIndexChanged += new System::EventHandler(this, FSizeCombo_SelectedIndexChanged);
			// 
			// FullCheck
			// 
			this->FullCheck->Location = System::Drawing::Point(24, 24);
			this->FullCheck->Name = S"FullCheck";
			this->FullCheck->Size = System::Drawing::Size(120, 16);
			this->FullCheck->TabIndex = 1;
			this->FullCheck->Text = S"フルスクリーン";
			this->FullCheck->CheckedChanged += new System::EventHandler(this, FullCheck_CheckedChanged);
			// 
			// label32
			// 
			this->label32->Location = System::Drawing::Point(24, 56);
			this->label32->Name = S"label32";
			this->label32->Size = System::Drawing::Size(96, 16);
			this->label32->TabIndex = 2;
			this->label32->Text = S"画面サイズ";
			// 
			// PageC
			// 
			this->PageC->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->PageC->Controls->Add(this->myselfcheck);
			this->PageC->Controls->Add(this->CtrlRadio4);
			this->PageC->Controls->Add(this->CtrlRadio3);
			this->PageC->Controls->Add(this->CtrlRadio2);
			this->PageC->Controls->Add(this->CtrlRadio1);
			this->PageC->Controls->Add(this->KeyCheck);
			this->PageC->Controls->Add(this->KeyGroup);
			this->PageC->Controls->Add(this->JoyGroup);
			this->PageC->Location = System::Drawing::Point(4, 21);
			this->PageC->Name = S"PageC";
			this->PageC->Size = System::Drawing::Size(512, 367);
			this->PageC->TabIndex = 3;
			this->PageC->Text = S"コントローラ";
			// 
			// myselfcheck
			// 
			this->myselfcheck->Location = System::Drawing::Point(240, 24);
			this->myselfcheck->Name = S"myselfcheck";
			this->myselfcheck->Size = System::Drawing::Size(256, 16);
			this->myselfcheck->TabIndex = 7;
			this->myselfcheck->Text = S"1人プレイ時 プレイヤー1の入力のみ受け付ける";
			this->myselfcheck->CheckedChanged += new System::EventHandler(this, myselfcheck_CheckedChanged);
			// 
			// CtrlRadio4
			// 
			this->CtrlRadio4->Location = System::Drawing::Point(376, 64);
			this->CtrlRadio4->Name = S"CtrlRadio4";
			this->CtrlRadio4->Size = System::Drawing::Size(104, 16);
			this->CtrlRadio4->TabIndex = 5;
			this->CtrlRadio4->Text = S"コントローラ4";
			this->CtrlRadio4->CheckedChanged += new System::EventHandler(this, CtrlRadio4_CheckedChanged);
			// 
			// CtrlRadio3
			// 
			this->CtrlRadio3->Location = System::Drawing::Point(264, 64);
			this->CtrlRadio3->Name = S"CtrlRadio3";
			this->CtrlRadio3->Size = System::Drawing::Size(104, 16);
			this->CtrlRadio3->TabIndex = 4;
			this->CtrlRadio3->Text = S"コントローラ3";
			this->CtrlRadio3->CheckedChanged += new System::EventHandler(this, CtrlRadio3_CheckedChanged);
			// 
			// CtrlRadio2
			// 
			this->CtrlRadio2->Location = System::Drawing::Point(152, 64);
			this->CtrlRadio2->Name = S"CtrlRadio2";
			this->CtrlRadio2->Size = System::Drawing::Size(104, 16);
			this->CtrlRadio2->TabIndex = 3;
			this->CtrlRadio2->Text = S"コントローラ2";
			this->CtrlRadio2->CheckedChanged += new System::EventHandler(this, CtrlRadio2_CheckedChanged);
			// 
			// CtrlRadio1
			// 
			this->CtrlRadio1->Checked = true;
			this->CtrlRadio1->Location = System::Drawing::Point(40, 64);
			this->CtrlRadio1->Name = S"CtrlRadio1";
			this->CtrlRadio1->Size = System::Drawing::Size(104, 16);
			this->CtrlRadio1->TabIndex = 2;
			this->CtrlRadio1->TabStop = true;
			this->CtrlRadio1->Text = S"コントローラ1";
			this->CtrlRadio1->CheckedChanged += new System::EventHandler(this, CtrlRadio1_CheckedChanged);
			// 
			// KeyCheck
			// 
			this->KeyCheck->Location = System::Drawing::Point(32, 24);
			this->KeyCheck->Name = S"KeyCheck";
			this->KeyCheck->Size = System::Drawing::Size(216, 16);
			this->KeyCheck->TabIndex = 1;
			this->KeyCheck->Text = S"キーボードをプレイヤー1として使用する";
			this->KeyCheck->CheckedChanged += new System::EventHandler(this, KeyCheck_CheckedChanged);
			// 
			// KeyGroup
			// 
			this->KeyGroup->Controls->Add(this->LMoveCombo);
			this->KeyGroup->Controls->Add(this->label18);
			this->KeyGroup->Controls->Add(this->RMoveCombo);
			this->KeyGroup->Controls->Add(this->label17);
			this->KeyGroup->Controls->Add(this->DMoveCombo);
			this->KeyGroup->Controls->Add(this->label16);
			this->KeyGroup->Controls->Add(this->DRoteCombo);
			this->KeyGroup->Controls->Add(this->URoteCombo);
			this->KeyGroup->Controls->Add(this->label14);
			this->KeyGroup->Controls->Add(this->label15);
			this->KeyGroup->Controls->Add(this->UMoveCombo);
			this->KeyGroup->Controls->Add(this->label13);
			this->KeyGroup->Controls->Add(this->LRoteCombo);
			this->KeyGroup->Controls->Add(this->RRoteCombo);
			this->KeyGroup->Controls->Add(this->ItemCombo);
			this->KeyGroup->Controls->Add(this->JumpCombo);
			this->KeyGroup->Controls->Add(this->StartCombo);
			this->KeyGroup->Controls->Add(this->CancelCombo);
			this->KeyGroup->Controls->Add(this->label12);
			this->KeyGroup->Controls->Add(this->label11);
			this->KeyGroup->Controls->Add(this->label10);
			this->KeyGroup->Controls->Add(this->label9);
			this->KeyGroup->Controls->Add(this->label8);
			this->KeyGroup->Controls->Add(this->label7);
			this->KeyGroup->Controls->Add(this->OKCombo);
			this->KeyGroup->Controls->Add(this->label6);
			this->KeyGroup->Location = System::Drawing::Point(40, 80);
			this->KeyGroup->Name = S"KeyGroup";
			this->KeyGroup->Size = System::Drawing::Size(432, 256);
			this->KeyGroup->TabIndex = 5;
			this->KeyGroup->TabStop = false;
			// 
			// LMoveCombo
			// 
			this->LMoveCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			System::Object* __mcTemp__9[] = new System::Object*[64];
			__mcTemp__9[0] = S"なし";
			__mcTemp__9[1] = S"Enter （エンター)";
			__mcTemp__9[2] = S"Space(スペース)";
			__mcTemp__9[3] = S"LShift (左)";
			__mcTemp__9[4] = S"RShift (右)";
			__mcTemp__9[5] = S"LCtrl (左)";
			__mcTemp__9[6] = S"RCtrl (右)";
			__mcTemp__9[7] = S"Right (カーソル)";
			__mcTemp__9[8] = S"Left   (カーソル)";
			__mcTemp__9[9] = S"Up    (カーソル)";
			__mcTemp__9[10] = S"down (カーソル)";
			__mcTemp__9[11] = S"A";
			__mcTemp__9[12] = S"B";
			__mcTemp__9[13] = S"C";
			__mcTemp__9[14] = S"D";
			__mcTemp__9[15] = S"E";
			__mcTemp__9[16] = S"F";
			__mcTemp__9[17] = S"G";
			__mcTemp__9[18] = S"H";
			__mcTemp__9[19] = S"I";
			__mcTemp__9[20] = S"J";
			__mcTemp__9[21] = S"K";
			__mcTemp__9[22] = S"L";
			__mcTemp__9[23] = S"M";
			__mcTemp__9[24] = S"N";
			__mcTemp__9[25] = S"O";
			__mcTemp__9[26] = S"P";
			__mcTemp__9[27] = S"Q";
			__mcTemp__9[28] = S"R";
			__mcTemp__9[29] = S"S";
			__mcTemp__9[30] = S"T";
			__mcTemp__9[31] = S"U";
			__mcTemp__9[32] = S"V";
			__mcTemp__9[33] = S"W";
			__mcTemp__9[34] = S"X";
			__mcTemp__9[35] = S"Y";
			__mcTemp__9[36] = S"Z";
			__mcTemp__9[37] = S"- (マイナス)";
			__mcTemp__9[38] = S"^ (べき乗)";
			__mcTemp__9[39] = S"\\ (右上)";
			__mcTemp__9[40] = S"@ (アットマーク)";
			__mcTemp__9[41] = S"[ (左括弧)";
			__mcTemp__9[42] = S"; (セミコロン)";
			__mcTemp__9[43] = S": (コロン)";
			__mcTemp__9[44] = S"] (右括弧)";
			__mcTemp__9[45] = S", (コンマ)";
			__mcTemp__9[46] = S"/ (スラッシュ)";
			__mcTemp__9[47] = S"\\ (右下)";
			__mcTemp__9[48] = S"0 (テンキー)";
			__mcTemp__9[49] = S"1 (テンキー)";
			__mcTemp__9[50] = S"2 (テンキー)";
			__mcTemp__9[51] = S"3 (テンキー)";
			__mcTemp__9[52] = S"4 (テンキー)";
			__mcTemp__9[53] = S"5 (テンキー)";
			__mcTemp__9[54] = S"6 (テンキー)";
			__mcTemp__9[55] = S"7 (テンキー)";
			__mcTemp__9[56] = S"8 (テンキー)";
			__mcTemp__9[57] = S"9 (テンキー)";
			__mcTemp__9[58] = S". (テンキー)";
			__mcTemp__9[59] = S"/ (テンキー)";
			__mcTemp__9[60] = S"* (テンキー)";
			__mcTemp__9[61] = S"- (テンキー)";
			__mcTemp__9[62] = S"+ (テンキー)";
			__mcTemp__9[63] = S"Enter (テンキー)";
			this->LMoveCombo->Items->AddRange(__mcTemp__9);
			this->LMoveCombo->Location = System::Drawing::Point(304, 156);
			this->LMoveCombo->Name = S"LMoveCombo";
			this->LMoveCombo->Size = System::Drawing::Size(104, 20);
			this->LMoveCombo->TabIndex = 17;
			this->LMoveCombo->SelectedIndexChanged += new System::EventHandler(this, LMoveCombo_SelectedIndexChanged);
			// 
			// label18
			// 
			this->label18->Location = System::Drawing::Point(224, 160);
			this->label18->Name = S"label18";
			this->label18->Size = System::Drawing::Size(80, 16);
			this->label18->TabIndex = 25;
			this->label18->Text = S"左移動ボタン";
			// 
			// RMoveCombo
			// 
			this->RMoveCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			System::Object* __mcTemp__10[] = new System::Object*[64];
			__mcTemp__10[0] = S"なし";
			__mcTemp__10[1] = S"Enter （エンター)";
			__mcTemp__10[2] = S"Space(スペース)";
			__mcTemp__10[3] = S"LShift (左)";
			__mcTemp__10[4] = S"RShift (右)";
			__mcTemp__10[5] = S"LCtrl (左)";
			__mcTemp__10[6] = S"RCtrl (右)";
			__mcTemp__10[7] = S"Right (カーソル)";
			__mcTemp__10[8] = S"Left   (カーソル)";
			__mcTemp__10[9] = S"Up    (カーソル)";
			__mcTemp__10[10] = S"down (カーソル)";
			__mcTemp__10[11] = S"A";
			__mcTemp__10[12] = S"B";
			__mcTemp__10[13] = S"C";
			__mcTemp__10[14] = S"D";
			__mcTemp__10[15] = S"E";
			__mcTemp__10[16] = S"F";
			__mcTemp__10[17] = S"G";
			__mcTemp__10[18] = S"H";
			__mcTemp__10[19] = S"I";
			__mcTemp__10[20] = S"J";
			__mcTemp__10[21] = S"K";
			__mcTemp__10[22] = S"L";
			__mcTemp__10[23] = S"M";
			__mcTemp__10[24] = S"N";
			__mcTemp__10[25] = S"O";
			__mcTemp__10[26] = S"P";
			__mcTemp__10[27] = S"Q";
			__mcTemp__10[28] = S"R";
			__mcTemp__10[29] = S"S";
			__mcTemp__10[30] = S"T";
			__mcTemp__10[31] = S"U";
			__mcTemp__10[32] = S"V";
			__mcTemp__10[33] = S"W";
			__mcTemp__10[34] = S"X";
			__mcTemp__10[35] = S"Y";
			__mcTemp__10[36] = S"Z";
			__mcTemp__10[37] = S"- (マイナス)";
			__mcTemp__10[38] = S"^ (べき乗)";
			__mcTemp__10[39] = S"\\ (右上)";
			__mcTemp__10[40] = S"@ (アットマーク)";
			__mcTemp__10[41] = S"[ (左括弧)";
			__mcTemp__10[42] = S"; (セミコロン)";
			__mcTemp__10[43] = S": (コロン)";
			__mcTemp__10[44] = S"] (右括弧)";
			__mcTemp__10[45] = S", (コンマ)";
			__mcTemp__10[46] = S"/ (スラッシュ)";
			__mcTemp__10[47] = S"\\ (右下)";
			__mcTemp__10[48] = S"0 (テンキー)";
			__mcTemp__10[49] = S"1 (テンキー)";
			__mcTemp__10[50] = S"2 (テンキー)";
			__mcTemp__10[51] = S"3 (テンキー)";
			__mcTemp__10[52] = S"4 (テンキー)";
			__mcTemp__10[53] = S"5 (テンキー)";
			__mcTemp__10[54] = S"6 (テンキー)";
			__mcTemp__10[55] = S"7 (テンキー)";
			__mcTemp__10[56] = S"8 (テンキー)";
			__mcTemp__10[57] = S"9 (テンキー)";
			__mcTemp__10[58] = S". (テンキー)";
			__mcTemp__10[59] = S"/ (テンキー)";
			__mcTemp__10[60] = S"* (テンキー)";
			__mcTemp__10[61] = S"- (テンキー)";
			__mcTemp__10[62] = S"+ (テンキー)";
			__mcTemp__10[63] = S"Enter (テンキー)";
			this->RMoveCombo->Items->AddRange(__mcTemp__10);
			this->RMoveCombo->Location = System::Drawing::Point(304, 124);
			this->RMoveCombo->Name = S"RMoveCombo";
			this->RMoveCombo->Size = System::Drawing::Size(104, 20);
			this->RMoveCombo->TabIndex = 16;
			this->RMoveCombo->SelectedIndexChanged += new System::EventHandler(this, RMoveCombo_SelectedIndexChanged);
			// 
			// label17
			// 
			this->label17->Location = System::Drawing::Point(224, 128);
			this->label17->Name = S"label17";
			this->label17->Size = System::Drawing::Size(80, 16);
			this->label17->TabIndex = 23;
			this->label17->Text = S"右移動ボタン";
			// 
			// DMoveCombo
			// 
			this->DMoveCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			System::Object* __mcTemp__11[] = new System::Object*[64];
			__mcTemp__11[0] = S"なし";
			__mcTemp__11[1] = S"Enter （エンター)";
			__mcTemp__11[2] = S"Space(スペース)";
			__mcTemp__11[3] = S"LShift (左)";
			__mcTemp__11[4] = S"RShift (右)";
			__mcTemp__11[5] = S"LCtrl (左)";
			__mcTemp__11[6] = S"RCtrl (右)";
			__mcTemp__11[7] = S"Right (カーソル)";
			__mcTemp__11[8] = S"Left   (カーソル)";
			__mcTemp__11[9] = S"Up    (カーソル)";
			__mcTemp__11[10] = S"down (カーソル)";
			__mcTemp__11[11] = S"A";
			__mcTemp__11[12] = S"B";
			__mcTemp__11[13] = S"C";
			__mcTemp__11[14] = S"D";
			__mcTemp__11[15] = S"E";
			__mcTemp__11[16] = S"F";
			__mcTemp__11[17] = S"G";
			__mcTemp__11[18] = S"H";
			__mcTemp__11[19] = S"I";
			__mcTemp__11[20] = S"J";
			__mcTemp__11[21] = S"K";
			__mcTemp__11[22] = S"L";
			__mcTemp__11[23] = S"M";
			__mcTemp__11[24] = S"N";
			__mcTemp__11[25] = S"O";
			__mcTemp__11[26] = S"P";
			__mcTemp__11[27] = S"Q";
			__mcTemp__11[28] = S"R";
			__mcTemp__11[29] = S"S";
			__mcTemp__11[30] = S"T";
			__mcTemp__11[31] = S"U";
			__mcTemp__11[32] = S"V";
			__mcTemp__11[33] = S"W";
			__mcTemp__11[34] = S"X";
			__mcTemp__11[35] = S"Y";
			__mcTemp__11[36] = S"Z";
			__mcTemp__11[37] = S"- (マイナス)";
			__mcTemp__11[38] = S"^ (べき乗)";
			__mcTemp__11[39] = S"\\ (右上)";
			__mcTemp__11[40] = S"@ (アットマーク)";
			__mcTemp__11[41] = S"[ (左括弧)";
			__mcTemp__11[42] = S"; (セミコロン)";
			__mcTemp__11[43] = S": (コロン)";
			__mcTemp__11[44] = S"] (右括弧)";
			__mcTemp__11[45] = S", (コンマ)";
			__mcTemp__11[46] = S"/ (スラッシュ)";
			__mcTemp__11[47] = S"\\ (右下)";
			__mcTemp__11[48] = S"0 (テンキー)";
			__mcTemp__11[49] = S"1 (テンキー)";
			__mcTemp__11[50] = S"2 (テンキー)";
			__mcTemp__11[51] = S"3 (テンキー)";
			__mcTemp__11[52] = S"4 (テンキー)";
			__mcTemp__11[53] = S"5 (テンキー)";
			__mcTemp__11[54] = S"6 (テンキー)";
			__mcTemp__11[55] = S"7 (テンキー)";
			__mcTemp__11[56] = S"8 (テンキー)";
			__mcTemp__11[57] = S"9 (テンキー)";
			__mcTemp__11[58] = S". (テンキー)";
			__mcTemp__11[59] = S"/ (テンキー)";
			__mcTemp__11[60] = S"* (テンキー)";
			__mcTemp__11[61] = S"- (テンキー)";
			__mcTemp__11[62] = S"+ (テンキー)";
			__mcTemp__11[63] = S"Enter (テンキー)";
			this->DMoveCombo->Items->AddRange(__mcTemp__11);
			this->DMoveCombo->Location = System::Drawing::Point(304, 92);
			this->DMoveCombo->Name = S"DMoveCombo";
			this->DMoveCombo->Size = System::Drawing::Size(104, 20);
			this->DMoveCombo->TabIndex = 15;
			this->DMoveCombo->SelectedIndexChanged += new System::EventHandler(this, DMoveCombo_SelectedIndexChanged);
			// 
			// label16
			// 
			this->label16->Location = System::Drawing::Point(224, 96);
			this->label16->Name = S"label16";
			this->label16->Size = System::Drawing::Size(80, 16);
			this->label16->TabIndex = 21;
			this->label16->Text = S"下移動ボタン";
			// 
			// DRoteCombo
			// 
			this->DRoteCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			System::Object* __mcTemp__12[] = new System::Object*[64];
			__mcTemp__12[0] = S"なし";
			__mcTemp__12[1] = S"Enter （エンター)";
			__mcTemp__12[2] = S"Space(スペース)";
			__mcTemp__12[3] = S"LShift (左)";
			__mcTemp__12[4] = S"RShift (右)";
			__mcTemp__12[5] = S"LCtrl (左)";
			__mcTemp__12[6] = S"RCtrl (右)";
			__mcTemp__12[7] = S"Right (カーソル)";
			__mcTemp__12[8] = S"Left   (カーソル)";
			__mcTemp__12[9] = S"Up    (カーソル)";
			__mcTemp__12[10] = S"down (カーソル)";
			__mcTemp__12[11] = S"A";
			__mcTemp__12[12] = S"B";
			__mcTemp__12[13] = S"C";
			__mcTemp__12[14] = S"D";
			__mcTemp__12[15] = S"E";
			__mcTemp__12[16] = S"F";
			__mcTemp__12[17] = S"G";
			__mcTemp__12[18] = S"H";
			__mcTemp__12[19] = S"I";
			__mcTemp__12[20] = S"J";
			__mcTemp__12[21] = S"K";
			__mcTemp__12[22] = S"L";
			__mcTemp__12[23] = S"M";
			__mcTemp__12[24] = S"N";
			__mcTemp__12[25] = S"O";
			__mcTemp__12[26] = S"P";
			__mcTemp__12[27] = S"Q";
			__mcTemp__12[28] = S"R";
			__mcTemp__12[29] = S"S";
			__mcTemp__12[30] = S"T";
			__mcTemp__12[31] = S"U";
			__mcTemp__12[32] = S"V";
			__mcTemp__12[33] = S"W";
			__mcTemp__12[34] = S"X";
			__mcTemp__12[35] = S"Y";
			__mcTemp__12[36] = S"Z";
			__mcTemp__12[37] = S"- (マイナス)";
			__mcTemp__12[38] = S"^ (べき乗)";
			__mcTemp__12[39] = S"\\ (右上)";
			__mcTemp__12[40] = S"@ (アットマーク)";
			__mcTemp__12[41] = S"[ (左括弧)";
			__mcTemp__12[42] = S"; (セミコロン)";
			__mcTemp__12[43] = S": (コロン)";
			__mcTemp__12[44] = S"] (右括弧)";
			__mcTemp__12[45] = S", (コンマ)";
			__mcTemp__12[46] = S"/ (スラッシュ)";
			__mcTemp__12[47] = S"\\ (右下)";
			__mcTemp__12[48] = S"0 (テンキー)";
			__mcTemp__12[49] = S"1 (テンキー)";
			__mcTemp__12[50] = S"2 (テンキー)";
			__mcTemp__12[51] = S"3 (テンキー)";
			__mcTemp__12[52] = S"4 (テンキー)";
			__mcTemp__12[53] = S"5 (テンキー)";
			__mcTemp__12[54] = S"6 (テンキー)";
			__mcTemp__12[55] = S"7 (テンキー)";
			__mcTemp__12[56] = S"8 (テンキー)";
			__mcTemp__12[57] = S"9 (テンキー)";
			__mcTemp__12[58] = S". (テンキー)";
			__mcTemp__12[59] = S"/ (テンキー)";
			__mcTemp__12[60] = S"* (テンキー)";
			__mcTemp__12[61] = S"- (テンキー)";
			__mcTemp__12[62] = S"+ (テンキー)";
			__mcTemp__12[63] = S"Enter (テンキー)";
			this->DRoteCombo->Items->AddRange(__mcTemp__12);
			this->DRoteCombo->Location = System::Drawing::Point(304, 220);
			this->DRoteCombo->Name = S"DRoteCombo";
			this->DRoteCombo->Size = System::Drawing::Size(104, 20);
			this->DRoteCombo->TabIndex = 19;
			this->DRoteCombo->SelectedIndexChanged += new System::EventHandler(this, DRoteCombo_SelectedIndexChanged);
			// 
			// URoteCombo
			// 
			this->URoteCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			System::Object* __mcTemp__13[] = new System::Object*[64];
			__mcTemp__13[0] = S"なし";
			__mcTemp__13[1] = S"Enter （エンター)";
			__mcTemp__13[2] = S"Space(スペース)";
			__mcTemp__13[3] = S"LShift (左)";
			__mcTemp__13[4] = S"RShift (右)";
			__mcTemp__13[5] = S"LCtrl (左)";
			__mcTemp__13[6] = S"RCtrl (右)";
			__mcTemp__13[7] = S"Right (カーソル)";
			__mcTemp__13[8] = S"Left   (カーソル)";
			__mcTemp__13[9] = S"Up    (カーソル)";
			__mcTemp__13[10] = S"down (カーソル)";
			__mcTemp__13[11] = S"A";
			__mcTemp__13[12] = S"B";
			__mcTemp__13[13] = S"C";
			__mcTemp__13[14] = S"D";
			__mcTemp__13[15] = S"E";
			__mcTemp__13[16] = S"F";
			__mcTemp__13[17] = S"G";
			__mcTemp__13[18] = S"H";
			__mcTemp__13[19] = S"I";
			__mcTemp__13[20] = S"J";
			__mcTemp__13[21] = S"K";
			__mcTemp__13[22] = S"L";
			__mcTemp__13[23] = S"M";
			__mcTemp__13[24] = S"N";
			__mcTemp__13[25] = S"O";
			__mcTemp__13[26] = S"P";
			__mcTemp__13[27] = S"Q";
			__mcTemp__13[28] = S"R";
			__mcTemp__13[29] = S"S";
			__mcTemp__13[30] = S"T";
			__mcTemp__13[31] = S"U";
			__mcTemp__13[32] = S"V";
			__mcTemp__13[33] = S"W";
			__mcTemp__13[34] = S"X";
			__mcTemp__13[35] = S"Y";
			__mcTemp__13[36] = S"Z";
			__mcTemp__13[37] = S"- (マイナス)";
			__mcTemp__13[38] = S"^ (べき乗)";
			__mcTemp__13[39] = S"\\ (右上)";
			__mcTemp__13[40] = S"@ (アットマーク)";
			__mcTemp__13[41] = S"[ (左括弧)";
			__mcTemp__13[42] = S"; (セミコロン)";
			__mcTemp__13[43] = S": (コロン)";
			__mcTemp__13[44] = S"] (右括弧)";
			__mcTemp__13[45] = S", (コンマ)";
			__mcTemp__13[46] = S"/ (スラッシュ)";
			__mcTemp__13[47] = S"\\ (右下)";
			__mcTemp__13[48] = S"0 (テンキー)";
			__mcTemp__13[49] = S"1 (テンキー)";
			__mcTemp__13[50] = S"2 (テンキー)";
			__mcTemp__13[51] = S"3 (テンキー)";
			__mcTemp__13[52] = S"4 (テンキー)";
			__mcTemp__13[53] = S"5 (テンキー)";
			__mcTemp__13[54] = S"6 (テンキー)";
			__mcTemp__13[55] = S"7 (テンキー)";
			__mcTemp__13[56] = S"8 (テンキー)";
			__mcTemp__13[57] = S"9 (テンキー)";
			__mcTemp__13[58] = S". (テンキー)";
			__mcTemp__13[59] = S"/ (テンキー)";
			__mcTemp__13[60] = S"* (テンキー)";
			__mcTemp__13[61] = S"- (テンキー)";
			__mcTemp__13[62] = S"+ (テンキー)";
			__mcTemp__13[63] = S"Enter (テンキー)";
			this->URoteCombo->Items->AddRange(__mcTemp__13);
			this->URoteCombo->Location = System::Drawing::Point(304, 188);
			this->URoteCombo->Name = S"URoteCombo";
			this->URoteCombo->Size = System::Drawing::Size(104, 20);
			this->URoteCombo->TabIndex = 18;
			this->URoteCombo->SelectedIndexChanged += new System::EventHandler(this, URoteCombo_SelectedIndexChanged);
			// 
			// label14
			// 
			this->label14->Location = System::Drawing::Point(224, 224);
			this->label14->Name = S"label14";
			this->label14->Size = System::Drawing::Size(80, 16);
			this->label14->TabIndex = 17;
			this->label14->Text = S"下回転ボタン";
			// 
			// label15
			// 
			this->label15->Location = System::Drawing::Point(224, 192);
			this->label15->Name = S"label15";
			this->label15->Size = System::Drawing::Size(80, 16);
			this->label15->TabIndex = 16;
			this->label15->Text = S"上回転ボタン";
			// 
			// UMoveCombo
			// 
			this->UMoveCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			System::Object* __mcTemp__14[] = new System::Object*[64];
			__mcTemp__14[0] = S"なし";
			__mcTemp__14[1] = S"Enter （エンター)";
			__mcTemp__14[2] = S"Space(スペース)";
			__mcTemp__14[3] = S"LShift (左)";
			__mcTemp__14[4] = S"RShift (右)";
			__mcTemp__14[5] = S"LCtrl (左)";
			__mcTemp__14[6] = S"RCtrl (右)";
			__mcTemp__14[7] = S"Right (カーソル)";
			__mcTemp__14[8] = S"Left   (カーソル)";
			__mcTemp__14[9] = S"Up    (カーソル)";
			__mcTemp__14[10] = S"down (カーソル)";
			__mcTemp__14[11] = S"A";
			__mcTemp__14[12] = S"B";
			__mcTemp__14[13] = S"C";
			__mcTemp__14[14] = S"D";
			__mcTemp__14[15] = S"E";
			__mcTemp__14[16] = S"F";
			__mcTemp__14[17] = S"G";
			__mcTemp__14[18] = S"H";
			__mcTemp__14[19] = S"I";
			__mcTemp__14[20] = S"J";
			__mcTemp__14[21] = S"K";
			__mcTemp__14[22] = S"L";
			__mcTemp__14[23] = S"M";
			__mcTemp__14[24] = S"N";
			__mcTemp__14[25] = S"O";
			__mcTemp__14[26] = S"P";
			__mcTemp__14[27] = S"Q";
			__mcTemp__14[28] = S"R";
			__mcTemp__14[29] = S"S";
			__mcTemp__14[30] = S"T";
			__mcTemp__14[31] = S"U";
			__mcTemp__14[32] = S"V";
			__mcTemp__14[33] = S"W";
			__mcTemp__14[34] = S"X";
			__mcTemp__14[35] = S"Y";
			__mcTemp__14[36] = S"Z";
			__mcTemp__14[37] = S"- (マイナス)";
			__mcTemp__14[38] = S"^ (べき乗)";
			__mcTemp__14[39] = S"\\ (右上)";
			__mcTemp__14[40] = S"@ (アットマーク)";
			__mcTemp__14[41] = S"[ (左括弧)";
			__mcTemp__14[42] = S"; (セミコロン)";
			__mcTemp__14[43] = S": (コロン)";
			__mcTemp__14[44] = S"] (右括弧)";
			__mcTemp__14[45] = S", (コンマ)";
			__mcTemp__14[46] = S"/ (スラッシュ)";
			__mcTemp__14[47] = S"\\ (右下)";
			__mcTemp__14[48] = S"0 (テンキー)";
			__mcTemp__14[49] = S"1 (テンキー)";
			__mcTemp__14[50] = S"2 (テンキー)";
			__mcTemp__14[51] = S"3 (テンキー)";
			__mcTemp__14[52] = S"4 (テンキー)";
			__mcTemp__14[53] = S"5 (テンキー)";
			__mcTemp__14[54] = S"6 (テンキー)";
			__mcTemp__14[55] = S"7 (テンキー)";
			__mcTemp__14[56] = S"8 (テンキー)";
			__mcTemp__14[57] = S"9 (テンキー)";
			__mcTemp__14[58] = S". (テンキー)";
			__mcTemp__14[59] = S"/ (テンキー)";
			__mcTemp__14[60] = S"* (テンキー)";
			__mcTemp__14[61] = S"- (テンキー)";
			__mcTemp__14[62] = S"+ (テンキー)";
			__mcTemp__14[63] = S"Enter (テンキー)";
			this->UMoveCombo->Items->AddRange(__mcTemp__14);
			this->UMoveCombo->Location = System::Drawing::Point(304, 60);
			this->UMoveCombo->Name = S"UMoveCombo";
			this->UMoveCombo->Size = System::Drawing::Size(104, 20);
			this->UMoveCombo->TabIndex = 14;
			this->UMoveCombo->SelectedIndexChanged += new System::EventHandler(this, UMoveCombo_SelectedIndexChanged);
			// 
			// label13
			// 
			this->label13->Location = System::Drawing::Point(224, 64);
			this->label13->Name = S"label13";
			this->label13->Size = System::Drawing::Size(80, 16);
			this->label13->TabIndex = 15;
			this->label13->Text = S"上移動ボタン";
			// 
			// LRoteCombo
			// 
			this->LRoteCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			System::Object* __mcTemp__15[] = new System::Object*[64];
			__mcTemp__15[0] = S"なし";
			__mcTemp__15[1] = S"Enter （エンター)";
			__mcTemp__15[2] = S"Space(スペース)";
			__mcTemp__15[3] = S"LShift (左)";
			__mcTemp__15[4] = S"RShift (右)";
			__mcTemp__15[5] = S"LCtrl (左)";
			__mcTemp__15[6] = S"RCtrl (右)";
			__mcTemp__15[7] = S"Right (カーソル)";
			__mcTemp__15[8] = S"Left   (カーソル)";
			__mcTemp__15[9] = S"Up    (カーソル)";
			__mcTemp__15[10] = S"down (カーソル)";
			__mcTemp__15[11] = S"A";
			__mcTemp__15[12] = S"B";
			__mcTemp__15[13] = S"C";
			__mcTemp__15[14] = S"D";
			__mcTemp__15[15] = S"E";
			__mcTemp__15[16] = S"F";
			__mcTemp__15[17] = S"G";
			__mcTemp__15[18] = S"H";
			__mcTemp__15[19] = S"I";
			__mcTemp__15[20] = S"J";
			__mcTemp__15[21] = S"K";
			__mcTemp__15[22] = S"L";
			__mcTemp__15[23] = S"M";
			__mcTemp__15[24] = S"N";
			__mcTemp__15[25] = S"O";
			__mcTemp__15[26] = S"P";
			__mcTemp__15[27] = S"Q";
			__mcTemp__15[28] = S"R";
			__mcTemp__15[29] = S"S";
			__mcTemp__15[30] = S"T";
			__mcTemp__15[31] = S"U";
			__mcTemp__15[32] = S"V";
			__mcTemp__15[33] = S"W";
			__mcTemp__15[34] = S"X";
			__mcTemp__15[35] = S"Y";
			__mcTemp__15[36] = S"Z";
			__mcTemp__15[37] = S"- (マイナス)";
			__mcTemp__15[38] = S"^ (べき乗)";
			__mcTemp__15[39] = S"\\ (右上)";
			__mcTemp__15[40] = S"@ (アットマーク)";
			__mcTemp__15[41] = S"[ (左括弧)";
			__mcTemp__15[42] = S"; (セミコロン)";
			__mcTemp__15[43] = S": (コロン)";
			__mcTemp__15[44] = S"] (右括弧)";
			__mcTemp__15[45] = S", (コンマ)";
			__mcTemp__15[46] = S"/ (スラッシュ)";
			__mcTemp__15[47] = S"\\ (右下)";
			__mcTemp__15[48] = S"0 (テンキー)";
			__mcTemp__15[49] = S"1 (テンキー)";
			__mcTemp__15[50] = S"2 (テンキー)";
			__mcTemp__15[51] = S"3 (テンキー)";
			__mcTemp__15[52] = S"4 (テンキー)";
			__mcTemp__15[53] = S"5 (テンキー)";
			__mcTemp__15[54] = S"6 (テンキー)";
			__mcTemp__15[55] = S"7 (テンキー)";
			__mcTemp__15[56] = S"8 (テンキー)";
			__mcTemp__15[57] = S"9 (テンキー)";
			__mcTemp__15[58] = S". (テンキー)";
			__mcTemp__15[59] = S"/ (テンキー)";
			__mcTemp__15[60] = S"* (テンキー)";
			__mcTemp__15[61] = S"- (テンキー)";
			__mcTemp__15[62] = S"+ (テンキー)";
			__mcTemp__15[63] = S"Enter (テンキー)";
			this->LRoteCombo->Items->AddRange(__mcTemp__15);
			this->LRoteCombo->Location = System::Drawing::Point(104, 220);
			this->LRoteCombo->Name = S"LRoteCombo";
			this->LRoteCombo->Size = System::Drawing::Size(104, 20);
			this->LRoteCombo->TabIndex = 13;
			this->LRoteCombo->SelectedIndexChanged += new System::EventHandler(this, LRoteCombo_SelectedIndexChanged);
			// 
			// RRoteCombo
			// 
			this->RRoteCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			System::Object* __mcTemp__16[] = new System::Object*[64];
			__mcTemp__16[0] = S"なし";
			__mcTemp__16[1] = S"Enter （エンター)";
			__mcTemp__16[2] = S"Space(スペース)";
			__mcTemp__16[3] = S"LShift (左)";
			__mcTemp__16[4] = S"RShift (右)";
			__mcTemp__16[5] = S"LCtrl (左)";
			__mcTemp__16[6] = S"RCtrl (右)";
			__mcTemp__16[7] = S"Right (カーソル)";
			__mcTemp__16[8] = S"Left   (カーソル)";
			__mcTemp__16[9] = S"Up    (カーソル)";
			__mcTemp__16[10] = S"down (カーソル)";
			__mcTemp__16[11] = S"A";
			__mcTemp__16[12] = S"B";
			__mcTemp__16[13] = S"C";
			__mcTemp__16[14] = S"D";
			__mcTemp__16[15] = S"E";
			__mcTemp__16[16] = S"F";
			__mcTemp__16[17] = S"G";
			__mcTemp__16[18] = S"H";
			__mcTemp__16[19] = S"I";
			__mcTemp__16[20] = S"J";
			__mcTemp__16[21] = S"K";
			__mcTemp__16[22] = S"L";
			__mcTemp__16[23] = S"M";
			__mcTemp__16[24] = S"N";
			__mcTemp__16[25] = S"O";
			__mcTemp__16[26] = S"P";
			__mcTemp__16[27] = S"Q";
			__mcTemp__16[28] = S"R";
			__mcTemp__16[29] = S"S";
			__mcTemp__16[30] = S"T";
			__mcTemp__16[31] = S"U";
			__mcTemp__16[32] = S"V";
			__mcTemp__16[33] = S"W";
			__mcTemp__16[34] = S"X";
			__mcTemp__16[35] = S"Y";
			__mcTemp__16[36] = S"Z";
			__mcTemp__16[37] = S"- (マイナス)";
			__mcTemp__16[38] = S"^ (べき乗)";
			__mcTemp__16[39] = S"\\ (右上)";
			__mcTemp__16[40] = S"@ (アットマーク)";
			__mcTemp__16[41] = S"[ (左括弧)";
			__mcTemp__16[42] = S"; (セミコロン)";
			__mcTemp__16[43] = S": (コロン)";
			__mcTemp__16[44] = S"] (右括弧)";
			__mcTemp__16[45] = S", (コンマ)";
			__mcTemp__16[46] = S"/ (スラッシュ)";
			__mcTemp__16[47] = S"\\ (右下)";
			__mcTemp__16[48] = S"0 (テンキー)";
			__mcTemp__16[49] = S"1 (テンキー)";
			__mcTemp__16[50] = S"2 (テンキー)";
			__mcTemp__16[51] = S"3 (テンキー)";
			__mcTemp__16[52] = S"4 (テンキー)";
			__mcTemp__16[53] = S"5 (テンキー)";
			__mcTemp__16[54] = S"6 (テンキー)";
			__mcTemp__16[55] = S"7 (テンキー)";
			__mcTemp__16[56] = S"8 (テンキー)";
			__mcTemp__16[57] = S"9 (テンキー)";
			__mcTemp__16[58] = S". (テンキー)";
			__mcTemp__16[59] = S"/ (テンキー)";
			__mcTemp__16[60] = S"* (テンキー)";
			__mcTemp__16[61] = S"- (テンキー)";
			__mcTemp__16[62] = S"+ (テンキー)";
			__mcTemp__16[63] = S"Enter (テンキー)";
			this->RRoteCombo->Items->AddRange(__mcTemp__16);
			this->RRoteCombo->Location = System::Drawing::Point(104, 188);
			this->RRoteCombo->Name = S"RRoteCombo";
			this->RRoteCombo->Size = System::Drawing::Size(104, 20);
			this->RRoteCombo->TabIndex = 12;
			this->RRoteCombo->SelectedIndexChanged += new System::EventHandler(this, RRoteCombo_SelectedIndexChanged);
			// 
			// ItemCombo
			// 
			this->ItemCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			System::Object* __mcTemp__17[] = new System::Object*[64];
			__mcTemp__17[0] = S"なし";
			__mcTemp__17[1] = S"Enter （エンター)";
			__mcTemp__17[2] = S"Space(スペース)";
			__mcTemp__17[3] = S"LShift (左)";
			__mcTemp__17[4] = S"RShift (右)";
			__mcTemp__17[5] = S"LCtrl (左)";
			__mcTemp__17[6] = S"RCtrl (右)";
			__mcTemp__17[7] = S"Right (カーソル)";
			__mcTemp__17[8] = S"Left   (カーソル)";
			__mcTemp__17[9] = S"Up    (カーソル)";
			__mcTemp__17[10] = S"down (カーソル)";
			__mcTemp__17[11] = S"A";
			__mcTemp__17[12] = S"B";
			__mcTemp__17[13] = S"C";
			__mcTemp__17[14] = S"D";
			__mcTemp__17[15] = S"E";
			__mcTemp__17[16] = S"F";
			__mcTemp__17[17] = S"G";
			__mcTemp__17[18] = S"H";
			__mcTemp__17[19] = S"I";
			__mcTemp__17[20] = S"J";
			__mcTemp__17[21] = S"K";
			__mcTemp__17[22] = S"L";
			__mcTemp__17[23] = S"M";
			__mcTemp__17[24] = S"N";
			__mcTemp__17[25] = S"O";
			__mcTemp__17[26] = S"P";
			__mcTemp__17[27] = S"Q";
			__mcTemp__17[28] = S"R";
			__mcTemp__17[29] = S"S";
			__mcTemp__17[30] = S"T";
			__mcTemp__17[31] = S"U";
			__mcTemp__17[32] = S"V";
			__mcTemp__17[33] = S"W";
			__mcTemp__17[34] = S"X";
			__mcTemp__17[35] = S"Y";
			__mcTemp__17[36] = S"Z";
			__mcTemp__17[37] = S"- (マイナス)";
			__mcTemp__17[38] = S"^ (べき乗)";
			__mcTemp__17[39] = S"\\ (右上)";
			__mcTemp__17[40] = S"@ (アットマーク)";
			__mcTemp__17[41] = S"[ (左括弧)";
			__mcTemp__17[42] = S"; (セミコロン)";
			__mcTemp__17[43] = S": (コロン)";
			__mcTemp__17[44] = S"] (右括弧)";
			__mcTemp__17[45] = S", (コンマ)";
			__mcTemp__17[46] = S"/ (スラッシュ)";
			__mcTemp__17[47] = S"\\ (右下)";
			__mcTemp__17[48] = S"0 (テンキー)";
			__mcTemp__17[49] = S"1 (テンキー)";
			__mcTemp__17[50] = S"2 (テンキー)";
			__mcTemp__17[51] = S"3 (テンキー)";
			__mcTemp__17[52] = S"4 (テンキー)";
			__mcTemp__17[53] = S"5 (テンキー)";
			__mcTemp__17[54] = S"6 (テンキー)";
			__mcTemp__17[55] = S"7 (テンキー)";
			__mcTemp__17[56] = S"8 (テンキー)";
			__mcTemp__17[57] = S"9 (テンキー)";
			__mcTemp__17[58] = S". (テンキー)";
			__mcTemp__17[59] = S"/ (テンキー)";
			__mcTemp__17[60] = S"* (テンキー)";
			__mcTemp__17[61] = S"- (テンキー)";
			__mcTemp__17[62] = S"+ (テンキー)";
			__mcTemp__17[63] = S"Enter (テンキー)ンキー)";
			this->ItemCombo->Items->AddRange(__mcTemp__17);
			this->ItemCombo->Location = System::Drawing::Point(104, 156);
			this->ItemCombo->Name = S"ItemCombo";
			this->ItemCombo->Size = System::Drawing::Size(104, 20);
			this->ItemCombo->TabIndex = 11;
			this->ItemCombo->SelectedIndexChanged += new System::EventHandler(this, ItemCombo_SelectedIndexChanged);
			// 
			// JumpCombo
			// 
			this->JumpCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			System::Object* __mcTemp__18[] = new System::Object*[64];
			__mcTemp__18[0] = S"なし";
			__mcTemp__18[1] = S"Enter （エンター)";
			__mcTemp__18[2] = S"Space(スペース)";
			__mcTemp__18[3] = S"LShift (左)";
			__mcTemp__18[4] = S"RShift (右)";
			__mcTemp__18[5] = S"LCtrl (左)";
			__mcTemp__18[6] = S"RCtrl (右)";
			__mcTemp__18[7] = S"Right (カーソル)";
			__mcTemp__18[8] = S"Left   (カーソル)";
			__mcTemp__18[9] = S"Up    (カーソル)";
			__mcTemp__18[10] = S"down (カーソル)";
			__mcTemp__18[11] = S"A";
			__mcTemp__18[12] = S"B";
			__mcTemp__18[13] = S"C";
			__mcTemp__18[14] = S"D";
			__mcTemp__18[15] = S"E";
			__mcTemp__18[16] = S"F";
			__mcTemp__18[17] = S"G";
			__mcTemp__18[18] = S"H";
			__mcTemp__18[19] = S"I";
			__mcTemp__18[20] = S"J";
			__mcTemp__18[21] = S"K";
			__mcTemp__18[22] = S"L";
			__mcTemp__18[23] = S"M";
			__mcTemp__18[24] = S"N";
			__mcTemp__18[25] = S"O";
			__mcTemp__18[26] = S"P";
			__mcTemp__18[27] = S"Q";
			__mcTemp__18[28] = S"R";
			__mcTemp__18[29] = S"S";
			__mcTemp__18[30] = S"T";
			__mcTemp__18[31] = S"U";
			__mcTemp__18[32] = S"V";
			__mcTemp__18[33] = S"W";
			__mcTemp__18[34] = S"X";
			__mcTemp__18[35] = S"Y";
			__mcTemp__18[36] = S"Z";
			__mcTemp__18[37] = S"- (マイナス)";
			__mcTemp__18[38] = S"^ (べき乗)";
			__mcTemp__18[39] = S"\\ (右上)";
			__mcTemp__18[40] = S"@ (アットマーク)";
			__mcTemp__18[41] = S"[ (左括弧)";
			__mcTemp__18[42] = S"; (セミコロン)";
			__mcTemp__18[43] = S": (コロン)";
			__mcTemp__18[44] = S"] (右括弧)";
			__mcTemp__18[45] = S", (コンマ)";
			__mcTemp__18[46] = S"/ (スラッシュ)";
			__mcTemp__18[47] = S"\\ (右下)";
			__mcTemp__18[48] = S"0 (テンキー)";
			__mcTemp__18[49] = S"1 (テンキー)";
			__mcTemp__18[50] = S"2 (テンキー)";
			__mcTemp__18[51] = S"3 (テンキー)";
			__mcTemp__18[52] = S"4 (テンキー)";
			__mcTemp__18[53] = S"5 (テンキー)";
			__mcTemp__18[54] = S"6 (テンキー)";
			__mcTemp__18[55] = S"7 (テンキー)";
			__mcTemp__18[56] = S"8 (テンキー)";
			__mcTemp__18[57] = S"9 (テンキー)";
			__mcTemp__18[58] = S". (テンキー)";
			__mcTemp__18[59] = S"/ (テンキー)";
			__mcTemp__18[60] = S"* (テンキー)";
			__mcTemp__18[61] = S"- (テンキー)";
			__mcTemp__18[62] = S"+ (テンキー)";
			__mcTemp__18[63] = S"Enter (テンキー)";
			this->JumpCombo->Items->AddRange(__mcTemp__18);
			this->JumpCombo->Location = System::Drawing::Point(104, 124);
			this->JumpCombo->Name = S"JumpCombo";
			this->JumpCombo->Size = System::Drawing::Size(104, 20);
			this->JumpCombo->TabIndex = 10;
			this->JumpCombo->SelectedIndexChanged += new System::EventHandler(this, JumpCombo_SelectedIndexChanged);
			// 
			// StartCombo
			// 
			this->StartCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			System::Object* __mcTemp__19[] = new System::Object*[64];
			__mcTemp__19[0] = S"なし";
			__mcTemp__19[1] = S"Enter （エンター)";
			__mcTemp__19[2] = S"Space(スペース)";
			__mcTemp__19[3] = S"LShift (左)";
			__mcTemp__19[4] = S"RShift (右)";
			__mcTemp__19[5] = S"LCtrl (左)";
			__mcTemp__19[6] = S"RCtrl (右)";
			__mcTemp__19[7] = S"Right (カーソル)";
			__mcTemp__19[8] = S"Left   (カーソル)";
			__mcTemp__19[9] = S"Up    (カーソル)";
			__mcTemp__19[10] = S"down (カーソル)";
			__mcTemp__19[11] = S"A";
			__mcTemp__19[12] = S"B";
			__mcTemp__19[13] = S"C";
			__mcTemp__19[14] = S"D";
			__mcTemp__19[15] = S"E";
			__mcTemp__19[16] = S"F";
			__mcTemp__19[17] = S"G";
			__mcTemp__19[18] = S"H";
			__mcTemp__19[19] = S"I";
			__mcTemp__19[20] = S"J";
			__mcTemp__19[21] = S"K";
			__mcTemp__19[22] = S"L";
			__mcTemp__19[23] = S"M";
			__mcTemp__19[24] = S"N";
			__mcTemp__19[25] = S"O";
			__mcTemp__19[26] = S"P";
			__mcTemp__19[27] = S"Q";
			__mcTemp__19[28] = S"R";
			__mcTemp__19[29] = S"S";
			__mcTemp__19[30] = S"T";
			__mcTemp__19[31] = S"U";
			__mcTemp__19[32] = S"V";
			__mcTemp__19[33] = S"W";
			__mcTemp__19[34] = S"X";
			__mcTemp__19[35] = S"Y";
			__mcTemp__19[36] = S"Z";
			__mcTemp__19[37] = S"- (マイナス)";
			__mcTemp__19[38] = S"^ (べき乗)";
			__mcTemp__19[39] = S"\\ (右上)";
			__mcTemp__19[40] = S"@ (アットマーク)";
			__mcTemp__19[41] = S"[ (左括弧)";
			__mcTemp__19[42] = S"; (セミコロン)";
			__mcTemp__19[43] = S": (コロン)";
			__mcTemp__19[44] = S"] (右括弧)";
			__mcTemp__19[45] = S", (コンマ)";
			__mcTemp__19[46] = S"/ (スラッシュ)";
			__mcTemp__19[47] = S"\\ (右下)";
			__mcTemp__19[48] = S"0 (テンキー)";
			__mcTemp__19[49] = S"1 (テンキー)";
			__mcTemp__19[50] = S"2 (テンキー)";
			__mcTemp__19[51] = S"3 (テンキー)";
			__mcTemp__19[52] = S"4 (テンキー)";
			__mcTemp__19[53] = S"5 (テンキー)";
			__mcTemp__19[54] = S"6 (テンキー)";
			__mcTemp__19[55] = S"7 (テンキー)";
			__mcTemp__19[56] = S"8 (テンキー)";
			__mcTemp__19[57] = S"9 (テンキー)";
			__mcTemp__19[58] = S". (テンキー)";
			__mcTemp__19[59] = S"/ (テンキー)";
			__mcTemp__19[60] = S"* (テンキー)";
			__mcTemp__19[61] = S"- (テンキー)";
			__mcTemp__19[62] = S"+ (テンキー)";
			__mcTemp__19[63] = S"Enter (テンキー)";
			this->StartCombo->Items->AddRange(__mcTemp__19);
			this->StartCombo->Location = System::Drawing::Point(104, 92);
			this->StartCombo->Name = S"StartCombo";
			this->StartCombo->Size = System::Drawing::Size(104, 20);
			this->StartCombo->TabIndex = 8;
			this->StartCombo->SelectedIndexChanged += new System::EventHandler(this, StartCombo_SelectedIndexChanged);
			// 
			// CancelCombo
			// 
			this->CancelCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			System::Object* __mcTemp__20[] = new System::Object*[64];
			__mcTemp__20[0] = S"なし";
			__mcTemp__20[1] = S"Enter （エンター)";
			__mcTemp__20[2] = S"Space(スペース)";
			__mcTemp__20[3] = S"LShift (左)";
			__mcTemp__20[4] = S"RShift (右)";
			__mcTemp__20[5] = S"LCtrl (左)";
			__mcTemp__20[6] = S"RCtrl (右)";
			__mcTemp__20[7] = S"Right (カーソル)";
			__mcTemp__20[8] = S"Left   (カーソル)";
			__mcTemp__20[9] = S"Up    (カーソル)";
			__mcTemp__20[10] = S"down (カーソル)";
			__mcTemp__20[11] = S"A";
			__mcTemp__20[12] = S"B";
			__mcTemp__20[13] = S"C";
			__mcTemp__20[14] = S"D";
			__mcTemp__20[15] = S"E";
			__mcTemp__20[16] = S"F";
			__mcTemp__20[17] = S"G";
			__mcTemp__20[18] = S"H";
			__mcTemp__20[19] = S"I";
			__mcTemp__20[20] = S"J";
			__mcTemp__20[21] = S"K";
			__mcTemp__20[22] = S"L";
			__mcTemp__20[23] = S"M";
			__mcTemp__20[24] = S"N";
			__mcTemp__20[25] = S"O";
			__mcTemp__20[26] = S"P";
			__mcTemp__20[27] = S"Q";
			__mcTemp__20[28] = S"R";
			__mcTemp__20[29] = S"S";
			__mcTemp__20[30] = S"T";
			__mcTemp__20[31] = S"U";
			__mcTemp__20[32] = S"V";
			__mcTemp__20[33] = S"W";
			__mcTemp__20[34] = S"X";
			__mcTemp__20[35] = S"Y";
			__mcTemp__20[36] = S"Z";
			__mcTemp__20[37] = S"- (マイナス)";
			__mcTemp__20[38] = S"^ (べき乗)";
			__mcTemp__20[39] = S"\\ (右上)";
			__mcTemp__20[40] = S"@ (アットマーク)";
			__mcTemp__20[41] = S"[ (左括弧)";
			__mcTemp__20[42] = S"; (セミコロン)";
			__mcTemp__20[43] = S": (コロン)";
			__mcTemp__20[44] = S"] (右括弧)";
			__mcTemp__20[45] = S", (コンマ)";
			__mcTemp__20[46] = S"/ (スラッシュ)";
			__mcTemp__20[47] = S"\\ (右下)";
			__mcTemp__20[48] = S"0 (テンキー)";
			__mcTemp__20[49] = S"1 (テンキー)";
			__mcTemp__20[50] = S"2 (テンキー)";
			__mcTemp__20[51] = S"3 (テンキー)";
			__mcTemp__20[52] = S"4 (テンキー)";
			__mcTemp__20[53] = S"5 (テンキー)";
			__mcTemp__20[54] = S"6 (テンキー)";
			__mcTemp__20[55] = S"7 (テンキー)";
			__mcTemp__20[56] = S"8 (テンキー)";
			__mcTemp__20[57] = S"9 (テンキー)";
			__mcTemp__20[58] = S". (テンキー)";
			__mcTemp__20[59] = S"/ (テンキー)";
			__mcTemp__20[60] = S"* (テンキー)";
			__mcTemp__20[61] = S"- (テンキー)";
			__mcTemp__20[62] = S"+ (テンキー)";
			__mcTemp__20[63] = S"Enter (テンキー)";
			this->CancelCombo->Items->AddRange(__mcTemp__20);
			this->CancelCombo->Location = System::Drawing::Point(104, 60);
			this->CancelCombo->Name = S"CancelCombo";
			this->CancelCombo->Size = System::Drawing::Size(104, 20);
			this->CancelCombo->TabIndex = 7;
			this->CancelCombo->SelectedIndexChanged += new System::EventHandler(this, CancelCombo_SelectedIndexChanged);
			// 
			// label12
			// 
			this->label12->Location = System::Drawing::Point(24, 224);
			this->label12->Name = S"label12";
			this->label12->Size = System::Drawing::Size(80, 16);
			this->label12->TabIndex = 7;
			this->label12->Text = S"左回転ボタン";
			// 
			// label11
			// 
			this->label11->Location = System::Drawing::Point(24, 192);
			this->label11->Name = S"label11";
			this->label11->Size = System::Drawing::Size(80, 16);
			this->label11->TabIndex = 6;
			this->label11->Text = S"右回転ボタン";
			// 
			// label10
			// 
			this->label10->Location = System::Drawing::Point(24, 160);
			this->label10->Name = S"label10";
			this->label10->Size = System::Drawing::Size(80, 16);
			this->label10->TabIndex = 5;
			this->label10->Text = S"アイテムボタン";
			// 
			// label9
			// 
			this->label9->Location = System::Drawing::Point(24, 128);
			this->label9->Name = S"label9";
			this->label9->Size = System::Drawing::Size(80, 16);
			this->label9->TabIndex = 4;
			this->label9->Text = S"ジャンプボタン";
			// 
			// label8
			// 
			this->label8->Location = System::Drawing::Point(24, 96);
			this->label8->Name = S"label8";
			this->label8->Size = System::Drawing::Size(80, 16);
			this->label8->TabIndex = 3;
			this->label8->Text = S"スタートボタン";
			// 
			// label7
			// 
			this->label7->Location = System::Drawing::Point(24, 64);
			this->label7->Name = S"label7";
			this->label7->Size = System::Drawing::Size(80, 16);
			this->label7->TabIndex = 2;
			this->label7->Text = S"キャンセルボタン";
			// 
			// OKCombo
			// 
			this->OKCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			System::Object* __mcTemp__21[] = new System::Object*[64];
			__mcTemp__21[0] = S"なし";
			__mcTemp__21[1] = S"Enter （エンター)";
			__mcTemp__21[2] = S"Space(スペース)";
			__mcTemp__21[3] = S"LShift (左)";
			__mcTemp__21[4] = S"RShift (右)";
			__mcTemp__21[5] = S"LCtrl (左)";
			__mcTemp__21[6] = S"RCtrl (右)";
			__mcTemp__21[7] = S"Right (カーソル)";
			__mcTemp__21[8] = S"Left   (カーソル)";
			__mcTemp__21[9] = S"Up    (カーソル)";
			__mcTemp__21[10] = S"down (カーソル)";
			__mcTemp__21[11] = S"A";
			__mcTemp__21[12] = S"B";
			__mcTemp__21[13] = S"C";
			__mcTemp__21[14] = S"D";
			__mcTemp__21[15] = S"E";
			__mcTemp__21[16] = S"F";
			__mcTemp__21[17] = S"G";
			__mcTemp__21[18] = S"H";
			__mcTemp__21[19] = S"I";
			__mcTemp__21[20] = S"J";
			__mcTemp__21[21] = S"K";
			__mcTemp__21[22] = S"L";
			__mcTemp__21[23] = S"M";
			__mcTemp__21[24] = S"N";
			__mcTemp__21[25] = S"O";
			__mcTemp__21[26] = S"P";
			__mcTemp__21[27] = S"Q";
			__mcTemp__21[28] = S"R";
			__mcTemp__21[29] = S"S";
			__mcTemp__21[30] = S"T";
			__mcTemp__21[31] = S"U";
			__mcTemp__21[32] = S"V";
			__mcTemp__21[33] = S"W";
			__mcTemp__21[34] = S"X";
			__mcTemp__21[35] = S"Y";
			__mcTemp__21[36] = S"Z";
			__mcTemp__21[37] = S"- (マイナス)";
			__mcTemp__21[38] = S"^ (べき乗)";
			__mcTemp__21[39] = S"\\ (右上)";
			__mcTemp__21[40] = S"@ (アットマーク)";
			__mcTemp__21[41] = S"[ (左括弧)";
			__mcTemp__21[42] = S"; (セミコロン)";
			__mcTemp__21[43] = S": (コロン)";
			__mcTemp__21[44] = S"] (右括弧)";
			__mcTemp__21[45] = S", (コンマ)";
			__mcTemp__21[46] = S"/ (スラッシュ)";
			__mcTemp__21[47] = S"\\ (右下)";
			__mcTemp__21[48] = S"0 (テンキー)";
			__mcTemp__21[49] = S"1 (テンキー)";
			__mcTemp__21[50] = S"2 (テンキー)";
			__mcTemp__21[51] = S"3 (テンキー)";
			__mcTemp__21[52] = S"4 (テンキー)";
			__mcTemp__21[53] = S"5 (テンキー)";
			__mcTemp__21[54] = S"6 (テンキー)";
			__mcTemp__21[55] = S"7 (テンキー)";
			__mcTemp__21[56] = S"8 (テンキー)";
			__mcTemp__21[57] = S"9 (テンキー)";
			__mcTemp__21[58] = S". (テンキー)";
			__mcTemp__21[59] = S"/ (テンキー)";
			__mcTemp__21[60] = S"* (テンキー)";
			__mcTemp__21[61] = S"- (テンキー)";
			__mcTemp__21[62] = S"+ (テンキー)";
			__mcTemp__21[63] = S"Enter (テンキー)";
			this->OKCombo->Items->AddRange(__mcTemp__21);
			this->OKCombo->Location = System::Drawing::Point(104, 28);
			this->OKCombo->Name = S"OKCombo";
			this->OKCombo->Size = System::Drawing::Size(104, 20);
			this->OKCombo->TabIndex = 6;
			this->OKCombo->SelectedIndexChanged += new System::EventHandler(this, OKCombo_SelectedIndexChanged);
			// 
			// label6
			// 
			this->label6->Location = System::Drawing::Point(24, 32);
			this->label6->Name = S"label6";
			this->label6->Size = System::Drawing::Size(80, 16);
			this->label6->TabIndex = 1;
			this->label6->Text = S"決定ボタン";
			// 
			// JoyGroup
			// 
			this->JoyGroup->Controls->Add(this->MoveAxisNumeric);
			this->JoyGroup->Controls->Add(this->label29);
			this->JoyGroup->Controls->Add(this->VibCheck);
			this->JoyGroup->Controls->Add(this->RoteAxisNumeric);
			this->JoyGroup->Controls->Add(this->label28);
			this->JoyGroup->Controls->Add(this->RoteAxisComboJ);
			this->JoyGroup->Controls->Add(this->label27);
			this->JoyGroup->Controls->Add(this->MoveAxisComboJ);
			this->JoyGroup->Controls->Add(this->label26);
			this->JoyGroup->Controls->Add(this->LRoteComboJ);
			this->JoyGroup->Controls->Add(this->RRoteComboJ);
			this->JoyGroup->Controls->Add(this->ItemComboJ);
			this->JoyGroup->Controls->Add(this->JumpComboJ);
			this->JoyGroup->Controls->Add(this->StartComboJ);
			this->JoyGroup->Controls->Add(this->CancelComboJ);
			this->JoyGroup->Controls->Add(this->label20);
			this->JoyGroup->Controls->Add(this->label21);
			this->JoyGroup->Controls->Add(this->label22);
			this->JoyGroup->Controls->Add(this->label23);
			this->JoyGroup->Controls->Add(this->label24);
			this->JoyGroup->Controls->Add(this->label25);
			this->JoyGroup->Controls->Add(this->OKComboJ);
			this->JoyGroup->Controls->Add(this->label19);
			this->JoyGroup->Location = System::Drawing::Point(40, 80);
			this->JoyGroup->Name = S"JoyGroup";
			this->JoyGroup->Size = System::Drawing::Size(432, 256);
			this->JoyGroup->TabIndex = 6;
			this->JoyGroup->TabStop = false;
			// 
			// MoveAxisNumeric
			// 
			this->MoveAxisNumeric->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			System::Int32 __mcTemp__22[] = new System::Int32[4];
			__mcTemp__22[0] = 10;
			__mcTemp__22[1] = 0;
			__mcTemp__22[2] = 0;
			__mcTemp__22[3] = 0;
			this->MoveAxisNumeric->Increment = System::Decimal(__mcTemp__22);
			this->MoveAxisNumeric->Location = System::Drawing::Point(352, 157);
			this->MoveAxisNumeric->Name = S"MoveAxisNumeric";
			this->MoveAxisNumeric->ReadOnly = true;
			this->MoveAxisNumeric->Size = System::Drawing::Size(56, 19);
			this->MoveAxisNumeric->TabIndex = 15;
			System::Int32 __mcTemp__23[] = new System::Int32[4];
			__mcTemp__23[0] = 100;
			__mcTemp__23[1] = 0;
			__mcTemp__23[2] = 0;
			__mcTemp__23[3] = 0;
			this->MoveAxisNumeric->Value = System::Decimal(__mcTemp__23);
			this->MoveAxisNumeric->ValueChanged += new System::EventHandler(this, MoveAxisNumeric_ValueChanged);
			// 
			// label29
			// 
			this->label29->Location = System::Drawing::Point(224, 160);
			this->label29->Name = S"label29";
			this->label29->Size = System::Drawing::Size(144, 16);
			this->label29->TabIndex = 28;
			this->label29->Text = S"移動軸の無効範囲( % )";
			// 
			// VibCheck
			// 
			this->VibCheck->Location = System::Drawing::Point(224, 224);
			this->VibCheck->Name = S"VibCheck";
			this->VibCheck->Size = System::Drawing::Size(184, 16);
			this->VibCheck->TabIndex = 17;
			this->VibCheck->Text = S"バイブレーション(振動)";
			this->VibCheck->CheckedChanged += new System::EventHandler(this, VibCheck_CheckedChanged);
			// 
			// RoteAxisNumeric
			// 
			this->RoteAxisNumeric->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			System::Int32 __mcTemp__24[] = new System::Int32[4];
			__mcTemp__24[0] = 10;
			__mcTemp__24[1] = 0;
			__mcTemp__24[2] = 0;
			__mcTemp__24[3] = 0;
			this->RoteAxisNumeric->Increment = System::Decimal(__mcTemp__24);
			this->RoteAxisNumeric->Location = System::Drawing::Point(352, 189);
			this->RoteAxisNumeric->Name = S"RoteAxisNumeric";
			this->RoteAxisNumeric->ReadOnly = true;
			this->RoteAxisNumeric->Size = System::Drawing::Size(56, 19);
			this->RoteAxisNumeric->TabIndex = 16;
			System::Int32 __mcTemp__25[] = new System::Int32[4];
			__mcTemp__25[0] = 100;
			__mcTemp__25[1] = 0;
			__mcTemp__25[2] = 0;
			__mcTemp__25[3] = 0;
			this->RoteAxisNumeric->Value = System::Decimal(__mcTemp__25);
			this->RoteAxisNumeric->ValueChanged += new System::EventHandler(this, RoteAxisNumeric_ValueChanged);
			// 
			// label28
			// 
			this->label28->Location = System::Drawing::Point(224, 192);
			this->label28->Name = S"label28";
			this->label28->Size = System::Drawing::Size(144, 16);
			this->label28->TabIndex = 25;
			this->label28->Text = S"回転軸の無効範囲( % )";
			// 
			// RoteAxisComboJ
			// 
			this->RoteAxisComboJ->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->RoteAxisComboJ->ItemHeight = 12;
			System::Object* __mcTemp__26[] = new System::Object*[3];
			__mcTemp__26[0] = S"なし";
			__mcTemp__26[1] = S"軸1";
			__mcTemp__26[2] = S"軸2";
			this->RoteAxisComboJ->Items->AddRange(__mcTemp__26);
			this->RoteAxisComboJ->Location = System::Drawing::Point(304, 60);
			this->RoteAxisComboJ->Name = S"RoteAxisComboJ";
			this->RoteAxisComboJ->Size = System::Drawing::Size(104, 20);
			this->RoteAxisComboJ->TabIndex = 14;
			this->RoteAxisComboJ->SelectedIndexChanged += new System::EventHandler(this, RoteAxisComboJ_SelectedIndexChanged);
			// 
			// label27
			// 
			this->label27->Location = System::Drawing::Point(224, 64);
			this->label27->Name = S"label27";
			this->label27->Size = System::Drawing::Size(80, 16);
			this->label27->TabIndex = 23;
			this->label27->Text = S"回転軸";
			// 
			// MoveAxisComboJ
			// 
			this->MoveAxisComboJ->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->MoveAxisComboJ->ItemHeight = 12;
			System::Object* __mcTemp__27[] = new System::Object*[3];
			__mcTemp__27[0] = S"なし";
			__mcTemp__27[1] = S"軸1";
			__mcTemp__27[2] = S"軸2";
			this->MoveAxisComboJ->Items->AddRange(__mcTemp__27);
			this->MoveAxisComboJ->Location = System::Drawing::Point(304, 28);
			this->MoveAxisComboJ->Name = S"MoveAxisComboJ";
			this->MoveAxisComboJ->Size = System::Drawing::Size(104, 20);
			this->MoveAxisComboJ->TabIndex = 13;
			this->MoveAxisComboJ->SelectedIndexChanged += new System::EventHandler(this, MoveAxisComboJ_SelectedIndexChanged);
			// 
			// label26
			// 
			this->label26->Location = System::Drawing::Point(224, 32);
			this->label26->Name = S"label26";
			this->label26->Size = System::Drawing::Size(80, 16);
			this->label26->TabIndex = 21;
			this->label26->Text = S"移動軸";
			// 
			// LRoteComboJ
			// 
			this->LRoteComboJ->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->LRoteComboJ->ItemHeight = 12;
			System::Object* __mcTemp__28[] = new System::Object*[13];
			__mcTemp__28[0] = S"なし";
			__mcTemp__28[1] = S"ボタン1";
			__mcTemp__28[2] = S"ボタン2";
			__mcTemp__28[3] = S"ボタン3";
			__mcTemp__28[4] = S"ボタン4";
			__mcTemp__28[5] = S"ボタン5";
			__mcTemp__28[6] = S"ボタン6";
			__mcTemp__28[7] = S"ボタン7";
			__mcTemp__28[8] = S"ボタン8";
			__mcTemp__28[9] = S"ボタン9";
			__mcTemp__28[10] = S"ボタン10";
			__mcTemp__28[11] = S"ボタン11";
			__mcTemp__28[12] = S"ボタン12";
			this->LRoteComboJ->Items->AddRange(__mcTemp__28);
			this->LRoteComboJ->Location = System::Drawing::Point(104, 220);
			this->LRoteComboJ->Name = S"LRoteComboJ";
			this->LRoteComboJ->Size = System::Drawing::Size(104, 20);
			this->LRoteComboJ->TabIndex = 12;
			this->LRoteComboJ->SelectedIndexChanged += new System::EventHandler(this, LRoteComboJ_SelectedIndexChanged);
			// 
			// RRoteComboJ
			// 
			this->RRoteComboJ->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->RRoteComboJ->ItemHeight = 12;
			System::Object* __mcTemp__29[] = new System::Object*[13];
			__mcTemp__29[0] = S"なし";
			__mcTemp__29[1] = S"ボタン1";
			__mcTemp__29[2] = S"ボタン2";
			__mcTemp__29[3] = S"ボタン3";
			__mcTemp__29[4] = S"ボタン4";
			__mcTemp__29[5] = S"ボタン5";
			__mcTemp__29[6] = S"ボタン6";
			__mcTemp__29[7] = S"ボタン7";
			__mcTemp__29[8] = S"ボタン8";
			__mcTemp__29[9] = S"ボタン9";
			__mcTemp__29[10] = S"ボタン10";
			__mcTemp__29[11] = S"ボタン11";
			__mcTemp__29[12] = S"ボタン12";
			this->RRoteComboJ->Items->AddRange(__mcTemp__29);
			this->RRoteComboJ->Location = System::Drawing::Point(104, 188);
			this->RRoteComboJ->Name = S"RRoteComboJ";
			this->RRoteComboJ->Size = System::Drawing::Size(104, 20);
			this->RRoteComboJ->TabIndex = 11;
			this->RRoteComboJ->SelectedIndexChanged += new System::EventHandler(this, RRoteComboJ_SelectedIndexChanged);
			// 
			// ItemComboJ
			// 
			this->ItemComboJ->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ItemComboJ->ItemHeight = 12;
			System::Object* __mcTemp__30[] = new System::Object*[13];
			__mcTemp__30[0] = S"なし";
			__mcTemp__30[1] = S"ボタン1";
			__mcTemp__30[2] = S"ボタン2";
			__mcTemp__30[3] = S"ボタン3";
			__mcTemp__30[4] = S"ボタン4";
			__mcTemp__30[5] = S"ボタン5";
			__mcTemp__30[6] = S"ボタン6";
			__mcTemp__30[7] = S"ボタン7";
			__mcTemp__30[8] = S"ボタン8";
			__mcTemp__30[9] = S"ボタン9";
			__mcTemp__30[10] = S"ボタン10";
			__mcTemp__30[11] = S"ボタン11";
			__mcTemp__30[12] = S"ボタン12";
			this->ItemComboJ->Items->AddRange(__mcTemp__30);
			this->ItemComboJ->Location = System::Drawing::Point(104, 156);
			this->ItemComboJ->Name = S"ItemComboJ";
			this->ItemComboJ->Size = System::Drawing::Size(104, 20);
			this->ItemComboJ->TabIndex = 10;
			this->ItemComboJ->SelectedIndexChanged += new System::EventHandler(this, ItemComboJ_SelectedIndexChanged);
			// 
			// JumpComboJ
			// 
			this->JumpComboJ->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->JumpComboJ->ItemHeight = 12;
			System::Object* __mcTemp__31[] = new System::Object*[13];
			__mcTemp__31[0] = S"なし";
			__mcTemp__31[1] = S"ボタン1";
			__mcTemp__31[2] = S"ボタン2";
			__mcTemp__31[3] = S"ボタン3";
			__mcTemp__31[4] = S"ボタン4";
			__mcTemp__31[5] = S"ボタン5";
			__mcTemp__31[6] = S"ボタン6";
			__mcTemp__31[7] = S"ボタン7";
			__mcTemp__31[8] = S"ボタン8";
			__mcTemp__31[9] = S"ボタン9";
			__mcTemp__31[10] = S"ボタン10";
			__mcTemp__31[11] = S"ボタン11";
			__mcTemp__31[12] = S"ボタン12";
			this->JumpComboJ->Items->AddRange(__mcTemp__31);
			this->JumpComboJ->Location = System::Drawing::Point(104, 124);
			this->JumpComboJ->Name = S"JumpComboJ";
			this->JumpComboJ->Size = System::Drawing::Size(104, 20);
			this->JumpComboJ->TabIndex = 9;
			this->JumpComboJ->SelectedIndexChanged += new System::EventHandler(this, JumpComboJ_SelectedIndexChanged);
			// 
			// StartComboJ
			// 
			this->StartComboJ->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->StartComboJ->ItemHeight = 12;
			System::Object* __mcTemp__32[] = new System::Object*[13];
			__mcTemp__32[0] = S"なし";
			__mcTemp__32[1] = S"ボタン1";
			__mcTemp__32[2] = S"ボタン2";
			__mcTemp__32[3] = S"ボタン3";
			__mcTemp__32[4] = S"ボタン4";
			__mcTemp__32[5] = S"ボタン5";
			__mcTemp__32[6] = S"ボタン6";
			__mcTemp__32[7] = S"ボタン7";
			__mcTemp__32[8] = S"ボタン8";
			__mcTemp__32[9] = S"ボタン9";
			__mcTemp__32[10] = S"ボタン10";
			__mcTemp__32[11] = S"ボタン11";
			__mcTemp__32[12] = S"ボタン12";
			this->StartComboJ->Items->AddRange(__mcTemp__32);
			this->StartComboJ->Location = System::Drawing::Point(104, 92);
			this->StartComboJ->Name = S"StartComboJ";
			this->StartComboJ->Size = System::Drawing::Size(104, 20);
			this->StartComboJ->TabIndex = 8;
			this->StartComboJ->SelectedIndexChanged += new System::EventHandler(this, StartComboJ_SelectedIndexChanged);
			// 
			// CancelComboJ
			// 
			this->CancelComboJ->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->CancelComboJ->ItemHeight = 12;
			System::Object* __mcTemp__33[] = new System::Object*[13];
			__mcTemp__33[0] = S"なし";
			__mcTemp__33[1] = S"ボタン1";
			__mcTemp__33[2] = S"ボタン2";
			__mcTemp__33[3] = S"ボタン3";
			__mcTemp__33[4] = S"ボタン4";
			__mcTemp__33[5] = S"ボタン5";
			__mcTemp__33[6] = S"ボタン6";
			__mcTemp__33[7] = S"ボタン7";
			__mcTemp__33[8] = S"ボタン8";
			__mcTemp__33[9] = S"ボタン9";
			__mcTemp__33[10] = S"ボタン10";
			__mcTemp__33[11] = S"ボタン11";
			__mcTemp__33[12] = S"ボタン12";
			this->CancelComboJ->Items->AddRange(__mcTemp__33);
			this->CancelComboJ->Location = System::Drawing::Point(104, 60);
			this->CancelComboJ->Name = S"CancelComboJ";
			this->CancelComboJ->Size = System::Drawing::Size(104, 20);
			this->CancelComboJ->TabIndex = 7;
			this->CancelComboJ->SelectedIndexChanged += new System::EventHandler(this, CancelComboJ_SelectedIndexChanged);
			// 
			// label20
			// 
			this->label20->Location = System::Drawing::Point(24, 224);
			this->label20->Name = S"label20";
			this->label20->Size = System::Drawing::Size(80, 16);
			this->label20->TabIndex = 13;
			this->label20->Text = S"左回転ボタン";
			// 
			// label21
			// 
			this->label21->Location = System::Drawing::Point(24, 192);
			this->label21->Name = S"label21";
			this->label21->Size = System::Drawing::Size(80, 16);
			this->label21->TabIndex = 12;
			this->label21->Text = S"右回転ボタン";
			// 
			// label22
			// 
			this->label22->Location = System::Drawing::Point(24, 160);
			this->label22->Name = S"label22";
			this->label22->Size = System::Drawing::Size(80, 16);
			this->label22->TabIndex = 11;
			this->label22->Text = S"アイテムボタン";
			// 
			// label23
			// 
			this->label23->Location = System::Drawing::Point(24, 128);
			this->label23->Name = S"label23";
			this->label23->Size = System::Drawing::Size(80, 16);
			this->label23->TabIndex = 10;
			this->label23->Text = S"ジャンプボタン";
			// 
			// label24
			// 
			this->label24->Location = System::Drawing::Point(24, 96);
			this->label24->Name = S"label24";
			this->label24->Size = System::Drawing::Size(80, 16);
			this->label24->TabIndex = 9;
			this->label24->Text = S"スタートボタン";
			// 
			// label25
			// 
			this->label25->Location = System::Drawing::Point(24, 64);
			this->label25->Name = S"label25";
			this->label25->Size = System::Drawing::Size(80, 16);
			this->label25->TabIndex = 8;
			this->label25->Text = S"キャンセルボタン";
			// 
			// OKComboJ
			// 
			this->OKComboJ->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->OKComboJ->ItemHeight = 12;
			System::Object* __mcTemp__34[] = new System::Object*[13];
			__mcTemp__34[0] = S"なし";
			__mcTemp__34[1] = S"ボタン1";
			__mcTemp__34[2] = S"ボタン2";
			__mcTemp__34[3] = S"ボタン3";
			__mcTemp__34[4] = S"ボタン4";
			__mcTemp__34[5] = S"ボタン5";
			__mcTemp__34[6] = S"ボタン6";
			__mcTemp__34[7] = S"ボタン7";
			__mcTemp__34[8] = S"ボタン8";
			__mcTemp__34[9] = S"ボタン9";
			__mcTemp__34[10] = S"ボタン10";
			__mcTemp__34[11] = S"ボタン11";
			__mcTemp__34[12] = S"ボタン12";
			this->OKComboJ->Items->AddRange(__mcTemp__34);
			this->OKComboJ->Location = System::Drawing::Point(104, 28);
			this->OKComboJ->Name = S"OKComboJ";
			this->OKComboJ->Size = System::Drawing::Size(104, 20);
			this->OKComboJ->TabIndex = 6;
			this->OKComboJ->SelectedIndexChanged += new System::EventHandler(this, OKComboJ_SelectedIndexChanged);
			// 
			// label19
			// 
			this->label19->Location = System::Drawing::Point(24, 32);
			this->label19->Name = S"label19";
			this->label19->Size = System::Drawing::Size(80, 16);
			this->label19->TabIndex = 3;
			this->label19->Text = S"決定ボタン";
			// 
			// PageS
			// 
			this->PageS->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->PageS->Controls->Add(this->SoundMultiCombo);
			this->PageS->Controls->Add(this->label39);
			this->PageS->Controls->Add(this->BGMCheck);
			this->PageS->Controls->Add(this->SoundComCombo);
			this->PageS->Controls->Add(this->label31);
			this->PageS->Controls->Add(this->SoundQuaCombo);
			this->PageS->Controls->Add(this->label30);
			this->PageS->Controls->Add(this->Sound3DCheck);
			this->PageS->Location = System::Drawing::Point(4, 21);
			this->PageS->Name = S"PageS";
			this->PageS->Size = System::Drawing::Size(512, 367);
			this->PageS->TabIndex = 2;
			this->PageS->Text = S"サウンド";
			// 
			// SoundMultiCombo
			// 
			this->SoundMultiCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			System::Object* __mcTemp__35[] = new System::Object*[3];
			__mcTemp__35[0] = S"少";
			__mcTemp__35[1] = S"中";
			__mcTemp__35[2] = S"多";
			this->SoundMultiCombo->Items->AddRange(__mcTemp__35);
			this->SoundMultiCombo->Location = System::Drawing::Point(288, 150);
			this->SoundMultiCombo->Name = S"SoundMultiCombo";
			this->SoundMultiCombo->Size = System::Drawing::Size(48, 20);
			this->SoundMultiCombo->TabIndex = 6;
			this->SoundMultiCombo->SelectedIndexChanged += new System::EventHandler(this, SoundMultiCombo_SelectedIndexChanged);
			// 
			// label39
			// 
			this->label39->Location = System::Drawing::Point(170, 152);
			this->label39->Name = S"label39";
			this->label39->Size = System::Drawing::Size(120, 16);
			this->label39->TabIndex = 5;
			this->label39->Text = S"効果音同時再生数";
			// 
			// BGMCheck
			// 
			this->BGMCheck->Location = System::Drawing::Point(184, 120);
			this->BGMCheck->Name = S"BGMCheck";
			this->BGMCheck->Size = System::Drawing::Size(104, 16);
			this->BGMCheck->TabIndex = 1;
			this->BGMCheck->Text = S"BGMを再生する";
			this->BGMCheck->CheckedChanged += new System::EventHandler(this, BGMCheck_CheckedChanged);
			// 
			// SoundComCombo
			// 
			this->SoundComCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			System::Object* __mcTemp__36[] = new System::Object*[3];
			__mcTemp__36[0] = S"低";
			__mcTemp__36[1] = S"中";
			__mcTemp__36[2] = S"高";
			this->SoundComCombo->Items->AddRange(__mcTemp__36);
			this->SoundComCombo->Location = System::Drawing::Point(288, 230);
			this->SoundComCombo->Name = S"SoundComCombo";
			this->SoundComCombo->Size = System::Drawing::Size(48, 20);
			this->SoundComCombo->TabIndex = 4;
			this->SoundComCombo->SelectedIndexChanged += new System::EventHandler(this, SoundComCombo_SelectedIndexChanged);
			// 
			// label31
			// 
			this->label31->Location = System::Drawing::Point(168, 232);
			this->label31->Name = S"label31";
			this->label31->Size = System::Drawing::Size(128, 16);
			this->label31->TabIndex = 4;
			this->label31->Text = S"3Dサウンドの計算回数";
			// 
			// SoundQuaCombo
			// 
			this->SoundQuaCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			System::Object* __mcTemp__37[] = new System::Object*[3];
			__mcTemp__37[0] = S"低";
			__mcTemp__37[1] = S"中";
			__mcTemp__37[2] = S"高";
			this->SoundQuaCombo->Items->AddRange(__mcTemp__37);
			this->SoundQuaCombo->Location = System::Drawing::Point(288, 206);
			this->SoundQuaCombo->Name = S"SoundQuaCombo";
			this->SoundQuaCombo->Size = System::Drawing::Size(48, 20);
			this->SoundQuaCombo->TabIndex = 3;
			this->SoundQuaCombo->SelectedIndexChanged += new System::EventHandler(this, SoundQuaCombo_SelectedIndexChanged);
			// 
			// label30
			// 
			this->label30->Location = System::Drawing::Point(168, 208);
			this->label30->Name = S"label30";
			this->label30->Size = System::Drawing::Size(120, 16);
			this->label30->TabIndex = 2;
			this->label30->Text = S"3Dサウンドのクオリティ";
			// 
			// Sound3DCheck
			// 
			this->Sound3DCheck->Location = System::Drawing::Point(184, 176);
			this->Sound3DCheck->Name = S"Sound3DCheck";
			this->Sound3DCheck->Size = System::Drawing::Size(144, 24);
			this->Sound3DCheck->TabIndex = 2;
			this->Sound3DCheck->Text = S"3Dサウンドを使用する";
			this->Sound3DCheck->CheckedChanged += new System::EventHandler(this, Sound3DCheck_CheckedChanged);
			// 
			// PageV
			// 
			this->PageV->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->PageV->Controls->Add(this->SoundLink3);
			this->PageV->Controls->Add(this->SoundLink2);
			this->PageV->Controls->Add(this->SoundLink1);
			this->PageV->Controls->Add(this->label5);
			this->PageV->Controls->Add(this->label4);
			this->PageV->Controls->Add(this->BGMLink);
			this->PageV->Controls->Add(this->label3);
			this->PageV->Controls->Add(this->label2);
			this->PageV->Controls->Add(this->pictureBox2);
			this->PageV->Controls->Add(this->label1);
			this->PageV->Controls->Add(this->HPLink);
			this->PageV->Controls->Add(this->pictureBox1);
			this->PageV->Location = System::Drawing::Point(4, 21);
			this->PageV->Name = S"PageV";
			this->PageV->Size = System::Drawing::Size(512, 367);
			this->PageV->TabIndex = 5;
			this->PageV->Text = S"バージョン";
			// 
			// SoundLink3
			// 
			this->SoundLink3->Location = System::Drawing::Point(312, 288);
			this->SoundLink3->Name = S"SoundLink3";
			this->SoundLink3->Size = System::Drawing::Size(120, 16);
			this->SoundLink3->TabIndex = 4;
			this->SoundLink3->TabStop = true;
			this->SoundLink3->Text = S"TAM Music Factory";
			this->SoundLink3->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SoundLink3_LinkClicked_1);
			// 
			// SoundLink2
			// 
			this->SoundLink2->Location = System::Drawing::Point(264, 288);
			this->SoundLink2->Name = S"SoundLink2";
			this->SoundLink2->Size = System::Drawing::Size(48, 16);
			this->SoundLink2->TabIndex = 3;
			this->SoundLink2->TabStop = true;
			this->SoundLink2->Text = S"音の杜";
			this->SoundLink2->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SoundLink2_LinkClicked);
			// 
			// SoundLink1
			// 
			this->SoundLink1->Location = System::Drawing::Point(168, 288);
			this->SoundLink1->Name = S"SoundLink1";
			this->SoundLink1->Size = System::Drawing::Size(96, 16);
			this->SoundLink1->TabIndex = 2;
			this->SoundLink1->TabStop = true;
			this->SoundLink1->Text = S"WEB WAVE LIB";
			this->SoundLink1->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, SoundLink1_LinkClicked_1);
			// 
			// label5
			// 
			this->label5->Font = new System::Drawing::Font(S"MS UI Gothic", 9);
			this->label5->Location = System::Drawing::Point(112, 288);
			this->label5->Name = S"label5";
			this->label5->Size = System::Drawing::Size(48, 16);
			this->label5->TabIndex = 8;
			this->label5->Text = S"SOUND";
			// 
			// label4
			// 
			this->label4->Font = new System::Drawing::Font(S"MS UI Gothic", 9);
			this->label4->Location = System::Drawing::Point(112, 312);
			this->label4->Name = S"label4";
			this->label4->Size = System::Drawing::Size(32, 16);
			this->label4->TabIndex = 7;
			this->label4->Text = S"BGM";
			// 
			// BGMLink
			// 
			this->BGMLink->Location = System::Drawing::Point(168, 312);
			this->BGMLink->Name = S"BGMLink";
			this->BGMLink->Size = System::Drawing::Size(64, 16);
			this->BGMLink->TabIndex = 5;
			this->BGMLink->TabStop = true;
			this->BGMLink->Text = S"煉獄庭園";
			this->BGMLink->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, BGMLink_LinkClicked);
			// 
			// label3
			// 
			this->label3->Font = new System::Drawing::Font(S"MS UI Gothic", 12);
			this->label3->Location = System::Drawing::Point(96, 248);
			this->label3->Name = S"label3";
			this->label3->Size = System::Drawing::Size(80, 16);
			this->label3->TabIndex = 5;
			this->label3->Text = S"素材提供";
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(328, 176);
			this->label2->Name = S"label2";
			this->label2->Size = System::Drawing::Size(56, 24);
			this->label2->TabIndex = 4;
			this->label2->Text = S"Var 1.1";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (__try_cast<System::Drawing::Image *  >(resources->GetObject(S"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(120, 152);
			this->pictureBox2->Name = S"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(64, 64);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			// 
			// label1
			// 
			this->label1->Font = new System::Drawing::Font(S"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label1->ForeColor = System::Drawing::Color::FromArgb((System::Byte)0, (System::Byte)148, (System::Byte)164);
			this->label1->Location = System::Drawing::Point(192, 168);
			this->label1->Name = S"label1";
			this->label1->Size = System::Drawing::Size(144, 32);
			this->label1->TabIndex = 3;
			this->label1->Text = S"ボウラーズ";
			this->label1->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// HPLink
			// 
			this->HPLink->Location = System::Drawing::Point(376, 112);
			this->HPLink->Name = S"HPLink";
			this->HPLink->Size = System::Drawing::Size(64, 16);
			this->HPLink->TabIndex = 1;
			this->HPLink->TabStop = true;
			this->HPLink->Text = S"HomePage";
			this->HPLink->LinkClicked += new System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, HPLink_LinkClicked);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (__try_cast<System::Drawing::Image *  >(resources->GetObject(S"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(56, 40);
			this->pictureBox1->Name = S"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(400, 96);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// Cancel
			// 
			this->Cancel->Location = System::Drawing::Point(456, 416);
			this->Cancel->Name = S"Cancel";
			this->Cancel->Size = System::Drawing::Size(72, 24);
			this->Cancel->TabIndex = 21;
			this->Cancel->Text = S"キャンセル";
			this->Cancel->Click += new System::EventHandler(this, Cancel_Click);
			// 
			// OK
			// 
			this->OK->Location = System::Drawing::Point(376, 416);
			this->OK->Name = S"OK";
			this->OK->Size = System::Drawing::Size(72, 24);
			this->OK->TabIndex = 20;
			this->OK->Text = S"OK";
			this->OK->Click += new System::EventHandler(this, OK_Click_1);
			// 
			// IP1
			// 
			this->IP1->Enabled = false;
			this->IP1->Location = System::Drawing::Point(16, 416);
			this->IP1->Name = S"IP1";
			this->IP1->Size = System::Drawing::Size(48, 19);
			this->IP1->TabIndex = 22;
			this->IP1->Text = S"textBox1";
			this->IP1->Visible = false;
			// 
			// IP2
			// 
			this->IP2->Enabled = false;
			this->IP2->Location = System::Drawing::Point(64, 416);
			this->IP2->Name = S"IP2";
			this->IP2->Size = System::Drawing::Size(48, 19);
			this->IP2->TabIndex = 23;
			this->IP2->Text = S"textBox1";
			this->IP2->Visible = false;
			// 
			// IP3
			// 
			this->IP3->Enabled = false;
			this->IP3->Location = System::Drawing::Point(112, 416);
			this->IP3->Name = S"IP3";
			this->IP3->Size = System::Drawing::Size(48, 19);
			this->IP3->TabIndex = 24;
			this->IP3->Text = S"textBox1";
			this->IP3->Visible = false;
			// 
			// IP4
			// 
			this->IP4->Enabled = false;
			this->IP4->Location = System::Drawing::Point(160, 416);
			this->IP4->Name = S"IP4";
			this->IP4->Size = System::Drawing::Size(48, 19);
			this->IP4->TabIndex = 25;
			this->IP4->Text = S"textBox1";
			this->IP4->Visible = false;
			// 
			// Port
			// 
			this->Port->Enabled = false;
			this->Port->Location = System::Drawing::Point(208, 416);
			this->Port->Name = S"Port";
			this->Port->Size = System::Drawing::Size(48, 19);
			this->Port->TabIndex = 26;
			this->Port->Text = S"textBox1";
			this->Port->Visible = false;
			// 
			// IPCheck
			// 
			this->IPCheck->Enabled = false;
			this->IPCheck->Location = System::Drawing::Point(256, 424);
			this->IPCheck->Name = S"IPCheck";
			this->IPCheck->Size = System::Drawing::Size(48, 16);
			this->IPCheck->TabIndex = 27;
			this->IPCheck->Text = S"checkBox1";
			this->IPCheck->Visible = false;
			// 
			// PortCheck
			// 
			this->PortCheck->Enabled = false;
			this->PortCheck->Location = System::Drawing::Point(296, 424);
			this->PortCheck->Name = S"PortCheck";
			this->PortCheck->Size = System::Drawing::Size(48, 16);
			this->PortCheck->TabIndex = 28;
			this->PortCheck->Text = S"checkBox1";
			this->PortCheck->Visible = false;
			// 
			// Form1
			// 
			this->AutoScale = false;
			this->AutoScaleBaseSize = System::Drawing::Size(5, 12);
			this->ClientSize = System::Drawing::Size(536, 446);
			this->ControlBox = false;
			this->Controls->Add(this->PortCheck);
			this->Controls->Add(this->IPCheck);
			this->Controls->Add(this->Port);
			this->Controls->Add(this->IP4);
			this->Controls->Add(this->IP3);
			this->Controls->Add(this->IP2);
			this->Controls->Add(this->IP1);
			this->Controls->Add(this->OK);
			this->Controls->Add(this->Cancel);
			this->Controls->Add(this->TabControl);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (__try_cast<System::Drawing::Icon *  >(resources->GetObject(S"$this.Icon")));
			this->Name = S"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = S"ボウラーズ設定";
			this->Load += new System::EventHandler(this, Form1_Load);
			this->TabControl->ResumeLayout(false);
			this->PageG->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->PageC->ResumeLayout(false);
			this->KeyGroup->ResumeLayout(false);
			this->JoyGroup->ResumeLayout(false);
			(__try_cast<System::ComponentModel::ISupportInitialize *  >(this->MoveAxisNumeric))->EndInit();
			(__try_cast<System::ComponentModel::ISupportInitialize *  >(this->RoteAxisNumeric))->EndInit();
			this->PageS->ResumeLayout(false);
			this->PageV->ResumeLayout(false);
			this->ResumeLayout(false);

		}	






//リンク係
private: System::Void HPLink_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			try
			{
				HPLink->LinkVisited = true;
				System::Diagnostics::Process::Start("http://parity.cjb.net");
			}
			catch (Exception * ex)
			{
				MessageBox::Show("リンク先が開けませんでした","エラー");
			}			 
		 }
private: System::Void BGMLink_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			try
			{
				BGMLink->LinkVisited = true;
				System::Diagnostics::Process::Start("http://www.rengoku-teien.com");
			}
			catch (Exception * ex)
			{
				MessageBox::Show("リンク先が開けませんでした","エラー");
			}			 
		 }
private: System::Void SoundLink1_LinkClicked_1(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			try
			{
				SoundLink1->LinkVisited = true;
				System::Diagnostics::Process::Start("http://www.s-t-t.com/wwl");
			}
			catch (Exception * ex)
			{
				MessageBox::Show("リンク先が開けませんでした","エラー");
			}
		 }
private: System::Void SoundLink2_LinkClicked(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			try
			{
				SoundLink2->LinkVisited = true;
//				System::Diagnostics::Process::Start("http://otonomori.cool.ne.jp");
				System::Diagnostics::Process::Start("http://www.mmworks.info/otonomori/");
			}
			catch (Exception * ex)
			{
				MessageBox::Show("リンク先が開けませんでした","エラー");
			}			 
		 }
private: System::Void SoundLink3_LinkClicked_1(System::Object *  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *  e)
		 {
			try
			{
				SoundLink3->LinkVisited = true;
				System::Diagnostics::Process::Start("http://www.tam-music.com");
			}
			catch (Exception * ex)
			{
				MessageBox::Show("リンク先が開けませんでした","エラー");
			}
		 }



private: System::Void Cancel_Click(System::Object *  sender, System::EventArgs *  e)
		 {
			if(MessageBox::Show("設定は保存されていません。終了してもよろしいですか？","確認",
				MessageBoxButtons::OKCancel,MessageBoxIcon::Question,MessageBoxDefaultButton::Button2)==DialogResult::OK)
				Form::Close();
		 }

private: System::Void OK_Click_1(System::Object *  sender, System::EventArgs *  e)
		 {
			if(MessageBox::Show("設定を変更します。よろしいですか？","確認",
				MessageBoxButtons::OKCancel,MessageBoxIcon::Question,MessageBoxDefaultButton::Button1)==DialogResult::OK)
			{
				//結果を保存


				int i;
				FILE* file;
				if((file=fopen("data/save/setting","w"))!=NULL)
				{

					//画面について
					fprintf(file,"%d\n",setting.FullScreen);
					fprintf(file,"%d\n",setting.FormWidth);
					fprintf(file,"%d\n",setting.FormHeight);
					fprintf(file,"%d\n",setting.BufferWidth);
					fprintf(file,"%d\n",setting.BufferHeight);
					fprintf(file,"%d\n",setting.BufferFormat);

					//グラフィック関係
					fprintf(file,"%d\n",setting.MultiTextureEnable);
					fprintf(file,"%d\n",setting.FiltarEnable);
					fprintf(file,"%d\n",setting.MipmapEnable);
					fprintf(file,"%d\n",setting.MipmapFiltarEnable);
					fprintf(file,"%f\n",setting.MipmapBias);
					fprintf(file,"%f\n",setting.KemuriMaxDis);
					fprintf(file,"%f\n",setting.ItemMaxDis);
					fprintf(file,"%d\n",setting.EnvEnable);
					fprintf(file,"%d\n",setting.ShadeEnable);
//					fprintf(file,"%d\n",setting.MultiMeshEnable);
//					fprintf(file,"%f\n",setting.MultiMeshRat);

					//サウンドについて
					fprintf(file,"%d\n",setting.BGM);
					fprintf(file,"%d\n",setting.SoundMultiCount);
					fprintf(file,"%d\n",setting.Sound3D);
					fprintf(file,"%d\n",setting.SoundAlg);
					fprintf(file,"%d\n",setting.SoundCommit);

					//ネットワーク
					fprintf(file,"%s\n",setting.ip);
					fprintf(file,"%s\n",setting.port);
					fprintf(file,"%d\n",setting.IPKeep);
					fprintf(file,"%d\n",setting.PortKeep);

					//入出力
					fprintf(file,"%d\n",setting.Key1p);
					fprintf(file,"%d\n",setting.only1p);

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

					fprintf(file,"%d\n",setting.anti);

					fclose(file);

					Form::Close();

				}
				else
				{
					MessageBox::Show("設定できませんでした","エラー");
				}

			}
		 }



private: System::Void Form1_Load(System::Object *  sender, System::EventArgs *  e)
		 {

//			 PageN->Enabled=false;



			 if(mutexcheck()==false)
			 {
				 MessageBox::Show("多重起動はできません","設定");
				 Form::Close();
			 }


			int i=0;

			//キーデータのセット
			getkey[i]=-1;i++;
			getkey[i]=DIK_RETURN;i++;
			getkey[i]=DIK_SPACE;i++;
			getkey[i]=DIK_LSHIFT;i++;
			getkey[i]=DIK_RSHIFT;i++;
			getkey[i]=DIK_LCONTROL;i++;
			getkey[i]=DIK_RCONTROL;i++;
			getkey[i]=DIK_RIGHT;i++;
			getkey[i]=DIK_LEFT;i++;
			getkey[i]=DIK_UP;i++;
			getkey[i]=DIK_DOWN;i++;
			getkey[i]=DIK_A;i++;
			getkey[i]=DIK_B;i++;
			getkey[i]=DIK_C;i++;
			getkey[i]=DIK_D;i++;
			getkey[i]=DIK_E;i++;
			getkey[i]=DIK_F;i++;
			getkey[i]=DIK_G;i++;
			getkey[i]=DIK_H;i++;
			getkey[i]=DIK_I;i++;
			getkey[i]=DIK_J;i++;
			getkey[i]=DIK_K;i++;
			getkey[i]=DIK_L;i++;
			getkey[i]=DIK_M;i++;
			getkey[i]=DIK_N;i++;
			getkey[i]=DIK_O;i++;
			getkey[i]=DIK_P;i++;
			getkey[i]=DIK_Q;i++;
			getkey[i]=DIK_R;i++;
			getkey[i]=DIK_S;i++;
			getkey[i]=DIK_T;i++;
			getkey[i]=DIK_U;i++;
			getkey[i]=DIK_V;i++;
			getkey[i]=DIK_W;i++;
			getkey[i]=DIK_X;i++;
			getkey[i]=DIK_Y;i++;
			getkey[i]=DIK_Z;i++;

			getkey[i]=DIK_MINUS;i++;
			getkey[i]=DIK_PREVTRACK;i++;
			getkey[i]=DIK_YEN;i++;
			getkey[i]=DIK_AT;i++;
			getkey[i]=DIK_LBRACKET;i++;
			getkey[i]=DIK_SEMICOLON;i++;
			getkey[i]=DIK_COLON;i++;
			getkey[i]=DIK_RBRACKET;i++;
			getkey[i]=DIK_COMMA;i++;
			getkey[i]=DIK_SLASH;i++;
			getkey[i]=DIK_BACKSLASH;i++;

			getkey[i]=DIK_NUMPAD0;i++;
			getkey[i]=DIK_NUMPAD1;i++;
			getkey[i]=DIK_NUMPAD2;i++;
			getkey[i]=DIK_NUMPAD3;i++;
			getkey[i]=DIK_NUMPAD4;i++;
			getkey[i]=DIK_NUMPAD5;i++;
			getkey[i]=DIK_NUMPAD6;i++;
			getkey[i]=DIK_NUMPAD7;i++;
			getkey[i]=DIK_NUMPAD8;i++;
			getkey[i]=DIK_NUMPAD9;i++;

			getkey[i]=DIK_DECIMAL;i++;
			getkey[i]=DIK_DIVIDE;i++;
			getkey[i]=DIK_MULTIPLY;i++;
			getkey[i]=DIK_SUBTRACT;i++;
			getkey[i]=DIK_ADD;i++;
			getkey[i]=DIK_NUMPADENTER;i++;

			getkey[i]=-2;//終了



			 //データの読み込み
			 
			FILE* file;
			if((file=fopen("data/save/setting","r"))!=NULL)
			{

				//画面について
				fscanf(file,"%d",&setting.FullScreen);
				fscanf(file,"%d",&setting.FormWidth);
				fscanf(file,"%d",&setting.FormHeight);
				fscanf(file,"%d",&setting.BufferWidth);
				fscanf(file,"%d",&setting.BufferHeight);
				fscanf(file,"%d",&setting.BufferFormat);

				//グラフィック関係
				fscanf(file,"%d",&setting.MultiTextureEnable);
				fscanf(file,"%d",&setting.FiltarEnable);
				fscanf(file,"%d",&setting.MipmapEnable);
				fscanf(file,"%d",&setting.MipmapFiltarEnable);
				fscanf(file,"%f",&setting.MipmapBias);
				fscanf(file,"%f",&setting.KemuriMaxDis);
				fscanf(file,"%f",&setting.ItemMaxDis);
				fscanf(file,"%d",&setting.EnvEnable);
				fscanf(file,"%d",&setting.ShadeEnable);
//				fscanf(file,"%d",&setting.MultiMeshEnable);
//				fscanf(file,"%f",&setting.MultiMeshRat);


				//サウンドについて
				fscanf(file,"%d",&setting.BGM);
				bool bgmtemp=setting.BGM;
				fscanf(file,"%d",&setting.SoundMultiCount);
				fscanf(file,"%d",&setting.Sound3D);
				bool keepsound3d=setting.Sound3D;
				fscanf(file,"%d",&setting.SoundAlg);
				fscanf(file,"%d",&setting.SoundCommit);


				//ネットワーク
				fscanf(file,"%s",setting.ip);
				fscanf(file,"%s",setting.port);
				fscanf(file,"%d",&setting.IPKeep);
				fscanf(file,"%d",&setting.PortKeep);

				//入出力
				fscanf(file,"%d",&setting.Key1p);
				fscanf(file,"%d",&setting.only1p);

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

				fscanf(file,"%d",&setting.anti);

				fclose(file);

				//char str[100];
				//sprintf(str,"%d",keynum[1].axis2);
				//MessageBox::Show(str);

				setting.BGM=bgmtemp;
				setting.Sound3D=keepsound3d;


			}
			else
			{
				//初期値指定


				int i;

				//画面について
				setting.FullScreen=true;
				setting.FormWidth=800;
				setting.FormHeight=600;
				setting.BufferWidth=640;
				setting.BufferHeight=480;
				setting.BufferFormat=16;

				//グラフィック関係
				setting.MultiTextureEnable=true;
				setting.FiltarEnable=true;
				setting.MipmapEnable=true;
				setting.MipmapFiltarEnable=true;
				setting.MipmapBias=0.3f;
				setting.KemuriMaxDis=200;
				setting.ItemMaxDis=200;
				setting.EnvEnable=true;
				setting.ShadeEnable=true;
				setting.MultiMeshEnable=true;
				setting.MultiMeshRat=1.0f;

				//サウンドについて
				setting.BGM=true;
				setting.SoundMultiCount=5;
				setting.Sound3D=false;
				setting.SoundAlg=1;
				setting.SoundCommit=3;

				//ネットワーク
				setting.ip[0]='\0';
				setting.port[0]='\0';
				setting.IPKeep=true;
				setting.PortKeep=true;

				//入出力
				setting.Key1p=true;
				setting.only1p=false;

				setting.anti=0;

				i=0;//キーボード
				keynum[i].ok=DIK_X;
				keynum[i].cancel=DIK_Z;
				keynum[i].jump=DIK_X;
				keynum[i].item=DIK_Z;
				keynum[i].start=DIK_RETURN;
				keynum[i].rightrote=DIK_S;
				keynum[i].leftrote=DIK_A;
				keynum[i].axis=-1;
				keynum[i].axis2=-1;
				keynum[i].up=DIK_UP;
				keynum[i].down=DIK_DOWN;
				keynum[i].left=DIK_LEFT;
				keynum[i].right=DIK_RIGHT;
				keynum[i].up2=DIK_NUMPAD8;
				keynum[i].down2=DIK_NUMPAD5;
				keynum[i].left2=DIK_NUMPAD4;
				keynum[i].right2=DIK_NUMPAD6;
				keynum[i].axisover=0.3f;
				keynum[i].axisover2=0.3f;
				keynum[i].VibEnable=false;

				for(i=1;i<5;i++)
				{
					keynum[i].ok=0;
					keynum[i].cancel=1;
					keynum[i].jump=0;
					keynum[i].item=1;
					keynum[i].start=8;
					keynum[i].rightrote=6;
					keynum[i].leftrote=7;
					keynum[i].axis=0;
					keynum[i].axis2=-1;
					keynum[i].up=-1;
					keynum[i].down=-1;
					keynum[i].left=-1;
					keynum[i].right=-1;
					keynum[i].up2=-1;
					keynum[i].down2=-1;
					keynum[i].left2=-1;
					keynum[i].right2=-1;
					keynum[i].axisover=0.3f;
					keynum[i].axisover2=0.3f;
					keynum[i].VibEnable=false;
				}

			}

			//ボタンにデータをセット
			FullCheck->Checked=setting.FullScreen;

			if(setting.FullScreen)
				FSizeCombo->Enabled=false;
			else
				ColorCombo->Enabled=false;

			if(setting.FormWidth==400 && setting.FormHeight==300)
				FSizeCombo->SelectedIndex=0;
			else if(setting.FormWidth==640 && setting.FormHeight==480)
				FSizeCombo->SelectedIndex=1;
			else if(setting.FormWidth==800 && setting.FormHeight==600)
				FSizeCombo->SelectedIndex=2;
			else if(setting.FormWidth==1024 && setting.FormHeight==768)
				FSizeCombo->SelectedIndex=3;
			else if(setting.FormWidth==1280 && setting.FormHeight==1024)
				FSizeCombo->SelectedIndex=4;
			else
				BSizeCombo->SelectedIndex=2;

			if(setting.BufferWidth==400 && setting.BufferHeight==300)
				BSizeCombo->SelectedIndex=0;
			else if(setting.BufferWidth==640 && setting.BufferHeight==480)
				BSizeCombo->SelectedIndex=1;
			else if(setting.BufferWidth==800 && setting.BufferHeight==600)
				BSizeCombo->SelectedIndex=2;
			else if(setting.BufferWidth==1024 && setting.BufferHeight==768)
				BSizeCombo->SelectedIndex=3;
			else if(setting.BufferWidth==1280 && setting.BufferHeight==1024)
				BSizeCombo->SelectedIndex=4;
			else
				BSizeCombo->SelectedIndex=1;


			if(setting.BufferFormat==32)
				ColorCombo->SelectedIndex=1;
			else
				ColorCombo->SelectedIndex=0;

			TexFilterCheck->Checked=setting.FiltarEnable;
			TexMultiCheck->Checked=setting.MultiTextureEnable;
//			if(!setting.MultiTextureEnable)
//				EnvCheck->Enabled=false;
			EnvCheck->Checked=setting.EnvEnable;

			if(!setting.MipmapEnable)
			{
				MipCombo->SelectedIndex=0;
				MipFilterCheck->Enabled=false;
			}
			else
			{
				if(setting.MipmapBias<=-0.9f)
					MipCombo->SelectedIndex=1;
				else if(setting.MipmapBias<=-0.3f)
					MipCombo->SelectedIndex=2;
				else
					MipCombo->SelectedIndex=3;
			}

			MipFilterCheck->Checked=setting.MipmapFiltarEnable;

			ShadeCheck->Checked=setting.ShadeEnable;

			if(!setting.MultiMeshEnable)
				PMeshCombo->SelectedIndex=0;
			else
			{
				if(setting.MultiMeshRat>=0.8f)
					PMeshCombo->SelectedIndex=1;
				else if(setting.MultiMeshRat>=0.6f)
					PMeshCombo->SelectedIndex=2;
				else
					PMeshCombo->SelectedIndex=3;
			}

			if(setting.KemuriMaxDis>=300)
				KemuriCombo->SelectedIndex=0;
			else if(setting.KemuriMaxDis>=150)
				KemuriCombo->SelectedIndex=1;
			else
				KemuriCombo->SelectedIndex=2;

			if(setting.ItemMaxDis>=200)
				ItemDisCombo->SelectedIndex=0;
			else if(setting.ItemMaxDis>=150)
				ItemDisCombo->SelectedIndex=1;
			else
				ItemDisCombo->SelectedIndex=2;




			BGMCheck->Checked=setting.BGM;

			if(setting.SoundMultiCount>=10)			//10
			{
				SoundMultiCombo->SelectedIndex=2;
				//MessageBox::Show("");
			}
			else if(setting.SoundMultiCount>=5)		//7
				SoundMultiCombo->SelectedIndex=1;
			else								//4
				SoundMultiCombo->SelectedIndex=0;

			Sound3DCheck->Checked=setting.Sound3D;
			if(!setting.Sound3D)
			{
				SoundQuaCombo->Enabled=false;
				SoundComCombo->Enabled=false;
			}
			SoundQuaCombo->SelectedIndex=setting.SoundAlg;
			if(setting.SoundCommit>=10)			//10
				SoundComCombo->SelectedIndex=0;
			else if(setting.SoundCommit>=3)		//5
				SoundComCombo->SelectedIndex=1;
			else								//1
				SoundComCombo->SelectedIndex=2;

			KeyCheck->Checked=setting.Key1p==0 ? false : true;
			if(setting.Key1p)
			{
				CtrlRadio1->Text="キーボード";
				CtrlRadio2->Text="コントローラ1";
				CtrlRadio3->Text="コントローラ2";
				CtrlRadio4->Text="コントローラ3";
			}
			else
			{
				CtrlRadio1->Text="コントローラ1";
				CtrlRadio2->Text="コントローラ2";
				CtrlRadio3->Text="コントローラ3";
				CtrlRadio4->Text="コントローラ4";
			}
			myselfcheck->Checked=setting.only1p;

			anticombo->SelectedIndex=setting.anti;

			//キーボードの設定をデフォルトで読み込んでおく
			for(i=0;;i++)
			{
				if(getkey[i]==-2)
					break;
				else if(getkey[i]==keynum[0].ok)
					OKCombo->SelectedIndex=i;
			}
			for(i=0;;i++)
			{
				if(getkey[i]==-2)
					break;
				else if(getkey[i]==keynum[0].cancel)
					CancelCombo->SelectedIndex=i;
			}
			for(i=0;;i++)
			{
				if(getkey[i]==-2)
					break;
				else if(getkey[i]==keynum[0].start)
					StartCombo->SelectedIndex=i;
			}
			for(i=0;;i++)
			{
				if(getkey[i]==-2)
					break;
				else if(getkey[i]==keynum[0].jump)
					JumpCombo->SelectedIndex=i;
			}
			for(i=0;;i++)
			{
				if(getkey[i]==-2)
					break;
				else if(getkey[i]==keynum[0].item)
					ItemCombo->SelectedIndex=i;
			}
			for(i=0;;i++)
			{
				if(getkey[i]==-2)
					break;
				else if(getkey[i]==keynum[0].item)
					ItemCombo->SelectedIndex=i;
			}

			for(i=0;;i++)
			{
				if(getkey[i]==-2)
					break;
				else if(getkey[i]==keynum[0].right2)
					RRoteCombo->SelectedIndex=i;
			}
			for(i=0;;i++)
			{
				if(getkey[i]==-2)
					break;
				else if(getkey[i]==keynum[0].left2)
					LRoteCombo->SelectedIndex=i;
			}
			for(i=0;;i++)
			{
				if(getkey[i]==-2)
					break;
				else if(getkey[i]==keynum[0].up2)
					URoteCombo->SelectedIndex=i;
			}
			for(i=0;;i++)
			{
				if(getkey[i]==-2)
					break;
				else if(getkey[i]==keynum[0].down2)
					DRoteCombo->SelectedIndex=i;
			}
			for(i=0;;i++)
			{
				if(getkey[i]==-2)
					break;
				else if(getkey[i]==keynum[0].right)
					RMoveCombo->SelectedIndex=i;
			}
			for(i=0;;i++)
			{
				if(getkey[i]==-2)
					break;
				else if(getkey[i]==keynum[0].left)
					LMoveCombo->SelectedIndex=i;
			}
			for(i=0;;i++)
			{
				if(getkey[i]==-2)
					break;
				else if(getkey[i]==keynum[0].up)
					UMoveCombo->SelectedIndex=i;
			}
			for(i=0;;i++)
			{
				if(getkey[i]==-2)
					break;
				else if(getkey[i]==keynum[0].down)
					DMoveCombo->SelectedIndex=i;
			}




			int ip[4];
			char str[10];
			sscanf(setting.ip,"%d.%d.%d.%d",&ip[0],&ip[1],&ip[2],&ip[3]);
			sprintf(str,"%d",ip[0]);
			IP1->Text=str;
			sprintf(str,"%d",ip[1]);
			IP2->Text=str;
			sprintf(str,"%d",ip[2]);
			IP3->Text=str;
			sprintf(str,"%d",ip[3]);
			IP4->Text=str;

			Port->Text=setting.port;

			IPCheck->Checked=setting.IPKeep;
			PortCheck->Checked=setting.PortKeep;



		 }


private: System::Void TabControl_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			if(TabControl->SelectedTab==PageC)
			{
				//コントローラの設定
				CtrlRadio1->Checked=true;

				if(setting.Key1p)
				{
					KeyCheck->Checked=false;
					KeyCheck->Checked=true;
				}
				else
				{
					KeyCheck->Checked=true;
					KeyCheck->Checked=false;
				}

			}
		 }

private: System::Void FullCheck_CheckedChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //フルスクリーン
			 setting.FullScreen=FullCheck->Checked;
			 if(setting.FullScreen)
			 {
				 ColorCombo->Enabled=true;
				 FSizeCombo->Enabled=false;
			 }
			 else
			 {
				 ColorCombo->Enabled=false;
				 FSizeCombo->Enabled=true;
			 }
		 }

private: System::Void ColorCombo_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //色数
			 if(ColorCombo->SelectedIndex==0)
				setting.BufferFormat=16;
			 else
				setting.BufferFormat=32;
		 }

private: System::Void FSizeCombo_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //画面サイズ
			 if(FSizeCombo->SelectedIndex==0)
			 {
				 setting.FormWidth=400;
				 setting.FormHeight=300;
			 }
			 else if(FSizeCombo->SelectedIndex==1)
			 {
				 setting.FormWidth=640;
				 setting.FormHeight=480;
			 }
			 else if(FSizeCombo->SelectedIndex==2)
			 {
				 setting.FormWidth=800;
				 setting.FormHeight=600;
			 }
			 else if(FSizeCombo->SelectedIndex==3)
			 {
				 setting.FormWidth=1024;
				 setting.FormHeight=768;
			 }
			 else if(FSizeCombo->SelectedIndex==4)
			 {
				 setting.FormWidth=1280;
				 setting.FormHeight=1024;
			 }
		 }

private: System::Void BSizeCombo_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //バッファサイズ
			 if(BSizeCombo->SelectedIndex==0)
			 {
				 setting.BufferWidth=400;
				 setting.BufferHeight=300;
			 }
			 else if(BSizeCombo->SelectedIndex==1)
			 {
				 setting.BufferWidth=640;
				 setting.BufferHeight=480;
			 }
			 else if(BSizeCombo->SelectedIndex==2)
			 {
				 setting.BufferWidth=800;
				 setting.BufferHeight=600;
			 }
			 else if(BSizeCombo->SelectedIndex==3)
			 {
				 setting.BufferWidth=1024;
				 setting.BufferHeight=768;
			 }
			 else if(BSizeCombo->SelectedIndex==4)
			 {
				 setting.BufferWidth=1280;
				 setting.BufferHeight=1024;
			 }
		 }

private: System::Void TexFilterCheck_CheckedChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //テクスチャのぼかし
			 setting.FiltarEnable=TexFilterCheck->Checked;
		 }

private: System::Void TexMultiCheck_CheckedChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //マルチテクスチャ
			 setting.MultiTextureEnable=TexMultiCheck->Checked;
//			 EnvCheck->Enabled=TexMultiCheck->Checked;
		 }

private: System::Void EnvCheck_CheckedChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //反射マップ
			 setting.EnvEnable=EnvCheck->Checked;
		 }

private: System::Void MipCombo_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //ミップマップ
			 setting.MipmapEnable=true;
			 if(MipCombo->SelectedIndex==0)
				 setting.MipmapEnable=false;
			 else if(MipCombo->SelectedIndex==1)
				 setting.MipmapBias=-0.9f;
			 else if(MipCombo->SelectedIndex==2)
				 setting.MipmapBias=-0.3f;
			 else if(MipCombo->SelectedIndex==3)
				 setting.MipmapBias=0.3f;

			 if(setting.MipmapEnable)
				 MipFilterCheck->Enabled=true;
			 else
				 MipFilterCheck->Enabled=false;
		 }

private: System::Void MipFilterCheck_CheckedChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //境界のぼかし
			 setting.MipmapFiltarEnable=MipFilterCheck->Checked;
		 }

private: System::Void ShadeCheck_CheckedChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //影の表示
			 setting.ShadeEnable=ShadeCheck->Checked;
		 }

private: System::Void PMeshCombo_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //プログレッシブメッシュ
			 setting.MultiMeshEnable=true;
			 if(PMeshCombo->SelectedIndex==0)
				 setting.MultiMeshEnable=false;
			 else if(PMeshCombo->SelectedIndex==1)
				 setting.MultiMeshRat=0.8f;
			 else if(PMeshCombo->SelectedIndex==2)
				 setting.MultiMeshRat=0.6f;
			 else if(PMeshCombo->SelectedIndex==3)
				 setting.MultiMeshRat=0.4f;
		 }

private: System::Void KemuriCombo_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //煙の表示
			 if(KemuriCombo->SelectedIndex==0)
				 setting.KemuriMaxDis=300;
			 else if(KemuriCombo->SelectedIndex==1)
				 setting.KemuriMaxDis=150;
			 else if(KemuriCombo->SelectedIndex==2)
				 setting.KemuriMaxDis=70;
		 }

private: System::Void Sound3DCheck_CheckedChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //3Dサウンド
			setting.Sound3D=Sound3DCheck->Checked;
			SoundQuaCombo->Enabled=setting.Sound3D;
			SoundComCombo->Enabled=setting.Sound3D;
		 }

private: System::Void SoundQuaCombo_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //3Dサウンドクオリティー
			 setting.SoundAlg=SoundQuaCombo->SelectedIndex;
		 }

private: System::Void SoundComCombo_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //3Dサウンドの計算回数
			 if(SoundComCombo->SelectedIndex==0)
				 setting.SoundCommit=10;
			 else if(SoundComCombo->SelectedIndex==1)
				 setting.SoundCommit=5;
			 else if(SoundComCombo->SelectedIndex==2)
				 setting.SoundCommit=1;
		 }

private: System::Void KeyCheck_CheckedChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //キーボード1P
			 setting.Key1p=KeyCheck->Checked;
			 CtrlRadio1->Checked=true;
			 CtrlRadio2->Checked=false;
			 CtrlRadio3->Checked=false;
			 CtrlRadio4->Checked=false;
			 if(setting.Key1p)
			 {
				 CtrlRadio1->Text="キーボード";
				 CtrlRadio2->Text="コントローラ1";
				 CtrlRadio3->Text="コントローラ2";
				 CtrlRadio4->Text="コントローラ3";
				 KeyGroup->Visible=true;
				 JoyGroup->Visible=false;
				 SelectCtrl=0;
			 }
			 else
			 {
				 CtrlRadio1->Text="コントローラ1";
				 CtrlRadio2->Text="コントローラ2";
				 CtrlRadio3->Text="コントローラ3";
				 CtrlRadio4->Text="コントローラ4";
				 KeyGroup->Visible=false;
				 JoyGroup->Visible=true;
				 SelectCtrl=1;

				 OKComboJ->SelectedIndex=keynum[SelectCtrl].ok+1;
				 CancelComboJ->SelectedIndex=keynum[SelectCtrl].cancel+1;
				 StartComboJ->SelectedIndex=keynum[SelectCtrl].start+1;
				 JumpComboJ->SelectedIndex=keynum[SelectCtrl].jump+1;
				 ItemComboJ->SelectedIndex=keynum[SelectCtrl].item+1;
				 RRoteComboJ->SelectedIndex=keynum[SelectCtrl].rightrote+1;
				 LRoteComboJ->SelectedIndex=keynum[SelectCtrl].leftrote+1;
				 MoveAxisComboJ->SelectedIndex=keynum[SelectCtrl].axis+1;
				 RoteAxisComboJ->SelectedIndex=keynum[SelectCtrl].axis2+1;
				 MoveAxisNumeric->Value=keynum[SelectCtrl].axisover*100;
				 RoteAxisNumeric->Value=keynum[SelectCtrl].axisover2*100;
				 VibCheck->Checked=keynum[SelectCtrl].VibEnable;
			 }
		 }

private: System::Void CtrlRadio1_CheckedChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //コントローラ1
			 if(setting.Key1p)
			 {
				 SelectCtrl=0;
				 KeyGroup->Visible=true;
				 JoyGroup->Visible=false;

			 }
			 else
			 {
				 SelectCtrl=1;
				 KeyGroup->Visible=false;
				 JoyGroup->Visible=true;
				 OKComboJ->SelectedIndex=keynum[SelectCtrl].ok+1;
				 CancelComboJ->SelectedIndex=keynum[SelectCtrl].cancel+1;
				 StartComboJ->SelectedIndex=keynum[SelectCtrl].start+1;
				 JumpComboJ->SelectedIndex=keynum[SelectCtrl].jump+1;
				 ItemComboJ->SelectedIndex=keynum[SelectCtrl].item+1;
				 RRoteComboJ->SelectedIndex=keynum[SelectCtrl].rightrote+1;
				 LRoteComboJ->SelectedIndex=keynum[SelectCtrl].leftrote+1;
				 MoveAxisComboJ->SelectedIndex=keynum[SelectCtrl].axis+1;
				 RoteAxisComboJ->SelectedIndex=keynum[SelectCtrl].axis2+1;
				 MoveAxisNumeric->Value=keynum[SelectCtrl].axisover*100;
				 RoteAxisNumeric->Value=keynum[SelectCtrl].axisover2*100;
				 VibCheck->Checked=keynum[SelectCtrl].VibEnable;
			 }
		 }

private: System::Void CtrlRadio2_CheckedChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //コントローラ2
			KeyGroup->Visible=false;
			JoyGroup->Visible=true;
			 if(setting.Key1p)
				 SelectCtrl=1;
			 else
				 SelectCtrl=2;

			KeyGroup->Visible=false;
			JoyGroup->Visible=true;
			OKComboJ->SelectedIndex=keynum[SelectCtrl].ok+1;
			CancelComboJ->SelectedIndex=keynum[SelectCtrl].cancel+1;
			StartComboJ->SelectedIndex=keynum[SelectCtrl].start+1;
			JumpComboJ->SelectedIndex=keynum[SelectCtrl].jump+1;
			ItemComboJ->SelectedIndex=keynum[SelectCtrl].item+1;
			RRoteComboJ->SelectedIndex=keynum[SelectCtrl].rightrote+1;
			LRoteComboJ->SelectedIndex=keynum[SelectCtrl].leftrote+1;
			MoveAxisComboJ->SelectedIndex=keynum[SelectCtrl].axis+1;
			RoteAxisComboJ->SelectedIndex=keynum[SelectCtrl].axis2+1;
			MoveAxisNumeric->Value=keynum[SelectCtrl].axisover*100;
			RoteAxisNumeric->Value=keynum[SelectCtrl].axisover2*100;
			VibCheck->Checked=keynum[SelectCtrl].VibEnable;
		 }

private: System::Void CtrlRadio3_CheckedChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //コントローラ3
			KeyGroup->Visible=false;
			JoyGroup->Visible=true;
			 if(setting.Key1p)
				 SelectCtrl=2;
			 else
				 SelectCtrl=3;


			KeyGroup->Visible=false;
			JoyGroup->Visible=true;
			OKComboJ->SelectedIndex=keynum[SelectCtrl].ok+1;
			CancelComboJ->SelectedIndex=keynum[SelectCtrl].cancel+1;
			StartComboJ->SelectedIndex=keynum[SelectCtrl].start+1;
			JumpComboJ->SelectedIndex=keynum[SelectCtrl].jump+1;
			ItemComboJ->SelectedIndex=keynum[SelectCtrl].item+1;
			RRoteComboJ->SelectedIndex=keynum[SelectCtrl].rightrote+1;
			LRoteComboJ->SelectedIndex=keynum[SelectCtrl].leftrote+1;
			MoveAxisComboJ->SelectedIndex=keynum[SelectCtrl].axis+1;
			RoteAxisComboJ->SelectedIndex=keynum[SelectCtrl].axis2+1;
			MoveAxisNumeric->Value=keynum[SelectCtrl].axisover*100;
			RoteAxisNumeric->Value=keynum[SelectCtrl].axisover2*100;
			VibCheck->Checked=keynum[SelectCtrl].VibEnable;
		 }

private: System::Void CtrlRadio4_CheckedChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //コントローラ4
			KeyGroup->Visible=false;
			JoyGroup->Visible=true;
			 if(setting.Key1p)
				 SelectCtrl=3;
			 else
				 SelectCtrl=4;

			KeyGroup->Visible=false;
			JoyGroup->Visible=true;
			OKComboJ->SelectedIndex=keynum[SelectCtrl].ok+1;
			CancelComboJ->SelectedIndex=keynum[SelectCtrl].cancel+1;
			StartComboJ->SelectedIndex=keynum[SelectCtrl].start+1;
			JumpComboJ->SelectedIndex=keynum[SelectCtrl].jump+1;
			ItemComboJ->SelectedIndex=keynum[SelectCtrl].item+1;
			RRoteComboJ->SelectedIndex=keynum[SelectCtrl].rightrote+1;
			LRoteComboJ->SelectedIndex=keynum[SelectCtrl].leftrote+1;
			MoveAxisComboJ->SelectedIndex=keynum[SelectCtrl].axis+1;
			RoteAxisComboJ->SelectedIndex=keynum[SelectCtrl].axis2+1;
			MoveAxisNumeric->Value=keynum[SelectCtrl].axisover*100;
			RoteAxisNumeric->Value=keynum[SelectCtrl].axisover2*100;
			VibCheck->Checked=keynum[SelectCtrl].VibEnable;
		 }


//キーボード
private: System::Void OKCombo_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //決定
			keynum[0].ok=getkey[OKCombo->SelectedIndex];
		 }


private: System::Void CancelCombo_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //キャンセル
			keynum[0].cancel=getkey[CancelCombo->SelectedIndex];
		 }

private: System::Void StartCombo_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //スタート
			keynum[0].start=getkey[StartCombo->SelectedIndex];
		 }

private: System::Void JumpCombo_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //ジャンプ
			keynum[0].jump=getkey[JumpCombo->SelectedIndex];
		 }

private: System::Void ItemCombo_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //アイテム
			keynum[0].item=getkey[ItemCombo->SelectedIndex];
		 }


private: System::Void URoteCombo_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //上回転
			keynum[0].up2=getkey[URoteCombo->SelectedIndex];
		 }

private: System::Void DRoteCombo_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //下回転
			keynum[0].down2=getkey[DRoteCombo->SelectedIndex];
		 }

private: System::Void RRoteCombo_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //右回転
			keynum[0].right2=getkey[RRoteCombo->SelectedIndex];
		 }

private: System::Void LRoteCombo_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //左回転
			keynum[0].left2=getkey[LRoteCombo->SelectedIndex];
		 }

private: System::Void UMoveCombo_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //上移動
			keynum[0].up=getkey[UMoveCombo->SelectedIndex];
		 }

private: System::Void DMoveCombo_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //下移動
			keynum[0].down=getkey[DMoveCombo->SelectedIndex];
		 }

private: System::Void RMoveCombo_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //右移動
			keynum[0].right=getkey[RMoveCombo->SelectedIndex];
		 }

private: System::Void LMoveCombo_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //左移動
			keynum[0].left=getkey[LMoveCombo->SelectedIndex];
		 }


//コントローラ
private: System::Void OKComboJ_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //決定
			 keynum[SelectCtrl].ok=OKComboJ->SelectedIndex-1;
		 }

private: System::Void CancelComboJ_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //キャンセル
			 keynum[SelectCtrl].cancel=CancelComboJ->SelectedIndex-1;
		 }

private: System::Void StartComboJ_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //スタート
			 keynum[SelectCtrl].start=StartComboJ->SelectedIndex-1;
		 }

private: System::Void JumpComboJ_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //ジャンプ
			 keynum[SelectCtrl].jump=JumpComboJ->SelectedIndex-1;
		 }

private: System::Void ItemComboJ_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //アイテム
			 keynum[SelectCtrl].item=ItemComboJ->SelectedIndex-1;
		 }

private: System::Void RRoteComboJ_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //右回転
			 keynum[SelectCtrl].rightrote=RRoteComboJ->SelectedIndex-1;
		 }

private: System::Void LRoteComboJ_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //左回転
			 keynum[SelectCtrl].leftrote=LRoteComboJ->SelectedIndex-1;
		 }

private: System::Void MoveAxisComboJ_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //移動軸
			 keynum[SelectCtrl].axis=MoveAxisComboJ->SelectedIndex-1;
		 }

private: System::Void RoteAxisComboJ_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //回転軸
			 keynum[SelectCtrl].axis2=RoteAxisComboJ->SelectedIndex-1;
		 }

private: System::Void MoveAxisNumeric_ValueChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //移動軸範囲
			 keynum[SelectCtrl].axisover=(float)MoveAxisNumeric->Value/100.0f;
		 }

private: System::Void RoteAxisNumeric_ValueChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //回転軸範囲
			 keynum[SelectCtrl].axisover2=(float)RoteAxisNumeric->Value/100.0f;
		 }

private: System::Void VibCheck_CheckedChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //バイブレーション
			 keynum[SelectCtrl].VibEnable=VibCheck->Checked;
		 }

private: System::Void IP1_TextChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //IP1
			 sprintf(setting.ip,"%s.%s.%s.%s",IP1->Text,IP2->Text,IP3->Text,IP4->Text);
		 }

private: System::Void IP2_TextChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //IP2
			 sprintf(setting.ip,"%s.%s.%s.%s",IP1->Text,IP2->Text,IP3->Text,IP4->Text);
		 }

private: System::Void IP3_TextChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //IP3
			 sprintf(setting.ip,"%s.%s.%s.%s",IP1->Text,IP2->Text,IP3->Text,IP4->Text);
		 }

private: System::Void IP4_TextChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //IP4
			 sprintf(setting.ip,"%s.%s.%s.%s",IP1->Text,IP2->Text,IP3->Text,IP4->Text);
		 }

private: System::Void Port_TextChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //Port
			 sprintf(setting.port,"%s",Port->Text);
		 }

private: System::Void IPCheck_CheckedChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //IP変更保存
			 setting.IPKeep=IPCheck->Checked;
		 }

private: System::Void PortCheck_CheckedChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //Port変更保存
			 setting.PortKeep=PortCheck->Checked;
		 }

private: System::Void BGMCheck_CheckedChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //BGM
			 setting.BGM=BGMCheck->Checked;
		 }

private: System::Void ItemDisCombo_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //アイテム表示距離
			 if(ItemDisCombo->SelectedIndex==0)
				 setting.ItemMaxDis=200;
			 else if(ItemDisCombo->SelectedIndex==1)
				 setting.ItemMaxDis=150;
			 else if(ItemDisCombo->SelectedIndex==2)
				 setting.ItemMaxDis=50;
		 }

private: System::Void SoundMultiCombo_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //効果音同時再生数
			 if(SoundMultiCombo->SelectedIndex==2)
				 setting.SoundMultiCount=10;
			 else if(SoundMultiCombo->SelectedIndex==1)
				 setting.SoundMultiCount=7;
			 else if(SoundMultiCombo->SelectedIndex==0)
				 setting.SoundMultiCount=4;
		 }

private: System::Void myselfcheck_CheckedChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 //他のプレイヤーの操作を受け付けるか
		
			if(myselfcheck->Checked)
				setting.only1p=true;
			else
				setting.only1p=false;
		}

private: System::Void button1_Click(System::Object *  sender, System::EventArgs *  e)
		 {//自信満々設定

			 //画面サイズ(ウィンドウモードのみ有効)
			//if(setting.FormWidth==400 && setting.FormHeight==300)
			//	FSizeCombo->SelectedIndex=0;
			//else if(setting.FormWidth==640 && setting.FormHeight==480)
			//	FSizeCombo->SelectedIndex=1;
			//else if(setting.FormWidth==800 && setting.FormHeight==600)
			//	FSizeCombo->SelectedIndex=2;
			//else if(setting.FormWidth==1024 && setting.FormHeight==768)
				FSizeCombo->SelectedIndex=3;
			//else if(setting.FormWidth==1280 && setting.FormHeight==1024)
			//	FSizeCombo->SelectedIndex=4;

			//バッファサイズ
			//if(setting.BufferWidth==400 && setting.BufferHeight==300)
			//	BSizeCombo->SelectedIndex=0;
			//else if(setting.BufferWidth==640 && setting.BufferHeight==480)
			//	BSizeCombo->SelectedIndex=1;
			//else if(setting.BufferWidth==800 && setting.BufferHeight==600)
			//	BSizeCombo->SelectedIndex=2;
			//else if(setting.BufferWidth==1024 && setting.BufferHeight==768)
				BSizeCombo->SelectedIndex=3;
			//else if(setting.BufferWidth==1280 && setting.BufferHeight==1024)
//				BSizeCombo->SelectedIndex=4;


//			if(setting.BufferFormat==32)
				ColorCombo->SelectedIndex=1;
//			else
//				ColorCombo->SelectedIndex=0;

			TexFilterCheck->Checked=true;
			TexMultiCheck->Checked=true;
			EnvCheck->Checked=true;

			MipCombo->SelectedIndex=1;
			MipFilterCheck->Enabled=true;
			MipFilterCheck->Checked=true;

			ShadeCheck->Checked=true;

			KemuriCombo->SelectedIndex=0;
			ItemDisCombo->SelectedIndex=0;

			anticombo->SelectedIndex=2;

			 
		 }

private: System::Void button2_Click(System::Object *  sender, System::EventArgs *  e)
		 {
			 //高め

			 //画面サイズ(ウィンドウモードのみ有効)
			//if(setting.FormWidth==400 && setting.FormHeight==300)
			//	FSizeCombo->SelectedIndex=0;
			//else if(setting.FormWidth==640 && setting.FormHeight==480)
			//	FSizeCombo->SelectedIndex=1;
			//else if(setting.FormWidth==800 && setting.FormHeight==600)
				FSizeCombo->SelectedIndex=2;
			//else if(setting.FormWidth==1024 && setting.FormHeight==768)
			//	FSizeCombo->SelectedIndex=3;
			//else if(setting.FormWidth==1280 && setting.FormHeight==1024)
			//	FSizeCombo->SelectedIndex=4;

			//バッファサイズ
			//if(setting.BufferWidth==400 && setting.BufferHeight==300)
			//	BSizeCombo->SelectedIndex=0;
			//else if(setting.BufferWidth==640 && setting.BufferHeight==480)
			//	BSizeCombo->SelectedIndex=1;
			//else if(setting.BufferWidth==800 && setting.BufferHeight==600)
				BSizeCombo->SelectedIndex=2;
			//else if(setting.BufferWidth==1024 && setting.BufferHeight==768)
			//	BSizeCombo->SelectedIndex=3;
			//else if(setting.BufferWidth==1280 && setting.BufferHeight==1024)
//				BSizeCombo->SelectedIndex=4;

			ColorCombo->SelectedIndex=0;

			TexFilterCheck->Checked=true;
			TexMultiCheck->Checked=true;
			EnvCheck->Checked=true;

			MipCombo->SelectedIndex=1;
			MipFilterCheck->Enabled=true;
			MipFilterCheck->Checked=false;

			ShadeCheck->Checked=true;

			KemuriCombo->SelectedIndex=0;
			ItemDisCombo->SelectedIndex=1;
			anticombo->SelectedIndex=1;

		 }

private: System::Void button3_Click(System::Object *  sender, System::EventArgs *  e)
		 {//普通


			 //画面サイズ(ウィンドウモードのみ有効)
			//if(setting.FormWidth==400 && setting.FormHeight==300)
			//	FSizeCombo->SelectedIndex=0;
			//else if(setting.FormWidth==640 && setting.FormHeight==480)
			//	FSizeCombo->SelectedIndex=1;
			//else if(setting.FormWidth==800 && setting.FormHeight==600)
				FSizeCombo->SelectedIndex=2;
			//else if(setting.FormWidth==1024 && setting.FormHeight==768)
			//	FSizeCombo->SelectedIndex=3;
			//else if(setting.FormWidth==1280 && setting.FormHeight==1024)
			//	FSizeCombo->SelectedIndex=4;

			//バッファサイズ
			//if(setting.BufferWidth==400 && setting.BufferHeight==300)
			//	BSizeCombo->SelectedIndex=0;
			//else if(setting.BufferWidth==640 && setting.BufferHeight==480)
				BSizeCombo->SelectedIndex=1;
			//else if(setting.BufferWidth==800 && setting.BufferHeight==600)
			//	BSizeCombo->SelectedIndex=2;
			//else if(setting.BufferWidth==1024 && setting.BufferHeight==768)
			//	BSizeCombo->SelectedIndex=3;
			//else if(setting.BufferWidth==1280 && setting.BufferHeight==1024)
//				BSizeCombo->SelectedIndex=4;

			ColorCombo->SelectedIndex=0;

			TexFilterCheck->Checked=true;
			TexMultiCheck->Checked=true;
			EnvCheck->Checked=true;

			MipCombo->SelectedIndex=2;
			MipFilterCheck->Enabled=true;
			MipFilterCheck->Checked=false;

			ShadeCheck->Checked=true;

			KemuriCombo->SelectedIndex=1;
			ItemDisCombo->SelectedIndex=1;
			anticombo->SelectedIndex=0;

		 }

private: System::Void button4_Click(System::Object *  sender, System::EventArgs *  e)
		 {//低い

			 

			 //画面サイズ(ウィンドウモードのみ有効)
			//if(setting.FormWidth==400 && setting.FormHeight==300)
			//	FSizeCombo->SelectedIndex=0;
			//else if(setting.FormWidth==640 && setting.FormHeight==480)
			//	FSizeCombo->SelectedIndex=1;
			//else if(setting.FormWidth==800 && setting.FormHeight==600)
				FSizeCombo->SelectedIndex=2;
			//else if(setting.FormWidth==1024 && setting.FormHeight==768)
			//	FSizeCombo->SelectedIndex=3;
			//else if(setting.FormWidth==1280 && setting.FormHeight==1024)
			//	FSizeCombo->SelectedIndex=4;

			//バッファサイズ
			//if(setting.BufferWidth==400 && setting.BufferHeight==300)
			//	BSizeCombo->SelectedIndex=0;
			//else if(setting.BufferWidth==640 && setting.BufferHeight==480)
				BSizeCombo->SelectedIndex=1;
			//else if(setting.BufferWidth==800 && setting.BufferHeight==600)
			//	BSizeCombo->SelectedIndex=2;
			//else if(setting.BufferWidth==1024 && setting.BufferHeight==768)
			//	BSizeCombo->SelectedIndex=3;
			//else if(setting.BufferWidth==1280 && setting.BufferHeight==1024)
//				BSizeCombo->SelectedIndex=4;

			ColorCombo->SelectedIndex=0;

			TexFilterCheck->Checked=true;
			TexMultiCheck->Checked=true;
			EnvCheck->Checked=false;

			MipCombo->SelectedIndex=2;
			MipFilterCheck->Enabled=true;
			MipFilterCheck->Checked=false;

			ShadeCheck->Checked=false;

			KemuriCombo->SelectedIndex=1;
			ItemDisCombo->SelectedIndex=2;

			anticombo->SelectedIndex=0;

		 }

private: System::Void button5_Click(System::Object *  sender, System::EventArgs *  e)
		 {//最悪


			 

			 //画面サイズ(ウィンドウモードのみ有効)
			//if(setting.FormWidth==400 && setting.FormHeight==300)
			//	FSizeCombo->SelectedIndex=0;
			//else if(setting.FormWidth==640 && setting.FormHeight==480)
				FSizeCombo->SelectedIndex=1;
			//else if(setting.FormWidth==800 && setting.FormHeight==600)
			//	FSizeCombo->SelectedIndex=2;
			//else if(setting.FormWidth==1024 && setting.FormHeight==768)
			//	FSizeCombo->SelectedIndex=3;
			//else if(setting.FormWidth==1280 && setting.FormHeight==1024)
			//	FSizeCombo->SelectedIndex=4;

			//バッファサイズ
			//if(setting.BufferWidth==400 && setting.BufferHeight==300)
				BSizeCombo->SelectedIndex=0;
			//else if(setting.BufferWidth==640 && setting.BufferHeight==480)
			//	BSizeCombo->SelectedIndex=1;
			//else if(setting.BufferWidth==800 && setting.BufferHeight==600)
			//	BSizeCombo->SelectedIndex=2;
			//else if(setting.BufferWidth==1024 && setting.BufferHeight==768)
			//	BSizeCombo->SelectedIndex=3;
			//else if(setting.BufferWidth==1280 && setting.BufferHeight==1024)
//				BSizeCombo->SelectedIndex=4;

			ColorCombo->SelectedIndex=0;

			TexFilterCheck->Checked=false;
			TexMultiCheck->Checked=false;
			EnvCheck->Checked=false;

			MipCombo->SelectedIndex=3;
			MipFilterCheck->Enabled=true;
			MipFilterCheck->Checked=false;

			ShadeCheck->Checked=false;

			KemuriCombo->SelectedIndex=2;
			ItemDisCombo->SelectedIndex=2;

			anticombo->SelectedIndex=0;

		 }

private: System::Void anticombo_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			setting.anti=anticombo->SelectedIndex;
		 }

};
}


