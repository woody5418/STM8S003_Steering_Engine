/********************************************************************
 *@file        Servo.c
 *@author      IC爬虫      QQ：1394024051
 *@version     V1.0
 *@date        2014-9-10
 *@brief       舵机控制应用
 *******************************************************************/
#include "Servo.h"
/*******************************************************************************
 * 函数名：TIM2_Mode_Config
 * 描述  ：配置TIM2输出的PWM信号的模式，如周期、极性、占空比
 * 输入  ：无
 * 输出  ：无
 * 调用  ：内部调用
 ******************************************************************************/
static void TIM2_Mode_Config(void)
{
  TIM2_DeInit();
  TIM2_TimeBaseInit(TIM2_PRESCALER_8,40000);//MCLK=16MHZ,PWM周期为20ms
  TIM2_OC1Init(TIM2_OCMODE_PWM1,TIM2_OUTPUTSTATE_ENABLE,3000,TIM2_OCPOLARITY_HIGH);//PD4输出PWM，高电平1.5ms，舵机转到90°
  TIM2_OC2Init(TIM2_OCMODE_PWM1,TIM2_OUTPUTSTATE_ENABLE,3000,TIM2_OCPOLARITY_HIGH);//PD3输出PWM，高电平1.5ms，舵机转到90°
  TIM2_OC2PreloadConfig(ENABLE);
  TIM2_OC1PreloadConfig(ENABLE);
  TIM2_ARRPreloadConfig(ENABLE);
  TIM2_ITConfig(TIM2_IT_UPDATE, DISABLE);
  

  TIM2_GenerateEvent(TIM2_EVENTSOURCE_UPDATE);
  TIM2_Cmd(ENABLE);	
}
/*******************************************************************************
 * 函数名：Servo_Init
 * 描述  ：TIM3 输出PWM信号初始化，只要调用这个函数
 *         TIM3的四个通道就会有PWM信号输出
 * 输入  ：无
 * 输出  ：无
 * 调用  ：外部调用
 ******************************************************************************/
void Servo_Init(void)
{									   
  TIM2_Mode_Config();	
}

/*******************************************************************************
 * 函数名：Set_Servo_degree
 * 描述  ：操作寄存器改变占空时间，操作寄存器改变占空时间
 * 输入  ：degree-舵机转动的角度
 * 输出  ：无
 * 调用  ：外部调用
 ******************************************************************************/
void Set_Servo_degree(float degree)	 //degree 表示角度
{

  TIM2->CCR1H = (uint8_t)((1000+(uint16_t)((degree/180)*4000)) >> 8);
  TIM2->CCR1L = (uint8_t)(1000+(uint16_t)((degree/180)*4000));
}