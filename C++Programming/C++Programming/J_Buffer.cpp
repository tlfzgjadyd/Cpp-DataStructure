#include <iostream>
using namespace std;
class Buffer {
private:
	string text;
public:
	Buffer(string text) { this->text = text; }
	void add(string next) { text += next; }
	void print() { cout << text << endl; }
};
Buffer& append(Buffer& buf, string str); //에러났던 이유는 함수 선언부 밑에다가 class Buffer 정의부 써서 못알아먹었기 때문 그러므로 함수선언부에 클래스 쓸거면 클래스를 먼저 위에 둬야됨

int main(void) {
	Buffer buf("Hello");
	Buffer& temp = append(buf, "Guys");//buf의 문자열에 "Guys" 덧붙임
	temp.print();
	buf.print();
}
Buffer& append(Buffer& buf, string str) { //이전 예제에서는 자기자신 참조를 리턴하는 것이었어서 *this를 리턴했지만 여기선 함수라 자기자신이 아니므로
	buf.add(str);
	return buf;								//그냥 받은대로 주면 됨 왜냐면 그냥 Buffer buf 전달인자 받으면 값에의한 호출로 값 수정 안되기에 Buffer&로 참조로 받았기 때문
}