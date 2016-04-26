#include "ioat91sam7x256.h"
#include "lib_at91sam7_spi.h"
#include "lcd_GE8.h"
//#include "bmp.h"
#include "bits.h"

AT91PS_PIO    l_pPioA   = AT91C_BASE_PIOA;
AT91PS_PIO    l_pPioB   = AT91C_BASE_PIOB;
AT91PS_SPI    l_pSpi    = AT91C_BASE_SPI0;
AT91PS_PMC    l_pPMC    = AT91C_BASE_PMC;
AT91PS_PDC    l_pPDC    = AT91C_BASE_PDC_SPI0;


#define SPI_SR_TXEMPTY

#define LCD_RESET_LOW     l_pPioA->PIO_CODR   = BIT2
#define LCD_RESET_HIGH    l_pPioA->PIO_SODR   = BIT2

void Delaya (unsigned long a) { while (--a!=0); }

void Delay_ (unsigned long a) {

  volatile unsigned long d;
  d=a;
  while (--d!=0);
}

unsigned int i,j;

void InitLCD(void) {

  // Pin for backlight
  //l_pPioB->PIO_CODR   = BIT20;    // Set PB20 to LOW
  l_pPioB->PIO_SODR   = BIT20;    // Set PB20 to HIGH
  l_pPioB->PIO_OER    = BIT20;    // Configure PB20 as output

  // Reset pin
  l_pPioA->PIO_SODR   = BIT2;     // Set PA2 to HIGH
  l_pPioA->PIO_OER    = BIT2;     // Configure PA2 as output

  // CS pin
  //l_pPioA->PIO_SODR   = BIT12;     // Set PA2 to HIGH
  //l_pPioA->PIO_OER    = BIT12;     // Configure PA2 as output


  // Init SPI0
  //set functionality to pins:
  //port0.12 -> NPCS0
  //port0.16 -> MISO
  //port0.17 -> MOSI
  //port0.18 -> SPCK
  l_pPioA->PIO_PDR = BIT12 | BIT16 | BIT17 | BIT18;
  l_pPioA->PIO_ASR = BIT12 | BIT16 | BIT17 | BIT18;
  l_pPioA->PIO_BSR = 0;


  //enable the clock of SPI
  l_pPMC->PMC_PCER = 1 << AT91C_ID_SPI0;
  //l_pPMC->PMC_PCER = 1 << 5;

  // Fixed mode
  l_pSpi->SPI_CR      = 0x81;               //SPI Enable, Software reset
  l_pSpi->SPI_CR      = 0x01;               //SPI Enable


  //l_pSpi->SPI_MR      = 0xE0099;           //Master mode, fixed select, disable decoder, FDIV=1 (NxMCK), PCS=1110, loopback
  //l_pSpi->SPI_MR      = 0xE0019;            //Master mode, fixed select, disable decoder, FDIV=1 (NxMCK), PCS=1110,
  //l_pSpi->SPI_MR      = 0xE0011;            //Master mode, fixed select, disable decoder, FDIV=0 (MCK), PCS=1110
  l_pSpi->SPI_MR      = 0xE0019;            //Master mode, fixed select, disable decoder, FDIV=1 (MCK), PCS=1110

  //l_pSpi->SPI_CSR[0]  = 0x4A02;           //8bit, CPOL=0, ClockPhase=1, SCLK = 200kHz
  //l_pSpi->SPI_CSR[0]  = 0x4A13;           //9bit, CPOL=1, ClockPhase=1, SCLK = 200kHz
  //l_pSpi->SPI_CSR[0]  = 0x4A12;           //9bit, CPOL=0, ClockPhase=1, SCLK = 200kHz
  //l_pSpi->SPI_CSR[0]  = 0x4A11;           //9bit, CPOL=1, ClockPhase=0, SCLK = 200kHz
  //l_pSpi->SPI_CSR[0]  = 0x01011F11;       //9bit, CPOL=1, ClockPhase=0, SCLK = 48Mhz/32*31 = 48kHz
  //l_pSpi->SPI_CSR[0]  = 0x01010F11;       //9bit, CPOL=1, ClockPhase=0, SCLK = 48Mhz/32*15 = 96kHz
  //l_pSpi->SPI_CSR[0]  = 0x01010C11;       //9bit, CPOL=1, ClockPhase=0, SCLK = 48Mhz/32*12 = 125kHz
  l_pSpi->SPI_CSR[0]  = 0x01010211;   	//9bit, CPOL=1, ClockPhase=0, SCLK = 48Mhz/32* 2 = 750kHz
  //l_pSpi->SPI_CSR[0]  = 0x01010111;		//9bit, CPOL=1, ClockPhase=0, SCLK = 48Mhz/32* 1 = 1500kHz

  Delay_(1000);
  // Custom Settings
  // ====================

    // Hardware reset
    LCD_RESET_LOW;
    Delay_(1000);
    LCD_RESET_HIGH;
    Delay_(1000);

    // Display vontrol
    WriteSpiCommand(DISCTL);
  //  WriteSpiData(0x03); // no division
  //  WriteSpiData(0x23); // 160 line
  //  WriteSpiData(0x02); // 2 highlighte line
    WriteSpiData(0x00); // default
    WriteSpiData(0x20); // (32 + 1) * 4 = 132 lines (of which 130 are visible)
    WriteSpiData(0x0a); // default

    // COM scan
    WriteSpiCommand(COMSCN);
    WriteSpiData(0x00);  // Scan 1-80

    // Internal oscilator ON
    WriteSpiCommand(OSCON);

    // wait aproximetly 100ms
    Delay_(10000);

    // Sleep out
    WriteSpiCommand(SLPOUT);

    // Voltage control
    WriteSpiCommand(VOLCTR);
    WriteSpiData(0x1F); // middle value of V1
    WriteSpiData(0x03); // middle value of resistance value

    // Temperature gradient
    WriteSpiCommand(TMPGRD);
    WriteSpiData(0x00); // default

    // Power control
    WriteSpiCommand(PWRCTR);
    WriteSpiData(0x0f);   // referance voltage regulator on, circuit voltage follower on, BOOST ON

    // Normal display
    WriteSpiCommand(DISNOR);

    // Inverse display
    WriteSpiCommand(DISINV);

    // Partial area off
    WriteSpiCommand(PTLOUT);

  //  // Scroll area set
  //  WriteSpiCommand(ASCSET);
  //  WriteSpiData(0);
  //  WriteSpiData(0);
  //  WriteSpiData(40);
  //  WriteSpiData(3);

  //  // Vertical scrool address start
  //  WriteSpiCommand(SCSTART);
  //  WriteSpiData(0);


    // Data control
    WriteSpiCommand(DATCTL);
    WriteSpiData(0x00); // all inversions off, column direction
    WriteSpiData(0x03); // RGB sequence
    WriteSpiData(0x02); // Grayscale -> 16

    // Page Address set
    WriteSpiCommand(PASET);
    WriteSpiData(0);
    WriteSpiData(131);

    // Page Column set
    WriteSpiCommand(CASET);
    WriteSpiData(0);
    WriteSpiData(131);

}


