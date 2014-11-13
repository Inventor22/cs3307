/* Name: Dustin Dobransky
ID: 250575030
Date: 12/11/14

Concrete Sensor declaration, CS3307 Assignment 2
Specifically, a humidity sensor.

Description:
This is a declaration for the hunidity sensor class, a subclass of Sensor.

The sensor should return the relative humidity of the soil from [0, 1],
no moisture to 100% humidity, respectively.

In this skeleton class, a value of 1 is always returned.

Each time the sensor calls the getHumidity() function, the subclass' notify function is also called.
The notify function will update the observers (the 'algorithms') with this new value.
*/

#ifndef HUMIDITYSENSOR_H
#define HUMIDITYSENSOR_H

#include "Sensor.h"
class HumiditySensor : public Sensor {
public:    
    HumiditySensor();    
    ~HumiditySensor();    
    int getHumidity();

private:    
    /// <summary>
    /// The humidity
    /// </summary>
    int humidity;
};

#endif