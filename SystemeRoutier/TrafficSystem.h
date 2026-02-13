#pragma once

#include <string>
#include <vector>
#include "Intersection.h"

using namespace std;

class TrafficSystem
{

private :
	vector<Intersection*> intersections;
	int totalTimeWaited;
	int totalVehiclesProcessed;

public :
	TrafficSystem();

	//Adds an intersection to the system
	void addIntersection(Intersection*);
	//Process a cycle for all the intersection in the system
	void processCycles();
	//Displays informations about the intersections of the system
	void intersectionsStates();

	int getTotalTimeWaited();
	int getTotalVehiclesProcessed();
};

