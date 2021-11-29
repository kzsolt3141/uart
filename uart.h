/*
 * uart.h
 *
 * Created: 12/21/2016 10:47:01 PM
 *  Author: Zsolt
 */ 

#ifndef USART_TOOLS_H_
#define USART_TOOLS_H_

#include <stdint.h>
#include <util/delay.h>

//------------------------------------------------
//               DEFINES
//------------------------------------------------

// define USART baud rate, this value will be identical with the baud rate of the COM port 
// in windows with which the microcontroller communicates with PC (see Device Manager!!)
#define USART_BAUDRATE 38400

// calculate from Baud rate the pre-scaler value for the microcontroller baud rate counter
#define BAUD_PRESCALE (((F_CPU/(USART_BAUDRATE*16UL)))-1) 

/**
 * Initialize UART related registers
 */
void USARTInit();

/**
 * Send out the character trough USART.
 */
void USART_char_send(char *c);

/**
 * Character received from UART is saved in this variable.
 */
uint8_t USART_ReadByte;

#endif /* USART_TOOLS_H_ */