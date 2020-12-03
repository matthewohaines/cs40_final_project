#ifndef __SIMULATION_CPP__
#define __SIMULATION_CPP__

#include "Simulation.h"
#include "Intersection.h"
#include "TrafficLight.h"
#include "VehicleBase.h"
#include "Vehicle.h"
#include "Lane.h"
#include <random>
#include <iostream>
#include <fstream>

Simulation::Simulation(std::string inputFile, int seed) {
   this->seed = seed;
   std::ifstream infile;
   infile.open(inputFile);

   if(!infile) {
      std::cerr << "Error ---- Could not open file: " << inputFile << std::endl;
      exit(1);
   }
   int count=0;
   std::string name;
   std::string value;

   while(infile.good()) {
      count++;
      infile >> name >> value;

      if(count == 1)
			time	 = stoi(value);
		else if(count == 2)
			sectionsBeforeIntersection = stoi(value);
		else if(count == 3)
			greenNS = stoi(value);
		else if(count == 4)
			yellowNS = stoi(value);
		else if(count == 5)
			greenEW = stoi(value);
		else if(count == 6)
			yellowEW = stoi(value);
		else if(count == 7)
			probNewVehicleN = stod(value);
		else if(count == 8)
			probNewVehicleS = stod(value);
		else if(count == 9)
			probNewVehicleE = stod(value);
		else if(count == 10)
			probNewVehicleW = stod(value);
		else if(count == 11)
			proportionCars = stod(value);
		else if(count == 12)
			proportionSUVs = stod(value);
		else if(count == 13)
			probRightCars = stod(value);
		else if(count == 14)
			probLeftCars = stod(value);
		else if(count == 15)
			probRightSUVs = stod(value);
		else if(count == 16)
			probLeftSUVs = stod(value);
		else if(count == 17)
			probRightTrucks = stod(value);
		else if(count == 18)
			probLeftTrucks = stod(value);
	}
   infile.close();
   proportionTrucks = 1 - proportionCars - proportionSUVs;
   }

Simulation::~Simulation() {
   for(size_t i=0; i < vehVector.size(); i++) {
      delete vehVector[i];
   }
   vehVector.clear();
}

void Simulation::simulate() {

   char dummy;
   Animator anim(sectionsBeforeIntersection);

   Intersection one;
   Intersection two;
   Intersection three;
   Intersection four;

   TrafficLight trafficLightNS(greenNS, yellowNS, greenEW+yellowEW, LightColor::green);
   TrafficLight trafficLightEW(greenEW, yellowEW, greenNS+yellowNS, LightColor::red);

   Lane nB(Direction::north, sectionsBeforeIntersection, &trafficLightNS, &one, &two);
   Lane sB(Direction::south, sectionsBeforeIntersection, &trafficLightNS, &three, &four);
   Lane eB(Direction::east, sectionsBeforeIntersection, &trafficLightEW, &four, &one);
   Lane wB(Direction::west, sectionsBeforeIntersection, &trafficLightEW, &two, &three);

   anim.setVehiclesNorthbound(nB.getVector());
   anim.setVehiclesSouthbound(sB.getVector());
   anim.setVehiclesEastbound(eB.getVector());
   anim.setVehiclesWestbound(wB.getVector());

   std::mt19937 mt;
   std::uniform_real_distribution<double> rand_double(0, 1);
   mt.seed(seed);

   for(int i=0; i <= time; i++) {
      createVehicle(&nB, probNewVehicleN, rand_double(mt), rand_double(mt), rand_double(mt));
      createVehicle(&sB, probNewVehicleS, rand_double(mt), rand_double(mt), rand_double(mt));
      createVehicle(&eB, probNewVehicleE, rand_double(mt), rand_double(mt), rand_double(mt));
      createVehicle(&wB, probNewVehicleW, rand_double(mt), rand_double(mt), rand_double(mt));

      anim.setLightNorthSouth(trafficLightNS.getColor());
      anim.setLightEastWest(trafficLightEW.getColor());

      anim.setVehiclesNorthbound(nB.getVector());
      anim.setVehiclesSouthbound(sB.getVector());
      anim.setVehiclesEastbound(eB.getVector());
      anim.setVehiclesWestbound(wB.getVector());

      anim.draw(i);
      std::cin.get(dummy);
      step();
      trafficLightNS.decrease();
      trafficLightEW.decrease();

   }
}

void Simulation::createVehicle(Lane *lane, double laneProb, double createProb,
 double vehicleProb, double turnProb) {

   if((lane->canPlace()) && (createProb<=laneProb)) {
      Vehicle *veh;

      if(vehicleProb <= proportionCars) {
         if(turnProb <= probRightCars) {
            veh = new Vehicle(lane, VehicleType::car, IntendedTurn::right);
         }
         else {
            veh = new Vehicle(lane, VehicleType::car, IntendedTurn::forward);
         }
      }
      else if(vehicleProb <= proportionCars + proportionSUVs) {
         if(turnProb <= probRightCars) {
            veh = new Vehicle(lane, VehicleType::suv, IntendedTurn::right);
         }
         else {
            veh = new Vehicle(lane, VehicleType::suv, IntendedTurn::forward);
         }
      }
      else {
         if(turnProb <=probRightCars) {
            veh = new Vehicle(lane, VehicleType::truck, IntendedTurn::right);
         }
         else {
            veh = new Vehicle(lane, VehicleType::truck, IntendedTurn::forward);
         }
      }
         vehVector.push_back(veh);
      }
   }


void Simulation::step() {
   std::vector<int> in;
   for(size_t i=0; i < vehVector.size(); i++) {
      if(vehVector[i]->isAtEnd()) {
         in.push_back(i);
      }
   }
   for(size_t i =0; i < in.size(); i++) {
      int index = in[i] - i;
      Vehicle* vehPtr = vehVector[index];
      vehVector.erase(vehVector.begin() + index);
      delete vehPtr;   
      }
   for(size_t i=0; i < vehVector.size(); i++) {
      vehVector[i]->move();
   }
}

#endif