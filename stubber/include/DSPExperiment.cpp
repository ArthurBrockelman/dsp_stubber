#include "DSPExperiment.h"
#include <exception>
#include <algorithm>
#include <iterator>
#include <vector>

template<typename Vector>
auto split_vector(const Vector& v, unsigned number_lines) {
  using Iterator = typename Vector::const_iterator;
  std::vector<Vector> rtn;
  Iterator it = v.cbegin();
  const Iterator end = v.cend();

  while (it != end) {
    Vector v;
    std::back_insert_iterator<Vector> inserter(v);
    const auto num_to_copy = std::min(static_cast<unsigned>(
        std::distance(it, end)), number_lines);
    std::copy(it, it + num_to_copy, inserter);
    rtn.push_back(std::move(v));
    std::advance(it, num_to_copy);
  }

  return rtn;
}

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

std::vector<std::vector<std::vector<double>>> DSPExperiment::Chunkify(unsigned sz) {
    std::vector<std::vector<std::vector<double>>> chunks; 
    std::vector<std::vector<double>> samples = _AF.samples;
    std::vector<std::vector<double>> chunked0 = split_vector(samples[0], sz);
    std::vector<std::vector<double>> chunked1 = split_vector(samples[1], sz);
    chunks.push_back(chunked0);
    chunks.push_back(chunked1);
    return chunks;
}


void DSPExperiment::SaveFile(std::string filePath) {
    _AF.save(filePath);
}



