#include "stm32f10x.h"
#include "stm32f10x_rtc.h"

typedef struct
{
	vu8 hour;
	vu8 min;
	vu8 sec;			
	vu16 w_year;
	vu8  w_month;
	vu8  w_date;
	
}RTCDate;


extern void RTCInit(void);
extern RTCDate RTC_Get(void);
