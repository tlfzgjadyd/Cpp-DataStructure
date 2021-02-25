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
	void show() {
		cout << "Matrix = { ";
		for (int i = 0; i < 4; i++)
			cout << array[i] << " ";
		cout << "}" << endl;
	}
	friend Matrix& operator>>(Matrix&, int arr[]);
	friend Matrix& operator<<(Matrix&, int arr[]);
};
Matrix& operator>>(Matrix& m, int arr[]) {//비교대상이 Matrix내부의 배열이긴 하지만 그래도 일단 받는 전달인자는 Matrix&여야됨 그렇게 받으니까
	for (int i = 0; i < 4; i++) { 
		arr[i] = m.array[i];	    	
	}
	return m;
}
Matrix& operator <<(Matrix& m, int arr[]) {
	for (int i = 0; i < 4; i++) {
		m.array[i] = arr[i];
	}
	return m;
}


int main(void) {
	Matrix a(4, 3, 2, 1), b;
	int x[4], y[4] = { 1, 2, 3, 4 }; //2차원 행렬의 4개의 원소 값
	a >> x; //a의 각 원소를 배열 x에 복사, x[]는 {4, 3, 2, 1}
	b << y; //배열 y의 원소 값을 b의 각 원소에 설정

	for (int i = 0; i < 4; i++) cout << x[i] << ' '; //x[] 출력
	cout << endl;
	b.show();
}