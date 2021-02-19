#include <iostream>
using namespace std;
class MyIntStack {
private:
	int* p; //스택 메모리로 사용할 포인터
	int size; //스택의 최대 크기
	int tos; //스택의 탑을 가리키는 인덱스
public:
	MyIntStack() {
		p = new int[1];
		size = 0;
		tos = 0;
	}
	MyIntStack(int size) {
		this->p = new int[size];
		this->size = size;
		this->tos = 0;
	}
	MyIntStack(const MyIntStack& s) {
		this->size = s.size;
		this->p = new int[size]; //복사생성자에서 계속 에러났었는데 알고보니 this->p = s.p;가 아니라 똑같은 공간 만든 다음 내용물을 복사해야하는거였음
		for (int i = 0; i < size; i++) {//그래서 new로 공간 생성 후 for문 돌며 내용 복사까지 완료해야 한다
			p[i] = s.p[i];
		}
		this->tos = s.tos;
	}//복사생성자
	~MyIntStack() {
		delete[] p;
		size = 0;
		tos = 0;
	}
	bool push(int n) {
		if (tos == size)
		{
			return false;
		}
		else
		{
			p[tos] = n;
			tos++;
			return true;
		}
	}//정수 n을 스택에 푸시한다
	//스택이 꽉 차 있으면 false를, 아니면 true 리턴
	bool pop(int& n) {
		if (tos == 0)
		{
			return false;
		}
		else
		{
			n = p[tos - 1];
			tos--;
			return true;
		}
	}//스택의 탑에 있는 값을 n에 팝한다
	//만일 스택이 비어있으면 false를, 아니면 true 리턴
};
int main(void) {
	MyIntStack a(10);
	a.push(10);
	a.push(20);
	MyIntStack b = a; //복사 생성
	b.push(30);

	int n;
	a.pop(n); //스택 a 팝
	cout << "스택 a에서 팝한 값 " << n << endl;
	b.pop(n);//스택 b 팝
	cout << "스택 b에서 팝한 값 " << n << endl;
}