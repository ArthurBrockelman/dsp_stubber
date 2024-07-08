#include "../../libs/AudioFile/AudioFile.h"
#include "../../libs/loris/src/loris.h.in"
#include "../../libs/loris/src/Analyzer.h"

#include <iostream>

int main() {
    AudioFile<double> audioFile;
    audioFile.load("/Users/arthurbrockelman/Ableton Stuff/SamplePacks/DATABROTH COMPOUND-FREE/DATABROTH COMPOUND-FREE/Amplifier Feedback.wav");
    audioFile.printSummary();
    int channel = 0;
    int numSamples = audioFile.getNumSamplesPerChannel();
    for (int i = 0; i < numSamples; i++)
    {
        double currentSample = audioFile.samples[channel][i];
        std::cout << currentSample;
    }
    double buffer[audioFile.getNumSamplesPerChannel()];
    std::copy(audioFile.samples[0].begin(), audioFile.samples[0].end(), buffer);

    Loris::Analyzer A{500};
    A.analyze(audioFile.samples[0], audioFile.getSampleRate());
    return 0;
}