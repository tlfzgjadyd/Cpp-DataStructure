#pragma once
#include <iostream>

using namespace std;
template <typename T>
class List { //(정렬되지 않은 ) 리스트
private:
    T* items;
    int itemCount;
    int size;
public:
    List();
    List(int size);
    ~List();
    int getItem(int index);
    void addItem(T itm);
    void insertItem(int index, T itm);
    int removeAt(int index);
    int removeItem(T itm);
    void concat(List& list);
    void print();
    int getItemCount();
};
template <typename T>
List<T>::List() :List(5){
    ;
}
template <typename T>
List<T>::List(int size) {
    this->size = size;
    this->itemCount = 0;
    this->items = new T[size];
}
template <typename T>
List<T>::~List() {
    if (items != NULL)
        delete[] items;
    this->itemCount = 0;
    this->size = 0;
}
template <typename T>
int List<T>::getItem(int index) {//리스트의 특정 위치에 있는 값을 가져오는 int getItem(int index) 함수 작성  ( index가 범위를 벗어날경우 -99999 반환 )
    if (index < itemCount)
    {
        bool flag = true;
        char* ptr = items[index].getBuffer();
        for (int i = 0; i < items[index].Length(); i++)
        {
            if (!isdigit(ptr[i]))
                flag = false;
        }
        if (flag)
        {
            cout << (items[index].Strtoi()) << endl;
            return (items[index].Strtoi());
        }
        else
            return -1;//연산자는 숫자대신 -1을 내보냄
    }
    else
        return -99999;
}
template <typename T>
void List<T>::addItem(T itm) {//리스트의 맨끝에 값을 추가하는 void addItem(int itm) 함수 작성
    if (itemCount < size)
    {
        items[itemCount] = itm;
        itemCount++;
    }
    else {
        cout << "리스트가 꽉차서 추가할 수 없습니다" << endl;
    }
}
template <typename T>
void List<T>::insertItem(int index, T itm) {// 리스트의 특정 위치에 값을 추가하는 void insertItem(int index, int itm) 함수 작성
    if (itemCount < size)
    {
        itemCount++;
        for (int i = itemCount - 2; i >= index; i--)
        {
            items[i + 1] = items[i];
        }
        items[index] = itm;

    }
    else {
        cout << "리스트가 꽉차서 추가할 수 없습니다" << endl;
    }
}
template <typename T>
int List<T>::removeAt(int index) {//리스트의 특정 위치에 있는 값을 삭제하는 int removeAt(int index) 함수 작성 ( 성공시 삭제된 값이 반환, 실패시(인덱스오류) -99999 반환)
    if (index < size && index < itemCount && items[index] != NULL)
    {
        int ret = items[index];
        for (int i = index; i < itemCount - 1; i++) {
            items[i] = items[i + 1];
        }
        itemCount--;
        return ret;
    }
    else {
        return -99999;
    }
}
template <typename T>
int List<T>::removeItem(T itm) {//리스트에 있는 특정 값을 찾아서 삭제하는 int removeItem(int itm) 함수 작성 (성공시 해당값의 위치 반환, 실패시(인덱스오류) -99999 반환)
                            // ※리스트 맨처음부터 시작하여 최초로 일치하는 곳의 값을 삭제
    for (int i = 0; i < itemCount; i++) {
        if (itm == items[i])
        {
            for (int j = i; j < itemCount - 1; j++) {
                items[j] = items[j + 1];
            }
            itemCount--;
            return i;
        }

    }
    return -99999;
}
template <typename T>
void List<T>::concat(List& list) {//리스트의 접합 연산을 수행하는 concat(List& list) 함수 구현 ( 2개의 리스트를 연결  - 자기자신과 파라미터로 전달된 리스트 )
        //반환형이 명시되어 있지 않지만 void로 지정하여 함수를 호출한 주체에 전달인자로 받은 리스트를 이어붙이는 방향으로 구현했습니다.
    int newSize = this->itemCount + list.itemCount;
    List newList(newSize);//새로운 List형을 만들어서 편집한 후 this의 모든걸 이 새로운 List의 것으로 교체
    for (int i = 0; i < this->itemCount; i++)
    {
        newList.addItem(this->items[i]);
    }
    for (int i = 0; i < list.itemCount; i++) {
        newList.addItem(list.items[i]);
    }
    this->size = newList.size;
    delete[] items;
    this->items = new int[size];//다시 공간할당 해준다
    this->itemCount = 0;
    for (int i = 0; i < newList.itemCount; i++) {
        this->addItem(newList.items[i]);
    }
}
template <typename T>
void List<T>::print() {//리스트의 모든 값을 출력하는 print() 함수 구현
    if (itemCount > 0)
    {
        cout << "리스트 출력 : ";
        for (int i = 0; i < itemCount; i++) {
            cout << <items[i] << " ";
        }
        cout << endl;
    }
    else
        cout << "내용물이 없습니다" << endl;
}
template <typename T>
int List<T>::getItemCount() {
    return itemCount;
}