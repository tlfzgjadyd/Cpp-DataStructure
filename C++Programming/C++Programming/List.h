#pragma once
#include <iostream>

using namespace std;
template <typename T>
class List { //(���ĵ��� ���� ) ����Ʈ
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
int List<T>::getItem(int index) {//����Ʈ�� Ư�� ��ġ�� �ִ� ���� �������� int getItem(int index) �Լ� �ۼ�  ( index�� ������ ������ -99999 ��ȯ )
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
            return -1;//�����ڴ� ���ڴ�� -1�� ������
    }
    else
        return -99999;
}
template <typename T>
void List<T>::addItem(T itm) {//����Ʈ�� �ǳ��� ���� �߰��ϴ� void addItem(int itm) �Լ� �ۼ�
    if (itemCount < size)
    {
        items[itemCount] = itm;
        itemCount++;
    }
    else {
        cout << "����Ʈ�� ������ �߰��� �� �����ϴ�" << endl;
    }
}
template <typename T>
void List<T>::insertItem(int index, T itm) {// ����Ʈ�� Ư�� ��ġ�� ���� �߰��ϴ� void insertItem(int index, int itm) �Լ� �ۼ�
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
        cout << "����Ʈ�� ������ �߰��� �� �����ϴ�" << endl;
    }
}
template <typename T>
int List<T>::removeAt(int index) {//����Ʈ�� Ư�� ��ġ�� �ִ� ���� �����ϴ� int removeAt(int index) �Լ� �ۼ� ( ������ ������ ���� ��ȯ, ���н�(�ε�������) -99999 ��ȯ)
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
int List<T>::removeItem(T itm) {//����Ʈ�� �ִ� Ư�� ���� ã�Ƽ� �����ϴ� int removeItem(int itm) �Լ� �ۼ� (������ �ش簪�� ��ġ ��ȯ, ���н�(�ε�������) -99999 ��ȯ)
                            // �ظ���Ʈ ��ó������ �����Ͽ� ���ʷ� ��ġ�ϴ� ���� ���� ����
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
void List<T>::concat(List& list) {//����Ʈ�� ���� ������ �����ϴ� concat(List& list) �Լ� ���� ( 2���� ����Ʈ�� ����  - �ڱ��ڽŰ� �Ķ���ͷ� ���޵� ����Ʈ )
        //��ȯ���� ��õǾ� ���� ������ void�� �����Ͽ� �Լ��� ȣ���� ��ü�� �������ڷ� ���� ����Ʈ�� �̾���̴� �������� �����߽��ϴ�.
    int newSize = this->itemCount + list.itemCount;
    List newList(newSize);//���ο� List���� ���� ������ �� this�� ���� �� ���ο� List�� ������ ��ü
    for (int i = 0; i < this->itemCount; i++)
    {
        newList.addItem(this->items[i]);
    }
    for (int i = 0; i < list.itemCount; i++) {
        newList.addItem(list.items[i]);
    }
    this->size = newList.size;
    delete[] items;
    this->items = new int[size];//�ٽ� �����Ҵ� ���ش�
    this->itemCount = 0;
    for (int i = 0; i < newList.itemCount; i++) {
        this->addItem(newList.items[i]);
    }
}
template <typename T>
void List<T>::print() {//����Ʈ�� ��� ���� ����ϴ� print() �Լ� ����
    if (itemCount > 0)
    {
        cout << "����Ʈ ��� : ";
        for (int i = 0; i < itemCount; i++) {
            cout << <items[i] << " ";
        }
        cout << endl;
    }
    else
        cout << "���빰�� �����ϴ�" << endl;
}
template <typename T>
int List<T>::getItemCount() {
    return itemCount;
}