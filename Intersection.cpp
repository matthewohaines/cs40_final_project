#ifndef __INTERSECTION_CPP__
#define __INTERSECTION_CPP__

#include "Intersection.h"
#include "Vehicle.h"

Intersection::Intersection():Section(){ isIntersection = true; }


Section *Intersection::getForward() {
    Direction direction = getVehicle()->getVehicleOriginalDirection();
    switch (direction) {
        case Direction::north : return intersectionOne;

        case Direction::south : return intersectionFour;

        case Direction::east : return intersectionTwo;

        case Direction::west : return intersectionThree;
    }
    return nullptr;
    
}

Section *Intersection::getPrevious() {
    if(getVehicle() == nullptr) {
        return Section::getPrevious();
    }

    Vehicle *vehicle = dynamic_cast<Vehicle *>(getVehicle());
    Direction direction = vehicle->getVehicleOriginalDirection();

    if(vehicle->getWillTurn()) {

        switch(direction) {
            case Direction::north : return intersectionTwo;

            case Direction::south : return intersectionThree;

            case Direction::east : return intersectionFour;

            case Direction::west : return intersectionOne;
        }
    }
    else {
        
        switch(direction) {
            case Direction::north : return intersectionFour;

            case Direction::south : return intersectionOne;

            case Direction::east : return intersectionThree;

            case Direction::west : return intersectionTwo;
        }
    }
    return nullptr;

}

Section *Intersection::getRight() {
    Direction direction = getVehicle()->getVehicleOriginalDirection();
    switch(direction) {
        case Direction::north : return intersectionTwo;

        case Direction::south : return intersectionThree;

        case Direction::east : return intersectionFour;

        case Direction::west : return intersectionOne;
    }
    return nullptr;
}

Section *Intersection::getIntersectionOne() {

    return this->intersectionOne;
}

Section *Intersection::getIntersectionTwo() {

    return this->intersectionTwo;
}

Section *Intersection::getIntersectionThree() {

    return this->intersectionThree;
}

Section *Intersection::getIntersectionFour() {

    return this->intersectionFour;
}

void Intersection::setIntersectionOne(Section *one) {

    this->intersectionOne = one;
}

void Intersection::setIntersectionTwo(Section *two) {

    this->intersectionTwo = two;
}

void Intersection::setIntersectionThree(Section *three) {

    this->intersectionThree = three;
}

void Intersection::setIntersectionFour(Section *four) {

    this->intersectionFour = four;
}
#endif
