#pragma once
#include "row_table.h"

namespace My4M_lab_2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	
	/// </summary>
	public ref class TableForm : public System::Windows::Forms::Form
	{

		int Task;
	public:
		TableForm(int task, const char* str)
		{
			Task = task;
			InitializeComponent();

			std::ifstream f;
			f.open(str);
			Table table;
			f >> table;
			f.close();

			ShowTable(table);
		}

	protected:
		/// <summary>
		/// </summary>
		~TableForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::DataGridView^  dataGridView1;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  i;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  hi_1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  xi;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  viPr;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  viKor;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  viPr_viKor;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  s;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  viUtoch;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  viItog;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  stepDec;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  stepInc;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->i = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->hi_1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->xi = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->viPr = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->viKor = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->viPr_viKor = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->s = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->viUtoch = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->viItog = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->stepDec = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->stepInc = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = 
				System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;

				this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >{
					this->i, this->hi_1,
						this->xi, this->viPr, this->viKor, this->viPr_viKor, this->s, this->viUtoch, this->viItog, this->stepDec, this->stepInc,
				});
			//}
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(691, 520);
			this->dataGridView1->TabIndex = 0;
			// 
			// i
			// 
			this->i->HeaderText = L"i";
			this->i->Name = L"i";
			this->i->ReadOnly = true;
			// 
			// hi_1
			// 
			this->hi_1->HeaderText = L"h[i-1]";
			this->hi_1->Name = L"hi_1";
			this->hi_1->ReadOnly = true;
			// 
			// xi
			// 
			this->xi->HeaderText = L"x[i]";
			this->xi->Name = L"xi";
			this->xi->ReadOnly = true;
			// 
			// viPr
			// 
			this->viPr->HeaderText = L"V[i]";
			this->viPr->Name = L"viPr";
			this->viPr->ReadOnly = true;
			// 
			// viKor
			// 
			this->viKor->HeaderText = L"Vudv[i]";
			this->viKor->Name = L"viKor";
			this->viKor->ReadOnly = true;
			// 
			// viPr_viKor
			// 
			this->viPr_viKor->HeaderText = L"V[i]-Vudv[i]";
			this->viPr_viKor->Name = L"viPr_viKor";
			this->viPr_viKor->ReadOnly = true;
			// 
			// s
			// 
			this->s->HeaderText = L"S";
			this->s->Name = L"s";
			this->s->ReadOnly = true;
			// 
			// viUtoch
			// 
			this->viUtoch->HeaderText = L"Vutoch[i]";
			this->viUtoch->Name = L"viUtoch";
			this->viUtoch->ReadOnly = true;
			// 
			// viItog
			// 
			this->viItog->HeaderText = L"Vitog[i]";
			this->viItog->Name = L"viItog";
			this->viItog->ReadOnly = true;
			// 
			// stepDec
			// 
			this->stepDec->HeaderText = L"dec_step";
			this->stepDec->Name = L"stepDec";
			this->stepDec->ReadOnly = true;
			// 
			// stepInc
			// 
			this->stepInc->HeaderText = L"inc_step";
			this->stepInc->Name = L"stepInc";
			this->stepInc->ReadOnly = true;
			// 
			// TableForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(691, 520);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"TableForm";
			this->Text = L"Table";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion


	protected: void ShowTable(Table& table) {
		int i = 0;
		for (auto it = table.begin(); it != table.end(); it++, i++) 
		{
			this->dataGridView1->Rows->Add();
			this->dataGridView1->Rows[i]->Cells[0]->Value = it->i;
			this->dataGridView1->Rows[i]->Cells[1]->Value = it->hi_1;
			this->dataGridView1->Rows[i]->Cells[2]->Value = it->xi;
			this->dataGridView1->Rows[i]->Cells[3]->Value = it->vi_pr;
			this->dataGridView1->Rows[i]->Cells[4]->Value = it->vi_cor;
			this->dataGridView1->Rows[i]->Cells[5]->Value = it->viPr_vi_ñor;
			this->dataGridView1->Rows[i]->Cells[6]->Value = it->s;
			this->dataGridView1->Rows[i]->Cells[7]->Value = it->vi_utoch;
			this->dataGridView1->Rows[i]->Cells[8]->Value = it->vi_itog;
			this->dataGridView1->Rows[i]->Cells[9]->Value = it->stepDec;
			this->dataGridView1->Rows[i]->Cells[10]->Value = it->stepInc;

		}
	}

	};
}
