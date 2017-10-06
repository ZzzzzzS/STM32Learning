#include "led.h"

/**********************718创新实验室开发板例程*********************
*  函数名:LED_Init
*  参数:无            
*  功能: led初始化
*	 使用示例:LED_Init;
*******************************************************************/
void LED_Init(void)					//led初始化									
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD, ENABLE);	 //使能PC,PD口时钟
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;				 //LED1-->PC.9口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOC, &GPIO_InitStructure);					 //根据设定参数初始化GPIOC.0
 GPIO_SetBits(GPIOC,GPIO_Pin_9);						 //PC.9 输出高

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;	    		 //LED2-->PC.8 端口配置, 推挽输出
 GPIO_Init(GPIOC, &GPIO_InitStructure);	  				 //推挽输出 ，IO口速度为50MHz
 GPIO_SetBits(GPIOC,GPIO_Pin_8); 						 //PC.8 输出高 
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;	    		 //LED3-->PC.7 端口配置, 推挽输出
 GPIO_Init(GPIOC, &GPIO_InitStructure);	  				 //推挽输出 ，IO口速度为50MHz
 GPIO_SetBits(GPIOC,GPIO_Pin_7); 						 //PC.2 输出高 

		
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;	    		 //LED4-->PC.6 端口配置, 推挽输出
 GPIO_Init(GPIOC, &GPIO_InitStructure);	  				 //推挽输出 ，IO口速度为50MHz
 GPIO_SetBits(GPIOC,GPIO_Pin_6); 						 //PC.6 输出高 
 
 	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;	    		 //LED5-->PD.15 端口配置, 推挽输出
 GPIO_Init(GPIOD, &GPIO_InitStructure);	  				 //推挽输出 ，IO口速度为50MHz
 GPIO_SetBits(GPIOD,GPIO_Pin_15); 						 //PCD.15 输出高 
 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;	    		 //LED6-->PD.14 端口配置, 推挽输出
 GPIO_Init(GPIOD, &GPIO_InitStructure);	  				 //推挽输出 ，IO口速度为50MHz
 GPIO_SetBits(GPIOD,GPIO_Pin_14); 						 //PCD.14 输出高 
}
 