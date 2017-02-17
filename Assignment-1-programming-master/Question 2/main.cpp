#include <iostream>
#include <string>
#include "Event.h"

using namespace std;

void populate(); // Declarations.
void header();
void printEvents();
void mainMenu();
void eventMenu();
void addCustomer();
void removeCustomer();
void findCustomer();
void clearEvent();

string eSelect = "None"; // Name of event selected .
int eNumber; // Integer representation of event.

string eventName1 = "Movie Screening: Gravity"; // Client friendly names of the event.
string eventName2 = "Mama Mia Live!";
string eventName3 = "Live: Jimmy Carr";
string eventName4 = "School play: Lion King";
string eventName5 = "FIFA world cup";

Event event1(eventName1); // Event holds the name of the event, a queue for last names and a queue for phone numbers.
Event event2(eventName2);
Event event3(eventName3);
Event event4(eventName4);
Event event5(eventName5);

int main()
{
	populate();
	header();
	mainMenu();

	return 0;
}

void populate() // Made up phone numbers and names to populate event lists with.
{
	string phoneNo1 = "01592717425"; 
	string phoneNo2 = "01333546783";
	string phoneNo3 = "01432769604";
	string phoneNo4 = "01132456870";
	string phoneNo5 = "01654346875";
	string phoneNo6 = "01264850756";
	string phoneNo7 = "01183674326";
	string phoneNo8 = "01753462673";
	string phoneNo9 = "01382436754";
	string phoneNo10 = "01456328803";
	string phoneNo11 = "01305762342";
	string phoneNo12 = "07973542567";

	event1.addCustomer("Bullock", phoneNo1);
	event1.addCustomer("Clooney", phoneNo2);

	event2.addCustomer("Charmichael", phoneNo3);
	event2.addCustomer("Bright", phoneNo4);
	event2.addCustomer("Austin", phoneNo5);
	event2.addCustomer("Sheridan", phoneNo6);

	event3.addCustomer("Carr", phoneNo7);

	event4.addCustomer("Shenzi", phoneNo8);
	event4.addCustomer("Banzai", phoneNo9);

	event4.addCustomer("Zazu", phoneNo10);
	event4.addCustomer("Simba", phoneNo11);
	event4.addCustomer("Timon", phoneNo12);
	event4.addCustomer("Scar", phoneNo1);
	event4.addCustomer("Pumbaa", phoneNo2);
	event4.addCustomer("Mufasa", phoneNo3);

	event5.addCustomer("Chair", phoneNo4);
	event5.addCustomer("Grass", phoneNo5);
	event5.addCustomer("Ball", phoneNo6);
	event5.addCustomer("Post", phoneNo7);
	event5.addCustomer("Net", phoneNo8);
}

void header() // Nice header introduction
{
	cout << "=========================================" << endl
		<< "            Ticket Master OS             " << endl
		<< "=========================================" << endl
		<< " Your one stop shop for event tickets!   " << endl << endl
		<< " Hello: Admin!" << endl;
		
}

void mainMenu()
{
	// Prints a list of events and their queues.
	
	cout << "-----------------------------------------" << endl << endl
		<< " Event 1: \"" << event1.getEventName() << "\"	Waiting list: " << event1.getLength() << endl
		<< " Event 2: \"" << event2.getEventName() << "\"		Waiting list: " << event2.getLength() << endl
		<< " Event 3: \"" << event3.getEventName() << "\"		Waiting list: " << event3.getLength() << endl
		<< " Event 4: \"" << event4.getEventName() << "\"	Waiting list: " << event4.getLength() << endl
		<< " Event 5: \"" << event5.getEventName() << "\"		Waiting list: " << event5.getLength() << endl << endl
		<< "-----------------------------------------" << endl;

	// Select an event or exit

	while (true)
	{
		char input;

		cout << " Choose an event (1-5) or q to exit: ";
		cin >> input;
		cout << endl;

		switch (input)
		{
		case '1':
			eSelect = event1.getEventName();
			eNumber = 1;
			eventMenu();
			return;

		case '2':
			eSelect = event2.getEventName();
			eNumber = 2;
			eventMenu();
			return;

		case '3':
			eSelect = event3.getEventName();
			eNumber = 3;
			eventMenu();
			return;

		case '4':
			eSelect = event4.getEventName();
			eNumber = 4;
			eventMenu();
			return;

		case '5':
			eSelect = event5.getEventName();
			eNumber = 5;
			eventMenu();
			return;

		case 'q':
			exit(0); // Exit prompts the program to terminate.

		default:
			cout << " Error: Unexpected input." << endl;
		}

	}
}

