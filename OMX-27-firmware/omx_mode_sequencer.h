#pragma once

#include "omx_mode_interface.h"

class OmxModeSequencer : public OmxModeInterface
{
public:
    OmxModeSequencer() {}
    ~OmxModeSequencer() {}

    void InitSetup() override;

    void initPatterns(); // Initializes all patterns

    void onModeActivated() override;

    void OnPotChanged(int potIndex, int potValue) override;

    void loopUpdate() override;

    // Should be part of LED update, intertangled with the sequencer class which is calling it in main FW code.
    void showCurrentStep(int patternNum);

    void updateLEDs() override;

    void onEncoderChanged(Encoder::Update enc) override;
    void onEncoderButtonDown() override;
    void onEncoderButtonDownLong() override;

    bool shouldBlockEncEdit() override;

    void onKeyUpdate(OMXKeypadEvent e) override;
    void onKeyHeldUpdate(OMXKeypadEvent e) override;

    void onDisplayUpdate() override;

    void setSeq1Mode()
    {
        seq2Mode = false;
    }

    void setSeq2Mode()
    {
        seq2Mode = true;
    }

private:
    bool initSetup = false;
    bool seq2Mode = false;

    // bool omxseqpatternParams = false;
    // bool omxseqseqPages = false;

    // bool omxseqnoteSelect = false;
    // bool omxseqnoteSelection = false;

    // int omxseqselectedNote = 0;
    // int omxSeqSelectedStep = 0;
    // bool omxseqstepSelect = false;
    // bool omxseqstepRecord = false;
    // bool omxseqstepDirty = false;

    // int omxSeqnspage = 0;
    // int omxSeqpppage = 0;
    // int omxSeqsqpage = 0;
    // int omxSeqsrpage = 0;

    // int omxSeqnsparam = 0; // note select params
    // int omxSeqppparam = 0; // pattern params
    // int omxSeqsqparam = 0; // seq params
    // int omxSeqsrparam = 0; // step record params

    // volatile unsigned long noteon_micros;
    // volatile unsigned long noteoff_micros;

    // These do not appear to be used
    bool copiedFlag = false;
    bool pastedFlag = false;
    bool clearedFlag = false;

    void onEncoderChangedNorm(Encoder::Update enc);
    void onEncoderChangedStep(Encoder::Update enc);

};