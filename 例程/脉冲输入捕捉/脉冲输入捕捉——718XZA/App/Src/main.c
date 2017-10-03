#include "stm32f10x.h"
#include "GeneralTIM.h"  
#include "module_74hc595.h"
/**
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
	

int main(void)
{
	uint32_t time;
	// TIM 计数器的驱动时钟
	uint32_t TIM_PscCLK = 72000000 / (GENERAL_TIM_PSC+1);
	
	
	/* 定时器初始化 */
	GENERAL_TIM_Init();
	/*数码管初始化*/
	hc595_init();
	
	
	while(1)
	{
		if(TIM_ICUserValueStructure.Capture_FinishFlag == 1)
		{
			// 计算高电平时间的计数器的值
			time = TIM_ICUserValueStructure.Capture_Period * (GENERAL_TIM_PERIOD+1) + 
			      (TIM_ICUserValueStructure.Capture_CcrValue+1);

						//在数码管上显示高电平脉宽时间
			Dispaly_M(time/TIM_PscCLK,time%TIM_PscCLK);
			
			
			TIM_ICUserValueStructure.Capture_FinishFlag = 0;			
		}		
	}
}
