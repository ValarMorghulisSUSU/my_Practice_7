#pragma once
#include <fstream>

using namespace System;
using namespace System::Collections;
using namespace System::Windows::Forms;

//Заказ
ref class Order {
	//номер заказа 
	int num_o; 
	//название товара
	String^ product; 
	//кол-во товаров
	int q; 
public:
	//доступ к номеру заказа
	property int Num_O {
		int get()
		{
			return num_o;
		}
		void set(int Num_O)
		{
			num_o = Num_O;
		}
	}
	//доступ к названию товара
	property String^ Product {
		String^ get()
		{
			return product;
		}
		void set(String^ Product)
		{
			product = gcnew String(Product);
		}
	}
	//доступ к кол-ву товара
	property int Q {
		int get()
		{
			return q;
		}
		void set(int Q) 
		{
			q = Q;
		}
	}
	
	//Конструктор по умолчанию
	Order(void);
	//Конструктор по параметрам
	Order(String^,int, int);
	//Конструктор копии
	Order(Order^);
};

//Заказчик
public ref class Customer: IComparable <Customer^> {
public:
	//ФИО
	String^ person;
	//Заказ
	Order^ order; 

	//Конструктор по умолчанию
	Customer(void);
	//Конструктор по параметрам
	Customer(String^, Order^);
	//Констурктор копии
	Customer(Customer^);

	//Компаратор по умолчанию, сортировка в алфавитном порядке
	virtual int CompareTo(Customer^);
};
//Предикат
public value class myPredicate {
	//что?
	int what;
public:
	//конструктор предиката
	myPredicate(int w);

	//Предикат для поиска по номеру заказа
	bool isMyOrder(Customer^ );
};
//Компаратор по полю номер заказа
int CompareByOrders(Customer^, Customer^);
//Поиск наиболее популярного товара
Order^ mostPopularProduct(System::Collections::Generic::List <Customer^>^, array <int> ^);
//Поиск наименее популярного товара
Order^ lessPopularProduct(System::Collections::Generic::List <Customer^>^, array <int>^);
//Просмотр в Grid'е
void Look(System::Collections::Generic::List <Customer^>^ , System::Windows::Forms::DataGridView^ );
//Чтение из файла
void readFromFile(System::IO::StreamReader ^, System::Collections::Generic::List <Customer^>^, 
	System::Collections::Generic::Queue <Customer^>^);
//Запись в файл
void writeToFile(System::IO::StreamWriter^, System::Collections::Generic::List <Customer^>^);
