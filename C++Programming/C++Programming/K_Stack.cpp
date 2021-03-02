#include <iostream>
using namespace std;
class Stack {
private:
	int* content;
	int size;
public:
	Stack(){
		this->size = 0;
		this->content = new int[size];
	}
	Stack& operator <<(int num) {
		content[size] = num;
		size++;
		return *this; //�������� ������ �ʿ��ϹǷ� �ڱ��ڽ� ����
	}
	bool operator !() {//���׿����ڴ� ȣ���� �տ� ������ ȣ������ ȣ���ѰŴϱ� ������ �������� �ȹ޴°ſ���
		if (size == 0)
			return true;
		else
			return false;
	}
	Stack& operator >>(int& place) {//�������� ������ �ϴ� �������̱⿡ �ڱ� �ڽ��� ������� �ϴµ� ������ ���� ���� ������ �ϱ⿡ ������ ���� ȣ��� �� ������ �����ϵ��� �������
		place = content[size - 1];
		content[size - 1] = 0;
		size--;
		return *this;
	}
};
int main(void) {
	Stack stack;
	stack << 3 << 5 << 10; //3, 5, 10�� ������� Ǫ��
	while (true) {
		if (!stack) break; //���� empty
		int x;
		stack >> x; //������ ž�� �ִ� ���� ��
		cout << x << ' ';
	}
	cout << endl;
}