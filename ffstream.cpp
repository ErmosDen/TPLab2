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
            std::string token;
            while (getline(ifs, str))
            {
                iss << str;
                    while (std::getline(iss, token, '.')) 
                    {
                        if (token.find(',') == std::string::npos) {
                        std::cout << token << std::endl;
                        }
                    }
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