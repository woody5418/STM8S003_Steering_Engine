/********************************************************************
 *@file        changyong.h
 *@author      Woody      QQ£º2490006131
 *@version     V1.0
 *@date        2016-10-14
 *@brief       ³£ÓÃº¯Êý¿â
 *******************************************************************/
#ifndef __CHANGYONG_H
#define __CHANGYONG_H

#define Out_High() GPIO_WriteHigh(GPIOA, GPIO_PIN_2); 
#define Out_Low() GPIO_WriteLow(GPIOA, GPIO_PIN_2);

#define In_Pin GPIO_PIN_1
#include "stm8s.h"


extern void Delayms(u32 time);
extern void Init_LED(void);
extern u32 FLASH_Read_Word(u32 Address_temp);



#endif