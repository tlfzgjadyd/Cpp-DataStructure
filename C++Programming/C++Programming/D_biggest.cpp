#include <iostream>
using namespace std;
int main(void) {
	double num1 = 0;
	double num2 = 0;
	double num3 = 0;
	double num4 = 0;
	double num5 = 0;
	double biggest = 0;
	
	cout << "5 개의 실수를 입력하라>>";
	cin >> num1 >> num2 >> num3 >> num4 >> num5;
	biggest = num1;

	if (biggest < num2)
		biggest = num2;

	if (biggest < num3)
		biggest = num3;
	
	if (biggest < num4)
		biggest = num4;
	
	if (biggest < num5)
		biggest = num5;

	cout << "제일 큰 수 = " << biggest << endl;

	return 0;
}