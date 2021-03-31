#pragma once
class List { //(���ĵ��� ���� ) ����Ʈ
private:
    int* items;
    int itemCount;
    int size;
public:
    List();
    List(int size);
    ~List();
    int getItem(int index);
    void addItem(int itm);
    void insertItem(int index, int itm);
    int removeAt(int index);
    int removeItem(int itm);
    void concat(List& list);
    void print();
};