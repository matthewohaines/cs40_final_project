#ifndef __SIM_CPP__
#define __SIM_CPP__

#include "Sim.h"
#include <random>
#include <fstream>
#include <iostream>


Sim::Sim(std::string file, int seed) {

    this->fileName = file;
	this->seed = seed;
    std::ifstream infile;
    infile.open(file);

    if(!infile) {

        std::cerr << "Error: could not open file: " << file << std::endl;
		exit(1);
	}

	std::string name;
	std::string value;

	for(int i=1; i<=18; i++) {
        infile >> name >> value;
        switch(i) {
            case 1: maximum_simulated_time = stoi(value);
            case 2: number_of_sections_before_intersection = stoi(value);
            case 3: green_north_south = stoi(value);
            case 4: yellow_north_south = stoi(value);
            case 5: green_east_west = stoi(value);
            case 6: yellow_east_west = stoi(value);
            case 7: prob_new_vehicle_northbound = stod(value);
            case 8: prob_new_vehicle_southbound = stod(value);
            case 9: prob_new_vehicle_eastbound = stod(value);
            case 10: prob_new_vehicle_westbound = stod(value);
            case 11: proportion_of_cars = stod(value);
            case 12: proportion_of_SUVs = stod(value);
            case 13: proportion_of_right_turn_cars = stod(value);
            case 14: proportion_of_left_turn_cars = stod(value);
            case 15: proportion_of_right_turn_SUVs = stod(value);
            case 16: proportion_of_left_turn_SUVs = stod(value);
            case 17: proportion_of_right_turn_trucks = stod(value);
            case 18: proportion_of_left_turn_trucks = stod(value);
        }
    }

	infile.close();
    red_north_south = green_east_west + yellow_east_west;
    red_east_west = green_north_south + yellow_north_south;
    proportion_of_trucks = 1 - proportion_of_cars - proportion_of_SUVs;

}

Sim::~Sim() {
	for (size_t i = 0; i < vehicleVector.size(); i++) {
      delete vehicleVector[i];
    }
	vehicleVector.clear();
}

void Sim::simulate() {

    Intersection interOne;
    Intersection interTwo;
    Intersection interThree;
    Intersection interFour;

    TrafficLight trafficLight_north_south(LightColor::green, green_north_south, yellow_north_south, red_north_south);
    TrafficLight trafficLight_east_west(LightColor::red, green_east_west, yellow_east_west, red_east_west);

    Lane northbound(number_of_sections_before_intersection, Direction::north, &trafficLight_north_south, &interOne, &interTwo);
    Lane westbound(number_of_sections_before_intersection, Direction::west, &trafficLight_east_west, &interTwo, &interThree);
    Lane southbound(number_of_sections_before_intersection, Direction::south, &trafficLight_north_south, &interThree, &interFour);
    Lane eastbound(number_of_sections_before_intersection, Direction::east, &trafficLight_east_west, &interFour, &interOne);

    std::mt19937 mt;
    std::uniform_real_distribution<double> rand_double(0,1);
    mt.seed(seed);

	char dummy;
	Animator anim(number_of_sections_before_intersection);

	anim.setVehiclesNorthbound(northbound.getVector());
    anim.setVehiclesWestbound(westbound.getVector());
    anim.setVehiclesSouthbound(southbound.getVector());
    anim.setVehiclesEastbound(eastbound.getVector());

	for (int i = 0; i <= maximum_simulated_time; i++) {

        anim.setLightNorthSouth(trafficLight_north_south.getColor());
        anim.setLightEastWest(trafficLight_east_west.getColor());

		createVehicle(&northbound, prob_new_vehicle_northbound, rand_double(mt), rand_double(mt), rand_double(mt));
        anim.setVehiclesNorthbound(northbound.getVector());
        createVehicle(&southbound, prob_new_vehicle_southbound, rand_double(mt), rand_double(mt), rand_double(mt));
        anim.setVehiclesSouthbound(southbound.getVector());
        createVehicle(&westbound, prob_new_vehicle_westbound, rand_double(mt), rand_double(mt), rand_double(mt));
        anim.setVehiclesWestbound(westbound.getVector());
		createVehicle(&eastbound, prob_new_vehicle_eastbound, rand_double(mt), rand_double(mt), rand_double(mt));
        anim.setVehiclesEastbound(eastbound.getVector());

		anim.draw(i);

        std::cin.get(dummy);

		move();

		trafficLight_north_south.decrement();
        trafficLight_east_west.decrement();
	}
}


void Sim::createVehicle(Lane *lane, double prop_new_vehicle, double prop_from_random,
	double vehicle_prop_random, double turn_prop_random) {

	if((lane->canCreate()) && (prop_from_random <= prop_new_vehicle)){
		Vehicle *veh;

		if(vehicle_prop_random <= proportion_of_cars){
			if(turn_prop_random <= proportion_of_right_turn_cars)
				veh = new Vehicle(lane, VehicleType::car, true);
			else
				veh = new Vehicle(lane, VehicleType::car, false);
		}

		else if(vehicle_prop_random <= proportion_of_SUVs){
			if(turn_prop_random <= proportion_of_right_turn_SUVs)
				veh = new Vehicle(lane, VehicleType::suv, true);
			else
				veh = new Vehicle(lane, VehicleType::suv, false);
		}

		else{
			if(turn_prop_random <= proportion_of_right_turn_trucks)
				veh = new Vehicle(lane, VehicleType::truck, true);
			else
				veh = new Vehicle(lane, VehicleType::truck, false);
		}

		vehicleVector.push_back(veh);
	}
}

void Sim::move() {

	std::vector<int> indices;
	for (size_t i = 0; i < vehicleVector.size(); i++) {
        if (vehicleVector[i]->reachedEnd()) {
			indices.push_back(i);
        }
    }

	for(size_t i = 0; i < indices.size(); i++) {
		int index = indices[i] - i;
        Vehicle* vehiclePtr = vehicleVector[index];
        vehicleVector.erase(vehicleVector.begin() + index);
        delete vehiclePtr;
	}

	for (size_t i = 0; i < vehicleVector.size(); i++) {
		vehicleVector[i]->move();
    }
}

#endif
