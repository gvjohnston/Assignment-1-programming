// This program assumes you are a user with admin privileges (staff).
// This program assumes five recurring events.

#include <iostream>
#include <string>
#include "Event.h"

using namespace std;

void populate(); //declarations
void header();
void printEvents();
void mainMenu();
void eventMenu();
void addCustomer();
void removeCustomer();

string eSelect = "None"; // name of event selected 
int eNumber; //integer representation of event

string eventName1 = "Movie Screening: Gravity";
string eventName2 = "Mama Mia Live!";
string eventName3 = "Live: Jimmy Carr";
string eventName4 = "School play: Lion King";
string eventName5 = "FIFA world cup";

Event event1(eventName1);
Event event2(eventName2);
Event event3(eventName3);
Event event4(eventName4);
Event event5(eventName5);

void populate()
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

	event1.addCustomer("bullock", phoneNo1);
	event1.addCustomer("clooney", phoneNo2);

	event2.addCustomer("Charmichael", phoneNo3);
	event2.addCustomer("Bright", phoneNo4);
	event2.addCustomer("Austin", phoneNo5);
	event2.addCustomer("Sheridan", phoneNo6);
}

void header()
{
	cout << "=========================================" << endl
		<< "            Ticket Master OS             " << endl
		<< "=========================================" << endl
		<< " Your one stop shop for event tickets!   " << endl << endl
		<< " Hello: Admin!" << endl;
		
}

void printEvents() //prints a list of events and their queues.
{
	
	cout << "-----------------------------------------" << endl << endl
		<< " Event 1: \"" << event1.getEventName() << "\"	Waiting list: " << event1.getLength() << endl
		<< " Event 2: \"" << event2.getEventName() << "\"		Waiting list: " << event2.getLength() << endl
		<< " Event 3: \"" << event3.getEventName() << "\"		Waiting list: " << event3.getLength() << endl
		<< " Event 4: \"" << event4.getEventName() << "\"	Waiting list: " << event4.getLength() << endl
		<< " Event 5: \"" << event5.getEventName() << "\"		Waiting list: " << event5.getLength() << endl <<endl
		<< "-----------------------------------------" << endl;
}

void mainMenu()
{

	printEvents();

	//select the event or exit

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
			exit(0); // exit prompts the program to terminate.

		default:
			cout << " Error: Unexpected input." << endl;
		}

	}
}

void eventMenu()
{
	cout << " Event selected: " << eSelect << endl
		<< "-----------------------------------------" << endl
		<< " Select your action!: " << endl
		<< "    1. Add a customer to waiting list." << endl
		<< "    2. Dispense availible ticket." << endl
		<< "    3. Check position in waiting list." << endl
		<< "    4. Signal event completion." << endl
		<< "    5. Return to Main Menu." << endl << endl;
		

	char input;

	while (true)
	{
		cout << " Action number: ";
		cin >> input;

		switch (input)
		{
		case '1':
//			addCustomer();
			return;


		case '2':
			eSelect = event2.getEventName();
			return;

		case '3':
			eSelect = event3.getEventName();
			return;

		case '4':
			eSelect = event4.getEventName();
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

}

void removeCustomer()
{

}

int main()
{
	populate();
	header();
	mainMenu();

	return 0;
}


