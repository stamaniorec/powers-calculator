#include "basedef.h"
#include "ioat91sam7x256.h"
#include "lib_AT91SAM7_PMC.h"
#include "lib_AT91SAM7_PIO.h"
#include "lib_AT91SAM7_RTTC.h"

/*----------------------------------------------------------------------------*/
/*! \fn   U32  AT91F_RTT_SetTimeBase(	AT91PS_RTTC pRTTC, \
 * 									U32 ms)
 * \brief  Set the RTT prescaler according to the TimeBase in ms
 * \param pRTTC pointer to RTT controller
 * \param ms time in ms
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_RTT_SetTimeBase(
        AT91PS_RTTC pRTTC,
        U32 ms)
{
	if (ms > 2000)
		return 1;   /* AT91C_TIME_OUT_OF_RANGE */
	pRTTC->RTTC_RTMR &= ~0xFFFF;
	pRTTC->RTTC_RTMR |= (((ms << 15) /1000) & 0xFFFF);
	return 0;
}

/*----------------------------------------------------------------------------*/
/*! \fn   U32  AT91F_RTT_SetPrescaler(	AT91PS_RTTC pRTTC, \
 * 									U32 rtpres)
 * \brief  Set the new prescaler value
 * \param pRTTC pointer to RTT controller
 * \param rtpres real time prescaler
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_RTT_SetPrescaler(
        AT91PS_RTTC pRTTC,
        U32 rtpres)
{
	pRTTC->RTTC_RTMR &= ~0xFFFF;
	pRTTC->RTTC_RTMR |= (rtpres & 0xFFFF);
	return (pRTTC->RTTC_RTMR);
}

/*----------------------------------------------------------------------------*/
/*! \fn   void  AT91F_RTT_Restart( AT91PS_RTTC pRTTC )
 * \brief  Restart the RTT prescaler
 * \param pRTTC pointer to RTT controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_RTT_Restart(
        AT91PS_RTTC pRTTC)
{
	pRTTC->RTTC_RTMR |= AT91C_RTTC_RTTRST;
}


/*----------------------------------------------------------------------------*/
/*! \fn  void   AT91F_RTT_SetAlarmInterrupt( AT91PS_RTTC pRTTC )
 * \brief  Enable RTT Alarm Interrupt
 * \param pRTTC pointer to RTT controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_RTT_SetAlarmInterrupt(
        AT91PS_RTTC pRTTC)
{
	pRTTC->RTTC_RTMR |= AT91C_RTTC_ALMIEN;
}

/*----------------------------------------------------------------------------*/
/*! \fn   void  AT91F_RTT_ClearAlarmInterrupt( AT91PS_RTTC pRTTC )
 * \brief  Disable RTT Alarm Interrupt
 * \param pRTTC pointer to RTT controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_RTT_ClearAlarmInterrupt(
        AT91PS_RTTC pRTTC)
{
	pRTTC->RTTC_RTMR &= ~AT91C_RTTC_ALMIEN;
}

/*----------------------------------------------------------------------------*/
/*! \fn  void  AT91F_RTT_SetRttIncInterrupt( AT91PS_RTTC pRTTC )
 * \brief  Enable RTT INC Interrupt
 * \param pRTTC pointer to RTT controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_RTT_SetRttIncInterrupt(
        AT91PS_RTTC pRTTC)
{
	pRTTC->RTTC_RTMR |= AT91C_RTTC_RTTINCIEN;
}

/*----------------------------------------------------------------------------*/
/*! \fn   void  AT91F_RTT_ClearRttIncInterrupt( AT91PS_RTTC pRTTC )
 * \brief  Disable RTT INC Interrupt
 * \param pRTTC pointer to RTT controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_RTT_ClearRttIncInterrupt(
        AT91PS_RTTC pRTTC)
{
	pRTTC->RTTC_RTMR &= ~AT91C_RTTC_RTTINCIEN;
}

/*----------------------------------------------------------------------------*/
/*! \fn    void AT91F_RTT_SetAlarmValue(	AT91PS_RTTC pRTTC, \
 * 										U32 alarm )
 * \brief  Set RTT Alarm Value
 * \param pRTTC pointer to RTT controller
 * \param alarm alarm value
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_RTT_SetAlarmValue(
        AT91PS_RTTC pRTTC, U32 alarm)
{
	pRTTC->RTTC_RTAR = alarm;
}

/*----------------------------------------------------------------------------*/
/*! \fn    U32 AT91F_RTT_GetAlarmValue( AT91PS_RTTC pRTTC )
 * \brief  Get RTT Alarm Value
 * \param pRTTC pointer to RTT controller
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_RTT_GetAlarmValue(
        AT91PS_RTTC pRTTC)
{
	return (pRTTC->RTTC_RTAR);
}

/*----------------------------------------------------------------------------*/
/*! \fn  U32   AT91F_RTT_GetStatus( AT91PS_RTTC pRTTC )
 * \brief  Read the RTT status
 * \param pRTTC pointer to RTT controller
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_RTT_GetStatus(
        AT91PS_RTTC pRTTC)
{
	return (pRTTC->RTTC_RTSR);
}

/*----------------------------------------------------------------------------*/
/*! \fn    U32 AT91F_RTT_ReadValue( AT91PS_RTTC pRTTC )
 * \brief  Read the RTT value
 * \param pRTTC pointer to RTT controller
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_RTT_ReadValue(
        AT91PS_RTTC pRTTC)
{
	register volatile U32 val1,val2;
	do
	{
		val1 = pRTTC->RTTC_RTVR;
		val2 = pRTTC->RTTC_RTVR;
	}
	while(val1 != val2);
	return(val1);
}

/*----------------------------------------------------------------------------*/
/*! \fn   void AT91F_RTTC_CfgPMC( AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  RTTC
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_RTTC_CfgPMC(AT91PS_PMC pPMC)
{
	AT91F_PMC_EnablePeripheralClock(
		pPMC, /* PIO controller base address */
		((U32) 1 << AT91C_ID_SYS));
}




/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_RTTC AT91F_RTTC_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base RTTC peripheral controller address
 * \param u8Controller RTTC controller index
 * \return pointer to RTTC controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_RTTC AT91F_RTTC_GetPeripheralAddress( U8 u8Controller )
{
	return AT91C_BASE_RTTC;
}
