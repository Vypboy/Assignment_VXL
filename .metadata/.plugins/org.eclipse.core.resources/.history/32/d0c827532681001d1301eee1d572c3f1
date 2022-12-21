#include "fsm_automatic.h"


void press_ped_lag(){
	flag_pad=1;
	cycle_pad = 0;
	setTimerBuzzer(10);
	setBuzzerLength(10);
}
void reset_pad_led(){
	flag_pad=0;
	cycle_pad=0;
	Display_P_Led_Reset();
}

void fsm_automatic_run(){
	//quan ly den tin hieu hang doc
	switch(status_col){
		case INIT:
			Display_Init();
			//chuyen trang thai ko dk
			status_col=AUTO_RED;
			setTimerCol(Time_Auto_Red);
			//dat gia tri bien dem time_value de hien thi tren terminal
			break;
		case AUTO_RED:
			Display_Led_Red1();

			//chuyen trang thai co dk
			if(timerCol_flag==1){
				status_col=AUTO_GREEN;
				setTimerCol(Time_Auto_Green);
			}
			//trang thai mode 2
			if(isButtonPressed(0)==1){
				status_col=MAN_RED;
				status_row=MAN_RED;
				setTimerCol(MODE_TIME);
			}
			if(isButtonPressed(3)==1){
				press_ped_lag();
			}
			break;
		case AUTO_GREEN:
			Display_Led_Green1();

			//chuyen trang thai co dk
			if(timerCol_flag==1){
				status_col=AUTO_YELLOW;
				setTimerCol(Time_Auto_Yellow);
			}
			if(isButtonPressed(0)==1){
				status_col=MAN_GREEN;
				status_row=MAN_GREEN;
				setTimerCol(MODE_TIME);
			}
			if(isButtonPressed(3)==1){
				press_ped_lag();
			}
			break;
		case AUTO_YELLOW:
			Display_Led_Yellow1();

			//chuyen trang thai co dk
			if(timerCol_flag==1){
				status_col=AUTO_RED;
				setTimerCol(Time_Auto_Red);
			}
			if(isButtonPressed(0)==1){
				status_col=MAN_YELLOW;
				status_row=MAN_YELLOW;

				setTimerCol(MODE_TIME);
			}
			if(isButtonPressed(3)==1){
				press_ped_lag();
			}
			break;
		default:
			break;
	}
///////////////////////////////////////////////////////////////////////
	//quan ly den tin hieu hang ngang
	switch(status_row){
		case INIT:
			Display_Init();

			//chuyen trang thai ko dk
			status_row=AUTO_GREEN;
			setTimerRow(Time_Auto_Green);
			//dat gia tri bien dem time_value de hien thi tren terminal
			set_time_value(Time_Auto_Red);
			break;
		case AUTO_RED:
			if(flag_pad==1) Display_P_Led_Red1();
			Display_Led_Red2();
//			Buzzer_Off();
			//chuyen trang thai co dk
			if(timerRow_flag==1){
				status_row=AUTO_GREEN;
				setTimerRow(Time_Auto_Green);
				setTimerBuzzer(10);
				setBuzzerLength(10);
				//dat gia tri bien dem time_value de hien thi tren terminal
				set_time_value(Time_Auto_Green);
			}
			break;
		case AUTO_GREEN:
			if(flag_pad==1) {
				Display_P_Led_Green1();
				//thuc hien buzzer
				if (timerBuzzer_flag == 1){
					float per = (float)(time_value * 1.0 / Time_Auto_Green);
					setTimerBuzzer((int)(0.15 * Time_Auto_Green * per));
					if (buzzerLength_flag == 1){
						Buzzer(300 - (int)(250 * per));
					}
				}
			}
			Display_Led_Green2();

			//chuyen trang thai co dk
			if(timerRow_flag==1){
				if (cycle_pad >= 1){
					reset_pad_led();//tat den cho nguoi di duong
				}
				else cycle_pad++;
				status_row=AUTO_YELLOW;
				setTimerRow(Time_Auto_Yellow);
				//dat gia tri bien dem time_value de hien thi tren terminal
				set_time_value(Time_Auto_Yellow);
			}
			break;
		case AUTO_YELLOW:
			Display_Led_Yellow2();
			if(flag_pad==1) Display_P_Led_Red1();
//			Buzzer_Off();
			//chuyen trang thai co dk
			if(timerRow_flag==1){
				status_row=AUTO_RED;
				setTimerRow(Time_Auto_Red);
				set_time_value(Time_Auto_Red);
			}
			break;
		default:
			break;
	}
	run_time_value();
	if (buzzerActive_flag == 1){
		Buzzer_Off();
	}
	///////////////////////////////////////////////////////////////////

}

