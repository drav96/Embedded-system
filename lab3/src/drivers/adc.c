#include <avr/io.h>

void ADC_init()
{
	ADMUX = (1 << REFS0); // selecting the reference voltage
	ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0); // enable ADC with Prescaler=Fcpu/128
}

int ADC_GetData(char channel)
{
	while(ADCSRA & 1 << ADSC); //wait until ADC is busy
	channel &= 0b00000111; //normalize the channel, leave last 3 bits LSB
	ADMUX = (ADMUX & ~(0b00000111)) | channel; //apply the channel to the ADMUX with protection of configuration bits
	ADCSRA |= (1<<ADSC); //start conversion
	while (ADCSRA & (1<<ADSC)); //wait until conversion is complete
	return (ADC);
}
