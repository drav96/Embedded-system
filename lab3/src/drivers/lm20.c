#include "adc.h"
#include <avr/io.h>

void LM20_init()
{
	ADC_init();
}

int LM20_GetTemp()
{
	ADC_GetData(7);
}
