#ifndef __SECTION_CPP__
#define __SECTION_CPP__

#include "Section.h"
#include "Vehicle.h"

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

#endif