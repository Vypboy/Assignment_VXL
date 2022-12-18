/*
 * Display.c
 *
 *  Created on: Oct 25, 2022
 *      Author: ADMIN
 */

#include "Display.h"


void Init(){
	status_col=INIT;
	status_row=INIT;

	setTimerCol(10);
}

//ham BkinkLed() de thuc hien nhap nhau 4 den cung mau trong trang thai MODE
int status1=0;
void BlinkLed(enum TypeLed L){
	if(timer5_flag==1){
		setTimer5(250);
		if(status1==1){
			if(L == Red){
				Display_Led_Red1();
				Display_Led_Red2();
			}
			else if(L == Green){
				Display_Led_Green1();
				Display_Led_Green2();
			}
			else if(L == Yellow){
				Display_Led_Yellow1();
				Display_Led_Yellow2();
			}
		}
		else{
			Display_Init();
		}
		status1=1 - status1;
	}
}


void Display_Init(){
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_RESET);
}


void Display_Led_Red1(){
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
}
void Display_Led_Green1(){
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
}
void Display_Led_Yellow1(){
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
}

void Display_Led_Red2(){
	HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_RESET);
}
void Display_Led_Green2(){
	HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_SET);
}
void Display_Led_Yellow2(){
	HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_SET);
}


//void Display_P_Led_Red1(){
//	HAL_GPIO_WritePin(P_LED1_GPIO_Port, P_LED1_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(P_LED2_GPIO_Port, P_LED2_Pin, GPIO_PIN_RESET);
//}
//void Display_P_Led_Green1(){
//	HAL_GPIO_WritePin(P_LED1_GPIO_Port, P_LED1_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(P_LED2_GPIO_Port, P_LED2_Pin, GPIO_PIN_SET);
//}
void Display_P_Led_Reset(){
	HAL_GPIO_WritePin(pled1_GPIO_Port, pled2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(pled1_GPIO_Port, pled2_Pin, GPIO_PIN_RESET);
}
void Display_P_Led_Red1(){
	HAL_GPIO_WritePin(pled1_GPIO_Port, pled2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(pled1_GPIO_Port, pled2_Pin, GPIO_PIN_SET);
}
void Display_P_Led_Green1(){
	HAL_GPIO_WritePin(pled1_GPIO_Port, pled2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(pled1_GPIO_Port, pled2_Pin, GPIO_PIN_RESET);
}



