#include "C_Account.h"

int main() {
	C_Account a("tlfzgjadyd", 1, 5000); //id 1��, �ܾ� 5000��, �̸��� tlfzgjadyd�� ���� ����
	a.deposit(50000);
	cout << a.getOwner() << "�� �ܾ��� " << a.inquiry() << endl;
	int money = a.withdraw(20000);
	cout << a.getOwner() << "�� �ܾ��� " << a.inquiry() << endl;
}