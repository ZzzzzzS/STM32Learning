/**********************718����ʵ���ҿ���������*********************

*  ����:718����ʵ����
*  ������:STM32F103VET6 718����ʵ���ҿ�����
*  ����:��������ˮƽ����,��������,����ʹ�ù����з������⻶ӭ���ָ��
*		
******************************************************************/
#include "stm32f10x_it.h"
#include "MPU6050.h"
#include "iic.h"
#include "module_74hc595.h"
#include "math.h"

void tim_init(void);
void showSomethings(int data);
void LED_Init(void);
void led_on(int tag);
void button_init(void);
void bee_init(void);
void bee_on(void);
void bee_off(void);
void pwm_init(void);
float angle_cal(void);

unsigned int time=0;
unsigned int time_led=0;
unsigned int time_display=0;
int angle=0;

uint16_t led_group[4]={GPIO_Pin_6,GPIO_Pin_7,GPIO_Pin_8,GPIO_Pin_9};

int main()
{
  //��ʼ��6050��IIC����
	Sys_Configuration();
	//��ʼ��6050
	hc595_init();
		DisplayScan(0,data_table[1]);		//ÏÔÊ¾Ê±¼ä
		DisplayScan(1,data_table[2]);
	
	
	
		DisplayScan(2,data_table[3]);
		DisplayScan(3,data_table[4]);
		DisplayScan(4,data_table[5]);
		DisplayScan(5,data_table[6]);
		DisplayScan(6,data_table[7]);
		DisplayScan(7,data_table[8]);
	DisplayScan(0,data_table[1]);		//ÏÔÊ¾Ê±¼ä
		DisplayScan(1,data_table[2]);
		DisplayScan(2,data_table[3]);
		DisplayScan(3,data_table[4]);
		DisplayScan(4,data_table[5]);
		DisplayScan(5,data_table[6]);
		DisplayScan(6,data_table[7]);
		DisplayScan(7,data_table[8]);
	DisplayScan(0,data_table[1]);		//ÏÔÊ¾Ê±¼ä
		DisplayScan(1,data_table[2]);
		DisplayScan(2,data_table[3]);
		DisplayScan(3,data_table[4]);
		DisplayScan(4,data_table[5]);
		DisplayScan(5,data_table[6]);
		DisplayScan(6,data_table[7]);
		DisplayScan(7,data_table[8]);
		DisplayScan(0,data_table[1]);		//ÏÔÊ¾Ê±¼ä
		DisplayScan(1,data_table[2]);
		DisplayScan(2,data_table[3]);
		DisplayScan(3,data_table[4]);
		DisplayScan(4,data_table[5]);
		DisplayScan(5,data_table[6]);
		DisplayScan(6,data_table[7]);
		DisplayScan(7,data_table[8]);
		DisplayScan(0,data_table[1]);		//ÏÔÊ¾Ê±¼ä
		DisplayScan(1,data_table[2]);
		DisplayScan(2,data_table[3]);
		DisplayScan(3,data_table[4]);
		DisplayScan(4,data_table[5]);
		DisplayScan(5,data_table[6]);
		DisplayScan(6,data_table[7]);
		DisplayScan(7,data_table[8]);
		DisplayScan(0,data_table[1]);		//ÏÔÊ¾Ê±¼ä
		DisplayScan(1,data_table[2]);
		DisplayScan(2,data_table[3]);
		DisplayScan(3,data_table[4]);
		DisplayScan(4,data_table[5]);
		DisplayScan(5,data_table[6]);
		DisplayScan(6,data_table[7]);
		DisplayScan(7,data_table[8]);
		DisplayScan(0,data_table[1]);		//ÏÔÊ¾Ê±¼ä
		DisplayScan(1,data_table[2]);
		DisplayScan(2,data_table[3]);
		DisplayScan(3,data_table[4]);
		DisplayScan(4,data_table[5]);
		DisplayScan(5,data_table[6]);
		DisplayScan(6,data_table[7]);
		DisplayScan(7,data_table[8]);
		DisplayScan(0,data_table[1]);		//ÏÔÊ¾Ê±¼ä
		DisplayScan(1,data_table[2]);
		DisplayScan(2,data_table[3]);
		DisplayScan(3,data_table[4]);
		DisplayScan(4,data_table[5]);
		DisplayScan(5,data_table[6]);
		DisplayScan(6,data_table[7]);
		DisplayScan(7,data_table[8]);
		DisplayScan(0,data_table[1]);		//ÏÔÊ¾Ê±¼ä
		DisplayScan(1,data_table[2]);
		DisplayScan(2,data_table[3]);
		DisplayScan(3,data_table[4]);
		DisplayScan(4,data_table[5]);
		DisplayScan(5,data_table[6]);
		DisplayScan(6,data_table[7]);
		DisplayScan(7,data_table[8]);
		
	tim_init();
	LED_Init();
	button_init();
	bee_init();
	pwm_init();
	
	while(1)
	{
		showSomethings(angle);
		
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)==0)
		{
			if(GPIO_ReadOutputDataBit(GPIOD,GPIO_Pin_14))
				GPIO_ResetBits(GPIOD,GPIO_Pin_14);
			else
				GPIO_SetBits(GPIOD,GPIO_Pin_14);
			bee_on();
		}
		
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13)==0)
		{
			if(GPIO_ReadOutputDataBit(GPIOD,GPIO_Pin_15))
				GPIO_ResetBits(GPIOD,GPIO_Pin_15);
			else
				GPIO_SetBits(GPIOD,GPIO_Pin_15);
			bee_on();
		}
	}
}



