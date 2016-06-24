/*
 * Queue.h (and Queue.cpp)
 * 
 * Class Description: A data collection ADT class to satisfy Assn 1's requiremetns.
 * Class invariants: FIFO or LILO  
 * Inspired on: June 18, 2016
 * Group: AC Soluctions
 */

#include <iostream>
#include <string>
#include "Event.h"
#include "Queue.h"
#include "EmptyDataCollectionException.h"

using namespace std;

// Default Constructor
Queue::Queue()
{

  for (int index = 0; index < Queue::maxNumberofEvents; index++)
  {
    events[index] = NULL;
  }
   
  eventCount = 0;
  numberofDepartures = 0;
  //cout << "Num of Dep " << numberofDepartures << endl;
} // End default constructor
/*
// Destructor
Queue::~Queue(){
  deleteALL();
} // End destructor
 */ 

// Description: Returns "true" is this queue is empty, otherwise "false".
// Time Efficiency: O(1)
bool Queue::isEmpty() const{
  if (eventCount == 0){
    return true;
  }else{
    return false;
   }
}// End isEmpty
  
// Description: Adds newElement to the "back" of this queue and 
//              returns "true" if successful, otherwise "false".
// Time Efficiency: O(1)
bool Queue::enqueue(const Event& newElement){
  Event*  event_copy = new Event;

  event_copy->settime(newElement.gettime());
  event_copy->settype(newElement.gettype());
  event_copy->setlength(newElement.getlength());

  //Check if there is enough space
  if (eventCount >= 100){
    return false;
  }else{ 
    events[eventCount] = event_copy;
    eventCount++;

    /*
    //Adds a corresponding departure event
    char type = event_copy.gettype();
    int time = event_copy.gettime();
    int exe_length = event_copy.getlength();
    Event* depart = new Event(type, (time + exe_length));
    events[eventCount++] = depart;
   */
    
    return true;
  }
} // End enqueue
   
// Description: Removes the element at the "front" of this queue and 
//              returns "true" if successful, otherwise "false".
// Precondition: This queue is not empty.
// Time Efficiency: O(1)
bool Queue::dequeue(){

  if(eventCount < 0){
    return false;
  }else{
    
    events[numberofDepartures] = 0;
    //eventCount--;
    numberofDepartures++;
    //currentTime++; 
    //Shouldnt be incremented since departures dont have a wait time
    return true;
  }
}// End dequeue

int Queue::getEventCount() const{
      return eventCount;
}


// Description: Retrieves (but does not remove) the element at the  
//              "front" of this queue and returns it.
// Precondition: This queue is not empty.
// Postcondition: This queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this queue is empty.
// Time Efficiency: O(1)

Event Queue::peek() const throw(EmptyDataCollectionException){
	

  if(isEmpty()){
    try{
		throw EmptyDataCollectionException();
	}
	catch(EmptyDataCollectionException& e){
		e.what();
	}
  }
  else{
    return *events[numberofDepartures];

    //return Event;
  }

} //End event peek


  

