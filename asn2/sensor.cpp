#include "Sensor.h"

Sensor::Sensor() {}

Sensor::~Sensor() {}

void Sensor::attach(Algorithm a) {
    algorithms.push_back(a);
}

void Sensor::detach(Algorithm a) {
    algorithms.resize(std::remove(algorithms.begin(), algorithms.end(), a) - algorithms.begin());
}

void Sensor::update() {
    std::vector<algorithms>::iterator i = algorithms.begin();
    for (; i != algorithms.end(); ++i) {
        i->update();
    }
}