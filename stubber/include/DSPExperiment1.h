#include "DSPExperiment.h"
#include <string>

class DSPExperiment1 : public DSPExperiment {
    public:
        DSPExperiment1(std::string audioFilePath);
        DSPExperiment1(std::string audioFilePath, int blockSize);

        void processBlock() override;
};