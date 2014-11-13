/*
    LowestVal - Concrete Observer

    Created by Andrew Simpson on November 2014-11-12

    Written by Andrew Simpson

    A concrete observer - just keeps a copy of the lowest value
    from the sensor it's attached to.
*/

#include "Algorithm.h"

class LowestVal : public Algorithm{
private:
    //Stores the current state of the algorithm
    float state;
public:
    //Constructor
    LowestVal();
    //Destructor
    ~LowestVal();
    //Update function called by subject (sensor)
    void update(float);
    //Returns current state
    float getState();
};