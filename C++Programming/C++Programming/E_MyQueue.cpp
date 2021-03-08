#include <iostream>
using namespace std;
class BaseArray {
private:
	int capacity; //배열의 크기, 이때 나는 현재 개수인줄 알았더니 최대개수더라 현재개수는 length라고 따로있음
	int* mem; //정수배열을 만들기 위한 메모리의 포인터
protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity; mem = new int[capacity];
	}
	~BaseArray() { delete[] mem; }
	void put(int index, int val) { mem[index] = val; } //
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};
class MyQueue :public BaseArray {
private:
	int len;
public:
	MyQueue(int capacity) :BaseArray(capacity) {
		this->len = 0;
	}
	void enqueue(int insert) {
		put(len, insert);
		cout << "enqueue완료 : "<<get(len)<<endl;
		len++;
	}
	int capacity() {
		int capacity = getCapacity();
		return capacity; //이전에도 그러더니 c++은 리턴자리에 함수 쓰는게 안되더라
	}
	int length() { 
		return len;
	}
	int dequeue() {
		int num = get(0);
		for (int i = 0; i < len - 1; i++) {
			put(i, get(i + 1));
		}
		put(len - 1, 0);
		len--;
		return num;
	}
};

int main(void) {
	MyQueue mQ(100);
	int n;
	cout << "큐에 삽입할 5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n); //큐에 삽입
	}
	cout << "큐의 용량:" << mQ.capacity() << ", 큐의 크기:" << mQ.length() << endl;
	cout << "큐의 원소를 순서대로 제거하여 출력한다>> ";
	while (mQ.length() != 0) {//여기에서 에러났었는데 이유는 변수명이랑 함수명이 똑같애서였음 len으로 변수명 바꿔주니까 해결됨
		cout << mQ.dequeue() << ' ';//큐에서 제거하여 출력
	}
	cout << endl << "큐의 현재크기 : " << mQ.length() << endl;
}