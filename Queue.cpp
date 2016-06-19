/*
 * Queue.h (and Queue.cpp)
 * 
 * Class Description: A data collection ADT class to satisfy Assn 1's requiremetns.
 * Class invariants: FIFO or LILO  
 * Inspired on: June 18, 2016
 * Group: AC Soluctions
 */

#pragma once
#include <string>
#include "Event.h"
#include "PQueue.h"

using namespace std;

// Default Constructor
Queue::Queue()
{

	for (int index = 0; index < Queue::maxNumberofEvents; index++)
	{
		events[index] = NULL;
		eventCount[index] = 0;
		currentTime = 0;
	}
} // End default constructor

// Destructor
Queue::~Queue(){
  deleteALL();
} // End destructor

// Description: Returns "true" is this queue is empty, otherwise "false".
// Time Efficiency: O(1)
bool isEmpty(){
  if (eventCount == 0){
    return true;
  }else{
    return false;
   }
}// End isEmpty
  
// Description: Adds newElement to the "back" of this queue and 
//              returns "true" if successful, otherwise "false".
// Time Efficiency: O(1)
bool enqueue(const Event& newElement){

  //Check if there is enough space
  if (eventCount == 100){
    return false;
  }else{
    events[eventCount++] = newElement;
    eventCount++;
    currentTime++;
    return true;
  }

} // End enqueue
   
// Description: Removes the element at the "front" of this queue and 
//              returns "true" if successful, otherwise "false".
// Precondition: This queue is not empty.
// Time Efficiency: O(1)
bool dequeue(){

  //Check to see if there are any incoming 

}// End dequeue

// Description: Retrieves (but does not remove) the element at the  
//              "front" of this queue and returns it.
// Precondition: This queue is not empty.
// Postcondition: This queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this queue is empty.
// Time Efficiency: O(1)
Event peek() const throw(EmptyDataCollectionException){

} //End event peek

  

