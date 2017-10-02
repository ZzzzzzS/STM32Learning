/*************************718开发板例程**********************

*   编写：718创新实验室
*		平台：STM32F103VET6科创培训开发板
*		说明：该例程使用官方库进行编写，由于作者的水平有限， 
*								若有不足之处， 还请大家见谅
*									建议大家多查阅数据手册，多在新生群和大家交流。

*************************************************************/
/*************************功能说明******************************
将一句话写入flash(相当于电脑上的硬盘)中,再将这句话读取出来显示
flash读写过程:
	写入:
		解锁flash->删除flash上原有的文件->向flash中写入内容->重新给flash上锁
	读取:
		解锁flash->读取flash上的内容->重新给flash上锁

1.flash加锁主要是为了防止程序里误读写
2.flash读取和写入的时候都要2个字节或者4个字节的读取,否则会出错
3.单片机里的程序和数据都是存储在flash里的,读写flash一定要谨慎,
	否则容易出现严重的故障
****************************************************************/
#include "stm32f10x_it.h"			//stm32底层的头文件
#include "stm32f10x_flash.h"	//flash控制相关的头文件
#include "Spi-OLED.h"					//OLED屏幕控制相关头文件


#define FLASH_ADDRESS ((u32)0x08006000)		//flash写入的地址,就是往这个地址里面写东西

unsigned char DataToWrite[]={"Welcome To 718! "}; //准备写入的一句话
unsigned char DataToRead[20];											//准备接收这句话的数组

/*============================================
函数名：main()
作用：主函数,程序的入口
==========================================*/

int main()
{
	unsigned int counter=0;
	OLED_Init();													//初始化OLED屏幕
	OLED_Print(0,0,"Flash Test");					//在OLED屏幕坐标(0,0)写一句话
  FLASH_Unlock();												//flash解锁
	FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);//清除flash标志位(这一步也可以不要)
	while(FLASH_ErasePage(FLASH_ADDRESS)!=FLASH_COMPLETE);			//等待flash清楚之前存的内容
	
	for(counter=0;counter<15;counter+=2)	//flash写入
	{
		uint16_t temp=(uint16_t)(DataToWrite[counter]<<8|DataToWrite[counter+1]);
		FLASH_ProgramHalfWord(counter+FLASH_ADDRESS,(uint16_t)(temp));
	}
  FLASH_Lock();													//flash加锁
	OLED_Print(0,2,"Flash Write OK");			//OLED提示写入完成
/***************************写入完成******************************/
	FLASH_Unlock();												//flash解锁
	for(counter=0;counter<15;counter+=2)	//读取flash
	{
		int16_t temp = *(int16_t*)(counter+FLASH_ADDRESS);
		int16_t temp2=temp>>8;
		DataToRead[counter]=(char)temp2;
		DataToRead[counter+1]=(char)temp;
	}
	FLASH_Lock();		
	OLED_Print(0,4,"Flash Read OK");			//提示读取成功
	OLED_Print(0,6,DataToRead);						//屏幕上输出读取到的内容
	/***************************读取完成******************************/
}
