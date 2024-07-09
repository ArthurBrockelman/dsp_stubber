#include "../../libs/AudioFile/AudioFile.h"
#include <string>

class DSPExperiment {
    public:
        DSPExperiment(std::string audioFilePath);;
        DSPExperiment(std::string audioFilePath, int blockSize);
        void PrintSamples();
        void SaveFile();
        virtual void processBlock(){};
    protected:
        AudioFile<double> _AF;
};