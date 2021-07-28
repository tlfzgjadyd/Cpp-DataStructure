//알바를 하기 위해 외워야하는 메뉴 문제 제조기
#include <iostream>
#include <random>
#define MAX_MENU_NUM 7
#define MAX_DAY_NUM 3
using namespace std;
bool isDayPractice(int select);
bool isQuit(int select);
void doDayPractice(int day, string* menu, string* answer, int* start, int* end);
int main(void) {
	string menu[MAX_MENU_NUM] = {"리얼초코프라페", "녹차프라페", "커피 바나나 프라페", "커피 프라페", "퐁 크러쉬", "딸기 퐁 크러쉬", "바나나 퐁 크러쉬"};
	string answer[MAX_MENU_NUM] = { "리얼초코프라페", "녹차프라페", "커피 바나나 프라페", "커피 프라페", "퐁 크러쉬", "딸기 퐁 크러쉬", "바나나 퐁 크러쉬" };
	int start[MAX_DAY_NUM] = {1, 3, 5};
	int end[MAX_DAY_NUM] = {2, 4, 6};
	random_device r;
	mt19937 gen(r());
	uniform_int_distribution<int> dis(0, 6);
	int num = 0;
	char select =' ';
	while (true) {
		num = dis(gen);
		cout << menu[num] << "을(를) 제조하시오" << endl;
		int select = (int)getchar();
		if (!isDayPractice(select))
		{
			cout << "======================================" << endl;
			cout << answer[num] << endl;
			cout << "======================================" << endl << endl << endl;
		}
		else
			doDayPractice(select-48, menu, answer, start, end);

	}
	return 0;
}
bool isDayPractice(int select)
{
	if (select == 10)
		return false;
	else
		return true;
}
bool isQuit(int select)
{
	if (select != 113)
		return false;
	else
		return true;
}
void doDayPractice(int day, string* menu, string* answer, int* start, int* end) {
	cout <<"<<<<< "<< day << "일차 학습을 시작합니다" <<" >>>>>"<<endl<<endl;
	for(int i=start[day];i<end[day]+1;i++)
	{
		cout <<i-start[day]+1<<". "<< menu[i] << "을(를) 제조하시오" << endl;
		if (isQuit(getchar()))
			break;
		cout << "======================================" << endl;
		cout << answer[i] << endl;
		cout << "======================================" << endl << endl;
		if (isQuit(getchar()))
			break;
	}
	cout <<"<<<<< "<< day <<"일차 학습이 끝났습니다" <<" >>>>>"<< endl << endl << endl;
	return;
}