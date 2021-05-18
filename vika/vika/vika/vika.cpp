#include <string>
#include <deque>
#include <iostream>
#include <Windows.h>
using namespace std;
class Person
{
public:
	string Name;
	string Surname;
	string Age;
};
class Room
{
public:
	int area;
	int	NumberResidents;
	int Number;
	deque<Person> Persons;
	string Print() {
		string result;
		result = "Номер комнаты: " + to_string(Number) + " Колличество жильцов: " + to_string(NumberResidents) + " Площать комнаты: " + to_string(area) + "\n";
		if (Persons.empty())
		{
			result += "В комнате отсутствуют жильцы";
		}
		else
		{
			for (int i = 0; i < Persons.size(); i++)
			{
				result += "Имя: " + Persons[i].Name + " Фамилия: " + Persons[i].Surname + " Возраст: " + Persons[i].Age + "\n";
			}
		}
		return result;
	}
	void addRoom()
	{
		cout << "Введите площать комнты" << endl;
		cin >> area ;
		cout << "Введите колличество жителей" << endl;
		cin >> NumberResidents;
		cout << "Введите номер комнаты" << endl;
		cin >> Number;
	}
	void addPerson()
	{
		if (Persons.size() == NumberResidents)
		{
			cout << "Комната переполнена" <<endl;
		}
		else
		{
			Person newPerson;
			cout << "Введите имя" << endl;
			cin >> newPerson.Name;
			cout << "Введите фамилию" << endl;
			cin >> newPerson.Surname;
			cout << "Введите возраст" << endl;
			cin >> newPerson.Age;
			Persons.push_back(newPerson);
		}
	}
};

void PrintDeque(deque<Room> Rooms)
{
	for (int i = 0; i < Rooms.size(); i++)
	{
		cout << Rooms[i].Print() << endl;;
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	deque<Room> Rooms;
	
	while (true)
	{
		Room room;
		int number;
		int numberRoom;
		int numberRoomDel;
		int check = 0;
		cout << "Введите опереацию:" << endl;
		cout << "1 - Просмотреть все комнаты" << endl;
		cout << "2 - Добавить комнату" << endl;
		cout << "3 - Добавить студента в комнату" << endl;
		cin >> number;
		switch (number)
		{
		case 1:
			PrintDeque(Rooms);
			break;
		case 2:
			room.addRoom();
			Rooms.push_back(room);
			break;
		case 3:
			cout << "Введите номер комнаты" << endl;
			cin >> numberRoom;
			for (int i = 0; i < Rooms.size(); i++)
			{
				if (Rooms[i].Number == numberRoom)
				{
					Rooms[i].addPerson();
					check = 1;
				}
			}
			if (check == 0)
			{
				cout << "Комната не существует" <<endl;
			}
			break;
		default:
			cout << "Неверно выедена операция";
			break;
		}
	}
}

