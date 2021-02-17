#include <iostream>
using namespace std;
string combine(string str1, string str2, string str3);
int main() {
	cout<< combine("I love you", "very much", "");
}
string combine(string str1, string str2, string str3) {
	str3 += str1;
	str3 += " ";
	str3 += str2;
	return str3;
}