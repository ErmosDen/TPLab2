#pragma warning(disable : 4996)
#include "elem.h"
#include <iostream>
#include <ctime> 
#include <time.h>
class keeper
{
public:
	keeper();
	~keeper();
	keeper(int size);

private:
	int size;
	elem* head;
public:
	//keeper operator++(int);
	void push(worker* w);

	worker* operator[] (const int index);

	void rm(int index);
	void sort();
	void showExp(int year);
	int getsize();
};

