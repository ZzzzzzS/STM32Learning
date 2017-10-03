/**********************718创新实验室开发板例程*********************
*  编写：718创新实验室
*  平台：STM32F103VET6
*  说明：由于作者的水平有限，若有不足之处，还请大家谅解。
*		 建议大家多看看数据手册。     
******************************************************************/


#ifndef __LED&BEEP_H__
#define __LED&BEEP_H__

#include "stm32f10x.h"
#include "stm32f10x_gpio.h"

typedef enum  //枚举定义灯的序号
{
	LED1,
	LED2,
	LED3,
	LED4,
	LED5,
	LED6
}LEDNumber;

typedef enum
{
	Power_ON,
	Power_OFF,
}PowerState;


extern void LEDInit();
extern void LEDPower(LEDNumber Number,PowerState State);
extern void BeepInit();
extern void BeepPower(PowerState State);

#endif
