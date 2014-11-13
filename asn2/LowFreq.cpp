#include "LowFreq.h"
#include <syslog.h>

LowPass::LowPass(){
    syslog(LOG_DEBUG, "Entered LowPass::LowPass()");
    state = 0;
    syslog(LOG_DEBUG, "Exited LowPass::LowPass()");
    return;
}

void LowPass::update(float updateVal){
    syslog(LOG_DEBUG, "Entered LowPass::update()");
    state = state*0.75 + updateVal*0.25;
    syslog(LOG_DEBUG, "Exited LowPass::update()");
    return;
}

float LowPass::getState(){
    syslog(LOG_DEBUG, "Entered LowPass::getState()");
    syslog(LOG_DEBUG, "Exited LowPass::getState()");
    return state;
}