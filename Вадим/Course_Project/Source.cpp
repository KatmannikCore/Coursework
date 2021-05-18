#include "Header.h"

// ���������� ������� ������ �� �����
int findPositionByKey(string key, vector<Request>& ourRequestBase, int startOfSearchIndex)
{ // key ����������� � ��������!
	string containerOfRequestSizeInStringType;
	for (int i = startOfSearchIndex; i < ourRequestBase.size(); i++)
	{
		containerOfRequestSizeInStringType = to_string(ourRequestBase[i].requestSize);
		if ((ourRequestBase[i].requestName.find(key) != -1) || (ourRequestBase[i].dateOfDelivery.find(key) != -1) || (ourRequestBase[i].requestSizeType.find(key) != -1) || (containerOfRequestSizeInStringType.find(key) != -1) || (ourRequestBase[i].subdivisionName.find(key) != -1))
			return i;
	}
	return -1;
}
// ����� ������� ������ � �������
void cOutRequestTable(vector<Request> ourRequestBase, char role)
{ // role - ������ ����� ������ �� ���������� ���������� (��� ���������� ������, ����� ������, �������� �������������� � ��� �� ��������������)
	if (role == 'H')
	{
		cout << "�����\t\t�������� \t���-�� \t\t������� \t���� \t\t\t�������������\t\t������������\n\n";
		for (int i = 0; i < ourRequestBase.size(); i++)
		{
			cout << i+1 << ".\t\t" << ourRequestBase[i].requestName << "\t\t" << ourRequestBase[i].requestSize << "\t\t" << ourRequestBase[i].requestSizeType << "\t\t" << ourRequestBase[i].dateOfDelivery << "\t\t" << ourRequestBase[i].subdivisionName << "\t\t     " << (ourRequestBase[i].isConfirmed!=0? "��": "���") << endl;
		}
	}
	if (role == 'S')
	{
		cout << "�����\t\t�������� \t���-�� \t\t������� \t���� \t\t\t�������������\t\t� �������\n\n";
		for (int i = 0; i < ourRequestBase.size(); i++)
		{
			cout << i+1 << ".\t\t" << ourRequestBase[i].requestName << "\t\t" << ourRequestBase[i].requestSize << "\t\t" << ourRequestBase[i].requestSizeType << "\t\t" << ourRequestBase[i].dateOfDelivery << "\t\t" << ourRequestBase[i].subdivisionName << "\t\t    " << (ourRequestBase[i].isInStore != 0 ? "��" : "���") << endl;
		}
	}
	if (role == 'E')
	{
		cout << "�����\t\t�������� \t���-�� \t\t������� \t���� \t\t\t�������������\t\t�������������\n\n";
		for (int i = 0; i < ourRequestBase.size(); i++)
		{
			cout << i+1 << ".\t\t" << ourRequestBase[i].requestName << "\t\t" << ourRequestBase[i].requestSize << "\t\t" << ourRequestBase[i].requestSizeType << "\t\t" << ourRequestBase[i].dateOfDelivery << "\t\t" << ourRequestBase[i].subdivisionName << "\t\t     " << (ourRequestBase[i].isSatisfactByDate != 0 ? "��" : "���") << endl;
		}
	}
	if (role == 'F')
	{
		cout << "�����\t\t�������� \t���-�� \t\t������� \t���� \t\t\t�������������\t\t������������\t\t� �������\t�������������\n\n";
		for (int i = 0; i < ourRequestBase.size(); i++)
		{
			cout << i + 1 << ".\t\t" << ourRequestBase[i].requestName << "\t\t" << ourRequestBase[i].requestSize << "\t\t" << ourRequestBase[i].requestSizeType << "\t\t" << ourRequestBase[i].dateOfDelivery << "\t\t" << ourRequestBase[i].subdivisionName << "\t\t     " << (ourRequestBase[i].isConfirmed != 0 ? "�� " : "���") << "\t\t    " << (ourRequestBase[i].isInStore != 0 ? "��" : "���") <<  "\t\t     " << (ourRequestBase[i].isSatisfactByDate != 0 ? "��" : "���") << endl;
		}
	}
}
// ��������� �� �� �����
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
// �������� �� � ����
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
// �������� ������ �� ��
void deleteRequestFromDataBase(vector<Request>& ourRequestBase, int deletePosition)
{
	ourRequestBase.erase(ourRequestBase.begin() + deletePosition);
}
// ���������� ������ � ��
void addRequestToDataBase(vector<Request>& ourRequestBase, Request ourRequest)
{
	ourRequestBase.push_back(ourRequest);
}



