/*
 * Display.c
 *
 *  Created on: Oct 25, 2022
 *      Author: ADMIN
 */

#include <Device_Functions.h>
#include <stdio.h>

void Init(){
	status_col=INIT;
	status_row=INIT;

	setTimerCol(10);
}
/////////////////////////////////////////////////////////////////
//					FUNCTIONS FOR LEDS
/////////////////////////////////////////////////////////////////

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


void Display_P_Led_Red1(){
	HAL_GPIO_WritePin(P_LED1_GPIO_Port, P_LED1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(P_LED2_GPIO_Port, P_LED2_Pin, GPIO_PIN_RESET);
}
void Display_P_Led_Green1(){
	HAL_GPIO_WritePin(P_LED1_GPIO_Port, P_LED1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(P_LED2_GPIO_Port, P_LED2_Pin, GPIO_PIN_SET);
}

void Display_P_Led_Reset(){
	HAL_GPIO_WritePin(P_LED1_GPIO_Port, P_LED1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(P_LED2_GPIO_Port, P_LED2_Pin, GPIO_PIN_RESET);
}


/////////////////////////////////////////////////////////////////
//					FUNCTIONS FOR BUZZER
/////////////////////////////////////////////////////////////////

void Buzzer(int intensity){
	__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, intensity);
	setBuzzerLength(200);
}

void Buzzer_Off(){
	__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 0);
}

/////////////////////////////////////////////////////////////////
//					FUNCTIONS FOR UART
/////////////////////////////////////////////////////////////////
char str[20];
void uart_run(){
	if(timerUart_flag==1){
		setTimerUart(1000);
		time_value--;
		HAL_UART_Transmit(&huart2, (void *)str, sprintf(str,"!7SEG:%2d#\n",time_value/1000), 1000);
	}
}
