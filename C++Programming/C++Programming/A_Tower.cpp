#include "A_Tower.h"

//내가 작성한 내용은 A_Tower.h에있음
int main(void) {
	A_Tower myTower; //1미터
	A_Tower seoulTower(100); //100미터
	cout << "높이는 " << myTower.getHeight() << "미터" << endl;
	cout << "높이는" << seoulTower.getHeight() << "미터"<< endl;
}