void tim_init(void)
{
		NVIC_InitTypeDef NVIC_InitStructure; 
		TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);		
    NVIC_InitStructure.NVIC_IRQChannel =TIM6_IRQn;	
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	 
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;	
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
	
		
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);
    TIM_TimeBaseStructure.TIM_Period = 1000-1;	
    TIM_TimeBaseStructure.TIM_Prescaler= 72-1;
    TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure);
    TIM_ClearFlag(TIM6, TIM_FLAG_Update);
    TIM_ITConfig(TIM6,TIM_IT_Update,ENABLE);
    TIM_Cmd(TIM6, ENABLE);
}

void  TIM6_IRQHandler (void)
{
	static int led_tag=0;
	if ( TIM_GetITStatus( TIM6, TIM_IT_Update) != RESET ) 
	{
		if(time>200)
		{
			angle=(int)angle_cal();
			time=0;
			//All color led
			TIM_SetCompare2(TIM2,2000);
			TIM_SetCompare3(TIM2,(7119-(angle>0? angle:0)*10)<0? 0:7119-angle*10);
			TIM_SetCompare4(TIM2,2000);
		}
		else
			time++;
		
		if(time_led>500)
		{
			if(led_tag>3)
				led_tag=0;
			led_on(led_tag++);
			time_led=0;
			bee_off();
		}
		else
			time_led++;
		
		TIM_ClearITPendingBit(TIM6 , TIM_FLAG_Update);  		 
	}
}

void showSomethings(int data)
{
		int i=0;
	  int  temp;
 		//������ʾÿ��λ
		if(data<0)
			data=-data;
		while(data/10!=0)
		{
			temp=data%10;
			DisplayScan((7-i++),data_table[temp]);
			data=data/10;
		}
		DisplayScan(7-i,data_table[data]);
}


void LED_Init(void)					//led???									
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD, ENABLE);	 //??PC,PD???
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;				 //LED1-->PC.9???
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //????
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO????50MHz
 GPIO_Init(GPIOC, &GPIO_InitStructure);					 //?????????GPIOC.0
 GPIO_SetBits(GPIOC,GPIO_Pin_9);						 //PC.9 ???

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;	    		 //LED2-->PC.8 ????, ????
 GPIO_Init(GPIOC, &GPIO_InitStructure);	  				 //???? ,IO????50MHz
 GPIO_SetBits(GPIOC,GPIO_Pin_8); 						 //PC.8 ??? 
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;	    		 //LED3-->PC.7 ????, ????
 GPIO_Init(GPIOC, &GPIO_InitStructure);	  				 //???? ,IO????50MHz
 GPIO_SetBits(GPIOC,GPIO_Pin_7); 						 //PC.2 ??? 

		
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;	    		 //LED4-->PC.6 ????, ????
 GPIO_Init(GPIOC, &GPIO_InitStructure);	  				 //???? ,IO????50MHz
 GPIO_SetBits(GPIOC,GPIO_Pin_6); 						 //PC.6 ??? 
 
 	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;	    		 //LED5-->PD.15 ????, ????
 GPIO_Init(GPIOD, &GPIO_InitStructure);	  				 //???? ,IO????50MHz
 GPIO_SetBits(GPIOD,GPIO_Pin_15); 						 //PCD.15 ??? 
 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;	    		 //LED6-->PD.14 ????, ????
 GPIO_Init(GPIOD, &GPIO_InitStructure);	  				 //???? ,IO????50MHz
 GPIO_SetBits(GPIOD,GPIO_Pin_14); 						 //PCD.14 ??? 
}


void led_on(int tag)
{
	int i;
	for(i=0;i<4;i++)
	{
		if(i==tag)
			GPIO_ResetBits(GPIOC,led_group[i]);
		else
			GPIO_SetBits(GPIOC,led_group[i]);
	}
}

void button_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;						
  RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13;			
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void bee_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;						
  RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOE, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;			
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOE, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOE,GPIO_Pin_12);
}

void bee_on(void)
{
	GPIO_SetBits(GPIOE,GPIO_Pin_12);
}

void bee_off(void)
{
	GPIO_ResetBits(GPIOE,GPIO_Pin_12);
}

void pwm_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA  | RCC_APB2Periph_AFIO, ENABLE);
	
 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
 
	TIM_TimeBaseStructure.TIM_Period = 7119;    //10KHz
 	TIM_TimeBaseStructure.TIM_Prescaler =0;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_Pulse=0;

	TIM_OC2Init(TIM2, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);

	TIM_OC3Init(TIM2, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);

	TIM_OC4Init(TIM2, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);
 
	TIM_Cmd(TIM2, ENABLE);
}

float angle_cal(void)
{
	float x,y,z,temp;
	x=((float)getAccX())/16384;
	y=((float)getAccY())/16384;
	z=((float)getAccZ())/16384;
	temp=sqrt(x*x+y*y)/z;
	temp=atan(temp);
	
	return temp*180/3.14;
}
