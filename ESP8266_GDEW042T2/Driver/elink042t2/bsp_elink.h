#ifndef __BSP_ELINK_H_
#define	__BSP_ELINK_H_


#include "stm32f10x.h"
#include "bsp_spi.h"
#include "bsp_SysTick.h"
#include "bsp_usart1.h"


/****************************** LED 引脚配置参数定义***************************************/
#define             LCD_RST_GPIO_CLK                       RCC_APB2Periph_GPIOB
#define             LCD_RST_GPIO_PORT                      GPIOB
#define             LCD_RST_GPIO_PIN                       GPIO_Pin_14

#define             LCD_BUSY_GPIO_CLK                      RCC_APB2Periph_GPIOB
#define             LCD_BUSY_GPIO_PORT                     GPIOB
#define             LCD_BUSY_GPIO_PIN                      GPIO_Pin_12

#define             LCD_BS_GPIO_CLK                        RCC_APB2Periph_GPIOE
#define             LCD_BS_GPIO_PORT                       GPIOE
#define             LCD_BS_GPIO_PIN                        GPIO_Pin_11


/****************************** LED 函数宏定义***************************************/
#define             LCD_RST_ON()                            GPIO_ResetBits ( LCD_RST_GPIO_PORT, LCD_RST_GPIO_PIN )
#define             LCD_RST_OFF()                           GPIO_SetBits ( LCD_RST_GPIO_PORT, LCD_RST_GPIO_PIN )
#define             LCD_RST_TOGGLE()                        GPIO_ReadOutputDataBit ( LCD_RST_GPIO_PORT, LCD_RST_GPIO_PIN ) ? \
                                                            GPIO_ResetBits ( LCD_RST_GPIO_PORT, LCD_RST_GPIO_PIN ) : GPIO_SetBits ( LCD_RST_GPIO_PORT, LCD_RST_GPIO_PIN )

#define             LCD_BUSY_ON()                            GPIO_ResetBits ( LCD_BUSY_GPIO_PORT, LCD_BUSY_GPIO_PIN )
#define             LCD_BUSY_OFF()                           GPIO_SetBits ( LCD_BUSY_GPIO_PORT, LCD_BUSY_GPIO_PIN )
#define             LCD_BUSY_TOGGLE()                        GPIO_ReadOutputDataBit ( LCD_BUSY_GPIO_PORT, LCD_BUSY_GPIO_PIN ) ? \
                                                            GPIO_ResetBits ( LCD_BUSY_GPIO_PORT, LCD_BUSY_GPIO_PIN ) : GPIO_SetBits ( LCD_BUSY_GPIO_PORT, LCD_BUSY_GPIO_PIN )

#define             LCD_BS_ON()                            GPIO_ResetBits ( LCD_BS_GPIO_PORT, LCD_BS_GPIO_PIN )
#define             LCD_BS_OFF()                           GPIO_SetBits ( LCD_BS_GPIO_PORT, LCD_BS_GPIO_PIN )
#define             LCD_BS_TOGGLE()                        GPIO_ReadOutputDataBit ( LCD_BS_GPIO_PORT, LCD_BS_GPIO_PIN ) ? \
                                                            GPIO_ResetBits ( LCD_BS_GPIO_PORT, LCD_BS_GPIO_PIN ) : GPIO_SetBits ( LCD_BS_GPIO_PORT, LCD_BS_GPIO_PIN )


#define nRST_H GPIO_SetBits(LCD_RST_GPIO_PORT, LCD_RST_GPIO_PIN)   		//PE.14
#define nRST_L GPIO_ResetBits(LCD_RST_GPIO_PORT, LCD_RST_GPIO_PIN)

#define nBUSY  GPIO_ReadInputDataBit(LCD_BUSY_GPIO_PORT, LCD_BUSY_GPIO_PIN) //PE.13

#define nBS_H  GPIO_SetBits(LCD_BS_GPIO_PORT, LCD_BS_GPIO_PIN)			//PE.11
#define nBS_L  GPIO_ResetBits(LCD_BS_GPIO_PORT, LCD_BS_GPIO_PIN)

//#define VPP_H	 GPIO_SetBits(GPIOA, GPIO_Pin_4)		//PA4
//#define VPP_L	 GPIO_ResetBits(GPIOA, GPIO_Pin_4)

/***************************变量定义******************************/



/************************** PAD 函数声明********************************/

void	elink_gpio_config(void);
void	elink_epd_w21_reset(void);
void	elink_check_busy_status(void);

void elink_booster_soft_start(void);
void elink_soft_panel_set(void);
void elink_soft_vcom_set(void);
void elink_soft_disp_refresh(void);
void elink_soft_deep_sleep(void);
void elink_soft_power_switch(unsigned char status);

void lut(void);
void lut1(void);

void elink_display_init(void);
void elink_framebuffer_display(const unsigned char * pStr);

void  partial_display(u8 x_start1, u8 x_start2, u8 x_end1, u8 x_end2, u8 y_start1, u8 y_start2, u8 y_end1, u8 y_end2, u8* pOldBuff, u8* pNewBuff, u16 length);



#endif /* __LED_H_ */

