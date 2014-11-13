#ifndef IRSENSOR_H
#define IRSENSOR_H

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Sensor.h"

class IRSensor : public Sensor {
private:
    int dist;
public:
    IRSensor() {
        /* initialize random seed: */
        srand(time(NULL));
    }

    int getDist() {
        return dist;
    }

    void readDist() {
        return rand() % 100;
    }
};

#endif
