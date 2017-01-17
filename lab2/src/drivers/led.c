
#include "led.h"

void LedInit(struct LedDevice *device){
	*(device->ddr) |= 1 << device->pinIndex;
}

void LedOn(struct LedDevice *device){
	*(device->port) &= ~(1<< device->pinIndex);	
}

void LedOff(struct LedDevice *device){
	*(device->port) |= (1<< device->pinIndex);
}