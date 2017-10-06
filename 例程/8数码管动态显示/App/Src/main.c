/**********************718创新实验室开发板例程*********************
*  编写：718创新实验室
*  平台：STM32F103VET6
*  说明：由于作者的水平有限，若有不足之处，还请大家谅解。
*		 建议大家多看看数据手册。     
******************************************************************/
/*************************功能说明********************************
数码管动态显示
*************************功能说明********************************/

#include "stm32f10x.h"
#include "module_74hc595.h"


void main()
{
	hc595_init();				//数码管初始化
	
	while(1)
	{
		DisplayScan(0,data_table[1]);		//显示时间
		DisplayScan(1,data_table[2]);
		DisplayScan(2,data_table[3]);
		DisplayScan(3,data_table[4]);
		DisplayScan(4,data_table[5]);
		DisplayScan(5,data_table[6]);
		DisplayScan(6,data_table[7]);
		DisplayScan(7,data_table[8]);
	}

	
}
