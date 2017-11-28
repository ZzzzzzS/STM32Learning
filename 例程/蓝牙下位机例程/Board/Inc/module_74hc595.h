#ifndef __74HC595__
#define __74HC595__

extern unsigned char data_table[];
extern unsigned char row[];

//宏定义替换代码块，减少函数中频繁操作IO口的代码量
#define OE(a)                                                                  \
  {                                                                            \
    if (a) {                                                                   \
      GPIO_SetBits(GPIOD, GPIO_Pin_0);                                         \
    } else {                                                                   \
      GPIO_ResetBits(GPIOD, GPIO_Pin_0);                                       \
    }                                                                          \
  }
#define SER(a)                                                                 \
  {                                                                            \
    if (a) {                                                                   \
      GPIO_SetBits(GPIOC, GPIO_Pin_12);                                        \
    } else {                                                                   \
      GPIO_ResetBits(GPIOC, GPIO_Pin_12);                                      \
    }                                                                          \
  }
#define RCLK(a)                                                                \
  {                                                                            \
    if (a) {                                                                   \
      GPIO_SetBits(GPIOC, GPIO_Pin_10);                                        \
    } else {                                                                   \
      GPIO_ResetBits(GPIOC, GPIO_Pin_10);                                      \
    }                                                                          \
  }
#define SRCLK(a)                                                               \
  {                                                                            \
    if (a) {                                                                   \
      GPIO_SetBits(GPIOC, GPIO_Pin_11);                                        \
    } else {                                                                   \
      GPIO_ResetBits(GPIOC, GPIO_Pin_11);                                      \
    }                                                                          \
  }
#define beeset(a)                                                              \
  {                                                                            \
    if (a) {                                                                   \
      GPIO_SetBits(GPIOC, GPIO_Pin_8);                                         \
    } else {                                                                   \
      GPIO_ResetBits(GPIOC, GPIO_Pin_8);                                       \
    }                                                                          \
  }

//初始化595相应引脚
extern void hc595_init(void);
//向595发送一个字
extern void Send_595(unsigned char dat);
//数码管显示
extern void DisplayScan(unsigned char column, unsigned char row);

#endif
