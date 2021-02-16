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
			cout << "���ᰡ �����մϴ�." << endl;
		}
	}
	void consume(int amount) {
		if (amount <= size)
			size -= amount;
		else
			cout << "���ᰡ �����մϴ�." << endl;
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
		cout << "���������� �弼�� " << endl;
	}
	void selectAmericano() {
		tong[0].consume();
		tong[1].consume(2);
		cout << "�Ƹ޸�ī�� �弼�� " << endl;
	}
	void selectSugarCoffee() {
		tong[0].consume();
		tong[1].consume(2);
		tong[2].consume();
		cout << "����Ŀ�� �弼�� " << endl;
	}
	void show() {
		cout << "Ŀ�� " << tong[0].getSize() << ", �� " << tong[1].getSize() << ", ���� " << tong[2].getSize()<<endl;
	}
public:
	void run() {
		cout << "***** Ŀ�����Ǳ⸦ �۵��մϴ�. *****" << endl;
		int select = 0;
		while (true) {
			cout << "�޴��� �����ּ���(1:����������, 2:�Ƹ޸�ī��, 3:����Ŀ��, 4:�ܷ�����, 5:ä���)>> ";
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
};//Ŭ���� ���� ������ ; �ʿ��߾���

int main(void) {
	CoffeeVendingMachine cm;
	cm.run();
	return 0;
}