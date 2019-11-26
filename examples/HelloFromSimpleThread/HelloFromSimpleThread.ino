/*
  HelloFromSimpleThread.ino

  This sketch prints a message to the Serial Monitor from a thread.
  
  Created 25/11/2019
  By Carmine D'Alessandro

  https://github.com/CarmineDAlessandro/Arduino-Simple-Threads-Library

*/


#include "ArduinoSimpleThreads.h"

void helloFromThread_setup(){
  /*Run once, when declaring the thread*/
  Serial.println("Hello from Thread Setup");
}

void helloFromThread_loop(){
  /*Run repeatedly*/
  Serial.println("Hello from Thread Loop");
}

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);

  /*Use one thread*/
  if(usingSimpleThreads(1) == SIMPLE_THREAD_ERROR)
  {
    Serial.println("Error during thread definition");
    exit(1);
  }

  /*Declare the therad*/
  if(declareSimpleThread(helloFromThread_loop,
                          helloFromThread_setup,
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

  delay(2000);
}
