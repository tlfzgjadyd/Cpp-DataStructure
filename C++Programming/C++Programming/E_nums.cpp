#include <iostream>
#include <string>
using namespace std;

//getline�� ���ڿ� �Է¹����� ���µ� ��� ���°ųĸ� cin.getline(�����Һ�����, ���幮�ڰ���)
//�ٵ� �̷��� char �迭�� str �����ߵ�
//�׷��� string���� ����ϱ� ���ؼ� getline(cin, ������) �̷��� ����Ѵ�
//�׸��� c++������ string�� �빮�� �ƴ�
int main(void) {
	int count = 0;
	string str;
	cout << "���ڵ��� �Է��϶�(100�� �̸�)." << endl;
	getline(cin, str);
	for (int i = 0; i < 100; i++)
	{
		if (str[i] == 'x')
			count++;
	}
	cout << "x�� ������ " << count << endl;
	return 0;
}