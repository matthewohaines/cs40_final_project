#include "Section.h"
#include "Lane.h"
#include "Intersection.h"
#include "Vehicle.h"
#include <iostream>

int main() {

    Intersection intersection;
    Lane northBound("northBound", 2);

    northBound.linkFromIntersection(intersection, 2);
    northBound.linkToIntersection(intersection, 2);

    
    Vehicle newVehicle(VehicleType::car, Direction::north, IntendedTurn::right);

    std::cout << northBound.firstSection->isSectionOccupied() << std::endl;

    northBound.firstSection->vehicle = &newVehicle;

    std::cout << northBound.firstSection->isSectionOccupied() << std::endl;

    northBound.firstSection->vehicle = nullptr;

    std::cout << northBound.firstSection->isSectionOccupied() << std::endl;
    std::cout << northBound.firstSection->isSectionOccupied() << std::endl;
    


    std::cout << northBound.getNumberOfSections() << std::endl;
    std::cout << northBound.getCurrentPosition() << std::endl;
    northBound.reset();
    std::cout << northBound.getCurrentPosition() << std::endl;

    //northBound.placeVehicle(newVehicle);

}