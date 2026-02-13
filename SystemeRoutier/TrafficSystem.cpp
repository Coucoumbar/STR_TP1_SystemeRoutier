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
		inter->process_cycle(total_wait_time, total_vehicles_processed);
	}
}

bool TrafficSystem::has_vehicles() const {
	for (Intersection* inter : intersections) {
		if (inter->has_vehicles()) return true;
	}

	return false;
}

void TrafficSystem::info() const {
	cout << "Total vehicles processed : " << total_vehicles_processed << endl
		<< "Total wait time : " << total_wait_time << endl;
	cout << "Intersections informations [Total:" << intersections.size() << "] :" << endl;
	for (Intersection* inter : intersections) {
		inter->info();
	}
}

void TrafficSystem::statistics() const {
	cout << endl << "//**********[FINAL RESULTS]***********//" << endl
		<< "Total vehicles processed : " << total_vehicles_processed << endl
		<< "Total wait time : " << total_wait_time << endl
		<< "Average wait time : " << (total_vehicles_processed > 0 ? total_wait_time / total_vehicles_processed : 0) << endl;
}

int TrafficSystem::get_total_wait_time() {
	return total_wait_time;
}

int TrafficSystem::get_total_vehicles_processed() {
	return total_vehicles_processed;
}