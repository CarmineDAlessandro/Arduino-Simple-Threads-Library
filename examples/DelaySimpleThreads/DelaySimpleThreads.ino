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

void fastMessage_loop(){
  /*Run repeatedly*/
  Serial.println("Fast");
}

void slowMessage_loop(){
  /*Run repeatedly*/
  Serial.println("    Slow");
}

void verySlowMessage_loop(){
  /*Run repeatedly*/
  Serial.println("        Very slow");
}

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);

  /*Use 3 threads*/
  if(usingSimpleThreads(3) == SIMPLE_THREAD_ERROR)
  {
    Serial.println("Error during thread definition");
    exit(1);
  }

  if(declareSimpleThread(fastMessage_loop,
                      WITHOUT_SETUP_FUNCTION,
                      1000L,  // 1 second
                      STANDARD_PRIORITY) == SIMPLE_THREAD_ERROR)
  {
    Serial.println("Error during thread declaration");
    exit(1);
  }
  
  if(declareSimpleThread(slowMessage_loop,
                      WITHOUT_SETUP_FUNCTION,
                      5000L,  // 5 seconds
                      STANDARD_PRIORITY) == SIMPLE_THREAD_ERROR)
  {
    Serial.println("Error during thread declaration");
    exit(1);
  }
  
  if(declareSimpleThread(verySlowMessage_loop,
                      WITHOUT_SETUP_FUNCTION,
                      10000L, // 10 seconds
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

  /*
  The delay() function influences the delay value of the 
  threads in the same way it influences the millis()
  count.

  In case of delay(500) or delay(1000), it would
  influence the print on the monitor because the delay
  function stops the whole program and may cause
  noise in the synchronization.
  */
  //delay(500);
  //delay(1000);
}
