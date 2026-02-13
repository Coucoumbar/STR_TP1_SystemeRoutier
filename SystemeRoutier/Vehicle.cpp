#include "Vehicle.h"
#include <iostream>

int Vehicle::last_id_number = 0;

Vehicle::Vehicle() {}

Vehicle::Vehicle(string type, string destination) :
	type(type),
	destination(destination),
	wait_time(0) 
{
	id = "V" + to_string(++last_id_number);
}


string Vehicle::get_id() const { return id; }

string Vehicle::get_type() const { return type; }

string Vehicle::get_destination() const { return destination; }

int Vehicle::get_wait_time() const { return wait_time; }


void Vehicle::wait() {
	wait_time++;
}

void Vehicle::info() const {
	cout << " -> [" << id << "] " << type << " going " << destination << " [Waited " << wait_time << " cycles]" << endl;
}