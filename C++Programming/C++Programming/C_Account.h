#pragma once
#include <iostream>
#include <cstring>
using namespace std; //�� �� �ؾ������ �־��� string inlude �ߴµ��� ��� �����ߴ°� using namespace ��� �׷��ɼ��� ����
class C_Account
{
private:
	string name;
	int id;
	int money;
public:
	C_Account(string n, int i, int m) {
		name = n;
		id = i;
		money = m;
	}
	void deposit(int add) {
		money += add;
	}
	int withdraw(int minus) {
		if (money >= minus)
		{
			money -= minus;
			return minus;
		}
		else
		{
			money = 0;
			return money;
		}
	}
	string getOwner() {
		return name;
	}
	int inquiry() {
		return money;
	}
};

