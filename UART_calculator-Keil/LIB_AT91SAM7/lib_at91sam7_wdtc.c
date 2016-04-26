#include "basedef.h"
#include "ioat91sam7x256.h"
#include "lib_AT91SAM7_PMC.h"
#include "lib_AT91SAM7_PIO.h"
#include "lib_AT91SAM7_WDTC.h"


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_WDTSetMode( AT91PS_WDTC pWDTC, \
 * 						U32 Mode)
 * \brief Set Watchdog Mode Register
 * \param pWDTC pointer to WDT controller
 * \param Mode mode value
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_WDTSetMode(
        AT91PS_WDTC pWDTC,
        U32 Mode)
{
	pWDTC->WDTC_WDMR = Mode;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_WDTRestart( AT91PS_WDTC pWDTC )
 * \brief Restart Watchdog
 * \param pWDTC pointer to WDT controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_WDTRestart(AT91PS_WDTC pWDTC)
{
	pWDTC->WDTC_WDCR = 0xA5000001;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_WDTSGetStatus( AT91PS_WDTC pWDTC )
 * \brief Get Watchdog Status
 * \param pWDTC pointer to WDT controller
 * \return watchdog status
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_WDTSGetStatus(AT91PS_WDTC pWDTC)
{
	return(pWDTC->WDTC_WDSR & 0x3);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_WDTGetPeriod(U32 ms)
 * \brief Translate ms into Watchdog Compatible value
 * \param ms time in ms
 * \return period for watchdog trigger ticks
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_WDTGetPeriod(U32 ms)
{
	if ((ms < 4) || (ms > 16000))
		return 0;
	return((ms << 8) / 1000);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_WDTC_CfgPMC( AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  WDTC
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_WDTC_CfgPMC( AT91PS_PMC pPMC )
{
	AT91F_PMC_EnablePeripheralClock(
		pPMC, /* PIO controller base address */
		((U32) 1 << AT91C_ID_SYS));
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_WDTC AT91F_WDTC_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base WDTC peripheral controller address
 * \param u8Controller WDTC controller index
 * \return pointer to WDTC controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_WDTC AT91F_WDTC_GetPeripheralAddress( U8 u8Controller )
{
	return AT91C_BASE_WDTC;
}
