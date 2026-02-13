#pragma once

#include <string>

using namespace std;

class Vehicle
{

private :
	string id;
	string type;
	string destination;
	int wait_time;
	static int last_id_number;

public :
	Vehicle();
	Vehicle(string, string);

	string get_id() const;
	string get_type() const;
	string get_destination() const;
	int get_wait_time() const;

	//Increments the vehicle's waited time
	void wait();
	//Displays the vehicle's informations
	void info() const;
};

