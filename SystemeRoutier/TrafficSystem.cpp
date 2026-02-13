#include "TrafficSystem.h"
#include <iostream>

TrafficSystem::TrafficSystem() {
	totalTimeWaited = 0;
	totalVehiclesProcessed = 0;
}

void TrafficSystem::addIntersection(Intersection* intersection) {
	intersections.push_back(intersection);
}

void TrafficSystem::processCycles() {

}

void TrafficSystem::intersectionsStates() {
	cout << "Intersections informations [Total:" << intersections.size() << "] :" << endl;
	for (Intersection* inter : intersections) {
		inter->display();
	}
}

int TrafficSystem::getTotalTimeWaited() {
	return totalTimeWaited;
}

int TrafficSystem::getTotalVehiclesProcessed() {
	return totalVehiclesProcessed;
}