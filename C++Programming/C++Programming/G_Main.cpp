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
    //���ļ���, ������ ��ȯ, ������ �Ϸ��ϴ� �Լ�
    int n1 = 1;
    int n2 = 2;
    cout << (char)(n2 - n1 + '0');
    if (!c.setExpression(expr))
    {
        /*
        //���⼭ ��ȯ�ϴ°� �ƴ϶� �̹� ��ȯ���ִ� ������ ������
        String postfix = c.getPostFix();
        try {//���⼭ ����� ����ϴ°� �ƴ϶� �̹� �����ִ� ������� ������
            cout << "����ǥ��� : " << postfix << "����� : " << c.getValue() << endl;
        }
        catch (const char* errmsg) {
            cout << errmsg << endl;
        }*/
    }
    return 0;
}