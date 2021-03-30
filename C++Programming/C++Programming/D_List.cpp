#include <iostream>
using namespace std;
class List { //(정렬되지 않은 ) 리스트
private:
    int* items;
    int itemCount;
    int size;
public:
    List() {
        this->size = 5;
    }
    ~List() {}
    /*      - 리스트의 특정 위치에 있는 값을 가져오는 int getItem(int index) 함수 작성  ( index가 범위를 벗어날경우 -99999 반환 )
     -  리스트의 맨끝에 값을 추가하는 void addItem(int itm) 함수 작성
     -  리스트의 특정 위치에 값을 추가하는 void insertItem(int index, int itm) 함수 작성
     -  리스트의 특정 위치에 있는 값을 삭제하는 int removeAt(int index) 함수 작성 ( 성공시 삭제된 값이 반환, 실패시(인덱스오류) -99999 반환)
     -  리스트에 있는 특정 값을 찾아서 삭제하는 int removeItem(int itm) 함수 작성 (성공시 해당값의 위치 반환, 실패시(인덱스오류) -99999 반환)

         ※리스트 맨처음부터 시작하여 최초로 일치하는 곳의 값을 삭제
     -  리스트의 접합 연산을 수행하는 concat(List& list) 함수 구현 ( 2개의 리스트를 연결  - 자기자신과 파라미터로 전달된 리스트 )
     -  리스트의 모든 값을 출력하는 print() 함수 구현 */
};
class OrderedList { //(정렬되어 있는) 리스트
private:
    int* items;
    int itemCount;
    int size;
public:
    OrderedList() {
        this->size = 5;
    }
    ~OrderedList() {}
    /* - 리스트의 특정 위치에 있는 값을 가져오는 int getItem(int index) 함수 작성  ( index가 범위를 벗어날경우 -99999 반환 )
     - 리스트에 값을 추가하는 void addItem(int itm) 함수 작성 --> 값추가후 정렬된 상태 유지
     - 리스트의 특정 위치에 있는 값을 삭제하는 int removeAt(int index) 함수 작성 ( 성공시 삭제된 값이 반환, 실패시(인덱스오류) -99999 반환)

     - 리스트에 있는 특정 값을 찾아서 삭제하는 int removeItem(int itm) 함수 작성 ( 성공시 해당값의 위치 반환, 실패시(인덱스오류) -99999 반환)

         ※리스트 맨처음부터 시작하여 최초로 일치하는 곳의 값을 삭제
    -  리스트의 접합 연산을 수행하는 void concat(OrderedList& olist) 함수 구현 ( 2개의 리스트를 연결 - 연결후에도 정렬된 상태 유지 - 자기자신과 파라미터로 전달된 리스트 )
     -  리스트의 모든 값을 출력하는 print() 함수 구현 */
};
int main(void) {
    /*위에서 구현된 기능의 동작을 확인할수 있는 main() 함수를 작성
    - 리스트에 최소 20 개 정도의 숫자를 삽입 ( 중복허용 ) 후 각각의 기능 테스트*/
}