#ifndef SENSOR_H
#define SENSOR_H

#include <vector>
#include "Algorithm.h"

class Sensor : ISensor {
private:
    std::vector<Algorithm> algorithms;

public:
    void attach(Algorithm algo) = 0;
    void detach(Algorithm algo) = 0;
};

#endif