
#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "uart.h"
#include "lis3dsh.h"
#include "i2c_lcd.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	char str[32];
	int ret;
	LIS_Data val;
	LIS_Init();
	DelayMs(500);
	SystemInit();
	//UartInit(BAUD_9600);
	//UartPuts("LIS3DSH Accel Demo!\r\n");
	ret=LcdInit();
	if(ret){
	//DelayMs(1000);
	while(1) {
		ret = LIS_DRdy();
		if(ret) {
			val = LIS_GetData();
			sprintf(str, "X=%d, Y=%d", val.x, val.y);
			LcdPuts(LCD_LINE1,str);
			sprintf(str,"Z=%d",val.z);
			LcdPuts(LCD_LINE2,str);
			DelayMs(500);
		}
	}
	}
	return 0;
}







