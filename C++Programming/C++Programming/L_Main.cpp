#include "L_Ram.h"

int main(void) {
	L_Ram ram;
	ram.write(100, 20); //100������ 20 ����
	ram.write(101, 30); //101������ 30 ����
	char res = ram.read(100) + ram.read(101); //20 + 30 = 50
	ram.write(102, res); //102������ 50 ����
	cout << "102������ �� = " << (int)ram.read(102) << endl; //102���� �� ���
}