#pragma once
#include <iostream>
#include<cstring>//strtok ����ֱ��ѵ� char * p=strtok(date, (const char*)'/');�̷��� ���°ű� �ѵ�
#include<string> //���� stoi ������� string to integer
#pragma warning (disable : 4996)
using namespace std;

class B_Date
{
private:
	int year;
	int month;
	int day;

public:
	B_Date() {
		year = 1111;
		month = 1;
		day = 1;
	}
	B_Date(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}
	B_Date(string date) {
		year = stoi(date.substr(0, 4));
		if (date[7] == '/')
		{
			month = stoi(date.substr(5, 6));
			day = stoi(date.substr(6, date.length()-1));
		}
		else
		{
			month = stoi(date.substr(5, 7));
			day = stoi(date.substr(7, date.length()-1));
		}
	}
	int getYear() {
		return year;
	}
	int getMonth() {
		return month;
	}
	int getDay() {
		return day;
	}

	void show() {
		cout << year << "��" << month << "��" << day << "��" << endl;
	}
};

