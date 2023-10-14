#pragma once

#include"Base.h"
#include"Poet.h"
#include"Roman.h"
#include"Fantast.h"
class Keeper {
	Base** arr;
	int n;
public:
	Keeper();
	Keeper(const Keeper& other);
	~Keeper();
	Keeper operator +(int a);

	void ShowAll();

	void save();
	void read();
	void delet();

	void fiooutput();

	void redak();

};