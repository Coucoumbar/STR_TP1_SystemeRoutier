#include <iostream>

#include "TrafficSystem.h"

void initiate_even(Road&, Road&, Road&, Road&, int);
void initiate_one_way(Road&, Road&, Road&, Road&, int);
void initiate_unbalanced(Road&, Road&, Road&, Road&, int, int);

int main()
{
    TrafficSystem system;

    Road north_road{ "North road", "North" };
    Road south_road{ "South road", "South" };
    Road east_road{ "East road", "East" };
    Road west_road{ "West road", "West" };



    //[VEHICLE DISTRIBUTION OPTIONS]//

    //initiate_even(north_road, south_road, east_road, west_road, 30);

    initiate_one_way(north_road, south_road, east_road, west_road, 60);/**/

    //initiate_unbalanced(north_road, south_road, east_road, west_road, 50, 10);



    //[INTERSECTION TYPE OPTIONS]//

    //Intersection intersection{ "Main Intersection", IntersectionType::PRIORITY_LIGHT, north_road, south_road, east_road, west_road, 2, 5 };

    //Intersection intersection{ "Main Intersection", IntersectionType::FIXED_LIGHT, north_road, south_road, east_road, west_road, 3 };

    Intersection intersection{"Main Intersection", IntersectionType::FOUR_WAY_STOP, north_road, south_road, east_road, west_road};/**/



    system.add_intersection(&intersection);

    int cpt = 0;

    while (system.has_vehicles()) {
        system.process_cycles();

        //system.info(); //Uncomment to get overwhelmed by text
    }

    system.statistics();
}

void initiate_even(Road& north, Road& south, Road& east, Road& west, int quantity) {
    for (int cpt = 0; cpt < quantity; cpt++)
    {
        Vehicle n{ "Car", "South" };
        Vehicle s{ "Car", "North" };
        Vehicle e{ "Car", "West" };
        Vehicle w{ "Car", "East" };

        north.add_vehicle(n);
        south.add_vehicle(s);
        east.add_vehicle(e);
        west.add_vehicle(w);
    }
}

void initiate_one_way(Road& north, Road& south, Road& east, Road& west, int quantity) {
    for (int cpt = 0; cpt < quantity; cpt++)
    {
        Vehicle n{ "Car", "South" };
        Vehicle s{ "Car", "North" };

        north.add_vehicle(n);
        south.add_vehicle(s);
    }
}

void initiate_unbalanced(Road& north, Road& south, Road& east, Road& west, int quantity_y, int quantity_x) {
    for (int cpt = 0; cpt < quantity_y; cpt++)
    {
        Vehicle n{ "Car", "South" };
        Vehicle s{ "Car", "North" };

        north.add_vehicle(n);
        south.add_vehicle(s);
    }

    for (int cpt = 0; cpt < quantity_x; cpt++)
    {
        Vehicle e{ "Car", "West" };
        Vehicle w{ "Car", "East" };

        east.add_vehicle(e);
        west.add_vehicle(w);
    }
}
