#pragma once
#include <windows.h>
#include "Algoritmos.h"

#using <System.dll>
#using <System.Windows.Forms.dll>

#pragma comment (lib, "User32.lib")


namespace Sorts
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Sumário para MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Adicione o código do construtor aqui
			//
		}

	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Variável de designer necessária.
		/// </summary>
		System::ComponentModel::Container^ components;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ arquivoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ abrirToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ ajudaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ sobreToolStripMenuItem;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::TextBox^ textBox1;

		   PictureBox^ pctBox;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::ProgressBar^ progressBar2;
	private: System::Windows::Forms::Button^ button3;
		   Algoritmos alg;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Método necessário para suporte ao Designer - não modifique 
		   /// o conteúdo deste método com o editor de código.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			   this->arquivoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->abrirToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->ajudaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->sobreToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			   this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			   this->progressBar2 = (gcnew System::Windows::Forms::ProgressBar());
			   this->button3 = (gcnew System::Windows::Forms::Button());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   this->menuStrip1->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left));
			   this->pictureBox1->BackColor = System::Drawing::Color::White;
			   this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->pictureBox1->Location = System::Drawing::Point(12, 27);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(640, 480);
			   this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pictureBox1->TabIndex = 0;
			   this->pictureBox1->TabStop = false;
			   // 
			   // menuStrip1
			   // 
			   this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				   this->arquivoToolStripMenuItem,
					   this->ajudaToolStripMenuItem
			   });
			   this->menuStrip1->Location = System::Drawing::Point(0, 0);
			   this->menuStrip1->Name = L"menuStrip1";
			   this->menuStrip1->Size = System::Drawing::Size(1314, 24);
			   this->menuStrip1->TabIndex = 1;
			   this->menuStrip1->Text = L"menuStrip1";
			   // 
			   // arquivoToolStripMenuItem
			   // 
			   this->arquivoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->abrirToolStripMenuItem });
			   this->arquivoToolStripMenuItem->Name = L"arquivoToolStripMenuItem";
			   this->arquivoToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			   this->arquivoToolStripMenuItem->Text = L"Arquivo";
			   // 
			   // abrirToolStripMenuItem
			   // 
			   this->abrirToolStripMenuItem->Name = L"abrirToolStripMenuItem";
			   this->abrirToolStripMenuItem->Size = System::Drawing::Size(100, 22);
			   this->abrirToolStripMenuItem->Text = L"Abrir";
			   this->abrirToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::abrirToolStripMenuItem_Click);
			   // 
			   // ajudaToolStripMenuItem
			   // 
			   this->ajudaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->sobreToolStripMenuItem });
			   this->ajudaToolStripMenuItem->Name = L"ajudaToolStripMenuItem";
			   this->ajudaToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			   this->ajudaToolStripMenuItem->Text = L"Ajuda";
			   // 
			   // sobreToolStripMenuItem
			   // 
			   this->sobreToolStripMenuItem->Name = L"sobreToolStripMenuItem";
			   this->sobreToolStripMenuItem->Size = System::Drawing::Size(104, 22);
			   this->sobreToolStripMenuItem->Text = L"Sobre";
			   this->sobreToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::sobreToolStripMenuItem_Click);
			   // 
			   // button1
			   // 
			   this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			   this->button1->Location = System::Drawing::Point(1227, 681);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(75, 23);
			   this->button1->TabIndex = 2;
			   this->button1->Text = L"Iniciar";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			   // 
			   // openFileDialog1
			   // 
			   this->openFileDialog1->DefaultExt = L"jpg";
			   this->openFileDialog1->FileName = L"imagem";
			   this->openFileDialog1->Filter = L"Imagens (.png, *.jpg)|0.png;*.jpg";
			   this->openFileDialog1->ReadOnlyChecked = true;
			   this->openFileDialog1->ShowReadOnly = true;
			   this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
			   // 
			   // textBox1
			   // 
			   this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			   this->textBox1->Location = System::Drawing::Point(1013, 684);
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(196, 20);
			   this->textBox1->TabIndex = 3;
			   // 
			   // pictureBox2
			   // 
			   this->pictureBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->pictureBox2->BackColor = System::Drawing::Color::White;
			   this->pictureBox2->Location = System::Drawing::Point(658, 27);
			   this->pictureBox2->Name = L"pictureBox2";
			   this->pictureBox2->Size = System::Drawing::Size(640, 480);
			   this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pictureBox2->TabIndex = 4;
			   this->pictureBox2->TabStop = false;
			   this->pictureBox2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox2_Paint);
			   // 
			   // button2
			   // 
			   this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			   this->button2->Location = System::Drawing::Point(1227, 652);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(75, 23);
			   this->button2->TabIndex = 5;
			   this->button2->Text = L"Cinza";
			   this->button2->UseVisualStyleBackColor = true;
			   this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			   // 
			   // progressBar1
			   // 
			   this->progressBar1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->progressBar1->Location = System::Drawing::Point(12, 684);
			   this->progressBar1->Name = L"progressBar1";
			   this->progressBar1->Size = System::Drawing::Size(980, 23);
			   this->progressBar1->TabIndex = 6;
			   // 
			   // comboBox1
			   // 
			   this->comboBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			   this->comboBox1->FormattingEnabled = true;
			   this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				   L"Bucket Sort", L"Bubble Sort", L"Cocktail Sort",
					   L"Optimized Bubble Sort"
			   });
			   this->comboBox1->Location = System::Drawing::Point(1013, 652);
			   this->comboBox1->Name = L"comboBox1";
			   this->comboBox1->Size = System::Drawing::Size(196, 21);
			   this->comboBox1->TabIndex = 7;
			   this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			   // 
			   // progressBar2
			   // 
			   this->progressBar2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->progressBar2->Location = System::Drawing::Point(13, 651);
			   this->progressBar2->Name = L"progressBar2";
			   this->progressBar2->Size = System::Drawing::Size(979, 23);
			   this->progressBar2->TabIndex = 8;
			   // 
			   // button3
			   // 
			   this->button3->Location = System::Drawing::Point(1227, 623);
			   this->button3->Name = L"button3";
			   this->button3->Size = System::Drawing::Size(75, 23);
			   this->button3->TabIndex = 9;
			   this->button3->Text = L"Filtro";
			   this->button3->UseVisualStyleBackColor = true;
			   this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1314, 716);
			   this->Controls->Add(this->button3);
			   this->Controls->Add(this->progressBar2);
			   this->Controls->Add(this->comboBox1);
			   this->Controls->Add(this->progressBar1);
			   this->Controls->Add(this->button2);
			   this->Controls->Add(this->pictureBox2);
			   this->Controls->Add(this->textBox1);
			   this->Controls->Add(this->button1);
			   this->Controls->Add(this->pictureBox1);
			   this->Controls->Add(this->menuStrip1);
			   this->MainMenuStrip = this->menuStrip1;
			   this->Name = L"MyForm";
			   this->Text = L"Sorts";
			   this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   this->menuStrip1->ResumeLayout(false);
			   this->menuStrip1->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e)
	{



	}
	private: System::Void sobreToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		MessageBox::Show("Sorts V. 0.1", "Sobre", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		//MessageBox(hWnd, TEXT("Sorts2 v1.0\nCopyright (C) 2020\n"), TEXT("About"), MB_OK | MB_ICONINFORMATION);
	}


	private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e)
	{
		Bitmap^ bmp = gcnew Bitmap(openFileDialog1->FileName);
		pictureBox1->Image = bmp;
		Image^ img = pictureBox1->Image;
		SizeF^ s = img->PhysicalDimension;

		float ratio;
		ratio = s->Height / s->Width;

		if (ratio < 1.0)
		{
			pictureBox1->Height = 640 * ratio;
			pictureBox1->Width = 640;
		}
		else
		{
			pictureBox1->Height = 480;
			pictureBox1->Width = 480 / ratio;
		}
		pictureBox2->Width = pictureBox1->Width;
		pictureBox2->Height = pictureBox1->Height;

		//MessageBox::Show(s->ToString(), "Arquivo", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);

		alg.txtbx = this->textBox1;
		alg.destpic = this->pictureBox2;
		alg.pg1 = this->progressBar1;
		alg.pg2 = this->progressBar2;

		alg.ProcessaBMP(bmp);

	}
	private:
		System::Void abrirToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
		{
			openFileDialog1->ShowDialog();
			//var filePath = string.Empty;
		}
	private:
		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
		{
			alg.Ordenar();

		}
	private:
		System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
		{
			alg.gerarCinza();
		}
	private:
		System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
		{
			alg.setSort(comboBox1->SelectedItem->ToString());
		}
	private:
		System::Void pictureBox2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
		{
			DoEvents();

		}

	public:
		void DoEvents()
		{
			MSG msg;
			BOOL result;

			while (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
			{
				result = GetMessage(&msg, NULL, 0, 0);
				if (result == 0) // WM_QUIT
				{
					PostQuitMessage(msg.wParam);
					break;
				}
				else if (result == -1)
				{
					// Handle errors/exit application, etc.
				}
				else
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
			}
		}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		alg.filtro();
	}
};
}
