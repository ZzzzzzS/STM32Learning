/*************************718¿ª·¢°åÀı³Ì**********************

*   ±àĞ´£º718´´ĞÂÊµÑéÊÒ
*		Æ½Ì¨£ºSTM32F103VET6¿Æ´´ÅàÑµ¿ª·¢°å
*		ËµÃ÷£º¸ÃÀı³ÌÊ¹ÓÃ¹Ù·½¿â½øĞĞ±àĞ´£¬ÓÉÓÚ×÷ÕßµÄË®Æ½ÓĞÏŞ£¬ 
*								ÈôÓĞ²»×ãÖ®´¦£¬ »¹Çë´ó¼Ò¼ûÁÂ
*									½¨Òé´ó¼Ò¶à²éÔÄÊı¾İÊÖ²á£¬¶àÔÚĞÂÉúÈººÍ´ó¼Ò½»Á÷¡£

*************************************************************/
#include "include.h"
#include <stdio.h>

//ºê¶¨Òå ×ÜÏßÊ±ÖÓ GPIOÊ±ÖÓ ²¨ÌØÂÊ
#define USART_CLK RCC_APB1Periph_USART3
#define USART_GPIO_CLK RCC_APB2Periph_GPIOB
#define USART_BAUDRATE 115200
#define USARTx USART3
#define USARTx_APBxClkCmd RCC_APB1PeriphClockCmd

//USART GPIO¹Ü½Åºê¶¨Òå
#define USART_TX_GPIO_PORT GPIOB
#define USART_TX_GPIO_PIN GPIO_Pin_10
#define USART_RX_GPIO_PORT GPIOB
#define USART_RX_GPIO_PIN GPIO_Pin_11

void USART_Config(void);
void NVIC_Configuration(void);
void Usart_SendByte( USART_TypeDef * pUSARTx, uint8_t ch);
void Usart_SendString( USART_TypeDef * pUSARTx, char *str);
void Usart_SendHalfWord( USART_TypeDef * pUSARTx, uint16_t ch);
void USART3_IRQHandler(void); 

