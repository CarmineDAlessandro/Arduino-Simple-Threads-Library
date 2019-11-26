/*
  PrioritySimpleThreads.ino

  This sketch synchronizes 5 different threads using the
  different priorities setting and plots on the Serial
  Monitor a sentence made by the 5 functions.
  
  Created 25/11/2019
  By Carmine D'Alessandro

  https://github.com/CarmineDAlessandro/Arduino-Simple-Threads-Library

*/


#include "ArduinoSimpleThreads.h"
#define NUMBER_SIMPLE_THREADS 5

void firstWord_loop(){
  /*Run repeatedly*/
  Serial.print("The ");
}

void secondWord_loop(){
  /*Run repeatedly*/
  Serial.print("priority ");
}

void thirdWord_loop(){
  /*Run repeatedly*/
  Serial.print("is ");
}

void fourthWord_loop(){
  /*Run repeatedly*/
  Serial.print("important");
}

void newLine_loop(){
  /*Run repeatedly*/
  Serial.println();
}


void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);

  /*Declare in random order*/
  /*The highest priority, the first they are executed*/
  declareSimpleThread(fourthWord_loop,
                      WITHOUT_SETUP_FUNCTION,
                      AS_SOON_AS_POSSIBLE,
                      STANDARD_PRIORITY-3);
  declareSimpleThread(firstWord_loop,
                      WITHOUT_SETUP_FUNCTION,
                      AS_SOON_AS_POSSIBLE,
                      STANDARD_PRIORITY);
  declareSimpleThread(thirdWord_loop,
                      WITHOUT_SETUP_FUNCTION,
                      AS_SOON_AS_POSSIBLE,
                      STANDARD_PRIORITY-2);
  declareSimpleThread(newLine_loop,
                      WITHOUT_SETUP_FUNCTION,
                      AS_SOON_AS_POSSIBLE,
                      STANDARD_PRIORITY-4);
  declareSimpleThread(secondWord_loop,
                      WITHOUT_SETUP_FUNCTION,
                      AS_SOON_AS_POSSIBLE,
                      STANDARD_PRIORITY-1);
                      
}

void loop() {
  // put your main code here, to run repeatedly:

  runSimpleThreads();

  delay(2000);
}
