
/*************** (C) COPYRIGHT  EW工作室 ***************************************
 * 文件名  ：uart.c
 * 描述    ：串口调试文件   
 * 实验平台：EW STM8入门板 V1.0
 * 库版本  ：V2.1.0
 * QQ群	   ：261825684
 * 修改时间：2013-08-20
*******************************************************************************/
/* 包含系统头文件 */
//#include <stdarg.h>
//#include <stdio.h>
/* 包含自定义头文件 */
#include "uart.h"

/* 自定义新类型 */

/* 自定义宏 */

/*实现函数部分*/

/*******************************************************************************
 * 名称: Uart_Init
 * 功能: UART1初始化操作
 * 形参: 无
 * 返回: 无
 * 说明: 无 
 ******************************************************************************/
void Uart1_Init(void)
{
   UART1_DeInit();	/* 将寄存器的值复位 */
	
	/*
	 * 将UART1配置为：
	 * 波特率 = 115200
	 * 数据位 = 8
	 * 1位停止位
	 * 无校验位
	 * 使能接收和发送
	 */


    UART1_Init((u32)115200, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, \
      UART1_PARITY_NO, UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TX_ENABLE);

 //  UART1_ITConfig(UART1_IT_RXNE_OR, ENABLE); //开启接收中断
    UART1_Cmd(ENABLE);
}



/*******************************************************************************
 * 名称: UART1_SendByte
 * 功能: UART1发送一个字节
 * 形参: data -> 要发送的字节
 * 返回: 无
 * 说明: 无 
 ******************************************************************************/
void UART1_SendByte(u8 data)
{
	UART1_SendData8((unsigned char)data);
	
	/* 等待传输结束 */
	while (UART1_GetFlagStatus(UART1_FLAG_TXE) == RESET);
}

/*******************************************************************************
 * 名称: UART1_SendString
 * 功能: UART1发送len个字符
 * 形参: data -> 指向要发送的字符串
 *       len -> 要发送的字节数
 * 返回: 无
 * 说明: 无 
 ******************************************************************************/
void UART1_SendString(u8* Data)
{
	u16 i=0;
	//for(; i < len; i++)
        while(Data[i]!='\0')
        {
           UART1_SendByte(Data[i]);	/* 循环调用发送一个字符函数 */
           i++;
        }
		
}

/*******************************************************************************
 * 名称: UART1_ReceiveByte
 * 功能: UART1接收一个字符
 * 形参: 无
 * 返回: 接收到的字符
 * 说明: 无 
 ******************************************************************************/
u8 UART1_ReceiveByte(void)
{
	u8 UART1_RX_BUF; 
	
	/* 等待接收完成 */
	while (UART1_GetFlagStatus(UART1_FLAG_RXNE) == RESET);
	
	UART1_RX_BUF = UART1_ReceiveData8();
	
	return  UART1_RX_BUF;
}

/*******************************************************************************
 * 名称: void putchar(char ch)
 * 功能: 打印一个字符
 * 形参: 需要输出的字符
 * 返回: 无
 * 说明: 无

 ******************************************************************************/
void putchar(char ch)		// print normal characters or '\n'
{	  
	if('\n' == ch)
	{
		UART1_SendByte('\r');
	}

	UART1_SendByte(ch);

}

/*******************************************************************************
 * 名称: void printf_str(unsigned char *buffer)
 * 功能: 打印字符串
 * 形参: 需要打印的字符串首地址
 * 返回: 无
 * 说明: 例如   printf_str("this is a uart test");

 ******************************************************************************/
void printf_str(unsigned char *buffer)
{
	while (*buffer != '\0')
	{
	    putchar(*buffer++);
    }
}

/*******************************************************************************
 * 名称: void putascbase(unsigned char ch)
 * 功能: 将字符转换成ASIC输出
 * 形参: 需要打印的字符
 * 返回: 无
 * 说明: 比如我们输出16进制55，在串口调试助手没勾上16进制显示，
 					这时就用putascbase(0x55);

 ******************************************************************************/
void putascbase(unsigned char ch)
{
	 unsigned char i, j;//,k;
	 //for(k = 0; k<4 ;k++)
	 {
	     i = (ch>>4) & 0x0f;
	     j = ch & 0x0f;
	     if (i>9) i += 7;
	
	     if (j>9) j += 7;
	     putchar(i+0x30);
	     putchar(j+0x30);
     }

//	 printf("\n");
}

/*******************************************************************************
 * 名称: void putasc(unsigned char ch)
 * 功能: 将字符转换成ASIC输出，换行
 * 形参: 需要打印的字符
 * 返回: 无
 * 说明: 无

 ******************************************************************************/
void putasc(unsigned char ch)
{
	 putascbase(ch);
	 putchar(' ');
//	 printf("\n");
}

/*******************************************************************************
 * 名称: void putascLong(unsigned long ch)
 * 功能: 输出一个4字节长度的字符
 * 形参: 需要输出的字符
 * 返回: 无
 * 说明: 无

 ******************************************************************************/
void putascLong(unsigned long ch)
{
	 unsigned char i, j,k;
	 for(k = 0; k<4 ;k++)
	 {
	     i = (((u8 *)&ch)[k]>>4) & 0x0f;
	     j = ((u8 *)&ch)[k] & 0x0f;
	     if (i>9) i += 7;
	
	     if (j>9) j += 7;
	     putchar(i+0x30);
	     putchar(j+0x30);
     }
	 putchar(' ');

}
/*******************************************************************************
 * 名称: void putascShort(unsigned short ch)
 * 功能: 输出一个2字节长度的字符
 * 形参: 需要输出的字符
 * 返回: 无
 * 说明: 无 

 ******************************************************************************/
void putascShort(unsigned short ch)
{
	 putascbase(ch>>8);
	 putascbase(ch>>0);
	 putchar(' ');
//	 printf("\n");	 //*/
}
/*******************************************************************************
 * 名称: void printf_array(unsigned char *buffer, unsigned short  cnt) 
 * 功能: 输出数组
 * 形参: 数组首地址，长度
 * 返回: 无
 * 说明: 输出BUF[10]
 					printf_array(BUF,10);

 ******************************************************************************/
void printf_array(unsigned char *buffer, unsigned short  cnt) 
{
	u16 i;
	for(i=0; i< cnt; i++)
	{
		putasc(buffer[i]);
		if(((i+1)%16)==0)
		    putchar('\n');	 
	}
		  
}   //*/


/******************* (C) COPYRIGHT EW工作室 *****END OF FILE******************/