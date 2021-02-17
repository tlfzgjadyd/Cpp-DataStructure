#include <iostream>
using namespace std;
double half(double num);
int main(void) {
	cout << half(20);
}
double half(double num) {
	return num / 2;
}