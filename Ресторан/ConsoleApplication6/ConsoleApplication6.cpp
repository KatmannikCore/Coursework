#include <math.h>
#include <stdio.h> //printf 
#include <conio.h> //fstream(для коректной работы)
#include <locale.h> //Rus lang
#include <cstdlib> //Using system
#include <string> //Work with string(строки)
#include <fstream> //file
#include <iostream> //cout-cin
#include <algorithm> //enable sort algorithm
using namespace std;

struct dish;
struct menu;
struct date;
struct table;
struct order;

void manageMenuOrders();

void newFileOrders();
void addNoteOrders();
void editNoteOrders();
void searchNote_NameOrders();
void displayAllOrders();

void manageMenuDishes();

void newFileDish();
void addNoteDish();
void editNoteDish();
void searchNoteDish();
void searchNote_NameDish();
void searchNote_NameCook();
void deleteNoteDish();
void displayAllDishes();

void manageMenuMenus();

void newFileMenus();
void addNoteMenus();
void editNoteMenus();
void searchNote_NameMenus();
void displayAllMenus();

struct dish {
	char nameDish[50];
	char nameCook[50];
};
dish dishesArray[15];
int d = 0; // number of dishes array
int df = 0; // file of dishes array

struct menu {
	char nameMenu[50];
	d                                                                                                                                                                                                                                                                   ish listOfDishes[10];
};
menu menusArray[15];
int m = 0;	// number of dishes array
int mf = 0;	// file of dishes array

struct date {
	int day, month, year;
};
struct table {
	int numberOfTable;
	int numberOfSeats;
};
struct order {
	char nameOrder[50];
	date dateOrder;
	table tableReserve;
	menu menuReserve;
};
order orderArray[15];
int ord = 0; // number of dishes array
int ordf = 0; // file of dishes array

// Заказы

void manageMenuOrders()
{
	bool OOAM = true;
	do
	{
		printf("Сделайте выбор для продолжения:\n");
		int choice;
		do
		{
			printf("1. Создать файл(обновить данные)\n");
			printf("2. Добавить заказ\n");
			printf("3. Редактировать заказ\n");
			printf("4. Поиск заказа по названию\n");
			printf("5. Просмотр базы заказов\n");
			printf("6. Выход\n");
			printf("Ваш выбор: ");
			cin >> choice;
			system("cls");
		} while (choice > 6);
		switch (choice)
		{
		case 1: newFileOrders(); break;
		case 2: addNoteOrders(); break;
		case 3: editNoteOrders(); break;
		case 4: searchNote_NameOrders(); break;
		case 5: displayAllOrders(); break;
		case 6: OOAM = false; break;
		default: printf("Ваш выбор неверен.\n");
		}
	} while (OOAM);
}

void newFileOrders()
{
	fstream fileIO;
	string pathFile = "OrdersFile.txt";
	fileIO.open(pathFile, fstream::out);
	fileIO.close();
	fileIO.open(pathFile, fstream::out | fstream::in | fstream::binary);
	ordf++; //Счетчик проверяющий создан ли файл 
	fileIO.close();
	cout << "Файл успешно создан\n\n";
	system("pause");
	system("cls");
}

void addNoteOrders()
{
	system("cls");
	if (ordf != 0)
	{
		fstream fileIO;
		string pathFile = "OrdersFile.txt";
		fileIO.open(pathFile, fstream::in | fstream::out | fstream::binary);

		cin.ignore();
		printf("Введите название заказа: ");
		cin.getline(orderArray[ord].nameOrder, 50);

		printf("Введите день заказа: ");
		cin >> orderArray[ord].dateOrder.day;
		printf("Введите месяц заказа: ");
		cin >> orderArray[ord].dateOrder.month;
		printf("Введите год заказа: ");
		cin >> orderArray[ord].dateOrder.year;

		printf("Введите номер стола: ");
		cin >> orderArray[ord].tableReserve.numberOfTable;
		printf("Введите количество мест: ");
		cin >> orderArray[ord].tableReserve.numberOfSeats;

		cout << "Список меню:\n";
		for (int i = 0; i < m; i++)
		{
			cout << i << "-" << menusArray[i].nameMenu << "\n";
		}

		//cin.ignore();
		int idMenuAdd;
		cout << "Введите номер меню, которое вы хотите добавить: ";
		do
		{
			cin >> idMenuAdd;
			if (idMenuAdd >= 0 && idMenuAdd < m)
			{
				orderArray[ord].menuReserve = menusArray[idMenuAdd];
			}
			else
			{
				cout << "Введите данные снова: ";
			}
		} while (idMenuAdd < 0 || idMenuAdd >= m);


		fileIO.write((char*)&orderArray, sizeof orderArray);
		fileIO.close();
		//Для проверки, состояния массивов
		/*fileIO.read((char*)&orderArray, sizeof orderArray);
		fileIO.close();*/
		printf("\nЗапись успешно добавлена\n\n");
		ord++; //Увеличивается если добавляется еще один заказ.
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");
		printf("Файл не создан\n\n");
		system("pause");
	}
	system("cls");
}

