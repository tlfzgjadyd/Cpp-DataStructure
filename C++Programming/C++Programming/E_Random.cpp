#include "E_Random.h"

int main(void) {
	E_Random r;
	cout << "-- 0에서" << RAND_MAX << "까지의 랜덤 정수 10 개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next(); //0에서 RAND_MAX(32767)사이의 랜덤한 정수
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2에서 " << "4 까지의 랜덤 정수 10 개 --" << endl;
	for (int i = 0; i < 10; i++){
		int n = r.nextInRange(2, 4); //2에서 4 사이의 랜덤한 정수
		cout<<n <<' ';
	}
	cout << endl;
}