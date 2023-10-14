#pragma once
#include"Base.h"

class roman :public Base
{
	string birth;
	string death;
	string biograf;
public:

	roman();


	roman(ifstream& f);

	void setbiograf();
	void getbiograf();
	void data();
	void printData();
	void showall(int col = 1) override;
	void writeall(ofstream& f) override;

	~roman();
	void redakone(int a) override;

};
