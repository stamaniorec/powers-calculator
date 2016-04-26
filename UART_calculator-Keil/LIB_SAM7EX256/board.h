/*----------------------------------------------------------------------------
*         ATMEL Microcontroller Software Support  -  ROUSSET  -
*----------------------------------------------------------------------------
* The software is delivered "AS IS" without warranty or condition of any
* kind, either express, implied or statutory. This includes without
* limitation any warranty or condition with respect to merchantability or
* fitness for any particular purpose, or against the infringements of
* intellectual property rights of others.
*----------------------------------------------------------------------------
* File Name           : Board.h
* Object              : AT91SAM7S Evaluation Board Features Definition File.
*
* Creation            : JPP   16/Jun/2004
* AT91SAM7X256 update : Dimitar Peikov 9/Apr/2007
* 	- add : new definitions added
*   - check : checked
*----------------------------------------------------------------------------
*/
#ifndef Board_h
#define Board_h

#include <basedef.h>
#include <ioat91sam7x256.h>

#ifndef __inline
#define __inline inline
#endif

/*!
 * \fn U32 AT91F_MCU_GetBCLK()
 * \brief Return the base frequency of BCLK
 * return Frequency of BCLK
 */
U32 AT91F_MCU_GetBCLK(void);

//  *******************************************************
//                External References
//  *******************************************************
extern	void AT91F_LowLevel_Init(void);
extern	void AT91F_Finalize_Init(void);

/*-------------------------------*/
/* SAM7Board Memories Definition */
/*-------------------------------*/
/* The AT91SAM7S64 embeds a 16-Kbyte SRAM bank, and 64 K-Byte Flash */
/* The AT91SAM7X256 embeds a 64-Kbyte SRAM bank, and 256 K-Byte Flash */

#define  INT_SARM           0x00200000
#define  INT_SARM_REMAP	    0x00000000

#define  INT_FLASH          0x00100000
#define  INT_FLASH_REMAP    0x00010000

#define  FLASH_PAGE_NB		1024
#define  FLASH_PAGE_SIZE	256

/* Dimitar Peikov - not used anymore */
/*---------------------*/
/* LCD GPIO Definition */
/*---------------------*/
/*                                 PIO		PIN */
#define LCD_CS			(1<<12)	/* PIOA		20 */
#define LCD_MISO		(1<<16)	/* PIOA		24 */
#define LCD_MOSI		(1<<17)	/* PIOA		25 */
#define LCD_SPCK		(1<<18)	/* PIOA		26 */

#define LCD_GPIO_MASK	( LCD_CS | LCD_MISO | LCD_MOSI | LCD_SPCK )

/*-------------------------*/
/* Push Buttons Definition */
/*-------------------------*/
/*                                 PIO    Flash    PA    PB   PIN */
#define SW1_MASK        (1<<19)	/* PA19 / PGMD7  & RK   FIQ     13 */
#define SW2_MASK        (1<<20)	/* PA20 / PGMD8  & RF   IRQ0    16 */
#define SW3_MASK        (1<<15)	/* PA15 / PGM3   & TF   TIOA1   20 */
#define SW4_MASK        (1<<14)	/* PA14 / PGMD2  & SPCK PWM3    21 */
#define SW_MASK         (SW1_MASK|SW2_MASK|SW3_MASK|SW4_MASK)


#define SW1 	(1<<19)	// PA19
#define SW2 	(1<<20)	// PA20
#define SW3 	(1<<15)	// PA15
#define SW4 	(1<<14)	// PA14


/*                                 			PIO		PIN */
// B1
#define PUSH_BUTTON_1			(1<<7)	/* PIOA		91 */
// B2
#define PUSH_BUTTON_2			(1<<8)	/* PIOA		13 */
// B3
#define PUSH_BUTTON_3			(1<<9)	/* PIOA		14 */
// B4
#define PUSH_BUTTON_4			(1<<14)	/* PIOA		22 */
// B5
#define PUSH_BUTTON_5			(1<<15)	/* PIOA		23 */



