#include "Queue.h"
#include <iostream>

Queue::Queue() {
	front = nullptr;
	back = nullptr;
	size = 0;
}

Queue::~Queue() {
	while (!isEmpty()) dequeue();
}

void Queue::enqueue(const Vehicle& newVehicle) {
	Node* node = new Node;
	node->data = newVehicle;
	node->next = nullptr;

	if (size == 0) {
		front = node;
		back = node;
	}
	else
	{
		back->next = node;
		back = node;
	}

	size++;
}

Vehicle Queue::dequeue() {
	if (size == 0)
	{
		throw runtime_error("Cannot dequeue, queue is empty.");
	}

	Node* temp = front;
	front = front->next;
	if (front == nullptr) back = nullptr;

	Vehicle data = temp->data;

	delete temp;

	size--;

	return data;
}

Vehicle& Queue::peek() const {
	if (size == 0)
	{
		cerr << "Cannot peek, queue is empty.";
		return;
	}

	return front->data;
}

int Queue::count() const {
	return size;
}

bool Queue::isEmpty() const {
	return size == 0;
}

void Queue::goThrough(const bool display, const bool wait) {
	Node* location = front;

	while (location != nullptr)
	{
		if (display) location->data.display();

		if (wait) location->data.wait();

		location = location->next;
	}
}




