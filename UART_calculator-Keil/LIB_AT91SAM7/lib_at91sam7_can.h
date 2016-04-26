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
#ifndef lib_AT91SAM7_CAN_H
#define lib_AT91SAM7_CAN_H


/* *****************************************************************************
                SOFTWARE API FOR CAN
   ***************************************************************************** */
#define	STANDARD_FORMAT 0
#define	EXTENDED_FORMAT 1

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_InitMailboxRegisters(AT91PS_CAN_MB	CAN_Mailbox, \
 *								S32  			mode_reg, \
 *								S32 			acceptance_mask_reg, \
 *								S32  			id_reg, \
 *								S32  			data_low_reg, \
 *								S32  			data_high_reg, \
 *								S32  			control_reg)
 * \brief Configure the corresponding mailbox
 * \param CAN_Mailbox pointer to CAN mailbox structure
 * \param mode_reg CAN mailbox mode register value
 * \param acceptance_mask_reg acceptance mask
 * \param id_reg message id
 * \param data_low_reg CAN message low 4 bytes
 * \param data_high_reg CAN message high 4 bytes
 * \param control_reg control ( data lenght, RTR, abort, start transmission )
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_InitMailboxRegisters(AT91PS_CAN_MB	CAN_Mailbox,
		S32  			mode_reg,
		S32 			acceptance_mask_reg,
		S32  			id_reg,
		S32  			data_low_reg,
		S32  			data_high_reg,
		S32  			control_reg);


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_CAN_Enable(AT91PS_CAN pCAN)
 * \brief enable CAN controller
 * \param pCAN pointer to CAN controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_CAN_Enable(
	AT91PS_CAN pCAN);     /* pointer to a CAN controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_CAN_Disable(AT91PS_CAN pCAN)
 * \brief disables CAN controller
 * \param pCAN pointer to CAN controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_CAN_Disable(
	AT91PS_CAN pCAN);     /* pointer to a CAN controller */

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_CAN_EnableInterrupt(	AT91PS_CAN pCAN, \
 * 								U32 flag)
 * \brief Enable CAN interrupt
 * \param pCAN pointer to CAN controller
 * \param flag interrupt reason to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_CAN_EnableInterrupt(
	AT91PS_CAN pCAN,     /* pointer to a CAN controller */
	U32 flag);   /* interrupt reason to be enabled */

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_CAN_DisableInterrupt(	AT91PS_CAN pCAN, \
 * 								U32 flag)
 * \brief Disable CAN interrupt
 * \param pCAN pointer to CAN controller
 * \param flag interrupt reason to be disabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_CAN_DisableInterrupt(
	AT91PS_CAN pCAN, /* pointer to a CAN controller */
	U32 flag); /* interrupt reason to be disabled */

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_CAN_GetStatus(AT91PS_CAN pCAN)
 * \brief Return CAN Interrupt Status
 * \param pCAN pointer to CAN controller
 * \return status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CAN_GetStatus( /* \return CAN Interrupt Status */
	AT91PS_CAN pCAN); /* pointer to a CAN controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_CAN_GetInterruptMaskStatus(AT91PS_CAN pCAN)
 * \brief Return CAN Interrupt Mask Status
 * \param pCAN pointer to CAN controller
 * \return interupt mask register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CAN_GetInterruptMaskStatus( /* \return CAN Interrupt Mask Status */
	AT91PS_CAN pCAN); /* pointer to a CAN controller */

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_CAN_IsInterruptMasked(	AT91PS_CAN pCAN, \
 * 										U32 flag)
 * \brief Test if CAN Interrupt is Masked
 * \param pCAN pointer to CAN controller
 * \param flag to be tested
 * \return masked interrupt mask register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CAN_IsInterruptMasked(
        AT91PS_CAN pCAN,   /* \arg  pointer to a CAN controller */
        U32 flag); /* \arg  flag to be tested */

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_CAN_IsStatusSet(	AT91PS_CAN pCAN, \
 * 									U32 flag)
 * \brief Test if CAN Interrupt is Set
 * \param pCAN pointer to CAN controller
 * \param flag to be tested
 * \return masked status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CAN_IsStatusSet(
        AT91PS_CAN pCAN,   /* \arg  pointer to a CAN controller */
        U32 flag); /* \arg  flag to be tested */

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_CAN_CfgModeRegister(	AT91PS_CAN pCAN, \
 * 									U32 mode)
 * \brief Configure the Mode Register of the CAN controller
 * \param pCAN pointer to CAN controller
 * \param mode CAN controller mode
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_CAN_CfgModeRegister(
	AT91PS_CAN pCAN, /* pointer to a CAN controller */
	U32 mode);        /* mode register */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_CAN_GetModeRegister(AT91PS_CAN pCAN)
 * \brief Return the Mode Register of the CAN controller value
 * \param pCAN pointer to CAN controller
 * \return mode register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CAN_GetModeRegister(
	AT91PS_CAN pCAN); /* pointer to a CAN controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_CAN_CfgBaudrateReg(	AT91PS_CAN pCAN, \
 * 										U32 baudrate_cfg)
 * \brief Configure the Baudrate of the CAN controller for the network
 * \param pCAN pointer to CAN controller
 * \param baudrate_cfg baud rate configuration
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_CAN_CfgBaudrateRegister(
	AT91PS_CAN pCAN, /* pointer to a CAN controller */
	U32 baudrate_cfg);


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_CAN_GetBaudrate(AT91PS_CAN pCAN)
 * \brief Return the Baudrate of the CAN controller for the network value
 * \param pCAN pointer to CAN controller
 * \return baudrate register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CAN_GetBaudrate(
	AT91PS_CAN pCAN ); /* pointer to a CAN controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_CAN_GetInternalCounter(AT91PS_CAN pCAN)
 * \brief Return CAN Timer Regsiter Value
 * \param pCAN pointer to CAN controller
 * \return time register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CAN_GetInternalCounter(
	AT91PS_CAN pCAN ); /* pointer to a CAN controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_CAN_GetTimestamp(AT91PS_CAN pCAN)
 * \brief Return CAN Timestamp Register Value
 * \param pCAN pointer to CAN controller
 * \return time stamp register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CAN_GetTimestamp(
	AT91PS_CAN pCAN ); /* pointer to a CAN controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_CAN_GetErrorCounter(AT91PS_CAN pCAN)
 * \brief Return CAN Error Counter Register Value
 * \param pCAN pointer to CAN controller
 * \return erro counter register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CAN_GetErrorCounter(
	AT91PS_CAN pCAN ); /* pointer to a CAN controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_CAN_InitTransferRequest(	AT91PS_CAN pCAN, \
 * 											U32 transfer_cmd)
 * \brief Request for a transfer on the corresponding mailboxes
 * \param pCAN pointer to CAN controller
 * \param transfer_cmd transfer command
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_CAN_InitTransferRequest(
	AT91PS_CAN pCAN, /* pointer to a CAN controller */
    U32 transfer_cmd);

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_CAN_InitAbortRequest(	AT91PS_CAN pCAN, \
 * 										U32 abort_cmd)
 * \brief Abort the corresponding mailboxes
 * \param pCAN pointer to CAN controller
 * \param abort_cmd abort command
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_CAN_InitAbortRequest(
	AT91PS_CAN pCAN, /* pointer to a CAN controller */
    U32 abort_cmd);


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_CAN_CfgMessageModeRegister(	AT91PS_CAN_MB CAN_Mailbox, \
 * 										U32 mode)
 * \brief Program the Message Mode Register
 * \param CAN_Mailbox pointer to CAN mailbox
 * \param mode mode
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_CAN_CfgMessageModeRegister(
	AT91PS_CAN_MB	CAN_Mailbox, /* pointer to a CAN Mailbox */
    U32 mode);

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_CAN_GetMessageModeRegister(	AT91PS_CAN_MB CAN_Mailbox )
 * \brief Return the Message Mode Register
 * \param CAN_Mailbox pointer to CAN mailbox
 * \return mailbox mode register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CAN_GetMessageModeRegister(
	AT91PS_CAN_MB	CAN_Mailbox); /* pointer to a CAN Mailbox */

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_CAN_CfgMessageIDRegister(	AT91PS_CAN_MB CAN_Mailbox, \
 * 										U32 id, \
 * 										U8 version )
 * \brief Program the Message ID Register
 * \brief Version == 0 for Standard messsage, Version == 1 for Extended
 * \param CAN_Mailbox pointer to CAN controller
 * \param id message ID
 * \param version 18bit or 29bit identifier
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_CAN_CfgMessageIDRegister(
	AT91PS_CAN_MB	CAN_Mailbox, /* pointer to a CAN Mailbox */
    U32 id,
    U8 version);


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_CAN_GetMessageIDRegister(	AT91PS_CAN_MB CAN_Mailbox )
 * \brief Return the Message ID Register
 * \param CAN_Mailbox pointer to CAN mailbox
 * \return mailbox ID register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CAN_GetMessageIDRegister(
	AT91PS_CAN_MB	CAN_Mailbox); /* pointer to a CAN Mailbox */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_CAN_CfgMessageAcceptanceMaskRegister(	AT91PS_CAN_MB CAN_Mailbox, \
 * 													U32 mask )
 * \brief Program the Message Acceptance Mask Register
 * \param CAN_Mailbox pointer to CAN mailbox
 * \param mask acceptance mask
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_CAN_CfgMessageAcceptanceMaskRegister(
	AT91PS_CAN_MB	CAN_Mailbox, /* pointer to a CAN Mailbox */
    U32 mask);

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_CAN_GetMessageAcceptanceMaskRegister(	AT91PS_CAN_MB CAN_Mailbox )
 * \brief Return the Message Acceptance Mask Register
 * \param CAN_Mailbox pointer to CAN mailbox
 * \return mailbox acceptance mask register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CAN_GetMessageAcceptanceMaskRegister(
	AT91PS_CAN_MB	CAN_Mailbox); /* pointer to a CAN Mailbox */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_CAN_GetFamilyID(	AT91PS_CAN_MB CAN_Mailbox )
 * \brief Return the Message ID Register
 * \param CAN_Mailbox pointer to CAN mailbox
 * \return mailbox family ID register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CAN_GetFamilyID(
	AT91PS_CAN_MB	CAN_Mailbox); /* pointer to a CAN Mailbox */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_CAN_CfgMessageCtrlRegister(	AT91PS_CAN_MB CAN_Mailbox, \
 * 										U32 message_ctrl_cmd )
 * \brief Request and config for a transfer on the corresponding mailbox
 * \param CAN_Mailbox pointer to CAN mailbox
 * \param message_ctrl_cmd message control command
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_CAN_CfgMessageCtrlRegister(
	AT91PS_CAN_MB	CAN_Mailbox, /* pointer to a CAN Mailbox */
    U32 message_ctrl_cmd);


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_CAN_GetMessageStatus(	AT91PS_CAN_MB CAN_Mailbox )
 * \brief Return CAN Mailbox Status
 * \param CAN_Mailbox pointer to CAN mailbox
 * \return mailbox status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CAN_GetMessageStatus(
	AT91PS_CAN_MB	CAN_Mailbox); /* pointer to a CAN Mailbox */

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_CAN_CfgMessageDataLow(	AT91PS_CAN_MB CAN_Mailbox, \
 * 										U32 data )
 * \brief Program data low value
 * \param CAN_Mailbox pointer to CAN mailbox
 * \param data set low 4 bytes of the message
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_CAN_CfgMessageDataLow(
	AT91PS_CAN_MB	CAN_Mailbox, /* pointer to a CAN Mailbox */
    U32 data);


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_CAN_GetMessageDataLow(	AT91PS_CAN_MB CAN_Mailbox )
 * \brief Return data low value
 * \param CAN_Mailbox pointer to CAN mailbox
 * \return low 4 bytes from the frame
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CAN_GetMessageDataLow(
	AT91PS_CAN_MB	CAN_Mailbox); /* pointer to a CAN Mailbox */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_CAN_CfgMessageDataHigh(	AT91PS_CAN_MB CAN_Mailbox, \
 * 										U32 data )
 * \brief Program data high value
 * \param CAN_Mailbox pointer to CAN mailbox
 * \param data set high 4 bytes of the message
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_CAN_CfgMessageDataHigh(
	AT91PS_CAN_MB	CAN_Mailbox, /* pointer to a CAN Mailbox */
    U32 data);


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_CAN_GetMessageDataHigh(	AT91PS_CAN_MB CAN_Mailbox )
 * \brief Return data high value
 * \param CAN_Mailbox pointer to CAN mailbox
 * \return high 4 bytes of the message
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CAN_GetMessageDataHigh(
	AT91PS_CAN_MB	CAN_Mailbox); /* pointer to a CAN Mailbox */

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_CAN_CfgPMC( AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  CAN
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_CAN_CfgPMC( AT91PS_PMC pPMC );

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_CAN_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
 * \brief Configure PIO controllers to drive CAN signals
 * \param pPIOA pointer to PIOA controller
 * \param pPIOB pointer to PIOB controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_CAN_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB );

/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_CAN AT91F_CAN_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base CAN peripheral controller address
 * \param u8Controller CAN controller index
 * \return pointer to CAN controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_CAN AT91F_CAN_GetPeripheralAddress( U8 u8Controller );


#endif /* lib_AT91SAM7_CAN_H */
