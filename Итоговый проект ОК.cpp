#include"class Message.h"
#include"class User.h"


User::User(string name, string login, string password) :
    _name(name), _login(login), _password(password) {}

int main()
{
    setlocale(LC_ALL, "Russian");
    const int sizem = 200;
    Message* message[sizem];//Создаём массив сообщений и заполняем его нулями
    for (int i = 0; i < sizem; ++i)
    {
        message[i] = new Message(int(0), int(0), string("0"));
    }
    message[0] = new Message(int(2), int(3), string("Привет Даша!!!"));//Заполняем массив данными для примера
    message[1] = new Message(int(3), int(2), string("Привет Петя!!!"));
    message[2] = new Message(int(2), int(3), string("Как дела Даша!!!"));
    message[3] = new Message(int(3), int(2), string("Как дела Петя!!!"));
    message[4] = new Message(int(2), int(201), string("Всем привет от Пети!!!"));
    const int size = 100;
    User* user[size];//Создаём массив юзеров и заполняем его нулями
    for (int i = 0; i < size; ++i)
    {
        user[i] = new User(string("0"), string("0"), string("0"));
    }
    user[1] = new User(string("Администратор"), string("ad"), string("1"));//Заполняем массив данными для примера
    user[2] = new User(string("Pety"), string("p"), string("2"));
    user[3] = new User(string("Dasha"), string("d"), string("3"));
    int menu1 = 0;//Содаём переменные для меню
    int menu2 = 0;
    do {
        int us = 0;//Переменная для идентификации индекса юзера
        string log;//Переменные для логина, пароля и имени юзера
        string pass;
        string name_new;
        int otkogo =0;//Переменные для сообщения
        int komu =0;
        string mess;
        bool pr = 0;//Переменная для нахождения пустой ячейки в массиве
        int nom_index = 0;//Переменные для написания сообщения
        int komu_message = 0;
        string komu_messag;
        cout << "Выберите действие:\n";//Главное меню
        cout << "1 - Войти в свой аккаунт\n";
        cout << "2 - Зарегестрироваться\n";
        cout << "0 - Выйти из программы\n";
        cin >> menu1;
        switch (menu1)
        {
        case 1:
            cout << "Введите логин ";
            cin >> log;
            cout << "Введите пароль ";
            cin >> pass;
            for (int i = 0; i < size; ++i)//Проверка логина и пароля
            {
                user[i]->Accaunt(&pr, log, pass);
                if (pr == 1)
                {
                    us = i;
                    break;
                }
            }
            if (pr == 1)
            {
                do {
                    user[us]->Display(us);//Вывод меню юзера, если логин и пароль совпали

                    for (int i = 0; i < sizem; ++i)
                    {
                        message[i]->DisplayMessageAll(&otkogo, &komu, &mess);//Вывод на консоль всех сообщений юзера
                        if (us == komu)
                        {
                            cout << mess << " ";
                            cout << "От: ";
                            user[otkogo]->Name();//Вывод имени юзера
                            cout << endl;
                        }
                        if (us == otkogo)
                        {
                            cout << "Вы: " << mess << endl;
                        }
                        if (komu == 201)
                            cout << "Всем: " << mess << endl;
                    }

                    cin >> menu2;
                    switch (menu2)
                    {
                    case 1://Отправка сообщения конкретному пользователю
                    {
                        cout << "Выберите кому хотите отправить сообщение:\n";
                        for (int i = 0; i < size; ++i)//Вывод на консоль всех пользователей для выбора
                        {
                            user[i]->DisplayUsers(i);
                        }
                        cin >> komu_message;//Ввод сообщения
                        user[komu_message]->Name();
                        cout << ":";
                        cin >> komu_messag;
                        for (int i = 0; i < sizem; ++i)//Ищем пустой индекс в массиве message
                        {
                            message[i]->Zero(&pr);
                            if (pr == 1)
                            {
                                nom_index = i;
                                break;
                            }
                        }
                        pr = 0;
                        message[nom_index] = new Message(int(us), int(komu_message), string(komu_messag)); //Заполняем сообщением и кому и от кого
                    }
                    break;
                    case 2://Отправка сообщения всем
                    {
                        cout << "Всем: ";
                        cin >> komu_messag;//Ввод сообщения
                        for (int i = 0; i < sizem; ++i)
                        {
                            message[i]->Zero(&pr);//Ищем пустой индекс в массиве message
                            if (pr == 1)
                            {
                                nom_index = i;
                                break;
                            }
                        }
                        message[nom_index] = new Message(int(us), int(201), string(komu_messag));//Заполняем сообщением и кому и от кого. Для всех 201.
                    }
                    break;
                    case 3:
                        for (int i = 0; i < size; ++i)//Вывод всех юзеров на консоль с именами, логинами и паролями для администратора
                        {
                            user[i]->DisplayUsersAll(i);
                        }
                        break;
                    case 4:
                        for (int i = 0; i < sizem; ++i)
                        {
                            message[i]->DisplayMessageAll(&otkogo, &komu, &mess);//Вывод всех сообщений для администратора
                            if (otkogo != 0)
                            {
                                cout << "Кому: ";
                                if (komu == 201)
                                {
                                    cout << "Всем";
                                }
                                else
                                {
                                    user[komu]->Name();
                                }
                                cout << " " << mess << " От кого: ";
                                user[otkogo]->Name();
                                cout << endl;
                            }
                        }
                        cout << endl;
                        break;
                    case 5:
                        cout << "Выберите кого надо удалить\n";
                        for (int i = 0; i < size; ++i)
                        {
                            user[i]->DisplayUsersAll(i);//Удаление юзера для администратора
                        }
                        int use;
                        cin >> use;
                        user[use] = new User(string("0"), string("0"), string("0"));
                        break;
                    }
                } while (menu2 != 0);
            }
            else
            {
                cout << "Неправильный логин и/или пароль" << endl;//Если логин или пароль не правильный
            }
            break;
        case 2://Регистрация нового пользователя
            try
            {
                cout << "Введите имя: ";
                cin >> name_new;
                for (int i = 0; i < size; ++i)//Проверка на зарегестрированное имя
                {
                    user[i]->VerificationUser(name_new);
                }
                cout << "Введите логин: ";
                cin >> log;
                for (int i = 0; i < size; ++i)//Проверка на зарегестрированный логин
                {
                    user[i]->VerificationUser(log);
                }
                cout << "Введите пароль: ";
                cin >> pass;
                for (int i = 1; i < size - 1; ++i)
                {
                    user[i]->ZeroUser(&pr);//Ищем пустой индекс в массиве User
                    if (pr == 1)
                    {
                        us = i;
                        break;
                    }
                }
                user[us] = new User(string(name_new), string(log), string(pass));//Заполняем данными нового юзера 
            }
            catch (const char* e)
            {
                cout << e << endl;//Обработка если имя или логин уже зарегестрированны
            }
            break;
        }
    } while (menu1 != 0);
 
    return 0;
}

