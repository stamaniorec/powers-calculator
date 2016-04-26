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

#ifndef lib_AT91SAM7_USART_H
#define lib_AT91SAM7_USART_H



/* *****************************************************************************
                SOFTWARE API FOR USART
   ***************************************************************************** */
/*----------------------------------------------------------------------------*/
/*    Standard Asynchronous Mode : 8 bits , 1 stop , no parity */
#define AT91C_US_ASYNC_MODE ( AT91C_US_USMODE_NORMAL + \
                        AT91C_US_NBSTOP_1_BIT + \
                        AT91C_US_PAR_NONE + \
                        AT91C_US_CHRL_8_BITS + \
                        AT91C_US_CLKS_CLOCK )

/*    Standard External Asynchronous Mode : 8 bits , 1 stop , no parity */
#define AT91C_US_ASYNC_SCK_MODE ( AT91C_US_USMODE_NORMAL + \
                            AT91C_US_NBSTOP_1_BIT + \
                            AT91C_US_PAR_NONE + \
                            AT91C_US_CHRL_8_BITS + \
                            AT91C_US_CLKS_EXT )

/*    Standard Synchronous Mode : 8 bits , 1 stop , no parity */
#define AT91C_US_SYNC_MODE ( AT91C_US_SYNC + \
                       AT91C_US_USMODE_NORMAL + \
                       AT91C_US_NBSTOP_1_BIT + \
                       AT91C_US_PAR_NONE + \
                       AT91C_US_CHRL_8_BITS + \
                       AT91C_US_CLKS_CLOCK )

/*    SCK used Label */
#define AT91C_US_SCK_USED (AT91C_US_CKLO | AT91C_US_CLKS_EXT)

/*    Standard ISO T=0 Mode : 8 bits , 1 stop , parity */
#define AT91C_US_ISO_READER_MODE ( AT91C_US_USMODE_ISO7816_0 + \
					   		 AT91C_US_CLKS_CLOCK +\
                       		 AT91C_US_NBSTOP_1_BIT + \
                       		 AT91C_US_PAR_EVEN + \
                       		 AT91C_US_CHRL_8_BITS + \
                       		 AT91C_US_CKLO +\
                       		 AT91C_US_OVER)

