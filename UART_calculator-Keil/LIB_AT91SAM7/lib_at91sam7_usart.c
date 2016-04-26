#include "basedef.h"
#include "ioat91sam7x256.h"
#include "lib_AT91SAM7_PMC.h"
#include "lib_AT91SAM7_PIO.h"
#include "lib_AT91SAM7_PDC.h"
#include "lib_AT91SAM7_USART.h"


/*----------------------------------------------------------------------------*/
/*    Standard Asynchronous Mode : 8 bits , 1 stop , no parity */
#define AT91C_US_ASYNC_MODE ( AT91C_US_USMODE_NORMAL + \
                        AT91C_US_NBSTOP_1_BIT + \
                        AT91C_US_PAR_NONE + \
                        AT91C_US_CHRL_8_BITS + \
                        AT91C_US_CLKS_CLOCK )

/*    Standard External Asynchronous Mode : 8 bits , 1 stop , no parity */
#define AT91C_US_ASYNC_SCK_MODE ( AT91C_US_USMODE_NORMAL + \
                            AT91C_US_NBSTOP_1_BIT + \
                            AT91C_US_PAR_NONE + \
                            AT91C_US_CHRL_8_BITS + \
                            AT91C_US_CLKS_EXT )

/*    Standard Synchronous Mode : 8 bits , 1 stop , no parity */
#define AT91C_US_SYNC_MODE ( AT91C_US_SYNC + \
                       AT91C_US_USMODE_NORMAL + \
                       AT91C_US_NBSTOP_1_BIT + \
                       AT91C_US_PAR_NONE + \
                       AT91C_US_CHRL_8_BITS + \
                       AT91C_US_CLKS_CLOCK )

/*    SCK used Label */
#define AT91C_US_SCK_USED (AT91C_US_CKLO | AT91C_US_CLKS_EXT)

/*    Standard ISO T=0 Mode : 8 bits , 1 stop , parity */
#define AT91C_US_ISO_READER_MODE ( AT91C_US_USMODE_ISO7816_0 + \
					   		 AT91C_US_CLKS_CLOCK +\
                       		 AT91C_US_NBSTOP_1_BIT + \
                       		 AT91C_US_PAR_EVEN + \
                       		 AT91C_US_CHRL_8_BITS + \
                       		 AT91C_US_CKLO +\
                       		 AT91C_US_OVER)

