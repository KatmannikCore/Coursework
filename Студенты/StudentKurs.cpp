
#include<iostream>
#include<string>
#include<conio.h>
#include<fstream>
#include<iomanip>//Для пробелов между словами и символами
#include<Windows.h>
#define N 1

using namespace std;

struct OT
{
	int shifr_studenta;

	char imja[20 + 1];
	char familia[20 + 1];
	char otchestvo[20 + 1];
	char facultet[10 + 1];
	int shifr_gruppi;
	int matematika;
	int angl;
	int history;
	int count;
};

bool add(int& count, OT* ot);
void drawLineW();
void drawLineN();
void print(int count, OT* ot);
void Menu(int count, OT* ot);

void horosho(int count, OT* ot);
void ploho(int count, OT* ot);
void search_student(int count, OT* ot);

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	system("cls");

	int count = N;
	OT* ot = new OT[count];
	Menu(count, ot);

	_getch();
	return 0;
}
void Menu(int count, OT* ot)
{
	system("cls");
	int numberSearch;
	do
	{
		cout << "Здравствуйте, пожалуйста выбирайте поле в Меню" << endl;
		cout << "1- Добавление студента " << endl;
		cout << "2- Печать студентов" << endl;
		cout << "3- Печать студентов со средним баллом 4 и выше" << endl;
		cout << "4- Печать студентов со средним баллом 3 ниже " << endl;
		cout << "5- вывести информацию о студенте" << endl;
		cout << "6- Выход из программы" << endl;
		cin >> numberSearch;
		switch (numberSearch)
		{
		case 1: add(count, ot); break;
		case 2: print(count, ot); break;
		case 3: horosho(count, ot); break;
		case 4: ploho(count, ot); break;
		case 5: search_student(count, ot); break;
		case 6: exit(0); break;
		}
	} while (numberSearch != 6);
	system("cls");
}

bool add(int& count, OT* ot)
{
	system("cls");
	cout << setw(50) << "Добавленние студента" << endl;

	for (int i = 0; i < count; i++)
	{
		system("cls");
		cout << "Номер группы: " << endl;
		cin.ignore(4, '\n') >> setw(6) >> ot[i].shifr_gruppi;//удалить разделитель строк,// пропускает указанное число элементов от текущей позиции чтения
		cout << "Фамилия студента " << endl;
		cin.ignore(20, '\n') >> setw(20) >> ot[i].familia;
		cout << "Отчество студента " << endl;
		cin.ignore(20, '\n') >> setw(20) >> ot[i].otchestvo;
		cout << "Имя студента " << endl;
		cin.ignore(20, '\n') >> setw(20) >> ot[i].imja;
		cout << "Номер студента: " << endl;
		cin.ignore(4, '\n') >> setw(6) >> ot[i].shifr_studenta;
		cout << "Оценка по математике " << endl;
		cin.ignore(4, '\n') >> setw(1) >> ot[i].matematika;
		cout << "Оценка по английскому " << endl;
		cin.ignore(4, '\n') >> setw(1) >> ot[i].angl;
		cout << "Оценка по история " << endl;
		cin.ignore(4, '\n') >> setw(1) >> ot[i].history;
	}
	system("cls");
	for (int i = 1; i < count; i++)
		for (int j = 0; j < count; j++)
			if (ot[i].shifr_gruppi == ot[j].shifr_gruppi &&
				ot[i].familia == ot[j].familia &&
				ot[i].otchestvo == ot[i].otchestvo &&
				ot[i].imja == ot[i].imja &&
				ot[i].shifr_studenta == ot[i].shifr_studenta &&
				ot[i].matematika == ot[i].matematika &&
				ot[i].angl == ot[i].angl &&
				ot[i].history == ot[i].history
				)
			{
				ot[j].count += ot[i].count;
				return true;
			}
	return false;

	char choice;
	do {
		cout << "\n Возвращение в меню кнопка -y; выход из Меню любая другая кнопка... " << endl;
		cin >> choice;
		if (choice == 'y')
			Menu(count, ot);

		else return exit;
	} while (1);


	system("cls");
}

void drawLineW()
{
	for (int i = 0; i < 80; ++i)
		cout << "_";
}

void drawLineN()
{
	for (int i = 0; i < 80; ++i)
		cout << "-";
}

void print(int count, OT* ot)
{
	system("cls");
	setlocale(LC_ALL, "Russian");

	cout << setw(40) << "Учёт успеваемости студента" << endl;
	drawLineW();
	cout << setiosflags(ios::left) << setw(6) << "\n| Шифр студента: " << setw(20) << "| Фамилия студента:       |"
		<< setw(20) << "| Имя студента:       |"
		<< setw(20) << "| Отечество студента:       |" << setw(6) << " шифр группы: |" << setw(1) << " оценка по английскому: |"
		<< setw(1) << " оценка по математике: |" << setw(1) << " оценка по истории: |"
		<< setw(1) << "Среднее: |" << endl;
	drawLineN();

	for (int i = 0; i < count; ++i)
	{
		float  srednee = (ot[i].matematika + ot[i].angl + ot[i].history) / 3;
		cout << setiosflags(std::ios::left) << "\n" << "| "
			<< setw(6) << ot[i].shifr_studenta << " | "
			<< setw(20) << ot[i].familia << " | "
			<< setw(20) << ot[i].imja << " | "
			<< setw(20) << ot[i].otchestvo << " | "
			<< setw(6) << ot[i].shifr_gruppi << " | "
			<< setw(1) << ot[i].angl << " | "
			<< setw(1) << ot[i].matematika << " | "
			<< setw(1) << ot[i].history << " | "
			<< setw(1) << srednee << " | "
			<< endl;
		drawLineN();
	}

	char choice;
	do {
		cout << "\n Возвращение в меню кнопка -y; выход из Меню любая другая кнопка... " << endl;
		cin >> choice;
		if (choice == 'y')
			Menu(count, ot);

		else return exit(1);
	} while (1);

}

