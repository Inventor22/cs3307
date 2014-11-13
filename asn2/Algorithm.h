/*
    Algorithm - Our Observer Class

    Created by Andrew Simpson on 2014-11-11

    Written by Andrew Simpson

    Implements the sensor observer for our robot Observer Pattern.
    Superclass for the LowFreq and LowestVal algorithms.
 */

#ifndef _ALGORITHM_H
#define _ALGORITHM_H

class Algorithm {
protected:

public:
    //Constructor
    Algorithm(){}
    //Destructor
    ~Algorithm(){}
    //Update function called by subject (sensor)
    virtual void update(float) = 0;
    //Equality check operator - needed for sensor to
    //remove an algorithm from its list of subcribed
    //algorithms.
    inline bool operator==(const Algorithm& other){
        return this == &other;
    }
};

#endif