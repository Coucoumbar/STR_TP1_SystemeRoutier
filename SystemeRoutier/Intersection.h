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

	TrafficLightState meridianLight; //North <-> South
	TrafficLightState equatorLight; //West <-> East

	int cycles;
	int minGreenTime;
	int maxGreenTime;

public :
	Intersection(string, IntersectionType);

	//Process a light cycle of the intersection
	void processCycle();
	//Updates the lights state
	void updateLights();
	//Display the intersection's informations
	void display();
};

