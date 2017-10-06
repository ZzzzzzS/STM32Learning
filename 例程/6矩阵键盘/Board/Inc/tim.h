#ifndef __TIM_H__
#define __TIM_H__

#include "stm32f10x.h"
#include "stm32f10x_tim.h"
#include "stm32f10x_gpio.h"

extern void TIM_Cap_Init();	//TIM输入捕捉模式初始化
extern void TIM_Init();//TIM定时初始化
extern void TIM_PWM_Init();//TIM输出PWM初始化



#endif