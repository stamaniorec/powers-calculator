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
#ifndef lib_AT91SAM7_SPI_H
#define lib_AT91SAM7_SPI_H


/* *****************************************************************************
                SOFTWARE API FOR SPI
   ***************************************************************************** */
/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SPI_CfgCs( AT91PS_SPI pSPI, \
 * 							U32 cs, \
 * 							U32 val)
 * \brief Configure SPI chip select register
 * \param pSPI pointer to a SPI controller
 * \param cs SPI cs number (0 to 3)
 * \param val chip select register
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SPI_CfgCs (
	AT91PS_SPI pSPI,     /* pointer to a SPI controller */
	U32 cs,     /* SPI cs number (0 to 3) */
 	U32 val);   /*  chip select register */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SPI_EnableInterrupt(	AT91PS_SPI pSPI, \
 * 										U32 flag)
 * \brief Enable SPI interrupt
 * \param pSPI pointer to a SPI controller
 * \param flag interrupt to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SPI_EnableInterrupt (
	AT91PS_SPI pSPI,     /* pointer to a SPI controller */
	U32 flag);   /* interrupt to be enabled */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SPI_DisableInterrupt(	AT91PS_SPI pSPI, \
 * 										U32 flag)
 * \brief Disable SPI interrupt
 * \param pSPI pointer to a SPI controller
 * \param flag interrupt to be disabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SPI_DisableInterrupt (
	AT91PS_SPI pSPI, /* pointer to a SPI controller */
	U32 flag); /* Iinterrupt to be disabled */

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SPI_Reset(	AT91PS_SPI pSPI )
 * \brief Reset the SPI controller
 * \param pSPI pointer to a SPI controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SPI_Reset (
	AT91PS_SPI pSPI /* pointer to a SPI controller */
	);


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SPI_Enable(	AT91PS_SPI pSPI )
 * \brief Enable the SPI controller
 * \param pSPI pointer to a SPI controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SPI_Enable (
	AT91PS_SPI pSPI /* pointer to a SPI controller */
	);


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SPI_Disable(	AT91PS_SPI pSPI )
 * \brief Disable the SPI controller
 * \param pSPI pointer to a SPI controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SPI_Disable (
	AT91PS_SPI pSPI /* pointer to a SPI controller */
	);


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SPI_CfgMode(	AT91PS_SPI pSPI, \
 * 								U32 mode)
 * \brief Enable the SPI controller
 * \param pSPI pointer to a SPI controller
 * \param mode mode register
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SPI_CfgMode (
	AT91PS_SPI pSPI, /* pointer to a SPI controller */
	U32 mode);        /* mode register */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SPI_CfgPCS(	AT91PS_SPI pSPI, \
 * 								S8 PCS_Device)
 * \brief Switch to the correct PCS of SPI Mode Register : Fixed Peripheral Selected
 * \param pSPI pointer to a SPI controller
 * \param PCS_Device PCS of the Device
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SPI_CfgPCS (
	AT91PS_SPI pSPI, /* pointer to a SPI controller */
	S8 PCS_Device); /* PCS of the Device */


