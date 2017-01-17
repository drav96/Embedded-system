#define F_CPU 8000000UL
#include "drivers/lm20.h"
#include "LCD.h"
#include <util/delay.h>

int main(void)
{
	//char ch;
	int ADCvalue = 0;
	int tempCelsius = 0;
	int tempFahrenheit = 0;
	float param0 = 2.4;
	int param = 382;
	char buffer[10];
	
	LM20_init();
	lcd_init(LCD_DISP_ON);

	while(1)
	{
		ADCvalue = LM20_GetTemp();
		tempCelsius = (param - ADCvalue) / param0;
		itoa(tempCelsius, buffer, 10); // converts tempCelsius numeric value into a string and stores it in buffer, base 10
		tempFahrenheit = tempCelsius * 1.8 + 32; // formula of Celsius - Fahrenheit conversion
		lcd_clrscr();
		lcd_puts(buffer);
		lcd_puts(" Celsius");
		itoa(tempFahrenheit, buffer, 10);
		lcd_gotoxy(0,1); // go to new line
		lcd_puts(buffer);
		lcd_puts(" Fahrenheit");
		_delay_ms(50);
	}
}
