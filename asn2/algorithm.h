/*
    Algorithm - Our Observer Class

    Created by Andrew Simpson on 2014-11-11

    Written by Andrew Simpson

    Implements the sensor observer for our robot Observer Pattern.
    Superclass for the LowFreq and LowestVal algorithms.
 */

class Algorithm {
protected:

public:
    virtual void update();
};