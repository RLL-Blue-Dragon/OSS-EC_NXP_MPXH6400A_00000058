// License       : License.txt
// Specifications: Spec-MPXH6400A.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : MPXH6400A.cpp
// Reason for change: 01.00.00 : 20/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include        "MPXH6400A.h"

#if     iMPXH6400A_ma == iSMA                           // Simple moving average filter
static float32 MPXH6400A_sma_buf[iMPXH6400A_SMA_num];
static sma_f32_t MPXH6400A_Phy_SMA =
{
        iInitial ,                                      // Initial state
        iMPXH6400A_SMA_num ,                            // Simple moving average number & buf size
        0U ,                                            // buffer position
        0.0F ,                                          // sum
        &MPXH6400A_sma_buf[0]                           // buffer
};

#elif   iMPXH6400A_ma == iEMA                           // Exponential moving average filter
static ema_f32_t MPXH6400A_Phy_EMA =
{
        iInitial ,                                      // Initial state
        0.0F ,                                          // Xn-1
        iMPXH6400A_EMA_K                                // Exponential smoothing factor 
};

#elif   iMPXH6400A_ma == iWMA                           // Weighted moving average filter
static float32 MPXH6400A_wma_buf[iMPXH6400A_WMA_num];
static wma_f32_t MPXH6400A_Phy_WMA =
{
        iInitial ,                                      // Initial state
        iMPXH6400A_WMA_num ,                            // Weighted moving average number & buf size
        0U ,                                            // buffer poition
        iMPXH6400A_WMA_num * (iMPXH6400A_WMA_num + 1)/2 , // kn sum
        &MPXH6400A_wma_buf[0]                           // Xn buffer
};

#else                                                   // Non-moving average filter
#endif

#define iDummy_adr       0xffffffff                     // Dummy address

const tbl_adc_t tbl_MPXH6400A =
{
        iMPXH6400A              ,
        iMPXH6400A_pin          ,
        iMPXH6400A_xoff         ,
        iMPXH6400A_yoff         ,
        iMPXH6400A_gain         ,
        iMPXH6400A_max          ,
        iMPXH6400A_min          ,
        iMPXH6400A_ma           ,
        
#if     iMPXH6400A_ma == iSMA                            // Simple moving average filter
        &MPXH6400A_Phy_SMA      ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#elif   iMPXH6400A_ma == iEMA                            // Exponential moving average filter
        (sma_f32_t*)iDummy_adr  ,
        &MPXH6400A_Phy_EMA      ,
        (wma_f32_t*)iDummy_adr
#elif   iMPXH6400A_ma == iWMA                            // Weighted moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        &MPXH6400A_Phy_WMA
#else                                                   // Non-moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#endif

};
