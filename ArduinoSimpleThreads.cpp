/*
	ArduinoSimpleThreads.cpp

	Simple Arduino library to schedule functions pretending they are threads.
	
	Created 25/11/2019
	By Carmine D'Alessandro

	https://github.com/CarmineDAlessandro/Arduino-Simple-Threads-Library

*/


#include "Arduino.h"
#include "ArduinoSimpleThreads.h"

struct simple_thread{
	void (*thread_function_pointer)(void);
	void (*thread_function_startup_pointer)(void);
	unsigned long last_execution;
	unsigned long thread_delay;
	int priority;

} simple_thread_array[NUMBER_SIMPLE_THREADS];
unsigned int simple_thread_array_size = 0;

void declareSimpleThread(void (*thread_function_pointer)(void),
						 void (*thread_function_startup_pointer)(void),
						 unsigned long thread_delay,
						 int priority) {
	int i;
	if(simple_thread_array_size < NUMBER_SIMPLE_THREADS)
	{
		for(i = simple_thread_array_size-1; i>=0; i--)
		{
			simple_thread_array[i+1] = simple_thread_array[i];
			if(priority < simple_thread_array[i].priority)
			{
				break;
			}
		}

		simple_thread_array[i+1].thread_function_pointer = thread_function_pointer;
		simple_thread_array[i+1].thread_function_startup_pointer = thread_function_startup_pointer;
		simple_thread_array[i+1].thread_delay = (unsigned long)thread_delay;
		simple_thread_array[i+1].priority = priority;
		simple_thread_array[i+1].last_execution = millis();

		/*Setup thread*/
		if(simple_thread_array[i+1].thread_function_startup_pointer)
		{
			simple_thread_array[i+1].thread_function_startup_pointer();
		}

		simple_thread_array_size++;
	}
}

void runSimpleThreads() {
	int i;
	unsigned long curr_millis = millis();
	for(i = 0; i < simple_thread_array_size; i++)
	{
		if(curr_millis-simple_thread_array[i].last_execution>simple_thread_array[i].thread_delay)
		{
			if(simple_thread_array[i].thread_function_pointer)
			{
				simple_thread_array[i].thread_function_pointer();
				simple_thread_array[i].last_execution = curr_millis;
			}
		}
	}
}
