/*************************************************************************
 *
 *    Used with ICCARM and AARM.
 *
 *    (c) Copyright IAR Systems 2006
 *
 *    File name   : adc.h
 *    Description : Analog to Digital Converter definitions
 *
 *    History :
 *    1. Date        : Aug 11, 2006
 *       Author      : Todor Atanasov
 *       Description : Created
 *
 *    2. Date        : Oct 15, 2007
 *       Author      : Dimitar Peikov
 *       Description : Changed to Analog.
 *
 *    $Revision:   1.3  $
**************************************************************************/
#ifndef  __ADC_H
#define  __ADC_H

#include <ioat91sam7x256.h>

enum ADC_CHANNEL_LIST {
	ADC_CHANNEL_0,
	ADC_CHANNEL_1,
	ADC_CHANNEL_2,
	ADC_CHANNEL_3,
	ADC_CHANNEL_4,
	ADC_CHANNEL_5,
	ADC_CHANNEL_6,
	ADC_CHANNEL_7,
	ADC_CHANNEL_MAX
};

/*!************************************************************************
 * \fn HRESULT ADC_Init( void )
 * AT91PS_PMC pPMC, AT91PS_ADC pADC
 * \param pPMC pointer to PMC controller
 * \param pADC pointer to ADC controller
 * \return ADC initialization status
 * \brief ADC module initialization
 *  It is expected to have this later :
 * 	AT91F_ADC_CfgTimings( pADC, 48, 2, 128, 128000 );
 *************************************************************************/
HRESULT ADC_Init( void );

/*!************************************************************************
 * \fn HRESULT ADC_GetChannel(U8 nChannel, U32 *pValue)
 * \param nChannel    The desired channel
 * \param pValue	  Pointer to U32 variable that will receive measured data
 * \return        ADC operation result
 * \brief  Starts blocked A/D conversion from a desired channel and returns
 *              the result.
 *************************************************************************/
HRESULT ADC_GetChannel(U8 channel, U32 *pValue);

/*!************************************************************************
 * \fn HRESULT ADC_SetTiming(U32 nMCK_Clock, U32 nADC_Clock , U32 nStartupTime, U32 nSampleTime )
 * \param nMCK_Clock    The desired channel
 * \param nADC_Clock	  Pointer to U32 variable that will receive measured data
 * \return ADC operation result
 * \brief  Sets timing parameters for ADC controller.
 *************************************************************************/
HRESULT ADC_SetTiming(U32 nMCK_Clock, U32 nADC_Clock, U32 nStartupTime, U32 nSampleTime );

#endif  /* __ADC_H */
