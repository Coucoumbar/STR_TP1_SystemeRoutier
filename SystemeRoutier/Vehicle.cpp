#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle() {}

Vehicle::Vehicle(string id, string type, string destination) : 
	id(id), 
	type(type), 
	destination(destination), 
	wait_time(0) {}


string Vehicle::get_id() const { return id; }

string Vehicle::get_type() const { return type; }

string Vehicle::get_destination() const { return destination; }

int Vehicle::get_wait_time() const { return wait_time; }


void Vehicle::wait() {
	wait_time++;
}

void Vehicle::info() const {
	cout << type << " [" << id << "]" << " : " << endl
		<< " -> Going " << destination << endl 
		<< " -> Has waited " << wait_time << " cycles" << endl;
}