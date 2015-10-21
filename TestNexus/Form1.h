#pragma once
#include "Drawer.h"
#include "GameManager.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

GameManager game;

namespace TestNexus {

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
			//
			//TODO: Add the constructor code here
			//
		}

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
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  score;
	private: System::Windows::Forms::Label^  highScore;
	private: System::Windows::Forms::Label^  label1;
	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->score = (gcnew System::Windows::Forms::Label());
			this->highScore = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 19);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(362, 362);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseClick);
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->button1->Font = (gcnew System::Drawing::Font(L"Impact", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Chartreuse;
			this->button1->Location = System::Drawing::Point(380, 251);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(143, 30);
			this->button1->TabIndex = 1;
			this->button1->Text = L"START";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ControlDark;
			this->button2->Font = (gcnew System::Drawing::Font(L"Impact", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Chartreuse;
			this->button2->Location = System::Drawing::Point(380, 287);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(143, 30);
			this->button2->TabIndex = 2;
			this->button2->Text = L"RESET";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::ControlDark;
			this->button3->Font = (gcnew System::Drawing::Font(L"Impact", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::Chartreuse;
			this->button3->Location = System::Drawing::Point(380, 323);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(143, 30);
			this->button3->TabIndex = 3;
			this->button3->Text = L"EXIT";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// score
			// 
			this->score->AutoSize = true;
			this->score->Font = (gcnew System::Drawing::Font(L"Impact", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->score->ForeColor = System::Drawing::Color::Chartreuse;
			this->score->Location = System::Drawing::Point(380, 123);
			this->score->Name = L"score";
			this->score->Size = System::Drawing::Size(73, 23);
			this->score->TabIndex = 4;
			this->score->Text = L"Score: 0";
			// 
			// highScore
			// 
			this->highScore->AutoSize = true;
			this->highScore->Font = (gcnew System::Drawing::Font(L"Impact", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->highScore->ForeColor = System::Drawing::Color::Chartreuse;
			this->highScore->Location = System::Drawing::Point(380, 169);
			this->highScore->Name = L"highScore";
			this->highScore->Size = System::Drawing::Size(112, 23);
			this->highScore->TabIndex = 5;
			this->highScore->Text = L"High Score: 0";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Impact", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Chartreuse;
			this->label1->Location = System::Drawing::Point(380, 47);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(143, 34);
			this->label1->TabIndex = 6;
			this->label1->Text = L"NEXUS 2000";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::CadetBlue;
			this->ClientSize = System::Drawing::Size(535, 395);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->highScore);
			this->Controls->Add(this->score);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Form1";
			this->Text = L"NEXUS 2000";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(!game.isGameStarted()){
					Drawer::init(pictureBox1->CreateGraphics());
					delete pictureBox1->Image;
					pictureBox1->Image = nullptr;
					game.gameStart();
					pictureBox1->Invalidate();

					timer1->Start();
				 }
			 }
	private: System::Void pictureBox1_Paint(Object^ sender, PaintEventArgs^ e) {
			 Drawer::init(e->Graphics);
			 game.drawAll();
			 Threading::Thread::Sleep(10);
		 }

	private: System::Void pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 pictureBox1->Invalidate();
				 game.move(e);
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

				Drawer::init(pictureBox1->CreateGraphics());
				delete pictureBox1->Image;
				pictureBox1->Image = nullptr;
				game.gameStart();
				pictureBox1->Invalidate();
				
				timer1->Start();
			 }
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 Application::Exit();
			 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			 if(game.isGameStarted()){
				 if(game.endState() == false){
					 score->Text = "Score: " + game.getCurrentScore();

					 if(game.getCurrentScore() >= game.getHighScore()){
						 highScore->Text = "High Score: " + game.getHighScore();
					 }
				 }
				 else{
					 game.setGameStarted(false);
					 timer1->Stop();
					 MessageBox::Show("Game Over!","Message", MessageBoxButtons::OK);
				 }
			 }
		 }
};
}
