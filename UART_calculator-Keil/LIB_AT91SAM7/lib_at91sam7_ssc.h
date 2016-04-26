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
#ifndef lib_AT91SAM7_SSC_H
#define lib_AT91SAM7_SSC_H

/* *****************************************************************************
                SOFTWARE API FOR SSC
   ***************************************************************************** */
/* Define the standard I2S mode configuration
 * Configuration to set in the SSC Transmit Clock Mode Register
 * Parameters :  nb_bit_by_slot : 8, 16 or 32 bits
 * 			  nb_slot_by_frame : number of channels
 */
#define AT91C_I2S_ASY_MASTER_TX_SETTING(nb_bit_by_slot, nb_slot_by_frame)( +\
									   AT91C_SSC_CKS_DIV   +\
                            		   AT91C_SSC_CKO_CONTINOUS      +\
                            		   AT91C_SSC_CKG_NONE    +\
                                       AT91C_SSC_START_FALL_RF +\
                           			   AT91C_SSC_STTOUT  +\
                            		   ((1<<16) & AT91C_SSC_STTDLY) +\
                            		   ((((nb_bit_by_slot*nb_slot_by_frame)/2)-1) <<24))


/* Configuration to set in the SSC Transmit Frame Mode Register
 * Parameters : nb_bit_by_slot : 8, 16 or 32 bits
 * 			 nb_slot_by_frame : number of channels
 */
#define AT91C_I2S_ASY_TX_FRAME_SETTING(nb_bit_by_slot, nb_slot_by_frame)( +\
									(nb_bit_by_slot-1)  +\
                            		AT91C_SSC_MSBF   +\
                            		(((nb_slot_by_frame-1)<<8) & AT91C_SSC_DATNB)  +\
                            		(((nb_bit_by_slot-1)<<16) & AT91C_SSC_FSLEN) +\
                            		AT91C_SSC_FSOS_NEGATIVE)


