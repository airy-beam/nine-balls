#pragma once
#include "board.h"
#include "newgame.h"
#include "tree.cpp"

namespace Nineballs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			gameBoard = 0;
			last_move = 0;
			your_move = false;
			this->cells.Add(nullptr);
			for (int i = 1; i <= 18; i++)
			{
				this->cells.Add(gcnew System::Windows::Forms::Label);
				(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[i]))->Name = L"cell" + System::Convert::ToString(i);
				(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[i]))->Tag = i;
				(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[i]))->Size = System::Drawing::Size(48, 33);			
				(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[i]))->Anchor = System::Windows::Forms::AnchorStyles::None;
				(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[i]))->BackColor = System::Drawing::SystemColors::Control;
				(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[i]))->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[i]))->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
					static_cast<System::Byte>(204)));
				(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[i]))->ForeColor = System::Drawing::Color::Black;
				(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[i]))->Location = System::Drawing::Point(394, 96);
				(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[i]))->Margin = System::Windows::Forms::Padding(3);
				(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[i]))->Name = L"lbl_Max8";
				(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[i]))->Size = System::Drawing::Size(70, 50);
				(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[i]))->TabIndex = 36;
				(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[i]))->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[i]))->Click += gcnew System::EventHandler(this, &Form1::cell_Click);
			}

			(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[1]))->Location = System::Drawing::Point(51, 96);
			(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[2]))->Location = System::Drawing::Point(100, 96);
			(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[3]))->Location = System::Drawing::Point(149, 96);
			(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[4]))->Location = System::Drawing::Point(198, 96);
			(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[5]))->Location = System::Drawing::Point(247, 96);
			(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[6]))->Location = System::Drawing::Point(296, 96);
			(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[7]))->Location = System::Drawing::Point(345, 96);
			(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[8]))->Location = System::Drawing::Point(394, 96);
			(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[9]))->Location = System::Drawing::Point(443, 96);
			(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[10]))->Location = System::Drawing::Point(443, 7);
			(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[11]))->Location = System::Drawing::Point(394, 7);
			(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[12]))->Location = System::Drawing::Point(345, 7);
			(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[13]))->Location = System::Drawing::Point(296, 7);
			(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[14]))->Location = System::Drawing::Point(247, 7);
			(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[15]))->Location = System::Drawing::Point(198, 7);
			(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[16]))->Location = System::Drawing::Point(149, 7);
			(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[17]))->Location = System::Drawing::Point(100, 7);
			(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[18]))->Location = System::Drawing::Point(51, 7);

			for (int i = 1; i <= 9; i++)
				this->board->Controls->Add((dynamic_cast<System::Windows::Forms::Label ^>(this->cells[i])), i, 2);
			for (int i = 10; i <= 18; i++)
				this->board->Controls->Add((dynamic_cast<System::Windows::Forms::Label ^>(this->cells[i])), 18 - i + 1, 0);

		}

		void show_board(Board *);
		void make_move(int);
		void computer_to_move();
		void cell_increment(int, int);
		void cell_make_nil(int);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lbl_MinBoiler;
	private: System::Windows::Forms::Label^  lbl_MaxBoiler;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  gameToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  newGameToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Label^  lbl_Min1;
	private: System::Windows::Forms::Label^  lbl_Min2;
	private: System::Windows::Forms::Label^  lbl_Min3;
	private: System::Windows::Forms::Label^  lbl_Min4;
	private: System::Windows::Forms::Label^  lbl_Min5;
	private: System::Windows::Forms::Label^  lbl_Min6;
	private: System::Windows::Forms::Label^  lbl_Min7;
	private: System::Windows::Forms::Label^  lbl_Min8;
	private: System::Windows::Forms::Label^  lbl_Min9;
	private: System::Windows::Forms::Label^  lbl_Max9;
	private: System::Windows::Forms::Label^  lbl_Max8;
	private: System::Windows::Forms::Label^  lbl_Max7;
	private: System::Windows::Forms::Label^  lbl_Max6;
	private: System::Windows::Forms::Label^  lbl_Max5;
	private: System::Windows::Forms::Label^  lbl_Max4;
	private: System::Windows::Forms::Label^  lbl_Max3;
	private: System::Windows::Forms::Label^  lbl_Max2;
	private: System::Windows::Forms::Label^  lbl_Max1;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  lbl_Move;


	private: System::Windows::Forms::TableLayoutPanel^  board;
	private: System::Windows::Forms::ToolStripStatusLabel^  lbl_last_move;
	private: Board* gameBoard;
			 bool your_move;
			 int last_move;
			 bool move_clicked;

			 bool animation_started;
			 bool animation_ended;
			 int animation_flash_count;
			 int animation_moving_from;
			 int animation_stones_left;
			 int animation_current_cell;

