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
		cout << getSourceString() << "�� " << getDestString() << "�� �ٲߴϴ�. ";
		cout << getSourceString() << "�� �Է��ϼ���>> ";
		cin >> src;
		cout << "��ȯ��� : " << convert(src) << getDestString() << endl;
	}
};
class KmToMile : public Converter {
public:
	KmToMile(double ratio) :Converter(ratio) {
		;
	}
	double convert(double src) {	//virtual�� ���ִ� �θ�Ŭ������ �Լ��� ������ override Ű���� ���� �ۼ��ϸ� �ȴ�
		return (double)(src / ratio);
	}
	string getSourceString() {
		return "Km";
	}
	string getDestString() {
		return "Mile";
	}
	void run() {
		cout <<getSourceString()<< "�� " <<getDestString()<< "�� �ٲߴϴ�. ";
		cout << "�� �Է��ϼ���>>";
		double num = 0;
		cin >> num;
		cout << "��ȯ ��� : " << convert(num) << getDestString()<<endl;
	}
};
int main(void) {
	KmToMile toMile(1.609344); //1������ 1.609344 km
	toMile.run();
}