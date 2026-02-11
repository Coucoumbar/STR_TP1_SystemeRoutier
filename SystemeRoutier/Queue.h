#pragma once

#include <string>
#include "Vehicle.h"

using namespace std;

#define QUEUE_MAX_SIZE 10

class Queue
{

private :
	Vehicle queue[QUEUE_MAX_SIZE];
	int back;
	int front;

public :
	//Adds a vehicle to the back of the queue
	void enqueue(const Vehicle&);
	//Removes the first vehicle from the queue
	Vehicle* dequeue();
	//Returns the first vehicle from the queue
	Vehicle& peek() const;
	//Returns true if the queue is empty
	bool isEmpty() const;
	//Returns true if the queue is full
	bool isFull() const;
	//Returns the number of vehicles currently in the queue
	int size() const;
	//TBD
	void update();
};

