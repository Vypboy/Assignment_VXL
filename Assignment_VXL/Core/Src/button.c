#include "button.h"
#include "main.h"

//add more case if you have more buttons
int ReadButton(int i){
	switch(i){
		case 0:
			return HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
		case 1:
			return HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin);
		case 2:
			return HAL_GPIO_ReadPin(Button3_GPIO_Port, Button3_Pin);
		case 3:
			return HAL_GPIO_ReadPin(PedestrianButton_GPIO_Port, PedestrianButton_Pin);
		default:
			break;
	}
	return 0;
}

int button_flag[N0_OF_BUTTONS];
int KeyReg0[N0_OF_BUTTONS];
int KeyReg1[N0_OF_BUTTONS];
int KeyReg2[N0_OF_BUTTONS];
int KeyReg3[N0_OF_BUTTONS];
int TimeForKeyPress[N0_OF_BUTTONS];

void initKey(){
	for(int i = 0; i < N0_OF_BUTTONS ; i++) {
		button_flag[i]= 0;

		KeyReg0[i]= NORMAL_STATE;
		KeyReg1[i]= NORMAL_STATE;
		KeyReg2[i]= NORMAL_STATE;
		KeyReg3[i]= NORMAL_STATE;
		TimeForKeyPress[i]= 200;
	}
}

void subKeyProcess(int i){
	button_flag[i]=1;
}

int isButtonPressed(int i){
	if(button_flag[i]==1){
		button_flag[i]=0;
		return 1;
	}
	return 0;
}


void getKeyInput(){
	for(int i = 0; i < N0_OF_BUTTONS ; i++) {
		KeyReg0[i]= KeyReg1[i];
		KeyReg1[i]= KeyReg2[i];
		KeyReg2[i]= ReadButton(i);
		if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
			if (KeyReg3[i] != KeyReg2[i]){
			  KeyReg3[i] = KeyReg2[i];
			  if (KeyReg2[i] == PRESSED_STATE){
				  TimeForKeyPress[i] = 200;
				  //TODO
				  subKeyProcess(i);
			  }
			} else {
				TimeForKeyPress[i]--;
				if (TimeForKeyPress[i] == 0){
					//TODO
					KeyReg3[i]= NORMAL_STATE;
				}
			}
		}
	}
}


