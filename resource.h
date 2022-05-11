#include <fstream>
#pragma once
using namespace std;
namespace d {
	class shifr {
		char text;
		string name;
	public:
		static shifr* Shifr_Input(ifstream& ifst);
		virtual void InData(ifstream& ofst) = 0;
		virtual void Output(ofstream& ofst) = 0;
		virtual int characters();
	protected:
		shifr() {};
	};
	class zamena : public shifr {
		char encrypt;
		char text;
		char* pair;
	public:
		void InData(ifstream& ifst);
		void Output(ofstream& ofst);
		zamena() { };
	};
	class sdvig : public shifr {
		char encrypt;
		char text;
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
			Node* Next;
			Node* Prev;
		};
	public:
		void In(ifstream& ifst);
		void Out(ofstream& ofst);
		container();
		~container();
		void sort();
		bool compare(shifr* first, shifr* second);
		void swap(Node* first, Node* second);
	private:
		Node* First;
		Node* Last;
		size_t SizeList;
	};
}