#include <avr/io.h>
#include <util/delay.h>
#include "Bit_Math.h"
#include "STD_Types.h"
#include "MCAL/Dio/Dio.h"
#include "MCAL/Dio/Dio_config.h"
#include <stdio.h>
#include <avr/interrupt.h>
#include "MCAL/SPI/master/master.h"
#include "HAL/UART/uart.h"


int main(){
	//initialize DIO
	Dio_init();

	//initialize SPI
	SPI_MasterInit();

	//initialize UART
	UART_init(103);

	while(1){
		_delay_ms(10);
		//receive data from bluetooth device and store it
		unsigned char data = UART_recieve();

		//send data received from the bluetooth device via SPI
		SPI_MasterTransmit(data);

		_delay_ms(10);

	}

}
