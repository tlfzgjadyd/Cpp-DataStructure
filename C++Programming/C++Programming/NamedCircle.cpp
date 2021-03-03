#include <iostream>
using namespace std;
class Circle {
private://�ڽ��� radius ����ϱ� ������ ����� ������ ��� Circle ���ؼ� �����ϱ⿡ protected�� �����൵��
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};
class NamedCircle : Circle {//�� ���� ���� �̷���? ���� �ڹٶ� �Ȱ��� �ʾҳ�? ����ϴ� ����� ��Ʋ��ó���ƴµ�?
private:
	string name;
public:
	NamedCircle(int radius, string name) :Circle(radius){//���� �̺κе� ��Ʋ��ó�� �ٲ���� �ƴϸ� �ΰ� ��� ������ �־ �Ȱ����� ���� ��ġ�� ��ë���ǰ� ������ �Ȱ�����
		this->name = name;
	}
	void show() {
		cout << "�������� " << getRadius() << "�� " << name << endl;//getRadius�� �θ��� �Լ��̱� ������ public���� ��ӹ޾ұ⿡ ������ �̸� ��� ���̵� ȣ�� ���� super�� �ڹٸ��� ���̾�����
	}
};
int main(void) {
	NamedCircle waffle(3, "waffle");//�������� 3�̰� �̸��� waffle�� ��
	waffle.show();
}