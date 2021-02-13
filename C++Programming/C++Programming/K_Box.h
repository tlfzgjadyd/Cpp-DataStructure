#pragma once
#include <iostream>
using namespace std;

class K_Box
{
private:
	int width;
	int height;
	char fill; //�ڽ��� ���θ� ä��� ����
public:
	K_Box(int w, int h) {
		setSize(w, h); //�ϱ� setSize�Լ� ������ �����ڿ��� ������� �ǰڱ���
		fill = '*';
	}
	void setFill(char f) {
		fill = f;
	}
	void setSize(int w, int h) { width = w; height = h; }
	void draw();//�ڽ� �׸���, �����ο� �����Ұ���
};

