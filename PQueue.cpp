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
        //headPtr = NULL;
	headPtr->next = NULL;
	//headPtr = 0;

	nodeCount = 0;

	cout << "Past Con";
}

//Destructor
PQueue::~PQueue(){
	
	Node* ptr = headPtr;
	Node* temp;

	while(ptr != NULL){
		temp = ptr;
		ptr = ptr->next;
		delete temp;
	}

	nodeCount = 0;
}

// Description: Returns "true" is this Priority Queue is empty, otherwise "false".
// Time Efficiency: O(1)
bool PQueue::isEmpty() const
{
    if(nodeCount == 0){
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
	Event* event_copy = new Event();

	event_copy->settime(newElement.gettime());
	event_copy->settype(newElement.gettype());
	event_copy->setlength(newElement.getlength());

    Node* prevNode;
    Node* nextNode;
    nextNode = headPtr;
    prevNode = NULL;

    cout << "Before newNode" << endl;

    	Node* newNode = new Node();

    	cout << "after";
    	nextNode->next = newNode;
    	nextNode->data = *event_copy;
    	nextNode->next = NULL;

    	cout << "After newNode" << endl;
    	//nextNode = nextNode->next;
    	cout << nextNode->data.gettime() << endl;
    	return true;
    





    /*
    if(nextNode->data.gettype() == 'A' || prevNode->data.gettype() == 'D'){ 
    	while(nextNode->next != NULL){
    		if(nextNode->data.gettime() == newElement.gettime()){
    			if(newElement.gettype() < nextNode->data.gettype()){ //therefore an A since A < D in ASCII
    				prevNode->next = new Node(newElement, nextNode->next); //insert A before nextNode
    				nodeCount++;
    				return true;
     			}else{
     				prevNode = nextNode->next;
    				nextNode = nextNode->next;
    				prevNode->next = new Node(newElement, nextNode->next);
    				nodeCount++;
    				return true;
     			}   			    			
    		}else if (newElement.gettime() < nextNode->data.gettime()){
    			prevNode->next = new Node(newElement, nextNode->next);
    			nodeCount++;
    			return true; 
    		}else{
    			nextNode->next = new Node(newElement, NULL);
    			nodeCount++;
    			return true;
    		}

    		prevNode = nextNode->next;
    		nextNode = nextNode->next;
    	 }

    }else{
    	return false;
    }
    */
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

int PQueue::getNodeCount() const{
      return nodeCount;
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
    	return headPtr->data;
    }   
}