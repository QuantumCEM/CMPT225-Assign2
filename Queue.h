/*
 * Queue.h (and Queue.cpp)
 * 
 * Class Description: A data collection ADT class to satisfy Assn 2's requiremetns.
 * Class invariants: FIFO or LILO  
 * Inspired on: June 18, 2016
 * Group: AC Solutions
 */

#pragma once
#include <string>
#include "Event.h"
#include "PQueue.h"
//#include "Node.h"

using namespace std;


class Queue
{
private: 
   int numberofDepartures;                    
   static const int maxNumberofEvents = 100;
   int eventCount;
   Event* events[maxNumberofEvents];
   //int eventCount[eventCount];


public:

   // Default Constructor
   Queue();

   //Queue::~Queue();
  
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
   Event peek(); //const throw(EmptyDataCollectionException);   
   
   int getEventCount() const;
  
};