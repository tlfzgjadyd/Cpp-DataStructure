#include "String.h"
int main()
{
	String a((char*)"hello", 5);
	String b((char*)"world", 5);
	String c=a;
	String d((char*)"",0);
	cout << "------------------" << endl;
	cout << "Concat test"<<endl;
	c=a.Concat(b);
	cout << "result : "; c.print();
	cout << "------------------" << endl << endl;

	cout << "------------------" << endl;
	cout << "operator= test" << endl;
	c = a;
	cout << "result : "; c.print();
	cout << "------------------" << endl << endl;

	
	cout << "------------------" << endl;
	cout << "operator== test" << endl;
	bool res1 = (a == b);
	bool res2 = (a == a);
	cout << "result : "<<res1<<" "<<res2<<endl;
	cout << "------------------" << endl<<endl;

	cout << "------------------" << endl;
	cout << "operator! test"<<endl;
	cout << "a : "<< !a << endl;
	cout << "d : "<< !d << endl;
	cout << "------------------" << endl;

	cout << "------------------" << endl;
	cout << "Length test" << endl;
	cout << a.Length() << endl;
	cout << "------------------" << endl<<endl;

	cout << "------------------" << endl;
	cout << "Substr test"<<endl;
	String sub=(String &)b.Substr(0, 2);
	sub.print();
	cout << "------------------" << endl << endl;

	cout << "------------------" << endl;
	cout << "find test"<<endl;
	String pat((char*)"or", 2);
	cout <<"try with a : "<< a.Find(pat) << endl;
	cout << "try with b : " << b.Find(pat) << endl;
	cout << "------------------" << endl << endl;

	cout << "------------------" << endl;
	cout << "print test" << endl;
	a.print();
	cout << "------------------" << endl<<endl;
	return 0;
}