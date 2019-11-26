/*
	ArduinoSimpleThreads.h

	Simple Arduino library to schedule functions pretending they are threads.
	
	Created 25/11/2019
	By Carmine D'Alessandro

	https://github.com/CarmineDAlessandro/Arduino-Simple-Threads-Library

*/


#ifndef ArduinoSimpleThreads_h
#define ArduinoSimpleThreads_h

#include "Arduino.h"

#ifndef NUMBER_SIMPLE_THREADS
#define NUMBER_SIMPLE_THREADS 10
#endif

#define AS_SOON_AS_POSSIBLE 0
#define DO_NOTHING_FUNCTION NULL
#define WITHOUT_SETUP_FUNCTION NULL

#define VERY_LOW_PRIORITY 	-200
#define LOW_PRIORITY		-100
#define STANDARD_PRIORITY 	0
#define HIGH_PRIORITY		100
#define VERY_HIGH_PRIORITY	200

void declareSimpleThread(void (*)(void),
                		 void (*)(void),
						 unsigned long,
						 int);

void runSimpleThreads();

#endif
