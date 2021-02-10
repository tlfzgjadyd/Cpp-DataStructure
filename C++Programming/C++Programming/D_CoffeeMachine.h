#pragma once
#include<iostream>
using namespace std;

class D_CoffeeMachine
{
private:
	int coffee;
	int water;
	int sugar;
public:
	D_CoffeeMachine(int c, int w, int s) {
		coffee = c;
		water = w;
		sugar = s;
	}
	void drinkEspresso() {
		if (coffee >= 1 && water >= 1)
		{
			coffee--;
			water--;
		}
		else
			cout << "������" << endl;
	}//Ŀ��1, ��1 �Һ�
	void drinkAmericano() {
		if (coffee >= 1 && water >= 2)
		{
			coffee--;
			water -= 2;
		}
		else
			cout << "������" << endl;
	}//Ŀ��1, ��2 �Һ�
	void drinkSugarCoffee() {
		if (coffee >= 1 && water >= 2 && sugar>=1)
		{
			coffee--;
			water -= 2;
			sugar--;
		}
		else
			cout << "������" << endl;
	}//Ŀ��1, ��2, ����1 �Һ�
	void fill() {
		coffee = 10;
		water = 10;
		sugar = 10;
	}//Ŀ��10 ��10 ����10���� ä���
	void show() {
		cout << "Ŀ�� �ӽ� ����, Ŀ��:" << coffee << "    ��:" << water << "    ����:" << sugar << endl;
	}//���� Ŀ�Ǹӽ� ���� ���

};

