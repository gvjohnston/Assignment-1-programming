#include "Event.h"

// Constructor

Event::Event(string eventName) :
name(eventName)
{}

string Event::getEventName() // Returns the name of the event represented by the object
{
	return name;
}

int Event::getLength() // returns the number of queue elements
{
	return lNames.getLength();
}

void Event::addCustomer(string lastName, string phoneNumber) // Adds a customer to the event queue
{
	lNames.Add(lastName);
	phones.Add(phoneNumber);
}

void Event::removeCustomer(string& lastName, string& phoneNumber) // Removes a customer from the event queue
{
	lNames.Remove(lastName);
	phones.Remove(phoneNumber);
}

void Event::findCustomer(string lastname, int& position) // Finds a customer in the event queue
{
	lNames.findQueueMember(lastname, position);
}

void Event::clear() // Resets the event
{
	string foo; //varible to satisfy Remove. Is discarded.

	for (int i = 0; i <= 10; i++)
	{
		lNames.Remove(foo);
		phones.Remove(foo);
	}
}