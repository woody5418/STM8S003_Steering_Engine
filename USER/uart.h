/*************** (C) COPYRIGHT  EW������ ***************************************
 * �ļ���  ��uart.h
 * ����    �����ڵ����ļ�   
 * ʵ��ƽ̨��EW STM8���Ű� V1.0
 * ��汾  ��V2.1.0
 * QQȺ	   ��261825684
 * �޸�ʱ�䣺2013-08-20
*******************************************************************************/
#ifndef __UART_H
#define __UART_H

/* ����ϵͳͷ�ļ� */

/* �����Զ���ͷ�ļ� */
#include "stm8s.h"

/* �Զ����������� */


/* �Զ��峣����ͱ��ʽ�� */


/* �������ⲿʹ�õı��� */

/* �������ⲿʹ�õĺ��� */


void  Uart1_Init(void);
void  UART1_Send(u8 dat);
void  UART1_SendString(u8* Data);

void putchar(char ch);
void printf_str(unsigned char *buffer);
void putascbase(unsigned char ch);
void putasc(unsigned char ch);
void putascLong(unsigned long ch);
void putascShort(unsigned short ch);
void printf_array(unsigned char *buffer, unsigned short  cnt) ;


#endif

/******************* (C) COPYRIGHT EW������ *****END OF FILE******************/