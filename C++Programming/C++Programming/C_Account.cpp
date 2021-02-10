#include "C_Account.h"

int main() {
	C_Account a("tlfzgjadyd", 1, 5000); //id 1번, 잔액 5000원, 이름이 tlfzgjadyd인 계좌 생성
	a.deposit(50000);
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
	int money = a.withdraw(20000);
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
}