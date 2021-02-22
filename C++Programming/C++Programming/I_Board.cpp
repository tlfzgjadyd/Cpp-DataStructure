#include <iostream>
#include <vector>
using namespace std;
class Board {
private:
	static vector<string> board;
public:
	static void add(string content) {
		board.push_back(content);
	}
	static void print() {
		cout << "********** �Խ����Դϴ�. **********" << endl;
		for (int i = 0; i < board.size(); i++) {
			cout << i << ": " << board[i] << endl;
		}
		cout << endl;
	}
};
vector<string> Board::board;//Ŭ���� ��ü�� ���� ������� �ʱ� ������ static ������Ƽ�� �̸� ������ �Ҵ������ �ؼ� �������� ������ �ʿ��ϴ� �ڷ��� Ŭ������::������;
int main(void) {
	//Board myBoard; //��ü ������ ������ �����Դϴ�.
	Board::add("�߰����� ���� ���� ���� �����Դϴ�.");
	Board::add("�ڵ� ����� ���� �̿��� �ּ���.");
	Board::print();
	Board::add("���Ҹ� �л��� ������ȸ �Ի��Ͽ����ϴ�. �������ּ���");
	Board::print();
}