private: System::Windows::Forms::Timer^  tmr_highlight;
private: System::Windows::Forms::Timer^  tmr_move_one_stone;
private: System::Windows::Forms::Label^  lbl_Game_over;




private: System::Windows::Forms::Panel^  pnl_image;
private: System::ComponentModel::BackgroundWorker^  worker_find_move;
private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::HelpProvider^  helpProvider1;





		 System::Collections::ArrayList cells;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->lbl_MinBoiler = (gcnew System::Windows::Forms::Label());
			this->lbl_MaxBoiler = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->gameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newGameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->lbl_Move = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->lbl_last_move = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->board = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->lbl_Game_over = (gcnew System::Windows::Forms::Label());
			this->tmr_highlight = (gcnew System::Windows::Forms::Timer(this->components));
			this->tmr_move_one_stone = (gcnew System::Windows::Forms::Timer(this->components));
			this->pnl_image = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->worker_find_move = (gcnew System::ComponentModel::BackgroundWorker());
			this->helpProvider1 = (gcnew System::Windows::Forms::HelpProvider());
			this->menuStrip1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->board->SuspendLayout();
			this->pnl_image->SuspendLayout();
			this->SuspendLayout();
			// 
			// lbl_MinBoiler
			// 
			this->lbl_MinBoiler->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lbl_MinBoiler->BackColor = System::Drawing::SystemColors::Control;
			this->lbl_MinBoiler->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lbl_MinBoiler->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->lbl_MinBoiler->ForeColor = System::Drawing::Color::Black;
			this->lbl_MinBoiler->Location = System::Drawing::Point(9, 51);
			this->lbl_MinBoiler->Margin = System::Windows::Forms::Padding(0);
			this->lbl_MinBoiler->Name = L"lbl_MinBoiler";
			this->lbl_MinBoiler->Size = System::Drawing::Size(64, 33);
			this->lbl_MinBoiler->TabIndex = 18;
			this->lbl_MinBoiler->Tag = L"";
			this->lbl_MinBoiler->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbl_MaxBoiler
			// 
			this->lbl_MaxBoiler->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lbl_MaxBoiler->BackColor = System::Drawing::SystemColors::Control;
			this->lbl_MaxBoiler->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lbl_MaxBoiler->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->lbl_MaxBoiler->ForeColor = System::Drawing::Color::Black;
			this->lbl_MaxBoiler->Location = System::Drawing::Point(577, 51);
			this->lbl_MaxBoiler->Margin = System::Windows::Forms::Padding(0);
			this->lbl_MaxBoiler->Name = L"lbl_MaxBoiler";
			this->lbl_MaxBoiler->Size = System::Drawing::Size(64, 33);
			this->lbl_MaxBoiler->TabIndex = 19;
			this->lbl_MaxBoiler->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->gameToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(699, 24);
			this->menuStrip1->TabIndex = 20;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &Form1::menuStrip1_ItemClicked);
			// 
			// gameToolStripMenuItem
			// 
			this->gameToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->newGameToolStripMenuItem, 
				this->toolStripMenuItem1, this->exitToolStripMenuItem});
			this->gameToolStripMenuItem->Name = L"gameToolStripMenuItem";
			this->gameToolStripMenuItem->Size = System::Drawing::Size(46, 20);
			this->gameToolStripMenuItem->Text = L"Игра";
			// 
			// newGameToolStripMenuItem
			// 
			this->newGameToolStripMenuItem->Name = L"newGameToolStripMenuItem";
			this->newGameToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F2;
			this->newGameToolStripMenuItem->Size = System::Drawing::Size(155, 22);
			this->newGameToolStripMenuItem->Text = L"Новая игра";
			this->newGameToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::newGameToolStripMenuItem_Click);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(152, 6);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(155, 22);
			this->exitToolStripMenuItem->Text = L"Выход";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->lbl_Move, this->lbl_last_move});
			this->statusStrip1->Location = System::Drawing::Point(0, 177);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(699, 22);
			this->statusStrip1->TabIndex = 22;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// lbl_Move
			// 
			this->lbl_Move->Name = L"lbl_Move";
			this->lbl_Move->Size = System::Drawing::Size(0, 17);
			// 
			// lbl_last_move
			// 
			this->lbl_last_move->Name = L"lbl_last_move";
			this->lbl_last_move->Size = System::Drawing::Size(0, 17);
			// 
			// board
			// 
			this->board->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->board->ColumnCount = 11;
			this->board->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 12.0048F)));
			this->board->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 8.443377F)));
			this->board->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 8.443377F)));
			this->board->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 8.443377F)));
			this->board->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 8.443377F)));
			this->board->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 8.443377F)));
			this->board->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 8.443377F)));
			this->board->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 8.443377F)));
			this->board->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 8.443377F)));
			this->board->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 8.443377F)));
			this->board->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 12.0048F)));
			this->board->Controls->Add(this->lbl_MaxBoiler, 10, 1);
			this->board->Controls->Add(this->lbl_MinBoiler, 0, 1);
			this->board->Controls->Add(this->lbl_Game_over, 1, 1);
			this->board->Location = System::Drawing::Point(23, 32);
			this->board->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->board->Name = L"board";
			this->board->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->board->RowCount = 3;
			this->board->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->board->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->board->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->board->Size = System::Drawing::Size(654, 138);
			this->board->TabIndex = 23;
			// 
			// lbl_Game_over
			// 
			this->lbl_Game_over->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lbl_Game_over->BackColor = System::Drawing::SystemColors::Control;
			this->board->SetColumnSpan(this->lbl_Game_over, 9);
			this->lbl_Game_over->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->lbl_Game_over->ForeColor = System::Drawing::Color::Black;
			this->lbl_Game_over->Location = System::Drawing::Point(108, 51);
			this->lbl_Game_over->Margin = System::Windows::Forms::Padding(0);
			this->lbl_Game_over->Name = L"lbl_Game_over";
			this->lbl_Game_over->Size = System::Drawing::Size(430, 33);
			this->lbl_Game_over->TabIndex = 20;
			this->lbl_Game_over->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lbl_Game_over->Visible = false;
			// 
			// tmr_highlight
			// 
			this->tmr_highlight->Interval = 350;
			this->tmr_highlight->Tick += gcnew System::EventHandler(this, &Form1::tmr_highlight_Tick);
			// 
			// tmr_move_one_stone
			// 
			this->tmr_move_one_stone->Interval = 500;
			this->tmr_move_one_stone->Tick += gcnew System::EventHandler(this, &Form1::tmr_move_one_stone_Tick);
			// 
			// pnl_image
			// 
			this->pnl_image->Controls->Add(this->label1);
			this->pnl_image->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnl_image->Location = System::Drawing::Point(0, 24);
			this->pnl_image->Name = L"pnl_image";
			this->pnl_image->Size = System::Drawing::Size(699, 153);
			this->pnl_image->TabIndex = 24;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(274, 72);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(156, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Нажмите F2 для начала игры";
			// 
			// worker_find_move
			// 
			this->worker_find_move->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Form1::worker_find_move_DoWork);
			this->worker_find_move->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &Form1::worker_find_move_RunWorkerCompleted);
			// 
			// helpProvider1
			// 
			this->helpProvider1->HelpNamespace = L"help.chm";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(699, 199);
			this->Controls->Add(this->pnl_image);
			this->Controls->Add(this->board);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->HelpButton = true;
			this->helpProvider1->SetHelpNavigator(this, System::Windows::Forms::HelpNavigator::TableOfContents);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->helpProvider1->SetShowHelp(this, true);
			this->Text = L"Тогыз кумалак";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->board->ResumeLayout(false);
			this->pnl_image->ResumeLayout(false);
			this->pnl_image->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

