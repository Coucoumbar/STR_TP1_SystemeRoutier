#pragma once

#include <string>
#include <vector>
#include "Intersection.h"

using namespace std;

class TrafficSystem
{

private :
	vector<Intersection*> intersections;
	int total_wait_time;
	int total_vehicles_processed;

public :
	TrafficSystem();

	//Adds an intersection to the system
	void add_intersection(Intersection*);
	//Process a cycle for all the intersection in the system
	void process_cycles();
	//Displays informations about the intersections of the system
	void info();

	int get_total_wait_time();
	int get_total_vehicles_processed();
};

