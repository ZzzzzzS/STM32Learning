/*************************718蓝牙下位机例程*********************

*   编写：718创新实验室
*		平台：STM32F103VET6科创培训开发板
*		说明：该例程使用官方库进行编写，由于作者的水平有限， 
*								若有不足之处， 还请大家见谅
*									建议大家多查阅数据手册，多在新生群和大家交流。
*关于更详细的说明,可以访问http://zzshub.cn/2017/11/28/%E6%96%B0%E7%94%9F%E6%9D%AF%E6%99%BA%E8%83%BD%E8%BD%A6%E8%B5%9B%E8%93%9D%E7%89%99%E6%8E%A5%E6%94%B6%E7%AB%AF/

*************************************************************/
#ifndef __SERIALPORT_H__
#define __SERIALPORT_H__

#include <stm32f10x.h>
#define BUFFERSIZE 20 //缓冲区大小,一般不需要修改
typedef enum    //暂时没用的枚举
{
	Function1Clicked = 0x01,
	Function2Clicked = 0x02,
	Function3Clicked = 0x04,
	Function4Clicked = 0x08,
	FSTOPClicked     = 0x10,
	ReservedFunction = 0x20
} serialPortInformationType;


typedef struct		//储存接收到的信息的结构体
{
	int GoSpeed;		//前进速度
	int GoSpeedOld;
	int TurnSpeed;	//转向速度
	int TurnSpeedOld;
	uint8_t OtherInfo;
	unsigned char serialPortQueueBuffer[BUFFERSIZE+5];	//接收缓冲区
} serialPortInfo;


extern void addSerialPortDate(unsigned char data,serialPortInfo *this); //向缓冲区添加数据
extern void serialPortexec(serialPortInfo *serialPortInfo);							//在while里面循环判断信息
extern void speedchangeEvent(int xSpeed,int ySpeed);										//车速发生改变会执行这个函数
extern void function1ButtonClickedEvent(void);					//按键被按下会执行这个函数
extern void function2ButtonClickedEvent(void);
extern void function3ButtonClickedEvent(void);
extern void function4ButtonClickedEvent(void);
extern void stopButtonClickedEvent(void);

#endif
