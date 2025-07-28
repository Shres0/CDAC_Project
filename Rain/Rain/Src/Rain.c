#include "stm32f4xx.h"
#include "Rain.h"

void Rain_Digital_Init(void) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;    // Enable GPIOA clock

    // Set PA1 as input
    GPIOA->MODER &= ~(3 << (1 * 2));
    GPIOA->PUPDR &= ~(3 << (1 * 2));
}

uint8_t Is_Raining(void) {
    return (GPIOA->IDR & GPIO_IDR_ID1) ? 0 : 1;
}
