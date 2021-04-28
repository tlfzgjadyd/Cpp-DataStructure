#include "Calculator.h"
/*������ ����ǥ������� �����ϰ�, ����ϴ� Calculator Ŭ���� �ۼ�
 (3+5)/10 �� List<String>���� ���� :    
 tokens[0] = "("
       tokens[1] = "3"
       tokens[2] = "+"
       tokens[3] = "5" ......
*/

int main(void) {
    char expr[1000];
    Calculator c;
    cout << "������ �Է��Ͻÿ� : ";
    cin.getline(expr, 1000);
    if (!c.setExpression(expr))
    {
        String postfix = c.getPostFix();
        try {
            cout << "����ǥ��� : " << postfix << "����� : " << c.getValue() << endl;

        }
        catch (const char* errmsg) {
            cout << errmsg << endl;
        }
    }
    return 0;
}