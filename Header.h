#pragma once
#include <fstream>

using namespace System;
using namespace System::Collections;
using namespace System::Windows::Forms;

//�����
ref class Order {
	//����� ������ 
	int num_o; 
	//�������� ������
	String^ product; 
	//���-�� �������
	int q; 
public:
	//������ � ������ ������
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
	//������ � �������� ������
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
	//������ � ���-�� ������
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
	
	//����������� �� ���������
	Order(void);
	//����������� �� ����������
	Order(String^,int, int);
	//����������� �����
	Order(Order^);
};

//��������
public ref class Customer: IComparable <Customer^> {
public:
	//���
	String^ person;
	//�����
	Order^ order; 

	//����������� �� ���������
	Customer(void);
	//����������� �� ����������
	Customer(String^, Order^);
	//����������� �����
	Customer(Customer^);

	//���������� �� ���������, ���������� � ���������� �������
	virtual int CompareTo(Customer^);
};
//��������
public value class myPredicate {
	//���?
	int what;
public:
	//����������� ���������
	myPredicate(int w);

	//�������� ��� ������ �� ������ ������
	bool isMyOrder(Customer^ );
};
//���������� �� ���� ����� ������
int CompareByOrders(Customer^, Customer^);
//����� �������� ����������� ������
Order^ mostPopularProduct(System::Collections::Generic::List <Customer^>^, array <int> ^);
//����� �������� ����������� ������
Order^ lessPopularProduct(System::Collections::Generic::List <Customer^>^, array <int>^);
//�������� � Grid'�
void Look(System::Collections::Generic::List <Customer^>^ , System::Windows::Forms::DataGridView^ );
//������ �� �����
void readFromFile(System::IO::StreamReader ^, System::Collections::Generic::List <Customer^>^, 
	System::Collections::Generic::Queue <Customer^>^);
//������ � ����
void writeToFile(System::IO::StreamWriter^, System::Collections::Generic::List <Customer^>^);
