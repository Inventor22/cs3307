/* Name: Dustin Dobransky
ID: 250575030
Date: 12/11/14

Concrete Sensor definition, CS3307 Assignment 2
Specifically, a humidity sensor.

Description:
This is a declaration for the humidity sensor class, a subclass of Sensor.

The sensor should return the relative humidity of the soil from [0, 1],
no moisture to 100% humidity, respectively.

In this skeleton class, a value of 1 is always returned.

Each time the sensor calls the getHumidity() function, the subclass' notify function is also called.
The notify function will update the observers (the 'algorithms') with this new value.
*/
#include <sys/syslog.h>
#include "HumiditySensor.h"

/// <summary>
/// Initializes a new instance of the <see cref="HumiditySensor"/> class.
/// </summary>
HumiditySensor::HumiditySensor() {
    syslog(LOG_DEBUG, "Entered HumiditySensor()");

}

/// <summary>
/// Finalizes an instance of the <see cref="HumiditySensor"/> class.
/// </summary>
HumiditySensor::~HumiditySensor() {
    syslog(LOG_DEBUG, "Entered ~HumiditySensor()");
}

/// <summary>
/// Gets the humidity.
/// Also calls the notify function, from the super class.
/// </summary>
/// <returns>the humidity</returns>
int HumiditySensor::getHumidity() {
    syslog(LOG_DEBUG, "Entered getHumidity()");
    int hum = 1;
    notify(hum);
    return hum;
}