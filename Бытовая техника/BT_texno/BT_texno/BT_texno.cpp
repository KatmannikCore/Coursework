#include <iostream>
#include <string>
#include <deque>
#include <Windows.h>
using namespace std;
class Technics
{
public:
	string name;
	int Prise;
	int count;
	string FirmName;
	string Data;
	void AddTechno()
	{
		cout << "Введите имя:" << endl;
		cin >> name;
		cout << "Введите цену: " << endl;
		cin >> Prise;
		cout << "Введите колличество:" << endl;
		cin >> count;
		cout << "Введите фирму:" << endl;
		cin >> FirmName;
		cout << "Введите дату поступления:" << endl;
		cin >>  Data;
	}
	void Print()
	{
		cout << "\nИмя: " << name << "\nЦена: " << Prise << "\nКолличество: " << count << "\nНазвание фирмы производителя: " << FirmName <<"\nДата поступления: " << Data << endl;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	deque<Technics> Technic;
	while (true)
	{
		int Number;
		bool selection = false;
		Technics technics;
		cout << "Введите опереацию:" << endl;
		cout << "1 - Просмотреть список бытовой технике" << endl;
		cout << "2 - Добавить бытовую технику" << endl;
		cout << "3 - Изменение" << endl;
		cout << "4 - Удаление последнего эллемента" << endl;
		cout << "5 - Удаление первого эллемента" << endl;
		cin >> Number;
		int number;
		switch (Number)
		{
		case 1:
			for (int i = 0; i < Technic.size(); i++)
			{
				Technic[i].Print();
			}
			break;
		case 2:
			technics.AddTechno();
			Technic.push_back(technics); 
			cout << "Добавление произошло успешно" << endl;
			break;
		case 3:
			cout << "Введите номер изменяемого эллемента:" << endl;
			cout << "Колличество эллентов: " << Technic.size() << endl;
			cin >> number;
			for (int i = 0; i < Technic.size(); i++)
			{
				if (i == number - 1)
				{
					Technic[i].AddTechnoo();
					selection = true;
					cout << "Изменение произошло успешно" << endl;
					break;
				}
			}
			if (selection)
			{
				cout << "Данного номера не существует" << endl;
			}
			break;
		case 4:
			Technic.pop_back();
			cout << "Эллемент удалён" <<endl;
			break;
		case 5:
			Technic.pop_front();
			cout << "Эллемент удалён" << endl;
			break;
		default:
			cout << "Неверно выедена операция";
			break;
		}
	}
}