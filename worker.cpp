#include "worker.h"

worker::worker()
{
	std::cout << "конструктор класса worker" << std::endl;
}

worker::~worker()
{
	std::cout << "деструктор класса worker" << std::endl;
}

worker::worker(const worker& copy)
{
	name = copy.name;
	fname = copy.fname;
	oname = copy.oname;
	position = copy.position;
	year = copy.year;
	std::cout << "Вызов конструктора копирования worker" << std::endl;
}

worker::worker(std::string fami, std::string namei, std::string onamei, std::string positioni, int yeari) {
	this->fname = fami;
	this->name = namei;
	this->oname = onamei;
	this->position = positioni;
	this->year = yeari;
	std::cout << "Вызов конструктора c параметром worker" << std::endl;
}

void worker::setpar()
{
	std::cin.ignore(32767, '\n');
	std::cout << "Введите фамилию рабочего" << std::endl;
	getline(std::cin, fname);
	std::cout << "Введите имя рабочего" << std::endl;
	std::getline(std::cin, name);
	std::cout << "Введите отчество рабочего" << std::endl;
	std::getline(std::cin, oname);
	std::cout << "Введите должность рабочего" << std::endl;
	getline(std::cin, position);
	std::cout << "Введите год поступления на работу" << std::endl;
	std::cin >> year;
}

void worker::setpar(std::string fami, std::string namei, std::string onamei, std::string positioni, int yeari) {
	this->fname = fami;
	this->name = namei;
	this->oname = onamei;
	this->position = positioni;
	this->year = yeari;
}

void worker::getpar()
{
	std::cout << "Информация о машине:" << std::endl;
	std::cout << "Фамилия - " << fname << std::endl;
	std::cout << "Имя - " << name << std::endl;
	std::cout << "Отчество - " << oname << std::endl;
	std::cout << "Должность - " << position << std::endl;
	std::cout << "год поступления на работу - " << year << std::endl;
	std::cout << std::endl;
}

std::string worker::getfam() 
{
	return this->fname;
}

int worker::getYear() 
{
	return this->year;
}


