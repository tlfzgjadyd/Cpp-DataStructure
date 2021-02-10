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
			cout << "재료부족" << endl;
	}//커피1, 물1 소비
	void drinkAmericano() {
		if (coffee >= 1 && water >= 2)
		{
			coffee--;
			water -= 2;
		}
		else
			cout << "재료부족" << endl;
	}//커피1, 물2 소비
	void drinkSugarCoffee() {
		if (coffee >= 1 && water >= 2 && sugar>=1)
		{
			coffee--;
			water -= 2;
			sugar--;
		}
		else
			cout << "재료부족" << endl;
	}//커피1, 물2, 설탕1 소비
	void fill() {
		coffee = 10;
		water = 10;
		sugar = 10;
	}//커피10 물10 설탕10으로 채우기
	void show() {
		cout << "커피 머신 상태, 커피:" << coffee << "    물:" << water << "    설탕:" << sugar << endl;
	}//현재 커피머신 상태 출력

};

