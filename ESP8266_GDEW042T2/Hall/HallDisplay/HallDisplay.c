/**
  ******************************************************************************
  * @file    HallDisplay.c
  * @author  Sky.Ye
  * @version V1.0
  * @date    2018-03-xx
  * @brief   ESP8266 WiFi + Elink 4.2inch ePaper模块测试
  ******************************************************************************/
	
#include "HallDisplay.h"
#include "ascii.h"

 
uint8_t OldBufferCN[32] = {0x00, 0x00, 0x00, 0x00,0x00, 0x00, 0x00, 0x00,0x00, 0x00, 0x00, 0x00,0x00, 0x00, 0x00, 0x00};
uint8_t OldBufferEN[16] = {0x00, 0x00, 0x00, 0x00,0x00, 0x00, 0x00, 0x00,0x00, 0x00, 0x00, 0x00,0x00, 0x00, 0x00, 0x00};
 
 

/**
 * @brief  在 Elink042 显示器上显示一个英文字符
 * @param  usX ：在特定扫描方向下字符的起始X坐标
 * @param  usY ：在特定扫描方向下该点的起始Y坐标
 * @param  cChar ：要显示的英文字符
 * @param  usColor_Background ：选择英文字符的背景色
 * @retval 无
 */
void Elink042_DispChar_EN( uint16_t usX, uint16_t usY, const char cChar, uint16_t usColor_Background)
{
	uint8_t ucRelativePositon, ucPage;
	uint8_t ucBuffer[16] = {0x00,0x00,0x00,0x66,0x66,0x66,0x66,0x7E,0x66,0x66,0x66,0x66,0x00,0x00,0x00,0x00};/*"H",40*/
	
	uint8_t x_start1 = usX >> 8;
	uint8_t x_start2 = usX & 0XFF;
	uint8_t x_end1 = (usX+WIDTH_EN_CHAR-1)>> 8;		//WIDTH_EN_CHAR
	uint8_t x_end2 = (usX+WIDTH_EN_CHAR-1)& 0XFF; //WIDTH_EN_CHAR
	
	uint8_t y_start1 = usY >> 8;
	uint8_t y_start2 = usY & 0XFF;
	uint8_t y_end1 = (usY+HEIGHT_EN_CHAR-1)>> 8; 
	uint8_t y_end2 = (usY+HEIGHT_EN_CHAR-1)& 0XFF;

	ucRelativePositon = cChar - ' ';	
		
	for( ucPage = 0; ucPage < HEIGHT_EN_CHAR; ucPage ++ )
	{
		ucBuffer[ucPage] = ucAscii_1608[ ucRelativePositon ] [ ucPage ];				
	}/* 全部写完 */
	
//	DBG( "\r\n[%s] x_start1 = 0x%2x,	x_start2 = %d, x_end1 = 0x%2x, x_end2 = %d\r\n", __FUNCTION__, x_start1, x_start2, x_end1, x_end2 );
//	DBG( "\r\n[%s] y_start1 = 0x%2x,	y_start2 = %d, y_end1 = 0x%2x, y_end2 = %d\r\n", __FUNCTION__, y_start1, y_start2, y_end1, y_end2 );
	
	partial_display(x_start1, x_start2,x_end1, x_end2, y_start1, y_start2, y_end1, y_end2, OldBufferEN, ucBuffer,EN_CHAR_0816_BYTE);
}

/**
 * @brief  在 Elink 显示器上显示一个中文字符
 * @param  usX ：在特定扫描方向下字符的起始X坐标
 * @param  usY ：在特定扫描方向下字符的起始Y坐标
 * @param  usChar ：要显示的中文字符（国标码） 
 * @retval 无
 */ 
void Elink042_DispChar_CN ( uint16_t usX, uint16_t usY, uint16_t usChar, uint16_t usColor_Background)
{
	uint8_t ucBuffer[32] = {0x00, 0x00};
 	
	uint8_t x_start1 = usX >> 8;
	uint8_t x_start2 = usX & 0XFF;
	uint8_t x_end1 = (usX+WIDTH_CH_CHAR-1)>> 8;
	uint8_t x_end2 = (usX+WIDTH_CH_CHAR-1)& 0XFF; 
	
	uint8_t y_start1 = usY >> 8;
	uint8_t y_start2 = usY & 0XFF;
	uint8_t y_end1 = (usY+HEIGHT_CH_CHAR-1)>> 8; 
	uint8_t y_end2 = (usY+HEIGHT_CH_CHAR-1)& 0XFF;
	   
  GetGBKCode( ucBuffer, usChar );	//取字模数据
	
	partial_display(x_start1, x_start2,x_end1, x_end2, y_start1, y_start2, y_end1, y_end2, OldBufferCN, ucBuffer, CN_CHAR_1616_BYTE);
		
}


