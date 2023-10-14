#pragma once
#include"Base.h";
class poet :public Base
{
	string birth;
	string death;
public:
	poet();
	poet(ifstream& f);

	void data();
	
	void printData();


	void showall(int col = 1) override;
	void writeall(ofstream& f) override;
	
	void redakone(int a) override;
	

	~poet();
	
};