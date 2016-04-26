#include "basedef.h"
#include "ioat91sam7x256.h"
#include "lib_AT91SAM7_PMC.h"
#include "lib_AT91SAM7_PIO.h"
#include "lib_AT91SAM7_RSTC.h"


/*----------------------------------------------------------------------------*/
/*! \fn  void  AT91F_RSTSoftReset(	AT91PS_RSTC pRSTC, \
 * 								U32 reset)
 * \brief Start Software Reset
 * \param pRSTC pointer to RST controller
 * \param reset reset factor
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_RSTSoftReset(
        AT91PS_RSTC pRSTC,
        U32 reset)
{
	pRSTC->RSTC_RCR = (0xA5000000 | reset);
}

/*----------------------------------------------------------------------------*/
/*! \fn   void AT91F_RSTSetMode(	AT91PS_RSTC pRSTC, \
 * 								U32 mode)
 * \brief Set Reset Mode
 * \param pRSTC pointer to RST controller
 * \param mode mode value
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_RSTSetMode(
        AT91PS_RSTC pRSTC,
        U32 mode)
{
	pRSTC->RSTC_RMR = (0xA5000000 | mode);
}

/*----------------------------------------------------------------------------*/
/*! \fn   U32 AT91F_RSTGetMode( AT91PS_RSTC pRSTC )
 * \brief Get Reset Mode
 * \param pRSTC pointer to RST controller
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_RSTGetMode(
        AT91PS_RSTC pRSTC)
{
	return (pRSTC->RSTC_RMR);
}

/*----------------------------------------------------------------------------*/
/*! \fn   U32 AT91F_RSTGetStatus( AT91PS_RSTC pRSTC )
 * \brief Get Reset Status
 * \param pRSTC pointer to RST controller
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_RSTGetStatus(
        AT91PS_RSTC pRSTC)
{
	return (pRSTC->RSTC_RSR);
}

/*----------------------------------------------------------------------------*/
/*! \fn   U32 AT91F_RSTIsSoftRstActive( AT91PS_RSTC pRSTC )
 * \brief Return !=0 if software reset is still not completed
 * \param pRSTC pointer to RST controller
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_RSTIsSoftRstActive(
        AT91PS_RSTC pRSTC)
{
	return ((pRSTC->RSTC_RSR) & AT91C_RSTC_SRCMP);
}


/*----------------------------------------------------------------------------*/
/*! \fn   void AT91F_RSTC_CfgPMC( AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  RSTC
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_RSTC_CfgPMC(AT91PS_PMC pPMC)
{
	AT91F_PMC_EnablePeripheralClock(
		pPMC, /* PIO controller base address */
		((U32) 1 << AT91C_ID_SYS));
}



/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_RSTC AT91F_RSTC_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base RSTC peripheral controller address
 * \param u8Controller RSTC controller index
 * \return pointer to RSTC controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_RSTC AT91F_RSTC_GetPeripheralAddress( U8 u8Controller )
{
	return AT91C_BASE_RSTC;
}
