/* Name: Dustin Dobransky
ID: 250575030
Date: 12/11/14

Sensor declaration, CS3307 Assignment 2

Description:
This is the declaration for the base sensor class.
The observer pattern is used:  For every sensor, there is an
associated list of algorithms which run.
Each concrete sensor class (sub class of Sensor) makes a call to
method 'notify' when the sensor performs a new reading.  Therefore,
all attached algorithms are immediately updated with the newest sensor data
as soon as its collected.
*/

#ifndef SENSOR_H
#define SENSOR_H

#include <vector>
#include "Algorithm.h"

class Sensor {
private:    
    /// <summary>
    /// The vector to hold the (pointers to) algorithms which are updated with a call to notify
    /// The various algorithms operate on the sensor.  For example, a sensor may have a
    /// low pass filter algorithm attached.  Or, multiple algorithms.  One could be an averaging filter,
    /// another could be a low/high pass filter, or notch filter.
    /// </summary>
    std::vector<Algorithm*> algorithms;

public:    
    Sensor();    
    ~Sensor();
    
    void attach(Algorithm* algo);    
    void detach(Algorithm* algo);    
    void notify(float a);
};

#endif