#include "basedef.h"
#include "ioat91sam7x256.h"
#include "lib_AT91SAM7_PMC.h"
#include "lib_AT91SAM7_PIO.h"
#include "lib_AT91SAM7_PITC.h"


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PITInit(	AT91PS_PITC pPITC, \
 *        					U32 period, \
 *        					U32 pit_frequency)
 * \brief System timer init : period in µsecond, system clock freq in MHz
 * \param pPITC pointer to PITC controller
 * \param period period
 * \param pit_frequency frequency in MHz
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PITInit(
        AT91PS_PITC pPITC,
        U32 period,
        U32 pit_frequency)
{
	pPITC->PITC_PIMR = period? (period * pit_frequency + 8) >> 4 : 0; /* +8 to avoid %10 and /10 */
	pPITC->PITC_PIMR |= AT91C_PITC_PITEN;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PITSetPIV(	AT91PS_PITC pPITC, \
 *        					U32 piv )
 * \brief Set the PIT Periodic Interval Value
 * \param pPITC pointer to PITC controller
 * \param piv PITC mode register
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PITSetPIV(
        AT91PS_PITC pPITC,
        U32 piv)
{
	pPITC->PITC_PIMR = piv | (pPITC->PITC_PIMR & (AT91C_PITC_PITEN | AT91C_PITC_PITIEN));
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PITEnableInt(	AT91PS_PITC pPITC )
 * \brief Enable PIT periodic interrupt
 * \param pPITC pointer to PITC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PITEnableInt(
        AT91PS_PITC pPITC)
{
	pPITC->PITC_PIMR |= AT91C_PITC_PITIEN;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PITDisableInt(	AT91PS_PITC pPITC )
 * \brief Disable PIT periodic interrupt
 * \param pPITC pointer to PITC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PITDisableInt(
        AT91PS_PITC pPITC)
{
	pPITC->PITC_PIMR &= ~AT91C_PITC_PITIEN;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PITGetMode(	AT91PS_PITC pPITC )
 * \brief Read PIT mode register
 * \param pPITC pointer to PITC controller
 * \return period interval mode register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PITGetMode(
        AT91PS_PITC pPITC)
{
	return(pPITC->PITC_PIMR);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PITGetStatus(	AT91PS_PITC pPITC )
 * \brief Read PIT status register
 * \param pPITC pointer to PITC controller
 * \return period interval status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PITGetStatus(
        AT91PS_PITC pPITC)
{
	return(pPITC->PITC_PISR);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PITGetPIIR(	AT91PS_PITC pPITC )
 * \brief Read PIT CPIV and PICNT without ressetting the counters
 * \param pPITC pointer to PITC controller
 * \return period interval image register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PITGetPIIR(
        AT91PS_PITC pPITC)
{
	return(pPITC->PITC_PIIR);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PITGetPIVR(	AT91PS_PITC pPITC )
 * \brief Read System timer CPIV and PICNT without ressetting the counters
 * \param pPITC pointer to PITC controller
 * \return period interval value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PITGetPIVR(
        AT91PS_PITC pPITC)
{
	return(pPITC->PITC_PIVR);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PITC_CfgPMC( AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  PITC
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PITC_CfgPMC( AT91PS_PMC pPMC )
{
	AT91F_PMC_EnablePeripheralClock(
		pPMC, /* PIO controller base address */
		((U32) 1 << AT91C_ID_SYS));
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_PITC AT91F_PITC_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base PITC peripheral controller address
 * \param u8Controller PITC controller index
 * \return pointer to PITC controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_PITC AT91F_PITC_GetPeripheralAddress( U8 u8Controller )
{
	return AT91C_BASE_PITC;
}
