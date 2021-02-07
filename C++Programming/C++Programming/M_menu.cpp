#include <iostream>
using namespace std;

//c++에선 boolean 대신 bool 사용
//종료할땐 System.exit(0)말고 exit(0)
int main(void) {
	cout << "***** 승리장에 오신 것을 환영합니다. *****" << endl;
	int select = 0;
	int num = 0;

	while (true) {
		cout << "짬뽕:1, 짜장:2, 군만두:3, 종료:4>>	";
		cin >> select;
		if (select < 1 || select>4)
		{
			cout << "다시 주문하세요!!" << endl;
			continue;
		}
		else if (select == 4)
		{
			cout << "오늘 영업은 끝났습니다.";
			exit(0);
		}
		cout << "몇인분?";
		cin >> num;

		switch (select) {
		case 1: cout << "짬뽕 " << num << "인분 나왔습니다" << endl; break;
		case 2: cout << "짜장 " << num << "인분 나왔습니다" << endl; break;
		case 3: cout << "군만두 " << num << "인분 나왔습니다" << endl; break;
		default: ;break;
		}	
	}
}