void horosho(int count, OT* ot)
{
	system("cls");// Получение из файла кол-ва записей в б.д.
	float srednee;

	cout << setw(40) << "Список студентов с баллом 4 и выше" << endl;
	drawLineW();
	cout << setiosflags(ios::left) << setw(6) << "\n| Шифр студента: " << setw(6) << "| Шифр группы:       |"
		<< setw(20) << "Фамилия     |" << setw(20) << " Имя     |" << setw(20) << "Отчество      |" << setw(1) << " Оценка по английскому: |" << setw(1) << " Оценка по математике: |"
		<< setw(1) << " Оценка по истории : |"
		<< setw(1) << "Среднее: |"
		<< endl;
	drawLineN();

	for (int i = 0; i < count; ++i)
	{
		srednee = (ot[i].matematika + ot[i].angl + ot[i].history) / 3;
		if (srednee >= 4) {

			srednee = (ot[i].matematika + ot[i].angl + ot[i].history) / 3;
			cout << setw(6) << ot[i].shifr_studenta << " | "
				<< setw(6) << ot[i].shifr_gruppi << " | "
				<< setw(20) << ot[i].familia << " | "
				<< setw(20) << ot[i].imja << " | "
				<< setw(20) << ot[i].otchestvo << " | "
				<< setw(1) << ot[i].angl << " | "
				<< setw(1) << ot[i].matematika << " | "
				<< setw(1) << ot[i].history << " | "
				<< setw(1) << srednee << " | "
				<< endl;

			drawLineN();
		}
	}
	char choice;
	do {
		cout << "\n Возвращение в меню кнопка -y; выход из Меню любая другая кнопка... " << endl;
		cin >> choice;
		if (choice == 'y')
			Menu(count, ot);

		else return exit(1);
	} while (1);

}
void ploho(int count, OT* ot) {
	system("cls");// Получение из файла кол-ва записей в б.д
	float srednee;
	cout << setw(40) << "Список студентов с баллом ниже 4" << endl;
	drawLineW();
	cout << setiosflags(ios::left) << setw(6) << "\n| Шифр студента: " << setw(6) << "| Шифр группы:       |"
		<< setw(20) << "Фамилия     |" << setw(20) << " Имя     |" << setw(20) << "Отчество      |" << setw(1) << " Оценка по английскому: |" << setw(1) << " Оценка по математике: |"
		<< setw(1) << " Оценка по истории : |"
		<< setw(1) << "Среднее: |"
		<< endl;
	drawLineN();

	for (int i = 0; i < count; ++i)
	{
		srednee = (ot[i].matematika + ot[i].angl + ot[i].history) / 3;
		if (srednee < 3) {
			srednee = (ot[i].matematika + ot[i].angl + ot[i].history) / 3;
			cout << setw(6) << ot[i].shifr_studenta << " | "
				<< setw(6) << ot[i].shifr_gruppi << " | "
				<< setw(20) << ot[i].familia << " | "
				<< setw(20) << ot[i].imja << " | "
				<< setw(20) << ot[i].otchestvo << " | "
				<< setw(1) << ot[i].angl << " | "
				<< setw(1) << ot[i].matematika << " | "
				<< setw(1) << ot[i].history << " | "
				<< setw(1) << srednee << " | "
				<< endl;

			drawLineN();
		}
	}
	char choice;
	do {
		cout << "\n Возвращение в меню кнопка -y; выход из Меню любая другая кнопка... " << endl;
		cin >> choice;
		if (choice == 'y')
			Menu(count, ot);

		else return exit(1);
	} while (1);
}



void search_student(int count, OT* ot) {
	system("cls");
	for (int i = 0; i < count; ++i) {
		float    srednee = (ot[i].matematika + ot[i].angl + ot[i].history) / 3;
		cout << setw(60) << "Введите код  студента" << endl;
		cin >> ot[i].shifr_studenta;

		cout << setw(60) << "Студент" << endl;
		drawLineW();
		cout << setiosflags(ios::left) << setw(6) << "\n| Шифр студента: " << setw(6) << "| Шифр группы:       |"
			<< setw(20) << "Фамилия     |" << setw(20) << " Имя     |" << setw(20) << "Отчество      |" << setw(1) << " Оценка по английскому: |" << setw(1) << " Оценка по математике: |"
			<< setw(1) << " Оценка по истории : |"
			<< setw(1) << "Среднее: |"
			<< endl;
		drawLineN();
		if (ot[i].shifr_studenta) {
			cout << "\n" << "| "
				<< setw(6) << ot[i].shifr_studenta << " | "
				<< setw(6) << ot[i].shifr_gruppi << " | "
				<< setw(20) << ot[i].familia << " | "
				<< setw(20) << ot[i].imja << " | "
				<< setw(20) << ot[i].otchestvo << " | "
				<< setw(1) << ot[i].angl << " | "
				<< setw(1) << ot[i].matematika << " | "
				<< setw(1) << ot[i].history << " | "
				<< setw(1) << srednee << " | "
				<< endl;
			drawLineN();
		}
	}
	char choice;
	do {
		cout << "\n Возвращение в меню кнопка -y; выход из Меню любая другая кнопка... " << endl;
		cin >> choice;
		if (choice == 'y')
			Menu(count, ot);

		else return exit(1);
	} while (1);

}