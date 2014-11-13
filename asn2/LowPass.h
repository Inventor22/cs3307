/*
    LowPass - Concrete Observer

    Created by Andrew Simpson on November 2014-11-12

    A concrete observer - just a low pass filter for the sensor it's attached to.
*/

class LowPass : public Algorithm{
private:
    float state;
public:
    void update(float);
    float getState;
};