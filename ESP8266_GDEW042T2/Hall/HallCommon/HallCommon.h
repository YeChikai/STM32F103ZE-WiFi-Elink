#ifndef __HALLCOMMON_H
#define __HALLCOMMON_H


#include "include.h"


/******************************* 宏定义 ***************************/
#define            macNVIC_PriorityGroup_x                     NVIC_PriorityGroup_2



/********************************** 函数声明 ***************************************/
void                     USART_printf                       ( USART_TypeDef * USARTx, char * Data, ... );



#endif /* __HALLCOMMON_H */

