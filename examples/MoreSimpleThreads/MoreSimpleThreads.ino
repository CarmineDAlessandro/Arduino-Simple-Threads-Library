/*
  MoreSimpleThreads.ino

  This sketch is made by 2 threads: printer, counter.
  The counter thread increase a variable "magic_number",
  the printer thread prints the "magic_number" on the
  Serial Monitor. The different priorities of the threads
  make the sketch to increase first the value and then 
  print it, avoiding any synchronization problem.
  The initialization of the variable is made in the
  setup function of the counter thread. 
  
  Created 25/11/2019
  By Carmine D'Alessandro

  https://github.com/CarmineDAlessandro/Arduino-Simple-Threads-Library

*/


#include "ArduinoSimpleThreads.h"

int magic_number;

/*******************************************/
/* PRINTER THREAD                          */
/*******************************************/

void printMagicNumber_loop(){
  /*Run repeatedly*/
  Serial.print("The magic number is ");
  Serial.println(magic_number);
}

/*******************************************/
/* COUNTER THREAD                          */
/*******************************************/

void setupCounter_setup(){
  /*Run once, when declaring the thread*/
  magic_number = 0;
}

void increaseCounter_loop(){
  /*Run repeatedly*/
  magic_number += 1;
}

/*******************************************/
/* MAIN PROGRAM                            */
/*******************************************/

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);

  /*Use 2 threads*/
  if(usingSimpleThreads(2) == SIMPLE_THREAD_ERROR)
  {
    Serial.println("Error during thread definition");
    exit(1);
  }

  /*PRINT THREAD*/
  if(declareSimpleThread(printMagicNumber_loop,
                      WITHOUT_SETUP_FUNCTION,
                      AS_SOON_AS_POSSIBLE,
                      STANDARD_PRIORITY) == SIMPLE_THREAD_ERROR)
  {
    Serial.println("Error during thread declaration");
    exit(1);
  }

   /*COUNTER THREAD*/
   if(declareSimpleThread(increaseCounter_loop,
                      setupCounter_setup,
                      AS_SOON_AS_POSSIBLE,
                      HIGH_PRIORITY) == SIMPLE_THREAD_ERROR)
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
