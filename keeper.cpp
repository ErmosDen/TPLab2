#include "keeper.h"

keeper::keeper() : size(0), head(NULL) {}
keeper::keeper(int size) : head(NULL) { this->size = size; }
keeper::~keeper()
{
	if (head != NULL) {
		elem* buffer;
		while (head->next != NULL)
		{
			buffer = head;
			head = head->next;
			buffer->c_data->~worker();
			delete(buffer);
		}
		head->c_data->~worker();
		delete(head);
	}
}

keeper::keeper(const keeper& copy)
{
	head = copy.head;
	elem* tmp1 = head;
	elem* tmp2 = copy.head;
	elem* newhead = tmp1;
	if (copy.head == nullptr) {
		head = copy.head;
		size = copy.size;
		return;
	}
	if (copy.head->next == 0) //Если в списке 1 элемент
	{
		tmp1->c_data = tmp2->c_data;
		tmp1->next = 0;
		size = copy.size;
		return;
	}
	while (tmp2->next != 0)
	{
		tmp1->c_data=tmp2->c_data;
		tmp1->next = tmp2->next;
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}
	tmp1->c_data=tmp2->c_data;
	tmp1->next=0;
	size = copy.size;
	return;
	std::cout << "Конструктор копирования keeper" << std::endl;
}


void keeper::push(int index)
{
	elem* buf = head;
	elem* buf1;
	if (size == 0) {
		std::cout << "Нечего удалять" << std::endl;
		return;
	}
	if (((index) >= size) || (index < 0)) {
		std::cout << "Неверный индекс" << std::endl;
	}

	else {
		if (buf->next == NULL) {
			std::cout << "удаляется последняя и единственная запись" << std::endl;
			buf->c_data->~worker();
			size--;
			return;
		}
		if (index == 0)
		{
			head = buf->next;
			head->prev = 0;
			buf->c_data->~worker();
			size--;
			return;
		}
		for (int i = 0; i < index - 1; i++) {
			buf = buf->next; //Переходим на элемент перед удаляемым
		}
		buf1 = buf->next; //переходим на удаляемый элемент
		buf->next = buf1->next;//присавеваем указатель на следующий

		buf1->c_data->~worker();
		size--;
	}
	sort();
}


void keeper::push(worker* w) {
	elem* newElem;
	newElem = new elem;
	if (size == 0)
	{
		newElem->c_data = w;
		size++;
		newElem->next = 0;
		newElem->prev = 0;
		head = newElem;
	}
	else
	{
		elem* buf = head;
		while (buf->next != NULL)
		{
			buf = buf->next;
		}
		newElem->c_data = w;
		newElem->next = 0;
		newElem->prev = buf;
		buf->next = newElem;
		size++;
	}
	sort();
}


void keeper::showExp(int year) 
{

	time_t theTime = time(NULL);
	struct tm* aTime = localtime(&theTime);


#pragma warning(disable : 4996)
	int cYear = aTime->tm_year + 1900; //взяли текущий год
	int num=0;

	std::cout << "Текущий год " << cYear << std::endl;
	if (size == 0) {
		std::cout << "Нечего выводить" << std::endl;
		return;
	}
	elem* buf = head;
	while (buf != NULL)
	{
		if ((cYear - buf->c_data->getYear()) >= year) 
		{
			buf->c_data->getpar();
			num++;
		}
		buf = buf->next;
	}
	if (num == 0) 
	{
		std::cout << "Работников не найдено" << std::endl;
		return;
	}
}


int keeper::getsize()
{
	return size;
}

worker* keeper::operator[] (const int index)
{
	elem* buf = head;
	if (((index) >= size) || (index < 0)) {
		std::cout << "Неверный индекс" << std::endl;
	}
	else {
		for (int i = 0; i < index; i++) {
			buf = buf->next;
		}
		return (buf->c_data);
	}
}

void keeper::sort()
{
	if (size <= 1)
	{
		std::cout << "Нечего сортировать" << std::endl;
		return;
	}
	elem* left = head;                 //Первый элемент — это пусть будет голова
	elem* right = head->next;          //Второй элемент — это пусть будет следующий за головой элемент

	elem* temp = new elem;              //Временное звено для хранения переставляемого всех значений переставляемого звена

	while (left->next) 
	{                 //Обходим по всем звеньям, за исключением крайнего правого
		while (right) 
		{              //Обходим по всем звеньям, включая крайний правый (по всем относительно первого левого на текущий момент)
			std::string lper = left->c_data->getfam();
			std::string rper = right->c_data->getfam();
			if (lper.compare(rper)>0) {        //Проверяем необходимость перестановки
				temp->c_data = left->c_data;              //И переставляем все внутренние элементы, за исключением указателей связи, местами
				left->c_data = right->c_data;             //Сейчас у нас имеется только x, поэтому только его
				right->c_data = temp->c_data;             //иначе бы  нужно было это проделывать для каждого несвязующего элемента
			}
			right = right->next;                    //не забываем направлять указатель на следующий элемент (по подобию инкремента), иначе цикл зависнет
		}
		left = left->next;                              //не забываем направлять указатель на следующий элемент (по подобию инкремента), иначе цикл зависнет
		right = left->next;                             //Поскольку второй указатель убежал немного вперёд, обязательно возвращаем его назад, это следующий элемент относительно текущего первог
	}
}