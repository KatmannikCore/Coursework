#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <deque>
using namespace std;

class Main_Thing
{ 
    string NameThing;

    double Prise;
    double PriseResult;
    Main_Thing() {}
    string Print()
    {
        return "Название товара: " + NameThing + " Цена: " + to_string(Prise) + " Остаточная цена: " + to_string(PriseResult);
    }
    void Reduce()
    {
        PriseResult =PriseResult - 30;
    }
    void Add()
    {
        cout << "Введите название товара:";
        cin >> NameThing;
        cout << "Введите цену :";
        cin >> Prise;
        PriseResult = Prise;
    }

};

class MOL
{
public:
    string Name;
    string Surname;
    deque<Main_Thing> Resources;
    string Print() {
        string result;
        result += "Name: " + Name + " Surname: " + Surname;
        if (Resources.empty())
        {
            result += "\nЗа данным материально ответственным лицом не чего не закреплено";
        }
        else
        {
            for (auto item: Resources)
               result += "\n" + item.Print();
            
        }
        return result;
    }
    void SetName(string value)
    {
        Name = value;
    }
    void SetSurname(string value)
    {
        Surname = value;
    }

};




int main()
{
    setlocale(LC_ALL, "Russian");
 
    deque<MOL> Persons;
    MOL person1;
    person1.SetName("Peregrine");
    person1.SetSurname("Dean");
    Persons.push_back(person1);
    MOL person2;
    person2.SetName("Charles");
    person2.SetSurname("Simmons");
    Persons.push_back(person2);
    MOL person3;
    person3.SetName("Branden");
    person3.SetSurname("Jordan");
    Persons.push_back(person3);

    Main_Thing accounting;
    deque<Main_Thing> client;
    accounting.NameThing = "Компьютер";
    accounting.Prise = 1000.0;
    accounting.PriseResult = 1000.0;
    client.push_back(accounting);
    accounting.NameThing = "телефон";
    accounting.Prise = 400;
    accounting.PriseResult = 400;
    client.push_back(accounting);
    accounting.NameThing = "Шифратор";
    accounting.Prise = 6000;
    accounting.PriseResult = 6000;
    client.push_back(accounting);
    while (true)
    {
        cout << " Выберите желаему операцию:" << endl;
        cout << " 1 - просмотреть весь список" << endl;
        cout << " 2 - перейти на следующий день" << endl;
        cout << " 3 - добавить средство" << endl;
        cout << " 4 - Просмотреть ответственных лиц" << endl;
        cout << " 5 - выдать средство" << endl;
        int selection;
        cin >> selection;

        double value;
      
        MOL temp;
        switch (selection)
        {
        case 1:
            for (auto item : client)
            {
                cout << item.Print() << endl;
            }
            break;
        case 2:
            for (int i = 0; i < client.size(); i++)
            {
                client[i].Reduce();
            }
            break;
        case 3:
            accounting.Add();
            client.push_back(accounting);
            break;
        case 4:
            for (MOL item :  )
            {
                cout << item.Print() << endl;
            }
            break;
        case 5:
            cout << "Выберите индекс лица получившего средство" <<endl;
            cout << "Колличество персон: " << Persons.size() <<endl;
            int number;
            cin >> number;
            int i ;
            i = 0;
            for (MOL item : Persons)
            {
                i++;
                if (i == number)
                {
                    cout<< "Выберите индекс лица получвемого средство" <<endl;
                    cout << "Колличество средств: " << client.size() << endl;
                    cin >> number;
                    int i1 = 0;
                    for (auto itemm : client)
                    {
                        i1++;
                        if (i1 == number)
                        {
                            item.Resources.push_back(itemm);
                            temp = item;
                            Persons[i-1] = temp;
                            break;
                        }
                    }
                    break;
                }
            }
            break;
        default:
            cout << "Неверно введены данные";
            break;
        }
    }
}



