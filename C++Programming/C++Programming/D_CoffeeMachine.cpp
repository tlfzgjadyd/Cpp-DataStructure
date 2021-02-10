#include "D_CoffeeMachine.h"

int main(void) {
	D_CoffeeMachine java(5, 10, 3); //커피량 물량 설탕 순서
	java.drinkEspresso(); //커피1, 물1 소비
	java.show(); //현재 커피머신 상태 출력
	java.drinkAmericano(); //커피1, 물2 소비
	java.show();
	java.drinkSugarCoffee(); //커피1, 물2, 설탕1 소비
	java.show();
	java.fill(); //커피10 물10 설탕10으로 채우기
	java.show();
}