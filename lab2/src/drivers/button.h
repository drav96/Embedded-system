


#ifndef BUTTON_H_
#define BUTTON_H_
#include <avr/io.h>

struct ButtonDevice {
	uint8_t pinIndex;
	volatile uint8_t *pin;
	volatile uint8_t *ddr;
};

void ButtonInit(struct ButtonDevice *device);
char ButtonPressed(struct ButtonDevice *device);

#endif /* BUTTON_H_ */