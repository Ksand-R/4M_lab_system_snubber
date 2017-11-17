#pragma once
#include "Compute.h"
#include "row_table.h"
#include "RefForm.h"
#include "TableForm.h"

namespace My4M_lab_2 {
	
	struct params {
		double m;
		double c;
		double k;

		//params(double _m, double _c, double _k) :
		//	m(_m), c(_c), k(_k) {};

	};

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	//public: Table* table;
			
	private:
		double len, _step, eps_edge, eps, m, c, k, u0, du0;
		int max_steps;
	
	private: System::Windows::Forms::ComboBox^  comboBox1;

	private: params* _par;

	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Label^  label23;

	private: int _NSeries;

	public:
		MainForm(void)
		{
			_par = new params();

			InitializeComponent();

			this->comboBox1->SelectedIndex = 0;
			_NSeries = 0;
			//table = 0;

		}
		
	protected: 
		void SetTable(Table& t) {
		t.Clear();

		Row row;
	}

		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete _par;
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label16;
	protected:



	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::TextBox^  textBox5;

	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  main_labelParameters;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::TextBox^  textBox10;

	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->main_labelParameters = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label16->Location = System::Drawing::Point(581, 33);
			this->label16->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(79, 28);
			this->label16->TabIndex = 85;
			this->label16->Text = L"Task:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(192, 156);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(39, 17);
			this->label12->TabIndex = 81;
			this->label12->Text = L"u\'0 =";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(236, 151);
			this->textBox5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(168, 22);
			this->textBox5->TabIndex = 80;
			this->textBox5->Text = L"0";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(191, 103);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(37, 18);
			this->label10->TabIndex = 78;
			this->label10->Text = L"u0 =";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(236, 100);
			this->textBox4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(168, 22);
			this->textBox4->TabIndex = 77;
			this->textBox4->Text = L"1";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(45, 156);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(54, 17);
			this->label7->TabIndex = 76;
			this->label7->Text = L"Rigidity";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(12, 185);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(27, 17);
			this->label8->TabIndex = 75;
			this->label8->Text = L"k =";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(48, 176);
			this->textBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(115, 22);
			this->textBox3->TabIndex = 74;
			this->textBox3->Text = L"1";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(45, 103);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(62, 17);
			this->label5->TabIndex = 73;
			this->label5->Text = L"Snubber";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 129);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(27, 17);
			this->label6->TabIndex = 72;
			this->label6->Text = L"c =";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(48, 123);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(115, 22);
			this->textBox2->TabIndex = 71;
			this->textBox2->Text = L"1";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(45, 57);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(41, 17);
			this->label3->TabIndex = 70;
			this->label3->Text = L"Mass";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 81);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(31, 17);
			this->label1->TabIndex = 69;
			this->label1->Text = L"m =";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(48, 76);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(115, 22);
			this->textBox1->TabIndex = 68;
			this->textBox1->Text = L"1";
			// 
			// main_labelParameters
			// 
			this->main_labelParameters->AutoSize = true;
			this->main_labelParameters->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->main_labelParameters->Location = System::Drawing::Point(16, 33);
			this->main_labelParameters->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->main_labelParameters->Name = L"main_labelParameters";
			this->main_labelParameters->Size = System::Drawing::Size(156, 20);
			this->main_labelParameters->TabIndex = 67;
			this->main_labelParameters->Text = L"Task parameters:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(871, 59);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(101, 17);
			this->label2->TabIndex = 88;
			this->label2->Text = L"Interval length:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(840, 84);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(29, 17);
			this->label4->TabIndex = 87;
			this->label4->Text = L"X =";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(875, 79);
			this->textBox6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(168, 22);
			this->textBox6->TabIndex = 86;
			this->textBox6->Text = L"12";
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox6_TextChanged);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(871, 112);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(110, 17);
			this->label14->TabIndex = 91;
			this->label14->Text = L"Integration step:";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(840, 137);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(28, 17);
			this->label17->TabIndex = 90;
			this->label17->Text = L"h =";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(875, 132);
			this->textBox7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(168, 22);
			this->textBox7->TabIndex = 89;
			this->textBox7->Text = L"0,001";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(871, 159);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(115, 17);
			this->label18->TabIndex = 94;
			this->label18->Text = L"border accuracy:";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(840, 185);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(28, 17);
			this->label19->TabIndex = 93;
			this->label19->Text = L"e =";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(875, 178);
			this->textBox8->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(168, 22);
			this->textBox8->TabIndex = 92;
			this->textBox8->Text = L"0,0001";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(1093, 112);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(128, 17);
			this->label20->TabIndex = 100;
			this->label20->Text = L"Local error control:";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(1096, 79);
			this->textBox9->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(168, 22);
			this->textBox9->TabIndex = 98;
			this->textBox9->Text = L"10000";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(1093, 59);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(150, 17);
			this->label22->TabIndex = 97;
			this->label22->Text = L"Max amounth of steps:";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(1096, 130);
			this->textBox10->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(168, 22);
			this->textBox10->TabIndex = 95;
			this->textBox10->Text = L"0,0000001";
			this->textBox10->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox10_TextChanged);
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(1093, 161);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(59, 17);
			this->label24->TabIndex = 102;
			this->label24->Text = L"Method:";
			// 
			// chart1
			// 
			chartArea4->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea4);
			legend4->Name = L"Legend1";
			this->chart1->Legends->Add(legend4);
			this->chart1->Location = System::Drawing::Point(417, 212);
			this->chart1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->chart1->Name = L"chart1";
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series4->Legend = L"Legend1";
			series4->Name = L"Series1";
			this->chart1->Series->Add(series4);
			this->chart1->Size = System::Drawing::Size(939, 498);
			this->chart1->TabIndex = 103;
			this->chart1->Text = L"chart1";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(48, 325);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(343, 47);
			this->button1->TabIndex = 104;
			this->button1->Text = L"Solve";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(48, 391);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(343, 47);
			this->button2->TabIndex = 105;
			this->button2->Text = L"Clear";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(48, 526);
			this->button3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(343, 47);
			this->button3->TabIndex = 107;
			this->button3->Text = L"Reference";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(48, 459);
			this->button4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(343, 47);
			this->button4->TabIndex = 106;
			this->button4->Text = L"Table";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MainForm::button4_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"RK4" });
			this->comboBox1->Location = System::Drawing::Point(1096, 181);
			this->comboBox1->Margin = System::Windows::Forms::Padding(4);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(215, 24);
			this->comboBox1->TabIndex = 108;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label13->Location = System::Drawing::Point(464, 74);
			this->label13->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(296, 39);
			this->label13->TabIndex = 109;
			this->label13->Text = L"m u\'\' + cu\' + ku =0;";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label15->Location = System::Drawing::Point(484, 112);
			this->label15->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(249, 29);
			this->label15->TabIndex = 110;
			this->label15->Text = L"u(x0) = u0 ; u\'(x0) = u\'0";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label21->Location = System::Drawing::Point(233, 33);
			this->label21->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(148, 20);
			this->label21->TabIndex = 111;
			this->label21->Text = L"Start conditions:";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label23->Location = System::Drawing::Point(960, 33);
			this->label23->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(183, 20);
			this->label23->TabIndex = 112;
			this->label23->Text = L"Method  parameters:";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1803, 730);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->textBox10);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->main_labelParameters);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MainForm";
			this->Text = L"Diff_eq_2_deg";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

	m = Convert::ToDouble(textBox1->Text);
	c = Convert::ToDouble(textBox2->Text);
	k = Convert::ToDouble(textBox3->Text);
	u0 = Convert::ToDouble(textBox4->Text);
	du0 = Convert::ToDouble(textBox5->Text);

	len = Convert::ToDouble(textBox6->Text);
	_step = Convert::ToDouble(textBox7->Text);
	eps_edge = Convert::ToDouble(textBox8->Text);
	max_steps = Convert::ToDouble(textBox9->Text);
	eps = Convert::ToDouble(textBox10->Text);
	
	Table* table = new Table();

	Integrate(RK_4, diff_eq, 0, len, u0, du0, max_steps, _step,
		eps, table, 4, m, c, k);

	const int n = (--table->end())->i + 1;
	array<double^>^ x = gcnew array<double^>(n);
	array<double^>^ y = gcnew array<double^>(n);
	int i = 0;

	DataVisualization::Charting::Series^ s = gcnew DataVisualization::
		Charting::Series;
	chart1->Series->Add(s);
	s->BorderWidth = 2;
	s->ChartType = System::Windows::Forms::DataVisualization
		::Charting::SeriesChartType::Line;

	interior_ptr<int> NSeries = &_NSeries;


	for (auto it = table->begin(); it != table->end(); it++, i++) {
		x[i] = gcnew double;
		y[i] = gcnew double;
		x[i] = it->xi;
		y[i] = it->vi_itog;

		chart1->Series[*NSeries]->Points->AddXY(x[i], y[i]);
	}
	(*NSeries)++;

	std::ofstream f;
	f.open("./log.txt");
	f << (*table);
	f.close();

	delete table;
	table = 0;


}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		const char* str =  "./log.txt";
		int p = 4;
		
		RefForm^ refForm = gcnew RefForm(str, 1, len, eps_edge, eps, max_steps, p, _step);
		refForm->Show();
}


private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	const char* str = "./log.txt";
	TableForm^ tableForm = gcnew TableForm(1, str);
	tableForm->Show();

}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

	for (int i = 0; i < _NSeries; i++) chart1->Series[i]->Points->Clear();
	_NSeries = 0;
	
}
private: System::Void label9_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox6_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox10_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}


