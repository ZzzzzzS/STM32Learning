/*************************718开发板例程**********************

*   编写：718创新实验室
*		平台：STM32F103VET6科创培训开发板
*		说明：该例程使用官方库进行编写，由于作者的水平有限， 
*								若有不足之处， 还请大家见谅
*									建议大家多查阅数据手册，多在新生群和大家交流。

*************************************************************/

/*************************功能说明******************************
通过systick定时器延时实现流水灯效果
****************************************************************/

/*************************说明******************************
详细内容请查看systick.c和systick.h文件
************************************************************/
#include "stm32f10x.h"
#include "led&beep.h"
#include "systick.h"

int main()
{
		LED_Init();		        //初始化LED端口
	while(1)
	{											//led为共阴极的电路，IO口为高电平的时候亮
			GPIO_ResetBits(GPIOC,GPIO_Pin_9);  //LED1对应引脚GPIOC9拉低，灭  
			Delay_ms(100);
			GPIO_ResetBits(GPIOC,GPIO_Pin_8);  //LED2对应引脚GPIOC8拉低，灭  
			Delay_ms(100);
			GPIO_ResetBits(GPIOC,GPIO_Pin_7);  //LED3对应引脚GPIOC7拉低，灭  
			Delay_ms(100);
			GPIO_ResetBits(GPIOC,GPIO_Pin_6);  // 类似
			Delay_ms(100);
			GPIO_ResetBits(GPIOD,GPIO_Pin_15); 
			Delay_ms(100);
			GPIO_ResetBits(GPIOD,GPIO_Pin_14);    
			Delay_ms(100);
		
			GPIO_SetBits(GPIOC,GPIO_Pin_9);   //LED1对应引脚GPIOC9拉高，亮
			Delay_ms(100);
			GPIO_SetBits(GPIOC,GPIO_Pin_8);   //LED2对应引脚GPIOC8拉高，亮
			Delay_ms(100);
			GPIO_SetBits(GPIOC,GPIO_Pin_7);   //LED3对应引脚GPIOC7拉高，亮
			Delay_ms(100);
			GPIO_SetBits(GPIOC,GPIO_Pin_6);  //类似
			Delay_ms(100);
			GPIO_SetBits(GPIOD,GPIO_Pin_15); 
			Delay_ms(100);
			GPIO_SetBits(GPIOD,GPIO_Pin_14);   
			Delay_ms(100);
	
	
	}
}
