#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"
#include "uart.h"
#include "led.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	char str[32];
	SystemInit();
	UartInit(BAUD_9600);
	LedInit(LED_RED);
	LedInit(LED_BLUE);
	char choice;
	while(1){
	UartPuts("Enter Strings...\r\n0.ext1.red on\n2.red off\n3.blue on \n4.blue off\r\n");

	UartGets(str);
	sscanf(str,"%d\r\n",&choice);
	switch(choice)
	{
	case 1:
		LedOn(LED_RED);
		break;
	case 2:
		LedOff(LED_RED);
		break;
	case 3:
		LedOn(LED_BLUE);
		break;
	case 4:
		LedOff(LED_BLUE);
		break;
	}

	}
	return 0;
}
