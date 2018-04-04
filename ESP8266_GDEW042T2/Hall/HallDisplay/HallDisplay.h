#ifndef __HALL_DISPLAY_H_
#define	__HALL_DISPLAY_H_


#include "include.h"



/***************** ILI934 显示屏全屏默认（扫描方向为1时）最大宽度和最大高度 *********************/
#define      ELINK042_Default_Max_Width		  400     //宽度
#define      ELINK042_Default_Max_Heigth		300     //高度


#define      WHITE		 		                  0xFFFF	   //白色
#define      BLACK                         	0x0000	   //黑色 



/***************************** ILI934 显示区域的起始坐标和总行列数 ***************************/
#define      ELINK042_DispWindow_X_Star		    0     //起始点的X坐标
#define      ELINK042_DispWindow_Y_Star		    0     //起始点的Y坐标

#define      ELINK042_DispWindow_COLUMN		  400     //总列数
#define      ELINK042_DispWindow_PAGE		    300     //总行数



/***************************** 在 ILI934 显示屏上显示的字符的大小 ***************************/
#define      WIDTH_EN_CHAR		             8	    //英文字符宽度 
#define      HEIGHT_EN_CHAR		            16		  //英文字符高度 

#define      EN_CHAR_0816_BYTE		            16		  //英文字符8*16字节数


#define      WIDTH_CH_CHAR		              16	    //中文字符宽度 
#define      HEIGHT_CH_CHAR		              16		  //中文字符高度 

#define      CN_CHAR_1616_BYTE		            32		  //中文字符16*16字节数


#define      GetGBKCode( ucBuffer, usChar )  GetGBKCode_from_EXFlash( ucBuffer, usChar )  //定义获取中文字符字模数组的函数名，ucBuffer为存放字模数组名，usChar为中文字符（国标码）



/************************** PAD 函数声明********************************/


void Elink042DispChinaString( uint16_t usX, uint16_t usY, const uint8_t * pStr, uint16_t usColor_Background ); 
void ELINK042_DispString_EN_CH ( uint16_t usX, uint16_t usY, const uint8_t * pStr, uint16_t usColor_Background );


#endif /* __HALL_DISPLAY_H_ */

