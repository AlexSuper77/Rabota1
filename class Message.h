#pragma once
#include <iostream>
#include <string>
using namespace std;
class Message //Класс сообщений
{
private:
    int _ot_kogo;
    int _komu;
    string _message;
public:
    Message(int ot_kogo, int komu, string message);

    void DisplayMessageAll(int* otkogo, int* komu, string* mess) //Функция выводит все сообщения на консоль
    {
        *otkogo = _ot_kogo;
        *komu = _komu;
        *mess = _message;
    }
    void Zero(bool* pr)//Функция ищет пустой индех в массиве для помещения в него сообщения
    {
        if (_ot_kogo == 0)
        {
            *pr = 1;
        }
    }
    ~Message() {}
};
Message::Message(int ot_kogo, int komu, string message) :
    _ot_kogo(ot_kogo), _komu(komu), _message(message) {}
