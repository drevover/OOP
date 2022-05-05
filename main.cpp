#include <fstream>
#include "Header.h"

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
	ifst >> name;
}
void shifr::Output(ofstream& ofst) {
	ofst << "Open text is " << text << ", name of own - " << name << endl;
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