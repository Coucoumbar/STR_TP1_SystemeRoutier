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
	Vehicle(string, string, int, string);

	//Increments the vehicle's waited time
	void wait();
	//Displays the vehicle's informations
	void display();
};

