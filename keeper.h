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
	keeper(const keeper& copy);

private:
	int size;
	elem* head;
public:
	//keeper operator++(int);
	void push(worker* w);
	void push(int index);

	worker* operator[] (const int index);

	void sort();
	void showExp(int year);
	int getsize();
};

