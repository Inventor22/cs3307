cs3307 - Assignment 2 - Observer Pattern
========================================

This is the skeleton code to demonstrate our design for the design patterns assignment of UWO's cs3307.

It consists of 3 main parts:

robot
-----
The skeleton system. Has sensors that receive readings. Various algorithms use these readings.

sensor
------
The subject of our model. A sensor can be watched by many algorithms.

algorithm
---------
The observer of our model. Watches one or more sensors and uses their output to produce its own.

Building the Software
=====================

This code was made to be portable - it should work on any Linux system that supports syslog.
Our test platform was an Ubuntu 14.04 VM.

To build, just:
- Naviagte to the 'directory' with a terminal
- Run 'cmake .'
- Run 'make'

That should build the program. To run, type:
./robotSim