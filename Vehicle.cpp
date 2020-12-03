#ifndef __VEHICLE_CPP__
#define __VEHICLE_CPP__

#include "Vehicle.h"
#include "Intersection.h"

Vehicle::Vehicle(Lane *laneC, VehicleType type, IntendedTurn turn) : VehicleBase(type, laneC->getDirection()) {
    lane = laneC;
    intendedTurn = turn;
    if(type == VehicleType::car) {
        length = 2;
    }
    else if(type == VehicleType::suv) {
        length = 3;
    }
    else {
        length = 4;
    }
    first = lane->getFirst();
    first->placeVehicle(this);
    last = first;

    for(int i=0; i<length-1; i++) {
        last = last->getPrevious();
        last->placeVehicle(this);
    }
}

void Vehicle::move() {
    if(!(first->getForward()->isEmpty()) || (first->getForward() == nullptr)) {
        return;
    }
    else if(first->getForward()->getIsIntersection() && !(first->getIsIntersection())) {
        if(lane->getTrafficLight()->getColor() == LightColor::red) {
            return;
        }
        else if(lane->getTrafficLight()->getColor() == LightColor::yellow) {
            int time = lane->getTrafficLight()->getClock();
            if(intendedTurn == IntendedTurn::right && (time < length+1)){
                return;
            }
            if(intendedTurn != IntendedTurn::right && (time < length+2)){
                return;
        }
    }
}
    else if(first->getForward()->getIsIntersection() && first->getIsIntersection() 
        &&  intendedTurn == IntendedTurn::right) {
            moveRight();
            return;
        }
    moveForward();

    if(first->getForward() == nullptr) {
        atEnd = true;
        Section *section = first;
        while(section != last) {
            section->clear();
            section = section->getPrevious();
        }
        last->clear();
    }
}

void Vehicle::moveForward() {
    first = first->getForward();
    first->placeVehicle(this);
    last = last->getForward();
    last->getPrevious()->clear();
}

void Vehicle::moveRight() {
    Intersection *inter = dynamic_cast<Intersection* > (first);
    first = inter->getRight();
    first->placeVehicle(this);
    last->clear();
    last = last->getForward();
    if(getVehicleOriginalDirection() == Direction::north) {
        changeDirection(Direction::east);
    }
    else if(getVehicleOriginalDirection() == Direction::south) {
        changeDirection(Direction::west);
    }
    else if(getVehicleOriginalDirection() == Direction::east) {
        changeDirection(Direction::south);
    }
    else if(getVehicleOriginalDirection() == Direction::west) {
        changeDirection(Direction::north);
    }
}

#endif