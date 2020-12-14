#pragma once
using namespace System; 
using namespace System::Windows::Forms;


bool isEmpty(TextBox^ TB) {
	return String::IsNullOrEmpty(TB->Text) || String::IsNullOrWhiteSpace(TB->Text);
}
bool isEmpty(ComboBox^ CB) {
	return String::IsNullOrEmpty(CB->Text) || String::IsNullOrWhiteSpace(CB->Text);
}


template <typename type> int arrayLength(array<type^>^ Array) {
	int len = 0;
	for (int i = 0; i < Array->Length; i++)
		if (Array[i] != nullptr)
			len++;
	return len;
}

template <typename Type> void myShow(TextBox^ TB, Type^ Point) {
	TB->Text = Point->ToString()
}
template <typename Type> void myShow(ListBox^ LB, Type^ Point) {
	LB->Items->Add(Point->ToString());
}

template <typename Type> Type^ Max(array <Type^>^ Array) {
	Type^ max = gcnew Type();
	max = Array[0];
	if (arrayLength(Array) > 1 )
		for (int i = 1; i < arrayLength(Array); i++)
			if (max < Array[i])
				max = Array[i];

	return max;
}

//template <typename Type> Type^ Max(System::Collections::Generic::List <Type^>^ List) {
//	Type^ max = gcnew Type();
//	max = Array[0];
//	if (arrayLength(Array) > 1)
//		for (int i = 1; i < arrayLength(Array); i++)
//			if (max < Array[i])
//				max = Array[i];
//
//	return max;
//}

template <typename Type> bool Find( ListBox^ LB, Type^ Point) {
	LB->SelectedIndex = -1;
	LB->SelectedItem = Convert::ToString(Point);
	if (LB->SelectedIndex == -1)
		return false;
	else
		return true;
}

template <typename Type> bool Find(DataGridView^ DGV, Type^ Point) {
	DGV-> = -1;
	
	DGV->SelectedCells = Convert::ToString(Point);
	if (DGV->SelectedRows == -1)
		return false;
	else
		return true;
}

template <typename Type> int myCount(Type^ Smth, int pred) {

}