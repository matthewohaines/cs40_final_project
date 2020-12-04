#ifndef __VEHICLE_CPP__
#define __VEHICLE_CPP__

#include "Intersection.h"
#include "Vehicle.h"
#include <iostream>


Vehicle::Vehicle(Lane *initialLane, VehicleType type, bool willTurn) : VehicleBase(type, initialLane->getDirection()) {
    this->lane = initialLane;
    this->willTurn = willTurn;
    switch(type) {
        case VehicleType::car:
            this->length = 2;
            break;
        case VehicleType::suv:
            this->length = 3;
            break;
        case VehicleType::truck:
            this->length = 4;
            break;
    }

    first = lane->getPrior();
    first->setVehicle(this);
    last = first;

    for(int i = 0; i < length - 1; i++){
        last = last->getPrevious();
        last->setVehicle(this);
    }
}

bool Vehicle::reachedEnd() { 

    return this->atTheEnd;
}

bool Vehicle::getWillTurn() {

    return this->willTurn;
}

void Vehicle::move(){

    if(first->getForward()->isEmpty() && !first->getForward()->getIsIntersection()) {

        first = first->getForward();
        first->setVehicle(this);
        last = last->getForward();
        last->getPrevious()->setEmpty();
    }

    else if(!first->getIsIntersection() && first->getForward()->getIsIntersection()) {

        LightColor trafficLightColor = lane->getTrafficLight()->getColor();
        int timeLeft = lane->getTrafficLight()->getTimeLeft();
        switch(trafficLightColor) {
            case LightColor::red :
                return;
            case LightColor::yellow :
                if(willTurn && (timeLeft < length+1)) {
                    return;
                }
                if(!willTurn && (timeLeft < length+2)) {
                    return;
                }
            case LightColor::green:
                first = first->getForward();
                first->setVehicle(this);
                last = last->getForward();
                last->getPrevious()->setEmpty();
                } 
            }
        else if(first->getIsIntersection() && first->getForward()->getIsIntersection()) {
                if(willTurn) {
                    Intersection *inter = dynamic_cast<Intersection *>(first);
                    first = inter->getRight();
                    first->setVehicle(this);
                    last->setEmpty();
                    last = last->getForward();
                    switch(getVehicleOriginalDirection()) {

                        case Direction::north :
                            changeDirection(Direction::east);
                            break;
                        case Direction::south :
                            changeDirection(Direction::west);
                            break;
                        case Direction::east :
                            changeDirection(Direction::south);
                            break;
                        case Direction::west :
                            changeDirection(Direction::north);
                            break;
                    }
                }  
                else {

                    first = first->getForward();
                    first->setVehicle(this);
                    last = last->getForward();
                    last->getPrevious()->setEmpty();
                }      

        }
        if(first->getForward() == nullptr){
            atTheEnd = true;
            Section *section = first;
            while(section != last){
                section->setEmpty();
                section = section->getPrevious();
        }
            last->setEmpty();
    }
 }

#endif
