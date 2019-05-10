/********************************************************************
 *@file        adc.h
 *@author      Woody      QQ：2490006131
 *@version     V1.0
 *@date        2016-10-14
 *@brief       ADC 初始化以及通道切换
 *******************************************************************/

#ifndef __ADC_H
#define __ADC_H

#include "stm8s.h"

extern void Adc_Init(void);
extern u16 getConversionValue_PD2_AIN3(void);
extern u16 getConversionValue_PC4_AIN2(void);

#endif