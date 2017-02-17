#include "queuetemplate.h"
#include <string>

using namespace std;

class Event
{
private:
	string name; // the events name
	queue<string> lNames;
	queue<string> phones;
	int ident;
public:
	Event(string eventName);
	string getEventName();
	int getLength();
	void addCustomer(string lastName, string phoneNumber);
	void removeCustomer(string& lastName, string& phoneNumber);
	void findCustomer(string lastName, string phoneNumber);
	
};