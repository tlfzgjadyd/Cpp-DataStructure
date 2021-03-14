#include <iostream>
using namespace std;

class Calculator {//가상함수가 들어있기에 이것은 추상 클래스가 된다
public:
	virtual int add(int a, int b) = 0; //cpp에서의 가상함수는 abstract 키워드 대신 virtual이란 키워드를 쓴다
	virtual int subtract(int a, int b) = 0; //또한 가상함수의 경우 함수 몸체 대신 =0을 사용해줘야 한다
	virtual double average(int a[], int size) = 0; //배열 a의 평균 리턴, size는 배열의 크기
};
class GoodCalc : public Calculator {
public:
	int add(int a, int b) { return a + b; } //그다음 자식에서 구현해주면 됨
	int subtract(int a, int b) { return a-b; }
	double average(int a[], int size) {
		double sum = 0;
		for (int i = 0; i < size; i++)
			sum += a[i];
		return sum / size;
	}
};
int main() {
	int a[] = { 1, 2, 3, 4, 5 };
	Calculator* p = new GoodCalc();
	cout << p->add(2, 3) << endl;//함수에 접근할때는 ->로 접근한다
	cout << p->subtract(2, 3) << endl;//평소에는 .으로 접근했잖아
	cout << p->average(a, 5) << endl;//가상함수를 구현한 함수이기 때문에 그런것같음
	delete p;
}