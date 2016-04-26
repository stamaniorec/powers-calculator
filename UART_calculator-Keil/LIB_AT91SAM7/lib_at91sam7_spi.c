#include "basedef.h"
#include "ioat91sam7x256.h"
#include "lib_AT91SAM7_PMC.h"
#include "lib_AT91SAM7_PIO.h"
#include "lib_AT91SAM7_PDC.h"
#include "lib_AT91SAM7_SPI.h"

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
__inline void AT91F_SPI_CfgCs(
	AT91PS_SPI pSPI,     /* pointer to a SPI controller */
	U32 cs,     /* SPI cs number (0 to 3) */
 	U32 val)   /*  chip select register */
{
	/** Write to the CSR register */
	*(pSPI->SPI_CSR + cs) = val;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SPI_EnableInterrupt(	AT91PS_SPI pSPI, \
 * 										U32 flag)
 * \brief Enable SPI interrupt
 * \param pSPI pointer to a SPI controller
 * \param flag interrupt to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SPI_EnableInterrupt(
	AT91PS_SPI pSPI,     /* pointer to a SPI controller */
	U32 flag)   /* interrupt to be enabled */
{
	/** Write to the IER register */
	pSPI->SPI_IER = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SPI_DisableInterrupt(	AT91PS_SPI pSPI, \
 * 										U32 flag)
 * \brief Disable SPI interrupt
 * \param pSPI pointer to a SPI controller
 * \param flag interrupt to be disabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SPI_DisableInterrupt(
	AT91PS_SPI pSPI, /* pointer to a SPI controller */
	U32 flag) /* Iinterrupt to be disabled */
{
	/** Write to the IDR register */
	pSPI->SPI_IDR = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SPI_Reset(	AT91PS_SPI pSPI )
 * \brief Reset the SPI controller
 * \param pSPI pointer to a SPI controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SPI_Reset(
	AT91PS_SPI pSPI /* pointer to a SPI controller */
	)
{
	/** Write to the CR register */
	pSPI->SPI_CR = (AT91C_SPI_SWRST) | (AT91C_SPI_SPIEN);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SPI_Enable(	AT91PS_SPI pSPI )
 * \brief Enable the SPI controller
 * \param pSPI pointer to a SPI controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SPI_Enable(
	AT91PS_SPI pSPI /* pointer to a SPI controller */
	)
{
	/** Write to the CR register */
	pSPI->SPI_CR = AT91C_SPI_SPIEN;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SPI_Disable(	AT91PS_SPI pSPI )
 * \brief Disable the SPI controller
 * \param pSPI pointer to a SPI controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SPI_Disable(
	AT91PS_SPI pSPI /* pointer to a SPI controller */
	)
{
	/** Write to the CR register */
	pSPI->SPI_CR = AT91C_SPI_SPIDIS;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SPI_CfgMode(	AT91PS_SPI pSPI, \
 * 								U32 mode)
 * \brief Enable the SPI controller
 * \param pSPI pointer to a SPI controller
 * \param mode mode register
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SPI_CfgMode(
	AT91PS_SPI pSPI, /* pointer to a SPI controller */
	U32 mode)        /* mode register */
{
	/** Write to the MR register */
	pSPI->SPI_MR = mode;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SPI_CfgPCS(	AT91PS_SPI pSPI, \
 * 								S8 PCS_Device)
 * \brief Switch to the correct PCS of SPI Mode Register : Fixed Peripheral Selected
 * \param pSPI pointer to a SPI controller
 * \param PCS_Device PCS of the Device
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SPI_CfgPCS(
	AT91PS_SPI pSPI, /* pointer to a SPI controller */
	S8 PCS_Device) /* PCS of the Device */
{
 	/** Write to the MR register */
	pSPI->SPI_MR &= 0xFFF0FFFF;
	pSPI->SPI_MR |= ( (PCS_Device<<16) & AT91C_SPI_PCS );
}

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
__inline U32 AT91F_SPI_ReceiveFrame(
	AT91PS_SPI pSPI,
	S8 *pBuffer,
	U32 szBuffer,
	S8 *pNextBuffer,
	U32 szNextBuffer )
{
	return AT91F_PDC_ReceiveFrame(
		(AT91PS_PDC) &(pSPI->SPI_RPR),
		pBuffer,
		szBuffer,
		pNextBuffer,
		szNextBuffer);
}

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
	U32 szNextBuffer )
{
	return AT91F_PDC_SendFrame(
		(AT91PS_PDC) &(pSPI->SPI_RPR),
		pBuffer,
		szBuffer,
		pNextBuffer,
		szNextBuffer);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SPI_Close(	AT91PS_SPI pSPI )
 * \brief Close SPI: disable IT disable transfert, close PDC
 * \param pSPI pointer to a SPI controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SPI_Close(
	AT91PS_SPI pSPI)     /* \arg pointer to a SPI controller */
{
    /** Reset all the Chip Select register */
    pSPI->SPI_CSR[0] = 0 ;
    pSPI->SPI_CSR[1] = 0 ;
    pSPI->SPI_CSR[2] = 0 ;
    pSPI->SPI_CSR[3] = 0 ;

    /** Reset the SPI mode */
    pSPI->SPI_MR = 0  ;

    /** Disable all interrupts */
    pSPI->SPI_IDR = 0xFFFFFFFF ;

    /** Abort the Peripheral Data Transfers */
    AT91F_PDC_Close((AT91PS_PDC) &(pSPI->SPI_RPR));

    /** Disable receiver and transmitter and stop any activity immediately */
    pSPI->SPI_CR = AT91C_SPI_SPIDIS;
}

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
__inline void AT91F_SPI_PutChar(
	AT91PS_SPI pSPI,
	U32 character,
	U32 cs_number )
{
    U32 value_for_cs;
    value_for_cs = (~(1 << cs_number)) & 0xF;  /* Place a zero among a 4 ONEs number */
    pSPI->SPI_TDR = (character & 0xFFFF) | (value_for_cs << 16);
}

/*----------------------------------------------------------------------------*/
/*! \fn   __inline U32 AT91F_SPI_GetChar(	AT91PS_SPI pSPI )
 * \brief Receive a character,does not check if a character is available
 * \param pSPI pointer to a SPI controller
 * \return last received character
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_SPI_GetChar(
	const AT91PS_SPI pSPI)
{
    return((pSPI->SPI_RDR) & 0xFFFF);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_SPI_GetInterruptMaskStatus(	AT91PS_SPI pSPI )
 * \brief Return SPI Interrupt Mask Status
 * \param pSPI pointer to a SPI controller
 * \return SPI interrupt mask 
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_SPI_GetInterruptMaskStatus( /* \return SPI Interrupt Mask Status */
        AT91PS_SPI pSpi) /* \arg  pointer to a SPI controller */
{
        return pSpi->SPI_IMR;
}

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
        U32 flag) /* \arg  flag to be tested */
{
        return (AT91F_SPI_GetInterruptMaskStatus(pSpi) & flag);
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_SPI_GetStatus(	AT91PS_SPI pSPI )
 * \brief Return SPI Status
 * \param pSPI pointer to a SPI controller
 * \return SPI status
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_SPI_GetStatus( /* \return SPI Status */
        AT91PS_SPI pSpi) /* \arg  pointer to a SPI controller */
{
        return pSpi->SPI_SR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_SPI_IsStatusMasked(	AT91PS_SPI pSPI, \
 * 										U32 flag )
 * \brief Test if SPI sttus is masked
 * \param pSPI pointer to a SPI controller
 * \param flag flag to be tested
 * \return masked SPI status
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_SPI_IsStatusMasked(
        AT91PS_SPI pSPI,   /* \arg  pointer to a SPI controller */
        U32 flag) /* \arg  flag to be tested */
{
        return (AT91F_SPI_GetStatus(pSPI) & flag);
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SPI1_CfgPMC( AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  SPI1
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SPI1_CfgPMC( AT91PS_PMC pPMC )
{
	AT91F_PMC_EnablePeripheralClock(
		pPMC, /* PIO controller base address */
		((U32) 1 << AT91C_ID_SPI1));
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SPI1_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
 * \brief Configure PIO controllers to drive SPI1 signals
 * \param pPIOA pointer to PIOA controller
 * \param pPIOB pointer to PIOB controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SPI1_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
{
	/* Configure PIO controllers to periph mode */
	AT91F_PIO_CfgPeripheral(
		pPIOA, /* PIO controller base address */
		0, /* Peripheral A */
		((U32) AT91C_PA23_SPI1_MOSI) |
		((U32) AT91C_PA21_SPI1_NPCS0) |
		((U32) AT91C_PA25_SPI1_NPCS1) |
		((U32) AT91C_PA2_SPI1_NPCS1) |
		((U32) AT91C_PA24_SPI1_MISO) |
		((U32) AT91C_PA22_SPI1_SPCK) |
		((U32) AT91C_PA26_SPI1_NPCS2) |
		((U32) AT91C_PA3_SPI1_NPCS2) |
		((U32) AT91C_PA29_SPI1_NPCS3) |
		((U32) AT91C_PA4_SPI1_NPCS3)); /* Peripheral B */
	/* Configure PIO controllers to periph mode */
	AT91F_PIO_CfgPeripheral(
		pPIOB, /* PIO controller base address */
		0, /* Peripheral A */
		((U32) AT91C_PB10_SPI1_NPCS1) |
		((U32) AT91C_PB11_SPI1_NPCS2) |
		((U32) AT91C_PB16_SPI1_NPCS3)); /* Peripheral B */
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SPI0_CfgPMC( AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  SPI0
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SPI0_CfgPMC( AT91PS_PMC pPMC )
{
	AT91F_PMC_EnablePeripheralClock(
		pPMC, /* PIO controller base address */
		((U32) 1 << AT91C_ID_SPI0));
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SPI0_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
 * \brief Configure PIO controllers to drive SPI0 signals
 * \param pPIOA pointer to PIOA controller
 * \param pPIOB pointer to PIOB controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SPI0_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
{
	/* Configure PIO controllers to periph mode */
	AT91F_PIO_CfgPeripheral(
		pPIOA, /* PIO controller base address */
		((U32) AT91C_PA17_SPI0_MOSI) |
		((U32) AT91C_PA12_SPI0_NPCS0) |
		((U32) AT91C_PA13_SPI0_NPCS1) |
		((U32) AT91C_PA16_SPI0_MISO) |
		((U32) AT91C_PA14_SPI0_NPCS2) |
		((U32) AT91C_PA18_SPI0_SPCK) |
		((U32) AT91C_PA15_SPI0_NPCS3), /* Peripheral A */
		((U32) AT91C_PA7_SPI0_NPCS1) |
		((U32) AT91C_PA8_SPI0_NPCS2) |
		((U32) AT91C_PA9_SPI0_NPCS3)); /* Peripheral B */
	/* Configure PIO controllers to periph mode */
	AT91F_PIO_CfgPeripheral(
		pPIOB, /* PIO controller base address */
		0, /* Peripheral A */
		((U32) AT91C_PB13_SPI0_NPCS1) |
		((U32) AT91C_PB14_SPI0_NPCS2) |
		((U32) AT91C_PB17_SPI0_NPCS3)); /* Peripheral B */
}

/*!************************************************************************
 * \fn void AT91F_SPI_WriteCommand(AT91PS_SPI pSPI, U32 data, U8 channel )
 * \param pSPI pointer to SPI controller
 * \param data Data to be sent to the LCD Driver
 * \param channel channel numner ( 0 .. 3 )
 * \brief   Sends a commands to the LCD driver
 *************************************************************************/
void AT91F_SPI_WriteCommand(AT91PS_SPI pSPI, U32 data, U8 channel )
{
	/* setup data as command */
	data = (data & ~0x0100);

	/* Wait for the transmission to complete */
	while ( AT91F_SPI_IsStatusMasked( pSPI, AT91C_SPI_TXEMPTY) == 0 );

	AT91F_SPI_PutChar( pSPI, data, channel );
}

/*!************************************************************************
 * \fn void AT91F_SPI_WriteData(AT91PS_SPI pSPI, U32 data, U8 channel )
 * \param pSPI pointer to SPI controller
 * \param data Data to be sent to the LCD Driver
 * \param channel channel numner ( 0 .. 3 )
 * \brief Sends data to the LCD driver
 *************************************************************************/
void AT91F_SPI_WriteData(AT91PS_SPI pSPI, U32 data, U8 channel )
{
	/* setup data as data */
	data = (data | 0x0100);

	/* Wait for the transmission to complete */
	while ( AT91F_SPI_IsStatusMasked( pSPI, AT91C_SPI_TXEMPTY) == 0 );

	AT91F_SPI_PutChar( pSPI, data, channel );
}



/*!************************************************************************
 * \fn HRESULT AT91F_SPI_ReadData(AT91PS_SPI pSPI, U8 * pData, U32 nDataSize, U8 channel )
 * \param pSPI pointer to SPI controller
 * \param data Data to be sent to the LCD Driver
 * \param channel channel numner ( 0 .. 3 )
 * \brief Sends data to the LCD driver
 *************************************************************************/
HRESULT AT91F_SPI_ReadData( AT91PS_SPI pSPI, U8 * pData, U32 nDataSize, U8 channel )
{
	HRESULT hResult = S_OK;
	volatile U32 nTimeout;

	if ( pData == NULL )
	{
		hResult = S_INVALID_ARGUMENT;
	} else {
		while ( nDataSize > 0 )
		{
			nTimeout = 1000000;
//			while ( ( (pSPI->SPI_SR & AT91C_SPI_RDRF) == 0 ) && ( -- nTimeout != 0 ) );
			while (  ((pSPI->SPI_SR & AT91C_SPI_RDRF) == 0) && ((pSPI->SPI_SR & AT91C_SPI_RXBUFF) == 0)  );

			if ( nTimeout == 0 )
			{
				hResult = S_TIMEOUT;
				break;
			} else {
				*pData = AT91F_SPI_GetChar( pSPI );
				pData ++;
				nDataSize --;
			}
		}
	}
	return hResult;
}



/*!************************************************************************
 * \fn HRESULT AT91F_SPI_Init( U8 nUnitId )
 * \return status of SPI intialization
 * \brief Sends data over SPI interface
 * additional configuration needed like the one bellow :
 * 	  AT91F_SPI_CfgMode( AT91C_BASE_SPI0, 0xE0019 ); // Master mode, fixed select, disable decoder, FDIV=1 (MCK), PCS=1110
 *    AT91F_SPI_CfgCs( AT91C_BASE_SPI0, 0, 0x01010211 ); // 9bit, CPOL=1, ClockPhase=0, SCLK = 48Mhz/(32*2) = 750kHz
 *************************************************************************/
HRESULT AT91F_SPI_Init( U8 nUnitId )
{
	HRESULT hResult = S_OK;
	AT91PS_SPI pSPI = AT91F_SPI_GetPeripheralAddress( nUnitId );
	
	if ( pSPI == NULL )
	{
		hResult = S_INVALID_ARGUMENT;
	} else {

		/* enable the clock of SPI */
		switch ( nUnitId )
		{
			case 0 :
				AT91F_SPI0_CfgPMC( AT91C_BASE_PMC );
				break;
			case 1 :
				AT91F_SPI1_CfgPMC( AT91C_BASE_PMC );
				break;
		}

		/* Fixed mode */
		AT91F_SPI_Reset( pSPI );
		AT91F_SPI_Enable( pSPI );

	    /** Abort the Peripheral Data Transfers */
	    AT91F_PDC_Open((AT91PS_PDC) &(pSPI->SPI_RPR));
	}

	return hResult;
}




/*!************************************************************************
 * \fn void * AT91F_SPI_GetPeripheralAddress( U8 nUnitId )
 * \param nUnitId SPI controller ID ( 0, 1, ... )
 * \return address of SPI controller 
 * \brief pointer to SPI peripheral control structure
 *************************************************************************/
void * AT91F_SPI_GetPeripheralAddress( U8 nUnitId )
{
	void * pResult = NULL;

	switch ( nUnitId )
	{
		case 0 :
			pResult = AT91C_BASE_SPI0;
			break;
		case 1 :
			pResult = AT91C_BASE_SPI1;
			break;
		default:
			pResult = NULL;
			break;
	}

	return pResult;
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_PDC AT91F_SPI_PDC_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base PDC peripheral controller address
 * \param u8Controller PDC controller index
 * \return pointer to PDC controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_PDC AT91F_SPI_PDC_GetPeripheralAddress( U8 u8Controller )
{
	AT91PS_PDC pPDC;

	switch ( u8Controller )
	{
		case 0 :
			pPDC = AT91C_BASE_PDC_SPI0;
			break;
		case 1 :
			pPDC = AT91C_BASE_PDC_SPI1;
			break;
		default :
			pPDC = NULL;
			break;
	}

	return pPDC;
}
