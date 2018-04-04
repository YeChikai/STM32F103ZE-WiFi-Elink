

#include "bsp_spi.h"   



void elink_spi_gpio_config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  RCC_APB2PeriphClockCmd(SPI_nCS_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin = SPI_nCS_GPIO_PIN;    // CS
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(SPI_nCS_GPIO_PORT, &GPIO_InitStructure);

  RCC_APB2PeriphClockCmd(SPI_CLK_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin = SPI_CLK_GPIO_PIN;    // CLK
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(SPI_CLK_GPIO_PORT, &GPIO_InitStructure);
	
  RCC_APB2PeriphClockCmd(SPI_SDA_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin = SPI_SDA_GPIO_PIN;    //SDA
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(SPI_SDA_GPIO_PORT, &GPIO_InitStructure);

  RCC_APB2PeriphClockCmd(SPI_nDC_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin = SPI_nDC_GPIO_PIN;    //D/C
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(SPI_nDC_GPIO_PORT, &GPIO_InitStructure);
	
}


 /**
  * @brief  配置 SPI4W_WRITECOM 功能
  * @param  无
  * @retval 无
  */
void SPI4W_WRITECOM(unsigned char INIT_COM)
{
	unsigned char TEMPCOM;
	unsigned char scnt;
	TEMPCOM=INIT_COM;
	nCS_H;
	nCS_L;
	SCLK_L; 
	nDC_L;	//0 , CMD; 1 , DATA
	
	for(scnt=0;scnt<8;scnt++)
	{
		if(TEMPCOM&0x80)
			SDA_H;
		else
			SDA_L;
		
		Delay_us(1);
		SCLK_H;  
		Delay_us(1);
		SCLK_L;   
		TEMPCOM=TEMPCOM<<1;
		Delay_us(1);
	}
	
	nCS_H;  
}


 /**
  * @brief  配置 SPI4W_WRITECOM 功能
  * @param  无
  * @retval 无
  */
void SPI4W_WRITEDATA(unsigned char INIT_DATA)
{
	unsigned char TEMPCOM;
	unsigned char scnt;
	TEMPCOM=INIT_DATA;
	nCS_H;
	nCS_L;
	SCLK_L; 
	nDC_H;	//0 , CMD; 1 , DATA
	
	for(scnt=0;scnt<8;scnt++)
	{
		if(TEMPCOM&0x80)
			SDA_H;
		else
			SDA_L;
		
		Delay_us(1);
		SCLK_H;		
		Delay_us(1);
		SCLK_L;
		
		TEMPCOM=TEMPCOM<<1;
		Delay_us(1);
	}
	
	nCS_H; 
}



/*********************************************END OF FILE**********************/
