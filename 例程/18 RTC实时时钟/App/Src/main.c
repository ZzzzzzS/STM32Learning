/**********************718创新实验室开发板例程*********************
*  编写：718创新实验室
*  平台：STM32F103VET6
*  说明：由于作者的水平有限，若有不足之处，还请大家谅解。
*		 建议大家多看看数据手册。     
******************************************************************/
/*************************功能说明********************************
通过stm32的RTC(real time clock)模块实现计时功能并显示在数码管上
*************************功能说明********************************/

#include "stm32f10x.h"
#include "module_74hc595.h"
#include "rtc.h"
#include "systick.h"

RTCDate calendar;  //RTCDate结构体,用于保存时间数据

 /**********************718创新实验室开发板例程*********************
*  函数名:RTC_IRQHandler
*  参数:   无       
*  功能:RTC时钟中断，每秒触发一次  
*  使用示例:
*******************************************************************/																
															 
void RTC_IRQHandler(void)
{		 
	if (RTC_GetITStatus(RTC_IT_SEC) != RESET)//秒钟中断
	{							
		calendar=RTC_Get();//更新时间   
 	}			  								 
	RTC_ClearITPendingBit(RTC_IT_SEC|RTC_IT_OW);		//清闹钟中断
	RTC_WaitForLastTask();	  	    						 	   	 
}

 /**********************718创新实验室开发板例程*********************
*  函数名:main
*  参数:   无       
*  功能:主函数  
*  使用示例:
*******************************************************************/		

int main()
{
	
	
	
	RTCInit();					//时钟初始化
	hc595_init();				//数码管初始化
	
	while(1)
	{
		DisplayScan(0,data_table[calendar.hour/10]);		//显示时间
		DisplayScan(1,data_table[calendar.hour%10]);
		DisplayScan(3,data_table[calendar.min/10]);
		DisplayScan(4,data_table[calendar.min%10]);
		DisplayScan(6,data_table[calendar.sec/10]);
		DisplayScan(7,data_table[calendar.sec%10]);
		
	}
}
