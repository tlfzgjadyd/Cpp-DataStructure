#include "H_CircleChange.h"

int main(void) {
	int num = 0;
	cout << "원의 개수 >> ";
	cin >> num;
	H_CircleChange* circles = new H_CircleChange[num]; //그냥 배열 만들때는 []내부에 상수만 가능하지만 동적 할당하는 배열인 경우 이렇게 가능하다
	int count = 0;
	for (int i = 0; i < num; i++) {
		cout << "원 " << i+1 << "의 반지름 >> ";
		int r = 0;
		cin >> r;
		circles[i].setRadius(r);
		if (circles[i].getArea() > 100)
			count++;
	}
	cout << "면적이 100보다 큰 원은 " << count << "개 입니다" << endl;
	
	
}