#include <iostream>
using namespace std;

//나는 연속으로 입력받는 방식을 택했는데
//책에서는 힌트로 한줄 읽고 나서 토큰 분리 후 atoi로 문자열->숫자로 바꾸는 방식을 택한다
int main(void) {
	int num1 = 0;
	char type;
	int num2 = 0;
	int res = 0;

	while (true) {
		cout << "? ";
		cin >> num1;
		cin >> type;
		cin >> num2;

		switch (type) {
		case '+': res = num1 + num2; break;
		case '-': res = num1 - num2; break;
		case '*': res = num1 * num2; break;
		case '/': res = num1 / num2; break;
		case '%': res = num1 % num2; break;
		default:; break;
		}

		cout << num1 << " " << type << " " << num2 << " = " << res << endl;
	}
	return 0;
}