#include <sys/syslog.h>
#include "HumiditySensor.h"

HumiditySensor::HumiditySensor() {
    syslog(LOG_DEBUG, "Entered HumiditySensor()");

}

HumiditySensor::~HumiditySensor() {
    syslog(LOG_DEBUG, "Entered ~HumiditySensor()");
}

int HumiditySensor::getHumidity() {
    syslog(LOG_DEBUG, "Entered getHumidity()");
    int hum = 1;
    notify(hum);
    return hum;
}