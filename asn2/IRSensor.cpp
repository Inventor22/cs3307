/* Name: Dustin Dobransky
ID: 250575030
Date: 12/11/14

Concrete Sensor implementation, CS3307 Assignment 2
Specifically, an infrared sensor.

Description:
This is a declaration for the infrared sensor class, a subclass of Sensor.
From the observer pattern, the sensor measures distance to an object using triangulation
of an infrared beam, then passes that value to the notify function of the parent class.
The notify function then updates all the algorithms with this new value so they may process
the changes.

In this implementation, a random value is returned, not actual distance.

Each time the sensor calls the readDist() function, the subclass' notify function is also called.
The notify function will update the observers (the 'algorithms') with this new value.
*/

#include <sys/syslog.h>
#include "IRSensor.h"

/// <summary>
/// Initializes a new instance of the <see cref="IRSensor"/> class.
/// </summary>
IRSensor::IRSensor() {
    syslog(LOG_DEBUG, "IRSensor Constructor");
    /* initialize random seed: */
    srand(time(NULL));
}

/// <summary>
/// Finalizes an instance of the <see cref="IRSensor"/> class.
/// </summary>
IRSensor::~IRSensor() {
    syslog(LOG_DEBUG, "Entered ~IRSensor");
}

/// <summary>
/// Gets the distance to an object in front of the sensor
/// </summary>
/// <returns>The distance</returns>
int IRSensor::getDist() {
    syslog(LOG_DEBUG, "IRSensor getDist");
    return dist;
}

/// <summary>
/// Reads the last recorded distance from the sensor.
/// also calls the notify function, which updates the
/// observing algorithms with the new value
/// </summary>
void IRSensor::readDist() {
    syslog(LOG_DEBUG, "IRSensor readDist");
    int dist = rand() % 100;
    notify(dist);
    return;
}
