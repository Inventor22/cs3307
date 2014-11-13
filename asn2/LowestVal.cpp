#include "LowestVal.h"
#include <syslog.h>
#include <math.h>

/*
    Constructor

    Set initial state to inifinity - that way the first reading
    will always become the lowest reading.
 */
LowestVal::LowestVal(){
    syslog(LOG_DEBUG, "Entered LowestVal::LowestVal()");
    state = infinity();
    syslog(LOG_DEBUG, "Exited LowestVal::LowestVal()");
    return;
}

/*
    Destructor

    Nothing special to do - just log destruction.
 */
LowestVal::~LowestVal(){
    syslog(LOG_DEBUG, "Entered LowestVal::~LowestVal()");
    syslog(LOG_DEBUG, "Exited LowestVal::~LowestVal()");
    return;
}

/*
    update

    Function called by the subject's notify function to let the
    observer know that the state has changed.

    Save the updated value if it is less than the stored one.
 */
void LowestVal::update(float updateVal){
    syslog(LOG_DEBUG, "Entered LowestVal::update()");
    if (updateVal < state){
        state = updateVal;
    }
    syslog(LOG_INFO, "State %f after update with %f", state, updateVal);
    syslog(LOG_DEBUG, "Exited LowestVal::update()");
    return;
}

/*
    getState

    Just returns the current state to the caller.
 */
float LowestVal::getState(){
    syslog(LOG_DEBUG, "Entered LowestVal::getState()");
    syslog(LOG_DEBUG, "Exited LowestVal::getState()");
    return state;
}