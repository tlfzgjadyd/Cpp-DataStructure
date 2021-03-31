#pragma once
class OrderedList { //(정렬되어 있는) 리스트
private:
    int* items;
    int itemCount;
    int size;
public:
    OrderedList();
    OrderedList(int size);
    ~OrderedList();
    int getItem(int index);
    void addItem(int itm);
    int removeAt(int index);
    int removeItem(int itm);
    void concat(OrderedList& olist);
    void print();
};