/********************************************************************
 *@file        Servo.c
 *@author      IC����      QQ��1394024051
 *@version     V1.0
 *@date        2014-9-10
 *@brief       �������Ӧ��
 *******************************************************************/
#include "Servo.h"
/*******************************************************************************
 * ��������TIM2_Mode_Config
 * ����  ������TIM2�����PWM�źŵ�ģʽ�������ڡ����ԡ�ռ�ձ�
 * ����  ����
 * ���  ����
 * ����  ���ڲ�����
 ******************************************************************************/
static void TIM2_Mode_Config(void)
{
  TIM2_DeInit();
  TIM2_TimeBaseInit(TIM2_PRESCALER_8,40000);//MCLK=16MHZ,PWM����Ϊ20ms
  TIM2_OC1Init(TIM2_OCMODE_PWM1,TIM2_OUTPUTSTATE_ENABLE,3000,TIM2_OCPOLARITY_HIGH);//PD4���PWM���ߵ�ƽ1.5ms�����ת��90��
  TIM2_OC2Init(TIM2_OCMODE_PWM1,TIM2_OUTPUTSTATE_ENABLE,3000,TIM2_OCPOLARITY_HIGH);//PD3���PWM���ߵ�ƽ1.5ms�����ת��90��
  TIM2_OC2PreloadConfig(ENABLE);
  TIM2_OC1PreloadConfig(ENABLE);
  TIM2_ARRPreloadConfig(ENABLE);
  TIM2_ITConfig(TIM2_IT_UPDATE, DISABLE);
  

  TIM2_GenerateEvent(TIM2_EVENTSOURCE_UPDATE);
  TIM2_Cmd(ENABLE);	
}
/*******************************************************************************
 * ��������Servo_Init
 * ����  ��TIM3 ���PWM�źų�ʼ����ֻҪ�����������
 *         TIM3���ĸ�ͨ���ͻ���PWM�ź����
 * ����  ����
 * ���  ����
 * ����  ���ⲿ����
 ******************************************************************************/
void Servo_Init(void)
{									   
  TIM2_Mode_Config();	
}

/*******************************************************************************
 * ��������Set_Servo_degree
 * ����  �������Ĵ����ı�ռ��ʱ�䣬�����Ĵ����ı�ռ��ʱ��
 * ����  ��degree-���ת���ĽǶ�
 * ���  ����
 * ����  ���ⲿ����
 ******************************************************************************/
void Set_Servo_degree(float degree)	 //degree ��ʾ�Ƕ�
{

  TIM2->CCR1H = (uint8_t)((1000+(uint16_t)((degree/180)*4000)) >> 8);
  TIM2->CCR1L = (uint8_t)(1000+(uint16_t)((degree/180)*4000));
}