#include "basedef.h"
#include "ioat91sam7x256.h"
#include "lib_AT91SAM7_PMC.h"
#include "lib_AT91SAM7_PIO.h"
#include "lib_AT91SAM7_EMAC.h"



/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_EMAC_CfgPMC( AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  EMAC
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_EMAC_CfgPMC( AT91PS_PMC pPMC )
{
	AT91F_PMC_EnablePeripheralClock(
		pPMC, /* PIO controller base address */
		((U32) 1 << AT91C_ID_EMAC));
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_EMAC_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
 * \brief Configure PIO controllers to drive EMAC signals
 * \param pPIOA pointer to PIOA controller
 * \param pPIOB pointer to PIOB controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_EMAC_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
{
	/* Configure PIO controllers to periph mode */
	AT91F_PIO_CfgPeripheral(
		pPIOB, /* PIO controller base address */
		((U32) AT91C_PB9_EMDIO   ) |
		((U32) AT91C_PB17_ERXCK   ) |
		((U32) AT91C_PB15_ERXDV_ECRSDV) |
		((U32) AT91C_PB8_EMDC    ) |
		((U32) AT91C_PB16_ECOL    ) |
		((U32) AT91C_PB7_ERXER   ) |
		((U32) AT91C_PB5_ERX0    ) |
		((U32) AT91C_PB6_ERX1    ) |
		((U32) AT91C_PB13_ERX2    ) |
		((U32) AT91C_PB1_ETXEN   ) |
		((U32) AT91C_PB14_ERX3    ) |
		((U32) AT91C_PB12_ETXER   ) |
		((U32) AT91C_PB2_ETX0    ) |
		((U32) AT91C_PB3_ETX1    ) |
		((U32) AT91C_PB10_ETX2    ) |
		((U32) AT91C_PB18_EF100   ) |
		((U32) AT91C_PB11_ETX3    ) |
		((U32) AT91C_PB4_ECRS    ) |
		((U32) AT91C_PB0_ETXCK_EREFCK), /* Peripheral A */
		0); /* Peripheral B */
}



/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_EMAC AT91F_EMAC_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base EMAC peripheral controller address
 * \param u8Controller EMAC controller index
 * \return pointer to EMAC controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_EMAC AT91F_EMAC_GetPeripheralAddress( U8 u8Controller )
{
	return AT91C_BASE_EMAC;
}
