#include <iostream>
using namespace std;

//���� �������� �Է¹޴� ����� ���ߴµ�
//å������ ��Ʈ�� ���� �а� ���� ��ū �и� �� atoi�� ���ڿ�->���ڷ� �ٲٴ� ����� ���Ѵ�
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