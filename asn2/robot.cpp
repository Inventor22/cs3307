/*
    Robot - Observer Design Pattern Demonstrator

    Created by Andrew Simpson on 2014-11-11

    Written by Andrew Simpson and Dustin Dobransky

    This is the main file of our demonstration.
 */

#include <syslog.h>
#include <stdlib.h>
#include "IRSensor.h"
#include "HumiditySensor.h"
#include "LowestVal.h"
#include "LowFreq.h"

/*
    The main function of our program.
 */
int main(int argc, char** argv){

    //Start logging
    openlog("robot", LOG_PERROR | LOG_PID | LOG_NDELAY, LOG_USER);
    //int log_level = LOG_DEBUG;
    //setlogmask(log_level);

    //Log start
    syslog(LOG_DEBUG, "Stating main.");

    //Arguments are unused for now
    if(argc < 0){
        syslog(LOG_ERR, "Too few arguments!");
    }
    //Force objects to be destroyed before closing log
    {
        //Create some sensors
        IRSensor myIR;
        HumiditySensor myHum;

        //Create some algorithms
        LowestVal lowestIR; //= new LowestVal();
        LowFreq lowFreqIR; //= new LowFreq();
        LowestVal lowestHum; //= new LowestVal();
        LowFreq lowFreqHum; //= new LowFreq();

        //Attach senors to algorithms
        myIR.attach(&lowestIR);
        myIR.attach(&lowFreqIR);
        myHum.attach(&lowestHum);
        myHum.attach(&lowFreqHum);

        //Do some updates
        for (int i = 0; i < 5; i++) {
            myIR.readDist();
            myHum.getHumidity();
        }

        //Kill an algorithm
        myHum.detach(&lowestHum);

        //Kill a sensor
        myIR.detach(&lowestIR);
        myIR.detach(&lowFreqIR);
    }
    //End logging
    syslog(LOG_DEBUG, "End of logging.");
    closelog();

    //End
    return EXIT_SUCCESS;
}
