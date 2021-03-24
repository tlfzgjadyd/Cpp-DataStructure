#include <iostream>
using namespace std;

class Rectangle {
private:
	int x;
	int y;
	int width;
	int height;
public:
	Rectangle() {
		this->x = 1;//��ǥ�� ����� ó���ϱ�
		this->y = 1;
		this->width = 0;
		this->height = 0;
	}
	Rectangle(int x, int y, int width, int height) {
		if (x > 0 && y > 0) {//��ǥ�� ����� ó���ϱ�
			cout << "������ : ���簢���� �����մϴ�" << endl;
			this->x = x;
			this->y = y;
		}
		else
		{
			cout << "��ǥ�� ����� �ƴ� ���� �����־� 1�� �ٲ� �����մϴ�" << endl;
			this->x = 1;//��ǥ�� ����� ó���ϱ�
			this->y = 1;
		}
		if (width > 0 && height > 0)
		{
			this->width = width;
			this->height = height;
		}
		else
		{
			this->width = 0;
			this->height = 0;
		}
	}
	~Rectangle() {
	}
	void read() {
		cout << "x, y, width, height�� �Է��Ͻÿ� : ";
		int x = 0;
		int y = 0;
		int width = 0;
		int height = 0;
		cin >> x >> y >> width >> height;
		if (x > 0 && y > 0) {//��ǥ�� ����� ó���ϱ�
			cout << "������ : ���簢���� �����մϴ�" << endl;
			this->x = x;
			this->y = y;
		}
		else
		{
			cout << "��ǥ�� ����� �ƴ� ���� �����־� 1�� �ٲ� �����մϴ�" << endl;
			this->x = 1;//��ǥ�� ����� ó���ϱ�
			this->y = 1;
		}
		if (width > 0 && height > 0)
		{
			this->width = width;
			this->height = height;
		}
		else
		{
			this->width = 0;
			this->height = 0;
		}
	}
	void print() {
		cout << "���簢���� ���� : �� ���簢���� x=" << x << ", y=" << y << ",width=" << width << ", height=" << height << "�Դϴ�." << endl;
	}
	int getArea() {
		return width * height;
	}

