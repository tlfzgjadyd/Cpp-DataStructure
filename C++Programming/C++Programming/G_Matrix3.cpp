#include <iostream>
using namespace std;
class Matrix {
private:
	int array[4];
public:
	Matrix() {
		for (int i = 0; i < 4; i++) {
			array[i] = 0;
		}
	}
	Matrix(int a, int b, int c, int d) {
		array[0] = a;
		array[1] = b;
		array[2] = c;
		array[3] = d;
	}
	Matrix& operator >>(int arr[]) {//operator는 항상 참조리턴같은거 해야한다고 생각했는데 안해도 되네 void해도 됨
		for (int i = 0; i < 4; i++) {  //참조리턴이 필요했던 이유는 a>>x>>y 이런식으로 연속 연산이 가능하도록 하기 위함이었는데 여기선 돌려줘야할게 a인지 x인지 불명확하므로
			arr[i] = array[i];	        //void로 놔둘 생각이긴 했는데 그래도 일단은 참조로 배열 리턴해줄게
		}
		return *this;
	}
	Matrix& operator <<(int arr[]) {
		for (int i = 0; i < 4; i++) {
			array[i] = arr[i];
		}	
		return *this;
	}
	void show() {
		cout << "Matrix = { ";
		for (int i = 0; i < 4; i++)
			cout << array[i]<<" ";
		cout << "}"<<endl;
	}
};
int main(void) {
	Matrix a(4, 3, 2, 1), b;
	int x[4], y[4] = { 1, 2, 3, 4 }; //2차원 행렬의 4개의 원소 값
	a >> x; //a의 각 원소를 배열 x에 복사, x[]는 {4, 3, 2, 1}
	b << y; //배열 y의 원소 값을 b의 각 원소에 설정
	
	for (int i = 0; i < 4; i++) cout << x[i] << ' '; //x[] 출력
	cout << endl;
	b.show();
}