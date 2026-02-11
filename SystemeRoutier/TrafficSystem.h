#pragma once

#include <string>
#include <vector>
#include "Intersection.h"

#include "Road.h"
#include "TrafficLightState.h"
#include "IntersectionType.h"

using namespace std;

class TrafficSystem
{

private :
	vector<Intersection*> intersections;
	int totalTimeWaited;
	int totalVehiclesProcessed;

public :
	void addIntersection(Intersection*);
	void processCycles();
	void intersectionsStates();
	int getTotalTimeWaited();
	int getTotalVehiclesProcessed();
};

