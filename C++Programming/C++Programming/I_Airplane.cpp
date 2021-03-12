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
		airplane[0] = Airplane("07시");
		airplane[1] = Airplane("12시");
		airplane[2] = Airplane("17시");
	}
	void run() {
		cout << "***** 한성항공에 오신것을 환영합니다 *****" << endl;
		while (true) {
			cout << endl << "예약:1, 취소:2, 보기:3, 끝내기:4>> ";
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
		cout << "07시:1, 12시:2, 17시:3>> ";
		int select = 0;
		cin >> select;
		show(select);
		cout << "좌석번호>> ";
		int seatNum = 0;
		cin >> seatNum;
		cout << "이름입력>> ";
		string name = "";
		cin >> name;
		if (seatNum > 0 && seatNum < 9)
		{
			string* s=airplane[select - 1].getSeat();
			s[seatNum - 1] = name;
		}
	}
	void cancel() {
		cout << "07시:1, 12시:2, 17시:3>> ";
		int select = 0;
		cin >> select;
		show(select);
		cout << "좌석번호>> ";
		int seatNum = 0;
		cin >> seatNum;
		cout << "이름입력>> ";
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
			cout << "없는 예약입니다" << endl;
	}
	void watch() {
		show(1);
		show(2);
		show(3);
	}
	void end() {
		cout << "예약 시스템을 종료합니다." << endl;
		exit(0);//자바랑 코틀린이 System.exit(0)이었다면 c++은 그냥 exit(0)이다
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