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
			cout << "프린트하였습니다." << endl;
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
				cout << "용지가 부족하여 프린트할 수 없습니다" << endl;
		}
		else {
			cout << "잉크가 부족하여 프린트할 수 없습니다" << endl;
		}

	}
	int getAvailableInk() {
		return availableInk;
	}
	void show() {
		cout << getModel() << ", " << getManufacturer() << ", 남은 종이 " << getAvailableCount() << "장, 남은 잉크 " << getAvailableInk() << endl;
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
				cout << "용지가 부족하여 프린트할 수 없습니다" << endl;
		}
		else {
			cout << "토너가 부족하여 프린트할 수 없습니다" << endl;
		}	
	}
	int getAvailableToner() {
		return availableToner;
	}
	void show() {
		cout << getModel() << " , " << getManufacturer() << " ,남은 종이 " << getAvailableCount() << "장, 남은 토너 " << getAvailableToner();
	}
};
int main(void) {

	InkJetPrinter ij("Officejet V40", "HP", 5, 10);
	LaserPrinter lp("SCX-6x45", "삼성전자", 3, 20);

	cout << "현재 작동중인 2 대의 프린터는 아래와 같다" << endl;
	cout << "잉크젯 : ";  ij.show();
	cout << "레이저 : "; lp.show();
	cout<< endl;

	int type = 0;
	int pages = 0;
	while (true) {
		cout << endl<<"프린터(1:잉크젯, 2:레이저)와 매수 입력 >>";
		cin >> type >> pages;
		
		if (pages <= 0)
		{
			cout << "잘못된 입력입니다";
			continue;
		}
		else {
			if (type == 1)
				ij.printInkJet(pages);
			else if (type == 2)
				lp.printLaser(pages);
			else
				cout << "잘못된 입력입니다" << endl << endl;
		}

		cout << "잉크젯 : ";  ij.show();
		cout << "레이저 : "; lp.show();
		cout << endl;

		char select = ' ';
		cout << "계속 프린트 하시겠습니까(y/n)>>";
		cin >> select;
		if (select == 'y')
			continue;
		else if (select == 'n')
			break;
		else
			cout << "잘못된 입력입니다" << endl << endl;

	}

}