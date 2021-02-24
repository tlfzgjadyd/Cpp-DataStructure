#include <iostream>
using namespace std;
//이전 예제에선 필요에 따라 프렌드, 멤버함수를 나눠서 작성했는데
//소문제로 다 프렌드 만들기, 다 멤버함수 만들기가 있어서
//그렇다면 억지로라도 다른버전으로 만들어보기로 했음
//그래서 이건 전부 프렌드 만들기 버전이다
class Matrix {
private:
	int a;
	int b;
	int c;
	int d;
public:
	Matrix() {//근데 밑에 프렌트하니까 가독성 좋다고했는데 원래는 일반 함수들도 여긴 선언만 남겨놓고 정의부 밖으로 빼는거였다 왜냐면 가독성이 좋으니까
		this->a = 0;//파일분리하면 왔다갔다하기 힘들어서 한곳에 놓고있었는데 파일분리도 해야하지
		this->b = 0;//일단은 일반함수들 선언부 빼는거부터 먼저 하자
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
	friend Matrix operator+(const Matrix& m1, const Matrix& m2);//잊지말고 const를 챙겨줬음
	friend Matrix& operator+=(Matrix& m1, const Matrix& m2);//하지만 여기선 m1이 변해야하기에 m2에만 const를 챙겨줬다
	friend bool operator==(const Matrix& m1, const Matrix& m2);//프렌드로 해두니까 가독성이 좋았음 파일들 넘기면서 뭐했었는지 찾을때 연산자 오버로딩
};															   //뭐뭐 했는지가 한눈에 보이더라
Matrix operator+(const Matrix& m1, const  Matrix& m2) { //리턴값은 이전파일에서 했던대로 새로운 Matrix 객체 만들어서 돌려줬음
	int a = m1.a + m2.a;
	int b = m1.b + m2.b;
	int c = m1.c + m2.c;
	int d = m1.d + m2.d;

	return Matrix(a, b, c, d);
}
Matrix& operator+=(Matrix& m1, const Matrix& m2) { //이미 +연산자 만들었으니 된거 아니냐고 생각할수도 있지만 +=는 별개의 문제라 이것도 만들어줘야한다
	m1.a += m2.a;					        		//근데 a+=b로 a가 b를 전달인자로 받으니까 전달인자 하나로 착각할수도 있는데 전역함수로 만들거라
	m1.b += m2.b;							        //결국엔 둘 다 전달인자로 받아야된다
	m1.c += m2.c;
	m1.d += m2.d;

	return m1;	//그대신 리턴값은 a를 돌려줘야겠지 m1을 받을때 이미 Matrix&로 받았기에 리턴타입때 *m1안해도 된다 참조리턴에 this일때만 *this하는것
}				//얼마전에는 똑같은 +=문제를 멤버함수로 만들었었기에 *this로 돌려줘야 했었지
bool operator==(const Matrix& m1, const Matrix& m2) {
	if (m1.a == m2.a && m2.b == m2.b && m1.c == m2.c && m1.d == m2.d)
		return true;
	else
		return false;
}
int main(void) {
	Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
	c = a + b;
	a += b;
	a.show(); b.show(); c.show();
	if (a == c)
		cout << "a and c are the same" << endl;
}