#include "K_Box.h"

int main(void) {
	K_Box b(10, 2);
	b.draw(); //박스를 그린다
	cout << endl;
	b.setSize(7, 4); //박스 크기를 변경한다
	b.setFill('^'); //박스의 내부를 채울 문자를 '^'로 변경한다
	b.draw(); //박스를 그린다
}