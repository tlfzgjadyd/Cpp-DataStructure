#include "A_Tower.h"

//���� �ۼ��� ������ A_Tower.h������
int main(void) {
	A_Tower myTower; //1����
	A_Tower seoulTower(100); //100����
	cout << "���̴� " << myTower.getHeight() << "����" << endl;
	cout << "���̴�" << seoulTower.getHeight() << "����"<< endl;
}