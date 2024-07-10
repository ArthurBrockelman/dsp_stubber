#include "../../libs/AudioFile/AudioFile.h"
#include <string>

class DSPExperiment {
    public:
        DSPExperiment(std::string audioFilePath);;
        DSPExperiment(std::string audioFilePath, int blockSize);
        void PrintSamples();
        void SaveFile();
        virtual void processBlock(){};
        void unload();
        std::vector<std::vector<double>> chunkify(int sz);
    protected:
        AudioFile<double> _AF;
};