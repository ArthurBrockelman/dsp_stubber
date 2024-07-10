#include "DSPExperiment.h"

DSPExperiment::DSPExperiment(std::string audioFilePath) {
    AudioFile<double> audioFile;
    audioFile.load(audioFilePath);
    audioFile.printSummary();
    _AF = audioFile;
}

DSPExperiment::DSPExperiment(std::string audioFilePath, int blockSize) {
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

void DSPExperiment::unload() {
    std::vector<std::vector<double>> samples = _AF.samples;
    for (std::vector<double>& channel : samples) {
        for(double sample : channel) {
            std::cout << sample;
        }
    }
};

std::vector<std::vector<double>> DSPExperiment::chunkify(int sz){
    std::vector<std::vector<double>> chunks;
    //assert( _AF.samples.size() % sz == 0 );
    for (std::vector<double>& channel : _AF.samples) {
        auto it = channel.begin();
        while( it != channel.end() ) {
            chunks.emplace_back( it, it + sz );
            it += sz;
        }
    }
    return chunks;
}


void DSPExperiment::SaveFile() {
    _AF.save("./output.wav");
}



