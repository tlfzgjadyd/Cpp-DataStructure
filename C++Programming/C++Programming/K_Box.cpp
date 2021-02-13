#include "K_Box.h"

void K_Box::draw() {
	for (int n = 0; n < height; n++) {
		for (int m = 0; m < width; m++)
			cout << fill;
		cout << endl;
	}
}//박스 그리기