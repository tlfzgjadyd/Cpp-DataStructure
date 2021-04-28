#pragma once
#include <algorithm>
using namespace std; //copy, min 등에 이걸 해줘야 잘 인식함 아니면 std::copy하던가
template <class T>
void ChangeSize1D(T*& a, const int oldSize, const int newSize)
{
	if (newSize < 0) throw "사이즈는 0보다 커야함";

	T* temp = new T[newSize];                                  //새로운 배열
	int number = (int)std::min(oldSize, newSize);						   // 복사할 개수
	copy(a, a + number, temp);
	delete[] a;												   //이전 메모리 해제
	a = temp;
}