void editNoteOrders()
{
	system("cls");
	if (ordf != 0) //Проверка, создан ли файл
	{
		fstream fileIO;
		fileIO.open("OrdersFile.txt", fstream::in | fstream::out | fstream::binary);
		char findOrderName[50];
		cin.ignore();
		printf("Введите название заказа для изменения меню: ");
		cin >> findOrderName;
		fileIO.write((char*)&orderArray, sizeof orderArray);

		bool temp = false;
		for (int j = 0; j < ord; j++)
		{
			if (string(findOrderName) == string(orderArray[j].nameOrder))
			{
				temp = true;
				cout << "Название заказа: " << orderArray[j].nameOrder << "\n";
				cout << "Дата заказа: " << orderArray[j].dateOrder.day << "." << orderArray[j].dateOrder.month << "." << orderArray[j].dateOrder.year << "\n";
				cout << "Номер стола: " << orderArray[j].tableReserve.numberOfTable << "\n";
				cout << "Количество мест: " << orderArray[j].tableReserve.numberOfSeats << "\n";
				cout << "Название меню: " << orderArray[j].menuReserve.nameMenu << "\n";
				cout << "Список блюд(номер блда, название блюда, имя повара): \n";
				for (int i = 0; string(orderArray[j].menuReserve.listOfDishes[i].nameDish) != string("\0"); i++)
				{
					cout << i << " - " << orderArray[j].menuReserve.listOfDishes[i].nameDish << " - " << orderArray[j].menuReserve.listOfDishes[i].nameCook << "\n";
				}
				// Начинать от сюда. Ввыод списком названий меню, выбор меню по id.
				cout << "Список меню:\n";
				for (int i = 0; string(menusArray[i].nameMenu) != string("\0"); i++)
				{
					cout << i << " - " << menusArray[i].nameMenu << "\n";
				}
				cout << "Введите номер меню, на которое вы хотите изменить существующее меню: ";
				int switchChoice;
				do
				{
					cin >> switchChoice;
					if (switchChoice >= 0 && switchChoice < m)
					{
						orderArray[j].menuReserve = menusArray[switchChoice];
					}
					else
					{
						cout << "Введите данные снова: ";
					}
				} while (switchChoice < 0 || switchChoice >= m);
			}
		}
		if (!temp)
			cout << "\nМеню с таким названием не обнаружено. Попробуйте ввести имя еще раз";
		fileIO.write((char*)&orderArray, sizeof orderArray);
		fileIO.close();
		//Для проверки, состояния массивов
	   /*fileIO.read((char*)&orderArray, sizeof orderArray);
	   fileIO.close();*/
		system("pause");
	}
	else
	{
		system("cls");
		printf("Файл не создан\n\n");
		system("pause");
	}
	system("cls");
}

