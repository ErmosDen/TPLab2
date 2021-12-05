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


void keeper::rm(int index)
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
}


void keeper::push(worker* w) {
	elem* newElem;
	newElem = new elem;
	if (size == 0)
	{
		newElem->c_data = f;
		size++;
		newElem->next = 0;
		head = newElem;
	}
	else
	{
		elem* buf = head;
		while (buf->next != NULL)
		{
			buf = buf->next;
		}
		newElem->c_data = f;
		newElem->next = 0;
		buf->next = newElem;
		size++;
	}

}	


void keeper::showExp(int year) 
{
	std::time_t t = std::time(nullptr);
	std::tm* const pTInfo = std::localtime(&t);
	int cYear = 1900 + pTInfo->tm_year; //взяли текущий год

}