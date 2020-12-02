#ifndef __LANE_CPP__
#define __LANE_CPP__

#include "Lane.h"
#include "Section.h"
#include "Intersection.h"

Lane::Lane(std::string direction, int number_of_sections_before_intersection) {

    this->firstSection = nullptr;
    this->lastSection = nullptr;
    this->currentSection = nullptr;
    this->direction = direction;
    this->numberOfSections = 0;
    this->currentPosition = 0;
    this->laneQueue = std::deque<Vehicle>();
    createLane(number_of_sections_before_intersection);
}

Lane::~Lane() {}

void Lane::add() {

    Section newSection;
    currentSection = &newSection;
    if(firstSection == nullptr) {
        firstSection = &newSection;
    }
    newSection.previous = lastSection;
    lastSection = &newSection;

    if(newSection.previous != nullptr) {
        lastSection->previous->forward = &newSection;
    }
    numberOfSections++;
    currentPosition++;
}

void Lane::placeVehicle(Vehicle& vehicle) {

    switch(vehicle.getVehicleType()) {

        case VehicleType::car:
            firstSection->vehicle = &vehicle;
            if(!firstSection->forward->isSectionOccupied()) {
                firstSection->forward->vehicle = &vehicle;
            }
            break;

        case VehicleType::suv:
            break;

        case VehicleType::truck:
            break;

    }
}

/*
bool Lane::getCurrent() {

    return currentSection->getSectionOccupied();
}

bool Lane::getFirst() {

    return firstSection->getSectionOccupied();
}

bool Lane::getLast() {
    
    return lastSection->getSectionOccupied();
}

bool Lane::getNext() {

    if(currentSection->forward != nullptr) {
        currentSection = currentSection->forward;
        currentPosition++;
        return currentSection->getSectionOccupied();
    }
    return currentSection->getSectionOccupied();
}

bool Lane::getPrevious() {

    if(currentSection->previous != nullptr) {
        currentSection = currentSection->previous;
        currentPosition--;
        return currentSection->getSectionOccupied();
    }
    return currentSection->getSectionOccupied();
}
*/

int Lane::getCurrentPosition() {

    return currentPosition;
}

int Lane::getNumberOfSections() {

    return numberOfSections;
}

void Lane::createLane(int number_of_sections_before_intersection) {
    for(int i{}; i<number_of_sections_before_intersection*2; i++) {

        add();
    }
}

void Lane::reset() {

    this->currentSection = firstSection;
    this->currentPosition = 1;
}

void Lane::linkFromIntersection(Intersection &inter, int number_of_sections_before_intersection) {

    reset();
    for(int i{}; i<number_of_sections_before_intersection; i++) {
        currentSection = currentSection->forward;
        currentPosition++;
    }
    switch(this->direction[0]) {
        case 'n' :
            inter.two.right = currentSection;
            currentSection->previous = &inter.two;
            break;

        case 's' :
            inter.four.right = currentSection;
            currentSection->previous = &inter.four;
            break;

         case 'e' :
            inter.one.right = currentSection;
            currentSection->previous = &inter.one;
            break;

         case 'w' :
            inter.three.right = currentSection;
            currentSection->previous = &inter.three;
            break;
    }
}

void Lane::linkToIntersection(Intersection &inter, int number_of_sections_before_intersection) {

    reset();
    for(int i{}; i<number_of_sections_before_intersection-1; i++) {
        currentSection = currentSection->forward;
        currentPosition++;
    }
    switch(this->direction[0]) {
        case 'n' :
            currentSection->forward = &inter.one;
            inter.one.previous = currentSection;
            break;

        case 's' :
            currentSection->forward = &inter.three;
            inter.three.previous = currentSection;
            break;

         case 'e' :
            currentSection->forward = &inter.four;
            inter.four.previous = currentSection;
            break;

         case 'w' :
            currentSection->forward = &inter.two;
            inter.two.previous = currentSection;
            break;
    }
}

#endif
