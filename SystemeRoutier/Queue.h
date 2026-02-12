#pragma once

#include <string>
#include "Vehicle.h"

using namespace std;

class Queue
{

private :
	Node* front;
	Node* back;
	int size;

public :
	Queue();
	~Queue();

	//Adds a vehicle to the back of the queue
	void enqueue(const Vehicle&);
	//Removes the first vehicle from the queue
	Vehicle dequeue();
	//Returns the first vehicle from the queue
	Vehicle& peek() const;
	//Returns true if the queue is empty
	bool isEmpty() const;
	//Returns the number of vehicles currently in the queue
	int count() const;
	//TBD
	void goThrough(const bool, const bool);
};

struct Node
{
	Vehicle data;
	Node* next;
};
