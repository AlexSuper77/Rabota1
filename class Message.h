#pragma once
#include <iostream>
#include <string>
using namespace std;
class Message //����� ���������
{
private:
    int _ot_kogo;
    int _komu;
    string _message;
public:
    Message(int ot_kogo, int komu, string message);

    void DisplayMessageAll(int* otkogo, int* komu, string* mess) //������� ������� ��� ��������� �� �������
    {
        *otkogo = _ot_kogo;
        *komu = _komu;
        *mess = _message;
    }
    void Zero(bool* pr)//������� ���� ������ ����� � ������� ��� ��������� � ���� ���������
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
