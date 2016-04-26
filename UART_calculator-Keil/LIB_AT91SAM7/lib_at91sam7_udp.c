#include "basedef.h"
#include "ioat91sam7x256.h"
#include "lib_AT91SAM7_PMC.h"
#include "lib_AT91SAM7_PIO.h"
#include "lib_AT91SAM7_UDP.h"


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_UDP_EnableInterrupt( AT91PS_UDP pUDP, \
 * 						U32 flag)
 * \brief Enable UDP interrupt
 * \param pUDP pointer to a UDP controller
 * \param flag interrupt to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_UDP_EnableInterrupt(
	AT91PS_UDP pUDP,     /* \arg pointer to a UDP controller */
	U32 flag)   /* \arg interrupt to be enabled */
{
	/*    Write to the IER register */
	pUDP->UDP_IER = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_UDP_DisableInterrupt( AT91PS_UDP pUDP, \
 * 						U32 flag)
 * \brief Disable UDP interrupt
 * \param pUDP pointer to a UDP controller
 * \param flag interrupt to be disabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_UDP_DisableInterrupt(
	AT91PS_UDP pUDP,     /* \arg pointer to a UDP controller */
	U32 flag)   /* \arg interrupt to be disabled */
{
	/*    Write to the IDR register */
	pUDP->UDP_IDR = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_UDP_SetAddress( AT91PS_UDP pUDP, \
 * 						U8 address)
 * \brief Set UDP functional address
 * \param pUDP pointer to a UDP controller
 * \param address new UDP address
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_UDP_SetAddress(
	AT91PS_UDP pUDP,     /* \arg pointer to a UDP controller */
	U8 address)   /* \arg new UDP address */
{
	pUDP->UDP_FADDR = (AT91C_UDP_FEN | address);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_UDP_EnableEndpoint( AT91PS_UDP pUDP, \
 * 						U8 endpoint)
 * \brief Enable Endpoint
 * \param pUDP pointer to a UDP controller
 * \param endpoint endpoint number
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_UDP_EnableEndpoint(
	AT91PS_UDP pUDP,     /* \arg pointer to a UDP controller */
	U8 endpoint)   /* \arg endpoint number */
{
	pUDP->UDP_CSR[endpoint] |= AT91C_UDP_EPEDS;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_UDP_DisableEndpoint( AT91PS_UDP pUDP, \
 * 						U8 endpoint)
 * \brief Enable Endpoint
 * \param pUDP pointer to a UDP controller
 * \param endpoint endpoint number
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_UDP_DisableEndpoint(
	AT91PS_UDP pUDP,     /* \arg pointer to a UDP controller */
	U8 endpoint)   /* \arg endpoint number */
{
	pUDP->UDP_CSR[endpoint] &= ~AT91C_UDP_EPEDS;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_UDP_SetState( AT91PS_UDP pUDP, \
 * 						U32 flag)
 * \brief Set UDP Device state
 * \param pUDP pointer to a UDP controller
 * \param flag new UDP address
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_UDP_SetState(
	AT91PS_UDP pUDP,     /* \arg pointer to a UDP controller */
	U32 flag)   /* \arg new UDP address */
{
	pUDP->UDP_GLBSTATE  &= ~(AT91C_UDP_FADDEN | AT91C_UDP_CONFG);
	pUDP->UDP_GLBSTATE  |= flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_UDP_GetState( AT91PS_UDP pUDP )
 * \brief return UDP Device state
 * \param pUDP pointer to a UDP controller
 * \return UDP fadden or config state from global state register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_UDP_GetState( /* \return the UDP device state */
	AT91PS_UDP pUDP)     /* \arg pointer to a UDP controller */
{
	return (pUDP->UDP_GLBSTATE  & (AT91C_UDP_FADDEN | AT91C_UDP_CONFG));
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_UDP_ResetEndpoint( AT91PS_UDP pUDP, \
 * 						U32 flag)
 * \brief Reset UDP endpoint
 * \param pUDP pointer to a UDP controller
 * \param flag Endpoints to be reset
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_UDP_ResetEndpoint( /* \return the UDP device state */
	AT91PS_UDP pUDP,     /* \arg pointer to a UDP controller */
	U32 flag)   /* \arg Endpoints to be reset */
{
	pUDP->UDP_RSTEP = flag;
	pUDP->UDP_RSTEP = 0;
}

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
	U8 endpoint)   /* \arg endpoint number */
{
	pUDP->UDP_CSR[endpoint] |= AT91C_UDP_FORCESTALL;
}

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
	U8 value)     /* \arg value to be written in the DPR */
{
	pUDP->UDP_FDR[endpoint] = value;
}

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
	U8 endpoint)  /* \arg endpoint number */
{
	return pUDP->UDP_FDR[endpoint];
}

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
	U8 endpoint)  /* \arg endpoint number */
{
	pUDP->UDP_CSR[endpoint] |= AT91C_UDP_TXPKTRDY;
}

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
	U32 flag)       /* \arg flag to be cleared */
{
	pUDP->UDP_CSR[endpoint] &= ~(flag);
}

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
	U32 flag)       /* \arg flag to be set */
{
	pUDP->UDP_CSR[endpoint] |= flag;
}

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
	U8 endpoint)  /* \arg endpoint number */
{
	return pUDP->UDP_CSR[endpoint];
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_UDP_GetInterruptMaskStatus( AT91PS_UDP pUDP )
 * \brief Return UDP Interrupt Mask Status
 * \param pUDP pointer to a UDP controller
 * \return interrupt mask register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_UDP_GetInterruptMaskStatus(
  AT91PS_UDP pUDP)        /* \arg  pointer to a UDP controller */
{
  return pUDP->UDP_IMR;
}

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
  U32 flag)     /* \arg  flag to be tested */
{
  return (AT91F_UDP_GetInterruptMaskStatus(pUdp) & flag);
}

