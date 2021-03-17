//������ �ð� ���� �ڵ�
#include <iostream>
#include <time.h>
#include <chrono> //c++11�� �߰��� ���̺귯���� �и���, ����ũ����, �����ʰ� ������
using namespace std;
typedef chrono::system_clock ch;

int main(void) {
	ch::time_point start, end;

	//1. 1000�п� 1 �и��ʷ� �����ϱ�
	start = ch::now();
	for (int i = 0; i < 5000; i++) {
		for (int j = 0; j < i; j++) {
			i* j;
		}
	}
	end = ch::now();
	cout << "�и��� ���� ��� : " << (chrono::duration_cast<chrono::milliseconds>(end - start)).count()<<endl;

	//2. ����ũ�� �ʷ� �����ϱ�
	start = ch::now();
	int sum = 0;
	for (int i = 0; i < 10000; i++) {
		sum += i;
	}
	end = ch::now();
	cout << "����ũ���� ���� ��� : " << (chrono::duration_cast<chrono::microseconds>(end - start)).count() << endl;

	//3. ���� �ʷ� �����ϱ�
	start = ch::now();
	for (int i = 0; i < 10000; i++) {
		i*i;
	}
	end = ch::now();
	cout << "������ ���� ��� : " << (chrono::duration_cast<chrono::nanoseconds>(end - start)).count() << endl;
}