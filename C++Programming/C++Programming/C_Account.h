#pragma once
#include <iostream>
#include <cstring>
using namespace std; //아 또 잊어버리고 있었다 string inlude 했는데도 계속 에러뜨는건 using namespace 없어서 그런걸수도 있음
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

