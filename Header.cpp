#pragma once
#include "Header.h"


Order::Order() {
	this->num_o = 0;
	this->product = gcnew String("");
	this->q = 0;
}

Order::Order(String^ p , int no, int qq) {
	this->num_o = no++;
	this->product = gcnew String(p);
	this->q = qq;
}

Order::Order(Order^ o) {
	this->num_o = o->num_o;
	this->product = gcnew String(o->product);
	this->q = o->q;
}

Customer::Customer() {
	this->person = gcnew String("");
	this->order = gcnew Order();
}

Customer::Customer(String^ p, Order^ o)	{ 
	this->person = gcnew String(p);
	this->order = gcnew Order(o);
}

Customer::Customer(Customer^ c)	{
	this->person = gcnew String(c->person);
	this->order = gcnew Order(c->order);
}

int Customer::CompareTo(Customer^ two) {
	if (this->person->CompareTo(two->person) > 0)
		return 1;
	if (this->person->CompareTo(two->person) < 0)
		return -1;
	if (this->person->CompareTo(two->person) == 0) {
		if (this->order->Num_O > two->order->Num_O)
			return 1;
		else
			return -1;
	}
}

int CompareByOrders(Customer^ one, Customer^ two) {
	if (one->order->Num_O > two->order->Num_O)
		return 1;
	else
		return -1;
}

void Look(System::Collections::Generic::List<Customer^>^ list, System::Windows::Forms::DataGridView^ dgv) {
	dgv->RowCount = 1;
	list->Sort();
	for each (Customer ^ el in list) {
		dgv->Rows->Add(el->person, System::Convert::ToString(el->order->Num_O), el->order->Product, System::Convert::ToString(el->order->Q));
	}
}

void readFromFile(System::IO::StreamReader^ SR, System::Collections::Generic::List <Customer^>^ LIST, 
	System::Collections::Generic::Queue <Customer^>^ QUEUE) {
	String^ line;
	int numbers = Convert::ToInt32(SR->ReadLine());
	for (int i = 0; i < numbers; i++) {
		line = SR->ReadLine();
		String ^P = gcnew String(line->Substring(0, line->IndexOf("#")));
		int NO = Convert::ToInt32(line->Substring(line->IndexOf("#") + 1, line->IndexOf("@") - line->IndexOf("#") - 1));
		String ^ Pr = line->Substring(line->IndexOf("@") + 1, line->IndexOf("$") - line->IndexOf("@") - 1);
		int Q = Convert::ToInt32(line->Substring(line->IndexOf("$") + 1));
		Order^ O = gcnew Order(Pr, NO, Q);
		Customer^ C = gcnew Customer(P, O);
		LIST->Add(C);
	}
	LIST->Sort(gcnew System::Comparison <Customer^>(CompareByOrders));
	for each (Customer^ C in LIST){
		QUEUE->Enqueue(C);
	}
	QUEUE->TrimExcess();
	LIST->TrimExcess();
}

void writeToFile(System::IO::StreamWriter^ SW, System::Collections::Generic::List <Customer^>^ LIST) {
	SW->WriteLine(LIST->Count);
	for each (Customer ^C in LIST)
	{
		SW->WriteLine(C->person + "#" + C->order->Num_O + "@" + C->order->Product + "$" + C->order->Q);
	}
}

myPredicate::myPredicate(int w) {
	this->what = w;
}

bool myPredicate::isMyOrder(Customer^ C) {
	if (C->order->Num_O == this->what)
		return true;
	else
		return false;
}

void countProducts(System::Collections::Generic::List <Customer^>^ LIST, array <int>^ AP) {
	/*Мыло - 0
		  Носки - 1
		  Шапка - 2
		  Варежки - 3
		  Шарф - 4
		  Свитер - 5
		  Леденцы - 6
		  Съедобный букет - 7
		*/
	for each (Customer ^ C in LIST)
	{
		C;
		if (C->order->Product->CompareTo("Мыло")==0)
			AP[0] += C->order->Q;
		if (C->order->Product->CompareTo("Носки")==0)
			AP[1] += C->order->Q;
		if (C->order->Product->CompareTo("Шапка")==0)
			AP[2] += C->order->Q;
		if (C->order->Product->CompareTo("Варежки")==0)
			AP[3] += C->order->Q;
		if (C->order->Product->CompareTo("Шарф")==0)
			AP[4] += C->order->Q;
		if (C->order->Product->CompareTo("Свитер")==0)
			AP[5] += C->order->Q;
		if (C->order->Product->CompareTo("Леденцы")==0)
			AP[6] += C->order->Q;
		if (C->order->Product->CompareTo("Съедобный букет")==0)
			AP[7] += C->order->Q;
	}
}

Order^ mostPopularProduct(System::Collections::Generic::List <Customer^>^ LIST, array <int>^ AP) {
	countProducts(LIST, AP);
	int result=0;
	for (int index = 1; index < AP->Length-1; index++) {
		if (AP[result] < AP[index])
			result = index;
	}
	String^ pr;
	if (result == 0) pr = gcnew String("Мыло");
	if (result == 1) pr = gcnew String("Носки");
	if (result == 2) pr = gcnew String("Шапка");
	if (result == 3) pr = gcnew String("Варежки");
	if (result == 4) pr = gcnew String("Шарф");
	if (result == 5) pr = gcnew String("Свитер");
	if (result == 6) pr = gcnew String("Леденцы");
	if (result == 7) pr = gcnew String("Съедобный букет");
	return gcnew Order(pr, 0, AP[result]);
}

Order^ lessPopularProduct(System::Collections::Generic::List <Customer^>^ LIST, array <int>^ AP) {
	countProducts(LIST, AP);
	int result = 0;
	for (int index = 1; index < AP->Length-1; index++) {
		if (AP[result] > AP[index])
			result = index;
	}
	String^ pr;
	if (result == 0) pr = gcnew String("Мыло");
	if (result == 1) pr = gcnew String("Носки");
	if (result == 2) pr = gcnew String("Шапка");
	if (result == 3) pr = gcnew String("Варежки");
	if (result == 4) pr = gcnew String("Шарф");
	if (result == 5) pr = gcnew String("Свитер");
	if (result == 6) pr = gcnew String("Леденцы");
	if (result == 7) pr = gcnew String("Съедобный букет");
	return gcnew Order(pr, 0, AP[result]);
}