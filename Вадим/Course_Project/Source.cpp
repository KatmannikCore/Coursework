#include "Header.h"

// нахождение позиции заявки по ключу
int findPositionByKey(string key, vector<Request>& ourRequestBase, int startOfSearchIndex)
{ // key чуствителен к регистру!
	string containerOfRequestSizeInStringType;
	for (int i = startOfSearchIndex; i < ourRequestBase.size(); i++)
	{
		containerOfRequestSizeInStringType = to_string(ourRequestBase[i].requestSize);
		if ((ourRequestBase[i].requestName.find(key) != -1) || (ourRequestBase[i].dateOfDelivery.find(key) != -1) || (ourRequestBase[i].requestSizeType.find(key) != -1) || (containerOfRequestSizeInStringType.find(key) != -1) || (ourRequestBase[i].subdivisionName.find(key) != -1))
			return i;
	}
	return -1;
}
// вывод таблицы заявок в консоль
void cOutRequestTable(vector<Request> ourRequestBase, char role)
{ // role - символ схемы вывода по конкретной надобности (для начальника службы, главы склада, инженера соответственно и всю БД соответственно)
	if (role == 'H')
	{
		cout << "Номер\t\tМатериал \tКол-во \t\tЕдиница \tДата \t\t\tПодразделение\t\tПодтверждено\n\n";
		for (int i = 0; i < ourRequestBase.size(); i++)
		{
			cout << i+1 << ".\t\t" << ourRequestBase[i].requestName << "\t\t" << ourRequestBase[i].requestSize << "\t\t" << ourRequestBase[i].requestSizeType << "\t\t" << ourRequestBase[i].dateOfDelivery << "\t\t" << ourRequestBase[i].subdivisionName << "\t\t     " << (ourRequestBase[i].isConfirmed!=0? "Да": "Нет") << endl;
		}
	}
	if (role == 'S')
	{
		cout << "Номер\t\tМатериал \tКол-во \t\tЕдиница \tДата \t\t\tПодразделение\t\tВ наличии\n\n";
		for (int i = 0; i < ourRequestBase.size(); i++)
		{
			cout << i+1 << ".\t\t" << ourRequestBase[i].requestName << "\t\t" << ourRequestBase[i].requestSize << "\t\t" << ourRequestBase[i].requestSizeType << "\t\t" << ourRequestBase[i].dateOfDelivery << "\t\t" << ourRequestBase[i].subdivisionName << "\t\t    " << (ourRequestBase[i].isInStore != 0 ? "Да" : "Нет") << endl;
		}
	}
	if (role == 'E')
	{
		cout << "Номер\t\tМатериал \tКол-во \t\tЕдиница \tДата \t\t\tПодразделение\t\tУдовлетворено\n\n";
		for (int i = 0; i < ourRequestBase.size(); i++)
		{
			cout << i+1 << ".\t\t" << ourRequestBase[i].requestName << "\t\t" << ourRequestBase[i].requestSize << "\t\t" << ourRequestBase[i].requestSizeType << "\t\t" << ourRequestBase[i].dateOfDelivery << "\t\t" << ourRequestBase[i].subdivisionName << "\t\t     " << (ourRequestBase[i].isSatisfactByDate != 0 ? "Да" : "Нет") << endl;
		}
	}
	if (role == 'F')
	{
		cout << "Номер\t\tМатериал \tКол-во \t\tЕдиница \tДата \t\t\tПодразделение\t\tПодтверждено\t\tВ наличии\tУдовлетворено\n\n";
		for (int i = 0; i < ourRequestBase.size(); i++)
		{
			cout << i + 1 << ".\t\t" << ourRequestBase[i].requestName << "\t\t" << ourRequestBase[i].requestSize << "\t\t" << ourRequestBase[i].requestSizeType << "\t\t" << ourRequestBase[i].dateOfDelivery << "\t\t" << ourRequestBase[i].subdivisionName << "\t\t     " << (ourRequestBase[i].isConfirmed != 0 ? "Да " : "Нет") << "\t\t    " << (ourRequestBase[i].isInStore != 0 ? "Да" : "Нет") <<  "\t\t     " << (ourRequestBase[i].isSatisfactByDate != 0 ? "Да" : "Нет") << endl;
		}
	}
}
// прочитать БД из файла
void pushRequestVectorFromFile(ifstream& readFile, vector<Request>& ourRequestBase)
{
	string requestName;
	int requestSize;
	string requestSizeType;
	string dateOfDelivery;
	string subdivisionName;
	bool isConfirmed;
	bool isInStore;
	bool isSatisfactByDate;


	if (readFile.is_open())
	{
		while (readFile >> requestName >> requestSize >> requestSizeType >> dateOfDelivery >> subdivisionName >> isConfirmed >> isInStore >> isSatisfactByDate)
		{
			ourRequestBase.push_back(Request(requestName, requestSize, requestSizeType, dateOfDelivery, subdivisionName, isConfirmed, isInStore, isSatisfactByDate));
		}
	}
	readFile.close();
}
// записать БД в файл
void writeRequestVectorToSubDataBase(ofstream& writeInFile, vector<Request>& ourRequestBase, char role)
{
	if (role == 'H')
	{
		if (writeInFile.is_open())
		{
			for (int i = 0; i < ourRequestBase.size(); i++)
			{
				writeInFile << ourRequestBase[i].requestName << " " << ourRequestBase[i].requestSize << " " << ourRequestBase[i].requestSizeType << " " << ourRequestBase[i].dateOfDelivery << " " << ourRequestBase[i].subdivisionName << " " << ourRequestBase[i].isConfirmed << endl;
			}
		}
	}
	if (role == 'S')
	{
		if (writeInFile.is_open())
		{
			for (int i = 0; i < ourRequestBase.size(); i++)
			{
				writeInFile << ourRequestBase[i].requestName << " " << ourRequestBase[i].requestSize << " " << ourRequestBase[i].requestSizeType << " " << ourRequestBase[i].dateOfDelivery << " " << ourRequestBase[i].subdivisionName << " " << ourRequestBase[i].isInStore << endl;
			}
		}
	}
	if (role == 'E')
	{
		if (writeInFile.is_open())
		{
			for (int i = 0; i < ourRequestBase.size(); i++)
			{
				writeInFile << ourRequestBase[i].requestName << " " << ourRequestBase[i].requestSize << " " << ourRequestBase[i].requestSizeType << " " << ourRequestBase[i].dateOfDelivery << " " << ourRequestBase[i].subdivisionName << " " << ourRequestBase[i].isSatisfactByDate << endl;
			}
		}
	}
	if (role == 'F')
	{
		if (writeInFile.is_open())
		{
			for (int i = 0; i < ourRequestBase.size(); i++)
			{
				writeInFile << ourRequestBase[i].requestName << " " << ourRequestBase[i].requestSize << " " << ourRequestBase[i].requestSizeType << " " << ourRequestBase[i].dateOfDelivery << " " << ourRequestBase[i].subdivisionName <<  " " << ourRequestBase[i].isConfirmed <<  " " << ourRequestBase[i].isInStore << " " << ourRequestBase[i].isSatisfactByDate << endl;
			}
		}
	}

}
// удаление заявки из БД
void deleteRequestFromDataBase(vector<Request>& ourRequestBase, int deletePosition)
{
	ourRequestBase.erase(ourRequestBase.begin() + deletePosition);
}
// добавление заявки в БД
void addRequestToDataBase(vector<Request>& ourRequestBase, Request ourRequest)
{
	ourRequestBase.push_back(ourRequest);
}



