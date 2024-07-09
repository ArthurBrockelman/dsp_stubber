#include "DSPExperiment.h"

DSPExperiment::DSPExperiment(std::string audioFilePath) {
    AudioFile<double> audioFile;
    audioFile.load(audioFilePath);
    audioFile.printSummary();
    _AF = audioFile;
}

void DSPExperiment::PrintSamples() {
    int channel = 0;
    int numSamples = _AF.getNumSamplesPerChannel();
    for (int i = 0; i < numSamples; i++)
    {
        double currentSample = _AF.samples[channel][i];
        std::cout << currentSample << "\n";
    }
}

