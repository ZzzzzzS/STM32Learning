/*************************718开发板例程**********************

*   编写：718创新实验室
*		平台：STM32F103VET6科创培训开发板
*		说明：该例程使用官方库进行编写，由于作者的水平有限， 
*								若有不足之处， 还请大家见谅
*									建议大家多查阅数据手册，多在新生群和大家交流。

*************************************************************/
#include "include.h"
/*********按键相关管脚******/
#define KEY_GPIO_CLK   RCC_APB2Periph_GPIOD			
#define KEY_GPIO_PORT 	GPIOD
#define KEY1_GPIO_PIN	GPIO_Pin_14
#define KEY2_GPIO_PIN	GPIO_Pin_15


#define LED_GPIO_PORT GPIOC
#define LED_GPIO_CLK   RCC_APB2Periph_GPIOC	
#define LED1_GPIO_PIN GPIO_Pin_6
#define LED2_GPIO_PIN GPIO_Pin_7
#define LED3_GPIO_PIN GPIO_Pin_8
#define LED4_GPIO_PIN GPIO_Pin_9

void Delay_ms(u16 time);			//延时
void Key_gpio_init(void);					//key初始化
void Led_init(void);//LED初始化
void Led_on(void);	//LED开
void Led_off(void);	//LED关

int main() {
  Key_gpio_init();			
  Led_init();
	
  while(1){
		
/************按键1按下 LED开 按键2按下 LED关***********************/
/**************按键1***************************/
	if(GPIO_ReadInputDataBit(KEY_GPIO_PORT,KEY1_GPIO_PIN) == 0){	//检测按键按下
	  Delay_ms(10);											//延时消抖
	  if(GPIO_ReadInputDataBit(KEY_GPIO_PORT,KEY1_GPIO_PIN) == 0){		//确实有键按下
		Led_on();
		while(GPIO_ReadInputDataBit(KEY_GPIO_PORT,KEY1_GPIO_PIN) == 0);		
	  }	
	}
	
/************按键2**********************************/
	if(GPIO_ReadInputDataBit(KEY_GPIO_PORT,KEY2_GPIO_PIN) == 0){	
	  Delay_ms(10);		//延时消抖	
	  if(GPIO_ReadInputDataBit(KEY_GPIO_PORT,KEY2_GPIO_PIN) == 0){	
		Led_off();
		while(GPIO_ReadInputDataBit(KEY_GPIO_PORT,KEY2_GPIO_PIN) == 0);		
	  }	
	}	
  };
  
}
/*
函数名： Delay_ms(u16 time)
作用： 		延时
参数：    u16 time
返回：		void
说明：		粗略延时 不准确 其中的i等参数大致随意给定 
					不必过于纠结
*/
void Delay_ms(u16 time) {        
  u16 i=0;      
  while(time--){       
	i=12000;        
	while(i--);      
  } 
}
/*
函数名： void Key_gpio_init(void)
作用： 		按键GPIO初始化
参数：    void
返回：		void
说明：		具体见数据手册及原理图
*/
void Key_gpio_init(void){
  GPIO_InitTypeDef GPIO_InitStructure;	//GPIO初始化结构体							
  RCC_APB2PeriphClockCmd(KEY_GPIO_CLK, ENABLE);		//打开GPIO时钟		
  GPIO_InitStructure.GPIO_Pin = KEY1_GPIO_PIN|KEY2_GPIO_PIN;//选择GPIO引脚				
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 			//设置为上拉输入
  GPIO_Init(KEY_GPIO_PORT, &GPIO_InitStructure);				//传入结构体 	完成初始化
}
/*
函数名： Led_init(void)；
作用： 		LED GPIO初始化
参数：    void
返回：		void
说明：		具体见数据手册及原理图
*/
void Led_init(void){
	GPIO_InitTypeDef GPIO_InitStructure;			//GPIO初始化结构体					
  RCC_APB2PeriphClockCmd(LED_GPIO_CLK, ENABLE);			//打开GPIO时钟	
  GPIO_InitStructure.GPIO_Pin = LED1_GPIO_PIN|LED2_GPIO_PIN|LED3_GPIO_PIN|LED4_GPIO_PIN;			//选择GPIO引脚	
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //设置为推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//设置管脚输出速率为50MHZ
  GPIO_Init(LED_GPIO_PORT, &GPIO_InitStructure);			//完成初始化
}
/*
函数名： void Led_on(void)
作用： 		LED 打开
参数：    void
返回：		void
说明：		参见原理图  端口置1时  开LED
*/
void Led_on(void){
	GPIO_SetBits(LED_GPIO_PORT,LED1_GPIO_PIN|LED2_GPIO_PIN|LED3_GPIO_PIN|LED4_GPIO_PIN);	//端口置1 打开LED
}
/*
函数名： void Led_off(void)
作用： 		LED 关
参数：    void
返回：		void
说明：		参见原理图  端口置0时  关LED
*/
void Led_off(void){
	GPIO_ResetBits(LED_GPIO_PORT,LED1_GPIO_PIN|LED2_GPIO_PIN|LED3_GPIO_PIN|LED4_GPIO_PIN);	//端口置0 关闭LED
}


