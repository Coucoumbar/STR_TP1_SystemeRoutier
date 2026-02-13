#include "Road.h"
#include <iostream>

Road::Road(string name, string direction) {
	this->name = name;
	this->direction = direction;
}

void Road::addVehicle(Vehicle& newVehicle) {
	vehicles.enqueue(newVehicle);
}

Vehicle* Road::nextVehicle() {
	Vehicle* next;

	try { next = new Vehicle(vehicles.dequeue()); }
	catch (runtime_error& e) { next = nullptr; }

	return next;
}

Vehicle& Road::peekFirst() const {
	return vehicles.peek();
}

void Road::waitAll() {
	vehicles.goThrough(false, true);
}

void Road::display() {
	cout << name << "[Leading " << direction << "] : " << endl
		<< " -> Number of cars waiting [" << vehicles.count() << "] :" << endl;
	vehicles.goThrough(true, false);
}

int Road::vehicleCount() const {
	return vehicles.count();
}