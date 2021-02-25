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
Matrix& operator>>(Matrix& m, int arr[]) {//�񱳴���� Matrix������ �迭�̱� ������ �׷��� �ϴ� �޴� �������ڴ� Matrix&���ߵ� �׷��� �����ϱ�
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
	int x[4], y[4] = { 1, 2, 3, 4 }; //2���� ����� 4���� ���� ��
	a >> x; //a�� �� ���Ҹ� �迭 x�� ����, x[]�� {4, 3, 2, 1}
	b << y; //�迭 y�� ���� ���� b�� �� ���ҿ� ����

	for (int i = 0; i < 4; i++) cout << x[i] << ' '; //x[] ���
	cout << endl;
	b.show();
}