#include <iostream>
using namespace std;
class Converter {
protected:
	string src;
	string dest;
	double ratio;
	virtual double convert(double src) = 0; //src�� �ٸ� ������ ��ȯ�Ѵ�
	virtual string getSourceString() = 0; //src ���� ��Ī
	virtual string getDestString() = 0; //dest ���� ��Ī
public:
	Converter(double ratio) { this->ratio = ratio; }
	void run() {
		double src;
		cout<<getSourceString()<<"�� "<<getDestString() << "�� �ٲߴϴ�. ";
		cout << getSourceString() << "�� �Է��ϼ���>> ";
		cin >> src;
		cout << "��ȯ��� : " << convert(src) << getDestString() << endl;
	}
};
class WonToDollar : public Converter{
private:
public:
	WonToDollar(int ratio) :Converter((double)ratio){
		src = "��";
		dest = "�޷�";
	}
	double convert(double src) {
		return src / ratio;
	}
	string getSourceString() {
		return src;
	}
	string getDestString() {
		return dest;
	}
	void run() {
		cout << src << "�� " << dest << "�� �ٲߴϴ�. " << src << "�� �Է��ϼ���>> ";
		int num = 0;
		cin >> num;
		cout << "��ȯ ��� : " << convert(num) << dest << endl;
	}
};
int main() {
	WonToDollar wd(1010); //1�޷��� 1010��
	wd.run();
}