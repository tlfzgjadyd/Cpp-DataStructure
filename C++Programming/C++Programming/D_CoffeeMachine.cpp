#include "D_CoffeeMachine.h"

int main(void) {
	D_CoffeeMachine java(5, 10, 3); //Ŀ�Ƿ� ���� ���� ����
	java.drinkEspresso(); //Ŀ��1, ��1 �Һ�
	java.show(); //���� Ŀ�Ǹӽ� ���� ���
	java.drinkAmericano(); //Ŀ��1, ��2 �Һ�
	java.show();
	java.drinkSugarCoffee(); //Ŀ��1, ��2, ����1 �Һ�
	java.show();
	java.fill(); //Ŀ��10 ��10 ����10���� ä���
	java.show();
}