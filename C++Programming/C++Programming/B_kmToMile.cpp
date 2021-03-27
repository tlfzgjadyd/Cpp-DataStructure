#include <iostream>
using namespace std;
class Converter {
protected:
	string src;
	string dest;
	double ratio;
	virtual double convert(double src) = 0; //src를 다른 단위로 변환한다
	virtual string getSourceString() = 0; //src 단위 명칭
	virtual string getDestString() = 0; //dest 단위 명칭
public:
	Converter(double ratio) { this->ratio = ratio; }
	void run() {
		double src;
		cout << getSourceString() << "을 " << getDestString() << "로 바꿉니다. ";
		cout << getSourceString() << "을 입력하세요>> ";
		cin >> src;
		cout << "변환결과 : " << convert(src) << getDestString() << endl;
	}
};
class KmToMile : public Converter {
public:
	KmToMile(double ratio) :Converter(ratio) {
		;
	}
	double convert(double src) {	//virtual로 돼있는 부모클래스의 함수는 별도의 override 키워드 없이 작성하면 된다
		return (double)(src / ratio);
	}
	string getSourceString() {
		return "Km";
	}
	string getDestString() {
		return "Mile";
	}
	void run() {
		cout <<getSourceString()<< "을 " <<getDestString()<< "로 바꿉니다. ";
		cout << "을 입력하세요>>";
		double num = 0;
		cin >> num;
		cout << "변환 결과 : " << convert(num) << getDestString()<<endl;
	}
};
int main(void) {
	KmToMile toMile(1.609344); //1마일은 1.609344 km
	toMile.run();
}