/*************************************************************************
 *
 *    Used with ICCARM and AARM.
 *
 *    (c) Copyright IAR Systems 2006
 *
 *    File name   : font.h
 *    Description : 12x16 font
 *                  if bit is set to '1' - the pixel is ON
 *                  otherwise - OFF (will be displayed in foreground colour respectively background colour)
 *    History :
 *    1. Date        : Aug 15, 2006
 *       Author      : Todor Atanasov
 *       Description : Created
 * 	  2. Date		 : Jul 21, 2007
 * 		 Author		 : Dimitar Peikov
 * 		 Description : Font structure modified. Now 
 * 					   contains characters width and height
 *
 *    $Revision:   1.1  $
**************************************************************************/

#ifndef  __FONT_H
#define  __FONT_H

#define FONT_NAME_LENGTH 16

/*! \struct font_description
 * 	describe font logistic data
 */
struct font_description
{
	/*! Font string name */
	const char *		font_name;
	/*! Font width in pixels */
	U8					font_width;
	/*! Font height in pixels */
	U8					font_height;
	/*! pointer to Font symbol data definition */
	const U8 *			font_data_ptr;
};

#endif  /* __FONT_H */
