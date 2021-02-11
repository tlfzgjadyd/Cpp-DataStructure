#include "I_Oval.h"

int main(void) {
	I_Oval a, b(3, 4);
	a.set(10, 20);
	a.show();
	cout << b.getWidth() << "," << b.getHeight() << endl;
	return 0;
}