#include <iostream>
using namespace std;
bool bigger(int a, int b, int& big);//big�� ������ ���� ȣ���� ����߱⿡
int main(void) {
	int num1 = 0;
	int num2 = 0;
	int big = 0;
	cout << "���� 2���� �Է��Ͻÿ� : ";
	cin >> num1 >> num2;
	bool res = bigger(num1, num2, big);//�Լ� ȣ��ÿ��� �Ϲݺ����� �ѱ��
	cout << "������ ���� : ";
	if (res == 0)
		cout << "false"<<endl;
	else
		cout << "true"<<endl;
	cout << "�� ū�� : "<<big<<endl;
}
bool bigger(int a, int b, int& big) {
	if (a == b) {
		big = a;					//������ ���� ȣ�� �Լ� �������� �Ϲݺ���ó�� ���������
		return true;				//������ �������� ������ ������ ���� �Ȼ���� �̸��� ����� ������ ����Ű�� �ȴ�
	}
	else if(a>b) {
		big = a;
		return false;
	}
	else {
		big = b;
		return false;
	}
}