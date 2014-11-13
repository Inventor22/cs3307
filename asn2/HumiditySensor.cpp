#include "HumiditySensor.h"

HumiditySensor::HumiditySensor() {

}

int HumiditySensor::getHumidity() {
    int hum = 1;
    notify(hum);
    return hum;
}