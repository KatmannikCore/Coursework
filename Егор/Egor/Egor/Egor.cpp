#include <iostream>
#include <string>
#include <deque>
#include <windows.h>
using namespace std;

class Developer
{
public:
	string Name;
	string Surname;
	deque<string> Technologies;
	string Print()
	{
		string result = "Name " + Name + " Surname " + Surname + " Teхнологии: ";
		for (int i = 0; i < Technologies.size(); i++)
		{
			result += " " + Technologies[i] + " ";
		}
		return result + "\n";
	}
};

class TeamDeveloper
{
public:
	deque<Developer> Developers;
	void AddDeveloper()
	{
		Developer developer;
		cout<< "Дабавить разработчика " <<endl;
		cout<< "Введите имя " <<endl;
		cin >> developer.Name;
		cout << "Введите фамилию " << endl;
		cin >> developer.Surname;
		int choice;
		bool whil = true;
		string Technologie;
		while (whil)
		{
			cout<< "Добовление технологии \n 1 - Добавить технологию \t 2 - Законьчить" <<endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
				cout << "" << endl;
				cin >> Technologie;
				developer.Technologies.push_back(Technologie);
				break;
			case 2:
				whil = false;
				break;
			default:
				break;
			}  
		}
		Developers.push_back(developer);
	}
	string Print()
	{
		string result;
		for (int i = 0; i < Developers.size(); i++)
		{
			result += Developers[i].Print() ;
		}
		return result;
	}
};

class Customer
{
public:
	string Name;
	string Surname;
	int Finance;
	void Add()
	{
		cout << "Введите данные закащика: " << endl;
		cout << "Введите имя закащика" << endl;
		cin >> Name;
		cout << "Введите фамилию закащика" << endl;
		cin >> Surname;
		cout << "Введите финансы закащика" << endl;
		cin >> Finance;
	}
	
};

class Contract
{
public:
	Customer customer;
	deque <TeamDeveloper> teams;
	TeamDeveloper team;
	int Prise;
	string Name;
	TeamDeveloper Add() 
	{
		cout << "Выберите номер команды разработчиков" << endl;
		cout << " Текущее колличество комантд: " << teams.size() << endl;
		int number;
		cin >> number;
		number--;
		for (int i = 0; i < teams.size(); i++)
		{
			if (i == number)
			{
				return teams[i];
			}
		}
	}
	void AddDataContract()
	{
		cout << "Введите данные проекта \n Цена: " <<endl;
		cin >> Prise;
		cout << "Введите название проекта:" <<endl;
		cin >> Name;
	}
	void SubscribeContract()
	{
		AddDataContract();
		customer.Add();
		team = Add();
	}
	void Print()
	{
		SYSTEMTIME st;
		GetSystemTime(&st);
		cout << "Закащик " << customer.Name << " " << customer.Surname << " подписывает контракт на сумму" << Prise << endl;
		cout << "Момпания же за данную сумму предоставляет следующих разработчиков \n" << team.Print();
		cout << "Разработчики будут работать над проектом " << Name << "Цена проекта " << Prise << endl;
		cout <<  "Дата заключение контракта  День: " << to_string(st.wDay) << "  Месяц: " << to_string(st.wMonth) << "  Год: " << to_string(st.wYear) << endl;
	}
};

int main()
{
    setlocale(LC_ALL, "Russian");
	Contract cont;

	Developer dev;
	Developer dev1;
	Developer dev2;

	TeamDeveloper tea;
	TeamDeveloper tea1;
	TeamDeveloper tea2;
	dev.Name = "Глеб";
	dev.Surname = "Назаров";
	dev.Technologies.push_back("css");
	dev.Technologies.push_back("HTML");
	dev.Technologies.push_back("JS");
	tea.Developers.push_back(dev);
	dev1.Name = "Вадим";
	dev1.Surname = "Иванов";
	dev1.Technologies.push_back("Python");
	dev1.Technologies.push_back("Django");
	tea2.Developers.push_back(dev1);
	cont.teams.push_back(tea2);
	dev2.Name = "Алексий";
	dev2.Surname = "Демидов";
	dev2.Technologies.push_back("С#");
	dev2.Technologies.push_back("ASP.Net");
	tea1.Developers.push_back(dev2);
	cont.teams.push_back(tea1);



	cont.SubscribeContract();
	cont.Print();
	
	
}
