#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Trace {
private:
    static vector<pair<string, string>> debug;
public:
	static void put(string target, string content) { //객체 생성 전에 함수 사용하길 원하고 있으므로 static
		if(debug.size()<=100)
			debug.push_back(pair<string, string>(target, content)); //static에선 static멤버만 사용 가능하므로 private 프로퍼티인 debug에도 static을 붙여야 에러 안남
	}
	static void print(string target) {
		cout << "----- " << target << "태그의 Trace 정보를 출력합니다. -----" << endl;
		for (int i = 0; i < debug.size(); i++) {
			if (debug[i].first == target)
				cout << debug[i].first << ":" << debug[i].second << endl;//pair의 first, second는 함수형식이 아니라 프로퍼티처럼 호출하는 거였지
		}
	}
	static void print() {
		cout << "----- 모든 Trace 정보를 출력합니다. -----" << endl;
		for (int i = 0; i < debug.size(); i++) {
			cout << debug[i].first << ":" << debug[i].second << endl;//pair의 first, second는 함수형식이 아니라 프로퍼티처럼 호출하는 거였지
		}
	}
};
vector<pair<string, string>> Trace::debug;  //이부분이 없으면 에러났음 
//class에서 static으로 사용한 private 프로퍼티의 경우 class정의 아래에 자료형 클래스명::변수명 으로 알려줘야한다
//이부분이 전역변수로 선언하는 부분인데
//클래스 객체를 따로 생성하지 않기 때문에 프로퍼티를 할당할 공간을 만들어줘야 하기 때문이다
//그래서 static 프로퍼티 멤버는 항상 함수 바깥에 전역변수 선언이 필요하다
//안그러면 아래와 같은 에러가 뜬다
/*심각도	코드	설명	프로젝트	파일	줄	비표시 오류(Suppression) 상태
오류	LNK2001	확인할 수 없는 외부 기호 "private: static class std::vector<class std::basic_string<char,struct 
std::char_traits<char>,class std::allocator<char> >,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > > >
Board::board" (?board@Board@@0V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@A)C++Programming
C:\Users\tlfzg\DataStructure-Cpp\C++Programming\C++Programming\I_Board.obj	1	
오류	LNK1120	1개의 확인할 수 없는 외부 참조입니다.	C++Programming	C:\Users\tlfzg\DataStructure-Cpp\C++Programming\x64\Debug\C++Programming.exe	1	
*/

void f() {
	int a, b, c;
	cout << "두 개의 정수를 입력하세요>>";
	cin >> a >> b;
	Trace::put("f()", "정수를 입력 받았음"); //디버깅 정보 저장
	c = a + b;
	Trace::put("f()", "합 계산"); //디버깅 정보 저장
	cout << "합은 " << c << endl;
}
int main(void) {
	Trace::put("main()", "프로그램 시작합니다"); //디버깅 정보 저장
	f();
	Trace::put("main()", "종료"); //put()의 첫 번째 매개변수는 태그이고
									//두 번째 매개변수는 디버깅 정보이다
	Trace::print("f()"); //"f()" 태그를 가진 디버깅 정보를 모두 출력한다.
	Trace::print(); //모든 디버깅 정보를 출력한다.*/
	;
}