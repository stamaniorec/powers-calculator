/*************************************************************************
 *    Description : Real Time Timer handler
 *
 *    $Revision:   1.1  $
 *    History :
 *	  $Log:   J:/_PVCSroot/JCI/University_Program/archives/Components/workspace/RealTimeTimer/RTT.c-arc  $
 * 
 *    Rev 1.1   Oct 15 2007 10:57:48   apeikod
 * Updated documentation and switched to more extended handling
 *	  Revision 1.3  2007/10/01 21:05:43  apeikod
 *	  API unification
 *	
 *	  Revision 1.2  2007/07/31 02:04:44  apeikod
 *	  add time and clock features
 *	
 **************************************************************************/
#include "RTT.h"

void RTT_IrqHandler(void) __irq
{
	//... Your code goes here
	AT91F_TC_GetStatus( AT91C_BASE_TC0 );									/* read TC0 Status Register to clear it	*/
}

void RTT_Init(fpIrqHandler func) {
	/* Enable Timer controller */
	AT91F_TC0_CfgPMC( AT91C_BASE_PMC );

	/* Set up the AIC  registers for Timer 0 */
	if (func==NULL)
	AT91F_AIC_ConfigureInterrupt( AT91C_BASE_AIC, AT91C_ID_TC0, 4, AT91C_AIC_SRCTYPE_INT_HIGH_LEVEL, (void*)RTT_IrqHandler);
	else
	AT91F_AIC_ConfigureInterrupt( AT91C_BASE_AIC, AT91C_ID_TC0, 4, AT91C_AIC_SRCTYPE_INT_HIGH_LEVEL, func);

	AT91F_AIC_DisableInterrupt( AT91C_BASE_AIC, AT91C_ID_TC0 );
	AT91F_AIC_EnableInterrupt( AT91C_BASE_AIC, AT91C_ID_TC0 );

	/*		TC Block Control Register TC_BCR    (read/write)
		|------------------------------------------------------------------|------|
		|                                                                  |SYNC  |
		|------------------------------------------------------------------|------|
	   31                                                               1    0

		SYNC = 0 (no effect)    <===== take  default
		SYNC = 1 (generate software trigger for all 3 timer channels simultaneously)
	*/
	AT91F_TCB_SetSynchonization( AT91C_BASE_TCB, 0);

	/*		TC Block Mode Register  TC_BMR    (read/write)

		|-------------------------------------|-----------|-----------|-----------|
	    |                                     | TC2XC2S   | TCXC1S    |  TC0XC0S  |
		|-------------------------------------|-----------|-----------|-----------|
	   31                                     5       4   3       2   1         0

		TC0XC0S Select = 00 TCLK0 (PA4)
		               = 01 none           <===== we select this one
	                   = 10 TIOA1 (PA15)
	                   = 11 TIOA2 (PA26)

		TCXC1S  Select = 00 TCLK1 (PA28)
		               = 01 none           <===== we select this one
	                   = 10 TIOA0 (PA15)
	                   = 11 TIOA2 (PA26)

		TC2XC2S Select = 00 TCLK2 (PA29)
		               = 01 none           <===== we select this one
	                   = 10 TIOA0 (PA00)
	                   = 11 TIOA1 (PA26)
	*/
	AT91F_TCB_SetExternalClocks( AT91C_BASE_TCB, 1, 1, 1);


	/*		TC Channel Control Register  TC_CCR    (read/write)

		|----------------------------------|--------------|------------|-----------|
	    |                                  |   SWTRG      |   CLKDIS   |   CLKENS  |
		|----------------------------------|--------------|------------|-----------|
	   31                                        2             1           0

		CLKEN = 0    no effect
		CLKEN = 1    enables the clock     <===== we select this one

		CLKDIS = 0   no effect             <===== take  default
		CLKDIS = 1   disables the clock

	    SWTRG = 0    no effect
	    SWTRG = 1    software trigger aserted counter reset and clock starts   <===== we select this one
	*/
	AT91F_TC_EnableController( AT91C_BASE_TC0, 5);


	/*		TC Channel Mode Register  TC_CMR    (read/write)
		|-----------------------------------|------------|---------------|
	    |                                   |  LDRB      |     LDRA      |
		|-----------------------------------|------------|---------------|
	   31                                  19        18 17           16

		|----------|---------|--------------|------------|---------------|
	    |WAVE = 0  | CPCTRG  |              |  ABETRG    |    ETRGEDG    |
		|----------|---------|--------------|------------|---------------|
	      15         14     13          11      10      9             8

		|----------|---------|--------------|------------|---------------|
	    |  LDBDIS  | LDBSTOP |   BURST      |  CLKI      |     TCCLKS    |
		|----------|---------|--------------|------------|---------------|
	       7          6     5            4      3       2             0

	  CLOCK SELECTION
		TCCLKS = 000  TIMER_CLOCK1    (MCK/2    =  24027420 hz)
		         001  TIMER_CLOCK2    (MCK/8    =   6006855 hz)
		         010  TIMER_CLOCK3    (MCK/32   =   1501713 hz)
		         011  TIMER_CLOCK4    (MCK/128  =    375428 hz)
		         100  TIMER_CLOCK5    (MCK/1024 =     46928 hz)   <===== we select this one
	           101  XC0
	           101  XC1
	           101  XC2

	  CLOCK INVERT
		CLKI   = 0   counter incremented on rising clock edge    <===== we select this one
		CLKI   = 1   counter incremented on falling clock edge

	  BURST SIGNAL SELECTION
	  BURST  = 00  clock is not gated by any external system   <===== take  default
	           01  XC0 is anded with the clock
	            10  XC1 is anded with the clock
	           11  XC2 is anded with the clock

	  COUNTER CLOCK STOPPED WITH RB LOADING
	  LDBSTOP  = 0  counter clock is not stopped when RB loading occurs   <===== take  default
	           = 1  counter clock is stopped when RB loading occur

	  COUNTER CLOCK DISABLE WITH RB LOADING
	  LDBDIS   = 0  counter clock is not disabled when RB loading occurs   <===== take  default
	           = 1  counter clock is disabled when RB loading occurs

	  EXTERNAL TRIGGER EDGE SELECTION
	  ETRGEDG  = 00  (none)              <===== take default
	             01  (rising edge)
	             10  (falling edge)
	             11  (each edge)

	  TIOA OR TIOB EXTERNAL TRIGGER SELECTION
	  ABETRG   = 0  (TIOA is used)      <===== take default
	             1  (TIOB is used)

	  RC COMPARE TRIGGER ENABLE
	  CPCTRG   = 0  (RC Compare has no effect on the counter and its clock)
	             1  (RC Compare resets the counter and starts the clock)      <===== we select this one

	  WAVE
	  WAVE     = 0  Capture Mode is enabled     <===== we select this one
	             1  Waveform Mode is enabled

	  RA LOADING SELECTION
	  LDRA  = 00 none)                   <===== take default
	          01 (rising edge of TIOA)
	          10 (falling edge of TIOA)
	          11 (each edge of TIOA)

	  RB LOADING SELECTION
	  LDRB  = 00 (none)                  <===== take default
	          01 (rising edge of TIOA)
	          10 (falling edge of TIOA)
	          11 (each edge of TIOA)
	*/
	AT91F_TC_ConfigureChannel( AT91C_BASE_TC0, 0x4004 );

	/*		TC Register C     TC_RC   (read/write)   Compare Register 16-bits
		|----------------------------------|----------------------------------------|
	    |           not used               |               RC                       |
		|----------------------------------|----------------------------------------|
	   31                              16 15                                    0

		Timer Calculation:   What count gives 50 msec time-out?

	     TIMER_CLOCK5 = MCK / 1024  = 48054841 / 1024  =  46928 hz

	     TIMER_CLOCK5 Period = 1 / 46928  =  21.309239686 microseconds

	     A little algebra:  .050 sec = count * 21.3092396896*10**-6
	                        count =  .050 / 21.3092396896*10**-6
	                        count =  2346
	*/
	/* 46928 at 96 MHz for 2 Hz clock ( 1Hz is not possible at that MCK, because 16bit are not enough ) */
	AT91F_TC_SetRCPeriod( AT91C_BASE_TC0, 2346 );

	/*		TC Interrupt Enable Register  TC_IER    (write-only)
		|------------|-------|-------|-------|-------|--------|--------|--------|--------|
	    |            | ETRGS | LDRBS | LDRAS | CPCS  | CPBS   |  CPAS  |  LOVRS |  COVFS |
		|------------|-------|-------|-------|-------|--------|--------|--------|--------|
	   31         8    7       6       5       4        3        2        1        0

	  COVFS    = 0  no effect    <===== take  default                                                                                          
	             1  enable counter overflow interrupt

	  LOVRS    = 0  no effect    <===== take  default
	             1  enable load overrun interrupt

	  CPAS     = 0  no effect    <===== take  default
	             1  enable RA compare interrupt

	  CPBS     = 0  no effect    <===== take  default
	             1  enable RB compare interrupt

	  CPCS     = 0  no effect
	             1  enable RC compare interrupt    <===== we select this one

	  LDRAS    = 0  no effect    <===== take  default
	             1  enable RA load interrupt

	  LDRBS    = 0  no effect    <===== take  default
	             1  enable RB load interrupt

	  ETRGS    = 0  no effect    <===== take  default
	             1  enable External Trigger interrupt
	*/
	AT91F_TC_InterruptEnable( AT91C_BASE_TC0, 0x10 );


	/*		TC Interrupt Disable Register  TC_IDR    (write-only)
		|------------|-------|-------|-------|-------|--------|--------|--------|--------|
	    |            | ETRGS | LDRBS | LDRAS | CPCS  | CPBS   |  CPAS  |  LOVRS |  COVFS |
		|------------|-------|-------|-------|-------|--------|--------|--------|--------|
	   31         8    7       6       5       4        3        2        1        0

	  COVFS    = 0  no effect
	             1  disable counter overflow interrupt    <===== we select this one

	  LOVRS    = 0  no effect
	             1  disable load overrun interrupt    <===== we select this one

	  CPAS     = 0  no effect
	             1  disable RA compare interrupt    <===== we select this one

	  CPBS     = 0  no effect
	             1  disable RB compare interrupt    <===== we select this one

	  CPCS     = 0  no effect    <===== take  default
	             1  disable RC compare interrupt

	  LDRAS    = 0  no effect
	             1  disable RA load interrupt    <===== we select this one

	  LDRBS    = 0  no effect
	             1  disable RB load interrupt    <===== we select this one

	  ETRGS    = 0  no effect
	             1  disable External Trigger interrupt    <===== we select this one
	*/
	AT91F_TC_InterruptDisable( AT91C_BASE_TC0, 0xEF );
}


