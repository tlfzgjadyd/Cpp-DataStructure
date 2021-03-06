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
class ColorPoint :public Point{
private:
	string color;
public:
	ColorPoint() :Point(0, 0) {
		this->color = "BLACK";
	}
	ColorPoint(int x, int y) :Point(x, y) {
		this->color = "BLACK";
	}
	void show() {
		cout << color << "색으로 (" << getX() << "," << getY() << ")에 위치한 점입니다." << endl;
	}
	void setPoint(int x, int y) {
		setX(x);
		setY(y);
	}
	void setColor(string color) {
		this->color = color;
	}
};
int main(void) {
	ColorPoint zeroPoint; //BLACK 색에 (0, 0) 위치의 점
	zeroPoint.show(); //zeroPoint를 출력한다

	ColorPoint cp(5, 5);
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show(); //cp를 출력한다
}