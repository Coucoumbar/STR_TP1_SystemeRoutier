#pragma once

#include <string>
#include "Queue.h"

using namespace std;

class Road
{

private :
	string name;
	Queue vehicles;
	string direction;

public :
	Road(string, string);

	//Adds a vehicle to the road's queue
	void add_vehicle(Vehicle&);
	//Moves the road's queue's front vehicle
	/*Vehicle* next_vehicle();*/
	void next_vehicle();

	Vehicle& peek_vehicle() const;
	//Increments the waited time of all this road's vehicles
	void wait();
	//Displays the road informations
	void info();
	//Returns the number of vehicles in this road's queue
	int vehicle_count() const;
};

