#include <iostream>
using namespace std;
//���� �������� �ʿ信 ���� ������, ����Լ��� ������ �ۼ��ߴµ�
//�ҹ����� �� ������ �����, �� ����Լ� ����Ⱑ �־
//�׷��ٸ� �����ζ� �ٸ��������� ������� ����
//�׷��� �̰� ���� ����Լ� ����� �����̴�
//������� ����°ź��� �ϰ� �Դµ� �´� �����µ� ������ �̰���
//�������� ������ ��������� �ø��� �ڲ� �������� ������ �ȸ´´ٰ� ���ϰ���
//�׷��� �������� ������ �����ϸ鼭 ������ ����� ã�ƾ�����
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
	Matrix operator +(const Matrix& m) {//�� �������� 1���� ��� Ǯ�� ���캸�ϱ� �ذ�ƴ�
		int a = this->a + m.a;	  //�ϴ� a+b�ϱ� a�� ȣ���� ��ü�� �Ǿ� this�� �ǰ��� �׸��� �������ڷδ� b�� �ް���
		int b = this->b + m.b;    //�ٵ� �����ִ°� c�� �Ǿ�� �ϴϱ� ���ο� ��ü�� �����ؼ� �������
		int c = this->c + m.c;    //�̶� return Matrix(a, b, c, d)�� ���ؼ��� ���ϰ��� Matrix�� �Ź����� ������ ���ϰ� Ÿ���� �ٲ����� �����̴�!!
		int d = this->d + m.d;
		return Matrix(a, b, c, d);
	}
	Matrix& operator +=(const Matrix& m) {
		this->a += m.a;
		this->b += m.b;
		this->c += m.c;
		this->d += m.d;
		return *this; //ȣ����ü�� a�� �����ִ°͵� a�� �ž߰���
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