#include "basedef.h"
#include "ioat91sam7x256.h"
#include "lib_AT91SAM7_PMC.h"
#include "lib_AT91SAM7_PIO.h"
#include "lib_AT91SAM7_PWMC.h"


/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PWMC_GetStatus( AT91PS_PWMC pPWM )
 * \brief Return PWM Interrupt Status
 * \param pPWM pointer to PWM controller
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PWMC_GetStatus( /* \return PWM Interrupt Status */
	AT91PS_PWMC pPWM) /* pointer to a PWM controller */
{
	return pPWM->PWMC_SR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PWMC_InterruptEnable(	AT91PS_PWMC pPWM, \
 * 										U32 flag )
 * \brief Enable PWM Interrupt
 * \param pPWM pointer to PWM controller
 * \param flag PWM interrupt to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PWMC_InterruptEnable(
        AT91PS_PWMC pPwm,   /* \arg  pointer to a PWM controller */
        U32 flag) /* \arg  PWM interrupt to be enabled */
{
        pPwm->PWMC_IER = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PWMC_InterruptDisable(	AT91PS_PWMC pPWM, \
 * 										U32 flag )
 * \brief Disable PWM Interrupt
 * \param pPWM pointer to PWM controller
 * \param flag PWM interrupt to be disabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PWMC_InterruptDisable(
        AT91PS_PWMC pPwm,   /* \arg  pointer to a PWM controller */
        U32 flag) /* \arg  PWM interrupt to be disabled */
{
        pPwm->PWMC_IDR = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PWMC_GetInterruptMaskStatus(	AT91PS_PWMC pPWM )
 * \brief Return PWM Interrupt Mask Status
 * \param pPWM pointer to PWM controller
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PWMC_GetInterruptMaskStatus( /* \return PWM Interrupt Mask Status */
        AT91PS_PWMC pPwm) /* \arg  pointer to a PWM controller */
{
        return pPwm->PWMC_IMR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PWMC_IsInterruptMasked(	AT91PS_PWMC pPWM, \
 * 										U32 flag )
 * \brief Test if PWM Interrupt is Masked
 * \param pPWM pointer to PWM controller
 * \param flag flag to be tested
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PWMC_IsInterruptMasked(
        AT91PS_PWMC pPWM,   /* \arg  pointer to a PWM controller */
        U32 flag) /* \arg  flag to be tested */
{
	return (AT91F_PWMC_GetInterruptMaskStatus(pPWM) & flag);
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PWMC_IsStatusSet(	AT91PS_PWMC pPWM, \
 * 									U32 flag )
 * \brief Test if PWM Interrupt is Set
 * \param pPWM pointer to PWM controller
 * \param flag flag to be tested
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PWMC_IsStatusSet(
        AT91PS_PWMC pPWM,   /* \arg  pointer to a PWM controller */
        U32 flag) /* \arg  flag to be tested */
{
	return (AT91F_PWMC_GetStatus(pPWM) & flag);
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PWMC_CfgChannel(	AT91PS_PWMC pPWM, \
 * 									U32 channelId, \
 * 									U32 mode, \
 * 									U32 period, \
 * 									U32 duty )
 * \brief Test if PWM Interrupt is Set
 * \param pPWM pointer to PWM controller
 * \param channelId PWM channel ID
 * \param mode PWM mode
 * \param period PWM period
 * \param duty PWM duty cycle
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PWMC_CfgChannel(
        AT91PS_PWMC pPWM,   /* \arg  pointer to a PWM controller */
        U32 channelId, /* \arg PWM channel ID */
        U32 mode, /* \arg  PWM mode */
        U32 period, /* \arg PWM period */
        U32 duty) /* \arg PWM duty cycle */
{
	pPWM->PWMC_CH[channelId].PWMC_CMR = mode;
	pPWM->PWMC_CH[channelId].PWMC_CDTYR = duty;
	pPWM->PWMC_CH[channelId].PWMC_CPRDR = period;
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PWMC_StartChannel(	AT91PS_PWMC pPWM, \
 * 									U32 flag )
 * \brief Enable channel
 * \param pPWM pointer to PWM controller
 * \param flag Channels IDs to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PWMC_StartChannel(
        AT91PS_PWMC pPWM,   /* \arg  pointer to a PWM controller */
        U32 flag) /* \arg  Channels IDs to be enabled */
{
	pPWM->PWMC_ENA = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PWMC_StopChannel(	AT91PS_PWMC pPWM, \
 * 									U32 flag )
 * \brief Disable channel
 * \param pPWM pointer to PWM controller
 * \param flag Channels IDs to be disabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PWMC_StopChannel(
        AT91PS_PWMC pPWM,   /* \arg  pointer to a PWM controller */
        U32 flag) /* \arg  Channels IDs to be disabled */
{
	pPWM->PWMC_DIS = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PWMC_UpdateChannel(	AT91PS_PWMC pPWM, \
 * 									U32 channelId, \
 * 									U32 update )
 * \brief Update Period or Duty Cycle
 * \param pPWM pointer to PWM controller
 * \param channelId PWM channel ID
 * \param update Channels IDs to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PWMC_UpdateChannel(
        AT91PS_PWMC pPWM,   /* \arg  pointer to a PWM controller */
        U32 channelId, /* \arg PWM channel ID */
        U32 update) /* \arg  Channels IDs to be enabled */
{
	pPWM->PWMC_CH[channelId].PWMC_CUPDR = update;
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PWMC_CH3_CfgPIO(  AT91PS_PIO pPIOA,  AT91PS_PIO pPIOB )
 * \brief Configure PIO controllers to drive PWMC_CH3 signals
 * \param pPIOA pointer to PIOA controller
 * \param pPIOB pointer to PIOB controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PWMC_CH3_CfgPIO( AT91PS_PIO pPIOA,  AT91PS_PIO pPIOB )
{
	/* Configure PIO controllers to periph mode */
	AT91F_PIO_CfgPeripheral(
		pPIOB, /* PIO controller base address */
		((U32) AT91C_PB22_PWM3    ), /* Peripheral A */
		((U32) AT91C_PB30_PWM3    )); /* Peripheral B */
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PWMC_CH2_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
 * \brief Configure PIO controllers to drive PWMC_CH2 signals
 * \param pPIOA pointer to PIOA controller
 * \param pPIOB pointer to PIOB controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PWMC_CH2_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
{
	/* Configure PIO controllers to periph mode */
	AT91F_PIO_CfgPeripheral(
		pPIOB, /* PIO controller base address */
		((U32) AT91C_PB21_PWM2    ), /* Peripheral A */
		((U32) AT91C_PB29_PWM2    )); /* Peripheral B */
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PWMC_CH1_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
 * \brief Configure PIO controllers to drive PWMC_CH1 signals
 * \param pPIOA pointer to PIOA controller
 * \param pPIOB pointer to PIOB controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PWMC_CH1_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
{
	/* Configure PIO controllers to periph mode */
	AT91F_PIO_CfgPeripheral(
		pPIOB, /* PIO controller base address */
		((U32) AT91C_PB20_PWM1    ), /* Peripheral A */
		((U32) AT91C_PB28_PWM1    )); /* Peripheral B */
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PWMC_CH0_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
 * \brief Configure PIO controllers to drive PWMC_CH0 signals
 * \param pPIOA pointer to PIOA controller
 * \param pPIOB pointer to PIOB controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PWMC_CH0_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
{
	/* Configure PIO controllers to periph mode */
	AT91F_PIO_CfgPeripheral(
		pPIOB, /* PIO controller base address */
		((U32) AT91C_PB19_PWM0    ), /* Peripheral A */
		((U32) AT91C_PB27_PWM0    )); /* Peripheral B */
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PWMC_CfgPMC( AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  PWMC
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PWMC_CfgPMC(AT91PS_PMC pPMC)
{
	AT91F_PMC_EnablePeripheralClock(
		pPMC, /* PIO controller base address */
		((U32) 1 << AT91C_ID_PWMC));
}



/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_PWMC AT91F_PWMC_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base PWMC peripheral controller address
 * \param u8Controller PWMC controller index
 * \return pointer to PWMC controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_PWMC AT91F_PWMC_GetPeripheralAddress( U8 u8Controller )
{
	return AT91C_BASE_PWMC;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PWMC_SetModeRegister(AT91PS_PWMC pPWM, U8 u8DivA, U8 u8DivB,  U8 u8PreA, U8 u8PreB) 
 * \brief Sets PWM Mode register
 * \param pPWM pointer to PWM controller
 * \param u8DivA divider a
 * \param u8DivB divider b
 * \param u8PreA prescaler a
 * \param u8PreB prescaler b
 * \return none
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PWMC_SetModeRegister( 
		AT91PS_PWMC pPWM, /* \arg  pointer to a PWM controller */
		U8 u8DivA, /* \arg  div A */
		U8 u8DivB, /* \arg  div B */
		U8 u8PreA, /* \arg  pre A */
		U8 u8PreB) /* \arg  pre B */
{
	/* Set PWM Mode Register */
	pPWM->PWMC_MR = (U32)( 	u8DivA | 
							((u8PreA & 0x0F)<<8) | 
							(u8DivB <<16) | 
							((u8PreB & 0x0F)<<24) );
	
}

