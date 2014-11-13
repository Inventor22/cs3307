#include <sys/syslog.h>
#include "IRSensor.h"

IRSensor::IRSensor() {
    syslog(LOG_DEBUG, "IRSensor Constructor");
    /* initialize random seed: */
    srand(time(NULL));
}

IRSensor::~IRSensor() {
    syslog(LOG_DEBUG, "Entered ~IRSensor");
}

int IRSensor::getDist() {
    syslog(LOG_DEBUG, "IRSensor getDist");
    return dist;
}

void IRSensor::readDist() {
    syslog(LOG_DEBUG, "IRSensor readDist");
    int dist = rand() % 100;
    notify(dist);
    return;
}
