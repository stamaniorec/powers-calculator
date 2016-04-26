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
    File Name           : lib_AT91SAM7XC256.h
    Object              : AT91SAM7XC256 inlined functions
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

#ifndef lib_AT91SAM7_PMC_H
#define lib_AT91SAM7_PMC_H

/* *****************************************************************************
                SOFTWARE API FOR PMC
   ***************************************************************************** */
/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PMC_CfgSysClkEnableRegister(	AT91PS_PMC pPMC, \
 * 											U32 mode)
 * \brief Configure the System Clock Enable Register of the PMC controller
 * \param pPMC pointer to PMC controller
 * \param mode enable mode value
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PMC_CfgSysClkEnableRegister(
	AT91PS_PMC pPMC, /* \arg pointer to PMC controller */
	U32 mode);

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PMC_CfgSysClkDisableRegister(	AT91PS_PMC pPMC, \
 * 											U32 mode)
 * \brief Configure the System Clock Disable Register of the PMC controller
 * \param pPMC pointer to PMC controller
 * \param mode disable mode value
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PMC_CfgSysClkDisableRegister(
	AT91PS_PMC pPMC, /* \arg pointer to PMC controller */
	U32 mode);


/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PMC_GetSysClkStatusRegister(	AT91PS_PMC pPMC )
 * \brief Return the System Clock Status Register of the PMC controller
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PMC_GetSysClkStatusRegister(
	AT91PS_PMC pPMC /* pointer to a CAN controller */
	);


/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PMC_EnablePeripheralClock(	AT91PS_PMC pPMC, \
 * 										U32 periphIds)
 * \brief Enable peripheral clock
 * \param pPMC pointer to PMC controller
 * \param periphIds IDs of peripherals
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PMC_EnablePeripheralClock(
	AT91PS_PMC pPMC, /* \arg pointer to PMC controller */
	U32 periphIds);  /* \arg IDs of peripherals */


/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PMC_DisablePeripheralClock(	AT91PS_PMC pPMC, \
 * 											U32 periphIds)
 * \brief Disable peripheral clock
 * \param pPMC pointer to PMC controller
 * \param periphIds IDs of peripherals
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PMC_DisablePeripheralClock(
	AT91PS_PMC pPMC, /* \arg pointer to PMC controller */
	U32 periphIds);  /* \arg IDs of peripherals */

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PMC_GetPeripheralClock(	AT91PS_PMC pPMC )
 * \brief Get peripheral clock status
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PMC_GetPeripheralClock(
	AT91PS_PMC pPMC); /* \arg pointer to PMC controller */





/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_CKGR_CfgMainOscillatorRegister( AT91PS_CKGR pCKGR, \
 * 											U32 mode)
 * \brief Cfg the main oscillator
 * \param pCKGR pointer to CKGR controller
 * \param mode mode
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_CKGR_CfgMainOscillatorRegister(
	AT91PS_CKGR pCKGR, /* \arg pointer to CKGR controller */
	U32 mode);


/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_CKGR_GetMainOscillatorRegister( AT91PS_CKGR pCKGR )
 * \brief Return the main oscillator
 * \param pCKGR pointer to CKGR controller
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CKGR_GetMainOscillatorRegister(
	AT91PS_CKGR pCKGR); /* \arg pointer to CKGR controller */

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_CKGR_EnableMainOscillator( AT91PS_CKGR pCKGR )
 * \brief Enable the main oscillator
 * \param pCKGR pointer to CKGR controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_CKGR_EnableMainOscillator(
	AT91PS_CKGR pCKGR); /* \arg pointer to CKGR controller */


/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_CKGR_DisableMainOscillator( AT91PS_CKGR pCKGR )
 * \brief Disable the main oscillator
 * \param pCKGR pointer to CKGR controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_CKGR_DisableMainOscillator(
	AT91PS_CKGR pCKGR); /* \arg pointer to CKGR controller */


