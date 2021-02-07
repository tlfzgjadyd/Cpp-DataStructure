#include<iostream>
using namespace std;
int main(void) {
	string names[3] = { "에스프레소", "아메리카노", "카푸치노" };
	int prices[3] = { 2000, 2300, 2500 };

	string name = "";
	int priceNow = 0;
	int num = 0;
	int sum = 0;
	cout << "에스프레소 2000원, 아메리카노 2300원, 카푸치노 2500원입니다."<<endl;
	while (true) {
		cout << "주문>>";
		cin >> name;
		cin >> num;
		for (int i = 0; i < 3; i++)
		{
			if (names[i] == name)
			{
				priceNow = num * prices[i];
				sum += priceNow;
				cout << priceNow << "원입니다. 맛있게 드세요"<<endl;
				break;
			}
		}
		if (sum >= 20000)
		{
			cout << "오늘 " << sum << "원을 판매하여 카페를 닫습니다. 내일 봐요~~~" << endl;
			break;
		}
	}


	return 0;
}