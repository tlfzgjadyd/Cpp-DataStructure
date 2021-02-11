#include "F_EvenRandom.h"

//자바였으면 new로 생성했겠지만 c++에선 클래스명 변수명(전달인자)로 생성
int main(void) {
	cout << "-- 0에서 32767까지의 랜덤 정수 10개 --" << endl;
	F_EvenRandom er;
	for (int i = 0; i < 10; i++) {
		cout<<er.run(0, 32767)<<" ";
	}
	cout << endl<<endl;
	cout << "-- 2에서 10까지의 랜덤 정수 10개 --" << endl;
	for (int i = 0; i < 10; i++) {
		cout << er.run(2, 10) << " ";
	}
	return 0;
}