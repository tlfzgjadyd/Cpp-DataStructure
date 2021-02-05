#include <iostream>
using namespace std;
int main (void) {
	int num1 = 0;
	int num2 = 0;
	int bigger = num1;
	cout << "두 수를 입력하라>>";
	cin >> num1 >> num2;
	if (num1 < num2)
		bigger = num2;
	cout << "큰 수 = " << bigger << endl;
	return 0;
}