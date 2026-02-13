#include "Road.h"
#include <iostream>

Road::Road(string name, string direction) : 
	name(name), 
	direction(direction) {}

void Road::add_vehicle(Vehicle& newVehicle) {
	vehicles.insert(newVehicle);
}

//Vehicle* Road::next_vehicle() {
//	Vehicle* next;
//
//	try { next = new Vehicle(vehicles.retrieve()); }
//	catch (runtime_error& e) { next = nullptr; }
//
//	return next;
//}

void Road::next_vehicle() {
	vehicles.retrieve();
}

Vehicle& Road::peek_vehicle() const {
	return vehicles.peek();
}

void Road::wait() {
	vehicles.wait();
}

void Road::info() {
	cout << name << "[Leading " << direction << "] : " << endl
		<< " -> Number of cars waiting [" << vehicles.count() << "] :" << endl;
	vehicles.info();
}

int Road::vehicle_count() const {
	return vehicles.count();
}