#include <iostream>
using namespace std;
int main (void) {
	int num1 = 0;
	int num2 = 0;
	int bigger = num1;
	cout << "�� ���� �Է��϶�>>";
	cin >> num1 >> num2;
	if (num1 < num2)
		bigger = num2;
	cout << "ū �� = " << bigger << endl;
	return 0;
}