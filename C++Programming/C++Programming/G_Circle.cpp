#include "G_Circle.h"

int main(void) {
	G_Circle circles[3];
	int count = 0;
	for (int i = 0; i < 3; i++) {
		cout << "�� " << i+1 << "�� ������ >> ";
		int r = 0;
		cin >> r;
		circles[i].setRadius(r);
		if (circles[i].getArea() > 100)
			count++;
	}
	cout << "������ 100���� ū ���� " << count << "�� �Դϴ�";
}