#include "DSPExperiment1.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "../../libs/AudioFile/AudioFile.h"

template <typename E,typename X>
void unroll(const std::vector<E>& v,std::vector<X>& out){
    out.insert(out.end(), v.begin(), v.end());
}


template <typename V,typename X>
void unroll(const std::vector<std::vector<V>>& v,std::vector<X>& out) {
    for (const auto& e : v) unroll(e,out);
}

DSPExperiment1::DSPExperiment1(std::string audioFilePath) : DSPExperiment(audioFilePath) {
   
};

DSPExperiment1::DSPExperiment1(std::string audioFilePath, int blockSize) : DSPExperiment(audioFilePath, blockSize) {
   
};

void DSPExperiment1::processBlock() {
    std::cout << _AF.isMono();
};

void DSPExperiment1::Puke(int chunksize) {
    std::vector<std::vector<std::vector<double>>> chunked = DSPExperiment1::Chunkify(chunksize);
    auto rd = std::random_device {}; 
    auto rng = std::default_random_engine { rd() };
    std::vector<std::vector<double>> channel1 = chunked[0];
    std::vector<std::vector<double>> channel2 = chunked[1];
    std::shuffle(std::begin(channel1), std::end(channel1), rng);
    std::shuffle(std::begin(channel2), std::end(channel2), rng);
    std::vector<double> randomizedchannel1{};
    std::vector<double> randomizedchannel2{};
    unroll(channel1, randomizedchannel1);
    unroll(channel2, randomizedchannel2);
    _AF.samples = std::vector{randomizedchannel1, randomizedchannel2};
}

void DSPExperiment1::Smooth(int chunksize, double threshold, int smoothingwindow) {
    DSPExperiment1::Puke(chunksize);
    std::vector<std::vector<double>> samples = _AF.samples;
    std::vector<double> randomizedchannel1 = samples[0];
    std::vector<double> randomizedchannel2 = samples[1];
    for(double sample : randomizedchannel1) {
         
    }
}



