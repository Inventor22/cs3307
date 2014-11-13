#include "LowFreq.h"
#include <syslog.h>

LowFreq::LowFreq(){
    syslog(LOG_DEBUG, "Entered LowFreq::LowFreq()");
    state = 0;
    syslog(LOG_DEBUG, "Exited LowFreq::LowFreq()");
    return;
}

void LowFreq::update(float updateVal){
    syslog(LOG_DEBUG, "Entered LowFreq::update()");
    state = state*0.75 + updateVal*0.25;
    syslog(LOG_DEBUG, "Exited LowFreq::update()");
    return;
}

float LowFreq::getState(){
    syslog(LOG_DEBUG, "Entered LowFreq::getState()");
    syslog(LOG_DEBUG, "Exited LowFreq::getState()");
    return state;
}