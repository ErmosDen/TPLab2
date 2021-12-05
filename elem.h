#pragma once
#include "worker.h"
#include <iostream>
class elem
{
public:
	elem* next;
	elem* prev;
	worker* c_data;
};

