/*************************718开发板例程**********************

*   编写：718创新实验室
*		平台：STM32F103VET6科创培训开发板
*		说明：该例程使用官方库进行编写，由于作者的水平有限， 
*								若有不足之处， 还请大家见谅
*									建议大家多查阅数据手册，多在新生群和大家交流。

*************************************************************/


#include "stm32f10x_it.h"
#include "TIM.h"
#define LED1_PORT  			GPIOC									//定义一些管脚
#define LED2_PORT  			GPIOC
#define LED3_PORT       GPIOC
#define LED4_PORT       GPIOC
#define LED_GPIO_CLK   RCC_APB2Periph_GPIOC
#define LED1_Pin        GPIO_Pin_6
#define LED2_Pin        GPIO_Pin_7
#define LED3_Pin        GPIO_Pin_8
#define LED4_Pin        GPIO_Pin_9

/*******************     GPIOD      *************************/

#define LED5_PORT  GPIOD
#define LED6_PORT  GPIOD

#define LED5_Pin  GPIO_Pin_14
#define LED6_Pin  GPIO_Pin_15

int time = 0;//定义计时变量time
void LED_GPIO_Config()
	{
	GPIO_InitTypeDef GPIO_InitStructure;			//GPIO初始化结构体					
  RCC_APB2PeriphClockCmd(LED_GPIO_CLK, ENABLE);			//打开GPIO时钟	
  GPIO_InitStructure.GPIO_Pin = LED1_Pin |LED2_Pin |LED3_Pin |LED4_Pin ;			//选择GPIO引脚	
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //设置为推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//设置管脚输出速率为50MHZ
  GPIO_Init(LED1_PORT, &GPIO_InitStructure);			//完成初始化
}

void led_off(){
	GPIO_ResetBits(LED1_PORT,LED1_Pin |LED2_Pin |LED3_Pin |LED4_Pin);	//端口置0 打开LED
}

void led_on(){
	GPIO_SetBits(LED1_PORT,LED1_Pin |LED2_Pin |LED3_Pin |LED4_Pin);	//端口置1 关闭LED
}



int main() 
	{

		LED_GPIO_Config();												//初始化LED灯
    	BASIC_TIM_Init();													//初始化定时器
		led_on();																	//先打开灯
		while(1)
		{
			if(time==100)//定时0.1s后关闭LED
			{
			led_off();
			}
			if(time==200)//再定时0.1s后打开LED
			{
				time=0;
				led_on();
			}
		}
	}

	
void  TIM6_IRQHandler (void)//TIM6中断服务函数
{
	if ( TIM_GetITStatus( TIM6, TIM_IT_Update) != RESET ) 
	{	
		time++;																					//在中断服务函数中进行计数
		TIM_ClearITPendingBit(TIM6 , TIM_FLAG_Update);  		 
	}		 	
}
