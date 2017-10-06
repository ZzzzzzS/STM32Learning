/*************************718开发板例程**********************

*   编写：718创新实验室
*		平台：STM32F103VET6科创培训开发板
*		说明：该例程使用官方库进行编写，由于作者的水平有限， 
*								若有不足之处， 还请大家见谅
*									建议大家多查阅数据手册，多在新生群和大家交流。

*************************************************************/
/*************************功能说明******************************
通过定时器输出PWM波控制灯的亮度变化,也可以用来控制电机转速
什么是PWM波:
http://www.eepw.com.cn/article/272990.htm
****************************************************************/

/*************************说明******************************
详细内容请查看TIM.h和TIM.c文件
************************************************************/
#include "stm32f10x.h"
#include "TIM.h"

void LED_GPIO_Config(void)
{		
		/*定义一个GPIO_InitTypeDef类型的结构体*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*开启LED相关的GPIO外设时钟*/
		RCC_APB2PeriphClockCmd( LED1_GPIO_CLK | LED2_GPIO_CLK | LED3_GPIO_CLK, ENABLE);
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LED1_GPIO_PIN;	

		/*设置引脚模式为通用推挽输出*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*设置引脚速率为50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*调用库函数，初始化GPIO*/
		GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStructure);	
		
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LED2_GPIO_PIN;

		/*调用库函数，初始化GPIO*/
		GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStructure);
		
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LED3_GPIO_PIN;

		/*调用库函数，初始化GPIOF*/
		GPIO_Init(LED3_GPIO_PORT, &GPIO_InitStructure);

		/* 关闭所有led灯	LED共阴*/  
	GPIO_ResetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);
	GPIO_ResetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);
	GPIO_ResetBits(LED3_GPIO_PORT, LED3_GPIO_PIN);
}
void delayms(int a)
{
int i,j;
	for(i=a;i>=0;i--)
	for(j=12000;j>=0;j--)
	{
		;;
	}
}
int main(void)
{
	/* led 端口配置 */ 
	LED_GPIO_Config();
	
	/* 定时器初始化 */
	GENERAL_TIM_Init();
	GPIO_SetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);//开一个灯做对比
  while(1)
  {      
		
		int a=0;
			TIM_SetCompare3(TIM8,0);	//占空比为0  防止蜂鸣器响。。
		for(a=0;a<=10;a++)//改变PWM值控制灯的亮度
		{
		TIM_SetCompare4(TIM8,a);	
			delayms(10);
			
		}
		for(;a>=0;a--)
		{
		TIM_SetCompare4(TIM8,a);	
			delayms(10);
		}
	//	GPIO_ResetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);//R
		//GPIO_ResetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);//G
	//	GPIO_ResetBits(LED3_GPIO_PORT, LED3_GPIO_PIN);//B
		/*****************不断改变PWM波的占空比****************/
		
  }
}
