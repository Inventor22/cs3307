/* Name: Dustin Dobransky
   Date: 12/11/14
   
   Sensor implementation, CS3307 Assignment 2

   Description:
        This is an implementation for the base sensor class.
   The observer pattern is used:  For every sensor, there is an
   associated list of algorithms which run.
   Each concrete sensor class (sub class of Sensor) makes a call to 
   method 'notify' when the sensor performs a new reading.  Therefore,
   all attached algorithms are immediately updated with the newest sensor data
   as soon as its collected.
*/

#include "Sensor.h"
#include "syslog.h"
#include <stdlib.h>
#include <algorithm>

/// <summary>
/// Initializes a new instance of the <see cref="Sensor"/> class.
/// </summary>
Sensor::Sensor() {
    syslog(LOG_DEBUG, "Sensor Constructor");
}

/// <summary>
/// Finalizes an instance of the <see cref="Sensor"/> class.
/// </summary>
Sensor::~Sensor() {
    syslog(LOG_DEBUG, "Sensor Destructor");
}

/// <summary>
/// Attaches the specified algo.
/// </summary>
/// <param name="algo">The algo.</param>
void Sensor::attach(Algorithm* a) {
    syslog(LOG_DEBUG, "Sensor attach");
    algorithms.push_back(a);
}

/// <summary>
/// Detaches the specified algo.
/// </summary>
/// <param name="algo">The algo.</param>
void Sensor::detach(Algorithm* a) {
    syslog(LOG_DEBUG, "Sensor detach");
    algorithms.resize(std::remove(algorithms.begin(), algorithms.end(), a) - algorithms.begin());
}

/// <summary>
/// Notifies the observing algorithms to changes in sensor state.
/// i.e. When the sensor performs a new reading (update), it notifies all
/// observing algorithms.
/// </summary>
/// <param name="a">The sensor value measured</param>
void Sensor::notify(float a) {
    syslog(LOG_DEBUG, "Sensor notify");
    std::vector<Algorithm*>::iterator i = algorithms.begin();
    for (; i != algorithms.end(); ++i) {
        (*i)->update(a);
    }
}