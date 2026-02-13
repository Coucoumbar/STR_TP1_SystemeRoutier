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
	void addVehicle(Vehicle&);
	//Moves the road's queue's front vehicle
	Vehicle* nextVehicle();

	Vehicle& peekFirst() const;
	//Increments the waited time of all this road's vehicles
	void waitAll();
	//Displays the road informations
	void display();
	//Returns the number of vehicles in this road's queue
	int vehicleCount() const;
};