/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_CKGR_CfgMainOscStartUpTime(	AT91PS_CKGR pCKGR, \
 * 												U32 startup_time, \
 * 												U32 slowClock)
 * \brief Cfg MOR Register according to the main osc startup time
 * \param pCKGR pointer to CKGR controller
 * \param startup_time main osc startup time in microsecond (us)
 * \param slowClock slowClock in Hz
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_CKGR_CfgMainOscStartUpTime(
	AT91PS_CKGR pCKGR, /* \arg pointer to CKGR controller */
	U32 startup_time,  /* \arg main osc startup time in microsecond (us) */
	U32 slowClock);  /* \arg slowClock in Hz */

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_CKGR_GetMainClockFreqRegister( AT91PS_CKGR pCKGR )
 * \brief Cfg the main oscillator
 * \param pCKGR pointer to CKGR controller
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CKGR_GetMainClockFreqRegister(
	AT91PS_CKGR pCKGR); /* \arg pointer to CKGR controller */


/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_CKGR_GetMainClock( AT91PS_CKGR pCKGR, \
 * 									U32 slowClock)
 * \brief Return Main clock in Hz
 * \param pCKGR pointer to CKGR controller
 * \param slowClock slowClock in Hz
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CKGR_GetMainClock(
	AT91PS_CKGR pCKGR, /* \arg pointer to CKGR controller */
	U32 slowClock);  /* \arg slowClock in Hz */


/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PMC_CfgMCKRegister( AT91PS_PMC pPMC, \
 * 								U32 mode)
 * \brief Cfg Master Clock Register
 * \param pPMC pointer to PMC controller
 * \param mode mode register
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PMC_CfgMCKRegister(
	AT91PS_PMC pPMC, /* \arg pointer to PMC controller */
	U32 mode);


/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PMC_GetMCKRegister(	AT91PS_PMC pPMC )
 * \brief Return Master Clock Register
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PMC_GetMCKRegister(
	AT91PS_PMC pPMC); /* \arg pointer to PMC controller */


/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PMC_GetMasterClock(	AT91PS_PMC pPMC, \
 * 										AT91PS_CKGR pCKGR, \
 * 										U32 slowClock)
 * \brief Return master clock in Hz which correponds to processor clock for ARM7
 * \param pPMC pointer to PMC controller
 * \param pCKGR pointer to CKGR controller
 * \param slowClock slowClock in Hz
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PMC_GetMasterClock(
	AT91PS_PMC pPMC, /* \arg pointer to PMC controller */
	AT91PS_CKGR pCKGR, /* \arg pointer to CKGR controller */
	U32 slowClock);  /* \arg slowClock in Hz */


/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PMC_EnablePCK(	AT91PS_PMC pPMC, \
 * 								U32 pck, \
 * 								U32 mode)
 * \brief Enable Programmable Clock x Output
 * \param pPMC pointer to PMC controller
 * \param pck Programmable Clock x Output
 * \param mode mode
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PMC_EnablePCK(
	AT91PS_PMC pPMC, /* \arg pointer to PMC controller */
	U32 pck,  /* \arg Programmable Clock x Output */
	U32 mode);


/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PMC_DisablePCK(	AT91PS_PMC pPMC, \
 *	 								U32 pck)
 * \brief Disable Programmable Clock x Output
 * \param pPMC pointer to PMC controller
 * \param pck Programmable Clock x Output
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PMC_DisablePCK(
	AT91PS_PMC pPMC, /* \arg pointer to PMC controller */
	U32 pck);  /* \arg Programmable Clock x Output */


/*----------------------------------------------------------------------------*/
/*! \fn   void AT91F_PMC_EnableInterrupt(	AT91PS_PMC pPMC, \
 *	 									U32 flag)
 * \brief Enable PMC interrupt
 * \param pPMC pointer to PMC controller
 * \param flag interrupt to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PMC_EnableInterrupt(
	AT91PS_PMC pPMC,     /* pointer to a PMC controller */
	U32 flag);   /* interrupt to be enabled */


