#include "../include/DSPExperiment.h"

int main() {
    DSPExperiment dsp{"/Users/arthurbrockelman/Ableton Stuff/SamplePacks/Nasko Patreon Sample Pack Vol. 22/N-Spectral Bass Glitch 08 E.wav"};
    dsp.SaveFile("./output.wav");
    return 0;
}