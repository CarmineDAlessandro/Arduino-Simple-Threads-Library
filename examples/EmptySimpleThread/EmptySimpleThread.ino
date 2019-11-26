/*
  DelaySimpleThreads.ino

  This sketch creates 3 threads and schedules them with 3 different
  times. Each thread prints on the Serial Monitor each: 1 second, 5 
  seconds, 10 seconds. To better understand the timing, enable the 
  date print of the Serial Monitor and change the delay() time at
  the end of the loop.
  
  Created 25/11/2019
  By Carmine D'Alessandro

  https://github.com/CarmineDAlessandro/Arduino-Simple-Threads-Library

*/


#include "ArduinoSimpleThreads.h"

void noLoopThread_setup(){
  /*Run once, when declaring the thread*/
  Serial.println("Even if I have no loop, I am executed anyway");
}


void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);

  /*Use 0 threads
    because the threads with no loop function do not count as a thread
  */
  if(usingSimpleThreads(0) == SIMPLE_THREAD_ERROR)
  {
    Serial.println("Error during thread definition");
    exit(1);
  }

  if(declareSimpleThread(DO_NOTHING_FUNCTION,
                      noLoopThread_setup,
                      AS_SOON_AS_POSSIBLE,
                      STANDARD_PRIORITY) == SIMPLE_THREAD_ERROR)
  {
    Serial.println("Error during thread declaration");
    exit(1);
  }
      
}

void loop() {
  // put your main code here, to run repeatedly:

  /*Execute the loop of the thread*/
  runSimpleThreads();

  Serial.println("I am doing nothing important");
  
  delay(2000);
}
