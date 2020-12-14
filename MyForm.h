#pragma once
#include "Header.h" 
#include "Template.h"
#include <algorithm>

namespace WindowsFormTemplate {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		System::Collections::Generic::Queue <Customer^> ^ qCustomer;
		System::Collections::Generic::List <Customer^> ^ lCustomer;
		Customer^ myCustomer;
		String^ FileName;
		StreamReader^ Sr;
		StreamWriter^ Sw;
		array <int> ^arrayProducts;


	private: System::Windows::Forms::CheckBox^ checkBox1;
		   Order^ myOrder;
		   int numbers;
	private: System::Windows::Forms::Button^ findOrder;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DGVCustomer;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DGVNumOrder;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DGVProduct;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DGVQuantity;

	public:
		MyForm(void)
		{
			InitializeComponent();
			this->myCustomer = gcnew Customer;
			this->myOrder = gcnew Order;
			this->qCustomer = gcnew System::Collections::Generic::Queue <Customer^>(5);
			this->lCustomer = gcnew System::Collections::Generic::List <Customer^>();
			this->numbers = 0;

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
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;




	private: System::Windows::Forms::Button^ addOrder;
	private: System::Windows::Forms::TextBox^ cust;
	private: System::Windows::Forms::ComboBox^ prod;
	private: System::Windows::Forms::TextBox^ quent;



	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;




	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ numord;

	private: System::Windows::Forms::Button^ closeOrder;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ acceptEdit;

	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ makeSummary;


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
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->DGVCustomer = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DGVNumOrder = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DGVProduct = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DGVQuantity = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->addOrder = (gcnew System::Windows::Forms::Button());
			this->cust = (gcnew System::Windows::Forms::TextBox());
			this->prod = (gcnew System::Windows::Forms::ComboBox());
			this->quent = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->numord = (gcnew System::Windows::Forms::TextBox());
			this->closeOrder = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->acceptEdit = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->makeSummary = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->findOrder = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(231, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(215, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Магазинчик HandMade";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->DGVCustomer,
					this->DGVNumOrder, this->DGVProduct, this->DGVQuantity
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 37);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(496, 328);
			this->dataGridView1->TabIndex = 1;
			// 
			// DGVCustomer
			// 
			this->DGVCustomer->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->DGVCustomer->HeaderText = L"Заказчик";
			this->DGVCustomer->Name = L"DGVCustomer";
			this->DGVCustomer->Width = 80;
			// 
			// DGVNumOrder
			// 
			this->DGVNumOrder->HeaderText = L"Номер заявки";
			this->DGVNumOrder->Name = L"DGVNumOrder";
			// 
			// DGVProduct
			// 
			this->DGVProduct->HeaderText = L"Товар";
			this->DGVProduct->Name = L"DGVProduct";
			// 
			// DGVQuantity
			// 
			this->DGVQuantity->HeaderText = L"Количество";
			this->DGVQuantity->Name = L"DGVQuantity";
			// 
			// addOrder
			// 
			this->addOrder->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->addOrder->Location = System::Drawing::Point(518, 164);
			this->addOrder->Name = L"addOrder";
			this->addOrder->Size = System::Drawing::Size(122, 23);
			this->addOrder->TabIndex = 2;
			this->addOrder->Text = L"Добавить заказ";
			this->addOrder->UseVisualStyleBackColor = true;
			this->addOrder->Click += gcnew System::EventHandler(this, &MyForm::addOrder_Click);
			// 
			// cust
			// 
			this->cust->Location = System::Drawing::Point(519, 55);
			this->cust->Name = L"cust";
			this->cust->Size = System::Drawing::Size(122, 20);
			this->cust->TabIndex = 3;
			// 
			// prod
			// 
			this->prod->FormattingEnabled = true;
			this->prod->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"Мыло", L"Носки", L"Шапка", L"Варежки", L"Шарф", L"Свитер",
					L"Леденцы", L"Съедобный букет"
			});
			this->prod->Location = System::Drawing::Point(519, 96);
			this->prod->Name = L"prod";
			this->prod->Size = System::Drawing::Size(122, 21);
			this->prod->TabIndex = 4;
			// 
			// quent
			// 
			this->quent->Location = System::Drawing::Point(518, 138);
			this->quent->Name = L"quent";
			this->quent->Size = System::Drawing::Size(122, 20);
			this->quent->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(516, 37);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(149, 15);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Заказчик (Фамилия И. О.)";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(516, 78);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(95, 15);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Выберите товар";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(516, 120);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(134, 15);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Укажите кол-во товара";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(515, 200);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(129, 15);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Укажите номер заказа";
			// 
			// numord
			// 
			this->numord->Location = System::Drawing::Point(517, 218);
			this->numord->Name = L"numord";
			this->numord->Size = System::Drawing::Size(122, 20);
			this->numord->TabIndex = 9;
			// 
			// closeOrder
			// 
			this->closeOrder->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->closeOrder->Location = System::Drawing::Point(517, 320);
			this->closeOrder->Name = L"closeOrder";
			this->closeOrder->Size = System::Drawing::Size(122, 45);
			this->closeOrder->TabIndex = 11;
			this->closeOrder->Text = L"Заказ из очереди выполнен";
			this->closeOrder->UseVisualStyleBackColor = true;
			this->closeOrder->Click += gcnew System::EventHandler(this, &MyForm::closeOrder_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->acceptEdit);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Location = System::Drawing::Point(12, 394);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(653, 63);
			this->groupBox1->TabIndex = 13;
			this->groupBox1->TabStop = false;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(6, 16);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(82, 15);
			this->label9->TabIndex = 14;
			this->label9->Text = L"Номер заказа";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(385, 17);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(134, 15);
			this->label8->TabIndex = 14;
			this->label8->Text = L"Укажите кол-во товара";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(264, 16);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(95, 15);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Выберите товар";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(109, 16);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(149, 15);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Заказчик (Фамилия И. О.)";
			// 
			// acceptEdit
			// 
			this->acceptEdit->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->acceptEdit->Location = System::Drawing::Point(525, 17);
			this->acceptEdit->Name = L"acceptEdit";
			this->acceptEdit->Size = System::Drawing::Size(122, 40);
			this->acceptEdit->TabIndex = 14;
			this->acceptEdit->Text = L"Принять изменения";
			this->acceptEdit->UseVisualStyleBackColor = true;
			this->acceptEdit->Click += gcnew System::EventHandler(this, &MyForm::acceptEdit_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(388, 37);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(131, 20);
			this->textBox3->TabIndex = 14;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(261, 36);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 14;
			// 
			// textBox2
			// 
			this->textBox2->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(8) {
				L"Мыло", L"Носки", L"Шапка",
					L"Варежки", L"Шарф", L"Свитер", L"Леденцы", L"Съедобный букет"
			});
			this->textBox2->Location = System::Drawing::Point(112, 37);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(143, 20);
			this->textBox2->TabIndex = 14;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(6, 37);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// makeSummary
			// 
			this->makeSummary->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->makeSummary->Location = System::Drawing::Point(12, 472);
			this->makeSummary->Name = L"makeSummary";
			this->makeSummary->Size = System::Drawing::Size(147, 32);
			this->makeSummary->TabIndex = 14;
			this->makeSummary->Text = L"Подвести итоги";
			this->makeSummary->UseVisualStyleBackColor = true;
			this->makeSummary->Click += gcnew System::EventHandler(this, &MyForm::makeSummary_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(12, 371);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(136, 17);
			this->checkBox1->TabIndex = 15;
			this->checkBox1->Text = L"Редактировать заказ";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// findOrder
			// 
			this->findOrder->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->findOrder->Location = System::Drawing::Point(517, 244);
			this->findOrder->Name = L"findOrder";
			this->findOrder->Size = System::Drawing::Size(122, 23);
			this->findOrder->TabIndex = 16;
			this->findOrder->Text = L"Найти заказ";
			this->findOrder->UseVisualStyleBackColor = true;
			this->findOrder->Click += gcnew System::EventHandler(this, &MyForm::findOrder_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(677, 520);
			this->Controls->Add(this->findOrder);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->makeSummary);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->closeOrder);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->numord);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->quent);
			this->Controls->Add(this->prod);
			this->Controls->Add(this->cust);
			this->Controls->Add(this->addOrder);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void addOrder_Click(System::Object^ sender, System::EventArgs^ e) {
		this->numbers++;
		try {
			Order^ otmp = gcnew Order(this->prod->Text, numbers, Convert::ToInt32(this->quent->Text));
			this->myCustomer = gcnew Customer(this->cust->Text, otmp);
			this->lCustomer->Add(myCustomer);
			this->qCustomer->Enqueue(myCustomer);
			Look(this->lCustomer, this->dataGridView1);
		}
		catch (...) {
			MessageBox::Show("Неверный формат входных данных.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
private: System::Void closeOrder_Click(System::Object^ sender, System::EventArgs^ e) {
	this->myCustomer = this->qCustomer->Dequeue();
	if(this->lCustomer->Remove(this->myCustomer))
		Look(this->lCustomer, this->dataGridView1);
}
private: System::Void acceptEdit_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		myPredicate predicate(Convert::ToInt32(this->textBox1->Text));
		int index = lCustomer->FindIndex(gcnew Predicate <Customer^>(predicate, &myPredicate::isMyOrder));
		this->lCustomer[index]->person = gcnew String(this->textBox2->Text);
		this->lCustomer[index]->order->Product = gcnew String(this->comboBox1->Text);
		this->lCustomer[index]->order->Q = Convert::ToInt32(this->textBox3->Text);
		Look(this->lCustomer, this->dataGridView1);
	}
	catch (...) {
		this->checkBox1->Checked = false;
		MessageBox::Show("Неверный формат входных данных.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	
}
private: System::Void makeSummary_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		this->FileName = gcnew String(Directory::GetCurrentDirectory() + "\\Summary.rtf");
		this->arrayProducts = gcnew array<int>(this->prod->Items->Count);
		Order^ MAX = gcnew Order(mostPopularProduct(this->lCustomer, this->arrayProducts));
		Order^ MIN = gcnew Order(lessPopularProduct(this->lCustomer, this->arrayProducts));
		this->Sw = gcnew StreamWriter(this->FileName);
		this->Sw->WriteLine(String::Format("Наиболее продаваемый товар \"{0}\", в количестве - {1} шт.",MAX->Product,MAX->Q));
		this->Sw->WriteLine(String::Format("Наименее продаваемый товар \"{0}\", в количестве - {1} шт.",MIN->Product, MIN->Q));
		this->Sw->Close();
		MessageBox::Show((String::Format("Итоги хранятся в файле Summary.rtf\n\nНаиболее продаваемый товар \"{0}\", в количестве - {1} шт.\nНаименее продаваемый товар \"{2}\", в количестве - {3} шт.", MAX->Product, MAX->Q, MIN->Product, MIN->Q)), 
			"Итоги", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	catch (...)
	{
		MessageBox::Show("Что-то пошло не так с сохранением :(", "Итоги", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	this->groupBox1->Enabled = false;
	this->FileName = gcnew String(Directory::GetCurrentDirectory() + "\\Orders.txt");
	this->Sr = gcnew StreamReader(this->FileName);
	readFromFile(this->Sr, this->lCustomer, this->qCustomer);
	this->Sr->Close();
	this->numbers = this->lCustomer->Count;
	Look(this->lCustomer, this->dataGridView1);
}
private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	this->checkBox1->Checked ? this->groupBox1->Enabled = true : this->groupBox1->Enabled = false;
}
private: System::Void findOrder_Click(System::Object^ sender, System::EventArgs^ e) {
	this->dataGridView1->ClearSelection();
	myPredicate predicate(Convert::ToInt32(this->numord->Text));
	int index = this->lCustomer->FindIndex(gcnew Predicate <Customer^>(predicate, &myPredicate::isMyOrder));
	this->dataGridView1->Rows[index]->Selected = true;
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	myPredicate predicate(Convert::ToInt32(this->textBox1->Text));
	int index = this->lCustomer->FindIndex(gcnew Predicate <Customer^>(predicate, &myPredicate::isMyOrder));
	this->textBox2->Text = this->lCustomer[index]->person;
	this->comboBox1->Text = this->lCustomer[index]->order->Product;
	this->textBox3->Text = Convert::ToString(lCustomer[index]->order->Q);
}
private: System::Void MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	this->FileName = gcnew String(Directory::GetCurrentDirectory() + "\\Orders.txt");
	this->Sw = gcnew StreamWriter(this->FileName);
	writeToFile(this->Sw, this->lCustomer);
	this->Sw->Close();
}
};
}
