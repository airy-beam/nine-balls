#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Nineballs {

	/// <summary>
	/// Summary for newgame
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class newgame : public System::Windows::Forms::Form
	{
	public:
		newgame(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		enum class Players { human, computer };
		Players first_move;
		int level;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~newgame()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::RadioButton^  rbtHuman;
	private: System::Windows::Forms::RadioButton^  rbtComputer;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::NumericUpDown^  edtLevel;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->rbtHuman = (gcnew System::Windows::Forms::RadioButton());
			this->rbtComputer = (gcnew System::Windows::Forms::RadioButton());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->edtLevel = (gcnew System::Windows::Forms::NumericUpDown());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->edtLevel))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 18);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Первый ход:";
			// 
			// rbtHuman
			// 
			this->rbtHuman->AutoSize = true;
			this->rbtHuman->Location = System::Drawing::Point(118, 16);
			this->rbtHuman->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->rbtHuman->Name = L"rbtHuman";
			this->rbtHuman->Size = System::Drawing::Size(69, 17);
			this->rbtHuman->TabIndex = 1;
			this->rbtHuman->TabStop = true;
			this->rbtHuman->Text = L"Человек";
			this->rbtHuman->UseVisualStyleBackColor = true;
			// 
			// rbtComputer
			// 
			this->rbtComputer->AutoSize = true;
			this->rbtComputer->Location = System::Drawing::Point(118, 38);
			this->rbtComputer->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->rbtComputer->Name = L"rbtComputer";
			this->rbtComputer->Size = System::Drawing::Size(83, 17);
			this->rbtComputer->TabIndex = 2;
			this->rbtComputer->TabStop = true;
			this->rbtComputer->Text = L"Компьютер";
			this->rbtComputer->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 71);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(112, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Уровень сложности:";
			// 
			// edtLevel
			// 
			this->edtLevel->Location = System::Drawing::Point(119, 71);
			this->edtLevel->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->edtLevel->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {6, 0, 0, 0});
			this->edtLevel->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			this->edtLevel->Name = L"edtLevel";
			this->edtLevel->Size = System::Drawing::Size(76, 20);
			this->edtLevel->TabIndex = 4;
			this->edtLevel->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {3, 0, 0, 0});
			// 
			// button1
			// 
			this->button1->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button1->Location = System::Drawing::Point(52, 103);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(70, 19);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Отмена";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->button2->Location = System::Drawing::Point(127, 103);
			this->button2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(68, 19);
			this->button2->TabIndex = 6;
			this->button2->Text = L"OK";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &newgame::button2_Click);
			// 
			// newgame
			// 
			this->AcceptButton = this->button2;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(202, 131);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->edtLevel);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->rbtComputer);
			this->Controls->Add(this->rbtHuman);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MaximizeBox = false;
			this->Name = L"newgame";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Новая игра";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->edtLevel))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (rbtComputer->Checked)
					 this->first_move = Players::computer;
				 else
					 this->first_move = Players::human;
				 this->level = System::Convert::ToInt16(edtLevel->Value);
			 }
};
}
