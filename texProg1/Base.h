#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include<conio.h>
#include <Windows.h>
#include <fstream>
using namespace std;
class Base
	
{
public:
	string fio;
	string* proz;
	int nproz;

	string getfio() ;

	string* getproz();
	int getnproz();
	void setfio();
	
	void setproz();
	virtual void showall(int col = 1) = 0;

	virtual void writeall(ofstream& f) = 0;

	virtual ~Base() = 0;

	virtual void redakone(int a) = 0;
};