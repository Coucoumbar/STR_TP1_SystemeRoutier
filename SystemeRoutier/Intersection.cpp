#include "Intersection.h"

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
		}
	}
	else {
		//Set equator to its next state and turn meridian green if needed
		if (--equator == meridian) {
			meridian = 2;
		}
	}

	//Updates the value of both lights
	meridianLight = static_cast<TrafficLightState>(meridian);
	equatorLight = static_cast<TrafficLightState>(equator);
}