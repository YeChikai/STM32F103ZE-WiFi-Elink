/**
  ******************************************************************************
  * @file    main.c
  * @author  Sky.Ye
  * @version V1.0
  * @date    2018-01-xx
  * @brief   ESP8266 WiFi + Elink 4.2inch ePaper模块测试
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火 iSO STM32 开发板 
  * 论坛    :http://www.chuxue123.com
  * 淘宝    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */ 
 
#include "include.h"
 
 

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main ( void )
{
	/* 初始化 */
  USARTx_Config();                                                              //初始化串口1
	
	SysTick_Init();                                                               //配置 SysTick 为 1ms 中断一次 
	
	ESP8266_Init();                                                               //初始化WiFi模块使用的接口和外设
	
	DHT11_Init();
	
  LED_Init();
	
	Beep_Init();
	
	FLASH_SPI_initialize();
	
	/**elink SPI init**/
	elink_spi_gpio_config();
	
	/**elink ePaper init**/
	elink_gpio_config();
	
	elink_display_init();
	
	Delay_ms(100);
	
	ELINK042_DispString_EN_CH( 128, 192, "Hello World...", WHITE); 
	ELINK042_DispString_EN_CH( 64, 64, "华为电子标签", WHITE); 
//	ELINK042_DispString_EN_CH( 128, 128, "HuaWei electric tag", WHITE); 
	
	DBG( "\r\n[BIRD] WF-ESP8266 WiFi模块测试...\r\n" );//打印测试例程提示信息

	ESP8266_StaTcpClient_UnvarnishTest();
	
	/************************power off Sequence************************/
	/**Vcom and data interval setting**/
	elink_soft_vcom_set();

	/**Power off**/
	elink_soft_power_switch(0);	
	
	/**deep sleep**/
	elink_soft_deep_sleep();
	/************************power off Sequence************************/	
 
  while( 1 )
	{
		//printf ( "\r\n[BIRD] elink ePaper 测试...\r\n" );                          //打印测试例程提示信息
		
		//Elink042DispChinaString( 16, 16, "野火开发板", WHITE); 

	
	}
	
	
}


/*********************************************END OF FILE**********************/
