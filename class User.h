#pragma once
#include <iostream>
#include <string>
using namespace std;
class User //����� ������
{
private:
    string _name;
    string _login;
    string _password;
public:
    User(string name, string login, string password);

    void Accaunt(bool* p, string lo, string pa)//������� �������� ������ � ������
    {
        if (lo == _login & pa == _password)
        {
            *p = 1;
        }
        else
        {
            *p = 0;
        }
    }
    void VerificationUser(string name)//������� �������� �� ������������� ��� ������������ ����� � ������ ��� �����������
    {
        if (name == _name)
        {
            throw "����� ��� ��� �����������������, ���������� ������";
        }
        if (name == _login)
        {
            throw "����� ����� ��� ���������������, ���������� ������";
        }
    }
    void Display(int us) //������� ������ �� ������� ���� � ������� ������.
    {
        cout << "����� ���������� � ��� " << _name << endl;
        cout << "�������� ��������:\n";
        cout << "1 - ��������� ���������\n";
        cout << "2 - ��������� ��������� ����\n";
        if (us == 1) //����� ���� ��� ��������������
        {
            cout << "3 - �������� ���� ������\n";
            cout << "4 - �������� ��� ���������\n";
            cout << "5 - ������� �����\n";
        }
        cout << "0 - ����� �� ��������\n";
        cout << "��� ���������:\n";
    }
    void Name()//������� ������ ����� �� �������
    {
        cout << _name;
    }
    int DisplayUsers(int i)//������� ������ ���� ������ �� �������
    {
        if (_name != ("0"))
        {
            cout << i << " " << _name << endl;
        }
        return 0;
    }
    void DisplayUsersAll(int i)//������� ������ ���� ������ �� �������, ��� ��������������
    {
        if (_name != ("0"))
        {
            cout << i << " - " << "���: " << _name << " �����: " << _login << " ������:" << _password << endl;
        }
    }
    void ZeroUser(bool* pr)//������� ���� ������ ������ � ������� ��� ������ �����
    {
        if (_name == ("0"))
        {
            *pr = 1;
        }
    }
    ~User() {}
};