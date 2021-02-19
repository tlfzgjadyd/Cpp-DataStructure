#include <iostream>
using namespace std;
class Buffer {
private:
	string text;
public:
	Buffer(string text) { this->text = text; }
	void add(string next) { text += next; }
	void print() { cout << text << endl; }
};
Buffer& append(Buffer& buf, string str); //�������� ������ �Լ� ����� �ؿ��ٰ� class Buffer ���Ǻ� �Ἥ ���˾ƸԾ��� ���� �׷��Ƿ� �Լ�����ο� Ŭ���� ���Ÿ� Ŭ������ ���� ���� �־ߵ�

int main(void) {
	Buffer buf("Hello");
	Buffer& temp = append(buf, "Guys");//buf�� ���ڿ��� "Guys" ������
	temp.print();
	buf.print();
}
Buffer& append(Buffer& buf, string str) { //���� ���������� �ڱ��ڽ� ������ �����ϴ� ���̾�� *this�� ���������� ���⼱ �Լ��� �ڱ��ڽ��� �ƴϹǷ�
	buf.add(str);
	return buf;								//�׳� ������� �ָ� �� �ֳĸ� �׳� Buffer buf �������� ������ �������� ȣ��� �� ���� �ȵǱ⿡ Buffer&�� ������ �޾ұ� ����
}