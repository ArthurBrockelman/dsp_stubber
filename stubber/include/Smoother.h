#pragma once
#include <vector>

class Smoother {
    

    public:
        Smoother(double threshold, int smoothingwindow);
        std::vector<double> Smooth(std::vector<double>& samples);
    private:
        int _chunksize;
        double _threshold;
        int _smoothingwindow;

};