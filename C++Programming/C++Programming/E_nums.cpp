#include <iostream>
#include <string>
using namespace std;

//getline�� ���ڿ� �Է¹����� ���µ� ��� ���°ųĸ� cin.getline(�����Һ�����, ���幮�ڰ���)
//�׸��� c++������ string�� �빮�� �ƴ�
int main(void) {
	int count = 0;
	char str[100];
	cout << "���ڵ��� �Է��϶�(100�� �̸�)." << endl;
	cin.getline(str, 99);
	for (int i = 0; i < 100; i++)
	{
		if (str[i] == 'x')
			count++;
	}
	cout << "x�� ������ " << count << endl;
	return 0;
}