private: System::Void newGameToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			newgame^ ng = gcnew newgame;
			if (ng->ShowDialog(this) == ::DialogResult::OK)
			{
				this->tmr_highlight->Enabled = false;
				this->tmr_move_one_stone->Enabled = false;
				if ( 0 != gameBoard ) delete gameBoard;
				gameBoard = new Board;
				gameBoard->initialize();
				gameBoard->MaxDepth = ng->level;
				this->pnl_image->Visible = false;
				this->lbl_Game_over->Visible = false;
				this->move_clicked = false;
				if ( newgame::Players::human == ng->first_move ) 
				{
					this->your_move = true;
					this->show_board(gameBoard);
				}
				else
				{
					this->your_move = false;
					gameBoard->turn = Board::Min;
					this->show_board(gameBoard);
					//this->Refresh();
					this->computer_to_move();
					//this->last_move = gameBoard->find_best_move();
					//this->make_move(this->last_move);
				}
			}
			delete ng;
		 }

private: System::Void cell_Click(System::Object^  sender, System::EventArgs^  e)
		 {		
			 int move = System::Convert::ToInt16(dynamic_cast<System::Windows::Forms::Label ^>(sender)->Tag);
			 if (( true == your_move ) && (gameBoard->is_legal(move)) && !(this->move_clicked))
			 {
				 this->move_clicked = true;
			     this->make_move(move);
			 }
		 }

