/*
 * global.c
 *
 *  Created on: Oct 24, 2022
 *      Author: ADMIN
 */

#include "global.h"

int status_col=0;
int status_row=0;
int status_pad = 0;
int flag_pad=1;
int cycle_pad = 0;

//quan ly thoi gian cac den bang cac bien ben duoi
int Time_Auto_Red =5000;
int Time_Auto_Green =2000;
int Time_Auto_Yellow = 3000;


void set_Time_Auto_Red(int duration){
	Time_Auto_Red = duration;
}
void set_Time_Auto_Green(int duration){
	Time_Auto_Green = duration;
}
void set_Time_Auto_Yellow(int duration){
	Time_Auto_Yellow = duration;
}


int time_value=0;
void set_time_value(int duration){
	time_value=duration / 1000;
}
