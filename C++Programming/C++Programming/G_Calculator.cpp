#include "Calculator.h"

int makeTokens(const char* expr) {//���� ������ ��ū���� �и�
    int length = 3;
    bool flag = true;//true�� ���� false�� ������
    for (int i = 0; i < length; i++)
    {
        //if(expr[i]Ÿ���� �ľ��Ѵ�)
            //����Ÿ���� ���ڿ��� ���
            //  �̹�Ÿ���� ���ڸ�
            //          �������ڿ� ��ħ ����Ѵ�
            //  �̹�Ÿ���� �����ڸ�
            //          ���±����� ���ڸ� tokens�� �ִ´�
            //����Ÿ���� �����ڿ��� ���
            //  �̹�Ÿ���� �翬�� ���ڴϱ� ����غ�

    }
    return 0;
}
int Calculator::makePostFix() {// postfix �� �����ϴ� �Լ� : ���������� 0 ���������� 1��ȯ
                                 // �������� postfix ������ ����, ������ ������ �ڵ带 errCode �� ���� (�����ڵ�� ���ڰ� ����)
    return 0;
}         
     
int Calculator::evaluation() {// postfix �� ����ϴ� �Լ� : 
                              // ���� ���� ����, ���� ���°�� 0, ������ �ִ� ���, 1�� ��ȯ
                               // ���� ���� value �� ����, ������ ������ �ڵ带 errCode �� ���� (�����ڵ�� ���ڰ� ����)
    return 0;
}           
           



//public �޼ҵ� ����
Calculator::Calculator() {
    this->errCode = 0; // �߻��� �����ڵ� �� : 0 -> ���� ���� , �ٸ� �� -> ���� ����
    this->value = 0; // ���� ��
    this->postfix = String((String&)" ");// ����ǥ��� = ���� �������� �ʱ�ȭ
}            
int Calculator::setExpression(const char* expr) {// expr�� ���޵� ����(����ǥ���)�� postfix�� �����ϰ� ����ϴ� �Լ� 
                                                //���� ���°��, 0, ������ �ִ� ���, 1�� ��ȯ 
    /*makeTokens(expr);
    for (int i = 0; i < tokens.getItemCount(); i++)
        cout << tokens.getItem(i) << endl;
    /*
    if (!makePostFix())
        return evaluation();
    else
        return 1;
        */
    cout << "setExpressionȣ��";
    return 0;
}
int Calculator::getErrorCode() {// �����ڵ� ��ȯ
    return errCode;
}     

     
                                                          
String Calculator::getPostFix() { // ��ȯ�� ����ǥ����� ��ȯ   --> ������ ������� ���ʰ��� ������ ����
    String s;
    return s;
}                          
int Calculator::getValue() {
    return 0;
}                                   // ���� �������� --> ���ܹ߻� throw "error"
                                                          // ���� �������� --> ����� ����