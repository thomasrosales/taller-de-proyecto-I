#include "mef.h"
#include "MAX7219.h"
#include "DSP.h"
#include "view.h"
#include "KEYPAD.h"

static state estado;

void MEF_init(){
	estado=ALL;
};

void MEF_next_state(){
	unsigned char key = KEYPAD_get_key();
	switch(key){
	case '1':
		estado = BAND1;
		MAX7219_clear_display();
		break;
	case '2':
		estado = BAND2;
		MAX7219_clear_display();
		break;
	case '3':
		estado = BAND3;
		MAX7219_clear_display();
		break;
	case '4':
		estado = BAND4;
		MAX7219_clear_display();
		break;
	case '5':
		estado = BAND5;
		MAX7219_clear_display();
		break;
	case '6':
		estado = BAND6;
		MAX7219_clear_display();
		break;
	case '7':
		estado = BAND7;
		MAX7219_clear_display();
		break;
	case '8':
		estado = BAND8;
		MAX7219_clear_display();
		break;
	case '*':
		estado = ALL;
		MAX7219_clear_display();
		break;
	}
}

void MEF_update(){
	switch(estado){
	case BAND1:
		VIEW_band1((int)DSP_get_potencia_band1());
		break;
	case BAND2:
		VIEW_band2((int)DSP_get_potencia_band2());
		break;
	case BAND3:
		VIEW_band3((int)DSP_get_potencia_band3());
		break;
	case BAND4:
		VIEW_band4((int)DSP_get_potencia_band4());
		break;
	case BAND5:
		VIEW_band5((int)DSP_get_potencia_band5());
		break;
	case BAND6:
		VIEW_band6((int)DSP_get_potencia_band6());
		break;
	case BAND7:
		VIEW_band7((int)DSP_get_potencia_band7());
		break;
	case BAND8:
		VIEW_band8((int)DSP_get_potencia_band8());
		break;
	case ALL:
		VIEW_band1((int)DSP_get_potencia_band1());
		VIEW_band2((int)DSP_get_potencia_band2());
		VIEW_band3((int)DSP_get_potencia_band3());
		VIEW_band4((int)DSP_get_potencia_band4());
		VIEW_band5((int)DSP_get_potencia_band5());
		VIEW_band6((int)DSP_get_potencia_band6());
		VIEW_band7((int)DSP_get_potencia_band7());
		VIEW_band8((int)DSP_get_potencia_band8());
		break;
	}
	MEF_next_state();
}

