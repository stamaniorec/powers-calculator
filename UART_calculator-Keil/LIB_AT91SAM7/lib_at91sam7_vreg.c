#include "basedef.h"
#include "ioat91sam7x256.h"
#include "lib_AT91SAM7_PMC.h"
#include "lib_AT91SAM7_PIO.h"
#include "lib_AT91SAM7_VREG.h"


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_VREG_Enable_LowPowerMode( AT91PS_VREG pVREG )
 * \brief Enable VREG Low Power Mode
 * \param pVREG pointer to VREG controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_VREG_Enable_LowPowerMode(
        AT91PS_VREG pVREG)
{
	pVREG->VREG_MR |= AT91C_VREG_PSTDBY;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_VREG_Disable_LowPowerMode( AT91PS_VREG pVREG )
 * \brief Disable VREG Low Power Mode
 * \param pVREG pointer to VREG controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_VREG_Disable_LowPowerMode(
        AT91PS_VREG pVREG)
{
	pVREG->VREG_MR &= ~AT91C_VREG_PSTDBY;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_VREG_CfgPMC( AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  VREG
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_VREG_CfgPMC( AT91PS_PMC pPMC )
{
	AT91F_PMC_EnablePeripheralClock(
		pPMC, /* PIO controller base address */
		((U32) 1 << AT91C_ID_SYS));
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_VREG AT91F_VREG_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base VREG peripheral controller address
 * \param u8Controller VREG controller index
 * \return pointer to VREG controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_VREG AT91F_VREG_GetPeripheralAddress( U8 u8Controller )
{
	return AT91C_BASE_VREG;
}
