#include "ffstream.h"


ffstream::ffstream() 
{

}

ffstream::~ffstream() 
{
    std::cout << "деструктор класса ffstr" << std::endl;
}

void ffstream::scantext() 
{
    std::string str;
    std::ifstream ifs;
    ifs.open("infile.txt");
    try {
        if (!ifs.is_open())
        {
            throw "Ошибка открытия файла";
        }

        else
        {
            std::stringstream iss;
            char c;
            std::string token;
            int flag = 0;
            while (getline(ifs, str))
            {
                iss << str;
                do {
                    c = iss.get();
                    if (c == ',') { flag = 1; }
                    token.push_back(c);
                    if (c == '.' || c=='?' || c=='!')
                    {
                        if (flag == 0)
                        std::cout << token << std::endl;
                        flag = 0;
                        token.clear();
                    }
                } while (c!= EOF);
                iss.clear();
            }
            ifs.close();
            return;
        }

    }
    catch (const char* exception) // обработчик исключений типа const char*
    {
        std::cerr << "Error: " << exception << '\n';
    }
}