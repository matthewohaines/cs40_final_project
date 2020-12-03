#ifndef __SIMULATION_H__
#define __SIMULATION_H__

#include "Animator.h"
#include "Section.h"
#include "Intersection.h"
#include "Lane.h"
#include "TrafficLight.h"
#include "Vehicle.h"
#include <vector>

class Simulation {

    private:
    std::vector<Vehicle *> vehVector;
    int seed;
    int time;
    int sectionsBeforeIntersection;    
    int greenNS;             
    int yellowNS;                      // Time that the north-south light is yellow
    int greenEW;                       // Time that the east-west light is green
    int yellowEW;                      // Time that the east-west light is yellow
    double probNewVehicleN;            // Probability a new vehicle is generated northbound
    double probNewVehicleS;            // Probability a new vehicle is generated southbound
    double probNewVehicleE;            // Probability a new vehicle is generated eastbound
    double probNewVehicleW;            // Probability a new vehicle is generated westbound
    double proportionCars;             // Proportion of generated vehicles that are cars
    double proportionSUVs;             // Proportion of generated vehicles that are SUV
    double proportionTrucks;           // Proportion of generated vehicles that are trucks
    double probRightCars;              // Probability a car turns right
    double probRightSUVs;              // Probability a SUV turns right
    double probRightTrucks;            // Probability a truck turns right
    double probLeftCars;               // Probability a car turns left
    double probLeftSUVs;               // Probability a SUV turns left
    double probLeftTrucks;   

    void createVehicle(Lane *lane, double laneProb, double createProb, double vehicleProb, double turnProb);
    void step();

    public:
        Simulation();
        Simulation(std::string inputFile, int seed);
        ~Simulation();

        void simulate();
        
};

#endif