void searchNote_NameOrders()
{
	system("cls");
	if (ordf != 0) //Проверка, создан ли файл
	{
		fstream fileIO;
		fileIO.open("OrdersFile.txt", fstream::in | fstream::out | fstream::binary);
		char findOrderName[50];
		cin.ignore();
		printf("Введите название меню просмотра состава блюд: ");
		cin >> findOrderName;
		fileIO.read((char*)&orderArray, sizeof orderArray);

		bool temp = false;
		for (int j = 0; j < ord; j++)
		{
			if (string(findOrderName) == string(orderArray[j].nameOrder))
			{
				temp = true;
				cout << "Название заказа: " << orderArray[j].nameOrder << "\n";
				cout << "Дата заказа: " << orderArray[j].dateOrder.day << "." << orderArray[j].dateOrder.month << "." << orderArray[j].dateOrder.year << "\n";
				cout << "Номер стола: " << orderArray[j].tableReserve.numberOfTable << "\n";
				cout << "Количество мест: " << orderArray[j].tableReserve.numberOfSeats << "\n";
				cout << "Название меню: " << orderArray[j].menuReserve.nameMenu << "\n";
				cout << "Список блюд(номер блда, название блюда, имя повара): \n";
				for (int i = 0; string(orderArray[j].menuReserve.listOfDishes[i].nameDish) != string("\0"); i++)
				{
					cout << i << " - " << orderArray[j].menuReserve.listOfDishes[i].nameDish << " - " << orderArray[j].menuReserve.listOfDishes[i].nameCook << "\n";
				}
			}
		}
		if (!temp)
			cout << "\nЗаказа с таким названием не обнаружено. Попробуйте ввести название еще раз";
		fileIO.close();
		// Для проверки, состояния массивов
		//fileIO.read((char*)&orderArray, sizeof orderArray);
		//fileIO.close();
		system("pause");
	}
	else
	{
		system("cls");
		printf("Файл не создан\n\n");
		system("pause");
	}
	system("cls");
}

void displayAllOrders()
{
	system("cls");
	if (ordf != 0) //Проверка, создан ли файл
	{
		fstream fileIO;
		fileIO.open("OrdersFile.txt", fstream::in | fstream::out | fstream::binary);
		//cout << "Файл успешно открыт" << endl;
		cin.ignore();
		for (int i = 0; string(orderArray[i].nameOrder) != string("\0"); i++)
		{
			cout << "\n\nНазвание заказа номер " << i << ": " << orderArray[i].nameOrder << "\n";
			cout << "Дата заказа: " << orderArray[i].dateOrder.day << "." << orderArray[i].dateOrder.month << "." << orderArray[i].dateOrder.year << "\n";
			cout << "Номер стола: " << orderArray[i].tableReserve.numberOfTable << "\n";
			cout << "Количество мест: " << orderArray[i].tableReserve.numberOfSeats << "\n";
			cout << "Название меню: " << orderArray[i].menuReserve.nameMenu << "\n";
			cout << "Список блюд(номер блда, название блюда, имя повара): \n";
			for (int j = 0; string(orderArray[i].menuReserve.listOfDishes[j].nameDish) != string("\0"); j++)
			{
				cout << j << " - " << orderArray[i].menuReserve.listOfDishes[j].nameDish << " - " << orderArray[j].menuReserve.listOfDishes[j].nameCook << "\n";
			}
		}
		fileIO.close();
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");
		printf("Файл не создан\n\n");
		system("pause");
	}
	system("cls");
}

// Меню

void manageMenuMenus()
{
	bool OOAM = true;
	do
	{
		printf("Сделайте выбор для продолжения:\n");
		int choice;
		do
		{
			printf("1. Создать файл(обновить данные)\n");
			printf("2. Добавить меню\n");
			printf("3. Редактировать меню\n");
			printf("4. Поиск меню по названию\n");
			printf("5. Просмотр базы меню\n");
			printf("6. Выход\n");
			printf("Ваш выбор: ");
			cin >> choice;
			system("cls");
		} while (choice > 6);
		switch (choice)
		{
		case 1: newFileMenus(); break;
		case 2: addNoteMenus(); break;
		case 3: editNoteMenus(); break;
		case 4: searchNote_NameMenus(); break;
		case 5: displayAllMenus(); break;
		case 6: OOAM = false; break;
		default: printf("Ваш выбор неверен.\n");
		}
	} while (OOAM);
}

void newFileMenus()
{
	fstream fileIO;
	string pathFile = "MenusFile.txt";
	fileIO.open(pathFile, fstream::out);
	fileIO.close();
	fileIO.open(pathFile, fstream::out | fstream::in | fstream::binary);
	mf++; //Счетчик проверяющий создан ли файл 
	//d = 0;
	fileIO.close();
	cout << "Файл успешно создан\n\n";
	system("pause");
	system("cls");
}

