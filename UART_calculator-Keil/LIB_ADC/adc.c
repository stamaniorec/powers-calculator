/*************************************************************************
 *
 *    Used with ICCARM and AARM.
 *
 *    (c) Copyright IAR Systems 2006
 *
 *    File name   : adc.c
 *    Description : Analog to Digital Converter
 *
 *    History :
 *    1. Date        : Aug 11, 2006
 *       Author      : Todor Atanasov
 *       Description : Created
 *
 *    2. Date        : Oct 15, 2007
 *       Author      : Dimitar Peikov ( Johnson Controls )
 *       Description : Changed to Analog.
 *
 *    $Revision:   1.4  $
**************************************************************************/
#include <basedef.h>
#include <lib_at91sam7_adc.h>
#include <lib_at91sam7_pmc.h>
#include <board.h>
#include <adc.h>

/*!************************************************************************
 * \fn HRESULT ADC_Init()
 * AT91PS_PMC pPMC, AT91PS_ADC pADC
 * \param pPMC pointer to PMC controller
 * \param pADC pointer to ADC controller
 * \brief ADC module initialization
 *  It is expected to have this later :
 * 	AT91F_ADC_CfgTimings( pADC, 48, 2, 128, 128000 );
 * *************************************************************************/
HRESULT ADC_Init(void)
{
	AT91PS_PMC pPMC = AT91F_PMC_GetPeripheralAddress(0);
	AT91PS_ADC pADC = AT91F_ADC_GetPeripheralAddress(0);

	/* Enable the interface clock */
	AT91F_ADC_CfgPMC( pPMC );

	/* Reset */
	AT91F_ADC_SoftReset( pADC );

	/* Set maximum startup time and hold time 
	 * SHTIM = 15     Sample & Hold Time = (SHTIM+1) / ADCClock
	 * STARTUP = 31   Startup Time = (STARTUP+1) * 8 / ADCClock
	 * PRESCAL = 15   ADCClock = MCK / ( (PRESCAL+1) * 2 )
	 */
	AT91F_ADC_CfgModeRegister( pADC, 0x0F1F0F00);

/*
 * It is expected to have this later :
 * 	AT91F_ADC_CfgTimings( pADC, 48, 2, 128, 128000 );
 */
	return S_OK;
}

/*!************************************************************************
 * \fn HRESULT ADC_GetChannel(U8 nChannel, U32 * pValue)
 * \param channel    The desired channel
 * \param pValue	Pointer to U32 data where to return measured value
 * \return        ADC result
 * \brief  Starts blocking A/D conversion from a desired channel and returns
 *              the result.
 *************************************************************************/
HRESULT ADC_GetChannel(U8 nChannel, U32 *pValue)
{
	HRESULT hr = S_OK;
	
	/* pointer to ADC base address */
	AT91PS_ADC pADC = AT91F_ADC_GetPeripheralAddress(0);

	if ( (pValue == NULL ) || (nChannel > ADC_CHANNEL_MAX) )
	{
		hr = S_INVALID_ARGUMENT;
	} else {

		/* Enable desired channel */
		AT91F_ADC_EnableChannel( pADC, nChannel );

		/* Start conversion */
		AT91F_ADC_StartConversion( pADC );

		/* wait for convertion to complete */
		while( ! AT91F_ADC_GetStatus( pADC ) );

		switch (nChannel)
		{
			case ADC_CHANNEL_0:
				*pValue = AT91F_ADC_GetConvertedDataCH0( pADC );
				break;

			case ADC_CHANNEL_1:
				*pValue = AT91F_ADC_GetConvertedDataCH1( pADC );
				break;

			case ADC_CHANNEL_2:
				*pValue = AT91F_ADC_GetConvertedDataCH2( pADC );
				break;

			case ADC_CHANNEL_3:
				*pValue = AT91F_ADC_GetConvertedDataCH3( pADC );
				break;

			case ADC_CHANNEL_4:
				*pValue = AT91F_ADC_GetConvertedDataCH4( pADC );
				break;

			case ADC_CHANNEL_5:
				*pValue = AT91F_ADC_GetConvertedDataCH5( pADC );
				break;

			case ADC_CHANNEL_6:
				*pValue = AT91F_ADC_GetConvertedDataCH6( pADC );
				break;

			case ADC_CHANNEL_7:
				*pValue = AT91F_ADC_GetConvertedDataCH7( pADC );
				break;

		default:
				hr = S_INVALID_ARGUMENT;
				break;
		}
	}
	return S_OK;
}

/*!************************************************************************
 * \fn HRESULT ADC_SetTiming(U32 nMCK_Clock, U32 nADC_Clock , U32 nStartupTime, U32 nSampleTime )
 * \param nMCK_Clock    The desired channel
 * \param nADC_Clock	  Pointer to U32 variable that will receive measured data
 * \return ADC operation result
 * \brief  Sets timing parameters for ADC controller.
 *************************************************************************/
HRESULT ADC_SetTiming(U32 nMCK_Clock, U32 nADC_Clock, U32 nStartupTime, U32 nSampleTime )
{
	/* pointer to ADC base address */
	AT91PS_ADC pADC = AT91F_ADC_GetPeripheralAddress(0);

	AT91F_ADC_CfgTimings( pADC, nMCK_Clock, nADC_Clock, nStartupTime, nSampleTime );

	return S_OK;
}
