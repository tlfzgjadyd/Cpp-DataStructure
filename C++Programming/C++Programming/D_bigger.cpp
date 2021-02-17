#include <iostream>
using namespace std;
bool bigger(int a, int b, int& big);//big에 참조에 의한 호출을 사용했기에
int main(void) {
	int num1 = 0;
	int num2 = 0;
	int big = 0;
	cout << "정수 2개를 입력하시오 : ";
	cin >> num1 >> num2;
	bool res = bigger(num1, num2, big);//함수 호출시에는 일반변수로 넘기고
	cout << "같은지 여부 : ";
	if (res == 0)
		cout << "false"<<endl;
	else
		cout << "true"<<endl;
	cout << "더 큰쪽 : "<<big<<endl;
}
bool bigger(int a, int b, int& big) {
	if (a == b) {
		big = a;					//참조에 의한 호출 함수 내에서도 일반변수처럼 사용하지만
		return true;				//실제론 전달인자 받을때 공간이 따로 안생기고 이름만 생기고 원본을 가리키게 된다
	}
	else if(a>b) {
		big = a;
		return false;
	}
	else {
		big = b;
		return false;
	}
}