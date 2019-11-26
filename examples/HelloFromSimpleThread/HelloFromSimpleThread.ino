/*
  HelloFromSimpleThread.ino

  This sketch prints a message to the Serial Monitor from a thread.
  
  Created 25/11/2019
  By Carmine D'Alessandro

  https://github.com/CarmineDAlessandro/Arduino-Simple-Threads-Library

*/


#include "ArduinoSimpleThreads.h"
#define NUMBER_SIMPLE_THREADS 1

void helloFromThread_loop(){
  /*Run repeatedly*/
  Serial.println("Hello from Thread");
}

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  declareSimpleThread(helloFromThread_loop,
                      WITHOUT_SETUP_FUNCTION,
                      AS_SOON_AS_POSSIBLE,
                      STANDARD_PRIORITY);
}

void loop() {
  // put your main code here, to run repeatedly:

  /* 
   * The threads run always before the main
   * because this function is called a the
   * beginning of the loop(). However, the
   * first time the thread will not run
   * because it is not ready yet.
   */
  runSimpleThreads();
  Serial.println("Hello, always after the threads");
  Serial.println();

  delay(3000);
}
