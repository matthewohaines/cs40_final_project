#ifndef __SECTION_CPP__
#define __SECTION_CPP__

#include "Section.h"

Section::Section() {

    this->forward = nullptr;
    this->previous = nullptr;
    this->vehicle = nullptr;
    this->empty = true;
    this->isIntersection = false;
}

Section::~Section() {}

void Section::setForward(Section *current) {

    forward = current;
}

void Section::setPrevious(Section *current) {

    previous = current;
}

void Section::clear() {

    empty = true;
    vehicle = nullptr;
}

void Section::placeVehicle(VehicleBase *veh) {

    vehicle = veh;
    empty = false;
}

#endif