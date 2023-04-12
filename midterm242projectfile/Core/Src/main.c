// Timer number: 14
// ARR NUMBER: 65535
// Duration: 22050
// Led Pin Number: 13

#include <stm32f407xx.h>
int main() {
//#define rccAPB1 *((int *)  0x40023840)
// rccAPB1= 0x00000100;

	// Enable the clock for Timer 14
RCC->APB1ENR |= RCC_APB1ENR_TIM14EN;

   // Enable the clock for Timer 14
RCC->APB1ENR |= RCC_APB1ENR_TIM14EN;

	// Set the prescaler to 2
TIM14->PSC = 1;

	// Update the prescaler value
TIM14->EGR |= TIM_EGR_UG;

// Set the auto-reload value to 65535
TIM14->ARR = 0xFFFF;

// Stop the timer by clearing the control register to 0
TIM14->CR1 &= ~TIM_CR1_CEN;

// Set the control register to 1
TIM14->CR1 |= TIM_CR1_CEN;

RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

// Set GPIOA pin 13 as output
GPIOA->MODER |= GPIO_MODER_MODE13_0;

// Turn on the orange LED
GPIOA->BSRR |= GPIO_BSRR_BS13;

while(1)
{
   if(TIM14->CNT < 22050){
      TIM14->CR1 &= ~TIM_CR1_CEN;

        TIM14->CNT = 1;


        GPIOA->ODR ^= GPIO_ODR_OD13;
     }
 }
}
