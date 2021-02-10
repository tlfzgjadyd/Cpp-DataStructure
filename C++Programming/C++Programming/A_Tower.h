#pragma once
#include <iostream>
using namespace std;

//자바와 달리 private int height하는게 아니라 private: 밑에 전부 작성 public: 밑에 전부 작성
class A_Tower
{
private:
	int height;
public:
	A_Tower() {
		height = 1;
	}
	A_Tower(int h) {
		height = h;//그리고 this가 없기에 멤버와 이름 다르게해서 전달인자 받아 초기화해야됨 같은 이름으로 하면 안먹히더라
	}
	int getHeight() {
		return height;
	}
};