/*----------------------------------------------------------------------------*/
/*! \fn void  AT91F_PMC_DisableInterrupt(	AT91PS_PMC pPMC, \
 *	 									U32 flag)
 * \brief Disable PMC interrupt
 * \param pPMC pointer to PMC controller
 * \param flag interrupt to be disabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PMC_DisableInterrupt(
	AT91PS_PMC pPMC, /* pointer to a PMC controller */
	U32 flag); /* interrupt to be disabled */


/*----------------------------------------------------------------------------*/
/*! \fn  U32 AT91F_PMC_GetStatus(	AT91PS_PMC pPMC )
 * \brief Return PMC Interrupt Status
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PMC_GetStatus( /* \return PMC Interrupt Status */
	AT91PS_PMC pPMC); /* pointer to a PMC controller */


/*----------------------------------------------------------------------------*/
/*! \fn  U32  AT91F_PMC_GetInterruptMaskStatus(	AT91PS_PMC pPMC )
 * \brief Return PMC Interrupt Mask Status
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PMC_GetInterruptMaskStatus( /* \return PMC Interrupt Mask Status */
	AT91PS_PMC pPMC); /* pointer to a PMC controller */


/*----------------------------------------------------------------------------*/
/*! \fn   U32 AT91F_PMC_IsInterruptMasked(	AT91PS_PMC pPMC, \
 *	 									U32 flag)
 * \brief Test if PMC Interrupt is Masked
 * \param pPMC pointer to PMC controller
 * \param flag flag to be tested
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PMC_IsInterruptMasked(
        AT91PS_PMC pPMC,   /* \arg  pointer to a PMC controller */
        U32 flag); /* \arg  flag to be tested */


/*----------------------------------------------------------------------------*/
/*! \fn  U32 AT91F_PMC_IsStatusSet(	AT91PS_PMC pPMC, \
 *	 									U32 flag)
 * \brief Test if PMC Status is Set
 * \param pPMC pointer to PMC controller
 * \param flag flag to be tested
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PMC_IsStatusSet(
        AT91PS_PMC pPMC,   /* \arg  pointer to a PMC controller */
        U32 flag); /* \arg  flag to be tested */


/*----------------------------------------------------------------------------*/
/*!  \fn  void  AT91F_CKGR_CfgPLLRegister(	AT91PS_CKGR pCKGR, \
 *	 								U32 mode)
 *  \brief Cfg the PLL Register
 * \param pCKGR pointer to CKGR controller
 * \param mode mode
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_CKGR_CfgPLLRegister(
	AT91PS_CKGR pCKGR, /* \arg pointer to CKGR controller */
	U32 mode);


/*----------------------------------------------------------------------------*/
/*!  \fn  U32  AT91F_CKGR_GetPLLRegister(	AT91PS_CKGR pCKGR )
 *  \brief Get the PLL Register
 * \param pCKGR pointer to CKGR controller
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CKGR_GetPLLRegister(
	AT91PS_CKGR pCKGR); /* \arg pointer to CKGR controller */



/*----------------------------------------------------------------------------*/
/*! \fn  void  AT91F_PMC_CfgPMC( AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  PMC
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PMC_CfgPMC( AT91PS_PMC pPMC );


/*----------------------------------------------------------------------------*/
/*! \fn  void  AT91F_PMC_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
 * \brief Configure PIO controllers to drive PMC signals
 * \param pPIOA pointer to PIOA controller
 * \param pPIOB pointer to PIOB controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PMC_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB );



/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_PMC AT91F_PMC_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base PMC peripheral controller address
 * \param u8Controller PMC controller index
 * \return pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_PMC AT91F_PMC_GetPeripheralAddress( U8 u8Controller );

#endif /* lib_AT91SAM7_PMC_H */
