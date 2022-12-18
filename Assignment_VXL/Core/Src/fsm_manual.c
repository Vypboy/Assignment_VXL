
#include "fsm_manual.h"


// fsm_manial_run() thuc hien kiem tra khi nhan button1
// button1 duoc nhan thi chuyen sang trang thai MODE duy tri trong 1 khoang thoi gian(MODE_TIME)
// trong MODE_TIME co the tien hanh chinh sua thoi gian cac LEDs bang button2, button3(duoc hien thuc trong modification_mode.c)
// het MODE_TIME se chuyen lai trang thai 1(automatic)
void fsm_manual_run(){
	switch(status_col){
		case MAN_RED:
			//TODO for mode2(RED_STATE)
			BlinkLed(Red);
			modification_mode();

			//chuyen trang thai co dk
			//reset system khi ket thuc mode
			if(timerCol_flag==1){
				Init();
			}

			if(isButtonPressed(0)==1){
				status_col=MAN_GREEN;
				setTimerCol(MODE_TIME);

				set_time_value(Time_Auto_Green);
			}
			break;
		case MAN_GREEN:
			//TODO for mode3(GREEN_STATE)
			BlinkLed(Green);
			modification_mode();

			//chuyen trang thai co dk
			if(timerCol_flag==1){
				status_col=INIT;
				status_row=INIT;
			}
			if(isButtonPressed(0)==1){
				status_col=MAN_YELLOW;
				setTimerCol(MODE_TIME);

				set_time_value(Time_Auto_Yellow);
			}
			break;
		case MAN_YELLOW:
			//TODO for mode4(YELLOW_STATE)
			BlinkLed(Yellow);
			modification_mode();

			//chuyen trang thai co dk
			if(timerCol_flag==1){
				status_col=INIT;
				status_row=INIT;
			}
			if(isButtonPressed(0)==1){
				status_col=MAN_RED;
				setTimerCol(MODE_TIME);

				set_time_value(Time_Auto_Red);
			}
			break;
		default:
			break;
	}
}
