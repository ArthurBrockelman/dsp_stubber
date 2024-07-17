#include "../../libs/AudioFile/AudioFile.h"
#include "../include/DSPExperiment1.h"
#include "../include/Smoother.h"
#include <iostream>

int main() {
    DSPExperiment1 dsp{"/Users/arthurbrockelman/Ableton Stuff/SamplePacks/Nasko Patreon Sample Pack Vol. 22/N-Spectral Bass Glitch 08 E.wav"};
    // Smoother smoother{.1, 10};
    // dsp.Puke(44100);
    dsp.processBlock();
    dsp.SaveFile("./output.wav");
    return 0;
}