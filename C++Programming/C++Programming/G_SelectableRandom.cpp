#include "G_SelectableRandom.h"
//��� : #include<random>�̰� ���̻� �õ� ������ �ʿ� �������� �˾Ƽ� ���� ����
int main(void) {
	cout << "-- 0���� 32767������ ���� ¦�� ���� 10�� --" << endl;
	G_SelectableRandom er;
	for (int i = 0; i < 10; i++) {
		cout << er.even(0, 32767) << " ";
	}
	cout << endl << endl;
	cout << "-- 2���� 9������ ���� Ȧ�� ���� 10�� --" << endl;
	for (int i = 0; i < 10; i++) {
		cout << er.odd(2, 9) << " ";
	}
	return 0;
}