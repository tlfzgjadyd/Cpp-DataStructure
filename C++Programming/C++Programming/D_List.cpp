#include <iostream>
#include "D_List.h"
#include "OrderedList.h"
using namespace std;

List::List() {
        this->size = 5;
        this->itemCount = 0;
        this->items = new int[size];
    }
List::List(int size) {
        this->size = size;
        this->itemCount = 0;
        this->items = new int[size];
    }
List::~List() {
        if(items!=NULL)
            delete[] items;
        this->itemCount = 0;
        this->size = 0;
    }
int List::getItem(int index) {//����Ʈ�� Ư�� ��ġ�� �ִ� ���� �������� int getItem(int index) �Լ� �ۼ�  ( index�� ������ ������ -99999 ��ȯ )
        if (index < size && index < itemCount&&items[index] != NULL)
            return items[index];
        else
            return -99999;
    }
void List::addItem(int itm) {//����Ʈ�� �ǳ��� ���� �߰��ϴ� void addItem(int itm) �Լ� �ۼ�
        if (itemCount <size)
        {
            items[itemCount] = itm;
            itemCount++;
        }
        else {
            cout << "����Ʈ�� ������ �߰��� �� �����ϴ�" << endl;
        }
    }
void List::insertItem(int index, int itm) {// ����Ʈ�� Ư�� ��ġ�� ���� �߰��ϴ� void insertItem(int index, int itm) �Լ� �ۼ�
        if (itemCount < size)
        {
            itemCount++;
            for (int i = itemCount-2; i >=index; i--)
            {
                items[i + 1] = items[i];
            }
            items[index] = itm;

        }
        else {
            cout << "����Ʈ�� ������ �߰��� �� �����ϴ�" << endl;
        }
    }
