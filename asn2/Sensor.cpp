#include "Sensor.h"
#include "syslog.h"
#include <stdlib.h>
#include <algorithm>

Sensor::Sensor() {
    syslog(LOG_DEBUG, "Sensor Constructor");
}

Sensor::~Sensor() {
    syslog(LOG_DEBUG, "Sensor Destructor");
}

void Sensor::attach(Algorithm a) {
    syslog(LOG_DEBUG, "Sensor attach");
    algorithms.push_back(a);
}

void Sensor::detach(Algorithm a) {
    syslog(LOG_DEBUG, "Sensor detach");
    algorithms.resize(std::remove(algorithms.begin(), algorithms.end(), a) - algorithms.begin());
}

void Sensor::notify(float a) {
    syslog(LOG_DEBUG, "Sensor notify");
    std::vector<Algorithm>::iterator i = algorithms.begin();
    for (; i != algorithms.end(); ++i) {
        i->update(a);
    }
}