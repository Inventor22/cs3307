#ifndef SENSOR_H
#define SENSOR_H

#include <vector>
#include "Algorithm.h"

class Sensor {
private:
    std::vector<Algorithm> algorithms;

public:
    Sensor();
    ~Sensor();
    void attach(Algorithm algo);
    void detach(Algorithm algo);
    void notify(float a);
};

#endif