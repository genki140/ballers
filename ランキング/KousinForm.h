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
	/// KousinForm �̊T�v
	///
	/// �x�� : ���̃N���X�̖��O��ύX����ꍇ�A���̃N���X���ˑ����邷�ׂĂ� .resx �t�@�C���Ɋ֘A�t����ꂽ 
	///          �}�l�[�W ���\�[�X �R���p�C�� �c�[���ɑ΂��� 'Resource File Name' �v���p�e�B�� 
	///          �ύX����K�v������܂��B���̕ύX���s��Ȃ��ƁA
	///          �f�U�C�i�ƁA���̃t�H�[���Ɋ֘A�t����ꂽ���[�J���C�Y�ς݃��\�[�X�Ƃ��A
	///          ���������݂ɗ��p�ł��Ȃ��Ȃ�܂��B
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
		/// �K�v�ȃf�U�C�i�ϐ��ł��B
		/// </summary>
		System::ComponentModel::Container* components;

		/// <summary>
		/// �f�U�C�i �T�|�[�g�ɕK�v�ȃ��\�b�h�ł��B���̃��\�b�h�̓��e��
		/// �R�[�h �G�f�B�^�ŕύX���Ȃ��ł��������B
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
			this->label1->Text = S"�ŐV������M���Ă��܂�";
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
