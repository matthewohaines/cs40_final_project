#ifndef __LANE_CPP__
#define __LANE_CPP__

#include "Lane.h"

Lane::Lane() {}

Section *Lane::link(int num, Section *last) {
    for(int i{}; i<num; i++) {
        Section *newSection = new Section();
        newSection->setPrevious(last);
        last->setForward(newSection);
        last = newSection;
        road.push_back(newSection);
    }
    return last;

}

Lane::Lane(Direction direction, int number_of_sections_before_intersection, 
    TrafficLight *trafficLight, Intersection *interOne, Intersection *interTwo) {

    this->trafficLight = trafficLight;
    this->length = number_of_sections_before_intersection*2 + 2;
    this->direction = direction;
    this->last = nullptr;

    for(int i=0; i<number_of_sections_before_intersection+4; i++) {
        Section *newSection = new Section();

        if(i == 3) {
            first = newSection;
        }
        if(last != nullptr) {
            newSection->setPrevious(last);
            last->setForward(newSection);
        }
        last = newSection;
        road.push_back(newSection);
    }

    last = link(number_of_sections_before_intersection, last);
    
    road.push_back(interOne);

    last->setForward(interOne);
    interOne->setPrevious(last);    

    Section *nextSection = new Section();

    if(direction == Direction::north) {
        interOne->setSouth(last);
        interOne->setNorth(interTwo);
        interTwo->setSouth(interOne);
        interTwo->setNorth(nextSection);
    }
    else if(direction == Direction::south) {

        interOne->setNorth(last);
        interOne->setSouth(interTwo);
        interTwo->setNorth(interOne);
        interTwo->setSouth(nextSection);
    }
    else if(direction == Direction::east) {
        interOne->setWest(last);
        interOne->setEast(interTwo);
        interTwo->setEast(nextSection);
        interTwo->setWest(interOne);
    }
    else if(direction == Direction::west) {
        interOne->setEast(last);
        interOne->setWest(interTwo);
        interTwo->setEast(interOne);
        interTwo->setWest(nextSection);
    }
    road.push_back(interTwo);
    road.push_back(nextSection);
    nextSection->setPrevious(interTwo);
    last = nextSection;

    link(number_of_sections_before_intersection+4, last);
}

Lane::~Lane() {
    for (size_t i=0; i < road.size(); i++) {
        if(!road[i]->getIsIntersection()) {
            delete this->road[i];
        }
    }
    road.clear();
}

std::vector<VehicleBase *> Lane::getVector() {
    std::vector <VehicleBase *> roadVector(length, nullptr);
    for(int i=0; i< length; i++) {
        if(!road[i+4]->isEmpty()) {
            roadVector[i] = road[i+4]->getVehicle();
        }
    }
    return roadVector;
}

bool Lane::canPlace() {
    for(size_t i=0; i<4; i++) {
        if(!road[i]->isEmpty()) {
            return false;
                }
        }
    return true;
}

#endif
