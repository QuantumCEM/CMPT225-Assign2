/*
 * BankSimApp.cpp - Assignment 12
 * 
 * Class Description: Bank Simulation Application
 *
 * In this version, we use our MyADT.
 *
 * Created on: June 18, 2016
 * Group: AC Solutions
 */
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <sstream>

#include "Event.h"
#include "Queue.h"
#include "PQueue.h"
#include "EmptyDataCollectionException.h"

using namespace std;

// Processes an arrival event.
bool processArrival(Event* arrivalEvent, Queue qArray)
{
	int departureTime = 0;
    bool tellerAvailable = true;
    Event* customer = new Event;
    
    // Remove this event from the event list
	qArray.dequeue();
	
	customer->settime(arrivalEvent->gettime());
  	customer->settype(arrivalEvent->gettype());
  	customer->setlength(arrivalEvent->getlength());

	if (qArray.isEmpty() && tellerAvailable){
            departureTime = arrivalEvent->gettime() + arrivalEvent->gettime();
            Event* newDepartureEvent = new Event();
            newDepartureEvent = new Event('D', departureTime);
            qArray.enqueue(*newDepartureEvent);
            tellerAvailable = false;	
            cout << "Processing an arrival event at time: " << arrivalEvent->gettime() << endl; 
            return true;
	}else{
            qArray.enqueue(*customer);
	}	
}


/*
// Processes a departure event .
bool processDeparture(Event* departureEvent, Queue q, PQueue pq)
{
    // Remove this event from the event list
    eventListPQueue.remove();
    if (!bankQueue.isEmpty())
    {
            // Customer at front of line begins transaction
            customer = bankQueue.peek()
            bankQueue.dequeue()
            departureTime = currentTime + transaction time in customer
            newDepartureEvent = a new departure event with departureTime
            eventListPQueue.add(newDepartureEvent);
    }
    else
    {
            tellerAvailable = true;
    }
}
 */

void simulate()
{
	//Create an empty queue bankQueue to represent the bank line
	Queue* queue = new Queue();	
	Event* object = new Event();
	string aLine;
	int newTime, newLength, customerCount = 0;
    int currentTime = 0;
	ifstream myfile ("simulation.in");

	//Create an empty priority queue eventListPQueue for the event list

	bool tellerAvailable = true;
	
	// Create and add arrival events to event list
	if (myfile.is_open()){
		//while (!eof()) ?? Maybe eof() returns true if file opened reached end
		while ( getline(myfile, aLine)){ //Could be cin instead of myfile, not sure
			stringstream ss(aLine);
			ss >> newTime >> newLength;
			object->settype('A');
			object->settime(newTime);
			object->setlength(newLength);

			cout << "Read: " << object->gettime() << " " << object->getlength() << " " << object->gettype() << endl;
			customerCount++;

			//Get next arrival time a and transaction time t from file
			//newArrivalEvent = a new arrival event containing a and t
			//eventListPQueue.add(newArrivalEvent);
            queue->enqueue(*object);       
		}
                
        cout << queue->getEventCount() << endl; //Counts number of events on the queue

        
        //Testing Event.peek()
        Event* test = new Event;
        *test = queue->peek();
        cout << "Time: " << test->gettime() << " Type: " << test->gettype() << " Length: " << test->getlength() << endl;
      
        int counter = 0;

		// Event loop
		while (!queue->isEmpty()) //eventListPQueue is not empty
		{
	        Event* newEvent = new Event();
	        *newEvent = queue->peek();
	        
	        // Get current time
	        currentTime = newEvent->gettime();

	        if (newEvent->gettype() == 'A' ){
	        	processArrival(newEvent, *queue);
	        	counter++;
	        }else{
	        	cout << "departure happened" << endl;
	        //processDeparture(newEvent, queue);
			}           
		}
	cout << "Before myfile close, count: " << counter;
	myfile.close();	

	}else{
		cout << "Unable to open file";
	} 
}

int main()
{
    cout << "Simulation Begins" << endl;
    simulate();
    cout << "Simulation Finished" << endl;
    
return 0;
}