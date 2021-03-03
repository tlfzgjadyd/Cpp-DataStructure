#include <iostream>
#include <algorithm>
using namespace std;
class SortedArray {
	int size;//���� �迭�� ũ��
	int* p; //���� �迭�� ���� ������
	void sort() {//������ �Լ��ε� private�� �� ������ main���� sort�� ����� �� ���� show�Ҷ��� ���������� ����ϴ� �Լ��̱� �����̴�
		int temp = 0;
		for (int i = size-1; i > 0; i--) {//i�� ������ �ִ� ���� ����Ű�� ���� �ϳ��� �پ����
			for (int j = 0; j < i; j++) {//�������� �񱳴� j�� j+1������ �̷������
				if (p[j] > p[j + 1])
				{
					temp = p[j];
					p[j] = p[j + 1];
					p[j + 1] = temp;
				}
			}
		}//������ ȿ�� ���� ������ ������ �߾��� �ٵ� �ڵ尡 �������ݾ� �׷��� ������������ ������ �迭�� ���� �Ѵ�
	}//���� �迭�� ������������ ����
public:
	SortedArray() {
		this->size = 0;
		p = NULL; //c++ ���� ���� ���� �빮�� 
	}//p�� NULL�� size�� 0���� �ʱ�ȭ
	SortedArray(SortedArray& src) {
		this->size = src.size;
		p = new int[size]; //���⼭ src.p�� �ּҸ� �����ϴ°� �ƴ϶� �迭 ���� ���빰�� ������ ���°ſ���, new Ű���� ������ ���� �Ҹ��ڿ��� delete�� �����Ҵ� ������ ���ְ�
		for (int i = 0; i < size; i++) {
			p[i] = src.p[i];
		}
	}//���� ������
	SortedArray(int p[], int size) {//�̹��� ��������ڰ� �ƴ϶� �迭�� ����� ���� �����ؼ� �ʱ�ȭ�ߴµ� �̷� ��쿡�� ���������� 1. �����Ҵ���� �ؼ� ���� �����ϰ� 2. ���빰 �����ؾߵ�
		this->size = size;
		this->p = new int[size];
		for (int i = 0; i < size; i++) {
			this->p[i] = p[i];
		}
	}//������, ���� �迭�� ũ�⸦ ���޹���
	~SortedArray() {
		delete[] p; //�迭�� ���� �����Ҵ� ������ �׳� delete�� �ƴ϶� delete[]����
		size = 0;
	}//�Ҹ���
	SortedArray operator + (SortedArray& op2) {//�迭 ��ó�� ���� �Ҵ��Ҷ� �̹� ũ�� ���س��� ������ �����ͼ� �ű⿡ �̾ �����ϴ°� �Ұ����ϴ� �ֳĸ� �����̿� �ް����� �ڸ� �ο��������� �ֱ� ����
		int size2 = this->size+op2.size;//�׷��Ƿ� �� �迭�� ��ģ ũ�⸸ŭ��
		int* p2 = new int[size2];//���ο� ������ �Ҵ�������Ѵ�, �ٷ� this�� �ȳְ� �� ������ �Ҵ��ϴ� ������ �Ʒ����� for�� ���� �����迭 ������ �������� ���� ������ �����־�� �ϱ� ����
		for (int i = 0; i < this->size; i++) {//ȿ���������� �� for�� �ȿ��� �� �迭 ���� �߰��Ϸ� �ߴµ� ����� �迭 ���̰� �� Ŭ�� �𸣴ϱ� �ڵ尡 ���� ���������� �׳� for�� 2�� ������
			p2[i] = this->p[i];
		}
		for (int i = 0; i < op2.size; i++) {
			p2[this->size + i] = op2.p[i];
		}
		SortedArray newArray (p2, size2);//�����Ҷ� �������°� �ƴ� �Ϲ� SortedArray�� �������� ������� ������ this���� ���ϰ� ���� ���� �����Ѵ�, *this���� �׳� this ���ϵ� �ȵ���
		return newArray;//�̶� return�ڸ��� �ٷ� �͸�ü �ߴ��� ��������
	}//���� �迭�� op2 �迭 �߰�
	SortedArray& operator = (const SortedArray& op2) {
		this->size = op2.size;
		this->p = new int[size];
		for (int i = 0; i < size; i++) {
			this->p[i] = op2.p[i];
		}
		return *this;
	}//���� �迭�� op2 �迭 ����
	void show() {
		sort();
		cout << "�迭 ��� : ";
		for (int i = 0; i < size; i++) {
			cout << p[i] << " ";
		}
		cout << endl;
	}//�迭�� ���� ���
};
int main(void) {
	int n[] = { 2, 20, 6 };
	int m[] = { 10, 7, 8, 30 };
	SortedArray a(n, 3), b(m, 4), c;
	c = a + b; // +, = ������ �ۼ� �ʿ�, ���⼭ �ɷ��� �۵��� �ȵƾ���
	//+�����ڰ� SortedArray ��ü�� �����ϹǷ� ���� ������ �ʿ�
	
	a.show();
	b.show();
	c.show();
}