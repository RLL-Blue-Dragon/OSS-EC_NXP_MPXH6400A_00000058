// License       : License.txt
// Specifications: Spec-MPXH6400A.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : MPXH6400A.h
// Reason for change: 01.00.00 : 20/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#ifndef __MPXH6400A_H__
#define __MPXH6400A_H__

#include "user_define.h"

// Components number
#define iMPXH6400A              121U                    // NXP MPXH6400A

// MPXH6400A System Parts definitions
#define iMPXH6400A_xoff         ( -0.00842F*iADC_vdd )  // X offset [V]
#define iMPXH6400A_yoff         0.0F                    // Y offset [kPa]
#define iMPXH6400A_gain         ( 0.002421F*iADC_vdd )  // Gain [V/kPa]
#define iMPXH6400A_max          400.0F                  // Pressure Max [kPa]
#define iMPXH6400A_min          20.0F                   // Pressure Min [kPa]

extern const tbl_adc_t tbl_MPXH6400A;

#endif /*__MPXH6400A_H__*/
