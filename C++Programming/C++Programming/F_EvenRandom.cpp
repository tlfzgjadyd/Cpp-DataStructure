#include "F_EvenRandom.h"

//�ڹٿ����� new�� �����߰����� c++���� Ŭ������ ������(��������)�� ����
int main(void) {
	cout << "-- 0���� 32767������ ���� ���� 10�� --" << endl;
	F_EvenRandom er;
	for (int i = 0; i < 10; i++) {
		cout<<er.run(0, 32767)<<" ";
	}
	cout << endl<<endl;
	cout << "-- 2���� 10������ ���� ���� 10�� --" << endl;
	for (int i = 0; i < 10; i++) {
		cout << er.run(2, 10) << " ";
	}
	return 0;
}