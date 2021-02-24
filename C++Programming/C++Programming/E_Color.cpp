#include <iostream>
using namespace std;
class Color {
private:
	int r;
	int g;
	int b;
public:
	Color(){
		this->r = 0;
		this->g = 0;
		this->b = 0;
	}
	Color(int r, int g, int b) {
		this->r = r;
		this->g = g;
		this->b = b;
	}
	void show() {
		cout << r << " " << g << " " << b << endl;
	}
	bool operator ==(const Color& c) {//���� ������ ������� �ͼ��������� ������ ��ü�� �������� ����� const�� ��鿩����
		if (this->r == c.r && this->g == c.g && this->b == c.b)//==�� �����ڴ� c==fuchsia�� Color���� ȣ���ϰ� �������ڷ� Color �ϳ� �����Ƿ�
			return true;										//���� ������ �Ȼ��� ����Լ��� ��������
		else
			return false;
	}
	friend Color operator+(const Color& c1, const Color& c2);//���� ������ ������� �ͼ��������� ������ ��ü�� �������� ����� const�� ��鿩����
};
Color operator+(const Color& c1, const Color& c2) { //�̹� ������ �����ε��� ������ �⺻�����ڷ� ���� c�� ���߿� a+b ���Ѱ����� �ٲٴ� ����̾���
	int r = c1.r + c2.r;							//�׷��� ColorŸ���� ȣ���ϰ� �������ڷ� ColorŸ�� 2���� �޾ƾ��ϴ� ��Ȳ
	int g = c1.g + c2.g;							//�ϴ� c=red+blue�� �س����� red+blud ������ ����δ� ColorŸ���� ���ߵ�
	int b = c1.b + c2.b;							//���ó�� Color&�� �����Ϸ��� �غ����� �������� *�� �޾ƺ����� ��������
	return Color(r, g, b);							//��¥�� c�� �Ϲ� Color���ٵ� ���� ����� �Ϲ� Color���� ���� �ʳ� ������ �����
}													//�׷��� �ƿ� c1, c2�� ������ �ǵ帮�� �ʰ� ���ο� ���� ����� �����Ҷ� �� Color ���� �Ϲ� Color�� �����ߴ�
int main(void) {									//�Ƹ� ���⼭ ���������� �ȵǴ� ������ �Լ� ������ ���� ���� Color��ü�� �Լ� ����� �Բ� �޸𸮿��� ������� �����ϰ���
	Color red(255, 0, 0), blue(0, 0, 255), c;
	c = red + blue;
	c.show(); //�� �� ���
	Color fuchsia(255, 0, 255); 
	if (c == fuchsia)
		cout << "����� ����";
	else
		cout << "����� �ƴ�";
}