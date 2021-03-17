//정밀한 시간 측정 코드
#include <iostream>
#include <time.h>
#include <chrono> //c++11에 추가된 라이브러리로 밀리초, 마이크로초, 나노초가 지원됨
using namespace std;
typedef chrono::system_clock ch;

int main(void) {
	ch::time_point start, end;

	//1. 1000분에 1 밀리초로 측정하기
	start = ch::now();
	for (int i = 0; i < 5000; i++) {
		for (int j = 0; j < i; j++) {
			i* j;
		}
	}
	end = ch::now();
	cout << "밀리초 연산 결과 : " << (chrono::duration_cast<chrono::milliseconds>(end - start)).count()<<endl;

	//2. 마이크로 초로 측정하기
	start = ch::now();
	int sum = 0;
	for (int i = 0; i < 10000; i++) {
		sum += i;
	}
	end = ch::now();
	cout << "마이크로초 연산 결과 : " << (chrono::duration_cast<chrono::microseconds>(end - start)).count() << endl;

	//3. 나노 초로 측정하기
	start = ch::now();
	for (int i = 0; i < 10000; i++) {
		i*i;
	}
	end = ch::now();
	cout << "나노초 연산 결과 : " << (chrono::duration_cast<chrono::nanoseconds>(end - start)).count() << endl;
}