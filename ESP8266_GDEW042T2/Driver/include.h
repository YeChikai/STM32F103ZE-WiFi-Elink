/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.h 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   This file contains the headers of the interrupt handlers.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __INCLUDE_H
#define __INCLUDE_H

#include <stdio.h>  
#include <string.h>  
#include <stdbool.h>
#include <stdarg.h>

#include "stm32f10x.h"

#include "bsp_esp8266.h"
#include "bsp_SysTick.h"
#include "bsp_dht11.h"
#include "bsp_beep.h"
#include "bsp_led.h"
#include "bsp_gpio.h"
#include "bsp_usart1.h"
#include "bsp_spi.h" 
#include "bsp_elink.h" 
#include "fatfs_flash_spi.h"

#include "HallCommon.h"
#include "HallWIFI.h"
#include "HallDisplay.h"

//#include "DisplayBuffer.h"


#endif /* __INCLUDE_H */


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
