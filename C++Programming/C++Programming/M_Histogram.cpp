#include <iostream>
#include <string>
using namespace std;
class Histogram {
private:
	string text;
public:
	Histogram(string text) {
		this->text = text;
		this->text += "\n";
	}
	void put(string addStr) {
		this->text += addStr;
	}
	void putc(char addChar)
	{
		this->text += addChar;
	}
	void print() {
		cout << text<< endl<<endl;

		string temp = text;
		int count = 0;
		int alphas[26] = { 0 };
		for (int i = 0; i < text.length(); i++) {
			if (isalpha(text[i]))
			{
				count++;
				temp[i]=tolower(text[i]);
				alphas[(int)temp[i] - 97]++;
			}
		}
		cout << "ÃÑ ¾ËÆÄºª ¼ö " << count << endl << endl;
		for (int i = 0; i < 26; i++) {
			cout << (char)(i + 97) << " (" << alphas[i] << ")    : ";
			for(int j=0;j<alphas[i];j++)
				cout << "*";
			cout << endl;
		}
	}
};
int main(void) {
	Histogram elvisHisto("Wise men say, only fools rush in But I can't help, ");
	elvisHisto.put("falling in love with you");
	elvisHisto.putc('-');
	elvisHisto.put("Elvis Presley");
	elvisHisto.print();
}