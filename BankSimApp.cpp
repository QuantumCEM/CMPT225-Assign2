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

#include "Event.h"
#include "Queue.h"
#include "PQueue.h"

using namespace std;

simulate(): void
{
	//Create an empty queue bankQueue to represent the bank line
	//Create an empty priority queue eventListPQueue for the event list
	tellerAvailable = true
	// Create and add arrival events to event list
	while ( data file is not empty )
	{
		//Get next arrival time a and transaction time t from file
		//newArrivalEvent = a new arrival event containing a and t
		eventListPQueue.add(newArrivalEvent)
	}
// Event loop
while (eventListPQueue is not empty )
	{
		newEvent = eventListPQueue.peek()
		// Get current time
		currentTime = time of newEvent
		if (newEvent is an arrival event )
		processArrival(newEvent, eventListPQueue, bankQueue)
		else
		processDeparture(newEvent, eventListPQueue, bankQueue)
	}
}

// Processes an arrival event.
processArrival(arrivalEvent: Event, eventListPQueue: PriorityQueue,bankQueue: Queue)
{
	// Remove this event from the event list
	eventListPQueue.remove()
	customer = customer referenced in arrivalEvent
	if (bankQueue.isEmpty() && tellerAvailable)
	{
		departureTime = currentTime + transaction time in arrivalEvent
		newDepartureEvent = a new departure event with departureTime
		eventListPQueue.add(newDepartureEvent)
		tellerAvailable = false	
	}
	else
	{
		bankQueue.enqueue(customer)
	}	

	// Processes a departure event .
	+processDeparture(departureEvent: Event, eventListPQueue: PriorityQueue,bankQueue: Queue)
	{
		// Remove this event from the event list
		eventListPQueue.remove()
		if (!bankQueue.isEmpty())
		{
			// Customer at front of line begins transaction
			customer = bankQueue.peek()
			bankQueue.dequeue()
			departureTime = currentTime + transaction time in customer
			newDepartureEvent = a new departure event with departureTime
			eventListPQueue.add(newDepartureEvent)
		}
		else
		{
			tellerAvailable = true
		}
	}
}

int main()
{




	return 0;
}