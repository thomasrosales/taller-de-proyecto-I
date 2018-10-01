#include "reloj.h"       /* <= own header */

unsigned int seg=0, min=0, h=0, count=0;
static char hora[]="HH:MM:SS";
void RELOJ_count(){
	count++;
	if (count==TICK){
		seg++;
		count=0;
		if (seg==60){
			seg=0;
			min++;
			if (min==60){
				min=0;
				h++;
				if (h==24){
					h=0;
				}
			}
		}
	}
}

char *RELOJ_get_hora(){
	hora[0]=h/10 + '0';
	hora[1]=h%10 + '0';
	hora[3]=min/10 + '0';
	hora[4]=min%10 + '0';
	hora[6]=seg/10 + '0';
	hora[7]=seg%10 + '0';
	return hora;
}

