#include "basedef.h"
#include "ioat91sam7x256.h"
#include "lib_AT91SAM7_PMC.h"
#include "lib_AT91SAM7_PIO.h"
#include "lib_AT91SAM7_PDC.h"


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PDC_SetNextRx(	AT91PS_PDC pPDC, \
 * 								S8 *address, \
 * 								U32 bytes)
 * \brief Set the next receive transfer descriptor
 * \param pPDC pointer to a PDC controller
 * \param address address to the next block to be received
 * \param bytes number of bytes to be received
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PDC_SetNextRx(
	AT91PS_PDC pPDC,     /* \arg pointer to a PDC controller */
	S8 *address,       /* \arg address to the next block to be received */
	U32 bytes)  /* \arg number of bytes to be received */
{
	pPDC->PDC_RNPR = (U32) address;
	pPDC->PDC_RNCR = bytes;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PDC_SetNextTx(	AT91PS_PDC pPDC, \
 * 								S8 *address, \
 * 								U32 bytes)
 * \brief Set the next transmit transfer descriptor
 * \param pPDC pointer to a PDC controller
 * \param address address to the next block to be transmitted
 * \param bytes number of bytes to be transmitted
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PDC_SetNextTx(
	AT91PS_PDC pPDC,       /* \arg pointer to a PDC controller */
	S8 *address,         /* \arg address to the next block to be transmitted */
	U32 bytes)    /* \arg number of bytes to be transmitted */
{
	pPDC->PDC_TNPR = (U32) address;
	pPDC->PDC_TNCR = bytes;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PDC_SetRx(	AT91PS_PDC pPDC, \
 *							S8 *address, \
 *							U32 bytes)
 * \brief Set the receive transfer descriptor
 * \param pPDC pointer to a PDC controller
 * \param address address to the next block to be received
 * \param bytes number of bytes to be received
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PDC_SetRx(
	AT91PS_PDC pPDC,       /* \arg pointer to a PDC controller */
	S8 *address,         /* \arg address to the next block to be received */
	U32 bytes)    /* \arg number of bytes to be received */
{
	pPDC->PDC_RPR = (U32) address;
	pPDC->PDC_RCR = bytes;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PDC_SetTx(	AT91PS_PDC pPDC, \
 * 								S8 *address, \
 * 								U32 bytes)
 * \brief Set the transmit transfer descriptor
 * \param pPDC pointer to a PDC controller
 * \param address address to the block to be transmitted
 * \param bytes number of bytes to be transmitted
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PDC_SetTx(
	AT91PS_PDC pPDC,       /* \arg pointer to a PDC controller */
	S8 *address,         /* \arg address to the block to be transmitted */
	U32 bytes)    /* \arg number of bytes to be transmitted */
{
	pPDC->PDC_TPR = (U32) address;
	pPDC->PDC_TCR = bytes;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PDC_EnableTx( AT91PS_PDC pPDC )
 * \brief Enable transmit
 * \param pPDC pointer to a PDC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PDC_EnableTx(
	AT91PS_PDC pPDC )       /* \arg pointer to a PDC controller */
{
	pPDC->PDC_PTCR = AT91C_PDC_TXTEN;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PDC_EnableRx( AT91PS_PDC pPDC )
 * \brief Enable receive
 * \param pPDC pointer to a PDC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PDC_EnableRx(
	AT91PS_PDC pPDC )       /* \arg pointer to a PDC controller */
{
	pPDC->PDC_PTCR = AT91C_PDC_RXTEN;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PDC_DisableTx( AT91PS_PDC pPDC )
 * \brief Disable transmit
 * \param pPDC pointer to a PDC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PDC_DisableTx(
	AT91PS_PDC pPDC )       /* \arg pointer to a PDC controller */
{
	pPDC->PDC_PTCR = AT91C_PDC_TXTDIS;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PDC_DisableRx( AT91PS_PDC pPDC )
 * \brief Disable receive
 * \param pPDC pointer to a PDC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PDC_DisableRx(
	AT91PS_PDC pPDC )       /* \arg pointer to a PDC controller */
{
	pPDC->PDC_PTCR = AT91C_PDC_RXTDIS;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PDC_IsTxEmpty( AT91PS_PDC pPDC )
 * \brief Test if the current transfer descriptor has been sent
 * \param pPDC pointer to a PDC controller
 * \return transmit counter register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PDC_IsTxEmpty( /* \return return 1 if transfer is complete */
	AT91PS_PDC pPDC )       /* \arg pointer to a PDC controller */
{
	return !(pPDC->PDC_TCR);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PDC_IsNextTxEmpty( AT91PS_PDC pPDC )
 * \brief Test if the next transfer descriptor has been moved to the current td
 * \param pPDC pointer to a PDC controller
 * \return next transmit counter register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PDC_IsNextTxEmpty( /* \return return 1 if transfer is complete */
	AT91PS_PDC pPDC )       /* \arg pointer to a PDC controller */
{
	return !(pPDC->PDC_TNCR);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PDC_IsRxEmpty( AT91PS_PDC pPDC )
 * \brief Test if the current transfer descriptor has been filled
 * \param pPDC pointer to a PDC controller
 * \return receive counter register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PDC_IsRxEmpty( /* \return return 1 if transfer is complete */
	AT91PS_PDC pPDC )       /* \arg pointer to a PDC controller */
{
	return !(pPDC->PDC_RCR);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PDC_IsNextRxEmpty( AT91PS_PDC pPDC )
 * \brief Test if the next transfer descriptor has been moved to the current td
 * \param pPDC pointer to a PDC controller
 * \return next receive counter register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PDC_IsNextRxEmpty( /* \return return 1 if transfer is complete */
	AT91PS_PDC pPDC )       /* \arg pointer to a PDC controller */
{
	return !(pPDC->PDC_RNCR);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PDC_Open( AT91PS_PDC pPDC )
 * \brief Open PDC: disable TX and RX reset transfer descriptors, re-enable RX and TX
 * \param pPDC pointer to a PDC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PDC_Open(
	AT91PS_PDC pPDC)       /* \arg pointer to a PDC controller */
{
    /** Disable the RX and TX PDC transfer requests */
	AT91F_PDC_DisableRx(pPDC);
	AT91F_PDC_DisableTx(pPDC);

	/** Reset all Counter register Next buffer first */
	AT91F_PDC_SetNextTx(pPDC, (S8 *) 0, 0);
	AT91F_PDC_SetNextRx(pPDC, (S8 *) 0, 0);
	AT91F_PDC_SetTx(pPDC, (S8 *) 0, 0);
	AT91F_PDC_SetRx(pPDC, (S8 *) 0, 0);

    /** Enable the RX and TX PDC transfer requests */
	AT91F_PDC_EnableRx(pPDC);
	AT91F_PDC_EnableTx(pPDC);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PDC_Close( AT91PS_PDC pPDC )
 * \brief Close PDC: disable TX and RX reset transfer descriptors
 * \param pPDC pointer to a PDC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PDC_Close(
	AT91PS_PDC pPDC)       /* \arg pointer to a PDC controller */
{
    /** Disable the RX and TX PDC transfer requests */
	AT91F_PDC_DisableRx(pPDC);
	AT91F_PDC_DisableTx(pPDC);

	/** Reset all Counter register Next buffer first */
	AT91F_PDC_SetNextTx(pPDC, (S8 *) 0, 0);
	AT91F_PDC_SetNextRx(pPDC, (S8 *) 0, 0);
	AT91F_PDC_SetTx(pPDC, (S8 *) 0, 0);
	AT91F_PDC_SetRx(pPDC, (S8 *) 0, 0);

}

/*----------------------------------------------------------------------------*/
/*! \fn   __inline U32  AT91F_PDC_SendFrame(	AT91PS_PDC pPDC, \
 * 								S8 *pBuffer, \
 * 								U32 szBuffer, \
 * 								S8 *pNextBuffer, \
 * 								U32 szNextBuffer )
 * \brief Close PDC: disable TX and RX reset transfer descriptors
 * \param pPDC pointer to a PDC controller
 * \param pBuffer pointer to transmition buffer
 * \param szBuffer size of the transmition buffer
 * \param pNextBuffer pointer to next transmition buffer
 * \param szNextBuffer size of the next transmition buffer
 * \return 2 if the two buffers are prepared for sending, \n 1 if only next buffer if prepared for sending, \n 0 if buffers are busy
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PDC_SendFrame(
	AT91PS_PDC pPDC,
	S8 *pBuffer,
	U32 szBuffer,
	S8 *pNextBuffer,
	U32 szNextBuffer )
{
	if (AT91F_PDC_IsTxEmpty(pPDC)) {
		/** Buffer and next buffer can be initialized */
		AT91F_PDC_SetTx(pPDC, pBuffer, szBuffer);
		AT91F_PDC_SetNextTx(pPDC, pNextBuffer, szNextBuffer);
		return 2;
	}
	else if (AT91F_PDC_IsNextTxEmpty(pPDC)) {
		/** Only one buffer can be initialized */
		AT91F_PDC_SetNextTx(pPDC, pBuffer, szBuffer);
		return 1;
	}
	else {
		/** All buffer are in use... */
		return 0;
	}
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PDC_ReceiveFrame(	AT91PS_PDC pPDC, \
 * 								S8 *pBuffer, \
 * 								U32 szBuffer, \
 * 								S8 *pNextBuffer, \
 * 								U32 szNextBuffer )
 * \brief Close PDC: disable TX and RX reset transfer descriptors
 * \param pPDC pointer to a PDC controller
 * \param pBuffer pointer to receiving buffer
 * \param szBuffer size of the receiving buffer
 * \param pNextBuffer pointer to next receiving buffer
 * \param szNextBuffer size of the next receiving buffer
 * \return 2 if the two buffers are prepared for receiving, \n 1 if only next buffer if prepared for receiving, \n 0 if buffers are busy
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PDC_ReceiveFrame(
	AT91PS_PDC pPDC,
	S8 *pBuffer,
	U32 szBuffer,
	S8 *pNextBuffer,
	U32 szNextBuffer )
{
	if (AT91F_PDC_IsRxEmpty(pPDC)) {
		/** Buffer and next buffer can be initialized */
		AT91F_PDC_SetRx(pPDC, pBuffer, szBuffer);
		AT91F_PDC_SetNextRx(pPDC, pNextBuffer, szNextBuffer);
		return 2;
	}
	else if (AT91F_PDC_IsNextRxEmpty(pPDC)) {
		/** Only one buffer can be initialized */
		AT91F_PDC_SetNextRx(pPDC, pBuffer, szBuffer);
		return 1;
	}
	else {
		/** All buffer are in use... */
		return 0;
	}
}


