#include "Calculator.h"

int makeTokens(const char* expr) {//들어온 수식을 토큰으로 분리
    int length = 3;
    bool flag = true;//true면 숫자 false면 연산자
    for (int i = 0; i < length; i++)
    {
        //if(expr[i]타입을 파악한다)
            //이전타입이 숫자였을 경우
            //  이번타입이 숫자면
            //          이전숫자와 합침 계속한다
            //  이번타입이 연산자면
            //          여태까지의 숫자를 tokens에 넣는다
            //이전타입이 연산자였을 경우
            //  이번타입은 당연히 숫자니까 계속해봄

    }

}
int Calculator::makePostFix() {// postfix 로 변경하는 함수 : 오류없으면 0 오류있으면 1반환
                                 // 변경결과는 postfix 변수에 저장, 오류시 적절한 코드를 errCode 에 저장 (오류코드는 각자가 정의)
    
}         
     
int Calculator::evaluation() {// postfix 를 계산하는 함수 : 
                              // 계산된 값을 구함, 오류 없는경우 0, 오류가 있는 경우, 1을 반환
                               // 계산된 값은 value 에 저장, 오류시 적절한 코드를 errCode 에 저장 (오류코드는 각자가 정의)
    
}            
           
Calculator::Calculator() {
    this->errCode = 0; // 발생된 오류코드 값 : 0 -> 오류 없음 , 다른 값 -> 오류 있음
    this->value = 0; // 계산된 값
    this->postfix = String((String&)" ");// 후위표기식 = 최초 공백으로 초기화
}                           
int Calculator::getErrorCode() {// 오류코드 반환
    return errCode;
}     

int Calculator::setExpression(const char* expr) {// expr에 전달된 수식(중위표기식)을 postfix로 변경하고 계산하는 함수 
                                                //오류 없는경우, 0, 오류가 있는 경우, 1을 반환 
    makeTokens(expr);
    for (int i = 0; i < tokens.getItemCount(); i++)
        cout << tokens.getItem(i)<<endl;
    /*
    if (!makePostFix())
        return evaluation();
    else
        return 1;
        */
}       
                                                          
String Calculator::getPostFix() { // 변환된 후위표기식을 반환   --> 오류가 있을경우 최초값인 공백이 리턴
    String s;
    return s;
}                          
int Calculator::getValue() {}                                   // 수식 오류있음 --> 예외발생 throw "error"
                                                          // 수식 오류없음 --> 결과값 리턴