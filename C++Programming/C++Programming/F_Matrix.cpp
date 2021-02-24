#include <iostream>
using namespace std;
//이전 예제에선 필요에 따라 프렌드, 멤버함수를 나눠서 작성했는데
//소문제로 다 프렌드 만들기, 다 멤버함수 만들기가 있어서
//그렇다면 억지로라도 다른버전으로 만들어보기로 했음
//그래서 이건 전부 멤버함수 만들기 버전이다
//프렌드로 만드는거부터 하고 왔는데 걔는 쉬웠는데 문제는 이거임
//전달인자 개수를 내마음대로 늘리면 자꾸 전달인자 개수가 안맞는다고 못하게함
//그래서 전달인자 개수를 유지하면서 연산할 방법을 찾아야했음
class Matrix {
private:
	int a;
	int b;
	int c;
	int d;
public:
	Matrix() { 
		this->a = 0;
		this->b = 0;
		this->c = 0;
		this->d = 0;
	}
	Matrix(int a, int b, int c, int d) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
	}
	void show() {
		cout << "Matrix = { " << a << " " << b << " " << c << " " << d << " }" << endl;
	}
	Matrix operator +(const Matrix& m) {//와 전달인자 1개로 어떻게 풀지 살펴보니까 해결됐다
		int a = this->a + m.a;	  //일단 a+b니까 a가 호출의 주체가 되어 this가 되겠지 그리고 전달인자로는 b를 받겠지
		int b = this->b + m.b;    //근데 돌려주는건 c가 되어야 하니까 새로운 객체를 생성해서 돌려줬고
		int c = this->c + m.c;    //이때 return Matrix(a, b, c, d)를 통해서는 리턴값이 Matrix가 돼버리기 때문에 리턴값 타입을 바꿔줬음 성공이다!!
		int d = this->d + m.d;
		return Matrix(a, b, c, d);
	}
	Matrix& operator +=(const Matrix& m) {
		this->a += m.a;
		this->b += m.b;
		this->c += m.c;
		this->d += m.d;
		return *this; //호출주체도 a고 돌려주는것도 a가 돼야겠지
	}
	bool operator ==(const Matrix& m) {
		if (this->a == m.a && this->b == m.b && this->c == m.c && this->d == m.d)
			return true;
		else
			return false;
	}
};
int main(void) {
	Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
	c = a + b;
	a += b;
	a.show(); b.show(); c.show();
	if (a == c)
		cout << "a and c are the same" << endl;
}