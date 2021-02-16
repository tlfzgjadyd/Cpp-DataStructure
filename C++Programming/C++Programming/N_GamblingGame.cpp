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
		cout << "***** ���� ������ �����մϴ�. *****"<<endl;
		string select1 = "";
		string select2 = "";
		cout << "ù��° ���� �̸�>>";
		cin >> select1;
		cout << "�ι�° ���� �̸�>>";
		cin >> select2;
		p[0].setName(select1);
		p[1].setName(select2);
		
		getchar(); //���� ����, �̸� �Է��Ҷ� ���� ���� �൵ �̰� �Ѱ��� ���� ��������
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
				cout << p[0].getName() << "�� �¸�!!" << endl;
			else
				cout << "�ƽ�����!" << endl;
			cout << p[1].getName() << ":<Enter>";
			getchar();
			cout << "            ";
			for (int i = 0; i < 3; i++) {
				nums[i] = rand() % 3;
				cout << nums[i] << "    ";
			}
			if (nums[0] == nums[1] && nums[1] == nums[2])
			{
				cout << p[1].getName() << "�� �¸�!!" << endl;
				break;
			}
			else
				cout << "�ƽ�����!" << endl;
		}
	}
};
int main(void) {
	GamblingGame game;
	game.run();
	return 0;
}