void addNoteMenus()
{
	system("cls");
	if (mf != 0)
	{
		fstream fileIO;
		string pathFile = "MenusFile.txt";
		fileIO.open(pathFile, fstream::in | fstream::out | fstream::binary);

		cin.ignore();
		printf("Введите название меню: ");
		cin.getline(menusArray[m].nameMenu, 50);

		cout << "Список блюд:\n";
		for (int i = 0; i < d - 1; i++)
		{
			cout << i << "-" << dishesArray[i].nameDish << "\n";
		}
		int idDishAdd;
		int switchChoice;
		int numberOfDishinMenu = 0;
		do {
			cout << "Введите номер блюда, которое вы хотите добавить: ";
			cin >> idDishAdd;
			menusArray[m].listOfDishes[numberOfDishinMenu] = dishesArray[idDishAdd];
			cout << "\nХотите ли добавить еще одно блюдо?\n";
			cout << "1. Хочу\n";
			cout << "2. Не хочу\n";
			cout << "Ваш выбор: ";
			cin >> switchChoice;
			numberOfDishinMenu++;
		} while (switchChoice != 2);

		fileIO.write((char*)&menusArray, sizeof menusArray);
		fileIO.close();
		printf("\nЗапись успешно добавлена\n\n");
		m++; //Увеличивается если добавляется еще одно меню.
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");
		printf("Файл не создан\n\n");
		system("pause");
	}
	system("cls");
}

void editNoteMenus()
{
	system("cls");
	if (mf != 0) //Проверка, создан ли файл
	{
		fstream fileIO;
		fileIO.open("MenusFile.txt", fstream::in | fstream::out | fstream::binary);
		char findMenuName[50];
		cin.ignore();
		printf("Введите название меню для изменения состава блюд: ");
		cin >> findMenuName;
		fileIO.write((char*)&menusArray, sizeof menusArray);

		bool temp = false;
		for (int j = 0; j < m; j++)
		{
			if (string(findMenuName) == string(menusArray[j].nameMenu))
			{
				temp = true;
				cout << "Название меню: " << menusArray[j].nameMenu << "\n";
				cout << "Список блюд: " << "\n";
				for (int i = 0; string(menusArray[j].listOfDishes[i].nameDish) != string("\0"); i++)
				{
					cout << i << " - " << menusArray[j].listOfDishes[i].nameDish << " - " << menusArray[j].listOfDishes[i].nameCook << "\n";
				}
				cout << "Введите название блюда, которое неободимо удалить из меню: ";
				char nameDishToRemove[50];
				cin >> nameDishToRemove;
				for (int k = 0; string(menusArray[j].listOfDishes[k].nameDish) != string("\0"); k++) //menusArray[j].listOfDishes[k].nameDish != 0
				{
					if (string(menusArray[j].listOfDishes[k].nameDish) == string(nameDishToRemove))
					{
						menusArray[j].listOfDishes[k] = menusArray[j].listOfDishes[k + 1];
						for (int g = k; g != 10; g++)
						{
							menusArray[j].listOfDishes[g] = menusArray[j].listOfDishes[g + 1];
						}
						cout << "\nУдаление элемента прошло успешно.";
					}
				}
			}
		}
		if (!temp)
			cout << "\nМеню с таким названием не обнаружено. Попробуйте ввести имя еще раз";
		fileIO.write((char*)&menusArray, sizeof menusArray);
		fileIO.close();
		// Для проверки, состояния массивов
		//fileIO.read((char*)&menusArray, sizeof menusArray);
		//fileIO.close();
		system("pause");
	}
	else
	{
		system("cls");
		printf("Файл не создан\n\n");
		system("pause");
	}
	system("cls");
}

