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
    int setExpression(const char* expr);       // expr에 전달된 수식(중위표기식)을 postfix로 변경하고 계산하는 함수     
                                                          //    오류 없는경우, 0, 오류가 있는 경우, 1을 반환 
    String getPostFix();                            // 변환된 후위표기식을 반환   --> 오류가 있을경우 최초값인 공백이 리턴
    int getValue();                                   // 수식 오류있음 --> 예외발생 throw "error"
                                                          // 수식 오류없음 --> 결과값 리턴
};