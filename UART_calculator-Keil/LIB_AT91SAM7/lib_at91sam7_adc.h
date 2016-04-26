/*  ----------------------------------------------------------------------------
            ATMEL Microcontroller Software Support  -  ROUSSET  -
    ----------------------------------------------------------------------------
    DISCLAIMER:  THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
    IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
    DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
    INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
    LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
    OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
    LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
    EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
    ----------------------------------------------------------------------------
    File Name           : lib_AT91SAM7.h
    Object              : AT91SAM7 inlined functions
    Generated           : AT91 SW Application Group  01/16/2006 (16:36:38)
   
    CVS Reference       : /lib_MC_SAM7X.h/1.1/Thu Mar 25 15:19:14 2004
    CVS Reference       : /lib_pdc.h/1.2/Tue Jul  2 13:29:40 2002
    CVS Reference       : /lib_des3_6150a.h/1.1/Mon Jan 17 09:19:19 2005
    CVS Reference       : /lib_dbgu.h/1.1/Thu Aug 25 12:56:22 2005
    CVS Reference       : /lib_aes_6149a.h/1.1/Mon Jan 17 07:43:09 2005
    CVS Reference       : /lib_VREG_6085B.h/1.1/Tue Feb  1 16:20:47 2005
    CVS Reference       : /lib_ssc.h/1.4/Fri Jan 31 12:19:20 2003
    CVS Reference       : /lib_spi2.h/1.2/Tue Aug 23 15:37:28 2005
    CVS Reference       : /lib_PWM_SAM.h/1.3/Thu Jan 22 10:10:50 2004
    CVS Reference       : /lib_tc_1753b.h/1.1/Fri Jan 31 12:20:02 2003
    CVS Reference       : /lib_pitc_6079A.h/1.2/Tue Nov  9 14:43:56 2004
    CVS Reference       : /lib_adc.h/1.6/Fri Oct 17 09:12:38 2003
    CVS Reference       : /lib_pmc_SAM7X.h/1.5/Fri Nov  4 09:41:32 2005
    CVS Reference       : /lib_rstc_6098A.h/1.1/Wed Oct  6 10:39:20 2004
    CVS Reference       : /lib_rttc_6081A.h/1.1/Wed Oct  6 10:39:38 2004
    CVS Reference       : /lib_pio.h/1.3/Fri Jan 31 12:18:56 2003
    CVS Reference       : /lib_twi.h/1.3/Mon Jul 19 14:27:58 2004
    CVS Reference       : /lib_wdtc_6080A.h/1.1/Wed Oct  6 10:38:30 2004
    CVS Reference       : /lib_usart.h/1.5/Thu Nov 21 16:01:54 2002
    CVS Reference       : /lib_udp.h/1.5/Tue Aug 30 12:13:47 2005
    CVS Reference       : /lib_aic_6075b.h/1.2/Thu Jul  7 07:48:22 2005
    CVS Reference       : /lib_can_AT91.h/1.5/Tue Aug 23 15:37:07 2005
    ----------------------------------------------------------------------------
*/
#ifndef lib_AT91SAM7_ADC_H
#define lib_AT91SAM7_ADC_H

#include "ioat91sam7x256.h"


