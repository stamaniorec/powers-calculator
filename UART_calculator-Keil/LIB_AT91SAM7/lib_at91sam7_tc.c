#include "basedef.h"
#include "ioat91sam7x256.h"
#include "lib_AT91SAM7_PMC.h"
#include "lib_AT91SAM7_PIO.h"
#include "lib_AT91SAM7_TC.h"


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_TC_EnableController( AT91PS_TC pTc, \
 * 								U32 flag)
 * \brief Enable TC controller
 * \param pTc pointer to a TC controller
 * \param flag TC to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_TC_EnableController(
        AT91PS_TC pTc,   /* \arg  pointer to a TC controller */
        U32 flag) /* \arg  TC to be enabled */
{
        pTc->TC_CCR = flag;
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_TC_ConfigureChannel( AT91PS_TC pTc, \
 * 								U32 mode)
 * \brief Configure TC channel
 * \param pTc pointer to a TC controller
 * \param mode mode to be set
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_TC_ConfigureChannel(
        AT91PS_TC pTc,   /* \arg  pointer to a TC controller */
        U32 mode) /* \arg  channel mode to be set */
{
        pTc->TC_CMR = mode;
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_TC_SetRAPeriod( AT91PS_TC pTc, \
 * 								U32 period)
 * \brief Set RA period counter
 * \param pTc pointer to a TC controller
 * \param period period in channel A ticks
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_TC_SetRAPeriod(
        AT91PS_TC pTc,   /* \arg  pointer to a TC controller */
        U32 period) /* \arg  TC mode to be setup */
{
        pTc->TC_RA = period;
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_TC_SetRBPeriod( AT91PS_TC pTc, \
 * 								U32 period)
 * \brief Set RB period counter
 * \param pTc pointer to a TC controller
 * \param period period in channel B ticks
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_TC_SetRBPeriod(
        AT91PS_TC pTc,   /* \arg  pointer to a TC controller */
        U32 period) /* \arg  RB period in ticks */
{
        pTc->TC_RB = period;
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_TC_SetRCPeriod( AT91PS_TC pTc, \
 * 								U32 period)
 * \brief Set RC period counter
 * \param pTc pointer to a TC controller
 * \param period period in channel C ticks
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_TC_SetRCPeriod(
        AT91PS_TC pTc,   /* \arg  pointer to a TC controller */
        U32 period) /* \arg  TC mode to be setup */
{
        pTc->TC_RC = period;
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_TC_InterruptEnable( AT91PS_TC pTc, \
 * 								U32 flag)
 * \brief Enable TC Interrupt
 * \param pTc pointer to a TC controller
 * \param flag TC interrupt to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_TC_InterruptEnable(
        AT91PS_TC pTc,   /* \arg  pointer to a TC controller */
        U32 flag) /* \arg  TC interrupt to be enabled */
{
        pTc->TC_IER = flag;
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_TC_InterruptDisable( AT91PS_TC pTc, \
 * 								U32 flag)
 * \brief Disable TC Interrupt
 * \param pTc pointer to a TC controller
 * \param flag TC interrupt to be disabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_TC_InterruptDisable(
        AT91PS_TC pTc,   /* \arg  pointer to a TC controller */
        U32 flag) /* \arg  TC interrupt to be disabled */
{
        pTc->TC_IDR = flag;
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_TC_GetInterruptMaskStatus( AT91PS_TC pTc )
 * \brief Return TC Interrupt Mask Status
 * \param pTc pointer to a TC controller
 * \return interrupt mask register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_TC_GetInterruptMaskStatus( /* \return TC Interrupt Mask Status */
        AT91PS_TC pTc) /* \arg  pointer to a TC controller */
{
        return pTc->TC_IMR;
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_TC_IsInterruptMasked( AT91PS_TC pTc, \
 * 								U32 flag)
 * \brief Test if TC Interrupt is Masked
 * \param pTc pointer to a TC controller
 * \param flag flag to be tested
 * \return masked interrupt mask register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_TC_IsInterruptMasked(
        AT91PS_TC pTc,   /* \arg  pointer to a TC controller */
        U32 flag) /* \arg  flag to be tested */
{
        return (AT91F_TC_GetInterruptMaskStatus(pTc) & flag);
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_TC_GetStatus( AT91PS_TC pTc )
 * \brief Return TC Status
 * \param pTc pointer to a TC controller
 * \return status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_TC_GetStatus( /* \return TC Status */
        AT91PS_TC pTc) /* \arg  pointer to a TC controller */
{
        return pTc->TC_SR;
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_TC_IsStatusMasked( AT91PS_TC pTc, \
 * 								U32 flag)
 * \brief Test if TC status is Masked
 * \param pTc pointer to a TC controller
 * \param flag flag to be tested
 * \return masked status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_TC_IsStatusMasked(
        AT91PS_TC pTc,   /* \arg  pointer to a TC controller */
        U32 flag) /* \arg  flag to be tested */
{
        return (AT91F_TC_GetStatus(pTc) & flag);
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_TCB_SetExternalClocks( AT91PS_TCB pTcb, \
 *		U32 XC0, \
 *		U32 XC1, \
 *		U32 XC2 )
 * \brief Test if TC status is Masked
 * \param pTcb pointer to a TCB controller
 * \param XC0 select external clock for XC0 (0-3)
 * \param XC1 select external clock for XC1 (0-3)
 * \param XC2 select external clock for XC2 (0-3)
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_TCB_SetExternalClocks(
		AT91PS_TCB pTcb,	/* \arg  pointer to a TC controller */
		U32 XC0,	/* select external clock for XC0 (0-3) */
		U32 XC1,	/* select external clock for XC1 (0-3) */
		U32 XC2 )	/* select external clock for XC2 (0-3) */
{
	pTcb->TCB_BMR = (XC0 & 3) | (XC1 & 3) << 2 | (XC2 & 3) << 4;
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_TCB_GetExternalClocks( AT91PS_TCB pTcb, \
 *		U32 * XC0, \
 *		U32 * XC1, \
 *		U32 * XC2 )
 * \brief Test if TC status is Masked
 * \param pTcb pointer to a TCB controller
 * \param XC0 select external clock for XC0 (0-3)
 * \param XC1 select external clock for XC1 (0-3)
 * \param XC2 select external clock for XC2 (0-3)
 * \return in XC0, XC1 and XC2 specified external clock selection
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_TCB_GetExternalClocks(
		AT91PS_TCB pTcb,	/* \arg  pointer to a TC controller */
		U32 *XC0,	/* select external clock for XC0 (0-3) */
		U32 *XC1,	/* select external clock for XC1 (0-3) */
		U32 *XC2 )	/* select external clock for XC2 (0-3) */
{
	U32 bmr;
	bmr = pTcb->TCB_BMR;

	if ( XC0 != NULL )
	{
		*XC0 = bmr & 3;
	}

	if ( XC1 != NULL )
	{
		*XC1 = (bmr >> 2) & 3;
	}

	if ( XC2 != NULL )
	{
		*XC2 = (bmr >> 4) & 3;
	}
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_TCB_GetExternalClocks( AT91PS_TCB pTcb, \
 *		U32 bSync )
 * \brief Test if TC status is Masked
 * \param pTcb pointer to a TCB controller
 * \param bSync flag to enable synchronization
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_TCB_SetSynchonization( 
		AT91PS_TCB pTcb,   /* \arg  pointer to a TC controller */
		U32 bSync )
{
	pTcb->TCB_BCR = bSync;
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_TC0_CfgPMC( AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  TC0
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_TC0_CfgPMC( AT91PS_PMC pPMC )
{
	AT91F_PMC_DisablePeripheralClock(
		pPMC, /* PIO controller base address */
		((U32) 1 << AT91C_ID_TC0));
	AT91F_PMC_EnablePeripheralClock(
		pPMC, /* PIO controller base address */
		((U32) 1 << AT91C_ID_TC0));
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_TC0_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
 * \brief Configure PIO controllers to drive TC0 signals
 * \param pPIOA pointer to PIOA controller
 * \param pPIOB pointer to PIOB controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_TC0_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
{
	/* Configure PIO controllers to periph mode */
	AT91F_PIO_CfgPeripheral(
		pPIOB, /* PIO controller base address */
		((U32) AT91C_PB23_TIOA0   ) |
		((U32) AT91C_PB24_TIOB0   ), /* Peripheral A */
		((U32) AT91C_PB12_TCLK0   )); /* Peripheral B */
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_TC1_CfgPMC( AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  TC1
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_TC1_CfgPMC( AT91PS_PMC pPMC )
{
	AT91F_PMC_EnablePeripheralClock(
		pPMC, /* PIO controller base address */
		((U32) 1 << AT91C_ID_TC1));
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_TC1_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
 * \brief Configure PIO controllers to drive TC1 signals
 * \param pPIOA pointer to PIOA controller
 * \param pPIOB pointer to PIOB controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_TC1_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
{
	/* Configure PIO controllers to periph mode */
	AT91F_PIO_CfgPeripheral(
		pPIOB, /* PIO controller base address */
		((U32) AT91C_PB25_TIOA1   ) |
		((U32) AT91C_PB26_TIOB1   ), /* Peripheral A */
		((U32) AT91C_PB19_TCLK1   )); /* Peripheral B */
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_TC2_CfgPMC( AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  TC2
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_TC2_CfgPMC( AT91PS_PMC pPMC )
{
	AT91F_PMC_EnablePeripheralClock(
		pPMC, /* PIO controller base address */
		((U32) 1 << AT91C_ID_TC2));
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_TC2_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
 * \brief Configure PIO controllers to drive TC2 signals
 * \param pPIOA pointer to PIOA controller
 * \param pPIOB pointer to PIOB controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_TC2_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
{
	/* Configure PIO controllers to periph mode */
	AT91F_PIO_CfgPeripheral(
		pPIOA, /* PIO controller base address */
		0, /* Peripheral A */
		((U32) AT91C_PA15_TCLK2   )); /* Peripheral B */
	/* Configure PIO controllers to periph mode */
	AT91F_PIO_CfgPeripheral(
		pPIOB, /* PIO controller base address */
		((U32) AT91C_PB27_TIOA2   ) |
		((U32) AT91C_PB28_TIOB2   ), /* Peripheral A */
		0); /* Peripheral B */
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_TC AT91F_TC_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base TC peripheral controller address
 * \param u8Controller TC controller index
 * \return pointer to TC controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_TC AT91F_TC_GetPeripheralAddress( U8 u8Controller )
{
	AT91PS_TC pTC;
	switch ( u8Controller ) {
	case 0:
		pTC = AT91C_BASE_TC0;
		break;
	case 1:
		pTC = AT91C_BASE_TC1;
		break;
	case 2:
		pTC = AT91C_BASE_TC2;
		break;
	default:
		pTC = NULL;
		break;
	}
	return pTC;
}
