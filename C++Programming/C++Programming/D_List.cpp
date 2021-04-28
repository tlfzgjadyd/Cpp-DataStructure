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
int List::getItem(int index) {//리스트의 특정 위치에 있는 값을 가져오는 int getItem(int index) 함수 작성  ( index가 범위를 벗어날경우 -99999 반환 )
        if (index < size && index < itemCount&&items[index] != NULL)
            return items[index];
        else
            return -99999;
    }
void List::addItem(int itm) {//리스트의 맨끝에 값을 추가하는 void addItem(int itm) 함수 작성
        if (itemCount <size)
        {
            items[itemCount] = itm;
            itemCount++;
        }
        else {
            cout << "리스트가 꽉차서 추가할 수 없습니다" << endl;
        }
    }
void List::insertItem(int index, int itm) {// 리스트의 특정 위치에 값을 추가하는 void insertItem(int index, int itm) 함수 작성
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
            cout << "리스트가 꽉차서 추가할 수 없습니다" << endl;
        }
    }
int List::removeAt(int index) {//리스트의 특정 위치에 있는 값을 삭제하는 int removeAt(int index) 함수 작성 ( 성공시 삭제된 값이 반환, 실패시(인덱스오류) -99999 반환)
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
int List::removeItem(int itm) {//리스트에 있는 특정 값을 찾아서 삭제하는 int removeItem(int itm) 함수 작성 (성공시 해당값의 위치 반환, 실패시(인덱스오류) -99999 반환)
                            // ※리스트 맨처음부터 시작하여 최초로 일치하는 곳의 값을 삭제
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
void List::concat(List& list) {//리스트의 접합 연산을 수행하는 concat(List& list) 함수 구현 ( 2개의 리스트를 연결  - 자기자신과 파라미터로 전달된 리스트 )
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
void List::print() {//리스트의 모든 값을 출력하는 print() 함수 구현
        if (itemCount > 0)
        {
            cout << "리스트 출력 : ";
            for (int i = 0; i < itemCount; i++) {
                cout << items[i] << " ";
            }
            cout << endl;
        }
        else
            cout << "내용물이 없습니다" << endl;
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
int OrderedList::getItem(int index) {//리스트의 특정 위치에 있는 값을 가져오는 int getItem(int index) 함수 작성  ( index가 범위를 벗어날경우 -99999 반환 )
        if (index < size && index < itemCount && items[index] != NULL)
            return items[index];
        else
            return -99999;
    }
void OrderedList::addItem(int itm) {//리스트에 값을 추가하는 void addItem(int itm) 함수 작성 --> 값추가후 정렬된 상태 유지
        if (itemCount < size)
        {
            //위치찾는 사전작업
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
            cout << "리스트가 꽉차서 추가할 수 없습니다" << endl;
        }
}
//교수님 예시 추가한 버전 공간 부족시 공간 늘리기
/*void OrderedList::addItem(int itm)//리스트에 값을 추가하는 함수
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
int OrderedList::removeAt(int index) {//리스트의 특정 위치에 있는 값을 삭제하는 int removeAt(int index) 함수 작성 ( 성공시 삭제된 값이 반환, 실패시(인덱스오류) -99999 반환)
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
int OrderedList::removeItem(int itm) {//리스트에 있는 특정 값을 찾아서 삭제하는 int removeItem(int itm) 함수 작성 (성공시 해당값의 위치 반환, 실패시(인덱스오류) -99999 반환)
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
void OrderedList::concat(OrderedList& olist) {//리스트의 접합 연산을 수행하는 void concat(OrderedList& olist) 함수 구현 ( 2개의 리스트를 연결 - 연결후에도 정렬된 상태 유지 - 자기자신과 파라미터로 전달된 리스트 )
        //반환형이 void로 명시되어 있어 함수를 호출한 주체에 전달인자로 받은 리스트를 이어붙이는 방향으로 구현했습니다.
    int newSize = this->itemCount + olist.itemCount;
    OrderedList newList(newSize);//새로운 OrderedList형을 만들어서 편집한 후 this의 모든걸 이 새로운 OrderedList의 것으로 교체
    for (int i = 0; i < this->itemCount; i++)
    {
        newList.addItem(this->items[i]);
    }
    for (int i = 0; i < olist.itemCount; i++) {
        newList.addItem(olist.items[i]);
    }
    this->size = newList.size;
    delete[] items;
    this->items = new int[size];//다시 공간할당 해준다
    this->itemCount = 0;
    for (int i = 0; i < newList.itemCount; i++) {
        this->addItem(newList.items[i]);
    }
}
void OrderedList::print() {//리스트의 모든 값을 출력하는 print() 함수 구현
        if (itemCount > 0)
        {
            cout << "리스트 출력 : ";
            for (int i = 0; i < itemCount; i++) {
                cout << items[i] << " ";
            }
            cout << endl;
        }
        else
            cout << "내용물이 없습니다" << endl;
    }

int main(void) {
        cout << "List 실험 시작" << endl;
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

       cout <<endl<<"List의 concat실험 시작" << endl;
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
    cout << "OrderedList 실험 시작" << endl;
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

    cout <<endl<< "OrderedList의 concat실험 시작" << endl;
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