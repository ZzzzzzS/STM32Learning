/*************************718开发板例程**********************
*   编写：718创新实验室
*		平台：STM32F103VET6科创培训开发板
*		说明：该例程使用官方库进行编写，由于作者的水平有限，
*								若有不足之处，
*还请大家见谅
*									建议大家多查阅数据手册，多在新生群和大家交流。
*************************************************************/

/*************************功能说明******************************
通过加速度传感器测量角度信息显示在数码管上
****************************************************************/

/*************************说明******************************
详细内容请查看
iic.c
MPU6050.c
module_74hc595.c
************************************************************/
#include "stm32f10x_it.h"
#include "MPU6050.h"
#include "iic.h"
#include "module_74hc595.h"

void showSomethings(int data) {
  int i = 0;
  int temp;
  //??????????????
  if (data < 0)
    data = -data;
  while (data / 10 != 0) {
    temp = data % 10;
    DisplayScan((7 - i++), data_table[temp]);
    data = data / 10;
  }
  DisplayScan(7 - i, data_table[data]);
}

void main() {
  int temp;
  //初始化6050和IIC设置
  Sys_Configuration();
  //初始化6050
  hc595_init();
  while (1) {
    temp = getTemperature();
    showSomethings(temp);
  }
}
