#include "L_Ram.h"

L_Ram::L_Ram() {
	size = 100 * 1024;
	for (int i = 0; i < size; i++) {
		mem[i] = 0;
	}
}
 L_Ram::~L_Ram() {
	cout << "메모리 제거됨" << endl;
}
char L_Ram::read(int address) {
	return mem[address];
}
void L_Ram::write(int address, char value) {
	mem[address] = value;
}