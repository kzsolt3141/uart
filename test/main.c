/*
 * main.c
 *
 * Created: 12/21/2016 10:44:40 PM
 *  Author: Zsolt
 */ 

#include "uart.h"
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

struct USART_RXC_cb_ctx_t {
    uint8_t rx;
    int cnt;
};

/**
 * USART RX interrupt callback handle
 * @param[inout] ctx user data for interrupt callback
 * When ISR occurs USART_RXC_cb will be called with ctx as parameter
 * UART RX data (UDR) should be saved in this function
 */
static void USART_RXC_cb_handle(void* ctx) {
    struct USART_RXC_cb_ctx_t* t_ctx = (struct USART_RXC_cb_ctx_t*)ctx;

    t_ctx->rx = UDR;
    t_ctx->cnt++;

    printf("r: %c i: %d\n", t_ctx->rx, t_ctx->cnt);
}

int main(void) {
    const uint16_t baud_rate = 38400;

    uint8_t sts = 0;
    struct USART_RXC_cb_ctx_t USART_RXC_ctx = {};

    regiter_USART_RXC_cb(USART_RXC_cb_handle, &USART_RXC_ctx);

    USART_init(baud_rate);
    if (sts) return sts;

    printf("Init Done UART baud: %u\n", (uint16_t)baud_rate);
    
// infinite loop
    while(1) {}

    return sts;
}
