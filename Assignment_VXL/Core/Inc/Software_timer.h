/*
 * Software_timer.h
 *
 *  Created on: Sep 23, 2022
 *      Author: dell
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timerCol_flag;
extern int timer2_flag;
extern int timerUart_flag;
extern int timerRow_flag;
extern int timer5_flag;
extern int timerBuzzer_flag;

void setTimerBuzzer(int duration);

void setTimerCol(int duration);

void setTimer2(int duration);

void setTimerUart(int duration);

void setTimerRow(int duration);

void setTimer5(int duration);

void timerRun();


#endif /* INC_SOFTWARE_TIMER_H_ */
