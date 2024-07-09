#include "../../libs/AudioFile/AudioFile.h"
#include "../include/DSPExperiment1.h"

#include <iostream>

int main() {
    DSPExperiment1 dsp{"/Users/arthurbrockelman/Ableton Stuff/SamplePacks/DATABROTH COMPOUND-FREE/DATABROTH COMPOUND-FREE/Amplifier Feedback.wav", 1024};
    dsp.processBlock();
    return 0;
}