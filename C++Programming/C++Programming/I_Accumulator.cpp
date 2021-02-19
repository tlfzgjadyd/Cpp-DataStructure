#include <iostream>
using namespace std;

class Accumulator {
private:
	int value;
public:
	Accumulator(int value) {
		this->value = value;
	}
	Accumulator& add(int n) {
		value += n;
		return *this; //오 Accumulator& 참조형 어떻게 리턴하는지 까먹고 있었는데 *this로 돌려주면 된다
	}
	int get() {
		return value;
	}
};
int main(void) {
	Accumulator acc(10);
	acc.add(5).add(6).add(7);
	cout << acc.get();
}