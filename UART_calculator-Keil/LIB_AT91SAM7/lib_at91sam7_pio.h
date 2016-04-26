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
   
    CVS Reference       : /lib_MC_SAM7X.h/1.1/Thu Mar 25 15:19:14 2004//
    CVS Reference       : /lib_pdc.h/1.2/Tue Jul  2 13:29:40 2002//
    CVS Reference       : /lib_des3_6150a.h/1.1/Mon Jan 17 09:19:19 2005//
    CVS Reference       : /lib_dbgu.h/1.1/Thu Aug 25 12:56:22 2005//
    CVS Reference       : /lib_aes_6149a.h/1.1/Mon Jan 17 07:43:09 2005//
    CVS Reference       : /lib_VREG_6085B.h/1.1/Tue Feb  1 16:20:47 2005//
    CVS Reference       : /lib_ssc.h/1.4/Fri Jan 31 12:19:20 2003//
    CVS Reference       : /lib_spi2.h/1.2/Tue Aug 23 15:37:28 2005//
    CVS Reference       : /lib_PWM_SAM.h/1.3/Thu Jan 22 10:10:50 2004//
    CVS Reference       : /lib_tc_1753b.h/1.1/Fri Jan 31 12:20:02 2003//
    CVS Reference       : /lib_pitc_6079A.h/1.2/Tue Nov  9 14:43:56 2004//
    CVS Reference       : /lib_adc.h/1.6/Fri Oct 17 09:12:38 2003//
    CVS Reference       : /lib_pmc_SAM7X.h/1.5/Fri Nov  4 09:41:32 2005//
    CVS Reference       : /lib_rstc_6098A.h/1.1/Wed Oct  6 10:39:20 2004//
    CVS Reference       : /lib_rttc_6081A.h/1.1/Wed Oct  6 10:39:38 2004//
    CVS Reference       : /lib_pio.h/1.3/Fri Jan 31 12:18:56 2003//
    CVS Reference       : /lib_twi.h/1.3/Mon Jul 19 14:27:58 2004//
    CVS Reference       : /lib_wdtc_6080A.h/1.1/Wed Oct  6 10:38:30 2004//
    CVS Reference       : /lib_usart.h/1.5/Thu Nov 21 16:01:54 2002//
    CVS Reference       : /lib_udp.h/1.5/Tue Aug 30 12:13:47 2005//
    CVS Reference       : /lib_aic_6075b.h/1.2/Thu Jul  7 07:48:22 2005//
    CVS Reference       : /lib_can_AT91.h/1.5/Tue Aug 23 15:37:07 2005//
    ----------------------------------------------------------------------------
*/
#ifndef lib_AT91SAM7_PIO_H
#define lib_AT91SAM7_PIO_H

/* *****************************************************************************
                SOFTWARE API FOR PIO
   ***************************************************************************** */
/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_CfgPeripheral(	AT91PS_PIO pPio, \
 * 									U32 periphAEnable, \
 * 									U32 periphBEnable)
 * \brief Enable pins to be drived by peripheral
 * \param pPio pointer to a PIO controller
 * \param periphAEnable PERIPH A to enable
 * \param periphBEnable PERIPH B to enable
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_CfgPeripheral(
	AT91PS_PIO pPio,             /* \arg pointer to a PIO controller */
	U32 periphAEnable,  /* \arg PERIPH A to enable */
	U32 periphBEnable);  /* \arg PERIPH B to enable */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_CfgOutput(	AT91PS_PIO pPio, \
 * 								U32 pioEnable)
 * \brief Enable PIO in output mode
 * \param pPio pointer to a PIO controller
 * \param pioEnable PIO to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_CfgOutput(
	AT91PS_PIO pPio,             /* \arg pointer to a PIO controller */
	U32 pioEnable);      /* \arg PIO to be enabled */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_CfgInput(	AT91PS_PIO pPio, \
 * 								U32 pioEnable)
 * \brief Enable PIO in input mode
 * \param pPio pointer to a PIO controller
 * \param pioEnable PIO to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_CfgInput(
	AT91PS_PIO pPio,             /* \arg pointer to a PIO controller */
	U32 inputEnable);      /* \arg PIO to be enabled */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_CfgOpenDrain(	AT91PS_PIO pPio, \
 * 									U32 multiDrvEnable)
 * \brief Configure PIO in open drain
 * \param pPio pointer to a PIO controller
 * \param multiDrvEnable PIO to be configured in open drain
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_CfgOpenDrain(
	AT91PS_PIO pPio,             /* \arg pointer to a PIO controller */
	U32 multiDrvEnable); /* \arg pio to be configured in open drain */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_CfgPullup(	AT91PS_PIO pPio, \
 * 								U32 pullupEnable)
 * \brief Enable pullup on PIO
 * \param pPio pointer to a PIO controller
 * \param pullupEnable enable pullup on PIO
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_CfgPullup(
	AT91PS_PIO pPio,             /* \arg pointer to a PIO controller */
	U32 pullupEnable);   /* \arg enable pullup on PIO */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_CfgDirectDrive(	AT91PS_PIO pPio, \
 * 										U32 directDrive)
 * \brief Enable direct drive on PIO
 * \param pPio pointer to a PIO controller
 * \param directDrive PIO to be configured with direct drive
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_CfgDirectDrive(
	AT91PS_PIO pPio,             /* \arg pointer to a PIO controller */
	U32 directDrive);    /* \arg PIO to be configured with direct drive */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_CfgInputFilter(	AT91PS_PIO pPio, \
 * 										U32 inputFilter)
 * \brief Enable input filter on input PIO
 * \param pPio pointer to a PIO controller
 * \param inputFilter PIO to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_CfgInputFilter(
	AT91PS_PIO pPio,             /* \arg pointer to a PIO controller */
	U32 inputFilter);    /* \arg PIO to be configured with input filter */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_GetInput(	AT91PS_PIO pPio )
 * \brief Return PIO input value
 * \param pPio pointer to a PIO controller
 * \return port data status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_GetInput( /* \return PIO input */
	AT91PS_PIO pPio); /* \arg  pointer to a PIO controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_IsInputSet(	AT91PS_PIO pPio, \
 * 									U32 flag)
 * \brief Test if PIO is input flag is active
 * \param pPio pointer to a PIO controller
 * \param flag flag to be tested
 * \return masked port data status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_IsInputSet(
	AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
	U32 flag); /* \arg  flag to be tested */



