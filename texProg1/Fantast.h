
#pragma once
#include"Base.h"

class fantas :public Base
{
	string film;
public:

	fantas();
	fantas(ifstream& f);
	~fantas();
	void setfilm();
	void getfilm();
	void showall(int col = 1) override;
	void writeall(ofstream& f) override;
	void redakone(int a) override;
};