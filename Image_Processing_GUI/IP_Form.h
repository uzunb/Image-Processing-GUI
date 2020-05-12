#include <Windows.h>
#include <atlstr.h>

#include "ReadBMP.h"
#include "IP_tools.h"
#include "SmoothingForm.h"

namespace ImageProcessingGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Microsoft::VisualBasic;

	/// <summary>
	/// Summary for IP_Form
	/// </summary>
	public ref class IP_Form : public System::Windows::Forms::Form
	{
	
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~IP_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openImageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ conversionToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::ToolStripMenuItem^ grayscaleImageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ binaryImageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ processToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ extractHistogramToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ closeImageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ original›mageHistogramToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ grayscale›mageHistogramToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ binary›mageHistogramToolStripMenuItem;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::ToolStripMenuItem^ smootingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ meanFilteringToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ medianFilteringToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ gaussianSmoothingToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	public: System::Windows::Forms::Label^ label4;


	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Label^ label5;
	public: System::Windows::Forms::ComboBox^ comboBox1;
	private:
	private: System::Windows::Forms::Label^ label6;
	public:

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openImageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeImageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->conversionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->grayscaleImageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->binaryImageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->processToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->extractHistogramToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->original›mageHistogramToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->grayscale›mageHistogramToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->binary›mageHistogramToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->smootingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->meanFilteringToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->medianFilteringToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gaussianSmoothingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::DimGray;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->conversionToolStripMenuItem, this->processToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1540, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->openImageToolStripMenuItem,
					this->closeImageToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(46, 24);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openImageToolStripMenuItem
			// 
			this->openImageToolStripMenuItem->Name = L"openImageToolStripMenuItem";
			this->openImageToolStripMenuItem->Size = System::Drawing::Size(174, 26);
			this->openImageToolStripMenuItem->Text = L"Open Image";
			this->openImageToolStripMenuItem->ToolTipText = L"Open BMP image";
			this->openImageToolStripMenuItem->Click += gcnew System::EventHandler(this, &IP_Form::openImageToolStripMenuItem_Click);
			// 
			// closeImageToolStripMenuItem
			// 
			this->closeImageToolStripMenuItem->Name = L"closeImageToolStripMenuItem";
			this->closeImageToolStripMenuItem->Size = System::Drawing::Size(174, 26);
			this->closeImageToolStripMenuItem->Text = L"Close Image";
			this->closeImageToolStripMenuItem->ToolTipText = L"Clean to buffers";
			this->closeImageToolStripMenuItem->Click += gcnew System::EventHandler(this, &IP_Form::closeImageToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(174, 26);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->ToolTipText = L"Clear to buffers and exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &IP_Form::exitToolStripMenuItem_Click);
			// 
			// conversionToolStripMenuItem
			// 
			this->conversionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->grayscaleImageToolStripMenuItem,
					this->binaryImageToolStripMenuItem
			});
			this->conversionToolStripMenuItem->Name = L"conversionToolStripMenuItem";
			this->conversionToolStripMenuItem->Size = System::Drawing::Size(96, 24);
			this->conversionToolStripMenuItem->Text = L"Conversion";
			// 
			// grayscaleImageToolStripMenuItem
			// 
			this->grayscaleImageToolStripMenuItem->Name = L"grayscaleImageToolStripMenuItem";
			this->grayscaleImageToolStripMenuItem->Size = System::Drawing::Size(201, 26);
			this->grayscaleImageToolStripMenuItem->Text = L"Grayscale Image";
			this->grayscaleImageToolStripMenuItem->ToolTipText = L"Convert to grayscale from original i";
			this->grayscaleImageToolStripMenuItem->Click += gcnew System::EventHandler(this, &IP_Form::grayscaleImageToolStripMenuItem_Click);
			// 
			// binaryImageToolStripMenuItem
			// 
			this->binaryImageToolStripMenuItem->Name = L"binaryImageToolStripMenuItem";
			this->binaryImageToolStripMenuItem->Size = System::Drawing::Size(201, 26);
			this->binaryImageToolStripMenuItem->Text = L"Binary Image";
			this->binaryImageToolStripMenuItem->ToolTipText = L"Convert to binary image from grayscale image";
			this->binaryImageToolStripMenuItem->Click += gcnew System::EventHandler(this, &IP_Form::binaryImageToolStripMenuItem_Click);
			// 
			// processToolStripMenuItem
			// 
			this->processToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->extractHistogramToolStripMenuItem,
					this->smootingToolStripMenuItem
			});
			this->processToolStripMenuItem->Name = L"processToolStripMenuItem";
			this->processToolStripMenuItem->Size = System::Drawing::Size(72, 24);
			this->processToolStripMenuItem->Text = L"Process";
			// 
			// extractHistogramToolStripMenuItem
			// 
			this->extractHistogramToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->original›mageHistogramToolStripMenuItem,
					this->grayscale›mageHistogramToolStripMenuItem, this->binary›mageHistogramToolStripMenuItem
			});
			this->extractHistogramToolStripMenuItem->Name = L"extractHistogramToolStripMenuItem";
			this->extractHistogramToolStripMenuItem->Size = System::Drawing::Size(208, 26);
			this->extractHistogramToolStripMenuItem->Text = L"Extract histogram";
			// 
			// original›mageHistogramToolStripMenuItem
			// 
			this->original›mageHistogramToolStripMenuItem->Name = L"original›mageHistogramToolStripMenuItem";
			this->original›mageHistogramToolStripMenuItem->Size = System::Drawing::Size(272, 26);
			this->original›mageHistogramToolStripMenuItem->Text = L"Original image histogram";
			this->original›mageHistogramToolStripMenuItem->Click += gcnew System::EventHandler(this, &IP_Form::originalImageHistogramToolStripMenuItem_Click);
			// 
			// grayscale›mageHistogramToolStripMenuItem
			// 
			this->grayscale›mageHistogramToolStripMenuItem->Name = L"grayscale›mageHistogramToolStripMenuItem";
			this->grayscale›mageHistogramToolStripMenuItem->Size = System::Drawing::Size(272, 26);
			this->grayscale›mageHistogramToolStripMenuItem->Text = L"Grayscale image histogram";
			this->grayscale›mageHistogramToolStripMenuItem->Click += gcnew System::EventHandler(this, &IP_Form::grayscaleImageHistogramToolStripMenuItem_Click);
			// 
			// binary›mageHistogramToolStripMenuItem
			// 
			this->binary›mageHistogramToolStripMenuItem->Name = L"binary›mageHistogramToolStripMenuItem";
			this->binary›mageHistogramToolStripMenuItem->Size = System::Drawing::Size(272, 26);
			this->binary›mageHistogramToolStripMenuItem->Text = L"Binary image histogram";
			this->binary›mageHistogramToolStripMenuItem->Click += gcnew System::EventHandler(this, &IP_Form::binaryImageHistogramToolStripMenuItem_Click);
			// 
			// smootingToolStripMenuItem
			// 
			this->smootingToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->meanFilteringToolStripMenuItem,
					this->medianFilteringToolStripMenuItem, this->gaussianSmoothingToolStripMenuItem
			});
			this->smootingToolStripMenuItem->Name = L"smootingToolStripMenuItem";
			this->smootingToolStripMenuItem->Size = System::Drawing::Size(208, 26);
			this->smootingToolStripMenuItem->Text = L"Smoothing";
			// 
			// meanFilteringToolStripMenuItem
			// 
			this->meanFilteringToolStripMenuItem->Name = L"meanFilteringToolStripMenuItem";
			this->meanFilteringToolStripMenuItem->Size = System::Drawing::Size(227, 26);
			this->meanFilteringToolStripMenuItem->Text = L"Mean Filtering";
			this->meanFilteringToolStripMenuItem->Click += gcnew System::EventHandler(this, &IP_Form::meanFilteringToolStripMenuItem_Click);
			// 
			// medianFilteringToolStripMenuItem
			// 
			this->medianFilteringToolStripMenuItem->Name = L"medianFilteringToolStripMenuItem";
			this->medianFilteringToolStripMenuItem->Size = System::Drawing::Size(227, 26);
			this->medianFilteringToolStripMenuItem->Text = L"Median Filtering";
			// 
			// gaussianSmoothingToolStripMenuItem
			// 
			this->gaussianSmoothingToolStripMenuItem->Name = L"gaussianSmoothingToolStripMenuItem";
			this->gaussianSmoothingToolStripMenuItem->Size = System::Drawing::Size(227, 26);
			this->gaussianSmoothingToolStripMenuItem->Text = L"Gaussian Smoothing";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(28, 41);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(400, 300);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(502, 41);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(400, 300);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(28, 388);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(400, 300);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 3;
			this->pictureBox3->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::MidnightBlue;
			this->label1->Location = System::Drawing::Point(155, 344);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(139, 25);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Original Image";
			this->label1->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::MidnightBlue;
			this->label2->Location = System::Drawing::Point(641, 344);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(111, 25);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Gray Image";
			this->label2->Visible = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::MidnightBlue;
			this->label3->Location = System::Drawing::Point(168, 691);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(126, 25);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Binary Image";
			this->label3->Visible = false;
			// 
			// chart1
			// 
			this->chart1->BackColor = System::Drawing::Color::DarkGray;
			this->chart1->BackImageTransparentColor = System::Drawing::Color::White;
			chartArea2->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea2);
			legend2->Alignment = System::Drawing::StringAlignment::Center;
			legend2->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Bottom;
			legend2->Name = L"Legend1";
			legend2->TableStyle = System::Windows::Forms::DataVisualization::Charting::LegendTableStyle::Tall;
			this->chart1->Legends->Add(legend2);
			this->chart1->Location = System::Drawing::Point(1018, 41);
			this->chart1->Name = L"chart1";
			this->chart1->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Bright;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series2->Legend = L"Legend1";
			series2->Name = L"Histogram";
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(500, 416);
			this->chart1->TabIndex = 7;
			this->chart1->Text = L"chart1";
			this->chart1->Visible = false;
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(1018, 502);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(500, 263);
			this->richTextBox1->TabIndex = 8;
			this->richTextBox1->Text = L"";
			this->richTextBox1->Visible = false;
			// 
			// trackBar1
			// 
			this->trackBar1->AccessibleDescription = L"Thereshold value bar";
			this->trackBar1->AccessibleName = L"Thereshold value bar";
			this->trackBar1->Location = System::Drawing::Point(12, 755);
			this->trackBar1->Maximum = 255;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(416, 56);
			this->trackBar1->TabIndex = 9;
			this->trackBar1->Value = 135;
			this->trackBar1->Visible = false;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &IP_Form::trackBar1_Scroll);
			// 
			// pictureBox4
			// 
			this->pictureBox4->Location = System::Drawing::Point(502, 388);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(400, 300);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 10;
			this->pictureBox4->TabStop = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::Color::MidnightBlue;
			this->label4->Location = System::Drawing::Point(641, 691);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(138, 25);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Smooth Image";
			this->label4->Visible = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(718, 557);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(121, 33);
			this->button1->TabIndex = 16;
			this->button1->Text = L"TAMAM";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &IP_Form::button1_Click);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"3", L"5", L"7" });
			this->comboBox2->Location = System::Drawing::Point(718, 505);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 33);
			this->comboBox2->TabIndex = 15;
			this->comboBox2->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label5->Location = System::Drawing::Point(550, 505);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(162, 28);
			this->label5->TabIndex = 14;
			this->label5->Text = L"ﬁablon Boyutu : ";
			this->label5->Visible = false;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(718, 468);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 33);
			this->comboBox1->TabIndex = 13;
			this->comboBox1->Visible = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label6->Location = System::Drawing::Point(550, 464);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(83, 28);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Resim : ";
			this->label6->Visible = false;
			// 
			// IP_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(1540, 845);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->ForeColor = System::Drawing::Color::MidnightBlue;
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"IP_Form";
			this->Text = L"IP_Form";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		public:
			IP_Form(void)
			{
				InitializeComponent();
				//
				//TODO: Add the constructor code here
				//
			}


			BYTE *imageBuffer, *grayscaleImageBuffer;
			int Height, Width;
			long size;
			Bitmap^ grayscaleImage, ^binaryImage, ^smoothImage;

			




		//OPEN IMAGE
		private: System::Void openImageToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		
			//delete[] imageBuffer;
			CString str;
			//Open BMP image
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				str = openFileDialog1->FileName;
				LPCTSTR input = (LPCTSTR)str;
			
				//BMP image reading
				imageBuffer = LoadBMP(Width, Height, size, input);
			
				pictureBox1->ImageLocation = openFileDialog1->FileName;
				label1->Visible = TRUE;
			
				richTextBox1->Text = "Image_PATH : " + openFileDialog1->FileName;
				richTextBox1->AppendText("\nImage opened.");
				richTextBox1->Visible = TRUE;
			}

		
		}//OPEN IMAGE

		//CONVERT TO GRAYSCALE
		private: System::Void grayscaleImageToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		
			//Convert to intensity from bmp
			grayscaleImageBuffer = ConvertBMPToIntensity(imageBuffer, Width, Height);
			grayscaleImage = gcnew Bitmap(Width, Height);

			Color c;
			for (int row = 0; row < Height; row++)
				for (int col = 0; col < Width; col++)
				{
					c = Color::FromArgb(*(grayscaleImageBuffer + row * Width + col), *(grayscaleImageBuffer + row * Width + col), *(grayscaleImageBuffer + row * Width + col));
					grayscaleImage->SetPixel(col, row, c);
				}

			pictureBox2->Image = grayscaleImage;
			this->comboBox1->Items->Add("grayscaleImage");
			label2->Visible = TRUE;
			richTextBox1->AppendText("\nImage converted to grayscale.");
		}//CONVERT TO GRAYSCALE

		//EXIT
		private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			delete[] imageBuffer;
			delete[] grayscaleImageBuffer;
			delete[] grayscaleImage;
			exit(0);
		}//EXIT

		//CLOSE IMAGE
		private: System::Void closeImageToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			delete[] imageBuffer;
			delete[] grayscaleImageBuffer;
			delete[] grayscaleImage;
			chart1->Series->Clear();

		}//CLOSE IMAGE



		//CONVERT BINARY IMAGE
		private: System::Void binaryImageToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			
			binaryImage = gcnew Bitmap(Width, Height);
			pictureBox3->Image = binaryImage;

			this->trackBar1->Visible = TRUE;

			toBinaryImage(binaryImage, grayscaleImage, 135);

			label3->Visible = TRUE;
			this->comboBox1->Items->Add("binaryImage");
			richTextBox1->AppendText("\nConverted to binary image with thereshold value : 135");
	
		}//CONVERT BINARY IMAGE



		//TRACKBAR SCROLL
		private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
			int thresholdValue = this->trackBar1->Value;
			toBinaryImage(binaryImage, grayscaleImage, thresholdValue);
			pictureBox3->Image = binaryImage;

			richTextBox1->AppendText("\nConverted to binary image with thereshold value : " + this->trackBar1->Value);
		}//TRACKBAR SCROLL


		
		//EXTRACT TO ORIGINAL IMAGE HISTOGRAM
		private: System::Void originalImageHistogramToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			double* histogram;
			histogram = extractHistogram(imageBuffer, Width, Height);

			chart1->Series->Add("Original Image Histogram");
			for (int i = 0; i < 256; i++)
				chart1->Series["Original Image Histogram"]->Points->AddXY(i, histogram[i]);
			chart1->Visible = TRUE;

			richTextBox1->AppendText("\nExtract to original image histogram.");
		}//EXTRACT TO ORIGINAL IMAGE HISTOGRAM



		//EXTRACT TO GRAYSCALE IMAGE HISTOGRAM
		private: System::Void grayscaleImageHistogramToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			double* histogram;
			histogram = extractHistogram(grayscaleImageBuffer, Width, Height);

			chart1->Series->Add("Grayscale Histogram");
			for (int i = 0; i < 256; i++)
				chart1->Series["Grayscale Histogram"]->Points->AddXY(i, histogram[i]);
			chart1->Visible = TRUE;

			richTextBox1->AppendText("\nExtract to grayscale image histogram.");
		}//EXTRACT TO GRAYSCALE IMAGE HISTOGRAM

		
		//EXTRACT TO BINARY IMAGE HISTOGRAM
		private: System::Void binaryImageHistogramToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			double* histogram = new double[255]();
			histogram = extractHistogram(binaryImage, Width, Height, histogram);

			try {
				chart1->Series->Add("Binary Histogram");
			}
			catch (const char e)
			{
				richTextBox1->AppendText("Hata olu˛tu." + e);

			}
			
			for (int i = 0; i < 256; i++)
				chart1->Series["Binary Histogram"]->Points->AddXY(i, histogram[i]);
			chart1->Visible = TRUE;

			richTextBox1->AppendText("\nExtract to binary image histogram.");
		}//EXTRACT TO BINARY IMAGE HISTOGRAM

		
		//SET MEAN FILTERING
		private: System::Void meanFilteringToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			this->pictureBox4->Visible = FALSE;
			this->label4->Visible = FALSE;

			this->label5->Visible = TRUE;
			this->label6->Visible = TRUE;
			this->comboBox1->Visible = TRUE;
			this->comboBox2->Visible = TRUE;
			this->button1->Visible = TRUE;

		}//SET MEAN FILTERING


		//EXECUTE MEAN FILTERING
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			int strElSize = Convert::ToInt32(comboBox2->SelectedItem->ToString());
			String^ selectedImage = comboBox1->SelectedItem->ToString();

			if (selectedImage == "grayscaleImage")
				smoothImage = meanFilter(grayscaleImage, strElSize);
			else if (selectedImage == "smoothImage")
				smoothImage = meanFilter(smoothImage, strElSize);
			else if (selectedImage == "binaryImage")
				smoothImage = meanFilter(binaryImage, strElSize);
			else 
			{richTextBox1->AppendText("\nWrong Input."); return;}

			this->pictureBox4->Image = smoothImage;
			this->pictureBox4->Visible = TRUE;
			this->label4->Visible = TRUE;

			this->label5->Visible = FALSE;
			this->label6->Visible = FALSE;
			this->comboBox1->Visible = FALSE;
			this->comboBox2->Visible = FALSE;
			this->button1->Visible = FALSE;
			richTextBox1->AppendText("\nSmoothing image.");
			this->comboBox1->Items->Add("smoothImage");

		}//EXECUTE MEAN FILTERING
};
}
