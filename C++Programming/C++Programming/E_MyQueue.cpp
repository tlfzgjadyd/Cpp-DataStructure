#include <iostream>
using namespace std;
class BaseArray {
private:
	int capacity; //�迭�� ũ��, �̶� ���� ���� �������� �˾Ҵ��� �ִ밳������ ���簳���� length��� ��������
	int* mem; //�����迭�� ����� ���� �޸��� ������
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
		cout << "enqueue�Ϸ� : "<<get(len)<<endl;
		len++;
	}
	int capacity() {
		int capacity = getCapacity();
		return capacity; //�������� �׷����� c++�� �����ڸ��� �Լ� ���°� �ȵǴ���
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
	cout << "ť�� ������ 5���� ������ �Է��϶�>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n); //ť�� ����
	}
	cout << "ť�� �뷮:" << mQ.capacity() << ", ť�� ũ��:" << mQ.length() << endl;
	cout << "ť�� ���Ҹ� ������� �����Ͽ� ����Ѵ�>> ";
	while (mQ.length() != 0) {//���⿡�� ���������µ� ������ �������̶� �Լ����� �Ȱ��ּ����� len���� ������ �ٲ��ִϱ� �ذ��
		cout << mQ.dequeue() << ' ';//ť���� �����Ͽ� ���
	}
	cout << endl << "ť�� ����ũ�� : " << mQ.length() << endl;
}