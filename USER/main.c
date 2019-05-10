/*************** (C) COPYRIGHT  四维拓智 ***************************************
 * 文件名  ：main.c
 * 描述    ：工程模板    
 * 库版本  ：V1.1.0
 * 开发人员：Woody QQ：2490006131
 * 修改时间：2016-10-14
*******************************************************************************/


/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "sysclock.h"
#include "servo.h"
#include "changyong.h"
#include "uart.h"
#include "adc.h"

/*  Defines -----------------------------------------------------------*/
/*  Variate ---------------------------------------------------------*/
u16 adc_val1=0;
u16 angel=0;


int main(void)
{
  /* 系统时钟初始化 */
  SystemClock_Init();
  Init_LED();
  Uart1_Init();
  Servo_Init();
  GPIO_Init(GPIOD, GPIO_PIN_3, GPIO_MODE_OUT_PP_HIGH_FAST);  
  while (1)
  {
    adc_val1 = getConversionValue_PD2_AIN3();   
    angel = 1200 + adc_val1*39/10;//4993 - 1000   
    TIM2_SetCompare1(angel);
    TIM2_SetCompare2(adc_val1*39); 
  }

 }

#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif


/******************* (C) COPYRIGHT EW工作室 *****END OF FILE******************/
