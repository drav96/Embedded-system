#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>



// Interrupt Routines

uint32_t counter = 0;

// timer0 overflow
ISR(TIMER1_OVF_vect) {
   // XOR PORTA with 0x01 to toggle the second bit up
    turn_off(0);
	turn_off(1);
	turn_off(2);
	turn_off(3);
	turn_off(4);
	turn_off(5);
	toggle_led(counter);
	counter++;
	
	if(counter >= 6) {
		counter = 0;
	}
	
	
}

int main( void ) {
    // Configure PORTA as output
    DDRA = 0xFF;
    PORTA = 0x00;
	
    // enable timer overflow interrupt for both Timer0 and Timer1
    TIMSK=(1<<TOIE0) | (1<<TOIE1);
    // set timer0 counter initial value to 0
    TCNT1=0x00;

    TCCR1B |= (1 << CS01);
    // enable interrupts
    sei();
    while(1) {
    }
}
