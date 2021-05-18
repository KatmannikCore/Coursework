#include <iostream>
#include <string>
#include <deque>
#include <Windows.h>
using namespace std;
class Author
{
public:
	string Name;
	string Surname;
	string  Print()
	{
		return  " Автор - Имя: " +Name + " Фамилия: " +Surname;
	}
	void AddAuthor()
	{
		cout << "Введите имя автора:" <<endl;
		cin >> Name;
		cout << "Введите фамилию автора::" << endl;
		cin >> Surname;
	}
};
class Book
{
public:
	string Name;
	Author autor;
	string Print()
	{
		return " Название:" + Name + autor.Print();
	}
	void AddBook()
	{
		cout << "Введите название книги:" << endl;
		cin >> Name;
		autor.AddAuthor();
	}
};
class Reader
{
public:
	string Name;
	string Surname;
	string Patronymic;
	Book book;
	string Print()
	{
		return "Имя: " + Name + " Фамилия: " + Surname + " Отчество: " + Patronymic + "\n" + book.Print();
	}
	void AddReader()
	{
		cout << "Введите имя читателя:" << endl;
		cin >> Name;
		cout << "Введите фамилию читателя:" << endl;
		cin >> Surname;
		cout << "Введите отчество читателя:" << endl;
		cin >> Patronymic;
	}
};
Book FindBook(deque<Book> books)
{
	bool selection = false;
	int number;
	while (true)
	{
		cout << "Введите номер добовляемой Книги:" << endl;
		cout << "Колличество эллентов: " << books.size() << endl;
		cin >> number;
		for (int i = 0; i < books.size(); i++)
		{
			if (i == number - 1)
			{

				selection = true;
				return books[i];
			}
			if (selection)
			{
				cout << "Данного номера не существует" << endl;
			}
		}
	}
}



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	Book bookEmpty;
	deque<Book> books;
	deque<Reader> readers;
	while (true)
	{
		int Number;
		bool selection = false;
		bool value = true;
		Book book;
		Reader reader;
		cout << "Введите опереацию:" << endl;
		cout << "1 - Просмотреть список книг" << endl;
		cout << "2 - Просмотреть список читателей" << endl;
		cout << "3 - Добавить книгу" << endl;
		cout << "4 - Добавить читателя" << endl;
		cout << "5 - Изменить книгу" << endl;
		cout << "6 - Изменить читателя " << endl;
		cout << "7 - Добавить книгу читателю" << endl;
		cout << "8 - Удалить книгу читателя" << endl;
		cin >> Number;
		int number;
		switch (Number)
		{
		case 1:
			for (int i = 0; i < books.size(); i++)
			{
				cout << books[i].Print() << endl;
			}
			break;
		case 2:
			for (int i = 0; i < readers.size(); i++)
			{
				cout << readers[i].Print()<<endl;
			}
			break;
		case 3:
			book.AddBook();
			books.push_back(book);
			break;
		case 4:
			reader.AddReader();
			readers.push_back(reader);
			break;
		case 5:
			while (value)
			{
				cout << "Введите номер изменяемого эллемента:" << endl;
				cout << "Колличество эллентов: " << books.size() << endl;
				cin >> number;
				for (int i = 0; i < books.size(); i++)
				{
					if (i == number -1)
					{
						books[i].AddBook();
						selection = true;
						cout << "Книга добавлена" << endl;
						value = false;
					}
					if (selection)
					{
						cout << "Данного номера не существует" << endl;
					}
				}
			}
			break;
		case 6:
			while (value)
			{
				cout << "Введите номер изменяемого эллемента:" << endl;
				cout << "Колличество эллентов: " << readers.size() << endl;
				cin >> number;
				for (int i = 0; i < readers.size(); i++)
				{
					if (i == number - 1)
					{
						readers[i].AddReader();
						selection = true;
						cout << "Читатель добавлен" << endl;
						value = false;
					}
					if (selection)
					{
						cout << "Данного номера не существует" << endl;
					}
				}
			}
			break;
		case 7:
			while (value)
			{
				cout << "Введите номер читателя брущего книгу:" << endl;
				cout << "Колличество читателй: " << readers.size() << endl;
				cin >> number;
				for (int i = 0; i < readers.size(); i++)
				{
					number--;
					if (i == number)
					{
						readers[i].book = FindBook(books);
						cout<< "Книга добавлена" <<endl;
						value = false;
						selection = false;
						break;
					}
					if (!selection)
					{
						cout << "Данного номера не существует" << endl;
					}
				}
			}
			break;
		case 8:
			while (value)
			{
				cout << "Введите номер читателя отдающего книгу:" << endl;
				cout << "Колличество читателей: " << readers.size() << endl;
				cin >> number;
				for (int i = 0; i < readers.size(); i++)
				{
					if (i == number - 1)
					{
						readers[i].book = bookEmpty;
						cout << "Книга удалена" << endl;
						selection = true;
						value = false;
					}
					if (!selection)
					{
						cout << "Данного номера не существует" << endl;
					}
				}
			}
			break;
		default:
			cout << "Неверно выедена операция";
			break;
		}
	}
}

