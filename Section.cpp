#ifndef __SECTION_CPP__
#define __SECTION_CPP__

#include "Section.h"


Section::Section()
    : forward(nullptr),
      previous(nullptr),
      vehicle(nullptr)
    {}

Section *Section::getForward() {
    
    return this->forward;
}

Section *Section::getPrevious() {
    
    return this->previous;
}

bool Section::getIsIntersection() {
    
    return this->isIntersection;
}

bool Section::isEmpty() {  
    
    return this->empty;
}

VehicleBase *Section::getVehicle() {

    return this->vehicle;
}

void Section::setForward(Section *section) {

    this->forward = section;
}

void Section::setPrevious(Section *section) {
    
    this->previous = section;
}

void Section::setEmpty() {

    this->empty = true;
    this->vehicle = nullptr;
}

void Section::setVehicle(VehicleBase *veh) {

    this->empty = false;
    this->vehicle = veh;
}
#endif
