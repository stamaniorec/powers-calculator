/* ----------------------------------------------------------------------------
            ATMEL Microcontroller Software Support  -  ROUSSET  -
    ----------------------------------------------------------------------------
    DISCLAIMER:  THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
    IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
    DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
    INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
    LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
    OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
    LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
    EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
    ----------------------------------------------------------------------------
    File Name           : lib_AT91SAM7.h
    Object              : AT91SAM7 inlined functions
    Generated           : AT91 SW Application Group  01/16/2006 (16:36:38)
   
    CVS Reference       : /lib_MC_SAM7X.h/1.1/Thu Mar 25 15:19:14 2004//
    CVS Reference       : /lib_pdc.h/1.2/Tue Jul  2 13:29:40 2002//
    CVS Reference       : /lib_des3_6150a.h/1.1/Mon Jan 17 09:19:19 2005//
    CVS Reference       : /lib_dbgu.h/1.1/Thu Aug 25 12:56:22 2005//
    CVS Reference       : /lib_aes_6149a.h/1.1/Mon Jan 17 07:43:09 2005//
    CVS Reference       : /lib_VREG_6085B.h/1.1/Tue Feb  1 16:20:47 2005//
    CVS Reference       : /lib_ssc.h/1.4/Fri Jan 31 12:19:20 2003//
    CVS Reference       : /lib_spi2.h/1.2/Tue Aug 23 15:37:28 2005//
    CVS Reference       : /lib_PWM_SAM.h/1.3/Thu Jan 22 10:10:50 2004//
    CVS Reference       : /lib_tc_1753b.h/1.1/Fri Jan 31 12:20:02 2003//
    CVS Reference       : /lib_pitc_6079A.h/1.2/Tue Nov  9 14:43:56 2004//
    CVS Reference       : /lib_adc.h/1.6/Fri Oct 17 09:12:38 2003//
    CVS Reference       : /lib_pmc_SAM7X.h/1.5/Fri Nov  4 09:41:32 2005//
    CVS Reference       : /lib_rstc_6098A.h/1.1/Wed Oct  6 10:39:20 2004//
    CVS Reference       : /lib_rttc_6081A.h/1.1/Wed Oct  6 10:39:38 2004//
    CVS Reference       : /lib_pio.h/1.3/Fri Jan 31 12:18:56 2003//
    CVS Reference       : /lib_twi.h/1.3/Mon Jul 19 14:27:58 2004//
    CVS Reference       : /lib_wdtc_6080A.h/1.1/Wed Oct  6 10:38:30 2004//
    CVS Reference       : /lib_usart.h/1.5/Thu Nov 21 16:01:54 2002//
    CVS Reference       : /lib_udp.h/1.5/Tue Aug 30 12:13:47 2005//
    CVS Reference       : /lib_aic_6075b.h/1.2/Thu Jul  7 07:48:22 2005//
    CVS Reference       : /lib_can_AT91.h/1.5/Tue Aug 23 15:37:07 2005//
    ----------------------------------------------------------------------------
*/
#ifndef lib_AT91SAM7_AIC_H
#define lib_AT91SAM7_AIC_H

/* *****************************************************************************
                SOFTWARE API FOR AIC
   ***************************************************************************** */
#define AT91C_AIC_BRANCH_OPCODE ((void (*) ()) 0xE51FFF20) /* ldr, pc, [pc, #-&F20] */

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
	void (*newHandler)() ); /* \arg address of the interrupt handler */


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
	U32 irq_id ); /* \arg interrupt number to initialize */

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
	U32 irq_id );


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
	U32 irq_id); /* \arg interrupt number to initialize */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_AIC_AcknowledgeInterrupt(	AT91PS_AIC pAic )
 * \brief Acknowledge corresponding interrupt number
 * \param pAic pointer to AIC structure
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_AIC_AcknowledgeInterrupt(
	AT91PS_AIC pAic);     /* \arg pointer to the AIC registers */


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
	void (*Handler)() );   /* \arg Interrupt Handler */


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
	U32 irq_id); /* \arg interrupt number */

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
	U32 irq_id); /* \arg Interrupt Number */


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
	U32 irq_id); /* \arg Interrupt Number */


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
	U32 protectMode);   /* \arg Debug Control Register */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_AIC_CfgPMC( AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  AIC
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_AIC_CfgPMC( AT91PS_PMC pPMC );


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_AIC_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB ) 
 * \brief Configure PIO controllers to drive AIC signals
 * \param pPIOA pointer to PIOA controller
 * \param pPIOB pointer to PIOB controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_AIC_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB );


/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_AIC AT91F_AIC_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base AIC peripheral controller address
 * \param u8Controller AIC controller index
 * \return pointer to AIC controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_AIC AT91F_AIC_GetPeripheralAddress( U8 u8Controller );

#endif /* lib_AT91SAM7_AIC_H */
