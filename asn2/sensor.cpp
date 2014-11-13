#include "Sensor.h"
#include "syslog.h"

Sensor::Sensor() {
    syslog(LOG_INFO, "Sensor Constructor");
}

Sensor::~Sensor() {
    syslog(LOG_INFO, "Sensor Destructor");
}

void Sensor::attach(Algorithm a) {
    syslog(LOG_INFO, "Sensor attach");
    algorithms.push_back(a);
}

void Sensor::detach(Algorithm a) {
    syslog(LOG_INFO, "Sensor detach");
    algorithms.resize(std::remove(algorithms.begin(), algorithms.end(), a) - algorithms.begin());
}

void Sensor::notify(float a) {
    syslog(LOG_INFO, "Sensor notify");
    std::vector<Algorithm>::iterator i = algorithms.begin();
    for (; i != algorithms.end(); ++i) {
        i->update(a);
    }
}