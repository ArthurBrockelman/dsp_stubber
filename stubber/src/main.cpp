#include "../../libs/AudioFile/AudioFile.h"
#include "../include/DSPExperiment1.h"

#include <iostream>

int main() {
    DSPExperiment1 dsp{"/Users/arthurbrockelman/Ableton Stuff/SamplePacks/SPORE/SPORE_SAMPLES/AvalonSpore3.wav"};
    dsp.Puke(44100);
    dsp.SaveFile("./output.wav");
    dsp.processBlock();
    return 0;
}