#include<iostream>
using namespace std;
int main(void) {
	string names[3] = { "����������", "�Ƹ޸�ī��", "īǪġ��" };
	int prices[3] = { 2000, 2300, 2500 };

	string name = "";
	int priceNow = 0;
	int num = 0;
	int sum = 0;
	cout << "���������� 2000��, �Ƹ޸�ī�� 2300��, īǪġ�� 2500���Դϴ�."<<endl;
	while (true) {
		cout << "�ֹ�>>";
		cin >> name;
		cin >> num;
		for (int i = 0; i < 3; i++)
		{
			if (names[i] == name)
			{
				priceNow = num * prices[i];
				sum += priceNow;
				cout << priceNow << "���Դϴ�. ���ְ� �弼��"<<endl;
				break;
			}
		}
		if (sum >= 20000)
		{
			cout << "���� " << sum << "���� �Ǹ��Ͽ� ī�並 �ݽ��ϴ�. ���� ����~~~" << endl;
			break;
		}
	}


	return 0;
}