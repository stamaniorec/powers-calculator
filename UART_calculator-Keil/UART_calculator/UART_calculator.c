#include <basedef.h>
#include <Board.h>
#include <stdio.h>

#include <fixedsys.h>
#include <lcd_GE8.h>
#include "lib_AT91SAM7_USART.h"
#include "lib_AT91SAM7_PMC.h" 
#include "lib_AT91SAM7_PIO.h"
#include "lib_AT91SAM7_PDC.h"
#include <string.h>

void Delay (unsigned long a) {while (--a!=0);}

AT91PS_PIO pPioA    = AT91C_BASE_PIOA;
AT91PS_PMC pPMC     = AT91C_BASE_PMC;
AT91PS_USART pUART1 = AT91C_BASE_US1;

// ----------------------------------------------
void f_red() 	{LCD_ClearScreen( LCD_COLOR_RED );}
void f_green() 	{LCD_ClearScreen( LCD_COLOR_GREEN );}
void f_blue() 	{LCD_ClearScreen( LCD_COLOR_BLUE );}
void f_yellow() {LCD_ClearScreen( LCD_COLOR_YELLOW );}

// ----------------------------------------------

Color_t		bckgColor=LCD_COLOR_WHITE;

void UART_PutChar(char ch){
	while (!AT91F_US_TxReady(pUART1));
	AT91F_US_PutChar(pUART1, ch);
}

void UART_WriteString(char *str) {
	int	i;

	UART_PutChar('S');
	for(i=0; i<strlen(str); i++) {
		UART_PutChar('s');
		UART_PutChar(str[i]);
	} 							  
	UART_PutChar('E');
}

void UART_ReadString(char* buff) {
	int i=0;
	int stop = false;
	int char_received = false;
	char curr_char;

	while (!AT91F_US_RxReady(pUART1) &&  AT91F_US_GetChar(pUART1) != 'S');
	while (!stop){
		if (AT91F_US_RxReady(pUART1))
			curr_char = AT91F_US_GetChar(pUART1);
		switch(curr_char){
			case 'S':
				break;
			case 'E':
				stop = true;
				break;
			case 's':
				char_received = false;
				break;
			default:
				if(!char_received)
					buff[i++] = curr_char;
				char_received = true;
				break;
		}
	}
	buff[i] = '\0';
}

void printExpr(char* expr){	 
	//LCD_ClearScreen( bckgColor );
	LCD_WriteString(expr, &Fixedsys_descriptor, 2, 4, LCD_COLOR_WHITE, LCD_COLOR_RED);
}

int main() {

	/* any other variables you need ... */
	// ...
	int fh, fw;
	char msg[16];

	/* Initialize the Atmel AT91SAM7X256 (watchdog, PLL clock, default interrupts, etc.) */

	AT91F_LowLevel_Init();
	InitLCD();
	LCD_ClearScreen( bckgColor );

	AT91F_US_Configure(pUART1, MCK, AT91C_US_ASYNC_MODE, 9600L, 0 );
	AT91F_PMC_EnablePeripheralClock(pPMC, 1 << AT91C_ID_US1 );

	AT91F_US1_CfgPMC(pPMC);
	AT91F_US1_CfgPIO(pPioA, 0);

    AT91F_US_EnableRx(pUART1);
    AT91F_US_EnableTx(pUART1);

	/* put other initializations here ... */
	// ...

	/* enable interrupts */
	//AT91F_Finalize_Init();

	/* add your program here ... */
	
	//LCDShowImage130x130(bmp);
	fh = Fixedsys_descriptor.font_height;
	fw = Fixedsys_descriptor.font_width;
	//LCD_WriteString("gibberish", &Fixedsys_descriptor, 2, fh, LCD_COLOR_WHITE, LCD_COLOR_RED);
	
	 

	/* your main loop ... */  
	while ( true ) {
		UART_ReadString(msg);
		printExpr(msg);
		UART_WriteString(msg);
	}
	/* sadistic mcu */
	return 42;
}
