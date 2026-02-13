#include "Intersection.h"
#include <iostream>

Intersection::Intersection(string name, IntersectionType type, Road& north, Road& south, Road& east, Road& west, int min, int max) {
	this->name = name;
	this->type = type;

	this->north = &north;
	this->south = &south;
	this->east = &east;
	this->west = &west;

	this->meridianLight = TrafficLightState::GREEN;
	this->equatorLight = TrafficLightState::RED;

	this->minGreenTime = min;
	this->maxGreenTime = max;

	this->cycles = 0;
}

void Intersection::processCycle() {
	//Parfaitement au courant du chaos de cette fonction...

	if (type == IntersectionType::FOUR_WAY_STOP)
	{
		Road* next = north;
		if (next->peekFirst().waitedTime() < east->peekFirst().waitedTime()) next = east;
		if (next->peekFirst().waitedTime() < south->peekFirst().waitedTime()) next = south;
		if (next->peekFirst().waitedTime() < west->peekFirst().waitedTime()) next = west;

		next->nextVehicle();

		cycles++;

		return;
	}
	
	if (meridianLight != TrafficLightState::RED) {
		north->nextVehicle();
		south->nextVehicle();
	}
	else {
		east->nextVehicle();
		west->nextVehicle();
	}

	if (++cycles >= maxGreenTime - 1) updateLights();

	else if (type == IntersectionType::PRIORITY_LIGHT && cycles > minGreenTime)
	{
		int meridian = north->vehicleCount() + south->vehicleCount();
		int equator = east->vehicleCount() + west->vehicleCount();

		if (meridianLight != TrafficLightState::RED && meridian < equator) updateLights();
		else if (equatorLight != TrafficLightState::RED && equator < meridian) updateLights();
	}
}

void Intersection::updateLights() {
	//Gets both lights current int value (0 = RED, 1 = YELLOW, 2 = GREEN)
	int meridian = static_cast<int>(meridianLight);
	int equator	= static_cast<int>(equatorLight);

	//If the result of meridian - equator is positive, then equator is red
	//If the result of meridian - equator is negative, then meridian is red
	if ((meridian - equator) > 0) {
		//Set meridian to its next state and turn equator green if needed
		if (--meridian == equator) {
			equator = 2;
			cycles = 0;
		}
	}
	else {
		//Set equator to its next state and turn meridian green if needed
		if (--equator == meridian) {
			meridian = 2;
			cycles = 0;
		}
	}

	//Updates the value of both lights
	meridianLight = static_cast<TrafficLightState>(meridian);
	equatorLight = static_cast<TrafficLightState>(equator);
}

void Intersection::display() const {
	cout << name << " [" << typeAsString() << "] :" << endl
		<< "Roads informations : " << endl;
	north->display();
	east->display();
	south->display();
	west->display();
}

int Intersection::typeAsInt() const {
	return static_cast<int>(type);
}

int Intersection::stateAsInt(TrafficLightState state) const {
	return static_cast<int>(state);
}

string Intersection::typeAsString() const {
	switch (type)
	{
		case IntersectionType::PRIORITY_LIGHT:
			return "Priority Light";
		case IntersectionType::FIXED_LIGHT:
			return "Fixed Light";
		case IntersectionType::FOUR_WAY_STOP:
			return "Four Way Stop";
	}
}

string Intersection::stateAsString(TrafficLightState state) const {
	switch (state)
	{
		case TrafficLightState::RED:
			return "RED";
		case TrafficLightState::GREEN:
			return "GREEN";
		case TrafficLightState::YELLOW:
			return "YELLOW";
	}
}