/*************************************************************************
 *    Description : Real Time Timer handler
 *
 *    $Revision:   1.1  $
 *    History :
 *	  $Log:   J:/_PVCSroot/JCI/University_Program/archives/Components/workspace/RealTimeTimer/RTT.h-arc  $
 * 
 *    Rev 1.1   Oct 15 2007 10:57:50   apeikod
 * Updated documentation and switched to more extended handling
 *	  Revision 1.4  2007/10/01 21:05:43  apeikod
 *	  API unification
 *	
 *	  Revision 1.3  2007/07/31 02:04:44  apeikod
 *	  add time and clock features
 *	
 **************************************************************************/
#ifndef  __RTT_H
#define  __RTT_H

#include <basedef.h>
#include <ioat91sam7x256.h>
#include <lib_AT91SAM7_AIC.h>
#include <lib_AT91SAM7_TC.h>
#include <lib_AT91SAM7_PIO.h>
#include <lib_AT91SAM7_SPI.h>
#include <lib_AT91SAM7_PMC.h>

typedef void (*fpIrqHandler)(void);

void	RTT_IrqHandler(void) __irq;
void	RTT_Init(fpIrqHandler);

#endif  /* __RTT_H */
