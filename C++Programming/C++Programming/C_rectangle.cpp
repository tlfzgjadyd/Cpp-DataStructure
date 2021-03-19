#include <iostream>
using namespace std;
/*1. �������� ��ǥ(x,y)�� ����(width) �� ����(height)�� ǥ���Ǵ� Rectangle Ŭ������ �ۼ�.

2. �⺻������ �� �Ҹ���(�ı���) �ۼ� ( �߰� ���� �� �Ҹ��ڸ� �����ص� �� )

3. Rectangle Ŭ������ �����͸� �Է¹޴� read �Լ� �ۼ�

4. Rectangle Ŭ������ �����͸� ����ϴ� print �Լ� �ۼ�

5. +, /, ==, << 4���� ������ �����ε��� ����

  5.1 + ��ȣ�� ������ --> 2���� �簢���� ���ο� �����ϴ� �������� �簢���� ������ǥ �� ���̿�, ���̸� ��� ( ���ǳ��� ���� )

  5.2 / ��ȣ�� ������ --> 2���� �簢���� �����Ǵ� �κ��� �簢���� ������ǥ �� ���̿� ���̸� ��� ( ���ǳ��� ���� )

  5.3 == ��ȣ�� ���ϼ� �Ǵ� --> 2���� �簢���� ������ ��ǥ �� ���̿� ���̸� ������ �ִ����� �Ǵ� ( ���� ���� )

  5.4 << ��ȣ�� ��� --> cout �� ���� ����Ҽ� �ֵ��� �����ڸ� ���� ( ���ǳ��� �� ���� ���� )

** 5.5 ���̸� ���ϴ� getArea()�Լ� �ۼ� ( ���ǳ��� ���� )
**��ǥ�� ����� ó���ϱ�
*/
class Rectangle {
private:
	int x;
	int y;
	int width;
	int height;
public:
	Rectangle(int x, int y, int width, int height) {
		if (x > 0 && y > 0 && width > 0 && height > 0) {
			cout << "������ : ���簢���� �����մϴ�" << endl;
			this->x = x;
			this->y = y;
			this->width = width;
			this->height = height;
		}
		else
		{
			cout << "������ �����־� ������ �Ұ����մϴ�" << endl;
		}
	}
	void read(int data) {

	}
	void print() {
		cout << "���簢���� ���� : �� ���簢���� x=" << x << ", y=" << y << ",width=" << width << ", height=" << height << "�Դϴ�." << endl;
	}
	int getArea() {
		return width * height;
	}
	~Rectangle() {
		cout << "�Ҹ��� : ���簢���� �����մϴ�" << endl;
	}
	Rectangle& operator +(Rectangle& r) {// + ��ȣ�� ������ --> 2���� �簢���� ���ο� �����ϴ� �������� �簢���� ������ǥ �� ���̿�, ���̸� ��� ( ���ǳ��� ���� )
		//���� �Ǻ��ϱ�
		Rectangle answer(x2, y2, w2, h2);
		return answer;
	}
	Rectangle& operator /(Rectangle& r) {//  / ��ȣ�� ������ --> 2���� �簢���� �����Ǵ� �κ��� �簢���� ������ǥ �� ���̿� ���̸� ��� ( ���ǳ��� ���� )

	}
	bool operator ==(Rectangle& r) {// == ��ȣ�� ���ϼ� �Ǵ� --> 2���� �簢���� ������ ��ǥ �� ���̿� ���̸� ������ �ִ����� �Ǵ� ( ���� ���� )
		if ((this->x == r.x) && (this->y == r.y) && (this->width == r.width) && (this->height == r.height))
			return true;
		else
			return false;
	}
	Rectangle& operator<<(ostream& cout) {// << ��ȣ�� ��� --> cout �� ���� ����Ҽ� �ֵ��� �����ڸ� ���� ( ���ǳ��� �� ���� ���� )
		print();
		return *this;
	}

};
int main(void) {
	cout << "���簢���� x, y, width, height�� �Է��Ͻÿ�>>";
	int x = 0;
	int y = 0;
	int width = 0;
	int height = 0;
	cin >> x >> y >> width >> height;
}