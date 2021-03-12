#include <iostream>
#include <string>
using namespace std;
class Airplane {
private:
	string time;
	string seat[8];
public:
	Airplane() {}
	Airplane(string time) {
		this->time = time;
		for (int i = 0; i < 8; i++) {
			seat[i] = "---";
		}
	}
	string* getSeat() {
		return seat;
	}
	string getTime() {
		return time;
	}
};
class AirplaneManager{
private:
	Airplane airplane[3];

public:
	AirplaneManager(){
		airplane[0] = Airplane("07��");
		airplane[1] = Airplane("12��");
		airplane[2] = Airplane("17��");
	}
	void run() {
		cout << "***** �Ѽ��װ��� ���Ű��� ȯ���մϴ� *****" << endl;
		while (true) {
			cout << endl << "����:1, ���:2, ����:3, ������:4>> ";
			int select = 0;
			cin >> select;
			switch (select) {
			case 1: reserve(); break;
			case 2: cancel(); break;
			case 3: watch(); break;
			case 4: end(); break;
			default:; break;
			}
		}
	}
	void reserve() {
		cout << "07��:1, 12��:2, 17��:3>> ";
		int select = 0;
		cin >> select;
		show(select);
		cout << "�¼���ȣ>> ";
		int seatNum = 0;
		cin >> seatNum;
		cout << "�̸��Է�>> ";
		string name = "";
		cin >> name;
		if (seatNum > 0 && seatNum < 9)
		{
			string* s=airplane[select - 1].getSeat();
			s[seatNum - 1] = name;
		}
	}
	void cancel() {
		cout << "07��:1, 12��:2, 17��:3>> ";
		int select = 0;
		cin >> select;
		show(select);
		cout << "�¼���ȣ>> ";
		int seatNum = 0;
		cin >> seatNum;
		cout << "�̸��Է�>> ";
		string name = "";
		cin >> name;
		bool flag = false;
		for (int i = 0; i < 8; i++) {
			string* s = airplane[select - 1].getSeat();
			if (s[i] == name)
			{
				flag = true;
				s[i] = "---";
				break;
			}
		}
		if (flag == false)
			cout << "���� �����Դϴ�" << endl;
	}
	void watch() {
		show(1);
		show(2);
		show(3);
	}
	void end() {
		cout << "���� �ý����� �����մϴ�." << endl;
		exit(0);//�ڹٶ� ��Ʋ���� System.exit(0)�̾��ٸ� c++�� �׳� exit(0)�̴�
	}
	void show(int select) {
		string* a = airplane[select - 1].getSeat();
		cout << airplane[select - 1].getTime()<<":";
		for (int i = 0; i < 8; i++) {
			cout<<"    "<<a[i];
		}
		cout << endl;
	}
};
int main(void) {
	AirplaneManager am;
	am.run();
	return 0;
}