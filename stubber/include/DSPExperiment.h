#include "../../libs/AudioFile/AudioFile.h"
#include <string>

class DSPExperiment {
    public:
        DSPExperiment(std::string audioFilePath);
        DSPExperiment(std::string audioFilePath, int blockSize);
        void PrintSamples();

        /*!
        * SaveFile()
        * Save the contents of 
        */
        void SaveFile(std::string filePath);

        /*!
        * processBlock()
        * Override this function with an algorithm that will process the
        * audio in the _AF audio file member.
        */
        virtual void processBlock(){};
        
        void unload();

        /*!
        * chunkify(unsigned sz);
        * Chunk the audio file into blocks comparable with JUCE's processBlock
        * function so the samples can be looped through in a similar manner.
        */
        std::vector<std::vector<std::vector<double>>> Chunkify(unsigned sz);

    protected:
        AudioFile<double> _AF;
    
};