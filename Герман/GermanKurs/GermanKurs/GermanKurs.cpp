#include <iostream>
#include <string>
#include <deque>
#include <Windows.h>
using namespace std;
class Spares
{
public:
	string Name;
	string Prise;
	string Size;
	void AddSpares()
	{
		cout << "Введите название:" << endl;
		cin >> Name;
		cout << "Введите цену:" << endl;
		cin >> Prise;
		cout << "Введите колличество:" << endl;
		cin >> Size;
	}
	void Print()
	{
		cout << "Название:" << Name << " \nЦена:" << Prise << "\nКолличество:" << Size << endl;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	deque<Spares> spares;
	while (true)
	{
		int Number;
		bool selection = false;
		Spares spar;
		cout << "Введите опереацию:" << endl;
		cout << "1 - Просмотреть список запчастей" << endl;
		cout << "2 - Добавить запасть" << endl;
		cout << "3 - Изменение" << endl;
		cin >> Number;
		int number;
		switch (Number)
		{
		case 1:
			for (int i = 0; i < spares.size(); i++)
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
			cout << "Колличество эллентов: " << spares.size() << endl;
			cin >> number;
			for (int i = 0; i < spares.size(); i++)
			{
				if (i = number - 1)
				{
					spares[i].AddSpares();
					selection = true;
				}
				if (selection)
				{
					cout << "Данного номера не существует" << endl;
				}
			}
			break;
		default:
			cout << "Неверно выедена операция";
			break;
		}
	}
}