#include<iostream>
using namespace std;
int sum(int a, int b);

int main(void) {
	int n = 0;
	cout << "�� ���� �Է��ϼ���>>";
	cin >> n;
	cout << "1���� " << n << "������ ���� " << sum(1, n) << "�Դϴ�." << endl;
	return 0;
}

int sum(int a, int b) {
	int res = 0;
	for (int k = a; k <= b; k++)
		res += k;
	return res;
}