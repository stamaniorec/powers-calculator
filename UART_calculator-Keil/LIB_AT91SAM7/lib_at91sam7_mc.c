#include "basedef.h"
#include "ioat91sam7x256.h"
#include "lib_AT91SAM7_PMC.h"
#include "lib_AT91SAM7_PIO.h"
#include "lib_AT91SAM7_MC.h"


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_MC_Remap( AT91PS_MC pMC )
 * \brief Make Remap
 * \param pMC pointer to MC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_MC_Remap( AT91PS_MC pMC )
{
    pMC->MC_RCR = AT91C_MC_RCB;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_MC_EFC_ConfigureModeRegister(	AT91PS_MC pMC, \
 * 									U32 mode)
 * \brief Configure the EFC Mode Register of the MC controller
 * \param pMC pointer to MC controller
 * \param mode mode register value
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_MC_EFC_ConfigureModeRegister(
	AT91PS_MC pMC, /* pointer to a MC controller */
	U32 mode)        /* mode register */
{
	/* Write to the FMR register */
	pMC->MC_FMR = mode;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_MC_EFC_GetModeReg(	AT91PS_MC pMC )
 * \brief Return MC EFC Mode Regsiter
 * \param pMC pointer to MC controller
 * \return flash mode register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_MC_EFC_GetModeReg(
	AT91PS_MC pMC) /* pointer to a MC controller */
{
	return pMC->MC_FMR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_MC_EFC_ComputeFMCN( U32 master_clock )
 * \brief Return MC EFC Mode Regsiter
 * \param master_clock master clock in Hz
 * \return master clock in MHz
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_MC_EFC_ComputeFMCN(
	U32 master_clock) /* master clock in Hz */
{
	return (master_clock/1000000 +2);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_MC_EFC_PerformCmd(	AT91PS_MC pMC, \
 * 									U32 transfer_cmd )
 * \brief Perform EFC Command
 * \param pMC pointer to MC controller
 * \param transfer_cmd transfer command
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_MC_EFC_PerformCmd (
	AT91PS_MC pMC, /* pointer to a MC controller */
    U32 transfer_cmd)
{
	pMC->MC_FCR = transfer_cmd;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_MC_EFC_GetStatus(	AT91PS_MC pMC )
 * \brief Return MC EFC Status
 * \param pMC pointer to MC controller
 * \return flash status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_MC_EFC_GetStatus(
	AT91PS_MC pMC) /* pointer to a MC controller */
{
	return pMC->MC_FSR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_MC_EFC_IsInterruptMasked(	AT91PS_MC pMC, \
 * 											U32 flag )
 * \brief Test if EFC MC Interrupt is Masked
 * \param pMC pointer to MC controller
 * \param flag flag to test
 * \return masked mode register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_MC_EFC_IsInterruptMasked(
        AT91PS_MC pMC,   /* \arg  pointer to a MC controller */
        U32 flag) /* \arg  flag to be tested */
{
	return (AT91F_MC_EFC_GetModeReg(pMC) & flag);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_MC_EFC_IsInterruptSet(	AT91PS_MC pMC, \
 * 										U32 flag )
 * \brief Test if EFC MC Interrupt is Set
 * \param pMC pointer to MC controller
 * \param flag flag to test
 * \return masked status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_MC_EFC_IsInterruptSet(
        AT91PS_MC pMC,   /* \arg  pointer to a MC controller */
        U32 flag) /* \arg  flag to be tested */
{
	return (AT91F_MC_EFC_GetStatus(pMC) & flag);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_MC_CfgPMC( AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  MC
 * \param pMC pointer to MC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_MC_CfgPMC( AT91PS_PMC pPMC )
{
	AT91F_PMC_EnablePeripheralClock(
		pPMC, /* PIO controller base address */
		((U32) 1 << AT91C_ID_SYS));
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_MC AT91F_MC_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base MC peripheral controller address
 * \param u8Controller MC controller index
 * \return pointer to MC controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_MC AT91F_MC_GetPeripheralAddress( U8 u8Controller )
{
	return AT91C_BASE_MC;
}

