/**********************718创新实验室开发板例程*********************
*  编写：718创新实验室	——ZZS
*  平台：STM32F103VET6
*  说明：由于作者的水平有限，若有不足之处，还请大家谅解。
*		 建议大家多看看数据手册。
*		 有问题，请联系我QQ523939208     by 718 ZZS       
******************************************************************/

/*************************功能说明******************************
通过SPI点亮OLED屏幕
什么是OLED:有机自发光体屏幕https://baike.baidu.com/item/OLED%E5%B1%8F%E5%B9%95/1688158?fr=aladdin
什么是SPI:参见百度百科
	https://baike.baidu.com/item/SPI/4429726?fr=aladdin
	OLED采用的不是标准的SPI通信,采用的4根线分别是:
	D0:SPI时钟控制线										A5
	D1:SPI数据传输线,MOSI穿出数据				A7
	RES:复位线,给一个脉冲低电平就复位		A3
	DC:数据/命令选择线,高电平数据,低电平数据  A1
OLED控制过程:
	初始化SPI控制器,初始化GPIO管脚->初始化OLED屏幕->向OLED屏幕写要显示的内容
****************************************************************/



#ifndef SPI_OLED_H								//防止重复定义头文件
#define SPI_OLED_H								//定义过头文件就不再定义,防止重复定义

#include <stm32f10x_spi.h>				//spi通信头文件
#include <stm32f10x_gpio.h>				//gpio头文件


#define OLED_SPI SPI1							//定义OLEDSPI为SPI1
#define OLED_RESET_PIN					GPIO_Pin_3	//定义OLED复位脚
#define OLED_COMMAND_DATA_PIN 	GPIO_Pin_1	//定义OLED数据指令切换脚

/*************************以下函数是OLED库函数,用户需要调用这些函数************************/

extern void OLED_Init(void);			//OLED初始化函数
extern void OLED_CLS(void);				//OLED清屏函数
extern void OLED_Print(unsigned char x,unsigned char y,unsigned char *ch);	//OLED输出字符函数
extern void OLED_PutPixel(unsigned char x, unsigned char y);

#endif
