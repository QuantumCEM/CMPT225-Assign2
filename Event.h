/*
 * Event.h (and Event.cpp)
 *  
 * Class Description: Models a single Bank Event
 * Class Invariant: The type is a string, time and length are integers
 *					these uniquely identify each event
 * 
 * Inspired on: June 18, 2016
 * Group: AC Soluctions
 */

#pragma once
#include <string>
#include "Queue.h"
#include "PQueue.h"

using namespace std;


class Event
{
private: 

	char type;
	int time;
	int length;
	int numberOfEvents; //Maybe?
	static const int ARRAY_SIZE = 100; // size of array
	string EventList[ARRAY_SIZE]; //List of events

public:


	// Default Constructor
	Event();

	char gettype() const;

	int gettime() const;

	int getlength() const;

	int numberOfEvents() const;

	void settype(const char Atype);

	void settime(const int Atime);

	void setlength(const int Alength);


};