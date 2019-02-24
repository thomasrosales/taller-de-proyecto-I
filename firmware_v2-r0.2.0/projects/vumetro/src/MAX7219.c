#include "sapi.h"
#include "MAX7219.h"

#define BYTES 2
// The opcodes for MAX7219
#define OP_NOOP         0
#define OP_DIGIT0       1
#define OP_DIGIT1       2
#define OP_DIGIT2       3
#define OP_DIGIT3       4
#define OP_DIGIT4       5
#define OP_DIGIT5       6
#define OP_DIGIT6       7
#define OP_DIGIT7       8
#define OP_DECODEMODE   9
#define OP_INTENSITY   10
#define OP_SCANLIMIT   11
#define OP_SHUTDOWN    12
#define OP_DISPLAYTEST 15

void transfer_data( uint8_t opcode,  uint8_t data) {
    uint8_t comando[BYTES];
    comando[0]=opcode;
    comando[1]=data;
    //chip select
    gpioWrite( GPIO0, 0 );
    spiWrite(SPI0, comando, BYTES );
    delay(10);
    //load data
    gpioWrite( GPIO0, 1 );
}
void MAX7219_init(){
	  // SPI configuration
	  spiConfig( SPI0 );
	  //configure GPIO0 as OUTPUT
	  gpioConfig( GPIO0, GPIO_OUTPUT );
	  gpioWrite(GPIO0, 1);
	  /*
	   * No display test
	  */
	  transfer_data(OP_DISPLAYTEST, 0);
	  /*
	   * Display 8 digits
	  */
	  transfer_data(OP_SCANLIMIT, 7);
	  /*
	   * No decode mode
	  */
	  transfer_data(OP_DECODEMODE, 0);
	  /*
	   * No shutdown mode
	  */
	  transfer_data(OP_SHUTDOWN, 1);
	  /*
	   * Set intensity 8
	  */
	  transfer_data(OP_INTENSITY, 15);
	  /*
	   * Clear display
	   */
	  MAX7219_clear_display();
}
void MAX7219_shutdown_mode(bool_t state){
	if (state)
	    transfer_data(OP_SHUTDOWN, 0);
	else
		transfer_data(OP_SHUTDOWN, 1);
}
void MAX7219_displaytest_mode(bool_t state){
	if (state)
		transfer_data(OP_DISPLAYTEST, 1);
	else
		transfer_data(OP_DISPLAYTEST, 0);
}
void MAX7219_set_scan_limit(uint8_t cantidad){
	transfer_data(OP_SCANLIMIT, cantidad);
}
void MAX7219_write_row(uint8_t row, uint8_t data){
	transfer_data(row+1, data);
}
void MAX7219_clear_display(){
  int i;
  for(i=OP_DIGIT0;i<=OP_DIGIT7;i++)
    transfer_data(i, 0);
}
void MAX7219_set_intensity(uint8_t intensity){
	transfer_data(OP_INTENSITY, intensity);
}