/*------------------*/
/* USART Definition */
/*------------------*/
/* SUB-D 9 points J3 DBGU*/
#define DBGU_RXD		AT91C_PA9_DRXD	  /* JP11 must be close */
#define DBGU_TXD		AT91C_PA10_DTXD	  /* JP12 must be close */
#define AT91C_DBGU_BAUD	   115200   // Baud rate

#define US_RXD_PIN		AT91C_PA5_RXD0    /* JP9 must be close */
#define US_TXD_PIN		AT91C_PA6_TXD0    /* JP7 must be close */
#define US_RTS_PIN		AT91C_PA7_RTS0    /* JP8 must be close */
#define US_CTS_PIN		AT91C_PA8_CTS0    /* JP6 must be close */


/*------------------*/
/*  ADC Definition  */
/*------------------*/
/* Analog Termometer */
#define AN_TERMOMETER		5
/* Analog Trimer */
#define AN_TRIMMER			6
/* Microphone IN */
#define AN_MICROPHONE		7


/* Dimitar Peikov - check */
/*--------------*/
/* Master Clock */
/*--------------*/
#define EXT_OC          18432000L   // Exetrnal ocilator MAINCK
#define MCK             48054841L   // MCK = (EXT_OC / 14 * (72 + 1))
#define MCKKHz          (MCK/1000) //

/* Dimitar Peikov - add */
/*----------------*/
/*       LCD      */
/*----------------*/
#define LCD_BACKLIGHT_AS_GPIO 			0
//#define LCD_BACKLIGHT_AS_PWM  				1

/*                                 							PIO		PIN */
#define LCD_BACKLIGHT_PIN 					(1 << 20)	/*	PIOB	20  */
#define LCD_BACKLIGHT_AS_PWM_CHANNEL		AT91C_PWMC_CHID1
#define LCD_BACKLIGHT_AS_PWM_CHANNEL_BASE	AT91C_BASE_PWMC_CH1


/* Dimitar Peikov - added */
/*----------------*/
/*       CAN      */
/*----------------*/
#define CAN_RX_PIN							(1 << 19)
#define CAN_TX_PIN							(1 << 20)
/*	MCK = 48MHz
	CAN baudrate= 500kbit/s => bit time= 2us
	Delay of the bus driver: 50 ns
	Delay of the receiver: 30ns
	Delay of the bus line (20m): 110ns
	The total number of time quanta in a bit time must be comprised between 8
	and 25. If we fix the bit time to 16 time quanta:
	Tcsc = 1 time quanta = bit time / 16 = 125 ns
	=> BRP = (Tcsc x MCK) - 1 = 5
	The propagation segment time is equal to twice the sum of the signal’s
	propagation time on the bus line, the receiver delay and the output driver delay:
	Tprs = 2 * (50+30+110) ns = 380 ns = 3 Tcsc
	=> PROPAG = Tprs/Tcsc - 1 = 2
	The remaining time for the two phase segments is:
	Tphs1 + Tphs2 = bit time - Tcsc - Tprs = (16 - 1 - 3)Tcsc
	Tphs1 + Tphs2 = 12 Tcsc
	Because this number is even, we choose Tphs2 = Tphs1 (else we would choose
	Tphs2 = Tphs1 + Tcsc)
	Tphs1 = Tphs2 = (12/2) Tcsc = 6 Tcsc
	=> PHASE1 = PHASE2 = Tphs1/Tcsc - 1 = 5
	The resynchronization jump width must be comprised between 1 Tcsc and the
	minimum of 4 Tcsc and Tphs1. We choose its maximum value:
	Tsjw = Min(4 Tcsc,Tphs1) = 4 Tcsc
	=> SJW = Tsjw/Tcsc - 1 = 3
	Finally: CAN_BR = 0x00053255
*/
#define CAN_BR_CONFIG						0x53255


#endif /* Board_h */
