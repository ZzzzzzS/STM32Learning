#ifndef __TIM_H__
#define __TIM_H__
#define            BASIC_TIM_Period            1000-1   //定时周期
#define            BASIC_TIM_Prescaler         72-1     //分频因子  这里为71  分频数为71+1=72
#define						 BASIC_TIM									 TIM6      //定时器
#define            BASIC_TIM_IRQ               TIM6_IRQn   //定时器中断号
static void BASIC_TIM_Mode_Config(void);
static void BASIC_TIM_NVIC_Config(void);
void BASIC_TIM_IRQHandler (void);
extern void BASIC_TIM_Init(void);












#endif