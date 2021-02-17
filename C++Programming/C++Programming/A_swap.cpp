#include <iostream>
using namespace std;
//참조에 의한 호출을 할 경우 전달인자로 넘기는 변수들에 대한 공간이 따로 생기지 않고
//전달인자에 쓴 이름만 생긴 다음 원본 공간을 가리키게 된다
void swap(int& num1, int& num2);//원래였다면 &주소로 보내고 *포인터로 받았겠지만 참조에 의한 호출을 하려면 전달인자 부분에 &여야됨
int main(void) {
	int num1 = 1;
	int num2 = 2;
	swap(num1, num2);//참조에 의한 호출 함수를 호출할때는 일반 변수처럼 호출하면 된다
	cout << num1 << " " << num2;
}
void swap(int& num1, int& num2) {
	int temp = num1; //참조에 의한 호출 함수 내부에서 그 변수를 사용할때는 일반 변수처럼 사용하면 된다
	num1 = num2;
	num2 = temp;
}