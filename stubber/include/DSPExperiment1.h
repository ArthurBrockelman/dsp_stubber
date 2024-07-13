#include "DSPExperiment.h"
#include <string>
#include <random>
#include "../../libs/AudioFile/AudioFile.h"

class DSPExperiment1 : public DSPExperiment {
    public:
        DSPExperiment1(std::string audioFilePath);
        DSPExperiment1(std::string audioFilePath, int blockSize);
        void Puke(int chunksize);
        void Smooth(int chunksize, double threshold, int smoothingwindow);
        void processBlock() override;
};