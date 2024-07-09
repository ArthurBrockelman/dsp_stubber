#include "DSPExperiment1.h"
#include <iostream>

DSPExperiment1::DSPExperiment1(std::string audioFilePath) : DSPExperiment(audioFilePath) {
   
};

DSPExperiment1::DSPExperiment1(std::string audioFilePath, int blockSize) : DSPExperiment(audioFilePath) {
   
};

void DSPExperiment1::processBlock() {
    std::cout << _AF.isMono();
};