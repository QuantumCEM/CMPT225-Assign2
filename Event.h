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
using namespace std;

class Event
{
private: 
	char type; 							// Either A for arrive or D for departure
	int time;  							// Time of arrive
	int length; 						//Execution time required to finish the event

	//We might need to implmement this in Queue itself since these variables are irrelevant to an 'Event' object
	/* 
	int numberOfEvents; 				//Maybe?
	static const int ARRAY_SIZE = 100; 	// size of array
	string EventList[ARRAY_SIZE]; 		//Preset list of events, required for current time
	*/

public:

	// Default Constructor
	// Description: Create an blank event. 
	// Postcondition: type set to "0", time set to 0, length set to 0 
	Event();

	// Paramatrized arrival constuctor
	// Description: Create an arrive event with preset parameters
	// Postcondition: type set to Atype, time set to Atime, length set to Alength 
	Event(char Atype, int Atime, int Alength);

	// Paramatrized departure constuctor
	// Description: Create a departure event with preset parameters
	// Postcondition: type set to Atype, time set to Atime, length set to Alength to zero 
	Event(char Atype, int Atime);
	
	/*
	// Destructor
	~Event();
	*/

	// Setters
	
	// Description: Sets the type of the event, i.e. A or D
	// Precondition: Atype must be either A, D, a, or d
	// Postcondition: Sets type to A or D but accepts a and d then converts it to upper case
	void settype(const char Atype);

	// Description: Sets the arrive time of the event
	// Precondition: Atime must be a positive integer greater than zero
	// Postcondition: time is set is Atime, if Atime is realistic, otherwise sets Atime to zero
	void settime(const int Atime);

	// Description: Sets the number of cycles required to complete the event, i.e. how many cycles after arrival will it depart
	// Precondition: Alength has to be greater than one
	// Postcondition: sets length to Alength, if Alength is realistic, otherwise sets Alength to 1
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

	/* 
	// Description: Recieves the number of events in the EventList
	// Postcondition: Return the number of events as an int
	int numberOfEvents() const;
	*/
};