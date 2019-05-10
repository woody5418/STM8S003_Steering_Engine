/********************************************************************
 *@file        changyong.c
 *@author      
 *@version     V1.0
 *@date        2016-10-14
 *@brief       常用函数库
 *******************************************************************/

#include "changyong.h"

//延时函数 
/*//---  微秒级延时-------------------------- 
void Delayus(void) 
{  
    asm("nop"); //一个asm("nop")函数经过示波器测试代表100ns 
    asm("nop"); 
    asm("nop"); 
    asm("nop");  
} */

//---- 毫秒级延时程序----------------------- 
void Delayms(u32 time) 
{ 
    u16 i; 
    while(time--)   
    for(i=1590;i>0;i--) 
    {
    asm("nop"); //一个asm("nop")函数经过示波器测试代表100ns 
    asm("nop"); 
    asm("nop"); 
    asm("nop");
    }   
}
/*******************************************************************************
 * 函数名：Init_LED
 * 描述  ：配置LED的初始化
 * 输入  ：无
 * 输出  ：无
 * 调用  ：外部调用
 ******************************************************************************/
//---- 初始化LED----------------------- 
void Init_LED(void)
{
  GPIO_Init(GPIOD, GPIO_PIN_3, GPIO_MODE_OUT_PP_LOW_FAST);
  
  for(u8 i = 0;i < 3;)
  {
  Delayms(40);
  GPIO_WriteHigh(GPIOD, GPIO_PIN_3);
  Delayms(40);
  GPIO_WriteLow(GPIOD, GPIO_PIN_3);
  i++;
  }
}
/*******************************************************************************
 * 函数名：FLASH_Read_Word
 * 描述  ：EEPROM读取函数
 * 输入  ：u32（unsigned long）类型的地址
 * 输出  ：u32（unsigned long）类型的变量
 * 调用  ：外部调用
 ******************************************************************************/
//------eeprom读取一个u32————————
u32 FLASH_Read_Word(u32 Address_temp)
{
  u32 temp;
  temp = (u32)FLASH_ReadByte(Address_temp+3) | ((u32)FLASH_ReadByte(Address_temp+1) << 2) |\
         ((u32)FLASH_ReadByte(Address_temp+1) << 16) | ((u32)FLASH_ReadByte(Address_temp) << 24);
  
  return(temp);
  

}