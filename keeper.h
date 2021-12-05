#pragma once
#include "elem.h"
#include <iostream>
#include <ctime> 
class keeper
{
public:
	keeper();
	~keeper();
	keeper(int size);

private:
	int size;
	elem* head;
	elem* node;
public:
	keeper operator++(int);
	void rm(int index);
	void showExp(int year)
};

