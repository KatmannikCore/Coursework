#include <iostream>
#include <string>
#include <deque>
#include <Windows.h>
using namespace std;

class Commandant
{
public:

    string surname;
    string name;
    string patronymic;

    void addCommandeant()
    {
        cout << "Введите имя коменданта" << endl;
        cin >> name;
        cout << "Введите фамилию коменданта" << endl;
        cin >> surname;
        cout << "Введите отчество коменданта" << endl;
        cin >> patronymic;
    }
    string printCommandeant()
    {
        return "Имя - " + name + " Фамилия - " + surname + " Отчество - " + patronymic + "\n";
    }
};
class Passport
{
public:
    string status = "Здание в прядке";
    deque<Commandant> Commandants;
    void removeStatus(string newStatus)
    {
        status = newStatus;
        cout << "Статус изменён" << endl; 
    }
    string printPassport()
    {
        string result = status + "\n";
        for (int i = 0; i < Commandants.size(); i++)
        {
            result += Commandants[i].printCommandeant();
        }
        return result;
    }
};

class Building
{
public:
    string sizeFloor;
    string sizeApartments;
    string Area;
    Passport passport;

    void addBuilding()
    {
        cout << "Введите колличество этажей" <<endl;
        cin >> sizeFloor;
        cout << "Введите колличество комнат" << endl;
        cin >> sizeApartments;
        cout << "Введите площадь здания" << endl;
        cin >> Area;
    }
    void printBuilding()
    {
        string result = "Колличество этажей - " + sizeFloor + " Колличество комнат - " + sizeApartments + " Площадь - " + Area + "\n";
        result += passport.printPassport();
        cout << result << endl;
    }
};




int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    deque<Building> Buildings;
    Building building;
    Commandant commandant;
    while (true)
    {
        cout << "1 - Добавить здание" <<endl;
        cout << "2 - Просмотр данных всех зданий" << endl;
        cout << "3 - Добавить коменданта в здание" << endl;
        cout << "4 - Изменить статус здания" << endl;
        cout << "5 - Вывести здания нуждающиеся в ремонте" << endl;
        int select;
        int selectStatus;
        int selectPrintStatus;
        cout << "Выберите операцию" <<endl;
        cin >> select;
        int number;
        bool selection = false;
        switch (select)
        {
        case 1:
            building.addBuilding();
            Buildings.push_back(building);
            break;
        case 2:
            for (int i = 0; i < Buildings.size(); i++)
            {
                Buildings[i].printBuilding();
            }
            break;
        case 3:
            cout << "Введите номер здания:" << endl;
            cout << "Колличество эллентов: " << Buildings.size() << endl;
            cin >> number;
            for (int i = 0; i < Buildings.size(); i++)
            {
                if (i == number - 1)
                {
                    commandant.addCommandeant();
                    Buildings[i].passport.Commandants.push_back(commandant);
                    selection = true;
                    cout << "Комендант добавлена" << endl;
                }
            }
            if (!selection)
            {
                cout << "Данного номера не существует" << endl;
            }
            break;
        case 4:
            cout << "Введите номер здания:" << endl;
            cout << "Колличество эллентов: " << Buildings.size() << endl;
            cin >> number;
            for (int i = 0; i < Buildings.size(); i++)
            {
                if (i == number - 1)
                {
                    cout <<"Выберите новый статус" <<endl;
                    cout << "1 - Теребуется капитальный ремонт" << endl;
                    cout << "2 - Теребуется космитический ремонт" << endl;
                    cout << "3 - Здание в прядке" << endl;
                    cin >> selectStatus;
                    switch (selectStatus)
                    {
                    case 1:
                        Buildings[i].passport.removeStatus("Теребуется капитальный ремонт");
                        break;
                    case 2:
                        Buildings[i].passport.removeStatus("Теребуется космитический ремонт");
                        break;
                    case 3:
                        Buildings[i].passport.removeStatus("Здание в прядке");
                        break;
                    default:
                        cout << "Неверно введен пункт" << endl;
                        break;
                    }
                    selection = true;
                    cout << "Комендант добавлена" << endl;
                }
            }
            if (!selection)
            {
                cout << "Данного номера не существует" << endl;
            }
            break;
        case 5:
            cout << "Введите какой статус здания для просмотра" <<endl;
            cout << "1 - Капитальный ремонт" <<endl;
            cout << "2 - Касметический ремонт" << endl;
            cin >> selectPrintStatus;
            switch (selectPrintStatus)
            {
            case 1:
                for (int i = 0; i < Buildings.size(); i++)
                {
                    if (Buildings[i].passport.status == "Теребуется капитальный ремонт")
                    {
                        Buildings[i].printBuilding();
                    }
                }
                break;
            case 2:
                for (int i = 0; i < Buildings.size(); i++)
                {
                    if (Buildings[i].passport.status == "Теребуется космитический ремонт")
                    {
                        Buildings[i].printBuilding();
                    }
                }
                break;
            default:
                cout << "Неверно введен пункт" << endl;
                break;
            }
            break;
        default:
            cout << "Неверно введен пункт" <<endl;
            break;
        }
    }

}

