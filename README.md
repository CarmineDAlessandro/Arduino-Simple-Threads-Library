# Arduino Simple Threads Library
Simple Arduino library to schedule functions pretending they are threads

## Overview
The idea behind this library is to generalize the mechanism shown in the [Arduino - Blink Without Delay](https://www.arduino.cc/en/tutorial/BlinkWithoutDelay) page, so, giving to the programmer the feeling of threads even if everything is actually executed sequentially. This is the code behind:
```
if (currentMillis - previousMillis >= interval) {

    // Imagine your code run here
    // ...
    
}
```
In this library I use the words "threading" or "pseudo-threading" referring to this concept, even if it has to be clear it is not actual threading but, more likely, "function scheduling". The library has only 2 functions: one to declare the pseudo-threads and one to execute them.

## How it works
### Install
You can use the [Official Documentation](https://www.arduino.cc/en/guide/libraries#toc4) or use this list:
1. Download the zip of the library and open you Arduino IDE
2. In the menu, select "Sketch", then "#include library", then "Add .ZIP library"
3. Select the zip file of this library
4. Run one of the sketch you find in the example folder, like the "HelloFromSimpleThread" to check if you did everything right
### Sintax
The main idea is to give the idea of having multiple execution flows. Each pseudo-thread has its own `setup()` and `loop()`. As the normal execution flow, the setup function is executed only once when the pseudo-thread is declared, the loop function is executed at each execution of the main loop of the sketch.
#### #define the number of threads
After you include the library, you have to define the number of threads your sketch uses. In case you do not define a number, a default amount of thread will be automatically defined. However, to save memory space and to avoid any uncorrect behavious, it is always better to define this information
```
#include "ArduinoSimpleThreads.h"
#define NUMBER_SIMPLE_THREADS 1
```
#### Declare a thread
To declare a pseudo-thread you have to use the function `declareSimpleThread(...)` in the setup of the sketch. This function has 4 parameters, as shown below, and returns `True` if the pseudo-thread was correctly declared, `False` otherwise.
```
void setup() {
  // put your setup code here, to run once:
  declareSimpleThread( <thread_loop_function>, <thread_setup_function>, <thread_delay>, <thread_priority> );
}
```
- **thread_loop_function**: the name of the loop function. It must return void and have no parameters, exactly like the standard loop. If your pseudo-thread has no loop, use the `DO_NOTHING_FUNCTION` macro instead; in this case, no memory space will be used and it is not necessary to consider it in the value of the macro `NUMBER_SIMPLE_THREADS`
- **thread_setup_function**: the name of the setup function. It must return void and have no parameters, exactly like the standard setup. If your pseudo-thread has no setup, use the `WITHOUT_SETUP_FUNCTION` macro instead
- **thread_delay**: the number of milliseconds the thread has to wait before being ready. It must be a positive integer. If you want your thread to be executed continuously, use the `AS_SOON_AS_POSSIBLE` macro instead
- **thread_priority**: the priority of the pseudo-thread. It must be an integer. Higher the number, higher the priority. You may use a number or use one of the macros already defined by the library
#### Run the threads
To run the pseudo-thread you have to use the function `runSimpleThreads()` in the loop. It requires no parameters and has void return.
```
void loop() {
  // put your main code here, to run repeatedly:
  
  declareSimpleThread( <thread_loop_function>, <thread_setup_function>, <thread_delay>, <thread_priority> );
}
```
All the code in the loop of the sketch written before the `runSimpleThreads()` function will be executed before the ready pseudo-threads. All the code in the loop of the sketch written after the `runSimpleThreads()` function will be executed after the ready pseudo-threads. If you use `delay()` it will influence the program in the same way it influences the mechanism explained in the overview and in the [Arduino - Blink Without Delay](https://www.arduino.cc/en/tutorial/BlinkWithoutDelay).
#### Useful macros
```
#define AS_SOON_AS_POSSIBLE     0          // Runs the thread as soon as possible, without delay
#define DO_NOTHING_FUNCTION     NULL       // No loop function specified
#define WITHOUT_SETUP_FUNCTION  NULL       // No setup function specified

#define VERY_LOW_PRIORITY       -200       
#define LOW_PRIORITY            -100
#define STANDARD_PRIORITY       0
#define HIGH_PRIORITY           100
#define VERY_HIGH_PRIORITY      200
```
### An example
