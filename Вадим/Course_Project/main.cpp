#include "Header.h"


void main()
{
	// ����� � ������ ��� ���������� ������ �������� �����
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	string fullDBFileName = "Full_data_base.txt"; // ��� ����� ������ ���� ������ (����� - ��)
	ifstream readFile(fullDBFileName); // ������ ����
	vector<Request> ourRequestBase; // ������������ �� ���� "������" ��� �������� ���� ������
	pushRequestVectorFromFile(readFile, ourRequestBase); // ��������� ������������ �� ���, ��� � ����� (readFile)


	string headOfServiceFileName = "Head_of_service_table.txt", storeManagerFileName = "Store_manager_table.txt", engineerFileName = "Engineer_table.txt"; // ����� ������ � ��������� �����
	ofstream writeInFile_1(headOfServiceFileName), writeInFile_2(storeManagerFileName), writeInFile_3(engineerFileName), writeInFile_M(fullDBFileName); // ������ ������ � ����� ����� � ��


	Request myRequest; // ���������� ��������� ������, ������� ����� ���������
	string userAnswer; int integerAnswer;

	
	startOfBeginPart:
	cout << "�������� ���� �������: \n1) �������� ���� ������ �� ���� ���������� ������\n2) �������� ���� ������ �� ���� ���������� ���������\n3) �������� ���� ������ �� ���� ��������\n4) ����� ������ �� ���� ���� ������\n5) �������� ������ \n6) ���������� ������ \n0) ����� \n\n ��� �����: ";
	cin >> userAnswer;

	switch (userAnswer[0])
	{
	case '1': // �� ���������� ������
	{
		system("cls");
		headOfServiceStart:
		cOutRequestTable(ourRequestBase, 'H');
		cout << "\n�������� ���� �������: \n1) ������������� ������ �������������\n2) ��������� \n\n ��� �����: "; cin >> userAnswer;

		if (userAnswer[0] == '1')
		{
			cout << "������� ����� ������, � ������� ����� ������� ��������� ������.  \n\n ��� �����: "; cin >> integerAnswer;
			if (integerAnswer > 0 && integerAnswer < ourRequestBase.size()+1) // �������� �� ������������ ��������� ����� ��
			{
				ourRequestBase[integerAnswer - 1].isConfirmed = !ourRequestBase[integerAnswer - 1].isConfirmed;
				system("cls");
				goto headOfServiceStart;
			}
			else // user-�����
			{
				system("cls");
				cout << "- ������������ ������� ������. ���������� ��� ��� !!!" << endl;
				goto headOfServiceStart;
			}
		}
		if (userAnswer[0] == '2') // �������
		{
			system("cls");
			goto startOfBeginPart;
		}
		else // user-�����
		{
			system("cls");
			cout << "- ������������ ������� ������. ���������� ��� ��� !!!" << endl;
			goto headOfServiceStart;
		}

		break;
	}
	case '2': // �� �����-���������
	{
		system("cls");
		
		storeManagerStart:
		cOutRequestTable(ourRequestBase, 'S');
		cout << "\n�������� ���� �������: \n1) ������������� ������ �������\n2) ��������� \n\n ��� �����: "; cin >> userAnswer;

		if (userAnswer[0] == '1')
		{
			cout << "������� ����� ������, � ������� ����� ������� ��������� ������.  \n\n ��� �����: "; cin >> integerAnswer;
			if (integerAnswer > 0 && integerAnswer < ourRequestBase.size() + 1) // �������� �� ������������ ��������� ����� ��
			{
				ourRequestBase[integerAnswer - 1].isInStore = !ourRequestBase[integerAnswer - 1].isInStore;
				system("cls");
				goto storeManagerStart;
				
			}
			else // user-�����
			{
				system("cls");
				cout << "- ������������ ������� ������. ���������� ��� ��� !!!" << endl;
				goto storeManagerStart;
			}
		}
		if (userAnswer[0] == '2') // �������
		{
			system("cls");
			goto startOfBeginPart;
		}
		else // user-�����
		{
			system("cls");
			cout << "- ������������ ������� ������. ���������� ��� ��� !!!" << endl;
			goto storeManagerStart;
		}

		break;
	}
	case '3': // �� ��������
	{
		system("cls");

		engineerStart:
		cOutRequestTable(ourRequestBase, 'E');
		cout << "\n�������� ���� �������: \n1) ������������� ������ �����������������\n2) ��������� \n\n ��� �����: "; cin >> userAnswer;

		if (userAnswer[0] == '1')
		{
			cout << "������� ����� ������, � ������� ����� ������� ��������� ������.  \n\n ��� �����: "; cin >> integerAnswer;
			if (integerAnswer > 0 && integerAnswer < ourRequestBase.size() + 1) // �������� �� ������������ ��������� ����� ��
			{
				ourRequestBase[integerAnswer - 1].isSatisfactByDate = !ourRequestBase[integerAnswer - 1].isSatisfactByDate;
				system("cls");
				goto engineerStart;

			}
			else // user-�����
			{
				system("cls");
				cout << "- ������������ ������� ������. ���������� ��� ��� !!!" << endl;
				goto engineerStart;
			}
		}
		if (userAnswer[0] == '2') // �������
		{
			system("cls");
			goto startOfBeginPart;
		}
		else // user-�����
		{
			system("cls");
			cout << "- ������������ ������� ������. ���������� ��� ��� !!!" << endl;
			goto engineerStart;
		}

		break;
	}

	case '4': // �����
	{
		system("cls");
		cOutRequestTable(ourRequestBase, 'F');
		cout << "������� ��������� ������, ����� ����� ���������� ������. � �������� ���������� ������� ������� �������� ���������, ���������� ���������, ������� ��������� ���������, ���� �������� ��� �������� �������������, ���������� ��������. �������������� ������� ������ �������. �������� ��� ���������� ������ �� ���������� ������� (������ 250 � 01.10.2019 �������� 0 1 1) ���������� ����� ������ (���) ��� (250) ��� (01.10) ��� (���). ������� �����������!\n\n ��� ������: ";
		cin >> userAnswer;
		integerAnswer = findPositionByKey(userAnswer, ourRequestBase, 0);
		if (integerAnswer !=-1)
		{
			system("cls");
			cOutRequestTable(ourRequestBase, 'F');
			cout << " ����� ������, ��������������� ������� - " << integerAnswer+1 << endl;
		}
		else
		{
			system("cls");
			cout << " ������ �� �������. " << endl;
		}
		cout  << "������� Enter ����� ���������� ... " << endl;
		_getch();
		goto startOfBeginPart;
	}
	
	case '5': // �������� ������
	{
		system("cls");
		cOutRequestTable(ourRequestBase, 'F');
		cout << "\n������� ����� ������, ������� ������ �������.\n\n ��� �����: ";
		cin >> integerAnswer;
		
		if (integerAnswer > 0 && integerAnswer < ourRequestBase.size() + 1) // �������� �� ������������ ��������� ����� ��
		{
			deleteRequestFromDataBase(ourRequestBase, integerAnswer-1);
			system("cls");
			cout << " ������ �������! " << endl << endl;
			cOutRequestTable(ourRequestBase, 'F');
			cout << "������� Enter ����� ���������� ... " << endl;
			system("cls");
			_getch();
			goto startOfBeginPart;
		}
		else  // user-�����
		{
			system("cls");
			cout << " ������������ ����� ������ " << endl << endl;
			goto startOfBeginPart;
		}
	
	}
	case '6': // ���������� ������
	{
		system("cls");

		cout << " ������� �������� ���������: "; cin >> myRequest.requestName;
		cout << " ������� ���������� ���������: "; cin >> myRequest.requestSize;
		cout << " ������� ��� ������ ��������: "; cin >> myRequest.requestSizeType;
		cout << " ������� ���� ��������: "; cin >> myRequest.dateOfDelivery;
		cout << " ������� �������� �������������, ������� �������� ��������: "; cin >> myRequest.subdivisionName;
		cout << " ������� �������������� ��������� (1 - ��, 0 - ���): "; cin >> myRequest.isConfirmed;
		cout << " ������� ����������� ��������� �� ������ (1 - ��, 0 - ���): "; cin >> myRequest.isInStore;
		cout << " ������� �������������������� ��������� (1 - ��, 0 - ���): "; cin >> myRequest.isSatisfactByDate;

		addRequestToDataBase(ourRequestBase, myRequest);
		system("cls");

		cout << " ������ ���������! \n\n";
		cOutRequestTable(ourRequestBase, 'F');
		goto startOfBeginPart;
	}
	case '0': // ���������� ������
	{
		system("cls");
		cout << "�� �������? \n1) ��\n2) ���\n\n ��� �����: "; cin >> userAnswer;
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
	default:  // user-�����
	{
		system("cls");
		cout << "- ������������ ������� ������. ���������� ��� ��� !!!" << endl;
		goto startOfBeginPart;
	}
	}
	

	// ��������� ��� �� ������ (���� ������ ������� �� ����������, ����� ���������!)
	writeRequestVectorToSubDataBase(writeInFile_M, ourRequestBase, 'F');
	writeRequestVectorToSubDataBase(writeInFile_1, ourRequestBase, 'H');
	writeRequestVectorToSubDataBase(writeInFile_2, ourRequestBase, 'S');
	writeRequestVectorToSubDataBase(writeInFile_3, ourRequestBase, 'E');
	system("cls");
	cout << "��������� ���������!\n\n";
}