void WriteSpiCommand(unsigned int data){

  data = (data & ~0x0100);

  // Wait for the transfer to complete
  while((l_pSpi->SPI_SR & AT91C_SPI_TXEMPTY) == 0);

  l_pSpi->SPI_TDR = data;
}

void WriteSpiData(unsigned int data){

  data = (data | 0x0100);

  // Wait for the transfer to complete
  while((l_pSpi->SPI_SR & AT91C_SPI_TXEMPTY) == 0);

  l_pSpi->SPI_TDR = data;
}


void Backlight(unsigned char state) {

  if(state == BKLGHT_LCD_ON)
    l_pPioB->PIO_SODR   = BIT20;    // Set PB20 to HIGH
  else
    l_pPioB->PIO_CODR   = BIT20;    // Set PB20 to LOW

}

void SetContrast(unsigned char contrast) {

#ifdef GE12
  WriteSpiCommand(CONTRAST);
  WriteSpiData(0x20+contrast);    // contrast
#else

#endif

}

void LCDShowImage130x130(const unsigned char *img) {

  // Display OFF
  WriteSpiCommand(DISOFF);

  // Page Address set
  WriteSpiCommand(PASET);
  WriteSpiData(0x00);
  WriteSpiData(0x83);

  // Page Column set
  WriteSpiCommand(CASET);
  WriteSpiData(0x00);
  WriteSpiData(0x83);

  // WRITE MEMORY
  WriteSpiCommand(RAMWR);

  for(j=0; j<25740; j++) //130*132*1.5
  {
    WriteSpiData(img[j]);
    //WriteSpiData(0xFF);
  }

  // wait aproximetly 100ms
  Delay_(10000);

  // Display On
  WriteSpiCommand(DISON);	
}

