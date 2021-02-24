#include <iostream>
using namespace std;
//���� �������� �ʿ信 ���� ������, ����Լ��� ������ �ۼ��ߴµ�
//�ҹ����� �� ������ �����, �� ����Լ� ����Ⱑ �־
//�׷��ٸ� �����ζ� �ٸ��������� ������� ����
//�׷��� �̰� ���� ������ ����� �����̴�
class Matrix {
private:
	int a;
	int b;
	int c;
	int d;
public:
	Matrix() {//�ٵ� �ؿ� ����Ʈ�ϴϱ� ������ ���ٰ��ߴµ� ������ �Ϲ� �Լ��鵵 ���� ���� ���ܳ��� ���Ǻ� ������ ���°ſ��� �ֳĸ� �������� �����ϱ�
		this->a = 0;//���Ϻи��ϸ� �Դٰ����ϱ� ���� �Ѱ��� �����־��µ� ���Ϻи��� �ؾ�����
		this->b = 0;//�ϴ��� �Ϲ��Լ��� ����� ���°ź��� ���� ����
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
	friend Matrix operator+(const Matrix& m1, const Matrix& m2);//�������� const�� ì������
	friend Matrix& operator+=(Matrix& m1, const Matrix& m2);//������ ���⼱ m1�� ���ؾ��ϱ⿡ m2���� const�� ì�����
	friend bool operator==(const Matrix& m1, const Matrix& m2);//������� �صδϱ� �������� ������ ���ϵ� �ѱ�鼭 ���߾����� ã���� ������ �����ε�
};															   //���� �ߴ����� �Ѵ��� ���̴���
Matrix operator+(const Matrix& m1, const  Matrix& m2) { //���ϰ��� �������Ͽ��� �ߴ���� ���ο� Matrix ��ü ���� ��������
	int a = m1.a + m2.a;
	int b = m1.b + m2.b;
	int c = m1.c + m2.c;
	int d = m1.d + m2.d;

	return Matrix(a, b, c, d);
}
Matrix& operator+=(Matrix& m1, const Matrix& m2) { //�̹� +������ ��������� �Ȱ� �ƴϳİ� �����Ҽ��� ������ +=�� ������ ������ �̰͵� ���������Ѵ�
	m1.a += m2.a;					        		//�ٵ� a+=b�� a�� b�� �������ڷ� �����ϱ� �������� �ϳ��� �����Ҽ��� �ִµ� �����Լ��� ����Ŷ�
	m1.b += m2.b;							        //�ᱹ�� �� �� �������ڷ� �޾ƾߵȴ�
	m1.c += m2.c;
	m1.d += m2.d;

	return m1;	//�״�� ���ϰ��� a�� ������߰��� m1�� ������ �̹� Matrix&�� �޾ұ⿡ ����Ÿ�Զ� *m1���ص� �ȴ� �������Ͽ� this�϶��� *this�ϴ°�
}				//�������� �Ȱ��� +=������ ����Լ��� ��������⿡ *this�� ������� �߾���
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