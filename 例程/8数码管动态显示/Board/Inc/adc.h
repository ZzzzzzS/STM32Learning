/**********************718创新实验室开发板例程*********************
*  编写：718创新实验室
*  平台：STM32F103VET6
*  说明：由于作者的水平有限，若有不足之处，还请大家谅解。
*		 建议大家多看看数据手册。     
******************************************************************/
#ifndef __ADC_H__
#define __ADC_H__

#include "stm32f10x.h"
#include "stm32f10x_adc.h"

extern void NTC_CDS_Init(void);//热敏电阻初始化

extern uint16_t GetNTC(void);
extern uint16_t GetCDS(void);


#endif