int main() {
	
	/*³õÊ¼»¯USART ÅäÖÃÄ£Ê½Îª 115200 8-N-1£¬*/
  USART_Config();
	
	/*·¢ËÍÒ»¸ö×Ö·û*/
	Usart_SendByte(USARTx,'*');
	/* ·¢ËÍÒ»¸ö×Ö·û´® */
	Usart_SendString( USARTx,"ÕâÊÇÒ»¸ö´®¿Ú½ÓÊÕ·¢ËÍ³ÌĞò\n");
	printf("718´´ĞÂÊµÑéÊÒ\n\n\n\n");
		
while(1){
	
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
  NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
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
º¯ÊıÃû£º void Usart_SendByte( USART_TypeDef * pUSARTx, uint8_t ch)
×÷ÓÃ£º 		·¢ËÍÒ»¸ö×Ö½Ú
²ÎÊı£º    USART_TypeDef * pUSARTx£¬ uint8_t ch
·µ»Ø£º		void
ËµÃ÷£º		ÏêÏ¸ËµÃ÷¿É¼ûÊı¾İÊÖ²á
*/
void Usart_SendByte( USART_TypeDef * pUSARTx, uint8_t ch)
{
	/* ·¢ËÍÒ»¸ö×Ö½ÚÊı¾İµ½USART */
	USART_SendData(pUSARTx,ch);
		
	/* µÈ´ı·¢ËÍÊı¾İ¼Ä´æÆ÷Îª¿Õ */
	while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET);	
}
/*
º¯ÊıÃû£º void Usart_SendArray( USART_TypeDef * pUSARTx, uint8_t *array, uint16_t num)
×÷ÓÃ£º 		·¢ËÍÒ»¸ö8Î»Êı×é
²ÎÊı£º    USART_TypeDef * pUSARTx, uint8_t *array, uint16_t num
·µ»Ø£º		void
ËµÃ÷£º		½«Êı×éÖĞ¸÷¸öÔªËØÒÀ´Î·¢ËÍ
*/
void Usart_SendArray( USART_TypeDef * pUSARTx, uint8_t *array, uint16_t num)
{
  uint8_t i;
	
	for(i=0; i<num; i++)
  {
	    /* ·¢ËÍÒ»¸ö×Ö½ÚÊı¾İµ½USART */
	    Usart_SendByte(pUSARTx,array[i]);	
  
  }
	/* µÈ´ı·¢ËÍÍê³É */
	while(USART_GetFlagStatus(pUSARTx,USART_FLAG_TC)==RESET);
}
/*
º¯ÊıÃû£º void Usart_SendString( USART_TypeDef * pUSARTx, char *str)
×÷ÓÃ£º 		·¢ËÍ×Ö·û´®
²ÎÊı£º    USART_TypeDef * pUSARTx, char *str
·µ»Ø£º		void
ËµÃ÷£º		
*/
void Usart_SendString( USART_TypeDef * pUSARTx, char *str)
{
	unsigned int k=0;
  do 
  {
      Usart_SendByte( pUSARTx, *(str + k) );
      k++;
  } while(*(str + k)!='\0');
  
  /* µÈ´ı·¢ËÍÍê³É */
  while(USART_GetFlagStatus(pUSARTx,USART_FLAG_TC)==RESET)
  {}
}
/*
º¯ÊıÃû£º Usart_SendHalfWord( USART_TypeDef * pUSARTx, uint16_t ch)
×÷ÓÃ£º 		·¢ËÍ16Î»µÄÊı
²ÎÊı£º    USART_TypeDef * pUSARTx, uint16_t ch
·µ»Ø£º		void
ËµÃ÷£º		ÏÈ·¢ËÍ¸ß°ËÎ»£¬ÔÙ·¢ËÍµÍ°ËÎ» È»ºóºÏ³É
*/
void Usart_SendHalfWord( USART_TypeDef * pUSARTx, uint16_t ch)
{
	uint8_t temp_h, temp_l;
	
	/* È¡³ö¸ß°ËÎ» */
	temp_h = (ch&0XFF00)>>8;
	/* È¡³öµÍ°ËÎ» */
	temp_l = ch&0XFF;
	
	/* ·¢ËÍ¸ß°ËÎ» */
	USART_SendData(pUSARTx,temp_h);	
	while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET);
	
	/* ·¢ËÍµÍ°ËÎ» */
	USART_SendData(pUSARTx,temp_l);	
	while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET);	
}
/*
º¯ÊıÃû£º int fputc(int ch, FILE *f)
×÷ÓÃ£º 		ÖØ¶¨Ïòc¿âº¯Êıprintfµ½´®¿Ú£¬ÖØ¶¨Ïòºó¿ÉÊ¹ÓÃprintfº¯Êı
²ÎÊı£º    int ch, FILE *f
·µ»Ø£º		ch
ËµÃ÷£º		printfÔÙ·¢ËÍÊ±ĞèÒªµ÷ÓÃfputcº¯Êı  ´Ë´¦½«¸Ãº¯ÊıÖØĞÂ¶¨Òå
*/
int fputc(int ch, FILE *f)
{
		/* ·¢ËÍÒ»¸ö×Ö½ÚÊı¾İµ½´®¿Ú */
		USART_SendData(USARTx, (uint8_t) ch);
		
		/* µÈ´ı·¢ËÍÍê±Ï */
		while (USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET);		
	
		return (ch);
}
/*
º¯ÊıÃû£º int fgetc(FILE *f)
×÷ÓÃ£º 		ÖØ¶¨Ïòc¿âº¯Êıscanfµ½´®¿Ú£¬ÖØĞ´Ïòºó¿ÉÊ¹ÓÃscanf¡¢getcharµÈº¯Êı
²ÎÊı£º    FILE *f
·µ»Ø£º		(int)USART_ReceiveData(USARTx)
ËµÃ÷£º		scanf½ÓÊÕÊ±ĞèÒªµ÷ÓÃfputcº¯Êı  ´Ë´¦½«¸Ãº¯ÊıÖØĞÂ¶¨Òå
*/
int fgetc(FILE *f)
{
		/* µÈ´ı´®¿ÚÊäÈëÊı¾İ */
		while (USART_GetFlagStatus(USARTx, USART_FLAG_RXNE) == RESET);

		return (int)USART_ReceiveData(USARTx);
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
void USART3_IRQHandler(void){
	uint8_t ucTemp;
	if(USART_GetITStatus(USARTx,USART_IT_RXNE)!=RESET)		//È·ÈÏÎª½ÓÊÕ¼Ä´æÆ÷¿ÕÖĞ¶Ï
	{		
		ucTemp = USART_ReceiveData(USARTx);
    USART_SendData(USARTx,ucTemp);    
	}	 
}
