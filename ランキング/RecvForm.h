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
	/// RecvForm の概要
	///
	/// 警告 : このクラスの名前を変更する場合、このクラスが依存するすべての .resx ファイルに関連付けられた 
	///          マネージ リソース コンパイラ ツールに対して 'Resource File Name' プロパティを 
	///          変更する必要があります。この変更を行わないと、
	///          デザイナと、このフォームに関連付けられたローカライズ済みリソースとが、
	///          正しく相互に利用できなくなります。
	/// </summary>
	public __gc class RecvForm : public System::Windows::Forms::Form
	{
	public: 
		RecvForm(void)
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
	private: System::Windows::Forms::Button *  button1;

	private: System::Windows::Forms::Label *  label1;
	private: System::Windows::Forms::ProgressBar *  progress;

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
			this->button1 = new System::Windows::Forms::Button();
			this->progress = new System::Windows::Forms::ProgressBar();
			this->label1 = new System::Windows::Forms::Label();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(176, 72);
			this->button1->Name = S"button1";
			this->button1->Size = System::Drawing::Size(80, 24);
			this->button1->TabIndex = 6;
			this->button1->Text = S" ";
			this->button1->Visible = false;
			// 
			// progress
			// 
			this->progress->Location = System::Drawing::Point(16, 48);
			this->progress->Name = S"progress";
			this->progress->Size = System::Drawing::Size(240, 16);
			this->progress->TabIndex = 5;
			this->progress->Visible = false;
			// 
			// label1
			// 
			this->label1->Font = new System::Drawing::Font(S"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)128);
			this->label1->Location = System::Drawing::Point(0, 32);
			this->label1->Name = S"label1";
			this->label1->Size = System::Drawing::Size(272, 24);
			this->label1->TabIndex = 4;
			this->label1->Text = S"リプレイデータを受信しています";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// RecvForm
			// 
			this->AutoScaleBaseSize = System::Drawing::Size(5, 12);
			this->ClientSize = System::Drawing::Size(270, 82);
			this->ControlBox = false;
			this->Controls->Add(this->button1);
			this->Controls->Add(this->progress);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = S"RecvForm";
			this->Opacity = 0.7;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->ResumeLayout(false);

		}		


	};
}
