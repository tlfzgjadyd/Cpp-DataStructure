#include "Calculator.h"
#include <stack>
using namespace std;

int Calculator::makeTokens(const char* expr) {//들어온 수식을 토큰으로 분리
    int length = String(expr).Length();
    bool flag = true;//true면 숫자 false면 연산자
    String str="";
    for (int i = 0; i < length; i++)
    {
        //if(expr[i]타입을 파악한다)
            //이전타입이 숫자였을 경우
            //  이번타입이 숫자면
            //          이전숫자와 합침 계속한다
            //  이번타입이 연산자면
            //          여태까지의 숫자를 tokens에 넣는다 연산자도 tokens에 넣는다
            //  이전타입이 연산자였을 경우
            //  이번타입은 당연히 숫자니까 계속해봄

        if (isdigit(expr[i]))//이번 문자의 타입을 파악해서 숫자면 flag true
        {//isdigit(문자) 맞음
            flag = true;
            String s(expr[i]);
            str.Concat(s);
            if(i==length-1)
                tokens.addItem(str);//평소엔 연산자나올때 넣어주지만 
            //마지막에 나오는 숫자 한번은 반드시 알아서 넣어줘야됨
        }
        else//이번 문자 타입이 연산자면 flag false
        {
            flag = false;
            tokens.addItem(str);
            tokens.addItem(expr[i]);
        }
    }
    return 0;
}
int Calculator::makePostFix() {// postfix 로 변경하는 함수 : 오류없으면 0 오류있으면 1반환
                                 // 변경결과는 postfix 변수에 저장, 오류시 적절한 코드를 errCode 에 저장 (오류코드는 각자가 정의)
    for (int i = 0; i < tokens.getItemCount(); i++)
    {
        ;// cout << tokens.getItem(i);
        //postfix만들었는데 연산자가 있어야하는 양보다 더 많음->errcode=1
        //postfix만들었는데 숫자가 있어야하는 양보다 더 많음->errcode=2
    }
    return 0;
}         

int Calculator::evaluation() {// postfix 를 계산하는 함수 : 
                              // 계산된 값을 구함, 오류 없는경우 0, 오류가 있는 경우, 1을 반환
                               // 계산된 값은 value 에 저장, 오류시 적절한 코드를 errCode 에 저장 (오류코드는 각자가 정의)

    if (isdigit(postfix.getItem(0)))//맨처음은 숫자인게 정상
        ;
    else //숫자도 다 안나왔는데 벌써 연산자면 errCode=3
    {
        errCode = 3;
        return 1;
    }

    stack<char> s;
    for (int i = 0; i < postfix.Length(); i++)
    {
        if (isdigit(postfix.getItem(i))) //숫자일 경우 스택에 넣는다
            s.push((char)postfix.getItem(i));
        else //연산자일 경우 빼서 계산후 다시 집어넣음
        {
            int n1 = s.top() - '0';// pop은 삭제만되고 값 안알려주니까 top으로 빼야됨
            s.pop();
            int n2 = s.top() - '0';
            s.pop();
            //pop해서 연산한다음 그값을 다시 push할거임
                switch (postfix.getItem(i))//연산자의 타입에 따라 다른 계산을 수행함
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
                    }break; //연산자가 아닌 문자가 들어와있을 경우 errCode=4
                }
        }
    }
    if (getErrorCode() == 0)
        return 0;
    else
        return 1;
}           
           



//public 메소드 시작
Calculator::Calculator() {
    this->errCode = 0; // 발생된 오류코드 값 : 0 -> 오류 없음 , 다른 값 -> 오류 있음
    this->value = 0; // 계산된 값
    this->postfix = String();// 후위표기식 = 최초 공백으로 초기화
}            
int Calculator::setExpression(const char* expr) {// expr에 전달된 수식(중위표기식)을 postfix로 변경하고 계산하는 함수 
                                                //오류 없는경우, 0, 오류가 있는 경우, 1을 반환 
    //일단 분리해서 집어넣기
    //후위표기식으로 변환하기
    //후위표기식 계산하기

    //1. 일단 분리해서 집어넣기
    makeTokens(expr);

    //2. 후위표기식으로 변환하기

    /*for (int i = 0; i < tokens.getItemCount(); i++)
        cout << tokens.getItem(i) << endl;
    */

    if (getErrorCode()== 0)//2번에서 에러 안났을 경우에만 evaluation으로 계산시도
    {
        //3. 후위표기식 계산하기
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
int Calculator::getErrorCode() {// 오류코드 반환
    return errCode;
}     

     
//여기서 변환하는게 아니라 이미 변환된 후위를 돌려줌                                                        
String Calculator::getPostFix() { // 변환된 후위표기식을 반환   --> 오류가 있을경우 최초값인 공백이 리턴
    if (getErrorCode()== 0)
        return postfix; 
    else
        return "";
}           

//여기서 계산하는게 아니라 이미 계산된 결과값을 돌려줌   
int Calculator::getValue() {
    if (getErrorCode() == 0)
        return value;
    else
        throw "error";
}                                   // 수식 오류있음 --> 예외발생 throw "error"
                                                          // 수식 오류없음 --> 결과값 리턴