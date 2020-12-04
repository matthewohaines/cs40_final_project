#include <iostream>
#include <fstream>
#include "Section.h"
#include "Intersection.h"
#include "Lane.h"
#include "TrafficLight.h"
#include "VehicleBase.h"
#include "Vehicle.h"
#include "Sim.h"
#include "Animator.h"

int main(int argc, char* argv[]) {

    if(argc < 3) {

        std::cerr << "Usage: ./simulation [input file] [initial seed]" << std::endl;
        exit(1);
    }

    std::ifstream infile(argv[1]);
    if (!infile) {

        std::cerr << "Error: could not open file: " << argv[1] << std::endl;
        exit(1);
    }

    int seed;
    try {
        seed = atoi(argv[2]);
    } catch(std::exception& e) {
        std::cerr << "Invalid initial seed: " << argv[2] << std::endl;
        exit(1);
    }

    Sim sim(argv[1], seed);
    sim.simulate();

    return 0;
}
