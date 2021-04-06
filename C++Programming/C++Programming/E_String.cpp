class String{private:	char* buffer;	int length;	int size;	String();	String(int m);public:	String(char* init, int m); //길이 m인 스트링 init으로 초기화	// Constructor that initializes *this to string init of length m.	bool operator==(String t);//동일한지 비교	// If the string represented by *this equals t, return true;	// else return false.	bool operator!();//공백이면 true 아니면 false	// If *this is empty then return true; else return false.	int Length();//문자수를 반환	// Return the number of characters in *this.	String Concat(String t);//연결된 스트링을 반환	// Return a string whose elements are those of *this followed by those of t.	String Substr(int i, int j);//i~j 사이의 스트링을 반환	// Return a string containing the j characters of *this at positions i, i+1, ...,	// i+j-1 if these are valid positions of *this; otherwise, throw an exception.	int Find(String pat);//스트링에서 pat 스트링을 찾아서 위치 반환, 없으면 -1	// Return an index i such that pat matches the substring of *this that begins	// at position i. Return -1 if pat is either empty or not a substring of *this.	int FastFind(String pat);	void FailureFunction();};int String::Find(String pat){// Return -1 if pat does not occur in *this;// otherwise return the first position in *this, where pat begins.	for (int start = 0; start <= Length() - pat.Length(); start++)	{// check for match beginning at str[start]		int j;		for (j = 0; j < pat.Length() && str[start + j] == pat.str[j]; j++)			if (j == pat.Length()) return start; // match found			// no match at position start	}	return -1; // pat is empty or does not occur in s}int String::FastFind(String pat)
{// Determine if pat is a substring of s.
	int posP = 0, posS = 0;
	int lengthP = pat.Length(), lengthS = Length();
	while ((posP < lengthP) && (posS < lengthS))
		if (pat.str[posP] == str[posS]) { // character match
			posP++; posS++;
		}
		else
			if (posP == 0)
				posS++;
			else posP = pat.f[posP - 1] + 1;
	if (posP < lengthP) return -1;
	else return posS - lengthP;
}
void String::FailureFunction()
{// Compute the failure function for the pattern *this.
	int lengthP = Length();
	f[0] = -1;
	for (int j = 1; j < lengthP; j++)  // compute f[j]
	{
		int i = f[j - 1];
		while ((*(str + j) != *(str + i + 1)) && (i >= 0)) i = f[i];
		if (*(str + j) == *(str + i + 1))
			f[j] = i + 1;
		else f[j] = -1;
	}
}