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

	//cout << "Past Con";
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
    
    cout << "Am I stuck here?";
}

// Description: Inserts newElement in sort order.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is sorted.   
// Postcondition: Once newElement is inserted, this Priority Queue remains sorted.           
bool PQueue::enqueue(const Event& newElement)
{
       
    Node* prevNode;
    Node* nextNode;
    Node* currentNode;
    nextNode = headPtr;
    prevNode = NULL;
    currentNode = headPtr;

    Node* newNode = new Node(newElement);
    
    //cout << "newNode type: " << newNode->data.gettime() << endl;
    
   
    int counter = 0;
    	while(nextNode != NULL){
            //cout << "nextNode time: a " << nextNode->data.gettime() << endl;
            if(nextNode->data.gettime() == newNode->data.gettime()){
                    if(newElement.gettype() < nextNode->data.gettype()){ //therefore an A since A < D in ASCII
                            prevNode->next = newNode; //insert A before nextNode
                            newNode->next = nextNode;
                            nodeCount++;
                            //cout << "Test1" << endl;
                            return true;

                    }else{
                            prevNode = nextNode->next;
                            nextNode = nextNode->next;
                            prevNode->next = newNode;
                            nodeCount++;
                            //cout << "Test2" << endl;
                            return true;

                    }   			    			
            }else if (newElement.gettime() < nextNode->data.gettime()){
                    prevNode->next = newNode;
                    newNode->next = nextNode;
                    nodeCount++;
                    //cout << "Test4" << endl;
                    return true;

            }else{
                //cout << "Next node time: " << nextNode->data.gettime() << endl;
                if(counter > 0){
                    //cout << "Prev node time: " <<  prevNode->data.gettime() << endl;
                }
                nextNode->next = newNode;
                newNode->next = nextNode;
                nodeCount++;
                //cout << "Test5 " << newNode->data.getlength() <<  endl;
                return true;
            }
            prevNode = nextNode;
            nextNode = nextNode->next;
            counter++;
    	 }                    
       //cout << "Test6" << endl;
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