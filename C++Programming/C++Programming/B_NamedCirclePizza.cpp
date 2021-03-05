#include <iostream>
using namespace std;
class Circle {
private:
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};
class NamedCircle : public Circle {//�Ǵٸ� �ſ� �߿��� �ٸ����� �־��� ��Ʋ���� �׳� �ڽ� : �θ� �ϸ� �Ǵµ� c++�� �׷��� �ϸ� �Ϲ������� private ������� �����ϱ� ������
								    //�ڽ�Ŭ���� ���ο��� �θ� Ŭ���� �Լ��� �� �� ������ �ٱ������� �ڽ�Ŭ���� ��ü�� ���� �θ�Ŭ���� �Լ��� ȣ���� �� ��������
									//���� ó���� ��ﶧ�� ���� �޶����Ͱ��� ��·�� ������ �׷��� �ٸ� �����̶� ���� �����������
									//�ڽ� : public �θ� �� ������� ��� �ٱ������� ���� ���� �˴���ó�� �θ��� �Լ� ȣ���� ����������
private:
	string name;
public:
	NamedCircle(int radius=0) : Circle(radius) {
		;
	}
	void set(int radius, string name) { 
		setRadius(radius);
		this->name = name;  
	} //�̰� ���� ��������ŵ� ó���� ������ �������� �ϴ��� �˰� �ִ� ���¿��µ�
		//��ӹ޾����ϱ� Circle�� public�Լ��� NamedCircle�� �����ݾ� �ٵ� �������°���
		 //�� public ���� �ڽ�:�θ�θ� ��ӹ��� �ڽ��� ���������� �θ��� ���������� ����� �Լ��� ������ ���������� �ٱ����� �Ұ����ϱ⿡ �ڽ� : public �θ�� �ؾ�����
											
	string getName() { return name; }
};
int main(void) {
	NamedCircle pizza[5];//���⼭ �������� ������ NamedCircle�� ���� �ʿ� ������ �˰� private: public: ���س��ٰ� �׳� ������ �Ἥ private:�� �ڵ��ν� �Ʊ� ����
	int radius = 0;
	string name = "";
	cout << "5 ���� ���� �������� ���� �̸��� �Է��ϼ���" << endl;
	for (int i = 0; i < 5; i++) {
		cout << i+1 << ">> ";
		cin >> radius;
		cin >> name;
		pizza[i].set(radius, name);
	}
	int biggest = 0;
	for (int i = 0; i < 4; i++) {
		if (pizza[i].getArea() < pizza[i + 1].getArea())
			biggest = i+1;
	}
	cout << "���� ������ ū ���ڴ� " << pizza[biggest].getName() << "�Դϴ�" << endl;
}