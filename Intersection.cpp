#ifndef __INTERSECTION_CPP__
#define __INTERSECTION_CPP__

#include "Intersection.h"
#include "Vehicle.h"

Intersection::Intersection():Section() {
    this->isIntersection = true;
}

Intersection::~Intersection() {}

Section *Intersection::getForward() {
    Direction direction = this->getVehicle()->getVehicleOriginalDirection();
    if(direction == Direction::north) {
        return north;
    }
    else if(direction == Direction::south) {
        return south;
    }
    else if(direction == Direction::east) {
        return east;
    }
    else if(direction == Direction::west) {
        return west;
    }
    else {
        Section::getForward();
    }
    return nullptr;
}

Section *Intersection::getRight() {
    Direction direction = this->getVehicle()->getVehicleOriginalDirection();
    if(direction == Direction::north) {
        return east;
    }
    else if(direction == Direction::south) {
        return west;
    }
    else if(direction == Direction::east) {
        return south;
    }
    else if(direction == Direction::west) {
        return north;
    }
    return nullptr;
}

Section *Intersection::getPrevious() {
    if(this->getVehicle() == nullptr) {
        return Section::getPrevious();
    }
    Vehicle *vehicle = dynamic_cast<Vehicle *>(getVehicle());
    Direction direction = vehicle->getVehicleOriginalDirection();

    if(vehicle->getIntendedTurn() == IntendedTurn::right) {
        if(direction == Direction::north) {
            return east;
        }
        else if(direction == Direction::south) {
            return west;
        }
        else if(direction == Direction::east) {
            return south;
        }
        else if(direction == Direction::west) {
            return north;
        }
    }
    else {
        if(direction == Direction::north) {
            return south;
        }
        else if(direction == Direction::south) {
            return north;
        }
        else if(direction == Direction::east) {
            return west;
        }
        else if(direction == Direction::west) {
            return east;
        }
    }
    return nullptr;

}


#endif