/*!************************************************************************
 * \fn void LCD_ClearScreen(Color_t color)
 * \param color Color to clear the screen
 * \brief Clears the whole LCD screen using special color
 *************************************************************************/
void LCD_ClearScreen(Color_t color)
{
	U16 j;

#ifdef GE12
	/* Display OFF */
	AT91F_SPI_WriteCommand( pSPI, LDS176_DISPOFF, 0 );

	AT91F_SPI_WriteCommand( pSPI, LDS176_CASET, 0 );
	AT91F_SPI_WriteData( pSPI, 0x01, 0 );
	AT91F_SPI_WriteData( pSPI, 0x82, 0 );

	AT91F_SPI_WriteCommand( pSPI, LDS176_RASET, 0 );
	AT91F_SPI_WriteData( pSPI, 0x01, 0 );
	AT91F_SPI_WriteData( pSPI, 0x82, 0 );

	AT91F_SPI_WriteCommand( pSPI, LDS176_RAMWR, 0 );

	for(j=0; j<132*65; j++)
	{
		LCDColor_t temp_color;
		temp_color = color;
		temp_color |= temp_color << 12;
		AT91F_SPI_WriteData( pSPI, (temp_color >> 16) & 0xFF, 0 );
		AT91F_SPI_WriteData( pSPI, (temp_color >> 8) & 0xFF, 0 );
		AT91F_SPI_WriteData( pSPI, temp_color & 0xFF, 0 );
	}

	/* Display On */
	AT91F_SPI_WriteCommand( pSPI, LDS176_DISPON, 0 );
#endif

#ifdef GE8

	if (0) {
	WriteSpiCommand(DISOFF);


	// Page Address set
	WriteSpiCommand(PASET);
	WriteSpiData(0x00);
	WriteSpiData(0x83);

	// Page Column set
	WriteSpiCommand(CASET);
	WriteSpiData(0x00);
	WriteSpiData(0x83);

	// WRITE MEMORY
	WriteSpiCommand(RAMWR);

	for(j = 0; j < 134*65; j++) {
		U32 temp_color;
		temp_color = color;
		temp_color |= temp_color << 12;
		WriteSpiData((temp_color >> 16) & 0xFF);
		WriteSpiData((temp_color >> 8) & 0xFF);
		WriteSpiData(temp_color & 0xFF);
	}

	WriteSpiCommand(DISON);
	}
	else {

#define LCD_SPI_CHANNEL 0
	void * pSPI = AT91F_SPI_GetPeripheralAddress(LCD_SPI_CHANNEL);

	  // Page Address set
	  AT91F_SPI_WriteCommand(pSPI, PASET, LCD_SPI_CHANNEL);
	  AT91F_SPI_WriteData(pSPI, 0x00, LCD_SPI_CHANNEL);
	  AT91F_SPI_WriteData(pSPI, 0x83, LCD_SPI_CHANNEL);

	  // Page Column set
	  AT91F_SPI_WriteCommand(pSPI, CASET, LCD_SPI_CHANNEL);
	  AT91F_SPI_WriteData(pSPI, 0x00, LCD_SPI_CHANNEL);
	  AT91F_SPI_WriteData(pSPI, 0x83, LCD_SPI_CHANNEL);

	  // WRITE MEMORY
	  AT91F_SPI_WriteCommand(pSPI, RAMWR, LCD_SPI_CHANNEL);

	  //for(j=0; j<sizeof(bmp)-396; j++) {
	  for(j = 0; j < 132*65; j++) {
			U32 temp_color;
			temp_color = color;
			temp_color |= temp_color << 12;
			AT91F_SPI_WriteData( pSPI, (temp_color >> 16) & 0xFF, 0 );
			AT91F_SPI_WriteData( pSPI, (temp_color >> 8) & 0xFF, 0 );
			AT91F_SPI_WriteData( pSPI, temp_color & 0xFF, 0 );
	  }

	  AT91F_SPI_WriteCommand( pSPI, DISON, LCD_SPI_CHANNEL);
	  //AT91F_SPI_WriteCommand( pSPI, NOP, LCD_SPI_CHANNEL);

	}
#endif

}