	Rectangle operator +(Rectangle& r) {// + ��ȣ�� ������ --> 2���� �簢���� ���ο� �����ϴ� �������� �簢���� ������ǥ �� ���̿�, ���̸� ��� ( ���ǳ��� ���� )
		int smallX = 0;
		int bigX = 0;
		int bigWidth = 0;

		int smallY = 0;
		int bigY = 0;
		int bigHeight = 0;

		if (this->x < r.x)
		{
			smallX = this->x;
			bigX = r.x;
			bigWidth = r.width;
		}
		else
		{
			smallX = r.x;
			bigX = this->x;
			bigWidth = this->width;
			if (this->x == r.x)
			{
				if (this->width > r.width)
					bigWidth = this->width;
				else
					bigWidth = r.width;
			}
		}
		if (this->y < r.y)
		{
			smallY = this->y;
			bigY = r.y;
			bigHeight = r.height;
		}
		else
		{
			smallY = r.y;
			bigY = this->y;
			bigHeight = this->height;
			if (this->y == r.y)
			{
				if (this->height > r.height)
					bigHeight = this->height;
				else
					bigHeight = r.height;
			}
	}
		return Rectangle(smallX, smallY, bigX - smallX + bigWidth, bigY - smallY + bigHeight);
	}
	Rectangle operator /(Rectangle& r) {//  / ��ȣ�� ������ --> 2���� �簢���� �����Ǵ� �κ��� �簢���� ������ǥ �� ���̿� ���̸� ��� ( ���ǳ��� ���� )
		int smallX = 0;
		int smallWidth = 0;
		int bigX = 0;

		int smallY = 0;
		int smallHeight = 0;
		int bigY = 0;

		if (this->x < r.x)
		{
			smallX = this->x;
			bigX = r.x;
			smallWidth = this->width;
		}
		else
		{
			smallX = r.x;
			bigX = this->x;
			smallWidth = r.width;
			if (this->x == r.x)
			{
				if (this->width > r.width)
					smallWidth = r.width;
				else
					smallWidth = this->width;
			}
		}
		if (this->y < r.y)
		{
			smallY = this->y;
			smallHeight = this->height;
			bigY = r.y;
		}
		else
		{
			smallY = r.y;
			bigY = this->y;
			smallHeight - r.height;
			if (this->y == r.y)
			{
				if (this->height > r.height)
					smallHeight = r.height;
				else
					smallHeight = this->height;
			}
		}
		if ((smallX + smallWidth < bigX) || (smallY + smallHeight < bigY))//�ȸ����� ���
		{
			return Rectangle(1, 1, 0, 0);//��ǥ�� ����� ����
		}
		else if ((smallX + smallWidth == bigX) && (smallY + smallHeight == bigY)) {//������ ���
			return Rectangle(1, 1, 0, 0);//��ǥ�� ����� ����
		}
		else {//��ġ�� ���
			return Rectangle(bigX, bigY, smallX + smallWidth - bigX, smallY + smallHeight - bigY);
		}
	}
	friend bool operator ==(Rectangle& r1, Rectangle& r2);
	friend ostream& operator<<(ostream& cout, Rectangle r);// << ��ȣ�� ��� --> cout �� ���� ����Ҽ� �ֵ��� �����ڸ� ���� ( ���ǳ��� �� ���� ���� )
};
ostream& operator<<(ostream& cout, Rectangle r)
{
	if (r.width == 0 || r.height == 0)
		cout << "���簢���� ���� : �� ���簢���� �ʺ� ���̰� 0�Դϴ�" << endl;
	else
		cout << "���簢���� ���� : �� ���簢���� x=" << r.x << ", y=" << r.y << ",width=" << r.width << ", height=" << r.height << "�Դϴ�."<<endl;
	return cout;
}
bool operator ==(Rectangle& r1, Rectangle& r2) {// == ��ȣ�� ���ϼ� �Ǵ� --> 2���� �簢���� ������ ��ǥ �� ���̿� ���̸� ������ �ִ����� �Ǵ� ( ���� ���� )
	if ((r1.x == r2.x) && (r1.y == r2.y) && (r1.width == r2.width) && (r1.height == r2.height))
		return true;
	else
		return false;
}
int main(void) {
	cout << "�⺻ �����ڷ� ���簢�� r1�� �����մϴ�" << endl;
	Rectangle r1;
	r1.print();
	r1.read();
	r1.print();
	cout<<"�� ���簢���� ���� : "<<r1.getArea()<<endl<<endl;

	cout << "���ڸ� ������ �����ڷ� ���簢�� r2�� �����մϴ�" << endl;
	Rectangle r2(3, 3, 2, 2);
	r2.print();
	cout << "�� ���簢���� ���� : "<< r2.getArea()<<endl << endl;

	cout << "������ ���ڷ� �ְ� ���簢�� r3 ������ �õ��մϴ� " << endl;
	Rectangle r3(-1, -2, -3, -4);
	r3.print();
	cout << "�� ���簢���� ���� : " << r3.getArea()<<endl << endl;

	cout << endl<<"=========================================" << endl;
	cout << "+�����ڷ� r1�� r2�� �������� ������ "<<endl;
	cout << r1 + r2;
	cout << "=========================================" << endl;
	cout << "/�����ڷ� r1�� r2�� �������� ������ "<<endl;
	cout << r1 / r2;
	cout << "=========================================" << endl;
	cout << "==�����ڷ� r1�� r2�� ������ ������ "<<endl;
	cout << (r1 == r2)<<endl;
	cout << "=========================================" << endl;
	cout<< "<<�����ڷ� r1�� r2�� ����غ��� " << endl;
	cout << r1 << endl << r2 << endl;
}