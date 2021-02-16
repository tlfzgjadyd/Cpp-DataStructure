#include <iostream>
#include <string>
using namespace std;
class Container {
private:
	int size;
public:
	Container() { size = 10; }
	void fill() {
		size = 10;
	}
	void consume() {
		if(size>=1)
			size--;
		else {
			cout << "원료가 부족합니다." << endl;
		}
	}
	void consume(int amount) {
		if (amount <= size)
			size -= amount;
		else
			cout << "원료가 부족합니다." << endl;
	}
	int getSize() {
		return size;
	}
};
class CoffeeVendingMachine {
private:
	Container tong[3];
	void fill() {
		for (int i = 0; i < 3; i++) {
			tong[i].fill();
		}
		show();
	}
	void selectEspresso() {
		tong[0].consume();
		tong[1].consume();
		cout << "에스프레소 드세요 " << endl;
	}
	void selectAmericano() {
		tong[0].consume();
		tong[1].consume(2);
		cout << "아메리카노 드세요 " << endl;
	}
	void selectSugarCoffee() {
		tong[0].consume();
		tong[1].consume(2);
		tong[2].consume();
		cout << "설탕커피 드세요 " << endl;
	}
	void show() {
		cout << "커피 " << tong[0].getSize() << ", 물 " << tong[1].getSize() << ", 설탕 " << tong[2].getSize()<<endl;
	}
public:
	void run() {
		cout << "***** 커피자판기를 작동합니다. *****" << endl;
		int select = 0;
		while (true) {
			cout << "메뉴를 눌러주세요(1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기, 5:채우기)>> ";
			cin >> select;
			switch (select) {
			case 1: selectEspresso();  break;
			case 2: selectAmericano(); break;
			case 3: selectSugarCoffee();  break;
			case 4: show(); break;
			case 5: fill(); break;
			default:; break;
			}
		}
	}
};//클래스 선언 끝에는 ; 필요했었지

int main(void) {
	CoffeeVendingMachine cm;
	cm.run();
	return 0;
}