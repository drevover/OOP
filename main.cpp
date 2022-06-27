#include <fstream>
#include "resource.h"

using namespace std;
using namespace d;

void zamena::InData(ifstream& ifst) {
	pair = new char[100];
	shifr::InData(ifst);
	ifst >> encrypt >> pair;
}
void zamena::Output(ofstream& ofst) {
	ofst << "It is Cipher of Zameny: encrypted text is " << encrypt << ", massive of pair " << pair << endl;
	shifr::Output(ofst);
}
void sdvig::InData(ifstream& ifst) {
	shifr::InData(ifst);
	ifst >> encrypt >> n;
}
void sdvig::Output(ofstream& ofst) {
	ofst << "It is Cipher of Sdviga: encrypted text is " << encrypt << ", sdvig on " << n << endl;
	shifr::Output(ofst);
}
shifr* shifr::Shifr_Input(ifstream& ifst) {
	shifr* sr;
	int k;
	ifst >> k;
	switch (k) {
	case 1:
		sr = new zamena;
		break;
	case 2:
		sr = new sdvig;
		break;
	default:
		return 0;
	}
	sr->InData(ifst);
	return sr;
}
void shifr::InData(ifstream& ifst) {
	ifst >> text;
}
void shifr::Output(ofstream& ofst) {
	ofst << "Open text is " << text << endl;
}
container::container()
{
	First = NULL;
	Last = First;
	SizeList = 0;
}

container::~container()
{
	Node* Temp = NULL;
	while (SizeList > 1)
	{
		Temp = Last->Prev;
		delete Last;
		Last = Temp;
		SizeList--;
	}
	if (SizeList == 1)
		delete First;
	SizeList--;
}

void container::In(ifstream& ifst)
{
	Node* Temp;
	while (!ifst.eof())
	{
		Temp = new Node;
		Temp->Next = NULL;
		Temp->sh = shifr::Shifr_Input(ifst);

		if (Temp->sh == NULL)
			break;

		if (First == NULL)
		{
			First = Last = Temp;
			Temp->Prev = Temp;
			Temp->Next = First;
		}
		else
		{
			Temp->Prev = Last;
			Last->Next = Temp;
			Temp->Next = First;
			Last = Temp;
		}
		SizeList++;
	}
}

void container::Out(ofstream& ofst)
{
	Node* Temp = First;
	ofst << "List contains " << SizeList << " elements" << endl;
	for (size_t i = 0; i < SizeList; i++)
	{
		ofst << i + 1 << ": ";
		Temp->sh->Output(ofst);
		Temp = Temp->Next;
	}
	ofst << endl;
}

void zamena::MultiMethod(shifr* other, ofstream& ofst)
{
	other->MultiMethod_Zamena(ofst);
}

void zamena::MultiMethod_Zamena(ofstream& ofst)
{
	ofst << "Zamena and Zamena" << endl;
}

void zamena::MultiMethod_Sdvig(ofstream& ofst)
{
	ofst << "Sdvig and Zamena" << endl;
}

void sdvig::MultiMethod(shifr* other, ofstream& ofst)
{
	other->MultiMethod_Sdvig(ofst);
}

void sdvig::MultiMethod_Zamena(ofstream& ofst)
{
	ofst << "Zamena and Sdvig" << endl;
}

void sdvig::MultiMethod_Sdvig(ofstream& ofst)
{
	ofst << "Sdvig and Sdvig" << endl;
}

void container::MultiMethod(ofstream& ofst)
{
	Node* current_first = First;
	Node* current_second = current_first->Next;

	ofst << "Multimethod." << endl;
	for (int i = 0; i < SizeList - 1; i++)
	{
		for (int j = i + 1; j < SizeList; j++)
		{
			current_first->sh->MultiMethod(current_second->sh, ofst);
			current_first->sh->Output(ofst);
			current_second->sh->Output(ofst);
			current_second = current_second->Next;
		}
		current_first = current_first->Next;
		current_second = current_first->Next;
	}
}