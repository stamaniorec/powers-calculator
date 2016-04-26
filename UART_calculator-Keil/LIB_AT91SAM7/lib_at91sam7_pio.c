#include "basedef.h"
#include "ioat91sam7x256.h"
#include "lib_AT91SAM7_PMC.h"
#include "lib_AT91SAM7_PIO.h"

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_CfgPeripheral(	AT91PS_PIO pPIO, \
 * 									U32 periphAEnable, \
 * 									U32 periphBEnable)
 * \brief Enable pins to be drived by peripheral
 * \param pPIO pointer to a PIO controller
 * \param periphAEnable PERIPH A to enable
 * \param periphBEnable PERIPH B to enable
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_CfgPeripheral(
	AT91PS_PIO pPIO,             /* \arg pointer to a PIO controller */
	U32 periphAEnable,  /* \arg PERIPH A to enable */
	U32 periphBEnable)  /* \arg PERIPH B to enable */
{
	pPIO->PIO_ASR = periphAEnable;
	pPIO->PIO_BSR = periphBEnable;
	pPIO->PIO_PDR = (periphAEnable | periphBEnable); /* Set in Periph mode */
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_CfgOutput(	AT91PS_PIO pPio, \
 * 								U32 pioEnable)
 * \brief Enable PIO in output mode
 * \param pPio pointer to a PIO controller
 * \param pioEnable PIO to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_CfgOutput(
	AT91PS_PIO pPio,             /* \arg pointer to a PIO controller */
	U32 pioEnable)      /* \arg PIO to be enabled */
{
	pPio->PIO_PER = pioEnable; /* Set in PIO mode */
	pPio->PIO_OER = pioEnable; /* Configure in Output */
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_CfgInput(	AT91PS_PIO pPio, \
 * 								U32 pioEnable)
 * \brief Enable PIO in input mode
 * \param pPio pointer to a PIO controller
 * \param pioEnable PIO to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_CfgInput(
	AT91PS_PIO pPio,             /* \arg pointer to a PIO controller */
	U32 inputEnable)      /* \arg PIO to be enabled */
{
	/* Disable output */
	pPio->PIO_ODR  = inputEnable;
	//pPio->PIO_PER  = inputEnable;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_CfgOpenDrain(	AT91PS_PIO pPio, \
 * 									U32 multiDrvEnable)
 * \brief Configure PIO in open drain
 * \param pPio pointer to a PIO controller
 * \param multiDrvEnable PIO to be configured in open drain
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_CfgOpenDrain(
	AT91PS_PIO pPio,             /* \arg pointer to a PIO controller */
	U32 multiDrvEnable) /* \arg pio to be configured in open drain */
{
	/* Configure the multi-drive option */
	pPio->PIO_MDDR = ~multiDrvEnable;
	pPio->PIO_MDER = multiDrvEnable;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_CfgPullup(	AT91PS_PIO pPio, \
 * 								U32 pullupEnable)
 * \brief Enable pullup on PIO
 * \param pPio pointer to a PIO controller
 * \param pullupEnable enable pullup on PIO
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_CfgPullup(
	AT91PS_PIO pPio,             /* \arg pointer to a PIO controller */
	U32 pullupEnable)   /* \arg enable pullup on PIO */
{
		/* Connect or not Pullup */
	pPio->PIO_PPUDR = ~pullupEnable;
	pPio->PIO_PPUER = pullupEnable;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_DisablePullup(	AT91PS_PIO pPio, \
 * 								U32 pullupDisable)
 * \brief Enable pullup on PIO
 * \param pPio pointer to a PIO controller
 * \param pullupDisable disable pullup on PIO
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_DisablePullup(
	AT91PS_PIO pPio,             /* \arg pointer to a PIO controller */
	U32 pullupDisable)   /* \arg enable pullup on PIO */
{
		/* Connect or not Pullup */
	pPio->PIO_PPUDR = pullupDisable;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_CfgDirectDrive(	AT91PS_PIO pPio, \
 * 										U32 directDrive)
 * \brief Enable direct drive on PIO
 * \param pPio pointer to a PIO controller
 * \param directDrive PIO to be configured with direct drive
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_CfgDirectDrive(
	AT91PS_PIO pPio,             /* \arg pointer to a PIO controller */
	U32 directDrive)    /* \arg PIO to be configured with direct drive */

{
	/* Configure the Direct Drive */
	pPio->PIO_OWDR  = ~directDrive;
	pPio->PIO_OWER  = directDrive;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_CfgInputFilter(	AT91PS_PIO pPio, \
 * 										U32 inputFilter)
 * \brief Enable input filter on input PIO
 * \param pPio pointer to a PIO controller
 * \param inputFilter PIO to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_CfgInputFilter(
	AT91PS_PIO pPio,             /* \arg pointer to a PIO controller */
	U32 inputFilter)    /* \arg PIO to be configured with input filter */

{
	/* Configure the Direct Drive */
	pPio->PIO_IFDR  = ~inputFilter;
	pPio->PIO_IFER  = inputFilter;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_GetInput(	AT91PS_PIO pPio )
 * \brief Return PIO input value
 * \param pPio pointer to a PIO controller
 * \return port data status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_GetInput( /* \return PIO input */
	AT91PS_PIO pPio) /* \arg  pointer to a PIO controller */
{
	return pPio->PIO_PDSR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_IsInputSet(	AT91PS_PIO pPio, \
 * 									U32 flag)
 * \brief Test if PIO is input flag is active
 * \param pPio pointer to a PIO controller
 * \param flag flag to be tested
 * \return masked port data status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_IsInputSet(
	AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
	U32 flag) /* \arg  flag to be tested */
{
	return (AT91F_PIO_GetInput(pPio) & flag);
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_SetOutput(	AT91PS_PIO pPio, \
 * 								U32 flag)
 * \brief Set to 1 output PIO
 * \param pPio pointer to a PIO controller
 * \param flag output to be set
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_SetOutput(
	AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
	U32 flag) /* \arg  output to be set */
{
	pPio->PIO_SODR = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_ClearOutput(	AT91PS_PIO pPio, \
 * 									U32 flag)
 * \brief Set to 0 output PIO
 * \param pPio pointer to a PIO controller
 * \param flag output to be cleared
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_ClearOutput(
	AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
	U32 flag) /* \arg  output to be cleared */
{
	pPio->PIO_CODR = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_ForceOutput(	AT91PS_PIO pPio, \
 * 									U32 flag)
 * \brief Force output when Direct drive option is enabled
 * \param pPio pointer to a PIO controller
 * \param flag output to be forced
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_ForceOutput(
	AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
	U32 flag) /* \arg  output to be forced */
{
	pPio->PIO_ODSR = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_Enable(	AT91PS_PIO pPio, \
 * 								U32 flag)
 * \brief Enable PIO
 * \param pPio pointer to a PIO controller
 * \param flag pio to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_Enable(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag) /* \arg  pio to be enabled */
{
        pPio->PIO_PER = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_Disable(	AT91PS_PIO pPio, \
 * 								U32 flag)
 * \brief Disable PIO
 * \param pPio pointer to a PIO controller
 * \param flag pio to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_Disable(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag) /* \arg  pio to be disabled */
{
        pPio->PIO_PDR = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_GetStatus(	AT91PS_PIO pPio )
 * \brief Return PIO Status
 * \param pPio pointer to a PIO controller
 * \return PIO status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_GetStatus( /* \return PIO Status */
        AT91PS_PIO pPio) /* \arg  pointer to a PIO controller */
{
        return pPio->PIO_PSR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_IsSet(	AT91PS_PIO pPio, \
 * 							U32 flag)
 * \brief Test if PIO is Set
 * \param pPio pointer to a PIO controller
 * \param flag flag to be tested
 * \return masked PIO status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_IsSet(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag) /* \arg  flag to be tested */
{
        return (AT91F_PIO_GetStatus(pPio) & flag);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_OutputEnable(	AT91PS_PIO pPio, \
 * 									U32 flag)
 * \brief Output Enable PIO
 * \param pPio pointer to a PIO controller
 * \param flag pio output to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_OutputEnable(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag) /* \arg  pio output to be enabled */
{
        pPio->PIO_OER = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_OutputDisable(	AT91PS_PIO pPio, \
 * 									U32 flag)
 * \brief Output Enable PIO
 * \param pPio pointer to a PIO controller
 * \param flag pio output to be disabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_OutputDisable(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag) /* \arg  pio output to be disabled */
{
        pPio->PIO_ODR = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_GetOutputStatus(	AT91PS_PIO pPio )
 * \brief Return PIO Output Status
 * \param pPio pointer to a PIO controller
 * \return port output status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_GetOutputStatus( /* \return PIO Output Status */
        AT91PS_PIO pPio) /* \arg  pointer to a PIO controller */
{
        return pPio->PIO_OSR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_IsOutputSet(	AT91PS_PIO pPio, \
 * 									U32 flag)
 * \brief Test if PIO Output is Set
 * \param pPio pointer to a PIO controller
 * \param flag flag to be tested
 * \return masked port output status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_IsOutputSet(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag) /* \arg  flag to be tested */
{
        return (AT91F_PIO_GetOutputStatus(pPio) & flag);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_InputFilterEnable(	AT91PS_PIO pPio, \
 * 										U32 flag)
 * \brief Input Filter Enable PIO
 * \param pPio pointer to a PIO controller
 * \param flag pio input filter to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_InputFilterEnable(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag) /* \arg  pio input filter to be enabled */
{
        pPio->PIO_IFER = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_InputFilterDisable(	AT91PS_PIO pPio, \
 * 											U32 flag)
 * \brief Input Filter Disable PIO
 * \param pPio pointer to a PIO controller
 * \param flag pio input filter to be disabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_InputFilterDisable(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag) /* \arg  pio input filter to be disabled */
{
        pPio->PIO_IFDR = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_GetInputFilterStatus(	AT91PS_PIO pPio )
 * \brief Return PIO Input Filter Status
 * \param pPio pointer to a PIO controller
 * \return port input filter status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_GetInputFilterStatus( /* \return PIO Input Filter Status */
        AT91PS_PIO pPio) /* \arg  pointer to a PIO controller */
{
        return pPio->PIO_IFSR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_IsInputFilterSet(	AT91PS_PIO pPio, \
 * 										U32 flag)
 * \brief Test if PIO Input filter is Set
 * \param pPio pointer to a PIO controller
 * \param flag flag to be tested
 * \return masked port input filter status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_IsInputFilterSet(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag) /* \arg  flag to be tested */
{
        return (AT91F_PIO_GetInputFilterStatus(pPio) & flag);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_GetOutputDataStatus(	AT91PS_PIO pPio )
 * \brief Return PIO Output Data Status
 * \param pPio pointer to a PIO controller
 * \return port outpur data status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_GetOutputDataStatus( /* \return PIO Output Data Status */
	AT91PS_PIO pPio) /* \arg  pointer to a PIO controller */
{
        return pPio->PIO_ODSR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_InterruptEnable(	AT91PS_PIO pPio, \
 * 										U32 flag)
 * \brief Enable PIO Interrupt
 * \param pPio pointer to a PIO controller
 * \param flag pio interrupt to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_InterruptEnable(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag) /* \arg  pio interrupt to be enabled */
{
        pPio->PIO_IER = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_InterruptDisable(	AT91PS_PIO pPio, \
 * 										U32 flag)
 * \brief Disable PIO Interrupt
 * \param pPio pointer to a PIO controller
 * \param flag pio interrupt to be disabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_InterruptDisable(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag) /* \arg  pio interrupt to be disabled */
{
        pPio->PIO_IDR = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_GetInterruptMaskStatus(	AT91PS_PIO pPio )
 * \brief Return PIO Interrupt Mask Status
 * \param pPio pointer to a PIO controller
 * \return interrput mask register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_GetInterruptMaskStatus( /* \return PIO Interrupt Mask Status */
        AT91PS_PIO pPio) /* \arg  pointer to a PIO controller */
{
        return pPio->PIO_IMR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_GetInterruptStatus(	AT91PS_PIO pPio )
 * \brief Return PIO Interrupt Status
 * \param pPio pointer to a PIO controller
 * \return interrupt status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_GetInterruptStatus( /* \return PIO Interrupt Status */
        AT91PS_PIO pPio) /* \arg  pointer to a PIO controller */
{
        return pPio->PIO_ISR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_IsInterruptMasked(	AT91PS_PIO pPio, \
 * 										U32 flag)
 * \brief Test if PIO Interrupt is Masked
 * \param pPio pointer to a PIO controller
 * \param flag flag to be tested
 * \return masked interrupt mask register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_IsInterruptMasked(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag) /* \arg  flag to be tested */
{
        return (AT91F_PIO_GetInterruptMaskStatus(pPio) & flag);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_IsInterruptSet(	AT91PS_PIO pPio, \
 * 										U32 flag)
 * \brief Test if PIO Interrupt is Set
 * \param pPio pointer to a PIO controller
 * \param flag flag to be tested
 * \return masked interrupt status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_IsInterruptSet(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag) /* \arg  flag to be tested */
{
        return (AT91F_PIO_GetInterruptStatus(pPio) & flag);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_MultiDriverEnable(	AT91PS_PIO pPio, \
 * 										U32 flag)
 * \brief Multi Driver Enable PIO
 * \param pPio pointer to a PIO controller
 * \param flag flag to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_MultiDriverEnable(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag) /* \arg  pio to be enabled */
{
        pPio->PIO_MDER = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_MultiDriverDisable(	AT91PS_PIO pPio, \
 * 											U32 flag)
 * \brief Multi Driver Disable PIO
 * \param pPio pointer to a PIO controller
 * \param flag flag to be disabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_MultiDriverDisable(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag) /* \arg  pio to be disabled */
{
        pPio->PIO_MDDR = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_GetMultiDriverStatus(	AT91PS_PIO pPio )
 * \brief Return PIO Multi Driver Status
 * \param pPio pointer to a PIO controller
 * \return multi-driver status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_GetMultiDriverStatus( /* \return PIO Multi Driver Status */
        AT91PS_PIO pPio) /* \arg  pointer to a PIO controller */
{
        return pPio->PIO_MDSR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_IsMultiDriverSet(	AT91PS_PIO pPio, \
 * 											U32 flag)
 * \brief Test if PIO MultiDriver is Set
 * \param pPio pointer to a PIO controller
 * \param flag flag to be tested
 * \return masked multi-driver status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_IsMultiDriverSet(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag) /* \arg  flag to be tested */
{
        return (AT91F_PIO_GetMultiDriverStatus(pPio) & flag);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_A_RegisterSelection(	AT91PS_PIO pPio, \
 * 											U32 flag)
 * \brief PIO A Register Selection
 * \param pPio pointer to a PIO controller
 * \param flag pio A register selection
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_A_RegisterSelection(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag) /* \arg  pio A register selection */
{
        pPio->PIO_ASR = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_B_RegisterSelection(	AT91PS_PIO pPio, \
 * 											U32 flag)
 * \brief PIO B Register Selection
 * \param pPio pointer to a PIO controller
 * \param flag pio B register selection
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_B_RegisterSelection(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag) /* \arg  pio B register selection */
{
        pPio->PIO_BSR = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_Get_AB_RegisterStatus(	AT91PS_PIO pPio )
 * \brief Return PIO AB register Status
 * \param pPio pointer to a PIO controller
 * \return AB peripheral select status register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_Get_AB_RegisterStatus( /* \return PIO AB Register Status */
        AT91PS_PIO pPio) /* \arg  pointer to a PIO controller */
{
        return pPio->PIO_ABSR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_IsAB_RegisterSet(	AT91PS_PIO pPio, \
 * 										U32 flag)
 * \brief Test if PIO AB Register is Set
 * \param pPio pointer to a PIO controller
 * \param flag flag to be tested
 * \return masked AB peripheral select status register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_IsAB_RegisterSet(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag) /* \arg  flag to be tested */
{
        return (AT91F_PIO_Get_AB_RegisterStatus(pPio) & flag);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_OutputWriteEnable(	AT91PS_PIO pPio, \
 * 										U32 flag)
 * \brief Output Write Enable PIO
 * \param pPio pointer to a PIO controller
 * \param flag pio output write to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_OutputWriteEnable(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag) /* \arg  pio output write to be enabled */
{
        pPio->PIO_OWER = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIO_OutputWriteDisable(	AT91PS_PIO pPio, \
 * 											U32 flag)
 * \brief Output Write Disable PIO
 * \param pPio pointer to a PIO controller
 * \param flag pio output write to be disabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIO_OutputWriteDisable(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag) /* \arg  pio output write to be disabled */
{
        pPio->PIO_OWDR = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_GetOutputWriteStatus(	AT91PS_PIO pPio )
 * \brief Return PIO Output Write Status
 * \param pPio pointer to a PIO controller
 * \return output write status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_GetOutputWriteStatus( /* \return PIO Output Write Status */
        AT91PS_PIO pPio) /* \arg  pointer to a PIO controller */
{
        return pPio->PIO_OWSR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_IsOutputWriteSet(	AT91PS_PIO pPio, \
 * 										U32 flag)
 * \brief Test if PIO OutputWrite is Set
 * \param pPio pointer to a PIO controller
 * \param flag flag to be tested
 * \return masked output write status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_IsOutputWriteSet(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag) /* \arg  flag to be tested */
{
        return (AT91F_PIO_GetOutputWriteStatus(pPio) & flag);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_GetCfgPullup(	AT91PS_PIO pPio )
 * \brief Return PIO Configuration Pullup
 * \param pPio pointer to a PIO controller
 * \return pull-up status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_GetCfgPullup( /* \return PIO Configuration Pullup */
        AT91PS_PIO pPio) /* \arg  pointer to a PIO controller */
{
        return pPio->PIO_PPUSR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_IsOutputDataStatusSet(	AT91PS_PIO pPio, \
 * 											U32 flag)
 * \brief Test if PIO Output Data Status is Set
 * \param pPio pointer to a PIO controller
 * \param flag flag to be tested
 * \return masked output data status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_IsOutputDataStatusSet(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag) /* \arg  flag to be tested */
{
        return (AT91F_PIO_GetOutputDataStatus(pPio) & flag);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PIO_IsCfgPullupStatusSet(	AT91PS_PIO pPio, \
 * 											U32 flag)
 * \brief Test if PIO Configuration Pullup Status is Set
 * \param pPio pointer to a PIO controller
 * \param flag flag to be tested
 * \return masked pull-up status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PIO_IsCfgPullupStatusSet(
        AT91PS_PIO pPio,   /* \arg  pointer to a PIO controller */
        U32 flag) /* \arg  flag to be tested */
{
        return (~AT91F_PIO_GetCfgPullup(pPio) & flag);
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIOA_CfgPMC( AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  PIOA
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIOA_CfgPMC( AT91PS_PMC pPMC )
{
	AT91F_PMC_EnablePeripheralClock(
		pPMC, /* PIO controller base address */
		((U32) 1 << AT91C_ID_PIOA));
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PIOB_CfgPMC( AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  PIOB
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PIOB_CfgPMC( AT91PS_PMC pPMC )
{
	AT91F_PMC_EnablePeripheralClock(
		pPMC, /* PIO controller base address */
		((U32) 1 << AT91C_ID_PIOB));
}



/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_PIO AT91F_PIO_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base PIO peripheral controller address
 * \param u8Controller PIO controller index
 * \return pointer to PIO controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_PIO AT91F_PIO_GetPeripheralAddress( U8 u8Controller )
{
	AT91PS_PIO pPIO;
	switch ( u8Controller ) {
	case 0:
		pPIO = AT91C_BASE_PIOA;
		break;
	case 1:
		pPIO = AT91C_BASE_PIOB;
		break;
	default:
		pPIO = NULL;
		break;
	}
	return pPIO;
}
