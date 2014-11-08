/* 
 * File:   xbee.h
 * Author: kunal-laptop
 *
 * Created on October 29, 2014, 12:15 AM
 */

#ifndef XBEE_H
#define	XBEE_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <uart.h>
#include <PPS.h>
#include <incap.h>
#include <outcompare.h>

#include "AVIX.h"
#include "Define.h"
#include "ELBv21_HardwareConfig.h"
#include "ELB_OSC.h"
#include "ELB_Timer.h"
#include "ELB_UART.h"
#include "ELB_LCD.h"

TAVIX_THREAD_REGULAR xbee_thread(void* p);
//
//    // 7E000F1701000000000000FFFFFFFE02444264
//    U8 com_atdb_broad[] = {0x7E, 0x00, 0x0F, 0x17, 0x01, 0x00, 0x00, 0x00, 0x00,
//        0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFE, 0x02, 0x44, 0x42, 0x64};
//
//    // 7E000F17010013A20040B79714FFFE0244420B
//    U8 com_atdb_ref1[] = {0x7E, 0x00, 0x0F, 0x17, 0x01, 0x00, 0x13, 0xA2, 0x00,
//        0x40, 0xB7, 0x97, 0x14, 0xFF, 0xFE, 0x02, 0x44, 0x42, 0x0B};
//
//    // 7E000F17010013A20040B79712FFFE0244420D
//    U8 com_atdb_ref2[] = {0x7E, 0x00, 0x0F, 0x17, 0x01, 0x00, 0x13, 0xA2, 0x00,
//        0x40, 0xB7, 0x97, 0x12, 0xFF, 0xFE, 0x02, 0x44, 0x42, 0x0D};
//
//    // 7E000F17010013A20040B796E8FFFE02444238
//    U8 com_atdb_ref3[] = {0x7E, 0x00, 0x0F, 0x17, 0x01, 0x00, 0x13, 0xA2, 0x00,
//        0x40, 0xB7, 0x96, 0xE8, 0xFF, 0xFE, 0x02, 0x44, 0x42, 0x38};
//
//    // sample response -> 7E 00 10 97 01 00 13 A2 00 40 AC C4 49 00 00 44 42 00 29 0A
//
//    // 7E 00 0C 00 01 00 00 00 00 00 00 FF FF 00 61 9F
//    U8 com_atrp_broad[] = {0x7E, 0x00, 0x0F, 0x17, 0x01, 0x00, 0x00, 0x00, 0x00,
//        0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFE, 0x02, 0x44, 0x42, 0x64};
//
//    // 7E 00 0C 00 01 00 13 A2 00 40 B7 97 14 00 61 46
//    U8 com_atrp_ref1[] = {0x7E, 0x00, 0x0F, 0x17, 0x01, 0x00, 0x13, 0xA2, 0x00,
//        0x40, 0xB7, 0x97, 0x14, 0xFF, 0xFE, 0x02, 0x44, 0x42, 0x0B};
//
//    // 7E 00 0C 00 01 00 13 A2 00 40 B7 97 12 00 61 48
//    U8 com_atrp_ref2[] = {0x7E, 0x00, 0x0F, 0x17, 0x01, 0x00, 0x13, 0xA2, 0x00,
//        0x40, 0xB7, 0x97, 0x12, 0xFF, 0xFE, 0x02, 0x44, 0x42, 0x0D};
//
//    // 7E 00 0C 00 01 00 13 A2 00 40 B7 96 E8 00 61 73
//    U8 com_atrp_ref3[] = {0x7E, 0x00, 0x0F, 0x17, 0x01, 0x00, 0x13, 0xA2, 0x00,
//        0x40, 0xB7, 0x96, 0xE8, 0xFF, 0xFE, 0x02, 0x44, 0x42, 0x38};

    // sample response ->


#ifdef	__cplusplus
}
#endif

#endif	/* XBEE_H */

