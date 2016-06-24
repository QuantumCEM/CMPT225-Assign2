/* 
 * File:   PQueue.h
 * Author: aka91
 * 
 * PQueue.h (and PQueue.cpp)
 * 
 * Class invariants: The elements stored in this Priority Queue are always sorted. 
 * Group: AC Soluctions
 *
 * Created on June 23, 2016, 1:45 PM
 */

#pragma once
#include <string>
#include "Event.h"
#include "Queue.h"
#include "EmptyDataCollectionException.h" 
#include "Node.h"

using namespace std;

class PQueue {

private:

	int nodeCount;

	Node* headPtr;
	//Node* nextPtr;
	//Node* tailPtr;

public:
	//Default Constructure
	PQueue();

	//Destructure
	~PQueue();

   // Description: Returns "true" is this Priority Queue is empty, otherwise "false".
   // Time Efficiency: O(1)
   bool isEmpty() const;
  
   // Description: Inserts newElement in sort order.
   //              It returns "true" if successful, otherwise "false".
   // Precondition: This Priority Queue is sorted.   
   // Postcondition: Once newElement is inserted, this Priority Queue remains sorted.           
   bool enqueue(const Event& newElement);
   
   // Description: Removes the element with the "highest" priority.
   //              It returns "true" if successful, otherwise "false".
   // Precondition: This Priority Queue is not empty.
   bool dequeue();

   // Description: Retrieves (but does not remove) the element with the "highest" priority.
   // Precondition: This Priority Queue is not empty.
   // Postcondition: This Priority Queue is unchanged.
   // Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
   Event peek() const throw(EmptyDataCollectionException);   
 
   int getNodeCount() const;
};