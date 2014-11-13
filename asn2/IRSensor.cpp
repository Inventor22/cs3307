#include "IRSensor.h"

IRSensor::IRSensor() {
    /* initialize random seed: */
    srand(time(NULL));
}

int IRSensor::getDist() {
    return dist;
}

void IRSensor::readDist() {
    return rand() % 100;
}