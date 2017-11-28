/*************************718¿ª·¢°åÀı³Ì**********************

*   ±àĞ´£º718´´ĞÂÊµÑéÊÒ
*		Æ½Ì¨£ºSTM32F103VET6¿Æ´´ÅàÑµ¿ª·¢°å
*		ËµÃ÷£º¸ÃÀı³ÌÊ¹ÓÃ¹Ù·½¿â½øĞĞ±àĞ´£¬ÓÉÓÚ×÷ÕßµÄË®Æ½ÓĞÏŞ£¬ 
*								ÈôÓĞ²»×ãÖ®´¦£¬ »¹Çë´ó¼Ò¼ûÁÂ
*									½¨Òé´ó¼Ò¶à²éÔÄÊı¾İÊÖ²á£¬¶àÔÚĞÂÉúÈººÍ´ó¼Ò½»Á÷¡£

*************************************************************/
#include "include.h"
#include <stdio.h>
#include "SerialPortImformation.h"

//ºê¶¨Òå ×ÜÏßÊ±ÖÓ GPIOÊ±ÖÓ ²¨ÌØÂÊ
#define USART_CLK RCC_APB2Periph_USART1
#define USART_GPIO_CLK RCC_APB2Periph_GPIOA
#define USART_BAUDRATE 115200
#define USARTx USART1
#define USARTx_APBxClkCmd RCC_APB2PeriphClockCmd

//USART GPIO¹Ü½Åºê¶¨Òå
#define USART_TX_GPIO_PORT GPIOA
#define USART_TX_GPIO_PIN GPIO_Pin_9
#define USART_RX_GPIO_PORT GPIOA
#define USART_RX_GPIO_PIN GPIO_Pin_10

void USART_Config(void);
void NVIC_Configuration(void);
void Usart_SendByte( USART_TypeDef * pUSARTx, uint8_t ch);
void Usart_SendString( USART_TypeDef * pUSARTx, char *str);
void Usart_SendHalfWord( USART_TypeDef * pUSARTx, uint16_t ch);
void USART1_IRQHandler(void); 

	serialPortInfo blueToothInfo; //ÅĞ¶Ï´®¿ÚĞÅÏ¢ĞèÒªµÄ½á¹¹Ìå

int main() {

	
	/*³õÊ¼»¯USART ÅäÖÃÄ£Ê½Îª 115200 8-N-1£¬*/
  USART_Config();

	printf("718´´ĞÂÊµÑéÊÒ\n\n\n\n");
		
while(1){
	serialPortexec(&blueToothInfo); //ÔÚwhile1µ±ÖĞÒ»Ö±ÅĞ¶ÏÊÇ²»ÊÇÓĞÓĞÓÃµÄÖ¸Áî
}

}


