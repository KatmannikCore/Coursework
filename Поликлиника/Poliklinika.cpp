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
	deque<string> illness;
	void AddPerson()
	{
		cout << "Введите имя:" << endl;
		cin >> name;
		cout << "Введите фамилию:" << endl;
		cin >> surname;
		cout << "Введите отчество:" << endl;
		cin >> patronymic;
		
	}
	void addDisease()
	{
		string Disease = "";
		cout << "Введите название болезьни: " <<endl;
		cin >> Disease;
		illness.push_back(Disease);
	}

	void Print()
	{
		string result = "";
		result += "\nИмя: " + name + " \nФамилия: " + surname + "\nОтчество : " + patronymic + "\n";
		if (illness.empty())
			result += "Cписок болезний пуст";
		else
		{
			for (int i = 0; i < illness.size(); i++)
			{
				result += illness[i];
			}
		}
		cout << result <<endl;
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
		cout << "1 - Просмотреть список поциентов" << endl;
		cout << "2 - Добавить поциента" << endl;
		cout << "3 - Добавить диагноз" << endl;
		cout << "4 - Очистить историю болезней" << endl;
		cout << "5 - Изменить данные поциента" << endl;
		cout << "5 - Удалить последнего поциента" << endl;
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
			cout << "Введите номер больного:" << endl;
			cout << "Колличество больных: " << Persons.size() << endl;
			cin >> number;
			for (int i = 0; i < Persons.size(); i++)
			{
				if (i == number - 1)
				{
					Persons[i].addDisease();
					selection = true;
					cout << "Болезнь добавлена" <<endl;
					break;
				}
			}
			if (selection)
			{
				cout << "Данного номера не существует" << endl;
			}
			break;
		case 4:
			cout << "Введите номер больного у которого будет очищаться история болезний:" << endl;
			cout << "Колличество больных: " << Persons.size() << endl;
			cin >> number;
			for (int i = 0; i < Persons.size(); i++)
			{
				if (i == number - 1)
				{
					Persons[i].illness.clear();
					selection = true;
					cout << "История болезней очищена" << endl;
					break;
				}
			}
			if (selection)
			{
				cout << "Данного номера не существует" << endl;
			}
			break;
		case 5:
			cout << "Введите номер изменяемого больного:" << endl;
			cout << "Колличество больных: " << Persons.size() << endl;
			cin >> number;
			for (int i = 0; i < Persons.size(); i++)
			{
				if (i == number - 1)
				{
					Persons[i].AddPerson();
					selection = true;
					cout << "Данные больного изменены" << endl;
					break;
				}
			}
			if (selection)
			{
				cout << "Данного номера не существует" << endl;
			}
			break;
			case 6:
				Persons.pop_back();
				break;
		default:
			cout << "Неверно выедена операция";
			break;
		}
	}
}