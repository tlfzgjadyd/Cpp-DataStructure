#include <iostream>
using namespace std;
class BaseMemory {
private:
	int size;
	char* mem;
protected:
	BaseMemory(int size) { 
		this->size = size;
		mem = new char[size]; 
	}
	char* getMem() {
		return mem;
	}
public:
	char read(int i) { return mem[i]; }
};
class ROM :public BaseMemory{
public:
	ROM(int size, char x[], int num):BaseMemory(size){
		for (int i = 0; i < num; i++) {
			getMem()[i] = x[i];
		}
	}
};
class RAM : public BaseMemory{
public:
	RAM(int size) :BaseMemory(size) {
	}
	void write(int i, char content) {
		getMem()[i] = content;
	}
};
int main(void) {
	char x[5]{ 'h', 'e', 'l', 'l', 'o' };
	ROM biosROM(1024*10, x, 5); //10KB�� ROM �޸�, �迭 x�� �ʱ�ȭ��
	RAM mainMemory(1024*1024); //1MB�� RAM �޸�

	//0�������� 4�������� biosROM���� �о� mainMemory�� ����
	for (int i = 0; i < 5; i++) mainMemory.write(i, biosROM.read(i));
	for (int i = 0; i < 5; i++) cout << mainMemory.read(i);
}