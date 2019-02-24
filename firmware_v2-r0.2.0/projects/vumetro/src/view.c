#include "view.h"
#include "MAX7219.h"
#include "sapi.h"

#define LEVEL8 (COL1|COL2|COL3|COL4|COL5|COL6|COL7|COL8)
#define LEVEL7 (COL2|COL3|COL4|COL5|COL6|COL7|COL8)
#define LEVEL6 (COL3|COL4|COL5|COL6|COL7|COL8)
#define LEVEL5 (COL4|COL5|COL6|COL7|COL8)
#define LEVEL4 (COL5|COL6|COL7|COL8)
#define LEVEL3 (COL6|COL7|COL8)
#define LEVEL2 (COL7|COL8)
#define LEVEL1 (COL8)
#define LEVEL0 0

#define BAND1 ROW8
#define BAND2 ROW7
#define BAND3 ROW6
#define BAND4 ROW5
#define BAND5 ROW4
#define BAND6 ROW3
#define BAND7 ROW2
#define BAND8 ROW1

uint8_t get_level(int potencia){
	if (potencia>=-17)
		return LEVEL8;
	else{
		if (potencia>=-21)
			return LEVEL7;
		else{
			if (potencia>=-25)
				return LEVEL6;
			else{
				if (potencia>=-33)
					return LEVEL5;
				else{
					if (potencia>=-40)
						return LEVEL4;
					else{
						if (potencia>=-46)
							return LEVEL3;
						else{
							if (potencia>=-52)
								return LEVEL2;
							else{
								if (potencia>=-58)
									return LEVEL1;
								else
									return LEVEL0;
							}
						}
					}
				}
			}
		}
	}
}

void VIEW_band1(int potencia){
	MAX7219_write_row(BAND1, get_level(potencia));
}

void VIEW_band2(int potencia){
	MAX7219_write_row(BAND2, get_level(potencia));
}

void VIEW_band3(int potencia){
	MAX7219_write_row(BAND3, get_level(potencia));
}

void VIEW_band4(int potencia){
	MAX7219_write_row(BAND4, get_level(potencia));
}

void VIEW_band5(int potencia){
	MAX7219_write_row(BAND5, get_level(potencia));
}

void VIEW_band6(int potencia){
	MAX7219_write_row(BAND6, get_level(potencia));
}

void VIEW_band7(int potencia){
	MAX7219_write_row(BAND7, get_level(potencia));
}

void VIEW_band8(int potencia){
	MAX7219_write_row(BAND8, get_level(potencia));
}
