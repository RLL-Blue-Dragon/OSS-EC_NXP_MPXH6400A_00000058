// License       : License.txt
// Specifications: Spec-00000058.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : MPXH6400A_00000058.cpp
// BSL              : 00000058
// Model number     : NXP MPXH6400A
// Spec               Component type       : ADC
//                    OS                   : Mbed
//                    Calculation          : Floating-point
//                    Conversion type      : Linear
//                    Moving average filter: Moving average filter select
//                    Diagnosis            : Range (Min to Max)
// Reason for change: 01.00.00 : 20/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include "MPXH6400A.h"

AnalogIn MPXH6400A_adc( iMPXH6400A_pin , iVref );       // AnalogIn object

// Main Function
pp2ap_adc_t MPXH6400A_00000058( void )
{
        pp2ap_adc_t res = pp_00000058( MPXH6400A_adc , tbl_MPXH6400A );
        return( res );
}
