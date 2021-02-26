#include <iostream>
using namespace std;
class Circle {
private:
	int radius;
public:
	Circle(int radius) {
		this->radius = radius;
	}
	void show() {
		cout << "radius = " << radius << " ÀÎ ¿ø" << endl;
	}
	friend Circle operator + (const int value, const Circle& c);
};
Circle operator + (const int value, const Circle& c) {
	return Circle(value + c.radius);
}
int main(void) {
	Circle a(5), b(4);
	b = 1 + a;
	a.show();
	b.show();
}