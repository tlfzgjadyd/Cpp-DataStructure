#include "E_Random.h"

int main(void) {
	E_Random r;
	cout << "-- 0����" << RAND_MAX << "������ ���� ���� 10 ��--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next(); //0���� RAND_MAX(32767)������ ������ ����
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2���� " << "4 ������ ���� ���� 10 �� --" << endl;
	for (int i = 0; i < 10; i++){
		int n = r.nextInRange(2, 4); //2���� 4 ������ ������ ����
		cout<<n <<' ';
	}
	cout << endl;
}