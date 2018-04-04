#ifndef __BSP_SPI_H_
#define	__BSP_SPI_H_


#include "stm32f10x.h"
#include "bsp_SysTick.h"


/****************************** LED 引脚配置参数定义***************************************/
#define             SPI_nCS_GPIO_CLK                        RCC_APB2Periph_GPIOB
#define             SPI_nCS_GPIO_PORT                       GPIOB
#define             SPI_nCS_GPIO_PIN                        GPIO_Pin_15

#define             SPI_CLK_GPIO_CLK                        RCC_APB2Periph_GPIOC
#define             SPI_CLK_GPIO_PORT                       GPIOC
#define             SPI_CLK_GPIO_PIN                        GPIO_Pin_7

#define             SPI_SDA_GPIO_CLK                        RCC_APB2Periph_GPIOB
#define             SPI_SDA_GPIO_PORT                       GPIOB
#define             SPI_SDA_GPIO_PIN                        GPIO_Pin_9

#define             SPI_nDC_GPIO_CLK                        RCC_APB2Periph_GPIOB
#define             SPI_nDC_GPIO_PORT                       GPIOB
#define             SPI_nDC_GPIO_PIN                        GPIO_Pin_13

/****************************** LED 函数宏定义***************************************/


#define SDA_H  GPIO_SetBits(SPI_SDA_GPIO_PORT, SPI_SDA_GPIO_PIN)	  //PD.8
#define SDA_L  GPIO_ResetBits(SPI_SDA_GPIO_PORT, SPI_SDA_GPIO_PIN)	  

#define SCLK_H GPIO_SetBits(SPI_CLK_GPIO_PORT, SPI_CLK_GPIO_PIN)	  //PD.9
#define SCLK_L GPIO_ResetBits(SPI_CLK_GPIO_PORT, SPI_CLK_GPIO_PIN)

#define nCS_H  GPIO_SetBits(SPI_nCS_GPIO_PORT, SPI_nCS_GPIO_PIN)	  //PD.10
#define nCS_L  GPIO_ResetBits(SPI_nCS_GPIO_PORT, SPI_nCS_GPIO_PIN)

#define nDC_H  GPIO_SetBits(SPI_nDC_GPIO_PORT, SPI_nDC_GPIO_PIN) //PE.15
#define nDC_L  GPIO_ResetBits(SPI_nDC_GPIO_PORT, SPI_nDC_GPIO_PIN)

/************************** PAD 函数声明********************************/

void elink_spi_gpio_config(void);
void SPI4W_WRITECOM(unsigned char INIT_COM);
void SPI4W_WRITEDATA(unsigned char INIT_DATA);
void SPI4W_WRITE(unsigned char INIT_COM,unsigned char INIT_DATA);

 
 

#endif /* __LED_H_ */

