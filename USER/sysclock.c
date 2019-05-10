
/*************** (C) COPYRIGHT  EW工作室 ***************************************
 * 文件名  ：sysclock.c
 * 描述    ：系统时钟设置    
 * 实验平台：EW STM8入门板 V1.0
 * 库版本  ：V2.1.0
 * QQ群	   ：261825684
 * 修改时间：2013-08-20
*******************************************************************************/

/* 包含系统头文件 */

/* 包含自定义头文件 */
#include "sysclock.h"

/* 自定义新类型 */

/* 自定义宏 */

//#define HSE_Enable

/*******************************************************************************
 * 名称: Sysclock_Init
 * 功能: 设置系统时钟频率
 * 形参: 无
 * 返回: 无
 * 说明: 时钟选择

 ******************************************************************************/
void SystemClock_Init(void)
{
//使用宏定义的写法
#ifdef  HSE_Enable
     while (!CLK_ClockSwitchConfig(CLK_SWITCHMODE_AUTO, CLK_SOURCE_HSE, DISABLE,\
            CLK_CURRENTCLOCKSTATE_DISABLE));
     //切换到外部时钟,并等待时钟却换成功
#else
     CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
#endif   

}


/******************* (C) COPYRIGHT EW工作室 *****END OF FILE******************/

