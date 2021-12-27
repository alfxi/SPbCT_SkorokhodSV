#include <iostream>
#include <cstdio>
#include <ctime>
#include <string>
#include <random>
#include <fstream>
#include <algorithm>
#include <windows.h>
#include "Replace.h"
namespace Praktica {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	HANDLE Ride, write;
	HANDLE SemaF;
	string str0;
	string str[10];
	int n = 0, k = 0, m = 10;

	DWORD WINAPI Thed1proc(LPVOID I) {

		cout << "\n|| ЗАМЕНА СИМВОЛА ||\n" << endl;

		int k = (int)I;
		for (k = 0; k < 10; k++) {
			str[k] = replace_all(str[k], to_string(k), "ඞ");
			cout << "Строка " << k << ": " << str[k] << endl;
		}
		WriteFile(write, str, 100, NULL, NULL);
		ReleaseSemaphore(SemaF, 1, NULL);
		return 0;
	}

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;







	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(13, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(116, 34);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Создать файл";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(14, 14);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(115, 33);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Чтение файла";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 303);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 13);
			this->label1->TabIndex = 2;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(14, 14);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(116, 42);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Создание таблицы";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Visible = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->ColumnHeadersVisible = false;
			this->dataGridView1->Cursor = System::Windows::Forms::Cursors::Arrow;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::MenuBar;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(254)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->Location = System::Drawing::Point(14, 62);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(369, 225);
			this->dataGridView1->TabIndex = 4;
			this->dataGridView1->Visible = false;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(136, 16);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(115, 39);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Запись в файл";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Visible = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label2->Location = System::Drawing::Point(402, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 20);
			this->label2->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label3->Location = System::Drawing::Point(402, 29);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 20);
			this->label3->TabIndex = 7;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label4->Location = System::Drawing::Point(402, 42);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 20);
			this->label4->TabIndex = 8;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(308, 29);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 9;
			this->button5->Text = L"Обновить";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(14, 14);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(116, 42);
			this->button6->TabIndex = 10;
			this->button6->Text = L"Замена символов";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Visible = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->button7->Location = System::Drawing::Point(405, 62);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(260, 225);
			this->button7->TabIndex = 11;
			this->button7->Text = L"ВЫХОД";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Visible = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(688, 339);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		label2->Text = "Скороход С.В. г.500";
		DateTime datetime = DateTime::Now;
		this->label3->Text = "Дата: " + datetime.ToString();
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {

		label2->Text = "Скороход С.В. г.500";
		DateTime datetime = DateTime::Now;
		this->label3->Text = "Дата: " + datetime.ToString();

	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		int A[100];
		char buf;

		srand(time(0));
		ofstream F1("File1.txt");
		for (int i = 0; i < 100; i++) {
			A[i] = rand() % 10;
			F1 << A[i];
		}
		F1.close();
		button2->Visible = true;
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		label1->Text = " ";
		ifstream F1("File1.txt");
		char C[100];
		if (F1.is_open()) {
			getline(F1, str0);
			F1.close();
		}
		else label1->Text = "Не удалось открыть";
		ifstream F2("File1.txt");
		if (F2.is_open()) {
			label1->Text += "В файле: ";
			for (int i = 0; i < 100; i++) {
				F2.get(C[i]);
				label1->Text += ((wchar_t)C[i]).ToString();
			}
		}
		else label1->Text = "Не удалось открыть";
		F2.close();
		button3->Visible = true;
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		dataGridView1->Columns->Clear();
		dataGridView1->Rows->Clear();
		dataGridView1->ColumnCount = 10;
		dataGridView1->RowCount = 10;
		for (int i = 1; i < 101; i++) {
			str[k] += str0[i - 1];
			if (i % 10 == 0) { k++; }
		}
		dataGridView1->Visible = true;
		for (k = 0; k < 10; k++) {
			for (int j = 0; j < 10; j++) {
				dataGridView1->Rows[k]->Cells[j]->Value = ((wchar_t)str[k].at(j)).ToString();
			}
		}
		k = 0;
		button6->Visible = true;
		button1->Enabled = false;
		button2->Enabled = false;
		button3->Enabled = false;
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {

		SemaF = CreateSemaphore(NULL, 0, 1, NULL);

		CreatePipe(&Ride, &write, NULL, 100);
		CreateThread(NULL, 0, Thed1proc, (LPVOID)k, 0, NULL);
		WaitForSingleObject(SemaF, INFINITE);
		ReadFile(Ride, str, 100, NULL, NULL);
		dataGridView1->Columns->Clear();
		dataGridView1->Rows->Clear();
		dataGridView1->ColumnCount = 10;
		dataGridView1->RowCount = 10;
		for (k = 0; k < 10; k++) {
			for (int j = 0; j < 10; j++) {
				dataGridView1->Rows[k]->Cells[j]->Value = ((wchar_t)str[k].at(j)).ToString();
			}
		}
		button4->Visible = true;

	}

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {

		SetFileAttributesA("File2.csv", FILE_ATTRIBUTE_NORMAL);
		fstream F1;
		F1.open("File2.csv", ios::out | ios::trunc);
		
		for (k = 0; k < 10; k++) {
			char* cstr = new char[str[k].length() + 1];
			strcpy(cstr, str[k].c_str());
			for (int j = 0; j < 10; j++) {
				F1 << cstr[j];
				if (j != 9) F1 << ";";
				else F1 << "\n";
			}
			delete[] cstr;
		}
		SetFileAttributesA("File2.csv", FILE_ATTRIBUTE_READONLY);
		button7->Visible = true;
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		exit(0);
	}
};
}
