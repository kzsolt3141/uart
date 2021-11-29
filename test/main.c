/*
 * main.c
 *
 * Created: 12/21/2016 10:44:40 PM
 *  Author: Zsolt
 */ 

#include "uart.h"
#include <stdio.h>
#include <util/delay.h>

int main(void)
{
    USARTInit(); 
    printf("Init Done usbasp\n\r");
    
// infinite loop
    while(1) {
        printf("received: %c\n", USART_ReadByte);
        _delay_ms(1000);
    }
}