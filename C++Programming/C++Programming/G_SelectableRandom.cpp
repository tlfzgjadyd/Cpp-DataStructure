#include "G_SelectableRandom.h"
//결론 : #include<random>이고 더이상 시드 설정할 필요 없어졌다 알아서 랜덤 내줌
int main(void) {
	cout << "-- 0에서 32767까지의 랜덤 짝수 정수 10개 --" << endl;
	G_SelectableRandom er;
	for (int i = 0; i < 10; i++) {
		cout << er.even(0, 32767) << " ";
	}
	cout << endl << endl;
	cout << "-- 2에서 9까지의 랜덤 홀수 정수 10개 --" << endl;
	for (int i = 0; i < 10; i++) {
		cout << er.odd(2, 9) << " ";
	}
	return 0;
}