private: System::Void menuStrip1_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) 
		 {
		 }

private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
		 {
		 }


private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if ( 0 != gameBoard ) delete gameBoard;
			 Application::Exit();
		 }

private: System::Void tmr_highlight_Tick(System::Object^  sender, System::EventArgs^  e)
		 {	 
			 if (this->animation_flash_count < 6)
			 {
				 (dynamic_cast<System::Windows::Forms::Label ^>(this->cells[this->animation_current_cell]))->BackColor = 
					 ( (this->animation_flash_count % 2 == 0)? System::Drawing::Color::Red :
						System::Drawing::SystemColors::Control );
				 this->animation_flash_count++;
			 }
			 else
			 {
				 this->tmr_highlight->Enabled = false;
				 this->tmr_move_one_stone->Enabled = true;
			 }	 
		}

private: System::Void tmr_move_one_stone_Tick(System::Object^  sender, System::EventArgs^  e)
		{
			if ( true == this->animation_ended )
			{
				this->tmr_move_one_stone->Enabled = false;
				Board * oldBoard = gameBoard;
				gameBoard = gameBoard->make_move(this->animation_moving_from);
				delete oldBoard;
				//_CrtDumpMemoryLeaks();

				if (gameBoard->game_over()) 
				{
					for (int i = 1; i <= 9; i++)
					{
						int a = System::Convert::ToInt16(this->lbl_MaxBoiler->Text);
						a += System::Convert::ToInt16((dynamic_cast<System::Windows::Forms::Label ^>(this->cells[i])->Text));
						this->lbl_MaxBoiler->Text = System::Convert::ToString(a);
						this->cell_make_nil(i);
					}
					for (int i = 10; i <= 18; i++)
					{
						int a = System::Convert::ToInt16(this->lbl_MinBoiler->Text);
						a += System::Convert::ToInt16((dynamic_cast<System::Windows::Forms::Label ^>(this->cells[i])->Text));
						this->lbl_MinBoiler->Text = System::Convert::ToString(a);
						this->cell_make_nil(i);
					}
					this->lbl_Move->Text = "";
					if (gameBoard->MaxBoiler > gameBoard->MinBoiler)
						this->lbl_Game_over->Text = "Вы победили!";
					if (gameBoard->MaxBoiler < gameBoard->MinBoiler)
						this->lbl_Game_over->Text = "Вы проиграли!";
					if (gameBoard->MaxBoiler == gameBoard->MinBoiler)
						this->lbl_Game_over->Text = "Ничья!";
					this->lbl_Game_over->Visible = true;
				}
				else
				{
					if ( true == this->your_move ) 
					{
						this->your_move = false;
						this->lbl_Move->Text = "Ход компьютера...";
						//this->Refresh();
						this->computer_to_move();
						//this->last_move = gameBoard->find_best_move();
						//this->make_move(this->last_move);
					}
					else
					{
						this->your_move = true;
						this->move_clicked = false;
						this->lbl_Move->Text = "Ваш ход!"; 
					}
				}
			}
			else
			{
				if ( true == this->animation_started )
				{
					this->animation_started = false;
					if ( 1 == this->animation_stones_left )
					{
						this->cell_make_nil(this->animation_current_cell);					
						this->animation_stones_left = 2;
					}
					else
						(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[this->animation_current_cell]))->Text = System::Convert::ToString(1);
				}
				else
				{
					if ( gameBoard->MaxSacred == this->animation_current_cell )
					{
						int a = System::Convert::ToInt16(this->lbl_MaxBoiler->Text);
						this->lbl_MaxBoiler->Text = System::Convert::ToString(a + 1);
					}
					else
					if ( gameBoard->MinSacred == this->animation_current_cell )
					{
						int a = System::Convert::ToInt16(this->lbl_MinBoiler->Text);
						this->lbl_MinBoiler->Text = System::Convert::ToString(a + 1);
					}
					else
					{
						this->cell_increment(this->animation_current_cell, 1);
					}					
				}		 
				this->animation_stones_left--;
				if ( 0 == this->animation_stones_left)
				{
					this->animation_ended = true;
					int last_balls = System::Convert::ToInt16((dynamic_cast<System::Windows::Forms::Label ^>(this->cells[this->animation_current_cell])->Text));
					int last_index = this->animation_current_cell;
					if ( 0 == last_balls % 2 )
					{
						if ((Board::Max == gameBoard->turn) &&
							(this->animation_current_cell >= 10) )
						{
							int a = System::Convert::ToInt16(this->lbl_MaxBoiler->Text);
							a += System::Convert::ToInt16((dynamic_cast<System::Windows::Forms::Label ^>(this->cells[last_index])->Text));
							this->lbl_MaxBoiler->Text = System::Convert::ToString(a);
							this->cell_make_nil(last_index);
						}
						if ((Board::Min == gameBoard->turn) &&
							(this->animation_current_cell <= 9) )
						{
							int a = System::Convert::ToInt16(this->lbl_MinBoiler->Text);
							a += System::Convert::ToInt16((dynamic_cast<System::Windows::Forms::Label ^>(this->cells[last_index]))->Text);
							this->lbl_MinBoiler->Text = System::Convert::ToString(a);
							this->cell_make_nil(last_index);
						}
					}
					
					if (last_balls == 3 && last_index != 9 && last_index != 18)
					{
						if ((0 == gameBoard->MaxSacred) &&
							(Board::Max == gameBoard->turn) &&
							(gameBoard->MinSacred != last_index - 9) &&
							(last_index >= 10))
						{
							int a = System::Convert::ToInt16(this->lbl_MaxBoiler->Text);
							a += System::Convert::ToInt16((dynamic_cast<System::Windows::Forms::Label ^>(this->cells[last_index])->Text));
							this->lbl_MaxBoiler->Text = System::Convert::ToString(a);
							(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[last_index]))->BackColor = System::Drawing::Color::Black;
							this->cell_make_nil(last_index);
						}
						if ((0 == gameBoard->MinSacred) &&
							(Board::Min == gameBoard->turn) &&
							(gameBoard->MaxSacred != last_index + 9) &&
							(last_index <= 9))
						{
							int a = System::Convert::ToInt16(this->lbl_MinBoiler->Text);
							a += System::Convert::ToInt16((dynamic_cast<System::Windows::Forms::Label ^>(this->cells[last_index]))->Text);
							this->lbl_MinBoiler->Text = System::Convert::ToString(a);
							(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[last_index]))->BackColor = System::Drawing::Color::Black;
							this->cell_make_nil(last_index);
						}
					}
					
				}
				this->animation_current_cell++;
				if (this->animation_current_cell > 18) this->animation_current_cell = 1;
			}
		}
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void worker_find_move_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
			 //Board * board = dynamic_cast<Board *>(e->Argument);
			 //e->Result = ->
			 BackgroundWorker^ worker = dynamic_cast<BackgroundWorker^>(sender);

      // Assign the result of the computation
      // to the Result property of the DoWorkEventArgs
      // object. This is will be available to the 
      // RunWorkerCompleted eventhandler.
			 e->Result = this->gameBoard->find_best_move();// ComputeFibonacci( safe_cast<Int32>(e->Argument), worker, e );

		 }
