/*
 * Software_timer.c
 *
 *  Created on: Sep 23, 2022
 *      Author: dell
 */
#include "Software_timer.h"
#define TICK 10

int timerCol_counter = 0;
int timerCol_flag = 0;

int timer2_counter = 0;
int timer2_flag = 0;

int timer3_counter = 0;
int timer3_flag = 0;


int timerUart_counter = 0;
int timerUart_flag = 0;

int timerRow_counter = 0;
int timerRow_flag = 0;

int timer5_counter = 0;
int timer5_flag = 0;

int timerBuzzer_counter = 0;
int timerBuzzer_flag = 0;

int buzzerLength_flag = 0;
int buzzerLength_counter = 0;
int buzzerActive_flag = 0;

void setBuzzerLength(int duration){
	buzzerLength_counter = duration/TICK;
	buzzerLength_flag = 0;
	buzzerActive_flag = 0;
}

void setTimerBuzzer(int duration){
	timerBuzzer_counter = duration/TICK;
	timerBuzzer_flag = 0;
}

void setTimerCol(int duration){
	timerCol_counter = duration/TICK;
	timerCol_flag = 0;
}

void setTimer2(int duration){
	timer2_counter = duration/TICK;
	timer2_flag = 0;
}

void setTimer3(int duration){
	timer3_counter = duration/TICK;
	timer3_flag = 0;
}

void setTimerUart(int duration){
	timerUart_counter = duration/TICK;
	timerUart_flag = 0;
}

void setTimerRow(int duration){
	timerRow_counter = duration/TICK;
	timerRow_flag = 0;
}

void setTimer5(int duration){
	timer5_counter = duration/TICK;
	timer5_flag = 0;
}



void timerRun(){
	if(buzzerLength_counter > 0){
		buzzerLength_counter--;
		if(buzzerLength_counter <= 10){
			buzzerActive_flag = 1;
		}
		if(buzzerLength_counter == 0){
			buzzerLength_flag = 1;
		}
	}
	if(timerCol_counter > 0){
		timerCol_counter--;
		if(timerCol_counter == 0){
			timerCol_flag = 1;
		}
	}
	if(timer2_counter > 0){
		timer2_counter--;
		if(timer2_counter == 0){
			timer2_flag = 1;
		}
	}
	if(timer3_counter > 0){
		timer3_counter--;
		if(timer3_counter == 0){
			timer3_flag = 1;
		}
	}
	if(timerUart_counter > 0){
		timerUart_counter--;
		if(timerUart_counter == 0){
			timerUart_flag = 1;
		}
	}
	if(timerRow_counter > 0){
		timerRow_counter--;
		if(timerRow_counter == 0){
			timerRow_flag = 1;
		}
	}
	if(timer5_counter > 0){
		timer5_counter--;
		if(timer5_counter == 0){
			timer5_flag = 1;
		}
	}
	if(timerBuzzer_counter > 0){
		timerBuzzer_counter--;
		if(timerBuzzer_counter == 0){
			timerBuzzer_flag = 1;
		}
	}

}

