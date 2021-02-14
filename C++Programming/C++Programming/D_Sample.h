#pragma once
#include <iostream>
using namespace std;

class D_Sample
{
private:
	int* p;
	int size;
public:
	D_Sample(int n) { size = n; p = new int[n]; }//n�� ���� �迭�� ���� ����, ������ ����س���
	void read() {
		for(int i=0;i<size;i++)
			cin >> p[i];
	} //���� �Ҵ���� ���� �迭 p�� ����ڷκ��� ������ �Է� ����
	void write() {
		for (int i = 0; i < size; i++)
			cout << p[i] << " ";
		cout << endl;
	}//���� �迭 ȭ�鿡 ���
	int big() {
		int biggest = p[0];
		for (int i = 1; i < size; i++) {
			if (biggest < p[i])
				biggest = p[i];
		}
		return biggest;
	}//���� �迭���� ���� ū�� ����
	~D_Sample() {
		delete[] p;
	} //�Ҹ���
};

