/*
********************************************************************************
[File]          : Config_UART.h
[Version]       : v0.1
[Processor]     : PIC24FJ256GB206
[Compiler]      : MPLAB C30
[Description]   : Macros and functions for UART
--------------------------------------------------------------------------------
[VERSION]	[DATE]   	[AUTHOR] 			CHANGES
 v0.1		07.10.2011	shashi.prakash@brigosha.com	Modified for PIC24F
********************************************************************************
*/
#ifndef __CONFIG_UART_H
#define __CONFIG_UART_H
 
#include "p24Fxxxx.h"
#include "p24FJ256GB210.h"

#include "Define.h"
#include "ELB_Osc.h"


/*** BAUD RATE MACROS ***/
#define M_300Hz     (S32)300
#define M_1200Hz    (S32)1200
#define M_2400Hz    (S32)2400
#define M_9600Hz    (S32)9600
#define M_10417Hz   (S32)10417
#define M_19_2KHz   (S32)19200
#define M_57_6KHz   (S32)57600
#define M_115_2KHz  (S32)115200

/*** BAUD RATE CONFIG MACROS ***/
#define M_BRGH_High   1
#define M_BRGH_Low    0

/*** INTERRUPT OPTIONS ***/
#define TX_INT_PRI0     0b10000000
#define TX_INT_PRI1     0b10010000
#define TX_INT_PRI2     0b10100000
#define TX_INT_PRI3     0b10110000
#define TX_INT_PRI4     0b11000000
#define TX_INT_PRI5     0b11010000
#define TX_INT_PRI6     0b11100000
#define TX_INT_PRI7     0b11110000

#define RX_INT_PRI0     0b00001000
#define RX_INT_PRI1     0b00001001
#define RX_INT_PRI2     0b00001010
#define RX_INT_PRI3     0b00001011
#define RX_INT_PRI4     0b00001100
#define RX_INT_PRI5     0b00001101
#define RX_INT_PRI6     0b00001110
#define RX_INT_PRI7     0b00001111

#define NO_INT_PRI0     0b00000000

/*** PUBLIC APIs ***/
S8 UART1_INIT(S32, U8, U8);
S8 UART2_INIT(S32, U8, U8);

void UART1_SEND_String(U8 *, U8);
void UART2_SEND_String(U8 *, U8);


#endif // End of header file UART_CONFIG.h

