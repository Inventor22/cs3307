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