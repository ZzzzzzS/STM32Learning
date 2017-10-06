#include "MatrixKeyboard.h"

void KeyInit(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; //定义结构体变量	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);		//打开相应的时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_14|GPIO_Pin_15;		//选择你要设置的IO口
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;         	//推挽输出
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	   			//设置传输速率
	GPIO_Init(GPIOB,&GPIO_InitStructure);		

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8|GPIO_Pin_9;	  	//选择你要设置的IO口
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;         	//推挽输出
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	   			//设置传输速率
	GPIO_Init(GPIOD,&GPIO_InitStructure);	  
	
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING ;  			//输入
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;   //设置传输速率
	GPIO_Init(GPIOD,&GPIO_InitStructure);
}

char KeyClicked(void)
{
	char key=0;
	/******操作第一列按键*******/

	GPIO_ResetBits(GPIOD,GPIO_Pin_8); // 高
	GPIO_SetBits(GPIOD,GPIO_Pin_9);   //低
	GPIO_SetBits(GPIOB,GPIO_Pin_14|GPIO_Pin_15);
	if(GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_13)==0)
	{ 
	  if(GPIO_ReadOutputDataBit(GPIOD, GPIO_Pin_13)==0)//确定按键被按下
		key=11;
	}
	else if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_12)==0)
	 {
		
	  if(GPIO_ReadOutputDataBit(GPIOD, GPIO_Pin_12)==0)//确定按键被按下
		key=21;
	 }
	else if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_11)==0)
	{
		
	  if( GPIO_ReadOutputDataBit(GPIOD, GPIO_Pin_11)==0)//确定按键被按下
		key=31;
	}
	else if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_10)==0)
	{
   	if( GPIO_ReadOutputDataBit(GPIOD, GPIO_Pin_10)==0)//确定按键被按下
		key=41;
	}
	/*****操作第二列按键******/
	GPIO_SetBits(GPIOB,GPIO_Pin_15);            // 设置为低电平
	GPIO_SetBits(GPIOD,GPIO_Pin_8);    // 设置为高电平
	GPIO_ResetBits(GPIOD,GPIO_Pin_9);               // 设置为高电平
	GPIO_SetBits(GPIOB,GPIO_Pin_14);            // 设置为低电平
	if(GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_13)==0)
	{
	  if(GPIO_ReadOutputDataBit(GPIOD, GPIO_Pin_13)==0)//确定按键被按下
		key=12;
	}
	else if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_12)==0)
	{
  	if(GPIO_ReadOutputDataBit(GPIOD, GPIO_Pin_12)==0)//确定按键被按下
		key=22;
	}
	else if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_11)==0)
	{
	  if( GPIO_ReadOutputDataBit(GPIOD, GPIO_Pin_11)==0)//确定按键被按下
		key=32;
	}
	else if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_10)==0)
	{
   	if( GPIO_ReadOutputDataBit(GPIOD, GPIO_Pin_10)==0)//确定按键被按下
		key=42;
	}

	/******操作第三列按键******/
	GPIO_SetBits(GPIOD,GPIO_Pin_8);            // 设置为低电平
	GPIO_SetBits(GPIOD,GPIO_Pin_9);               // 设置为高电平
	GPIO_ResetBits(GPIOB,GPIO_Pin_15);       // 设置为高电平
	GPIO_SetBits(GPIOB,GPIO_Pin_14);            // 设置为低电平
	if(GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_13)==0)
	{
	  if(GPIO_ReadOutputDataBit(GPIOD, GPIO_Pin_13)==0)//确定按键被按下
		key=13;
	}
	else if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_12)==0)
	{
	  if(GPIO_ReadOutputDataBit(GPIOD, GPIO_Pin_12)==0)//确定按键被按下
		key=23;
	}
	else if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_11)==0)
	{
	  if( GPIO_ReadOutputDataBit(GPIOD, GPIO_Pin_11)==0)//确定按键被按下
		key=33;
	}
 else if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_10)==0)
	{
   	if( GPIO_ReadOutputDataBit(GPIOD, GPIO_Pin_10)==0)//确定按键被按下
		key=43;
	}
		
   /*****操作第四列按键*****/
	GPIO_SetBits(GPIOD,GPIO_Pin_9); //设置为低电平
	GPIO_SetBits(GPIOD,GPIO_Pin_8);   //设置为高电平
	GPIO_ResetBits(GPIOB,GPIO_Pin_14);//设置为高电平
	GPIO_SetBits(GPIOD,GPIO_Pin_15);   //设置为高电平
	if(GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_13)==0)
	{
	  if(GPIO_ReadOutputDataBit(GPIOD, GPIO_Pin_13)==0)//确定按键被按下
		key=14;
	}
	else if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_12)==0)
	 {
		
	  if(GPIO_ReadOutputDataBit(GPIOD, GPIO_Pin_12)==0)//确定按键被按下
		key=24;
	 }
	else if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_11)==0)
	{
		
	  if( GPIO_ReadOutputDataBit(GPIOD, GPIO_Pin_11)==0)//确定按键被按下
		key=34;
	}
	else if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_10)==0)
	{
	
	  if( GPIO_ReadOutputDataBit(GPIOD, GPIO_Pin_10)==0)//确定按键被按下
		key=44;
	}

	return key;
	
}