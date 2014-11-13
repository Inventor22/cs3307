/*
    LowPass - Concrete Observer

    Created by Andrew Simpson on November 2014-11-12

    A concrete observer - just a low pass filter (averaging filter)
    for the sensor it's attached to.
*/

#include "Algorithm.h"

class LowPass : public Algorithm{
private:
    //Stores the current state of the algorithm
    float state;
public:
    //Constructor
    LowPass();
    //Update function called by subject (sensor)
    void update(float);
    //Returns current state
    float getState();
};