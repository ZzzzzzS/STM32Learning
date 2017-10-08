/**********************718创新实验室开发板例程*********************
*  编写：718创新实验室
*  平台：STM32F103VET6
*  说明：由于作者的水平有限，若有不足之处，还请大家谅解。
*		 建议大家多看看数据手册。     
******************************************************************/

#ifndef __Matrix_Keyboard_H__
#define __Matrix_Keyboard_H__

#include "stm32f10x.h"
#include "stm32f10x_gpio.h"

void KeyInit(void);	//声明矩阵键盘初始化函数

char KeyClicked(void); //声明被按下的按钮,如果没有被按下的就返回0

#endif
