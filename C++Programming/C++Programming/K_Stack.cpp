#include <iostream>
using namespace std;
class Stack {
private:
	int* content;
	int size;
public:
	Stack(){
		this->size = 0;
		this->content = new int[size];
	}
	Stack& operator <<(int num) {
		content[size] = num;
		size++;
		return *this; //지속적인 연산이 필요하므로 자기자신 리턴
	}
	bool operator !() {//단항연산자는 호출대상 앞에 오더라도 호출대상이 호출한거니까 별도의 전달인자 안받는거였지
		if (size == 0)
			return true;
		else
			return false;
	}
	Stack& operator >>(int& place) {//지속적인 연산을 하는 연산자이기에 자기 자신을 돌려줘야 하는데 변수에 팝한 값도 담아줘야 하기에 참조에 의한 호출로 값 변경이 가능하도록 만들었다
		place = content[size - 1];
		content[size - 1] = 0;
		size--;
		return *this;
	}
};
int main(void) {
	Stack stack;
	stack << 3 << 5 << 10; //3, 5, 10을 순서대로 푸시
	while (true) {
		if (!stack) break; //스택 empty
		int x;
		stack >> x; //스택의 탑에 있는 정수 팝
		cout << x << ' ';
	}
	cout << endl;
}