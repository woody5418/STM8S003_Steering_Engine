/********************************************************************
 *@file        changyong.c
 *@author      
 *@version     V1.0
 *@date        2016-10-14
 *@brief       ���ú�����
 *******************************************************************/

#include "changyong.h"

//��ʱ���� 
/*//---  ΢�뼶��ʱ-------------------------- 
void Delayus(void) 
{  
    asm("nop"); //һ��asm("nop")��������ʾ�������Դ���100ns 
    asm("nop"); 
    asm("nop"); 
    asm("nop");  
} */

//---- ���뼶��ʱ����----------------------- 
void Delayms(u32 time) 
{ 
    u16 i; 
    while(time--)   
    for(i=1590;i>0;i--) 
    {
    asm("nop"); //һ��asm("nop")��������ʾ�������Դ���100ns 
    asm("nop"); 
    asm("nop"); 
    asm("nop");
    }   
}
/*******************************************************************************
 * ��������Init_LED
 * ����  ������LED�ĳ�ʼ��
 * ����  ����
 * ���  ����
 * ����  ���ⲿ����
 ******************************************************************************/
//---- ��ʼ��LED----------------------- 
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
 * ��������FLASH_Read_Word
 * ����  ��EEPROM��ȡ����
 * ����  ��u32��unsigned long�����͵ĵ�ַ
 * ���  ��u32��unsigned long�����͵ı���
 * ����  ���ⲿ����
 ******************************************************************************/
//------eeprom��ȡһ��u32����������������
u32 FLASH_Read_Word(u32 Address_temp)
{
  u32 temp;
  temp = (u32)FLASH_ReadByte(Address_temp+3) | ((u32)FLASH_ReadByte(Address_temp+1) << 2) |\
         ((u32)FLASH_ReadByte(Address_temp+1) << 16) | ((u32)FLASH_ReadByte(Address_temp) << 24);
  
  return(temp);
  

}