#include "../../libs/AudioFile/AudioFile.h"
#include <string>

class DSPExperiment {
    public:
        DSPExperiment(std::string audioFilePath);
        void PrintSamples();
    private:
        AudioFile<double> _AF;
};