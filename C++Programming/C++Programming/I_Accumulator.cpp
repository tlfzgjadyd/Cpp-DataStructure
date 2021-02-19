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
		return *this; //�� Accumulator& ������ ��� �����ϴ��� ��԰� �־��µ� *this�� �����ָ� �ȴ�
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