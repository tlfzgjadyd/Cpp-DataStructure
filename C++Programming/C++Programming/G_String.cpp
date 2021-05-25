#include "String.h"
void String::DeepCopy(const char* src, int size)
{

	if (this->size > 0)
		delete[] buffer;


	if (size <= 0)
	{
		size = 0;
		while (src[size++] != '\0');
	}

	buffer = new char[size];
	this->size = size;

	for (int i = 0; i < this->size; i++)
	{
		if (src[i] == '\0') length = i;
		buffer[i] = src[i];
	}
}
String::String() :String(10) {}
String::String(String& s) : String(s.length + 1)
{
	for (int i = 0; i < s.length; i++)
		buffer[i] = s.buffer[i];
	buffer[s.length] = '\0';
	length = s.length;
}
String::String(int m)
{
	size = m;
	buffer = new char[m];
	length = 0;
}
String::String(char c)
{
	buffer = new char[2];
	buffer[0] = c;
	buffer[1] = '\0';
	size = 2;
	length = 1;
}
String::String(const char* str) : String()
{
	String s(str);
	DeepCopy(str, s.Length());
}
String::String(char* str) : String((const char*)str)
{
	;
}
String::String(const char* init, int m) : String()
{
	DeepCopy(init, m);
}

String::~String()
{
	delete[] buffer;
}
String String::Concat(String t)//t=b;
{
	String result(length + t.length + 1);

	for (int i = 0; i < length; i++)
		result.buffer[i] = buffer[i];
	for (int i = 0; i < t.length; i++)
		result.buffer[length + i] = t.buffer[i];

	result.buffer[length + t.length] = '\0';
	result.length = length + t.length;

	return result;
}
bool String::operator!() {
	if (this->length == 0)
		return true;
	else
		return false;
}
String& String::operator=(const String& s)
{
	delete[] buffer;
	length = s.length;
	size = s.size;
	buffer = new char[length + 1];
	for (int i = 0; i < length; i++)
		buffer[i] = s.buffer[i];
	buffer[length] = '\0';

	return *this;
}
bool String::operator==(String t) {
	int bigger = max(this->length, t.length);
	bool flag = true;
	for (int i = 0; i < bigger; i++) {
		if (buffer[i] != t.buffer[i])
		{
			flag = false;
			break;
		}
	}
	return flag;
}
int String::Length() {
	return length;
}
String String::Substr(int i, int j) {
	String result(j - i + 1);

	for (int index = i; index < j; index++)
		result.buffer[index] = (buffer[index]);
	result.buffer[j - i] = '\0';
	result.length = j - i;

	return result;
}
int String::Find(String pat)
{
	int posP = 0, posS = 0;
	int lengthP = pat.Length(), lengthS = Length();
	while ((posP < lengthP) && (posS < lengthS))
		if (pat.buffer[posP] == buffer[posS]) { //ÀÏÄ¡
			posP++; posS++;
		}
		else
			if (posP == 0)
				posS++;
			else posP = pat.buffer[posP - 1] + 1;
	if (posP < lengthP) return -1;
	else return posS - lengthP;
}
void String::print() {
	for (int i = 0; i < length; i++)
		cout << buffer[i];
	cout << endl;
}
ostream& String::operator<<(ostream& o) {
	for(int i=0;i<length;i++)
		o << buffer[i];
	o << endl;
	return o;
}
char String::getItem(int i) {
	if (buffer[i] != NULL)
		return (char)buffer[i];
	else
		return NULL;
}