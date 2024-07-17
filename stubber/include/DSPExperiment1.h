#include "DSPExperiment.h"
#include <string>
#include <random>
#include "../../libs/AudioFile/AudioFile.h"
#include "Smoother.h"
#include "CFxRbjFilter.h"

class DSPExperiment1 : public DSPExperiment {
    public:
        DSPExperiment1(std::string audioFilePath);
        DSPExperiment1(std::string audioFilePath, int blockSize);
        void Puke(int chunksize);
        void Smooth(Smoother& smoother);
        void processBlock() override;
};