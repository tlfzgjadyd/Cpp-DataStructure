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
	Matrix& operator >>(int arr[]) {//operator�� �׻� �������ϰ����� �ؾ��Ѵٰ� �����ߴµ� ���ص� �ǳ� void�ص� ��
		for (int i = 0; i < 4; i++) {  //���������� �ʿ��ߴ� ������ a>>x>>y �̷������� ���� ������ �����ϵ��� �ϱ� �����̾��µ� ���⼱ ��������Ұ� a���� x���� �Ҹ�Ȯ�ϹǷ�
			arr[i] = array[i];	        //void�� ���� �����̱� �ߴµ� �׷��� �ϴ��� ������ �迭 �������ٰ�
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
	int x[4], y[4] = { 1, 2, 3, 4 }; //2���� ����� 4���� ���� ��
	a >> x; //a�� �� ���Ҹ� �迭 x�� ����, x[]�� {4, 3, 2, 1}
	b << y; //�迭 y�� ���� ���� b�� �� ���ҿ� ����
	
	for (int i = 0; i < 4; i++) cout << x[i] << ' '; //x[] ���
	cout << endl;
	b.show();
}