/*    Standard IRDA mode */
#define AT91C_US_ASYNC_IRDA_MODE (  AT91C_US_USMODE_IRDA + \
                            AT91C_US_NBSTOP_1_BIT + \
                            AT91C_US_PAR_NONE + \
                            AT91C_US_CHRL_8_BITS + \
                            AT91C_US_CLKS_CLOCK )

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_US_Baudrate( const U32 main_clock, \
 * 											const U32 baud_rate)
 * \brief Caluculate baud_value according to the main clock and the baud rate
 * \param main_clock peripheral clock
 * \param baud_rate UART baudrate
 * \return computed baudrate
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_US_Baudrate (
	const U32 main_clock, /* \arg peripheral clock */
	const U32 baud_rate)  /* \arg UART baudrate */
{
	U32 baud_value = ((main_clock*10)/(baud_rate * 16));
	if ((baud_value % 10) >= 5)
		baud_value = (baud_value / 10) + 1;
	else
		baud_value /= 10;
	return baud_value;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US_SetBaudrate( AT91PS_USART pUSART, \
 * 								U32 mainClock, \
 * 								U32 speed)
 * \brief Set the baudrate according to the CPU clock
 * \param pUSART pointer to a USART controller
 * \param mainClock peripheral clock in Hz
 * \param speed UART baudrate
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US_SetBaudrate (
	AT91PS_USART pUSART,    /* \arg pointer to a USART controller */
	U32 mainClock, /* \arg peripheral clock */
	U32 speed)     /* \arg UART baudrate */
{
	/*    Define the baud rate divisor register */
	pUSART->US_BRGR = AT91F_US_Baudrate(mainClock, speed);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US_SetTimeguard( AT91PS_USART pUSART, \
 * 								U32 timeguard)
 * \brief Set USART timeguard
 * \param pUSART pointer to a USART controller
 * \param timeguard timeguard value
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US_SetTimeguard (
	AT91PS_USART pUSART,    /* \arg pointer to a USART controller */
	U32 timeguard) /* \arg timeguard value */
{
	/*    Write the Timeguard Register */
	pUSART->US_TTGR = timeguard;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US_EnableInterrupt( AT91PS_USART pUSART, \
 * 								U32 flag)
 * \brief Enable USART interrupt
 * \param pUSART pointer to a USART controller
 * \param flag nterrupt to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US_EnableInterrupt (
	AT91PS_USART pUSART, /* \arg pointer to a USART controller */
	U32 flag)   /* \arg interrupt to be enabled */
{
	/*    Write to the IER register */
	pUSART->US_IER = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US_DisableInterrupt( AT91PS_USART pUSART, \
 * 								U32 flag)
 * \brief Disable USART interrupt
 * \param pUSART pointer to a USART controller
 * \param flag nterrupt to be disabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US_DisableInterrupt (
	AT91PS_USART pUSART, /* \arg pointer to a USART controller */
	U32 flag)   /* \arg interrupt to be disabled */
{
	/*    Write to the IER register */
	pUSART->US_IDR = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US_Configure( AT91PS_USART pUSART, \
 * 								U32 mainClock, \
 * 								U32 mode, \
 * 								U32 baudRate, \
 * 								U32 timeguard)
 * \brief Configure USART
 * \param pUSART pointer to a USART controller
 * \param mainClock peripheral clock
 * \param mode mode Register to be programmed
 * \param baudRate baudrate to be programmed
 * \param timeguard timeguard to be programmed
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US_Configure (
	AT91PS_USART pUSART,     /* \arg pointer to a USART controller */
	U32 mainClock,  /* \arg peripheral clock */
	U32 mode ,      /* \arg mode Register to be programmed */
	U32 baudRate ,  /* \arg baudrate to be programmed */
	U32 timeguard ) /* \arg timeguard to be programmed */
{
    /*    Disable interrupts */
    pUSART->US_IDR = (U32) -1;

    /*    Reset receiver and transmitter */
    pUSART->US_CR = AT91C_US_RSTRX | AT91C_US_RSTTX | AT91C_US_RXDIS | AT91C_US_TXDIS;

	/*    Define the baud rate divisor register */
	AT91F_US_SetBaudrate(pUSART, mainClock, baudRate);

	/*    Write the Timeguard Register */
	AT91F_US_SetTimeguard(pUSART, timeguard);

    /*    Clear Transmit and Receive Counters */ 
    AT91F_PDC_Open((AT91PS_PDC) &(pUSART->US_RPR));

    /*    Define the USART mode */
    pUSART->US_MR = mode;

}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US_EnableRx( AT91PS_USART pUSART )
 * \brief Enable receiving characters
 * \param pUSART pointer to a USART controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US_EnableRx(AT91PS_USART pUSART)     /* \arg pointer to a USART controller */
{
    /*    Enable receiver */
    pUSART->US_CR = AT91C_US_RXEN;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US_EnableTx( AT91PS_USART pUSART )
 * \brief Enable sending characters
 * \param pUSART pointer to a USART controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US_EnableTx(AT91PS_USART pUSART)     /* \arg pointer to a USART controller */
{
    /*    Enable  transmitter */
    pUSART->US_CR = AT91C_US_TXEN;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US_ResetRx( AT91PS_USART pUSART )
 * \brief Reset Receiver and re-enable it
 * \param pUSART pointer to a USART controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US_ResetRx(AT91PS_USART pUSART)     /* \arg pointer to a USART controller */
{
	/*    Reset receiver */
	pUSART->US_CR = AT91C_US_RSTRX;
    /*    Re-Enable receiver */
    pUSART->US_CR = AT91C_US_RXEN;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US_ResetTx( AT91PS_USART pUSART )
 * \brief Reset Transmitter and re-enable it
 * \param pUSART pointer to a USART controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US_ResetTx(AT91PS_USART pUSART)     /* \arg pointer to a USART controller */
{
	/*    Reset transmitter */
	pUSART->US_CR = AT91C_US_RSTTX;
    /*    Enable transmitter */
    pUSART->US_CR = AT91C_US_TXEN;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US_DisableRx( AT91PS_USART pUSART )
 * \brief Disable Receiver
 * \param pUSART pointer to a USART controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US_DisableRx(AT91PS_USART pUSART)     /* \arg pointer to a USART controller */
{
    /*    Disable receiver */
    pUSART->US_CR = AT91C_US_RXDIS;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US_DisableTx( AT91PS_USART pUSART )
 * \brief Disable Transmitter
 * \param pUSART pointer to a USART controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US_DisableTx(AT91PS_USART pUSART)     /* \arg pointer to a USART controller */
{
    /*    Disable transmitter */
    pUSART->US_CR = AT91C_US_TXDIS;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US_Close( AT91PS_USART pUSART )
 * \brief Close USART: disable IT disable receiver and transmitter, close PDC
 * \param pUSART pointer to a USART controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US_Close(AT91PS_USART pUSART)     /* \arg pointer to a USART controller */
{
    /*    Reset the baud rate divisor register */
    pUSART->US_BRGR = 0 ;

    /*    Reset the USART mode */
    pUSART->US_MR = 0;

    /*    Reset the Timeguard Register */
    pUSART->US_TTGR = 0;

    /*    Disable all interrupts */
    pUSART->US_IDR = 0xFFFFFFFF;

    /*    Abort the Peripheral Data Transfers */
    AT91F_PDC_Close((AT91PS_PDC) &(pUSART->US_RPR));

    /*    Disable receiver and transmitter and stop any activity immediately */
    pUSART->US_CR = AT91C_US_TXDIS | AT91C_US_RXDIS | AT91C_US_RSTTX | AT91C_US_RSTRX ;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_US_TxReady( AT91PS_USART pUSART )
 * \brief Return 1 if a character can be written in US_THR
 * \param pUSART pointer to a USART controller
 * \return transmit ready channel status
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_US_TxReady(AT91PS_USART pUSART )     /* \arg pointer to a USART controller */
{
    return (pUSART->US_CSR & AT91C_US_TXRDY);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_US_RxReady( AT91PS_USART pUSART )
 * \brief Return 1 if a character can be read in US_RHR
 * \param pUSART pointer to a USART controller
 * \return receive ready channel status
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_US_RxReady(AT91PS_USART pUSART )     /* \arg pointer to a USART controller */
{
    return (pUSART->US_CSR & AT91C_US_RXRDY);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_US_Error( AT91PS_USART pUSART )
 * \brief Return the error flag
 * \param pUSART pointer to a USART controller
 * \return error channel status
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_US_Error(AT91PS_USART pUSART )     /* \arg pointer to a USART controller */
{
    return (pUSART->US_CSR &
    	(AT91C_US_OVRE |  /* Overrun error */
    	 AT91C_US_FRAME | /* Framing error */
    	 AT91C_US_PARE));  /* Parity error */
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US_PutChar( AT91PS_USART pUSART, \
 * 								U32 character )
 * \brief Send a character,does not check if ready to send
 * \param pUSART pointer to a USART controller
 * \param character character to be transferred
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US_PutChar (
	AT91PS_USART pUSART,
	U32 character )
{
    pUSART->US_THR = (character & 0x1FF);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_US_GetChar( AT91PS_USART pUSART )
 * \brief Receive a character, does not check if a character is available
 * \param pUSART pointer to a USART controller
 * \return character held in receiver holding register
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_US_GetChar (
	const AT91PS_USART pUSART)
{
    return((pUSART->US_RHR) & 0x1FF);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_US_SendFrame( AT91PS_USART pUSART, \
 * 								S8 *pBuffer, \
 * 								U32 szBuffer, \
 * 								S8 *pNextBuffer, \
 * 								U32 szNextBuffer )
 * \brief Request two frames to be queued for transmittion
 * \param pUSART pointer to a USART controller
 * \param pBuffer pointer to transmition buffer
 * \param szBuffer size of the transmition buffer
 * \param pNextBuffer pointer to next transmition buffer
 * \param szNextBuffer size of the next transmition buffer
 * \return 2 if the two buffers are prepared for sending, \n 1 if only next buffer if prepared for sending, \n 0 if buffers are busy
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_US_SendFrame(
	AT91PS_USART pUSART,
	S8 *pBuffer,
	U32 szBuffer,
	S8 *pNextBuffer,
	U32 szNextBuffer )
{
	return AT91F_PDC_SendFrame(
		(AT91PS_PDC) &(pUSART->US_RPR),
		pBuffer,
		szBuffer,
		pNextBuffer,
		szNextBuffer);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_US_ReceiveFrame( AT91PS_USART pUSART, \
 * 								S8 *pBuffer, \
 * 								U32 szBuffer, \
 * 								S8 *pNextBuffer, \
 * 								U32 szNextBuffer )
 * \brief Request to queue two frames for receiving
 * \param pUSART pointer to a USART controller
 * \param pBuffer pointer to receiving buffer
 * \param szBuffer size of the receiving buffer
 * \param pNextBuffer pointer to next receiving buffer
 * \param szNextBuffer size of the next receiving buffer
 * \return 2 if the two buffers are prepared for receiving, \n 1 if only next buffer if prepared for receiving, \n 0 if buffers are busy
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_US_ReceiveFrame (
	AT91PS_USART pUSART,
	S8 *pBuffer,
	U32 szBuffer,
	S8 *pNextBuffer,
	U32 szNextBuffer )
{
	return AT91F_PDC_ReceiveFrame(
		(AT91PS_PDC) &(pUSART->US_RPR),
		pBuffer,
		szBuffer,
		pNextBuffer,
		szNextBuffer);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US_SetIrdaFilter( AT91PS_USART pUSART, \
 * 								U8 value )
 * \brief Set the value of IrDa filter tregister
 * \param pUSART pointer to a USART controller
 * \param value IRDA filter mask value
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US_SetIrdaFilter (
	AT91PS_USART pUSART,
	U8 value
)
{
	pUSART->US_IF = value;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US1_CfgPMC( AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  US1
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US1_CfgPMC(AT91PS_PMC pPMC)
{
	AT91F_PMC_EnablePeripheralClock(
		pPMC, /* PIO controller base address */
		((U32) 1 << AT91C_ID_US1));
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US1_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
 * \brief Configure PIO controllers to drive US1 signals
 * \param pPIOA pointer to PIOA controller
 * \param pPIOB pointer to PIOB controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US1_CfgPIO(AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
{
	/* Configure PIO controllers to periph mode */
	AT91F_PIO_CfgPeripheral(
		pPIOA, /* PIO controller base address */
		((U32) AT91C_PA5_RXD1    ) |
		((U32) AT91C_PA6_TXD1    ) |
		((U32) AT91C_PA8_RTS1    ) |
		((U32) AT91C_PA7_SCK1    ) |
		((U32) AT91C_PA9_CTS1    ), /* Peripheral A */
		0); /* Peripheral B */
	/* Configure PIO controllers to periph mode */
	AT91F_PIO_CfgPeripheral(
		pPIOB, /* PIO controller base address */
		0, /* Peripheral A */
		((U32) AT91C_PB25_DTR1    ) |
		((U32) AT91C_PB23_DCD1    ) |
		((U32) AT91C_PB24_DSR1    ) |
		((U32) AT91C_PB26_RI1     )); /* Peripheral B */
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US0_CfgPMC( AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  US0
 * \param pPMC pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US0_CfgPMC( AT91PS_PMC pPMC )
{
	AT91F_PMC_EnablePeripheralClock(
		pPMC, /* PIO controller base address */
		((U32) 1 << AT91C_ID_US0));
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_US0_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
 * \brief Configure PIO controllers to drive US0 signals
 * \param pPIOA pointer to PIOA controller
 * \param pPIOB pointer to PIOB controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_US0_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
{
	/* Configure PIO controllers to periph mode */
	AT91F_PIO_CfgPeripheral(
		pPIOA, /* PIO controller base address */
		((U32) AT91C_PA0_RXD0    ) |
		((U32) AT91C_PA1_TXD0    ) |
		((U32) AT91C_PA3_RTS0    ) |
		((U32) AT91C_PA2_SCK0    ) |
		((U32) AT91C_PA4_CTS0    ), /* Peripheral A */
		0); /* Peripheral B */
}



/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_PDC AT91F_USART_PDC_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base PDC peripheral controller address
 * \param u8Controller PDC controller index
 * \return pointer to PDC controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_PDC AT91F_USART_PDC_GetPeripheralAddress( U8 u8Controller )
{
	AT91PS_PDC pPDC;
	switch ( u8Controller )
	{
	case 0 :
		pPDC = AT91C_BASE_PDC_US0;
		break;
	case 1 :
		pPDC = AT91C_BASE_PDC_US0;
		break;
	default:
		pPDC = NULL;
		break;
	}
	return pPDC;
}

/*----------------------------------------------------------------------------*/
/*! \fn   __inline AT91PS_USART AT91F_USART_GetChannelAddress( U8 u8Channel )
 * \brief Returns USART channel address
 * \param u8Channel USART channel index
 * \return pointer to USART controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_USART AT91F_USART_GetChannelAddress( U8 u8Channel )
{
	AT91PS_USART pUSART;
	switch ( u8Channel )
	{
	case 0 :
		pUSART = AT91C_BASE_US0;
		break;
	case 1 :
		pUSART = AT91C_BASE_US1;
		break;
	default:
		pUSART = NULL;
		break;
	}
	return pUSART;
}