/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_SetOutput(	AT91PS_PIO pPio, \
 * 								U32 flag)
 * \brief Set to 1 output PIO
 * \param pPio pointer to a PIO controller
 * \param flag output to be set
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_SetOutput(
	AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
	U32 flag); /* \arg  output to be set */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_ClearOutput(	AT91PS_PIO pPio, \
 * 									U32 flag)
 * \brief Set to 0 output PIO
 * \param pPio pointer to a PIO controller
 * \param flag output to be cleared
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_ClearOutput(
	AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
	U32 flag); /* \arg  output to be cleared */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_ForceOutput(	AT91PS_PIO pPio, \
 * 									U32 flag)
 * \brief Force output when Direct drive option is enabled
 * \param pPio pointer to a PIO controller
 * \param flag output to be forced
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_ForceOutput(
	AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
	U32 flag); /* \arg  output to be forced */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_Enable(	AT91PS_PIO pPio, \
 * 								U32 flag)
 * \brief Enable PIO
 * \param pPio pointer to a PIO controller
 * \param flag pio to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_Enable(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag); /* \arg  pio to be enabled */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_Disable(	AT91PS_PIO pPio, \
 * 								U32 flag)
 * \brief Disable PIO
 * \param pPio pointer to a PIO controller
 * \param flag pio to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_Disable(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag); /* \arg  pio to be disabled */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_GetStatus(	AT91PS_PIO pPio )
 * \brief Return PIO Status
 * \param pPio pointer to a PIO controller
 * \return PIO status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_GetStatus( /* \return PIO Status */
        AT91PS_PIO pPio); /* \arg  pointer to a PIO controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_IsSet(	AT91PS_PIO pPio, \
 * 							U32 flag)
 * \brief Test if PIO is Set
 * \param pPio pointer to a PIO controller
 * \param flag flag to be tested
 * \return masked PIO status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_IsSet(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag); /* \arg  flag to be tested */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_OutputEnable(	AT91PS_PIO pPio, \
 * 									U32 flag)
 * \brief Output Enable PIO
 * \param pPio pointer to a PIO controller
 * \param flag pio output to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_OutputEnable(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag); /* \arg  pio output to be enabled */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_OutputDisable(	AT91PS_PIO pPio, \
 * 									U32 flag)
 * \brief Output Enable PIO
 * \param pPio pointer to a PIO controller
 * \param flag pio output to be disabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_OutputDisable(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag); /* \arg  pio output to be disabled */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_GetOutputStatus(	AT91PS_PIO pPio )
 * \brief Return PIO Output Status
 * \param pPio pointer to a PIO controller
 * \return port output status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_GetOutputStatus( /* \return PIO Output Status */
        AT91PS_PIO pPio); /* \arg  pointer to a PIO controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_IsOutputSet(	AT91PS_PIO pPio, \
 * 									U32 flag)
 * \brief Test if PIO Output is Set
 * \param pPio pointer to a PIO controller
 * \param flag flag to be tested
 * \return masked port output status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_IsOutputSet(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag); /* \arg  flag to be tested */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_InputFilterEnable(	AT91PS_PIO pPio, \
 * 										U32 flag)
 * \brief Input Filter Enable PIO
 * \param pPio pointer to a PIO controller
 * \param flag pio input filter to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_InputFilterEnable(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag); /* \arg  pio input filter to be enabled */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_InputFilterDisable(	AT91PS_PIO pPio, \
 * 											U32 flag)
 * \brief Input Filter Disable PIO
 * \param pPio pointer to a PIO controller
 * \param flag pio input filter to be disabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_InputFilterDisable(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag); /* \arg  pio input filter to be disabled */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_GetInputFilterStatus(	AT91PS_PIO pPio )
 * \brief Return PIO Input Filter Status
 * \param pPio pointer to a PIO controller
 * \return port input filter status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_GetInputFilterStatus( /* \return PIO Input Filter Status */
        AT91PS_PIO pPio); /* \arg  pointer to a PIO controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_IsInputFilterSet(	AT91PS_PIO pPio, \
 * 										U32 flag)
 * \brief Test if PIO Input filter is Set
 * \param pPio pointer to a PIO controller
 * \param flag flag to be tested
 * \return masked port input filter status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_IsInputFilterSet(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag); /* \arg  flag to be tested */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_GetOutputDataStatus(	AT91PS_PIO pPio )
 * \brief Return PIO Output Data Status
 * \param pPio pointer to a PIO controller
 * \return port outpur data status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_GetOutputDataStatus( /* \return PIO Output Data Status */
	AT91PS_PIO pPio); /* \arg  pointer to a PIO controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_InterruptEnable(	AT91PS_PIO pPio, \
 * 										U32 flag)
 * \brief Enable PIO Interrupt
 * \param pPio pointer to a PIO controller
 * \param flag pio interrupt to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_InterruptEnable(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag); /* \arg  pio interrupt to be enabled */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_InterruptDisable(	AT91PS_PIO pPio, \
 * 										U32 flag)
 * \brief Disable PIO Interrupt
 * \param pPio pointer to a PIO controller
 * \param flag pio interrupt to be disabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_InterruptDisable(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag); /* \arg  pio interrupt to be disabled */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_GetInterruptMaskStatus(	AT91PS_PIO pPio )
 * \brief Return PIO Interrupt Mask Status
 * \param pPio pointer to a PIO controller
 * \return interrput mask register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_GetInterruptMaskStatus( /* \return PIO Interrupt Mask Status */
        AT91PS_PIO pPio); /* \arg  pointer to a PIO controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_GetInterruptStatus(	AT91PS_PIO pPio )
 * \brief Return PIO Interrupt Status
 * \param pPio pointer to a PIO controller
 * \return interrupt status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_GetInterruptStatus( /* \return PIO Interrupt Status */
        AT91PS_PIO pPio); /* \arg  pointer to a PIO controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_IsInterruptMasked(	AT91PS_PIO pPio, \
 * 										U32 flag)
 * \brief Test if PIO Interrupt is Masked
 * \param pPio pointer to a PIO controller
 * \param flag flag to be tested
 * \return masked interrupt mask register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_IsInterruptMasked(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag); /* \arg  flag to be tested */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_IsInterruptSet(	AT91PS_PIO pPio, \
 * 										U32 flag)
 * \brief Test if PIO Interrupt is Set
 * \param pPio pointer to a PIO controller
 * \param flag flag to be tested
 * \return masked interrupt status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_IsInterruptSet(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag); /* \arg  flag to be tested */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_MultiDriverEnable(	AT91PS_PIO pPio, \
 * 										U32 flag)
 * \brief Multi Driver Enable PIO
 * \param pPio pointer to a PIO controller
 * \param flag flag to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_MultiDriverEnable(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag); /* \arg  pio to be enabled */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_MultiDriverDisable(	AT91PS_PIO pPio, \
 * 											U32 flag)
 * \brief Multi Driver Disable PIO
 * \param pPio pointer to a PIO controller
 * \param flag flag to be disabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_MultiDriverDisable(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag); /* \arg  pio to be disabled */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_GetMultiDriverStatus(	AT91PS_PIO pPio )
 * \brief Return PIO Multi Driver Status
 * \param pPio pointer to a PIO controller
 * \return multi-driver status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_GetMultiDriverStatus( /* \return PIO Multi Driver Status */
        AT91PS_PIO pPio); /* \arg  pointer to a PIO controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_IsMultiDriverSet(	AT91PS_PIO pPio, \
 * 											U32 flag)
 * \brief Test if PIO MultiDriver is Set
 * \param pPio pointer to a PIO controller
 * \param flag flag to be tested
 * \return masked multi-driver status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_IsMultiDriverSet(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag); /* \arg  flag to be tested */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_A_RegisterSelection(	AT91PS_PIO pPio, \
 * 											U32 flag)
 * \brief PIO A Register Selection
 * \param pPio pointer to a PIO controller
 * \param flag pio A register selection
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_A_RegisterSelection(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag); /* \arg  pio A register selection */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_B_RegisterSelection(	AT91PS_PIO pPio, \
 * 											U32 flag)
 * \brief PIO B Register Selection
 * \param pPio pointer to a PIO controller
 * \param flag pio B register selection
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_B_RegisterSelection(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag); /* \arg  pio B register selection */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_Get_AB_RegisterStatus(	AT91PS_PIO pPio )
 * \brief Return PIO AB register Status
 * \param pPio pointer to a PIO controller
 * \return AB peripheral select status register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_Get_AB_RegisterStatus( /* \return PIO AB Register Status */
        AT91PS_PIO pPio); /* \arg  pointer to a PIO controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_IsAB_RegisterSet(	AT91PS_PIO pPio, \
 * 										U32 flag)
 * \brief Test if PIO AB Register is Set
 * \param pPio pointer to a PIO controller
 * \param flag flag to be tested
 * \return masked AB peripheral select status register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_IsAB_RegisterSet(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag); /* \arg  flag to be tested */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_OutputWriteEnable(	AT91PS_PIO pPio, \
 * 										U32 flag)
 * \brief Output Write Enable PIO
 * \param pPio pointer to a PIO controller
 * \param flag pio output write to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_OutputWriteEnable(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag); /* \arg  pio output write to be enabled */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_OutputWriteDisable(	AT91PS_PIO pPio, \
 * 											U32 flag)
 * \brief Output Write Disable PIO
 * \param pPio pointer to a PIO controller
 * \param flag pio output write to be disabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_OutputWriteDisable(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag); /* \arg  pio output write to be disabled */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_GetOutputWriteStatus(	AT91PS_PIO pPio )
 * \brief Return PIO Output Write Status
 * \param pPio pointer to a PIO controller
 * \return output write status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_GetOutputWriteStatus( /* \return PIO Output Write Status */
        AT91PS_PIO pPio); /* \arg  pointer to a PIO controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_IsOutputWriteSet(	AT91PS_PIO pPio, \
 * 										U32 flag)
 * \brief Test if PIO OutputWrite is Set
 * \param pPio pointer to a PIO controller
 * \param flag flag to be tested
 * \return masked output write status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_IsOutputWriteSet(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag); /* \arg  flag to be tested */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_GetCfgPullup(	AT91PS_PIO pPio )
 * \brief Return PIO Configuration Pullup
 * \param pPio pointer to a PIO controller
 * \return pull-up status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_GetCfgPullup( /* \return PIO Configuration Pullup */
        AT91PS_PIO pPio); /* \arg  pointer to a PIO controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_IsOutputDataStatusSet(	AT91PS_PIO pPio, \
 * 											U32 flag)
 * \brief Test if PIO Output Data Status is Set
 * \param pPio pointer to a PIO controller
 * \param flag flag to be tested
 * \return masked output data status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_IsOutputDataStatusSet(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag); /* \arg  flag to be tested */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_IsCfgPullupStatusSet(	AT91PS_PIO pPio, \
 * 											U32 flag)
 * \brief Test if PIO Configuration Pullup Status is Set
 * \param pPio pointer to a PIO controller
 * \param flag flag to be tested
 * \return masked pull-up status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_IsCfgPullupStatusSet(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag); /* \arg  flag to be tested */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIOA_CfgPMC( AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  PIOA
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIOA_CfgPMC( AT91PS_PMC pPMC );


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIOB_CfgPMC( AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  PIOB
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIOB_CfgPMC( AT91PS_PMC pPMC );



/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_PIO AT91F_PIO_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base PIO peripheral controller address
 * \param u8Controller PIO controller index
 * \return pointer to PIO controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_PIO AT91F_PIO_GetPeripheralAddress( U8 u8Controller );


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_DisablePullup(	AT91PS_PIO pPio, \
 * 								U32 pullupDisable)
 * \brief Enable pullup on PIO
 * \param pPio pointer to a PIO controller
 * \param pullupDisable disable pullup on PIO
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_DisablePullup(
	AT91PS_PIO pPio,             /* \arg pointer to a PIO controller */
	U32 pullupDisable);   /* \arg enable pullup on PIO */

#endif /* lib_AT91SAM7_PIO_H */
