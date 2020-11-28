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
    createLane(number_of_sections_before_intersection);
}

Lane::~Lane() {}

void Lane::add() {

    Section *newSection = new Section;
    if(firstSection == nullptr) {
        firstSection = newSection;
        lastSection = newSection;
        currentSection = newSection;
    }
    else {
        lastSection->forward = newSection;
        lastSection = lastSection->forward;
        currentSection = newSection;
    }
    numberOfSections++;
    currentPosition++;
}

int Lane::getCurrentPosition() {

    return this->currentPosition;
}

int Lane::getNumberOfSections() {

    return this->numberOfSections;
}

void Lane::createLane(int number_of_sections_before_intersection) {
    for(int i{}; i<number_of_sections_before_intersection*2; i++) {

        add();
    }
}

void Lane::moveCurrent(Intersection &inter, int number) {

    if(currentPosition == number+2) {
        currentSection = currentSection->right;
        currentPosition++;
    }
    else {
    currentSection = currentSection->forward;
    currentPosition++;
    }
}

void Lane::reset() {

    this->currentSection = firstSection;
    this->currentPosition = 1;
}
void Lane::linkFromIntersection(Intersection &inter, int number_of_sections_before_intersection) {

    reset();
    for(int i{}; i<number_of_sections_before_intersection; i++) {
        moveCurrent(inter, number_of_sections_before_intersection);
    }
    switch(this->direction[0]) {
        case 'n' :
            inter.two.right = currentSection;
            break;

        case 's' :
            inter.four.right = currentSection;
            break;

         case 'e' :
            inter.one.right = currentSection;
            break;

         case 'w' :
            inter.three.right = currentSection;
            break;
    }
}

void Lane::linkToIntersection(Intersection &inter, int number_of_sections_before_intersection) {

    reset();
    for(int i{}; i<number_of_sections_before_intersection-1; i++) {
        moveCurrent(inter, number_of_sections_before_intersection);
    }
    switch(this->direction[0]) {
        case 'n' :
            currentSection->forward = &inter.one;
            break;

        case 's' :
            currentSection->forward = &inter.three;
            break;

         case 'e' :
            currentSection->forward = &inter.four;
            break;

         case 'w' :
            currentSection->forward = &inter.two;
            break;
    }
}

#endif
