#pragma once

#include <string>
#include "Vehicle.h"
#include "Node.h"

using namespace std;

class Queue
{

private :
	Node* front_index;
	Node* back_index;
	int size;

public :
	Queue();
	~Queue();

	//Adds a vehicle to the back of the queue
	void insert(const Vehicle&);
	//Removes the first vehicle from the queue
	Vehicle retrieve();
	//Erase the first vehicle from the queue
	void erase();
	//Returns the first vehicle from the queue
	Vehicle& peek() const;
	//Returns true if the queue is empty
	bool is_empty() const;
	//Returns the number of vehicles currently in the queue
	int count() const;

	void info() const;
	void wait();
};
