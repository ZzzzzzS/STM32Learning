/*************************718开发板例程**********************

*   编写：718创新实验室
*		平台：STM32F103VET6科创培训开发板
*		说明：该例程使用官方库进行编写，由于作者的水平有限， 
*								若有不足之处， 还请大家见谅
*									建议大家多查阅数据手册，多在新生群和大家交流。

*************************************************************/

#include "stm32f10x.h"
#define  LED1_PORT 			GPIOC   
#define  LED1_PIN       GPIO_Pin_9
#define  LED1_PORT_RCC  RCC_APB2Periph_GPIOC

/*******************************************************************************
* 函 数 名         : main
* 函数功能		   : 主函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
int main()
{
	GPIO_InitTypeDef GPIO_InitStructure;//定义结构体变量
	
	RCC_APB2PeriphClockCmd(LED1_PORT_RCC,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin=LED1_PIN;  //选择你要设置的IO口
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;	 //设置推挽输出模式
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //设置传输速率
	GPIO_Init(LED1_PORT,&GPIO_InitStructure); 	   //初始化GPIO
	
	GPIO_SetBits(LED1_PORT,LED1_PIN);   //将LED端口拉高，熄灭所有LED
	while(1);
}
