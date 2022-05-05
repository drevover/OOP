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
void number::InData(ifstream& ifst) {
	pair = new char[100];
	shifr::InData(ifst);
	ifst >> encrypt >> pair;
}
void number::Output(ofstream& ofst) {
	ofst << "It is Cipher of Change-to-number: encrypted text is " << encrypt << ", massive of pair " << pair << endl;
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
	case 3:
		sr = new number;
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
		ofst << "Characters on text = " << Temp->sh->characters() << endl;
		Temp = Temp->Next;
	}
	ofst << endl;
}
int shifr::characters() {
	return size(text);
}
void container::sort() {
	if (SizeList < 2) {
		return;
	}

	Node* current = First;
	bool flag = false;

	do
	{
		current = First;
		flag = false;
		for (int i = 0; i < (SizeList - 1); ++i)
		{
			if (compare(current->sh, current->Next->sh))
			{
				swap(current, current->Next);
				flag = true;
			}
			else
			{
				current = current->Next;
			}
		}
	} while (flag);
}

bool container::compare(shifr* first, shifr* second) {
	return first->characters() > second->characters();
}

void container::swap(Node* first, Node* second) {
	shifr* tmp;
	tmp = first->sh;
	first->sh = second->sh;
	second->sh = tmp;
	return;
}