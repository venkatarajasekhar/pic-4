/* 
 * File:   ELB_Timer.h
 * Author: Shashu
 *
 * Created on 17 October, 2012, 12:28 PM
 */

#ifndef ELB_TIMER_H
#define	ELB_TIMER_H

#include <p24FJ256GB206.h>
#include "Define.h"
#include "ELB_Osc.h"

/**** Interrupt Options ***/
#define TMR_INT_PRI0     0b00001000
#define TMR_INT_PRI1     0b00001001
#define TMR_INT_PRI2     0b00001010
#define TMR_INT_PRI3     0b00001011
#define TMR_INT_PRI4     0b00001100
#define TMR_INT_PRI5     0b00001101
#define TMR_INT_PRI6     0b00001110
#define TMR_INT_PRI7     0b00001111

/*** Public APIs ***/
void TIMER1_INIT(F32 , U8);
void TIMER2_INIT(F32 , U8);
void TIMER3_INIT(F32 , U8);

void TIMER23_INIT(F32 , U8);
void TIMER45_INIT(F32 , U8);

#endif	/* ELB_TIMER_H */
