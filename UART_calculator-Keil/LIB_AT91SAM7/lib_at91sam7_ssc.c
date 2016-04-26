#include "basedef.h"
#include "ioat91sam7x256.h"
#include "lib_AT91SAM7_PMC.h"
#include "lib_AT91SAM7_PIO.h"
#include "lib_AT91SAM7_PDC.h"
#include "lib_AT91SAM7_SSC.h"

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SSC_Configure(	AT91PS_SSC pSSC, \
 * 							U32 syst_clock, \
 * 							U32 baud_rate, \
 * 							U32 clock_rx, \
 * 							U32 mode_rx, \
 * 							U32 clock_tx, \
 * 							U32 mode_tx)
 * \brief Configure SSC
 * \param pSSC pointer to a SSC controller
 * \param syst_clock System Clock Frequency
 * \param baud_rate Expected Baud Rate Frequency
 * \param clock_rx Receiver Clock Parameters
 * \param mode_rx mode Register to be programmed
 * \param clock_tx Transmitter Clock Parameters
 * \param mode_tx mode Register to be programmed
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SSC_Configure(
             AT91PS_SSC pSSC,          /* \arg pointer to a SSC controller */
             U32 syst_clock,  /* \arg System Clock Frequency */
             U32 baud_rate,   /* \arg Expected Baud Rate Frequency */
             U32 clock_rx,    /* \arg Receiver Clock Parameters */
             U32 mode_rx,     /* \arg mode Register to be programmed */
             U32 clock_tx,    /* \arg Transmitter Clock Parameters */
             U32 mode_tx)     /* \arg mode Register to be programmed */
{
    /** Disable interrupts */
	pSSC->SSC_IDR = (U32) -1;

    /** Reset receiver and transmitter */
	pSSC->SSC_CR = AT91C_SSC_SWRST | AT91C_SSC_RXDIS | AT91C_SSC_TXDIS ;

    /** Define the Clock Mode Register */
	AT91F_SSC_SetBaudrate(pSSC, syst_clock, baud_rate);

     /** Write the Receive Clock Mode Register */
	pSSC->SSC_RCMR =  clock_rx;

     /** Write the Transmit Clock Mode Register */
	pSSC->SSC_TCMR =  clock_tx;

     /** Write the Receive Frame Mode Register */
	pSSC->SSC_RFMR =  mode_rx;

     /** Write the Transmit Frame Mode Register */
	pSSC->SSC_TFMR =  mode_tx;

    /** Clear Transmit and Receive Counters */
	AT91F_PDC_Open((AT91PS_PDC) &(pSSC->SSC_RPR));


}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SSC_CfgPMC( AT91PS_PMC pPMC )
 * \brief Enable Peripheral clock in PMC for  SSC
 * \param pointer to PMC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SSC_CfgPMC( AT91PS_PMC pPMC )
{
	AT91F_PMC_EnablePeripheralClock(
		pPMC, /* PIO controller base address */
		((U32) 1 << AT91C_ID_SSC));
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SSC_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
 * \brief Configure PIO controllers to drive SSC signals
 * \param pPIOA pointer to PIOA controller
 * \param pPIOB pointer to PIOB controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SSC_CfgPIO( AT91PS_PIO pPIOA, AT91PS_PIO pPIOB )
{
	/* Configure PIO controllers to periph mode */
	AT91F_PIO_CfgPeripheral(
		pPIOA, /* PIO controller base address */
		((U32) AT91C_PA23_TD      ) |
		((U32) AT91C_PA21_TF      ) |
		((U32) AT91C_PA25_RK      ) |
		((U32) AT91C_PA24_RD      ) |
		((U32) AT91C_PA26_RF      ) |
		((U32) AT91C_PA22_TK      ), /* Peripheral A */
		0); /* Peripheral B */
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_SSC_ReceiveFrame( AT91PS_SSC pSSC, \
 * 								S8 *pBuffer, \
 * 								U32 szBuffer, \
 * 								S8 *pNextBuffer, \
 * 								U32 szNextBuffer )
 * \brief Request to queue two frames for receiving
 * \param pSSC pointer to a SSC controller
 * \param pBuffer pointer to receiving buffer
 * \param szBuffer size of the receiving buffer
 * \param pNextBuffer pointer to next receiving buffer
 * \param szNextBuffer size of the next receiving buffer
 * \return 2 if the two buffers are prepared for sending, \n 1 if only next buffer if prepared for sending, \n 0 if buffers are busy
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_SSC_ReceiveFrame(
	AT91PS_SSC pSSC,
	S8 *pBuffer,
	U32 szBuffer,
	S8 *pNextBuffer,
	U32 szNextBuffer )
{
	return AT91F_PDC_ReceiveFrame(
		(AT91PS_PDC) &(pSSC->SSC_RPR),
		pBuffer,
		szBuffer,
		pNextBuffer,
		szNextBuffer);
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_SSC_SendFrame( AT91PS_SSC pSSC, \
 * 								S8 *pBuffer, \
 * 								U32 szBuffer, \
 * 								S8 *pNextBuffer, \
 * 								U32 szNextBuffer )
 * \brief Request two frames to be queued for transmittion
 * \param pSSC pointer to a SSC controller
 * \param pBuffer pointer to transmition buffer
 * \param szBuffer size of the transmition buffer
 * \param pNextBuffer pointer to next transmition buffer
 * \param szNextBuffer size of the next transmition buffer
 * \return 2 if the two buffers are prepared for sending, \n 1 if only next buffer if prepared for sending, \n 0 if buffers are busy
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_SSC_SendFrame(
	AT91PS_SSC pSSC,
	S8 *pBuffer,
	U32 szBuffer,
	S8 *pNextBuffer,
	U32 szNextBuffer )
{
	return AT91F_PDC_SendFrame(
		(AT91PS_PDC) &(pSSC->SSC_RPR),
		pBuffer,
		szBuffer,
		pNextBuffer,
		szNextBuffer);
}


/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SSC_SetBaudrate(	AT91PS_SSC pSSC, \
 * 									U32 mainClock, \
 * 									U32 speed)
 * \brief Set the baudrate according to the CPU clock
 * \param pSSC pointer to a SSC controller
 * \param mainClock peripheral clock
 * \param speed SSC baudrate
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SSC_SetBaudrate(
        AT91PS_SSC pSSC,        /* \arg pointer to a SSC controller */
        U32 mainClock, /* \arg peripheral clock */
        U32 speed)     /* \arg SSC baudrate */
{
        U32 baud_value;
        /** Define the baud rate divisor register */
        if (speed == 0)
           baud_value = 0;
        else
        {
           baud_value = (U32) (mainClock * 10)/(2*speed);
           if ((baud_value % 10) >= 5)
                  baud_value = (baud_value / 10) + 1;
           else
                  baud_value /= 10;
        }

        pSSC->SSC_CMR = baud_value;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SSC_EnableRx( AT91PS_SSC pSSC )
 * \brief Enable receiving datas
 * \param pSSC pointer to a SSC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SSC_EnableRx(
	AT91PS_SSC pSSC)     /* \arg pointer to a SSC controller */
{
    /** Enable receiver */
    pSSC->SSC_CR = AT91C_SSC_RXEN;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SSC_DisableRx( AT91PS_SSC pSSC )
 * \brief Disable receiving datas
 * \param pSSC pointer to a SSC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SSC_DisableRx(
	AT91PS_SSC pSSC)     /* \arg pointer to a SSC controller */
{
    /** Disable receiver */
    pSSC->SSC_CR = AT91C_SSC_RXDIS;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SSC_EnableTx( AT91PS_SSC pSSC )
 * \brief Enable sending datas
 * \param pSSC pointer to a SSC controller
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SSC_EnableTx(
	AT91PS_SSC pSSC)     /* \arg pointer to a SSC controller */
{
    /** Enable  transmitter */
    pSSC->SSC_CR = AT91C_SSC_TXEN;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SSC_DisableTx( AT91PS_SSC pSSC )
 * \brief Disable sending datas
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SSC_DisableTx(
	AT91PS_SSC pSSC)     /* \arg pointer to a SSC controller */
{
    /** Disable  transmitter */
    pSSC->SSC_CR = AT91C_SSC_TXDIS;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SSC_EnableInterrupt( AT91PS_SSC pSSC, \
 * 						U32 flag)
 * \brief Enable SSC interrupt
 * \param pSSC pointer to a SSC controller
 * \param flag interrupt to be enabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SSC_EnableInterrupt(
	AT91PS_SSC pSSC, /* \arg pointer to a SSC controller */
	U32 flag)   /* \arg interrupt to be enabled */
{
	/** Write to the IER register */
	pSSC->SSC_IER = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline void AT91F_SSC_DisableInterrupt( AT91PS_SSC pSSC, \
 * 						U32 flag)
 * \brief Disable SSC interrupt
 * \param pSSC pointer to a SSC controller
 * \param flag interrupt to be disabled
 */
/*----------------------------------------------------------------------------*/
__inline void AT91F_SSC_DisableInterrupt(
	AT91PS_SSC pSSC, /* \arg pointer to a SSC controller */
	U32 flag)   /* \arg interrupt to be disabled */
{
	/** Write to the IDR register */
	pSSC->SSC_IDR = flag;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline U32 AT91F_SSC_GetInterruptMaskStatus( AT91PS_SSC pSSC )
 * \brief Return SSC Interrupt Mask Status
 * \param pSSC pointer to a SSC controller
 * \return interrupt mask register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_SSC_GetInterruptMaskStatus( /* \return SSC Interrupt Mask Status */
        AT91PS_SSC pSSC) /* \arg  pointer to a SSC controller */
{
        return pSSC->SSC_IMR;
}

/*----------------------------------------------------------------------------*/
/*! \fn    AT91F_SSC_IsInterruptMasked( AT91PS_SSC pSSC, \
 * 						U32 flag)
 * \brief Test if SSC Interrupt is Masked
 * \param pSSC pointer to a SSC controller
 * \param flag flag to be tested
 * \return masked interrupt mask register value
 */
/*----------------------------------------------------------------------------*/
__inline U32 AT91F_SSC_IsInterruptMasked(
        AT91PS_SSC pSSC,   /* \arg  pointer to a SSC controller */
        U32 flag) /* \arg  flag to be tested */
{
        return (AT91F_SSC_GetInterruptMaskStatus(pSSC) & flag);
}



/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_PDC AT91F_SSC_PDC_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base PDC peripheral controller address
 * \param u8Controller PDC controller index
 * \return pointer to PDC controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_PDC AT91F_SSC_PDC_GetPeripheralAddress( U8 u8Controller )
{
	return AT91C_BASE_PDC_SSC;
}

/*----------------------------------------------------------------------------*/
/*! \fn    __inline AT91PS_SSC AT91F_SSC_GetPeripheralAddress( U8 u8Controller )
 * \brief Returns base SSC peripheral controller address
 * \param u8Controller SSC controller index
 * \return pointer to SSC controller
 */
/*----------------------------------------------------------------------------*/
__inline AT91PS_SSC AT91F_SSC_GetPeripheralAddress( U8 u8Controller )
{
	return AT91C_BASE_SSC;
}
