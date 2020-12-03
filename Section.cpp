#ifndef __SECTION_CPP__
#define __SECTION_CPP__

#include "Section.h"
#include "Vehicle.h"

Vehicle newVehicle(VehicleType::car, Direction::north, IntendedTurn::right);
Section::Section() {
    
    this->vehicle = nullptr;
    this->forward = nullptr;
    this->right = nullptr;
    this->previous = nullptr;
}
Section::~Section() {}

bool Section::isSectionOccupied() {
 
    return vehicle != nullptr;
}

void Section::changeSectionOccupied(Vehicle &vehicle) {

    this->vehicle = &vehicle;
}

Vehicle Section::getVehicle(){
   return *vehicle;
}
#endif
