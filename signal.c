#include <msp430.h>

const char DISP[] = { 0b00111111, 0b00000110 };

int main(void) {
	// disable watchdog and run at 1Mhz
	WDTCTL  = WDTPW | WDTHOLD;
	BCSCTL1 = CALBC1_1MHZ;
	DCOCTL  = CALDCO_1MHZ;

	// use P2.6 and P2.7 normally
	P2SEL  &= ~(BIT6|BIT7);
	P2SEL2 &= ~(BIT6|BIT7);

	// initialize other things
	// TODO: set up display

	// TODO: set up P1.3 button

	// TODO: set up P2.7 button

	// TODO: green light

	// TODO: red light

	// TODO: blue light

	// put zero on display
	P2OUT = DISP[0];

	// TODO: initialize timer1

	// TODO: initialize timer0

	// we'll definitely need interrupts enabled
	__eint();

	for (;;) {
		// execute forever
		// TODO: blink red light
	}

	return 0;
}

#pragma vector=PORT1_VECTOR
__interrupt void BUTTON1(void)
{
	// TODO: go back to previous mode

	// debounce routine
	while (!(BIT3 & P1IN));
	__delay_cycles(32000);
	P1IFG &= ~BIT3;
}

#pragma vector=PORT2_VECTOR
__interrupt void BUTTON2(void)
{
	// TODO: go forward to next mode

	// debounce routine
	while (!(BIT7 & P2IN));
	__delay_cycles(32000);
	P2IFG &= ~BIT7;
}

#pragma vector=TIMER1_A0_VECTOR
__interrupt void TIMER(void)
{
	// TODO: what should timer do?
}