/*----------------------------------------------------------------------------*/
/*!  \fn    __inline U32 AT91F_UDP_InterruptStatusRegister( AT91PS_UDP pUDP )
 * \brief Return the Interrupt Status Register
 * \param pUDP pointer to a UDP controller
 * \return interrupt status register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_UDP_InterruptStatusRegister(
  AT91PS_UDP pUDP )      /* \arg  pointer to a UDP controller */
{
  return pUDP->UDP_ISR;
}

/*----------------------------------------------------------------------------*/
/*!  \fn    __inline void AT91F_UDP_InterruptClearRegister( AT91PS_UDP pUDP, \
 * 						U32 flag)
 *  \brief Clear Interrupt Register
 * \param pUDP pointer to a UDP controller
 * \param flag interrupt to be cleat
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_UDP_InterruptClearRegister(
  AT91PS_UDP pUDP,       /* \arg pointer to UDP controller */
  U32 flag)     /* \arg interrupt to be cleat */
{
  pUDP->UDP_ICR = flag;
}

/*----------------------------------------------------------------------------*/
/*!  \fn    __inline void AT91F_UDP_EnableTransceiver( AT91PS_UDP pUDP )
 *  \brief Enable transceiver
 * \param pUDP pointer to a UDP controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_UDP_EnableTransceiver(
  AT91PS_UDP pUDP )      /* \arg  pointer to a UDP controller */
{
    pUDP->UDP_TXVC &= ~AT91C_UDP_TXVDIS;
}

/*----------------------------------------------------------------------------*/
/*!  \fn    __inline void AT91F_UDP_DisableTransceiver( AT91PS_UDP pUDP )
 *  \brief Disable transceiver
 * \param pUDP pointer to a UDP controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_UDP_DisableTransceiver(
  AT91PS_UDP pUDP )      /* \arg  pointer to a UDP controller */
{
    pUDP->UDP_TXVC = AT91C_UDP_TXVDIS;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_UDP_CfgPMC( void )
 * \brief Enable Peripheral clock in PMC for  UDP
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_UDP_CfgPMC(AT91PS_PMC pPMC)
{
	AT91F_PMC_EnablePeripheralClock(
		pPMC, /* PIO controller base address */
		((U32) 1 << AT91C_ID_UDP));
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_UDP AT91F_UDP_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base UDP peripheral controller address
 * \param u8Controller UDP controller index
 * \return pointer to UDP controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_UDP AT91F_UDP_GetPeripheralAddress( U8 u8Controller )
{
	return AT91C_BASE_UDP;
}