/* Function prototypes from library */

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SSC_Configure(	AT91PS_SSC pSSC, \
 * 							U32 syst_clock, \
 * 							U32 baud_rate, \
 * 							U32 clock_rx, \
 * 							U32 mode_rx, \
 * 							U32 clock_tx, \
 * 							U32 mode_tx)
 * \brief Configure SSC
 * \param pSSC pointer to a SSC controller
 * \param syst_clock System Clock Frequency
 * \param baud_rate Expected Baud Rate Frequency
 * \param clock_rx Receiver Clock Parameters
 * \param mode_rx mode Register to be programmed
 * \param clock_tx Transmitter Clock Parameters
 * \param mode_tx mode Register to be programmed
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SSC_Configure(
             AT91PS_SSC pSSC,          /* \arg pointer to a SSC controller */
             U32 syst_clock,  /* \arg System Clock Frequency */
             U32 baud_rate,   /* \arg Expected Baud Rate Frequency */
             U32 clock_rx,    /* \arg Receiver Clock Parameters */
             U32 mode_rx,     /* \arg mode Register to be programmed */
             U32 clock_tx,    /* \arg Transmitter Clock Parameters */
             U32 mode_tx);    /* \arg mode Register to be programmed */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SSC_CfgPMC( AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  SSC
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SSC_CfgPMC( AT91PS_PMC pPMC );


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SSC_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
 * \brief Configure PIO controllers to drive SSC signals
 * \param pPIOA pointer to PIOA controller
 * \param pPIOB pointer to PIOB controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SSC_CfgPIO( AT91PS_PIO pPIOA,  AT91PS_PIO pPIOB );


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_SSC_ReceiveFrame( AT91PS_SSC pSSC, \
 * 								S8 *pBuffer, \
 * 								U32 szBuffer, \
 * 								S8 *pNextBuffer, \
 * 								U32 szNextBuffer )
 * \brief Request to queue two frames for receiving
 * \param pSSC pointer to a SSC controller
 * \param pBuffer pointer to receiving buffer
 * \param szBuffer size of the receiving buffer
 * \param pNextBuffer pointer to next receiving buffer
 * \param szNextBuffer size of the next receiving buffer
 * \return 2 if the two buffers are prepared for sending, \n 1 if only next buffer if prepared for sending, \n 0 if buffers are busy
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_SSC_ReceiveFrame(
	AT91PS_SSC pSSC,
	S8 *pBuffer,
	U32 szBuffer,
	S8 *pNextBuffer,
	U32 szNextBuffer );


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_SSC_SendFrame( AT91PS_SSC pSSC, \
 * 								S8 *pBuffer, \
 * 								U32 szBuffer, \
 * 								S8 *pNextBuffer, \
 * 								U32 szNextBuffer )
 * \brief Request two frames to be queued for transmittion
 * \param pSSC pointer to a SSC controller
 * \param pBuffer pointer to transmition buffer
 * \param szBuffer size of the transmition buffer
 * \param pNextBuffer pointer to next transmition buffer
 * \param szNextBuffer size of the next transmition buffer
 * \return 2 if the two buffers are prepared for sending, \n 1 if only next buffer if prepared for sending, \n 0 if buffers are busy
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_SSC_SendFrame(
	AT91PS_SSC pSSC,
	S8 *pBuffer,
	U32 szBuffer,
	S8 *pNextBuffer,
	U32 szNextBuffer );



/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SSC_SetBaudrate(	AT91PS_SSC pSSC, \
 * 									U32 mainClock, \
 * 									U32 speed)
 * \brief Set the baudrate according to the CPU clock
 * \param pSSC pointer to a SSC controller
 * \param mainClock peripheral clock
 * \param speed SSC baudrate
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SSC_SetBaudrate(
        AT91PS_SSC pSSC,        /* \arg pointer to a SSC controller */
        U32 mainClock, /* \arg peripheral clock */
        U32 speed);     /* \arg SSC baudrate */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SSC_EnableRx( AT91PS_SSC pSSC )
 * \brief Enable receiving datas
 * \param pSSC pointer to a SSC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SSC_EnableRx(
	AT91PS_SSC pSSC);     /* \arg pointer to a SSC controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SSC_DisableRx( AT91PS_SSC pSSC )
 * \brief Disable receiving datas
 * \param pSSC pointer to a SSC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SSC_DisableRx(
	AT91PS_SSC pSSC);     /* \arg pointer to a SSC controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SSC_EnableTx( AT91PS_SSC pSSC )
 * \brief Enable sending datas
 * \param pSSC pointer to a SSC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SSC_EnableTx(
	AT91PS_SSC pSSC);     /* \arg pointer to a SSC controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SSC_DisableTx( AT91PS_SSC pSSC )
 * \brief Disable sending datas
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SSC_DisableTx(
	AT91PS_SSC pSSC);     /* \arg pointer to a SSC controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SSC_EnableInterrupt( AT91PS_SSC pSSC, \
 * 						U32 flag)
 * \brief Enable SSC interrupt
 * \param pSSC pointer to a SSC controller
 * \param flag interrupt to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SSC_EnableInterrupt(
	AT91PS_SSC pSSC, /* \arg pointer to a SSC controller */
	U32 flag);   /* \arg interrupt to be enabled */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SSC_DisableInterrupt( AT91PS_SSC pSSC, \
 * 						U32 flag)
 * \brief Disable SSC interrupt
 * \param pSSC pointer to a SSC controller
 * \param flag interrupt to be disabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SSC_DisableInterrupt(
	AT91PS_SSC pSSC, /* \arg pointer to a SSC controller */
	U32 flag);   /* \arg interrupt to be disabled */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_SSC_GetInterruptMaskStatus( AT91PS_SSC pSSC )
 * \brief Return SSC Interrupt Mask Status
 * \param pSSC pointer to a SSC controller
 * \return interrupt mask register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_SSC_GetInterruptMaskStatus( /* \return SSC Interrupt Mask Status */
        AT91PS_SSC pSSC); /* \arg  pointer to a SSC controller */


/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_SSC_IsInterruptMasked( AT91PS_SSC pSSC, \
 * 						U32 flag)
 * \brief Test if SSC Interrupt is Masked
 * \param pSSC pointer to a SSC controller
 * \param flag flag to be tested
 * \return masked interrupt mask register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_SSC_IsInterruptMasked(
        AT91PS_SSC pSSC,   /* \arg  pointer to a SSC controller */
        U32 flag); /* \arg  flag to be tested */



/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_PDC AT91F_SSC_PDC_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base PDC peripheral controller address
 * \param u8Controller PDC controller index
 * \return pointer to PDC controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_PDC AT91F_SSC_PDC_GetPeripheralAddress( U8 u8Controller );


/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_SSC AT91F_SSC_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base SSC peripheral controller address
 * \param u8Controller SSC controller index
 * \return pointer to SSC controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_SSC AT91F_SSC_GetPeripheralAddress( U8 u8Controller );

#endif /* lib_AT91SAM7_SSC_H */
