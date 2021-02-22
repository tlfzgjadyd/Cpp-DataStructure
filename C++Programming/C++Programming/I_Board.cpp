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
		cout << "********** 게시판입니다. **********" << endl;
		for (int i = 0; i < board.size(); i++) {
			cout << i << ": " << board[i] << endl;
		}
		cout << endl;
	}
};
vector<string> Board::board;//클래스 객체를 따로 사용하지 않기 때문에 static 프로퍼티는 미리 공간을 할당해줘야 해서 전역변수 선언이 필요하다 자료형 클래스명::변수명;
int main(void) {
	//Board myBoard; //객체 생성은 컴파일 오류입니다.
	Board::add("중간고사는 감독 없는 자율 시험입니다.");
	Board::add("코딩 라운지 많이 이용해 주세요.");
	Board::print();
	Board::add("진소린 학생이 경진대회 입상하였습니다. 축하해주세요");
	Board::print();
}