/*----------------------------------------------------------------------------*/
/*! \fn  __inline U32  AT91F_SPI_ReceiveFrame(	AT91PS_SPI pSPI, \
 * 									S8 * pBuffer, \
 * 									U32 szBuffer, \
 * 									S8 * pNextBuffer, \
 * 									U32 szNextBuffer )
 * \brief Return 2 if PDC has been initialized with Buffer and Next Buffer, 1 if PDC has been initializaed with Next Buffer, 0 if PDC is busy
 * \param pSPI pointer to a SPI controller
 * \param pBuffer pointer to receiving buffer
 * \param szBuffer receiving buffer size
 * \param pNextBuffer pointer to next receiving buffer
 * \param szNextBuffer size of next receiving buffer
 * \return 2 if PDC has been initialized with Buffer and Next Buffer,\n 1 if PDC has been initializaed with Next Buffer,\n 0 if PDC is busy
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_SPI_ReceiveFrame (
	AT91PS_SPI pSPI,
	S8 *pBuffer,
	U32 szBuffer,
	S8 *pNextBuffer,
	U32 szNextBuffer );


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_SPI_SendFrame(	AT91PS_SPI pSPI, \
 * 									S8 * pBuffer, \
 * 									U32 szBuffer, \
 * 									S8 * pNextBuffer, \
 * 									U32 szNextBuffer )
 * \brief Return 2 if PDC has been initialized with Buffer and Next Buffer, 1 if PDC has been initializaed with Next Buffer, 0 if PDC is bSPIy
 * \param pSPI pointer to a SPI controller
 * \param pBuffer pointer to transmition buffer
 * \param szBuffer transmition buffer size
 * \param pNextBuffer pointer to next transmition buffer
 * \param szNextBuffer size of next transmition buffer
 * \return 2 if the two buffers are prepared for sending, \n 1 if only next buffer if prepared for sending, \n 0 if buffers are busy
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_SPI_SendFrame(
	AT91PS_SPI pSPI,
	S8 *pBuffer,
	U32 szBuffer,
	S8 *pNextBuffer,
	U32 szNextBuffer );


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SPI_Close(	AT91PS_SPI pSPI )
 * \brief Close SPI: disable IT disable transfert, close PDC
 * \param pSPI pointer to a SPI controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SPI_Close (
	AT91PS_SPI pSPI);     /* \arg pointer to a SPI controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SPI_PutChar(	AT91PS_SPI pSPI, \
 * 								U32 character, \
 * 								U32 cs_number )
 * \brief Send a character,does not check if ready to send
 * \param pSPI pointer to a SPI controller
 * \param character S8 to be transmitted
 * \param cs_number range ( 0 - 15 )
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SPI_PutChar (
	AT91PS_SPI pSPI,
	U32 character,
	U32 cs_number );


/*----------------------------------------------------------------------------*/
/*! \fn   __inline U32 AT91F_SPI_GetChar(	AT91PS_SPI pSPI )
 * \brief Receive a character,does not check if a character is available
 * \param pSPI pointer to a SPI controller
 * \return last received character
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_SPI_GetChar (
	const AT91PS_SPI pSPI);


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_SPI_GetInterruptMaskStatus(	AT91PS_SPI pSPI )
 * \brief Return SPI Interrupt Mask Status
 * \param pSPI pointer to a SPI controller
 * \return SPI interrupt mask 
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_SPI_GetInterruptMaskStatus( /* \return SPI Interrupt Mask Status */
        AT91PS_SPI pSpi); /* \arg  pointer to a SPI controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_SPI_IsInterruptMasked(	AT91PS_SPI pSPI, \
 * 										U32 flag )
 * \brief Test if SPI Interrupt is Masked
 * \param pSPI pointer to a SPI controller
 * \param flag flag to be tested
 * \return masked SPI interrupt status
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_SPI_IsInterruptMasked(
        AT91PS_SPI pSpi,   /* \arg  pointer to a SPI controller */
        U32 flag); /* \arg  flag to be tested */

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_SPI_GetStatus(	AT91PS_SPI pSPI )
 * \brief Return SPI Status
 * \param pSPI pointer to a SPI controller
 * \return SPI status
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_SPI_GetStatus( /* \return SPI Status */
        AT91PS_SPI pSpi); /* \arg  pointer to a SPI controller */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_SPI_IsStatusMasked(	AT91PS_SPI pSPI, \
 * 										U32 flag )
 * \brief Test if SPI status is masked
 * \param pSPI pointer to a SPI controller
 * \param flag flag to be tested
 * \return masked SPI status
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_SPI_IsStatusMasked(
        AT91PS_SPI pSpi,   /* \arg  pointer to a SPI controller */
        U32 flag); /* \arg  flag to be tested */


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SPI1_CfgPMC(  AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  SPI1
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SPI1_CfgPMC(  AT91PS_PMC pPMC );


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SPI1_CfgPIO(  AT91PS_PIO pPIOA,  AT91PS_PIO pPIOB )
 * \brief Configure PIO controllers to drive SPI1 signals
 * \param pPIOA pointer to PIOA controller
 * \param pPIOB pointer to PIOB controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SPI1_CfgPIO( AT91PS_PIO pPIOA,  AT91PS_PIO pPIOB );


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SPI0_CfgPMC(  AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  SPI0
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SPI0_CfgPMC( AT91PS_PMC pPMC );


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SPI0_CfgPIO(  AT91PS_PIO pPIOA,  AT91PS_PIO pPIOB )
 * \brief Configure PIO controllers to drive SPI0 signals
 * \param pPIOA pointer to PIOA controller
 * \param pPIOB pointer to PIOB controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SPI0_CfgPIO( AT91PS_PIO pPIOA,  AT91PS_PIO pPIOB );


/*!************************************************************************
 * \fn void AT91F_SPI_WriteCommand(AT91PS_SPI pSPI, U32 data, U8 channel )
 * \param pSPI pointer to SPI controller
 * \param data Data to be sent to the LCD Driver
 * \param channel channel numner ( 0 .. 3 )
 * \brief   Sends a commands to the LCD driver
 *************************************************************************/
void AT91F_SPI_WriteCommand( AT91PS_SPI pSPI, U32 data, U8 channel );


/*!************************************************************************
 * \fn void AT91F_SPI_WriteData(AT91PS_SPI pSPI, U32 data, U8 channel )
 * \param pSPI pointer to SPI controller
 * \param data Data to be sent to the LCD Driver
 * \param channel channel numner ( 0 .. 3 )
 * \brief Sends data to the LCD driver
 *************************************************************************/
void AT91F_SPI_WriteData( AT91PS_SPI pSPI, U32 data, U8 channel );


/*!************************************************************************
 * \fn HRESULT AT91F_SPI_ReadData(AT91PS_SPI pSPI, U8 * pData, U32 nDataSize, U8 channel )
 * \param pSPI pointer to SPI controller
 * \param data Data to be sent to the LCD Driver
 * \param channel channel numner ( 0 .. 3 )
 * \brief Sends data to the LCD driver
 *************************************************************************/
HRESULT AT91F_SPI_ReadData( AT91PS_SPI pSPI, U8 * pData, U32 nDataSize, U8 channel );


/*!************************************************************************
 * \fn HRESULT AT91F_SPI_Init( U8 nUnitId )
 * \param nUnitId SPI controller ID ( 0, 1, ... )
 * \return status of SPI intialization
 * \brief Initialize SPI interface
 * additional configuration needed like the one bellow :
 *    pSPI = AT91F_SPI_GetPeripheralAddress( 0 );
 * 	  AT91F_SPI_CfgMode( pSPI, 0xE0019 ); // Master mode, fixed select, disable decoder, FDIV=1 (MCK), PCS=1110
 *    AT91F_SPI_CfgCs( pSPI, 0, 0x01010211 ); // 9bit, CPOL=1, ClockPhase=0, SCLK = 48Mhz/(32*2) = 750kHz
 *************************************************************************/
HRESULT AT91F_SPI_Init( U8 nUnitId );


/*!************************************************************************
 * \fn void * AT91F_SPI_GetPeripheralAddress( U8 nUnitId )
 * \param nUnitId SPI controller ID ( 0, 1, ... )
 * \return address of SPI controller 
 * \brief pointer to SPI peripheral control structure
 *************************************************************************/
void * AT91F_SPI_GetPeripheralAddress( U8 nUnitId );


/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_PDC AT91F_SPI_PDC_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base PDC peripheral controller address
 * \param u8Controller PDC controller index
 * \return pointer to PDC controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_PDC AT91F_SPI_PDC_GetPeripheralAddress( U8 u8Controller );


#endif /* lib_AT91SAM7_SPI_H */
