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
		cout<<getSourceString()<<"을 "<<getDestString() << "로 바꿉니다. ";
		cout << getSourceString() << "을 입력하세요>> ";
		cin >> src;
		cout << "변환결과 : " << convert(src) << getDestString() << endl;
	}
};
class WonToDollar : public Converter{
private:
public:
	WonToDollar(int ratio) :Converter((double)ratio){
		src = "원";
		dest = "달러";
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
		cout << src << "을 " << dest << "로 바꿉니다. " << src << "을 입력하세요>> ";
		int num = 0;
		cin >> num;
		cout << "변환 결과 : " << convert(num) << dest << endl;
	}
};
int main() {
	WonToDollar wd(1010); //1달러에 1010원
	wd.run();
}