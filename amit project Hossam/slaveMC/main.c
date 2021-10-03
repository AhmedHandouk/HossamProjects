#include <avr/io.h>
#include <util/delay.h>
#include "Bit_Math.h"
#include "STD_Types.h"
#include <stdio.h>
#include <avr/interrupt.h>
#include "MCAL/Dio/Dio.h"
#include "MCAL/Dio/Dio_config.h"
#include "MCAL/SPI/slave.h"



int main(){
	//initialize DIO
	Dio_init();

	//initialize SPI
	SPI_SlaveInit();

	while(1){
		_delay_ms(10);

		//receive data
		char data = SPI_SlaveRec();

		//check whether data received is a 1 or 2 as characters and toggle leds accordingly
		if(data=='1'){
			PORTA ^=(1<<6);
		}
		if(data=='2'){
			PORTA ^=(1<<7);
		}
	}
	return 0;

}
