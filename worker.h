#pragma once
#include <string>
#include <fstream>
#include <iostream>
class worker
{
public:
	worker();
	~worker();
	worker(std::string fami, std::string namei, std::string onamei, std::string positioni, int yeari);
	worker(const worker& copy);
	void setpar();
	void setpar(std::string fami, std::string namei, std::string onamei, std::string positioni, int yeari);
	void getpar();
	std::string getfam();
	int getYear();
private:
	std::string name;
	std::string fname;
	std::string oname;
	std::string position;
	int year;

};

