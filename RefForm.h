#pragma once
#include "row_table.h"
#include <cmath>

namespace My4M_lab_2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для RefForm
	/// </summary>
	public ref class RefForm : public System::Windows::Forms::Form
	{
	public:
		RefForm(const char * str, int task, double X, double maxL, double eps, int N, int p, double h0)
		{
			InitializeComponent();

			std::ifstream f;
			f.open(str);
			Table table;
			f >> table;
			f.close();

this->labelP->Text = L" method order = " + p.ToString();
this->labelX0->Text = L" x0 = " + table.begin()->xi.ToString() + L", len = " + X.ToString();
this->labelH0->Text = L"h0 = " + h0.ToString() + L", local error = " + maxL.ToString();
this->label1->Text = L"max amount of steps = " + N.ToString();
this->label2->Text = L"border control = " + eps.ToString();
this->labelUdv->Text = L"step increace = " + findUdv(table).ToString() + L", step decreace =" + findDel(table).ToString();
this->labelBoard->Text = L"amount of steps = " + findN(table).ToString();
this->labelMaxL->Text = L"Max|S|=" + findMaxS(table).ToString() + L" при x=" + findMaxSX(table).ToString();
this->labelMinL->Text = L"Min|S|=" + findMinS(table).ToString() + L" при x=" + findMinSX(table).ToString();
this->labelMaxh->Text = L"Max h[i]=" + findHMax(table).ToString() + L" при x[i+1]=" + findHMaxX(table).ToString();
this->labelMinh->Text = L"Min h[i]=" + findHMin(table).ToString() + L" при x[i+1]=" + findHMinX(table).ToString();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~RefForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  labelBoard;
	protected:



	private: System::Windows::Forms::Label^  labelMaxL;
	private: System::Windows::Forms::Label^  labelMaxh;
	private: System::Windows::Forms::Label^  labelMinh;
	private: System::Windows::Forms::Label^  labelP;



	private: System::Windows::Forms::Label^  labelX0;
	private: System::Windows::Forms::Label^  labelH0;
	private: System::Windows::Forms::Label^  labelMinL;
	private: System::Windows::Forms::Label^  labelUdv;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;






	protected:

	protected:




	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent()
		{
			this->labelBoard = (gcnew System::Windows::Forms::Label());
			this->labelMaxL = (gcnew System::Windows::Forms::Label());
			this->labelMaxh = (gcnew System::Windows::Forms::Label());
			this->labelMinh = (gcnew System::Windows::Forms::Label());
			this->labelP = (gcnew System::Windows::Forms::Label());
			this->labelX0 = (gcnew System::Windows::Forms::Label());
			this->labelH0 = (gcnew System::Windows::Forms::Label());
			this->labelMinL = (gcnew System::Windows::Forms::Label());
			this->labelUdv = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// labelBoard
			// 
			this->labelBoard->AutoSize = true;
			this->labelBoard->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelBoard->Location = System::Drawing::Point(61, 217);
			this->labelBoard->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelBoard->Name = L"labelBoard";
			this->labelBoard->Size = System::Drawing::Size(164, 20);
			this->labelBoard->TabIndex = 0;
			this->labelBoard->Text = L"Выход на границу:";
			// 
			// labelMaxL
			// 
			this->labelMaxL->AutoSize = true;
			this->labelMaxL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelMaxL->Location = System::Drawing::Point(61, 254);
			this->labelMaxL->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelMaxL->Name = L"labelMaxL";
			this->labelMaxL->Size = System::Drawing::Size(297, 20);
			this->labelMaxL->TabIndex = 0;
			this->labelMaxL->Text = L"Максимальная лок. погрешность: ";
			// 
			// labelMaxh
			// 
			this->labelMaxh->AutoSize = true;
			this->labelMaxh->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelMaxh->Location = System::Drawing::Point(61, 365);
			this->labelMaxh->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelMaxh->Name = L"labelMaxh";
			this->labelMaxh->Size = System::Drawing::Size(177, 20);
			this->labelMaxh->TabIndex = 0;
			this->labelMaxh->Text = L"Максимальный шаг:";
			// 
			// labelMinh
			// 
			this->labelMinh->AutoSize = true;
			this->labelMinh->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelMinh->Location = System::Drawing::Point(61, 402);
			this->labelMinh->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelMinh->Name = L"labelMinh";
			this->labelMinh->Size = System::Drawing::Size(169, 20);
			this->labelMinh->TabIndex = 0;
			this->labelMinh->Text = L"Минимальный шаг:";
			// 
			// labelP
			// 
			this->labelP->AutoSize = true;
			this->labelP->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelP->Location = System::Drawing::Point(61, 49);
			this->labelP->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelP->Name = L"labelP";
			this->labelP->Size = System::Drawing::Size(157, 20);
			this->labelP->TabIndex = 1;
			this->labelP->Text = L"Порядок метода:";
			// 
			// labelX0
			// 
			this->labelX0->AutoSize = true;
			this->labelX0->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelX0->Location = System::Drawing::Point(61, 86);
			this->labelX0->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelX0->Name = L"labelX0";
			this->labelX0->Size = System::Drawing::Size(74, 20);
			this->labelX0->TabIndex = 1;
			this->labelX0->Text = L"x0= u0= ";
			// 
			// labelH0
			// 
			this->labelH0->AutoSize = true;
			this->labelH0->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelH0->Location = System::Drawing::Point(61, 123);
			this->labelH0->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelH0->Name = L"labelH0";
			this->labelH0->Size = System::Drawing::Size(42, 20);
			this->labelH0->TabIndex = 1;
			this->labelH0->Text = L"h0= ";
			// 
			// labelMinL
			// 
			this->labelMinL->AutoSize = true;
			this->labelMinL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelMinL->Location = System::Drawing::Point(61, 291);
			this->labelMinL->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelMinL->Name = L"labelMinL";
			this->labelMinL->Size = System::Drawing::Size(289, 20);
			this->labelMinL->TabIndex = 0;
			this->labelMinL->Text = L"Минимальная лок. погрешность: ";
			// 
			// labelUdv
			// 
			this->labelUdv->AutoSize = true;
			this->labelUdv->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelUdv->Location = System::Drawing::Point(61, 328);
			this->labelUdv->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelUdv->Name = L"labelUdv";
			this->labelUdv->Size = System::Drawing::Size(221, 20);
			this->labelUdv->TabIndex = 0;
			this->labelUdv->Text = L"Число увеличений шага: ";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->labelUdv->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(62, 157);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Maxst";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->labelUdv->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(62, 187);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"border";
			// 
			// RefForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(383, 513);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->labelH0);
			this->Controls->Add(this->labelX0);
			this->Controls->Add(this->labelP);
			this->Controls->Add(this->labelMinL);
			this->Controls->Add(this->labelMaxL);
			this->Controls->Add(this->labelMaxh);
			this->Controls->Add(this->labelMinh);
			this->Controls->Add(this->labelUdv);
			this->Controls->Add(this->labelBoard);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"RefForm";
			this->Text = L"Reference";
			this->Load += gcnew System::EventHandler(this, &RefForm::RefForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void RefForm_Load(System::Object^  sender, System::EventArgs^  e) {}

	private: int findN(Table&t) {
		return (--t.end())->i;
	}

	private: double findBoard(Table&t, double b) {
		return abs(b - (--t.end())->xi);
	}

	private: double findMaxS(Table&t) {
		double s = (++t.begin())->s;
		for (auto it = ++t.begin(); it != t.end(); it++)
			if (abs(it->s) > abs(s)) {
				s = it->s;
			}
		return abs(s);
	}
	private: double findMaxSX(Table&t) {
		double s = (++t.begin())->s;
		double x = (++t.begin())->xi;
		for (auto it = ++t.begin(); it != t.end(); it++)
			if (abs(it->s) > abs(s)) {
				s = it->s;
				x = it->xi;
			}
		return x;
	}

	private: double findMinS(Table&t) {
		double s = (++t.begin())->s;
		for (auto it = ++t.begin(); it != t.end(); it++)
			if (abs(it->s) < abs(s)) {
				s = it->s;
			}
		return abs(s);
	}
	private: double findMinSX(Table&t) {
		double s = (++t.begin())->s;
		double x = (++t.begin())->xi;
		for (auto it = ++t.begin(); it != t.end(); it++)
			if (abs(it->s) < abs(s)) {
				s = it->s;
				x = it->xi;
			}
		return x;
	}

	private: int findUdv(Table&t) {
		int n = 0;
		for (auto it = t.begin(); it != t.end(); it++)
			n += it->stepInc;
		return n;
	}

	private: int findDel(Table&t) {
		int n = 0;
		for (auto it = t.begin(); it != t.end(); it++)
			n += it->stepDec;
		return n;
	}

	private: double findHMax(Table&t) {
		double h = (++t.begin())->hi_1;
		for (auto it = ++t.begin(); it != t.end(); it++)
			if (it->hi_1 > h) {
				h = it->hi_1;
			}
		return h;
	}
	private: double findHMaxX(Table&t) {
		double h = (++t.begin())->hi_1;
		double x = (++t.begin())->xi;
		for (auto it = ++t.begin(); it != t.end(); it++)
			if (it->hi_1 > h) {
				h = it->hi_1;
				x = it->xi;
			}
		return x;
	}

	private: double findHMin(Table&t) {
		double h = (++t.begin())->hi_1;
		for (auto it = ++t.begin(); it != t.end(); it++)
			if (it->hi_1 < h) {
				h = it->hi_1;
			}
		return h;
	}
	private: double findHMinX(Table&t) {
		double h = (++t.begin())->hi_1;
		double x = (++t.begin())->xi;
		for (auto it = ++t.begin(); it != t.end(); it++)
			if (it->hi_1 < h) {
				h = it->hi_1;
				x = it->xi;
			}
		return x;
	}



	};
}
