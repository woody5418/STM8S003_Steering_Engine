/********************************************************************
 *@file        Servo.h
 *@author      IC����     QQ��1394024051
 *@version     V1.0
 *@date        2014-9-10
 *@brief       �������Ӧ��
 *******************************************************************/
#ifndef __SERVO_H
#define __SERV0_H

#include "stm8s.h"
static void TIM2_Mode_Config(void);
void Servo_Init(void);
void Set_Servo_degree(float degree);

#endif