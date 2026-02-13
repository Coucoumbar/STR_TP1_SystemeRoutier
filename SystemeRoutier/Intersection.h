#pragma once

#include <string>
#include "Road.h"
#include "TrafficLightState.h"
#include "IntersectionType.h"

using namespace std;

class Intersection
{

private :
	string name;
	IntersectionType type;

	Road* north;
	Road* south;
	Road* east;
	Road* west;

	TrafficLightState north_south_light;
	TrafficLightState east_west_light;

	int cycles;
	int min_green_time;
	int max_green_time;

public :
	Intersection(string, IntersectionType, Road&, Road&, Road&, Road&, int, int);

	//Process a light cycle of the intersection
	void process_cycle(int&, int&);
	//Updates the lights state
	void update_lights();
	//Display the intersection's informations
	void info() const;

	int type_as_int() const;
	int state_as_int(TrafficLightState) const;

	string type_as_string() const;
	string state_as_string(TrafficLightState) const;

	void priority_cycle();
	Road* next_road();
	void update_road(Road&, int&, int&);
};

