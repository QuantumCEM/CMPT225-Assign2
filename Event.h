/*
 * Event.h (and Event.cpp)
 *  
 * Class Description: Models a single Bank Event
 * Class Invariant: The type is a string, time and length are integers
 *					these uniquely identify each event
 * 
 * Inspired on: June 18, 2016
 * Group: AC Solutions
 */

#pragma once
#include <string>
#include "Queue.h"
#include "PQueue.h"

using namespace std;


class Event
{
private: 

	char type; 							// Either A for arrive or D for departure
	int time;  							// Time of arrive
	int length; 						//Execution time required to finish the event
	int numberOfEvents; 				//Maybe?
	static const int ARRAY_SIZE = 100; 	// size of array
	string EventList[ARRAY_SIZE]; 		//Preset list of events, required for current time
public:


	// Default Constructor
	Event();

	// Destructor
	~Event();

	// Setters
	
	// Description: Sets the type of the event, i.e. A or D
	void settype(const char Atype);

	// Description: Sets the arrive time of the event
	void settime(const int Atime);

	// Description: Sets the number of cycles required to complete the event, i.e. how many cycles after arrival will it depart
	void setlength(const int Alength);

	//Getters

	// Description: Receives the type of the event, i.e. A or D
	// Postcondition: Returns the event type as a char
	char gettype() const;

	// Description: Receives the arrival time of the event
	// Postcondition: Returns an int for the arrival time
	int gettime() const;

	// Description: Receives the number of execution cycles needed to complete the event
	// Postcondition: Returns required amount of exeqution cycles as an int
	int getlength() const;

	// Description: Recieves the number of events in the EventList
	// Postcondition: Return the number of events as an int
	int numberOfEvents() const;
};