#include <fstream>
#pragma once
using namespace std;
namespace d {
	class shifr {
		string text;
		string name;
	public:
		static shifr* Shifr_Input(ifstream& ifst);
		virtual void InData(ifstream& ofst) = 0;
		virtual void Output(ofstream& ofst) = 0;
		virtual int Characters();
		virtual void OutZamena(ofstream& ofst) { ofst << endl; }
	protected:
		shifr() {};
	};
	class zamena : public shifr {
		string encrypt;
		char* pair;
	public:
		void InData(ifstream& ifst);
		void Output(ofstream& ofst);
		void OutZamena(ofstream& ofst);
		zamena() { };
	};
	class sdvig : public shifr {
		string encrypt;
		int n;
	public:
		void InData(ifstream& ifst);
		void Output(ofstream& ofst);
		sdvig() { };
	};
	class number : public shifr {
		int encrypt;
		char* pair;
	public:
		void InData(ifstream& ifst);
		void Output(ofstream& ofst);
		number() { };
	};
	class container {
		struct Node
		{
			shifr* sh;
			Node* next;
			Node* prev;
		};
	public:
		void In(ifstream& ifst);
		void Out(ofstream& ofst);
		container();
		~container();
		void Sort();
		bool Compare(shifr* first, shifr* second);
		void Swap(Node* first, Node* second);
	private:
		Node* first;
		Node* last;
		size_t sizelist;
	};
}