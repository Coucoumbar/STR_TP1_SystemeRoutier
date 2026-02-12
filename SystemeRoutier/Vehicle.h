#pragma once

#include <string>

using namespace std;

class Vehicle
{

private :
	string id;
	string type;
	int waited;
	string destination;

public :
	Vehicle();
	Vehicle(string, string, string);

	//Increments the vehicle's waited time
	void wait();
	//Displays the vehicle's informations
	void display() const;
};