/**
 * @brief  在 Elink 显示器上显示中文字符串
 * @param  usX ：在特定扫描方向下字符串的起始X坐标
 * @param  usY ：在特定扫描方向下字符串的起始Y坐标
 * @param  pStr ：要显示的英文字符串的首地址
 * @param  usColor_Background ：选择字符串的背景色
 * @retval 无
 */
void Elink042DispChinaString( uint16_t usX, uint16_t usY, const uint8_t * pStr, uint16_t usColor_Background)
{	
	uint16_t usCh;
		
	while( * pStr != '\0' )
	{		
		if ( ( usX - ELINK042_DispWindow_X_Star + WIDTH_CH_CHAR ) > ELINK042_DispWindow_COLUMN )
		{
			usX = ELINK042_DispWindow_X_Star;
			usY += HEIGHT_CH_CHAR;
		}
		
		if ( ( usY - ELINK042_DispWindow_Y_Star + HEIGHT_CH_CHAR ) > ELINK042_DispWindow_PAGE )
		{
			usX = ELINK042_DispWindow_X_Star;
			usY = ELINK042_DispWindow_Y_Star;
		}	
		
		usCh = * ( uint16_t * ) pStr;	
	  usCh = ( usCh << 8 ) + ( usCh >> 8 );//大、小端转换

		Elink042_DispChar_CN( usX, usY, usCh, usColor_Background );
		
		usX += WIDTH_CH_CHAR;
		
		pStr += 2;           //一个汉字两个字节 

	}	   
	
}


/**
 * @brief  在 ELINK042 显示器上显示中英文字符串
 * @param  usX ：在特定扫描方向下字符串的起始X坐标
 * @param  usY ：在特定扫描方向下字符串的起始Y坐标
 * @param  pStr ：要显示的字符串的首地址
 * @param  usColor_Background ：选择字符串的背景色
 * @retval 无
 */
void ELINK042_DispString_EN_CH ( uint16_t usX, uint16_t usY, const uint8_t * pStr, uint16_t usColor_Background )
{
	uint16_t usCh;
	
	SPI4W_WRITECOM(0X50);
	SPI4W_WRITEDATA(0x47);	//0x47 White background; 0x17 Black background

	lut1();		
	
	while( * pStr != '\0' )
	{
		if ( * pStr <= 126 )	           	//英文字符
		{
			if ( ( usX - ELINK042_DispWindow_X_Star + WIDTH_EN_CHAR ) > ELINK042_DispWindow_COLUMN )
			{
				usX = ELINK042_DispWindow_X_Star;
				usY += HEIGHT_EN_CHAR;
			}
			
			if ( ( usY - ELINK042_DispWindow_Y_Star + HEIGHT_EN_CHAR ) > ELINK042_DispWindow_PAGE )
			{
				usX = ELINK042_DispWindow_X_Star;
				usY = ELINK042_DispWindow_Y_Star;
			}			
		
		  Elink042_DispChar_EN( usX, usY, * pStr, usColor_Background);
			DBG( "\r\n[%s] English char: %c	\r\n",__FUNCTION__, * pStr );
			
			usX += WIDTH_EN_CHAR;
		
		  pStr++;

		}		
		else	                            //汉字字符
		{
			if ( ( usX - ELINK042_DispWindow_X_Star + WIDTH_CH_CHAR ) > ELINK042_DispWindow_COLUMN )
			{
				usX = ELINK042_DispWindow_X_Star;
				usY += HEIGHT_CH_CHAR;
			}
			
			if ( ( usY - ELINK042_DispWindow_Y_Star + HEIGHT_CH_CHAR ) > ELINK042_DispWindow_PAGE )
			{
				usX = ELINK042_DispWindow_X_Star;
				usY = ELINK042_DispWindow_Y_Star;
			}	
			
			usCh = * ( uint16_t * ) pStr;	
			
			usCh = ( usCh << 8 ) + ( usCh >> 8 );		

			Elink042_DispChar_CN( usX, usY, usCh, usColor_Background);
			DBG( "\r\n[%s] Chinese char: %ls \r\n",__FUNCTION__, ( uint16_t * ) pStr );
			
			usX += WIDTH_CH_CHAR;
			
			pStr += 2;           //一个汉字两个字节 
		
    }
		
  }
	
	DBG( "\r\n[%s] Display String complished !!!\r\n", __FUNCTION__ );	
} 


/*********************************************END OF FILE**********************/
