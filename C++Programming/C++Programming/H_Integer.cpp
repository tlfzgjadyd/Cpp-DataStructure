#include "H_Integer.h"

int main(void) {
	H_Integer n(30);
	cout << n.get() << ' '; //30 ���
	n.set(50);
	cout << n.get() << ' ';

	H_Integer m("300");
	cout << m.get() << ' ';  //300���
		cout << m.isEven(); //true(���� 1) ���
	return 0;
}