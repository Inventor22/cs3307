#include <sys/syslog.h>
#include "HumiditySensor.h"

HumiditySensor::HumiditySensor() {
    syslog(LOG_INFO, "HumiditySensor Constructor");

}

int HumiditySensor::getHumidity() {
    syslog(LOG_INFO, "HumiditySensor getHumidity");
    int hum = 1;
    notify(hum);
    return hum;
}