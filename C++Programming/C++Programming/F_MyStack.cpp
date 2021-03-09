#include <iostream>
using namespace std;
class MyStack {
private:
	int* p;
	int size;
	int current;
public:
	MyStack(int size) {
		this->size = size;
		p = new int[size];
		current = 0;
	}
	void push(int num) {
		if (current < size)
		{
			p[current] = num;
			current++;
		}
		else
		{
			cout << "스택이 꽉찼습니다" << endl;
		}
	}
	int capacity() {
		return size;
	}
	int length() {
		return current;
	}
	int pop() {
		int temp = p[current - 1];
		p[current - 1] = 0;
		current--;
		return temp;
	}
};
int main(void) {
	MyStack mStack(100);
	int n;
	cout << "스택에 삽입할 5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mStack.push(n); //스택에 푸시
	}
	cout << "스택용량:" << mStack.capacity()<< ", 스택크기:" << mStack.length() << endl;
	cout << "스택의 모든 원소를 팝하여 출력한다>> ";
	while (mStack.length() != 0) {
		cout << mStack.pop() << ' '; //스택에서 팝
	}
	cout << endl << "스택의 현재 크기 : " << mStack.length() << endl;
}