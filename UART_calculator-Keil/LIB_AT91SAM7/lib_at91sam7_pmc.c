#include "basedef.h"
#include "ioat91sam7x256.h"
#include "lib_AT91SAM7_PMC.h"
#include "lib_AT91SAM7_PIO.h"


/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PMC_CfgSysClkEnableRegister(	AT91PS_PMC pPMC, \
 * 											U32 mode)
 * \brief Configure the System Clock Enable Register of the PMC controller
 * \param pPMC pointer to PMC controller
 * \param mode enable mode value
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PMC_CfgSysClkEnableRegister(
	AT91PS_PMC pPMC, /* \arg pointer to PMC controller */
	U32 mode)
{
	/** Write to the SCER register */
	pPMC->PMC_SCER = mode;
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PMC_CfgSysClkDisableRegister(	AT91PS_PMC pPMC, \
 * 											U32 mode)
 * \brief Configure the System Clock Disable Register of the PMC controller
 * \param pPMC pointer to PMC controller
 * \param mode disable mode value
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PMC_CfgSysClkDisableRegister(
	AT91PS_PMC pPMC, /* \arg pointer to PMC controller */
	U32 mode)
{
	/** Write to the SCDR register */
	pPMC->PMC_SCDR = mode;
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PMC_GetSysClkStatusRegister(	AT91PS_PMC pPMC )
 * \brief Return the System Clock Status Register of the PMC controller
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PMC_GetSysClkStatusRegister(
	AT91PS_PMC pPMC /* pointer to a CAN controller */
	)
{
	return pPMC->PMC_SCSR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PMC_EnablePeripheralClock(	AT91PS_PMC pPMC, \
 * 										U32 periphIds)
 * \brief Enable peripheral clock
 * \param pPMC pointer to PMC controller
 * \param periphIds IDs of peripherals
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PMC_EnablePeripheralClock(
	AT91PS_PMC pPMC, /* \arg pointer to PMC controller */
	U32 periphIds)  /* \arg IDs of peripherals */
{
	pPMC->PMC_PCER = periphIds;
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PMC_DisablePeripheralClock(	AT91PS_PMC pPMC, \
 * 											U32 periphIds)
 * \brief Disable peripheral clock
 * \param pPMC pointer to PMC controller
 * \param periphIds IDs of peripherals
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PMC_DisablePeripheralClock(
	AT91PS_PMC pPMC, /* \arg pointer to PMC controller */
	U32 periphIds)  /* \arg IDs of peripherals */
{
	pPMC->PMC_PCDR = periphIds;
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PMC_GetPeripheralClock(	AT91PS_PMC pPMC )
 * \brief Get peripheral clock status
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PMC_GetPeripheralClock(
	AT91PS_PMC pPMC) /* \arg pointer to PMC controller */
{
	return pPMC->PMC_PCSR;
}




/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_CKGR_CfgMainOscillatorRegister( AT91PS_CKGR pCKGR, \
 * 											U32 mode)
 * \brief Cfg the main oscillator
 * \param pCKGR pointer to CKGR controller
 * \param mode mode
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_CKGR_CfgMainOscillatorRegister(
	AT91PS_CKGR pCKGR, /* \arg pointer to CKGR controller */
	U32 mode)
{
	pCKGR->CKGR_MOR = mode;
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_CKGR_GetMainOscillatorRegister( AT91PS_CKGR pCKGR )
 * \brief Return the main oscillator
 * \param pCKGR pointer to CKGR controller
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CKGR_GetMainOscillatorRegister(
	AT91PS_CKGR pCKGR) /* \arg pointer to CKGR controller */
{
	return pCKGR->CKGR_MOR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_CKGR_EnableMainOscillator( AT91PS_CKGR pCKGR )
 * \brief Enable the main oscillator
 * \param pCKGR pointer to CKGR controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_CKGR_EnableMainOscillator(
	AT91PS_CKGR pCKGR) /* \arg pointer to CKGR controller */
{
	pCKGR->CKGR_MOR |= AT91C_CKGR_MOSCEN;
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_CKGR_DisableMainOscillator( AT91PS_CKGR pCKGR )
 * \brief Disable the main oscillator
 * \param pCKGR pointer to CKGR controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_CKGR_DisableMainOscillator(
	AT91PS_CKGR pCKGR) /* \arg pointer to CKGR controller */
{
	pCKGR->CKGR_MOR &= ~AT91C_CKGR_MOSCEN;
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_CKGR_CfgMainOscStartUpTime(	AT91PS_CKGR pCKGR, \
 * 												U32 startup_time, \
 * 												U32 slowClock)
 * \brief Cfg MOR Register according to the main osc startup time
 * \param pCKGR pointer to CKGR controller
 * \param startup_time main osc startup time in microsecond (us)
 * \param slowClock slowClock in Hz
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_CKGR_CfgMainOscStartUpTime(
	AT91PS_CKGR pCKGR, /* \arg pointer to CKGR controller */
	U32 startup_time,  /* \arg main osc startup time in microsecond (us) */
	U32 slowClock)  /* \arg slowClock in Hz */
{
	pCKGR->CKGR_MOR &= ~AT91C_CKGR_OSCOUNT;
	pCKGR->CKGR_MOR |= ((slowClock * startup_time)/(8*1000000)) << 8;
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_CKGR_GetMainClockFreqRegister( AT91PS_CKGR pCKGR )
 * \brief Cfg the main oscillator
 * \param pCKGR pointer to CKGR controller
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CKGR_GetMainClockFreqRegister(
	AT91PS_CKGR pCKGR) /* \arg pointer to CKGR controller */
{
	return pCKGR->CKGR_MCFR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_CKGR_GetMainClock( AT91PS_CKGR pCKGR, \
 * 									U32 slowClock)
 * \brief Return Main clock in Hz
 * \param pCKGR pointer to CKGR controller
 * \param slowClock slowClock in Hz
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CKGR_GetMainClock(
	AT91PS_CKGR pCKGR, /* \arg pointer to CKGR controller */
	U32 slowClock)  /* \arg slowClock in Hz */
{
	return ((pCKGR->CKGR_MCFR  & AT91C_CKGR_MAINF) * slowClock) >> 4;
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PMC_CfgMCKRegister( AT91PS_PMC pPMC, \
 * 								U32 mode)
 * \brief Cfg Master Clock Register
 * \param pPMC pointer to PMC controller
 * \param mode mode register
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PMC_CfgMCKRegister(
	AT91PS_PMC pPMC, /* \arg pointer to PMC controller */
	U32 mode)
{
	pPMC->PMC_MCKR = mode;
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PMC_GetMCKRegister(	AT91PS_PMC pPMC )
 * \brief Return Master Clock Register
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PMC_GetMCKRegister(
	AT91PS_PMC pPMC) /* \arg pointer to PMC controller */
{
	return pPMC->PMC_MCKR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PMC_GetMasterClock(	AT91PS_PMC pPMC, \
 * 										AT91PS_CKGR pCKGR, \
 * 										U32 slowClock)
 * \brief Return master clock in Hz which correponds to processor clock for ARM7
 * \param pPMC pointer to PMC controller
 * \param pCKGR pointer to CKGR controller
 * \param slowClock slowClock in Hz
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PMC_GetMasterClock(
	AT91PS_PMC pPMC, /* \arg pointer to PMC controller */
	AT91PS_CKGR pCKGR, /* \arg pointer to CKGR controller */
	U32 slowClock)  /* \arg slowClock in Hz */
{
	U32 reg = pPMC->PMC_MCKR;
	U32 prescaler = (1 << ((reg & AT91C_PMC_PRES) >> 2));
	U32 pllDivider, pllMultiplier;

	switch (reg & AT91C_PMC_CSS) {
		case AT91C_PMC_CSS_SLOW_CLK: /* Slow clock selected */
			return slowClock / prescaler;
		case AT91C_PMC_CSS_MAIN_CLK: /* Main clock is selected */
			return AT91F_CKGR_GetMainClock(pCKGR, slowClock) / prescaler;
		case AT91C_PMC_CSS_PLL_CLK: /* PLLB clock is selected */
			reg = pCKGR->CKGR_PLLR;
			pllDivider    = (reg  & AT91C_CKGR_DIV);
			pllMultiplier = ((reg  & AT91C_CKGR_MUL) >> 16) + 1;
			return AT91F_CKGR_GetMainClock(pCKGR, slowClock) / pllDivider * pllMultiplier / prescaler;
	}
	return 0;
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PMC_EnablePCK(	AT91PS_PMC pPMC, \
 * 								U32 pck, \
 * 								U32 mode)
 * \brief Enable Programmable Clock x Output
 * \param pPMC pointer to PMC controller
 * \param pck Programmable Clock x Output
 * \param mode mode
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PMC_EnablePCK(
	AT91PS_PMC pPMC, /* \arg pointer to PMC controller */
	U32 pck,  /* \arg Programmable Clock x Output */
	U32 mode)
{
	pPMC->PMC_PCKR[pck] = mode;
	pPMC->PMC_SCER = (1 << pck) << 8;
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PMC_DisablePCK(	AT91PS_PMC pPMC, \
 *	 								U32 pck)
 * \brief Disable Programmable Clock x Output
 * \param pPMC pointer to PMC controller
 * \param pck Programmable Clock x Output
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PMC_DisablePCK(
	AT91PS_PMC pPMC, /* \arg pointer to PMC controller */
	U32 pck)  /* \arg Programmable Clock x Output */
{
	pPMC->PMC_SCDR = (1 << pck) << 8;
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PMC_EnableInterrupt(	AT91PS_PMC pPMC, \
 *	 									U32 flag)
 * \brief Enable PMC interrupt
 * \param pPMC pointer to PMC controller
 * \param flag interrupt to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PMC_EnableInterrupt(
	AT91PS_PMC pPMC,     /* pointer to a PMC controller */
	U32 flag)   /* interrupt to be enabled */
{
	/** Write to the IER register */
	pPMC->PMC_IER = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PMC_DisableInterrupt(	AT91PS_PMC pPMC, \
 *	 									U32 flag)
 * \brief Disable PMC interrupt
 * \param pPMC pointer to PMC controller
 * \param flag interrupt to be disabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PMC_DisableInterrupt(
	AT91PS_PMC pPMC, /* pointer to a PMC controller */
	U32 flag) /* interrupt to be disabled */
{
	/** Write to the IDR register */
	pPMC->PMC_IDR = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PMC_GetStatus(	AT91PS_PMC pPMC )
 * \brief Return PMC Interrupt Status
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PMC_GetStatus( /* \return PMC Interrupt Status */
	AT91PS_PMC pPMC) /* pointer to a PMC controller */
{
	return pPMC->PMC_SR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PMC_GetInterruptMaskStatus(	AT91PS_PMC pPMC )
 * \brief Return PMC Interrupt Mask Status
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PMC_GetInterruptMaskStatus( /* \return PMC Interrupt Mask Status */
	AT91PS_PMC pPMC) /* pointer to a PMC controller */
{
	return pPMC->PMC_IMR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PMC_IsInterruptMasked(	AT91PS_PMC pPMC, \
 *	 									U32 flag)
 * \brief Test if PMC Interrupt is Masked
 * \param pPMC pointer to PMC controller
 * \param flag flag to be tested
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PMC_IsInterruptMasked(
        AT91PS_PMC pPMC,   /* \arg  pointer to a PMC controller */
        U32 flag) /* \arg  flag to be tested */
{
	return (AT91F_PMC_GetInterruptMaskStatus(pPMC) & flag);
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PMC_IsStatusSet(	AT91PS_PMC pPMC, \
 *	 									U32 flag)
 * \brief Test if PMC Status is Set
 * \param pPMC pointer to PMC controller
 * \param flag flag to be tested
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PMC_IsStatusSet(
        AT91PS_PMC pPMC,   /* \arg  pointer to a PMC controller */
        U32 flag) /* \arg  flag to be tested */
{
	return (AT91F_PMC_GetStatus(pPMC) & flag);
}

/*----------------------------------------------------------------------------*/
/*!  \fn    AT91F_CKGR_CfgPLLRegister(	AT91PS_CKGR pCKGR, \
 *	 								U32 mode)
 *  \brief Cfg the PLL Register
 * \param pCKGR pointer to CKGR controller
 * \param mode mode
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_CKGR_CfgPLLRegister(
	AT91PS_CKGR pCKGR, /* \arg pointer to CKGR controller */
	U32 mode)
{
	pCKGR->CKGR_PLLR = mode;
}

/*----------------------------------------------------------------------------*/
/*!  \fn    AT91F_CKGR_GetPLLRegister(	AT91PS_CKGR pCKGR )
 *  \brief Get the PLL Register
 * \param pCKGR pointer to CKGR controller
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_CKGR_GetPLLRegister(
	AT91PS_CKGR pCKGR) /* \arg pointer to CKGR controller */
{
	return pCKGR->CKGR_PLLR;
}



/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PMC_CfgPMC( AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  PMC
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PMC_CfgPMC( AT91PS_PMC pPMC )
{
	AT91F_PMC_EnablePeripheralClock(
		pPMC, /* PIO controller base address */
		((U32) 1 << AT91C_ID_SYS));
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_PMC_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
 * \brief Configure PIO controllers to drive PMC signals
 * \param pPIOA pointer to PIOA controller
 * \param pPIOB pointer to PIOB controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PMC_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
{
	/* Configure PIO controllers to periph mode */
	AT91F_PIO_CfgPeripheral(
		pPIOA, /* PIO controller base address */
		0, /* Peripheral A */
		((U32) AT91C_PA13_PCK1    ) |
		((U32) AT91C_PA30_PCK2    ) |
		((U32) AT91C_PA27_PCK3    )); /* Peripheral B */
	/* Configure PIO controllers to periph mode */
	AT91F_PIO_CfgPeripheral(
		pPIOB, /* PIO controller base address */
		((U32) AT91C_PB29_PCK1    ) |
		((U32) AT91C_PB30_PCK2    ), /* Peripheral A */
		((U32) AT91C_PB21_PCK1    ) |
		((U32) AT91C_PB22_PCK2    ) |
		((U32) AT91C_PB20_PCK0    ) |
		((U32) AT91C_PB0_PCK0    )); /* Peripheral B */
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_PMC AT91F_PMC_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base PMC peripheral controller address
 * \param u8Controller PMC controller index
 * \return pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_PMC AT91F_PMC_GetPeripheralAddress( U8 u8Controller )
{
	return AT91C_BASE_PMC;
}
