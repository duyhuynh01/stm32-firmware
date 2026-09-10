#include "FreeRTOS.h"
#include "stm32f103xb.h"
#include "task.h"
#include <stdint.h>
#include <stdio.h>

void delay(volatile uint32_t t) {
    while (t--);
}

int main(void) {
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN; 
    GPIOC->CRH &= ~(0xF << 20);
    GPIOC->CRH |= (0x1 << 20);
    while (1) {
        GPIOC->ODR ^= (1 << 13);
        delay(1000000);
    }
}


