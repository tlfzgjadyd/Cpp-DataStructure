#include "H_CircleChange.h"

int main(void) {
	int num = 0;
	cout << "���� ���� >> ";
	cin >> num;
	H_CircleChange* circles = new H_CircleChange[num]; //�׳� �迭 ���鶧�� []���ο� ����� ���������� ���� �Ҵ��ϴ� �迭�� ��� �̷��� �����ϴ�
	int count = 0;
	for (int i = 0; i < num; i++) {
		cout << "�� " << i+1 << "�� ������ >> ";
		int r = 0;
		cin >> r;
		circles[i].setRadius(r);
		if (circles[i].getArea() > 100)
			count++;
	}
	cout << "������ 100���� ū ���� " << count << "�� �Դϴ�" << endl;
	
	
}