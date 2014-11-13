#include "IRSensor.h"

IRSensor::IRSensor() {
    /* initialize random seed: */
    srand(time(NULL));
}

int IRSensor::getDist() {
    return dist;
}

void IRSensor::readDist() {
    int dist = rand() % 100;
    notify(dist);
    return dist;
}
