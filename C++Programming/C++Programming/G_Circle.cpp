#include "G_Circle.h"

int main(void) {
	G_Circle circles[3];
	int count = 0;
	for (int i = 0; i < 3; i++) {
		cout << "원 " << i+1 << "의 반지름 >> ";
		int r = 0;
		cin >> r;
		circles[i].setRadius(r);
		if (circles[i].getArea() > 100)
			count++;
	}
	cout << "면적이 100보다 큰 원은 " << count << "개 입니다";
}