#pragma once


#include <iostream> // работа с потоком ввода/вывода (cout там вс€кие)
#include <string> // работа со строками
#include <fstream> // работа с файлами
#include <vector> // использование хитрыого класса, повзол€ющего нам удобно обращатьс€ с нашими за€вками
#include <conio.h> // дл€ _getch()
#include <Windows.h> // дл€ выставлени€ кодировок, позвол€ющих вводить русские символы из консоли



using namespace std;


struct Request
{
	string requestName;
	int requestSize;
	string requestSizeType;
	string dateOfDelivery;
	string subdivisionName;

	bool isConfirmed = false;  // только дл€ начальника службы
	bool isInStore = false;  // только дл€ склада
	bool isSatisfactByDate = false;  // только дл€ инженера

	Request() {} // конструктор по умолчанию (пригодитс€ только дл€ создани€ пустой Ѕƒ в начале)
	Request(string rN, int rS, string rST, string dOD, string sN, bool iC, bool iIS, bool iSBD) : requestName(rN), requestSize(rS), requestSizeType(rST), dateOfDelivery(dOD), subdivisionName(sN), isConfirmed(iC), isInStore(iIS), isSatisfactByDate(iSBD) {} // конструктор дл€ удобного заполнени€ вектора
};


int findPositionByKey(string key, vector<Request>& ourRequestBase, int startOfSearchIndex);
void cOutRequestTable(vector<Request> ourRequestBase, char role);
void pushRequestVectorFromFile(ifstream& readFile, vector<Request>& ourRequestBase);
void writeRequestVectorToSubDataBase(ofstream& writeInFile, vector<Request>& ourRequestBase, char role);
void deleteRequestFromDataBase(vector<Request>& ourRequestBase, int deletePosition);
void addRequestToDataBase(vector<Request>& ourRequestBase, Request ourRequest);