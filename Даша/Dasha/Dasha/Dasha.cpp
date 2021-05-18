#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <list>
#include <deque>

using namespace std;
class Path
{
public:
    int Length;
    int Tonnage;
    int Type;
    int Damage;
    string Name;

    Path(int length, int tonnage, int type, int damage, string name)
    {
        Length = length;
        Tonnage = tonnage;
        Type = type;
        Damage = damage;
        Name = name;
    }
    string Print()
    {
        return "Length - " + to_string(Length) + " Tonnage - " + to_string(Tonnage) + " type - " + to_string(Type) + " Damage - " + to_string(Damage);
    }


};

int main()
{
    setlocale(LC_ALL, "Russian");

    deque<Path> paths;
    Path value1(250 ,40000, 1, 100, "Минск-Орша");
    paths.push_back(value1);
    Path value2(490, 30000, 2, 100, "Минск-Гомель");
    paths.push_back(value2);
    Path value3(800, 90000, 3, 100, "Минск-Москва");
    paths.push_back(value3);
    deque<Path>  overhaul;
    deque<Path> redecorating;
    while (true)
    {
        cout << " Выберите желаему операцию:" << endl;
        cout << " 1 - Просмотреть весь список путей" << endl;
        cout << " 2 - Перемотать время" << endl;
        cout << " 3 - Просмотреть список ремонта" << endl;
        cout << " 4 - Отправить отчёты для ремонта" << endl;
        int selection;
        cin >> selection;
        switch (selection)
        {
        case 1:
            for (int i = 0; i < paths.size(); i++)
            {
                cout << paths[i].Print() << endl;
            }
            break;
        case 2:
            for (int i = 0; i < paths.size(); i++)
            {
                int type = paths[i].Type;
                switch (type)
                {
                case 1:
                    paths[i].Damage -= 10;
                    break;
                case 2:
                    paths[i].Damage -= 15;
                    break;
                case 3:
                    paths[i].Damage -= 20;
                    break;
                default:
                    break;
                }
            }
            break;
        case 3:
            for (int i = 0; i < paths.size(); i++)
            {
                int type = paths[i].Type;
                switch (type)
                {
                case 1:
                    if (paths[i].Damage > 40 && paths[i].Damage < 90)
                    {
                        cout<< "Путь необходим косметический ремонт\n" + paths[i].Print() <<endl;
                        redecorating.push_back(paths[i]);
                    }
                    else if (paths[i].Damage < 40 )
                    {
                        cout << "Путь необходим капитальный ремонт\n" + paths[i].Print() << endl;
                        overhaul.push_back(paths[i]);
                    }
                    break;
                case 2:
                    if (paths[i].Damage > 30 && paths[i].Damage < 90)
                    {
                        cout << "Путь необходим косметический ремонт\n" + paths[i].Print() << endl;
                        redecorating.push_back(paths[i]);
                    }
                    if (paths[i].Damage <= 30)
                    {
                        cout << "Путь необходим капитальный ремонт\n" + paths[i].Print() << endl;
                        overhaul.push_back(paths[i]);
                    }
                    break;
                case 3:
                    if (paths[i].Damage > 20 && paths[i].Damage < 90)
                    {
                        cout << "Путь необходим косметический ремонт\n" + paths[i].Print() << endl;
                        redecorating.push_back(paths[i]);
                    }
                    if (paths[i].Damage <= 20)
                    {
                        cout << "Путь необходим капитальный ремонт\n" + paths[i].Print() << endl;
                        overhaul.push_back(paths[i]);
                    }
                    break;
                default:
                    cout << "Неверно введены данные";
                    break;
                }
            }
            break;
        case 4:
            for (int i = 0; i < paths.size(); i++)
            {
                paths[i].Damage = 100;
            }
            break;
        default:
            cout << "Неверно введены данные";
            break;
        }
    }
}
