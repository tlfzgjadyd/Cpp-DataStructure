#pragma once
class Mul
{
private:
	int a;
	int b;
public:
	void setValue(int x, int y) {
		a = x;
		b = y;
	}
	int calculate() {
		return a * b;
	}
};

