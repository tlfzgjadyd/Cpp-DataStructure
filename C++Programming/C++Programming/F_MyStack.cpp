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
			cout << "������ ��á���ϴ�" << endl;
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
	cout << "���ÿ� ������ 5���� ������ �Է��϶�>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mStack.push(n); //���ÿ� Ǫ��
	}
	cout << "���ÿ뷮:" << mStack.capacity()<< ", ����ũ��:" << mStack.length() << endl;
	cout << "������ ��� ���Ҹ� ���Ͽ� ����Ѵ�>> ";
	while (mStack.length() != 0) {
		cout << mStack.pop() << ' '; //���ÿ��� ��
	}
	cout << endl << "������ ���� ũ�� : " << mStack.length() << endl;
}