void searchNote_NameMenus()
{
	system("cls");
	if (mf != 0) //Проверка, создан ли файл
	{
		fstream fileIO;
		fileIO.open("MenusFile.txt", fstream::in | fstream::out | fstream::binary);
		char findMenuName[50];
		cin.ignore();
		printf("Введите название меню просмотра состава блюд: ");
		cin >> findMenuName;
		fileIO.write((char*)&menusArray, sizeof menusArray);

		bool temp = false;
		for (int j = 0; j < m; j++)
		{
			if (string(findMenuName) == string(menusArray[j].nameMenu))
			{
				temp = true;
				cout << "Название меню: " << menusArray[j].nameMenu << "\n";
				cout << "Список блюд: " << "\n";
				for (int i = 0; string(menusArray[j].listOfDishes[i].nameDish) != string("\0"); i++)
				{
					cout << i << " - " << menusArray[j].listOfDishes[i].nameDish << " - " << menusArray[j].listOfDishes[i].nameCook << "\n";
				}
			}
		}
		if (!temp)
			cout << "\nМеню с таким названием не обнаружено. Попробуйте ввести имя еще раз";
		fileIO.write((char*)&menusArray, sizeof menusArray);
		fileIO.close();
		// Для проверки, состояния массивов
		//fileIO.read((char*)&menusArray, sizeof menusArray);
		//fileIO.close();
		system("pause");
	}
	else
	{
		system("cls");
		printf("Файл не создан\n\n");
		system("pause");
	}
	system("cls");
}

void displayAllMenus()
{
	system("cls");
	if (mf != 0) //Проверка, создан ли файл
	{
		fstream fileIO;
		fileIO.open("MenusFile.txt", fstream::in | fstream::out | fstream::binary);
		//cout << "Файл успешно открыт" << endl;
		cin.ignore();
		for (int i = 0; string(menusArray[i].nameMenu) != string("\0"); i++)
		{
			cout << "\n\nНазвание меню номер " << i << ": " << menusArray[i].nameMenu << "\n";
			cout << "Список блюд(Номер блюда - Название блюда - Имя повара)" << "\n";
			for (int j = 0; string(menusArray[i].listOfDishes[j].nameDish) != string("\0"); j++)
			{
				cout << j << " - " << menusArray[i].listOfDishes[j].nameDish << " - " << menusArray[i].listOfDishes[j].nameCook << "\n";
			}
		}
		fileIO.close();
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");
		printf("Файл не создан\n\n");
		system("pause");
	}
	system("cls");
}

// Блюда

void manageMenuDishes()
{
	bool OOAM = true;
	do
	{
		printf("Сделайте выбор для продолжения:\n");
		int choice;
		do
		{
			printf("1. Создать файл(обновить данные)\n");
			printf("2. Добавить блюдо\n");
			printf("3. Редактировать блюдо\n");
			printf("4. Поиск блюда\n");
			printf("5. Удаление блюда \n");
			printf("6. Просмотр базы\n");
			printf("7. Выход\n");
			printf("Ваш выбор: ");
			cin >> choice;
			system("cls");
		} while (choice > 7);
		switch (choice)
		{
		case 1: newFileDish(); break;
		case 2: addNoteDish(); break;
		case 3: editNoteDish(); break;
		case 4: searchNoteDish(); break;
		case 5: deleteNoteDish(); break;
		case 6: displayAllDishes(); break;
		case 7: OOAM = false; break;
		default: printf("Ваш выбор неверен.\n");
		}
	} while (OOAM);

	if (df != 0) //Проверка, создан ли файл
	{
		fstream fileIO;
		fileIO.open("DishesFile.txt", fstream::in);
		d = 0;
		while (!fileIO.eof())
		{
			fileIO.getline(dishesArray[d].nameDish, 50, '|');
			fileIO.getline(dishesArray[d].nameCook, 50);
			d++;
		}
		fileIO.close();
	}
	else
	{
		system("cls");
		printf("Файл для блюд не создан\n\n");
		system("pause");
	}
	system("cls");


}

void newFileDish()
{
	fstream fileIO;
	string pathFile = "DishesFile.txt";
	fileIO.open(pathFile, fstream::out);
	fileIO.close();
	fileIO.open(pathFile, fstream::out | fstream::in | fstream::app);
	df++; //Счетчик проверяющий создан ли файл 
	fileIO.close();
	cout << "Файл успешно создан\n\n";
	system("pause");
	system("cls");
}

