#include "basedef.h"
#include "ioat91sam7x256.h"
#include "lib_AT91SAM7_PMC.h"
#include "lib_AT91SAM7_PIO.h"
#include "lib_AT91SAM7_ADC.h"



/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_ADC_EnableInterrupt(	AT91PS_ADC pADC, \
 * 										U32 flag )
 * \brief Enable ADC interrupt
 * \param pADC pointer to a ADC controller
 * \param flag interrupt reasons to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_ADC_EnableInterrupt(
	AT91PS_ADC pADC,     /* pointer to a ADC controller */
	U32 flag)   /* interrupt reasons to be enabled */
{
	/* Write to the IER register */
	pADC->ADC_IER = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_ADC_DisableInterrupt(	AT91PS_ADC pADC, \
 * 										U32 flag )
 * \brief Disable ADC interrupt
 * \param pADC pointer to a ADC controller
 * \param flag interrupt reasons to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_ADC_DisableInterrupt(
	AT91PS_ADC pADC, /* pointer to a ADC controller */
	U32 flag) /* interrupt reasons to be disabled */
{
	/* Write to the IDR register */
	pADC->ADC_IDR = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_ADC_GetStatus( AT91PS_ADC pADC )
 * \brief Return ADC Interrupt Status
 * \param pADC pointer to a ADC controller
 * \return status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_ADC_GetStatus( /* \return ADC Interrupt Status */
	AT91PS_ADC pADC) /* pointer to a ADC controller */
{
	return pADC->ADC_SR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_ADC_GetInterruptMaskStatus( AT91PS_ADC pADC )
 * \brief Return ADC Interrupt Mask Status
 * \param pADC pointer to a ADC controller
 * \return interrupt mask register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_ADC_GetInterruptMaskStatus( /* \return ADC Interrupt Mask Status */
	AT91PS_ADC pADC) /* pointer to a ADC controller */
{
	return pADC->ADC_IMR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_ADC_IsInterruptMasked( AT91PS_ADC pADC, \
 * 										U32 flag )
 * \brief Test if ADC Interrupt is Masked
 * \param pADC pointer to a ADC controller
 * \param flag interrupt reasons to be tested
 * \return masked interrupt mask regster value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_ADC_IsInterruptMasked(
        AT91PS_ADC pADC,   /* \arg  pointer to a ADC controller */
        U32 flag) /* \arg  interrupt reasons to be tested */
{
	return (AT91F_ADC_GetInterruptMaskStatus(pADC) & flag);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_ADC_IsStatusSet(	AT91PS_ADC pADC, \
 * 									U32 flag )
 * \brief Test if ADC Status is Set
 * \param pADC pointer to a ADC controller
 * \param flag status flags to be tested
 * \return masked status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_ADC_IsStatusSet(
        AT91PS_ADC pADC,   /* \arg  pointer to a ADC controller */
        U32 flag) /* \arg  status flags to be tested */
{
	return (AT91F_ADC_GetStatus(pADC) & flag);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_ADC_CfgModeRegister(	AT91PS_ADC pADC, \
 * 									U32 mode )
 * \brief Configure the Mode Register of the ADC controller
 * \param pADC pointer to a ADC controller
 * \param mode mode register
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_ADC_CfgModeRegister(
	AT91PS_ADC pADC, /* pointer to a ADC controller */
	U32 mode)        /* mode register */
{
	/** Write to the MR register */
	pADC->ADC_MR = mode;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_ADC_GetModeRegister( AT91PS_ADC pADC )
 * \brief Return the Mode Register of the ADC controller value
 * \param pADC pointer to a ADC controller
 * \return mode register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_ADC_GetModeRegister(
	AT91PS_ADC pADC /* pointer to a ADC controller */
	)
{
	return pADC->ADC_MR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_ADC_CfgTimings(	AT91PS_ADC pADC, \
 * 									U32 mck_clock, \
 * 									U32 adc_clock, \
 * 									U32 startup_time, \
 * 									U32 sample_and_hold_time )
 * \brief Configure the different necessary timings of the ADC controller
 * \param pADC pointer to a ADC controller
 * \param mck_clock master clock for the controller in MHz
 * \param adc_clock sampling clock in MHz ( mck_clock/2 >= adc_clock >= mck_clock / 128 )
 * \param startup_time startup time in us
 * \param sample_and_hold_time in ns
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_ADC_CfgTimings(
	AT91PS_ADC pADC, /* pointer to a ADC controller */
	U32 mck_clock, /* in MHz */
	U32 adc_clock, /* in MHz */
	U32 startup_time, /* in us */
	U32 sample_and_hold_time)	/* in ns */
{
	U32 prescal,startup,shtim;

	prescal = mck_clock/(2*adc_clock) - 1;
	startup = adc_clock*startup_time/8 - 1;
	shtim = adc_clock*sample_and_hold_time/1000 - 1;

	/* Write to the MR register */
	pADC->ADC_MR = ( (prescal<<8) & AT91C_ADC_PRESCAL) | ( (startup<<16) & AT91C_ADC_STARTUP) | ( (shtim<<24) & AT91C_ADC_SHTIM);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_ADC_EnableChannel( AT91PS_ADC pADC,
 * 									U32 channel )
 * \brief Return ADC Timer Register Value
 * \param pADC pointer to a ADC controller
 * \param channel channel number to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_ADC_EnableChannel(
	AT91PS_ADC pADC, /* pointer to a ADC controller */
	U32 channel)        /* channel number */
{
	/* Write to the CHER register */
	pADC->ADC_CHER = 1 << channel;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_ADC_DisableChannel(	AT91PS_ADC pADC, \
 * 										U32 channel )
 * \brief Return ADC Timer Register Value
 * \param pADC pointer to a ADC controller
 * \param channel channnel to be disabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_ADC_DisableChannel(
	AT91PS_ADC pADC, /* pointer to a ADC controller */
	U32 channel)        /* channel number */
{
	/** Write to the CHDR register */
	pADC->ADC_CHDR = 1 << channel;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_ADC_GetChannelStatus( AT91PS_ADC pADC )
 * \brief Return ADC Timer Register Value
 * \param pADC pointer to a ADC controller
 * \return channel status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_ADC_GetChannelStatus(
	AT91PS_ADC pADC /* pointer to a ADC controller */
	)
{
	return pADC->ADC_CHSR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_ADC_StartConversion( AT91PS_ADC pADC )
 * \brief Software request for a analog to digital conversion
 * \param pADC pointer to a ADC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_ADC_StartConversion(
	AT91PS_ADC pADC /* pointer to a ADC controller */
	)
{
	pADC->ADC_CR = AT91C_ADC_START;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_ADC_SoftReset( AT91PS_ADC pADC )
 * \brief Software reset
 * \param pADC pointer to a ADC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_ADC_SoftReset(
	AT91PS_ADC pADC /* pointer to a ADC controller */
	)
{
	pADC->ADC_CR = AT91C_ADC_SWRST;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_ADC_GetLastConvertedData( AT91PS_ADC pADC )
 * \brief Return the Last Converted Data
 * \param pADC pointer to a ADC controller
 * \return last converted data register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_ADC_GetLastConvertedData(
	AT91PS_ADC pADC /* pointer to a ADC controller */
	)
{
	return pADC->ADC_LCDR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_ADC_GetConvertedDataCH0( AT91PS_ADC pADC )
 * \brief Return the Channel 0 Converted Data
 * \param pADC pointer to a ADC controller
 * \return channel 0 data register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_ADC_GetConvertedDataCH0(
	AT91PS_ADC pADC /* pointer to a ADC controller */
	)
{
	return pADC->ADC_CDR0;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_ADC_GetConvertedDataCH1( AT91PS_ADC pADC )
 * \brief Return the Channel 1 Converted Data
 * \param pADC pointer to a ADC controller
 * \return channel 1 data register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_ADC_GetConvertedDataCH1(
	AT91PS_ADC pADC /* pointer to a ADC controller */
	)
{
	return pADC->ADC_CDR1;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_ADC_GetConvertedDataCH2( AT91PS_ADC pADC )
 * \brief Return the Channel 2 Converted Data
 * \param pADC pointer to a ADC controller
 * \return channel 2 data register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_ADC_GetConvertedDataCH2(
	AT91PS_ADC pADC /* pointer to a ADC controller */
	)
{
	return pADC->ADC_CDR2;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_ADC_GetConvertedDataCH3( AT91PS_ADC pADC )
 * \brief Return the Channel 3 Converted Data
 * \param pADC pointer to a ADC controller
 * \return channel 3 data register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_ADC_GetConvertedDataCH3(
	AT91PS_ADC pADC /* pointer to a ADC controller */
	)
{
	return pADC->ADC_CDR3;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_ADC_GetConvertedDataCH4( AT91PS_ADC pADC )
 * \brief Return the Channel 4 Converted Data
 * \param pADC pointer to a ADC controller
 * \return channel 4 data register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_ADC_GetConvertedDataCH4(
	AT91PS_ADC pADC /* pointer to a ADC controller */
	)
{
	return pADC->ADC_CDR4;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_ADC_GetConvertedDataCH5( AT91PS_ADC pADC )
 * \brief Return the Channel 5 Converted Data
 * \param pADC pointer to a ADC controller
 * \return channel 5 data register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_ADC_GetConvertedDataCH5(
	AT91PS_ADC pADC /* pointer to a ADC controller */
	)
{
	return pADC->ADC_CDR5;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_ADC_GetConvertedDataCH6( AT91PS_ADC pADC )
 * \brief Return the Channel 6 Converted Data
 * \param pADC pointer to a ADC controller
 * \return channel 6 data register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_ADC_GetConvertedDataCH6(
	AT91PS_ADC pADC /* pointer to a ADC controller */
	)
{
	return pADC->ADC_CDR6;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_ADC_GetConvertedDataCH7( AT91PS_ADC pADC )
 * \brief Return the Channel 7 Converted Data
 * \param pADC pointer to a ADC controller
 * \return channel 7 data register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_ADC_GetConvertedDataCH7(
	AT91PS_ADC pADC /* pointer to a ADC controller */
	)
{
	return pADC->ADC_CDR7;
}



/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_ADC_CfgPMC( AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  ADC
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_ADC_CfgPMC( AT91PS_PMC pPMC )
{
	AT91F_PMC_EnablePeripheralClock(
		pPMC, /* PIO controller base address */
		((U32) 1 << AT91C_ID_ADC));
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_ADC_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
 * \brief Configure PIO controllers to drive ADC signals
 * \param pPIOA pointer to PIOA controller 
 * \param pPIOB pointer to PIOB controller 
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_ADC_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
{
	/* Configure PIO controllers to periph mode */
	AT91F_PIO_CfgPeripheral(
		pPIOB, /* PIO controller base address */
		0, /* Peripheral A */
		((U32) AT91C_PB18_ADTRG )); /* Peripheral B */
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_ADC AT91F_ADC_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base ADC peripheral controller address
 * \param u8Controller ADC controller index
 * \return pointer to ADC controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_ADC AT91F_ADC_GetPeripheralAddress( U8 u8Controller )
{
	return AT91C_BASE_ADC;
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_PDC AT91F_ADC_PDC_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base PDC peripheral controller address
 * \param u8Controller PDC controller index
 * \return pointer to PDC controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_PDC AT91F_ADC_PDC_GetPeripheralAddress( U8 u8Controller )
{
	return AT91C_BASE_PDC_ADC;
}
