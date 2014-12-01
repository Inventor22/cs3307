#include "LowFreq.h"
#include <syslog.h>


/*
    Constructor

    Set initial state to zero - it will disappear after
    a sufficient number of readings.
 */
LowFreq::LowFreq(){
    syslog(LOG_DEBUG, "Entered LowFreq::LowFreq()");
    state = 0;
    syslog(LOG_DEBUG, "Exited LowFreq::LowFreq()");
    return;
}

/*
    Destructor

    Nothing special to do - leave the body empty.
 */
LowFreq::~LowFreq(){
    syslog(LOG_DEBUG, "Entered LowestVal::~LowestVal()");
    syslog(LOG_DEBUG, "Exited LowestVal::~LowestVal()");
    return;
}

/*
    update

    Function called by the subject's notify function to let the
    observer know that the state has changed.

    Take the weighted average of the last state and the update
    reading, then save that as the current state.
 */
void LowFreq::update(float updateVal){
    syslog(LOG_DEBUG, "Entered LowFreq::update()");
    state = state*0.75 + updateVal*0.25;
    syslog(LOG_INFO, "State is %f after with %f", state, updateVal);
    syslog(LOG_DEBUG, "Exited LowFreq::update()");
    return;
}

/*
    getState

    Just returns the current state to the caller.
 */
float LowFreq::getState(){
    syslog(LOG_DEBUG, "Entered LowFreq::getState()");
    syslog(LOG_DEBUG, "Exited LowFreq::getState()");
    return state;
}