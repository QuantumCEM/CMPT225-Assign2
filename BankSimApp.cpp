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
bool processArrival(Event* arrivalEvent, PQueue priorityQ, Queue qArray)
{
    int departureTime = 0;
    bool tellerAvailable = true;
    Event* customer = new Event();
    
    // Remove this event from the event list
    qArray.dequeue();
	
    customer->settime(arrivalEvent->gettime());
    customer->settype(arrivalEvent->gettype());
    customer->setlength(arrivalEvent->getlength());

    if (qArray.isEmpty() && tellerAvailable){
        departureTime = arrivalEvent->gettime() + arrivalEvent->getlength();
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

// Processes a departure event .
bool processDeparture(Event* departureEvent, PQueue pQueue, Queue queue)
{
    bool tellerAvailable;
    
    Event *customer = new Event();
    Event *newDepartureEvent = new Event();
    
    int departureTime, currentTime, transactionTime = 0;
    currentTime = departureEvent->gettime();
    transactionTime = departureEvent->getlength();
    
    // Remove this event from the event list
    pQueue.dequeue();
    if (!queue.isEmpty())
    {
            // Customer at front of line begins transaction
            *customer = queue.peek();
            pQueue.dequeue();
            departureTime = currentTime + transactionTime;
            newDepartureEvent->settime(departureTime);
            newDepartureEvent->settype('D');
            pQueue.enqueue(*newDepartureEvent);
            tellerAvailable = false;
    }
    else
    {
            tellerAvailable = true;
    }
    
    return tellerAvailable;
}
 

void simulate(){
    //Create an empty queue bankQueue to represent the bank line
    Queue* queue = new Queue();
    PQueue* pqueue = new PQueue();	
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

            customerCount++;

            //Get next arrival time a and transaction time t from file
            //newArrivalEvent = a new arrival event containing a and t
            //eventListPQueue.add(newArrivalEvent);
            pqueue->enqueue(*object);       
        }
            
            cout << "Finished reading" << endl;
        // Event loop
        while (!pqueue->isEmpty()){
            cout << "Entering while: ";
        Event* newEvent = new Event();
        *newEvent = pqueue->peek();

        // Get current time
        currentTime = newEvent->gettime();

        if (newEvent->gettype() == 'A' ){
            processArrival(newEvent, *pqueue, *queue);
        }else{
            processDeparture(newEvent, *pqueue, *queue);
        }           
    }

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
    
    //Event *trial = new Event('A',10,5);
    /*
    Event* object = new Event();
    object->settype('A');
    object->settime(1);
    object->setlength(5);
    
    Event* object1 = new Event();
    object1->settype('A');
    object1->settime(11);
    object1->setlength(6);

    Event* object2 = new Event();

    cout << "Before queue" << endl;
    object2->settype('A');
    object2->settime(6);
    object2->setlength(6);
    
    Event* object3 = new Event();

    cout << "Before queue" << endl;
    object3->settype('D');
    object3->settime(6);
    object3->setlength();
    
    PQueue* q = new PQueue();
    Queue* qa = new Queue();
    
    bool A;
    bool B;
    bool C;
    bool D;
    
    //trial = Queue->peek();
    A = qa->enqueue(*object);
    int count = qa->getEventCount();
    cout << count;

     //Testing Event.peek()
     Event* test = new Event;
    *test = qa->peek();
     cout << "Time: " << test->gettime() << " Type: " << test->gettype() << " Length: " << test->getlength() << endl;
      	
    cout << object->gettime() << " " << object->getlength() << endl;
    cout << "Simulation Finished" << endl;

    //for(int i = 0; i<5; i++){
    //A = q->enqueue(*object);
    
        A = q->enqueue(*object);
        B = q->enqueue(*object1);
        C = q->enqueue(*object2);
        D = q->enqueue(*object3);
        
        cout << q->getNodeCount() << endl;
    //}
   */
    
return 0;
}
/*
	Event *trial = new Event('A',10,5);
    PQueue* q = new PQueue();
    
    bool A;
    //trial = Queue->peek();
    A = q->enqueue(*trial);
    int count = q->getNodeCount();
    cout << count;
 
 cout << "Simulation Finished" << endl;
*/ 