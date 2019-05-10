/********************************************************************
 *@file        adc.c
 *@author      Woody      QQ：2490006131
 *@version     V1.0
 *@date        2016-10-14
 *@brief       ADC 初始化以及通道切换
 *******************************************************************/
#include "adc.h"
/*******************************************************************************
 * 函数名：Adc_Init
 * 描述  ：配置ADC1的初始化
 * 输入  ：无
 * 输出  ：无
 * 调用  ：外部调用
 ******************************************************************************/

void Adc_Init(void)
{
  ADC1_Cmd(ENABLE);
  ADC1_DeInit(); 
  ADC1_Init(ADC1_CONVERSIONMODE_CONTINUOUS, \
    ADC1_CHANNEL_3, ADC1_PRESSEL_FCPU_D2, ADC1_EXTTRIG_TIM, \
      DISABLE, ADC1_ALIGN_RIGHT, ADC1_SCHMITTTRIG_CHANNEL0, DISABLE);
  
  ADC1_Cmd(ENABLE);
  ADC1_StartConversion();

}
/*******************************************************************************
 * 函数名：getConversionValue_PD2_AIN3
 * 描述  ：获取PD2引脚（通道3）的ADC采样值
 * 输入  ：无
 * 输出  ：unsigned short 类型
 * 调用  ：外部调用
 ******************************************************************************/
u16 getConversionValue_PD2_AIN3(void)
{
    ADC1_DeInit();
    ADC1_Init(ADC1_CONVERSIONMODE_SINGLE,ADC1_CHANNEL_3,ADC1_PRESSEL_FCPU_D2,\
        ADC1_EXTTRIG_TIM,DISABLE,ADC1_ALIGN_RIGHT,ADC1_SCHMITTTRIG_CHANNEL3,DISABLE);
    ADC1_Cmd(ENABLE);
   
    //Flag status.
    FlagStatus adcReady;
    
    //Start conversion.
    ADC1_StartConversion();
    //Do while.
    do
    {
        //Get status.
        adcReady = ADC1_GetFlagStatus(ADC1_FLAG_EOC);
        
    }while(adcReady == RESET);
    //Return result.
    return ADC1_GetConversionValue();
}
/*******************************************************************************
 * 函数名：getConversionValue_PC4_AIN2
 * 描述  ：获取PD4引脚（通道2）的ADC采样值
 * 输入  ：无
 * 输出  ：unsigned short 类型
 * 调用  ：外部调用
 ******************************************************************************/
u16 getConversionValue_PC4_AIN2(void)
{
    ADC1_DeInit();
    //Set single conversion mode.
    /**< Single conversion mode */
    /**< Analog channel 3 */
    /**< Prescaler selection fADC1 = fcpu/6 */
    /**< Conversion from Internal TIM TRGO event */
    /** DISABLE ADC1_ExtTriggerState**/
    /**< Data alignment right */
    /**< Schmitt trigger disable on AIN3 */
    /**DISABLE ADC1_SchmittTriggerState*/
    ADC1_Init(ADC1_CONVERSIONMODE_SINGLE,ADC1_CHANNEL_2,ADC1_PRESSEL_FCPU_D2,\
        ADC1_EXTTRIG_TIM,DISABLE,ADC1_ALIGN_RIGHT,ADC1_SCHMITTTRIG_CHANNEL2,DISABLE);
    //Enable ADC1.
    ADC1_Cmd(ENABLE);
    
    //Flag status.
    FlagStatus adcReady;
    
    //Start conversion.
    ADC1_StartConversion();
    //Do while.
    do
    {
        //Get status.
        adcReady = ADC1_GetFlagStatus(ADC1_FLAG_EOC);
        
    }while(adcReady == RESET);
    //Return result.
    return ADC1_GetConversionValue();
}