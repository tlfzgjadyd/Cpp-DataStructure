#pragma once
#include <algorithm>
using namespace std; //copy, min � �̰� ����� �� �ν��� �ƴϸ� std::copy�ϴ���
template <class T>
void ChangeSize1D(T*& a, const int oldSize, const int newSize)
{
	if (newSize < 0) throw "������� 0���� Ŀ����";

	T* temp = new T[newSize];                                  //���ο� �迭
	int number = (int)std::min(oldSize, newSize);						   // ������ ����
	copy(a, a + number, temp);
	delete[] a;												   //���� �޸� ����
	a = temp;
}