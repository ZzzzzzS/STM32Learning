/**********************718创新实验室开发板例程*********************
*  编写：718创新实验室
*  平台：STM32F103VET6
*  说明：由于作者的水平有限，若有不足之处，还请大家谅解。
*		 建议大家多看看数据手册。     
******************************************************************/

#include "led&beep.h"

/*============================================
函数名:LED_Init()
作用:初始化所有led灯
==========================================*/

void LED_Init()					//led初始化									
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


/*============================================
函数名:LEDPower(LEDNumber Number,PowerState State)
作用:开关led灯
==========================================*/

void LEDPower(LEDNumber Number,PowerState State)
{
	if(Number==LED1)
	{
		if(State==Power_ON)
		{
			GPIO_SetBits(GPIOC,GPIO_Pin_9);
		}
		else
		{
			GPIO_ResetBits(GPIOC,GPIO_Pin_9);
		}
	}
	else if(Number==LED2)
	{
		if(State==Power_ON)
		{
			GPIO_SetBits(GPIOC,GPIO_Pin_8); 
		}
		else
		{
			GPIO_ResetBits(GPIOC,GPIO_Pin_8); 
		}
	}
	else if(Number==LED3)
	{
		if(State==Power_ON)
		{
			GPIO_SetBits(GPIOC,GPIO_Pin_7);
		}
		else
		{
			GPIO_ResetBits(GPIOC,GPIO_Pin_7);
		}
	}
	else if(Number==LED4)
	{
		if(State==Power_ON)
		{
			GPIO_SetBits(GPIOC,GPIO_Pin_6);
		}
		else
		{
			GPIO_ResetBits(GPIOC,GPIO_Pin_6);
		}
	}
	else if(Number==LED5)
	{
		if(State==Power_ON)
		{
			GPIO_SetBits(GPIOD,GPIO_Pin_15); 
		}
		else
		{
			GPIO_ResetBits(GPIOD,GPIO_Pin_15); 
		}
	}
	else if(Number==LED6)
	{
		if(State==Power_ON)
		{
			GPIO_SetBits(GPIOD,GPIO_Pin_14);  
		}
		else
		{
			GPIO_ResetBits(GPIOD,GPIO_Pin_14);  
		}
	}
	
}

/*============================================
函数名:BeepInit()
作用:初始化蜂鸣器
==========================================*/

void BeepInit()
{
	GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);	 //使能PC,PD口时钟
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;				 //LED1-->PC.9口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOE, &GPIO_InitStructure);					 //根据设定参数初始化GPIOC.0
}

/*============================================
函数名:BeepPower(PowerState State)
作用:开关蜂鸣器
==========================================*/

void BeepPower(PowerState State)
{
	if(State==Power_ON)
	{
		GPIO_SetBits(GPIOE,GPIO_Pin_12);
	}
	else
	{
		GPIO_ResetBits(GPIOE,GPIO_Pin_12);
	}
	
}
