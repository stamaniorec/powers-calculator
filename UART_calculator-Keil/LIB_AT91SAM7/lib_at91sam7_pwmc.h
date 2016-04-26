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
#ifndef lib_AT91SAM7_PWMC_H
#define lib_AT91SAM7_PWMC_H


/* *****************************************************************************
                SOFTWARE API FOR PWMC
   ***************************************************************************** */
/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PWMC_GetStatus( AT91PS_PWMC pPWM )
 * \brief Return PWM Interrupt Status
 * \param pPWM pointer to PWM controller
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PWMC_GetStatus( /* \return PWM Interrupt Status */
	AT91PS_PWMC pPWM); /* pointer to a PWM controller */


/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PWMC_InterruptEnable(	AT91PS_PWMC pPWM, \
 * 										U32 flag )
 * \brief Enable PWM Interrupt
 * \param pPWM pointer to PWM controller
 * \param flag PWM interrupt to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PWMC_InterruptEnable(
        AT91PS_PWMC pPwm,   /* \arg  pointer to a PWM controller */
        U32 flag); /* \arg  PWM interrupt to be enabled */


/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PWMC_InterruptDisable(	AT91PS_PWMC pPWM, \
 * 										U32 flag )
 * \brief Disable PWM Interrupt
 * \param pPWM pointer to PWM controller
 * \param flag PWM interrupt to be disabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PWMC_InterruptDisable(
        AT91PS_PWMC pPwm,   /* \arg  pointer to a PWM controller */
        U32 flag); /* \arg  PWM interrupt to be disabled */


/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PWMC_GetInterruptMaskStatus(	AT91PS_PWMC pPWM )
 * \brief Return PWM Interrupt Mask Status
 * \param pPWM pointer to PWM controller
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PWMC_GetInterruptMaskStatus( /* \return PWM Interrupt Mask Status */
        AT91PS_PWMC pPwm); /* \arg  pointer to a PWM controller */


/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PWMC_IsInterruptMasked(	AT91PS_PWMC pPWM, \
 * 										U32 flag )
 * \brief Test if PWM Interrupt is Masked
 * \param pPWM pointer to PWM controller
 * \param flag flag to be tested
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PWMC_IsInterruptMasked(
        AT91PS_PWMC pPWM,   /* \arg  pointer to a PWM controller */
        U32 flag); /* \arg  flag to be tested */


/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PWMC_IsStatusSet(	AT91PS_PWMC pPWM, \
 * 									U32 flag )
 * \brief Test if PWM Interrupt is Set
 * \param pPWM pointer to PWM controller
 * \param flag flag to be tested
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PWMC_IsStatusSet(
        AT91PS_PWMC pPWM,   /* \arg  pointer to a PWM controller */
        U32 flag); /* \arg  flag to be tested */


/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PWMC_CfgChannel(	AT91PS_PWMC pPWM, \
 * 									U32 channelId, \
 * 									U32 mode, \
 * 									U32 period, \
 * 									U32 duty )
 * \brief Test if PWM Interrupt is Set
 * \param pPWM pointer to PWM controller
 * \param channelId PWM channel ID
 * \param mode PWM mode
 * \param period PWM period
 * \param duty PWM duty cycle
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PWMC_CfgChannel(
        AT91PS_PWMC pPWM,   /* \arg  pointer to a PWM controller */
        U32 channelId, /* \arg PWM channel ID */
        U32 mode, /* \arg  PWM mode */
        U32 period, /* \arg PWM period */
        U32 duty); /* \arg PWM duty cycle */


/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PWMC_StartChannel(	AT91PS_PWMC pPWM, \
 * 									U32 flag )
 * \brief Enable channel
 * \param pPWM pointer to PWM controller
 * \param flag Channels IDs to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PWMC_StartChannel(
        AT91PS_PWMC pPWM,   /* \arg  pointer to a PWM controller */
        U32 flag); /* \arg  Channels IDs to be enabled */


/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PWMC_StopChannel(	AT91PS_PWMC pPWM, \
 * 									U32 flag )
 * \brief Disable channel
 * \param pPWM pointer to PWM controller
 * \param flag Channels IDs to be disabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PWMC_StopChannel(
        AT91PS_PWMC pPWM,   /* \arg  pointer to a PWM controller */
        U32 flag); /* \arg  Channels IDs to be disabled */


/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PWMC_UpdateChannel(	AT91PS_PWMC pPWM, \
 * 									U32 channelId, \
 * 									U32 update )
 * \brief Update Period or Duty Cycle
 * \param pPWM pointer to PWM controller
 * \param channelId PWM channel ID
 * \param update Channels IDs to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PWMC_UpdateChannel(
        AT91PS_PWMC pPWM,   /* \arg  pointer to a PWM controller */
        U32 channelId, /* \arg PWM channel ID */
        U32 update); /* \arg  Channels IDs to be enabled */


/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PWMC_CH3_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
 * \brief Configure PIO controllers to drive PWMC_CH3 signals
 * \param pPIOA pointer to PIOA controller
 * \param pPIOB pointer to PIOB controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PWMC_CH3_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB );


/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PWMC_CH2_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
 * \brief Configure PIO controllers to drive PWMC_CH2 signals
 * \param pPIOA pointer to PIOA controller
 * \param pPIOB pointer to PIOB controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PWMC_CH2_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB );


/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PWMC_CH1_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
 * \brief Configure PIO controllers to drive PWMC_CH1 signals
 * \param pPIOA pointer to PIOA controller
 * \param pPIOB pointer to PIOB controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PWMC_CH1_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB );


/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PWMC_CH0_CfgPIO( AT91PS_PIO pPIOA,  AT91PS_PIO pPIOB )
 * \brief Configure PIO controllers to drive PWMC_CH0 signals
 * \param pPIOA pointer to PIOA controller
 * \param pPIOB pointer to PIOB controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PWMC_CH0_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB );


/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PWMC_CfgPMC( AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  PWMC
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PWMC_CfgPMC(AT91PS_PMC pPMC);



/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_PWMC AT91F_PWMC_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base PWMC peripheral controller address
 * \param u8Controller PWMC controller index
 * \return pointer to PWMC controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_PWMC AT91F_PWMC_GetPeripheralAddress( U8 u8Controller );

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PWMC_SetModeRegister(AT91PS_PWMC pPWM, U8 u8DivA, U8 u8DivB,  U8 u8PreA, U8 u8PreB) 
 * \brief Sets PWM Mode register
 * \param pPWM pointer to PWM controller
 * \param u8DivA divider a
 * \param u8DivB divider b
 * \param u8PreA prescaler a
 * \param u8PreB prescaler b
 * \return none
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PWMC_SetModeRegister( 
		AT91PS_PWMC pPWM, /* \arg  pointer to a PWM controller */
		U8 u8DivA, /* \arg  div A */
		U8 u8DivB, /* \arg  div B */
		U8 u8PreA, /* \arg  pre A */
		U8 u8PreB); /* \arg  pre B */

#endif /* lib_AT91SAM7_PWMC_H */