void eventMenu() // Presented after an event is chosen.
{
	cout << " Event selected: " << eSelect << endl
		<< "-----------------------------------------" << endl
		<< " Select your action!: " << endl
		<< "    1. Add a customer to waiting list." << endl
		<< "    2. Dispense available ticket." << endl
		<< "    3. Check position in waiting list." << endl
		<< "    4. Signal event completion." << endl
		<< "    5. Return to Main Menu." << endl << endl;
		

	char input;

	while (true)
	{
		cout << " Action number: ";
		cin >> input;
		cout << endl;
		switch (input)
		{
		case '1':
			addCustomer();
			return;

		case '2':
			removeCustomer();
			return;

		case '3':
			findCustomer();
			return;

		case '4':
			clearEvent();
			return;

		case '5':
			mainMenu();
			return;

		default:
			cout << " Error: Unexpected input." << endl;
		}
	}
}

void addCustomer()
{
	string lname;
	string phoneNo;
	bool full = false; // Holds if the event is full
	
	cout << " Enter the customers name: ";
	cin >> lname;
	cout << endl;

	cout << " Enter the customers phone number: ";
	cin >> phoneNo;
	cout << endl;

	switch (eNumber) // For the sake of compactness addCustomer() is allowed to run even if the queue is full.
	{				 // The function has no effect as the queue function checks if the queue is not full before
	case 1:			 // it allows changes.
		if (event1.getLength() == 10)
		{
			full = true;
		}
		event1.addCustomer(lname, phoneNo); // Adds a customer to the event queues.
		break;

	case 2:
		if (event2.getLength() == 10)
		{
			full = true;
		}
		event2.addCustomer(lname, phoneNo);
		break;

	case 3:
		if (event3.getLength() == 10)
		{
			full = true;
		}
		event3.addCustomer(lname, phoneNo);
		break;

	case 4:
		if (event4.getLength() == 10)
		{
			full = true;
		}
		event4.addCustomer(lname, phoneNo);
		break;

	case 5:
		if (event5.getLength() == 10)
		{
			full = true;
		}
		event5.addCustomer(lname, phoneNo);
		break;

	default:
		break; // Should never happen as eNumber can not be any other value without edits to the code.
	}

	if (!full) // If there is room on the waiting list
	{
		cout << " Customer: " << lname << " has been added to the waiting list!" << endl << endl;
	}
	else
	{
		cout << "Sorry. There is no more room. Try again later!" << endl << endl;
	}
	eventMenu();
}
void removeCustomer()
{
	string lname;
	string phoneNo;

	switch (eNumber)
	{
	case 1:
		event1.removeCustomer(lname, phoneNo); // Removes the front customer in the queue and stores the last name and phone number. 
		break;

	case 2:
		event2.removeCustomer(lname, phoneNo);
		break;

	case 3:
		event3.removeCustomer(lname, phoneNo);
		break;

	case 4:
		event4.removeCustomer(lname, phoneNo);
		break;

	case 5:
		event5.removeCustomer(lname, phoneNo);
		break;

	default:
		break; // Should never happen as eNumber can not be anyother value without code edits.
	}
	if (lname == "") // If no one was removed the list must be empty.
	{
		cout << "Could not release. No customers waiting." << endl << endl;
	}
	else
	{
		cout << " Inform " << lname << " on " << phoneNo << " that they are going to the event!" << endl << endl;
	}
	eventMenu();
}

void clearEvent()
{
	string eName;

	switch (eNumber)
	{
	case 1:
		eName = eventName1;
		event1.clear(); // Emptys the queues.
		break;

	case 2:
		eName = eventName2;
		event2.clear();
		break;

	case 3:
		eName = eventName3;
		event3.clear();
		break;

	case 4:
		eName = eventName4;
		event4.clear();
		break;

	case 5:
		eName = eventName5;
		event5.clear();
		break;

	default:
		break; // Should never happen as eNumber can not be anyother value without code edits.
	}

	cout << "The waiting list for event " << eName << " has been cleared!" << endl << endl;

	eventMenu();
}

void findCustomer()
{
	string lname;
	int position = -1; // Initalised to -1 so it can be differenietated findCustomer() output.

	cout << " Enter the customers name: ";
	cin >> lname;
	cout << endl;
	
	switch (eNumber)
	{
	case 1:
		event1.findCustomer(lname, position); // Finds the customer in the queue and stores the position in the second variable. 
		break;

	case 2:
		event2.findCustomer(lname, position);
		break;

	case 3:
		event3.findCustomer(lname, position);
		break;

	case 4:
		event4.findCustomer(lname, position);
		break;

	case 5:
		event5.findCustomer(lname, position);
		break;

	default:
		break; // Should never happen as eNumber can not be anyother value without code edits.
	}
	if (position == -1) // If position was unchanged the search failed.
	{
		cout << "Could not find this customer!" << endl << endl;
	}
	else
	{
		cout << " Customer " << lname << " is in position: " << position << " in the line!" << endl << endl;
	}
	eventMenu();
}


