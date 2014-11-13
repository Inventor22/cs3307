#include <sys/syslog.h>
#include "IRSensor.h"

IRSensor::IRSensor() {
    syslog(LOG_INFO, "IRSensor Constructor");
    /* initialize random seed: */
    srand(time(NULL));
}

int IRSensor::getDist() {
    syslog(LOG_INFO, "IRSensor getDist");
    return dist;
}

void IRSensor::readDist() {
    syslog(LOG_INFO, "IRSensor readDist");
    int dist = rand() % 100;
    notify(dist);
    return;
}
