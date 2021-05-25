#include "Calculator.h"
/*수식을 후위표기식으로 변경하고, 계산하는 Calculator 클래스 작성
 (3+5)/10 을 List<String>으로 변경 :    
 tokens[0] = "("
       tokens[1] = "3"
       tokens[2] = "+"
       tokens[3] = "5" ......
*/

int main(void) {
    char expr[1000];
    Calculator c;
    cout << "수식을 입력하시오 : ";
    cin.getline(expr, 1000);
    //수식세팅, 후위로 변환, 계산까지 완료하는 함수
    int n1 = 1;
    int n2 = 2;
    cout << (char)(n2 - n1 + '0');
    if (!c.setExpression(expr))
    {
        /*
        //여기서 변환하는게 아니라 이미 변환돼있는 후위를 가져옴
        String postfix = c.getPostFix();
        try {//여기서 결과값 계산하는게 아니라 이미 계산돼있는 결과값을 가져옴
            cout << "후위표기식 : " << postfix << "결과값 : " << c.getValue() << endl;
        }
        catch (const char* errmsg) {
            cout << errmsg << endl;
        }*/
    }
    return 0;
}