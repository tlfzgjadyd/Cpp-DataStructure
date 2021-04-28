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
    if (!c.setExpression(expr))
    {
        String postfix = c.getPostFix();
        try {
            cout << "후위표기식 : " << postfix << "결과값 : " << c.getValue() << endl;

        }
        catch (const char* errmsg) {
            cout << errmsg << endl;
        }
    }
    return 0;
}