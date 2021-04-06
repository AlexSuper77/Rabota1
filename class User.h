#pragma once
#include <iostream>
#include <string>
using namespace std;
class User //Класс юзеров
{
private:
    string _name;
    string _login;
    string _password;
public:
    User(string name, string login, string password);

    void Accaunt(bool* p, string lo, string pa)//Функция проверки логина и пароля
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
    void VerificationUser(string name)//Функция проверки на существование уже существующих имени и логина при регистрации
    {
        if (name == _name)
        {
            throw "Такое имя уже зарегестрированно, придумайте другое";
        }
        if (name == _login)
        {
            throw "Такой логин уже зарегестрирован, придумайте другой";
        }
    }
    void Display(int us) //Функция вывода на консоль меню в учётной записи.
    {
        cout << "Добро пожаловать в чат " << _name << endl;
        cout << "Выберите действие:\n";
        cout << "1 - Отправить сообщение\n";
        cout << "2 - Отправить сообщение всем\n";
        if (us == 1) //Часть меню для администратора
        {
            cout << "3 - Показать всех юзеров\n";
            cout << "4 - Показать все сообщения\n";
            cout << "5 - Удалить юзера\n";
        }
        cout << "0 - Выйти из аккаунта\n";
        cout << "Вам сообщение:\n";
    }
    void Name()//Функция вывода имени на консоль
    {
        cout << _name;
    }
    int DisplayUsers(int i)//Функция вывода всех юзеров на консоль
    {
        if (_name != ("0"))
        {
            cout << i << " " << _name << endl;
        }
        return 0;
    }
    void DisplayUsersAll(int i)//Функция вывода всех юзеров на консоль, для администратора
    {
        if (_name != ("0"))
        {
            cout << i << " - " << "Имя: " << _name << " Логин: " << _login << " Пароль:" << _password << endl;
        }
    }
    void ZeroUser(bool* pr)//Функция ищет пустой индекс в массиве для нового юзера
    {
        if (_name == ("0"))
        {
            *pr = 1;
        }
    }
    ~User() {}
};