//  *************************************************************************************
//   						LCDSetPixel.c
//
//	Lights a single pixel in the specified color at the specified x and y addresses
//
//	Inputs:	  x     =   row address (0 .. 131)
//			  y     =   column address  (0 .. 131)
//		      color = 	12-bit color value  rrrrggggbbbb
//						rrrr = 1111 full red
//								  :
//						       0000 red is off
//
//						gggg = 1111 full green
//								  :
//						       0000 green is off
//
//						bbbb = 1111 full blue
//								  :
//						       0000 blue is off
//
//	   Returns:   nothing
//
//		Note: see lcd.h for some sample color settings
//
//  	Author:  James P Lynch     August 30, 2007
//
//		Modified by: Lazar Chervenkov 22 April, 2010
//  *************************************************************************************

void LCDSetPixel(int x, int y, Color_t color) {

	// Row address set  (command 0x2B)
	WriteSpiCommand(PASET);
	WriteSpiData(y);
	WriteSpiData(y);

	// Column address set  (command 0x2A)
	WriteSpiCommand(CASET);
	WriteSpiData(x);
	WriteSpiData(x);

	// Now illuminate the pixel (2nd pixel will be ignored)
	WriteSpiCommand(RAMWR);
	WriteSpiData((color >> 4) & 0xFF);
	WriteSpiData(((color & 0xF) << 4) | ((color >> 8) & 0xF));
	WriteSpiData(color & 0xFF);
}

//  *************************************************************************************************
//   						LCDSetLine.c
//
//	Draws a line in the specified color from (x0,y0) to (x1,y1)
//
//	Inputs:	  x     =   row address (0 .. 131)
//			  y     =   column address  (0 .. 131)
//		      color = 	12-bit color value  rrrrggggbbbb
//						rrrr = 1111 full red
//								  :
//						       0000 red is off
//
//						gggg = 1111 full green
//								  :
//						       0000 green is off
//
//						bbbb = 1111 full blue
//								  :
//						       0000 blue is off
//
//	Returns:   nothing
//
//	Note: good write-up on this algorithm in Wikipedia (search for Bresenham's line algorithm)
//		  see lcd.h for some sample color settings
//
//	Authors: 	Dr. Leonard McMillan, Associate Professor UNC
//				Jack Bresenham IBM, Winthrop University (Father of this algorithm, 1962)
//
//				Note: taken verbatim from Professor McMillan's presentation:
//					  http://www.cs.unc.edu/~mcmillan/comp136/Lecture6/Lines.html
//
//
//	Modified by: Lazar Chervenkov 22 April, 2010
//  *************************************************************************************************

void LCDSetLine(int x0, int y0, int x1, int y1, Color_t color) {

    int dy = y1 - y0;
    int dx = x1 - x0;
	int stepx, stepy;

    if (dy < 0) { dy = -dy;  stepy = -1; } else { stepy = 1; }
    if (dx < 0) { dx = -dx;  stepx = -1; } else { stepx = 1; }
    dy <<= 1;							// dy is now 2*dy
    dx <<= 1;							// dx is now 2*dx

	LCDSetPixel(x0, y0, color);
    if (dx > dy) {
    	int fraction = dy - (dx >> 1);	// same as 2*dy - dx
	    while (x0 != x1) {
	    	if (fraction >= 0) {
	    		y0 += stepy;
	            fraction -= dx;			// same as fraction -= 2*dx
	        }
	        x0 += stepx;
	        fraction += dy;				// same as fraction -= 2*dy
	        LCDSetPixel(x0, y0, color);
	    }
    }
    else {
	    int fraction = dx - (dy >> 1);
	    while (y0 != y1) {
	    	if (fraction >= 0) {
	    		x0 += stepx;
	            fraction -= dy;
	        }
	    y0 += stepy;
	    fraction += dx;
	    LCDSetPixel(x0, y0, color);
	    }
    }
}

