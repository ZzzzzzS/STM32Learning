/**********************718创新实验室开发板例程*********************
*  编写：718创新实验室
*  平台：STM32F103VET6
*  说明：由于作者的水平有限，若有不足之处，还请大家谅解。
*		 建议大家多看看数据手册。     
******************************************************************/
/*************************功能说明********************************
通过外部中断实现按键控制led开关
*************************功能说明********************************/

#include "stm32f10x.h"
#include "led&beep.h"

void Key_Init()
{
	EXTI_InitTypeDef EXTI_InitStructure;													//外部中断配置信息结构体
	NVIC_InitTypeDef NVIC_InitStructure;													//中断优先级配置结构体
	GPIO_InitTypeDef GPIO_InitStructure;													//gpio控制结构体
	//使能用到的GPIO的时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);					//GPIOB
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;                    //管脚12
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;									//GPIO设置为上拉输入
  //传入配置信息结构体，初始化管脚
  GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);   						//优先级分配2:2
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);          //使能管脚复用时钟
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource12);  //将中断和GPIO连接
	
	//中断线和中断初始化配置
	EXTI_InitStructure.EXTI_Line = EXTI_Line12;										//因为引脚是GPIO15，使用15号中断线
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;						//配置模式为中断
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;				//下降沿触发中断
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;											//使能中断配置
	EXTI_Init(&EXTI_InitStructure);                               //传入中断信息，初始化
	
	//中断优先级配置
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;					//使能按键外部中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;				//抢占优先级为2
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;						//子优先级为2
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能配置
	NVIC_Init(&NVIC_InitStructure);																//传入配置信息，初始化
}

int main()
{
	LED_Init();																										//初始化led灯
	Key_Init();																										//初始化按键
	
	while(1)
  {
      LEDPower(LED1,Power_ON);//一直打开led灯,在中断里关闭
  }

}

void delay()					//延时
{
	int i,j;
	for(i=0;i<1000;i++)
	for(j=0;j<1000;j++);
	
	
}

void EXTI15_10_IRQHandler ()			//外部中断
{
	if(EXTI_GetITStatus(EXTI_Line12) != RESET)	//判断是不是12触发了中断
	{
		
		LEDPower(LED1,Power_OFF);									//关灯
		delay();
		EXTI_ClearITPendingBit(EXTI_Line12);			//清除中断标志位
	}
}
