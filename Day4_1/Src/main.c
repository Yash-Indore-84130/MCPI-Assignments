
#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "lcd.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	int i=1;
	SystemInit();
	LcdInit();
	LcdPuts(LCD_LINE1, "Yash Indore");
	LcdPuts(LCD_LINE2, " GOD BLESS YOU ");
	while(i<=40)
	{
		LcdWrite(LCD_CMD,LCD_SHIFT);
		DelayMs(500);
		i++;
	}
	return 0;
}