void addNoteDish()
{
	system("cls");
	if (df != 0)
	{
		fstream fileIO;
		string pathFile = "DishesFile.txt";
		fileIO.open(pathFile, fstream::in | fstream::out | fstream::app);
		cin.ignore();
		printf("Введите название блюда: ");
		cin.getline(dishesArray[d].nameDish, 50);
		printf("\nВведите имя повара: ");
		cin.getline(dishesArray[d].nameCook, 50);

		//Запись данных в файл
		fileIO << dishesArray[d].nameDish << '|' << dishesArray[d].nameCook << '\n';
		fileIO.close();
		printf("\nЗапись успешно добавлена\n\n");
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");
		printf("Файл не создан\n\n");
		system("pause");
	}
	system("cls");
}

void editNoteDish()
{
	system("cls");
	if (df != 0) //Проверка, создан ли файл
	{
		fstream fileIO;
		fstream buffFile;
		fileIO.open("DishesFile.txt", fstream::in);
		buffFile.open("BuffFile.txt", fstream::out);
		//cout << "Файл успешно открыт" << endl;
		cin.ignore();
		char nameDish[50];
		char nameCook[50];
		char findDDishName[50];

		printf("Введите название блюда для обновления имени повара: ");
		cin.getline(findDDishName, 50);
		while (!fileIO.eof())
		{
			fileIO.getline(nameDish, 50, '|');
			fileIO.getline(nameCook, 50);
			if (strcmp(nameDish, findDDishName) == 0)
			{
				printf("Обновите информацию о поваре: ");
				string changedNameCook;
				cin >> changedNameCook;
				buffFile << nameDish << '|' << changedNameCook << '\n';
			}
			else
			{
				buffFile << nameDish << '|' << nameCook << '\n';
			}
		}
		buffFile.close();
		fileIO.close();

		fileIO.open("DishesFile.txt", fstream::out);
		buffFile.open("BuffFile.txt", fstream::in);
		while (!buffFile.eof())
		{
			buffFile.getline(nameDish, 50, '|');
			buffFile.getline(nameCook, 50);
			if (strcmp(nameDish, "") != 0)//Проверка, если в переменную nameCook записывается пустое значение в буфферный файл, то в основной эта информация не попадает
			{
				fileIO << nameDish << '|' << nameCook << '\n';
			}
		}
		buffFile.close();
		fileIO.close();
		remove("BuffFile.txt");
		system("pause");
	}
	else
	{
		system("cls");
		printf("Файл не создан\n\n");
		system("pause");
	}
	system("cls");
}

void searchNoteDish()
{
	int choice;
	bool FRT = true;
	while (FRT)
	{
		do
		{
			system("cls");
			printf("Выбор критерия поиска\n");
			printf("1. Поиск по названию блюда\n");
			printf("2. Поиск по имени повара\n");
			printf("3. Выход\n");
			printf("Ваш выбор: ");
			cin >> choice;
			system("cls");
			switch (choice)
			{
			case 1: searchNote_NameDish(); break;
			case 2: searchNote_NameCook(); break;
			case 3: FRT = false; break;
			default: printf("Неверный выбор\n");
			}
		} while (choice > 3);
	}
}

void searchNote_NameDish()
{
	system("cls");
	if (df != 0) //Проверка, создан ли файл
	{
		fstream fileIO;
		fileIO.open("DishesFile.txt", fstream::in);
		//cout << "Файл успешно открыт" << endl;
		cin.ignore();
		char nameDish[50];
		char nameCook[50];
		char NameDishForFind[50];
		int x = 0;
		printf("Введите полное название блюда для поиска\n");
		printf("Введите данные: ");
		cin.getline(NameDishForFind, 100);
		while (!fileIO.eof())
		{
			fileIO.getline(nameDish, 50, '|');
			fileIO.getline(nameCook, 50);
			if (strcmp(nameDish, NameDishForFind) == 0)
			{
				cout << nameDish << '\t' << nameCook << '\n';
				x = 1;
				break; // Отвечает за то, что если одино и то же название будет у двух блюд
			}
		}
		if (x == 0)
		{
			cout << "Такая запись была не найдена\n";
		}
		fileIO.close();
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");
		printf("Файл не создан\n\n");
		system("pause");
	}
	system("cls");
}

