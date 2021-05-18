#include <iostream>
#include <string>
#include <deque>
#include <Windows.h>
using namespace std;
class Person
{
public:
	string Name;
	string Surname;
	string MiddleName;
	string MaritalStatus;
	string children;
	string position;
	string AcademicDegree;
	void AddPerson()
	{
		cout << "Введите имя:" << endl;
		cin >> Name;
		cout << "Введите фамилия:" << endl;
		cin >> Surname;
		cout << "Введите отсчество:" << endl;
		cin >> MiddleName;
		cout << "Симейное положение:" << endl;
		cin >> MaritalStatus;
		cout << "Колличество детей:" << endl;
		cin >> children;
		cout << "Введите должность:" << endl;
		cin >> position;
		cout << "Введите учёную степень:" << endl;
		cin >> AcademicDegree;
	}
	void Print()
	{
		cout << "Имя:" << Name << " \nФамилия:" << Surname << "\nОтсчество:" << MiddleName << "\nПоложение:" << MaritalStatus << "\nДетей:" << children << "\nДолжность:" << position << "\nУчёная степень:" << AcademicDegree << "\n"<< endl;
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
		cout << "1 - Просмотреть всех работников" << endl;
		cout << "2 - Добавить работника" << endl;
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
			cout<< "Введите номер изменяемого эллемента:" <<endl;
			cout << "Колличество эллентов: " << Persons.size() <<endl;
			cin >> number;
			for (int i = 0; i < Persons.size(); i++)
			{
				if (i = number-1)
				{
					Persons[i].AddPerson();
					selection = true;
				}
				if (selection)
				{
					cout<< "Данного номера не существует" <<endl;
				}
			}
			break;
		default:
			cout << "Неверно выедена операция";
			break;
		}
	}
}