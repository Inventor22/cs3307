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
    IRSensor();
    ~IRSensor();
    int getDist();
    void readDist();
};

#endif
