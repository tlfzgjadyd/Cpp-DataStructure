#include <iostream>
using namespace std;

//c++���� boolean ��� bool ���
//�����Ҷ� System.exit(0)���� exit(0)
int main(void) {
	cout << "***** �¸��忡 ���� ���� ȯ���մϴ�. *****" << endl;
	int select = 0;
	int num = 0;

	while (true) {
		cout << "«��:1, ¥��:2, ������:3, ����:4>>	";
		cin >> select;
		if (select < 1 || select>4)
		{
			cout << "�ٽ� �ֹ��ϼ���!!" << endl;
			continue;
		}
		else if (select == 4)
		{
			cout << "���� ������ �������ϴ�.";
			exit(0);
		}
		cout << "���κ�?";
		cin >> num;

		switch (select) {
		case 1: cout << "«�� " << num << "�κ� ���Խ��ϴ�" << endl; break;
		case 2: cout << "¥�� " << num << "�κ� ���Խ��ϴ�" << endl; break;
		case 3: cout << "������ " << num << "�κ� ���Խ��ϴ�" << endl; break;
		default: ;break;
		}	
	}
}