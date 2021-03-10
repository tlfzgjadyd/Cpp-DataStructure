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
	ROM biosROM(1024*10, x, 5); //10KB의 ROM 메모리, 배열 x로 초기화됨
	RAM mainMemory(1024*1024); //1MB의 RAM 메모리

	//0번지에서 4번지까지 biosROM에서 읽어 mainMemory에 복사
	for (int i = 0; i < 5; i++) mainMemory.write(i, biosROM.read(i));
	for (int i = 0; i < 5; i++) cout << mainMemory.read(i);
}