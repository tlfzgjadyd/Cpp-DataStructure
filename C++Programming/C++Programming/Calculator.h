#pragma once
#include <iostream>
#include "List.h"
#include "String.h"
using namespace std;
class Calculator
{
private:
    List<String> tokens;
    int errCode;                
    int value;                    
    String postfix;              

    int makeTokens(const char* expr);
    int makePostFix();         
    int evaluation();          

public:
    Calculator();
    int getErrorCode();                             
    int setExpression(const char* expr);       // expr�� ���޵� ����(����ǥ���)�� postfix�� �����ϰ� ����ϴ� �Լ�     
                                                          //    ���� ���°��, 0, ������ �ִ� ���, 1�� ��ȯ 
    String getPostFix();                            // ��ȯ�� ����ǥ����� ��ȯ   --> ������ ������� ���ʰ��� ������ ����
    int getValue();                                   // ���� �������� --> ���ܹ߻� throw "error"
                                                          // ���� �������� --> ����� ����
};