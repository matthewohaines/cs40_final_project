#ifndef __LANE_CPP__
#define __LANE_CPP__

#include "Lane.h"

Lane::Lane(int numberOfSections, Direction direction, TrafficLight *trafficLight, Intersection *interOne, Intersection *interTwo) {
    
    Section *last = nullptr;
    this->totalLength = numberOfSections*2 + 2;
    this->trafficLight = trafficLight;
    this->direction = direction;

    for (int i=0; i<4; i++) {
        Section *newSection = new Section();
        if (i == 3) {
            this->priorSection = newSection;
        }
        if (last != nullptr){
            newSection->setPrevious(last);
            last->setForward(newSection);
        }
        last= newSection;
        this->lane.push_back(newSection);
    }
    
    for(int i=0; i<numberOfSections; i++) {
        Section *newSection = new Section();
        newSection->setPrevious(last);
        last->setForward(newSection);
        last = newSection;
        this->lane.push_back(newSection);
    }
    
    lane.push_back(interOne);
    last->setForward(interOne);
    interOne->setPrevious(last);

    Section *afterIntersection = new Section();

    switch(direction) {
        case Direction::north:
            interOne->setIntersectionFour(last);
            interOne->setIntersectionOne(interTwo);
            interTwo->setIntersectionFour(interOne);
            interTwo->setIntersectionOne(afterIntersection);
            break;

        case Direction::south:
            interOne->setIntersectionOne(last);
            interOne->setIntersectionFour(interTwo);
            interTwo->setIntersectionOne(interOne);
            interTwo->setIntersectionFour(afterIntersection);   
            break;

        case Direction::east:
            interOne->setIntersectionThree(last);
            interOne->setIntersectionTwo(interTwo);
            interTwo->setIntersectionThree(interOne);
            interTwo->setIntersectionTwo(afterIntersection);
            break;

        case Direction::west:
            interOne->setIntersectionTwo(last);
            interOne->setIntersectionThree(interTwo);
            interTwo->setIntersectionTwo(interOne);
            interTwo->setIntersectionThree(afterIntersection);
            break;
    }

    this->lane.push_back(interTwo);
    this->lane.push_back(afterIntersection);
    afterIntersection->setPrevious(interTwo);
    last = afterIntersection;

    for(int i=0; i<numberOfSections+4; i++) {
        Section *otherSection = new Section();
        otherSection->setPrevious(last);
        last->setForward(otherSection);
        last = otherSection;
        this->lane.push_back(otherSection);
    }
}

Lane::~Lane() {
    for (int i = 0; i < this->lane.size(); i++) {
        if (!this->lane[i]->getIsIntersection()) {
            delete this->lane[i];
        }
    }
    this->lane.clear();
}


Section *Lane::getPrior() {

    return this->priorSection;
}

Direction Lane::getDirection() {

    return this->direction;
}

TrafficLight *Lane::getTrafficLight() {

    return this->trafficLight;
}

std::vector<VehicleBase *> Lane::getVector() {
    std::vector<VehicleBase *> laneVector(totalLength, nullptr);
    for (int i = 0; i < totalLength; i++) {
        if (!this->lane[i + 4]->isEmpty()) {
            laneVector[i] = lane[i + 4]->getVehicle();
        }
    }
    return laneVector;
}

bool Lane::canCreate() {
    for (int i = 0; i < 4; i++){
        if (!this->lane[i]->isEmpty()) {
            return false;
        }
    }
    return true;
}

#endif
