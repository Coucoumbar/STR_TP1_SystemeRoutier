#include "Queue.h"
#include <iostream>

Queue::Queue() : 
	front_index(nullptr), 
	back_index(nullptr), 
	size(0) {}

Queue::~Queue() {
	while (!is_empty()) retrieve();
}

void Queue::insert(const Vehicle& newVehicle) {
	Node* node = new Node;
	node->data = newVehicle;
	node->next = nullptr;

	if (size == 0) {
		front_index = node;
		back_index = node;
	}
	else
	{
		back_index->next = node;
		back_index = node;
	}

	size++;
}

//Vehicle Queue::retrieve() {
//	if (size == 0) throw runtime_error("Cannot retrieve, queue is empty.");
//
//	Node* temp = front_index;
//	front_index = front_index->next;
//	if (front_index == nullptr) back_index = nullptr;
//
//	Vehicle data = temp->data;
//
//	delete temp;
//
//	size--;
//
//	return data;
//}

//void Queue::erase() {
//	//if (size == 0) throw runtime_error("Cannot erase, queue is empty.");
//
//	Node* temp = front_index;
//	front_index = front_index->next;
//	if (front_index == nullptr) back_index = nullptr;
//
//	delete temp;
//
//	size--;
//}

void Queue::retrieve() {
	//if (size == 0) throw runtime_error("Cannot erase, queue is empty.");

	Node* temp = front_index;
	front_index = front_index->next;
	if (front_index == nullptr) back_index = nullptr;

	delete temp;

	size--;
}

Vehicle& Queue::peek() const {
	if (size == 0)throw runtime_error("Cannot peek, queue is empty.");

	return front_index->data;
}

int Queue::count() const {
	return size;
}

bool Queue::is_empty() const {
	return size == 0;
}

void Queue::info() const {
	Node* location = front_index;

	while (location != nullptr)
	{
		location->data.info();
		location = location->next;
	}
}

void Queue::wait() {
	Node* location = front_index;

	while (location != nullptr)
	{
		location->data.wait();
		location = location->next;
	}
}