//  *****************************************************************************************
//   						LCDSetRect.c
//
//	Draws a rectangle in the specified color from (x1,y1) to (x2,y2)
//	Rectangle can be filled with a color if desired
//
//	Inputs:	  x     =   row address (0 .. 131)
//			  y     =   column address  (0 .. 131)
//			  fill  =   0=no fill, 1-fill entire rectangle
//		      color = 	12-bit color value for lines	rrrrggggbbbb
//						rrrr = 1111 full red
//								  :
//						       0000 red is off
//
//						gggg = 1111 full green
//								  :
//						       0000 green is off
//
//						bbbb = 1111 full blue
//								  :
//						       0000 blue is off
//
//	   Returns:   nothing
//
//		Notes:
//
//		The best way to fill a rectangle is to take advantage of the "wrap-around" featute
//		built into the Epson S1D15G00 controller. By defining a drawing box, the memory can
//		be simply filled by successive memory writes until all pixels have been illuminated.
//
//			1.  Given the coordinates of two opposing corners (x0, y0) (x1, y1)
//				calculate the minimums and maximums of the coordinates
//
//					xmin = (x0 <= x1) ? x0 : x1;
//					xmax = (x0 > x1) ? x0 : x1;
//					ymin = (y0 <= y1) ? y0 : y1;
//					ymax = (y0 > y1) ? y0 : y1;
//
//			2. Now set up the drawing box to be the desired rectangle
//
//					WriteSpiCommand(PASET);		// set the row boundaries
//					WriteSpiData(xmin);
//					WriteSpiData(xmax);
//					WriteSpiCommand(CASET);		// set the column boundaries
//					WriteSpiData(ymin);
//					WriteSpiData(ymax);
//
//			3. Calculate the number of pixels to be written divided by 2
//
//					NumPixels = ((((xmax - xmin + 1) * (ymax - ymin + 1)) / 2) + 1)
//
//						You may notice that I added one pixel to the formula.
//						This covers the case where the number of pixels is odd and we
//						would lose one pixel due to rounding error. In the case of
//						odd pixels, the number of pixels is exact.
//						in the case of even pixels, we have one more pixel than
//						needed, but it cannot be displayed because it is outside
//						the drawing box.
//
//						We divide by 2 because two pixels are represented by three bytes.
//						So we work through the rectangle two pixels at a time.
//
//			4.  Now a simple memory write loop will fill the rectangle
//
//				for (i = 0; i < ((((xmax - xmin + 1) * (ymax - ymin + 1)) / 2) + 1); i++) {
//					WriteSpiData((color >> 4) & 0xFF);
//					WriteSpiData(((color & 0xF) << 4) | ((color >> 8) & 0xF));
//					WriteSpiData(color & 0xFF);
//				}
//
//
//		In the case of an unfilled rectangle, drawing four lines with the Bresenham line
//		drawing algorithm is reasonably efficient.
//
//
//  	Author:  James P Lynch      August 30, 2007
//
//		Modified by: Lazar Chervenkov 22 April, 2010
//  *****************************************************************************************

