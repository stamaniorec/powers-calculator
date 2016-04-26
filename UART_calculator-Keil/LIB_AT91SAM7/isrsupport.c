//  **********************************************************************************************
//
//  File Name	: isrsupport.c
//  Title		: interrupt enable/disable functions
//  Author		: Pascal Stang - Copyright (C) 2004
//  Created		: 2004.05.05
//  Revised		: 2004.07.12
//  Version		: 0.1
//  Target MCU	: ARM processors
//  Editor Tabs	: 4
//
//  NOTE: This code is currently below version 1.0, and therefore is considered
//  to be lacking in some functionality or documentation, or may not be fully
//  tested.  Nonetheless, you can expect most functions to work.
//
//  This code is distributed under the GNU Public License
//  which can be found at http://www.gnu.org/licenses/gpl.txt
//
//  Note from Jim Lynch:  
//  This is an abbreviated version of Pascal Stang's processor.c routine from the ARMLIB  
//      http://hubbard.engr.scu.edu/embedded/arm/armlib/index.html
//
//  **********************************************************************************************

#define IRQ_MASK 0x00000080
#define FIQ_MASK 0x00000040
#define INT_MASK (IRQ_MASK | FIQ_MASK)

char * _sbrk (int incr) {return 0;}		//<<<<< it's not Ok at all, I use it to get over the nasty 'sprintf' errors

//static inline unsigned __get_cpsr(void)
//{
//  unsigned long retval;
//  asm volatile (" mrs  %0, cpsr" : "=r" (retval) : /* no inputs */  );
//  return retval;
//}
//
//static inline void __set_cpsr(unsigned val)
//{
//  asm volatile (" msr  cpsr, %0" : /* no outputs */ : "r" (val)  );
//}

#include <intrinsics.h>

#define __get_cpsr()    __get_CPSR()
#define __set_cpsr(irq)   __set_CPSR(irq)

unsigned disableIRQ(void)
{
  unsigned _cpsr;

  _cpsr = __get_cpsr();
  __set_cpsr(_cpsr | IRQ_MASK);
  return _cpsr;
}

unsigned restoreIRQ(unsigned oldCPSR)
{
  unsigned _cpsr;

  _cpsr = __get_cpsr();
  __set_cpsr((_cpsr & ~IRQ_MASK) | (oldCPSR & IRQ_MASK));
  return _cpsr;
}

unsigned enableIRQ(void)
{
  unsigned _cpsr;

  _cpsr = __get_cpsr();
  __set_cpsr(_cpsr & ~IRQ_MASK);
  return _cpsr;
}

unsigned disableFIQ(void)
{
  unsigned _cpsr;

  _cpsr = __get_cpsr();
  __set_cpsr(_cpsr | FIQ_MASK);
  return _cpsr;
}

unsigned restoreFIQ(unsigned oldCPSR)
{
  unsigned _cpsr;

  _cpsr = __get_cpsr();
  __set_cpsr((_cpsr & ~FIQ_MASK) | (oldCPSR & FIQ_MASK));
  return _cpsr;
}

unsigned enableFIQ(void)
{
  unsigned _cpsr;

  _cpsr = __get_cpsr();
  __set_cpsr(_cpsr & ~FIQ_MASK);
  return _cpsr;
}
