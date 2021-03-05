#include <iostream>
using namespace std;
class Point {
private:
	int x, y;
public:
	Point(int x, int y) { this->x = x; this->y = y; }
	int getX() { return x; }
	int getY() { return y; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
protected:
	void move(int x, int y) { this->x = x; this->y = y; }
};
class ColorPoint : public Point {
private:
	string color;
public:
	ColorPoint(int x, int y, string color) : Point(x, y) {
		this->color = color;
	}
	void setPoint(int x, int y) { 
		this->setX(x);
		this->setY(y);
	}
	void setColor(string color) {
		this->color = color;
	}
	void show() {
		cout << color << "색으로 (" << getX() << "," << getY() << ")에 위치한 점입니다." << endl;
	}
};
int main(void) {
	ColorPoint cp(5, 5, "RED");
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show();
}