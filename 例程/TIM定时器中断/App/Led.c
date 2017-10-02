#include  "include.h"


/*---------------------------*/
/*--------此函数功能---------*/
/*红灯--------PB5
  蓝灯--------PB1
  绿灯--------PB0*/
void LED_GPIO_Config(void)
	{
GPIO_InitTypeDef GPIO_InitStructure;//新建GPIO初始化结构体

RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);//开启GPIOB通道时钟

GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;//管脚设置

GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//输出模式推挽输出

GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//输出频率50M


		 GPIO_Init(GPIOB, &GPIO_InitStructure);    //初始化GPIOB
		///
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;//管脚设置

GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//输出模式推挽输出

GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//输出频率50M
GPIO_Init(GPIOB, &GPIO_InitStructure);    //初始化GPIOB
		///
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;//管脚设置

GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//输出模式推挽输出

GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//输出频率50M
GPIO_Init(GPIOB, &GPIO_InitStructure);    //初始化GPIOB
////
		GPIO_SetBits(GPIOB,GPIO_Pin_5);//关闭红色灯
		GPIO_SetBits(GPIOB,GPIO_Pin_0);//关闭绿色灯
		GPIO_SetBits(GPIOB,GPIO_Pin_1);//关闭蓝色灯

}
	/*typedef enum colour {
		chi,
		cheng,
		huang,
		lv,
		lan,
		dian,
		zi,
}colour;
	
void  colourselect(colour C)
{
	
}*/
void Colour_Red()
	{
			GPIO_ResetBits(GPIOB,GPIO_Pin_5);
		GPIO_SetBits(GPIOB,GPIO_Pin_0);
		GPIO_SetBits(GPIOB,GPIO_Pin_1);
	}
void Colour_Green()
{
		GPIO_SetBits(GPIOB,GPIO_Pin_5);
		GPIO_ResetBits(GPIOB,GPIO_Pin_0);
		GPIO_SetBits(GPIOB,GPIO_Pin_1);
}
void Colour_Blue()
{
		GPIO_SetBits(GPIOB,GPIO_Pin_5);
		 GPIO_SetBits(GPIOB,GPIO_Pin_0);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_1); 
}
void Delay_ms(int a)
{
	int i,k;
		for(i=a;i>0;i--)
		for(k=72000;k>0;k--)
		{
			__nop;
		};
}