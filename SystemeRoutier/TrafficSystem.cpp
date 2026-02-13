#include "TrafficSystem.h"
#include <iostream>

TrafficSystem::TrafficSystem() : 
	total_wait_time(0), 
	total_vehicles_processed(0) {}

void TrafficSystem::add_intersection(Intersection* intersection) {
	intersections.push_back(intersection);
}

void TrafficSystem::process_cycles() {
	for (Intersection* inter : intersections) {
		inter->process_cycle();
	}
}

void TrafficSystem::info() {
	cout << "Intersections informations [Total:" << intersections.size() << "] :" << endl;
	for (Intersection* inter : intersections) {
		inter->info();
	}
}

int TrafficSystem::get_total_wait_time() {
	return total_wait_time;
}

int TrafficSystem::get_total_vehicles_processed() {
	return total_vehicles_processed;
}