void LCDSetRect(int x0, int y0, int x1, int y1, unsigned char fill, Color_t color) {
	int 	xmin, xmax, ymin, ymax;
	int		i;

	// check if the rectangle is to be filled
	if (fill == FILL) {

		// best way to create a filled rectangle is to define a drawing box
		// and loop two pixels at a time

		// calculate the min and max for x and y directions
		xmin = (x0 <= x1) ? x0 : x1;
		xmax = (x0 > x1) ? x0 : x1;
		ymin = (y0 <= y1) ? y0 : y1;
		ymax = (y0 > y1) ? y0 : y1;

		// specify the controller drawing box according to those limits
		// Row address set  (command 0x2B)
		WriteSpiCommand(CASET);
		WriteSpiData(xmin);
		WriteSpiData(xmax);

		// Column address set  (command 0x2A)
		WriteSpiCommand(PASET);
		WriteSpiData(ymin);
		WriteSpiData(ymax);

		// WRITE MEMORY
		WriteSpiCommand(RAMWR);

		// loop on total number of pixels / 2
		for (i = 0; i < ((((xmax - xmin + 1) * (ymax - ymin + 1)) / 2) + 130); i++) {

			// use the color value to output three data bytes covering two pixels
			WriteSpiData((color >> 4) & 0xFF);
			WriteSpiData(((color & 0xF) << 4) | ((color >> 8) & 0xF));
			WriteSpiData(color & 0xFF);
		}
	}
	else {

  		// best way to draw un unfilled rectangle is to draw four lines
		LCDSetLine(x0, y0, x1, y0, color);
		LCDSetLine(x0, y1, x1, y1, color);
		LCDSetLine(x0, y0, x0, y1, color);
		LCDSetLine(x1, y0, x1, y1, color);
    }
}

//  *************************************************************************************
//   						LCDSetCircle.c
//
//	Draws a line in the specified color at center (x0,y0) with radius
//
//	Inputs:	  x0     =   row address (0 .. 131)
//			  y0     =   column address  (0 .. 131)
//			  radius =  radius in pixels
//		      color  = 	12-bit color value  rrrrggggbbbb
//
//	Returns:   nothing
//
//	Author: 	Jack Bresenham IBM, Winthrop University (Father of this algorithm, 1962)
//
//				Note: taken verbatim Wikipedia article on Bresenham's line algorithm
//					  http://www.wikipedia.org
//
//
//	Modified by: Lazar Chervenkov 22 April, 2010
//  *************************************************************************************

void LCDSetCircle(int x0, int y0, int radius, Color_t color) {
	int f = 1 - radius;
	int ddF_x = 0;
	int ddF_y = -2 * radius;
	int x = 0;
	int y = radius;

	LCDSetPixel(x0, y0 + radius, color);
	LCDSetPixel(x0, y0 - radius, color);
	LCDSetPixel(x0 + radius, y0, color);
	LCDSetPixel(x0 - radius, y0, color);

	while(x < y) {
		if(f >= 0) {
			y--;
			ddF_y += 2;
			f += ddF_y;
		}
		x++;
		ddF_x += 2;
		f += ddF_x + 1;
		LCDSetPixel(x0 + x, y0 + y, color);
		LCDSetPixel(x0 - x, y0 + y, color);
		LCDSetPixel(x0 + x, y0 - y, color);
		LCDSetPixel(x0 - x, y0 - y, color);
		LCDSetPixel(x0 + y, y0 + x, color);
		LCDSetPixel(x0 - y, y0 + x, color);
		LCDSetPixel(x0 + y, y0 - x, color);
		LCDSetPixel(x0 - y, y0 - x, color);
	}
}

/*!************************************************************************
 * \fn void LCD_WriteChar(	U8 Ascii, \
 * 							struct font_description * font, \
 * 							U8 xb, \
 * 							U8 yb, \
 * 							U16 FG_Color, U16 BG_Color)
 * \param Ascii   Character which should be displayed
 * \param font    font_digits[] table.
 * \param xb      horizontal begin pixel position
 * \param xe      horizontal end pixel position
 * \param yb      vertical begin pixel position
 * \param ye      vertical end pixel position
 * \param FG_Color    Foreground colour - 12 bits. The most significant nibble is set to '0'
 * \param BG_Color Background colour - 12 bits. The most significant nibble is set to '0'
 * \brief   Displays a symbol on the LCD with specified font, coordinates and color
 *************************************************************************/
