#include <iostream>
using namespace std;
class MyIntStack {
private:
	int* p; //���� �޸𸮷� ����� ������
	int size; //������ �ִ� ũ��
	int tos; //������ ž�� ����Ű�� �ε���
public:
	MyIntStack() {
		p = new int[1];
		size = 0;
		tos = 0;
	}
	MyIntStack(int size) {
		this->p = new int[size];
		this->size = size;
		this->tos = 0;
	}
	MyIntStack(const MyIntStack& s) {
		this->size = s.size;
		this->p = new int[size]; //��������ڿ��� ��� ���������µ� �˰��� this->p = s.p;�� �ƴ϶� �Ȱ��� ���� ���� ���� ���빰�� �����ؾ��ϴ°ſ���
		for (int i = 0; i < size; i++) {//�׷��� new�� ���� ���� �� for�� ���� ���� ������� �Ϸ��ؾ� �Ѵ�
			p[i] = s.p[i];
		}
		this->tos = s.tos;
	}//���������
	~MyIntStack() {
		delete[] p;
		size = 0;
		tos = 0;
	}
	bool push(int n) {
		if (tos == size)
		{
			return false;
		}
		else
		{
			p[tos] = n;
			tos++;
			return true;
		}
	}//���� n�� ���ÿ� Ǫ���Ѵ�
	//������ �� �� ������ false��, �ƴϸ� true ����
	bool pop(int& n) {
		if (tos == 0)
		{
			return false;
		}
		else
		{
			n = p[tos - 1];
			tos--;
			return true;
		}
	}//������ ž�� �ִ� ���� n�� ���Ѵ�
	//���� ������ ��������� false��, �ƴϸ� true ����
};
int main(void) {
	MyIntStack a(10);
	a.push(10);
	a.push(20);
	MyIntStack b = a; //���� ����
	b.push(30);

	int n;
	a.pop(n); //���� a ��
	cout << "���� a���� ���� �� " << n << endl;
	b.pop(n);//���� b ��
	cout << "���� b���� ���� �� " << n << endl;
}