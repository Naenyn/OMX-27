#pragma once

#include <stdint.h>

#include "../config.h"

uint32_t potBankAuxColor(uint8_t bankIndex);

void potBankAuxPreviewColors(uint8_t currentBank, uint32_t *out13, uint32_t *out14);

void potBankAuxTriggerFlash(uint8_t newBankIndex);

void potBankAuxClearFlash();

// Call from updateLEDs while AUX bank UI active. If returns true, set LEDs 13&14 to color (or LEDOFF when false).
bool potBankAuxPollFlash(uint32_t *outColor, bool *ledsLit);
