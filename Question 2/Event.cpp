#include "Event.h"

// Constructor

Event::Event(string eventName) :
name(eventName)
{}

string Event::getEventName()
{
	return name;
}

int Event::getLength()
{
	return lNames.getLength();
}

void Event::addCustomer(string lastName, string phoneNumber)
{
	lNames.Add(lastName);
	phones.Add(phoneNumber);
}

void Event::removeCustomer(string& lastName, string& phoneNumber)
{
	lNames.Remove(lastName);
	phones.Remove(phoneNumber);
}

void Event::findCustomer(string lastname, string phoneNumber)
{

}