/* *****************************************************************************
                SOFTWARE API FOR ADC
   ***************************************************************************** */
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
	U32 flag);   /* interrupt reasons to be enabled */


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
	U32 flag); /* interrupt reasons to be disabled */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_ADC_GetStatus( AT91PS_ADC pADC )
 * \brief Return ADC Interrupt Status
 * \param pADC pointer to a ADC controller
 * \return status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_ADC_GetStatus( /* \return ADC Interrupt Status */
	AT91PS_ADC pADC); /* pointer to a ADC controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_ADC_GetInterruptMaskStatus( AT91PS_ADC pADC )
 * \brief Return ADC Interrupt Mask Status
 * \param pADC pointer to a ADC controller
 * \return interrupt mask register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_ADC_GetInterruptMaskStatus( /* \return ADC Interrupt Mask Status */
	AT91PS_ADC pADC); /* pointer to a ADC controller */


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
        U32 flag); /* \arg  interrupt reasons to be tested */


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
        U32 flag); /* \arg  status flags to be tested */


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
	U32 mode);        /* mode register */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_ADC_GetModeRegister( AT91PS_ADC pADC )
 * \brief Return the Mode Register of the ADC controller value
 * \param pADC pointer to a ADC controller
 * \return mode register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_ADC_GetModeRegister(
	AT91PS_ADC pADC /* pointer to a ADC controller */
	);


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
	U32 sample_and_hold_time);	/* in ns */


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
	U32 channel);        /* channel number */


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
	U32 channel);        /* channel number */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_ADC_GetChannelStatus( AT91PS_ADC pADC )
 * \brief Return ADC Timer Register Value
 * \param pADC pointer to a ADC controller
 * \return channel status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_ADC_GetChannelStatus(
	AT91PS_ADC pADC /* pointer to a ADC controller */
	);


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_ADC_StartConversion( AT91PS_ADC pADC )
 * \brief Software request for a analog to digital conversion
 * \param pADC pointer to a ADC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_ADC_StartConversion(
	AT91PS_ADC pADC /* pointer to a ADC controller */
	);


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_ADC_SoftReset( AT91PS_ADC pADC )
 * \brief Software reset
 * \param pADC pointer to a ADC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_ADC_SoftReset(
	AT91PS_ADC pADC /* pointer to a ADC controller */
	);

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_ADC_GetLastConvertedData( AT91PS_ADC pADC )
 * \brief Return the Last Converted Data
 * \param pADC pointer to a ADC controller
 * \return last converted data register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_ADC_GetLastConvertedData(
	AT91PS_ADC pADC /* pointer to a ADC controller */
	);


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_ADC_GetConvertedDataCH0( AT91PS_ADC pADC )
 * \brief Return the Channel 0 Converted Data
 * \param pADC pointer to a ADC controller
 * \return channel 0 data register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_ADC_GetConvertedDataCH0(
	AT91PS_ADC pADC /* pointer to a ADC controller */
	);


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_ADC_GetConvertedDataCH1( AT91PS_ADC pADC )
 * \brief Return the Channel 1 Converted Data
 * \param pADC pointer to a ADC controller
 * \return channel 1 data register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_ADC_GetConvertedDataCH1(
	AT91PS_ADC pADC /* pointer to a ADC controller */
	);


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_ADC_GetConvertedDataCH2( AT91PS_ADC pADC )
 * \brief Return the Channel 2 Converted Data
 * \param pADC pointer to a ADC controller
 * \return channel 2 data register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_ADC_GetConvertedDataCH2(
	AT91PS_ADC pADC /* pointer to a ADC controller */
	);


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_ADC_GetConvertedDataCH3( AT91PS_ADC pADC )
 * \brief Return the Channel 3 Converted Data
 * \param pADC pointer to a ADC controller
 * \return channel 3 data register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_ADC_GetConvertedDataCH3(
	AT91PS_ADC pADC /* pointer to a ADC controller */
	);


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_ADC_GetConvertedDataCH4( AT91PS_ADC pADC )
 * \brief Return the Channel 4 Converted Data
 * \param pADC pointer to a ADC controller
 * \return channel 4 data register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_ADC_GetConvertedDataCH4(
	AT91PS_ADC pADC /* pointer to a ADC controller */
	);


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_ADC_GetConvertedDataCH5( AT91PS_ADC pADC )
 * \brief Return the Channel 5 Converted Data
 * \param pADC pointer to a ADC controller
 * \return channel 5 data register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_ADC_GetConvertedDataCH5(
	AT91PS_ADC pADC /* pointer to a ADC controller */
	);


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_ADC_GetConvertedDataCH6( AT91PS_ADC pADC )
 * \brief Return the Channel 6 Converted Data
 * \param pADC pointer to a ADC controller
 * \return channel 6 data register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_ADC_GetConvertedDataCH6(
	AT91PS_ADC pADC /* pointer to a ADC controller */
	);


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_ADC_GetConvertedDataCH7( AT91PS_ADC pADC )
 * \brief Return the Channel 7 Converted Data
 * \param pADC pointer to a ADC controller
 * \return channel 7 data register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_ADC_GetConvertedDataCH7(
	AT91PS_ADC pADC /* pointer to a ADC controller */
	);


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_ADC_CfgPMC( AT91PS_PMC pPMC )
 * \param pPMC pointer to PMC controller
 * \brief Enable Peripheral clock in PMC for  ADC
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_ADC_CfgPMC( AT91PS_PMC pPMC );


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_ADC_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
 * \param pPIOA pointer to PIOA controller 
 * \param pPIOB pointer to PIOB controller 
 * \brief Configure PIO controllers to drive ADC signals
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_ADC_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB );


/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_ADC AT91F_ADC_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base ADC peripheral controller address
 * \param u8Controller ADC controller index
 * \return pointer to ADC controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_ADC AT91F_ADC_GetPeripheralAddress( U8 u8Controller );


/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_PDC AT91F_ADC_PDC_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base PDC peripheral controller address
 * \param u8Controller PDC controller index
 * \return pointer to PDC controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_PDC AT91F_ADC_PDC_GetPeripheralAddress( U8 u8Controller );

#endif /* lib_AT91SAM7_ADC_H */
