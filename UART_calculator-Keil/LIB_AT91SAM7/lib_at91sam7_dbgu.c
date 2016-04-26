#include "basedef.h"
#include "ioat91sam7x256.h"
#include "lib_AT91SAM7_PMC.h"
#include "lib_AT91SAM7_PIO.h"
#include "lib_AT91SAM7_DBGU.h"


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_DBGU_InterruptEnable(	AT91PS_DBGU pDbgu, \
 * 										U32 flag)
 * \brief Enable DBGU Interrupt
 * \param pDbgu pointer to a DBGU controller
 * \param flag dbgu interrupt to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_DBGU_InterruptEnable(
        AT91PS_DBGU pDbgu,   /* \arg  pointer to a DBGU controller */
        U32 flag) /* \arg  dbgu interrupt to be enabled */
{
        pDbgu->DBGU_IER = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_DBGU_InterruptDisable(	AT91PS_DBGU pDbgu, \
 * 										U32 flag)
 * \brief Disable DBGU Interrupt
 * \param pDbgu pointer to a DBGU controller
 * \param flag dbgu interrupt to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_DBGU_InterruptDisable(
        AT91PS_DBGU pDbgu,   /* \arg  pointer to a DBGU controller */
        U32 flag) /* \arg  dbgu interrupt to be disabled */
{
        pDbgu->DBGU_IDR = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_DBGU_GetInterruptMaskStatus(	AT91PS_DBGU pDbgu )
 * \brief Return DBGU Interrupt Mask Status
 * \param pDbgu pointer to a DBGU controller
 * \return interrupt mask register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_DBGU_GetInterruptMaskStatus( /* \return DBGU Interrupt Mask Status */
        AT91PS_DBGU pDbgu) /* \arg  pointer to a DBGU controller */
{
        return pDbgu->DBGU_IMR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_DBGU_IsInterruptMasked(	AT91PS_DBGU pDbgu, \
 * 											U32 flag)
 * \brief Test if DBGU Interrupt is Masked
 * \param pDbgu pointer to a DBGU controller
 * \param flag dbgu interrupt to be enabled
 * \return masked interrupt mask register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_DBGU_IsInterruptMasked(
        AT91PS_DBGU pDbgu,   /* \arg  pointer to a DBGU controller */
        U32 flag) /* \arg  flag to be tested */
{
        return (AT91F_DBGU_GetInterruptMaskStatus(pDbgu) & flag);
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_DBGU_CfgPMC( AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  DBGU
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_DBGU_CfgPMC( AT91PS_PMC pPMC )
{
	AT91F_PMC_EnablePeripheralClock(
		pPMC, /* PIO controller base address */
		((U32) 1 << AT91C_ID_SYS));
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_DBGU_CfgPIO( AT91PS_PIO pPIOA,  AT91PS_PIO pPIOB )
 * \brief Configure PIO controllers to drive DBGU signals
 * \param pPIOA pointer to PIOA controller
 * \param pPIOB pointer to PIOB controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_DBGU_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
{
	/* Configure PIO controllers to periph mode */
	AT91F_PIO_CfgPeripheral(
		pPIOA, /* PIO controller base address */
		((U32) AT91C_PA28_DTXD    ) |
		((U32) AT91C_PA27_DRXD    ), /* Peripheral A */
		0); /* Peripheral B */
}



/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_DBGU AT91F_DBGU_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base DBGU peripheral controller address
 * \param u8Controller DBGU controller index
 * \return pointer to DBGU controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_DBGU AT91F_DBGU_GetPeripheralAddress( U8 u8Controller )
{
	return AT91C_BASE_DBGU;
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_PDC AT91F_DBGU_PDC_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base PDC peripheral controller address
 * \param u8Controller PDC controller index
 * \return pointer to PDC controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_PDC AT91F_DBGU_PDC_GetPeripheralAddress( U8 u8Controller )
{
	return AT91C_BASE_PDC_DBGU;
}
