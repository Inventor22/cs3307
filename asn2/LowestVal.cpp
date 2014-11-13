#include "LowestVal.h"
#include <syslog.h>
#include <math.h>

LowestVal::LowestVal(){
    syslog(LOG_DEBUG, "Entered LowestVal::LowestVal()");
    state = infinity();
    syslog(LOG_DEBUG, "Exited LowestVal::LowestVal()");
    return;
}

LowestVal::~LowestVal(){}

void LowestVal::update(float updateVal){
    syslog(LOG_DEBUG, "Entered LowestVal::update()");
    if (updateVal < state){
        state = updateVal;
    }
    syslog(LOG_INFO, "State %f after update with %f", state, updateVal);
    syslog(LOG_DEBUG, "Exited LowestVal::update()");
    return;
}

float LowestVal::getState(){
    syslog(LOG_DEBUG, "Entered LowestVal::getState()");
    syslog(LOG_DEBUG, "Exited LowestVal::getState()");
    return state;
}