/*    Standard IRDA mode */
#define AT91C_US_ASYNC_IRDA_MODE (  AT91C_US_USMODE_IRDA + \
                            AT91C_US_NBSTOP_1_BIT + \
                            AT91C_US_PAR_NONE + \
                            AT91C_US_CHRL_8_BITS + \
                            AT91C_US_CLKS_CLOCK )

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_US_Baudrate( const U32 main_clock, \
 * 											const U32 baud_rate)
 * \brief Caluculate baud_value according to the main clock and the baud rate
 * \param main_clock peripheral clock
 * \param baud_rate UART baudrate
 * \return computed baudrate
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_US_Baudrate (
	const U32 main_clock, /* \arg peripheral clock */
	const U32 baud_rate);  /* \arg UART baudrate */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US_SetBaudrate( AT91PS_USART pUSART, \
 * 								U32 mainClock, \
 * 								U32 speed)
 * \brief Set the baudrate according to the CPU clock
 * \param pUSART pointer to a USART controller
 * \param mainClock peripheral clock in Hz
 * \param speed UART baudrate
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US_SetBaudrate (
	AT91PS_USART pUSART,    /* \arg pointer to a USART controller */
	U32 mainClock, /* \arg peripheral clock */
	U32 speed);     /* \arg UART baudrate */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US_SetTimeguard( AT91PS_USART pUSART, \
 * 								U32 timeguard)
 * \brief Set USART timeguard
 * \param pUSART pointer to a USART controller
 * \param timeguard timeguard value
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US_SetTimeguard (
	AT91PS_USART pUSART,    /* \arg pointer to a USART controller */
	U32 timeguard); /* \arg timeguard value */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US_EnableInterrupt( AT91PS_USART pUSART, \
 * 								U32 flag)
 * \brief Enable USART interrupt
 * \param pUSART pointer to a USART controller
 * \param flag nterrupt to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US_EnableInterrupt (
	AT91PS_USART pUSART, /* \arg pointer to a USART controller */
	U32 flag);   /* \arg interrupt to be enabled */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US_DisableInterrupt( AT91PS_USART pUSART, \
 * 								U32 flag)
 * \brief Disable USART interrupt
 * \param pUSART pointer to a USART controller
 * \param flag nterrupt to be disabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US_DisableInterrupt (
	AT91PS_USART pUSART, /* \arg pointer to a USART controller */
	U32 flag);   /* \arg interrupt to be disabled */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US_Configure( AT91PS_USART pUSART, \
 * 								U32 mainClock, \
 * 								U32 mode, \
 * 								U32 baudRate, \
 * 								U32 timeguard)
 * \brief Configure USART
 * \param pUSART pointer to a USART controller
 * \param mainClock peripheral clock
 * \param mode mode Register to be programmed
 * \param baudRate baudrate to be programmed
 * \param timeguard timeguard to be programmed
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US_Configure (
	AT91PS_USART pUSART,     /* \arg pointer to a USART controller */
	U32 mainClock,  /* \arg peripheral clock */
	U32 mode ,      /* \arg mode Register to be programmed */
	U32 baudRate ,  /* \arg baudrate to be programmed */
	U32 timeguard); /* \arg timeguard to be programmed */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US_EnableRx( AT91PS_USART pUSART )
 * \brief Enable receiving characters
 * \param pUSART pointer to a USART controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US_EnableRx(AT91PS_USART pUSART);     /* \arg pointer to a USART controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US_EnableTx( AT91PS_USART pUSART )
 * \brief Enable sending characters
 * \param pUSART pointer to a USART controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US_EnableTx(AT91PS_USART pUSART);     /* \arg pointer to a USART controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US_ResetRx( AT91PS_USART pUSART )
 * \brief Reset Receiver and re-enable it
 * \param pUSART pointer to a USART controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US_ResetRx(AT91PS_USART pUSART);     /* \arg pointer to a USART controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US_ResetTx( AT91PS_USART pUSART )
 * \brief Reset Transmitter and re-enable it
 * \param pUSART pointer to a USART controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US_ResetTx(AT91PS_USART pUSART);     /* \arg pointer to a USART controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US_DisableRx( AT91PS_USART pUSART )
 * \brief Disable Receiver
 * \param pUSART pointer to a USART controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US_DisableRx(AT91PS_USART pUSART);     /* \arg pointer to a USART controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US_DisableTx( AT91PS_USART pUSART )
 * \brief Disable Transmitter
 * \param pUSART pointer to a USART controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US_DisableTx(AT91PS_USART pUSART);     /* \arg pointer to a USART controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US_Close( AT91PS_USART pUSART )
 * \brief Close USART: disable IT disable receiver and transmitter, close PDC
 * \param pUSART pointer to a USART controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US_Close(AT91PS_USART pUSART);     /* \arg pointer to a USART controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_US_TxReady( AT91PS_USART pUSART )
 * \brief Return 1 if a character can be written in US_THR
 * \param pUSART pointer to a USART controller
 * \return transmit ready channel status
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_US_TxReady(AT91PS_USART pUSART);     /* \arg pointer to a USART controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_US_RxReady( AT91PS_USART pUSART )
 * \brief Return 1 if a character can be read in US_RHR
 * \param pUSART pointer to a USART controller
 * \return receive ready channel status
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_US_RxReady(AT91PS_USART pUSART);     /* \arg pointer to a USART controller */

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_US_Error( AT91PS_USART pUSART )
 * \brief Return the error flag
 * \param pUSART pointer to a USART controller
 * \return error channel status
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_US_Error(AT91PS_USART pUSART);     /* \arg pointer to a USART controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US_PutChar( AT91PS_USART pUSART, \
 * 								U32 character )
 * \brief Send a character,does not check if ready to send
 * \param pUSART pointer to a USART controller
 * \param character character to be transferred
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US_PutChar (
	AT91PS_USART pUSART,
	U32 character);


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_US_GetChar( AT91PS_USART pUSART )
 * \brief Receive a character, does not check if a character is available
 * \param pUSART pointer to a USART controller
 * \return character held in receiver holding register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_US_GetChar(const AT91PS_USART pUSART);


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_US_SendFrame( AT91PS_USART pUSART, \
 * 								S8 *pBuffer, \
 * 								U32 szBuffer, \
 * 								S8 *pNextBuffer, \
 * 								U32 szNextBuffer )
 * \brief Request two frames to be queued for transmittion
 * \param pUSART pointer to a USART controller
 * \param pBuffer pointer to transmition buffer
 * \param szBuffer size of the transmition buffer
 * \param pNextBuffer pointer to next transmition buffer
 * \param szNextBuffer size of the next transmition buffer
 * \return 2 if the two buffers are prepared for sending, \n 1 if only next buffer if prepared for sending, \n 0 if buffers are busy
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_US_SendFrame(
	AT91PS_USART pUSART,
	S8 *pBuffer,
	U32 szBuffer,
	S8 *pNextBuffer,
	U32 szNextBuffer);


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_US_ReceiveFrame( AT91PS_USART pUSART, \
 * 								S8 *pBuffer, \
 * 								U32 szBuffer, \
 * 								S8 *pNextBuffer, \
 * 								U32 szNextBuffer )
 * \brief Request to queue two frames for receiving
 * \param pUSART pointer to a USART controller
 * \param pBuffer pointer to receiving buffer
 * \param szBuffer size of the receiving buffer
 * \param pNextBuffer pointer to next receiving buffer
 * \param szNextBuffer size of the next receiving buffer
 * \return 2 if the two buffers are prepared for receiving, \n 1 if only next buffer if prepared for receiving, \n 0 if buffers are busy
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_US_ReceiveFrame(
	AT91PS_USART pUSART,
	S8 *pBuffer,
	U32 szBuffer,
	S8 *pNextBuffer,
	U32 szNextBuffer);


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US_SetIrdaFilter( AT91PS_USART pUSART, \
 * 								U8 value )
 * \brief Set the value of IrDa filter tregister
 * \param pUSART pointer to a USART controller
 * \param value IRDA filter mask value
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US_SetIrdaFilter (
	AT91PS_USART pUSART,
	U8 value);


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US1_CfgPMC( AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  US1
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US1_CfgPMC( AT91PS_PMC pPMC );


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US1_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
 * \brief Configure PIO controllers to drive US1 signals
 * \param pPIOA pointer to PIOA controller
 * \param pPIOB pointer to PIOB controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US1_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB );


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US0_CfgPMC( AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  US0
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US0_CfgPMC(AT91PS_PMC pPMC);


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US0_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
 * \brief Configure PIO controllers to drive US0 signals
 * \param pPIOA pointer to PIOA controller
 * \param pPIOB pointer to PIOB controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US0_CfgPIO( AT91PS_PIO pPIOA,  AT91PS_PIO pPIOB );


/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_PDC AT91F_USART_PDC_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base PDC peripheral controller address
 * \param u8Controller PDC controller index
 * \return pointer to PDC controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_PDC AT91F_USART_PDC_GetPeripheralAddress( U8 u8Controller );

/*----------------------------------------------------------------------------*/
/*! \fn   __inline AT91PS_USART AT91F_USART_GetChannelAddress( U8 u8Channel )
 * \brief Returns USART channel address
 * \param u8Channel USART channel index
 * \return pointer to USART controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_USART AT91F_USART_GetChannelAddress( U8 u8Channel );

#endif /* lib_AT91SAM7_USART_H */
