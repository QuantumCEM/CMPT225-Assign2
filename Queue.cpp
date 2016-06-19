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

Queue::Queue()
{

	for (int index = 0; index < Queue::maxNumberofEvents; index++)
	{
		events[index] = NULL;
		eventCount[index] = 0;
		currentTime = 0;
	}
}

/*
// Copy constructor
Queue::Queue(const Queue& rhs) {
   //cout << "Queue::copy constructor" << endl; // For testing purposes ... and curiosity

   for (int index = 0; index < Queue::maxNumberofEvents; index++) {
       events[index] = NULL;
       eventCount[index] = rhs.elementCount[index];
       
       // Deep copy the events
       if (rhs.events[index] != NULL && rhs.eventCount[index] ==  0) {
          events[index] = new Event[capacity[index]];
          for (int events = 0; events < elementCount[index]; events++) {
             events[index][events] = rhs.events[index][events];
          }
       }
   }
}  // end copy constructor
*/


  // Description: Returns "true" is this queue is empty, otherwise "false".
  // Time Efficiency: O(1)
  bool isEmpty() const;
   
  // Description: Adds newElement to the "back" of this queue and 
  //              returns "true" if successful, otherwise "false".
  // Time Efficiency: O(1)
  bool enqueue(const Event& newElement);
   
  // Description: Removes the element at the "front" of this queue and 
  //              returns "true" if successful, otherwise "false".
  // Precondition: This queue is not empty.
  // Time Efficiency: O(1)
  bool dequeue();

  // Description: Retrieves (but does not remove) the element at the  
  //              "front" of this queue and returns it.
  // Precondition: This queue is not empty.
  // Postcondition: This queue is unchanged.
  // Exceptions: Throws EmptyDataCollectionException if this queue is empty.
  // Time Efficiency: O(1)
  Event peek() const throw(EmptyDataCollectionException);   