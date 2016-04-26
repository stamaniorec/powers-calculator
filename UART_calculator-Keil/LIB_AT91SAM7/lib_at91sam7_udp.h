/*  ----------------------------------------------------------------------------
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

#ifndef lib_AT91SAM7_UDP_H
#define lib_AT91SAM7_UDP_H


/* *****************************************************************************
                SOFTWARE API FOR UDP
   ***************************************************************************** */
/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_UDP_EnableInterrupt( AT91PS_UDP pUDP, \
 * 						U32 flag)
 * \brief Enable UDP interrupt
 * \param pUDP pointer to a UDP controller
 * \param flag interrupt to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_UDP_EnableInterrupt (
	AT91PS_UDP pUDP,     /* \arg pointer to a UDP controller */
	U32 flag);   /* \arg interrupt to be enabled */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_UDP_DisableInterrupt( AT91PS_UDP pUDP, \
 * 						U32 flag)
 * \brief Disable UDP interrupt
 * \param pUDP pointer to a UDP controller
 * \param flag interrupt to be disabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_UDP_DisableInterrupt (
	AT91PS_UDP pUDP,     /* \arg pointer to a UDP controller */
	U32 flag);   /* \arg interrupt to be disabled */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_UDP_SetAddress( AT91PS_UDP pUDP, \
 * 						U8 address)
 * \brief Set UDP functional address
 * \param pUDP pointer to a UDP controller
 * \param address new UDP address
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_UDP_SetAddress (
	AT91PS_UDP pUDP,     /* \arg pointer to a UDP controller */
	U8 address);   /* \arg new UDP address */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_UDP_EnableEndpoint( AT91PS_UDP pUDP, \
 * 						U8 endpoint)
 * \brief Enable Endpoint
 * \param pUDP pointer to a UDP controller
 * \param endpoint endpoint number
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_UDP_EnableEndpoint (
	AT91PS_UDP pUDP,     /* \arg pointer to a UDP controller */
	U8 endpoint);   /* \arg endpoint number */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_UDP_DisableEndpoint( AT91PS_UDP pUDP, \
 * 						U8 endpoint)
 * \brief Enable Endpoint
 * \param pUDP pointer to a UDP controller
 * \param endpoint endpoint number
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_UDP_DisableEndpoint (
	AT91PS_UDP pUDP,     /* \arg pointer to a UDP controller */
	U8 endpoint);   /* \arg endpoint number */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_UDP_SetState( AT91PS_UDP pUDP, \
 * 						U32 flag)
 * \brief Set UDP Device state
 * \param pUDP pointer to a UDP controller
 * \param flag new UDP address
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_UDP_SetState (
	AT91PS_UDP pUDP,     /* \arg pointer to a UDP controller */
	U32 flag);   /* \arg new UDP address */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_UDP_GetState( AT91PS_UDP pUDP )
 * \brief return UDP Device state
 * \param pUDP pointer to a UDP controller
 * \return UDP fadden or config state from global state register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_UDP_GetState ( /* \return the UDP device state */
	AT91PS_UDP pUDP);     /* \arg pointer to a UDP controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_UDP_ResetEndpoint( AT91PS_UDP pUDP, \
 * 						U32 flag)
 * \brief Reset UDP endpoint
 * \param pUDP pointer to a UDP controller
 * \param flag Endpoints to be reset
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_UDP_ResetEndpoint ( /* \return the UDP device state */
	AT91PS_UDP pUDP,     /* \arg pointer to a UDP controller */
	U32 flag);   /* \arg Endpoints to be reset */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_UDP_EndpointStall( AT91PS_UDP pUDP, \
 * 						U8 endpoint)
 * \brief Endpoint will STALL requests
 * \param pUDP pointer to a UDP controller
 * \param endpoint endpoint number
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_UDP_EndpointStall(
	AT91PS_UDP pUDP,     /* \arg pointer to a UDP controller */
	U8 endpoint);   /* \arg endpoint number */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_UDP_EndpointWrite( AT91PS_UDP pUDP, \
 * 						U8 endpoint, \
 * 						U8 value)
 * \brief Write value in the DPR
 * \param pUDP pointer to a UDP controller
 * \param endpoint endpoint number
 * \param value value to be written in the DPR
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_UDP_EndpointWrite(
	AT91PS_UDP pUDP,         /* \arg pointer to a UDP controller */
	U8 endpoint,  /* \arg endpoint number */
	U8 value);     /* \arg value to be written in the DPR */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_UDP_EndpointRead( AT91PS_UDP pUDP, \
 * 						U8 endpoint)
 * \brief Return value from the DPR
 * \param pUDP pointer to a UDP controller
 * \param endpoint endpoint number
 * \return value from endpoint FIFO data register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_UDP_EndpointRead(
	AT91PS_UDP pUDP,         /* \arg pointer to a UDP controller */
	U8 endpoint);  /* \arg endpoint number */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_UDP_EndpointEndOfWrite( AT91PS_UDP pUDP, \
 * 						U8 endpoint)
 * \brief Notify the UDP that values in DPR are ready to be sent
 * \param pUDP pointer to a UDP controller
 * \param endpoint endpoint number
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_UDP_EndpointEndOfWrite(
	AT91PS_UDP pUDP,         /* \arg pointer to a UDP controller */
	U8 endpoint);  /* \arg endpoint number */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_UDP_EndpointClear( AT91PS_UDP pUDP, \
 * 						U8 endpoint, \
 * 						U32 flag)
 * \brief Clear flag in the endpoint CSR register
 * \param pUDP pointer to a UDP controller
 * \param endpoint endpoint number
 * \param flag flag to be cleared
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_UDP_EndpointClear(
	AT91PS_UDP pUDP,         /* \arg pointer to a UDP controller */
	U8 endpoint,  /* \arg endpoint number */
	U32 flag);       /* \arg flag to be cleared */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_UDP_EndpointSet( AT91PS_UDP pUDP, \
 * 						U8 endpoint, \
 * 						U32 flag)
 * \brief Set flag in the endpoint CSR register
 * \param pUDP pointer to a UDP controller
 * \param endpoint endpoint number
 * \param flag flag to be cleared
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_UDP_EndpointSet(
	AT91PS_UDP pUDP,         /* \arg pointer to a UDP controller */
	U8 endpoint,  /* \arg endpoint number */
	U32 flag);       /* \arg flag to be set */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_UDP_EndpointStatus( AT91PS_UDP pUDP, \
 * 						U8 endpoint)
 * \brief Return the endpoint CSR register
 * \param pUDP pointer to a UDP controller
 * \param endpoint endpoint number
 * \return endpoint control and status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_UDP_EndpointStatus(
	AT91PS_UDP pUDP,         /* \arg pointer to a UDP controller */
	U8 endpoint);  /* \arg endpoint number */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_UDP_GetInterruptMaskStatus( AT91PS_UDP pUDP )
 * \brief Return UDP Interrupt Mask Status
 * \param pUDP pointer to a UDP controller
 * \return interrupt mask register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_UDP_GetInterruptMaskStatus(AT91PS_UDP pUDP);        /* \arg  pointer to a UDP controller */


