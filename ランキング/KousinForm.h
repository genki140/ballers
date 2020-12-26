#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace My
{
	/// <summary> 
	/// KousinForm の概要
	///
	/// 警告 : このクラスの名前を変更する場合、このクラスが依存するすべての .resx ファイルに関連付けられた 
	///          マネージ リソース コンパイラ ツールに対して 'Resource File Name' プロパティを 
	///          変更する必要があります。この変更を行わないと、
	///          デザイナと、このフォームに関連付けられたローカライズ済みリソースとが、
	///          正しく相互に利用できなくなります。
	/// </summary>
	public __gc class KousinForm : public System::Windows::Forms::Form
	{
	public: 
		KousinForm(void)
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
	private: System::Windows::Forms::Label *  label1;

	private:
		/// <summary>
		/// 必要なデザイナ変数です。
		/// </summary>
		System::ComponentModel::Container* components;

		/// <summary>
		/// デザイナ サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディタで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = new System::Windows::Forms::Label();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label1->Location = System::Drawing::Point(0, 32);
			this->label1->Name = S"label1";
			this->label1->Size = System::Drawing::Size(272, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = S"最新情報を受信しています";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// KousinForm
			// 
			this->AutoScale = false;
			this->AutoScaleBaseSize = System::Drawing::Size(5, 12);
			this->ClientSize = System::Drawing::Size(270, 82);
			this->ControlBox = false;
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = S"KousinForm";
			this->Opacity = 0.7;
			this->ShowInTaskbar = false;
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->ResumeLayout(false);

		}		



	};
}
