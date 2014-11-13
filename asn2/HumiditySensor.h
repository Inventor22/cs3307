#ifndef HUMIDITYSENSOR_H
#define HUMIDITYSENSOR_H

#include "Sensor.h"

class HumiditySensor : public Sensor {
public:
    HumiditySensor();
    int getHumidity();

private:
    int humidity;
};

#endif