#include <iostream>
#include <string>
using namespace std;
class Player {
private:
	string name;
public:
	string getName() {
		return name;
	}
	void setName(string name) {
		this->name = name;
	}
};
class GamblingGame {
private:
	Player* p;
	int size;
public:
	GamblingGame() {
		this->size = 2;
		p = new Player[size];
	}
	void run() {
		cout << "***** 갬블링 게임을 시작합니다. *****"<<endl;
		string select1 = "";
		string select2 = "";
		cout << "첫번째 선수 이름>>";
		cin >> select1;
		cout << "두번째 선수 이름>>";
		cin >> select2;
		p[0].setName(select1);
		p[1].setName(select2);
		
		getchar(); //버퍼 비우기, 이름 입력할때 공백 많이 줘도 이거 한개로 대응 가능했음
		int nums[3];
		while (true) {
			cout << p[0].getName() << ":<Enter>";
			getchar();
			cout << "            ";
			for (int i = 0; i < 3; i++) {
				nums[i] = rand() % 3;
				cout << nums[i]<<"    ";
			}
			if (nums[0] == nums[1] && nums[1] == nums[2])
				cout << p[0].getName() << "님 승리!!" << endl;
			else
				cout << "아쉽군요!" << endl;
			cout << p[1].getName() << ":<Enter>";
			getchar();
			cout << "            ";
			for (int i = 0; i < 3; i++) {
				nums[i] = rand() % 3;
				cout << nums[i] << "    ";
			}
			if (nums[0] == nums[1] && nums[1] == nums[2])
			{
				cout << p[1].getName() << "님 승리!!" << endl;
				break;
			}
			else
				cout << "아쉽군요!" << endl;
		}
	}
};
int main(void) {
	GamblingGame game;
	game.run();
	return 0;
}