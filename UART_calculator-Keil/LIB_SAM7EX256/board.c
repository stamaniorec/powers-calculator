/*
	AT91SAM7X256 - Olimex board definition
*/
#define __BOARD_INSTANCIATE__
#include <board.h>
#include <lib_AT91SAM7_PMC.h>


/*!
 * \fn U32 AT91F_MCU_GetBCLK()
 * \brief Return the base frequency of BCLK
 * return Frequency of BCLK
 */
U32 AT91F_MCU_GetBCLK()
{
 	AT91PS_PMC     pPMC = AT91F_PMC_GetPeripheralAddress( 0 );
 	U32				u32MUL;
 	U32				u32DIV;
 	
 	u32MUL = (pPMC->PMC_PLLR & AT91C_CKGR_MUL) >> 16;
 	u32DIV = (pPMC->PMC_PLLR & AT91C_CKGR_DIV);

	return 18432000L * u32MUL / u32DIV;
}

//AT91PS_AIC		gpAIC = AT91C_BASE_AIC;
//AT91PS_CAN		gpCAN = AT91C_BASE_CAN;
//AT91PS_TCB		gpTCB = AT91C_BASE_TCB;
//AT91PS_PMC		gpPMC = AT91C_BASE_PMC;
//AT91PS_PWMC		gpPWMC = AT91C_BASE_PWMC;
//AT91PS_PIO		gpPIOA = AT91C_BASE_PIOA;
//AT91PS_PIO		gpPIOB = AT91C_BASE_PIOB;
//AT91PS_USART	gpUSART0 = AT91C_BASE_US0;
//AT91PS_USART	gpUSART1 = AT91C_BASE_US1;
//AT91PS_PDC		gpPDC_US0   = AT91C_BASE_PDC_US0;
//AT91PS_PDC		gpPDC_US1   = AT91C_BASE_PDC_US1;
//AT91PS_PDC		gpPDC_SPI0    = AT91C_BASE_PDC_SPI0;
//AT91PS_MC		gpMC     = AT91C_BASE_MC;
//AT91PS_ADC		gpADC = AT91C_BASE_ADC;
//AT91PS_SPI		gpSPI    = AT91C_BASE_SPI0;
//AT91PS_TC		gpTC0    = AT91C_BASE_TC0;


//AT91PS_AIC		AIC_GetAddress(U8 u8Channel)
//{
//	return AT91C_BASE_AIC;
//}

//AT91PS_CAN		CAN_GetAddress( U8 u8Channel )
//{
//	return AT91C_BASE_CAN;
//}

//AT91PS_TCB		TCB_GetAddress( U8 u8Channel )
//{
//	return AT91C_BASE_TCB;
//}

//AT91PS_PMC		PMC_GetAddress( U8 u8Channel )
//{
//	return AT91C_BASE_PMC;
//}

//AT91PS_PWMC		PWMC_GetAddress( U8 u8Channel )
//{
//	return AT91C_BASE_PWMC;
//}

//AT91PS_PIO		PIO_GetAddress( U8 u8Channel )
//{
//	AT91PS_PIO pPIO;
//
//	if ( u8Channel == 0 )
//	{
//		pPIO = AT91C_BASE_PIOA;
//	} else {
//		pPIO = AT91C_BASE_PIOA;
//	}
//	return  pPIO;
//}
//
//AT91PS_USART	USART_GetAddress( U8 u8Channel )
//{
//	AT91PS_USART pUSART;
//
//	if ( u8Channel == 0 )
//	{
//		pUSART = AT91C_BASE_US0;
//	} else {
//		pUSART = AT91C_BASE_US1;
//	}
//	return pUSART;
//}
//
//AT91PS_PDC		PDC_US_GetAddress( U8 u8Channel )
//{
//	AT91PS_PDC pPDC;
//
//	if ( u8Channel == 0 )
//	{
//		pPDC = AT91C_BASE_PDC_US0;
//	} else {
//		pPDC = AT91C_BASE_PDC_US1;
//	}
//	return pPDC;
//}
//
//AT91PS_PDC		PDC_SPI_GetAddress( U8 u8Channel )
//{
//	return AT91C_BASE_PDC_SPI0;
//}
//
//AT91PS_MC		MC_GetAddress( U8 u8Channel )
//{
//	return AT91C_BASE_MC;
//}
//
//AT91PS_ADC		ADC_GetAddress( U8 u8Channel )
//{
//	return AT91C_BASE_ADC;
//}

//AT91PS_SPI		SPI_GetAddress( U8 u8Channel )
//{
//	return AT91C_BASE_SPI0;
//}
//
//AT91PS_TC		TC_GetAddress( U8 u8Channel )
//{
//	AT91PS_TC pTC;
//
//	if ( u8Channel == 0 )
//	{
//		pTC = AT91C_BASE_TC0;
//	} else {
//		pTC = AT91C_BASE_TC1;
//	}
//	return pTC;
//}
