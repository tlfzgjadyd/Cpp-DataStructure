#include <iostream>
using namespace std;
int main(void) {
	int sum = 0;
	for (int i = 1; i <= 10; i++)
		sum += i;
	cout << "결과는 " << sum << "입니다" << endl;
}