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
#ifndef lib_AT91SAM7_PDC_H
#define lib_AT91SAM7_PDC_H

/* *****************************************************************************
                SOFTWARE API FOR PDC
   ***************************************************************************** */
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
	U32 bytes);  /* \arg number of bytes to be received */


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
	U32 bytes);    /* \arg number of bytes to be transmitted */


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
__inline void AT91F_PDC_SetRx (
	AT91PS_PDC pPDC,       /* \arg pointer to a PDC controller */
	S8 *address,         /* \arg address to the next block to be received */
	U32 bytes);    /* \arg number of bytes to be received */


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
	U32 bytes);    /* \arg number of bytes to be transmitted */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PDC_EnableTx( AT91PS_PDC pPDC )
 * \brief Enable transmit
 * \param pPDC pointer to a PDC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PDC_EnableTx(
	AT91PS_PDC pPDC );       /* \arg pointer to a PDC controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PDC_EnableRx( AT91PS_PDC pPDC )
 * \brief Enable receive
 * \param pPDC pointer to a PDC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PDC_EnableRx(
	AT91PS_PDC pPDC );       /* \arg pointer to a PDC controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PDC_DisableTx( AT91PS_PDC pPDC )
 * \brief Disable transmit
 * \param pPDC pointer to a PDC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PDC_DisableTx(
	AT91PS_PDC pPDC );       /* \arg pointer to a PDC controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PDC_DisableRx( AT91PS_PDC pPDC )
 * \brief Disable receive
 * \param pPDC pointer to a PDC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PDC_DisableRx(
	AT91PS_PDC pPDC );       /* \arg pointer to a PDC controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PDC_IsTxEmpty( AT91PS_PDC pPDC )
 * \brief Test if the current transfer descriptor has been sent
 * \param pPDC pointer to a PDC controller
 * \return transmit counter register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PDC_IsTxEmpty( /* \return return 1 if transfer is complete */
	AT91PS_PDC pPDC );       /* \arg pointer to a PDC controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PDC_IsNextTxEmpty( AT91PS_PDC pPDC )
 * \brief Test if the next transfer descriptor has been moved to the current td
 * \param pPDC pointer to a PDC controller
 * \return next transmit counter register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PDC_IsNextTxEmpty( /* \return return 1 if transfer is complete */
	AT91PS_PDC pPDC );       /* \arg pointer to a PDC controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PDC_IsRxEmpty( AT91PS_PDC pPDC )
 * \brief Test if the current transfer descriptor has been filled
 * \param pPDC pointer to a PDC controller
 * \return receive counter register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PDC_IsRxEmpty( /* \return return 1 if transfer is complete */
	AT91PS_PDC pPDC );       /* \arg pointer to a PDC controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_PDC_IsNextRxEmpty( AT91PS_PDC pPDC )
 * \brief Test if the next transfer descriptor has been moved to the current td
 * \param pPDC pointer to a PDC controller
 * \return next receive counter register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_PDC_IsNextRxEmpty( /* \return return 1 if transfer is complete */
	AT91PS_PDC pPDC );       /* \arg pointer to a PDC controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PDC_Open( AT91PS_PDC pPDC )
 * \brief Open PDC: disable TX and RX reset transfer descriptors, re-enable RX and TX
 * \param pPDC pointer to a PDC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PDC_Open(
	AT91PS_PDC pPDC);       /* \arg pointer to a PDC controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_PDC_Close( AT91PS_PDC pPDC )
 * \brief Close PDC: disable TX and RX reset transfer descriptors
 * \param pPDC pointer to a PDC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_PDC_Close(
	AT91PS_PDC pPDC);       /* \arg pointer to a PDC controller */


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
	U32 szNextBuffer );


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
	U32 szNextBuffer );


#endif /* lib_AT91SAM7_PDC_H */
