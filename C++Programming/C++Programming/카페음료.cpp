//알바를 하기 위해 외워야하는 메뉴 문제 제조기
#include <iostream>
#include <random>
#define MAX_MENU_NUM 7
using namespace std;
int main(void) {
	string menu[MAX_MENU_NUM] = {"리얼초코프라페", "녹차프라페", "커피 바나나 프라페", "커피 프라페", "퐁 크러쉬", "딸기 퐁 크러쉬", "바나나 퐁 크러쉬"};
	string answer[MAX_MENU_NUM] = { "리얼초코프라페", "녹차프라페", "커피 바나나 프라페", "커피 프라페", "퐁 크러쉬", "딸기 퐁 크러쉬", "바나나 퐁 크러쉬" };
	random_device r;
	mt19937 gen(r());
	uniform_int_distribution<int> dis(0, 6);
	int num = 0;
	while (true) {
		num = dis(gen);
		cout << menu[num] << "을(를) 제조하시오" << endl;
		getchar();
		cout << "======================================" << endl;
		cout << answer[num] << endl;
		cout << "======================================" << endl<<endl<<endl;
		getchar();
	}
	return 0;
}