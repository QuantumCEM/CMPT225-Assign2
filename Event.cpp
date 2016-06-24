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
#include <iostream>
#include <string>
#include "Event.h"
#include <locale>

using namespace std;

// Default Constructor
// Description: Create an blank event. 
// Postcondition: type set to "0", time set to 0, length set to 0 
Event::Event(){
	type = '0';
	time = 0;
	length = 0;

}// End default constructor

// Paramatrized arrival constuctor
// Description: Create an arrive event with preset parameters
// Postcondition: type set to Atype, time set to Atime, length set to Alength 
Event::Event(char Atype, int Atime, int Alength){
    cout << "test";
	this->settype(Atype);
	this->settime(Atime);
	this->setlength(Alength);
        
}// End paramatrized arrival constuctor

// Paramatrized departure constuctor
// Description: Create a departure event with preset parameters
// Postcondition: type set to Atype, time set to Atime, length set to Alength to zero 
Event::Event(char Atype, int Atime){
        this->settype(Atype);
	this->settime(Atime);
	length = 0;
}// End paramatrized departure constuctor

/*
	// Destructor
Event::~Event(){

}// End destructor
*/

// Setters
	
// Description: Sets the type of the event, i.e. A or D
// Precondition: Atype must be either A, D, a, or d
// Postcondition: Sets type to A or D but accepts a and d then converts it to upper case
void Event::settype(const char Atype){

	if(Atype == 97 || Atype == 98){
		type = toupper(Atype);
	}
        else if(Atype == 65 || Atype == 66){
		type = Atype;
	}else{
		type = '0';
	}
}// End settype implementation

// Description: Sets the arrive time of the event
// Precondition: Atime must be a positive integer greater than zero
// Postcondition: time is set is Atime, if Atime is realistic, otherwise sets Atime to zero
void Event::settime(const int Atime){
	if(Atime >= 0){
		time = Atime;
	}else{
		time = 0;
	}
	
}// End settime implemention

// Description: Sets the number of cycles required to complete the event, i.e. how many cycles after arrival will it depart
// Precondition: Alength has to be greater than one
// Postcondition: sets length to Alength, if Alength is realistic, otherwise sets Alength to 1
void Event::setlength(const int Alength){
	if(Alength >= 1){
		length = Alength;
	}else{
		length = 0;
                
	}
}// End setlength implementation

//Getters

// Description: Receives the type of the event, i.e. A or D
// Postcondition: Returns the event type as a char
char Event::gettype() const{
	return type;
}// End gettype implementation

// Description: Receives the arrival time of the event
// Postcondition: Returns an int for the arrival time
int Event::gettime() const{
	return time;
}// End gettime implmentation

// Description: Receives the number of execution cycles needed to complete the event
// Postcondition: Returns required amount of exeqution cycles as an int
int Event::getlength() const{
        
	return length;
}// End getlength implementation

/*
// Description: Recieves the number of events in the EventList
// Postcondition: Return the number of events as an int
int Event::numberOfEvents() const{

}// End numberOfEvents implementation
*/