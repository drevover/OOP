#include <fstream>
#pragma once
using namespace std;
namespace d {
	class shifr {
		char text[50];
	public:
		static shifr* Shifr_Input(ifstream& ifst);
		virtual void InData(ifstream& ofst) = 0;
		virtual void Output(ofstream& ofst) = 0;
		virtual void MultiMethod(shifr* other, ofstream& fout) {};
		virtual void MultiMethod_Zamena(ofstream& fout) {};
		virtual void MultiMethod_Sdvig(ofstream& fout) {};
	protected:
		shifr() {};
	};
	class zamena : public shifr {
		char encrypt[50];
		char text[50];
		char* pair;
	public:
		void InData(ifstream& ifst);
		void Output(ofstream& ofst);
		void MultiMethod(shifr* other, ofstream& fout);
		void MultiMethod_Zamena(ofstream& fout);
		void MultiMethod_Sdvig(ofstream& fout);
		zamena() { };
	};
	class sdvig : public shifr {
		char encrypt[50];
		char text[50];
		int n;
	public:
		void InData(ifstream& ifst);
		void Output(ofstream& ofst);
		void MultiMethod(shifr* other, ofstream& fout);
		void MultiMethod_Zamena(ofstream& fout);
		void MultiMethod_Sdvig(ofstream& fout);
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
		void MultiMethod(ofstream& ofst);
		container();
		~container();
	private:
		Node* First;
		Node* Last;
		size_t SizeList;
	};
}