void LCD_WriteChar(U8 Ascii, struct font_description * font, U8 xb, U8 yb, U16 FG_Color, U16 BG_Color)
{
	U8	Byte_1 = 0, Byte_2 = 0, Byte_3 = 0, Pixel = 0;
	U16	i, j;
	void * pSPI = AT91F_SPI_GetPeripheralAddress( 0 );

#ifdef GE12
	AT91F_SPI_WriteCommand( pSPI, LDS176_CASET, 0 );
#endif
#ifdef GE8
	  AT91F_SPI_WriteCommand(pSPI, 0x15/*CASET*/, LCD_SPI_CHANNEL);
#endif
	AT91F_SPI_WriteData( pSPI, xb, 0 );
	AT91F_SPI_WriteData( pSPI, xb + font->font_width - 1, 0 );

#ifdef GE12
	AT91F_SPI_WriteCommand( pSPI, LDS176_RASET, 0 );
#endif
#ifdef GE8
	  AT91F_SPI_WriteCommand(pSPI, 0x75/*PASET*/, LCD_SPI_CHANNEL);
#endif
	AT91F_SPI_WriteData( pSPI, yb, 0 );
	AT91F_SPI_WriteData( pSPI, yb + font->font_height - 1, 0 );

#ifdef GE12
	AT91F_SPI_WriteCommand( pSPI, LDS176_RAMWR, 0 );
#endif
#ifdef GE8
	  AT91F_SPI_WriteCommand(pSPI, 0x5C/*RAMWR*/, LCD_SPI_CHANNEL);
#endif

	for( j = 0; j < font->font_height; j++ ) {
		Pixel = font->font_data_ptr[ j + ( font->font_height * Ascii ) ];
		for( i = 0; i < font->font_width; i++ )
		{
			/* Use 3 bytes to present 2 pixels (even and odd addresses) */
			if( i % 2 )
			{
			    if( Pixel & 0x80 )      /* Pixel ON */
			    {
			        Byte_2 &= 0xF0;
			        Byte_2 |= FG_Color >> 8;
			        Byte_3 = FG_Color & 0x00FF;
			    }
			    else                /* Pixel OFF */
			    {
			        Byte_2 &= 0xF0;
			        Byte_2 |= BG_Color >> 8;
			        Byte_3 =  BG_Color & 0x00FF;
			    }
			    AT91F_SPI_WriteData( pSPI, Byte_1, 0 );
			    AT91F_SPI_WriteData( pSPI, Byte_2, 0 );
			    AT91F_SPI_WriteData( pSPI, Byte_3, 0 );
			}
			else
			{
			    if( Pixel & 0x80 )      /* Pixel ON */
			    {
			        Byte_1 = FG_Color >> 4;
			        Byte_2 = FG_Color << 4;
			    }
			    else                /* Pixel OFF */
		        {
		            Byte_1 = BG_Color >> 4;
		            Byte_2 = BG_Color << 4;
/*		            Byte_2 = 0;
		            Byte_2 |= BG_Color << 4;
*/		        }
		    }
		    Pixel <<= 1;
		}
	}

#ifdef GE12
	AT91F_SPI_WriteCommand( pSPI, LDS176_NOP, LCD_SPI_CHANNEL);
#endif
#ifdef GE8
	AT91F_SPI_WriteCommand( pSPI, 0x25/*NOP*/, LCD_SPI_CHANNEL);
#endif

}

/*!************************************************************************
 * \fn void LCDWriteString(const S8 * pString,\
 * 							struct font_description * font, \
 * 							Coordinate_t xb, Coordinate_t xe, \
 * 							Color_t FG_Color, Color_t BG_Color)
 * \param Ascii   Characters which should be displayed
 * \param font    font_digits[] table.
 * \param xb      horizontal begin pixel position
 * \param xe      horizontal end pixel position
 * \param FG_Color    Foreground colour - 12 bits. The most significant nibble is set to '0'
 * \param BG_Color Background colour - 12 bits. The most significant nibble is set to '0'
 * \brief   Displays a string on LCD with specified font, coordinates and color
 *************************************************************************/
void LCD_WriteString(	char *pString, struct font_description *font,
						Coordinate_t xb, Coordinate_t yb, Color_t FG_Colour, Color_t BG_Colour)
{
	S8 * pStr = (S8 *) pString;
	Coordinate_t _x;

	_x = xb;

	while ( *pStr )
	{
		LCD_WriteChar( *pStr, font, _x, yb, FG_Colour, BG_Colour);
		pStr ++;
		_x += font->font_width;
	}
}
