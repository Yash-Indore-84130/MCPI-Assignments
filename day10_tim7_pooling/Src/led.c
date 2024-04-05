/*
 * led.c
 *
 *  Created on: Apr 4, 2024
 *      Author: akshay
 */

#include"led.h"
#include"stm32f4xx.h"

void LedInit(uint32_t pin)
{
	//enable gpio clock
	RCC->AHB1ENR |= BV(LED_GPIO_EN);

	//set gpio pin as output
	LED_GPIO->MODER &= ~BV(pin*2+1);
	LED_GPIO->MODER |= BV(pin*2);

	//set low speed
	LED_GPIO->OSPEEDR &= ~(BV(pin*2+1) | BV(pin*2));

	//no pull up pull down
	LED_GPIO->PUPDR &= ~(BV(pin*2+1) | BV(pin*2));

	//no push pull
	LED_GPIO->OTYPER &= ~(BV(pin));
}

void LedOn(uint32_t pin) {
	// set led pin (in ODR)
	LED_GPIO->ODR |= BV(pin);
}

void LedOff(uint32_t pin) {
	// clear led pin (in ODR)
	LED_GPIO->ODR &= ~BV(pin);
}

void LedBlink(uint32_t pin, uint32_t delay) {
	LedOn(pin);
	DelayMs(delay);
	LedOff(pin);
}
