#include <iostream>
#include <fstream>
#include "Animator.h"
#include "VehicleBase.h"
#include "Section.h"
#include "Intersection.h"
#include "Lane.h"
#include "TrafficLight.h"
#include "Vehicle.h"
#include "Simulation.h"

int main(int argc, char* argv[]) {

    if(argc < 3) {
        std::cerr << "Usage ./simulation [input file] [initial seed]" << std::endl;
    }

    std::ifstream infile(argv[1]);
    if(!infile) {
        std::cerr << "Error: could not open file: " << argv[1] << std::endl;
    }

    int seed;
    try {
        seed = atoi(argv[2]);
    }
    catch(std::exception& e) {
        std::cerr << "Invalid int for the seed" << std::endl;
            }

        Simulation sim(argv[1], seed);
        sim.simulate();

        return 0;

}