#include <iostream>
#include <string>
#include <deque>
#include <Windows.h>
using namespace std;
class Person
{
public:
	string name;
	string surname;
	string patronymic;
	string populationDate;
	string evictionData;
	void AddPerson()
	{
		cout << "Введите имя:" << endl;
		cin >> name;
		cout << "Введите фамилию:" << endl;
		cin >> surname;
		cout << "Введите отчество:" << endl;
		cin >> patronymic;
		cout << "Введите дату заселения:" << endl;
		cin >> populationDate;
		cout << "Введите дату выселения:" << endl;
		cin >> evictionData;
	}
	void Print()
	{
		cout << "\nИмя: " << name << " \nФамилия: " << surname << "\nОтчество :" << patronymic << "\nДата заселения: " << populationDate << "\nДата выселения: " << evictionData << endl;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	deque<Person> Persons;
	while (true)
	{
		int Number;
		bool selection = false;
		Person person;
		cout << "Введите опереацию:" << endl;
		cout << "1 - Просмотреть список клиентов" << endl;
		cout << "2 - Добавить клиента" << endl;
		cout << "3 - Изменение" << endl;
		cin >> Number;
		int number;
		switch (Number)
		{
		case 1:
			for (int i = 0; i < Persons.size(); i++)
			{
				Persons[i].Print();
			}
			break;
		case 2:
			person.AddPerson();
			Persons.push_back(person);
			break;
		case 3:
			cout << "Введите номер изменяемого эллемента:" << endl;
			cout << "Колличество эллентов: " << Persons.size() << endl;
			cin >> number;
			for (int i = 0; i < Persons.size(); i++)
			{
				if (i == number - 1)
				{
					Persons[i].AddPerson();
					selection = true;
					break;
				}
			}
			if (selection)
			{
				cout << "Данного номера не существует" << endl;
			}
			break;
		default:
			cout << "Неверно выедена операция";
			break;
		}
	}
}\