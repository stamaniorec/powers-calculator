#include "basedef.h"
#include "ioat91sam7x256.h"
#include "lib_AT91SAM7_PMC.h"
#include "lib_AT91SAM7_PIO.h"
#include "lib_AT91SAM7_CAN.h"

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
		S32  			control_reg)
{
	CAN_Mailbox->CAN_MB_MCR 	= 0x0;
	CAN_Mailbox->CAN_MB_MMR 	= mode_reg;
	CAN_Mailbox->CAN_MB_MAM 	= acceptance_mask_reg;
	CAN_Mailbox->CAN_MB_MID 	= id_reg;
	CAN_Mailbox->CAN_MB_MDL 	= data_low_reg;
	CAN_Mailbox->CAN_MB_MDH 	= data_high_reg;
	CAN_Mailbox->CAN_MB_MCR 	= control_reg;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_EnableCAN(AT91PS_CAN pCAN)
 * \brief enable CAN controller
 * \param pCAN pointer to CAN controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_EnableCAN(
	AT91PS_CAN pCAN)     /* pointer to a CAN controller */
{
	pCAN->CAN_MR |= AT91C_CAN_CANEN;

	/* Wait for WAKEUP flag raising <=> 11-recessive-bit were scanned by the transceiver */
	while( (pCAN->CAN_SR & AT91C_CAN_WAKEUP) != AT91C_CAN_WAKEUP );
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_DisableCAN(AT91PS_CAN pCAN)
 * \brief disables CAN controller
 * \param pCAN pointer to CAN controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_DisableCAN(
	AT91PS_CAN pCAN)     /* pointer to a CAN controller */
{
	pCAN->CAN_MR &= ~AT91C_CAN_CANEN;
}

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
	U32 flag)   /* interrupt reason to be enabled */
{
	/** Write to the IER register */
	pCAN->CAN_IER = flag;
}

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
	U32 flag) /* interrupt reason to be disabled */
{
	/** Write to the IDR register */
	pCAN->CAN_IDR = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_CAN_GetStatus(AT91PS_CAN pCAN)
 * \brief Return CAN Interrupt Status
 * \param pCAN pointer to CAN controller
 * \return status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CAN_GetStatus( /* \return CAN Interrupt Status */
	AT91PS_CAN pCAN) /* pointer to a CAN controller */
{
	return pCAN->CAN_SR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_CAN_GetInterruptMaskStatus(AT91PS_CAN pCAN)
 * \brief Return CAN Interrupt Mask Status
 * \param pCAN pointer to CAN controller
 * \return interupt mask register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CAN_GetInterruptMaskStatus( /* \return CAN Interrupt Mask Status */
	AT91PS_CAN pCAN) /* pointer to a CAN controller */
{
	return pCAN->CAN_IMR;
}

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
        U32 flag) /* \arg  flag to be tested */
{
	return (AT91F_CAN_GetInterruptMaskStatus(pCAN) & flag);
}

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
        U32 flag) /* \arg  flag to be tested */
{
	return (AT91F_CAN_GetStatus(pCAN) & flag);
}

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
	U32 mode)        /* mode register */
{
	/** Write to the MR register */
	pCAN->CAN_MR = mode;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_CAN_GetModeRegister(AT91PS_CAN pCAN)
 * \brief Return the Mode Register of the CAN controller value
 * \param pCAN pointer to CAN controller
 * \return mode register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CAN_GetModeRegister(
	AT91PS_CAN pCAN /* pointer to a CAN controller */
	)
{
	return pCAN->CAN_MR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_CAN_CfgBaudrateRegister(	AT91PS_CAN pCAN, \
 * 										U32 baudrate_cfg)
 * \brief Configure the Baudrate of the CAN controller for the network
 * \param pCAN pointer to CAN controller
 * \param baudrate_cfg baud rate configuration
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_CAN_CfgBaudrateRegister(
	AT91PS_CAN pCAN, /* pointer to a CAN controller */
	U32 baudrate_cfg)
{
	/** Write to the BR register */
	pCAN->CAN_BR = baudrate_cfg;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_CAN_GetBaudrate(AT91PS_CAN pCAN)
 * \brief Return the Baudrate of the CAN controller for the network value
 * \param pCAN pointer to CAN controller
 * \return baudrate register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CAN_GetBaudrate(
	AT91PS_CAN pCAN /* pointer to a CAN controller */
	)
{
	return pCAN->CAN_BR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_CAN_GetInternalCounter(AT91PS_CAN pCAN)
 * \brief Return CAN Timer Regsiter Value
 * \param pCAN pointer to CAN controller
 * \return time register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CAN_GetInternalCounter(
	AT91PS_CAN pCAN /* pointer to a CAN controller */
	)
{
	return pCAN->CAN_TIM;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_CAN_GetTimestamp(AT91PS_CAN pCAN)
 * \brief Return CAN Timestamp Register Value
 * \param pCAN pointer to CAN controller
 * \return time stamp register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CAN_GetTimestamp(
	AT91PS_CAN pCAN /* pointer to a CAN controller */
	)
{
	return pCAN->CAN_TIMESTP;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_CAN_GetErrorCounter(AT91PS_CAN pCAN)
 * \brief Return CAN Error Counter Register Value
 * \param pCAN pointer to CAN controller
 * \return erro counter register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CAN_GetErrorCounter(
	AT91PS_CAN pCAN /* pointer to a CAN controller */
	)
{
	return pCAN->CAN_ECR;
}

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
    U32 transfer_cmd)
{
	pCAN->CAN_TCR = transfer_cmd;
}

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
    U32 abort_cmd)
{
	pCAN->CAN_ACR = abort_cmd;
}

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
    U32 mode)
{
	CAN_Mailbox->CAN_MB_MMR = mode;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_CAN_GetMessageModeRegister(	AT91PS_CAN_MB CAN_Mailbox )
 * \brief Return the Message Mode Register
 * \param CAN_Mailbox pointer to CAN mailbox
 * \return mailbox mode register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CAN_GetMessageModeRegister(
	AT91PS_CAN_MB	CAN_Mailbox) /* pointer to a CAN Mailbox */
{
	return CAN_Mailbox->CAN_MB_MMR;
}

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
    U8 version)
{
	if(version==0)	/* IDvA Standard Format */
		CAN_Mailbox->CAN_MB_MID = id<<18;
	else	/* IDvB Extended Format */
		CAN_Mailbox->CAN_MB_MID = id | (1<<29);	/* set MIDE bit */
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_CAN_GetMessageIDRegister(	AT91PS_CAN_MB CAN_Mailbox )
 * \brief Return the Message ID Register
 * \param CAN_Mailbox pointer to CAN mailbox
 * \return mailbox ID register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CAN_GetMessageIDRegister(
	AT91PS_CAN_MB	CAN_Mailbox) /* pointer to a CAN Mailbox */
{
	return CAN_Mailbox->CAN_MB_MID;
}

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
    U32 mask)
{
	CAN_Mailbox->CAN_MB_MAM = mask;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_CAN_GetMessageAcceptanceMaskRegister(	AT91PS_CAN_MB CAN_Mailbox )
 * \brief Return the Message Acceptance Mask Register
 * \param CAN_Mailbox pointer to CAN mailbox
 * \return mailbox acceptance mask register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CAN_GetMessageAcceptanceMaskRegister(
	AT91PS_CAN_MB	CAN_Mailbox) /* pointer to a CAN Mailbox */
{
	return CAN_Mailbox->CAN_MB_MAM;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_CAN_GetFamilyID(	AT91PS_CAN_MB CAN_Mailbox )
 * \brief Return the Message ID Register
 * \param CAN_Mailbox pointer to CAN mailbox
 * \return mailbox family ID register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CAN_GetFamilyID(
	AT91PS_CAN_MB	CAN_Mailbox) /* pointer to a CAN Mailbox */
{
	return CAN_Mailbox->CAN_MB_MFID;
}

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
    U32 message_ctrl_cmd)
{
	CAN_Mailbox->CAN_MB_MCR = message_ctrl_cmd;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_CAN_GetMessageStatus(	AT91PS_CAN_MB CAN_Mailbox )
 * \brief Return CAN Mailbox Status
 * \param CAN_Mailbox pointer to CAN mailbox
 * \return mailbox status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CAN_GetMessageStatus(
	AT91PS_CAN_MB	CAN_Mailbox) /* pointer to a CAN Mailbox */
{
	return CAN_Mailbox->CAN_MB_MSR;
}

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
    U32 data)
{
	CAN_Mailbox->CAN_MB_MDL = data;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_CAN_GetMessageDataLow(	AT91PS_CAN_MB CAN_Mailbox )
 * \brief Return data low value
 * \param CAN_Mailbox pointer to CAN mailbox
 * \return low 4 bytes from the frame
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CAN_GetMessageDataLow(
	AT91PS_CAN_MB	CAN_Mailbox) /* pointer to a CAN Mailbox */
{
	return CAN_Mailbox->CAN_MB_MDL;
}

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
    U32 data)
{
	CAN_Mailbox->CAN_MB_MDH = data;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_CAN_GetMessageDataHigh(	AT91PS_CAN_MB CAN_Mailbox )
 * \brief Return data high value
 * \param CAN_Mailbox pointer to CAN mailbox
 * \return high 4 bytes of the message
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CAN_GetMessageDataHigh(
	AT91PS_CAN_MB	CAN_Mailbox) /* pointer to a CAN Mailbox */
{
	return CAN_Mailbox->CAN_MB_MDH;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_CAN_CfgPMC( AT191PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  CAN
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_CAN_CfgPMC( AT91PS_PMC pPMC )
{
	AT91F_PMC_EnablePeripheralClock(
		pPMC, /* PIO controller base address */
		((U32) 1 << AT91C_ID_CAN));
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_CAN_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
 * \brief Configure PIO controllers to drive CAN signals
 * \param pPIOA pointer to PIOA controller
 * \param pPIOB pointer to PIOB controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_CAN_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
{
	/* Configure PIO controllers to periph mode */
	AT91F_PIO_CfgPeripheral(
		pPIOA, /* PIOA controller base address */
		((U32) AT91C_PA20_CANTX ) |
		((U32) AT91C_PA19_CANRX ), /* Peripheral A */
		0); /* Peripheral B */
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_CAN AT91F_CAN_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base CAN peripheral controller address
 * \param u8Controller CAN controller index
 * \return pointer to CAN controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_CAN AT91F_CAN_GetPeripheralAddress( U8 u8Controller )
{
	return AT91C_BASE_CAN;

}

