# powers-calculator

This is an embedded software project.

Core functionality:
  - calculates fractional powers, e.g. 2.5^1.6
  - uses Newton's method to get to the answer iteration by iteration
  - can evaluate expressions, e.g. (429*(9394-(934+43/21))/3.14)-341.3*45.2-3.14
  - two microcontrollers - an Arduino Mega and an AT91SAM7EX-256
  - contains SAM7X256 initialization code
  - both MCUs can receive and transmit data to each other (important: with a level converter)

The following algorithms and data structures were implemented:
  - evaluating a string expression with two stacks, one for operators and one for operands
  - GCD of two numbers
  - Newton's method
  - finding the derivative of a function
  - balanced parantheses and valid arithmetic expression check
  - generic (with void*) stack implemented both with dynamic memory allocation and a static buffer
  - string implemented both with dynamic memory allocation and a static buffer
  - at one point a generic linked list was needed too

Serial communication between the two microcontrollers was implemented:
  - for transmitting additional symbols are appended for the beginning and the end of the strings and between the symbols.
  - on receiving the microcontroller only takes the characters between these symbols because it reads the pins much faster than the transmission lasts
  - Pushbottons are being connected so that the microcontroller can read values from them and prints them out to the LCD

Transmitter pin of the Arduino(TX1) is connected to the USART1 receiver of the Olimex board and vice versa. They are however not directly connected - there's a bi-directional level converter between them (5V-3.3V)

Structure:
  - pure_c contains the C code behind the project
  - UART_calculator-Keil contains C, assembly, linkers and other terrible formats needed for running the infernal MCU that SAM7EX256 is
  - UART_calculator-Arduino contains the last version of the project. The Olimex board only uses its display and the Arduino does the calculations instead of it, but there were tight deadlines in place... The code is also not the best, but it works. Communication also works.