int List::removeAt(int index) {//����Ʈ�� Ư�� ��ġ�� �ִ� ���� �����ϴ� int removeAt(int index) �Լ� �ۼ� ( ������ ������ ���� ��ȯ, ���н�(�ε�������) -99999 ��ȯ)
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
int List::removeItem(int itm) {//����Ʈ�� �ִ� Ư�� ���� ã�Ƽ� �����ϴ� int removeItem(int itm) �Լ� �ۼ� (������ �ش簪�� ��ġ ��ȯ, ���н�(�ε�������) -99999 ��ȯ)
                            // �ظ���Ʈ ��ó������ �����Ͽ� ���ʷ� ��ġ�ϴ� ���� ���� ����
        for (int i = 0; i < itemCount; i++) {
            if (itm == items[i])
            {
                for (int j = i; j < itemCount-1; j++) {
                    items[j] = items[j + 1];
                }
                itemCount--;
                return i;
            }
                
        }
        return -99999;
    }
void List::concat(List& list) {//����Ʈ�� ���� ������ �����ϴ� concat(List& list) �Լ� ���� ( 2���� ����Ʈ�� ����  - �ڱ��ڽŰ� �Ķ���ͷ� ���޵� ����Ʈ )
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
void List::print() {//����Ʈ�� ��� ���� ����ϴ� print() �Լ� ����
        if (itemCount > 0)
        {
            cout << "����Ʈ ��� : ";
            for (int i = 0; i < itemCount; i++) {
                cout << items[i] << " ";
            }
            cout << endl;
        }
        else
            cout << "���빰�� �����ϴ�" << endl;
    }

OrderedList::OrderedList() {
        this->size = 5;
        this->itemCount = 0;
        this->items = new int[size];
    }
OrderedList::OrderedList(int size) {
        this->size = size;
        this->itemCount = 0;
        this->items = new int[size];
    }
OrderedList::~OrderedList() {
        if (items != NULL)
            delete[] items;
        this->itemCount = 0;
        this->size = 0;
    }
int OrderedList::getItem(int index) {//����Ʈ�� Ư�� ��ġ�� �ִ� ���� �������� int getItem(int index) �Լ� �ۼ�  ( index�� ������ ������ -99999 ��ȯ )
        if (index < size && index < itemCount && items[index] != NULL)
            return items[index];
        else
            return -99999;
    }
void OrderedList::addItem(int itm) {//����Ʈ�� ���� �߰��ϴ� void addItem(int itm) �Լ� �ۼ� --> ���߰��� ���ĵ� ���� ����
        if (itemCount < size)
        {
            //��ġã�� �����۾�
            int index = itemCount;
            for (int i = 0; i < itemCount; i++) {
                if (itm <= items[i])
                {
                    index = i;
                    break;
                }
            }
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
//������ ���� �߰��� ���� ���� ������ ���� �ø���
/*void OrderedList::addItem(int itm)//����Ʈ�� ���� �߰��ϴ� �Լ�
{
    if (itemCount >= size)
    {
        int newSize = size * 2;
        int* newItem = new int[newSize];
        for (int i = 0; i < itemCount; i++)
            newItem[i] = items[i];
        delete[]items;
        items = new int[newSize];
        for (int j = 0; j < itemCount; j++)
            items[j] = newItem[j];
        size = newSize;
    }

    int pos;
    for (pos = 0; pos < itemCount; pos++) {
        if (items[pos] > itm)
            break;
    }
    itemCount++;
    for (int i = itemCount - 1; i > pos; i--)
        items[i] = items[i - 1];
    items[pos] = itm;
}*/
int OrderedList::removeAt(int index) {//����Ʈ�� Ư�� ��ġ�� �ִ� ���� �����ϴ� int removeAt(int index) �Լ� �ۼ� ( ������ ������ ���� ��ȯ, ���н�(�ε�������) -99999 ��ȯ)
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
int OrderedList::removeItem(int itm) {//����Ʈ�� �ִ� Ư�� ���� ã�Ƽ� �����ϴ� int removeItem(int itm) �Լ� �ۼ� (������ �ش簪�� ��ġ ��ȯ, ���н�(�ε�������) -99999 ��ȯ)
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
void OrderedList::concat(OrderedList& olist) {//����Ʈ�� ���� ������ �����ϴ� void concat(OrderedList& olist) �Լ� ���� ( 2���� ����Ʈ�� ���� - �����Ŀ��� ���ĵ� ���� ���� - �ڱ��ڽŰ� �Ķ���ͷ� ���޵� ����Ʈ )
        //��ȯ���� void�� ��õǾ� �־� �Լ��� ȣ���� ��ü�� �������ڷ� ���� ����Ʈ�� �̾���̴� �������� �����߽��ϴ�.
    int newSize = this->itemCount + olist.itemCount;
    OrderedList newList(newSize);//���ο� OrderedList���� ���� ������ �� this�� ���� �� ���ο� OrderedList�� ������ ��ü
    for (int i = 0; i < this->itemCount; i++)
    {
        newList.addItem(this->items[i]);
    }
    for (int i = 0; i < olist.itemCount; i++) {
        newList.addItem(olist.items[i]);
    }
    this->size = newList.size;
    delete[] items;
    this->items = new int[size];//�ٽ� �����Ҵ� ���ش�
    this->itemCount = 0;
    for (int i = 0; i < newList.itemCount; i++) {
        this->addItem(newList.items[i]);
    }
}
void OrderedList::print() {//����Ʈ�� ��� ���� ����ϴ� print() �Լ� ����
        if (itemCount > 0)
        {
            cout << "����Ʈ ��� : ";
            for (int i = 0; i < itemCount; i++) {
                cout << items[i] << " ";
            }
            cout << endl;
        }
        else
            cout << "���빰�� �����ϴ�" << endl;
    }

int main(void) {
        cout << "List ���� ����" << endl;
        List list1(25);
        list1.addItem(1);
        list1.addItem(2);
        list1.addItem(3);
        list1.addItem(4);
        list1.addItem(5);
        list1.addItem(6);
        list1.addItem(7);
        list1.addItem(8);
        list1.addItem(9);
        list1.addItem(10);
        list1.addItem(11);
        list1.addItem(12);
        list1.addItem(13);
        list1.addItem(14);
        list1.addItem(15);
        list1.addItem(16);
        list1.addItem(17);
        list1.addItem(18);
        list1.addItem(19);
        list1.addItem(20);
        list1.print();
        list1.insertItem(2, 100);
        list1.print();
        cout << list1.getItem(2) << endl;
        cout << list1.getItem(1000) << endl;
        list1.addItem(5);
        list1.print();
        list1.addItem(6);
        list1.print();
        list1.addItem(7);
        list1.print();
        list1.addItem(8);
        list1.print();
        list1.addItem(9);
        list1.print();
        list1.insertItem(1, 10);
        list1.print();
        cout << list1.removeAt(0) << endl;
        list1.print();
        cout << list1.removeAt(80) << endl;
        list1.print();
        cout << list1.removeItem(100) << endl;
        list1.print();
        cout << list1.removeItem(1234) << endl;
        list1.print();

       cout <<endl<<"List�� concat���� ����" << endl;
        List list11(10);
        list11.addItem(1);
        list11.addItem(2);
        list11.addItem(3);
        list11.addItem(4);
        list11.addItem(5);
        list11.print();
        list1.concat(list11);
        list1.print();
    
    cout << endl<<"//////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "OrderedList ���� ����" << endl;
    OrderedList list2(25);
    list2.addItem(1);
    list2.addItem(2);
    list2.addItem(3);
    list2.addItem(4);
    list2.addItem(11);
    list2.addItem(12);
    list2.addItem(13);
    list2.addItem(14);
    list2.addItem(15);
    list2.addItem(16);
    list2.addItem(5);
    list2.addItem(6);
    list2.addItem(7);
    list2.addItem(8);
    list2.addItem(9);
    list2.addItem(10);
    list2.addItem(17);
    list2.addItem(18);
    list2.addItem(19);
    list2.addItem(20);
    list2.print();
    list2.addItem(100);
    list2.print();
    cout << list2.getItem(2) << endl;
    cout << list2.getItem(1000) << endl;
    list2.addItem(5);
    list2.print();
    list2.addItem(6);
    list2.print();
    list2.addItem(7);
    list2.print();
    list2.addItem(8);
    list2.print();
    list2.addItem(9);
    list2.print();
    cout << list2.removeAt(0) << endl;
    list2.print();
    cout << list2.removeAt(80) << endl;
    list2.print();
    cout << list2.removeItem(100) << endl;
    list2.print();
    cout << list2.removeItem(1234) << endl;
    list2.print();

    cout <<endl<< "OrderedList�� concat���� ����" << endl;
    OrderedList list22(10);
    list22.addItem(1);
    list22.addItem(2);
    list22.addItem(3);
    list22.addItem(4);
    list22.addItem(5);
    list22.print();
    list2.concat(list22);
    list2.print();
    return 0;
}