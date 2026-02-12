#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle(string id, string type, string destination) {
	this->id = id;
	this->type = type;
	this->destination = destination;
	this->waited = 0;
}

void Vehicle::wait() {
	waited++;
}

void Vehicle::display() const {
	cout << type << " [" << id << "]" << " : " << endl
		<< " -> Going " << destination << endl 
		<< " -> Has waited " << waited << " cycles" << endl;
}