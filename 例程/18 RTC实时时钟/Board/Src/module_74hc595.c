#include "stm32f10x_it.h"
#include "module_74hc595.h"

unsigned char data_table[] = {
    // 0     1    2    3    4    5    6    7    8    9    A    B    C    D    E
    // F
    0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,
    0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};
unsigned char row[] = {0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f};

/************************************************************
*初始化74HC595用到的各个引脚
************************************************************/
void hc595_init(void) {
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;          //管脚2
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  //管脚输出速度
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // GPIO设置为推挽输出
  GPIO_Init(GPIOD, &GPIO_InitStructure);

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
  GPIO_InitStructure.GPIO_Pin =
      GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12;       //管脚2
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  //管脚输出速度
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // GPIO设置为推挽输出
  GPIO_Init(GPIOC, &GPIO_InitStructure);
}
/************************************************************
*向595发送一个字
*参数:从原理图得到的字
************************************************************/
void Send_595(unsigned char dat) {
  unsigned char i;
  OE(0);
  for (i = 0; i < 8; i++) {
    if (dat & 0x80) {
      SER(1);
    } else {
      SER(0);
    }
    SRCLK(1);
    SRCLK(0);
    dat <<= 1;
  }
}
/************************************************************
*数码管显示
*参数:第几个数码管(从右到左)，显示内容
************************************************************/
void DisplayScan(unsigned char r, unsigned char data) {
  Send_595(row[r]);
  Send_595(data);
  RCLK(1);
  RCLK(0);
}
