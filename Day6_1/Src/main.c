#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"
#include "lcd.h"
#include "led.h"
#include "switch.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	int count=0;
	char str[16];
	SystemInit();
	LcdInit();
	LedInit(LED_ORANGE);
	SwitchInit(SWITCH);
	while(1) {

		while(exti0_flag == 0);
		LedBlink(LED_ORANGE, 500);
		sprintf(str, "CNT=%d", count);
		LcdPuts(LCD_LINE2, str);
		exti0_flag = 0;
	}
	return 0;
}