/*
º¯ÊıÃû£º void USART_Config(void)
×÷ÓÃ£º 		USART³õÊ¼»¯
²ÎÊı£º    void
·µ»Ø£º		void
ËµÃ÷£º		USART1 Ê¹ÓÃAPB2 Ê±ÖÓ ÆäËûÊ¹ÓÃAPB1Ê±ÖÓ£
					ÏêÏ¸ÉèÖÃ¿É¼ûÊı¾İÊÖ²á
*/
void USART_Config(void){
	GPIO_InitTypeDef GPIO_InitStructure;		//GPIO³õÊ¼»¯½á¹¹Ìå
	USART_InitTypeDef USART_InitStructure;	//USART³õÊ¼»¯½á¹¹Ìå
	//´ò¿ªGPIOÊ±ÖÓ
	RCC_APB2PeriphClockCmd(USART_GPIO_CLK,ENABLE);
	//´ò¿ª´®¿ÚÍâÉèÊ±ÖÓ
	USARTx_APBxClkCmd(USART_CLK,ENABLE);
	// ½«USART TxµÄGPIOÅäÖÃÎªÍÆÍì¸´ÓÃÄ£Ê½
	GPIO_InitStructure.GPIO_Pin = USART_TX_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(USART_TX_GPIO_PORT, &GPIO_InitStructure);
  // ½«USART RxµÄGPIOÅäÖÃÎª¸¡¿ÕÊäÈëÄ£Ê½
	GPIO_InitStructure.GPIO_Pin = USART_RX_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(USART_RX_GPIO_PORT, &GPIO_InitStructure);
// ÅäÖÃ´®¿ÚµÄ¹¤×÷²ÎÊı
	// ÅäÖÃ²¨ÌØÂÊÎª115200
	USART_InitStructure.USART_BaudRate = USART_BAUDRATE;
	// ÅäÖÃ ÕëÊı¾İ×Ö³¤Îª8Î»
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	// ÅäÖÃÍ£Ö¹Î» 1Î»
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	// ÅäÖÃĞ£ÑéÎ» ²»¼ìÑé
	USART_InitStructure.USART_Parity = USART_Parity_No ;
	// ÅäÖÃÓ²¼şÁ÷¿ØÖÆ  ÎŞ
	USART_InitStructure.USART_HardwareFlowControl = 
	USART_HardwareFlowControl_None;
	// ÅäÖÃ¹¤×÷Ä£Ê½£¬ÊÕ·¢Ò»Æğ
	USART_InitStructure.USART_Mode =  USART_Mode_Rx|USART_Mode_Tx;
	// Íê³É´®¿ÚµÄ³õÊ¼»¯ÅäÖÃ
	USART_Init(USARTx, &USART_InitStructure);
	//Ê¹ÄÜUSART
	USART_Cmd(USARTx,ENABLE);
	//ÖĞ¶Ï³õÊ¼»¯
	NVIC_Configuration();
	//Ê¹ÄÜUSART½ÓÊÕÖĞ¶Ï
	USART_ITConfig(USARTx, USART_IT_RXNE, ENABLE);	
	
}
/*
º¯ÊıÃû£º NVIC_Configuration(void)
×÷ÓÃ£º 		³õÊ¼»¯ÖĞ¶Ï
²ÎÊı£º    void
·µ»Ø£º		void
ËµÃ÷£º		ÏêÏ¸ĞÅÏ¢¿É¼û¼¼ÊõÊÖ²á
*/
void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  
  /* Ç¶Ì×ÏòÁ¿ÖĞ¶Ï¿ØÖÆÆ÷×éÑ¡Ôñ  ÇÀ¶ÏÓÅÏÈ¼¶Á½Î» ×ÓÓÅÏÈ¼¶Á½Î» */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  
  /* ÅäÖÃUSARTÎªÖĞ¶ÏÔ´ */
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
  /* ÇÀ¶ÏÓÅÏÈ¼¶*/
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  /* ×ÓÓÅÏÈ¼¶ */
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  /* Ê¹ÄÜÖĞ¶Ï */
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  /* ³õÊ¼»¯ÅäÖÃNVIC */
  NVIC_Init(&NVIC_InitStructure);
}



/*
º¯ÊıÃû£º	USART3_IRQHandler(void)
×÷ÓÃ£º 		¶ÁÈ¡½ÓÊÕµ½µÄÊı¾İ ²¢»Ø·¢
²ÎÊı£º    void
·µ»Ø£º		void
ËµÃ÷£º		Ê¹ÄÜÖĞ¶Ïºó£¬µ±±êÖ¾Î»USART_IT_RXNEÎª1Ê±£¨½ÓÊÕ¼Ä´æÆ÷·Ç¿Õ£© ½øÈëÖĞ¶Ï
					Èç¹ûÍâ½çÓĞ¶à¸öÖĞ¶ÏÇëÇóÔ´ ¸÷¸öÖĞ¶ÏÔ´¾ù»áÒıÆğUSART3_IRQÖĞ¶Ï  ËùÒÔĞèÒªÔÚÖĞ¶ÏÄÚ²¿ÅĞ¶Ï¾ßÌåÎªÄÄÒ»ÖĞ¶ÏÇëÇóÔ´ÒıÆğµÄÖĞ¶Ï
					ÏêÏ¸ÏêÏ¸¿É¼û¼¼ÊõÊÖ²á
*/
void USART1_IRQHandler(void){
	uint8_t ucTemp;
	if(USART_GetITStatus(USARTx,USART_IT_RXNE)!=RESET)		//È·ÈÏÎª½ÓÊÕ¼Ä´æÆ÷¿ÕÖĞ¶Ï
	{		
		ucTemp = USART_ReceiveData(USARTx);
		addSerialPortDate(ucTemp,&blueToothInfo);				//Õâ¾ÍÊÇÌí¼ÓÊı¾İµ½½á¹¹ÌåÖĞ
	}	 
}
int fputc(int ch, FILE *f)  //¾¯¸æÉ¾³ıÕâ¸öº¯Êı¾Í»áµ¼ÖÂprintf¹¤×÷²»Õı³£,Èç¹û²»ĞèÒªprintfÒ²¿ÉÒÔÉ¾³ı
{
		USART_SendData(USARTx, (uint8_t) ch);
		while (USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET);		
		return (ch);
}
void function1ButtonClickedEvent()							//üÒÈç¹û¹¦ÄÜ¼üÒ»±»°´ÏÂ,¾Í»áÖ´ĞĞÕâ¸öº¯Êı
{
	//ÔÚÕâÀïĞ´¹¦ÄÜ¼üÒ»±»°´ÏÂĞèÒªÖ´ĞĞµÄ²Ù×÷°É
}
