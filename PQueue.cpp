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

#include <iostream>
#include <string>
#include "Event.h"
#include "Queue.h"
#include "PQueue.h"
#include "Node.h"

using namespace std;

//Default Constructor
PQueue::PQueue(){
	
	Event* event_data = new Event;

	headPtr = new Node;
	headPtr->next = NULL;
	headPtr->data = event_data;
	
}

//Destructor
PQueue::~PQueue(){
	
	Node* ptr = headPtr;
	Node* temp;

	while(ptr != NULL){
		temp = ptr;
		ptr = ptr->next;
		delete temp:
	}

	nodeCount = 0;
}

// Description: Returns "true" is this Priority Queue is empty, otherwise "false".
// Time Efficiency: O(1)
bool PQueue::isEmpty() const
{
    if(eventCount == 0){
    	return true;
    }else{
    	return false;
    }
    
}

// Description: Inserts newElement in sort order.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is sorted.   
// Postcondition: Once newElement is inserted, this Priority Queue remains sorted.           
bool PQueue::enqueue(const Event& newElement)
{
    Node* temp_prev;
    Node* temp_next;
    bool insertedArrival;
    temp_next = headPtr;
    temp_prev = NULL;

    if(temp->data.gettype() == 'A' || temp->data.gettype() == 'D'){ //http://www.cprogramming.com/tutorial/lesson15.html
    	while(temp_next->next != NULL){
    		if(temp_next->data.gettime() == newElement.gettime()){
    			if(newElement.gettype() < temp_next->data.gettype(){ //therefore an A since A < D in ASCII
    				temp_prev->next = Node(newElement, temp_next->next);
    				insertedArrival = true;
    			}   			    			
    		}else{
    			temp->next = new Node;
    			temp = temp->next;
    			temp->next = NULL;
    			temp->data = newElement;
    		}
    		
    		temp_prev = temp_next->next;
    		temp_next = temp_next->next;

    		if(insertedArrival == true){
    			temp_prev->next = Node(newElement, temp_next->next);
    			insertedArrival = false;

    		return true;
    		}

    	 } 
    }else{
    	return false;
    }
}

// Description: Removes the element with the "highest" priority.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is not empty.
bool PQueue::dequeue()
{
    if(isEmpty()){
    	return false;
    }else{
    	headPtr = headPtr->next;
    	return true;
    }
}

// Description: Retrieves (but does not remove) the element with the "highest" priority.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
Event PQueue::peek() const throw(EmptyDataCollectionException){
    if(isEmpty()){
    	try{
			throw EmptyDataCollectionException();
		}
		catch(EmptyDataCollectionException& e){
			e.what();
		}
	}else{
    	return *headPtr->data;
    }    
}