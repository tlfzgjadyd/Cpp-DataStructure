#pragma once
#include <iostream>
using namespace std;

class K_Box
{
private:
	int width;
	int height;
	char fill; //박스의 내부를 채우는 문자
public:
	K_Box(int w, int h) {
		setSize(w, h); //하긴 setSize함수 있으면 생성자에서 써버려도 되겠구나
		fill = '*';
	}
	void setFill(char f) {
		fill = f;
	}
	void setSize(int w, int h) { width = w; height = h; }
	void draw();//박스 그리기, 구현부에 정의할거임
};