/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_UDP_IsInterruptMasked( AT91PS_UDP pUDP, \
 * 						U32 flag)
 * \brief Test if UDP Interrupt is Masked
 * \param pUDP pointer to a UDP controller
 * \param flag flag to be tested
 * \return masked interrupt mask register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_UDP_IsInterruptMasked(
	AT91PS_UDP pUdp,       /* \arg  pointer to a UDP controller */
	U32 flag);     /* \arg  flag to be tested */


/*----------------------------------------------------------------------------*/
/*!  \fn    __inline U32 AT91F_UDP_InterruptStatusRegister( AT91PS_UDP pUDP )
 * \brief Return the Interrupt Status Register
 * \param pUDP pointer to a UDP controller
 * \return interrupt status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_UDP_InterruptStatusRegister(
	AT91PS_UDP pUDP);      /* \arg  pointer to a UDP controller */


/*----------------------------------------------------------------------------*/
/*!  \fn    __inline void AT91F_UDP_InterruptClearRegister( AT91PS_UDP pUDP, \
 * 						U32 flag)
 *  \brief Clear Interrupt Register
 * \param pUDP pointer to a UDP controller
 * \param flag interrupt to be cleat
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_UDP_InterruptClearRegister (
	AT91PS_UDP pUDP,       /* \arg pointer to UDP controller */
	U32 flag);     /* \arg interrupt to be cleat */


/*----------------------------------------------------------------------------*/
/*!  \fn    __inline void AT91F_UDP_EnableTransceiver( AT91PS_UDP pUDP )
 *  \brief Enable transceiver
 * \param pUDP pointer to a UDP controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_UDP_EnableTransceiver(AT91PS_UDP pUDP );      /* \arg  pointer to a UDP controller */


/*----------------------------------------------------------------------------*/
/*!  \fn    __inline void AT91F_UDP_DisableTransceiver( AT91PS_UDP pUDP )
 *  \brief Disable transceiver
 * \param pUDP pointer to a UDP controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_UDP_DisableTransceiver(AT91PS_UDP pUDP );      /* \arg  pointer to a UDP controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_UDP_CfgPMC( AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  UDP
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_UDP_CfgPMC( AT91PS_PMC pPMC );


/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_UDP AT91F_UDP_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base UDP peripheral controller address
 * \param u8Controller UDP controller index
 * \return pointer to UDP controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_UDP AT91F_UDP_GetPeripheralAddress( U8 u8Controller );


#endif /* lib_AT91SAM7_UDP_H */
