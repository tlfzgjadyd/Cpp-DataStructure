#include <iostream>
using namespace std;

class Calculator {//�����Լ��� ����ֱ⿡ �̰��� �߻� Ŭ������ �ȴ�
public:
	virtual int add(int a, int b) = 0; //cpp������ �����Լ��� abstract Ű���� ��� virtual�̶� Ű���带 ����
	virtual int subtract(int a, int b) = 0; //���� �����Լ��� ��� �Լ� ��ü ��� =0�� �������� �Ѵ�
	virtual double average(int a[], int size) = 0; //�迭 a�� ��� ����, size�� �迭�� ũ��
};
class GoodCalc : public Calculator {
public:
	int add(int a, int b) { return a + b; } //�״��� �ڽĿ��� �������ָ� ��
	int subtract(int a, int b) { return a-b; }
	double average(int a[], int size) {
		double sum = 0;
		for (int i = 0; i < size; i++)
			sum += a[i];
		return sum / size;
	}
};
int main() {
	int a[] = { 1, 2, 3, 4, 5 };
	Calculator* p = new GoodCalc();
	cout << p->add(2, 3) << endl;//�Լ��� �����Ҷ��� ->�� �����Ѵ�
	cout << p->subtract(2, 3) << endl;//��ҿ��� .���� �������ݾ�
	cout << p->average(a, 5) << endl;//�����Լ��� ������ �Լ��̱� ������ �׷��Ͱ���
	delete p;
}