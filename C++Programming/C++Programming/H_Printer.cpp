#include <iostream>
using namespace std;
class Printer {
private:
	string model;
	string manufacturer;
	int printedCount;
	int availableCount;

public:
	Printer(string model, string manufacturer, int availableCount) {
		this->model = model;
		this->manufacturer = manufacturer;
		this->availableCount = availableCount;
		this->printedCount = 0;
	}
	void print(int pages) {
			printedCount++;
			availableCount--;
			cout << "����Ʈ�Ͽ����ϴ�." << endl;
	}
	string getModel() {
		return model;
	}
	string getManufacturer() {
		return manufacturer;
	}
	int getAvailableCount() {
		return availableCount;
	}
};
class InkJetPrinter :public Printer {
private:
	int availableInk;
public:
	InkJetPrinter(string model, string manufacturer, int availableCount, int availableInk) :Printer(model, manufacturer, availableCount) {
		this->availableInk=availableInk;
	}
	void printInkJet(int pages) {
		if (availableInk - pages >= 0) {
			availableInk -= pages;
			if (getAvailableCount() - pages >= 0) {
				print(pages);
			}
			else
				cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�" << endl;
		}
		else {
			cout << "��ũ�� �����Ͽ� ����Ʈ�� �� �����ϴ�" << endl;
		}

	}
	int getAvailableInk() {
		return availableInk;
	}
	void show() {
		cout << getModel() << ", " << getManufacturer() << ", ���� ���� " << getAvailableCount() << "��, ���� ��ũ " << getAvailableInk() << endl;
	}
};
class LaserPrinter :public Printer {
private:
	int availableToner;
public:
	LaserPrinter(string model, string manufacturer, int availableCount, int availableToner) :Printer(model, manufacturer, availableCount){
		this->availableToner = availableToner;
	}
	void printLaser(int pages) {
		if (availableToner - pages >= 0)
		{
			availableToner -= pages;
			if (getAvailableCount() - pages >= 0) {
				print(pages);
			}
			else
				cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�" << endl;
		}
		else {
			cout << "��ʰ� �����Ͽ� ����Ʈ�� �� �����ϴ�" << endl;
		}	
	}
	int getAvailableToner() {
		return availableToner;
	}
	void show() {
		cout << getModel() << " , " << getManufacturer() << " ,���� ���� " << getAvailableCount() << "��, ���� ��� " << getAvailableToner();
	}
};
int main(void) {

	InkJetPrinter ij("Officejet V40", "HP", 5, 10);
	LaserPrinter lp("SCX-6x45", "�Ｚ����", 3, 20);

	cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����" << endl;
	cout << "��ũ�� : ";  ij.show();
	cout << "������ : "; lp.show();
	cout<< endl;

	int type = 0;
	int pages = 0;
	while (true) {
		cout << endl<<"������(1:��ũ��, 2:������)�� �ż� �Է� >>";
		cin >> type >> pages;
		
		if (pages <= 0)
		{
			cout << "�߸��� �Է��Դϴ�";
			continue;
		}
		else {
			if (type == 1)
				ij.printInkJet(pages);
			else if (type == 2)
				lp.printLaser(pages);
			else
				cout << "�߸��� �Է��Դϴ�" << endl << endl;
		}

		cout << "��ũ�� : ";  ij.show();
		cout << "������ : "; lp.show();
		cout << endl;

		char select = ' ';
		cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
		cin >> select;
		if (select == 'y')
			continue;
		else if (select == 'n')
			break;
		else
			cout << "�߸��� �Է��Դϴ�" << endl << endl;

	}

}