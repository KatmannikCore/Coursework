#include "Header.h"


void main()
{
	// танцы с бубном для нормальной работы русского языка
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	string fullDBFileName = "Full_data_base.txt"; // имя файла полной база данных (далее - БД)
	ifstream readFile(fullDBFileName); // читаем файл
	vector<Request> ourRequestBase; // динамическая БД типа "вектор" для хранения всех заявок
	pushRequestVectorFromFile(readFile, ourRequestBase); // заполняем динамическую БД тем, что в файле (readFile)


	string headOfServiceFileName = "Head_of_service_table.txt", storeManagerFileName = "Store_manager_table.txt", engineerFileName = "Engineer_table.txt"; // Имена файлов с таблицами подБД
	ofstream writeInFile_1(headOfServiceFileName), writeInFile_2(storeManagerFileName), writeInFile_3(engineerFileName), writeInFile_M(fullDBFileName); // потоки записи в файлы подБД и БД


	Request myRequest; // переменная отдельной заявки, которую будем добавлять
	string userAnswer; int integerAnswer;

	
	startOfBeginPart:
	cout << "Выберите один вариант: \n1) просмотр базы данных от лица начальника службы\n2) просмотр базы данных от лица складского менеджера\n3) просмотр базы данных от лица инженера\n4) поиск заявки по всей базе данных\n5) удаление заявки \n6) добавление заявки \n0) выйти \n\n Ваш ответ: ";
	cin >> userAnswer;

	switch (userAnswer[0])
	{
	case '1': // БД начальника службы
	{
		system("cls");
		headOfServiceStart:
		cOutRequestTable(ourRequestBase, 'H');
		cout << "\nВыберите один вариант: \n1) Редактировать статус подтверждения\n2) Вернуться \n\n Ваш ответ: "; cin >> userAnswer;

		if (userAnswer[0] == '1')
		{
			cout << "Введите номер заявки, у которой будет изменен выбранный статус.  \n\n Ваш ответ: "; cin >> integerAnswer;
			if (integerAnswer > 0 && integerAnswer < ourRequestBase.size()+1) // проверка на соответствие габаритам нашей БД
			{
				ourRequestBase[integerAnswer - 1].isConfirmed = !ourRequestBase[integerAnswer - 1].isConfirmed;
				system("cls");
				goto headOfServiceStart;
			}
			else // user-дурак
			{
				system("cls");
				cout << "- Недопустимый вариант ответа. Попробуйте ещё раз !!!" << endl;
				goto headOfServiceStart;
			}
		}
		if (userAnswer[0] == '2') // обратно
		{
			system("cls");
			goto startOfBeginPart;
		}
		else // user-дурак
		{
			system("cls");
			cout << "- Недопустимый вариант ответа. Попробуйте ещё раз !!!" << endl;
			goto headOfServiceStart;
		}

		break;
	}
	case '2': // БД склад-менеджера
	{
		system("cls");
		
		storeManagerStart:
		cOutRequestTable(ourRequestBase, 'S');
		cout << "\nВыберите один вариант: \n1) Редактировать статус наличия\n2) Вернуться \n\n Ваш ответ: "; cin >> userAnswer;

		if (userAnswer[0] == '1')
		{
			cout << "Введите номер заявки, у которой будет изменен выбранный статус.  \n\n Ваш ответ: "; cin >> integerAnswer;
			if (integerAnswer > 0 && integerAnswer < ourRequestBase.size() + 1) // проверка на соответствие габаритам нашей БД
			{
				ourRequestBase[integerAnswer - 1].isInStore = !ourRequestBase[integerAnswer - 1].isInStore;
				system("cls");
				goto storeManagerStart;
				
			}
			else // user-дурак
			{
				system("cls");
				cout << "- Недопустимый вариант ответа. Попробуйте ещё раз !!!" << endl;
				goto storeManagerStart;
			}
		}
		if (userAnswer[0] == '2') // обратно
		{
			system("cls");
			goto startOfBeginPart;
		}
		else // user-дурак
		{
			system("cls");
			cout << "- Недопустимый вариант ответа. Попробуйте ещё раз !!!" << endl;
			goto storeManagerStart;
		}

		break;
	}
	case '3': // БД инженера
	{
		system("cls");

		engineerStart:
		cOutRequestTable(ourRequestBase, 'E');
		cout << "\nВыберите один вариант: \n1) Редактировать статус удовлетворенности\n2) Вернуться \n\n Ваш ответ: "; cin >> userAnswer;

		if (userAnswer[0] == '1')
		{
			cout << "Введите номер заявки, у которой будет изменен выбранный статус.  \n\n Ваш ответ: "; cin >> integerAnswer;
			if (integerAnswer > 0 && integerAnswer < ourRequestBase.size() + 1) // проверка на соответствие габаритам нашей БД
			{
				ourRequestBase[integerAnswer - 1].isSatisfactByDate = !ourRequestBase[integerAnswer - 1].isSatisfactByDate;
				system("cls");
				goto engineerStart;

			}
			else // user-дурак
			{
				system("cls");
				cout << "- Недопустимый вариант ответа. Попробуйте ещё раз !!!" << endl;
				goto engineerStart;
			}
		}
		if (userAnswer[0] == '2') // обратно
		{
			system("cls");
			goto startOfBeginPart;
		}
		else // user-дурак
		{
			system("cls");
			cout << "- Недопустимый вариант ответа. Попробуйте ещё раз !!!" << endl;
			goto engineerStart;
		}

		break;
	}

	case '4': // поиск
	{
		system("cls");
		cOutRequestTable(ourRequestBase, 'F');
		cout << "Введите известные данные, чтобы найти подходящую заявку. В качестве поискового запроса подойдёт название материала, количество материала, единица измерения материала, дата поставки или название подразделения, принявшего материал. Неоябязательно вводить данные целиком. Например для нахождения заявки со следующими данными (Бензин 250 т 01.10.2019 Заправка 0 1 1) достаточно будет ввести (зин) или (250) или (01.10) или (Зап). Регистр учитывается!\n\n Ваш запрос: ";
		cin >> userAnswer;
		integerAnswer = findPositionByKey(userAnswer, ourRequestBase, 0);
		if (integerAnswer !=-1)
		{
			system("cls");
			cOutRequestTable(ourRequestBase, 'F');
			cout << " Номер заявки, удовлетворяющий запросу - " << integerAnswer+1 << endl;
		}
		else
		{
			system("cls");
			cout << " Ничего не найдено. " << endl;
		}
		cout  << "Нажмите Enter чтобы продолжить ... " << endl;
		_getch();
		goto startOfBeginPart;
	}
	
	case '5': // удаление заявки
	{
		system("cls");
		cOutRequestTable(ourRequestBase, 'F');
		cout << "\nВведите номер заявки, которую хотите удалить.\n\n Ваш ответ: ";
		cin >> integerAnswer;
		
		if (integerAnswer > 0 && integerAnswer < ourRequestBase.size() + 1) // проверка на соответствие габаритам нашей БД
		{
			deleteRequestFromDataBase(ourRequestBase, integerAnswer-1);
			system("cls");
			cout << " Заявка удалена! " << endl << endl;
			cOutRequestTable(ourRequestBase, 'F');
			cout << "Нажмите Enter чтобы продолжить ... " << endl;
			system("cls");
			_getch();
			goto startOfBeginPart;
		}
		else  // user-дурак
		{
			system("cls");
			cout << " Неккоректный номер заявки " << endl << endl;
			goto startOfBeginPart;
		}
	
	}
	case '6': // добавление заявки
	{
		system("cls");

		cout << " Введите название материала: "; cin >> myRequest.requestName;
		cout << " Введите количество материала: "; cin >> myRequest.requestSize;
		cout << " Введите тип единиц материла: "; cin >> myRequest.requestSizeType;
		cout << " Введите дату поставки: "; cin >> myRequest.dateOfDelivery;
		cout << " Введите название подразделения, которое заказало материал: "; cin >> myRequest.subdivisionName;
		cout << " Введите утвержденность материала (1 - да, 0 - нет): "; cin >> myRequest.isConfirmed;
		cout << " Введите присутствие материала на складе (1 - да, 0 - нет): "; cin >> myRequest.isInStore;
		cout << " Введите удовлетворительность материала (1 - да, 0 - нет): "; cin >> myRequest.isSatisfactByDate;

		addRequestToDataBase(ourRequestBase, myRequest);
		system("cls");

		cout << " Заявка добавлена! \n\n";
		cOutRequestTable(ourRequestBase, 'F');
		goto startOfBeginPart;
	}
	case '0': // завершение сеанса
	{
		system("cls");
		cout << "Вы уверены? \n1) Да\n2) Нет\n\n Ваш ответ: "; cin >> userAnswer;
		if (userAnswer[0] == '1')
		{
			system("cls");
		}
		else {
			system("cls");
			goto startOfBeginPart;
		}
		break;
	}
	default:  // user-дурак
	{
		system("cls");
		cout << "- Недопустимый вариант ответа. Попробуйте ещё раз !!!" << endl;
		goto startOfBeginPart;
	}
	}
	

	// сохраняем все по файлам (если нажать крестик до сохранения, файлы затруться!)
	writeRequestVectorToSubDataBase(writeInFile_M, ourRequestBase, 'F');
	writeRequestVectorToSubDataBase(writeInFile_1, ourRequestBase, 'H');
	writeRequestVectorToSubDataBase(writeInFile_2, ourRequestBase, 'S');
	writeRequestVectorToSubDataBase(writeInFile_3, ourRequestBase, 'E');
	system("cls");
	cout << "Изменения сохранены!\n\n";
}




