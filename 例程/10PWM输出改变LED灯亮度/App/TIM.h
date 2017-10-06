#ifndef __TIM_H
#define __TIM_H


/************通用定时器TIM参数定义，只限TIM2、3、4、5************/
// 当使用不同的定时器的时候，对应的GPIO是不一样的，这点要注意
// 我们这里默认使用TIM3

#define            GENERAL_TIM                   TIM8
#define            GENERAL_TIM_APBxClock_FUN     RCC_APB2PeriphClockCmd
#define            GENERAL_TIM_CLK               RCC_APB2Periph_TIM8 
#define            GENERAL_TIM_Period            10
#define            GENERAL_TIM_Prescaler         71

// TIM3 输出比较通道3
#define            GENERAL_TIM_CH3_GPIO_CLK      RCC_APB2Periph_GPIOC
#define            GENERAL_TIM_CH3_PORT          GPIOC
#define            GENERAL_TIM_CH3_PIN           GPIO_Pin_8

// TIM3 输出比较通道4
#define            GENERAL_TIM_CH4_GPIO_CLK      RCC_APB2Periph_GPIOC
#define            GENERAL_TIM_CH4_PORT          GPIOC
#define            GENERAL_TIM_CH4_PIN           GPIO_Pin_9





#define LED1_GPIO_PORT    	GPIOC			              
#define LED1_GPIO_CLK 	    RCC_APB2Periph_GPIOC		
#define LED1_GPIO_PIN	    	GPIO_Pin_7			       


#define LED2_GPIO_PORT    	GPIOC			              
#define LED2_GPIO_CLK 	    RCC_APB2Periph_GPIOC		
#define LED2_GPIO_PIN		GPIO_Pin_8			        


#define LED3_GPIO_PORT    	GPIOC			              
#define LED3_GPIO_CLK 	    RCC_APB2Periph_GPIOC		
#define LED3_GPIO_PIN		GPIO_Pin_9			        


/** the macro definition to trigger the led on or off 
  * 1 - off
  *0 - on
  */
#define ON  0
#define OFF 1




/* 基本混色，后面高级用法使用PWM可混出全彩颜色,且效果更好 */


void LED_GPIO_Config(void);
/**************************函数声明********************************/

void GENERAL_TIM_Init(void);


#endif	/* __BSP_GENERALTIME_H */
