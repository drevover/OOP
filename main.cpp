#include <fstream>
#include "resource.h"
#include <string>
#define WRONG_SHIFR 0

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
	string tmp;
	ifst >> k;
	if (tmp == "\0")
		return 0;
	if (!isdigit(int(tmp.front())) || tmp.length() > 1)
		k = WRONG_SHIFR;
	else
		k = stoi(tmp);
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
	ifst >> name;
}
void shifr::Output(ofstream& ofst) {
	ofst << "Open text is " << text << ", name of own - " << name << endl;
}
container::container()
{
	first = NULL;
	last = first;
	sizelist = 0;
}

container::~container()
{
	Node* temp = NULL;
	while (sizelist > 1)
	{
		temp = last->prev;
		delete last;
		last = temp;
		sizelist--;
	}
	if (sizelist == 1)
		delete first;
	sizelist--;
}

void container::In(ifstream& ifst)
{
	Node* temp;
	while (!ifst.eof())
	{
		temp = new Node;
		temp->next = NULL;
		temp->sh = shifr::Shifr_Input(ifst);

		if (temp->sh == NULL)
			break;

		if (first == NULL)
		{
			first = last = temp;
			temp->prev = temp;
			temp->next = first;
		}
		else
		{
			temp->prev = last;
			last->next = temp;
			temp->next = first;
			last = temp;
		}
		sizelist++;
	}
}

void container::Out(ofstream& ofst)
{
	Node* temp = first;
	ofst << "List contains " << sizelist << " elements" << endl;
	for (size_t i = 0; i < sizelist; i++)
	{
		ofst << i + 1 << ": ";
		temp->sh->Output(ofst);
		ofst << "Characters on text = " << temp->sh->Characters() << endl;
		temp = temp->next;
	}
	ofst << endl;
	for (int i = 0; i < sizelist; i++) {
		ofst << i + 1 << ": ";
		temp->sh->OutZamena(ofst);
		temp = temp->next;
	}
	ofst << endl;
}

int shifr::Characters() {
	return size(text);
}

void container::Sort() {
	if (sizelist < 2) {
		return;
	}

	Node* current = first;
	bool flag = false;

	do
	{
		current = first;
		flag = false;
		for (int i = 0; i < (sizelist - 1); ++i)
		{
			if (Compare(current->sh, current->next->sh))
			{
				Swap(current, current->next);
				flag = true;
			}
			else
			{
				current = current->next;
			}
		}
	} while (flag);
}

bool container::Compare(shifr* first, shifr* second) {
	return first->Characters() > second->Characters();
}

void container::Swap(Node* first, Node* second) {
	shifr* tmp;
	tmp = first->sh;
	first->sh = second->sh;
	second->sh = tmp;
	return;
}

void zamena::OutZamena(ofstream& ofst) {
	ofst << "It is Cipher of zameny: encrypted text is " << encrypt << ", massive of pair " << pair << endl;
}