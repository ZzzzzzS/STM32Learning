/**********************718创新实验室开发板例程*********************
*  编写：718创新实验室
*  平台：STM32F103VET6
*  说明：由于作者的水平有限，若有不足之处，还请大家谅解。
*		 建议大家多看看数据手册。     
******************************************************************/
/*************************功能说明******************************
	通过for循环硬延时实现闪烁LED灯
	详细看led&beep.h
****************************************************************/

#include "stm32f10x.h"
#include "led&beep.h"


void DELAY()							//采用for循环硬延时
{
	int i=0,j=0;
	for(i=0;i<10000;i++)
	{
		for(j=0;j<100;j++);
	}
}

void main()
{

	LED_Init();										//led初始化

	while(1)
	{
		LEDPower(LED1,Power_ON);
		LEDPower(LED2,Power_ON);
		LEDPower(LED3,Power_ON);
		LEDPower(LED4,Power_ON);
		LEDPower(LED5,Power_ON);
		LEDPower(LED6,Power_ON);
		
		DELAY();
		LEDPower(LED1,Power_OFF);
		LEDPower(LED1,Power_OFF);
		LEDPower(LED2,Power_OFF);
		LEDPower(LED3,Power_OFF);
		LEDPower(LED4,Power_OFF);
		LEDPower(LED5,Power_OFF);
		LEDPower(LED6,Power_OFF);
		
		DELAY();
	}
	
}