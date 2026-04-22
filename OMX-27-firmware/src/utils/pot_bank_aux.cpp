#include "pot_bank_aux.h"

#include "../consts/colors.h"

#include <elapsedMillis.h>

namespace
{
	const uint32_t kBankColors[NUM_CC_BANKS] = {RED, YELLOW, WHITE, CYAN, BLUE};

	elapsedMillis flashElapsed;
	uint8_t flashBankIdx = 0;
	uint8_t flashPhase = 0;
	const uint8_t kFlashPhases = 6;
	bool flashActive = false;
}

uint32_t potBankAuxColor(uint8_t bankIndex)
{
	return kBankColors[bankIndex % NUM_CC_BANKS];
}

void potBankAuxPreviewColors(uint8_t currentBank, uint32_t *out13, uint32_t *out14)
{
	const uint8_t b = currentBank % NUM_CC_BANKS;
	*out13 = kBankColors[(b + NUM_CC_BANKS - 1) % NUM_CC_BANKS];
	*out14 = kBankColors[(b + 1) % NUM_CC_BANKS];
}

void potBankAuxTriggerFlash(uint8_t newBankIndex)
{
	flashBankIdx = newBankIndex % NUM_CC_BANKS;
	flashPhase = 0;
	flashActive = true;
	flashElapsed = 0;
}

void potBankAuxClearFlash()
{
	flashActive = false;
	flashPhase = 0;
}

bool potBankAuxPollFlash(uint32_t *outColor, bool *ledsLit)
{
	if (!flashActive || outColor == nullptr || ledsLit == nullptr)
	{
		return false;
	}

	if (flashPhase >= kFlashPhases)
	{
		flashActive = false;
		return false;
	}

	if (flashElapsed >= 70)
	{
		flashElapsed = 0;
		flashPhase++;
		if (flashPhase >= kFlashPhases)
		{
			flashActive = false;
			return false;
		}
	}

	*ledsLit = (flashPhase % 2) == 0;
	*outColor = potBankAuxColor(flashBankIdx);
	return true;
}
