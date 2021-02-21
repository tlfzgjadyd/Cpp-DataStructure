#include <iostream>
using namespace std;
class MyVector {
private:
	int* mem;
	int size;
public:
	MyVector(int n = 100, int val = 0) {//디폴트값은 오른쪽만 있는건 허용됨 앞에서부터 전달받은값 채워넣기 때문
		mem = new int[n];
		size = n;
		for (int i = 0; i < size; i++)mem[i] = val;
	}
	~MyVector() { delete[] mem; }
};
int main(void) {
	MyVector();
	MyVector(1);
	MyVector(1, 1);
}