private: System::Void помощьToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 System::Windows::Forms::SendKeys::Send("{F1}");
		 }

private: System::Void worker_find_move_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
			 this->make_move(System::Convert::ToInt16(e->Result->ToString()));
		 }
};

void Form1::show_board(Board* board)
{
	this->lbl_MaxBoiler->Text = System::Convert::ToString(gameBoard->MaxBoiler);
	this->lbl_MinBoiler->Text = System::Convert::ToString(gameBoard->MinBoiler);
	
	for (int i = 1; i <= 18; i++)
	{
		(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[i]))->Text = System::Convert::ToString(gameBoard->cells[i]);
		(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[i]))->BackColor = System::Drawing::SystemColors::Control;
	}
	if ( 0 != gameBoard->MaxSacred )
	{
		(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[gameBoard->MaxSacred]))->BackColor = 
			System::Drawing::Color::Black;
	}
	if ( 0 != gameBoard->MinSacred )
	{
		(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[gameBoard->MinSacred]))->BackColor = 
			System::Drawing::Color::Black;
	}

	if ((0 != last_move) && (0 != gameBoard->last_index))
	{
		int start_cell = last_move;
		int end_cell = gameBoard->last_index;
		int gradient_steps = 0;
		int current_cell = start_cell;
		while (!(current_cell == end_cell))
		{
			current_cell++;
			if (current_cell > 18) current_cell = 1;
			gradient_steps++;
		}
		int color_change = 200 / gradient_steps;
		int grad_color = 0;
		current_cell = start_cell;
		(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[current_cell]))->BackColor = 
				System::Drawing::Color::FromArgb(255, grad_color, grad_color);
		while (!(current_cell == end_cell))
		{
			current_cell++;
			if (current_cell > 18) current_cell = 1;
			grad_color += color_change;
			if ((current_cell != gameBoard->MaxSacred) && (current_cell != gameBoard->MinSacred))
			(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[current_cell]))->BackColor = 
				System::Drawing::Color::FromArgb(255, grad_color, grad_color);
		}
	}

	if (gameBoard->game_over()) 
	{
		if (gameBoard->MaxBoiler > gameBoard->MinBoiler)
			this->lbl_Move->Text = "Вы выиграли!";
		if (gameBoard->MaxBoiler < gameBoard->MinBoiler)
			this->lbl_Move->Text = "Вы проиграли!";
		if (gameBoard->MaxBoiler == gameBoard->MinBoiler)
			this->lbl_Move->Text = "Ничья!";
	}
	else
	{
		if (your_move) 
		{
			this->lbl_Move->Text = "Ваш ход!"; 
		}
		else	
		{
			this->lbl_Move->Text = "Ход компьютера!";
		}
	}
}

void Form1::make_move(int move)
{		
	/* 
	for (int i = 1; i <= 18; i++)
		if ( ( i != gameBoard->MaxSacred ) && ( i != gameBoard->MinSacred ) )
			(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[i]))->BackColor = System::Drawing::SystemColors::Control;
	*/
	this->animation_started = true;
	this->animation_ended = false;
	this->animation_flash_count = 0;
	this->animation_moving_from = move;
	this->animation_current_cell = move;
	this->animation_stones_left = gameBoard->cells[move];
	this->tmr_highlight->Enabled = true;
}

void Form1::computer_to_move()
{
	this->worker_find_move->RunWorkerAsync();
}

void Form1::cell_increment(int n, int inc)
{
	int stones = System::Convert::ToInt16((dynamic_cast<System::Windows::Forms::Label ^>(this->cells[n])->Text));
	stones += inc;
	(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[n]))->Text = System::Convert::ToString(stones);
}

void Form1::cell_make_nil(int n)
{
	(dynamic_cast<System::Windows::Forms::Label ^>(this->cells[n]))->Text = System::Convert::ToString(0);
}


}
