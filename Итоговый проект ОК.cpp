#include"class Message.h"
#include"class User.h"


User::User(string name, string login, string password) :
    _name(name), _login(login), _password(password) {}

int main()
{
    setlocale(LC_ALL, "Russian");
    const int sizem = 200;
    Message* message[sizem];//������ ������ ��������� � ��������� ��� ������
    for (int i = 0; i < sizem; ++i)
    {
        message[i] = new Message(int(0), int(0), string("0"));
    }
    message[0] = new Message(int(2), int(3), string("������ ����!!!"));//��������� ������ ������� ��� �������
    message[1] = new Message(int(3), int(2), string("������ ����!!!"));
    message[2] = new Message(int(2), int(3), string("��� ���� ����!!!"));
    message[3] = new Message(int(3), int(2), string("��� ���� ����!!!"));
    message[4] = new Message(int(2), int(201), string("���� ������ �� ����!!!"));
    const int size = 100;
    User* user[size];//������ ������ ������ � ��������� ��� ������
    for (int i = 0; i < size; ++i)
    {
        user[i] = new User(string("0"), string("0"), string("0"));
    }
    user[1] = new User(string("�������������"), string("ad"), string("1"));//��������� ������ ������� ��� �������
    user[2] = new User(string("Pety"), string("p"), string("2"));
    user[3] = new User(string("Dasha"), string("d"), string("3"));
    int menu1 = 0;//����� ���������� ��� ����
    int menu2 = 0;
    do {
        int us = 0;//���������� ��� ������������� ������� �����
        string log;//���������� ��� ������, ������ � ����� �����
        string pass;
        string name_new;
        int otkogo =0;//���������� ��� ���������
        int komu =0;
        string mess;
        bool pr = 0;//���������� ��� ���������� ������ ������ � �������
        int nom_index = 0;//���������� ��� ��������� ���������
        int komu_message = 0;
        string komu_messag;
        cout << "�������� ��������:\n";//������� ����
        cout << "1 - ����� � ���� �������\n";
        cout << "2 - ������������������\n";
        cout << "0 - ����� �� ���������\n";
        cin >> menu1;
        switch (menu1)
        {
        case 1:
            cout << "������� ����� ";
            cin >> log;
            cout << "������� ������ ";
            cin >> pass;
            for (int i = 0; i < size; ++i)//�������� ������ � ������
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
                    user[us]->Display(us);//����� ���� �����, ���� ����� � ������ �������

                    for (int i = 0; i < sizem; ++i)
                    {
                        message[i]->DisplayMessageAll(&otkogo, &komu, &mess);//����� �� ������� ���� ��������� �����
                        if (us == komu)
                        {
                            cout << mess << " ";
                            cout << "��: ";
                            user[otkogo]->Name();//����� ����� �����
                            cout << endl;
                        }
                        if (us == otkogo)
                        {
                            cout << "��: " << mess << endl;
                        }
                        if (komu == 201)
                            cout << "����: " << mess << endl;
                    }

                    cin >> menu2;
                    switch (menu2)
                    {
                    case 1://�������� ��������� ����������� ������������
                    {
                        cout << "�������� ���� ������ ��������� ���������:\n";
                        for (int i = 0; i < size; ++i)//����� �� ������� ���� ������������� ��� ������
                        {
                            user[i]->DisplayUsers(i);
                        }
                        cin >> komu_message;//���� ���������
                        user[komu_message]->Name();
                        cout << ":";
                        cin >> komu_messag;
                        for (int i = 0; i < sizem; ++i)//���� ������ ������ � ������� message
                        {
                            message[i]->Zero(&pr);
                            if (pr == 1)
                            {
                                nom_index = i;
                                break;
                            }
                        }
                        pr = 0;
                        message[nom_index] = new Message(int(us), int(komu_message), string(komu_messag)); //��������� ���������� � ���� � �� ����
                    }
                    break;
                    case 2://�������� ��������� ����
                    {
                        cout << "����: ";
                        cin >> komu_messag;//���� ���������
                        for (int i = 0; i < sizem; ++i)
                        {
                            message[i]->Zero(&pr);//���� ������ ������ � ������� message
                            if (pr == 1)
                            {
                                nom_index = i;
                                break;
                            }
                        }
                        message[nom_index] = new Message(int(us), int(201), string(komu_messag));//��������� ���������� � ���� � �� ����. ��� ���� 201.
                    }
                    break;
                    case 3:
                        for (int i = 0; i < size; ++i)//����� ���� ������ �� ������� � �������, �������� � �������� ��� ��������������
                        {
                            user[i]->DisplayUsersAll(i);
                        }
                        break;
                    case 4:
                        for (int i = 0; i < sizem; ++i)
                        {
                            message[i]->DisplayMessageAll(&otkogo, &komu, &mess);//����� ���� ��������� ��� ��������������
                            if (otkogo != 0)
                            {
                                cout << "����: ";
                                if (komu == 201)
                                {
                                    cout << "����";
                                }
                                else
                                {
                                    user[komu]->Name();
                                }
                                cout << " " << mess << " �� ����: ";
                                user[otkogo]->Name();
                                cout << endl;
                            }
                        }
                        cout << endl;
                        break;
                    case 5:
                        cout << "�������� ���� ���� �������\n";
                        for (int i = 0; i < size; ++i)
                        {
                            user[i]->DisplayUsersAll(i);//�������� ����� ��� ��������������
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
                cout << "������������ ����� �/��� ������" << endl;//���� ����� ��� ������ �� ����������
            }
            break;
        case 2://����������� ������ ������������
            try
            {
                cout << "������� ���: ";
                cin >> name_new;
                for (int i = 0; i < size; ++i)//�������� �� ������������������ ���
                {
                    user[i]->VerificationUser(name_new);
                }
                cout << "������� �����: ";
                cin >> log;
                for (int i = 0; i < size; ++i)//�������� �� ������������������ �����
                {
                    user[i]->VerificationUser(log);
                }
                cout << "������� ������: ";
                cin >> pass;
                for (int i = 1; i < size - 1; ++i)
                {
                    user[i]->ZeroUser(&pr);//���� ������ ������ � ������� User
                    if (pr == 1)
                    {
                        us = i;
                        break;
                    }
                }
                user[us] = new User(string(name_new), string(log), string(pass));//��������� ������� ������ ����� 
            }
            catch (const char* e)
            {
                cout << e << endl;//��������� ���� ��� ��� ����� ��� �����������������
            }
            break;
        }
    } while (menu1 != 0);
 
    return 0;
}

