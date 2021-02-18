#include <iostream>
using namespace std;
class MyIntStack{
private:
	int p[10]; //최대 10개의 정수 저장
	int tos; //스택의 꼭대기를 가리키는 인덱스
public:
	MyIntStack() {
		tos = 0;
	}
	bool push(int n) {
		if (tos == 10)
		{
			return false;
		}
		else
		{
			p[tos] = n;
			tos++;
			return true;
		}
	}//정수 n 푸시 꽉차있으면 false, 아니면 true 리턴
	bool pop(int& n) {
		if (tos == 0) 
		{
			return false;
		}
		else
		{
			n=p[tos - 1];
			tos--;
			return true;
		}
		
	}//팝하여 n에 저장, 스택이 비어있으면 false, 아니면 true 리턴
};
int main(void) {
	MyIntStack a;
	for (int i = 0; i < 11; i++) {
		if (a.push(i))cout << i << ' ';
		else cout << endl << i + 1 << " 번째 stack full" << endl;
	}
	int n;
	for (int i = 0; i < 11; i++) {
		if (a.pop(n))cout << n << ' ';
		else cout << endl << i + 1 << " 번째 stack empty";
	}
	cout << endl;
}