void searchNote_NameCook()
{
	system("cls");
	if (df != 0) //Проверка, создан ли файл
	{
		fstream fileIO;
		fileIO.open("DishesFile.txt", fstream::in);
		//cout << "Файл успешно открыт" << endl;
		cin.ignore();
		char nameDish[50];
		char nameCook[50];
		char NameCookForFind[50];
		int x = 0;
		printf("Введите полное имя повара для поиска\n");
		printf("Введите данные: ");
		cin.getline(NameCookForFind, 100);
		while (!fileIO.eof())
		{
			fileIO.getline(nameDish, 50, '|');
			fileIO.getline(nameCook, 50);
			if (strcmp(nameCook, NameCookForFind) == 0)
			{
				cout << nameDish << '\t' << nameCook << '\n';
				x = 1;
				break; // Отвечает за то, что если одино и то же имя повора у двух блюд
			}
		}
		if (x == 0)
		{
			cout << "Такая запись была не найдена\n";
		}
		fileIO.close();
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");
		printf("Файл не создан\n\n");
		system("pause");
	}
	system("cls");
}

void deleteNoteDish()
{

	system("cls");
	if (df != 0) //Проверка, создан ли файл
	{
		fstream fileIO;
		fstream buffFile;
		fileIO.open("DishesFile.txt", fstream::in);
		buffFile.open("BuffFile.txt", fstream::out);
		//cout << "Файл успешно открыт" << endl;
		cin.ignore();
		char nameDish[50];
		char nameCook[50];
		char nameDishForRemove[100];

		printf("Введите полное название для удаления записи: \n");
		printf("Введите информацию: ");
		cin.getline(nameDishForRemove, 100);
		while (!fileIO.eof())
		{
			fileIO.getline(nameDish, 50, '|');
			fileIO.getline(nameCook, 50);
			if (strcmp(nameDish, nameDishForRemove) == 0)
			{
				continue;
			}
			else
			{
				buffFile << nameDish << '|' << nameCook << '\n';
			}
		}
		buffFile.close();
		fileIO.close();

		fileIO.open("DishesFile.txt", fstream::out);
		buffFile.open("BuffFile.txt", fstream::in);
		while (!buffFile.eof())
		{
			buffFile.getline(nameDish, 50, '|');
			buffFile.getline(nameCook, 50);
			if (strcmp(nameDish, "") != 0)
			{
				fileIO << nameDish << '|' << nameCook << '\n';
			}
		}
		buffFile.close();
		fileIO.close();
		remove("BuffFile.txt");
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");
		printf("Файл не создан\n\n");
		system("pause");
	}
	system("cls");
}

void displayAllDishes()
{
	system("cls");
	if (df != 0) //Проверка, создан ли файл
	{
		fstream fileIO;
		fileIO.open("DishesFile.txt", fstream::in);
		//cout << "Файл успешно открыт" << endl;
		cin.ignore();
		cout << "-----------------------------------------------------------------" << endl;
		cout << "| Название блюда		| Имя повара                    |" << endl;
		cout << "-----------------------------------------------------------------" << endl;
		while (!fileIO.eof())
		{
			char nameDish[50];
			char nameCook[50];
			char a[100] = "|                               |                               |";
			int x = 0;

			fileIO.getline(nameDish, 50, '|');
			if (strcmp(nameDish, "") != 0)
			{
				for (int i = 0; nameDish[i] != 0; i++)
				{
					a[i + 2] = nameDish[i];
				}
				fileIO.getline(nameCook, 50); // 50, '|'
				for (int i = 0; nameCook[i] != 0; i++)
				{
					a[i + 34] = nameCook[i];
				}
				cout << a << endl;
			}
		}
		fileIO.close();
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");
		printf("Файл не создан\n\n");
		system("pause");
	}
	system("cls");
}

int main()
{
	setlocale(LC_ALL, "Russian");
	bool OOAM = true;
	do
	{
		printf("Сделайте выбор для продолжения:\n");
		int choice;
		do
		{
			printf("1. Управление блюдами\n");
			printf("2. Управление меню\n");
			printf("3. Управление заказами\n");
			printf("4. Выход\n");
			printf("Ваш выбор: ");
			cin >> choice;
			system("cls");
		} while (choice > 5);
		switch (choice)
		{
		case 1: manageMenuDishes(); break;
		case 2: manageMenuMenus(); break;
		case 3: manageMenuOrders(); break;
		case 4: OOAM = false; break;
		default: printf("Ваш выбор неверен.\n");
		}
	} while (OOAM);
	return 0;
}
