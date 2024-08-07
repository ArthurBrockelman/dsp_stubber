#include "DSPExperiment.h"
#include <gtest/gtest.h>
#include <iostream>

namespace dsp_stubber_test {
  TEST(DSPExperiment, Chunkify) {
    DSPExperiment dsp{"../../test/testfiles/input.wav"};
    std::vector<std::vector<std::vector<double>>> vec = dsp.Chunkify(1024);
    assert(vec.size() == 2);
    assert(vec[1][1].size() == 1024);
  };
  TEST(DSPExperiment, PrintSamples) {
    DSPExperiment dsp{"../../test/testfiles/input.wav"};
    dsp.PrintSamples();
  }; 
}