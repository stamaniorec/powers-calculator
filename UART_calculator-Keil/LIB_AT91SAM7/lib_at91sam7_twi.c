#include "basedef.h"
#include "ioat91sam7x256.h"
#include "lib_AT91SAM7_PMC.h"
#include "lib_AT91SAM7_PIO.h"
#include "lib_AT91SAM7_TWI.h"

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_TWI_EnableInterrupt( AT91PS_TWI pTWI, \
 * 					U32 flag)
 * \brief Enable TWI IT
 * \param pTWI pointer to a TWI controller
 * \param flag interrupt to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_TWI_EnableInterrupt(
	AT91PS_TWI pTWI, /* \arg pointer to a TWI controller */
	U32 flag)   /* \arg interrupt to be enabled */
{
	/*    Write to the IER register */
	pTWI->TWI_IER = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_TWI_DisableInterrupt( AT91PS_TWI pTWI, \
 * 					U32 flag)
 * \brief Disable TWI IT
 * \param pTWI pointer to a TWI controller
 * \param flag interrupt to be disabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_TWI_DisableInterrupt(
	AT91PS_TWI pTWI, /* \arg pointer to a TWI controller */
	U32 flag)   /* \arg interrupt to be disabled */
{
	/*    Write to the IDR register */
	pTWI->TWI_IDR = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_TWI_Configure( AT91PS_TWI pTWI )
 * \brief Configure TWI in master mode
 * \param pTWI pointer to a TWI controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_TWI_Configure( AT91PS_TWI pTWI )          /* \arg pointer to a TWI controller */
{
    /*    Disable interrupts */
	pTWI->TWI_IDR = (U32) -1;

    /*    Reset peripheral */
	pTWI->TWI_CR = AT91C_TWI_SWRST;

	/*    Set Master mode */
	pTWI->TWI_CR = AT91C_TWI_MSEN;

}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_TWI_GetInterruptMaskStatus( AT91PS_TWI pTWI )
 * \brief Return TWI Interrupt Mask Status
 * \param pTWI pointer to a TWI controller
 * \return interrupt mask register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_TWI_GetInterruptMaskStatus( /* \return TWI Interrupt Mask Status */
        AT91PS_TWI pTWI) /* \arg  pointer to a TWI controller */
{
        return pTWI->TWI_IMR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_TWI_IsInterruptMasked( AT91PS_TWI pTWI, \
 * 					U32 flag)
 * \brief Test if TWI Interrupt is Masked
 * \param pTWI pointer to a TWI controller
 * \param flag flag to be tested
 * \return masked interrupt mask register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_TWI_IsInterruptMasked(
        AT91PS_TWI pTwi,   /* \arg  pointer to a TWI controller */
        U32 flag) /* \arg  flag to be tested */
{
        return (AT91F_TWI_GetInterruptMaskStatus(pTwi) & flag);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_TWI_CfgPMC( void )
 * \brief Enable Peripheral clock in PMC for  TWI
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_TWI_CfgPMC( AT91PS_PMC pPMC )
{
	AT91F_PMC_EnablePeripheralClock(
		pPMC, /* PIO controller base address */
		((U32) 1 << AT91C_ID_TWI));
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_TWI_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
 * \brief Configure PIO controllers to drive TWI signals
 * \param pPIOA pointer to PIOA controller
 * \param pPIOB pointer to PIOB controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_TWI_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
{
	/* Configure PIO controllers to periph mode */
	AT91F_PIO_CfgPeripheral(
		pPIOA, /* PIO controller base address */
		((U32) AT91C_PA10_TWD     ) |
		((U32) AT91C_PA11_TWCK    ), /* Peripheral A */
		0); /* Peripheral B */
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_TWI AT91F_TWI_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base TWI peripheral controller address
 * \param u8Controller TWI controller index
 * \return pointer to TWI controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_TWI AT91F_TWI_GetPeripheralAddress( U8 u8Controller )
{
	return AT91C_BASE_TWI;
}

