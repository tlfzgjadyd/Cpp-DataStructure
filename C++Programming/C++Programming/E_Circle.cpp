#include <iostream>
using namespace std;
//��� ���� �ڵ忡 ���� ���µ� �� ������ �ȵ��� �����Ҽ��� ������ ��� ������ �Ⱥ����� ���� ���� ȣ�� �ϸ� �� �����ص� �����ȵ�
//�׷��Ƿ� class�Լ� �Ȱǵ帮�� increaseBy�� �����ؼ� �ùٸ� ���� ������ �Ϸ��� �������ڸ� &�� �ٲ���Ѵ�
class Circle {
private:
	int radius;
public:
	Circle(int r) { radius = r; }
	int getRadius() { return radius; }
	void setRadius(int r) { radius = r; }
	void show() { cout << "�������� " << radius << "�� ��" << endl; }
};
void increaseBy(Circle& a, Circle& b){
	int r = a.getRadius() + b.getRadius();
	a.setRadius(r);
}
int main(void) {
	Circle x(10), y(5);
	increaseBy(x, y); //x�� �������� 15�� ���� ������� �Ѵ�
	x.show(); //"�������� 15�� ��"�� ����Ѵ�
}