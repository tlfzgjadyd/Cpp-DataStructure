#include "Calculator.h"
#include <stack>
using namespace std;

int Calculator::makeTokens(const char* expr) {//���� ������ ��ū���� �и�
    int length = String(expr).Length();
    bool flag = true;//true�� ���� false�� ������
    String str="";
    for (int i = 0; i < length; i++)
    {
        //if(expr[i]Ÿ���� �ľ��Ѵ�)
            //����Ÿ���� ���ڿ��� ���
            //  �̹�Ÿ���� ���ڸ�
            //          �������ڿ� ��ħ ����Ѵ�
            //  �̹�Ÿ���� �����ڸ�
            //          ���±����� ���ڸ� tokens�� �ִ´� �����ڵ� tokens�� �ִ´�
            //  ����Ÿ���� �����ڿ��� ���
            //  �̹�Ÿ���� �翬�� ���ڴϱ� ����غ�

        if (isdigit(expr[i]))//�̹� ������ Ÿ���� �ľ��ؼ� ���ڸ� flag true
        {//isdigit(����) ����
            flag = true;
            String s(expr[i]);
            str.Concat(s);
            if(i==length-1)
                tokens.addItem(str);//��ҿ� �����ڳ��ö� �־������� 
            //�������� ������ ���� �ѹ��� �ݵ�� �˾Ƽ� �־���ߵ�
        }
        else//�̹� ���� Ÿ���� �����ڸ� flag false
        {
            flag = false;
            tokens.addItem(str);
            tokens.addItem(expr[i]);
        }
    }
    return 0;
}
int Calculator::makePostFix() {// postfix �� �����ϴ� �Լ� : ���������� 0 ���������� 1��ȯ
                                 // �������� postfix ������ ����, ������ ������ �ڵ带 errCode �� ���� (�����ڵ�� ���ڰ� ����)
    for (int i = 0; i < tokens.getItemCount(); i++)
    {
        ;// cout << tokens.getItem(i);
        //postfix������µ� �����ڰ� �־���ϴ� �纸�� �� ����->errcode=1
        //postfix������µ� ���ڰ� �־���ϴ� �纸�� �� ����->errcode=2
    }
    return 0;
}         

int Calculator::evaluation() {// postfix �� ����ϴ� �Լ� : 
                              // ���� ���� ����, ���� ���°�� 0, ������ �ִ� ���, 1�� ��ȯ
                               // ���� ���� value �� ����, ������ ������ �ڵ带 errCode �� ���� (�����ڵ�� ���ڰ� ����)

    if (isdigit(postfix.getItem(0)))//��ó���� �����ΰ� ����
        ;
    else //���ڵ� �� �ȳ��Դµ� ���� �����ڸ� errCode=3
    {
        errCode = 3;
        return 1;
    }

    stack<char> s;
    for (int i = 0; i < postfix.Length(); i++)
    {
        if (isdigit(postfix.getItem(i))) //������ ��� ���ÿ� �ִ´�
            s.push((char)postfix.getItem(i));
        else //�������� ��� ���� ����� �ٽ� �������
        {
            int n1 = s.top() - '0';// pop�� �������ǰ� �� �Ⱦ˷��ִϱ� top���� ���ߵ�
            s.pop();
            int n2 = s.top() - '0';
            s.pop();
            //pop�ؼ� �����Ѵ��� �װ��� �ٽ� push�Ұ���
                switch (postfix.getItem(i))//�������� Ÿ�Կ� ���� �ٸ� ����� ������
                {
                    case'+':s.push((char)(n2 + n1 + '0')); break;
                    case'-':s.push((char)(n2 - n1 + '0')); break;
                   // {
                   //     if(n2>=n1)
                   //         s.push((char)(n2 - n1 + '0')); 
                   //    else
                   //         s.push((char)(n1 - n2 + '0'));
                   // }break;
                    case'*':s.push((char)(n2 * n1 + '0')); break;
                    case'/':s.push((char)(n2 / n1 + '0')); break;
                    case'%':s.push((char)(n2 % n1 + '0')); break;
                    default:
                    {
                        errCode = 4;
                        return 1;
                    }break; //�����ڰ� �ƴ� ���ڰ� �������� ��� errCode=4
                }
        }
    }
    if (getErrorCode() == 0)
        return 0;
    else
        return 1;
}           
           



//public �޼ҵ� ����
Calculator::Calculator() {
    this->errCode = 0; // �߻��� �����ڵ� �� : 0 -> ���� ���� , �ٸ� �� -> ���� ����
    this->value = 0; // ���� ��
    this->postfix = String();// ����ǥ��� = ���� �������� �ʱ�ȭ
}            
int Calculator::setExpression(const char* expr) {// expr�� ���޵� ����(����ǥ���)�� postfix�� �����ϰ� ����ϴ� �Լ� 
                                                //���� ���°��, 0, ������ �ִ� ���, 1�� ��ȯ 
    //�ϴ� �и��ؼ� ����ֱ�
    //����ǥ������� ��ȯ�ϱ�
    //����ǥ��� ����ϱ�

    //1. �ϴ� �и��ؼ� ����ֱ�
    makeTokens(expr);

    //2. ����ǥ������� ��ȯ�ϱ�

    /*for (int i = 0; i < tokens.getItemCount(); i++)
        cout << tokens.getItem(i) << endl;
    */

    if (getErrorCode()== 0)//2������ ���� �ȳ��� ��쿡�� evaluation���� ���õ�
    {
        //3. ����ǥ��� ����ϱ�
        evaluation();
        if (getErrorCode() == 0)
            return 0;
        else
            return 1;
    }
    else
    {
        return 1;
    }
        
}
int Calculator::getErrorCode() {// �����ڵ� ��ȯ
    return errCode;
}     

     
//���⼭ ��ȯ�ϴ°� �ƴ϶� �̹� ��ȯ�� ������ ������                                                        
String Calculator::getPostFix() { // ��ȯ�� ����ǥ����� ��ȯ   --> ������ ������� ���ʰ��� ������ ����
    if (getErrorCode()== 0)
        return postfix; 
    else
        return "";
}           

//���⼭ ����ϴ°� �ƴ϶� �̹� ���� ������� ������   
int Calculator::getValue() {
    if (getErrorCode() == 0)
        return value;
    else
        throw "error";
}                                   // ���� �������� --> ���ܹ߻� throw "error"
                                                          // ���� �������� --> ����� ����