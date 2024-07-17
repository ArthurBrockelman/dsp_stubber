#include <vector>
#include <cmath>
#include "Smoother.h"
#include <iostream>

Smoother::Smoother(double threshold, int smoothingwindow) {

    _threshold = threshold;
    _smoothingwindow = smoothingwindow;
}

std::vector<double> Smoother::Smooth(std::vector<double>& samples) {
    int samplesInserted = 0;
    for(int sample = 0; sample < samples.size(); sample++) {
        std::cout << samples.size() << "\n";
        std::cout << samplesInserted << "\n";
        if(sample != 0 && sample != samples.size()) {
            double gap = abs(samples[sample + samplesInserted] - samples[sample + samplesInserted + 1]);
            if(gap > _threshold) {
                for(int inserts = 1; inserts <= _smoothingwindow; inserts++) {
                    samplesInserted++;
                    double sampleToInsert = (gap / _smoothingwindow) * inserts;
                    samples.insert(samples.begin() + sample + samplesInserted, sampleToInsert);
                }
            }
        }
    }
    return samples;
}