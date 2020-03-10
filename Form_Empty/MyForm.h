#pragma once
#include <Windows.h>
#include <atlstr.h>
#include"imge_bmp.h"

namespace Form_Empty {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

		LPCTSTR input, output;
		int Width, Height;
		long Size, new_size;
		double* histogram = new double[256];
		BYTE* buffer;
		Bitmap^ binarySurface;




	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::ToolStripMenuItem^ toolsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ drawCircleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ drawEllipseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ drawRectangleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ analyzeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ calculateHistogramToolStripMenuItem;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart2;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::ToolStripMenuItem^ conversionToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ toBinaryImageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ toGrayImageToolStripMenuItem;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::ToolStripMenuItem^ thresholdingToolStripMenuItem;
		   
		

	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;


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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea5 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea6 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->drawCircleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->drawEllipseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->drawRectangleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->analyzeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->calculateHistogramToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->thresholdingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->conversionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toGrayImageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toBinaryImageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::Gray;
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->fileToolStripMenuItem,
					this->toolsToolStripMenuItem, this->analyzeToolStripMenuItem, this->conversionToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1904, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->openToolStripMenuItem });
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(42, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(109, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
			// 
			// toolsToolStripMenuItem
			// 
			this->toolsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->drawCircleToolStripMenuItem,
					this->drawEllipseToolStripMenuItem, this->drawRectangleToolStripMenuItem
			});
			this->toolsToolStripMenuItem->Name = L"toolsToolStripMenuItem";
			this->toolsToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->toolsToolStripMenuItem->Text = L"Tools";
			// 
			// drawCircleToolStripMenuItem
			// 
			this->drawCircleToolStripMenuItem->Name = L"drawCircleToolStripMenuItem";
			this->drawCircleToolStripMenuItem->Size = System::Drawing::Size(168, 22);
			this->drawCircleToolStripMenuItem->Text = L"DrawCircle";
			this->drawCircleToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::drawCircleToolStripMenuItem_Click);
			// 
			// drawEllipseToolStripMenuItem
			// 
			this->drawEllipseToolStripMenuItem->Name = L"drawEllipseToolStripMenuItem";
			this->drawEllipseToolStripMenuItem->Size = System::Drawing::Size(168, 22);
			this->drawEllipseToolStripMenuItem->Text = L"DrawEllipse";
			this->drawEllipseToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::drawEllipseToolStripMenuItem_Click);
			// 
			// drawRectangleToolStripMenuItem
			// 
			this->drawRectangleToolStripMenuItem->Name = L"drawRectangleToolStripMenuItem";
			this->drawRectangleToolStripMenuItem->Size = System::Drawing::Size(168, 22);
			this->drawRectangleToolStripMenuItem->Text = L"DrawRectangle";
			this->drawRectangleToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::drawRectangleToolStripMenuItem_Click);
			// 
			// analyzeToolStripMenuItem
			// 
			this->analyzeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->calculateHistogramToolStripMenuItem,
					this->thresholdingToolStripMenuItem
			});
			this->analyzeToolStripMenuItem->Name = L"analyzeToolStripMenuItem";
			this->analyzeToolStripMenuItem->Size = System::Drawing::Size(68, 20);
			this->analyzeToolStripMenuItem->Text = L"Analyze";
			// 
			// calculateHistogramToolStripMenuItem
			// 
			this->calculateHistogramToolStripMenuItem->Name = L"calculateHistogramToolStripMenuItem";
			this->calculateHistogramToolStripMenuItem->Size = System::Drawing::Size(203, 22);
			this->calculateHistogramToolStripMenuItem->Text = L"Calculate Histogram";
			this->calculateHistogramToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::calculateHistogramToolStripMenuItem_Click);
			// 
			// thresholdingToolStripMenuItem
			// 
			this->thresholdingToolStripMenuItem->Name = L"thresholdingToolStripMenuItem";
			this->thresholdingToolStripMenuItem->Size = System::Drawing::Size(203, 22);
			this->thresholdingToolStripMenuItem->Text = L"Thresholding";
			this->thresholdingToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::thresholdingToolStripMenuItem_Click);
			// 
			// conversionToolStripMenuItem
			// 
			this->conversionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toGrayImageToolStripMenuItem,
					this->toBinaryImageToolStripMenuItem
			});
			this->conversionToolStripMenuItem->Name = L"conversionToolStripMenuItem";
			this->conversionToolStripMenuItem->Size = System::Drawing::Size(90, 20);
			this->conversionToolStripMenuItem->Text = L"Conversion";
			// 
			// toGrayImageToolStripMenuItem
			// 
			this->toGrayImageToolStripMenuItem->Name = L"toGrayImageToolStripMenuItem";
			this->toGrayImageToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->toGrayImageToolStripMenuItem->Text = L"To Gray Image";
			this->toGrayImageToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::toGrayImageToolStripMenuItem_Click_1);
			// 
			// toBinaryImageToolStripMenuItem
			// 
			this->toBinaryImageToolStripMenuItem->Name = L"toBinaryImageToolStripMenuItem";
			this->toBinaryImageToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->toBinaryImageToolStripMenuItem->Text = L"To Binary Image";
			this->toBinaryImageToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::toBinaryImageToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(21, 42);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(512, 288);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// chart1
			// 
			this->chart1->BackColor = System::Drawing::Color::Gray;
			this->chart1->BorderlineColor = System::Drawing::Color::Silver;
			chartArea5->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea5);
			legend5->Name = L"Legend1";
			this->chart1->Legends->Add(legend5);
			this->chart1->Location = System::Drawing::Point(1450, 27);
			this->chart1->Name = L"chart1";
			this->chart1->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::SeaGreen;
			series5->ChartArea = L"ChartArea1";
			series5->Legend = L"Legend1";
			series5->Name = L"Values";
			this->chart1->Series->Add(series5);
			this->chart1->Size = System::Drawing::Size(442, 315);
			this->chart1->TabIndex = 3;
			this->chart1->Text = L"si";
			this->chart1->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1447, 695);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 20);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Weight : ";
			this->label1->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(1447, 722);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(64, 20);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Mean : ";
			this->label2->Visible = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(1447, 751);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(88, 20);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Variance : ";
			this->label3->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(1541, 695);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(42, 20);
			this->label4->TabIndex = 7;
			this->label4->Text = L"NaN";
			this->label4->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(1541, 751);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(42, 20);
			this->label5->TabIndex = 8;
			this->label5->Text = L"NaN";
			this->label5->Visible = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(1541, 722);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(42, 20);
			this->label6->TabIndex = 9;
			this->label6->Text = L"NaN";
			this->label6->Visible = false;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(18, 939);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(118, 20);
			this->label7->TabIndex = 10;
			this->label7->Text = L"Image PATH: ";
			this->label7->Visible = false;
			// 
			// chart2
			// 
			this->chart2->BackColor = System::Drawing::Color::Gray;
			chartArea6->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea6);
			legend6->Name = L"Legend1";
			this->chart2->Legends->Add(legend6);
			this->chart2->Location = System::Drawing::Point(1450, 358);
			this->chart2->Name = L"chart2";
			series6->ChartArea = L"ChartArea1";
			series6->Legend = L"Legend1";
			series6->Name = L"Values";
			this->chart2->Series->Add(series6);
			this->chart2->Size = System::Drawing::Size(442, 315);
			this->chart2->TabIndex = 11;
			this->chart2->Text = L"si";
			this->chart2->Visible = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(616, 42);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(512, 288);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 12;
			this->pictureBox2->TabStop = false;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(192, 333);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(122, 20);
			this->label8->TabIndex = 13;
			this->label8->Text = L"Original Image";
			this->label8->Visible = false;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(818, 333);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(95, 20);
			this->label9->TabIndex = 14;
			this->label9->Text = L"Gray Image";
			this->label9->Visible = false;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(1601, 324);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(88, 20);
			this->label10->TabIndex = 15;
			this->label10->Text = L"Histogram";
			this->label10->Visible = false;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(1601, 655);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(107, 20);
			this->label11->TabIndex = 16;
			this->label11->Text = L"Thresholding";
			this->label11->Visible = false;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(192, 708);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(108, 20);
			this->label12->TabIndex = 18;
			this->label12->Text = L"Binary Image";
			this->label12->Visible = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(21, 417);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(512, 288);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 17;
			this->pictureBox3->TabStop = false;
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(22, 751);
			this->trackBar1->Maximum = 255;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(512, 45);
			this->trackBar1->TabIndex = 155;
			this->trackBar1->Visible = false;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(1904, 1001);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->chart2);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::Olive;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Image Processing GUI";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




	//Load Image
	private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		
		delete[] buffer;
		CString str;
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			str = openFileDialog1->FileName;
			input = (LPCTSTR)str;

			//BMP image reading
			buffer = LoadBMP(Width, Height, Size, input);

			pictureBox1->ImageLocation = openFileDialog1->FileName;
			label7->Text = (String^)(label7->Text +  openFileDialog1->FileName);
		}
		label7->Visible = TRUE;
		label8->Visible = TRUE;
	}//Load Image
	
	
	private: System::Void drawCircleToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

		DrawCircle(buffer, Width, Height);

	}//DrawCircle

	private: System::Void drawEllipseToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (MessageBox::Show("Pek yakýnda...", "DrawEllipse",
			MessageBoxButtons::OK, MessageBoxIcon::Information) == System::Windows::Forms::DialogResult::Yes)
			Application::Exit();

	}//DrawEllipse
	private: System::Void drawRectangleToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (MessageBox::Show("Pek yakýnda...", "DrawRegtangle",
			MessageBoxButtons::OK, MessageBoxIcon::Information) == System::Windows::Forms::DialogResult::Yes)
			Application::Exit();
	}//DrawRegtangle


	//Calculate Histogram
	private: System::Void calculateHistogramToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	
		histogram = Histogram(buffer, Width, Height, histogram);

		this->chart1->Series["Values"]->Points->Clear();
		for (int i = 0; i < 256; i++)
			this->chart1->Series["Values"]->Points->AddXY(i, histogram[i]);

		chart1->Visible = TRUE;
		label10->Visible = TRUE;
	}

	//Calculate Threshold
	private: System::Void thresholdingToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		
		histogram = Histogram(buffer, Width, Height, histogram);

		double weight = CalculateWeight(histogram, Width, Height);
		double mean = CalculateMean(histogram);
		double variance = CalculateVariance(mean, histogram);

		
		label4->Text = weight.ToString();
		label5->Text = mean.ToString();
		label6->Text = variance.ToString();


		label1->Visible = TRUE;
		label2->Visible = TRUE;
		label3->Visible = TRUE;
		label4->Visible = TRUE;
		label5->Visible = TRUE;
		label6->Visible = TRUE;
		label11->Visible = TRUE;


		histogram = thresholding(2500.0, histogram);
		
		this->chart2->Series["Values"]->Points->Clear();
		for (int i = 0; i < 256; i++)
			this->chart2->Series["Values"]->Points->AddXY(i, histogram[i]);
		chart2->Visible = TRUE;
		
	}

	

	private: System::Void toGrayImageToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {
		
		//Convert to intensity from bmp
		buffer = ConvertBMPToIntensity(buffer, Width, Height);

		Bitmap^ surface = gcnew Bitmap(Width, Height);
		pictureBox2->Image = surface;

		Color c;
		for (int row = 0; row < Height; row++)
			for (int col = 0; col < Width; col++)
			{
				c = Color::FromArgb(*(buffer + row * Width + col), *(buffer + row * Width + col), *(buffer + row * Width + col));
				surface->SetPixel(col, row, c);
			}

		label9->Visible = TRUE;
	}

	//Binary Image
	private: System::Void toBinaryImageToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

		binarySurface = gcnew Bitmap(Width, Height);
		pictureBox3->Image = binarySurface;

		this->trackBar1->Visible = TRUE;
		int threshold = trackBar1->Value;
				
		toBinaryImage(binarySurface, threshold);

		label12->Visible = TRUE;
	}

	private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
		int threshold = trackBar1->Value;
		binarySurface = toBinaryImage(binarySurface, threshold);
		pictureBox3->Image = binarySurface;
	}

	Bitmap^ toBinaryImage(Bitmap^ binarySurface, int threshold)
	{
		Color c;
		for (int row = 0; row < Height; row++)
			for (int col = 0; col < Width; col++)
			{
				if (*(buffer + (row * Width + col)) < threshold)
				{
					c = Color::FromArgb(0, 0, 0);
					buffer[row * Width + col] = 0;
				}
				else
				{
					c = Color::FromArgb(255, 255, 255);
					buffer[row * Width + col] = 255;
				}
				binarySurface->SetPixel(col, row, c);
			}
		return binarySurface;
	}
};
}
