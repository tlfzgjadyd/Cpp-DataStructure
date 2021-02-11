#pragma once
#include <iostream>
using namespace std;
class I_Oval
{
private:
	int width;
	int height;
public:
	I_Oval() {
		width = 1;
		height = 1;
	}
	I_Oval(int w, int h) {
		width = w;
		height = h;
	}
	void set(int w, int h) {
		width = w;
		height = h;
	}
	void show() {
		cout << "width = " << width << ", height = " << height << endl;
	}
	int getWidth() {
		return width;
	}
	int getHeight() {
		return height;
	}
	~I_Oval() {
		cout<<"Oval ¼Ò¸ê : width = "<<width<< ", height = " << height << endl;
	}
};

