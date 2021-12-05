#include <iostream>
#include <Windows.h>
#include <clocale>
#include "keeper.h"
#include "worker.h"
#include "ffstream.h"

int main(void) {

    int choose1;
    int id1, id2;
    int year;
    std::string znach;
    keeper keep;
    ffstream fstr;
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    do {
        std::cout << "1 Добавить работника " << std::endl;
        std::cout << "2 Изменить работника" << std::endl;
        std::cout << "3 Удалить работника " << std::endl;
        std::cout << "4 Вывести всех работников " << std::endl;
        std::cout << "5 Вывести работников, чей стаж больше введенного " << std::endl;
        std::cout << "6 Вывести предложения не содержащие запятых" << std::endl;
        std::cout << "0 Выход " << std::endl;
        std::cin >> choose1;
        std::cin.ignore(32767, '\n');
        switch (choose1)
        {
        case 1:
            worker * work;
            work = new worker;
            work->setpar();
            keep.push(work);
            break;
        case 2:
            if (keep.getsize() == 0) { std::cout << "Нечего изменять" << std::endl; break; }
            std::cout << "Какую запись изменить, всего записей - " << keep.getsize() - 1 << " нумерация с 0" << std::endl;
            std::cin >> id1;
            std::cin.ignore(32767, '\n');
            keep[id1]->getpar();
            std::cout << "какой параметр изменить " << std::endl;
            std::cin >> id2;
            std::cin.ignore(32767, '\n');
            std::cout << "на что изменить" << std::endl;
            getline(std::cin, znach);
            std::cin.ignore(32767, '\n');
            keep[id1]->change(id2, znach);
            keep.sort();
            break;
        case 3:
            std::cout << "Какую запись удалить, всего записей - " << keep.getsize() - 1 << " нумерация с 0" << std::endl;
            std::cin >> id1;
            std::cin.ignore(32767, '\n');
            keep.rm(id1);
            break;
        case 4:
            for (int i = 0; i < keep.getsize(); i++)
            {
                keep[i]->getpar();
            }
            break;
        case 5:
            std::cout << "Введите число лет стажа " << std::endl;
            std::cin >> year;
            std::cin.ignore(32767, '\n');
            keep.showExp(year);
            break;
        case 6:
            fstr.scantext();
            break;
        case 0:
            break;
        default:
            std::cout << "неверны ввод" << std::endl;
            break;
        }
    } while (choose1 != 0);
}