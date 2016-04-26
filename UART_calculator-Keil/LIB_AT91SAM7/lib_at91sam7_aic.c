#include "basedef.h"
#include "ioat91sam7x256.h"
#include "lib_AT91SAM7_PMC.h"
#include "lib_AT91SAM7_PIO.h"
#include "lib_AT91SAM7_AIC.h"


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_AIC_ConfigureInterrupt(	AT91PS_AIC pAic, \
 * 									U32 irq_id, \
 * 									U32 priority, \
 * 									U32 src_type, \
 * 									void (*newHandler)() )
 * \brief Interrupt Handler Initialization
 * \param pAic pointer to AIC structure
 * \param irq_id interrupt number ( valid range 0 - 63 )
 * \param priority priority level ( valid range 0 - 7 )
 * \param src_type interrupt trigger type ( valid range )
 * \param newHandler interrupt function handler
 * \return old handler
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_AIC_ConfigureInterrupt(
	AT91PS_AIC pAic,  /* \arg pointer to the AIC registers */
	U32 irq_id,     /* \arg interrupt number to initialize */
	U32 priority,   /* \arg priority to give to the interrupt */
	U32 src_type,   /* \arg activation and sense of activation */
	void (*newHandler)() ) /* \arg address of the interrupt handler */
{
	U32 oldHandler;
    U32 mask ;

    oldHandler = pAic->AIC_SVR[irq_id];

    mask = 0x1 << irq_id ;
    /** Disable the interrupt on the interrupt controller */
    pAic->AIC_IDCR = mask ;
    /** Save the interrupt handler routine pointer and the interrupt priority */
    pAic->AIC_SVR[irq_id] = (U32) newHandler ;
    /** Store the Source Mode Register */
    pAic->AIC_SMR[irq_id] = src_type | priority  ;
    /** Clear the interrupt on the interrupt controller */
    pAic->AIC_ICCR = mask ;

	return oldHandler;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_AIC_EnableInterrupt(	AT91PS_AIC pAic, \
 * 								U32 irq_id )
 * \brief Enable corresponding interrupt number
 * \param pAic pointer to AIC structure
 * \param irq_id interrupt number ( valid range 0 - 63 )
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_AIC_EnableInterrupt(
	AT91PS_AIC pAic,      /* \arg pointer to the AIC registers */
	U32 irq_id ) /* \arg interrupt number to initialize */
{
    /** Enable the interrupt on the interrupt controller */
    pAic->AIC_IECR = 0x1 << irq_id ;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_AIC_DisableInterrupt(	AT91PS_AIC pAic, \
 * 										U32 irq_id )
 * \brief Disable corresponding interrupt number
 * \param pAic pointer to AIC structure
 * \param irq_id interrupt number ( valid range 0 - 63 )
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_AIC_DisableInterrupt(
	AT91PS_AIC pAic, 
	U32 irq_id ) 
{
    U32 mask = 0x1 << irq_id;
    /** Disable the interrupt on the interrupt controller */
    pAic->AIC_IDCR = mask ;
    /** Clear the interrupt on the Interrupt Controller ( if one is pending ) */
    pAic->AIC_ICCR = mask ;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_AIC_ClearInterrupt(	AT91PS_AIC pAic, \
 * 								U32 irq_id )
 * \brief Clear corresponding interrupt number
 * \param pAic pointer to AIC structure
 * \param irq_id interrupt number ( valid range 0 - 63 )
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_AIC_ClearInterrupt(
	AT91PS_AIC pAic,     /* \arg pointer to the AIC registers */
	U32 irq_id) /* \arg interrupt number to initialize */
{
    /** Clear the interrupt on the Interrupt Controller ( if one is pending ) */
    pAic->AIC_ICCR = (0x1 << irq_id);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_AIC_AcknowledgeInterrupt(	AT91PS_AIC pAic )
 * \brief Acknowledge corresponding interrupt number
 * \param pAic pointer to AIC structure
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_AIC_AcknowledgeInterrupt(
	AT91PS_AIC pAic)     /* \arg pointer to the AIC registers */
{
    pAic->AIC_EOICR = pAic->AIC_EOICR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_AIC_SetExceptionVector(	U32 *pVector, \
 * 											void (*Handler)() )
 * \brief Configure vector handler
 * \param pVector pointer to the AIC registers
 * \param Handler Interrupt Handler
 * \return old handler
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_AIC_SetExceptionVector(
	U32 *pVector, /* \arg pointer to the AIC registers */
	void (*Handler)() )   /* \arg Interrupt Handler */
{
	U32 oldVector = *pVector;

	if ((U32) Handler == (U32) AT91C_AIC_BRANCH_OPCODE)
		*pVector = (U32) AT91C_AIC_BRANCH_OPCODE;
	else
		*pVector = (((((U32) Handler) - ((U32) pVector) - 0x8) >> 2) & 0x00FFFFFF) | 0xEA000000;

	return oldVector;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_AIC_Trigger(	AT91PS_AIC pAic, \
 * 							U32 irq_id )
 * \brief Trigger an interrupt
 * \param pAic pointer to AIC structure
 * \param irq_id interrupt number ( valid range 0 - 63 )
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_AIC_Trigger(
	AT91PS_AIC pAic,     /* \arg pointer to the AIC registers */
	U32 irq_id) /* \arg interrupt number */
{
	pAic->AIC_ISCR = (0x1 << irq_id) ;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_AIC_IsActive(	AT91PS_AIC pAic, \
 * 								U32 irq_id )
 * \brief Test if an IRQ is active
 * \param pAic pointer to AIC structure
 * \param irq_id IRQ number ( valid range 0 - 63 )
 * \return masked interrupt status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_AIC_IsActive(
	AT91PS_AIC pAic,     /* \arg pointer to the AIC registers */
	U32 irq_id) /* \arg Interrupt Number */
{
	return (pAic->AIC_ISR & (0x1 << irq_id));
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_AIC_IsPending(	AT91PS_AIC pAic, \
 * 								U32 irq_id )
 * \brief Test if an interrupt is pending
 * \param pAic pointer to AIC structure
 * \param irq_id interrupt number ( valid range 0 - 63 )
 * \return masked interrupt pending register value
 */
/*----------------------------------------------------------------------------*/
__inline U32  AT91F_AIC_IsPending(
	AT91PS_AIC pAic,     /* \arg pointer to the AIC registers */
	U32 irq_id) /* \arg Interrupt Number */
{
	return (pAic->AIC_IPR & (0x1 << irq_id));
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_AIC_Open(	AT91PS_AIC pAic, \
 * 							void (*IrqHandler)(), \
 * 							void (*FiqHandler)(), \
 * 							void (*DefaultHandler)(), \
 * 							void (*SpuriousHandler)(), \
 * 							U32 protectMode)
 * \brief Set exception vectors and AIC registers to default values
 * \param pAic pointer to AIC structure
 * \param IrqHandler Default IRQ vector exception
 * \param FiqHandler Default FIQ vector exception
 * \param DefaultHandler Default Handler set in ISR
 * \param SpuriousHandler Default Spurious Handler
 * \param protectMode Debug Control Register
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_AIC_Open(
	AT91PS_AIC pAic,        /* \arg pointer to the AIC registers */
	void (*IrqHandler)(),  /* \arg Default IRQ vector exception */
	void (*FiqHandler)(),  /* \arg Default FIQ vector exception */
	void (*DefaultHandler)(), /* \arg Default Handler set in ISR */
	void (*SpuriousHandler)(), /* \arg Default Spurious Handler */
	U32 protectMode)   /* \arg Debug Control Register */
{
	int i;

	/* Disable all interrupts and set IVR to the default handler */
	for (i = 0; i < 32; ++i) {
		AT91F_AIC_DisableInterrupt(pAic, i);
		AT91F_AIC_ConfigureInterrupt(pAic, i, AT91C_AIC_PRIOR_LOWEST, AT91C_AIC_SRCTYPE_HIGH_LEVEL, DefaultHandler);
	}

	/* Set the IRQ exception vector */
	AT91F_AIC_SetExceptionVector((U32 *) 0x18, IrqHandler);
	/* Set the Fast Interrupt exception vector */
	AT91F_AIC_SetExceptionVector((U32 *) 0x1C, FiqHandler);

	pAic->AIC_SPU = (U32) SpuriousHandler;
	pAic->AIC_DCR = protectMode;
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_AIC_CfgPMC( AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  AIC
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_AIC_CfgPMC( AT91PS_PMC pPMC )
{
	AT91F_PMC_EnablePeripheralClock(
		pPMC, /* PIO controller base address */
		((U32) 1 << AT91C_ID_IRQ0) |
		((U32) 1 << AT91C_ID_FIQ) |
		((U32) 1 << AT91C_ID_IRQ1));
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_AIC_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB ) 
 * \brief Configure PIO controllers to drive AIC signals
 * \param pPIOA pointer to PIOA controller
 * \param pPIOB pointer to PIOB controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_AIC_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
{
	/* Configure PIO controllers to periph mode */
	AT91F_PIO_CfgPeripheral(
		pPIOA, /* PIO controller base address */
		((U32) AT91C_PA30_IRQ0    ) |
		((U32) AT91C_PA29_FIQ     ), /* Peripheral A */
		((U32) AT91C_PA14_IRQ1    )); /* Peripheral B */
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_AIC AT91F_AIC_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base AIC peripheral controller address
 * \param u8Controller AIC controller index
 * \return pointer to AIC controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_AIC AT91F_AIC_GetPeripheralAddress( U8 u8Controller )
{
	return AT91C_BASE_AIC;
}
