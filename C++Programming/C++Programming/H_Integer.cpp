#include "H_Integer.h"

int main(void) {
	H_Integer n(30);
	cout << n.get() << ' '; //30 출력
	n.set(50);
	cout << n.get() << ' ';

	H_Integer m("300");
	cout << m.get() << ' ';  //300출력
		cout << m.isEven(); //true(정수 1) 출력
	return 0;
}