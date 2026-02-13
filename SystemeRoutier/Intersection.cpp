#include "Intersection.h"
#include <iostream>

Intersection::Intersection(string name, IntersectionType type, Road& north, Road& south, Road& east, Road& west, int min, int max) :
	name(name),
	type(type),
	north(&north),
	south(&south),
	east(&east),
	west(&west),
	min_green_time(min),
	max_green_time(max),
	north_south_light(TrafficLightState::GREEN),
	east_west_light(TrafficLightState::RED),
	cycles(0) {}

Intersection::Intersection(string name, IntersectionType type, Road& north, Road& south, Road& east, Road& west, int max) :
	name(name),
	type(type),
	north(&north),
	south(&south),
	east(&east),
	west(&west),
	max_green_time(max),
	north_south_light(TrafficLightState::GREEN),
	east_west_light(TrafficLightState::RED),
	cycles(0) {}

Intersection::Intersection(string name, IntersectionType type, Road& north, Road& south, Road& east, Road& west) :
	name(name),
	type(type),
	north(&north),
	south(&south),
	east(&east),
	west(&west),
	cycles(0) {}

void Intersection::process_cycle(int& waited, int& processed) {
	if (type == IntersectionType::FOUR_WAY_STOP) 
	{
		Road* next = next_road();

		update_road(*next, waited, processed);

		cycles++;
	}
	else
	{
		if (north_south_light != TrafficLightState::RED) {
			update_road(*north, waited, processed);
			update_road(*south, waited, processed);
		}
		else {
			update_road(*east, waited, processed);
			update_road(*west, waited, processed);
		}

		if (++cycles >= max_green_time - 1) update_lights();
		else if (cycles > min_green_time) priority_cycle();

	}

	north->wait();
	south->wait();
	east->wait();
	west->wait();

}

void Intersection::update_road(Road& road, int& waited, int& processed) {
	if (road.vehicle_count() != 0) {
		waited += road.peek_vehicle().get_wait_time();
		processed++;
		road.next_vehicle();
	}
}

void Intersection::priority_cycle() {
	int meridian = north->vehicle_count() + south->vehicle_count();
	int equator = east->vehicle_count() + west->vehicle_count();

	if (north_south_light != TrafficLightState::RED && meridian < equator) update_lights();
	else if (east_west_light != TrafficLightState::RED && equator < meridian) update_lights();
}

Road* Intersection::next_road() {
	Road* next = north;
	if (next->vehicle_count() == 0 || next->peek_vehicle().get_wait_time() < east->peek_vehicle().get_wait_time()) next = east;
	if (next->vehicle_count() == 0 || next->peek_vehicle().get_wait_time() < south->peek_vehicle().get_wait_time()) next = south;
	if (next->vehicle_count() == 0 || next->peek_vehicle().get_wait_time() < west->peek_vehicle().get_wait_time()) next = west;

	return next;
}

bool Intersection::has_vehicles() const {
	return (north->vehicle_count() != 0 || south->vehicle_count() != 0 || east->vehicle_count() != 0 || west->vehicle_count() != 0);
}

void Intersection::update_lights() {
	//Gets both lights current int value (0 = RED, 1 = YELLOW, 2 = GREEN)
	int meridian = static_cast<int>(north_south_light);
	int equator	= static_cast<int>(east_west_light);

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
	north_south_light = static_cast<TrafficLightState>(meridian);
	east_west_light = static_cast<TrafficLightState>(equator);
}

void Intersection::info() const {
	cout << endl << name << " [" << type_as_string() << "] :" << endl
		<< "Roads informations : " << endl;
	north->info();
	east->info();
	south->info();
	west->info();
}

int Intersection::type_as_int() const {
	return static_cast<int>(type);
}

int Intersection::state_as_int(TrafficLightState state) const {
	return static_cast<int>(state);
}

string Intersection::type_as_string() const {
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

string Intersection::state_as_string(TrafficLightState state) const {
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