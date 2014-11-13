/*
    Robot - Observer Design Pattern Demonstrator

    Created by Andrew Simpson on 2014-11-11

    Written by Andrew Simpson and Dustin Dobransky

    This is the main file of
 */

#include <syslog.h>
#include <stdlib.h>

/*
    The main function of our program.
 */
int main(int argc, char** argv){

    //Start logging
    openlog("robot_tester", LOG_PERROR | LOG_PID | LOG_NDELAY, <#(int)#>LOG_USER);
    int log_level = LOG_DEBUG;
    setlogmask(log_level);

    //Arguments are unused for now
    if(argc < 0){
        syslog(LOG_ERR, "Too few arguments!");
    }

    //Create some sensors


    //Create some algorithms


    //Attach senors to algorithms


    //Do some updates


    //Kill an algorithm


    //Kill a sensor


    //End logging
    closelog();

    //End
    return EXIT_SUCCESS;
}