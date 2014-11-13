/* Name: Dustin Dobransky
ID: 250575030
Date: 12/11/14

Concrete Sensor declaration, CS3307 Assignment 2
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
