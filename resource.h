#include <fstream>
#pragma once
using namespace std;
namespace d {
	class shifr {
		char text;
	public:
		static shifr* Shifr_Input(ifstream& ifst);
		virtual void InData(ifstream& ofst) = 0;
		virtual void Output(ofstream& ofst) = 0;
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
	private:
		Node* First;
		Node* Last;
		size_t SizeList;
	};
}