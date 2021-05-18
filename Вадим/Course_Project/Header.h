#pragma once


#include <iostream> // ������ � ������� �����/������ (cout ��� ������)
#include <string> // ������ �� ��������
#include <fstream> // ������ � �������
#include <vector> // ������������� �������� ������, ������������ ��� ������ ���������� � ������ ��������
#include <conio.h> // ��� _getch()
#include <Windows.h> // ��� ����������� ���������, ����������� ������� ������� ������� �� �������



using namespace std;


struct Request
{
	string requestName;
	int requestSize;
	string requestSizeType;
	string dateOfDelivery;
	string subdivisionName;

	bool isConfirmed = false;  // ������ ��� ���������� ������
	bool isInStore = false;  // ������ ��� ������
	bool isSatisfactByDate = false;  // ������ ��� ��������

	Request() {} // ����������� �� ��������� (���������� ������ ��� �������� ������ �� � ������)
	Request(string rN, int rS, string rST, string dOD, string sN, bool iC, bool iIS, bool iSBD) : requestName(rN), requestSize(rS), requestSizeType(rST), dateOfDelivery(dOD), subdivisionName(sN), isConfirmed(iC), isInStore(iIS), isSatisfactByDate(iSBD) {} // ����������� ��� �������� ���������� �������
};


int findPositionByKey(string key, vector<Request>& ourRequestBase, int startOfSearchIndex);
void cOutRequestTable(vector<Request> ourRequestBase, char role);
void pushRequestVectorFromFile(ifstream& readFile, vector<Request>& ourRequestBase);
void writeRequestVectorToSubDataBase(ofstream& writeInFile, vector<Request>& ourRequestBase, char role);
void deleteRequestFromDataBase(vector<Request>& ourRequestBase, int deletePosition);
void addRequestToDataBase(vector<Request>& ourRequestBase, Request ourRequest);