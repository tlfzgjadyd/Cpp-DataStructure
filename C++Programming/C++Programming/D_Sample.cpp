#include "D_Sample.h"

int main(void) {
	D_Sample s(10); //10�� ���� �迭�� ���� Sample ��ü ����
	s.read(); //Ű���忡�� ���� �迭 �б�
	s.write(); //���� �迭 ���
	cout << "���� ū ���� " << s.big() << endl; //���� ū �� ���
}